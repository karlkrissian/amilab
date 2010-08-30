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

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "amilab_boost.h"

#include "dwControlPoint.h"

TO_STRING(dwControlPoint);

class WrapClass_dwControlPoint: public WrapClass<dwControlPoint>
{
  DEFINE_CLASS(WrapClass_dwControlPoint);

  public:

    /// Constructor
    WrapClass_dwControlPoint(dwControlPoint::ptr si): WrapClass<dwControlPoint>(si) { }

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( dwControlPoint* sp);

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( dwControlPoint, "Wrapping of dwControlPoint." );

    // wrapping of other methods
    ADD_CLASS_METHOD(GetX,      "Gets the X position.");
    ADD_CLASS_METHOD(SetX,      "Sets the X position.");

    ADD_CLASS_METHOD(GetY,      "Gets the Y position.");
    ADD_CLASS_METHOD(SetY,      "Sets the Y position.");

    ADD_CLASS_METHOD(GetHorizontalLine,      "Gets the horizontal line property.");
    ADD_CLASS_METHOD(SetHorizontalLine,      "Sets the horizontal line property.");

    ADD_CLASS_METHOD(GetVerticalLine,      "Gets the vertical line property.");
    ADD_CLASS_METHOD(SetVerticalLine,      "Sets the vertical line property.");

    ADD_CLASS_METHOD(GetType,      "Gets the point type.");
    ADD_CLASS_METHOD(SetType,      "Sets the point type.");

    ADD_CLASS_METHOD(GetColour, "Gets the colour.");
    ADD_CLASS_METHOD(SetColour, "Sets the colour.");

    ADD_CLASS_METHOD(copy,      "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<dwControlPoint>::ptr this_ptr )
    {
      AddVar_GetX(              this_ptr);
      AddVar_SetX(              this_ptr);

      AddVar_GetY(              this_ptr);
      AddVar_SetY(              this_ptr);

      AddVar_SetHorizontalLine( this_ptr);
      AddVar_GetHorizontalLine( this_ptr);

      AddVar_SetVerticalLine(   this_ptr);
      AddVar_GetVerticalLine(   this_ptr);

      AddVar_SetType(           this_ptr);
      AddVar_GetType(           this_ptr);

      AddVar_GetColour(         this_ptr);
      AddVar_SetColour(         this_ptr);

      AddVar_copy(      this_ptr);
      AddVar_assign(    this_ptr);
    };

};


#endif 
// _wrap_dwControlPoint_h_
