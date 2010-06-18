/**
 * C++ Interface: wrap_Viewer3D
 *
 * Description: wrapping Viewer3D
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_Viewer3D.h"

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
#include "CallBackAMIFunction.h"

extern yyip::Driver GB_driver;
extern MainFrame* GB_main_wxFrame;
extern wxApp* GB_wxApp;

extern void CB_delete_variable( void* var);
extern void CB_delete_varlist( void* var);


//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_Viewer3D(  WrapClass_Viewer3D::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("Viewer3D");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_Viewer3D( Viewer3D* si)
{
  // Create smart pointer with own deleter
  Viewer3D::ptr si_ptr = Viewer3D::Create_ptr(si);

  WrapClass_Viewer3D::ptr sip(new WrapClass_Viewer3D(si_ptr));
  AMIObject::ptr amiobject(AddWrap_Viewer3D(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
// Method that adds wrapping of Viewer3D
//---------------------------------------------------

void  wrap_Viewer3D::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"Title of viewer.");
  return_comments = "A wrapped Viewer3D object.";
}

//---------------------------------------------------
BasicVariable::ptr wrap_Viewer3D::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  //if (!get_var_param<string>(sTitle,p,n)) ClassHelpAndReturn;
  GET_PARAM(string,sTitle,"");

  Viewer3D* oViewer3D = new Viewer3D(GB_main_wxFrame, sTitle);

  BasicVariable::ptr res = CreateVar_Viewer3D(oViewer3D);

  // Create a list of weak pointers to the variables that are refering to the drawing window
  std::list<BasicVariable::wptr>* refvarlist = new std::list<BasicVariable::wptr>;
  refvarlist->push_back(BasicVariable::wptr(res));

  // Problem here: we don't dont in which variable the smart pointer will end up, can we manage it with the NewReference method ?
  oViewer3D->SetCloseFunction(
    (void*) CB_delete_varlist,
    (void*) refvarlist);

  return res;
}

//---------------------------------------------------
//  reference
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_reference::SetParametersComments() 
{
  ADDPARAMCOMMENT("New reference variable as parameter for processing.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_reference::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);
  if (p) {
    BasicVariable::ptr var = p->GetParam(0);
    if (var.get() && sdraw.get()) {
      std::list<BasicVariable::wptr>* varlist =
        static_cast<std::list<BasicVariable::wptr>*>(sdraw->GetCloseData());
      if (varlist)
        varlist->push_back(BasicVariable::wptr(var));
    }
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  rotate
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_rotate::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(float,"rotation around X axis in degrees");
  ADDPARAMCOMMENT_TYPE(float,"rotation around Y axis in degrees");
  ADDPARAMCOMMENT_TYPE(float,"rotation around Z axis in degrees");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_rotate::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(float,rotateX,0);
  GET_PARAM(float,rotateY,0);
  GET_PARAM(float,rotateZ,0);

  sdraw->GetCanvas()->UserRotate(rotateX,rotateY,rotateZ);
  sdraw->Paint();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  AddObject
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_AddObject::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(AMIObject,"A wrapped SurfacePoly object.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_AddObject::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(SurfacePoly,varsurf,surf);
  if (!surf.get()) ClassHelpAndReturn;

  if (surf.get())
  {
    sdraw->GetCanvas()->AddSurface(surf);
    sdraw->Paint();
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  add_assign
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_add_assign::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(AMIObject,"A wrapped SurfacePoly object.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_add_assign::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(SurfacePoly,varsurf,surf);
  if (!surf.get()) ClassHelpAndReturn;

  if (surf.get())
    sdraw->GetCanvas()->AddSurface(surf);

  //sdraw->Paint();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  subtraction_assign
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_subtraction_assign::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(AMIObject,"A wrapped SurfacePoly object.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_subtraction_assign::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(SurfacePoly,varsurf,surf);
  if (!surf.get()) ClassHelpAndReturn;

  if (surf.get())
  {
    sdraw->GetCanvas()->RemoveSurface(surf);
    sdraw->Paint();
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Remove
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_Remove::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(AMIObject,"A wrapped SurfacePoly object.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_Remove::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(SurfacePoly,varsurf,surf);
  if (!surf.get()) ClassHelpAndReturn;

  /**
    Description: Removes the surface without swapping the 3D buffer
  **/
  if (surf.get())
  {
    sdraw->GetCanvas()->RemoveSurface(surf);
    sdraw->Paint(false);
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SwapBuffers
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_SwapBuffers::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_SwapBuffers::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  /**
    Description:  Swaps the 3D buffer
  **/
  sdraw->GetCanvas()->AfficheBuffer();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  drawCCOnlyCC
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_drawCCOnlyCC::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int,"The specified connected component. If -1 draws all connected components, otherwise only draws the one selected.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_drawCCOnlyCC::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  GET_PARAM(int,cc,0);

  sdraw->GetCanvas()->DessineSurfaceCC ( cc );
  sdraw->Paint();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  drawCC
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_drawCC::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int,"The specified connected component. If -1 draws all connected components, otherwise only draws the one selected.");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Choose if drawing a particular connected component.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_drawCC::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  GET_PARAM(int,cc,0);
  GET_PARAM(unsigned char,draw, 0);

  sdraw->GetCanvas()->DessineSurfaceCC ( cc, draw );
  sdraw->Paint();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCurrentObj
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_SetCurrentObj::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int,"Index of the object.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_SetCurrentObj::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  GET_PARAM(int,i,0);

  if ( sdraw->GetCanvas()->SetCurrentObject( i ) )
    sdraw->Paint();
  else
    GB_driver.err_print("WrapClass_Viewer3D::wrap_SetCurrentObj Incorrect index.\n");

