
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
//------- Variable<unsigned char>
//------------------------------------------------------

/// Copy contents to new variable
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::NewCopy() const
{
  uchar_ptr newval( new unsigned char(Value()));
  Variable<unsigned char>::ptr newvar(new Variable<unsigned char>(newval));
  return newvar;
}


// Arithmetic operators

/// +a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator +()
{  RETURN_VARPTR(unsigned char,Value());}

/// prefix ++ operator ++a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator ++()
{
  RETURN_VARPTR(unsigned char,++RefValue());
}

/// postfix ++ operator a++
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator ++(int)
{
  RETURN_VARPTR(unsigned char,RefValue()++);
}

/// -a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator -()
{   RETURN_VARPTR(unsigned char,-Value());}

/// prefix -- operator --a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator --()
{  RETURN_VARPTR(unsigned char,--RefValue()); }

/// postfix -- operator a--
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator --(int)
{  RETURN_VARPTR(unsigned char,RefValue()--);  }



/// a+b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator +(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()+b->GetValueAsDouble());
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator +=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() += b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator -(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()-b->GetValueAsDouble());
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator -=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() -= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a*b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator *(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()*b->GetValueAsDouble());
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator *=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() *= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a/b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator /(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()/b->GetValueAsDouble());
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator /=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() /= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char, ((int) round(Value())) % ((int) round(b->GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator %=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b->GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

//  Comparison Operators

/// a<b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator <(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()<b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator <=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()<=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator >(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()>b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator >=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()>=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator !=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()!=b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


/// a==b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator ==(const BasicVariable::ptr& b)
{ 
  //std::cout << __func__ << std::endl;
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,Value()==b->GetValueAsDouble());
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Logical operators

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator !() 
{
  RETURN_VARPTR(unsigned char,!(Value()>0.5));
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,(Value()>0.5)&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(unsigned char,(Value()>0.5) || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Mathematical functions
// TODO: improve type conversions here ...
#define VAR_IMPL_FUNC(type,fname,func) \
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<type>::m_##fname() \
{ \
    RETURN_VARPTR(unsigned char, (int) func((double)Value())); \
}

/*
VAR_IMPL_FUNC(unsigned char,  sin,  sin)
VAR_IMPL_FUNC(unsigned char,  cos,  cos)
VAR_IMPL_FUNC(unsigned char,  tan,  tan)
VAR_IMPL_FUNC(unsigned char,  asin, asin)
VAR_IMPL_FUNC(unsigned char,  acos, acos)
VAR_IMPL_FUNC(unsigned char,  atan, atan)
*/
VAR_IMPL_FUNC(unsigned char,  fabs, fabs)
/*
VAR_IMPL_FUNC(unsigned char,  round,round)
VAR_IMPL_FUNC(unsigned char,  floor,floor)
VAR_IMPL_FUNC(unsigned char,  exp,  exp)
VAR_IMPL_FUNC(unsigned char,  log,  1.0/log(10.0)*log)
VAR_IMPL_FUNC(unsigned char,  ln,   log)
*/
VAR_IMPL_FUNC(unsigned char,  norm, fabs)
VAR_IMPL_FUNC(unsigned char,  sqrt, sqrt)


//---------------------------------------------------
template<> AMI_DLLEXPORT
BasicVariable::ptr Variable<unsigned char>::TryCast(
    const std::string& type_string) const
{
  if (type_string==AMILabType<unsigned char>::name_as_string()) 
    return NewCopy();
  try
  {
    // cast to double
    if (type_string==AMILabType<double>::name_as_string()) {
      RETURN_VARPTR(double, boost::numeric_cast<double>(Value()));
    } else 
    // cast to float
    if (type_string==AMILabType<float>::name_as_string()) {
      RETURN_VARPTR(float, boost::numeric_cast<float>(Value()));
    } else 
    // cast to long
    if (type_string==AMILabType<long>::name_as_string()) {
      RETURN_VARPTR(long, boost::numeric_cast<long>(Value()));
    } else 
    // cast to int
    if (type_string==AMILabType<int>::name_as_string()) {
      RETURN_VARPTR(int, boost::numeric_cast<int>(Value()));
    } else 
    {
      // make default conversion to double??
      CLASS_ERROR(boost::format("No convertion available for variable %1% from 'unsigned char' to %2%") % _name % type_string);
    }
  } catch (std::bad_cast &e)
  {
    CLASS_ERROR(boost::format("%1%, for variable %2% from 'unsigned char' to %3%") % e.what() % _name % type_string);
    return BasicVariable::ptr();
  }
}


//---------------------------------------
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<unsigned char>::BasicCast(const int& type)
{
  try
  {
    switch((WORDTYPE)type) {
      case WT_UNSIGNED_CHAR:  break; // uchar to uchar: nothing to do ...
      case WT_SIGNED_INT:
      {
          RETURN_VARPTR(int, boost::numeric_cast<int>(Value()));
      }
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
      case WT_SIGNED_SHORT:   //res=(short) res;  break;
      case WT_UNSIGNED_SHORT: //res=(unsigned short) res;  break;
      default:
        CLASS_ERROR(boost::format("Conversion to type %1% not available")%((WORDTYPE)type));
    }
  } catch (std::bad_cast &e)
  {
    CLASS_ERROR(boost::format("%1%, for variable %2% from 'unsigned char' to WORDTYPE %3%") % e.what() % _name % (WORDTYPE)type );
    return BasicVariable::ptr();
  }

  RETURN_VARPTR(unsigned char, Value());

}

//
template<>
BasicVariable::ptr Variable<unsigned char>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2)
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
BasicVariable::ptr Variable<unsigned char>::operator =(const BasicVariable::ptr& b)
{
  // TODO: better conversion here !!!
  try
  {
    if (IsNumeric()) {
      RefValue() = boost::numeric_cast<unsigned char>(b->GetValueAsDouble());
    } else
      CLASS_ERROR("operation not defined");
  }
  catch (std::bad_cast &e)
  {
    CLASS_ERROR(boost::format("%1%, for variable %2% to 'unsigned char'") % e.what() % b->Name() );
  }
  return NewReference();
}
