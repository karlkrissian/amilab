
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


// TODO: should be defined as functions ...
#define UNARYOP_IMAGE(im,operator)        {   \
  InrImage::ptr res;                           \
  if (im.use_count()==1) res = im; \
  else {\
    res = InrImage::ptr(new InrImage( im->GetFormat(),\
                                      im->GetVDim(),\
                                      (std::string("unaryop_")+im->GetName()).c_str(),\
                                      im.get()));\
    (*res) = (*im);\
  }\
  int       i;                            \
  res->InitBuffer();                       \
  if (res->ScalarFormat()) {             \
    do {                                \
     res->FixeValeur( operator(res->ValeurBuffer()) );   \
    } while (res->IncBuffer());             \
  } else {                                                \
    for(i=0;i<res->GetVDim();i++) {                 \
      res->InitBuffer();                       \
      do {                                 \
       res->VectFixeValeur( i, operator(res->VectValeurBuffer(i)) );   \
      } while (res->IncBuffer());  \
    }                                   \
  }                                       \
  driver.im_stack.AddImage(res); \
  }

//------------------------------------------------------
//------- Variable<InrImage>
//------------------------------------------------------


// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<InrImage>::operator +()
{
  return NewReference();
}

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<InrImage>::operator ++()
{
  std::cout << "**" << endl;
  RETURN_VARPTR(InrImage,++RefValue());
}

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<InrImage>::operator ++(int)
{
  std::cout << "**" << endl;
  RETURN_VARPTR(InrImage,RefValue()++);
}

/// -a
template<> BasicVariable::ptr Variable<InrImage>::operator -()
{
  UNARYOP_IMAGE(this->Pointer(), -); 
  return Variable<type>::ptr( new Variable<type>(res)); 
}

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<InrImage>::operator --()
{  RETURN_VARPTR(InrImage,--RefValue()); }

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<InrImage>::operator --(int)
{  RETURN_VARPTR(InrImage,RefValue()--);  }



/// a+b
template<> BasicVariable::ptr Variable<InrImage>::operator +(const BasicVariable& b)
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()+b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a+=b
template<> BasicVariable::ptr Variable<InrImage>::operator +=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RefValue() += b.GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-b
template<> BasicVariable::ptr Variable<InrImage>::operator -(const BasicVariable& b)
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()-b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-=b
template<> BasicVariable::ptr Variable<InrImage>::operator -=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RefValue() -= b.GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*b
template<> BasicVariable::ptr Variable<InrImage>::operator *(const BasicVariable& b)
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()*b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*=b
template<> BasicVariable::ptr Variable<InrImage>::operator *=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RefValue() *= b.GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/b
template<> BasicVariable::ptr Variable<InrImage>::operator /(const BasicVariable& b)
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()/b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/=b
template<> BasicVariable::ptr Variable<InrImage>::operator /=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RefValue() /= b.GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%b
template<> BasicVariable::ptr Variable<InrImage>::operator %(const BasicVariable& b)
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage, ((int) round(Value())) % ((int) round(b.GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> BasicVariable::ptr Variable<InrImage>::operator %=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b.GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<InrImage>::operator <(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()<b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> BasicVariable::ptr Variable<InrImage>::operator <=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()<=b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> BasicVariable::ptr Variable<InrImage>::operator >(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()>b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> BasicVariable::ptr Variable<InrImage>::operator >=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()>=b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> BasicVariable::ptr Variable<InrImage>::operator !=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()!=b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a==b
template<> BasicVariable::ptr Variable<InrImage>::operator ==(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()==b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Logical operators

template<> BasicVariable::ptr Variable<InrImage>::operator !() 
{
  RETURN_VARPTR(InrImage,!(Value()>0.5));
}

template<> BasicVariable::ptr Variable<InrImage>::operator &&(const BasicVariable& b) 
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value()&& (bool) (b.GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> BasicVariable::ptr Variable<InrImage>::operator ||(const BasicVariable& b) 
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(InrImage,Value() || (bool) (b.GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Mathematical functions




#define VAR_IMPL_FUNC(type,fname,func) \
template<> BasicVariable::ptr Variable<type>::m_##fname() \
{ \
  UNARYOP_IMAGE(this->Pointer(), func); \
  return Variable<type>::ptr( new Variable<type>(res)); \
}

VAR_IMPL_FUNC(InrImage,  sin,  sin)
VAR_IMPL_FUNC(InrImage,  cos,  cos)
VAR_IMPL_FUNC(InrImage,  tan,  tan)
VAR_IMPL_FUNC(InrImage,  asin, asin)
VAR_IMPL_FUNC(InrImage,  acos, acos)
VAR_IMPL_FUNC(InrImage,  atan, atan)
VAR_IMPL_FUNC(InrImage,  fabs, fabs)
VAR_IMPL_FUNC(InrImage,  round,round)
VAR_IMPL_FUNC(InrImage,  floor,floor)
VAR_IMPL_FUNC(InrImage,  exp,  exp)
VAR_IMPL_FUNC(InrImage,  log,  1.0/log(10.0)*log)
VAR_IMPL_FUNC(InrImage,  ln,   log)
VAR_IMPL_FUNC(InrImage,  sqrt, sqrt)

// TODO: norm(image)
VAR_IMPL_FUNC(InrImage,  norm, fabs)

//
template<> BasicVariable::ptr Variable<InrImage>::BasicCast(const int& type)
{
  InrImage res = Value();

  switch((WORDTYPE)type) {
    case WT_UNSIGNED_CHAR:  res=(unsigned char) res; break;
    case WT_SIGNED_SHORT:   res=(short) res;  break;
    case WT_UNSIGNED_SHORT: res=(unsigned short) res;  break;
    case WT_SIGNED_INT:     res=(int) res;  break;
    case WT_UNSIGNED_INT:   res=(unsigned int) res;  break;
    case WT_FLOAT:          res=(InrImage) res;  break;
    default:
      std::cerr << boost::format("Conversion to type %1% not available")%((WORDTYPE)type) << std::endl;
  }
  RETURN_VARPTR(InrImage, res);
}

//
template<>
BasicVariable::ptr Variable<InrImage>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2)
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
