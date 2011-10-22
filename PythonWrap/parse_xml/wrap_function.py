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

# configuration, containing the global variables
import config

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
import wrap_class

def get_include_file(funcname, filename):
  last = filename.rfind('/')
  incfile=filename[last+1:]
  print "including function {0} from file {1}".format(funcname,incfile)
  return incfile

def WxHelpLink(funcname):
  if funcname in config.available_operators.keys():
    mname=config.available_operators[funcname]
  else:
    mname=funcname
  return "http://docs.wxwidgets.org/stable/wx_{0}.html#{1}".format(funcname.lower(),mname.lower())


##------------------------------
#def AvailableType(typename,typeid,missing_types,check_includes=False,return_type=False):
  #if check_includes:
    #if (typename in config.available_classes):
      #config.AddDeclare(parse_function.FunctionUsedName(typename))
      #return (not args.val.overwrite) or (typename in wrapped_classes)
  #if  not(typename in config.available_classes) and \
      #not(typename in config.available_types) and \
      #not(typename in typesubst.type_substitute.keys()) and \
      #typename not in typesubst.type_equivalence.keys():
    #missing_types.append(typename)
    #return False
  ## special case for void in arguments
  #if not(return_type) and typename=="void":
    #missing_types.append(typename)
    #return False
  #return True

##------------------------------
#def MissingTypes(parsedfunc,check_includes=False):
  #missing_types=[]
  #if parsedfunc.returntype!=None:
    #typename=config.types[parsedfunc.returntype].GetString()
    #typeid=config.types[parsedfunc.returntype].GetMainTypeId()
    #avail = AvailableType(typename,typeid,missing_types,check_includes,True)
  #for a in parsedfunc.args:
    #typename=config.types[a.typeid].GetString()
    #typefullname=config.types[a.typeid].GetFullString()
    ## discard triple pointers or double pointers with const (TODO: improve this part)
    #if (typefullname.endswith("* * *")) or (typefullname.endswith("* const *")):
      #missing_types.append(typefullname)
    #else:
      #typeid=config.types[a.typeid].GetMainTypeId()
      #avail = AvailableType(typename,typeid,missing_types,check_includes)
      #if (not avail):
        #utils.WarningMessage("type {0} not available: {1}".format(typename,config.types[typeid].GetType()))
  #res = ""
  #if len(missing_types)>0:
    #for t in missing_types:
      #res += t+", "
    #res = res[:-2]
  #if res!="":
    #parsedfunc.missingtypes=True
  #return res



#------------------------------
#class FunctionInfo:
  #def __init__(self):
    #self.name=""
    #self.usedname=""
    #self.duplicated=False
    #self.args=[]
    #self.returntype=None
    #self.missingtypes=False
    #self.deprecated=False

  #def GetDescription(self,funcname):
    #res=''
    #if self.returntype!=None:
      #res += config.types[self.returntype].GetFullString()+" "
    #if self.name in config.available_operators.keys():
      #res += funcname+"::operator "+self.name+'('
    #else:
      #res += funcname+"::"+self.name+'('
    #for a in self.args:
      #res +=  config.types[a.typeid].GetFullString()+" "+a.name
      #if a.default!=None:
        #res += " = {0}".format(FormatArgDefault(a.default))
      #res += ", "
    #if len(self.args)>0:
      #res = res[:-2]
    #res += ')'
    #return res


def CheckBlackList(mname,demangled):
  if mname in config.members_blacklist:
    utils.WarningMessage("Do not implement member {0}, which is in the blacklist !!!".format(mname))
    return True
  for bname in config.members_blacklist:
    if demangled.startswith(bname+"(") or demangled==bname:
      utils.WarningMessage("Do not implement member {0}, which is in the blacklist !!!".format( demangled))
      return True
  return False


#------------------------------
def AddParameters(parsefunc):
  res='('
  if (len(parsefunc.args)>0):
    res += parsefunc.args[0].name
    for i in range(1,len(parsefunc.args)):
      res += ', {0}'.format(parsefunc.args[i].name)
  res += ')'
  return res

