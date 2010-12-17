#
# Parse types and variables
#

from xml.sax import saxutils,handler
import config

import argtypes
import re
import args

typelist=('Class','Typedef','Struct','FundamentalType','CvQualifiedType','ReferenceType','PointerType','Enumeration','ArrayType','Union','MethodType')

variablelist = ('Variable')


#------------------------------
class FindTypesAndVariables(handler.ContentHandler):
  def __init__(self):
    self.found=False
    self.number_of_libclasses=0 # classes that match the current library filter
    self.inenum = False

  def startElement(self, name, attrs):

    # first check for variable
    if name in variablelist:
      name = attrs.get('name', None)
      if name == None: return
      typeid = attrs.get('type', None)
      if typeid == None: return
      config.variables[name]=typeid
      #print "added var ", name
      return

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

    if name=="Class":
      if re.match(args.val.filter, attrs.get('name', None)) != None:
        self.number_of_libclasses = self.number_of_libclasses +1

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

    # store bases
    bases = attrs.get('bases', None)
    if bases != None:
      self.argtype.SetBases(bases)
    
    # store abstract
    abstract = attrs.get('abstract', None)
    if abstract == "1":
      self.argtype.SetAbstract(abstract)
    
  def endElement(self, name):
    if (self.inenum==True) and (name =="Enumeration"):
      self.inenum=False

