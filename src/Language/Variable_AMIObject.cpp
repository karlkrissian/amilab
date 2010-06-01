
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

/*
#define RETURN_VARPTR(type,  value) \
  boost::shared_ptr<type> newval(new type(value)); \
  return Variable<type>::ptr( new Variable<type>(newval));
*/
#include "inrimage.hpp"




//------------------------------------------------------
//------- Variable<AMIObject>
//------------------------------------------------------

/*
/// Copy contents to new variable
template<> BasicVariable::ptr Variable<AMIObject>::NewCopy() const
{
  // TODO copy constructor here
  return NewReference();

  AMIObject::ptr newval( new AMIObject( Pointer()->GetFormat(),
                                      Pointer()->GetVDim(),
                                      Pointer()->GetName(),
                                      Pointer().get()));
  (*newval) = (*Pointer());
  Variable<AMIObject>::ptr newvar(new Variable<AMIObject>(newval));
  return newvar;
}
*/


// Arithmetic operators

/*
/// +a
template<> BasicVariable::ptr Variable<AMIObject>::operator +()
{
  return NewReference();
}

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<AMIObject>::operator ++()
{
  std::cout << "**" << endl;
  RETURN_VARPTR(AMIObject,++RefValue());
}

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<AMIObject>::operator ++(int)
{
  std::cout << "**" << endl;
  RETURN_VARPTR(AMIObject,RefValue()++);
}

/// -a
template<> BasicVariable::ptr Variable<AMIObject>::operator -()
{
  UNARYOP_IMAGE(this->Pointer(), -); 
}

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<AMIObject>::operator --()
{  RETURN_VARPTR(AMIObject,--RefValue()); }

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<AMIObject>::operator --(int)
{  RETURN_VARPTR(AMIObject,RefValue()--);  }



/// a+b
template<> BasicVariable::ptr Variable<AMIObject>::operator +(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),+,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),+);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a+=b
template<> BasicVariable::ptr Variable<AMIObject>::operator +=(const BasicVariable::ptr& b)
{ 
//  if (b->IsNumeric()) {
//    RefValue() += b->GetValueAsDouble();

  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    if (var_im2.get()) {
      // copy option
      (*Pointer())+=(*var_im2->Pointer());
    } else {
      GB_driver.err_print("Error, parameter of += operator points to NULL image\n");
    }
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-b
template<> BasicVariable::ptr Variable<AMIObject>::operator -(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),-,b->GetValueAsDouble());
  } 
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),-);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a-=b
template<> BasicVariable::ptr Variable<AMIObject>::operator -=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() -= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*b
template<> BasicVariable::ptr Variable<AMIObject>::operator *(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),*,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),*);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*=b
template<> BasicVariable::ptr Variable<AMIObject>::operator *=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() *= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/b
template<> BasicVariable::ptr Variable<AMIObject>::operator /(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),/,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),/);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/=b
template<> BasicVariable::ptr Variable<AMIObject>::operator /=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() /= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%b
template<> BasicVariable::ptr Variable<AMIObject>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(AMIObject, ((int) round(Value())) % ((int) round(b->GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> BasicVariable::ptr Variable<AMIObject>::operator %=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b->GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<AMIObject>::operator <(const BasicVariable::ptr& b)
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
template<> BasicVariable::ptr Variable<AMIObject>::operator <=(const BasicVariable::ptr& b)
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
template<> BasicVariable::ptr Variable<AMIObject>::operator >(const BasicVariable::ptr& b)
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
template<> BasicVariable::ptr Variable<AMIObject>::operator >=(const BasicVariable::ptr& b)
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

/// a!=b
template<> BasicVariable::ptr Variable<AMIObject>::operator !=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),!=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),!=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a==b
template<> BasicVariable::ptr Variable<AMIObject>::operator ==(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),==,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(AMIObject,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),==);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


// Logical operators

/*
template<> BasicVariable::ptr Variable<AMIObject>::operator !() 
{
  RETURN_VARPTR(AMIObject,!(Value()>0.5));
}

template<> BasicVariable::ptr Variable<AMIObject>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),==,b->GetValueAsDouble());
    RETURN_VARPTR(AMIObject,Value()&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> BasicVariable::ptr Variable<AMIObject>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(AMIObject,Value() || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a^b
template<> BasicVariable::ptr Variable<AMIObject>::operator ^(const BasicVariable::ptr& b)
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
template<> BasicVariable::ptr Variable<type>::m_##fname() \
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
template<> BasicVariable::ptr Variable<AMIObject>::m_norm() 
{ 
  AMIObject::ptr res ( Norm(*Pointer()));
  if (!res.get())
    fprintf(stderr,"Error computing the norm |image| \n");
  return Variable<AMIObject>::ptr( new Variable<AMIObject>(res)); 
}
//VAR_IMPL_FUNC(AMIObject,  norm, fabs)

// Image Pixel Type Cast
template<> BasicVariable::ptr Variable<AMIObject>::BasicCast(const int& type)
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
    } else {
      GB_driver.yyiperror(" operator[], class member 'at' of this type is not available. \n");
      return this->NewReference(); 
    }
  } else
  {
    return BasicVariable::ptr();
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