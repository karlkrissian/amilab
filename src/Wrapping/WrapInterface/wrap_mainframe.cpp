//
// C++ Implementation: wrap_mainframe
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "MainFrame.h"
#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrap_mainframe.h"

extern VarContexts  Vars;

extern MainFrame*    GB_main_wxFrame;

void AddWrapMainFrame()
{

  Vars.AddVar(type_c_procedure, "mf_DrawSetCurve",  (void*) wrap_MainFrameDrawSetCurve );
  Vars.AddVar(type_c_procedure, "mf_DrawSetXLimits",  (void*) wrap_MainFrameDrawSetXLimits );
  Vars.AddVar(type_c_procedure, "mf_DrawSetYLimits",  (void*) wrap_MainFrameDrawSetYLimits );
  Vars.AddVar(type_c_procedure, "mf_DrawSetCurveProperties",  (void*) wrap_MainFrameDrawSetCurveProperties );
}


/**
 * Adds the MainFrame wrapping
 * @param p 
 */
void wrap_MainFrame( ParamList* p)
{
    char functionname[] = "MainFrame";
    char description[]=" \n\
      Adds wrapping for MainFrame. \n\
            ";
    char parameters[] =" \n\
            ";

  AddWrapMainFrame();
}


//--------------------------------------------------
void wrap_MainFrameDrawSetXLimits( ParamList* p)
{
    char functionname[] = "mf_DrawSetXLimits";
    char description[]=" \n\
      Sets the limits along X axis. \n\
            ";
    char parameters[] =" \n\
      1. minimal value (def:-10)\n\
      2. maximal value (def:10) \n\
            ";

  float xmin = -10;
  float xmax = 10;
  int n=0;

  if (!get_val_param<float>( xmin, p, n)) HelpAndReturn;
  if (!get_val_param<float>( xmax, p, n)) HelpAndReturn;

  GB_main_wxFrame->GetDrawingWindow()->SetXLimits(xmin,xmax);
  GB_main_wxFrame->GetDrawingWindow()->Refresh();
}


//--------------------------------------------------
void wrap_MainFrameDrawSetYLimits( ParamList* p)
{
    char functionname[] = "mf_DrawSetYLimits";
    char description[]=" \n\
      Sets the limits along Y axis. \n\
            ";
    char parameters[] =" \n\
      1. minimal value (def:-10)\n\
      2. maximal value (def:10) \n\
            ";

  float ymin = -10;
  float ymax = 10;
  int n=0;

  if (!get_val_param<float>( ymin, p, n)) HelpAndReturn;
  if (!get_val_param<float>( ymax, p, n)) HelpAndReturn;

  GB_main_wxFrame->GetDrawingWindow()->SetYLimits(ymin,ymax);
  GB_main_wxFrame->GetDrawingWindow()->Refresh();
}


//--------------------------------------------------
void wrap_MainFrameDrawSetCurve( ParamList* p)
{
    char functionname[] = "mf_DrawSetCurve";
    char description[]=" \n\
      Set the curve to draw in the Main Frame based on the first line of the given image \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input          : image\n\
              integer (def 0): position number of the curve to draw, if the number does not correspond to an existing position, a new curve is added to the list\n\
            ";

  InrImage* input;
  int pos = 0;
  int n=0;

  if (!get_val_ptr_param<InrImage>( input,    p, n)) HelpAndReturn;
  if (!get_int_param(   pos,      p, n)) HelpAndReturn;

  wxDrawingWindow* dw = GB_main_wxFrame->GetDrawingWindow();
  if ((pos>=0)&&(pos<dw->GetNumberOfCurves()))
    dw->SetCurve(pos,input);
  else
    dw->AddCurve(input);
  dw->Refresh();

}

//---------------------------------------------------------
void wrap_MainFrameDrawSetCurveProperties(  ParamList* p)
{
    char functionname[] = "mf_DrawSetCurveProperties";
    char description[]=" \n\
      Sets the properties of the displayed curve: color, style, width. \n\
            ";
    char parameters[] =" \n\
      1. curve number (def:0)\n\
      2. color as a string, format is #RRGGBB  \n\
      3. style (def:0 for wxSOLID),\n\
        supported styles are: \n\
        0: wxSOLID   Solid style.\n\
        1: wxDOT   Dotted style.\n\
        2: wxLONG_DASH   Long dashed style.\n\
        3: wxSHORT_DASH  Short dashed style.\n\
        4: wxDOT_DASH  Dot and dash style. \n\
      4. width (def:1)\n\
            ";
  int curve_number       = 0;
  std::string* color_str = NULL;
  int style              = wxSOLID;
  int width              = 1;
  int n                  = 0;

  if (!get_int_param(    curve_number, p, n)) HelpAndReturn;
  if (!get_val_ptr_param<string>( color_str,    p, n)) HelpAndReturn;
  if (!get_int_param(    style,        p, n)) HelpAndReturn;
  if (!get_int_param(    width,        p, n)) HelpAndReturn;

  GB_main_wxFrame->GetDrawingWindow()->SetCurveColor(curve_number,*color_str);
  GB_main_wxFrame->GetDrawingWindow()->SetCurveStyle(curve_number,style);
  GB_main_wxFrame->GetDrawingWindow()->SetCurveWidth(curve_number,width);
}
