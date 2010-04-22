
#include "amilab_messages.h"
#include "DefineClass.hpp"
#include "Variable.hpp"
#include <math.h>
#include "driver.h"
#include <boost/pointer_cast.hpp>

extern yyip::Driver GB_driver;

#define NEW_SMARTPTR(type, var, value) \
  boost::shared_ptr<type> var(new type(value));

#define RETURN_VARPTR(type,  value) \
  boost::shared_ptr<type> newval(new type(value)); \
  return Variable<type>::ptr( new Variable<type>(newval));

#include "inrimage.hpp"


// TODO: should be defined as functions ...
#define UNARYOP_IMAGE(im,operator)      \
  {   \
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
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); \
  }


#define IMAGE_OP_EXPR(im,operator,expr)      \
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
        res->FixeValeur(res->ValeurBuffer() operator val); \
      } while (res->IncBuffer());             \
    }else{                                                  \
      do {                                              \
        for(i=0;i<res->GetVDim();i++) {                         \
          res->VectFixeValeur(i,res->VectValeurBuffer(i) operator val);  \
        }                                            \
      } while(res->IncBuffer());              \
    }                                                  \
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); \
  }

/*
#define EXPR_OP_IMAGE(operator,expr)    {                 \
  InrImage::ptr im(driver.im_stack.GetLastImage());            \
  InrImage::ptr res;                           \
  if (im.use_count()==1) res = im; \
  else {\
    res = InrImage::ptr(new InrImage( im->GetFormat(),\
                                      im->GetVDim(),\
                                      (std::string("expr_op_")+im->GetName()).c_str(),\
                                      im.get()));\
    (*res) = (*im);\
  }\
  int       i;                                           \
  double    val = expr;                                  \
  res->InitBuffer();                                     \
  Si res->ScalarFormat() Alors                           \
    Repeter                                              \
      res->FixeValeur(val operator res->ValeurBuffer() ); \
    JusquA Non(res->IncBuffer()) FinRepeter              \
  Sinon                                                  \
    Repeter                                              \
      Pour(i,0,res->GetVDim()-1)                         \
        res->VectFixeValeur(i, val operator res->VectValeurBuffer(i));  \
      FinPour                                            \
    JusquA Non(res->IncBuffer()) FinRepeter              \
  FinSi                                                  \
  driver.im_stack.AddImage(res); }
*/