//    fprintf(stderr," Incorrect index \n");

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  compare
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_compare::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(Viewer3D,"Viewer to compare to.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_compare::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  CLASS_GET_OBJECT_PARAM(Viewer3D,varViewer3D,sdraw2);
  if (!sdraw2.get()) ClassHelpAndReturn;

  if (sdraw2.get())
    sdraw->AddCompSurf(sdraw2);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  setvector
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_setvector::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int,"Number of the vector field (1,2 or 3).");
  ADDPARAMCOMMENT_TYPE(InrImage,"Vector field image");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_setvector::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,number,0);
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;

  InrImage::ptr image(varim->Pointer());

  if (!image.get()) {
    GB_driver.err_print("WrapClass_Viewer3D::wrap_setvector empty image.");
    return BasicVariable::ptr();
  }

  switch (number) {
  case 1:
    sdraw->GetCanvas()->SetVectors1( image);
    break;
  case 2:
    sdraw->GetCanvas()->SetVectors2( image);
    break;
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  ShowSection
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_ShowSection::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int ,"Section number.");
  ADDPARAMCOMMENT_TYPE(InrImage,"Image to use");
  ADDPARAMCOMMENT_TYPE(int,"Orientation (0, 1 or 2)");
  ADDPARAMCOMMENT_TYPE(int,"Position");
  ADDPARAMCOMMENT_TYPE(float,"TODO (Imin)");
  ADDPARAMCOMMENT_TYPE(float,"TODO (Imax)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_ShowSection::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  Variable<InrImage>::ptr varim;

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,number,0);
  if (!get_var_param<InrImage>(varim,p,n)) ClassHelpAndReturn;
  GET_PARAM(int,orientation,0);
  GET_PARAM(int,pos,0);
  GET_PARAM(float,Imin,0);
  GET_PARAM(float,Imax,0);

  InrImage::ptr image(varim->Pointer());

  if (!image.get()) {
    GB_driver.err_print("WrapClass_Viewer3D::wrap_ShowSection empty image.");
    return BasicVariable::ptr();
  }

  sdraw->GetCanvas()->ShowFreeSection(number,
                                      image.get(),
                                      orientation,
                                      pos,
                                      Imin,
                                      Imax);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  HideSection
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_HideSection::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int ,"Section number.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_HideSection::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,number,0);

  sdraw->GetCanvas()->HideFreeSection(number);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  PrintMatrices
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_PrintMatrices::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_PrintMatrices::CallMember( ParamList* p)
{
  Viewer3D::ptr vi(this->_objectptr->_obj);

  vi->GetCanvas()->PrintMatrices();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetTransform
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_SetTransform::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(GLTransfMatrix,"gltransform");
  ADDPARAMCOMMENT_TYPE(float,"Threshold");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_SetTransform::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  /**
   * This method is overloaded:
   *    - SetTransform(gltransform)
   *    - SetTransform(gltransform, Threshold)
   * The Threshold parametre is optional.
   */

  GB_driver.err_print("WrapClass_Viewer3D::wrap_SetTransform Not available at this time!");

/*
        void SetObjectTransform( const GLTransfMatrix& obj_transf);

        | VAR_SURFDRAW T_POINT T_SetTransform T_OP_PAR gltransform T_CL_PAR
        {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }

        | VAR_SURFDRAW T_POINT T_SetTransform T_OP_PAR gltransform T_COMMA expr T_CL_PAR
        {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ($7>0.5) sdraw->Paint();
          delete tr;
        }

*/

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Paint
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_Paint::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_Paint::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  sdraw->Paint();
  sdraw->Update();
  //sdraw->Raise();
  // process all pending events ...
  while (GB_wxApp->Pending()) {
    if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
    GB_wxApp->Dispatch();
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetLightAmbient
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_SetLightAmbient::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int,"light number");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Red Component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Green Component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Blue Component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_SetLightAmbient::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,lightnumber,0);
  GET_PARAM(unsigned char,r,0);
  GET_PARAM(unsigned char,g,0);
  GET_PARAM(unsigned char,b,0);

  if (lightnumber<MAX_LIGHTS) {
    sdraw->GetCanvas()->GetLight(lightnumber)._ambient.FixeValeur(r,g,b);
    sdraw->Paint();
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetLightDiffuse
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_SetLightDiffuse::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int,"light number");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Red Component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Green Component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Blue Component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_SetLightDiffuse::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,lightnumber,0);
  GET_PARAM(unsigned char,r,0);
  GET_PARAM(unsigned char,g,0);
  GET_PARAM(unsigned char,b,0);

  if (lightnumber<MAX_LIGHTS) {
    sdraw->GetCanvas()->GetLight(lightnumber)._diffuse.FixeValeur(r,g,b);
    sdraw->Paint();
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetLightSpecular
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_SetLightSpecular::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int,"light number");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Red Component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Green Component (0-255)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Blue Component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_SetLightSpecular::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,lightnumber,0);
  GET_PARAM(unsigned char,r,0);
  GET_PARAM(unsigned char,g,0);
  GET_PARAM(unsigned char,b,0);

  if (lightnumber<MAX_LIGHTS) {
    sdraw->GetCanvas()->GetLight(lightnumber)._specular.FixeValeur(r,g,b);
    sdraw->Paint();
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetBackground
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_SetBackground::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int,"Red Component (0-255)");
  ADDPARAMCOMMENT_TYPE(int,"Green Component (0-255)");
  ADDPARAMCOMMENT_TYPE(int,"Blue Component (0-255)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_SetBackground::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,r,0);
  GET_PARAM(int,g,0);
  GET_PARAM(int,b,0);

  sdraw->GetCanvas()->SetBG(r,g,b);
  sdraw->Paint();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Normalize
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_Normalize::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_Normalize::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  /**
    Description:
      Normalizes the 3D view based on the limits in space of the current objects
  **/
  sdraw->GetCanvas()->Normalize();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Center
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_Center::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_Center::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  /**
    Description:
      Centers the 3D view based on the limits in space of the current objects
  **/
  sdraw->GetCanvas()->Center();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetWindowSize
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_SetWindowSize::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(int,"width");
  ADDPARAMCOMMENT_TYPE(int,"height");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_SetWindowSize::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,width,0);
  GET_PARAM(int,height,0);

  sdraw->SetSize(width,height);
  sdraw->Paint();
  sdraw->Update();
  // process all pending events ...
  while (GB_wxApp->Pending()) {
    if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
    GB_wxApp->Dispatch();
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  getimage
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_getimage::SetParametersComments() 
{
  //TODO
  return_comments = "A snapshot as a 2D image of format RGB";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_getimage::CallMember( ParamList* p)
{
  Viewer3D::ptr sdraw(this->_objectptr->_obj);

  return Variable<InrImage>::ptr( 
    new Variable<InrImage>(InrImage::ptr(sdraw->GetCanvas()->GetGLImage()))
  );

}

//---------------------------------------------------
//  GetImageFromX
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_GetImageFromX::SetParametersComments() 
{
  //TODO
  return_comments = "A snapshot as a 2D image of format RGB";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_GetImageFromX::CallMember( ParamList* p)
{
  Viewer3D::ptr vi(this->_objectptr->_obj);

  GB_driver.err_print("WrapClass_Viewer3D::wrap_GetImageFromX Not available in new wxwidgets version of the 3D viewer !");

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetTransform
//---------------------------------------------------
void WrapClass_Viewer3D::
      wrap_GetTransform::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_Viewer3D::
      wrap_GetTransform::CallMember( ParamList* p)
{
  Viewer3D::ptr vi(this->_objectptr->_obj);

  GB_driver.err_print("WrapClass_Viewer3D::wrap_GetTransform Not available at this time!");

/*
        |
        VAR_SURFDRAW T_POINT T_GetTransform
        {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix glt;
          GLTransfMatrix* newglt;
  
          printf("GetTransform begin \n");
          newglt = new GLTransfMatrix();
              glt = (varsurfd->Pointer())->GetCanvas()->GetObjectTransform();
          (*newglt) = (glt);
          driver.gltransf_stack.AddMatrix(newglt);
          printf("GetTransform \n");
      }
*/

  return BasicVariable::ptr();
}