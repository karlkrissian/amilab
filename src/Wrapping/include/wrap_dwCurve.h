//
// C++ Interface: _wrap_dwCurve_h_
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_dwCurve_h_
#define _wrap_dwCurve_h_

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

#include "dwCurve.h"
#include "wrap_wxColour.h"
#include "Variables.hpp"

AMI_DECLARE_TYPE(dwCurve);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<dwCurve>::CreateVar( ParamList* p, bool quiet );

// allow wrapping of std::vector<dwCurve>
AMI_DECLARE_TYPE(std::vector<dwCurve>);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<std::vector<dwCurve> >::CreateVar( ParamList* p, bool quiet );


class WrapClass_dwCurve: public WrapClass<dwCurve>
{
  DEFINE_CLASS(WrapClass_dwCurve);

  public:

    /// Constructor
    WrapClass_dwCurve(dwCurve::ptr si): WrapClass<dwCurve>(si) { }

    /// Constructor const
    WrapClass_dwCurve(boost::shared_ptr<dwCurve const> si,bool): 
      WrapClass<dwCurve>(si,true) { }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( dwCurve, "Wrapping of dwCurve." );

    // wrapping of other methods
    ADD_CLASS_SETGET(unsigned char,DrawLines,"Enable/Disable the drawing of lines between the points.");
    ADD_CLASS_SETGET(unsigned char,DrawPoints,"Enable/Disable the drawing of the points.");
    ADD_CLASS_SETGET(wxColour,Colour,"the curve colour.");

    ADD_CLASS_METHOD(copy,      "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<dwCurve>::ptr this_ptr )
    {
      AddVar_SetGetDrawLines(      this_ptr);
      AddVar_SetGetDrawPoints(     this_ptr);
      AddVar_SetGetColour(         this_ptr);

      AddVar_copy(      this_ptr);
      AddVar_assign(    this_ptr);
    };

};


#endif 
// _wrap_dwCurve_h_
