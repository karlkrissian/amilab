
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
//------- Variable<double>
//------------------------------------------------------

/// Copy contents to new variable
template<> BasicVariable::ptr Variable<double>::NewCopy()
{
  double_ptr newval( new double(Value()));
  Variable<double>::ptr newvar(new Variable<double>(newval));
  return newvar;
}


// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<double>::operator +()
{  RETURN_VARPTR(double,Value());}

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<double>::operator ++()
{
  std::cout << "**" << endl;
  RETURN_VARPTR(double,++RefValue());
}

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<double>::operator ++(int)
{
  std::cout << "**" << endl;
  RETURN_VARPTR(double,RefValue()++);
}

/// -a
template<> BasicVariable::ptr Variable<double>::operator -()
{   RETURN_VARPTR(double,-Value());}

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<double>::operator --()
{  RETURN_VARPTR(double,--RefValue()); }

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<double>::operator --(int)
{  RETURN_VARPTR(double,RefValue()--);  }



/// a+b
template<> BasicVariable::ptr Variable<double>::operator +(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()+b->GetValueAsDouble());
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
template<> BasicVariable::ptr Variable<double>::operator +=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() += b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-b
template<> BasicVariable::ptr Variable<double>::operator -(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()-b->GetValueAsDouble());
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
template<> BasicVariable::ptr Variable<double>::operator -=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() -= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*b
template<> BasicVariable::ptr Variable<double>::operator *(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()*b->GetValueAsDouble());
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
template<> BasicVariable::ptr Variable<double>::operator *=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() *= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/b
template<> BasicVariable::ptr Variable<double>::operator /(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()/b->GetValueAsDouble());
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
template<> BasicVariable::ptr Variable<double>::operator /=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() /= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%b
template<> BasicVariable::ptr Variable<double>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double, ((int) round(Value())) % ((int) round(b->GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> BasicVariable::ptr Variable<double>::operator %=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b->GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<double>::operator <(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()<b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> BasicVariable::ptr Variable<double>::operator <=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()<=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> BasicVariable::ptr Variable<double>::operator >(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()>b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> BasicVariable::ptr Variable<double>::operator >=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()>=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> BasicVariable::ptr Variable<double>::operator !=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()!=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


/// a==b
template<> BasicVariable::ptr Variable<double>::operator ==(const BasicVariable::ptr& b)
{ 
  //std::cout << __func__ << std::endl;
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()==b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Logical operators

template<> BasicVariable::ptr Variable<double>::operator !() 
{
  RETURN_VARPTR(double,!(Value()>0.5));
}

template<> BasicVariable::ptr Variable<double>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> BasicVariable::ptr Variable<double>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value() || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Mathematical functions
#define VAR_IMPL_FUNC(type,fname,func) \
template<> BasicVariable::ptr Variable<type>::m_##fname() \
{ \
    RETURN_VARPTR(double, func(Value())); \
}

VAR_IMPL_FUNC(double,  sin,  sin)
VAR_IMPL_FUNC(double,  cos,  cos)
VAR_IMPL_FUNC(double,  tan,  tan)
VAR_IMPL_FUNC(double,  asin, asin)
VAR_IMPL_FUNC(double,  acos, acos)
VAR_IMPL_FUNC(double,  atan, atan)
VAR_IMPL_FUNC(double,  fabs, fabs)
VAR_IMPL_FUNC(double,  round,round)
VAR_IMPL_FUNC(double,  floor,floor)
VAR_IMPL_FUNC(double,  exp,  exp)
VAR_IMPL_FUNC(double,  log,  1.0/log(10.0)*log)
VAR_IMPL_FUNC(double,  ln,   log)
VAR_IMPL_FUNC(double,  norm, fabs)
VAR_IMPL_FUNC(double,  sqrt, sqrt)

//
template<> BasicVariable::ptr Variable<double>::BasicCast(const int& type)
{
  double res = Value();

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
  RETURN_VARPTR(double, res);
}

//
template<>
BasicVariable::ptr Variable<double>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2)
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


template<> 
BasicVariable::ptr Variable<double>::operator =(const BasicVariable::ptr& b)
{
  if (IsNumeric()) {
    RefValue() = b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return NewReference();
}
