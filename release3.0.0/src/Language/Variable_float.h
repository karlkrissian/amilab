
#ifndef _Variable_float_h_
#define _Variable_float_h_

#include "Variable.hpp"


//------------------------------------------------------
//------- Variable<float>
//------------------------------------------------------

/// Copy contents to new variable
template<> BasicVariable::ptr Variable<float>::NewCopy() const;

// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<float>::operator +();

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<float>::operator ++();

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<float>::operator ++(int);

/// -a
template<> BasicVariable::ptr Variable<float>::operator -();

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<float>::operator --();

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<float>::operator --(int);


/// a+b
template<> BasicVariable::ptr Variable<float>::operator +(const BasicVariable::ptr& b);

/// a+=b
template<> BasicVariable::ptr Variable<float>::operator +=(const BasicVariable::ptr& b);

/// a-b
template<> BasicVariable::ptr Variable<float>::operator -(const BasicVariable::ptr& b);

/// a-=b
template<> BasicVariable::ptr Variable<float>::operator -=(const BasicVariable::ptr& b);

/// a*b
template<> BasicVariable::ptr Variable<float>::operator *(const BasicVariable::ptr& b);

/// a*=b
template<> BasicVariable::ptr Variable<float>::operator *=(const BasicVariable::ptr& b);

/// a/b
template<> BasicVariable::ptr Variable<float>::operator /(const BasicVariable::ptr& b);

/// a/=b
template<> BasicVariable::ptr Variable<float>::operator /=(const BasicVariable::ptr& b);

/// a%b
template<> BasicVariable::ptr Variable<float>::operator %(const BasicVariable::ptr& b);

/// a%=b
template<> BasicVariable::ptr Variable<float>::operator %=(const BasicVariable::ptr& b);

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<float>::operator <(const BasicVariable::ptr& b);

/// a<=b
template<> BasicVariable::ptr Variable<float>::operator <=(const BasicVariable::ptr& b);

/// a>b
template<> BasicVariable::ptr Variable<float>::operator >(const BasicVariable::ptr& b);

/// a>=b
template<> BasicVariable::ptr Variable<float>::operator >=(const BasicVariable::ptr& b);

/// a!=b
template<> BasicVariable::ptr Variable<float>::operator !=(const BasicVariable::ptr& b);

/// a==b
template<> BasicVariable::ptr Variable<float>::operator ==(const BasicVariable::ptr& b);

// Logical operators

template<> BasicVariable::ptr Variable<float>::operator !();

template<> BasicVariable::ptr Variable<float>::operator &&(const BasicVariable::ptr& b);

template<> BasicVariable::ptr Variable<float>::operator ||(const BasicVariable::ptr& b);

// // Mathematical functions
// #define VAR_DECL_FUNC(type,fname) 
// template<> BasicVariable::ptr Variable<type>::m_##fname();

VAR_DECL_FUNC(float,sin)
VAR_DECL_FUNC(float,cos)
VAR_DECL_FUNC(float,tan)
VAR_DECL_FUNC(float,asin)
VAR_DECL_FUNC(float,acos)
VAR_DECL_FUNC(float,atan)
VAR_DECL_FUNC(float,fabs)
VAR_DECL_FUNC(float,round)
VAR_DECL_FUNC(float,floor)
VAR_DECL_FUNC(float,exp)
VAR_DECL_FUNC(float,log)
VAR_DECL_FUNC(float,ln)
VAR_DECL_FUNC(float,norm)
VAR_DECL_FUNC(float,sqrt)

/// Cast to a type based on its name as a string
template<>
BasicVariable::ptr Variable<float>::TryCast(const std::string&) const;


template<> BasicVariable::ptr Variable<float>::BasicCast(const int& type);

/// (cond?a:b)
template<> BasicVariable::ptr Variable<float>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2);


/// Other operators
/// a=b
/**
 * Basic Assignment operator
 * if b must be a numerical value here
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<float>::operator =(const BasicVariable::ptr& b);

#endif 
// _Variable_float_h_
