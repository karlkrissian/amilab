//
// C++ Interface: wrap_varlist
//
// Description: Wrapping of a list of variables
//
//
// Author: Karl krissian  <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_varlist_h_
#define _wrap_varlist_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "DefineClass.hpp"
#include <list>

// varlist type
class VarList
{
  DEFINE_CLASS(VarList);

  public:
    std::list<BasicVariable::ptr> list;
};

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_VarList( ParamList* p);

ADD_METHOD( VarList, push_front,        "Add element at beginning.");
ADD_METHOD( VarList, push_back,         "Add element at the end.");
ADD_METHOD( VarList, pop_front,         "Deletes the element at the beginning of a list.");
ADD_METHOD( VarList, pop_back,          "Deletes the element at the end of a list.");
ADD_METHOD( VarList, size,              "Return size.");
ADD_METHOD( VarList, front,             "Access first element.");
ADD_METHOD( VarList, back,              "Access last element.");


#endif
// _wrap_varlist_h_
