
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

#include <boost/numeric/conversion/cast.hpp>  


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
//------- Variable<int>
//------------------------------------------------------

/// Copy contents to new variable
template<> BasicVariable::ptr Variable<int>::NewCopy() const
{
  int_ptr newval( new int(Value()));
  Variable<int>::ptr newvar(new Variable<int>(newval));
  return newvar;
}


// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<int>::operator +()
{  RETURN_VARPTR(int,Value());}

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<int>::operator ++()
{
  RETURN_VARPTR(int,++RefValue());
}

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<int>::operator ++(int)
{
  RETURN_VARPTR(int,RefValue()++);
}

/// -a
template<> BasicVariable::ptr Variable<int>::operator -()
{   RETURN_VARPTR(int,-Value());}

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<int>::operator --()
{  RETURN_VARPTR(int,--RefValue()); }

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<int>::operator --(int)
{  RETURN_VARPTR(int,RefValue()--);  }



/// a+b
template<> BasicVariable::ptr Variable<int>::operator +(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()+b->GetValueAsDouble());
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
template<> BasicVariable::ptr Variable<int>::operator +=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() += b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-b
template<> BasicVariable::ptr Variable<int>::operator -(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()-b->GetValueAsDouble());
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
template<> BasicVariable::ptr Variable<int>::operator -=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() -= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*b
template<> BasicVariable::ptr Variable<int>::operator *(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()*b->GetValueAsDouble());
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
template<> BasicVariable::ptr Variable<int>::operator *=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() *= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/b
template<> BasicVariable::ptr Variable<int>::operator /(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()/b->GetValueAsDouble());
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
template<> BasicVariable::ptr Variable<int>::operator /=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() /= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%b
template<> BasicVariable::ptr Variable<int>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(int, ((int) round(Value())) % ((int) round(b->GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> BasicVariable::ptr Variable<int>::operator %=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b->GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<int>::operator <(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()<b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> BasicVariable::ptr Variable<int>::operator <=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()<=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> BasicVariable::ptr Variable<int>::operator >(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()>b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> BasicVariable::ptr Variable<int>::operator >=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()>=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> BasicVariable::ptr Variable<int>::operator !=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()!=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


/// a==b
template<> BasicVariable::ptr Variable<int>::operator ==(const BasicVariable::ptr& b)
{ 
  //std::cout << __func__ << std::endl;
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,Value()==b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Logical operators

template<> BasicVariable::ptr Variable<int>::operator !() 
{
  RETURN_VARPTR(int,!(Value()>0.5));
}

template<> BasicVariable::ptr Variable<int>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,(Value()>0.5)&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> BasicVariable::ptr Variable<int>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(int,(Value()>0.5) || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Mathematical functions
// TODO: improve type conversions here ...
#define VAR_IMPL_FUNC(type,fname,func) \
template<> BasicVariable::ptr Variable<type>::m_##fname() \
{ \
    RETURN_VARPTR(int, (int) func((double)Value())); \
}

/*
VAR_IMPL_FUNC(int,  sin,  sin)
VAR_IMPL_FUNC(int,  cos,  cos)
VAR_IMPL_FUNC(int,  tan,  tan)
VAR_IMPL_FUNC(int,  asin, asin)
VAR_IMPL_FUNC(int,  acos, acos)
VAR_IMPL_FUNC(int,  atan, atan)
*/
VAR_IMPL_FUNC(int,  fabs, fabs)
/*
VAR_IMPL_FUNC(int,  round,round)
VAR_IMPL_FUNC(int,  floor,floor)
VAR_IMPL_FUNC(int,  exp,  exp)
VAR_IMPL_FUNC(int,  log,  1.0/log(10.0)*log)
VAR_IMPL_FUNC(int,  ln,   log)
*/
VAR_IMPL_FUNC(int,  norm, fabs)
VAR_IMPL_FUNC(int,  sqrt, sqrt)


//---------------------------------------------------
template<>
BasicVariable::ptr Variable<int>::TryCast(
    const std::string& type_string) const
{
  if (type_string==to_string<int>::value()) 
    return NewCopy();
  try
  {
    // cast to double
    if (type_string==to_string<double>::value()) {
      RETURN_VARPTR(double, boost::numeric_cast<double>(Value()));
    } else 
    // cast to float
    if (type_string==to_string<float>::value()) {
      RETURN_VARPTR(float, boost::numeric_cast<float>(Value()));
    } else 
    // cast to long
    if (type_string==to_string<long>::value()) {
      RETURN_VARPTR(long, boost::numeric_cast<long>(Value()));
    } else 
    // cast to unsigned char
    if (type_string==to_string<unsigned char>::value()) {
      RETURN_VARPTR(unsigned char, boost::numeric_cast<unsigned char>(Value()));
    } else 
    {
      // make default conversion to double??
      CLASS_ERROR(boost::format("No convertion available for variable %1% from int to %2%") % _name % type_string);
    }
  } catch (std::bad_cast &e)
  {
    CLASS_ERROR(boost::format("%1%, for variable %2% from int to %3%") % e.what() % _name % type_string);
    return BasicVariable::ptr();
  }
}


//---------------------------------------
template<> BasicVariable::ptr Variable<int>::BasicCast(const int& type)
{
  try
  {
    switch((WORDTYPE)type) {
      case WT_SIGNED_INT:  break; // int to int: nothing to do ...
      case WT_SIGNED_LONG:
      {
          RETURN_VARPTR(long, boost::numeric_cast<long>(Value()));
      }
      case WT_FLOAT:
      {
          RETURN_VARPTR(float, boost::numeric_cast<float>(Value()));
      }
      case WT_DOUBLE: 
      {
          RETURN_VARPTR(double, boost::numeric_cast<double>(Value()));
      }
      case WT_UNSIGNED_CHAR:
      {
          RETURN_VARPTR(unsigned char, boost::numeric_cast<unsigned char>(Value()));
      }
      case WT_UNSIGNED_INT:  //res=(unsigned char) res; break;
      case WT_SIGNED_SHORT:   //res=(short) res;  break;
      case WT_UNSIGNED_SHORT: //res=(unsigned short) res;  break;
      default:
        CLASS_ERROR(boost::format("Conversion to type %1% not available")%((WORDTYPE)type));
    }
  } catch (std::bad_cast &e)
  {
    CLASS_ERROR(boost::format("%1%, for variable %2% from float to WORDTYPE %3%") % e.what() % _name % (WORDTYPE)type );
    return BasicVariable::ptr();
  }

  RETURN_VARPTR(int, Value());

}

//
template<>
BasicVariable::ptr Variable<int>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2)
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
BasicVariable::ptr Variable<int>::operator =(const BasicVariable::ptr& b)
{
  // TODO: better conversion here !!!
  try
  {
    if (IsNumeric()) {
      RefValue() = boost::numeric_cast<int>(b->GetValueAsDouble());
    } else
      CLASS_ERROR("operation not defined");
  }
  catch (std::bad_cast &e)
  {
    CLASS_ERROR(boost::format("%1%, for variable %2% to 'int'") % e.what() % b->Name() );
  }
  return NewReference();
}
