//
// C++ Interface: _wrap_dwControlledCurve_h_
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_dwControlledCurve_h_
#define _wrap_dwControlledCurve_h_

#include "AMILabConfig.h"

#ifdef AMI_USE_PRECOM_HEADERS
  #include "WrapInterface_header.h"
#else
  #include "wrapfunction_class.h"
  #include "wrapfunctions.hpp"
  #include "Variable.hpp"
  #include "paramlist.h"
  #include "ami_object.h"
  #include "amilab_boost.h"
#endif


#include "dwControlledCurve.h"

AMI_DECLARE_TYPE(dwControlledCurve);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<dwControlledCurve>::CreateVar( ParamList* p);

// allow wrapping of std::vector<dwControlledCurve>
AMI_DECLARE_TYPE(std::vector<dwControlledCurve>);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<std::vector<dwControlledCurve> >::CreateVar( ParamList* p);


class WrapClass_dwControlledCurve: public WrapClass<dwControlledCurve>
{
  DEFINE_CLASS(WrapClass_dwControlledCurve);

  public:

    /// Constructor
    WrapClass_dwControlledCurve(dwControlledCurve::ptr si): WrapClass<dwControlledCurve>(si) { }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( dwControlledCurve, "Wrapping of dwControlledCurve." );

    ADD_CLASS_METHOD(GetControlPoints,     "Returns a reference to the std::vector of control points.");

    ADD_CLASS_SETGET(int,Type,"the curve type, 0 for normal_curve, 1 for colormap curve.");

    ADD_CLASS_METHOD(copy,      "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<dwControlledCurve>::ptr this_ptr )
    {
      AddVar_SetGetType(       this_ptr);
      AddVar_GetControlPoints( this_ptr);
      AddVar_copy(             this_ptr);
      AddVar_assign(           this_ptr);
    };

};


#endif 
// _wrap_dwControlledCurve_h_
