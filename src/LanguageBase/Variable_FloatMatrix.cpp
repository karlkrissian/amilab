
#include "amilab_messages.h"
#include "DefineClass.hpp"
#include "Variable.hpp"
#include <math.h>
#include <boost/pointer_cast.hpp>
#include "FloatMatrix.hpp"
#include "wrapfunctions.hpp"


#include "AmiMessage.h"
#include "CommonConfigure.h"
COMMON_VAR_IMPORT AmiMessage GB_AmiMessage;

#if defined(_MSC_VER) || defined(__MINGW32__)
  static inline double round( double d ) {  return floor( d + 0.5 );}
#endif


#define NEW_SMARTPTR(type, var, value) \
  boost::shared_ptr<type> var(new type(value));

/*
#define RETURN_VARPTR(type,  value) \
  boost::shared_ptr<type> newval(new type(value)); \
  return Variable<type>::ptr( new Variable<type>(newval));
*/

/// Macros to facilitate the matrix operations

#define UNARYOP_MATRIX(mat, operator)           \
  { \
    FloatMatrix::ptr res; \
    if (mat.use_count()==1) \
      res = mat; \
    else \
      res = FloatMatrix::ptr( new FloatMatrix( *Pointer())); \
    int       i,j;                            \
    for (i=0;i<res->Rows();i++)               \
    for (j=0;j<res->Cols();j++) {             \
      (*res)[i][j]=operator((*res)[i][j]);               \
    }                                         \
    return Variable<FloatMatrix>::ptr( new Variable<FloatMatrix>(res)); \
  }

#define MATRIX_OP_EXPR(mat,operator,expr)        \
  FloatMatrix::ptr res; \
  if (mat.use_count()==1) \
    res = mat; \
  else \
    res = FloatMatrix::ptr( new FloatMatrix( *Pointer())); \
  int       i,j;                             \
  float     val = expr;                      \
  for (i=0;i<res->Rows();i++)               \
  for (j=0;j<res->Cols();j++) {             \
    (*res)[i][j]=(*res)[i][j] operator val;            \
  }                                         \
  return Variable<FloatMatrix>::ptr( new Variable<FloatMatrix>(res)); \

#define MATRIX_OP_MATRIX(mat1,mat2,operator)       \
  { \
    FloatMatrix::ptr res;                          \
    int       i,j;                             \
    if ((mat1->Rows()==mat2->Rows())&&(mat1->Cols()==mat2->Cols())) { \
      res = FloatMatrix::ptr( new FloatMatrix( mat1->Rows(),mat1->Cols())); \
      for (i=0;i<mat1->Rows();i++)               \
      for (j=0;j<mat1->Cols();j++)              \
        (*res)[i][j]=(*mat1)[i][j] operator (*mat2)[i][j];            \
    }                                              \
    else                                           \
      res = FloatMatrix::ptr(mat1);                \
    return Variable<FloatMatrix>::ptr( new Variable<FloatMatrix>(res)); \
  } \


//------------------------------------------------------
//------- Variable<FloatMatrix>
//------------------------------------------------------

/// Copy contents to new variable
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::NewCopy() const
{
  FloatMatrix::ptr newval( new FloatMatrix( *Pointer()));
  Variable<FloatMatrix>::ptr newvar(new Variable<FloatMatrix>(newval));
  return newvar;
}


// Arithmetic operators

/*
/// +a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator +()
{
  return NewReference();
}

/// prefix ++ operator ++a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator ++()
{
  std::cout << "**" << std::endl;
  RETURN_VARPTR(FloatMatrix,++RefValue());
}

/// postfix ++ operator a++
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator ++(int)
{
  std::cout << "**" << std::endl;
  RETURN_VARPTR(FloatMatrix,RefValue()++);
}
*/

/// -a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator -()
{
  UNARYOP_MATRIX(this->Pointer(), -); 
}

/*
/// prefix -- operator --a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator --()
{  RETURN_VARPTR(FloatMatrix,--RefValue()); }

/// postfix -- operator a--
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator --(int)
{  RETURN_VARPTR(FloatMatrix,RefValue()--);  }
*/



/// a+b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator +(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),+,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),+);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a+=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator +=(const BasicVariable::ptr& b)
{ 
//  if (b->IsNumeric()) {
//    RefValue() += b->GetValueAsDouble();

  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    if (var_mat2.get()) {
      // copy option
      (*Pointer())+=(*var_mat2->Pointer());
    } else {
      GB_AmiMessage.Error("Error, parameter of += operator points to NULL image\n");
    }
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/// a-b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator -(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),-,b->GetValueAsDouble());
  } 
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),-);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a-=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator -=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() -= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/// a*b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator *(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),*,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    FloatMatrix::ptr res( Multiply(Pointer().get(), var_mat2->Pointer().get())) ;
    return Variable<FloatMatrix>::ptr( new Variable<FloatMatrix>(res));
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a*=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator *=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() *= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/// a/b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator /(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),/,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),/);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a/=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator /=(const BasicVariable::ptr& b)
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(FloatMatrix, ((int) round(Value())) % ((int) round(b->GetValueAsDouble())));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a%=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator %=(const BasicVariable::ptr& b)
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
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator <(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),<,b->GetValueAsDouble());
  } 
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),<);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator <=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),<=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),<=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator >(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),>,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),>);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator >=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),>=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),>=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator !=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),!=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),!=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a==b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator ==(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),==,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),==);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


