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
    ADD_CLASS_METHOD(SetLinearColormapCallback, "Callback for linear colormap update event.");
    
    ADD_CLASS_METHOD(AddControlPoint,       "Add control point.");
    
    ADD_CLASS_METHOD(GetNumberOfCurves,     "Returns the number of curves.");
//    ADD_CLASS_METHOD(RemoveControl,        "Removes a control point.");

    ADD_CLASS_METHOD(GetColormapImage,     "Returns the image representing the colormap.");

    ADD_CLASS_METHOD(GetControlPoints,     "Returns a reference to the std::vector of control points.");

    ADD_CLASS_METHOD(GetCurves,            "Returns a reference to the std::vector of the curves.");

    ADD_CLASS_METHOD(GetControlledCurves,  "Returns a reference to the std::vector of the controlled curves.");
    
    //Color maps operations
    ADD_CLASS_METHOD(GetSizelinearCM,      "Gets the sizer of the LienarCM vector.");
    ADD_CLASS_METHOD(GetColourlinearCM,    "Gets the colour of point x of the LienarCM vector.");
    ADD_CLASS_METHOD(GetPoslinearCM,       "Gets the pos value of point x of the LienarCM vector.");
    ADD_CLASS_METHOD(GetAlphalinearCM,     "Gets the alpha value of point x of the LienarCM vector.");
    ADD_CLASS_METHOD(DrawLinearCM,         "Calculate LienarCM vector.");
    
    void AddMethods(WrapClass<wxDrawingWindow>::ptr this_ptr )
    {

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
      AddVar_SetLinearColormapCallback( this_ptr);
      
      AddVar_AddControlPoint(       this_ptr);
//      AddVar_RemoveControl(         this_ptr);

      AddVar_GetColormapImage(      this_ptr);

      AddVar_GetControlPoints(      this_ptr);
      AddVar_GetCurves(             this_ptr);
      AddVar_GetControlledCurves(   this_ptr);
      
      AddVar_GetNumberOfCurves(     this_ptr);

      AddVar_GetSizelinearCM(       this_ptr);
      AddVar_GetColourlinearCM(     this_ptr);
      AddVar_GetPoslinearCM(        this_ptr);
      AddVar_GetAlphalinearCM(      this_ptr);
      AddVar_DrawLinearCM(          this_ptr);
      
      // Add public fields 
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());

      // Add base parent wxWindow
      boost::shared_ptr<wxWindow > parent_wxWindow(  boost::dynamic_pointer_cast<wxWindow >(this_ptr->GetObj()));
      BasicVariable::ptr var_wxWindow = AMILabType<wxWindow>::CreateVarFromSmtPtr(parent_wxWindow);
      context->AddVar("wxWindow",var_wxWindow);
      // Set as a default context
      Variable<AMIObject>::ptr obj_wxWindow = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxWindow);
      context->AddDefault(obj_wxWindow->Pointer()->GetContext());

    }

};


#endif // _wrap_wxDrawingWindow_h_
