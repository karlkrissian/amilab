#
# Parse types and variables
#

import xml.etree.ElementTree as ET
import config

import argtypes
import re
import args
import utils
import wrap_class

typelist=(
    'Class',
    'Typedef',
    'Struct',
    'FundamentalType',
    'CvQualifiedType',
    'ReferenceType',
    'PointerType',
    'Enumeration',
    'ArrayType',
    'Union',
    'MethodType',
    'Namespace',
    'OperatorFunction')

variablelist = ('Variable')


#------------------------------
class FindTypesAndVariables():
  
  #---------------------------------------------
  def __init__(self, class_list):
    self.class_list = class_list
    #self.parse_public_members = wrap_class.ParsePublicMembers(class_list)
    self.found=False
    self.number_of_libclasses=0 # classes that match the current library filter
    self.inenum  = False
    self.inclass = False
    self.inoperatorfunction = False
    self.number_of_files=0 # classes that match the current library filter
    print "FindTypesAndVariables"

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
  def ParseClass(self, tag, attrs):
    # If it's not a comic element, ignore it
    if (self.inclass)and(tag=='Base'):
      baseaccess  = attrs.get('access', None)
      basevirtual = attrs.get('virtual', None)
      if baseaccess=='public':
        basetype = attrs.get('type', None)
        utils.WarningMessage("inherit from {0}\n".format(basetype))
        self.argtype.bases.append((basetype,basevirtual))
      return True
      
    # allow namespaces
    if (tag!="Namespace"):
      if (tag not in config.class_types): return False

    # create the corresponding structure
    self.argtype = eval("argtypes."+tag+"Info()")
    
    # Class Id
    classid = attrs.get('id', None)
    self.argtype.SetId(classid)
    
    # Name
    classname = attrs.get('name', None)
    if tag=='Typedef':
      print "typedef='{0}'".format(classname)
    if classname=="":
        # replace empty name by type+id
        classname=tag+classid
    self.argtype.SetName(classname)
    
    if classname!=None:
      if re.match(args.val.filter, classname) != None:
        self.number_of_libclasses = self.number_of_libclasses +1
    
    # Set Context
    context = attrs.get('context', None)
    if context != None:
      self.argtype.SetContext(context)
    
    demangled=attrs.get('demangled',None)
    #print "demangled = ",demangled
    #print "tag = ",tag
    #print "----- classname =",classname,
    if classname!=None:
        if demangled==None:
            demangled=classname
            #print "context = ", context,
            try:
                context_type = config.types[context]
                if context_type.GetType() in [ "Namespace", "Class", "Struct" ]:
                    #print config.types[context].GetDemangled()
                    if context_type.GetDemangled()!="::":
                        demangled = context_type.GetDemangled() + "::"+demangled
            except:
                pass
    #print " setting demangled to ",demangled
    self.argtype.SetDemangled(demangled)
    
    #print classname
    #if (classname == self.search_classname)or(demangled==self.search_classname):
    #self.found=True
    self.inclass=True
    
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
        
    # File id
    self.argtype.fileid = attrs.get('file', None)
    #print "fileid = ", self.argtype.fileid 
    
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
  def startElement(self, tag, attrs):

    # first check for Files
    if tag == 'File':
      self.number_of_files = self.number_of_files + 1
      fileid = attrs.get('id', None)
      name   = attrs.get('name', None)
      config.files[fileid]=name

    # first check for variable
    if tag in variablelist:
      name = attrs.get('name', None)
      if name == None: return
      typeid = attrs.get('type', None)
      if typeid == None: return
      config.variables[name]=typeid
      #print "added var ", name
      return

    if self.ParseClass(tag,attrs):
      return
    
    ## don't parse public members if only looking at the class hierarchy
    #if args.val.ancestors == []:
      ## Check for public members of user-given classes
      #if self.parse_public_members.startElement(name,attrs):
        ## if parsing has found the right contexts, and there is nothing else to process
        #return
    
    # don't parse enums if only looking at the class hierarchy
    if args.val.ancestors == []:
      # Deal with these enums after the possible classes enum members
      if self.inenum and tag =="EnumValue":
        name = attrs.get('name', None)
        val = attrs.get('init',0)
        config.enumvalues[name]=self.argtype.GetContext()
        self.argtype._values[name]=val
        return
      
      # parse first argument of operatorfunction
      if self.inoperatorfunction and tag=='Argument':
        self.argtype._first_argument_id = attrs.get('type',0)
        self.inoperatorfunction = False
        return
    
    # don't parse non-classes types if only looking at the class hierarchy
    if args.val.ancestors == []:
      # ignore elements that cannot be argument types
      if not (tag in typelist): return
    else:
      # accept classes or typedefs ...
      if (not (tag in config.class_types)) and (tag != "Typedef"): return

    # first check for variable
    if tag =="Enumeration": self.inenum = True

    # first check for variable
    if tag =="OperatorFunction": self.inoperatorfunction = True

    # create the corresponding structure
    self.argtype = eval("argtypes."+tag+"Info()")
    
    # Look for the title and number attributes (see text)
    id = attrs.get('id', None)
    self.argtype.SetId(id)
    config.types[id] = self.argtype

    typeid = attrs.get('type',None)
    if (typeid!=None):
      self.argtype.SetRefTypeId(typeid)

    # Store typedefs
    if tag=="Typedef":
      name_attribute = attrs.get('name', None)
      config.typedefs[name_attribute]=id
      # File id
      self.argtype.fileid = attrs.get('file', None)
      #print "Added typedef {0} {1} {2}".format(name,id,self.argtype.GetRealType())
      if name_attribute=="string":
        print "found string typedef"
        print config.types[typeid].demangled
        # change type name and demanged?

    context = attrs.get('context', None)
    if context != None:
      self.argtype.SetContext(context)

    name_attribute = attrs.get('name', None)
    if name_attribute != None:
      self.argtype.SetName(name_attribute)
      
    const = attrs.get('const', None)
    if const != None:
      self.argtype.SetConst(const)

    # store abstract
    abstract = attrs.get('abstract', None)
    if abstract == "1":
      self.argtype.SetAbstract(abstract)
    
  #-------------------------------------------------------
  def endElement(self, name):
    if (self.inenum==True)              and (name =="Enumeration"):
      self.inenum=False
    if (self.inoperatorfunction==True)  and (name =="OperatorFunction"):
      self.inoperatorfunction=False
    if (self.inclass==True)             and (name =="Class"):
      #print self.argtype.bases
      self.inclass=False
    #if args.val.ancestors == []:
      #self.parse_public_members.endElement(name)