// Logical operators

/*
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator !() 
{
  RETURN_VARPTR(FloatMatrix,!(Value()>0.5));
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),==,b->GetValueAsDouble());
    RETURN_VARPTR(FloatMatrix,Value()&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(FloatMatrix,Value() || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/*
/// a^b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::operator ^(const BasicVariable::ptr& b)
{ 
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),^);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

// Mathematical functions

#define VAR_IMPL_FUNC(type,fname,func) \
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<type>::m_##fname() \
{ \
  UNARYOP_MATRIX(this->Pointer(), func); \
}

VAR_IMPL_FUNC(FloatMatrix,  sin,  sin)
VAR_IMPL_FUNC(FloatMatrix,  cos,  cos)
VAR_IMPL_FUNC(FloatMatrix,  tan,  tan)
VAR_IMPL_FUNC(FloatMatrix,  asin, asin)
VAR_IMPL_FUNC(FloatMatrix,  acos, acos)
VAR_IMPL_FUNC(FloatMatrix,  atan, atan)
VAR_IMPL_FUNC(FloatMatrix,  fabs, fabs)
VAR_IMPL_FUNC(FloatMatrix,  round,round)
VAR_IMPL_FUNC(FloatMatrix,  floor,floor)
VAR_IMPL_FUNC(FloatMatrix,  exp,  exp)
VAR_IMPL_FUNC(FloatMatrix,  log,  1.0/log(10.0)*log)
VAR_IMPL_FUNC(FloatMatrix,  ln,   log)
VAR_IMPL_FUNC(FloatMatrix,  sqrt, sqrt)

/*
//  norm(matrix)
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::m_norm() 
{ 
  FloatMatrix::ptr res ( Norm(*Pointer()));
  if (!res.get())
    fprintf(stderr,"Error computing the norm |image| \n");
  return Variable<FloatMatrix>::ptr( new Variable<FloatMatrix>(res)); 
}
//VAR_IMPL_FUNC(FloatMatrix,  norm, fabs)
*/

/*
// Image Pixel Type Cast
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::BasicCast(const int& type)
{
  FloatMatrix::ptr res  ( new FloatMatrix( (WORDTYPE) type, "castimage.ami.gz", Pointer().get()));
  (*res) = (*Pointer());
  return Variable<FloatMatrix>::ptr( new Variable<FloatMatrix>(res)); 
}
*/

/**
 * Array subscript operator
 * @param v 
 * @return 
 */
/*
template<> AMI_DLLEXPORT  BasicVariable::ptr Variable<FloatMatrix>::operator[](const BasicVariable::ptr& v)
{
  if (v->IsNumeric()) {
    int pos = (int) v->GetValueAsDouble();
    FloatMatrix::ptr im(Pointer());
    FloatMatrix::ptr res;
    if (pos<0) pos = 0;
    if (pos>=im->GetVDim()) pos = im->GetVDim()-1;
    std::string imname  = (boost::format("C%d_%s") % pos % this->Name()).str();

    switch ( im->GetFormat() ){
        case WT_RGB:
        case WT_RGBA:
            res = FloatMatrix::ptr(new FloatMatrix(WT_UNSIGNED_CHAR,1,imname.c_str(),im.get()));
        break;
        case WT_FLOAT_VECTOR:
            res = FloatMatrix::ptr(new FloatMatrix(WT_FLOAT,1,imname.c_str(),im.get()));
        break;

        case WT_UNSIGNED_CHAR:
        case WT_UNSIGNED_INT:
        case WT_SIGNED_INT:
        case WT_UNSIGNED_SHORT:
        case WT_SIGNED_SHORT:
        case WT_FLOAT:
        case WT_DOUBLE:
            res = FloatMatrix::ptr(new FloatMatrix(im->_format,1,imname.c_str(),im.get()));
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
    return Variable<FloatMatrix>::ptr( new Variable<FloatMatrix>(res)); 

  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/*
//
template<> AMI_DLLEXPORT
BasicVariable::ptr Variable<FloatMatrix>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2)
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
template<> AMI_DLLEXPORT 
BasicVariable::ptr Variable<FloatMatrix>::operator =(const BasicVariable::ptr& b)
{
  CLASS_MESSAGE("begin");
  if (b->IsNumeric()) {
    (*Pointer())=b->GetValueAsDouble();
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    if (var_mat2.get()) {
      // copy option
      if (! ((*Pointer())=(var_mat2->Pointer().get()))) GB_AmiMessage.Error(" Error in images assignement\n");
    } else {
      GB_AmiMessage.Error("Error, empty variable as parameter of assignment operator\n");
    }
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// Transpose
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::Transpose()
{
  FloatMatrix::ptr res( Pointer()->Transpose());
  return Variable<FloatMatrix>::ptr( new Variable<FloatMatrix>(res)); 
}

/// Pointwise multiplication 
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<FloatMatrix>::PointWiseMult(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    MATRIX_OP_EXPR(Pointer(),*,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_matrix) {
    DYNAMIC_CAST_VARIABLE(FloatMatrix,b,var_mat2);
    MATRIX_OP_MATRIX(Pointer(),var_mat2->Pointer(),*);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
