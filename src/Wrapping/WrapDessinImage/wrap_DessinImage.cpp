/**
 * C++ Interface: wrap_DessinImage
 *
 * Description: wrapping DessinImage
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_DessinImage.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

#include "vtkwrap.h"
#include "FluidProject.h"
#include "Func_ReadCTALine.h"
#include "fonctions.h"

#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define GET_SMTPTR_PARAM(type,varname) \
  boost::shared_ptr<type> varname; \
  if (!get_val_smtptr_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#include "driver.h"
#include "MainFrame.h"

extern yyip::Driver GB_driver;
extern MainFrame* GB_main_wxFrame;

extern void CB_delete_variable( void* var);

extern void CB_ParamWin( void* cd );


//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_DessinImage(  WrapClass_DessinImage::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("DessinImage");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_DessinImage( DessinImage* si)
{
  // Create smart pointer with own deleter
  DessinImage::ptr si_ptr = DessinImage::Create_ptr(si);

  WrapClass_DessinImage::ptr sip(new WrapClass_DessinImage(si_ptr));
  AMIObject::ptr amiobject(AddWrap_DessinImage(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
// Method that adds wrapping of DessinImage
//---------------------------------------------------

void  wrap_DessinImage::SetParametersComments() 
{
  ADDPARAMCOMMENT("Input image.");
  return_comments = "A wrapped DessinImage object.";
}

//---------------------------------------------------
BasicVariable::ptr wrap_DessinImage::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  Variable<InrImage>::ptr varim;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;

  std::string sTitle = (boost::format("%s_draw") % varim->Name().c_str()).str();
  DessinParam::ptr parametres;
  InrImage::ptr image(varim->Pointer());

  if (!image.get()) {
    GB_driver.err_print("wrap_DessinImage constructor empty image.");
    return BasicVariable::ptr();
  }

  DessinImage* oDessinImage = new DessinImage(GB_main_wxFrame,
                                              sTitle,
                                              image,//.get(),
                                              parametres,
                                              400,
                                              400,
                                              CREATE_TOPLEVEL_SHELL);

  BasicVariable::ptr res = CreateVar_DessinImage(oDessinImage);

  // Problem here: we don't dont in which variable the smart pointer will end up, can we manage it with the NewReference method ?
  oDessinImage->SetCloseFunction(
    (void*) CB_delete_variable,
    (void*) res.get());

  return res;
}

//---------------------------------------------------
//  setpos
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_setpos::SetParametersComments() 
{
  ADDPARAMCOMMENT("X pos of the cursor");
  ADDPARAMCOMMENT("Y pos of the cursor");
  ADDPARAMCOMMENT("Z pos of the cursor");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_setpos::CallMember( ParamList* p)
{
  DessinImage::ptr draw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,posX,0);
  GET_PARAM(int,posY,0);
  GET_PARAM(int,posZ,0);

  DessinImageParametres* param;

  param = draw->GetParam();
  param->_pos._x = posX;
  param->_pos._y = posY;
  param->_pos._z = posZ;
  param->CheckPosition( draw->GetDisplayedImage());
  param->_MAJ.MAJCoupes();

  draw->Paint();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  showcursor
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_showcursor::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer 0 or 1");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_showcursor::CallMember( ParamList* p)
{
  DessinImage::ptr draw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,curseur,0);

  DessinImageParametres* param;

  param = draw->GetParam();
  param->_curseur._visible = (int) (curseur>0.5);
  //      param->_MAJ.MAJCoupes();

  draw->Paint();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  update
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_update::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_update::CallMember( ParamList* p)
{
  DessinImage::ptr draw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;

  DessinImageParametres* param;

  param = draw->GetParam();
  param->_MAJ.MAJCoupes();
  draw->Paint();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  compare
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_compare::SetParametersComments() 
{
  ADDPARAMCOMMENT("image to compare");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_compare::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  Variable<InrImage>::ptr varim;
  int n=0;

  if (!p) ClassHelpAndReturn;

  if (!get_var_param<InrImage>(varim,p,n)) {
    n=0;
    CLASS_GET_OBJECT_PARAM(DessinImage,varimd,objimd);
    if (!objimd.get()) ClassHelpAndReturn;

    //DessinImage::ptr di_2(varimd->Pointer());

    if(objimd.get())
      di->CreeCompare2Image(objimd);
    else
    {
      GB_driver.err_print("WrapClass_DessinImage::wrap_compare empty imagedraw.");
      return BasicVariable::ptr();
    }

  } else {
    //var_image parameter.
    // TODO: fix this code ...
/*

    InrImage::ptr image(varim->Pointer());
    std::string sTitle = (boost::format("%s_draw") % varim->Name().c_str()).str();
    DessinParam::ptr parametres;

    if (!image.get()) {
      GB_driver.err_print("WrapClass_DessinImage::wrap_compare empty image.");
      return BasicVariable::ptr();
    }

    DessinImage* oDessinImage = new DessinImage(GB_main_wxFrame,
                                                sTitle,
                                                image,//.get(),
                                                parametres,
                                                400,
                                                400,
                                                CREATE_TOPLEVEL_SHELL);

    DessinImage::ptr di_2 = DessinImage::Create_ptr(oDessinImage);
    DessinImageParametres* param;
    param = di_2->GetParam();
    param->_MAJ.MAJCoupes();
    di_2->Paint();

    di_2->SetCloseFunction(
      (void*) CB_delete_variable,
      (void*) di_2.get());

    di->CreeCompare2Image(di_2);
*/
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCompareDisplacement
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetCompareDisplacement::SetParametersComments() 
{
  ADDPARAMCOMMENT("comparison window");
  ADDPARAMCOMMENT("Vectorial image");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetCompareDisplacement::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;
  CLASS_GET_OBJECT_PARAM(DessinImage,varimd,objimd);
  if (!objimd.get()) ClassHelpAndReturn;

  // TODO: check for SetCompareDisplacement, does it really work?
  di->SetCompareDisplacement(objimd,varim->Pointer());

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCompTransf
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetCompTransf::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetCompTransf::CallMember( ParamList* p)
{
  //TODO
  GB_driver.err_print("SetCompTransf is not available at the moment");
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  setvector
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_setvector::SetParametersComments() 
{
  ADDPARAMCOMMENT("index of the vector field to be drawned (1,2 or 3).");
  ADDPARAMCOMMENT("vector field image.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_setvector::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,number,0);
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;

  InrImage::ptr image(varim->Pointer());

  if (!image.get()) {
    GB_driver.err_print("WrapClass_DessinImage::wrap_setvector empty image.");
    return BasicVariable::ptr();
  }

  //di->LoadVectImage(number,image.get());
  di->LoadVectImage(number,image);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  DrawVector
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_DrawVector::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT("Vector size");
  ADDPARAMCOMMENT("Visible or not (0 or 1)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_DrawVector::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,vectnum,0);
  GET_PARAM(int,draw,0);

  di->SetVectorVisible(vectnum, draw);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  DisplayVectors
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_DisplayVectors::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_DisplayVectors::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  di->CB_AfficheChampVect(di.get(),NULL);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetVectParam
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetVectParam::SetParametersComments() 
{
  ADDPARAMCOMMENT("vector size");
  ADDPARAMCOMMENT("vector spacing");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetVectParam::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(float,size,0);
  GET_PARAM(int,spacing,0);

  di->SetVectParam(size,spacing);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetVectColor
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetVectColor::SetParametersComments() 
{
  ADDPARAMCOMMENT("vector id");
  ADDPARAMCOMMENT("red component (0-255)");
  ADDPARAMCOMMENT("green component (0-255)");
  ADDPARAMCOMMENT("blue component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetVectColor::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,vectid,0);
  GET_PARAM(unsigned char,red,0);
  GET_PARAM(unsigned char,green,0);
  GET_PARAM(unsigned char,blue,0);

  di->SetVectColor( vectid,red,green,blue);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetVectStyle
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetVectStyle::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT("Vector type (Integer)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetVectStyle::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,type,0);

  di->SetVectType( type);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetLineThickness
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetLineThickness::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT("Line thickness (Integer)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetLineThickness::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,lt,0);

  di->SetLineThickness( lt);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetZoom
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetZoom::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT("Lower limit X-coordinate");
  ADDPARAMCOMMENT("Lower limit Y-coordinate");
  ADDPARAMCOMMENT("Lower limit Z-coordinate");
  ADDPARAMCOMMENT("Higher limit X-coordinate");
  ADDPARAMCOMMENT("Higher limit Y-coordinate");
  ADDPARAMCOMMENT("Higher limit Z-coordinate");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetZoom::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,xmin,0);
  GET_PARAM(int,ymin,0);
  GET_PARAM(int,zmin,0);
  GET_PARAM(int,xmax,0);
  GET_PARAM(int,ymax,0);
  GET_PARAM(int,zmax,0);

  di->SetZoom(xmin,ymin,zmin,xmax,ymax,zmax);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetWindowSize
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetWindowSize::SetParametersComments() 
{
  ADDPARAMCOMMENT("width");
  ADDPARAMCOMMENT("height");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetWindowSize::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,width,0);
  GET_PARAM(int,height,0);

  di->SetSize(width,height);
  di->Update();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  drawcircle
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_drawcircle::SetParametersComments() 
{
  ADDPARAMCOMMENT("X-coordinate.");
  ADDPARAMCOMMENT("Y-coordinate.");
  ADDPARAMCOMMENT("Z-coordinate.");
  ADDPARAMCOMMENT("red component (0-255)");
  ADDPARAMCOMMENT("green component (0-255)");
  ADDPARAMCOMMENT("blue component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_drawcircle::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,x,0);
  GET_PARAM(int,y,0);
  GET_PARAM(int,z,0);
  GET_PARAM(unsigned char,red,0);
  GET_PARAM(unsigned char,green,0);
  GET_PARAM(unsigned char,blue,0);

  ClasseCouleur c;

  c.FixeValeur(red,green,blue);
  di->Paint();
  di->DessineCercle(x,y,z,c);
  di->DrawingAreaDisplay();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetColormap
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetColormap::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT("image to use");
  ADDPARAMCOMMENT("Center (Float)");
  ADDPARAMCOMMENT("Extent (Float)");

}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetColormap::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;
  GET_PARAM(float,center,0);
  GET_PARAM(float,extent,0);

  InrImage::ptr image(varim->Pointer());

  if (!image.get()) {
    GB_driver.err_print("WrapClass_DessinImage::SetColormap empty image.");
    return BasicVariable::ptr();
  }

  //di->SetUserColormap(image.get(),center,extent);
  di->SetUserColormap(image,center,extent);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  setGLwin
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_setGLwin::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT("Viewer 3D");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_setGLwin::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  Variable<Viewer3D>::ptr varsurfd;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_var_param<Viewer3D>(varsurfd,p,n)) ClassHelpAndReturn;

  Viewer3D::ptr surfd(varsurfd->Pointer());

  if (!surfd.get()) {
    GB_driver.err_print("WrapClass_DessinImage::setGLwin empty image.");
    return BasicVariable::ptr();
  }

  di->SetGLWindow(surfd);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetIsoContour
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetIsoContour::SetParametersComments() 
{
  //TODO

  /*************************************************************************
   * This method is overloaded:                                            *
   * ^^^^^^^^^^^^^^^^^^^^^^^^^                                             *
   * commande <-- $variable_imagedraw.SetIsoContour(expr,var_image,expr)   *
   * commande <-- $variable_imagedraw.SetIsoContour(var_image,expr)        *
   *************************************************************************/
  ADDPARAMCOMMENT("isocontour index (0,1 or 2)");
  ADDPARAMCOMMENT("image to use for the isocontour");
  ADDPARAMCOMMENT("intensity value of the isocontour");

}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetIsoContour::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  Variable<InrImage>::ptr varim;
  int n=0;
  int num;

  if (!p) ClassHelpAndReturn;

  /**
   * This method is overloaded:
   *    - SetIsoContour(num, var_image, seuil)
   *    - SetIsoContour(var_image, seuil)
   * The num parametre is optional.
   */

  n=0;
  if(get_val_param<int>(num,p,n))
  {
    // Case: Three parametres.
    if (!get_var_param<InrImage>(varim,p,n))  ClassHelpAndReturn;
    GET_PARAM(float,seuil,0);
    InrImage::ptr image(varim->Pointer());

    if (!image.get()) {
      GB_driver.err_print("WrapClass_DessinImage::SetIsoContour empty image.");
      return BasicVariable::ptr();
    }

    di->InitIsoContour(image,seuil,num);
    di->DrawIsoContour(num,true);
  }
  else  // Case: Two parametres.
  {
    n=0;
    if (!get_var_param<InrImage>(varim,p,n))  ClassHelpAndReturn;
    GET_PARAM(float,seuil,0);
    InrImage::ptr image(varim->Pointer());

    if (!image.get()) {
      GB_driver.err_print("WrapClass_DessinImage::SetIsoContour empty image.");
      return BasicVariable::ptr();
    }

    di->InitIsoContour(image,seuil,0);
    di->DrawIsoContour(0,true);
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetIsoContourParam
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetIsoContourParam::SetParametersComments() 
{
  //TODO
  /*************************************************************************
   * This method is overloaded:                                            *
   * ^^^^^^^^^^^^^^^^^^^^^^^^^                                             *
   * commande <-- $variable_imagedraw.SetIsoContourParam(expr,expr,expr)   *
   * commande <-- $variable_imagedraw.SetIsoContourParam(expr,expr,expr,   *
   *                                                     expr,expr)        *
   *************************************************************************/
  ADDPARAMCOMMENT("isocontour index (0,1 or 2) def:0");
  ADDPARAMCOMMENT("isocontour thickness def:1");
  ADDPARAMCOMMENT("isocontour style: 0,1,2 for LineSolid, LineOnOffDash, or LineDoubleDash (def:0)");
  ADDPARAMCOMMENT("cap_style: 0:CapNotLast, 1:CapButt, 2:CapRound, or 3:CapProjecting (def:0)");
  ADDPARAMCOMMENT("join_style: 0:JoinMiter, 1:JoinRound, or 2:JoinBevel (def:0)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetIsoContourParam::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  GET_PARAM(int,num,       0);
  GET_PARAM(int,thickness, 1);
  GET_PARAM(int,style,     0);
  GET_PARAM(int,capstyle,  0);
  GET_PARAM(int,joinstyle, 0);

  /**
   * This method is overloaded:
   *    - SetIsoContourParam(num, thickness, style)
   *    - SetIsoContourParam(num, thickness, style, capstyle, joinstyle)
   * The last parameters are optional.
   */

  di->SetIsoContourParam(num, thickness, style);
  di->SetLineAttributes(capstyle, joinstyle);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  DrawIsoContour
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_DrawIsoContour::SetParametersComments() 
{
  ADDPARAMCOMMENT("isocontour index (0,1 or 2)");
  ADDPARAMCOMMENT("visible or not (0 or 1)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_DrawIsoContour::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  GET_PARAM(int,num,0);
  GET_PARAM(int,val,0);

  di->DrawIsoContour(num, val);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetIsoContourColor
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetIsoContourColor::SetParametersComments() 
{
  ADDPARAMCOMMENT("isocontour index (0,1 or 2)");
  ADDPARAMCOMMENT("Red component in [0,255]");
  ADDPARAMCOMMENT("Green component in [0,255]");
  ADDPARAMCOMMENT("Blue component in [0,255]");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetIsoContourColor::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  GET_PARAM(int,num,0);
  GET_PARAM(unsigned char,r,0);
  GET_PARAM(unsigned char,g,0);
  GET_PARAM(unsigned char,b,0);

  di->SetIsoContourColor(num, r, g, b);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  DrawAllContours
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_DrawAllContours::SetParametersComments() 
{
  ADDPARAMCOMMENT("boolean parameter");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_DrawAllContours::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  GET_PARAM(unsigned char,draw,0);

  di->SetDrawAllContours(draw);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  AllContoursParam
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_AllContoursParam::SetParametersComments() 
{
  ADDPARAMCOMMENT("intensity step between isocontours");
  ADDPARAMCOMMENT("half size of the intensity range where to draw isocontours");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_AllContoursParam::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  GET_PARAM(float,step,0);
  GET_PARAM(float,bandwidth,0);

  di->AllContoursParam(step,bandwidth);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  PaintCallback
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_PaintCallback::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT("Callback function (AMIFunction)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_PaintCallback::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  Variable<AMIFunction>::ptr varfunc;
  int n=0;

  if (!p) ClassHelpAndReturn;

  if (!get_var_param<AMIFunction>(varfunc,p,n))  ClassHelpAndReturn;

  AMIFunction::ptr func(varfunc->Pointer());

  di->SetPaintCallback( (void*) CB_ParamWin,
                        (void*) func.get() );

  // may be a pb to call Paint() here since it will start another interpreter ??? to check
  //di->Paint();

  //void  SetPaintCallback (void *paint_cb, void *paint_cb_data)

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetOpacityImage
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetOpacityImage::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT("Image to use");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetOpacityImage::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;

  InrImage::ptr image(varim->Pointer());

  if (!image.get()) {
    GB_driver.err_print("WrapClass_DessinImage::SetOpacityImage empty image.");
    return BasicVariable::ptr();
  }

  di->SetVolRenOpacity(image.get());

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetXmin
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_GetXmin::SetParametersComments() 
{
  //TODO
  return_comments = "The minimum dimension of the coordinate X";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_GetXmin::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  DessinImageParametres* param;
  param = di->GetParam();
  float val=param->_Zoom._xmin;

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  GetXmax
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_GetXmax::SetParametersComments() 
{
  //TODO
  return_comments = "The maximum dimension of the coordinate X";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_GetXmax::CallMember( ParamList* p)
{
  //TODO
  DessinImage::ptr di(this->_objectptr->_obj);

  DessinImageParametres* param;
  param = di->GetParam();
  float val=param->_Zoom._xmax;

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  GetYmin
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_GetYmin::SetParametersComments() 
{
  //TODO
  return_comments = "The minimum dimension of the coordinate Y";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_GetYmin::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  DessinImageParametres* param;
  param = di->GetParam();
  float val=param->_Zoom._ymin;

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  GetYmax
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_GetYmax::SetParametersComments() 
{
  //TODO
  return_comments = "The maximum dimension of the coordinate Y";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_GetYmax::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  DessinImageParametres* param;
  param = di->GetParam();
  float val=param->_Zoom._ymax;

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  GetZmin
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_GetZmin::SetParametersComments() 
{
  //TODO
  return_comments = "The minimum dimension of the coordinate Z";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_GetZmin::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  DessinImageParametres* param;
  param = di->GetParam();
  float val=param->_Zoom._zmin;

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  GetZmax
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_GetZmax::SetParametersComments() 
{
  //TODO
  return_comments = "The maximum dimension of the coordinate Z";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_GetZmax::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  DessinImageParametres* param;
  param = di->GetParam();
  float val=param->_Zoom._zmax;

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  GetXPos
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_GetXPos::SetParametersComments() 
{
  //TODO
  return_comments = "The position of the coordinate X";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_GetXPos::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  DessinImageParametres* param;
  param = di->GetParam();
  float val=param->_pos._x;
  string comment;
  comment = str(format(" //  xpos=%3d") % param->_pos._x);
  if(GB_driver.InConsole())
    GB_main_wxFrame->GetConsole()
                    ->IncCommand(wxString::FromAscii(comment.c_str()));

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  GetYPos
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_GetYPos::SetParametersComments() 
{
  //TODO
  return_comments = "The position of the coordinate Y";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_GetYPos::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  DessinImageParametres* param;
  param = di->GetParam();
  float val=param->_pos._y;
  string comment;
  comment = str( format(" //  ypos=%3d") % param->_pos._y);
  if(GB_driver.InConsole())
    GB_main_wxFrame->GetConsole()
                    ->IncCommand(wxString::FromAscii(comment.c_str()));

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  GetZPos
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_GetZPos::SetParametersComments() 
{
  //TODO
  return_comments = "The position of the coordinate Z";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_GetZPos::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  DessinImageParametres* param;
  param = di->GetParam();
  float val=param->_pos._z;
  string comment;
  comment = str( format(" //  zpos=%3d") % param->_pos._z);
  if(GB_driver.InConsole())
    GB_main_wxFrame->GetConsole()
                    ->IncCommand(wxString::FromAscii(comment.c_str()));

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  getimage
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_getimage::SetParametersComments() 
{
  //TODO
  return_comments = "A snapshot as a 2D image of format RGB";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_getimage::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  return Variable<InrImage>::ptr( 
    new Variable<InrImage>(InrImage::ptr(di->GetInrImage()))
  );
}
