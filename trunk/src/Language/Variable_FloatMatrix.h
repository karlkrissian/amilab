
#ifndef _Variable_FloatMatrix_h_
#define _Variable_FloatMatrix_h_

#include "Variable.hpp"

class FloatMatrix;

//------------------------------------------------------
//------- Variable<FloatMatrix>
//------------------------------------------------------

/// Copy contents to new variable
template<> BasicVariable::ptr Variable<FloatMatrix>::NewCopy() const;

// Arithmetic operators

/*
/// +a
template<> BasicVariable::ptr Variable<FloatMatrix>::operator +();

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<FloatMatrix>::operator ++();

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<FloatMatrix>::operator ++(int);
*/

/// -a
template<> BasicVariable::ptr Variable<FloatMatrix>::operator -();

/*
/// prefix -- operator --a
template<> BasicVariable::ptr Variable<FloatMatrix>::operator --();

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<FloatMatrix>::operator --(int);
*/


/// a+b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator +(const BasicVariable::ptr& b);

/*
/// a+=b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator +=(const BasicVariable::ptr& b);
*/

/// a-b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator -(const BasicVariable::ptr& b);

/*
/// a-=b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator -=(const BasicVariable::ptr& b);
*/

/// a*b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator *(const BasicVariable::ptr& b);

/*
/// a*=b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator *=(const BasicVariable::ptr& b);
*/

/// a/b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator /(const BasicVariable::ptr& b);

/*
/// a/=b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator /=(const BasicVariable::ptr& b);
*/

/*
/// a%b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator %(const BasicVariable::ptr& b);

/// a%=b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator %=(const BasicVariable::ptr& b);
*/

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator <(const BasicVariable::ptr& b);

/// a<=b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator <=(const BasicVariable::ptr& b);

/// a>b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator >(const BasicVariable::ptr& b);

/// a>=b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator >=(const BasicVariable::ptr& b);

/// a!=b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator !=(const BasicVariable::ptr& b);

/// a==b
template<> BasicVariable::ptr Variable<FloatMatrix>::operator ==(const BasicVariable::ptr& b);

// Logical operators
/*
template<> BasicVariable::ptr Variable<FloatMatrix>::operator !();

template<> BasicVariable::ptr Variable<FloatMatrix>::operator &&(const BasicVariable::ptr& b);

template<> BasicVariable::ptr Variable<FloatMatrix>::operator ||(const BasicVariable::ptr& b);
*/

// Bitwise operators
/*
/// in this case, for vectorial images, used for pointwise cross-product.
template<> BasicVariable::ptr Variable<FloatMatrix>::operator ^(const BasicVariable::ptr& b);
*/

// // Mathematical functions
// #define VAR_DECL_FUNC(type,fname) 
// template<> BasicVariable::ptr Variable<type>::m_##fname();

VAR_DECL_FUNC(FloatMatrix,sin)
VAR_DECL_FUNC(FloatMatrix,cos)
VAR_DECL_FUNC(FloatMatrix,tan)
VAR_DECL_FUNC(FloatMatrix,asin)
VAR_DECL_FUNC(FloatMatrix,acos)
VAR_DECL_FUNC(FloatMatrix,atan)
VAR_DECL_FUNC(FloatMatrix,fabs)
VAR_DECL_FUNC(FloatMatrix,round)
VAR_DECL_FUNC(FloatMatrix,floor)
VAR_DECL_FUNC(FloatMatrix,exp)
VAR_DECL_FUNC(FloatMatrix,log)
VAR_DECL_FUNC(FloatMatrix,ln)
//VAR_DECL_FUNC(FloatMatrix,norm)
VAR_DECL_FUNC(FloatMatrix,sqrt)


/*
template<> BasicVariable::ptr Variable<FloatMatrix>::BasicCast(const int& type);
*/

/*
template<>  BasicVariable::ptr Variable<FloatMatrix>::operator[](const BasicVariable::ptr& v);
*/

/*
/// (cond?a:b)
template<> BasicVariable::ptr Variable<FloatMatrix>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2);
*/


/// Other operators
/// a=b

/// Transpose
template<> BasicVariable::ptr Variable<FloatMatrix>::Transpose();

/// Pointwise multiplication 
template<> BasicVariable::ptr Variable<FloatMatrix>::PointWiseMult(const BasicVariable::ptr& b);

/**
 * Basic Assignment operator
 * if b is 
 * - a numerical value, sets the whole image to this value
 * - another image: copy image contents
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<FloatMatrix>::operator =(const BasicVariable::ptr& b);

#endif 
// _Variable_FloatMatrix_h_
