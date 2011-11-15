//
// C++ Interface: wrap_RGBTransformInc
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_RGBTransformInc_h_
#define _wrap_RGBTransformInc_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "amilab_boost.h"

#include "RGBTransformInc.h"

#include "wrap_RGBTransformBase.h"


AMI_DECLARE_TYPE(RGBTransformInc);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformInc>::CreateVar( ParamList* p,
                                                          bool quiet);


class WrapClass_RGBTransformInc:  public WrapClass<RGBTransformInc>, 
                                  public WrapClass_RGBTransformBase
{
  DEFINE_CLASS(WrapClass_RGBTransformInc);

  protected:  
    // for nested classes
    typedef WrapClass<RGBTransformInc>::ptr _parentclass_ptr;
    typedef RGBTransformInc ObjectType;

  public:

    /// Constructor
    WrapClass_RGBTransformInc(RGBTransformInc::ptr si): 
      WrapClass<RGBTransformInc>(si),WrapClass_RGBTransformBase(si) 
    { }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( RGBTransformInc, "Wrapping of RGBTransformInc." );

    // PDI: Set the methods to change the parameters
    // wrapping of other methods
    ADD_CLASS_SETGET(int,R,"Selected Red   increment");
    ADD_CLASS_SETGET(int,G,"Selected Green increment");
    ADD_CLASS_SETGET(int,B,"Selected Blue  increment");

    ADD_CLASS_METHOD(copy,      "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<RGBTransformInc>::ptr this_ptr )
    {
      // Add members from RGBTransformBase
      WrapClass_RGBTransformBase::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_RGBTransformBase>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      // PDI: Set the methods to change the parameters
      AddVar_SetGetR( this_ptr);
      AddVar_SetGetG( this_ptr);
      AddVar_SetGetB( this_ptr);
      
      AddVar_copy(      this_ptr);
      AddVar_assign(    this_ptr);
    };

};


#endif 
// _wrap_RGBTransformInc_h_
