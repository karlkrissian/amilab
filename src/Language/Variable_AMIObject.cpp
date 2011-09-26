
#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "amilab_messages.h"
#include "DefineClass.hpp"
#include "Variable.hpp"
#include <math.h>
#include "driver.h"
#include <boost/pointer_cast.hpp>
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"

extern yyip::Driver GB_driver;

#define NEW_SMARTPTR(type, var, value) \
  boost::shared_ptr<type> var(new type(value));

#include "inrimage.hpp"


/**
 * \def APPLY_MEMBER_PARAM0
 * \brief applies the given variable member with no parameter
 **/
#define APPLY_MEMBER_NOPARAM(member_name, resvar) \
  AMIObject::ptr object(this->Pointer()); \
  BasicVariable::ptr member = object->GetContext()->GetVar(member_name); \
  BasicVariable::ptr resvar; \
  if (member.get()) { \
    if (member->Type()==type_class_member) { \
      DYNAMIC_CAST_VARIABLE(WrapClassMember,member, var1); \
      resvar = (var1->Pointer())->CallMember(NULL); \
    } else \
    if (member->Type()==type_ami_function) { \
      DYNAMIC_CAST_VARIABLE(AMIFunction,member, var1); \
      AMIFunction::ptr f(var1->Pointer()); \
      resvar = GB_driver.yyip_call_function(f.get()); \
    } else \
    { \
      GB_driver.yyiperror((boost::format("Class member '%1%' for this type is not available. ") % member_name ).str().c_str()); \
    } \
  }

/**
 * \def APPLY_MEMBER_PARAM1
 * \brief applies the given variable member with 1 parameter
 **/
#define APPLY_MEMBER_PARAM1(member_name, varparam, resvar) \
  AMIObject::ptr object(this->Pointer()); \
  BasicVariable::ptr member = object->GetContext()->GetVar(member_name); \
  BasicVariable::ptr resvar; \
  if (member.get()) { \
    ParamList::ptr param(new ParamList()); \
    param->AddParam(varparam); \
    if (member->Type()==type_class_member) { \
      DYNAMIC_CAST_VARIABLE(WrapClassMember,member, var1); \
      resvar = (var1->Pointer())->CallMember(param.get()); \
    } else \
    if (member->Type()==type_ami_function) { \
      DYNAMIC_CAST_VARIABLE(AMIFunction,member, var1); \
      AMIFunction::ptr f(var1->Pointer()); \
      resvar = GB_driver.yyip_call_function(f.get(),param); \
    } else \
    { \
      GB_driver.yyiperror((boost::format("Class member '%1%' for this type is not available. ") % member_name ).str().c_str()); \
    } \
  }


//------------------------------------------------------
//------- Variable<AMIObject>
//------------------------------------------------------

/// Cast to a type based on its name as a string
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::TryCast(const std::string& type_string) const
{
  //Modified: Added (12-07-2010)
  string_ptr value( new std::string(type_string));
  Variable<std::string>::ptr b( new Variable<std::string>( type_string, value));

  APPLY_MEMBER_PARAM1("try_cast", b, varres)
  if (varres.get())
    return varres;
  else
    return BasicVariable::ptr();
}

/// Copy contents to new variable
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::NewCopy() const
{
  APPLY_MEMBER_NOPARAM("__copy__", varres)
  if (varres.get()) return varres;
  {
    // for compatibility only
    APPLY_MEMBER_NOPARAM("copy", varres)
    if (varres.get()) return varres;
  }
  return BasicVariable::ptr();
}



/// new variable as a reference to the current variable
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::NewReference() const
{
  std::string resname = _name+"_ref";
  ptr ref(new Variable<AMIObject>(resname,_pointer));
  // copy the comments
  ref->SetComments(_comments);
  // give the oportunity to deal with this new reference
  // TODO: find a solution, are there too many variable references ???
  // could this slow down considerably amilab??
  // should we have a boolean saying that the reference needs special treatment?
  APPLY_MEMBER_PARAM1("__reference__", ref, varres);
  return ref;
}

