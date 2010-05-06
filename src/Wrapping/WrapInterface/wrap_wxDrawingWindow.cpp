//
// C++ Implementation: wrap_wxDrawingWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_wxDrawingWindow.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "wrap_wxWindow.h"

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxDrawingWindow(  WrapClass_wxDrawingWindow::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("wxDrawingWindow");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddVar_SetXLimits(         objectptr);
  objectptr->AddVar_SetYLimits(         objectptr);
  objectptr->AddVar_SetCurve(           objectptr);
  objectptr->AddVar_SetCurveProperties( objectptr);

  return amiobject;
}

//---------------------------------------------------
BasicVariable::ptr wrap_wxDrawingWindow( ParamList* p)
{
    char functionname[] = "HtmlWindow";
    char description[]=" \n\
      Wrapped wxDrawingWindow class. \n\
            ";
    char parameters[] =" \n\
      - Parent window ... \n\
            ";

  int n = 0;
  std::string* title = NULL;

  Variable<AMIObject>::ptr var;
  wxWindow* parent = NULL;

  if (get_var_param<AMIObject>(var, p, n)) 
  {
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass_wxWindow::ptr obj( boost::dynamic_pointer_cast<WrapClass_wxWindow>(object));
    if (obj.get()) {
      parent = obj->_win.get();
    } else {
      FILE_ERROR("Could not cast dynamically the variable to wxWindow.")
      HelpAndReturnVarPtr;
    }
  }  else {
    FILE_ERROR("Need a wrapped wxWindow object as parameter.")
    HelpAndReturnVarPtr;
  }

  boost::shared_ptr<wxDrawingWindow> wxw_ptr(
    new wxDrawingWindow( parent),
      wxwindow_nodeleter<wxDrawingWindow>() // deletion will be done by wxwidgets
    );

  WrapClass_wxDrawingWindow::ptr wp(new WrapClass_wxDrawingWindow(wxw_ptr));


  AMIObject::ptr amiobject (AddWrap_wxDrawingWindow(wp));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));

  return varres;
}


//---------------------------------------------------
//  SetXLimits
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetXLimits::SetParametersComments() 
{
  ADDPARAMCOMMENT( "minimal value (def:-10).");
  ADDPARAMCOMMENT( "maximal value (def:10).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetXLimits::CallMember( ParamList* p)
{
  float xmin = -10;
  float xmax = 10;
  int n=0;

  if (!get_val_param<float>( xmin, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( xmax, p, n)) ClassHelpAndReturn;

  this->_objectptr->_drawingwin->SetXLimits(xmin,xmax);
  this->_objectptr->_drawingwin->Refresh();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetYLimits
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetYLimits::SetParametersComments() 
{
  ADDPARAMCOMMENT( "minimal value (def:-10).");
  ADDPARAMCOMMENT( "maximal value (def:10).");
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetYLimits::CallMember( ParamList* p)
{
  float ymin = -10;
  float ymax = 10;
  int n=0;

  if (!get_val_param<float>( ymin, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( ymax, p, n)) ClassHelpAndReturn;

  this->_objectptr->_drawingwin->SetYLimits(ymin,ymax);
  this->_objectptr->_drawingwin->Refresh();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCurve
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetCurve::SetParametersComments() 
{
  ADDPARAMCOMMENT( "input image.");
  ADDPARAMCOMMENT( "integer (def 0): position number of the curve to draw, if the number does not correspond to an existing position, a new curve is added to the list.");

}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetCurve::CallMember( ParamList* p)
{
  InrImage* input;
  int pos = 0;
  int n=0;

  if (!get_val_ptr_param<InrImage>( input,    p, n)) ClassHelpAndReturn;
  if (!get_int_param(   pos,      p, n)) ClassHelpAndReturn;

  wxDrawingWindow::ptr dw = this->_objectptr->_drawingwin;
  if ((pos>=0)&&(pos<dw->GetNumberOfCurves()))
    dw->SetCurve(pos,input);
  else
    dw->AddCurve(input);
  dw->Refresh();
}

//---------------------------------------------------
//  SetCurveProperties
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetCurveProperties::SetParametersComments() 
{
  ADDPARAMCOMMENT( "curve number (def:0).");
  ADDPARAMCOMMENT( "color as a string, format is #RRGGBB.");
  ADDPARAMCOMMENT( "style (def:0 for wxSOLID),\n\
        supported styles are: \n\
        0: wxSOLID   Solid style.\n\
        1: wxDOT   Dotted style.\n\
        2: wxLONG_DASH   Long dashed style.\n\
        3: wxSHORT_DASH  Short dashed style.\n\
        4: wxDOT_DASH  Dot and dash style..");
  ADDPARAMCOMMENT( "width (def:1).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetCurveProperties::CallMember( ParamList* p)
{
  int curve_number       = 0;
  std::string* color_str = NULL;
  int style              = wxSOLID;
  int width              = 1;
  int n                  = 0;

  if (!get_int_param(    curve_number, p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( color_str,    p, n)) ClassHelpAndReturn;
  if (!get_int_param(    style,        p, n)) ClassHelpAndReturn;
  if (!get_int_param(    width,        p, n)) ClassHelpAndReturn;

  this->_objectptr->_drawingwin->SetCurveColor(curve_number,*color_str);
  this->_objectptr->_drawingwin->SetCurveStyle(curve_number,style);
  this->_objectptr->_drawingwin->SetCurveWidth(curve_number,width);
}

