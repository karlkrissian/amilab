//
// C++ Interface: _wrap_dwControlPoint_h_
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_dwControlPoint_h_
#define _wrap_dwControlPoint_h_

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

#include "dwControlPoint.h"
#include "Variables.hpp"

AMI_DECLARE_TYPE(dwControlPoint);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<dwControlPoint>::CreateVar( ParamList* p, bool quiet );

// allow wrapping of std::vector<dwControlPoint>
AMI_DECLARE_TYPE(std::vector<dwControlPoint>);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<std::vector<dwControlPoint> >::CreateVar( ParamList* p, bool quiet );


class WrapClass_dwControlPoint: public WrapClass<dwControlPoint>
{
  DEFINE_CLASS(WrapClass_dwControlPoint);

  public:

    /// Constructor
    WrapClass_dwControlPoint(dwControlPoint::ptr si): WrapClass<dwControlPoint>(si) { }

    /// Constructor
    WrapClass_dwControlPoint(boost::shared_ptr<dwControlPoint const> si, bool): 
      WrapClass<dwControlPoint>(si,true) { }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( dwControlPoint, "Wrapping of dwControlPoint." );

    // wrapping of other methods
    ADD_CLASS_SETGET(float,X,"X position");
    ADD_CLASS_SETGET(float,Y,"Y position");

    ADD_CLASS_SETGET(double,midpoint, "midpoint for curve interpolation (see vtkPiecewiseFunction)");
    ADD_CLASS_SETGET(double,sharpness,"sharpness for curve interpolation (see vtkPiecewiseFunction)");

    ADD_CLASS_SETGET(unsigned char,HorizontalLine,
                      "horizontal line property: 0 or 1.");
    ADD_CLASS_SETGET(unsigned char,VerticalLine,  
                      "vertical line property: 0 or 1.");

    ADD_CLASS_SETGET(unsigned char,YLocked,  
                      "Lock/Unlock y coordinate: 1 or 0.");

    ADD_CLASS_SETGET(int,Type,"the point type, 0 for normal_point, 1 for colormap point");

    ADD_CLASS_METHOD(GetColour, "Gets the colour.");
    ADD_CLASS_METHOD(SetColour, "Sets the colour.");

    ADD_CLASS_METHOD(copy,      "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<dwControlPoint>::ptr this_ptr )
    {
      AddVar_SetGetX(              this_ptr);
      AddVar_SetGetY(              this_ptr);
      AddVar_SetGetmidpoint(       this_ptr);
      AddVar_SetGetsharpness(      this_ptr);
      AddVar_SetGetHorizontalLine( this_ptr);
      AddVar_SetGetVerticalLine(   this_ptr);
      AddVar_SetGetType(           this_ptr);
      AddVar_SetGetYLocked(        this_ptr);

      AddVar_GetColour(         this_ptr);
      AddVar_SetColour(         this_ptr);

      AddVar_copy(      this_ptr);
      AddVar_assign(    this_ptr);
    };

};


#endif 
// _wrap_dwControlPoint_h_