// Arithmetic operators

/*
/// +a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator +()
{
  return NewReference();
}



/// -a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator -()
{
  UNARYOP_IMAGE(this->Pointer(), -); 
}

/// prefix -- operator --a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator --()
{  RETURN_VARPTR(AMIObject,--RefValue()); }


*/

/// prefix * operator *a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator *()
{
  APPLY_MEMBER_NOPARAM("__indirection__", varres)
  if (varres.get()) return varres;
  return BasicVariable::ptr();
}

/// prefix ++ operator ++a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator ++()
{
  APPLY_MEMBER_NOPARAM("__preinc__", varres)
  if (varres.get()) return varres;
  return BasicVariable::ptr();
}

/// postfix ++ operator a++
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator ++(int)
{
  APPLY_MEMBER_NOPARAM("__postinc__", varres)
  if (varres.get()) return varres;
  return BasicVariable::ptr();
}

/// prefix -- operator --a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator --()
{
  APPLY_MEMBER_NOPARAM("__predec__", varres)
  if (varres.get()) return varres;
  return BasicVariable::ptr();
}

/// postfix -- operator a--
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator --(int)
{
  APPLY_MEMBER_NOPARAM("__postdec__", varres)
  if (varres.get()) return varres;
  return BasicVariable::ptr();
}

/// a+b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator +(const BasicVariable::ptr& b)
{
  APPLY_MEMBER_PARAM1("__add__", b, varres)
  if (varres.get()) return varres;
  {
    // for compatibility only
    APPLY_MEMBER_PARAM1("add", b, varres)
    if (varres.get()) return varres;
  }
  return BasicVariable::ptr();
}


/// a+=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator +=(const BasicVariable::ptr& b)
{ 
  APPLY_MEMBER_PARAM1("__add_assign__", b, varres)
  if (varres.get()) return varres;
  {
    // for compatibility only
    APPLY_MEMBER_PARAM1("add_assign", b, varres)
    if (varres.get()) return varres;
  }
  return BasicVariable::ptr();
}

/// a-b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator -(const BasicVariable::ptr& b)
{
  APPLY_MEMBER_PARAM1("__substract__", b, varres)
  if (varres.get()) return varres;
  {
    // for compatibility only
    APPLY_MEMBER_PARAM1("substract", b, varres)
    if (varres.get()) return varres;
  }
  return BasicVariable::ptr();
}

/// a-=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator -=(const BasicVariable::ptr& b)
{ 
  APPLY_MEMBER_PARAM1("__sub_assign__", b, varres)
  if (varres.get()) return varres;
  {
    // for compatibility only
    APPLY_MEMBER_PARAM1("sub_assign", b, varres)
    if (varres.get()) return varres;
  }
  return BasicVariable::ptr();
}

/// a*b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator *(const BasicVariable::ptr& b)
{
  APPLY_MEMBER_PARAM1("__mult__", b, varres)
  if (varres.get()) return varres;
  return BasicVariable::ptr();
}

/// a*=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator *=(const BasicVariable::ptr& b)
{ 
  APPLY_MEMBER_PARAM1("__mult_assign__", b, varres)
  if (varres.get()) return varres;
  return BasicVariable::ptr();
}

/// a/b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator /(const BasicVariable::ptr& b)
{
  APPLY_MEMBER_PARAM1("__div__", b, varres)
  if (varres.get()) return varres;
  return BasicVariable::ptr();
}

/// a/=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator /=(const BasicVariable::ptr& b)
{ 
  APPLY_MEMBER_PARAM1("__div_assign__", b, varres)
  if (varres.get()) return varres;
  return BasicVariable::ptr();
}

