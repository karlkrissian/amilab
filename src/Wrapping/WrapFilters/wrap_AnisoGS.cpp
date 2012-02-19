//
// C++ Implementation: wrap_AnisoGS
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_AnisoGS.h"
#include "amiAnisoGS.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "func_imagebasictools.h"

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_AnisoGS(  WrapClass_AnisoGS::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("AnisoGS");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddMethods(       objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_AnisoGS( ami::AnisoGS* si)
{
  // here AnisoGS can be deleted
  boost::shared_ptr<ami::AnisoGS> _si_ptr( si );

  WrapClass_AnisoGS::ptr sip(new WrapClass_AnisoGS(_si_ptr));
  AMIObject::ptr amiobject(AddWrap_AnisoGS(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  AnisoGS Constructor
//---------------------------------------------------
void  wrap_AnisoGS::SetParametersComments() 
{
  ADDPARAMCOMMENT("input image");
  ADDPARAMCOMMENT("sigma: standard deviation of the Gaussian smoothing applied to compute the local structure orientations.");
  ADDPARAMCOMMENT("k: diffusion parameter that controls the diffusion depending on the local gradients.");
  ADDPARAMCOMMENT("beta: data attachment coefficient.");
  ADDPARAMCOMMENT("number of iterations");
  return_comments = "Resulting image.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_AnisoGS::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  if (p->GetNumParam()==0) 
    return CreateVar_AnisoGS(new ami::AnisoGS());

  int n = 0;
  
  InrImage* input;
  float sigma;
  float k;
  float beta;
  int   nb_iter;

  if (!get_val_ptr_param<InrImage>
                           (  input,   p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(  sigma,   p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(  k,       p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(  beta,    p, n)) ClassHelpAndReturn;
  if (!get_int_param(         nb_iter, p, n)) ClassHelpAndReturn;

  ami::AnisoGS::ptr aniso(new ami::AnisoGS());
  aniso->Init(input,sigma,k,beta);

  if (nb_iter < 1) nb_iter = 1;

  //int error = 0;
  for(int i=1;i<=nb_iter;i++){
    //error = 
    aniso->Iterate();
  }

  InrImage* imres = aniso->Getresult_image();
  int bs = aniso->boundary_extension_size;

  InrImage::ptr res(
                    Func_SubImage( imres,
                        bs,bs,bs,
                        imres->DimX()-1-bs,
                        imres->DimY()-1-bs,
                        imres->DimZ()-1-bs));
  // Set translation and voxel size ?

  // show delete imres ???
  Variable<InrImage>::ptr varres( new Variable<InrImage>(res));
  return varres;
}

//---------------------------------------------------
//  Init
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_Init::SetParametersComments() 
{
  ADDPARAMCOMMENT("input image");
  ADDPARAMCOMMENT("sigma: standard deviation of the Gaussian smoothing applied to compute the local structure orientations.");
  ADDPARAMCOMMENT("k: diffusion parameter that controls the diffusion depending on the local gradients.");
  ADDPARAMCOMMENT("beta: data attachment coefficient.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_Init::CallMember( ParamList* p)
{
  int n = 0;
  InrImage* input;
  float sigma;
  float k;
  float beta;

  if (!get_val_ptr_param<InrImage>
                           (  input,   p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(  sigma,   p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(  k,       p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(  beta,    p, n)) ClassHelpAndReturn;

  this->_objectptr->_obj->Init(input,sigma,k,beta);
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  SetDistMap
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetDistMap::SetParametersComments() 
{
  ADDPARAMCOMMENT("bool: Enable/Disable distance map computation, in this mode, the filter tries to compute an Euclidean distance map.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetDistMap::CallMember( ParamList* p)
{
  int n = 0;
  int dm = 0;
  if (!get_int_param(  dm,   p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->SetDistanceMap(dm);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetNoiseType
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetNoiseType::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: 0: Gaussian noise, 1: Speckle noise.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetNoiseType::CallMember( ParamList* p)
{
  int n = 0;
  int nt = 0;
  if (!get_int_param(  nt,   p, n)) ClassHelpAndReturn;

  switch (nt) {
    case GAUSSIAN_NOISE:
    case SPECKLE_NOISE:
      this->_objectptr->_obj->Setnoise_type( nt);
      break;
    default:
      CLASS_ERROR("Func_AnisoGS_SetNoiseType(%d) \t bad noise type \n");
  }
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetMask
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetMask::SetParametersComments() 
{
  ADDPARAMCOMMENT("image: mask.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetMask::CallMember( ParamList* p)
{
  int n = 0;
  InrImage::ptr mask;
  if (!get_val_smtptr_param<InrImage>
                           (  mask,   p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->Setmask( mask);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetAttachMask
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetAttachMask::SetParametersComments() 
{
  ADDPARAMCOMMENT("image: Attachment mask, only apply attachment data to pixels/voxels with mask value >0.5 .");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetAttachMask::CallMember( ParamList* p)
{
  int n = 0;
  InrImage::ptr mask;
  if (!get_val_smtptr_param<InrImage>
                           (  mask,   p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->Setattach_mask( mask);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetSRADROI
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetSRADROI::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image which defines a region of interest used to estimate the noise parameters in the Oriented Speckle Reducing Anisotropic Diffusion");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetSRADROI::CallMember( ParamList* p)
{
  int n = 0;
  InrImage::ptr roi;
  if (!get_val_smtptr_param<InrImage>
                           (  roi,   p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->SetSRAD_ROI(roi);
  this->_objectptr->_obj->Setcontours_mode( ami::AnisoGS::CONTOURS_SRAD);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetRNRADROI
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetRNRADROI::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image which defines a region of interest used to estimate the noise parameters in the Rician Noise Reducing Anisotropic Diffusion");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetRNRADROI::CallMember( ParamList* p)
{
  int n = 0;
  InrImage::ptr roi;
  if (!get_val_smtptr_param<InrImage>
                           (  roi,   p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->SetSRAD_ROI(roi);
  this->_objectptr->_obj->Setcontours_mode( ami::AnisoGS::CONTOURS_RNRAD);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetRNRADROI_NEW
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetRNRADROI_NEW::SetParametersComments() 
{
  ADDPARAMCOMMENT("mage which defines a region of interest used to estimate the noise parameters in the Rician Noise Reducing Anisotropic Diffusion");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetRNRADROI_NEW::CallMember( ParamList* p)
{
  int n = 0;
  InrImage::ptr roi;
  if (!get_val_smtptr_param<InrImage>
                           (  roi,   p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->SetSRAD_ROI(roi);
  this->_objectptr->_obj->Setcontours_mode( ami::AnisoGS::CONTOURS_RNRAD_NEW);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetLocalStruct
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetLocalStruct::SetParametersComments() 
{
  ADDPARAMCOMMENT("expr: determine the local structure description: -0 for smoothed gradient and principal curv. directions; -1 for the local structure tensor.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetLocalStruct::CallMember( ParamList* p)
{
  int n = 0;
  int lsm = 0;
  if (!get_int_param( lsm, p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->Setlocal_structure_mode( lsm);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetEigenMode
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetEigenMode::SetParametersComments() 
{
  ADDPARAMCOMMENT(" expr: option for selecting the eigenvalues for the diffusion matrix, 0: sums the 3D, 2D and 1D diffusions: - lambda1 will depend on a coefficient based on a 3D neighborhood - lambda2 will be the sum of lambda1 + a coeff based on a 2D neighborhood  - lambda3 = lambda2 + coeff based on a linear neigh.  1: take the maximum instead of the sum");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetEigenMode::CallMember( ParamList* p)
{
  return BasicVariable::ptr();
  int n = 0;
  int em = 0;
  if (!get_int_param( em, p, n)) ClassHelpAndReturn;

  this->_objectptr->_obj->Setdiffusion_eigenvalues_mode( em);
}

//---------------------------------------------------
//  Setdt
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_Setdt::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: time-step value for the PDE.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_Setdt::CallMember( ParamList* p)
{
  int n = 0;
  float dt = 0;
  if (!get_val_param<float>( dt,   p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->Setdt(dt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Setneighborhood
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_Setneighborhood::SetParametersComments() 
{
  ADDPARAMCOMMENT(" integer: if a value 'd' is given, the neighborhood will be (2d+1)^n where n is the image dimension.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_Setneighborhood::CallMember( ParamList* p)
{
  return BasicVariable::ptr();
  int n = 0;
  int ns = 1;
  if (!get_int_param( ns, p, n)) ClassHelpAndReturn;

  this->_objectptr->_obj->Setneighborhood( ns);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  setcoeff
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_setcoeff::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: if 2 parameters: coefficient in the minimal curvature direction. if 1 parameter coefficient for the tangential direction (parallel to the contours).");
  ADDPARAMCOMMENT("float: coefficient in the maximal curvature direction.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_setcoeff::CallMember( ParamList* p)
{

  if (p->GetNumParam()==1) {
    int n = 0;
    float tang_coeff = 0;
    if (!get_val_param<float>(  tang_coeff,   p, n)) ClassHelpAndReturn;
    this->_objectptr->_obj->Settang_coeff(tang_coeff);
    return BasicVariable::ptr();
  }

  int n = 0;
  float cmin = 0;
  float cmax = 0;
  if (!get_val_param<float>( cmin,   p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( cmax,   p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->Setmincurv_coeff(cmin);
  this->_objectptr->_obj->Setmaxcurv_coeff(cmax);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Iterate
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_Iterate::SetParametersComments() 
{
  return_comments="Returns the maximal difference between the 2 last iterations.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_Iterate::CallMember( ParamList* p)
{
  float diff = this->_objectptr->_obj->Iterate();
  RETURN_VAR(float,diff);
}

//---------------------------------------------------
//  GetNoiseSD
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_GetNoiseSD::SetParametersComments() 
{
  return_comments="Estimated noise standard deviation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_GetNoiseSD::CallMember( ParamList* p)
{
  float nsd = this->_objectptr->_obj->Getnoise_standard_deviation();
  RETURN_VAR(float,nsd);
}

//---------------------------------------------------
//  SetNoiseSD
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_SetNoiseSD::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: user set noise standard deviation.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_SetNoiseSD::CallMember( ParamList* p)
{
  int n = 0;
  float nsd = 0;
  if (!get_val_param<float>( nsd,   p, n)) ClassHelpAndReturn;

  this->_objectptr->_obj->Setnoise_standard_deviation( nsd);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetDAcoeff
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_GetDAcoeff::SetParametersComments() 
{
  return_comments="Return estimated Data Attachment coefficient.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_GetDAcoeff::CallMember( ParamList* p)
{
  float dac = this->_objectptr->_obj->Getestimated_DA_coeff();
  RETURN_VAR(float,dac);
}

//---------------------------------------------------
//  GetOutput
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_GetOutput::SetParametersComments() 
{
  return_comments="Output image.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_GetOutput::CallMember( ParamList* p)
{
}

//---------------------------------------------------
//  GetDiffCoeff
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_GetDiffCoeff::SetParametersComments() 
{
  ADDPARAMCOMMENT("The image of the diffusion coefficients.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_GetDiffCoeff::CallMember( ParamList* p)
{
  InrImage* imc  = this->_objectptr->_obj->Getimage_c();
  if (imc!=NULL)
  {
    InrImage::ptr res(new InrImage(WT_FLOAT, "imagec_copy.ami.gz", imc));
    (*res) = (*imc);
    Variable<InrImage>::ptr varres( new Variable<InrImage>(res));
    return varres;
  }
  else {
    CLASS_ERROR("image_c == NULL ");
    return BasicVariable::ptr();
  }
}

//---------------------------------------------------
//  Compute_sigma2_MRI_mode
//---------------------------------------------------
void WrapClass_AnisoGS::
      wrap_Compute_sigma2_MRI_mode::SetParametersComments() 
{
  ADDPARAMCOMMENT("The input image to estimate the noise variance.");
  return_comments = "The estimated noise variance as a float variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_AnisoGS::
      wrap_Compute_sigma2_MRI_mode::CallMember( ParamList* p)
{
  int n = 0;
  InrImage::ptr inputim;
  if (!get_val_smtptr_param<InrImage>
                           (  inputim,   p, n)) ClassHelpAndReturn;

  float variance = this->_objectptr->_obj->Compute_sigma2_MRI_mode(inputim.get());
  RETURN_VAR(float,variance);
}

