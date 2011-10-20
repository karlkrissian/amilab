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

#include "MainFrame.h"
#include "CallBackAMIFunction.h"

#include "DriverBase.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT DriverBase::ptr  GB_DriverBase;

#include "AMILabConfigure.h"
AMILab_VAR_IMPORT MainFrame*  GB_main_wxFrame;

extern void CB_delete_variable( void* var);
extern void CB_delete_varlist( void* var);

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<DessinImage>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_DessinImage::wrap_DessinImage construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(DessinImage);

//
// static member for creating a variable from a pointer to DessinImage
//
Variable<AMIObject>::ptr WrapClass_DessinImage::CreateVar( DessinImage* sp)
{
  DessinImage::ptr di_ptr = DessinImage::Create_ptr(sp);
  Variable<AMIObject>::ptr res = 
    WrapClass<DessinImage>::CreateVar(
      // Create smart pointer with own deleter
      new WrapClass_DessinImage(di_ptr)
    );
  return res;
}


//---------------------------------------------------
// Method that adds wrapping of DessinImage
//---------------------------------------------------

void WrapClass_DessinImage::
      wrap_DessinImage::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(InrImage,"Input image.");
  return_comments = "A wrapped DessinImage object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_DessinImage::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  Variable<InrImage>::ptr varim;
  int n=0;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;

  std::string sTitle = (boost::format("%s_draw") % varim->Name().c_str()).str();
  DessinParam::ptr parametres;
  InrImage::ptr image(varim->Pointer());

  if (!image.get()) {
    GB_DriverBase->err_print("wrap_DessinImage constructor empty image.");
    return BasicVariable::ptr();
  }

  DessinImage* oDessinImage = new DessinImage(GB_main_wxFrame,
                                              sTitle,
                                              image,//.get(),
                                              parametres,
                                              400,
                                              400,
                                              CREATE_TOPLEVEL_SHELL);

  BasicVariable::ptr res = WrapClass_DessinImage::CreateVar(oDessinImage);

  // Create a list of weak pointers to the variables that are refering to the drawing window
  std::list<BasicVariable::wptr>* refvarlist = new std::list<BasicVariable::wptr>;
  refvarlist->push_back(BasicVariable::wptr(res));

  // Problem here: we don't dont in which variable the smart pointer will end up, can we manage it with the NewReference method ?
  oDessinImage->SetCloseFunction(
    (void*) CB_delete_varlist,
    (void*) refvarlist);

  return res;
}

