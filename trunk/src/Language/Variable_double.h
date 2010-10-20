
#ifndef _Variable_double_h_
#define _Variable_double_h_

#include "Variable.hpp"


//------------------------------------------------------
//------- Variable<double>
//------------------------------------------------------

/// Copy contents to new variable
template<> BasicVariable::ptr Variable<double>::NewCopy() const;

// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<double>::operator +();

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<double>::operator ++();

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<double>::operator ++(int);

/// -a
template<> BasicVariable::ptr Variable<double>::operator -();

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<double>::operator --();

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<double>::operator --(int);


/// a+b
template<> BasicVariable::ptr Variable<double>::operator +(const BasicVariable::ptr& b);

/// a+=b
template<> BasicVariable::ptr Variable<double>::operator +=(const BasicVariable::ptr& b);

/// a-b
template<> BasicVariable::ptr Variable<double>::operator -(const BasicVariable::ptr& b);

/// a-=b
template<> BasicVariable::ptr Variable<double>::operator -=(const BasicVariable::ptr& b);

/// a*b
template<> BasicVariable::ptr Variable<double>::operator *(const BasicVariable::ptr& b);

/// a*=b
template<> BasicVariable::ptr Variable<double>::operator *=(const BasicVariable::ptr& b);

/// a/b
template<> BasicVariable::ptr Variable<double>::operator /(const BasicVariable::ptr& b);

/// a/=b
template<> BasicVariable::ptr Variable<double>::operator /=(const BasicVariable::ptr& b);

/// a%b
template<> BasicVariable::ptr Variable<double>::operator %(const BasicVariable::ptr& b);

/// a%=b
template<> BasicVariable::ptr Variable<double>::operator %=(const BasicVariable::ptr& b);

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<double>::operator <(const BasicVariable::ptr& b);

/// a<=b
template<> BasicVariable::ptr Variable<double>::operator <=(const BasicVariable::ptr& b);

/// a>b
template<> BasicVariable::ptr Variable<double>::operator >(const BasicVariable::ptr& b);

/// a>=b
template<> BasicVariable::ptr Variable<double>::operator >=(const BasicVariable::ptr& b);

/// a!=b
template<> BasicVariable::ptr Variable<double>::operator !=(const BasicVariable::ptr& b);

/// a==b
template<> BasicVariable::ptr Variable<double>::operator ==(const BasicVariable::ptr& b);

// Logical operators

template<> BasicVariable::ptr Variable<double>::operator !();

template<> BasicVariable::ptr Variable<double>::operator &&(const BasicVariable::ptr& b);

template<> BasicVariable::ptr Variable<double>::operator ||(const BasicVariable::ptr& b);

// // Mathematical functions
// #define VAR_DECL_FUNC(type,fname) 
// template<> BasicVariable::ptr Variable<type>::m_##fname();

VAR_DECL_FUNC(double,sin)
VAR_DECL_FUNC(double,cos)
VAR_DECL_FUNC(double,tan)
VAR_DECL_FUNC(double,asin)
VAR_DECL_FUNC(double,acos)
VAR_DECL_FUNC(double,atan)
VAR_DECL_FUNC(double,fabs)
VAR_DECL_FUNC(double,round)
VAR_DECL_FUNC(double,floor)
VAR_DECL_FUNC(double,exp)
VAR_DECL_FUNC(double,log)
VAR_DECL_FUNC(double,ln)
VAR_DECL_FUNC(double,norm)
VAR_DECL_FUNC(double,sqrt)


/// Cast to a type based on its name as a string
template<>
BasicVariable::ptr Variable<double>::TryCast(const std::string&) const;

template<> BasicVariable::ptr Variable<double>::BasicCast(const int& type);

/// (cond?a:b)
template<> BasicVariable::ptr Variable<double>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2);


/// Other operators
/// a=b
/**
 * Basic Assignment operator
 * if b must be a numerical value here
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<double>::operator =(const BasicVariable::ptr& b);

#endif 
// _Variable_double_h_
