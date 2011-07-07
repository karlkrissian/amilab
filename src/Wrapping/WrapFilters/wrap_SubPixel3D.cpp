/*
 *  wrap_SubPixel3D.cpp
 *  AMILab
 */

#include "wrap_SubPixel3D.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "SubPixel3D.h"
#include "wrap_DessinImage.h"
#include <wx/colour.h>


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<SubPixel3D>::CreateVar( ParamList* p)
{
  WrapClass_SubPixel3D::wrap_SubPixel3D construct;
  return construct.CallMember(p);
}

//---------------------------------------------------
//SubPixel3D Wrapping
//---------------------------------------------------

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(SubPixel3D);
AMI_DEFINE_VARFROMSMTPTR(SubPixel3D);

//---------------------------------------------------
//SubPixel3D Constructor
void WrapClass_SubPixel3D::wrap_SubPixel3D::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE(InrImage, "The input image.");
  ADDPARAMCOMMENT_TYPE(float, "The intensity threshold.");
  ADDPARAMCOMMENT_TYPE(int, "First or second order method.");
  return_comments = "A wrapped SubPixel3D object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SubPixel3D::wrap_SubPixel3D::CallMember(ParamList* p)
{
  InrImage* input_image;
  float thres;
  int num = 0;
  
  if (!get_val_ptr_param<InrImage>(input_image, p, num)) ClassHelpAndReturn;
  if (!get_val_param<float>(thres, p, num))    ClassHelpAndReturn;
  
  return AMILabType<SubPixel3D>::CreateVar(new SubPixel3D(input_image, thres));
}

//---------------------------------------------------
//GradienteCurvo3D
void WrapClass_SubPixel3D::wrap_GradienteCurvo3D::SetParametersComments()
{
  return_comments = "Returns an AMIObject with parameters inside 1D images.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_SubPixel3D::wrap_GradienteCurvo3D
                                       ::CallMember(ParamList* p)
{
  SubPixel3D::ptr sp(_objectptr->GetObj());
    
  sp->GradienteCurvo3D();
  
  //Create the AMIObject with the result
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("Sub-pixel2D");
  int size = sp->getBorderVoxelVector().size();
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
  InrImage::ptr d          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "dcoef.inr.gz"));
  InrImage::ptr f          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "fcoef.inr.gz"));
  InrImage::ptr g          = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "gcoef.inr.gz"));
  InrImage::ptr curvature  = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "curvature.inr.gz"));
  InrImage::ptr posx       = InrImage::ptr(new InrImage(size, 1, 1, WT_SIGNED_SHORT,
                                                        "xpos.inr.gz"));
  InrImage::ptr posy       = InrImage::ptr(new InrImage(size, 1, 1, WT_SIGNED_SHORT,
                                                        "ypos.inr.gz"));
  InrImage::ptr posz       = InrImage::ptr(new InrImage(size, 1, 1, WT_SIGNED_SHORT,
                                                        "zpos.inr.gz"));
  InrImage::ptr nx       = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "nx.inr.gz"));
  InrImage::ptr ny       = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "ny.inr.gz"));
  InrImage::ptr nz       = InrImage::ptr(new InrImage(size, 1, 1, WT_DOUBLE,
                                                        "nz.inr.gz"));
  
  
  //Fill InrImages
  sp->fillImages(AIntensity, BIntensity, border, a, b, c, d, f, g, curvature,
                 posx, posy, posz, nx, ny, nz);
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
  amiobject->GetContext()->AddVar<InrImage>("dcoef", d,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("fcoef", f,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("gcoef", g,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("curvature", curvature,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("xpos", posx,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ypos", posy,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("zpos", posz,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("nx", nx,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("ny", ny,
                                            amiobject->GetContext());
  amiobject->GetContext()->AddVar<InrImage>("nz", nz,
                                            amiobject->GetContext());

  Variable<AMIObject>::ptr result(
      new Variable<AMIObject>(amiobject));
  return result;

}

