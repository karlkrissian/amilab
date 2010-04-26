//
// C++ Implementation: wrap_vtkLevelSets
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapfunctions_draw.h"
#include "ami_class.h"
#include "ami_object.h"
#include "vtkLevelSets.h"
#include "wrap_vtkLevelSets.h"
#include "MainFrame.h"
#include "ami_function.h"
#include "vtkCommand.h"
#include "vtk_common.h"

#define RETURN_VARINT(val,name)             \
  std::string varname = (boost::format("%1%_id")%name).str();\
  int_ptr varint(new int(val));\
  Variable<int>::ptr varres( new Variable<int>(varname, varint));\
  return varres;


extern MainFrame*     GB_main_wxFrame;

class vtkUpdateProgressBar : public vtkCommand
{
  public:

  static vtkUpdateProgressBar *New() { return new vtkUpdateProgressBar;  }

  virtual void Execute(vtkObject *caller, unsigned long, void* calldata)
  {
    double value = *(double*) calldata;
    GB_main_wxFrame->SetProgress((int)(value*100+0.5));
  }
};
static vtkUpdateProgressBar update_progressbar;


//-------------------------------------------------------------------------
AMIObject::ptr AddWrapvtkLevelSets(  WrapClass_vtkLevelSets::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("vtkLevelSets");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddVar_SetParam(           objectptr);
  objectptr->AddVar_InitWithImage(      objectptr);
  objectptr->AddVar_InitWithThreshold(  objectptr);
 
  objectptr->AddVar_SetILowTh(          objectptr);
  objectptr->AddVar_SetIHighTh(         objectptr);
  objectptr->AddVar_SetNumInitPoints(   objectptr);
  objectptr->AddVar_SetInitPoint(       objectptr);
  objectptr->AddVar_SetIsoContourBin(   objectptr);
  objectptr->AddVar_SetMeanCurv(        objectptr);
  objectptr->AddVar_SetAffineCurv(      objectptr);
  objectptr->AddVar_SetCurvWeights(     objectptr);
  objectptr->AddVar_GetCurvature(       objectptr);
  objectptr->AddVar_SetVelocity(        objectptr);
  objectptr->AddVar_GetVelocity(        objectptr);
  objectptr->AddVar_SetBalloonScheme(   objectptr);
  objectptr->AddVar_SetExpansionImage(  objectptr);
  objectptr->AddVar_SetExpansion(       objectptr);
  objectptr->AddVar_GetExpansion(       objectptr);
  objectptr->AddVar_SetProbThreshold(   objectptr);
  objectptr->AddVar_SetProbHighTh(      objectptr);
  objectptr->AddVar_SetNumGaussians(    objectptr);
  objectptr->AddVar_SetGaussian(        objectptr);
  objectptr->AddVar_SetAdvectionField(  objectptr);
  objectptr->AddVar_GetAdvection(       objectptr);
  objectptr->AddVar_SetDistMethod(      objectptr);
  objectptr->AddVar_SetBandTube(        objectptr);
  objectptr->AddVar_GetDistMap(         objectptr);
  objectptr->AddVar_GetSkeleton(        objectptr);

  objectptr->AddVar_SetThreads(         objectptr);
  objectptr->AddVar_SaveDistMap(        objectptr);
  objectptr->AddVar_SaveSecDerGrad(     objectptr);
  objectptr->AddVar_Iterate(            objectptr);
  objectptr->AddVar_UpdateResult(       objectptr);
  objectptr->AddVar_GetOutputImage(     objectptr);
  objectptr->AddVar_GetAttachVect(      objectptr);
  objectptr->AddVar_End(                objectptr);

  return amiobject;
}

//---------------------------------------------------
BasicVariable::ptr wrap_vtkLevelSets( ParamList* p)
{
    char functionname[] = "vtkLevelSets";
    char description[]=" \n\
      New vtkLevelSets object, for creating GUI. \n\
            ";
    char parameters[] =" \n\
            ";

  Variable<AMIObject>::ptr var;
  boost::shared_ptr<vtkLevelSets> ownls = vtk_new<vtkLevelSets> ()();
  WrapClass_vtkLevelSets::ptr wls(new WrapClass_vtkLevelSets());
  wls->_vtkLevelSets = ownls;
  AMIObject::ptr amiobject (AddWrapvtkLevelSets(wls));
  Variable<AMIObject>::ptr varres( new Variable<AMIObject>("tmp_vtkLevelSets",  amiobject));

  return varres;

}


