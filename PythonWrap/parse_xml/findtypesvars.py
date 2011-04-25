#
# Parse types and variables
#

from xml.sax import saxutils,handler
import config

import argtypes
import re
import args
import utils
import wrap_class

typelist=('Class','Typedef','Struct','FundamentalType','CvQualifiedType','ReferenceType','PointerType','Enumeration','ArrayType','Union','MethodType','Namespace')

variablelist = ('Variable')


#------------------------------
class FindTypesAndVariables(handler.ContentHandler):
  
  #---------------------------------------------
  def __init__(self,class_list):
    self.class_list = class_list
    self.parse_public_members = wrap_class.ParsePublicMembers(class_list)
    self.found=False
    self.number_of_libclasses=0 # classes that match the current library filter
    self.inenum  = False
    self.inclass = False
    self.number_of_files=0 # classes that match the current library filter

  #---------------------------------------------
  def ParseClass(self, name, attrs):
    #print name
    # If it's not a comic element, ignore it
    if (self.inclass)and(name=='Base'):
      baseaccess  = attrs.get('access', None)
      basevirtual = attrs.get('virtual', None)
      if baseaccess=='public':
        basetype = attrs.get('type', None)
        utils.WarningMessage("inherit from {0}\n".format(basetype))
        self.argtype.bases.append((basetype,basevirtual))
      return True
      
    if (name not in config.class_types): return False

    # create the corresponding structure
    self.argtype = eval("argtypes."+name+"Info()")
    
    # Name
    classname = attrs.get('name', None)
    #print "Classname='{0}'".format(classname)
    self.argtype.SetName(classname)
    
    if classname!=None:
      if re.match(args.val.filter, classname) != None:
        self.number_of_libclasses = self.number_of_libclasses +1
    
    
    demangled=attrs.get('demangled',None)
    self.argtype.SetDemangled(demangled)
    
    #print classname
    #if (classname == self.search_classname)or(demangled==self.search_classname):
    #self.found=True
    self.inclass=True
    
    # Class Id
    classid = attrs.get('id', None)
    self.argtype.SetId(classid)
    config.types[classid] = self.argtype
    # Find id from the class name
    if classname!=demangled and demangled!=None and (demangled.startswith("MT")or demangled.startswith("amilab")):
      print "classname != demangled : {0} {1}, using the demangled name".format(classname,demangled)
    config.classes[demangled]=classid
    
    #print "'{0}' '{1}' {2} id:{3}".format(name, classname,demangled,classid)
    found = classname in config.classes.keys()
    #print "found is ", found
    
    # Incomplete
    incomplete = attrs.get('incomplete', '0')
    self.argtype.incomplete = incomplete
    
    if incomplete=='1':
      utils.WarningMessage("Class {0} is incomplete, skipping ...".format(classname))
      config.incomplete_classes.append(classname)
      return True
    
    # Abstract
    self.argtype.abstract = attrs.get('abstract', '0')
    
    # Set Context
    context = attrs.get('context', None)
    if context != None:
      self.argtype.SetContext(context)
    
    # File id
    self.argtype.fileid = attrs.get('file', None)
    
    # Not sure about the utility of this condition!!!
    #if demangled==self.search_classname and classname!=demangled:
      ## add an equivalence of the type name and the demangled name
      #typesubst.type_equivalence[classname]=demangled
    #if classname!=demangled:
      #print "Classname={0} demangled={1}".format(classname,demangled)
      #print "Use class equivalence?"
    utils.WarningMessage( "{0}  found, id = {1}".format(classname,classid))
    return True
  
  #---------------------------------------------
  def startElement(self, name, attrs):

    # first check for variable
    if name == 'File':
      self.number_of_files = self.number_of_files + 1
      fileid = attrs.get('id', None)
      name   = attrs.get('name', None)
      config.files[fileid]=name

    # first check for Files
    if name in variablelist:
      name = attrs.get('name', None)
      if name == None: return
      typeid = attrs.get('type', None)
      if typeid == None: return
      config.variables[name]=typeid
      #print "added var ", name
      return

    if self.ParseClass(name,attrs):
      return
    
    # Check for public members of user-given classes
    if self.parse_public_members.startElement(name,attrs):
      # if parsing has found the right contexts, and there is nothing else to process
      return
    
    # Deal with these enums after the possible classes enum members
    if self.inenum and name =="EnumValue":
      name = attrs.get('name', None)
      val = attrs.get('init',0)
      config.enumvalues[name]=self.argtype.GetContext()
      self.argtype._values[name]=val
      return
    
    # ignore elements that cannot be argument types
    if not (name in typelist): return

    # first check for variable
    if name =="Enumeration": self.inenum = True

    # create the corresponding structure
    self.argtype = eval("argtypes."+name+"Info()")
    
    # Look for the title and number attributes (see text)
    id = attrs.get('id', None)
    self.argtype.SetId(id)
    config.types[id] = self.argtype

    typeid = attrs.get('type',None)
    if (typeid!=None):
      self.argtype.SetRefTypeId(typeid)

    context = attrs.get('context', None)
    if context != None:
      self.argtype.SetContext(context)

    name = attrs.get('name', None)
    if name != None:
      self.argtype.SetName(name)
      
    const = attrs.get('const', None)
    if const != None:
      self.argtype.SetConst(const)

    # store abstract
    abstract = attrs.get('abstract', None)
    if abstract == "1":
      self.argtype.SetAbstract(abstract)
    
  #-------------------------------------------------------
  def endElement(self, name):
    if (self.inenum==True) and (name =="Enumeration"):
      self.inenum=False
    if (self.inclass==True) and (name =="Class"):
      #print self.argtype.bases
      self.inclass=False
    self.parse_public_members.endElement(name)

