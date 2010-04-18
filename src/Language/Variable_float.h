
#ifndef _Variable_float_h_
#define _Variable_float_h_

#include "Variable.hpp"


//------------------------------------------------------
//------- Variable<float>
//------------------------------------------------------


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
template<> BasicVariable::ptr Variable<float>::operator +(const BasicVariable& b);

/// a+=b
template<> BasicVariable::ptr Variable<float>::operator +=(const BasicVariable& b);

/// a-b
template<> BasicVariable::ptr Variable<float>::operator -(const BasicVariable& b);

/// a-=b
template<> BasicVariable::ptr Variable<float>::operator -=(const BasicVariable& b);

/// a*b
template<> BasicVariable::ptr Variable<float>::operator *(const BasicVariable& b);

/// a*=b
template<> BasicVariable::ptr Variable<float>::operator *=(const BasicVariable& b);

/// a/b
template<> BasicVariable::ptr Variable<float>::operator /(const BasicVariable& b);

/// a/=b
template<> BasicVariable::ptr Variable<float>::operator /=(const BasicVariable& b);

/// a%b
template<> BasicVariable::ptr Variable<float>::operator %(const BasicVariable& b);

/// a%=b
template<> BasicVariable::ptr Variable<float>::operator %=(const BasicVariable& b);

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<float>::operator <(const BasicVariable& b);

/// a<=b
template<> BasicVariable::ptr Variable<float>::operator <=(const BasicVariable& b);

/// a>b
template<> BasicVariable::ptr Variable<float>::operator >(const BasicVariable& b);

/// a>=b
template<> BasicVariable::ptr Variable<float>::operator >=(const BasicVariable& b);

/// a!=b
template<> BasicVariable::ptr Variable<float>::operator !=(const BasicVariable& b);

/// a==b
template<> BasicVariable::ptr Variable<float>::operator ==(const BasicVariable& b);

// Logical operators

template<> BasicVariable::ptr Variable<float>::operator !();

template<> BasicVariable::ptr Variable<float>::operator &&(const BasicVariable& b);

template<> BasicVariable::ptr Variable<float>::operator ||(const BasicVariable& b);

// Mathematical functions
#define VAR_DECL_FUNC(type,fname) \
template<> BasicVariable::ptr Variable<type>::m_##fname();

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

template<> BasicVariable::ptr Variable<float>::BasicCast(const int& type);

/// (cond?a:b)
template<> BasicVariable::ptr Variable<float>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2);

#endif 
// _Variable_float_h_
