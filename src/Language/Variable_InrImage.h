
#ifndef _Variable_InrImage_h_
#define _Variable_InrImage_h_

#include "Variable.hpp"

class InrImage;

//------------------------------------------------------
//------- Variable<InrImage>
//------------------------------------------------------


// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<InrImage>::operator +();

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<InrImage>::operator ++();

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<InrImage>::operator ++(int);

/// -a
template<> BasicVariable::ptr Variable<InrImage>::operator -();

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<InrImage>::operator --();

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<InrImage>::operator --(int);


/// a+b
template<> BasicVariable::ptr Variable<InrImage>::operator +(const BasicVariable& b);

/// a+=b
template<> BasicVariable::ptr Variable<InrImage>::operator +=(const BasicVariable& b);

/// a-b
template<> BasicVariable::ptr Variable<InrImage>::operator -(const BasicVariable& b);

/// a-=b
template<> BasicVariable::ptr Variable<InrImage>::operator -=(const BasicVariable& b);

/// a*b
template<> BasicVariable::ptr Variable<InrImage>::operator *(const BasicVariable& b);

/// a*=b
template<> BasicVariable::ptr Variable<InrImage>::operator *=(const BasicVariable& b);

/// a/b
template<> BasicVariable::ptr Variable<InrImage>::operator /(const BasicVariable& b);

/// a/=b
template<> BasicVariable::ptr Variable<InrImage>::operator /=(const BasicVariable& b);

/// a%b
template<> BasicVariable::ptr Variable<InrImage>::operator %(const BasicVariable& b);

/// a%=b
template<> BasicVariable::ptr Variable<InrImage>::operator %=(const BasicVariable& b);

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<InrImage>::operator <(const BasicVariable& b);

/// a<=b
template<> BasicVariable::ptr Variable<InrImage>::operator <=(const BasicVariable& b);

/// a>b
template<> BasicVariable::ptr Variable<InrImage>::operator >(const BasicVariable& b);

/// a>=b
template<> BasicVariable::ptr Variable<InrImage>::operator >=(const BasicVariable& b);

/// a!=b
template<> BasicVariable::ptr Variable<InrImage>::operator !=(const BasicVariable& b);

/// a==b
template<> BasicVariable::ptr Variable<InrImage>::operator ==(const BasicVariable& b);

// Logical operators

template<> BasicVariable::ptr Variable<InrImage>::operator !();

template<> BasicVariable::ptr Variable<InrImage>::operator &&(const BasicVariable& b);

template<> BasicVariable::ptr Variable<InrImage>::operator ||(const BasicVariable& b);

// Mathematical functions
#define VAR_DECL_FUNC(type,fname) \
template<> BasicVariable::ptr Variable<type>::m_##fname();

VAR_DECL_FUNC(InrImage,sin)
VAR_DECL_FUNC(InrImage,cos)
VAR_DECL_FUNC(InrImage,tan)
VAR_DECL_FUNC(InrImage,asin)
VAR_DECL_FUNC(InrImage,acos)
VAR_DECL_FUNC(InrImage,atan)
VAR_DECL_FUNC(InrImage,fabs)
VAR_DECL_FUNC(InrImage,round)
VAR_DECL_FUNC(InrImage,floor)
VAR_DECL_FUNC(InrImage,exp)
VAR_DECL_FUNC(InrImage,log)
VAR_DECL_FUNC(InrImage,ln)
VAR_DECL_FUNC(InrImage,norm)
VAR_DECL_FUNC(InrImage,sqrt)

template<> BasicVariable::ptr Variable<InrImage>::BasicCast(const int& type);

/// (cond?a:b)
template<> BasicVariable::ptr Variable<InrImage>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2);

#endif 
// _Variable_InrImage_h_
