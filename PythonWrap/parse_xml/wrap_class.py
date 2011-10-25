# -*- coding: windows-1252 -*-
from xml.sax import saxutils,handler
from xml.sax import make_parser
from xml.sax.handler import feature_namespaces
import sys
import shutil
import fileinput
#import os
import glob
import re
import os.path
import datetime
import time

# configuration, containing the global variables
import config
import filecmp

# load command line arguments
import args

# type substitution
import typesubst

# type argument information
from argtypes import *

import utils

import findtypesvars
import findfiles
import wx_lib

import arginfo

import parse_function

import generate_html #HTML generate file functions


def IsTemplate(classname):
  return re.match(r"(.*)<(.*)>",classname)!=None

def IsWithinContext(classname):
  return config.types[config.classes[classname]].GetContext() != "_1"


def ClassConstructor(classname):
  ctemp = re.match(r"([^<]*)<(.*)>",classname)
  if ctemp==None:
    namenotemplate = classname
  else:
    namenotemplate = ctemp.group(1)
  
  no_ns = re.match(r"(.*)::([^:]*)",namenotemplate)
  if no_ns==None:
    return namenotemplate
  else:
    return no_ns.group(2)

def FindIncludeFile(classname,fileid):
  if config.libmodule != None:
    include_file = config.libmodule.get_include_file(classname, \
                    config.files[fileid])
    return '{0}'.format(include_file)
  else:
    if fileid in config.files.keys():
      filename = config.files[fileid]
      # check for vxl/core/vnl
      vxl_pos = filename.find("vxl/core/vnl/")
      if vxl_pos!=-1:
        incfile=filename[vxl_pos+len("vxl/core/"):]
      elif filename.find("/stl_"):
        # keep stl files to avoid pb finding the path
        incfile=filename
      else:
        last = filename.rfind('/')
        incfile=filename[last+1:]
      include_file = incfile
    else:
      include_file=""
      print "Include file for {0} not found".format(classname)
      return "";
    #'#include "{0}"'.format(incfile)
    #include_file
  return '#include "{0}"'.format(include_file)

#------------------------------
class EnumInfo:
  def __init__(self):
    self.name=""
    self.values={}

#------------------------------
class FieldInfo:
  def __init__(self):
    self.name=""
    self.typeid=""


#------------------------------
def FormatArgDefault(argdef):
  # to deal with string within default parameter ...
  return argdef.replace('"',"'").replace('\\000','')


def WxHelpLink(classname,method):
  if method.name in config.available_operators.keys():
    mname=config.available_operators[method.name]
  else:
    mname=method.name
  return "http://docs.wxwidgets.org/stable/wx_{0}.html#{1}".format(classname.lower(),mname.lower())


#------------------------------
def AvailableType(typename,typeid,missing_types,check_includes=False,return_type=False):
  #print "AvailableType({0},...)".format(typename)
  #if typename.find('SurfacePoly')!=-1:
  #  print "**************** Checking for SurfacePoly *********************"
  #  print "check_includes {0}".format(check_includes)
  #  print "typename '{0}'".format(typename)
  if check_includes:
    if (typename in config.available_classes):
      #if typename.find('SurfacePoly')!=-1:
      #  print "AddDeclare..."
      config.AddDeclare(typename)
      if typename==config.types[typeid].GetDemangled():
        #print "{0}".format(typename)
        fileid = config.types[typeid].fileid
        to_include_file = FindIncludeFile(typename,fileid)
        if to_include_file!="":
          config.AddInclude(to_include_file)
      if args.val.overwrite and (typename not in config.wrapped_classes) \
          and (typename not in config.needed_classes) \
          and (typename not in config.new_needed_classes):
        config.new_needed_classes.append(typename)
      return (not args.val.overwrite) or (typename in config.wrapped_classes)
  if  not(typename in config.available_classes) and \
      not(typename in config.available_types) and \
      not(typename in typesubst.type_substitute.keys()) and \
      typename not in typesubst.type_equivalence.keys():
    missing_types.append(typename)
    if (config.types[typeid].GetType() in config.class_types) \
        and (typename not in config.needed_classes) \
        and (typename not in config.new_needed_classes):
      # add to class list
      config.new_needed_classes.append(typename)
      utils.WarningMessage( "** Adding needed class {0}".format(typename))
    return False
  # special case for void in arguments
  if not(return_type) and typename=="void":
    missing_types.append(typename)
    return False
  return True

#------------------------------
def MissingTypes(classname,method,check_includes=False):
  missing_types=[]
  if method.returntype!=None:
    typename = config.types[method.returntype].GetDemangled()
    typeid=config.types[method.returntype].GetMainTypeId()
    shared_type = config.IsSharedPtr(typename)
    if shared_type!=None:
      avail = AvailableType(shared_type,typeid,missing_types,check_includes,True)
    else:
      avail = AvailableType(typename,typeid,missing_types,check_includes,True)
  for a in method.args:
    typename=config.types[a.typeid].GetDemangled()
    typefullname=config.types[a.typeid].GetFullString()
    #
    ispointer= config.types[a.typeid].GetType()=="PointerType"
    isconstpointer = typefullname.endswith("const *")
    if typename=='void' and ispointer:
      print "need to deal with 'void pointer' here\n"
    else:
      #
      # discard triple pointers or double pointers with const (TODO: improve this part)
      if (typefullname.endswith("* * *")) or (typefullname.endswith("* const *")):
        missing_types.append(typefullname)
      else:
        typeid=config.types[a.typeid].GetMainTypeId()
        shared_type = config.IsSharedPtr(typename)
        if shared_type!=None:
          avail = AvailableType(shared_type,typeid,missing_types,check_includes)
        else:
          avail = AvailableType(typename,typeid,missing_types,check_includes)
        if (not avail):
          utils.WarningMessage("type {0} not available: {1}".format(typename,config.types[typeid].GetType()))
  res = ""
  if len(missing_types)>0:
    for t in missing_types:
      res += t+", "
    res = res[:-2]
  if res!="":
    method.missingtypes=True
  return res



#------------------------------
class MethodInfo:
  def __init__(self):
    self.name=""
    self.usedname=""
    self.duplicated=False
    self.args=[]
    self.returntype=None
    self.missingtypes=False
    self.is_copyconstr=False
    self.static="0"
    self.deprecated=False
    self.demangled=""

  def GetDescription(self,classname,constructor=False):
    res=''
    if constructor:
      res += "Constructor "
    if self.static==1:
      res += "static "
    if self.returntype!=None:
      res += config.types[self.returntype].GetFullString()+" "
    if self.name in config.available_operators.keys():
      res += classname+"::operator "+self.name+'('
    else:
      res += classname+"::"+self.name+'('
    for a in self.args:
      if a.name=='lpszHostname':
        print "type for lpszHostname {0}".format(a.typeid)
        print "type for lpszHostname {0}".format(config.types[a.typeid].GetType())
        print "type for lpszHostname {0}".format(config.types[a.typeid].GetFullString())
      res +=  config.types[a.typeid].GetFullString()+" "+a.name
      if a.default!=None:
        res += " = {0}".format(FormatArgDefault(a.default))
      res += ", "
    if len(self.args)>0:
      res = res[:-2]
    res += ')'
    return res

  def GetHTMLDescription(self,classname,url):
    if url!="":
      mname = '<A title="Link to doxygen documentation" href="{0}"><i>Dox</i></A>&nbsp;{1}'.format(url,self.name)
    else:
      mname = self.name
    mname='<b>{0}</b>'.format(mname)
    res=''
    if self.static==1:
      res += "static "
    if self.returntype!=None:
      typestr = config.types[self.returntype].GetFullString()
      typestr = typestr.replace('<','&lt;')
      typestr = typestr.replace('>','&gt;')
      typestr = generate_html.obj.CheckTypeLink(\
                      config.types[self.returntype].GetString(),\
                      typestr)
      res += "<em>{0}</em> ".format(typestr)
    if self.name in config.available_operators.keys():
      res += "operator "+mname+'('
    else:
      res += mname+'('
    paramlist=""
    for a in self.args:
      typestr = config.types[a.typeid].GetFullString()
      typestr = typestr.replace('<','&lt;')
      typestr = typestr.replace('>','&gt;')
      typestr = generate_html.obj.CheckTypeLink(\
                      config.types[a.typeid].GetString(),\
                      typestr)
      paramlist +=  "<em>{0}</em> <font color=\"#22AA22\">{1}</font>".format(typestr,a.name)
      if a.default!=None:
        paramlist += " = {0}".format(FormatArgDefault(a.default))
      paramlist += ", "
    if len(self.args)>0:
      paramlist = paramlist[:-2]
    res += paramlist+')'
    return res


