/*
 *  wrapSubPixel2D.cpp
 */




#include "wrapSubPixel2D.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "SubPixel2D.h"
#include "wrap_DessinImage.h"
#include "wrap_wxColour.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<SubPixel2D>::CreateVar( ParamList* p)
{
  WrapClass_SubPixel2D::wrap_SubPixel2D construct;
  return construct.CallMember(p);
}

//---------------------------------------------------
//SubPixel2D Wrapping
//---------------------------------------------------

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(SubPixel2D);
AMI_DEFINE_VARFROMSMTPTR(SubPixel2D);

//---------------------------------------------------
//SubPixel2D Constructor
void WrapClass_SubPixel2D::wrap_SubPixel2D::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage, "The input image.");
  ADDPARAMCOMMENT_TYPE(float, "The intensity threshold.");
  ADDPARAMCOMMENT_TYPE(float, "The low intensity threshold.")
  ADDPARAMCOMMENT_TYPE(int, "First or second order method.");
  return_comments = "A wrapped SubPixel2D object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SubPixel2D::wrap_SubPixel2D::CallMember(ParamList* p)
{
  InrImage* input;
  float threshold;
  float lowThreshold;
  int linear_case;
  int n = 0;
  
  if (!get_val_ptr_param<InrImage>(input, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(threshold, p, n))    ClassHelpAndReturn;
  if (!get_val_param<float>(lowThreshold, p, n)) ClassHelpAndReturn;
  if (!get_val_param<int>(linear_case, p, n))    ClassHelpAndReturn;
  
  return AMILabType<SubPixel2D>::CreateVar(new SubPixel2D(input, threshold, 
                                                          lowThreshold, linear_case));
}

//---------------------------------------------------
//SuperGradienteCurvo
void WrapClass_SubPixel2D::wrap_SuperGradienteCurvo::SetParametersComments()
{
  return_comments = "Returns an AMIObject with parameters inside 1D images.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SubPixel2D::wrap_SuperGradienteCurvo
                                       ::CallMember(ParamList* p)
{
  SubPixel2D::ptr sp(_objectptr->GetObj());
  
  sp->SuperGradienteCurvo();
  
  //Create the AMIObject with the result
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("Sub-pixel2D");
  int size = sp->getBorderPixelVector().size();
  //InrImages for params
  InrImage::ptr AIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "aintensity.inr.gz"));
  InrImage::ptr BIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bintensity.inr.gz"));
  InrImage::ptr border     = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_CHAR,
                                                        "border.inr.gz"));
  InrImage::ptr a          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "acoef.inr.gz"));
  InrImage::ptr b          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bcoef.inr.gz"));
  InrImage::ptr c          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "ccoef.inr.gz"));
  InrImage::ptr curvature  = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "curvature.inr.gz"));
  InrImage::ptr posx       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "xpos.inr.gz"));
  InrImage::ptr posy       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "ypos.inr.gz"));
  
  //Fill InrImages
  sp->fillImages(AIntensity, BIntensity, border, a, b, c, curvature, 
                 posx, posy);
  //Add to amiobject
  amiobject->GetContext()->AddVar<InrImage>("aintensity", AIntensity, 
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bintensity", BIntensity,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("border", border,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("acoef", a,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bcoef", b,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ccoef", c,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("curvature", curvature,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("xpos", posx,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ypos", posy,
                                            amiobject->GetContext());

  Variable<AMIObject>::ptr result(
      new Variable<AMIObject>(amiobject));
  return result;

}

