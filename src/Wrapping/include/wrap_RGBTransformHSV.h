//
// C++ Interface: wrap_RGBTransformHSV
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_RGBTransformHSV_h_
#define _wrap_RGBTransformHSV_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "amilab_boost.h"

#include "RGBTransformHSV.h"

#include "wrap_RGBTransformBase.h"


AMI_DECLARE_TYPE(RGBTransformHSV);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformHSV>::CreateVar( ParamList* p, bool quiet);


class WrapClass_RGBTransformHSV: public WrapClass<RGBTransformHSV>, public WrapClass_RGBTransformBase
{
  DEFINE_CLASS(WrapClass_RGBTransformHSV);

  protected:  
    // for nested classes
    typedef WrapClass<RGBTransformHSV>::ptr _parentclass_ptr;
    typedef RGBTransformHSV ObjectType;

  public:

    /// Constructor
    WrapClass_RGBTransformHSV(RGBTransformHSV::ptr si): WrapClass<RGBTransformHSV>(si),WrapClass_RGBTransformBase(si) { }

    std::string ObjPointerAsString() { return "RGBTransformHSV"; }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( RGBTransformHSV, "Wrapping of RGBTransformHSV." );

    // PDI: Set the methods to change the parameters
    // wrapping of other methods
    ADD_CLASS_SETGET(float,H,"Selected Hue increment");
    ADD_CLASS_SETGET(float,S,"Selected saturation factor");
    ADD_CLASS_SETGET(float,V,"Selected value factor");

    ADD_CLASS_METHOD(copy,      "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<RGBTransformHSV>::ptr this_ptr )
    {
      // Add members from RGBTransformBase
      WrapClass_RGBTransformBase::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_RGBTransformBase>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      // PDI: Set the methods to change the parameters
      AddVar_SetGetH( this_ptr);
      AddVar_SetGetS( this_ptr);
      AddVar_SetGetV( this_ptr);
      
      AddVar_copy(      this_ptr);
      AddVar_assign(    this_ptr);
    };

};


#endif 
// _wrap_RGBTransformHSV_h_
