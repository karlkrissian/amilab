//
// C++ Interface: wrap_RGBTransformComponent
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_RGBTransformComponent_h_
#define _wrap_RGBTransformComponent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "amilab_boost.h"

#include "RGBTransformComponent.h"

#include "wrap_RGBTransformBase.h"


AMI_DECLARE_TYPE(RGBTransformComponent);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformComponent>::CreateVar( ParamList* p, 
                                                                bool quiet);


class WrapClass_RGBTransformComponent:  public WrapClass<RGBTransformComponent>,
                                        public WrapClass_RGBTransformBase
{
  DEFINE_CLASS(WrapClass_RGBTransformComponent);

  protected:  
    // for nested classes
    typedef WrapClass<RGBTransformComponent>::ptr _parentclass_ptr;
    typedef RGBTransformComponent ObjectType;

  public:

    /// Constructor
    WrapClass_RGBTransformComponent(RGBTransformComponent::ptr si): 
      WrapClass<RGBTransformComponent>(si),WrapClass_RGBTransformBase(si) 
    { }

    /// Constructor const
    WrapClass_RGBTransformComponent(boost::shared_ptr<RGBTransformComponent const> si, bool): 
      WrapClass<RGBTransformComponent>(si, true),
      WrapClass_RGBTransformBase(si, true) 
    { }

    std::string ObjPointerAsString() { return "RGBTransformComponent"; }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( RGBTransformComponent, "Wrapping of RGBTransformComponent." );

    // PDI: Set the methods to change the parameters
    // wrapping of other methods
    ADD_CLASS_SETGET(int,component,"Selected component to display");

    ADD_CLASS_METHOD(copy,      "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<RGBTransformComponent>::ptr this_ptr )
    {
      // Add members from RGBTransformBase
      WrapClass_RGBTransformBase::ptr parent_obj(
        boost::dynamic_pointer_cast<WrapClass_RGBTransformBase>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      // PDI: Set the methods to change the parameters
      AddVar_SetGetcomponent( this_ptr);
      
      AddVar_copy(      this_ptr);
      AddVar_assign(    this_ptr);
    };

};


#endif 
// _wrap_RGBTransformComponent_h_
