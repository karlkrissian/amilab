
from xml.sax import saxutils,handler
import utils
import re

import config
# load command line arguments
import args
# type substitution
import typesubst

#-------------------------------------------------------------
# Find class
#-------------------------------------------------------------

#-------------------------------------------------------------
def ClassUsedName(classname):
  res = classname
  res = res.replace('<','_')
  res = res.replace('>','_')
  res = res.replace(',','_')
  return res

def IsTemplate(classname):
  return re.match(r"(.*)<(.*)>",classname)!=None

def ClassConstructor(classname):
  ctemp = re.match(r"(.*)<(.*)>",classname)
  if ctemp==None:
    return classname
  else:
    return ctemp.group(1)

#-------------------------------------------------------------
class FindClass(handler.ContentHandler):
  def __init__(self, classname):
    self.search_classname = classname
    self.found=False
    self.bases=[]
    self.inclass=False
    self.abstract="0"
    self.incomplete="0"
    self.has_copyconstr=False
    self.fileid=""

  def startElement(self, name, attrs):
    #print name
    # If it's not a comic element, ignore it
    if (self.inclass)and(name=='Base'):
      baseaccess  = attrs.get('access', None)
      basevirtual = attrs.get('virtual', None)
      if baseaccess=='public':
        basetype = attrs.get('type', None)
        utils.WarningMessage("inherit from {0}\n".format(config.types[basetype].GetString()))
        self.bases.append((basetype,basevirtual))
      return
      
    if (name not in config.class_types): return

    # Look for the title and number attributes (see text)projects/Install/InsightToolkit-3.20.0/CableSwig/
    classname = attrs.get('name', None)
    demangled=attrs.get('demangled',None)
    incomplete = attrs.get('incomplete', '0')
    if (classname != self.search_classname)and(demangled!=self.search_classname):
      return
    if incomplete=='1':
      utils.WarningMessage("Class {0} is incomplete, skipping ...".format(classname))
      config.incomplete_classes.append(classname)
      return
    #print classname
    if (classname == self.search_classname)or(demangled==self.search_classname):
      self.found=True
      self.inclass=True
      self.classid = attrs.get('id',None)
      self.abstract = attrs.get('abstract', '0')
      self.fileid = attrs.get('file', None)
      if demangled==self.search_classname and classname!=demangled:
        # add an equivalence of the type name and the demangled name
        typesubst.type_equivalence[classname]=demangled
      utils.WarningMessage( "{0}  found, id = {1}".format(classname,self.classid))

  def endElement(self, name):
    if (self.inclass==True) and (name in config.class_types):
      self.inclass=False