#
# USING the version in wrap_class now
#
#------------------------------------------------------------------
#  ImplementFunctionWrap
#------------------------------------------------------------------
#def ImplementFunctionWrap( parsefunc, functioncount=1):

  ##wrapmethod_name = parsefunc.usedname
  #func_usedname = parse_function.FunctionUsedName(parsefunc.name)

  ## don't return help in case of duplicated method
  #if functioncount>1:
    #returnstring="ClassReturnEmptyVar"
    #quiet="true"
  #else:
    #returnstring="ClassHelpAndReturn"
    #quiet="false"

  #res = "\n"
  #res += "//---------------------------------------------------\n"
  #res += "//  Wrapping of "
  #res += parsefunc.GetDescription()+'\n'
  #res += "//---------------------------------------------------\n"
  ## second implementation
  ##   Documentation part
  ##res += "\n"
  ##res += "//  wrapping of {0}::{1}\n".format(funcname,parsefunc.name)
  ##res += "//---------------------------------------------------\n"
  #res += "void     wrap_{0}::SetParametersComments()\n".format(func_usedname) 
  #res += "{\n"
  #for a in parsefunc.args:
    #typename=config.types[a.typeid].GetString()
    #if typename in typesubst.type_substitute.keys():
      #typename=typesubst.type_substitute[typename]
    #res += '  ADDPARAMCOMMENT_TYPE( {0}, "parameter named \'{1}\''.format(typename,a.name)
    #if a.default!=None:
      #res+= ' (def:{0})'.format(parse_function.FormatArgDefault(a.default))
    #res += '")\n'
  #if parsefunc.returntype!=None:
    #returntypest=config.types[parsefunc.returntype].GetString()
    #if returntypest!="void":
      #if returntypest in typesubst.type_substitute.keys():
        #returntypest=typesubst.type_substitute[returntypest]
      #res += '  return_comments="returning a variable of type {0}";\n'.format(returntypest)
  #res += "}\n"
  ##
  ##   Execution part
  ##
  #res += "\n"
  #res += "//---------------------------------------------------\n"
  #res += "BasicVariable::ptr wrap_{0}::CallMember( ParamList* _p)\n".format(func_usedname) 
  #res += "{\n"
  ## check if there are arguments
  #if (len(parsefunc.args)):
    #res +=  "  if (!_p) {0};\n".format(returnstring)
    ## don't accept too many arguments
    #res +=  "  if (_p->GetNumParam()>{0}) {1};\n".format(len(parsefunc.args),returnstring)
    #res +=  "  int _n=0;\n"
    #for a in parsefunc.args:
      #noconstructor_call = False
      #res += "\n"
      #res += a.WrapGetParam(noconstructor_call,returnstring,quiet)
  #else:
    ## don't accept parameters if there is no argument to the function
    #res +=  "  if (_p)  if (_p->GetNumParam()>0) {0};\n".format(returnstring)
  #if parsefunc.returntype!=None:
    #returntypest=config.types[parsefunc.returntype].GetString()
  #else:
    #returntypest="void"
  #res += "\n"
  ## not in constructor and returning void
  #if returntypest=="void":
    #if parsefunc.name in config.available_operators.keys():
      #if len(parsefunc.args)>0:
        #if parsefunc.name=='[]':
          #res += '   [ '.format(parsefunc.name)
          #res += AddParameters(parsefunc)+"];\n";
        #else:
          #res += '   {0} '.format(parsefunc.name)
          #res += AddParameters(parsefunc)+";\n";
      #else:
        ## operator without arguments: put it in front
        #res += ' {0} ;\n'.format(parsefunc.name)
    #else:
      #res += '  {0}'.format(parsefunc.name)
      #res += AddParameters(parsefunc)+";\n";
    #res += '  return BasicVariable::ptr();\n'
  #else:
    #returntypest = config.types[parsefunc.returntype].GetString()
    ## create a string topointer to convert result to a pointer for calling WrapClass_...::CreateVar ...
    #returnpointer= (config.types[parsefunc.returntype].GetType()=="PointerType")
    ##if returnpointer:
    ##  topointer=''
    ##else:
    ##  topointer='&'
    #if parsefunc.name in config.available_operators.keys():
      #res += '  {0} res = '.format(config.types[parsefunc.returntype].GetFullString())
      #if len(parsefunc.args)>0:
        #res += '   {0} '.format(parsefunc.name)
        #res += AddParameters(parsefunc)+";\n";
      #else:
        ## operator without arguments: put it in front
        #res += ' {0};\n'.format(parsefunc.name)
    #else:
      #res += '  {0} res = '.format(config.types[parsefunc.returntype].GetFullString())
      #res += '  {0}'.format(parsefunc.name)
      #res += AddParameters(parsefunc)+";\n";
    ##--- Type substitution before return
    #if returntypest in typesubst.type_substitute.keys():
      #substtype=typesubst.type_substitute[returntypest]
      #substvar="res_{0}".format(typesubst.GetShortName(substtype))
      #if returnpointer:
        #res += '  '+typesubst.ConvertPtrFrom(parsefunc.returntype,'res',substvar)+"\n"
      #else:
        #res += '  '+typesubst.ConvertValFrom(parsefunc.returntype,'res',substvar)+"\n"
      #if (substtype in config.available_classes) and returnpointer:
        #res += '  BasicVariable::ptr res_var = WrapClass_{0}::CreateVar({1});\n'.format(substtype,substvar)
        #res += '  return res_var;\n'
      #else:
        #res += '  return AMILabType<{0} >::CreateVar({1});\n'.format(substtype,substvar)
    ##--- No type substitution before return
    #else:
      #typename=config.types[parsefunc.returntype].GetString()
      #if typename in config.available_classes and returnpointer: 
        #nonconstres = typesubst.RemovePointerConstness(config.types[parsefunc.returntype].GetFullString(),"res")
        ## don't delete returned pointer ...
        #res += '  BasicVariable::ptr res_var = AMILabType<{0} >::CreateVar({1},true);\n'.format(typename,nonconstres)
        #res += '  return res_var;\n'
      #else:
        #if returnpointer:
          ## Avoid deleting the returned pointer ...
          #nonconstres = typesubst.RemovePointerConstness(config.types[parsefunc.returntype].GetFullString(),"res")
          #res += '  return AMILabType<{0} >::CreateVar({1},true);\n'.format(typename,nonconstres)
        #else:
          #res += '  return AMILabType<{0} >::CreateVar(res);\n'.format(typename)
  #res += "}\n"
  #return res
  



