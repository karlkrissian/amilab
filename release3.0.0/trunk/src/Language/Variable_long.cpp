
#include "amilab_messages.h"
#include "DefineClass.hpp"
#include "Variable.hpp"
#include <math.h>

#define NEW_SMARTPTR(type, var, value) \
  boost::shared_ptr<type> var(new type(value));

#define RETURN_VARPTR(type,  value) \
  boost::shared_ptr<type> newval(new type(value)); \
  return Variable<type>::ptr( new Variable<type>(newval));

#include "inrimage.hpp"



#define EXPR_OP_IMAGE(expr,operator,im)      \
  {       \
    InrImage::ptr res;                          \
    if (im.use_count()==1) res = im; \
    else {\
      res = InrImage::ptr(new InrImage( im->GetFormat(),\
                                        im->GetVDim(),\
                                        (im->GetName()+std::string("_op_expression")).c_str(),\
                                        im.get()));\
      (*res) = (*im);\
    }\
    int       i;                                           \
    double    val = expr;                                  \
    res->InitBuffer();                                     \
    if( res->ScalarFormat() ){                           \
      do {                                              \
        res->FixeValeur(val operator res->ValeurBuffer()); \
      } while (res->IncBuffer());             \
    }else{                                                  \
      do {                                              \
        for(i=0;i<res->GetVDim();i++) {                         \
          res->VectFixeValeur(i,val operator res->VectValeurBuffer(i));  \
        }                                            \
      } while(res->IncBuffer());              \
    }                                                  \
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); \
  }

//------------------------------------------------------
//------- Variable<long>
//------------------------------------------------------

/// Copy contents to new variable
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::NewCopy() const
{
  long_ptr newval( new long int(Value()));
  Variable<long int>::ptr newvar(new Variable<long int>(newval));
  return newvar;
}


// Arithmetic operators

/// +a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator +()
{  RETURN_VARPTR(long int,Value());}

/// prefix ++ operator ++a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator ++()
{
  //std::cout << "**" << std::endl;
  RETURN_VARPTR(long int,++RefValue());
}

/// postfix ++ operator a++
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator ++(int)
{
  //std::cout << "**" << std::endl;
  RETURN_VARPTR(long int,RefValue()++);
}

/// -a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator -()
{   RETURN_VARPTR(long int,-Value());}

/// prefix -- operator --a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator --()
{  RETURN_VARPTR(long int,--RefValue()); }

/// postfix -- operator a--
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator --(int)
{  RETURN_VARPTR(long int,RefValue()--);  }



/// a+b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator +(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()+b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    EXPR_OP_IMAGE(Value(), + , var_im2->Pointer());
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a+=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator +=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() += b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator -(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()-b->GetValueAsDouble());
  }
  else
 if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    EXPR_OP_IMAGE(Value(), -, var_im2->Pointer());
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator -=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() -= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator *(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()*b->GetValueAsDouble());
  } 
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    EXPR_OP_IMAGE(Value(), * , var_im2->Pointer());
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator *=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() *= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator /(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()/b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    EXPR_OP_IMAGE(Value(), / , var_im2->Pointer());
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator /=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() /= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int, ((int) round(Value())) % ((int) round(b->GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator %=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b->GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

//  Comparison Operators

/// a<b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator <(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()<b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator <=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()<=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator >(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()>b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator >=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()>=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator !=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()!=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


/// a==b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator ==(const BasicVariable::ptr& b)
{ 
  //std::cout << __func__ << std::endl;
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()==b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Logical operators

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator !() 
{
  RETURN_VARPTR(long int,!(Value()>0.5));
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value()&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(long int,Value() || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Mathematical functions
#define VAR_IMPL_FUNC(type,fname,func) \
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<type>::m_##fname() \
{ \
    RETURN_VARPTR(long int, func((double)Value())); \
}

VAR_IMPL_FUNC(long int,  sin,  sin)
VAR_IMPL_FUNC(long int,  cos,  cos)
VAR_IMPL_FUNC(long int,  tan,  tan)
VAR_IMPL_FUNC(long int,  asin, asin)
VAR_IMPL_FUNC(long int,  acos, acos)
VAR_IMPL_FUNC(long int,  atan, atan)
VAR_IMPL_FUNC(long int,  fabs, fabs)
VAR_IMPL_FUNC(long int,  round,round)
VAR_IMPL_FUNC(long int,  floor,floor)
VAR_IMPL_FUNC(long int,  exp,  exp)
VAR_IMPL_FUNC(long int,  log,  1.0/log(10.0)*log)
VAR_IMPL_FUNC(long int,  ln,   log)
VAR_IMPL_FUNC(long int,  norm, fabs)
VAR_IMPL_FUNC(long int,  sqrt, sqrt)

//
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<long int>::BasicCast(const int& type)
{
  long int res = Value();

  switch((WORDTYPE)type) {
    case WT_UNSIGNED_CHAR:  res=(unsigned char) res; break;
    case WT_SIGNED_SHORT:   res=(short) res;  break;
    case WT_UNSIGNED_SHORT: res=(unsigned short) res;  break;
    case WT_SIGNED_INT:     res=(int) res;  break;
    case WT_UNSIGNED_INT:   res=(unsigned int) res;  break;
    case WT_FLOAT:          { RETURN_VARPTR(float, (float) res); }
    case WT_DOUBLE:         { RETURN_VARPTR(double, res); } /// New (added: 24/05/2010)
    default:
      std::cerr << boost::format("Conversion to type %1% not available")%((WORDTYPE)type) << std::endl;
  }
  RETURN_VARPTR(float, res);
}

//
template<> AMI_DLLEXPORT
BasicVariable::ptr Variable<long int>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2)
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


template<> AMI_DLLEXPORT 
BasicVariable::ptr Variable<long int>::operator =(const BasicVariable::ptr& b)
{
  if (IsNumeric()) {
    RefValue() = b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return NewReference();
}
