//
// C++ Interface: wrapfunction_class
//
// Description: Prototype for wrapping functions
// based on http://www.parashift.com/c++-faq-lite/pointers-to-members.html#faq-33.1
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrapfunction_class_h_
#define _wrapfunction_class_h_

#include "paramlist.h"
#include "DefineClass.hpp"

/**
 * Basic class for wrapping class function members.
 **/
class WrapClassMember {

  DEFINE_CLASS(WrapClassMember);

  protected:
    std::string functionname;
    std::string description;
    std::string parameters;

  public:
    virtual ~WrapClassMember() = 0;
    virtual void CallProc(ParamList*) = 0;

    /**
     * Display the function help in an information dialog.
     */
    void ShowHelp();

};
 
inline WrapClassMember::~WrapClassMember() { }  // defined even though it's pure virtual; it's faster this way; 


#endif 
// _wrapfunction_class_h_
