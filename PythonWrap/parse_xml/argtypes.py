#
# Organize the different types for function arguments
# 

import config
import utils
import typesubst

#------------------------------
class ArgTypeBase:
  def __init__(self):
    self._type=""
    self._name=""
    self._id=0
    self._context=None
    self._bases=None
    self._abstract=None

  def SetType(self,t):
    self._type=t
  
  def GetType(self):
    return self._type
    
  def SetName(self,n):
    self._name=n
  
  def SetBases(self,_b):
    self._bases = _b

  def GetBases(self):
    return self._bases
    
  def SetAbstract(self,_b):
    self._abstract = _b

  def GetAbstract(self):
    return self._abstract
    
  def SetId(self,_id):
    self._id = _id

  def GetId(self):
    return self._id
  def SetRefTypeId(self,t):
    self._reftypeid=t

  def GetFullString(self):
    return self._name

  def GetMainTypeId(self):
    return self._id

  def GetString(self):
    return self._name
    
  def IsConst(self):
    return False
    
  def SetContext(self,context):
    #utils.WarningMessage(" type {0} context {1} ".format(self._name,context) )
    self._context = context
    
  def GetContext(self):
    return self._context


# organize a little bit the information
#------------------------------
class ClassInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self.publicmembers=()
    self._type="Class"
    self._bases=[]
    self.bases=()

#------------------------------
class ArgumentInfo:
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self.name=""

#------------------------------
class MemberInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="Member"

#------------------------------
class TypedefInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="Typedef"
    
  def GetString(self):
    if self._reftypeid in config.types.keys():
      #print config.types[self._reftypeid].GetString()
      # if member typedef (or function), keep the typedef name
      if config.types[self._reftypeid].GetString()=="__MethodType__":
        typename=self._name
      else:
        typename=config.types[self._reftypeid].GetString()
    else:
      typename=self._reftypeid
    return typename

  def GetMainTypeId(self):
    if self._reftypeid in config.types.keys():
      return config.types[self._reftypeid].GetId()
    else:
      return self.GetId()

#------------------------------
class StructInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="Struct"

#------------------------------
class EnumerationInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="Enumeration"
    self._values={}

  def SetName(self,n):
    self._name=n
    # register global enums or enums that belong to available types
    if (self._context=="_1") or (self._context in config.types.keys()):
      self.Register()
      
    
  def Register(self):
    utils.WarningMessage("Registering enum type {0} with 'int' substitution".format(self.GetString()))
    typesubst.type_substitute[self.GetString()]='int'

  def GetString(self):
    if self._context != None:
      if self._context in config.types.keys():
        return "{0}::{1}".format(config.types[self._context].GetString(),self._name)
      else:
        return self._name
    else:
      return self._name

  def GetFullString(self):
    return self.GetString()

#------------------------------
class FundamentalTypeInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="FundamentalType"

#------------------------------
class UnionInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="Union"

#------------------------------
class ArrayTypeInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="ArrayType"

  def GetString(self):
    if self._reftypeid in config.types.keys():
      typename=config.types[self._reftypeid].GetString()
    else:
      typename=self._reftypeid
    return typename
#------------------------------
class MethodTypeInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="MethodType"
    self.const="0"
  
  def GetString(self):
    return "__MethodType__"

  def SetConst(self,v):
    self.const = v

#------------------------------
class CvQualifiedTypeInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="CvQualifiedType"
    self.const="0"

  def SetConst(self,v):
    self.const = v

  def GetFullString(self):
    if self._reftypeid in config.types.keys():
      typename=config.types[self._reftypeid].GetFullString()
    else:
      typename=self._reftypeid
    if self.const=="1":
      return typename+" const"
    else:
      return typename
  
  def GetString(self):
    if self._reftypeid in config.types.keys():
      typename=config.types[self._reftypeid].GetString()
    else:
      typename=self._reftypeid
    return typename

  def GetAbstract(self):
    if self._reftypeid in config.types.keys():
      return config.types[self._reftypeid].GetAbstract()
    return None

  def GetMainTypeId(self):
    if self._reftypeid in config.types.keys():
      return config.types[self._reftypeid].GetMainTypeId()
    else:
      return self.GetId()
      
  def IsConst(self):
    return self.const=="1"

#------------------------------
class ReferenceTypeInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="ReferenceType"
  
  def GetFullString(self):
    if self._reftypeid in config.types.keys():
      typename=config.types[self._reftypeid].GetFullString()
    else:
      typename=self._reftypeid
    return typename+" &"

  def GetString(self):
    if self._reftypeid in config.types.keys():
      typename=config.types[self._reftypeid].GetString()
    else:
      typename=self._reftypeid
    return typename

  def GetAbstract(self):
    if self._reftypeid in config.types.keys():
      return config.types[self._reftypeid].GetAbstract()
    return None

  def GetMainTypeId(self):
    if self._reftypeid in config.types.keys():
      return config.types[self._reftypeid].GetMainTypeId()
    else:
      return self.GetId()
#------------------------------
class PointerTypeInfo(ArgTypeBase):
  def __init__(self):
    ArgTypeBase.__init__(self) 
    self._type="PointerType"
  
  def GetFullString(self):
    if self._reftypeid in config.types.keys():
      typename=config.types[self._reftypeid].GetFullString()
    else:
      typename=self._reftypeid
    return typename+" *"

  def GetString(self):
    if self._reftypeid in config.types.keys():
      typename=config.types[self._reftypeid].GetString()
    else:
      typename=self._reftypeid
    return typename

  def GetMainTypeId(self):
    if self._reftypeid in config.types.keys():
      return config.types[self._reftypeid].GetMainTypeId()
    else:
      return self.GetId()
