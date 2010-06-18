
#ifndef _Variable_AMIObject_h_
#define _Variable_AMIObject_h_

#include "Variable.hpp"

class AMIObject;

//------------------------------------------------------
//------- Variable<AMIObject>
//------------------------------------------------------

// Copy contents to new variable
template<> BasicVariable::ptr Variable<AMIObject>::NewCopy() const;

template<> BasicVariable::ptr Variable<AMIObject>::NewReference() const;

/*
// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<AMIObject>::operator +();

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<AMIObject>::operator ++();

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<AMIObject>::operator ++(int);

/// -a
template<> BasicVariable::ptr Variable<AMIObject>::operator -();

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<AMIObject>::operator --();

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<AMIObject>::operator --(int);


/// a+b
template<> BasicVariable::ptr Variable<AMIObject>::operator +(const BasicVariable::ptr& b);
*/
/// a+=b
template<> BasicVariable::ptr Variable<AMIObject>::operator +=(const BasicVariable::ptr& b);
/*
/// a-b
template<> BasicVariable::ptr Variable<AMIObject>::operator -(const BasicVariable::ptr& b);
*/
/// a-=b
template<> BasicVariable::ptr Variable<AMIObject>::operator -=(const BasicVariable::ptr& b);
/*
/// a*b
template<> BasicVariable::ptr Variable<AMIObject>::operator *(const BasicVariable::ptr& b);

/// a*=b
template<> BasicVariable::ptr Variable<AMIObject>::operator *=(const BasicVariable::ptr& b);

/// a/b
template<> BasicVariable::ptr Variable<AMIObject>::operator /(const BasicVariable::ptr& b);

/// a/=b
template<> BasicVariable::ptr Variable<AMIObject>::operator /=(const BasicVariable::ptr& b);

/// a%b
template<> BasicVariable::ptr Variable<AMIObject>::operator %(const BasicVariable::ptr& b);

/// a%=b
template<> BasicVariable::ptr Variable<AMIObject>::operator %=(const BasicVariable::ptr& b);

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<AMIObject>::operator <(const BasicVariable::ptr& b);

/// a<=b
template<> BasicVariable::ptr Variable<AMIObject>::operator <=(const BasicVariable::ptr& b);

/// a>b
template<> BasicVariable::ptr Variable<AMIObject>::operator >(const BasicVariable::ptr& b);

/// a>=b
template<> BasicVariable::ptr Variable<AMIObject>::operator >=(const BasicVariable::ptr& b);

/// a!=b
template<> BasicVariable::ptr Variable<AMIObject>::operator !=(const BasicVariable::ptr& b);

/// a==b
template<> BasicVariable::ptr Variable<AMIObject>::operator ==(const BasicVariable::ptr& b);

// Logical operators
template<> BasicVariable::ptr Variable<AMIObject>::operator !();

template<> BasicVariable::ptr Variable<AMIObject>::operator &&(const BasicVariable::ptr& b);

template<> BasicVariable::ptr Variable<AMIObject>::operator ||(const BasicVariable::ptr& b);

// Bitwise operators
/// in this case, for vectorial images, used for pointwise cross-product.
template<> BasicVariable::ptr Variable<AMIObject>::operator ^(const BasicVariable::ptr& b);


// Mathematical functions
#define VAR_DECL_FUNC(type,fname) \
template<> BasicVariable::ptr Variable<type>::m_##fname();

VAR_DECL_FUNC(AMIObject,sin)
VAR_DECL_FUNC(AMIObject,cos)
VAR_DECL_FUNC(AMIObject,tan)
VAR_DECL_FUNC(AMIObject,asin)
VAR_DECL_FUNC(AMIObject,acos)
VAR_DECL_FUNC(AMIObject,atan)
VAR_DECL_FUNC(AMIObject,fabs)
VAR_DECL_FUNC(AMIObject,round)
VAR_DECL_FUNC(AMIObject,floor)
VAR_DECL_FUNC(AMIObject,exp)
VAR_DECL_FUNC(AMIObject,log)
VAR_DECL_FUNC(AMIObject,ln)
VAR_DECL_FUNC(AMIObject,norm)
VAR_DECL_FUNC(AMIObject,sqrt)

//
template<> BasicVariable::ptr Variable<AMIObject>::BasicCast(const int& type);
*/

/**
 * Array subscript operator,
 * @return redirects to the object member named at() if it exists
 */
template<>  BasicVariable::ptr Variable<AMIObject>::operator[](const BasicVariable::ptr& v);


/*
/// (cond?a:b)
template<> BasicVariable::ptr Variable<AMIObject>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2);
*
*/

/// Other operators
/// a=b

/**
 * Assignment operator
 * @return 
 **/
template<> BasicVariable::ptr Variable<AMIObject>::operator =(const BasicVariable::ptr& b);

/**
 * Defines operator <<= for each object type, normally, it tries to force the assignation.
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<AMIObject>::left_assign(const BasicVariable::ptr& b);

#endif
// _Variable_AMIObject_h_