/*

/// a*=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator *=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() *= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


/// a/=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator /=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() /= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(AMIObject, ((int) round(Value())) % ((int) round(b->GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator %=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b->GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

//  Comparison Operators

/// a<b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator <(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),<,b->GetValueAsDouble());
  } 
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),<);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator <=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),<=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),<=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator >(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),>,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),>);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator >=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),>=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),>=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/
/// a!=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator !=(const BasicVariable::ptr& b)
{ 
  APPLY_MEMBER_PARAM1("__not_equal__", b, varres)
  if (varres.get()) return varres;
  {
    // for compatibility only
    APPLY_MEMBER_PARAM1("not_equal", b, varres)
    if (varres.get()) return varres;
  }
  return BasicVariable::ptr();
}

/// a==b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator ==(const BasicVariable::ptr& b)
{ 
  APPLY_MEMBER_PARAM1("__equal__", b, varres)
  if (varres.get()) return varres;
  {
    // for compatibility only
    APPLY_MEMBER_PARAM1("equal", b, varres)
    if (varres.get()) return varres;
  }
  return BasicVariable::ptr();
}


// Logical operators

/*
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator !() 
{
  RETURN_VARPTR(AMIObject,!(Value()>0.5));
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),==,b->GetValueAsDouble());
    RETURN_VARPTR(AMIObject,Value()&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(AMIObject,Value() || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a^b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator ^(const BasicVariable::ptr& b)
{ 
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),^);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Mathematical functions

#define VAR_IMPL_FUNC(type,fname,func) \
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<type>::m_##fname() \
{ \
  UNARYOP_IMAGE(this->Pointer(), func); \
}

VAR_IMPL_FUNC(AMIObject,  sin,  sin)
VAR_IMPL_FUNC(AMIObject,  cos,  cos)
VAR_IMPL_FUNC(AMIObject,  tan,  tan)
VAR_IMPL_FUNC(AMIObject,  asin, asin)
VAR_IMPL_FUNC(AMIObject,  acos, acos)
VAR_IMPL_FUNC(AMIObject,  atan, atan)
VAR_IMPL_FUNC(AMIObject,  fabs, fabs)
VAR_IMPL_FUNC(AMIObject,  round,round)
VAR_IMPL_FUNC(AMIObject,  floor,floor)
VAR_IMPL_FUNC(AMIObject,  exp,  exp)
VAR_IMPL_FUNC(AMIObject,  log,  1.0/log(10.0)*log)
VAR_IMPL_FUNC(AMIObject,  ln,   log)
VAR_IMPL_FUNC(AMIObject,  sqrt, sqrt)

//  norm(image)
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::m_norm() 
{ 
  AMIObject::ptr res ( Norm(*Pointer()));
  if (!res.get())
    fprintf(stderr,"Error computing the norm |image| \n");
  return Variable<AMIObject>::ptr( new Variable<AMIObject>(res)); 
}
//VAR_IMPL_FUNC(AMIObject,  norm, fabs)

// Image Pixel Type Cast
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::BasicCast(const int& type)
{
  AMIObject::ptr res  ( new AMIObject( (WORDTYPE) type, "castimage.ami.gz", Pointer().get()));
  (*res) = (*Pointer());
  return Variable<AMIObject>::ptr( new Variable<AMIObject>(res)); 
}
*/

/**
 * Array subscript operator
 * @param v 
 * @return 
 */