//---------------------------------------------------
//SuperGradienteGaussianoCurvo
void WrapClass_SubPixel2D::wrap_SuperGradienteGaussianoCurvo
                         ::SetParametersComments()
{
  return_comments = "Returns an AMIObject with parameters inside 1D images.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SubPixel2D::wrap_SuperGradienteGaussianoCurvo
                                       ::CallMember(ParamList* p)
{
  SubPixel2D::ptr sp(this->_objectptr->GetObj());
  
  sp->SuperGradienteGaussianoCurvo();
  
  //Create the AMIObject with the result
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("GaussianSub-pixel2D");
  int size = sp->getBorderPixelVector().size();
  //InrImages for params
  InrImage::ptr AIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "aintensity.inr.gz"));
  InrImage::ptr BIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bintensity.inr.gz"));
  InrImage::ptr border     = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_CHAR,
                                                        "border.inr.gz"));
  InrImage::ptr a          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "acoef.inr.gz"));
  InrImage::ptr b          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bcoef.inr.gz"));
  InrImage::ptr c          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "ccoef.inr.gz"));
  InrImage::ptr curvature  = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "curvature.inr.gz"));
  InrImage::ptr posx       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "xpos.inr.gz"));
  InrImage::ptr posy       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "ypos.inr.gz"));
  
  //Fill InrImages
  sp->fillImages(AIntensity, BIntensity, border, a, b, c, curvature, 
                 posx, posy);
  
  //Copy the result of averaged in a smart pointer
  InrImage* aux = sp->getDenoised();
  InrImage::ptr output = InrImage::ptr(new InrImage(WT_DOUBLE,
                                                    "averaged.ami.gz",aux));
  *(output.get()) = *aux;
  
  //Add to amiobject
  amiobject->GetContext()->AddVar<InrImage>("denoised", output,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("aintensity", AIntensity, 
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bintensity", BIntensity,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("border", border,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("acoef", a,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bcoef", b,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ccoef", c,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("curvature", curvature,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("xpos", posx,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ypos", posy,
                                            amiobject->GetContext());

  Variable<AMIObject>::ptr result(
      new Variable<AMIObject>(amiobject));
  return result;

}

//---------------------------------------------------
//DenoisingGus
void WrapClass_SubPixel2D::wrap_DenoisingGus
                         ::SetParametersComments()
{
  return_comments = "Returns an AMIObject with parameters inside 1D images.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SubPixel2D::wrap_DenoisingGus
                                       ::CallMember(ParamList* p)
{
  SubPixel2D::ptr sp(this->_objectptr->GetObj());
  
  sp->DenoisingGus();
  
  //Create the AMIObject with the result
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("GaussianSub-pixel2D");
  int size = sp->getBorderPixelVector().size();
  //InrImages for params  
  InrImage::ptr AIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "aintensity.inr.gz"));
  InrImage::ptr BIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bintensity.inr.gz"));
  InrImage::ptr border     = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_CHAR,
                                                        "border.inr.gz"));
  InrImage::ptr a          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "acoef.inr.gz"));
  InrImage::ptr b          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bcoef.inr.gz"));
  InrImage::ptr c          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "ccoef.inr.gz"));
  InrImage::ptr curvature  = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "curvature.inr.gz"));
  InrImage::ptr posx       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "xpos.inr.gz"));
  InrImage::ptr posy       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "ypos.inr.gz"));
  
  //Fill InrImages
  sp->fillImages(AIntensity, BIntensity, border, a, b, c, curvature, 
                 posx, posy);
  
  //Copy the result of averaged in a smart pointer
  InrImage* aux = sp->getDenoised();
  InrImage::ptr output = InrImage::ptr(new InrImage(WT_DOUBLE,
                                                    "averaged.ami.gz",aux));
  *(output.get()) = *aux;
  
  //Add to amiobject
  amiobject->GetContext()->AddVar<InrImage>("denoised", output,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("aintensity", AIntensity, 
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bintensity", BIntensity,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("border", border,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("acoef", a,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bcoef", b,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ccoef", c,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("curvature", curvature,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("xpos", posx,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ypos", posy,
                                            amiobject->GetContext());

  Variable<AMIObject>::ptr result(
      new Variable<AMIObject>(amiobject));
  return result;
}


