//
// C++ Interface: wrap_wxDrawingWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxDrawingWindow_h_
#define _wrap_wxDrawingWindow_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>
#include "wrap_wxWindow.h"
#include "wxDrawingWindow.h"

AMI_DECLARE_TYPE(wxDrawingWindow);

class WrapClass_wxDrawingWindow : public WrapClass<wxDrawingWindow>, public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxDrawingWindow);

  protected:
    // for nested classes
    typedef WrapClass<wxDrawingWindow>::ptr _parentclass_ptr;
    typedef wxDrawingWindow ObjectType;

  public:

    /// Constructor
    WrapClass_wxDrawingWindow(boost::shared_ptr<wxDrawingWindow> w): WrapClass<wxDrawingWindow>(w), WrapClass_wxWindow(w)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDrawingWindow, "Wrapping of wxDrawingWindow." )

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDrawingWindow*);

    ADD_CLASS_METHOD(SetXLimits,         "Sets the limits along X axis.");
    ADD_CLASS_METHOD(SetYLimits,         "Sets the limits along Y axis.");
    ADD_CLASS_METHOD(SetCurve,           "Sets the curve to draw in the Main Frame based on the first line of the given image.");
    ADD_CLASS_METHOD(SetCurveProperties, "Sets the properties of the displayed curve: color, style, width.");
    ADD_CLASS_METHOD(SetCurveDrawLines,  "Enable/Disable drawing of a curve lines.");
    ADD_CLASS_METHOD(SetCurveDrawPoints,  "Enable/Disable drawing of a curve points.");
    ADD_CLASS_METHOD(Paint,               "Redraws the contents of the window.");
    ADD_CLASS_METHOD(GetNumberOfCtrlPoints,"Returns the number of control points used.");
    ADD_CLASS_METHOD(GetCtrlPoint,        "Returns the control point at the given index.");
    ADD_CLASS_METHOD(SetCtrlPoint,        "Sets the control point at the given index.");
    ADD_CLASS_METHOD(GetCtrlPointX,        "Returns the X position a given control point.");
    ADD_CLASS_METHOD(GetCtrlPointY,        "Returns the Y position a given control point.");
    ADD_CLASS_METHOD(SetCtrlPointX,        "Sets the X position a given control point.");
    ADD_CLASS_METHOD(SetCtrlPointY,        "Sets the Y position a given control point.");
    ADD_CLASS_METHOD(SetCtrlPointCallback, "Callback for motion of a control point.");

    ADD_CLASS_METHOD(AddControlPoint,      "Adds a control point.");
//    ADD_CLASS_METHOD(RemoveControl,        "Removes a control point.");

    ADD_CLASS_METHOD(GetColormapImage,     "Returns the image representing the colormap.");

    ADD_CLASS_METHOD(GetControlPoints,     "Returns a reference to the std::vector of control points.");

    ADD_CLASS_METHOD(GetCurves,            "Returns a reference to the std::vector of the curves.");

    ADD_CLASS_METHOD(GetControlledCurves,  "Returns a reference to the std::vector of the controlled curves.");

    void AddMethods(WrapClass<wxDrawingWindow>::ptr this_ptr )
    {
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      AddVar_SetXLimits(            this_ptr);
      AddVar_SetYLimits(            this_ptr);
      AddVar_SetCurve(              this_ptr);
      AddVar_SetCurveProperties(    this_ptr);
      AddVar_SetCurveDrawLines(     this_ptr);
      AddVar_SetCurveDrawPoints(    this_ptr);
      AddVar_Paint(                 this_ptr, "_Paint");
      AddVar_GetNumberOfCtrlPoints( this_ptr);
      AddVar_GetCtrlPoint(          this_ptr);
      AddVar_SetCtrlPoint(          this_ptr);
      AddVar_GetCtrlPointX(         this_ptr);
      AddVar_GetCtrlPointY(         this_ptr);
      AddVar_SetCtrlPointX(         this_ptr);
      AddVar_SetCtrlPointY(         this_ptr);
      AddVar_SetCtrlPointCallback(  this_ptr);

      AddVar_AddControlPoint(       this_ptr);
//      AddVar_RemoveControl(         this_ptr);

      AddVar_GetColormapImage(      this_ptr);

      AddVar_GetControlPoints(      this_ptr);
      AddVar_GetCurves(             this_ptr);
      AddVar_GetControlledCurves(   this_ptr);
    }

};


#endif // _wrap_wxDrawingWindow_h_
