//
// C++ Implementation: wrap_DessinImage
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
//#include "wrapfunctions_draw.h"
#include "wrap_imagedraw.h"
#include "ami_class.h"
#include "ami_object.h"
#include "DessinImage.hpp"

extern VarContexts  Vars;


void AddWrapImageDraw( const DessinImage::ptr& objectptr, const std::string& objname)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName(objname.c_str());

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  ADDMEMBER("DrawLine",       DessinImage,DrawLine);
  ADDMEMBER("DisplayDA",      DessinImage,DisplayDA);
  ADDMEMBER("LineParam",      DessinImage,LineParam);
  ADDMEMBER("SetLineColor",   DessinImage,SetLineColor);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.AddVar<AMIObject>(amiobject->GetName().c_str(), amiobject);
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

  if (!get_val_smtptr_param<DessinImage>( imdraw,      p, n)) HelpAndReturn;
  if (!get_val_ptr_param<string>(    object_name, p, n)) HelpAndReturn;

  AddWrapImageDraw(imdraw,*object_name);
}


//---------------------------------------------------------
// LineParam
//---------------------------------------------------------
void wrap_DessinImageLineParam::SetParametersComments()
{
  ADDPARAMCOMMENT( "thickness (def:1): line thickness.");
  ADDPARAMCOMMENT( "style (def:0): line style, 0 for SOLID, 1 for DOT.");
}
//---------------------------------------------------------
BasicVariable::ptr wrap_DessinImageLineParam::CallMember( ParamList* p)
{
  int thickness = 1;
  int style = 0;
  int n=0;

  if (!get_int_param( thickness, p, n)) ClassHelpAndReturn;
  if (!get_int_param( style, p, n))     ClassHelpAndReturn;

  int wxstyle;
  switch (style) {
    case 0: wxstyle = wxSOLID; break;
    case 1: wxstyle = wxDOT; break;
    default: wxstyle = wxSOLID;
  }
  this->_objectptr->FixeParametresLigne( thickness, wxstyle, wxCAP_ROUND, wxJOIN_MITER);
  return BasicVariable::ptr();

}


//---------------------------------------------------------
//  SetLineColor
//---------------------------------------------------------
void wrap_DessinImageSetLineColor::SetParametersComments()
{
  ADDPARAMCOMMENT( "red    (0-255) default 10.");
  ADDPARAMCOMMENT( "green  (0-255) default 10.");
  ADDPARAMCOMMENT( "blue   (0-255) default 10.");
  ADDPARAMCOMMENT( "alpha  (0-255) default 10.");
}
//---------------------------------------------------------
BasicVariable::ptr wrap_DessinImageSetLineColor::CallMember( ParamList* p)
{
  int red   = 10;
  int green = 10;
  int blue  = 10;
  int alpha = wxALPHA_OPAQUE;
  int n=0;

  if (!get_int_param( red,   p, n)) ClassHelpAndReturn;
  if (!get_int_param( green, p, n)) ClassHelpAndReturn;
  if (!get_int_param( blue,  p, n)) ClassHelpAndReturn;
  if (!get_int_param( alpha, p, n)) ClassHelpAndReturn;

  this->_objectptr->SetPenColor(wxColour((unsigned char)red,
    (unsigned char)green,
    (unsigned char)blue,
    (unsigned char)alpha));
  return BasicVariable::ptr();
}


//---------------------------------------------------------
//  DrawLine
//---------------------------------------------------------
void wrap_DessinImageDrawLine::SetParametersComments()
{
  ADDPARAMCOMMENT( "number x1.");
  ADDPARAMCOMMENT( "number y1.");
  ADDPARAMCOMMENT( "number x2.");
  ADDPARAMCOMMENT( "number y2.");
  ADDPARAMCOMMENT( "number update (def:0): 0 does not update display, 1 updates display");
}
//---------------------------------------------------------
BasicVariable::ptr wrap_DessinImageDrawLine::CallMember( ParamList* p)
{
  float x1 = 0,y1 = 0,x2 = 0,y2 = 0 ;
  int update = 0;
  int n=0;

  if (!get_val_param<float>( x1, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( y1, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( x2, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( y2, p, n)) ClassHelpAndReturn;
  if (!get_int_param(   update, p, n))  ClassHelpAndReturn;

  //imdraw->FixeParametresLigne( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);
  this->_objectptr->DrawLineZ(x1,y1,x2,y2);
  //imdraw->AfficheImage( IMAGE_XY);
  if (update) this->_objectptr->DrawingAreaDisplay();
  return BasicVariable::ptr();

}


//---------------------------------------------------------
//  DisplayDA
//---------------------------------------------------------
void wrap_DessinImageDisplayDA::SetParametersComments() {}
//---------------------------------------------------------
BasicVariable::ptr wrap_DessinImageDisplayDA::CallMember( ParamList* p)
{
  this->_objectptr->DrawingAreaDisplay();
  return BasicVariable::ptr();
}