#-------------------------------------------------------------------------------
class FindPublicMembers():
  #---------------------------------------------
  def __init__(self,class_list):
    print "FindPublicMembers.__init__"
    self.parse_public_members = wrap_class.ParsePublicMembers(class_list)
    self.found=False

  #---------------------------------------------
  def parse(self, xmltree, tagfilter):
    self.tagfilter = tagfilter
    # go through elements
    root = xmltree.getroot()
    print " nb of elemnts = ", len(list(root))
    self.parseElt(root, 0)

  #---------------------------------------------
  def parseElt(self,elt, level):
    self.startElement(elt.tag, elt.attrib)
    if level==0:
      index = 0
      size = len(list(elt))
      percent = 0
      filter_count = 0
    for child in list(elt):
      if self.tagfilter==None or child.tag in self.tagfilter:
          self.parseElt(child, level+1)
      if level==0:
          index = index+1
          prev_percent = percent
          percent = index*100/size
          if self.tagfilter==None or child.tag in self.tagfilter:
            filter_count = filter_count + 1
          if percent>prev_percent+5:
            print "done {0} % count {1}".format(percent,filter_count)
            filter_count = 0
          else:
              percent = prev_percent
    self.endElement(elt.tag)

  #---------------------------------------------
  def startElement(self, name, attrs):
    # don't parse public members if only looking at the class hierarchy
    #if args.val.ancestors == []:
    #print "FindPublicMembers.startElement( ", name, ", ..)"
    # Check for public members of user-given classes
    if self.parse_public_members.startElement(name,attrs):
      # if parsing has found the right contexts, and there is nothing 
      # else to process
      return
  #-------------------------------------------------------
  def endElement(self, name):
    #if args.val.ancestors == []:
    self.parse_public_members.endElement(name)
