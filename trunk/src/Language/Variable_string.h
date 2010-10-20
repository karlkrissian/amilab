
#ifndef _Variable_string_h_
#define _Variable_string_h_

#include "Variable.hpp"


//------------------------------------------------------
//------- Variable<std::string>
//------------------------------------------------------


/// Copy contents to new variable
template<> BasicVariable::ptr Variable<std::string>::NewCopy() const;

// Arithmetic operators

/*
/// +a
template<> BasicVariable::ptr Variable<std::string>::operator +();

/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<std::string>::operator ++();

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<std::string>::operator ++(int);

/// -a
template<> BasicVariable::ptr Variable<std::string>::operator -();

/// prefix -- operator --a
template<> BasicVariable::ptr Variable<std::string>::operator --();

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<std::string>::operator --(int);
*/

/// a+b
template<> BasicVariable::ptr Variable<std::string>::operator +(const BasicVariable::ptr& b);

/// a+=b
template<> BasicVariable::ptr Variable<std::string>::operator +=(const BasicVariable::ptr& b);

/**
 * Removes the string if it is at the end of the current string (inverse of +)
 * @param b : smart pointer to a string variable
 * @return 
 */
template<> BasicVariable::ptr Variable<std::string>::operator -(const BasicVariable::ptr& b);

/**
 * Removes the string if it is at the end of the current string (inverse of +=)
 * @param b : smart pointer to a string variable
 * @return 
 */
template<> BasicVariable::ptr Variable<std::string>::operator -=(const BasicVariable::ptr& b);

/*
/// a*b
template<> BasicVariable::ptr Variable<std::string>::operator *(const BasicVariable::ptr& b);

/// a*=b
template<> BasicVariable::ptr Variable<std::string>::operator *=(const BasicVariable::ptr& b);

/// a/b
template<> BasicVariable::ptr Variable<std::string>::operator /(const BasicVariable::ptr& b);

/// a/=b
template<> BasicVariable::ptr Variable<std::string>::operator /=(const BasicVariable::ptr& b);
*/


/**
 * The operator string % expr uses boost::format(string) % expr to return a formatted string
 * @param b string or numeric variable
 * @return formatted string
 */
template<> BasicVariable::ptr Variable<std::string>::operator %(const BasicVariable::ptr& b);

/*
/// a%=b
template<> BasicVariable::ptr Variable<std::string>::operator %=(const BasicVariable::ptr& b);
*/

//  Comparison Operators

/**
 * string \< operator, applies the same operator from std::string
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<std::string>::operator <(const BasicVariable::ptr& b);

/**
 * string \<= operator, applies the same operator from std::string
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<std::string>::operator <=(const BasicVariable::ptr& b);

/**
 * string \> operator, applies the same operator from std::string
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<std::string>::operator >(const BasicVariable::ptr& b);

/**
 * string \>= operator, applies the same operator from std::string
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<std::string>::operator >=(const BasicVariable::ptr& b);

/// a!=b
template<> BasicVariable::ptr Variable<std::string>::operator !=(const BasicVariable::ptr& b);

/// a==b
template<> BasicVariable::ptr Variable<std::string>::operator ==(const BasicVariable::ptr& b);

/*
// Logical operators

template<> BasicVariable::ptr Variable<std::string>::operator !();

template<> BasicVariable::ptr Variable<std::string>::operator &&(const BasicVariable::ptr& b);

template<> BasicVariable::ptr Variable<std::string>::operator ||(const BasicVariable::ptr& b);
*/

/*
template<> BasicVariable::ptr Variable<std::string>::BasicCast(const int& type);
*/


/// Other operators
/// a=b
/**
 * Basic Assignment operator
 * if b must be another string variable here
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<std::string>::operator =(const BasicVariable::ptr& b);

#endif 
// _Variable_string_h_
