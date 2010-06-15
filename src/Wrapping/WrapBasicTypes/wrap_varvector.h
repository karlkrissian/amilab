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
#include "ami_object.h"
#include <vector>


typedef std::vector<BasicVariable::ptr> VarVector;

// varvector type
class WrapClass_VarVector : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_VarVector);

  // for nested classes
  typedef WrapClass_VarVector::ptr _parentclass_ptr;
  typedef VarVector _obj_type;

  public:
    boost::shared_ptr<_obj_type> _obj;
    const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }
    

    /// Constructor
    WrapClass_VarVector( boost::shared_ptr<VarVector>& vv): _obj(vv)
    {}

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

    void AddMethods(_parentclass_ptr& this_ptr )
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

/**
 * Create a Wrapped object around VarVector
 * @param this_ptr input smart pointer to a WrapClass_VarVector
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_VarVector(  WrapClass_VarVector::ptr& this_ptr);

/**
 * Create a Wrapped object around VarVector
 * @param si_ptr input smart pointer to a VarVector
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_VarVector( VarVector* si);

/** Method that adds wrapping of VarVector 
 */
ADD_CLASS_FUNCTION( VarVector, "Wrapping of std::vector<BasicVariable::ptr>." );



#endif
// _wrap_varvector_h_
