
#ifndef _Variable_long_h_
#define _Variable_long_h_

#include "Variable.hpp"


//------------------------------------------------------
//------- Variable<long>
//------------------------------------------------------


/// Copy contents to new variable
template<> BasicVariable::ptr Variable<long int>::NewCopy() const;

// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<long>::operator +();

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<long int>::operator ++();

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<long int>::operator ++(int);

/// -a
template<> BasicVariable::ptr Variable<long int>::operator -();

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<long int>::operator --();

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<long int>::operator --(int);


/// a+b
template<> BasicVariable::ptr Variable<long int>::operator +(const BasicVariable::ptr& b);

/// a+=b
template<> BasicVariable::ptr Variable<long int>::operator +=(const BasicVariable::ptr& b);

/// a-b
template<> BasicVariable::ptr Variable<long int>::operator -(const BasicVariable::ptr& b);

/// a-=b
template<> BasicVariable::ptr Variable<long int>::operator -=(const BasicVariable::ptr& b);

/// a*b
template<> BasicVariable::ptr Variable<long int>::operator *(const BasicVariable::ptr& b);

/// a*=b
template<> BasicVariable::ptr Variable<long int>::operator *=(const BasicVariable::ptr& b);

/// a/b
template<> BasicVariable::ptr Variable<long int>::operator /(const BasicVariable::ptr& b);

/// a/=b
template<> BasicVariable::ptr Variable<long int>::operator /=(const BasicVariable::ptr& b);

/// a%b
template<> BasicVariable::ptr Variable<long int>::operator %(const BasicVariable::ptr& b);

/// a%=b
template<> BasicVariable::ptr Variable<long int>::operator %=(const BasicVariable::ptr& b);

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<long int>::operator <(const BasicVariable::ptr& b);

/// a<=b
template<> BasicVariable::ptr Variable<long int>::operator <=(const BasicVariable::ptr& b);

/// a>b
template<> BasicVariable::ptr Variable<long int>::operator >(const BasicVariable::ptr& b);

/// a>=b
template<> BasicVariable::ptr Variable<long int>::operator >=(const BasicVariable::ptr& b);

/// a!=b
template<> BasicVariable::ptr Variable<long int>::operator !=(const BasicVariable::ptr& b);

/// a==b
template<> BasicVariable::ptr Variable<long int>::operator ==(const BasicVariable::ptr& b);

// Logical operators

template<> BasicVariable::ptr Variable<long int>::operator !();

template<> BasicVariable::ptr Variable<long int>::operator &&(const BasicVariable::ptr& b);

template<> BasicVariable::ptr Variable<long int>::operator ||(const BasicVariable::ptr& b);

// Mathematical functions
#define VAR_DECL_FUNC(type,fname) \
template<> BasicVariable::ptr Variable<type>::m_##fname();

VAR_DECL_FUNC(long int,sin)
VAR_DECL_FUNC(long int,cos)
VAR_DECL_FUNC(long int,tan)
VAR_DECL_FUNC(long int,asin)
VAR_DECL_FUNC(long int,acos)
VAR_DECL_FUNC(long int,atan)
VAR_DECL_FUNC(long int,fabs)
VAR_DECL_FUNC(long int,round)
VAR_DECL_FUNC(long int,floor)
VAR_DECL_FUNC(long int,exp)
VAR_DECL_FUNC(long int,log)
VAR_DECL_FUNC(long int,ln)
VAR_DECL_FUNC(long int,norm)
VAR_DECL_FUNC(long int,sqrt)

template<> BasicVariable::ptr Variable<long int>::BasicCast(const int& type);

/// (cond?a:b)
template<> BasicVariable::ptr Variable<long int>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2);


/// Other operators
/// a=b
/**
 * Basic Assignment operator
 * if b must be a numerical value here
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<long int>::operator =(const BasicVariable::ptr& b);

#endif 
// _Variable_long_h_
