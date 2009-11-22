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
}

void wrap_MainFrameDrawSetLimits( ParamList* p)
{
}

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

