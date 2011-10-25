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
#include "ami_object.h"
#include "ami_function.h"
#include "wrap_wxWindow.h"
#include "CallBackAMIFunction.h"
#include "wrap_dwControlPoint.h"
#include "wrap_dwCurve.h"
#include "wrap_dwControlledCurve.h"
#include "wrap_stdvector.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxDrawingWindow>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_wxDrawingWindow::wrap_wxDrawingWindow construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxDrawingWindow);

//
// static member for creating a variable from a pointer to wxDrawingWindow
//
Variable<AMIObject>::ptr WrapClass_wxDrawingWindow::CreateVar( wxDrawingWindow* sp)
{
  return 
    WrapClass<wxDrawingWindow>::CreateVar(
      new WrapClass_wxDrawingWindow(
        boost::shared_ptr<wxDrawingWindow>(sp,
        wxwindow_nodeleter<wxDrawingWindow>() 
        // deletion will be done by wxwidgets
        ))
    );
}



//---------------------------------------------------
//  wxDrawingWindow Constructor
//---------------------------------------------------
void  WrapClass_wxDrawingWindow::
      wrap_wxDrawingWindow::SetParametersComments() 
{
  ADDPARAMCOMMENT("wxWindow: parent");
  return_comments = "A wrapped xDrawingWindow object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_wxDrawingWindow::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(wxWindow,var,parent);
  if (parent.get())
    return WrapClass_wxDrawingWindow::CreateVar(new wxDrawingWindow(parent.get()));
  else
    ClassHelpAndReturn;
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

  _objectptr->GetObj()->SetXLimits(xmin,xmax);
  _objectptr->GetObj()->Refresh();
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

  _objectptr->GetObj()->SetYLimits(ymin,ymax);
  _objectptr->GetObj()->Refresh();
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

  wxDrawingWindow::ptr dw = _objectptr->GetObj();
  if ((pos>=0)&&(pos<dw->GetNumberOfCurves()))
    dw->SetCurve(pos,input);
  else
    dw->AddCurve(input);
  dw->Refresh();

  return BasicVariable::ptr();
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
  if (!get_val_ptr_param<std::string>( color_str,    p, n)) ClassHelpAndReturn;
  if (!get_int_param(    style,        p, n)) ClassHelpAndReturn;
  if (!get_int_param(    width,        p, n)) ClassHelpAndReturn;

  _objectptr->GetObj()->SetCurveColor(curve_number,*color_str);
  _objectptr->GetObj()->SetCurveStyle(curve_number,style);
  _objectptr->GetObj()->SetCurveWidth(curve_number,width);

  return BasicVariable::ptr();

}

