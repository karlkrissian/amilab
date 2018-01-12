
#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "amilab_messages.h"
#include "DefineClass.hpp"
#include "Variable.hpp"
#include <math.h>
#include <boost/pointer_cast.hpp>
#include "ami_object.h"
#include "ami_function.h"
#include "paramlist.h"
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"

#include "DriverBase.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT DriverBase::ptr  GB_DriverBase;

#define NEW_SMARTPTR(type, var, value) \
  boost::shared_ptr<type> var(new type(value));

#include "inrimage.hpp"


//------------------------------------------------------------------------------
template<>  AMI_DLLEXPORT 
  Variable<WrapClassMember>::Variable(const boost::shared_ptr<WrapClassMember>& p)
{
  _type    = GetVarType<WrapClassMember>();
  _name    = "tmpvar";
  _pointer = boost::shared_ptr<WrapClassMember>(p);
}

//------------------------------------------------------------------------------
template<>  AMI_DLLEXPORT 
  Variable<WrapClassMember>::Variable( WrapClassMember* p)
{
  _type    = GetVarType<WrapClassMember>();
  _name    = "tmpvar";
  _pointer = boost::shared_ptr<WrapClassMember>(p);
}

//------------------------------------------------------------------------------
template<>  AMI_DLLEXPORT 
  Variable<WrapClassMember>::Variable(const std::string& name, 
           const boost::shared_ptr<WrapClassMember>& p)
{
  _type    = GetVarType<WrapClassMember>();
  _name    = name;
  _pointer = boost::shared_ptr<WrapClassMember>(p);
}

//------------------------------------------------------------------------------
template<>  AMI_DLLEXPORT bool Variable<WrapClassMember>::Equal( BasicVariable::ptr v)
{
  if (_type == v->Type()) {
    // convert pointer
    ptr newvar (boost::dynamic_pointer_cast<Variable<WrapClassMember> >(v));
    return ((_name     == newvar->_name) &&
            (_comments == newvar->_comments) &&
            (_pointer.get()  == newvar->_pointer.get()));

  }
  else return false;
}



//------------------------------------------------------
//------- Variable<WrapClassMember>
//------------------------------------------------------




