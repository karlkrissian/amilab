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

#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define GET_SMTPTR_PARAM(type,varname) \
  boost::shared_ptr<type> varname; \
  if (!get_val_smtptr_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define RETURN_VARPTR(type,  value) \
  boost::shared_ptr<type> newval(new type(value)); \
  return Variable<type>::ptr( new Variable<type>(newval));


//---------------------------------------------------
//SubPixel2D Wrapping
//---------------------------------------------------
AMIObject::ptr AddWrap_SubPixel2D(WrapClass_SubPixel2D::ptr& objectptr)
{
  //Create a new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("SubPixel2D");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods(objectptr);
  return amiobject;
}

//---------------------------------------------------
Variable<AMIObject>::ptr CreateVar_SubPixel2D(SubPixel2D* si)
{
  boost::shared_ptr<SubPixel2D> si_ptr(si);
  WrapClass_SubPixel2D::ptr sip(new WrapClass_SubPixel2D(si_ptr));
  AMIObject::ptr amiobject(AddWrap_SubPixel2D(sip));
  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>(amiobject));
  return varres;
}

//---------------------------------------------------
//SubPixel2D Constructor
void wrap_SubPixel2D::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage, "The input image.");
  ADDPARAMCOMMENT_TYPE(float, "The intensity threshold.");
  ADDPARAMCOMMENT_TYPE(int, "First or second order method.");
  return_comments = "A wrapped SubPixel2D object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_SubPixel2D::CallMember(ParamList* p)
{
  InrImage* input;
  float threshold;
  int linear_case;
  int n = 0;
  
  if (!get_val_ptr_param<InrImage>(input, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(threshold, p, n))    ClassHelpAndReturn;
  if (!get_val_param<int>(linear_case, p, n))    ClassHelpAndReturn;
  
  return CreateVar_SubPixel2D(new SubPixel2D(input, threshold, linear_case));
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
  vector<borderPixel> vaux = sp->getBorderPixelVector();
  sp->fillImages(vaux, AIntensity, BIntensity, border, a, b, c, curvature, 
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
  
  InrImage::ptr output = InrImage::ptr(new InrImage(WT_DOUBLE, 
                                                    "promedio.ami.gz",
                                                    sp->getInput()));
  
  sp->Promedio3x3(/*sp->getInput(),*/ output.get(), (double)1/9, (double)1/9, (double)1/9);
  
  sp->setInput(output.get());
  
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
  vector<borderPixel> vaux = sp->getBorderPixelVector();
  sp->fillImages(vaux, AIntensity, BIntensity, border, a, b, c, curvature, 
                 posx, posy);
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
  
  InrImage::ptr output = InrImage::ptr(new InrImage(WT_DOUBLE, 
                                                    "promedio.ami.gz",
                                                    sp->getInput()));
  
  sp->Promedio3x3(output.get(), (double)1/9, (double)1/9, (double)1/9);
  
  sp->setInput(output.get());
  
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
  vector<borderPixel> vaux = sp->getBorderPixelVector();
  sp->fillImages(vaux, AIntensity, BIntensity, border, a, b, c, curvature, 
                 posx, posy);
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

