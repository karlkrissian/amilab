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



def IsTemplate(classname):
  return re.match(r"(.*)<(.*)>",classname)!=None

def ClassConstructor(classname):
  ctemp = re.match(r"(.*)<(.*)>",classname)
  if ctemp==None:
    return classname
  else:
    return ctemp.group(1)


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
  if check_includes:
    if (typename in config.available_classes):
      config.AddDeclare(typename)
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
    typename=config.types[method.returntype].GetString()
    typeid=config.types[method.returntype].GetMainTypeId()
    avail = AvailableType(typename,typeid,missing_types,check_includes,True)
  for a in method.args:
    typename=config.types[a.typeid].GetString()
    typefullname=config.types[a.typeid].GetFullString()
    # discard triple pointers or double pointers with const (TODO: improve this part)
    if (typefullname.endswith("* * *")) or (typefullname.endswith("* const *")):
      missing_types.append(typefullname)
    else:
      typeid=config.types[a.typeid].GetMainTypeId()
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
      res +=  config.types[a.typeid].GetFullString()+" "+a.name
      if a.default!=None:
        res += " = {0}".format(FormatArgDefault(a.default))
      res += ", "
    if len(self.args)>0:
      res = res[:-2]
    res += ')'
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
    self.Enumerations=[]


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
      methods.append(method)
    methodlist.append(mname)
    if num>=1:
      self.method.usedname=config.ClassUsedName(mname)+"_{0}".format(num+1)
    else:
      self.method.usedname=config.ClassUsedName(mname)

  #---------------------------------------------
  def CheckOperatorMethodName(self,mname):
    methodindex=''
    methodlist=self.public_members.OperatorMethodNames
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
      self.public_members.OperatorMethods.append(method)
    methodlist.append(mname)
    if num>=1:
      methodindex="_{0}".format(num+1)
    if mname in config.available_operators.keys():
      self.method.usedname=config.available_operators[mname]+methodindex
    else:
      self.method.usedname="operator not available"

  #---------------------------------------------
  def CheckEnumDefault(self, default):
    #print "default for {0}".format(default)
    if default in config.enumvalues.keys():
      typeid = config.enumvalues[default]
      if typeid in config.types.keys():
        print "replacing {0} by {1}::{0} ".format(default,config.types[typeid].GetString())
        return "{1}::{0}".format(default,config.types[typeid].GetString())
    return default


  #---------------------------------------------
  def startElement(self, name, attrs):
    if self.inmethod==1:
      # process arguments
      if name=='Argument':
        typeid=attrs.get('type',None)
        argname=attrs.get('name',None)
        default=attrs.get('default',None)
        if default=="IsForward": print "****** default=IsForward"
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
        
    if self.inenum:
      if name=="EnumValue":
        #print "*"
        valname=attrs.get('name',None)
        valinit=attrs.get('init',None)
        if valname=="IsForward": print "******* Processing IsForward..."
        if (valname!=None) and (valinit!=None):
          self.enum.values[valname]=valinit
      return False # allow further processing of the enumeration
    
    if (name!='Field') and (name!='Enumeration') \
        and (name not in self.available_methods):
      return False
    
    context = attrs.get('context', None)
    # don't process global context
    if context=='_1': return False
    
    access  = attrs.get('access',  None)
    if context in config.types.keys():
      contextname = config.types[context].GetString()
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
      if "{0}::{1}".format(config.types[context].GetString(),fname) in config.members_blacklist:
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
      print "found enumeration ", ename, " in ", config.types[context].GetString()
      return False # allow further processing of the enumeration
      
    # If it's not a method element, ignore it
    if not(name in self.available_methods): return False

    # skip pure virtual methods
    pure_virtual=attrs.get('pure_virtual',None)
    if (pure_virtual=='1'): return False

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
    # adapt names in case of multiple member with the same function name
    if name=='Constructor':
      # problem: for structure, the constructor name is something like '._12': not a valid nor usefull name:
      # replace it by the class or structure name ...
      # only if not template ... so check for '<' character
      if mname != config.types[context].GetString() and config.types[context].GetString().find("<")==-1:
        utils.WarningMessage(" replacing constructor name {0} --> {1}".format(mname,config.types[context].GetString()))
        mname = config.types[context].GetString()
      self.CheckMethodName(self.public_members.ConstructorNames,self.public_members.Constructors,mname)
    if name=='Method':
      if static=="1":
        self.CheckMethodName(self.public_members.StaticMethodNames,self.public_members.StaticMethods,mname)
      else:
        self.CheckMethodName(self.public_members.MethodNames,self.public_members.Methods,mname)
    if name=='OperatorMethod':
      self.CheckOperatorMethodName(mname)
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
def AddParameters(method):
  res='('
  if (len(method.args)>0):
    res += method.args[0].name
    for i in range(1,len(method.args)):
      res += ', {0}'.format(method.args[i].name)
  res += ')'
  return res