def CheckBlackList(mname,demangled):
  if mname in config.members_blacklist:
    utils.WarningMessage("Do not implement member {0}, which is in the blacklist !!!".format(mname))
    return True
  for bname in config.members_blacklist:
    if demangled.startswith(bname+"(") or demangled==bname:
      utils.WarningMessage("Do not implement member {0}, which is in the blacklist !!!".format( demangled))
      return True
  return False


class PublicMembers:
  def __init__(self):
    self.MethodNames=[]
    self.StaticMethodNames=[]
    self.ConstructorNames=[]
    self.OperatorMethodNames=[]
    self.Methods=[]
    self.Constructors=[]
    self.StaticMethods=[]
    self.OperatorMethods=[]
    self.Fields=[]
    self.Typedefs=[]
    self.Enumerations=[]
    self.destructor=None

class GlobalMembers:
  def __init__(self):
    self.MethodNames=[]
    #self.StaticMethodNames=[]
    #self.ConstructorNames=[]
    self.OperatorMethodNames=[]
    self.Methods=[]
    #self.Constructors=[]
    #self.StaticMethods=[]
    self.OperatorMethods=[]
    #self.Fields=[]
    #self.Typedefs=[]
    #self.Enumerations=[]
    #self.destructor=None


# Store Class information
class ParsePublicMembers:
  def __init__(self, class_list):
    self.class_list = class_list
    self.found=False
    self.inmethod=0
    self.available_methods=['Method','Constructor','Destructor','OperatorMethod']
    self.inenum=False

  #---------------------------------------------
  def CheckMethodName(self,methodlist,methods,mname):
    num=methodlist.count(mname)
    if num==1:
      # rename initial method
      pos=0
      for m in methods:
        if m.usedname==config.ClassUsedName(mname):
          methods[pos].usedname=config.ClassUsedName(mname)+"_1"
          staticval = methods[pos].static
        pos= pos+1
      # add main method
      method = MethodInfo()
      method.name=mname
      method.static = staticval
      method.usedname=config.ClassUsedName(mname)
      method.duplicated=True
      methods.insert(len(methods)-1,method)
    methodlist.append(mname)
    if num>=1:
      self.method.usedname=config.ClassUsedName(mname)+"_{0}".format(num+1)
    else:
      self.method.usedname=config.ClassUsedName(mname)

  #---------------------------------------------
  def CheckOperatorMethodName(self,method):
    mname=method.name
    methodindex=''
    methodlist=self.public_members.OperatorMethodNames
    # deal with prefix ++ and -- operators
    if mname=='++' or mname=='--':
      if len(method.args)>0:
        method.usedname=config.available_operators[mname+"(int)"]
      else:
        method.usedname=config.available_operators[mname]
      print "{0}: method.usedname = {1}".format(method.demangled,method.usedname)
    elif mname=='*' and len(method.args)==0:
      # indirection operator
      method.usedname=config.available_operators[mname+'()']
    else:
      num=methodlist.count(mname)
      if num==1:
        # rename initial method
        pos=0
        for m in self.public_members.OperatorMethods:
          if m.name==mname and mname in config.available_operators.keys():
            self.public_members.OperatorMethods[pos].usedname +="_1"
          pos = pos+1
        # add main method
        method = MethodInfo()
        method.name=mname
        if mname in config.available_operators.keys():
          method.usedname=config.available_operators[mname]
        else:
          method.usedname="operator not available"
        method.duplicated=True
        self.public_members.OperatorMethods.insert(\
              len(self.public_members.OperatorMethods)-1,method)
      methodlist.append(mname)
      if num>=1:
        methodindex="_{0}".format(num+1)
      if mname in config.available_operators.keys():
        self.method.usedname=config.available_operators[mname]+methodindex
      else:
        self.method.usedname="operator not available"

  #---------------------------------------------
  # Note: could be simplified since we don't need perfect default values anymore
  #
  def CheckEnumDefault(self, default):
   #print "default for {0}".format(default)
    if default in config.enumvalues.keys():
      typeid = config.enumvalues[default]
      if typeid in config.types.keys() and typeid!="_1":
        #print "replacing {0} by {1}::{0} ".format(default,config.types[typeid].GetString())
        return "{1}::{0}".format(default,config.types[typeid].GetString())
    return default


  #---------------------------------------------
  def CheckArgument(self, name, attrs):
    # process arguments
    if name=='Argument':
      typeid=attrs.get('type',None)
      argname=attrs.get('name',None)
      default=attrs.get('default',None)
      if argname==None:
        argname='param{0}'.format(len(self.method.args))
      if typeid in config.types.keys():
        typename=config.types[typeid].GetFullString(),
      else:
        typename=typeid,
      utils.WarningMessage("\t\t {0} \t\t {1}".format(typename,argname))
      # append argument to list
      arg=arginfo.ArgInfo()
      arg.name=argname
      arg.typeid=typeid
      if default != None:
        arg.default=self.CheckEnumDefault(default)
      else:
        arg.default=None
      self.method.args.append(arg)
      return True
    else:
      utils.WarningMessage( "Non-argument in method: {0}\n".format(name))

  #---------------------------------------------
  def CheckEnum(self, name, attrs):
    if name=="EnumValue":
      #print "*"
      valname=attrs.get('name',None)
      valinit=attrs.get('init',None)
      #if valname=="IsForward": print "******* Processing IsForward..."
      if (valname!=None) and (valinit!=None):
        self.enum.values[valname]=valinit
    return False # allow further processing of the enumeration

  #---------------------------------------------
  def startElement(self, name, attrs):
    if self.inmethod==1:
      return self.CheckArgument(name,attrs)
    if self.inenum:
      return self.CheckEnum(name,attrs)
    
    if (name not in ['Field','Enumeration','Typedef']) \
        and (name not in self.available_methods):
      return False
    
    context = attrs.get('context', None)
    
    # don't process global context
    if context=='_1': return False
    
    access  = attrs.get('access',  None)
    if context in config.types.keys():
      contextname = config.types[context].GetDemangled()
    else:
      #print "Name = {0}, context {1} not yet included in types".format(name,context)
      return False

    if (contextname not in self.class_list) or (access!="public"): return False
    
    # Context should be of class or struct type, and have a PublicMembers instance
    self.public_members = config.types[context].public_members
    # now we can modify all the lists elements in the object 'public_members'
    
    # deal with public variable members
    if name=='Field':
      fname   = attrs.get('name',    None)
      ftype   = attrs.get('type',    None)
      bits    = attrs.get('bits',    None)
      if "{0}::{1}".format(config.types[context].GetDemangled(),fname) in config.members_blacklist:
        print "Discarded field ",fname, " which is in the backlist"
      else:
        field = FieldInfo()
        field.name  =fname
        field.typeid=ftype
        field.bits=bits
        self.public_members.Fields.append(field)
      return True
      
    if name=='Enumeration':
      ename   = attrs.get('name',    None)
      access  = attrs.get('access',  None)
      self.enum = EnumInfo()
      self.enum.name  =ename
      self.public_members.Enumerations.append(self.enum)
      self.inenum = True
      print "found enumeration ", ename, " in ", config.types[context].GetDemangled()
      return False # allow further processing of the enumeration
      

    if name=='Typedef':
      tname=attrs.get('name',None)
      ttype=attrs.get('type',None)
      print "Found Typedef '{0}' in class".format(tname)
      typedef = TypedefInfo()
      typedef.name=tname
      typedef._reftypeid = ttype
      self.public_members.Typedefs.append(typedef)
      
    # If it's not a method element, ignore it
    if not(name in self.available_methods): return False

    # skip pure virtual methods, why??
    pure_virtual=attrs.get('pure_virtual',None)
    #if (pure_virtual=='1'): return False

    # Look for the title and number attributes (see text)
    access=attrs.get('access',None)
    demangled=attrs.get('demangled',None)
    static=attrs.get('static',"0")
    attributes=attrs.get('attributes',None)
    
    #print context
    #print classname
    mname=attrs.get('name',None)
    if CheckBlackList(mname,demangled): return
    if attributes=="deprecated":
      utils.WarningMessage("Skipping deprecated method {0}".format(mname))
      #print "Skipping deprecated method {0}".format(mname)
      return False
    self.method = MethodInfo()
    self.method.name=mname
    self.method.static=static
    self.method.demangled=demangled
    # adapt names in case of multiple member with the same function name
    if name=='Constructor':
      # problem: for structure, the constructor name is something like '._12': not a valid nor usefull name:
      # replace it by the class or structure name ...
      # only if not template ... so check for '<' character
      #if mname != config.types[context].GetString() and config.types[context].GetString().find("<")==-1:
      if config.types[context].GetString().find(mname)==-1:
        utils.WarningMessage(" replacing constructor name {0} --> {1}".format(mname,config.types[context].GetString()))
        mname = config.types[context].GetString()
      self.CheckMethodName(self.public_members.ConstructorNames,self.public_members.Constructors,mname)
    if name=='Method':
      if static=="1":
        self.CheckMethodName(self.public_members.StaticMethodNames,self.public_members.StaticMethods,mname)
      else:
        self.CheckMethodName(self.public_members.MethodNames,self.public_members.Methods,mname)
    #if name=='OperatorMethod':
    #  self.CheckOperatorMethodName(mname)
    self.method.returntype=attrs.get('returns',None)
    if name=='Method':
      if static=="1":
        self.public_members.StaticMethods.append(self.method)
        utils.WarningMessage( "Added {0} to static methods".format(mname))
      else:
        self.public_members.Methods.append(self.method)
    if name=='Constructor':
      self.public_members.Constructors.append(self.method)
    if name=='OperatorMethod':
      self.public_members.OperatorMethods.append(self.method)
    if name=='Destructor':
      self.public_members.destructor = self.method
      
    utils.WarningMessage( "\t {0} # found {1} \t ".format(self.method.name,attrs.get('demangled',None)))
    self.inmethod=1
    return True
          
  def endElement(self, name):  
    if (self.inmethod==1) and (name in self.available_methods):
      if name=='OperatorMethod':
        self.CheckOperatorMethodName(self.method)
      self.inmethod=0
    if (self.inenum==True) and (name=="Enumeration"):
      self.inenum=False

