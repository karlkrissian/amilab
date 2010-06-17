
#ifndef _Variable_int_h_
#define _Variable_int_h_

#include "Variable.hpp"


//------------------------------------------------------
//------- Variable<int>
//------------------------------------------------------

/// Copy contents to new variable
template<> BasicVariable::ptr Variable<int>::NewCopy() const;

// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<int>::operator +();

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<int>::operator ++();

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<int>::operator ++(int);

/// -a
template<> BasicVariable::ptr Variable<int>::operator -();

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<int>::operator --();

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<int>::operator --(int);


/// a+b
template<> BasicVariable::ptr Variable<int>::operator +(const BasicVariable::ptr& b);

/// a+=b
template<> BasicVariable::ptr Variable<int>::operator +=(const BasicVariable::ptr& b);

/// a-b
template<> BasicVariable::ptr Variable<int>::operator -(const BasicVariable::ptr& b);

/// a-=b
template<> BasicVariable::ptr Variable<int>::operator -=(const BasicVariable::ptr& b);

/// a*b
template<> BasicVariable::ptr Variable<int>::operator *(const BasicVariable::ptr& b);

/// a*=b
template<> BasicVariable::ptr Variable<int>::operator *=(const BasicVariable::ptr& b);

/// a/b
template<> BasicVariable::ptr Variable<int>::operator /(const BasicVariable::ptr& b);

/// a/=b
template<> BasicVariable::ptr Variable<int>::operator /=(const BasicVariable::ptr& b);

/// a%b
template<> BasicVariable::ptr Variable<int>::operator %(const BasicVariable::ptr& b);

/// a%=b
template<> BasicVariable::ptr Variable<int>::operator %=(const BasicVariable::ptr& b);

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<int>::operator <(const BasicVariable::ptr& b);

/// a<=b
template<> BasicVariable::ptr Variable<int>::operator <=(const BasicVariable::ptr& b);

/// a>b
template<> BasicVariable::ptr Variable<int>::operator >(const BasicVariable::ptr& b);

/// a>=b
template<> BasicVariable::ptr Variable<int>::operator >=(const BasicVariable::ptr& b);

/// a!=b
template<> BasicVariable::ptr Variable<int>::operator !=(const BasicVariable::ptr& b);

/// a==b
template<> BasicVariable::ptr Variable<int>::operator ==(const BasicVariable::ptr& b);

// Logical operators

template<> BasicVariable::ptr Variable<int>::operator !();

template<> BasicVariable::ptr Variable<int>::operator &&(const BasicVariable::ptr& b);

template<> BasicVariable::ptr Variable<int>::operator ||(const BasicVariable::ptr& b);

// Mathematical functions, 
#define VAR_DECL_FUNC(type,fname) \
template<> BasicVariable::ptr Variable<type>::m_##fname();

// TODO: don t define trigonometry for int, it should be floating point
// and these functions should not be operators ...
/*
VAR_DECL_FUNC(int,sin)
VAR_DECL_FUNC(int,cos)
VAR_DECL_FUNC(int,tan)
VAR_DECL_FUNC(int,asin)
VAR_DECL_FUNC(int,acos)
VAR_DECL_FUNC(int,atan)
*/
VAR_DECL_FUNC(int,fabs)
/* no rounding or exp
VAR_DECL_FUNC(int,round)
VAR_DECL_FUNC(int,floor)
VAR_DECL_FUNC(int,exp)
VAR_DECL_FUNC(int,log)
VAR_DECL_FUNC(int,ln)
*/
VAR_DECL_FUNC(int,norm)
VAR_DECL_FUNC(int,sqrt)


/// Cast to a type based on its name as a string
template<>
BasicVariable::ptr Variable<int>::TryCast(const std::string&) const;

template<> BasicVariable::ptr Variable<int>::BasicCast(const int& type);

/// (cond?a:b)
template<> BasicVariable::ptr Variable<int>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2);


/// Other operators
/// a=b
/**
 * Basic Assignment operator
 * if b must be a numerical value here
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<int>::operator =(const BasicVariable::ptr& b);

#endif 
// _Variable_long_h_
