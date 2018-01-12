
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




#endif
// _Variable_WrapClassMember_h_
