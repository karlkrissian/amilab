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
class WrapClass_vector : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_vector);

  // for nested classes
  typedef WrapClass_vector::ptr _parentclass_ptr;

  public:
    std::vector<BasicVariable::ptr> vector;

    ADD_CLASS_METHOD( push_back,    "Add element at the end.");
    ADD_CLASS_METHOD( pop_back,     "Deletes the element at the end of a list.");
    ADD_CLASS_METHOD( size,         "Return size.");
    ADD_CLASS_METHOD( front,        "Access first element.");
    ADD_CLASS_METHOD( back,         "Access last element.");
    ADD_CLASS_METHOD( at,           "Return the value a the given position.");
    ADD_CLASS_METHOD( clear,        "Removes all elements from the vector");

};

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_VarVector( ParamList* p);


#endif
// _wrap_varvector_h_