#------------------------------------------------------------------
#  ImplementDuplicatedMethodWrap
#------------------------------------------------------------------
def ImplementDuplicatedMethodWrap( method, nummethods, methods):
  # first: easy display
  #if parsefunc.returntype==None:
  #  print 'void',
  #else:
  wrapclass_name="WrapClass_{0}".format(parse_function.FunctionUsedName(funcname))
  wrapmethod_name = parsefunc.usedname
  res = "\n"
  res += "//---------------------------------------------------\n"
  res += "//  Wrapping of multipled defined method:"
  res += "... "
  res += funcname+'(...)\n'
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
    usedname= "{0}_{1}".format(parsefunc.usedname,n)
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
def ImplementCopyMethodWrap(funcname, method):
  wrapclass_name="WrapClass_{0}".format(parse_function.FunctionUsedName(funcname))
  res = "\n"
  res += "//---------------------------------------------------\n"
  res += "//  Wrapping of 'copy' method for {0}.\n".format(funcname)
  res += "//---------------------------------------------------\n"
  # second implementation
  #   Documentation part
  res += "void {0}::\n".format(wrapclass_name)
  res += "    wrap___copy__::SetParametersComments()\n"
  res += "{\n"
  res += '  return_comments="A copy of the {0} object within a new variable.";\n'.format(funcname)
  res += "}\n"
  #   Execution part
  res += "\n"
  res += "//---------------------------------------------------\n"
  res += "BasicVariable::ptr {0}::\n".format(wrapclass_name)
  res += "    wrap___copy__::CallMember( ParamList* _p)\n"
  res += "{\n"
  res += "    return AMILabType<{0} >::CreateVar( new {0}(*(this->_objectptr->GetObj())));\n".format(funcname)
  res += "}\n"
  return res




#----------------------------------------------------------------------
#  FindIncludeFile
#----------------------------------------------------------------------
def FindIncludeFile(funcname,fileid):
  include_file=""
  if fileid in config.files.keys():
    filename = config.files[fileid]
    include_file=filename
  else:
    print "Include file for {0} not found".format(classname)
    return "";
  return '#include "{0}"'.format(include_file)

