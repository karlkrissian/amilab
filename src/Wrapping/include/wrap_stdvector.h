//
// C++ Interface: wrap_stdvector
//
// Description: Wrapping of a list of variables
//
//
// Author: Karl krissian  <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_stdvector_h_
#define _wrap_stdvector_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "DefineClass.hpp"
#include "ami_object.h"
#include <vector>



// stdvector type
template<class T>
class WrapClass_StdVector : public WrapClass<std::vector<T> >, public virtual WrapClassBase
{
    typedef boost::shared_ptr<WrapClass<std::vector<T> > > _parentclass_ptr;
    typedef std::vector<T> ObjectType;

  public:

    /// Constructor
    WrapClass_StdVector(boost::shared_ptr< std::vector<T> > si): WrapClass<std::vector<T> >(si) { }

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( std::vector<T>* sp);

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( StdVector, "Wrapping of dwControlPoint." );

    ADD_CLASS_METHOD( push_back,    "Add element at the end.");
    ADD_CLASS_METHOD( pop_back,     "Deletes the element at the end of a list.");
    ADD_CLASS_METHOD( size,         "Return size.");

    ADD_CLASS_METHOD( front,        "Access first element.");
    ADD_CLASS_METHOD( back,         "Access last element.");
    ADD_CLASS_METHOD( at,           "Return the value a the given position.");

    ADD_CLASS_METHOD( clear,        "Removes all elements from the vector");
    ADD_CLASS_METHOD( setelement,   "Sets the variable at the given position");

    /// <<= operator
//    ADD_CLASS_METHOD( left_assign,  "Reassign operator <<=");
    ADD_CLASS_METHOD( assign,       "Assign operator =");
    ADD_CLASS_METHOD( copy,         "Copy constructor.");

    void AddMethods(boost::shared_ptr<WrapClass<std::vector<T> > > this_ptr )
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
 //     AddVar_left_assign( this_ptr);
      AddVar_assign(      this_ptr);
      AddVar_copy(        this_ptr);

    }

};

#include "wrap_stdvector.tpp"

#endif
// _wrap_stdvector_h_