#------------------------------------------------------------------
#  ImplementMethodWrap
#------------------------------------------------------------------
def ImplementMethodWrap(classname, method, constructor=False, methodcount=1):

  wrapclass_name="WrapClass_{0}".format(config.ClassUsedName(classname))
  wrapmethod_name = method.usedname
  if method.static=="1":
     wrapmethod_name = "static_"+wrapmethod_name

  # don't return help in case of duplicated method
  if methodcount>1:
    returnstring="ClassReturnEmptyVar"
    quiet="true"
  else:
    returnstring="ClassHelpAndReturn"
    quiet="false"

  res = "\n"
  res += "//---------------------------------------------------\n"
  res += "//  Wrapping of "
  res += method.GetDescription(classname,constructor)+'\n'
  res += "//---------------------------------------------------\n"
  # second implementation
  #   Documentation part
  #res += "\n"
  #res += "//  wrapping of {0}::{1}\n".format(classname,method.name)
  #res += "//---------------------------------------------------\n"
  res += "void {0}::\n".format(wrapclass_name)
  res += "    wrap_{0}::SetParametersComments()\n".format(wrapmethod_name) 
  res += "{\n"
  for a in method.args:
    typename=config.types[a.typeid].GetString()
    if typename in typesubst.type_substitute.keys():
      typename=typesubst.type_substitute[typename]
    res += '  ADDPARAMCOMMENT_TYPE( {0}, "parameter named \'{1}\''.format(typename,a.name)
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
  #
  #   Execution part
  #
  res += "\n"
  res += "//---------------------------------------------------\n"
  res += "BasicVariable::ptr {0}::\n".format(wrapclass_name)
  res += "    wrap_{0}::CallMember( ParamList* _p)\n".format(wrapmethod_name) 
  res += "{\n"
  # check if there are arguments
  if (len(method.args)):
    res +=  "  if (!_p) {0};\n".format(returnstring)
    # don't accept too many arguments
    res +=  "  if (_p->GetNumParam()>{0}) {1};\n".format(len(method.args),returnstring)
    res +=  "  int _n=0;\n"
    for a in method.args:
      noconstructor_call = constructor and (config.types[a.typeid].GetString()==classname)
      res += "\n"
      res += a.WrapGetParam(noconstructor_call,returnstring,quiet)
  else:
    # don't accept parameters if there is no argument to the function
    res +=  "  if (_p)  if (_p->GetNumParam()>0) {0};\n".format(returnstring)
  if method.returntype!=None:
    returntypest=config.types[method.returntype].GetString()
  else:
    returntypest="void"
  res += "\n"
  if constructor:
    res += '  {0}* _newobj = new {0}'.format(classname)
    res += AddParameters(method)+";\n";
    res += "  BasicVariable::ptr res = {0}::CreateVar(_newobj);\n".format(wrapclass_name)
    res += "  return res;\n"
  else:
    # not in constructor and returning void
    if returntypest=="void":
      if method.name in config.available_operators.keys():
        if len(method.args)>0:
          if method.name=='[]':
            res += '  (*this->_objectptr->GetObj()) [ '.format(method.name)
            res += AddParameters(method)+"];\n";
          else:
            res += '  (*this->_objectptr->GetObj()) {0} '.format(method.name)
            res += AddParameters(method)+";\n";
        else:
          # operator without arguments: put it in front
          res += ' {0} (*this->_objectptr->GetObj());\n'.format(method.name)
      else:
        if method.static=="1":
          res += "  {0}::{1}".format(classname,method.name)
        else:
          res += '  this->_objectptr->GetObj()->{0}'.format(method.name)
        res += AddParameters(method)+";\n";
      res += '  return BasicVariable::ptr();\n'
    else:
      returntypest = config.types[method.returntype].GetString()
      # create a string topointer to convert result to a pointer for calling WrapClass_...::CreateVar ...
      returnpointer= (config.types[method.returntype].GetType()=="PointerType")
      #if returnpointer:
      #  topointer=''
      #else:
      #  topointer='&'
      if method.name in config.available_operators.keys():
        res += '  {0} res = '.format(config.types[method.returntype].GetFullString())
        if len(method.args)>0:
          if method.name=='[]':
            res += '  (*this->_objectptr->GetObj()) [ '.format(method.name)
            res += AddParameters(method)+"];\n";
          else:
            res += '  (*this->_objectptr->GetObj()) {0} '.format(method.name)
            res += AddParameters(method)+";\n";
        else:
          # operator without arguments: put it in front
          res += ' {0} (*this->_objectptr->GetObj());\n'.format(method.name)
      else:
        res += '  {0} res = '.format(config.types[method.returntype].GetFullString())
        if method.static=="1":
          res += "  {0}::{1}".format(classname,method.name)
        else:
          res += '  this->_objectptr->GetObj()->{0}'.format(method.name)
        res += AddParameters(method)+";\n";
      #--- Type substitution before return
      if returntypest in typesubst.type_substitute.keys():
        substtype=typesubst.type_substitute[returntypest]
        substvar="res_{0}".format(typesubst.GetShortName(substtype))
        if returnpointer:
          res += '  '+typesubst.ConvertPtrFrom(method.returntype,'res',substvar)+"\n"
        else:
          res += '  '+typesubst.ConvertValFrom(method.returntype,'res',substvar)+"\n"
        if (substtype in config.available_classes) and returnpointer:
          res += '  BasicVariable::ptr res_var = WrapClass_{0}::CreateVar({1});\n'.format(substtype,substvar)
          res += '  return res_var;\n'
        else:
          res += '  return AMILabType<{0} >::CreateVar({1});\n'.format(substtype,substvar)
      #--- No type substitution before return
      else:
        typename=config.types[method.returntype].GetString()
        if typename in config.available_classes and returnpointer: 
          nonconstres = typesubst.RemovePointerConstness(config.types[method.returntype].GetFullString(),"res")
          # don't delete returned pointer ...
          res += '  BasicVariable::ptr res_var = AMILabType<{0} >::CreateVar({1},true);\n'.format(typename,nonconstres)
          res += '  return res_var;\n'
        else:
          if returnpointer:
            # Avoid deleting the returned pointer ...
            nonconstres = typesubst.RemovePointerConstness(config.types[method.returntype].GetFullString(),"res")
            res += '  return AMILabType<{0} >::CreateVar({1},true);\n'.format(typename,nonconstres)
          else:
            res += '  return AMILabType<{0} >::CreateVar(res);\n'.format(typename)
  res += "}\n"
  return res
  