#----------------------------------------------------------------------
#  WrapFunction
#----------------------------------------------------------------------
def WrapFunction(funcname,include_file,inputfile):
  # Create the handler
  dh = parse_function.FindFunction(funcname)

  parser = make_parser()
  # Tell the parser to use our handler
  parser.setContentHandler(dh)
  # Parse the input
  inputfile.seek(0)
  parser.parse(inputfile)

  #
  if not(dh.found):
    print "... {0} : function not found ...".format(funcname)
  else:
    utils.WarningMessage( "{0} id= {1}".format(funcname,dh.funcid))

    # Create Header File
    header_filename=args.val.outputdir+"/wrap_{0}.h".format(parse_function.FunctionUsedName(funcname))
    if parse_function.IsTemplate(funcname):
      shutil.copyfile(args.val.templatefile_dir+"/wrap_templatefunction.h.in",header_filename)
    else:
      shutil.copyfile(args.val.templatefile_dir+"/wrap_function.h.in",header_filename)

    #

    # now output the results:
    indent=""

    func_decl=""
    func_decl+=indent+'// Adding standard methods\n'
    # step 1:
    pos = 0
    missingtypes = wrap_class.MissingTypes("",dh)
    if missingtypes!="":
      func_decl+= "/* The following types are missing: "+missingtypes+"\n"
      dh.missingtypes=True
    func_decl+=indent+'ADD_CLASS_FUNCTION('+parse_function.FunctionUsedName(funcname)+',"{0}  ({1})")\n'.format(\
          dh.GetDescription(),\
          WxHelpLink(funcname))
    if missingtypes!="":
      func_decl += "*/\n"
    pos = pos+1
    func_decl+='\n'
    

    #local_include_file = get_include_file(funcname,\
    #  config.files[dh.fileid])
    #to_include_file = FindIncludeFile(funcname,dh.fileid)
    to_include_file = wrap_class.FindIncludeFile(funcname,dh.fileid)
    if to_include_file!="":
      config.AddInclude(to_include_file)
    
    for line in fileinput.FileInput(header_filename,inplace=1):
      line = line.replace("${FUNCTION}",   funcname)
      line = line.replace("${INCLUDEFILES}", "")
      line = line.replace("${WRAP_FUNCTION}",     func_decl)
      print line,
          

    ## Implement CreateVar
    #implement_createvar=''

    # Create Implementation File
    impl_filename=args.val.outputdir+"/wrap_{0}.cpp".format(parse_function.FunctionUsedName(funcname))
    if parse_function.IsTemplate(funcname):
      shutil.copyfile(args.val.templatefile_dir+"/wrap_functiontemplate.cpp.in",impl_filename)
    else:
      shutil.copyfile(args.val.templatefile_dir+"/wrap_function.cpp.in",impl_filename)
    
    ## arguments
    impl = ""
    


    ## Methods
    #missingtypes = MissingTypes(dh)
    #print "Checking for missing types\n"
    missingtypes = wrap_class.MissingTypes("",dh,True)
    if missingtypes!="":
      impl += "/* The following types are missing: "+missingtypes+"\n"
    #methodcount=fm.MethodNames.count(m.name)
    #if m.duplicated:
      #impl += ImplementDuplicatedMethodWrap(funcname,m,methodcount,fm.Methods)
    #else:

    impl += wrap_class.ImplementMethodWrap("",dh)
    #impl += ImplementFunctionWrap(dh)

    if missingtypes!="":
      impl += "*/\n"
        
    ## OperatorMethods
    #for m in fm.OperatorMethods:
      #missingtypes = MissingTypes(funcname,m,True)
      #if (missingtypes!="") or (m.usedname=="operator not available"):
        #impl += "/*\n"
      #if missingtypes!="":
        #impl += " * The following types are missing: "+missingtypes+"\n"
      #if m.usedname=="operator not available":
        #impl += " * operator not available \n"
      #methodcount=fm.OperatorMethodNames.count(m.name)
      #if m.duplicated:
        #impl += ImplementDuplicatedMethodWrap(funcname,m,methodcount,fm.OperatorMethods)
      #else:
        #impl += ImplementMethodWrap(funcname,m,False,methodcount)
      #if (missingtypes!="") or (m.usedname=="operator not available"):
        #impl += "*/\n"
        
    ## in place replace TEMPLATE by funcname
    ## in place replace ${ADD_CLASS_METHOD_ALL} by func_decl
    ## in place replace ${ADD_CLASS_METHOD_ALL} by func_decl
    for line in fileinput.FileInput(impl_filename,inplace=1):
      line = line.replace("${FUNCTION}",   funcname)
      line = line.replace("${INCLUDES}",   config.CreateIncludes())
      line = line.replace("${IMPLEMENT_WRAP_FUNCTION}",   impl)
      print line,

