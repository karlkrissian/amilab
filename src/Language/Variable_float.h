
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

#endif 
// _Variable_float_h_