//---------------------------------------------------
//  SetCurveDrawLines
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetCurveDrawLines::SetParametersComments() 
{
  ADDPARAMCOMMENT( "curve number (def:0).");
  ADDPARAMCOMMENT( "bool: Enable/Disable.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetCurveDrawLines::CallMember( ParamList* p)
{
  int curve_number       = 0;
  unsigned char enable   = 1;
  int n                  = 0;

  if (!get_val_param<int>(           curve_number, p, n)) ClassHelpAndReturn;
  if (!get_val_param<unsigned char>( enable,       p, n)) ClassHelpAndReturn;

  _objectptr->GetObj()->SetCurveDrawLines(curve_number,enable);

  return BasicVariable::ptr();

}

//---------------------------------------------------
//  SetCurveDrawPoints
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetCurveDrawPoints::SetParametersComments() 
{
  ADDPARAMCOMMENT( "curve number (def:0).");
  ADDPARAMCOMMENT( "bool: Enable/Disable.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetCurveDrawPoints::CallMember( ParamList* p)
{
  int curve_number       = 0;
  unsigned char enable   = 1;
  int n                  = 0;

  if (!get_val_param<int>(           curve_number, p, n)) ClassHelpAndReturn;
  if (!get_val_param<unsigned char>( enable,       p, n)) ClassHelpAndReturn;

  _objectptr->GetObj()->SetCurveDrawPoints(curve_number,enable);

  return BasicVariable::ptr();

}

//---------------------------------------------------
//  Paint
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_Paint::SetParametersComments() 
{
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_Paint::CallMember( ParamList* p)
{
  _objectptr->GetObj()->Paint();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetNumberOfCtrlPoints
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetNumberOfCtrlPoints::SetParametersComments() 
{
  return_comments = "Current number of control points";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetNumberOfCtrlPoints::CallMember( ParamList* p)
{
  int n =   _objectptr->GetObj()->GetNumberOfCtrlPoints();
  RETURN_VAR(int,n);
}

//---------------------------------------------------
//  GetCtrlPoint
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetCtrlPoint::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"index of the control point");
  return_comments = "the given control point";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetCtrlPoint::CallMember( ParamList* p)
{
  int index = 0;
  int n     = 0;
  if (!get_val_param<int>( index, p, n)) ClassHelpAndReturn;

  dwControlPoint cp = _objectptr->GetObj()->GetControlPoint(index);

  // now
  return AMILabType<dwControlPoint>::CreateVar(new dwControlPoint(cp));
}


//---------------------------------------------------
//  SetCtrlPoint
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetCtrlPoint::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"index of the control point");
  ADDPARAMCOMMENT_TYPE(dwControlPoint,"Control point");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetCtrlPoint::CallMember( ParamList* p)
{
  int index = 0;
  int n     = 0;
  if (!get_val_param<int>( index, p, n)) ClassHelpAndReturn;
  CLASS_GET_OBJECT_PARAM(dwControlPoint,var,varobj);
  
  if ((index>=0)&&
      (index<(int)_objectptr->GetObj()->_controlpoints->size()))
  {
    (*_objectptr->GetObj()->_controlpoints)[index] = (*varobj);
  }
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetCtrlPointX
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetCtrlPointX::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"index of the control point");
  return_comments = "X position of the given control point";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetCtrlPointX::CallMember( ParamList* p)
{
  int index = 0;
  int n     = 0;

  if (!get_val_param<int>( index, p, n)) ClassHelpAndReturn;

  dwControlPoint cp = _objectptr->GetObj()->GetControlPoint(index);
  RETURN_VAR(double,cp.GetX());
}

//---------------------------------------------------
//  GetCtrlPointY
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetCtrlPointY::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"index of the control point");
  return_comments = "Y position of the given control point";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetCtrlPointY::CallMember( ParamList* p)
{
  int index = 0;
  int n     = 0;

  if (!get_val_param<int>( index, p, n)) ClassHelpAndReturn;

  dwControlPoint cp = _objectptr->GetObj()->GetControlPoint(index);
  RETURN_VAR(double,cp.GetY());
}

//---------------------------------------------------
//  SetCtrlPointX
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetCtrlPointX::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"index of the control point");
  ADDPARAMCOMMENT_TYPE(float,"X position in world coordinates.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetCtrlPointX::CallMember( ParamList* p)
{
  int n     = 0;

  GET_PARAM(int,  index,0)
  GET_PARAM(float,xpos,0)

  (*_objectptr->GetObj()->_controlpoints)[index].SetPos(
      xpos,
      (*_objectptr->GetObj()->_controlpoints)[index].GetY());
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCtrlPointY
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetCtrlPointY::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"index of the control point");
  ADDPARAMCOMMENT_TYPE(float,"Y position in world coordinates.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetCtrlPointY::CallMember( ParamList* p)
{
  int n     = 0;
  GET_PARAM(int,  index,0)
  GET_PARAM(float,ypos,0)

  (*_objectptr->GetObj()->_controlpoints)[index].SetPos(
      (*_objectptr->GetObj()->_controlpoints)[index].GetX(),
      ypos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCtrlPointCallback
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetCtrlPointCallback::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(AMIFunction,"Callback function (AMIFunction)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetCtrlPointCallback::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  Variable<AMIFunction>::ptr varfunc;
  int n=0;
  if (!get_var_param<AMIFunction>(varfunc,p,n))  ClassHelpAndReturn;

  AMIFunction::ptr func(varfunc->Pointer());
  CallBackAMIFunction::ptr cb(new CallBackAMIFunction(func));
  _objectptr->GetObj()->SetCtrlPointCallback( cb );

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetPaintCallback
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_SetPaintCallback::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(AMIFunction,"Callback function (AMIFunction)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_SetPaintCallback::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  Variable<AMIFunction>::ptr varfunc;
  int n=0;
  if (!get_var_param<AMIFunction>(varfunc,p,n))  ClassHelpAndReturn;

  AMIFunction::ptr func(varfunc->Pointer());
  CallBackAMIFunction::ptr cb(new CallBackAMIFunction(func));
  _objectptr->GetObj()->SetPaintCallback( cb );

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  AddControlPoint
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_AddControlPoint::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(dwControlPoint,"Control Point to add.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_AddControlPoint::CallMember( ParamList* p)
{
  int n=0;
  CLASS_GET_OBJECT_PARAM(dwControlPoint,var,varobj);
  _objectptr->GetObj()->AddControlPoint(*varobj);
  return BasicVariable::ptr();
}

/*
//---------------------------------------------------
//  RemoveControl
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_RemoveControl::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"Index of the control point to be removed.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_RemoveControl::CallMember( ParamList* p)
{
  int n     = 0;
  GET_PARAM(int,  index,0)
  _objectptr->GetObj()->RemoveControl(index);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  GetColormapImage
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetColormapImage::SetParametersComments() 
{
  return_comments = "Image of the colormap, of type RGB, 3 components, and dimensions 256x1x1.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetColormapImage::CallMember( ParamList* p)
{
  InrImage::ptr res = _objectptr->GetObj()->GetColormapImage();
  return Variable<InrImage>::ptr(new Variable<InrImage>(res));
}

//---------------------------------------------------
//  GetControlPoints
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetControlPoints::SetParametersComments() 
{
  return_comments = "The std::vector of dwControlPoints.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetControlPoints::CallMember( ParamList* p)
{
  boost::shared_ptr<std::vector<dwControlPoint> > obj_ptr = _objectptr->GetObj()->GetControlPoints();
  return AMILabType<std::vector<dwControlPoint> >::CreateVarFromSmtPtr(obj_ptr);
}

//---------------------------------------------------
//  GetCurves
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetCurves::SetParametersComments() 
{
  return_comments = "The std::vector of dwCurve.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetCurves::CallMember( ParamList* p)
{
  boost::shared_ptr<std::vector<dwCurve> > obj_ptr = _objectptr->GetObj()->GetCurves();
  return AMILabType<std::vector<dwCurve> >::CreateVarFromSmtPtr(obj_ptr);
}

//---------------------------------------------------
//  GetControlledCurves
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetControlledCurves::SetParametersComments() 
{
  return_comments = "The std::vector of dwControlledCurve.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetControlledCurves::CallMember( ParamList* p)
{
  boost::shared_ptr<std::vector<dwControlledCurve> > obj_ptr = _objectptr->GetObj()->GetControlledCurves();
  return AMILabType<std::vector<dwControlledCurve> >::CreateVarFromSmtPtr(obj_ptr);
}


//---------------------------------------------------
//  GetNumberOfCurves
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetNumberOfCurves::SetParametersComments() 
{
  return_comments = "Numbers of curves";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetNumberOfCurves::CallMember( ParamList* p)
{
  RETURN_VAR(int,this->_objectptr->GetObj()->GetNumberOfCurves());
}

//---------------------------------------------------
//  Colour Map operations
//---------------------------------------------------

//---------------------------------------------------
//  DrawLinearCM
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_DrawLinearCM::SetParametersComments() 
{
  return_comments = "Calculate linearCM vector";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_DrawLinearCM::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->DrawLinearCM();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetSizerlinearCM
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetSizelinearCM::SetParametersComments() 
{
  return_comments = "Colour of the point as a wxColour object";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetSizelinearCM::CallMember( ParamList* p)
{
  RETURN_VAR(int,this->_objectptr->GetObj()->GetSizelinearCM());
}


//---------------------------------------------------
//  GetColourlinearCM
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetColourlinearCM::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"Index of the linearCM point.");
  return_comments = "Colour of the point as a wxColour object";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetColourlinearCM::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,pos,0);  
  wxColour* c = new wxColour(this->_objectptr->GetObj()->GetColourlinearCM(pos));
  return AMILabType<wxColour>::CreateVar(c);
}


//---------------------------------------------------
//  GetAlphalinearCM
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetAlphalinearCM::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"Index of the linearCM point.");
  return_comments = "Alpha value of the point X as double";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetAlphalinearCM::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,pos,0);  
  RETURN_VAR(double,this->_objectptr->GetObj()->GetAlphalinearCM(pos));
}


//---------------------------------------------------
//  GetPoslinearCM
//---------------------------------------------------
void WrapClass_wxDrawingWindow::
      wrap_GetPoslinearCM::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"Index of the linearCM point.");
  return_comments = "Pos value of the point X as double";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawingWindow::
      wrap_GetPoslinearCM::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,pos,0);  
  RETURN_VAR(double,this->_objectptr->GetObj()->GetPoslinearCM(pos));
}