#------------------------------
#------------------------------
class FindPublicMembers(handler.ContentHandler):
  def __init__(self, class_list):
    self.parse_public_members = ParsePublicMembers(class_list)

  #---------------------------------------------
  def startElement(self, name, attrs):
    self.parse_public_members.startElement(name,attrs)
          
  def endElement(self, name):  
    self.parse_public_members.endElement(name)

#------------------------------
def AddParameters(method,numparam=-1):
  res='('
  if (len(method.args)>0):
    if numparam!=0:
      res += method.args[0].name
    for i in range(1,len(method.args)):
      if numparam==-1 or i<numparam:
        res += ', {0}'.format(method.args[i].name)
  res += ')'
  return res


#------------------------------------------------------------------
#  ImplementMethodDescription, 
#  if classname="" then can be used for a standard function
#------------------------------------------------------------------
def ImplementMethodDescription(classname, method, constructor=False, methodcount=1):
  
  if classname!="":
    wrapclass_name="WrapClass_{0}".format(config.ClassUsedName(classname))
  wrapmethod_name = method.usedname
  if method.static=="1":
     wrapmethod_name = "static_"+wrapmethod_name
  
  res = "\n"
  res += "//---------------------------------------------------\n"
  res += "//  Wrapping of "
  if classname!="":
    res += method.GetDescription(classname,constructor)+'\n'
  else:
    res += method.GetDescription()+'\n'
  res += "//---------------------------------------------------\n"
  # second implementation
  #   Documentation part
  #res += "\n"
  #res += "//  wrapping of {0}::{1}\n".format(classname,method.name)
  #res += "//---------------------------------------------------\n"
  res += "void "
  if classname!="":
    res += "{0}::\n".format(wrapclass_name)
  res += "    wrap_{0}::SetParametersComments()\n".format(wrapmethod_name) 
  res += "{\n"
  for a in method.args:
    typename=config.types[a.typeid].GetDemangled()
    if typename in typesubst.type_substitute.keys():
      typename=typesubst.type_substitute[typename]
    
    shared_type = config.IsSharedPtr(typename)
    if shared_type==None:
      if typename.count(",")>0:
        res += '  ADDPARAMCOMMENT_TYPE( {0}, "parameter named \'{1}\''.format(config.ClassTypeDef(typename),a.name)
      else:
        res += '  ADDPARAMCOMMENT_TYPE( {0}, "parameter named \'{1}\''.format(typename,a.name)
    else:
      res += '  ADDPARAMCOMMENT_TYPE( {0}, "parameter named \'{1}\''.format(shared_type,a.name)
    if a.default!=None:
      res+= ' (def:{0})'.format(FormatArgDefault(a.default))
    res += '")\n'
  if method.returntype!=None:
    returntypest=config.types[method.returntype].GetString()
    if returntypest!="void":
      if returntypest in typesubst.type_substitute.keys():
        returntypest=typesubst.type_substitute[returntypest]
      res += '  return_comments="returning a variable of type {0}";\n'.format(returntypest)
    if constructor:
      res += '  return_comments="returning a new variable of type {0};\n'.format(classname)
  res += "}\n"
  return res