#define IMAGE_OP_IMAGE(im1,im2,operator)    \
  {\
    if (im1->ScalarFormat()&&im2->ScalarFormat()) { \
      std::string newname = (boost::format("%1%_%2%_%3%")%im1->GetName()%#operator%im2->GetName()).str(); \
      InrImage::ptr res = InrImage::ptr(new InrImage(im1->_format,newname.c_str(),im1.get()));\
      im1->InitBuffer();                \
      im2->InitBuffer();                \
      res->InitBuffer();                \
      do{                           \
        res->FixeValeur(im1->ValeurBuffer() operator im2->ValeurBuffer()); \
        im1->IncBuffer();               \
        im2->IncBuffer();               \
      } while (res->IncBuffer());      \
      return Variable<InrImage>::ptr( new Variable<InrImage>(res)); \
    } else \
      GB_driver.err_print((boost::format("Both images should be scalar for operator %1%.") % #operator ).str()); \
      return Variable<InrImage>::ptr(); \
  }

#define IMAGE_OP_IMAGE_2(im1,im2,operator) \
  { \
    InrImage::ptr res( (*im1) operator (*im2));     \
    if (!res.get()){              \
      GB_driver.err_print((boost::format("Error in operation %s \t IMAGE_OP_IMAGE_2 \n") % #operator).str().c_str()); \
    }                             \
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); \
  }


//------------------------------------------------------
//------- Variable<InrImage>
//------------------------------------------------------

/// Copy contents to new variable
template<> BasicVariable::ptr Variable<InrImage>::NewCopy()
{
  InrImage::ptr newval( new InrImage( Pointer()->GetFormat(),
                                      Pointer()->GetVDim(),
                                      Pointer()->GetName(),
                                      Pointer().get()));
  (*newval) = (*Pointer());
  Variable<InrImage>::ptr newvar(new Variable<InrImage>(newval));
  return newvar;
}


// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<InrImage>::operator +()
{
  return NewReference();
}

/*
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
*/

/// -a
template<> BasicVariable::ptr Variable<InrImage>::operator -()
{
  UNARYOP_IMAGE(this->Pointer(), -); 
}

/*
/// prefix -- operator --a
template<> BasicVariable::ptr Variable<InrImage>::operator --()
{  RETURN_VARPTR(InrImage,--RefValue()); }

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<InrImage>::operator --(int)
{  RETURN_VARPTR(InrImage,RefValue()--);  }
*/



/// a+b
template<> BasicVariable::ptr Variable<InrImage>::operator +(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),+,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),+);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a+=b
template<> BasicVariable::ptr Variable<InrImage>::operator +=(const BasicVariable::ptr& b)
{ 
//  if (b->IsNumeric()) {
//    RefValue() += b->GetValueAsDouble();

  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
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
template<> BasicVariable::ptr Variable<InrImage>::operator -(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),-,b->GetValueAsDouble());
  } 
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),-);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a-=b
template<> BasicVariable::ptr Variable<InrImage>::operator -=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() -= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/// a*b
template<> BasicVariable::ptr Variable<InrImage>::operator *(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),*,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),*);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a*=b
template<> BasicVariable::ptr Variable<InrImage>::operator *=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() *= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/// a/b
template<> BasicVariable::ptr Variable<InrImage>::operator /(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),/,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),/);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a/=b
template<> BasicVariable::ptr Variable<InrImage>::operator /=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() /= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/*
/// a%b
template<> BasicVariable::ptr Variable<InrImage>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(InrImage, ((int) round(Value())) % ((int) round(b->GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> BasicVariable::ptr Variable<InrImage>::operator %=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b->GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<InrImage>::operator <(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),<,b->GetValueAsDouble());
  } 
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),<);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> BasicVariable::ptr Variable<InrImage>::operator <=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),<=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),<=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> BasicVariable::ptr Variable<InrImage>::operator >(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),>,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),>);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> BasicVariable::ptr Variable<InrImage>::operator >=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),>=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),>=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> BasicVariable::ptr Variable<InrImage>::operator !=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),!=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),!=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a==b
template<> BasicVariable::ptr Variable<InrImage>::operator ==(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),==,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),==);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


// Logical operators

/*
template<> BasicVariable::ptr Variable<InrImage>::operator !() 
{
  RETURN_VARPTR(InrImage,!(Value()>0.5));
}

template<> BasicVariable::ptr Variable<InrImage>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),==,b->GetValueAsDouble());
    RETURN_VARPTR(InrImage,Value()&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> BasicVariable::ptr Variable<InrImage>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(InrImage,Value() || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/// a^b
template<> BasicVariable::ptr Variable<InrImage>::operator ^(const BasicVariable::ptr& b)
{ 
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
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

//  norm(image)
template<> BasicVariable::ptr Variable<InrImage>::m_norm() 
{ 
  InrImage::ptr res ( Norm(*Pointer()));
  if (!res.get())
    fprintf(stderr,"Error computing the norm |image| \n");
  return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 
}
//VAR_IMPL_FUNC(InrImage,  norm, fabs)

// Image Pixel Type Cast
template<> BasicVariable::ptr Variable<InrImage>::BasicCast(const int& type)
{
  InrImage::ptr res  ( new InrImage( (WORDTYPE) type, "castimage.ami.gz", Pointer().get()));
  (*res) = (*Pointer());
  return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 
}

/**
 * Array subscript operator
 * @param v 
 * @return 
 */
template<>  BasicVariable::ptr Variable<InrImage>::operator[](const BasicVariable::ptr& v)
{
  if (v->IsNumeric()) {
    int pos = (int) v->GetValueAsDouble();
    InrImage::ptr im(Pointer());
    InrImage::ptr res;
    if (pos<0) pos = 0;
    if (pos>=im->GetVDim()) pos = im->GetVDim()-1;
    std::string imname  = (boost::format("C%d_%s") % pos % this->Name()).str();

    switch ( im->GetFormat() ){
        case WT_RGB:
        case WT_RGBA:
            res = InrImage::ptr(new InrImage(WT_UNSIGNED_CHAR,1,imname.c_str(),im.get()));
        break;
        case WT_FLOAT_VECTOR:
            res = InrImage::ptr(new InrImage(WT_FLOAT,1,imname.c_str(),im.get()));
        break;

        case WT_UNSIGNED_CHAR:
        case WT_UNSIGNED_INT:
        case WT_SIGNED_INT:
        case WT_UNSIGNED_SHORT:
        case WT_SIGNED_SHORT:
        case WT_FLOAT:
        case WT_DOUBLE:
            res = InrImage::ptr(new InrImage(im->_format,1,imname.c_str(),im.get()));
        break;

        default:
          GB_driver.yyiperror(" operator [] does not handle this format \n");
          return this->NewReference(); 
    }

    im->InitBuffer();
    res->InitBuffer();
    do {
      res->FixeValeur(im->VectValeurBuffer(pos));
      im->IncBuffer();
    } while (res->IncBuffer());
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 

  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


/*
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
*/

/// Other operators
/// a=b
template<> 
BasicVariable::ptr Variable<InrImage>::operator =(const BasicVariable::ptr& b)
{
  CLASS_MESSAGE("begin");
  if (b->IsNumeric()) {
    Pointer()->InitImage(b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
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