//---------------------------------------------------
//SubpixelDenoising
void WrapClass_SubPixel2D::wrap_SubpixelDenoising
                         ::SetParametersComments()
{
  return_comments = "Returns an AMIObject with parameters inside 1D images.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SubPixel2D::wrap_SubpixelDenoising
                                       ::CallMember(ParamList* p)
{
  SubPixel2D::ptr sp(this->_objectptr->GetObj());
  int n = 0;
  int niter;
  
  if (!get_val_param<int>(niter, p, n)) ClassHelpAndReturn;

  sp->SubpixelDenoising(niter);
  
  //Create the AMIObject with the result
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("SubpixelDenoising2D");
  int size = sp->getBorderPixelVector().size();
  //InrImages for params
  InrImage::ptr AIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "aintensity.inr.gz"));
  InrImage::ptr BIntensity = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bintensity.inr.gz"));
  InrImage::ptr border     = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_CHAR,
                                                        "border.inr.gz"));
  InrImage::ptr a          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "acoef.inr.gz"));
  InrImage::ptr b          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "bcoef.inr.gz"));
  InrImage::ptr c          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "ccoef.inr.gz"));
  InrImage::ptr curvature  = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "curvature.inr.gz"));
  InrImage::ptr posx       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "xpos.inr.gz"));
  InrImage::ptr posy       = InrImage::ptr(new InrImage(size, 1, 1, WT_UNSIGNED_SHORT,
                                                        "ypos.inr.gz"));
  
  //Fill InrImages
  sp->fillImages(AIntensity, BIntensity, border, a, b, c, curvature, 
                 posx, posy);

  //Copy the result of restoration in a smart pointer
  InrImage* aux = sp->getInput();
  InrImage::ptr output = InrImage::ptr(new InrImage(WT_DOUBLE,
                                                    "restored.ami.gz",aux));
  *(output.get()) = *aux;


  //Add to amiobject
  amiobject->GetContext()->AddVar<InrImage>("restored", output,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("aintensity", AIntensity, 
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bintensity", BIntensity,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("border", border,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("acoef", a,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("bcoef", b,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ccoef", c,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("curvature", curvature,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("xpos", posx,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ypos", posy,
                                            amiobject->GetContext());

  Variable<AMIObject>::ptr result(
      new Variable<AMIObject>(amiobject));
  return result;
}


//---------------------------------------------------
//drawBorder
void WrapClass_SubPixel2D::wrap_drawBorder::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(AMIObject, "The image viewer.");
  ADDPARAMCOMMENT_TYPE(InrImage,  "Image that marks de view zone.");
  ADDPARAMCOMMENT_TYPE(InrImage,  "Points for draw the border.");
  ADDPARAMCOMMENT_TYPE(wxColour,  "Border color.");
  ADDPARAMCOMMENT_TYPE(int,       "Border thickness.");
  ADDPARAMCOMMENT_TYPE(int,       "Border style.");
  ADDPARAMCOMMENT_TYPE(int,       "Says if draw the border normals.");
  ADDPARAMCOMMENT_TYPE(InrImage,  "Points for draw normals.");
  ADDPARAMCOMMENT_TYPE(wxColour,  "Normals color.");
  ADDPARAMCOMMENT_TYPE(int,       "Normals thickness.");
  ADDPARAMCOMMENT_TYPE(int,       "Normals style.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SubPixel2D::wrap_drawBorder::CallMember(ParamList* p)
{
  SubPixel2D::ptr sp(this->_objectptr->GetObj());
    
  DessinImage* viewer = NULL;
  InrImage* inside;
  InrImage* border_pts;
  InrImage* norm_pts;
  int draw_normals;
  int bthickness;
  int bstyle;
  int nthickness;
  int nstyle;
  int n = 0;
  //Get the viewer object
  CLASS_GET_OBJECT_PARAM(DessinImage, viewervar, viewerobj);
  if(viewerobj.get())
    viewer = viewerobj.get();
  else
    ClassHelpAndReturn;
  
  //Get params (inside, border points, color, thickness, style and normals control)
  if (!get_val_ptr_param<InrImage>(inside, p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<InrImage>(border_pts, p, n)) ClassHelpAndReturn;
  CLASS_GET_OBJECT_PARAM(wxColour, bcolorvar, bcolorobj);
  if (bcolorobj.get()) {
    if (!get_int_param(bthickness, p, n)) ClassHelpAndReturn;
    if (!get_int_param(bstyle, p, n)) ClassHelpAndReturn;
    if (!get_int_param(draw_normals, p, n)) ClassHelpAndReturn;
  }
  else ClassHelpAndReturn;
  
  //If the user sets draw_normals, get the normal points image, and call to
  //drawBorder
  if (draw_normals) 
  {
    if (!get_val_ptr_param<InrImage>(norm_pts, p, n)) ClassHelpAndReturn;
    CLASS_GET_OBJECT_PARAM(wxColour, ncolorvar, ncolorobj);
    if (ncolorobj.get()) 
    {
      if (!get_int_param(nthickness, p, n)) ClassHelpAndReturn;
      if (!get_int_param(nstyle, p, n)) ClassHelpAndReturn;
      sp->drawBorder(viewer, inside, border_pts, bcolorobj.get(), bthickness, 
                     bstyle, draw_normals, norm_pts, ncolorobj.get(), nthickness, 
                     nstyle);
    }
    else ClassHelpAndReturn;
  }
  else 
  {
    //If it isn't set draw_normals, calls to drawBorder with a NULL value on
    //last parameters
    sp->drawBorder(viewer, inside, border_pts, bcolorobj.get(), bthickness, bstyle,
                   draw_normals, NULL, NULL, 0, 0);
  }
  return BasicVariable::ptr();
}

