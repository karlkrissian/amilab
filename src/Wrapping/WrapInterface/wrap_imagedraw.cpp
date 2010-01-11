//
// C++ Implementation: wrap_imagedraw
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapfunctions_draw.h"
#include "wrap_imagedraw.h"
#include "ami_class.h"
#include "ami_object.h"

extern VarContexts  Vars;


void AddWrapImageDraw()
{
  // Create new instance of the class
  AMIObject* amiobject = new AMIObject;
  amiobject->SetName("wrap_idraw_inst");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  Vars.AddVar(type_c_procedure, "DrawLine",  (void*)  wrap_ImageDrawDrawLine, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure, "DisplayDA",  (void*)  wrap_ImageDrawDisplayDA, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure, "LineParam",  (void*)  wrap_ImageDrawLineParam, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure, "SetLineColor",  (void*)  wrap_ImageDrawSetLineColor, OBJECT_CONTEXT_NUMBER);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.AddVar( type_ami_object, amiobject->GetName().c_str(), (void*) amiobject);
}

/**
 * Adds the ImageDraw wrapping
 * @param p 
 */
void wrap_ImageDraw( ParamList* p)
{
    char functionname[] = "ImageDraw";
    char description[]=" \n\
      Adds wrapping for ImageDraw. \n\
            ";
    char parameters[] =" \n\
            ";

  AddWrapImageDraw();
}


/**
 * set the line parameters on an image drawing window
 * @param p 
 */
void wrap_ImageDrawLineParam( ParamList* p)
{
    char functionname[] = "LineParam";
    char description[]=" \n\
      Sets the parameters of the line. \n\
            ";
    char parameters[] =" \n\
      - image drawing window\n\
      - thickness (def:1): line thickness \n\
      - style (def:0): line style, 0 for SOLID, 1 for DOT \n\
            ";

  DessinImage::ptr imdraw;
  int thickness = 1;
  int style = 0;
  int n=0;

  if (!get_imagedraw_param( imdraw, p, n)) HelpAndReturn;
  if (!get_int_param( thickness, p, n)) HelpAndReturn;
  if (!get_int_param( style, p, n)) HelpAndReturn;

  int wxstyle;
  switch (style) {
    case 0: wxstyle = wxSOLID; break;
    case 1: wxstyle = wxDOT; break;
    default: wxstyle = wxSOLID;
  }
  imdraw->FixeParametresLigne( thickness, wxstyle, wxCAP_ROUND, wxJOIN_MITER);

}


/**
 * set the line color on an image drawing window
 * @param p 
 */
void wrap_ImageDrawSetLineColor( ParamList* p)
{
    char functionname[] = "SetLineColor";
    char description[]=" \n\
      Sets the color of the line. \n\
            ";
    char parameters[] =" \n\
      - image drawing window\n\
      - red    (0-255) default 10\n\
      - green  (0-255) default 10\n\
      - blue   (0-255) default 10\n\
      - alpha  (0-255) default wxALPHA_OPAQUE \n\
      \n\
            ";

  DessinImage::ptr imdraw;
  int red   = 10;
  int green = 10;
  int blue  = 10;
  int alpha = wxALPHA_OPAQUE;
  int n=0;

  if (!get_imagedraw_param( imdraw, p, n)) HelpAndReturn;
  if (!get_int_param( red,   p, n)) HelpAndReturn;
  if (!get_int_param( green, p, n)) HelpAndReturn;
  if (!get_int_param( blue,  p, n)) HelpAndReturn;
  if (!get_int_param( alpha, p, n)) HelpAndReturn;

  imdraw->SetPenColor(wxColour((unsigned char)red,
    (unsigned char)green,
    (unsigned char)blue,
    (unsigned char)alpha));
}


/**
 * Draws a line on an image drawing window
 * @param p 
 */
void wrap_ImageDrawDrawLine( ParamList* p)
{
    char functionname[] = "DrawLine";
    char description[]=" \n\
      Draws a line on XY plane. \n\
            ";
    char parameters[] =" \n\
      - image drawing window\n\
      - number x1  \n\
      - number y1  \n\
      - number x2  \n\
      - number y2  \n\
      - number update (def:0): 0 does not update display, 1 updates display\n\
            ";

  DessinImage::ptr imdraw;
  float x1 = 0,y1 = 0,x2 = 0,y2 = 0 ;
  int update = 0;
  int n=0;


  if (!get_imagedraw_param( imdraw, p, n)) HelpAndReturn;
  if (!get_float_param( x1, p, n)) HelpAndReturn;
  if (!get_float_param( y1, p, n)) HelpAndReturn;
  if (!get_float_param( x2, p, n)) HelpAndReturn;
  if (!get_float_param( y2, p, n)) HelpAndReturn;
  if (!get_int_param(   update, p, n)) HelpAndReturn;

  //imdraw->FixeParametresLigne( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
  imdraw->DrawLineZ(x1,y1,x2,y2);
  //imdraw->AfficheImage( IMAGE_XY);
  if (update) imdraw->DrawingAreaDisplay();

}


/**
 * Updates the display
 * @param p 
 */
void wrap_ImageDrawDisplayDA( ParamList* p)
{
    char functionname[] = "DisplayDA";
    char description[]=" \n\
      Updates the display of the Drawing Area\n\
            ";
    char parameters[] =" \n\
      - image drawing window\n\
            ";

  DessinImage::ptr imdraw;
  int n=0;

  if (!get_imagedraw_param( imdraw, p, n)) HelpAndReturn;
  imdraw->DrawingAreaDisplay();

}
