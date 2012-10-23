//
// C++ Interface: wrap_RGBTransformBase
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_RGBTransformBase_h_
#define _wrap_RGBTransformBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "amilab_boost.h"

#include "RGBTransformBase.h"

AMI_DECLARE_TYPE(RGBTransformBase);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<RGBTransformBase>::CreateVar( ParamList* p, bool quiet);


class WrapClass_RGBTransformBase: public WrapClass<RGBTransformBase>
{
  DEFINE_CLASS(WrapClass_RGBTransformBase);

  public:

    /// Constructor
    WrapClass_RGBTransformBase(RGBTransformBase::ptr si): WrapClass<RGBTransformBase>(si) { }

    /// Constructor const
    WrapClass_RGBTransformBase(boost::shared_ptr<RGBTransformBase const> si, bool): 
      WrapClass<RGBTransformBase>(si,true) { }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( RGBTransformBase, "Wrapping of RGBTransformBase." );


    void AddMethods(WrapClass<RGBTransformBase>::ptr this_ptr )
    {
    };

};


#endif 
// _wrap_RGBTransformBase_h_
