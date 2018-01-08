
#ifndef _Variable_WrapClassMember_h_
#define _Variable_WrapClassMember_h_

#include "Variable.hpp"

class WrapClassMember;
#include "LanguageBaseConfigure.h"

//------------------------------------------------------
//------- Variable<WrapClassMember>
//------------------------------------------------------

template<>  LanguageBase_EXPORT 
  Variable<WrapClassMember>::Variable(const boost::shared_ptr<WrapClassMember>& p);

template<>  LanguageBase_EXPORT 
  Variable<WrapClassMember>::Variable( WrapClassMember* p);

template<>  LanguageBase_EXPORT 
  Variable<WrapClassMember>::Variable(const std::string& name, 
                                const boost::shared_ptr<WrapClassMember>& p);

template<>  LanguageBase_EXPORT bool 
  Variable<WrapClassMember>::Equal( BasicVariable::ptr v);


/// Cast to a type based on its name as a string
template<> LanguageBase_EXPORT BasicVariable::ptr Variable<WrapClassMember>::TryCast(const std::string& type_string) const; ///New Added:12-07-2010


/**
 * Assignment operator
 * @return 
 **/
template<> LanguageBase_EXPORT BasicVariable::ptr Variable<WrapClassMember>::operator =(const BasicVariable::ptr& b);

/**
 * Defines operator <<= for each object type, normally, it tries to force the assignation.
 * @param b 
 * @return 
 */
template<> LanguageBase_EXPORT BasicVariable::ptr Variable<WrapClassMember>::left_assign(const BasicVariable::ptr& b);

#endif
// _Variable_WrapClassMember_h_