template<>  BasicVariable::ptr Variable<AMIObject>::operator[](const BasicVariable::ptr& v)
{

/*
        // 1. check the variable type
        GET_CHECK_VARSTACK(var)
        ParamList::ptr param($3);

        // TODO: run this with overloading from BasicVariable ...
        if (var->Type()==type_class_member) {
          ///    Call a wrapped C++ class member.
          DYNAMIC_CAST_VARIABLE(WrapClassMember,var, var1);
          BasicVariable::ptr res ((var1->Pointer())->CallMember(param.get()));
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_ami_function) 
        {
          ///    Call a language function with its parameters.
          DYNAMIC_CAST_VARIABLE(AMIFunction,var, var1);
          AMIFunction::ptr f(var1->Pointer());
          BasicVariable::ptr res(driver.yyip_call_function(f,param));
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_c_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_varfunction,var, func);
          BasicVariable::ptr  res;
          res = (*func->Pointer())(param.get());
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_procedure) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_procedure,var, func);
          BasicVariable::ptr  res;
          (*func->Pointer())(param.get());
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_image_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_imagefunction,var, func);
          InrImage::ptr  im((*func->Pointer())(param.get()));
          if (!im.get()) {
            driver.yyiperror(" image function returns NULL \n");
            YYABORT;
          }
          Variable<InrImage>::ptr res(new Variable<InrImage>(im));
          driver.var_stack.AddVar(res);
        } else
        {
          // error message here
          driver.yyiperror("variable is not of a function type \n");
          driver.var_stack.AddVar(BasicVariable::ptr());
        }
      }
*/
  // todo ... 
  // 1. check if identifier belongs to the object
  // 2. if so return corresponding variable
  AMIObject::ptr object(this->Pointer());

  // looking for function member named at
  BasicVariable::ptr member = object->GetContext()->GetVar("at");
  if (!member.get()) {
    member = object->GetContext()->GetVar("__at__");
  }

  if (member.get()) {
    // Create a paramlist from the parameter
    ParamList::ptr param(new ParamList());
    BasicVariable::ptr newvar(v->NewReference());
    param->AddParam(newvar);

    // check the type of the member variable
    if (member->Type()==type_class_member) {
      ///    Call a wrapped C++ class member.
      DYNAMIC_CAST_VARIABLE(WrapClassMember,member, var1);
      BasicVariable::ptr res ((var1->Pointer())->CallMember(param.get()));
      return res;
    } else 
    if (member->Type()==type_ami_function) { 
      DYNAMIC_CAST_VARIABLE(AMIFunction,member, var1); 
      AMIFunction::ptr f(var1->Pointer()); 
      return GB_driver.yyip_call_function(f.get(),param); 
    } else {
      GB_driver.yyiperror(" operator[], class member 'at' (or '__at__') of this type is not available. \n");
      return BasicVariable::empty_variable; 
    }
  } else
  {
    return BasicVariable::empty_variable;
  }
}


/*
//
template<>
BasicVariable::ptr Variable<AMIObject>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2)
{

  if (IsNumeric()) {
    if (GetValueAsDouble()>0.5) {
      return v1->NewReference();
    } else {
      return v2->NewReference();
    }
  } else
    CLASS_ERROR("operation not defined");
  return NewReference();
}

/// Other operators
/// a=b
template<> 
BasicVariable::ptr Variable<AMIObject>::operator =(const BasicVariable::ptr& b)
{
  CLASS_MESSAGE("begin");
  if (b->IsNumeric()) {
    Pointer()->InitImage(b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    if (var_im2.get()) {
      // copy option
      if (!((*Pointer())=(*var_im2->Pointer()))) GB_driver.err_print(" Error in images assignement\n");
    } else {
      if (GB_driver.err_print("Error, empty variable as parameter of assignment operator\n"));
    }
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::operator =(const BasicVariable::ptr& b)
{
  APPLY_MEMBER_PARAM1("__assign__", b, varres)
  if (varres.get()) return varres;
  {
    // for compatibility only
    APPLY_MEMBER_PARAM1("assign", b, varres)
    if (varres.get()) return varres;
  }
  return BasicVariable::ptr();
}


// TODO: put this code within a macro???
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<AMIObject>::left_assign(const BasicVariable::ptr& b)
{
  APPLY_MEMBER_PARAM1("__left_assign__", b, varres)
  if (varres.get()) return varres;
  {
    // for compatibility only
    APPLY_MEMBER_PARAM1("left_assign", b, varres)
    if (varres.get()) return varres;
  }
  return BasicVariable::ptr();
}
