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

  if (!get_float_param( xmin, p, n)) HelpAndReturn;
  if (!get_float_param( xmax, p, n)) HelpAndReturn;

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

  if (!get_float_param( ymin, p, n)) HelpAndReturn;
  if (!get_float_param( ymax, p, n)) HelpAndReturn;

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
              input image\n\
            ";

  InrImage* input;
  int n=0;

  if (!get_image_param(  input,      p, n)) HelpAndReturn;

  GB_main_wxFrame->GetDrawingWindow()->AddFunction(input);
  GB_main_wxFrame->GetDrawingWindow()->Refresh();

}

