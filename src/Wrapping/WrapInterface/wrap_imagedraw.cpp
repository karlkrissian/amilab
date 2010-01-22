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
#include "DessinImage.hpp"

extern VarContexts  Vars;


void AddWrapImageDraw( const DessinImage::ptr& imdraw, const std::string& objname)
{
  // Create new instance of the class
  AMIObject* amiobject = new AMIObject;
  amiobject->SetName(objname.c_str());

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  Vars.AddVar(  type_class_procedure, "DrawLine",  
                (void*)  new wrap_ImageDrawDrawLine(imdraw),  OBJECT_CONTEXT_NUMBER);

  Vars.AddVar(  type_class_procedure, "DisplayDA",  
                (void*)  new wrap_ImageDrawDisplayDA(imdraw), OBJECT_CONTEXT_NUMBER);

  Vars.AddVar(  type_class_procedure, "LineParam",  
                (void*)  new wrap_ImageDrawLineParam(imdraw), OBJECT_CONTEXT_NUMBER);

  Vars.AddVar(  type_class_procedure, "SetLineColor", 
                (void*)  new wrap_ImageDrawSetLineColor(imdraw), OBJECT_CONTEXT_NUMBER);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Variable* res = Vars.AddVar( type_ami_object, amiobject->GetName().c_str(), (void*) amiobject);
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
      - image drawing window\n\
      - name of new object (def:wrap_idraw)\n\
            ";

  int n=0;
  DessinImage::ptr imdraw;
  std::string* object_name = NULL;

  if (!get_imagedraw_param( imdraw,      p, n)) HelpAndReturn;
  if (!get_string_param(    object_name, p, n)) HelpAndReturn;

  AddWrapImageDraw(imdraw,*object_name);
}



/**
 * set the line parameters on an image drawing window
 * @param p 
 */
void wrap_ImageDrawLineParam::CallProc( ParamList* p)
{
    char functionname[] = "LineParam";
    char description[]=" \n\
      Sets the parameters of the line. \n\
            ";
    char parameters[] =" \n\
      - thickness (def:1): line thickness \n\
      - style (def:0): line style, 0 for SOLID, 1 for DOT \n\
            ";

  int thickness = 1;
  int style = 0;
  int n=0;

  if (!get_int_param( thickness, p, n)) HelpAndReturn;
  if (!get_int_param( style, p, n)) HelpAndReturn;

  int wxstyle;
  switch (style) {
    case 0: wxstyle = wxSOLID; break;
    case 1: wxstyle = wxDOT; break;
    default: wxstyle = wxSOLID;
  }
  this->_imdraw->FixeParametresLigne( thickness, wxstyle, wxCAP_ROUND, wxJOIN_MITER);

}


/**
 * set the line color on an image drawing window
 * @param p 
 */
void wrap_ImageDrawSetLineColor::CallProc( ParamList* p)
{
    char functionname[] = "SetLineColor";
    char description[]=" \n\
      Sets the color of the line. \n\
            ";
    char parameters[] =" \n\
      - red    (0-255) default 10\n\
      - green  (0-255) default 10\n\
      - blue   (0-255) default 10\n\
      - alpha  (0-255) default wxALPHA_OPAQUE \n\
      \n\
            ";

  int red   = 10;
  int green = 10;
  int blue  = 10;
  int alpha = wxALPHA_OPAQUE;
  int n=0;

  if (!get_int_param( red,   p, n)) HelpAndReturn;
  if (!get_int_param( green, p, n)) HelpAndReturn;
  if (!get_int_param( blue,  p, n)) HelpAndReturn;
  if (!get_int_param( alpha, p, n)) HelpAndReturn;

  this->_imdraw->SetPenColor(wxColour((unsigned char)red,
    (unsigned char)green,
    (unsigned char)blue,
    (unsigned char)alpha));
}


/**
 * Draws a line on an image drawing window
 * @param p 
 */
void wrap_ImageDrawDrawLine::CallProc( ParamList* p)
{
    char functionname[] = "DrawLine";
    char description[]=" \n\
      Draws a line on XY plane. \n\
            ";
    char parameters[] =" \n\
      - number x1  \n\
      - number y1  \n\
      - number x2  \n\
      - number y2  \n\
      - number update (def:0): 0 does not update display, 1 updates display\n\
            ";

  float x1 = 0,y1 = 0,x2 = 0,y2 = 0 ;
  int update = 0;
  int n=0;

  if (!get_float_param( x1, p, n)) HelpAndReturn;
  if (!get_float_param( y1, p, n)) HelpAndReturn;
  if (!get_float_param( x2, p, n)) HelpAndReturn;
  if (!get_float_param( y2, p, n)) HelpAndReturn;
  if (!get_int_param(   update, p, n)) HelpAndReturn;

  //imdraw->FixeParametresLigne( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
  this->_imdraw->DrawLineZ(x1,y1,x2,y2);
  //imdraw->AfficheImage( IMAGE_XY);
  if (update) this->_imdraw->DrawingAreaDisplay();

}


/**
 * Updates the display
 * @param p 
 */
void wrap_ImageDrawDisplayDA::CallProc( ParamList* p)
{
    char functionname[] = "DisplayDA";
    char description[]=" \n\
      Updates the display of the Drawing Area\n\
            ";
    char parameters[] =" \n\
            ";

  this->_imdraw->DrawingAreaDisplay();

}
