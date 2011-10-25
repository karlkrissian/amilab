//
// C++ Interface: _wrap_ImageViewerBase_h_
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_ImageViewerBase_h_
#define _wrap_ImageViewerBase_h_

#include "AMILabConfig.h"

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "amilab_boost.h"

#include "ImageViewerBase.h"

AMI_DECLARE_TYPE(ImageViewerBase);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ImageViewerBase>::CreateVar( ParamList* p, bool quiet );

// allow wrapping of std::vector<ImageViewerBase>
AMI_DECLARE_TYPE(std::vector<ImageViewerBase>);


class WrapClass_ImageViewerBase: public WrapClass<ImageViewerBase>
{
  DEFINE_CLASS(WrapClass_ImageViewerBase);

  public:

    /// Constructor
    WrapClass_ImageViewerBase(ImageViewerBase::ptr si): WrapClass<ImageViewerBase>(si) { }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( ImageViewerBase, "Wrapping of ImageViewerBase." );

    void AddMethods(WrapClass<ImageViewerBase>::ptr this_ptr )
    {
    };

};


#endif 
// _wrap_ImageViewerBase_h_