//---------------------------------------------------
//  reference
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap___reference__::SetParametersComments() 
{
  ADDPARAMCOMMENT("New reference variable as parameter for processing.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap___reference__::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);
  if (p) {
    BasicVariable::ptr var = p->GetParam(0);
    if (var.get() && di.get()) {
      std::list<BasicVariable::wptr>* varlist =
        static_cast<std::list<BasicVariable::wptr>*>(di->GetCloseData());
      if (varlist)
        varlist->push_back(BasicVariable::wptr(var));
    }
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  setpos
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_setpos::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"X pos of the cursor");
  ADDPARAMCOMMENT_TYPE(int,"Y pos of the cursor");
  ADDPARAMCOMMENT_TYPE(int,"Z pos of the cursor");
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
  ADDPARAMCOMMENT_TYPE(int," 0 or 1: Shows/Hides the cursor.");
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
//  int n=0;

  DessinImageParametres* param;

  param = draw->GetParam();
  param->_MAJ.MAJCoupes();
  draw->Paint();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Paint
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_Paint::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_Paint::CallMember( ParamList* p)
{
  DessinImage::ptr draw(this->_objectptr->_obj);
  draw->Paint();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  compare
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_compare::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(DessinImage,"Image viewer to compare to.");
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
      GB_DriverBase->err_print("WrapClass_DessinImage::wrap_compare empty imagedraw.");
      return BasicVariable::ptr();
    }

  } else {
    //var_image parameter.
    // TODO: fix this code ...
    // Call constructor from DessinImage constructor function
    std::string title = (boost::format("%s_draw") % varim->Name()).str();
    ParamList* p = new ParamList();
    p->AddParam(varim);
    BasicVariable::ptr newvar = wrap_DessinImage().CallMember(p);
    FILE_MESSAGE((boost::format("SHOW var_image creating title %s ") % title).str().c_str());
    // TODO: change the way amilab deals with the parameters to avoid creating new variables from the start
    Variables::ptr context = varim->GetContext();
    if ( newvar.get() && context.get()) {
      newvar->Rename(title.c_str());
      context->AddVar(newvar, context);
    } else {
      GB_DriverBase->err_print("Failed to create image viewer.");
      return BasicVariable::ptr();
    }

    GET_WRAPPED_OBJECT(DessinImage,newvar,di_2);
    if (di_2.get())
      di->CreeCompare2Image(di_2);
    return newvar;
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCompareDisplacement
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetCompareDisplacement::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(DessinImage,"comparison window");
  ADDPARAMCOMMENT_TYPE(InrImage,"Vectorial image");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetCompareDisplacement::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(DessinImage,varimd,objimd);
  if (!objimd.get()) ClassHelpAndReturn;
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;

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
  GB_DriverBase->err_print("SetCompTransf is not available at the moment");
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  setvector
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_setvector::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"index of the vector field to be drawned (in the interval [0,2].");
  ADDPARAMCOMMENT_TYPE(InrImage,"vector field image.");
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
    GB_DriverBase->err_print("WrapClass_DessinImage::wrap_setvector empty image.");
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
  ADDPARAMCOMMENT_TYPE(int,"Index of the vector field to be drawned (0,1 or 2).");
  ADDPARAMCOMMENT_TYPE(int,"Visible or not (0 or 1)");
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
//  SetDisplayVectors
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetDisplayVectors::SetParametersComments() 
{ 
  
  ADDPARAMCOMMENT_TYPE(unsigned char,"Enable/Disable the display of the vectors (default: 1 or enable).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetDisplayVectors::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(unsigned char,display,1);
  *di->Get_display_vectors() = display;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetVectParam
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetVectParam::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(float,"vector size");
  ADDPARAMCOMMENT_TYPE(int,"vector spacing");
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
  ADDPARAMCOMMENT_TYPE(int,"vector id");
  ADDPARAMCOMMENT_TYPE(unsigned char,"red component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"green component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"blue component (0-255)");
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
  ADDPARAMCOMMENT_TYPE(int,"Vector type (Integer)");
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
  ADDPARAMCOMMENT_TYPE(int,"Line thickness (Integer)");
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
  ADDPARAMCOMMENT_TYPE(int,"Lower limit X-coordinate");
  ADDPARAMCOMMENT_TYPE(int,"Lower limit Y-coordinate");
  ADDPARAMCOMMENT_TYPE(int,"Lower limit Z-coordinate");
  ADDPARAMCOMMENT_TYPE(int,"Higher limit X-coordinate");
  ADDPARAMCOMMENT_TYPE(int,"Higher limit Y-coordinate");
  ADDPARAMCOMMENT_TYPE(int,"Higher limit Z-coordinate");
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
  ADDPARAMCOMMENT_TYPE(int,"width");
  ADDPARAMCOMMENT_TYPE(int,"height");
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
  ADDPARAMCOMMENT_TYPE(int,"X-coordinate.");
  ADDPARAMCOMMENT_TYPE(int,"Y-coordinate.");
  ADDPARAMCOMMENT_TYPE(int,"Z-coordinate.");
  ADDPARAMCOMMENT_TYPE(unsigned char,"red component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"green component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"blue component (0-255)");
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
//  DrawCircleR - MicronTracker utility
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_DrawCircleR::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"X-coordinate.");
  ADDPARAMCOMMENT_TYPE(int,"Y-coordinate.");
  ADDPARAMCOMMENT_TYPE(int,"Radius.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_DrawCircleR::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);
  int x = 0,y = 0,r = 0 ;
  int n=0;
  if (!p) ClassHelpAndReturn;
  if (!get_val_param<int>( x, p, n)) ClassHelpAndReturn;
  if (!get_val_param<int>( y, p, n)) ClassHelpAndReturn;
  if (!get_val_param<int>( r, p, n)) ClassHelpAndReturn;
  
  di->DrawCircleR(x,y,r);
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  SetUserColormap
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetUserColormap::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(InrImage,"image to use");
  ADDPARAMCOMMENT_TYPE(float,"Center (Float)");
  ADDPARAMCOMMENT_TYPE(float,"Extent (Float)");

}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetUserColormap::CallMember( ParamList* p)
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
    GB_DriverBase->err_print("WrapClass_DessinImage::SetColormap empty image.");
    return BasicVariable::ptr();
  }

  //di->SetUserColormap(image.get(),center,extent);
  di->SetUserColormap(image,center,extent);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  UpdateColormap
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_UpdateColormap::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_UpdateColormap::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);
  di->UpdateColormap();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  setGLwin
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_setGLwin::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(Viewer3D,"Viewer 3D");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_setGLwin::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(Viewer3D, varsurfd, surfd);
  if (!surfd.get()) ClassHelpAndReturn;

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
  ADDPARAMCOMMENT_TYPE(int,"isocontour index (0,1 or 2)");
  ADDPARAMCOMMENT_TYPE(InrImage,"image to use for the isocontour");
  ADDPARAMCOMMENT_TYPE(float,"intensity value of the isocontour");
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
      GB_DriverBase->err_print("WrapClass_DessinImage::SetIsoContour empty image.");
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
      GB_DriverBase->err_print("WrapClass_DessinImage::SetIsoContour empty image.");
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
  ADDPARAMCOMMENT_TYPE(int,"isocontour index (0,1 or 2) def:0");
  ADDPARAMCOMMENT_TYPE(int,"isocontour thickness def:1");
  ADDPARAMCOMMENT_TYPE(int,"isocontour style: 0,1,2 for LineSolid, LineOnOffDash, or LineDoubleDash (def:0)");
  ADDPARAMCOMMENT_TYPE(int,"cap_style: 0:CapNotLast, 1:CapButt, 2:CapRound, or 3:CapProjecting (def:0)");
  ADDPARAMCOMMENT_TYPE(int,"join_style: 0:JoinMiter, 1:JoinRound, or 2:JoinBevel (def:0)");
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
  ADDPARAMCOMMENT_TYPE(int,"isocontour index (0,1 or 2)");
  ADDPARAMCOMMENT_TYPE(int,"visible or not (0 or 1)");
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
  ADDPARAMCOMMENT_TYPE(int,"isocontour index (0,1 or 2)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"red component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"green component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"blue component (0-255)");
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
  ADDPARAMCOMMENT_TYPE(unsigned char,"boolean parameter");
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
  ADDPARAMCOMMENT_TYPE(float,"intensity step between isocontours");
  ADDPARAMCOMMENT_TYPE(float,"half size of the intensity range where to draw isocontours");
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
  ADDPARAMCOMMENT_TYPE(AMIFunction,"Callback function (AMIFunction)");
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

  CallBackAMIFunction::ptr cb(new CallBackAMIFunction(func));
  di->SetPaintCallback( cb );

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
  ADDPARAMCOMMENT_TYPE(InrImage,"Image to use");
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
    GB_DriverBase->err_print("WrapClass_DessinImage::SetOpacityImage empty image.");
    return BasicVariable::ptr();
  }

  di->SetVolRenOpacity(image);

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
  std::string comment;
  comment = str(format(" //  xpos=%3d") % param->_pos._x);
  if(GB_DriverBase->InConsole())
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
  std::string comment;
  comment = str( format(" //  ypos=%3d") % param->_pos._y);
  if(GB_DriverBase->InConsole())
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
  std::string comment;
  comment = str( format(" //  zpos=%3d") % param->_pos._z);
  if(GB_DriverBase->InConsole())
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

//---------------------------------------------------
//  DrawLineZ
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_DrawLineZ::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(float, "number x1.");
  ADDPARAMCOMMENT_TYPE(float, "number y1.");
  ADDPARAMCOMMENT_TYPE(float, "number x2.");
  ADDPARAMCOMMENT_TYPE(float, "number y2.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_DrawLineZ::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->GetObj());
  float x1 = 0,y1 = 0,x2 = 0,y2 = 0 ;
  int n=0;

  if (!get_val_param<float>( x1, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( y1, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( x2, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( y2, p, n)) ClassHelpAndReturn;

  di->DrawLineZ(x1,y1,x2,y2);
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  SetIntensityRange
//---------------------------------------------------
void WrapClass_DessinImage::
      wrap_SetIntensityRange::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(float, "minimal intensity for LUT.");
  ADDPARAMCOMMENT_TYPE(float, "maximal intensity for LUT.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_DessinImage::
      wrap_SetIntensityRange::CallMember( ParamList* p)
{
  DessinImage::ptr di(this->_objectptr->GetObj());
  int n=0;
  GET_PARAM(float,Imin,0)
  GET_PARAM(float,Imax,255)

  di->SetIntensityRange(Imin,Imax);
  return BasicVariable::ptr();
}