#------------------------------------------------------------------
#  ImplementMethodCall
#  with a given number of parameter, allowing to deal with default arguments
#  if classname="" then can be used for a standard function
#------------------------------------------------------------------
def ImplementMethodCall(classname, method, numparam, constructor=False, ident=''):
  
  wrapmethod_name = method.usedname
  if classname!="":
    wrapclass_name="WrapClass_{0}".format(config.ClassUsedName(classname))
    if method.static=="1":
      wrapmethod_name = "static_"+wrapmethod_name
  
  methodparams = AddParameters(method,numparam)
  if method.returntype!=None:
    returntypest=config.types[method.returntype].GetDemangled()
  else:
    returntypest="void"
  if numparam==-1:
    numparam_text = "all"
  elif numparam==0:
    numparam_text = "no"
  else:
    numparam_text = "{0}".format(numparam)
  res = ident+"  // -------- Calling the class method with {0} parameter(s)\n".format(numparam_text)
  
  if constructor:
    res += ident+'  {0}* _newobj = new {0}'.format(classname)
    res += methodparams+";\n";
    res += ident+"  BasicVariable::ptr res = {0}::CreateVar(_newobj);\n".format(wrapclass_name)
    res += ident+"  return res;\n"
  else:
    
    # Define the string containing the method call
    obj_ptr='this->_objectptr->GetObj()'
    # check for null object
    if method.static!="1" and classname!="":
      res += ident+"  if (!{0}.get()) return BasicVariable::ptr();\n".format(obj_ptr)
    if method.name in config.available_operators.keys():
      if len(method.args)>0:
        if method.name=='[]':
          methodcall = '(*{0}) [{1}]'.format(obj_ptr,methodparams)
        else:
          if method.name=='()':
            methodcall = '(*{0}) {1}'.format(obj_ptr,methodparams)
          elif method.name in ['++','--']:
            methodcall = '(*{0}){1}'.format(obj_ptr,method.name)
          else:
            methodcall = '(*{0}) {1}{2}'.format(obj_ptr,method.name,methodparams)
      else:
        # operator without arguments: put it in front
        methodcall = '{0} (*{1})'.format(method.name,obj_ptr)
    else:
      if method.static=="1":
        methodcall = "{0}::{1}".format(classname,method.name)
      else:
        if classname!="":
          methodcall = '{0}->{1}'.format(obj_ptr,method.name)
        else:
          methodcall = '{0}'.format(method.name)
      methodcall += methodparams;
    
    # not in constructor and returning void
    if returntypest=="void":
      res += ident+'  {0};\n'.format(methodcall)
      res += ident+'  return BasicVariable::ptr();\n'
    else:
      returntypest = config.types[method.returntype].GetString()
      # create a string topointer to convert result to a pointer for calling WrapClass_...::CreateVar ...
      returnpointer= (config.types[method.returntype].GetType()=="PointerType")
      pointercount = config.types[method.returntype].GetFullString().count("*")
      #if returnpointer:
      #  topointer=''
      #else:
      #  topointer='&'
      res += ident+'  {0} res = '.format(config.types[method.returntype].GetFullString())
      res += methodcall+';\n';
      #--- Type substitution before return
      if returntypest in typesubst.type_substitute.keys():
        substtype=typesubst.type_substitute[returntypest]
        substvar="res_{0}".format(typesubst.GetShortName(substtype))
        if returnpointer:
          res += ident+'  '+typesubst.ConvertPtrFrom(method.returntype,'res',substvar)+"\n"
        else:
          res += ident+'  '+typesubst.ConvertValFrom(method.returntype,'res',substvar)+"\n"
        if (substtype in config.available_classes) and returnpointer:
          res += ident+'  if ({0}==NULL) return nullvar;\n'.format('res')
          res += ident+'  BasicVariable::ptr res_var = WrapClass_{0}::CreateVar({1});\n'.format(substtype,substvar)
          res += ident+'  return res_var;\n'
        else:
          res += ident+'  return AMILabType<{0} >::CreateVar({1});\n'.format(substtype,substvar)
      #--- No type substitution before return
      else:
        typename=config.types[method.returntype].GetDemangled()
        if typename in config.available_classes and returnpointer: 
          nonconstres = typesubst.RemovePointerConstness(config.types[method.returntype].GetFullString(),"res")
          # don't delete returned pointer ...
          res += ident+'  if ({0}==NULL) return nullvar;\n'.format(nonconstres)
          res += ident+'  BasicVariable::ptr res_var = AMILabType<{0} >::CreateVar({1},true);\n'.format(typename,nonconstres)
          res += ident+'  return res_var;\n'
        else:
          if returnpointer:
            res += ident+'  if ({0}==NULL) return nullvar;\n'.format('res')
            # Avoid deleting the returned pointer ...
            nonconstres = typesubst.RemovePointerConstness(config.types[method.returntype].GetFullString(),"res")
            if pointercount==1:
              res += ident+'  return AMILabType<{0} >::CreateVar({1},true);\n'.format(typename,nonconstres)
            else:
              print "Pointer count = {0}".format(pointercount)
              # several pointers ... try to convert to a single one
              res += ident+'  return AMILabType<{0} >::CreateVar(({2}*){1},true);\n'.format(typename,nonconstres,config.types[method.returntype].GetString())
          else:
            shared_type = config.IsSharedPtr(typename)
            if shared_type==None:
              if config.types[method.returntype].GetType() == "ReferenceType" and not(config.types[method.returntype].GetFullString().endswith('const &')) and not(config.types[method.returntype].GetFullString().endswith('* &')):
                # return a pointer that will not be deleted
                res += ident+'  return AMILabType<{0} >::CreateVar(&res,true);\n'.format(typename)
              else:
                if config.types[method.returntype].GetFullString().endswith('* &'):
                  res += ident+'  return AMILabType<{0} >::CreateVar(res,true);\n'.format(typename)
                else:
                  res += ident+'  return AMILabType<{0} >::CreateVar(res);\n'.format(typename)
            else:
              res += ident+'  return AMILabType<{0} >::CreateVarFromSmtPtr(res);\n'.format(shared_type)
  return res

#------------------------------------------------------------------
#  ImplementMethodWrap
#  if classname="" then can be used for a standard function
#------------------------------------------------------------------
def ImplementMethodWrap(classname, method, constructor=False, methodcount=1):

  wrapmethod_name = method.usedname
  if classname!="":
    wrapclass_name="WrapClass_{0}".format(config.ClassUsedName(classname))
    if method.static=="1":
      wrapmethod_name = "static_"+wrapmethod_name

  #
  # Implement the description/help part
  #
  res = ImplementMethodDescription(classname,method,constructor)
  
  # don't return help in case of duplicated method
  if methodcount>1:
    returnstring="ClassReturnEmptyVar"
    quiet="true"
  else:
    returnstring="ClassHelpAndReturn"
    quiet="false"

  #
  #   Execution part
  #
  res += "\n"
  res += "//---------------------------------------------------\n"
  res += "BasicVariable::ptr "
  if classname!="":
    res += "{0}::\n    ".format(wrapclass_name)
  res += "wrap_{0}::CallMember( ParamList* _p)\n".format(wrapmethod_name) 
  res += "{\n"
  # check if there are arguments
  # never use arguments for ++ and -- operators
  if (len(method.args)) and (method.name not in ['++','--']):
    res +=  "  if (!_p) {0};\n".format(returnstring)
    # don't accept too many arguments
    res +=  "  if (_p->GetNumParam()>{0}) {1};\n".format(len(method.args),returnstring)
    res +=  "  int _n=0;\n"
    argnum=0
    for a in method.args:
      argnum+=1
      noconstructor_call = constructor and (config.types[a.typeid].GetString()==classname)
      res += "\n"
      if a.default!=None:
        res += "  // Check the number of parameters here for default arguments\n"
        res += '  if (_p->GetNumParam()<{0})\n'.format(argnum)
        res += '  {\n'
        res += ' {0}'.format(ImplementMethodCall(classname,method,argnum-1,constructor,'  '))
        res += '  }\n'
      res += a.WrapGetParam(noconstructor_call,returnstring,quiet)
  else:
    # don't accept parameters if there is no argument to the function
    res +=  "  if (_p)  if (_p->GetNumParam()>0) {0};\n".format(returnstring)
  
  # Calling the method with its parameters
  res += ImplementMethodCall(classname,method,-1,constructor)
  res += "}\n"
  return res


#-----------------------------------------------------------------
# filename is the new file that should end with '.new'
# it is copied to the original file only if they differ
#-----------------------------------------------------------------
def BackupFile(filename):
  # Check implementation file for backup
  if os.path.isfile(filename[:-4]):
    if filecmp.cmp(filename,filename[:-4]):
      # if same "mv xxx.cpp.new xxx.cpp.old", not changing the original file to avoid recompilation
      shutil.move(filename,filename[:-4]+".old")
    else:
      print "FILES differ: {0}".format(filename[:-4])
      # else "mv xxx.cpp xxx.cpp.old" and "mv xxx.cpp.new xxx.cpp"
      shutil.move(filename[:-4],filename[:-4]+".old")
      shutil.move(filename,filename[:-4])
  else:
      shutil.move(filename,filename[:-4])


