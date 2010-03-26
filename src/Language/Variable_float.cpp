
#include "amilab_messages.h"
#include "DefineClass.hpp"
#include "Variable.hpp"


#define NEW_SMARTPTR(type, var, value) \
  boost::shared_ptr<type> var(new type(value));

#define RETURN_VARPTR(type,  value) \
  std::cout << get_name() << "::operator " << __func__  << "!!!"<< std::endl; \
  boost::shared_ptr<type> newval(new type(value)); \
  return Variable<type>::ptr( new Variable<type>(newval));


//------------------------------------------------------
//------- Variable<float>
//------------------------------------------------------


// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<float>::operator +()
{  RETURN_VARPTR(float,Value());}

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<float>::operator ++()
{
  std::cout << "**" << endl;
  RETURN_VARPTR(float,++RefValue());
}

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<float>::operator ++(int)
{
  std::cout << "**" << endl;
  RETURN_VARPTR(float,RefValue()++);
}

/// -a
template<> BasicVariable::ptr Variable<float>::operator -()
{   RETURN_VARPTR(float,-Value());}

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<float>::operator --()
{  RETURN_VARPTR(float,--RefValue()); }

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<float>::operator --(int)
{  RETURN_VARPTR(float,RefValue()--);  }



/// a+b
template<> BasicVariable::ptr Variable<float>::operator +(const BasicVariable& b)
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()+b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a+=b
template<> BasicVariable::ptr Variable<float>::operator +=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RefValue() += b.GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-b
template<> BasicVariable::ptr Variable<float>::operator -(const BasicVariable& b)
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()-b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-=b
template<> BasicVariable::ptr Variable<float>::operator -=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RefValue() -= b.GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*b
template<> BasicVariable::ptr Variable<float>::operator *(const BasicVariable& b)
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()*b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*=b
template<> BasicVariable::ptr Variable<float>::operator *=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RefValue() *= b.GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/b
template<> BasicVariable::ptr Variable<float>::operator /(const BasicVariable& b)
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()/b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/=b
template<> BasicVariable::ptr Variable<float>::operator /=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RefValue() /= b.GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<float>::operator <(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()<b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> BasicVariable::ptr Variable<float>::operator <=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()<=b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> BasicVariable::ptr Variable<float>::operator >(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()>b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> BasicVariable::ptr Variable<float>::operator >=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()>=b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> BasicVariable::ptr Variable<float>::operator !=(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()!=b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a==b
template<> BasicVariable::ptr Variable<float>::operator ==(const BasicVariable& b)
{ 
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()==b.GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Logical operators

template<> BasicVariable::ptr Variable<float>::operator !() 
{
  RETURN_VARPTR(float,!(Value()>0.5));
}

template<> BasicVariable::ptr Variable<float>::operator &&(const BasicVariable& b) 
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value()&& (bool) (b.GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> BasicVariable::ptr Variable<float>::operator ||(const BasicVariable& b) 
{
  if (b.IsNumeric()) {
    RETURN_VARPTR(float,Value() || (bool) (b.GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
