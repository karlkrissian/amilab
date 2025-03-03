
import utils
import re

import config
# load command line arguments
import args
# type substitution
import typesubst
import arginfo

#-------------------------------------------------------------
def FunctionUsedName(funcname):
  res = funcname
  res = res.replace('<','_')
  res = res.replace('>','_')
  res = res.replace(',','_')
  res = res.replace('::','_')
  #res = res.replace('(','')
  #res = res.replace(')','')
  # get rid of function parameters
  m=re.search('([^(]+)\s*(\(.*\))?',res)
  res = m.group(1)
  return res

#------------------------------
def FormatArgDefault(argdef):
  # to deal with string within default parameter ...
  return argdef.replace('"',"'").replace('\\000','')


def IsTemplate(classname):
  return re.match(r"(.*)<(.*)>",classname)!=None

#-------------------------------------------------------------
class FindFunction():
  def __init__(self, funcname):
    self.search_funcname = funcname
    self.name         = funcname
    self.usedname     = FunctionUsedName(funcname)
    self.static       = "0"
    self.found        = False
    self.infunc       = False
    self.fileid       = ""
    self.duplicated   = False
    self.args         = []
    self.missingtypes = False
    self.converter    = False
    self.const        = False

  #---------------------------------------------
  def parse(self, xmltree):
    # go through elements
    root = xmltree.getroot()
    self.parseElt(root)

  #---------------------------------------------
  def parseElt(self,elt):
    self.startElement(elt.tag, elt.attrib)
    for child in list(elt):
      self.parseElt(child)
    self.endElement(elt.tag)

  #---------------------------------------------
  def CheckEnumDefault(self, default):
    #print "default for {0}".format(default)
    if default in config.enumvalues.keys():
      typeid = config.enumvalues[default]
      if typeid in config.types.keys():
        #print "replacing {0} by {1}::{0} ".format(default,config.types[typeid].GetString())
        return "{1}::{0}".format(default,config.types[typeid].GetString())
    return default
  
  #---------------------------------------------
  def GetDescription(self):
    res=''
    if self.returntype!=None:
      res += config.types[self.returntype].GetFullString()+" "
    if self.name in config.available_operators.keys():
      res += self.search_funcname+"::operator "+self.name+'('
    else:
      res += self.name+'('
    for a in self.args:
      res +=  config.types[a.typeid].GetFullString()+" "+a.name
      if a.default!=None:
        res += " = {0}".format(FormatArgDefault(a.default))
      res += ", "
    if len(self.args)>0:
      res = res[:-2]
    res += ')'
    return res

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
      arg.SetName(argname)
      arg.typeid=typeid
      if default != None:
        arg.default=self.CheckEnumDefault(default)
      else:
        arg.default=None
      self.args.append(arg)
      return True
    else:
      utils.WarningMessage( "Non-argument in method: {0}\n".format(name))

#---------------------------------------------
  def startElement(self, name, attrs):
    # Parse function arguments
    if self.infunc==1:
      return self.CheckArgument(name,attrs)
      
    if self.found or (name != "Function"): return

    funcname = attrs.get('name', None)
    context = attrs.get('context',None)
    #print "funcname=",funcname," context=",context," contextname=",config.types[context].GetFullString()
    
    demangled=attrs.get('demangled',None)
    if demangled==None and config.types[context].GetName()!="::":
        demangled = config.types[context].GetFullString()+"::"+funcname
    
    if (funcname != self.search_funcname):
      if demangled==None: 
        return
      else:
        if  (self.search_funcname != demangled) and \
            (not (self.search_funcname+"(" in demangled)):
          return
    #print "found name = {0}, demangled = {1}".format(funcname,demangled)
    self.found=True
    self.infunc=True
    self.funcid = attrs.get('id',None)
    self.fileid = attrs.get('file', None)
    utils.WarningMessage( "{0}  found, id = {1}".format(funcname,self.funcid))
    self.returntype=attrs.get('returns',None)

  def endElement(self, name):
    if (self.infunc==True) and (name == "Function"):
      self.infunc=False