#------------------------------------------------------------------
#  ImplementDuplicatedMethodWrap
#------------------------------------------------------------------
def ImplementDuplicatedMethodWrap(classname, method, nummethods, methods, constructor=False):
  # first: easy display
  #if method.returntype==None:
  #  print 'void',
  #else:
  wrapclass_name="WrapClass_{0}".format(config.ClassUsedName(classname))
  wrapmethod_name = method.usedname
  if method.static=="1":
     wrapmethod_name = "static_"+wrapmethod_name
  res = "\n"
  res += "//---------------------------------------------------\n"
  res += "//  Wrapping of multipled defined method:"
  res += "... "
  if constructor:
    res += "Constructor "
  if method.static=="1":
    res += "static "
  res += classname+"::"+method.name+'(...)\n'
  res += "//---------------------------------------------------\n"
  # second implementation
  #   Documentation part
  res += "void {0}::\n".format(wrapclass_name)
  res += "    wrap_{0}::SetParametersComments()\n".format(wrapmethod_name) 
  res += "{}\n"
  #   Execution part
  res += "\n"
  res += "//---------------------------------------------------\n"
  res += "BasicVariable::ptr {0}::\n".format(wrapclass_name)
  res += "    wrap_{0}::CallMember( ParamList* _p)\n".format(wrapmethod_name) 
  res += "{\n"
  res += "  BasicVariable::ptr res;\n"
  for n in range(1,nummethods+1):
    usedname= "{0}_{1}".format(method.usedname,n)
    utils.WarningMessage(" wrapping of {0}".format(usedname))
    # find corresponding method and check if it is implemented
    pos=0
    # Set False as default ...
    is_implemented=False
    for m in methods:
      #print "method name {0} usedname {1}".format(m.name,m.usedname)
      if m.usedname==usedname:
        #print " found method {0}".format(usedname)
        #print " Is implemented = {0}".format(not methods[pos].missingtypes)
        is_implemented = not methods[pos].missingtypes
        utils.WarningMessage(" Duplicated Method {0} is implemented: {1}".format(usedname,is_implemented))
      pos = pos+1
    if is_implemented:
      if m.static=="1":
        usedname = "static_"+usedname
      if constructor or (m.static=="1"):
        res += "  {0}::wrap_{1} m{2};\n".format(wrapclass_name,usedname,n)
      else:
        res += "  {0}::wrap_{1} m{2}(this->_objectptr);\n".format(wrapclass_name,usedname,n)
      res += "  res = m{0}.CallMember(_p);\n".format(n)
      res += "  if (!m{0}.Get_arg_failure()) return res;\n".format(n)
  res += "  if (!quiet)\n"
  res += "    ClassHelpAndReturn\n"
  res += "  else\n"
  res += "    return BasicVariable::ptr();\n"
  res += "}\n"
  return res


#------------------------------------------------------------------
#  ImplementCopyMethodWrap
#------------------------------------------------------------------
def ImplementCopyMethodWrap(classname, method):
  wrapclass_name="WrapClass_{0}".format(config.ClassUsedName(classname))
  res = "\n"
  res += "//---------------------------------------------------\n"
  res += "//  Wrapping of 'copy' method for {0}.\n".format(classname)
  res += "//---------------------------------------------------\n"
  # second implementation
  #   Documentation part
  res += "void {0}::\n".format(wrapclass_name)
  res += "    wrap___copy__::SetParametersComments()\n"
  res += "{\n"
  res += '  return_comments="A copy of the {0} object within a new variable.";\n'.format(classname)
  res += "}\n"
  #   Execution part
  res += "\n"
  res += "//---------------------------------------------------\n"
  res += "BasicVariable::ptr {0}::\n".format(wrapclass_name)
  res += "    wrap___copy__::CallMember( ParamList* _p)\n"
  res += "{\n"
  res += "    return AMILabType<{0} >::CreateVar( new {0}(*(this->_objectptr->GetObj())));\n".format(classname)
  res += "}\n"
  return res


#----------------------------------------------------------------------
#  Initialize HTML module
#----------------------------------------------------------------------
def HTMLInitialization(createhtml,templatedir, outputdirectory, outputfilename, url, libraryname):
  if(createhtml):
    generate_html.obj.Initialization( templatedir,\
                                      outputdirectory,\
                                      outputfilename,\
                                      url,\
                                      libraryname)

