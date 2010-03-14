//
// C++ Interface: wrap_varvector
//
// Description: Wrapping of a list of variables
//
//
// Author: Karl krissian  <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_varvector_h_
#define _wrap_varvector_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "DefineClass.hpp"
#include <vector>

// varvector type
class VarVector
{
  DEFINE_CLASS(VarVector);

  public:
    std::vector<BasicVariable::ptr> vector;

  ADD_CLASS_METHOD(clear, "Removes all elements from the vector");

};

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_VarVector( ParamList* p);

ADD_METHOD( VarVector, push_back,         "Add element at the end.");
ADD_METHOD( VarVector, pop_back,          "Deletes the element at the end of a list.");
ADD_METHOD( VarVector, size,              "Return size.");
ADD_METHOD( VarVector, front,             "Access first element.");
ADD_METHOD( VarVector, back,              "Access last element.");

ADD_METHOD( VarVector, at,                "Return the value a the given position.");

#endif
// _wrap_varvector_h_