//---------------------------------------------------
//  SetParam
// version 1
    // threshold on cumulative histo = 0.8
    // 1. number of iterations
    // 2. coefficient of the data attachment
    // 3. curvature coefficient
    // evolution step = 1
    // 4. reinitialization frequency for the distance map
// version 2
    // Parameters:
    // 1. threshold on the cumulative histo of the grad norm for data attachment
    // 2. number of iterations
    // 3. coefficient of the data attachment
    // 4. curvature coefficient
    // 5. evolution step dt
    // 6. reinitialization frequency for the distance map

//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetParam::SetParametersComments() 
{
  // 1. threshold on the cumulative histo of the grad norm for data attachment
  // 2. number of iterations
  // 3. coefficient of the data attachment
  // 4. curvature coefficient
  // 5. evolution step dt
  // 6. reinitialization frequency for the distance map

  ADDPARAMCOMMENT("Threshold on the cumulative histo of the grad norm for data attachment");
  ADDPARAMCOMMENT("Number of iterations");
  ADDPARAMCOMMENT("Coefficient of the data attachment");
  ADDPARAMCOMMENT("Curvature coefficient");
  ADDPARAMCOMMENT("Evolution step dt");
  ADDPARAMCOMMENT("Reinitialization frequency for the distance map");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetParam::CallMember( ParamList* p)
{
  float thres_ng    = 0.8;
  int   nb_it       = 10;
  float coeff_data  = 1;
  float coeff_curv  = 1;
  float dt          = 1;
  int   freq        = 6;
  int   n = 0;

  if (!get_val_param<float>( thres_ng,   p, n))     ClassHelpAndReturn;
  if (!get_int_param       ( nb_it,      p, n))     ClassHelpAndReturn;
  if (!get_val_param<float>( coeff_data, p, n))     ClassHelpAndReturn;
  if (!get_val_param<float>( coeff_curv, p, n))     ClassHelpAndReturn;
  if (!get_val_param<float>( dt,         p, n))     ClassHelpAndReturn;
  if (!get_int_param       ( freq,      p, n))     ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);

  curv->SetNumIters(           nb_it);
  curv->SetAdvectionCoeff(     coeff_data);
  curv->SetStepDt(             dt);
  curv->SetReinitFreq(         freq);
  curv->SetHistoGradThreshold( thres_ng);
  curv->Setcoeff_curvature(    coeff_curv);
  curv->SetDMmethod(           DISTMAP_FASTMARCHING);
  curv->Setsavedistmap(        0);
  //  Si meancurv AlorsFait curv->DoMeanOn();
  curv->Setadvection_scheme(   ADVECTION_MORPHO);

  // Progress event, really needed ??
  curv->AddObserver(vtkCommand::ProgressEvent,&update_progressbar);

  return BasicVariable::ptr();

}

//---------------------------------------------------
//  InitWithImage
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_InitWithImage::SetParametersComments() 
{
  ADDPARAMCOMMENT("Input image.");
  ADDPARAMCOMMENT("Initial position of the level set a the zero-crossing of this image.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_InitWithImage::CallMember( ParamList* p)
{
  InrImage* input = NULL;
  InrImage* initial = NULL;
  int n=0;

  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<InrImage>(  initial,  p, n)) ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);

  // Initialize the evolution
  this->_objectptr->image_input  = (vtkImageData_ptr) (*input);
  this->_objectptr->image_output = vtk_new<vtkImageData>()();

  if (!this->_objectptr->initimage.use_count()) {
    this->_objectptr->initimage = (vtkImageData_ptr) (*initial);
  }

  curv->InitParam( this->_objectptr->image_input.get(), this->_objectptr->image_output.get());
  curv->SetinitImage(this->_objectptr->initimage.get());
  curv->SetInitThreshold(0);
  curv->InitEvolution();
  InrImage::ptr res(new InrImage(this->_objectptr->image_output.get()));
  return Variable<InrImage>::ptr(new Variable<InrImage>(res));
}