#----------------------------------------------------------------------
#  WrapClass
#----------------------------------------------------------------------
def WrapClass(classname,include_file,inputfile):
  if (args.val.profile):
    t0 = time.clock()
    #print "\n**************"
    print "\n   Wrapping: {0}".format(classname)
    print "             **************"
    #print "WrapClass({0},{1},{2})".format(classname,include_file,inputfile)
  parser = make_parser()
  # Create the handler
  #dh = parse_class.FindClass(classname)
  ## Tell the parser to use our handler
  #parser.setContentHandler(dh)
  ## Parse the input
  #inputfile.seek(0)
  #parser.parse(inputfile)

  found = classname in config.classes.keys()

  #
  if found:
    classid = config.classes[classname]
    dh = config.types[classid]
    utils.WarningMessage( "{0} id= {1}".format(classname,classid))
    # Create the handler
    #print "classname is ",classname
    #print "args.val.classes is ",config.parsed_classes

    if classname not in config.parsed_classes:
      fpm = FindPublicMembers([classname])
      # Tell the parser to use our handler
      parser.setContentHandler(fpm)
      # Parse the input
      inputfile.seek(0)
      parser.parse(inputfile)
    #else:
      #print "Is part of args.val.classes"
    
    fm = config.types[classid].public_members
    generate_html.obj.SetPublicMethods(fm) 

    # Smart Pointer Deleter
    failed = False
    if config.libmodule != None:
      try:
        implement_deleter = config.libmodule.implement_deleter(config.ClassTypeDef(classname))
      except:
        failed=True
      if not failed:
        # Check if a file needs to be included
        try:
          fileinc = config.libmodule.deleter_includefile()
          config.AddInclude(fileinc)
        except:
          pass
    else:
      failed=True
    if failed:
      implement_deleter = ""
      if (dh.abstract=='1') or (dh.public_members.destructor==None):
        implement_deleter = ", smartpointer_nodeleter<{0} >()".format(config.ClassTypeDef(classname))

    # Check for Copy Constructor
    pos=0
    dh.has_copyconstr = False
    for m in fm.Constructors:
      if len(m.args)==1:
        typename = config.types[m.args[0].typeid].GetFullString()
        if typename=="{0} const &".format(classname):
          utils.WarningMessage( "Copy constructor found: {0}".format(m.usedname))
          dh.has_copyconstr = True
          fm.Constructors[pos].is_copyconstr=True
      pos = pos+1
    
    # Check for =(T&) operator
    pos=0
    dh.has_copyassign = False
    for m in fm.OperatorMethods:
      if m.name == "=":
        if len(m.args)==1:
          typename = config.types[m.args[0].typeid].GetFullString()
          if typename=="{0} const &".format(classname):
            utils.WarningMessage( "Copy assign operator found: {0}".format(m.usedname))
            dh.has_copyassign = True
      pos = pos+1
    
    implement_type="\n"
    if dh.has_copyassign:
        implement_type += "AMI_DEFINE_GETVALPARAM({0});\n".format(config.ClassTypeDef(classname))
    if dh.has_copyconstr:
      if dh.abstract=='1':
        implement_type += "AMI_DEFINE_WRAPPEDTYPE_ABSTRACT({0});\n".format(config.ClassTypeDef(classname))
      else:
        implement_type += "AMI_DEFINE_WRAPPEDTYPE_HASCOPY({0});\n".format(config.ClassTypeDef(classname))
      if (IsTemplate(classname) and args.val.templates) or IsWithinContext(classname):
        implement_type += "AMI_DEFINE_VARFROMSMTPTR_TEMPLATE2({0},{1});\n".format(config.ClassTypeDef(classname),config.ClassUsedName(classname))
      else:
        implement_type += "AMI_DEFINE_VARFROMSMTPTR({0});\n".format(config.ClassTypeDef(classname))
    else:
      implement_type += "AMI_DEFINE_WRAPPEDTYPE_NOCOPY({0});\n".format(config.ClassTypeDef(classname))
      #print "{0} is template {1}".format(classname,IsTemplate(classname))
      # need to implement CreateVar ...
      if (IsTemplate(classname) and args.val.templates) or IsWithinContext(classname):
        implement_type += "AMI_DEFINE_VARFROMSMTPTR_TEMPLATE2({0},{1});\n".format(config.ClassTypeDef(classname),config.ClassUsedName(classname))
      else:
        implement_type += "AMI_DEFINE_VARFROMSMTPTR({0});\n".format(config.ClassTypeDef(classname))
      implement_type += "\n"
      implement_type += "// Implementing CreateVar for AMILabType\n"
      implement_type += "BasicVariable::ptr AMILabType<{0} >::CreateVar( {0}* val, bool nodeleter)\n".format(classname)
      implement_type += "{ \n"
      implement_type += "    boost::shared_ptr<{0} > obj_ptr;\n".format(classname)
      implement_type += "  if (nodeleter)\n"
      implement_type += "    obj_ptr = boost::shared_ptr<{0} >(val, smartpointer_nodeleter<{0} >());\n".format(classname)
      implement_type += "  else\n"
      implement_type += "    obj_ptr = boost::shared_ptr<{0} >(val {1});\n".format(classname,implement_deleter)
      implement_type += "  return AMILabType<{0} >::CreateVarFromSmtPtr(obj_ptr);\n".format(classname)
      implement_type += "}\n"
              
    # Create Header File
    header_filename=args.val.outputdir+"/wrap_{0}.h.new".format(config.ClassUsedName(classname))
    if IsTemplate(classname) or IsWithinContext(classname):
      shutil.copyfile(args.val.templatefile_dir+"/wrap_templateclass.h.in",header_filename)
    else:
      shutil.copyfile(args.val.templatefile_dir+"/wrap_class.h.in",header_filename)
    
    # add the class to the available ones
    if classname not in config.available_classes:
      config.available_classes.append(classname)

    # Template case
    include_typedef=''
    if ( classname!=config.ClassTypeDef(classname) ):
      include_typedef='/// Redefinition of the template class\n'
      include_typedef+='typedef '+classname+' '+config.ClassTypeDef(classname)+";"

    # Create Inheritance information
    include_bases='\n'
    inherit_bases=''
    constructor_bases=''
    methods_bases='// Adding Bases\n'
    #if len(fm.Fields)==0 and len(fm.Enumerations)==0\
       #and len(dh.bases)>0:
      #indent = '  '
      #methods_bases = "// Get the current context\n"
      #methods_bases += indent+'AMIObject::ptr tmpobj(amiobject.lock());\n'
      #methods_bases += indent+'if (!tmpobj.get()) return;\n'
      #methods_bases += indent+'Variables::ptr context(tmpobj->GetContext());\n'
    #
    #print "number of bases:",len(dh.bases)
    #print dh.bases
    for (base,virtual) in dh.bases:
      basename=config.types[base].GetString()
      print "base:",base," name:",basename
      virtualstring=''
      baseusedname=config.ClassUsedName(basename)
      wrapped_base='WrapClass_{0}'.format(baseusedname)
      if virtual=='1':
        virtualstring="virtual"
      # problem to find the base class because of spaces mismatch after the ',' 
      # in templates, small trick here to try to fix it
      basename1 = basename.replace(',',', ')
      basename1 = basename1.replace(',  ',', ')
      basename_ok = basename in config.available_classes or \
                    basename1 in config.available_classes
      if basename_ok:
        include_bases+='#include "wrap_{0}.h"\n'.format(baseusedname)
        inherit_bases+=', public {0}  {1}'.format(\
            virtualstring, wrapped_base)
        constructor_bases+=', {0}(si)'.format(wrapped_base)
      else:
        print "basename = ", basename
        print "basename1 = ", basename1
        print "config.available_classes = ", config.available_classes
        config.new_needed_classes.append(basename)
        include_bases+='//#include "wrap_{0}.h"\n'.format(baseusedname)
        inherit_bases+='//, public {0} {1}'.format(virtualstring,wrapped_base)
        constructor_bases+='//, WrapClass_{0}(si)'.format(baseusedname)
      #
      # Add lines needed to include parents methods in object context
      #
      if  not(basename_ok):
        methods_bases +="/*"
      methods_bases+="\n"
      indent='  '
      methods_bases+=indent+'// Add base parent {0}\n'.format(basename)
      # cast object
      methods_bases+=indent+'boost::shared_ptr<{0} > parent_{1}('.format(basename,baseusedname)
      methods_bases+=indent+'boost::dynamic_pointer_cast<{0} >(this_ptr->GetObj()));\n'.format(basename)
      # Create a new variable
      methods_bases+=indent+'BasicVariable::ptr var_{1} = AMILabType<{0} >::CreateVarFromSmtPtr(parent_{1});\n'.format(basename,baseusedname)
      # Add the variable
      methods_bases+=indent+'context->AddVar("{0}",var_{0});\n'.format(baseusedname)
      # set as a default context
      methods_bases+=indent+'// Set as a default context\n'
      methods_bases+=indent+'Variable<AMIObject>::ptr obj_{0} = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_{0});\n'.format(baseusedname)
      methods_bases+=indent+'context->AddDefault(obj_{0}->Pointer()->GetContext());\n'.format(baseusedname)
      
      if not(basename_ok):
        methods_bases +="*/\n"
      

    # now output the results:
    constructors_decl='\n'
    indent="    "
    wrapped_constructors=0
    if dh.abstract!='1':
      pos=0
      for m in fm.Constructors:
        missingtypes = MissingTypes(classname,m)
        m.iswrapped=(missingtypes=="")
        if missingtypes!="":
          constructors_decl+=  indent+"/* The following types are missing: "+missingtypes+"\n"
          fm.Constructors[pos].missingtypes=True
        constructors_decl += indent+"/// Wrapping of the constructor\n"
        constructors_decl+=indent+'ADD_CLASS_CONSTRUCTOR('+\
                m.usedname+',"{0} ({1}).");\n'.format(\
                                m.GetDescription(classname,True),\
                                WxHelpLink(classname,m))
        if missingtypes!="":
          constructors_decl +=  indent+"*/\n"
        else:
          wrapped_constructors = wrapped_constructors+1
        pos=pos+1
      constructors_decl+='\n'
    else:
      for m in fm.Constructors:
        m.iswrapped=False

    # Static Methods:
    staticmethods_decl='\n'
    indent="    "
    pos=0
    utils.WarningMessage( "Number of static methods {0}".format(len(fm.StaticMethods)))
    for m in fm.StaticMethods:
      missingtypes = MissingTypes(classname,m)
      m.iswrapped=(missingtypes=="")
      if missingtypes!="":
        staticmethods_decl+=  indent+"/* The following types are missing: "+missingtypes+"\n"
        fm.StaticMethods[pos].missingtypes=True
      staticmethods_decl+=indent+'ADD_CLASS_STATICMETHOD('+\
              m.usedname+',"{0} ({1}).");\n'.format(\
                              m.GetDescription(classname,False),\
                              WxHelpLink(classname,m))
      if missingtypes!="":
        staticmethods_decl +=  indent+"*/\n"
      pos=pos+1
    staticmethods_decl+='\n'

    class_decl='\n'
    # check for 'copy' method
    if dh.has_copyconstr and (dh.abstract!="1"):
      class_decl+=indent+'// Adding copy method\n'
      class_decl+=indent+'ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");\n'

    class_decl+=indent+'// Adding standard methods\n'
    # step 1:
    pos = 0
    for m in fm.Methods:
      missingtypes = MissingTypes(classname,m)
      m.iswrapped=(missingtypes=="")
      if missingtypes!="":
        class_decl+= "/* The following types are missing: "+missingtypes+"\n"
        fm.Methods[pos].missingtypes=True
      class_decl+=indent+'ADD_CLASS_METHOD('+m.usedname+',"{0}  ({1})")\n'.format(\
            m.GetDescription(classname,False),\
            WxHelpLink(classname,m))
      if missingtypes!="":
        class_decl += "*/\n"
      generate_html.obj.AddClassMethod(m)
      pos = pos+1
    class_decl+='\n'
    #print "\nBegin: {0}\n".format(classname)
    #generate_html.GenerateHTMLStandardMethods(classname)
    #print "\nEnd: {0}\n".format(classname)
        
    if len(fm.OperatorMethods)>0:
      class_decl+=indent+"// Operators:\n"
    pos = 0
    for m in fm.OperatorMethods:
      missingtypes = MissingTypes(classname,m)
      m.iswrapped=(missingtypes=="")
      if missingtypes!="":
        class_decl+= "/* The following types are missing: "+missingtypes+"\n"
        fm.OperatorMethods[pos].missingtypes=True
      if m.usedname=="operator not available":
        class_decl+=indent+'// ADD_CLASS_METHOD('+m.usedname+',"{0} ({1})")\n'.format(\
            m.GetDescription(classname,False),\
            WxHelpLink(classname,m))
        m.iswrapped=False
      else:
        class_decl+=indent+'ADD_CLASS_METHOD('+m.usedname+',\
            "{0} ({1})")\n'.format(\
            m.GetDescription(classname,False),\
            WxHelpLink(classname,m))
      if missingtypes!="":
        class_decl += "*/\n"
      pos = pos + 1
    class_decl+='\n'

    # step 2:
    add_var_all='\n'
    indent ="  "

    # check for 'copy' method
    if dh.has_copyconstr and (dh.abstract!="1"):
      add_var_all+=indent+'// Adding copy method \n'
      add_var_all+=indent+'AddVar___copy__( this_ptr);\n'

    add_var_all+=indent+'// Adding standard methods \n'
    for m in fm.Methods:
      missingtypes = MissingTypes(classname,m)
      if missingtypes!="":
        add_var_all += "/* The following types are missing: "+missingtypes+"\n"
      if m.usedname in config.ami_tokens.values():
        add_var_all += indent+'AddVar_{0}( this_ptr,"_{0}"); // it is a language token\n'.format(m.usedname)
      else:
        add_var_all += indent+'AddVar_'+m.usedname+'( this_ptr);\n'
      if missingtypes!="":
        add_var_all += "*/\n"
    add_var_all += '\n'

    if len(fm.OperatorMethods)>0:
      add_var_all += indent+"// Adding operators\n"
      for m in fm.OperatorMethods:
        missingtypes = MissingTypes(classname,m)
        if missingtypes!="":
          add_var_all += "/* The following types are missing: "+missingtypes+"\n"
        if m.usedname=="operator not available":
          add_var_all += indent+'// AddVar_'+m.usedname+'( this_ptr);\n'
        else:
          add_var_all += indent+'AddVar_'+m.usedname+'( this_ptr);\n'
        if missingtypes!="":
          add_var_all += "*/\n"
      add_var_all += '\n'

    # Adding public fields
    add_public_fields = ''
    if config.libmodule != None:
      if not config.libmodule.wrap_public_fields(classname):
        # clear public fields
        fm.Fields=[]
      
    if len(fm.Fields)>0 or len(fm.Enumerations)>0 or len(dh.bases)>0:
      add_public_fields = "// Add public fields \n"
      add_public_fields += indent+'AMIObject::ptr tmpobj(amiobject.lock());\n'
      add_public_fields += indent+'if (!tmpobj.get()) return;\n'
      add_public_fields += indent+'Variables::ptr context(tmpobj->GetContext());\n'

    for f in fm.Fields:
      typename=config.types[f.typeid].GetString()
      fulltypename=config.types[f.typeid].GetFullString()
      ispointer= config.types[f.typeid].GetType()=="PointerType"
      isconstpointer = fulltypename.endswith("const *")
      available_type =  (typename in config.available_classes) or \
                        (typename in config.available_types)
      add_public_fields += indent+"\n"
      # Wwe can't take address of a bit field
      if not available_type or f.bits!=None or config.types[f.typeid].GetType()=="ArrayType":
        if not available_type:
          add_public_fields += indent+"/* Type not available\n"
        else:
          if config.types[f.typeid].GetType()=="ArrayType":
            add_public_fields += indent+"/* ArrayType not implemented\n"
          else:
            if f.bits!=None:
              add_public_fields += indent+"/* Can't get address of a bit field\n"
      else:
        # check includes
        if (typename in config.available_classes):
          config.AddDeclare(typename)
        if isconstpointer:
          add_public_fields += indent+"/* Avoiding const pointers for the moment\n"
        else:
          if fulltypename.endswith("void *"):
            add_public_fields += indent+"/* Cannot wrap void* \n"
      add_public_fields += indent+"// Adding public member {0}\n".format(f.name)
      if ispointer:
        refstring=""
      else:
        refstring="&"
      add_public_fields += indent+"boost::shared_ptr<{0} > var_{1}_ptr({2}GetObj()->{1}, smartpointer_nodeleter<{0} >());\n".\
        format(typename,f.name,refstring)
      add_public_fields += indent+"if (var_{0}_ptr.get()) ".format(f.name)+'{\n'
      add_public_fields += indent+"  BasicVariable::ptr var_{1} = AMILabType<{0} >::CreateVarFromSmtPtr(var_{1}_ptr);\n".format(typename,f.name)
      add_public_fields += indent+"  if (var_{0}.get()) ".format(f.name)+'{\n'
      add_public_fields += indent+'    var_{0}->Rename("{0}");\n'.format(f.name)
      add_public_fields += indent+'    context->AddVar(var_{0},context);\n'.format(f.name)
      add_public_fields += indent+'  }\n'
      add_public_fields += indent+'}\n'
      f.iswrapped = True
      if (not available_type) or (isconstpointer) or (fulltypename.endswith("void *")) or f.bits!=None or \
      config.types[f.typeid].GetType()=="ArrayType" :
        add_public_fields += indent+"*/\n"
        f.iswrapped = False
              
    # Adding public typedefs as static elments
    add_public_typedefs = ''
    if len(fm.Typedefs)>0:
      n=0
      add_public_typedefs += "// Adding public typedefs \n"
    for td in fm.Typedefs:
      add_public_typedefs += indent
      # need to find the variable that corresponds to the type to add ...
      # for now just adding a string
      st = '{0}  --  {1}'.format(td.GetFullString(),\
            config.ClassShortName(\
                config.types[td._reftypeid].GetString(),args.val.libname))
      add_public_typedefs += 'BasicVariable::ptr type_{0} = AMILabType<std::string>::CreateVar(new std::string("{1}"));\n'.format(n,st)
      add_public_typedefs += indent
      add_public_typedefs += 'type_{0}->Rename("{1}");\n'.format(n,td.name)
      add_public_typedefs += indent
      add_public_typedefs += "amiobject->GetContext()->AddVar(type_{0}->Name(),type_{0},context);\n".format(n)
      n=n+1

    # Add public Enumerations
    add_public_enums = '\n'
    # TODO: ideally should check for a typedef here
    add_public_enums += "// Add public enumerations \n"
    for e in fm.Enumerations:
      enum_usedname = e.name.replace('.','enum')
      # Create an amiobject
      add_public_enums += indent
      add_public_enums += "AMIObject::ptr obj_{0}(new AMIObject);\n".format(enum_usedname)
      add_public_enums += indent
      add_public_enums += 'obj_{0}->SetName("{0}");\n'.format(enum_usedname)
      # add all the values
      add_public_enums += "\n"
      for ev in e.values.keys():
        add_public_enums += indent
        add_public_enums += "BasicVariable::ptr var_{0} = AMILabType<int >::CreateVar({1});\n".format(ev,e.values[ev])
        add_public_enums += indent
        add_public_enums += "if (var_{0}.get()) ".format(ev)+'{\n'
        add_public_enums += indent
        add_public_enums += '  var_{0}->Rename("{0}");\n'.format(ev)
        add_public_enums += indent
        add_public_enums += '  obj_{0}->GetContext()->AddVar(var_{1},obj_{0}->GetContext());\n'.format(enum_usedname,ev)
        add_public_enums += indent+"}\n"
      add_public_enums += "\n"
      add_public_enums += indent+"// Add enum to context\n"
      add_public_enums += indent
      add_public_enums += "amiobject->GetContext()->AddVar<AMIObject>(obj_{0}->GetName().c_str(),obj_{0},context);\n".format(enum_usedname)
      add_public_enums += indent+"// Add as default context\n"
      add_public_enums += indent+"amiobject->GetContext()->AddDefault(obj_{0}->GetContext());\n".format(enum_usedname)
         

    # Adding constructor to the user given context:
    add_constructor=''
    if wrapped_constructors>0:
      indent ="  "
      if dh.abstract!='1':
        pos=0
        for m in fm.Constructors:
          if fm.Constructors[pos].missingtypes:
            add_constructor+=  indent+"/* Types are missing\n"
          add_constructor+=indent+'WrapClass_{0}::AddVar_{1}(amiobject->GetContext());\n'.format(\
            config.ClassUsedName(classname),m.usedname)
          if fm.Constructors[pos].missingtypes:
            add_constructor +=  indent+"*/\n"
          pos=pos+1
        add_constructor+='\n'

    # Adding static methods to the user given context:
    add_static_methods='// Static methods \n'
    indent = "  "
    pos=0
    for m in fm.StaticMethods:
      if fm.StaticMethods[pos].missingtypes:
        add_static_methods +=  indent+"/* Types are missing\n"
      add_static_methods+=indent+'WrapClass_{0}::AddVar_{1}(amiobject->GetContext());\n'.format(\
          config.ClassUsedName(classname),m.usedname)
      if fm.StaticMethods[pos].missingtypes:
        add_static_methods +=  indent+"*/\n"
      pos=pos+1
    #add_static_methods+='\n'

    # Generate HTML file
    generate_html.obj.GenerateHTMLClassFile( classname)

    # in place replace TEMPLATE by classname
    # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
    # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
    local_include_file = FindIncludeFile(classname,dh.fileid)
    #print "local include file {0}".format(local_include_file)
    #local_include_file = '#include "{0}"'.format(local_include_file)
    # in case of template, check template parameters for includes
    m = re.match(r"([^<]*)<(.*)>",classname)
    if m!=None:
      template_params = []
      config.templatetypes(m.group(2),template_params)
      for template_param in template_params:
        template_param = template_param.strip(' ')
        print "To check for include: {0}".format(template_param)
        if template_param in config.classes.keys():
          fileid = config.types[config.classes[template_param]].fileid
          filetoadd = FindIncludeFile(template_param,fileid)
          #local_include_file += '\n#include "{0}"'.format(filetoadd)
          local_include_file += '\n{0}'.format(filetoadd)
    print "from {0}".format(local_include_file)
        
    for line in fileinput.FileInput(header_filename,inplace=1):
      line = line.replace("${INCLUDE_BASES}",     include_bases)
      line = line.replace("${INCLUDE_TYPEDEF}",   include_typedef)
      line = line.replace("${INHERIT_BASES}",     inherit_bases)
      line = line.replace("${CONSTRUCTOR_BASES}", constructor_bases)
      line = line.replace("${TEMPLATE}",          config.ClassTypeDef(classname))
      line = line.replace("${TEMPLATENAME}",      config.ClassUsedName(classname))
      line = line.replace("${INCLUDEFILES}",      local_include_file)
      line = line.replace("${ADD_CLASS_CONSTRUCTORS}",constructors_decl)
      line = line.replace("${ADD_CLASS_STATIC_METHODS}",staticmethods_decl)
      line = line.replace("${ADD_CLASS_METHOD_ALL}",class_decl)
      print line,
          

    # Implement CreateVar
    implement_createvar=''
    if dh.abstract=='1':
      implement_createvar += "  // No variable creation for an abstract class ...\n"
      implement_createvar += "  return BasicVariable::ptr();\n"
    else:
      #if len(fm.Constructors)>0:
      if wrapped_constructors>0:
        implement_createvar += "  WrapClass_{0}::wrap_{1} construct;\n".format(config.ClassUsedName(classname),ClassConstructor(classname))
        implement_createvar += "  construct.Set_quiet(quiet);\n"
        implement_createvar += "  return construct.CallMember(p);\n"
      else:
        # check for possible other method
        utils.WarningMessage( "Using args.val.constructor = {0}".format(args.val.constructor))
        #print fm.StaticMethods
        if args.val.constructor != '' and \
          (args.val.constructor in fm.StaticMethodNames):
          implement_createvar += "  WrapClass_{0}::wrap_static_{1} construct;\n".format(config.ClassUsedName(classname),args.val.constructor)
          implement_createvar += "  construct.Set_quiet(quiet);\n"
          implement_createvar += "  return construct.CallMember(p);\n"
        else:
          implement_createvar += "  // No constructor available !!\n"
          implement_createvar += "  return BasicVariable::ptr();\n"

    # Create Implementation File
    impl_filename=args.val.outputdir+"/wrap_{0}.cpp.new".format(config.ClassUsedName(classname))
    if IsTemplate(classname) or IsWithinContext(classname):
      shutil.copyfile(args.val.templatefile_dir+"/wrap_templateclass.cpp.in",impl_filename)
    else:
      shutil.copyfile(args.val.templatefile_dir+"/wrap_class.cpp.in",impl_filename)
    
    # arguments
    impl = ""
    if dh.abstract!='1':
      # Constructors for non-abstract classes
      for m in fm.Constructors:
        missingtypes = MissingTypes(classname,m,True)
        if missingtypes!="":
          impl += "/* The following types are missing: "+missingtypes+"\n"
        methodcount=fm.ConstructorNames.count(m.name)
        if m.duplicated:
          impl += ImplementDuplicatedMethodWrap(classname,m,methodcount,fm.Constructors,True)
        else:
          impl += ImplementMethodWrap(classname,m,True,methodcount)
        if missingtypes!="":
          impl += "*/\n"

    # Destructor??
    
    # implement static methods
    for m in fm.StaticMethods:
      missingtypes = MissingTypes(classname,m,True)
      if missingtypes!="":
        impl += "/* The following types are missing: "+missingtypes+"\n"
      methodcount=fm.StaticMethodNames.count(m.name)
      if m.duplicated:
        impl += ImplementDuplicatedMethodWrap(classname,m,methodcount,fm.StaticMethods)
      else:
        impl += ImplementMethodWrap(classname,m,False,methodcount)
      if missingtypes!="":
        impl += "*/\n"
    
    # implement copy method
    if dh.has_copyconstr and (dh.abstract!="1"):
      impl+=ImplementCopyMethodWrap(classname,m)

    # Methods
    for m in fm.Methods:
      missingtypes = MissingTypes(classname,m,True)
      if missingtypes!="":
        impl += "/* The following types are missing: "+missingtypes+"\n"
      methodcount=fm.MethodNames.count(m.name)
      if m.duplicated:
        impl += ImplementDuplicatedMethodWrap(classname,m,methodcount,fm.Methods)
      else:
        impl += ImplementMethodWrap(classname,m,False,methodcount)
      if missingtypes!="":
        impl += "*/\n"
        
    # OperatorMethods
    for m in fm.OperatorMethods:
      missingtypes = MissingTypes(classname,m,True)
      if (missingtypes!="") or (m.usedname=="operator not available"):
        impl += "/*\n"
      if missingtypes!="":
        impl += " * The following types are missing: "+missingtypes+"\n"
      if m.usedname=="operator not available":
        impl += " * operator not available \n"
      methodcount=fm.OperatorMethodNames.count(m.name)
      if m.duplicated:
        impl += ImplementDuplicatedMethodWrap(classname,m,methodcount,fm.OperatorMethods)
      else:
        impl += ImplementMethodWrap(classname,m,False,methodcount)
      if (missingtypes!="") or (m.usedname=="operator not available"):
        impl += "*/\n"
        
    # in place replace TEMPLATE by classname
    # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
    # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
    for line in fileinput.FileInput(impl_filename,inplace=1):
      line = line.replace("${INCLUDES}",              config.CreateIncludes())
      line = line.replace("${IMPLEMENT_TYPE}",        implement_type)
      line = line.replace("${IMPLEMENT_CREATEVAR}",   implement_createvar)
      line = line.replace("${IMPLEMENT_DELETER}",     implement_deleter)
      line = line.replace("${TEMPLATE}",              config.ClassTypeDef(classname))
      line = line.replace("${TEMPLATENAME}",          config.ClassUsedName(classname))
      line = line.replace("${TEMPLATESHORTNAME}",     config.ClassShortName(classname,args.val.libname))
      line = line.replace("${METHODS_BASES}",         methods_bases)
      line = line.replace("${AddVar_method_all}",     add_var_all)
      line = line.replace("${AddPublicFields}",       add_public_fields)
      line = line.replace("${AddPublicEnums}",        add_public_enums)
      line = line.replace("${AddPublicTypedefs}",     add_public_typedefs)
      line = line.replace("${AddVar_constructor}",    add_constructor)
      line = line.replace("${AddVar_static_methods}", add_static_methods)
      line = line.replace("${WRAP_PUBLIC_METHODS}",   impl)
      print line,

  if found:
    # Check header file for backup
    BackupFile(header_filename)

    # Check implementation file for backup
    BackupFile(impl_filename)
  else:
    print "Class {0} not found".format(classname)
    print "Classes are:"
    print "****************************"
    print  config.classes.keys()
    print "****************************"
  
  if (args.val.profile):
    if not found: 
      print "Class not found: {0}".format(classname)
    else:
      print "WrapClass({0})  {1}".format(classname,time.clock()-t0)
    t0 = time.clock()
