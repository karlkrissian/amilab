
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

#include <boost/numeric/conversion/cast.hpp>  


//------------------------------------------------------
//------- Variable<double>
//------------------------------------------------------

/// Copy contents to new variable
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::NewCopy() const
{
  double_ptr newval( new double(Value()));
  Variable<double>::ptr newvar(new Variable<double>(newval));
  return newvar;
}


// Arithmetic operators

/// +a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator +()
{  RETURN_VARPTR(double,Value());}

/// prefix ++ operator ++a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator ++()
{
  std::cout << "**" << endl;
  RETURN_VARPTR(double,++RefValue());
}

/// postfix ++ operator a++
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator ++(int)
{
  std::cout << "**" << endl;
  RETURN_VARPTR(double,RefValue()++);
}

/// -a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator -()
{   RETURN_VARPTR(double,-Value());}

/// prefix -- operator --a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator --()
{  RETURN_VARPTR(double,--RefValue()); }

/// postfix -- operator a--
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator --(int)
{  RETURN_VARPTR(double,RefValue()--);  }



/// a+b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator +(const BasicVariable::ptr& b)
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator +=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() += b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator -(const BasicVariable::ptr& b)
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator -=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() -= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator *(const BasicVariable::ptr& b)
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator *=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() *= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator /(const BasicVariable::ptr& b)
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator /=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() /= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double, ((int) round(Value())) % ((int) round(b->GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator %=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b->GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

//  Comparison Operators

/// a<b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator <(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()<b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator <=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()<=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator >(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()>b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator >=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()>=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator !=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()!=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


/// a==b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator ==(const BasicVariable::ptr& b)
{ 
  //std::cout << __func__ << std::endl;
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()==b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Logical operators

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator !() 
{
  RETURN_VARPTR(double,!(Value()>0.5));
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value()&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(double,Value() || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Mathematical functions
#define VAR_IMPL_FUNC(type,fname,func) \
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<type>::m_##fname() \
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


//---------------------------------------------------
template<> AMI_DLLEXPORT
BasicVariable::ptr Variable<double>::TryCast(
    const std::string& type_string) const
{
  try
  {
    // cast to float
    if (type_string==to_string<float>::value()) {
      RETURN_VARPTR(float, boost::numeric_cast<float>(Value()));
    } else 
    // cast to int
    if (type_string==to_string<int>::value()) {
      RETURN_VARPTR(int, boost::numeric_cast<int>(Value()));
    } else 
    // cast to unsigned char
    if (type_string==to_string<unsigned char>::value()) {
      RETURN_VARPTR(unsigned char, boost::numeric_cast<unsigned char>(Value()));
    } else 
    {
      // make default conversion to double??
      CLASS_ERROR(boost::format("No convertion available for variable %1% from double to %2%") % _name % type_string);
    }
  } catch (std::bad_cast &e)
  {
    CLASS_ERROR(boost::format("%1%, for variable %2% from double to %3%") % e.what() % _name % type_string);
    return BasicVariable::ptr();
  }
}

//
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<double>::BasicCast(const int& type)
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
template<> AMI_DLLEXPORT
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


template<> AMI_DLLEXPORT 
BasicVariable::ptr Variable<double>::operator =(const BasicVariable::ptr& b)
{
  if (IsNumeric()) {
    RefValue() = b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return NewReference();
}
