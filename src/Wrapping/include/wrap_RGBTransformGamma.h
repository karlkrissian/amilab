//
// C++ Interface: wrap_RGBTransformGamma
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_RGBTransformGamma_h_
#define _wrap_RGBTransformGamma_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "amilab_boost.h"

#include "RGBTransformGamma.h"

#include "wrap_RGBTransformBase.h"


AMI_DECLARE_TYPE(RGBTransformGamma);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformGamma>::CreateVar( ParamList* p, 
                                                            bool quiet);


class WrapClass_RGBTransformGamma: public WrapClass<RGBTransformGamma>, public WrapClass_RGBTransformBase
{
  DEFINE_CLASS(WrapClass_RGBTransformGamma);

  protected:  
    // for nested classes
    typedef WrapClass<RGBTransformGamma>::ptr _parentclass_ptr;
    typedef RGBTransformGamma ObjectType;

  public:

    /// Constructor
    WrapClass_RGBTransformGamma(RGBTransformGamma::ptr si): 
      WrapClass<RGBTransformGamma>(si),WrapClass_RGBTransformBase(si) { }

    std::string ObjPointerAsString() { return "RGBTransformGamma"; }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( RGBTransformGamma, "Wrapping of RGBTransformGamma." );

    // PDI: Set the methods to change the parameters
    // wrapping of other methods
    ADD_CLASS_SETGET(float,gamma,"Selected gamma coefficient");

    ADD_CLASS_METHOD(copy,      "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<RGBTransformGamma>::ptr this_ptr )
    {
      // Add members from RGBTransformBase
      WrapClass_RGBTransformBase::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_RGBTransformBase>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      // PDI: Set the methods to change the parameters
      AddVar_SetGetgamma( this_ptr);
      
      AddVar_copy(      this_ptr);
      AddVar_assign(    this_ptr);
    };

};


#endif 
// _wrap_RGBTransformGamma_h_