//---------------------------------------------------
//  InitWithThreshold
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_InitWithThreshold::SetParametersComments() 
{
  ADDPARAMCOMMENT("Input image.");
  ADDPARAMCOMMENT("Threshold on the input image to define the initial contour.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_InitWithThreshold::CallMember( ParamList* p)
{

  InrImage* input = NULL;
  int th = 0;
  int n=0;

  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;
  if (!get_int_param(  th,  p, n)) ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);

  InrImage* out;
  //float tr_x,tr_y,tr_z;

  // Initialize the evolution
  this->_objectptr->image_input  = (vtkImageData_ptr) (*input);
  this->_objectptr->image_output = vtk_new<vtkImageData>()();

  curv->InitParam( this->_objectptr->image_input.get(), this->_objectptr->image_output.get());

  curv->SetInitThreshold(   th);
  curv->InitEvolution();
  InrImage::ptr res(new InrImage(this->_objectptr->image_output.get()));
  return Variable<InrImage>::ptr(new Variable<InrImage>(res));
}

//---------------------------------------------------
//  SetILowTh
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetILowTh::SetParametersComments() 
{
  ADDPARAMCOMMENT("Initial image lower intensity threshold.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetILowTh::CallMember( ParamList* p)
{
  float thres    = 0;
  int   n = 0;

  if (!get_val_param<float>( thres,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->UseLowThresholdOn();
  curv->SetLowThreshold(thres);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetIHighTh
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetIHighTh::SetParametersComments() 
{
  ADDPARAMCOMMENT("Initial image higher intensity threshold.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetIHighTh::CallMember( ParamList* p)
{
  float thres    = 0;
  int   n = 0;

  if (!get_val_param<float>( thres,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->UseHighThresholdOn();
  curv->SetHighThreshold(thres);
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  SetNumInitPoints
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetNumInitPoints::SetParametersComments() 
{
  ADDPARAMCOMMENT("Number of initial points.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetNumInitPoints::CallMember( ParamList* p)
{
  int   nb = 0;
  int   n  = 0;

  if (!get_int_param( nb,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->SetNumInitPoints(nb);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetInitPoint
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetInitPoint::SetParametersComments() 
{
  ADDPARAMCOMMENT("Index of the point");
  ADDPARAMCOMMENT("X coordinate");
  ADDPARAMCOMMENT("Y coordinate");
  ADDPARAMCOMMENT("Z coordinate");
  ADDPARAMCOMMENT("Radius of the sphere");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetInitPoint::CallMember( ParamList* p)
{
  int   id = 0;
  int   x = 0;
  int   y = 0;
  int   z = 0;
  float radius = 1;
  int   n  = 0;

  if (!get_int_param( id,   p, n))     ClassHelpAndReturn;
  if (!get_int_param( x,   p, n))     ClassHelpAndReturn;
  if (!get_int_param( y,   p, n))     ClassHelpAndReturn;
  if (!get_int_param( z,   p, n))     ClassHelpAndReturn;
  if (!get_val_param<float>( radius,   p, n))     ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->SetInitPoint(id,x,y,z,radius);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetIsoContourBin
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetIsoContourBin::SetParametersComments() 
{
  ADDPARAMCOMMENT("bool (0 or 1): use binary contours (for experimental purpose, bad accuracy ...)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetIsoContourBin::CallMember( ParamList* p)
{
  int   bc = 0;
  int   n  = 0;

  if (!get_int_param( bc,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->SetIsoContourBin(bc);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetMeanCurv
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetMeanCurv::SetParametersComments() 
{
  ADDPARAMCOMMENT("bool: set Mean curvature On/Off");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetMeanCurv::CallMember( ParamList* p)
{
  int   val = 0;
  int   n  = 0;

  if (!get_int_param( val,   p, n))     ClassHelpAndReturn;
  this->_objectptr->_vtkLevelSets->SetDoMean(val);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetAffineCurv
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetAffineCurv::SetParametersComments() 
{
  ADDPARAMCOMMENT("bool: set Affine curvature On/Off");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetAffineCurv::CallMember( ParamList* p)
{
  int   val = 0;
  int   n  = 0;
  if (!get_int_param( val,   p, n))     ClassHelpAndReturn;
  this->_objectptr->_vtkLevelSets->SetAffineCurvature(val);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCurvWeights
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetCurvWeights::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image of curvature weights (in float format).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetCurvWeights::CallMember( ParamList* p)
{
  InrImage* input;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;
  if (input->GetFormat()==WT_FLOAT) {
    this->_objectptr->_vtkLevelSets->SetCurvatureWeights((float*)(input->GetData()));
  } else
    CLASS_ERROR("Input image is not in float format ...");
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetCurvature
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_GetCurvature::SetParametersComments() 
{
  ADDPARAMCOMMENT("input image (in float) to copy the curvature values.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_GetCurvature::CallMember( ParamList* p)
{
  InrImage* input;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  if (input!=NULL)
    curv->GetCurvatureTerm( (float*) input->Buffer());
  else
    curv->GetCurvatureTerm( NULL);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetVelocity
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetVelocity::SetParametersComments() 
{
  ADDPARAMCOMMENT("Image of velocity.");
  ADDPARAMCOMMENT("Velocity coefficient.");
}


//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetVelocity::CallMember( ParamList* p)
{
  InrImage* input;
  float coeff = 1;
  int n = 0;
  if (!get_val_ptr_param<InrImage>( input,  p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>(        coeff,   p, n))     ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  // need to have it as a member of the class to deal with allocation ..
  this->_objectptr->velocity  = vtk_new<vtkImageData>()((vtkImageData*) (*input));

  curv->Setvelocity(this->_objectptr->velocity.get());
  curv->Setcoeff_velocity(coeff);

  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetVelocity
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_GetVelocity::SetParametersComments() 
{
  ADDPARAMCOMMENT("input image (in float) to copy the velocity values.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_GetVelocity::CallMember( ParamList* p)
{
  InrImage* input;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  if (input!=NULL)
    curv->GetVelocityTerm( (float*) input->Buffer());
  else
    curv->GetVelocityTerm( NULL);

  return BasicVariable::ptr();
}


//---------------------------------------------------
//  SetBalloonScheme
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetBalloonScheme::SetParametersComments() 
{
  ADDPARAMCOMMENT("Sets the expansion scheme (options?)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetBalloonScheme::CallMember( ParamList* p)
{
  int   val = 0;
  int   n  = 0;
  if (!get_int_param( val,   p, n))     ClassHelpAndReturn;
  this->_objectptr->_vtkLevelSets->Setballoon_scheme(val);
  return BasicVariable::ptr();
}



//---------------------------------------------------
//  SetExpansionImage
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetExpansionImage::SetParametersComments() 
{
  ADDPARAMCOMMENT("Sets the expansion force image.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetExpansionImage::CallMember( ParamList* p)
{
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  InrImage* input;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;

  if (input) {
    this->_objectptr->expansion_image  = vtk_new<vtkImageData>()((vtkImageData*) (*input));
    curv->Setballoon_image(this->_objectptr->expansion_image.get());
  } else
    CLASS_ERROR("Input image not allocated ...");
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetExpansion
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetExpansion::SetParametersComments() 
{
  ADDPARAMCOMMENT("Sets the expansion coefficient.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetExpansion::CallMember( ParamList* p)
{
  float coeff = 1;
  int n = 0;
  if (!get_val_param<float>(        coeff,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->Setballoon_coeff(coeff);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetExpansion
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_GetExpansion::SetParametersComments() 
{
  ADDPARAMCOMMENT("input image (in float) to copy the expansion values.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_GetExpansion::CallMember( ParamList* p)
{
  InrImage* input;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  if (input!=NULL)
    curv->GetBalloonTerm( (float*) input->Buffer());
  else
    curv->GetBalloonTerm( NULL);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetProbThreshold
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetProbThreshold::SetParametersComments() 
{
  ADDPARAMCOMMENT("float: set the threshold for the probability (expansion) function, must be in the interval ]0,1[");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetProbThreshold::CallMember( ParamList* p)
{
  float coeff = 1;
  int n = 0;
  if (!get_val_param<float>(        coeff,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  if ((coeff>0)&&(coeff<1))
    curv->SetProbabilityThreshold(coeff);
  else
    CLASS_ERROR("threshold must be in ]0,1[");
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetProbHighTh
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetProbHighTh::SetParametersComments() 
{
  ADDPARAMCOMMENT("High threshold intensity value, intensities higher will have a probability of 1.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetProbHighTh::CallMember( ParamList* p)
{
  float coeff = 1;
  int n = 0;
  if (!get_val_param<float>(        coeff,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->SetProbabilityHighThreshold(coeff);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetNumGaussians
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetNumGaussians::SetParametersComments() 
{
  ADDPARAMCOMMENT("Number of Gaussians used for intensity probability");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetNumGaussians::CallMember( ParamList* p)
{
  int   val = 0;
  int   n  = 0;
  if (!get_int_param( val,   p, n))     ClassHelpAndReturn;
  this->_objectptr->_vtkLevelSets->SetNumGaussians(val);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetGaussian
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetGaussian::SetParametersComments() 
{
  ADDPARAMCOMMENT("Gaussian id");
  ADDPARAMCOMMENT("Gaussian mean");
  ADDPARAMCOMMENT("Gaussian standard deviation");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetGaussian::CallMember( ParamList* p)
{
  int id = 0;
  float mean = 0;
  float std  = 10;
  int n = 0;
  if (!get_int_param(         id,     p, n))     ClassHelpAndReturn;
  if (!get_val_param<float>(  mean,   p, n))     ClassHelpAndReturn;
  if (!get_val_param<float>(  std,    p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->SetGaussian(id,mean,std);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetAdvectionField
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetAdvectionField::SetParametersComments() 
{
  ADDPARAMCOMMENT("X component of the advection field.");
  ADDPARAMCOMMENT("Y component of the advection field.");
  ADDPARAMCOMMENT("Z component of the advection field.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetAdvectionField::CallMember( ParamList* p)
{
  InrImage* input_x;
  InrImage* input_y;
  InrImage* input_z;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input_x,  p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<InrImage>(  input_y,  p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<InrImage>(  input_z,  p, n)) ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);

  if ((input_x->GetFormat()==WT_FLOAT)&&
      (input_y->GetFormat()==WT_FLOAT)&&
      (input_z->GetFormat()==WT_FLOAT)) 
  {
    curv->SetAdvectionVectorField((float*)(input_x->GetData()),
          (float*)(input_y->GetData()),
          (float*)(input_z->GetData()));
  }
  else
    CLASS_ERROR("All images should be in float format.");

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetAdvection
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_GetAdvection::SetParametersComments() 
{
  ADDPARAMCOMMENT("input image (in float) to copy the advection values.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_GetAdvection::CallMember( ParamList* p)
{
  InrImage* input;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  if (input!=NULL)
    curv->GetAdvectionTerm( (float*) input->Buffer());
  else
    curv->GetAdvectionTerm( NULL);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetDistMethod
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetDistMethod::SetParametersComments() 
{
  ADDPARAMCOMMENT("Distance Transform method: value in {0,1,2,3} for:  \
    DISTMAP_CURVES       0 \
    DISTMAP_FASTMARCHING 1 \
    DISTMAP_CHAMFER      2 \
    DISTMAP_SHAPE        3");
}


//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetDistMethod::CallMember( ParamList* p)
{
  int   val = 0;
  int   n  = 0;
  if (!get_int_param( val,   p, n))     ClassHelpAndReturn;
  if ((val>=0)&&(val<=3))
    this->_objectptr->_vtkLevelSets->SetDMmethod( val);
  else
    CLASS_ERROR("Bad value ");
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetBandTube
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetBandTube::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: band size for narrow band.");
  ADDPARAMCOMMENT("integer: tube size for narrow band.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetBandTube::CallMember( ParamList* p)
{
  int   band = 3;
  int   tube = 6;
  int   n  = 0;
  if (!get_int_param( band,   p, n))     ClassHelpAndReturn;
  if (!get_int_param( tube,   p, n))     ClassHelpAndReturn;
  this->_objectptr->_vtkLevelSets->SetBand(band);
  this->_objectptr->_vtkLevelSets->SetTube(tube);
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetDistMap
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_GetDistMap::SetParametersComments() 
{
  ADDPARAMCOMMENT("input image (in float) to copy the distance map to the evolving contour.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_GetDistMap::CallMember( ParamList* p)
{
  InrImage* input;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  if (input!=NULL)
    curv->GetDistanceMap( (float*) input->Buffer());
  else
    curv->GetDistanceMap( NULL);
  return BasicVariable::ptr();

}

//---------------------------------------------------
//  GetSkeleton
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_GetSkeleton::SetParametersComments() 
{
  ADDPARAMCOMMENT("input image (in float) to copy the skeleton (in 2D) to the evolving contour.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_GetSkeleton::CallMember( ParamList* p)
{
  InrImage* input;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);

  vtkImageData* SkeletonImage;
  float* buf2;

  if (input!=NULL) {
    // The images must be in float format
    SkeletonImage = curv->GetSkeletonImage();

    buf2 = (float*) SkeletonImage->GetScalarPointer();
    input->InitBuffer();
    do {
      input->FixeValeur(*buf2);
      buf2++;
    }
    while (input->IncBuffer());
  }

  return BasicVariable::ptr();

}

//---------------------------------------------------
//  SetThreads
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SetThreads::SetParametersComments() 
{
  ADDPARAMCOMMENT("Integer: number of threads (def:1)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SetThreads::CallMember( ParamList* p)
{
  int nbthreads=1;
  int   n  = 0;
  if (!get_int_param( nbthreads,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  if (nbthreads>=1) curv->SetEvolveThreads( nbthreads);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SaveDistMap
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SaveDistMap::SetParametersComments() 
{
  ADDPARAMCOMMENT("bool: activate saving the distance map (def:0).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SaveDistMap::CallMember( ParamList* p)
{
  int   sdm=0;
  int   n  = 0;
  if (!get_int_param( sdm,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->Setsavedistmap(sdm);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SaveSecDerGrad
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_SaveSecDerGrad::SetParametersComments() 
{
  ADDPARAMCOMMENT("bool: activate saving the second order derivatives image (def:0).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_SaveSecDerGrad::CallMember( ParamList* p)
{
  int   save=0;
  int   n  = 0;
  if (!get_int_param( save,   p, n))     ClassHelpAndReturn;
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->Setsavesecdergrad(save);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Iterate
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_Iterate::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_Iterate::CallMember( ParamList* p)
{
  this->_objectptr->_vtkLevelSets->Iterate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  UpdateResult
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_UpdateResult::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_UpdateResult::CallMember( ParamList* p)
{
  this->_objectptr->_vtkLevelSets->UpdateResult();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetOutputImage
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_GetOutputImage::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_GetOutputImage::CallMember( ParamList* p)
{
  InrImage::ptr res(new InrImage(this->_objectptr->image_output.get()));
  return Variable<InrImage>::ptr(new Variable<InrImage>(res));
}


//---------------------------------------------------
//  GetAttachVect
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_GetAttachVect::SetParametersComments() 
{
  ADDPARAMCOMMENT("Input image as an example to create the resulting image.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_GetAttachVect::CallMember( ParamList* p)
{
  InrImage* input;
  int n = 0;
  if (!get_val_ptr_param<InrImage>(  input,  p, n)) ClassHelpAndReturn;

  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);

  InrImage::ptr res;
  float_vec DAx;
  float_vec DAy;
  float_vec DAz;
  int i;

  switch  (curv->Getadvection_scheme()) {
    case ADVECTION_UPWIND_VECTORS:
    case ADVECTION_CENTRAL_VECTORS:
      res = InrImage::ptr(new InrImage(WT_FLOAT,3,"AttachVectors.ami.gz",input));
      curv->GetDataAttach(DAx,DAy,DAz);
      res->InitBuffer();
      i = 0;
      do {
        res->VectFixeValeurs(DAx[i],DAy[i],DAz[i]);
        i++;
      } while (res->IncBuffer());
      break;
    case ADVECTION_MORPHO:
      res = InrImage::ptr(new InrImage(WT_FLOAT,"AttachVectors.ami.gz",input));
      curv->GetDataAttach(DAx,DAy,DAz);
      res->InitBuffer();
      i = 0;
      do {
        res->FixeValeur(DAx[i]);
        i++;
      } while (res->IncBuffer());
      break;
  } // end switch      

  return Variable<InrImage>::ptr(new Variable<InrImage>(res));
}


//---------------------------------------------------
//  End
//---------------------------------------------------
void WrapClass_vtkLevelSets::wrap_End::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkLevelSets::wrap_End::CallMember( ParamList* p)
{
  boost::shared_ptr<vtkLevelSets> curv(this->_objectptr->_vtkLevelSets);
  curv->EndEvolution();
  this->_objectptr->_vtkLevelSets   .reset();
  this->_objectptr->image_input     .reset();
  this->_objectptr->velocity        .reset();
  this->_objectptr->expansion_image .reset();
  this->_objectptr->image_output    .reset();
  this->_objectptr->initimage       .reset();
  return BasicVariable::ptr();
}

