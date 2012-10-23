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
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "DefineClass.hpp"
#include "ami_object.h"
#include <vector>


typedef std::vector<BasicVariable::ptr> VarVector;

AMI_DECLARE_TYPE(VarVector);


// varvector type
class WrapClass_VarVector : public WrapClass<VarVector>
{
  DEFINE_CLASS(WrapClass_VarVector);

  public:

    /// Constructor
    WrapClass_VarVector( const boost::shared_ptr<VarVector>& vv): WrapClass<VarVector>(vv)
    {}

    /// Constructor const
    WrapClass_VarVector( const boost::shared_ptr<VarVector const>& vv, bool): 
      WrapClass<VarVector>(vv, true)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( VarVector, "Wrapping of VarVector (std::vector<BasicVariable::ptr>)." );

/*
    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( VarVector* vv);
*/

    ADD_CLASS_METHOD( push_back,    "Add element at the end.");
    ADD_CLASS_METHOD( pop_back,     "Deletes the element at the end of a list.");
    ADD_CLASS_METHOD( size,         "Return size.");
    ADD_CLASS_METHOD( front,        "Access first element.");
    ADD_CLASS_METHOD( back,         "Access last element.");
    ADD_CLASS_METHOD( at,           "Return the value a the given position.");
    ADD_CLASS_METHOD( clear,        "Removes all elements from the vector");
    ADD_CLASS_METHOD( setelement,   "Sets the variable at the given position");

    /// <<= operator
    ADD_CLASS_METHOD( left_assign,  "Reassign operator <<=");
    ADD_CLASS_METHOD( assign,       "Assign operator =");

    void AddMethods(WrapClass<VarVector>::ptr this_ptr )
    {
      AddVar_push_back(  this_ptr);
      AddVar_pop_back(   this_ptr);
      AddVar_size(       this_ptr);
      AddVar_front(      this_ptr);
      AddVar_back(       this_ptr);
      AddVar_at(         this_ptr);
      AddVar_clear(      this_ptr);
      AddVar_setelement( this_ptr);

      // operators
      AddVar_left_assign( this_ptr);
      AddVar_assign(      this_ptr);
    }

};


#endif
// _wrap_varvector_h_