# filename is the new file that should end with '.new'
# it is copied to the original file only if they differ
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
  res += "  ClassHelpAndReturn;\n"
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
#  WrapClass
#----------------------------------------------------------------------
def WrapClass(classname,include_file,inputfile):
  if (args.val.profile):
    t0 = time.clock()
    print "WrapClass({0})".format(classname)
  
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
    implement_type="\n"
    if dh.has_copyconstr:
      if dh.abstract=='1':
        implement_type += "AMI_DEFINE_WRAPPEDTYPE_ABSTRACT({0});\n".format(classname)
      else:
        implement_type += "AMI_DEFINE_WRAPPEDTYPE_HASCOPY({0});\n".format(classname)
      if IsTemplate(classname) and args.val.templates:
        implement_type += "AMI_DEFINE_VARFROMSMTPTR_TEMPLATE2({0},{1});\n".format(classname,config.ClassUsedName(classname))
      else:
        implement_type += "AMI_DEFINE_VARFROMSMTPTR({0});\n".format(classname)
    else:
      implement_type += "AMI_DEFINE_WRAPPEDTYPE_NOCOPY({0});\n".format(classname)
      # need to implement CreateVar ...
      implement_type += "AMI_DEFINE_VARFROMSMTPTR({0});\n".format(classname)
      implement_type += "\n"
      implement_type += "// Implementing CreateVar for AMILabType\n"
      implement_type += "BasicVariable::ptr AMILabType<{0}>::CreateVar( {0}* val, bool nodeleter)\n".format(classname)
      implement_type += "{ \n"
      implement_type += "  boost::shared_ptr<{0}> obj_ptr(val,smartpointer_nodeleter<{0}>());\n".format(classname)
      implement_type += "  return AMILabType<{0}>::CreateVarFromSmtPtr(obj_ptr);\n".format(classname)
      implement_type += "}\n"
          
    # Create Header File
    header_filename=args.val.outputdir+"/wrap_{0}.h.new".format(config.ClassUsedName(classname))
    if IsTemplate(classname):
      shutil.copyfile(args.val.templatefile_dir+"/wrap_templateclass.h.in",header_filename)
    else:
      shutil.copyfile(args.val.templatefile_dir+"/wrap_class.h.in",header_filename)
    
    # add the class to the available ones
    if classname not in config.available_classes:
      config.available_classes.append(classname)

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
      #print basename
      virtualstring=''
      baseusedname=config.ClassUsedName(basename)
      wrapped_base='WrapClass_{0}'.format(baseusedname)
      if virtual=='1':
        virtualstring="virtual"
      if basename in config.available_classes:
        include_bases+='#include "wrap_{0}.h"\n'.format(baseusedname)
        inherit_bases+=', public {0}  {1}'.format(\
            virtualstring, wrapped_base)
        constructor_bases+=', {0}(si)'.format(wrapped_base)
      else:
        config.new_needed_classes.append(basename)
        include_bases+='//#include "wrap_{0}.h"\n'.format(baseusedname)
        inherit_bases+='//, public {0} {1}'.format(virtualstring,wrapped_base)
        constructor_bases+='//, WrapClass_{0}(si)'.format(baseusedname)
      #
      # Add lines needed to include parents methods in object context
      #
      if not(basename in config.available_classes):
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
      
      if not(basename in config.available_classes):
        methods_bases +="*/\n"
      

    # now output the results:
    constructors_decl='\n'
    indent="    "
    wrapped_constructors=0
    if dh.abstract!='1':
      pos=0
      for m in fm.Constructors:
        missingtypes = MissingTypes(classname,m)
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

    # Static Methods:
    staticmethods_decl='\n'
    indent="    "
    pos=0
    utils.WarningMessage( "Number of static methods {0}".format(len(fm.StaticMethods)))
    for m in fm.StaticMethods:
      missingtypes = MissingTypes(classname,m)
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
      if missingtypes!="":
        class_decl+= "/* The following types are missing: "+missingtypes+"\n"
        fm.Methods[pos].missingtypes=True
      class_decl+=indent+'ADD_CLASS_METHOD('+m.usedname+',"{0}  ({1})")\n'.format(\
            m.GetDescription(classname,False),\
            WxHelpLink(classname,m))
      if missingtypes!="":
        class_decl += "*/\n"
      pos = pos+1
    class_decl+='\n'
    
    if len(fm.OperatorMethods)>0:
      class_decl+=indent+"// Operators:\n"
    pos = 0
    for m in fm.OperatorMethods:
      missingtypes = MissingTypes(classname,m)
      if missingtypes!="":
        class_decl+= "/* The following types are missing: "+missingtypes+"\n"
        fm.OperatorMethods[pos].missingtypes=True
      if m.usedname=="operator not available":
        class_decl+=indent+'// ADD_CLASS_METHOD('+m.usedname+',"{0} ({1})")\n'.format(\
            m.GetDescription(classname,False),\
            WxHelpLink(classname,m))
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

    add_public_fields = ''
    if not config.libmodule.wrap_public_fields(classname):
      # clear public fields
      fm.Fields=[]
      
    if len(fm.Fields)>0 or len(fm.Enumerations)>0 or len(dh.bases)>0:
      add_public_fields = "// Add public fields and Enumerations\n"
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
      if (not available_type) or (isconstpointer) or (fulltypename.endswith("void *")) or f.bits!=None or \
      config.types[f.typeid].GetType()=="ArrayType" :
        add_public_fields += indent+"*/\n"
              
    # Add public Enumerations
    add_public_enums = '\n'
    for e in fm.Enumerations:
      # TODO: ideally should check for a typedef here
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
      add_public_enums += "context->AddVar<AMIObject>(obj_{0}->GetName().c_str(),obj_{0},context);\n".format(enum_usedname)
         
         
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


    # in place replace TEMPLATE by classname
    # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
    # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
    local_include_file = config.libmodule.get_include_file(classname,\
      config.files[dh.fileid])
    
    for line in fileinput.FileInput(header_filename,inplace=1):
      line = line.replace("${INCLUDE_BASES}",     include_bases)
      line = line.replace("${INHERIT_BASES}",     inherit_bases)
      line = line.replace("${CONSTRUCTOR_BASES}", constructor_bases)
      line = line.replace("${TEMPLATE}",          classname)
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
        implement_createvar += "  return construct.CallMember(p);\n"
      else:
        # check for possible other method
        utils.WarningMessage( "Using args.val.constructor = {0}".format(args.val.constructor))
        #print fm.StaticMethods
        if args.val.constructor != '' and \
          (args.val.constructor in fm.StaticMethodNames):
          implement_createvar += "  WrapClass_{0}::wrap_static_{1} construct;\n".format(config.ClassUsedName(classname),args.val.constructor)
          implement_createvar += "  return construct.CallMember(p);\n"
        else:
          implement_createvar += "  // No constructor available !!\n"
          implement_createvar += "  return BasicVariable::ptr();\n"

    # Create Implementation File
    impl_filename=args.val.outputdir+"/wrap_{0}.cpp.new".format(config.ClassUsedName(classname))
    if IsTemplate(classname):
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
      line = line.replace("${TEMPLATE}",              classname)
      line = line.replace("${TEMPLATENAME}",          config.ClassUsedName(classname))
      line = line.replace("${TEMPLATESHORTNAME}",     config.ClassShortName(classname))      
      line = line.replace("${METHODS_BASES}",         methods_bases)
      line = line.replace("${AddVar_method_all}",     add_var_all)
      line = line.replace("${AddPublicFields}",       add_public_fields)
      line = line.replace("${AddPublicEnums}",        add_public_enums)
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
  
  if (args.val.profile):
    if not found: 
      print "Class not found: {0}".format(classname)
    else:
      print "WrapClass({0})  {1}".format(classname,time.clock()-t0)
    t0 = time.clock()
