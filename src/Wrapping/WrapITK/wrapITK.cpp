//
// C++ Implementation: wrapAMIFluid
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//



// #ifdef AMI_USE_ITK

// #include "itkImageLinearConstIteratorWithIndex.h"
// #include "itkImageLinearIteratorWithIndex.h"
// #include "itkImage.h"
// #include "itkImageIOBase.h"
// #include "itkIsoContourDistanceImageFilter.h"
// #include "itkBasicNLMeansFilter.h"
// #include "itkRecursiveGaussianImageFilter.h"
// #include "itkFastMarchingImageFilter.h"

// //using namespace itk;

// #include "itkImageFileReader.h"

// #endif // AMI_USE_ITK


#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapITK.h"
#include "wrapitkRead_3D_US.h"
#include "wrapitkRead.h"
#include "wrapitkRecursiveGaussianImageFilter.h"
#include "wrapitkIsoContourDist.h"
//#include "wrapitkBasicNLMeansFilter.h"
#include "wrapitkWrite.h"
#include "wrapitkFastMarchingImageFilter.h"
#include "wrapitkWaterShedImageFilter.h"
#include "ami_object.h"


extern VarContexts  Vars;

//---------------------------------------------------------
void AddWrapITK(){

  // Create new instance of the class
  AMIObject::ptr amiobject (new AMIObject);
  amiobject->SetName("itk");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  ADDOBJECTVAR_IMFUNC_NAME("Read_3D_US", 
                           itkRead_3D_US);
  
  ADDOBJECTVAR_IMFUNC_NAME( "Read",
                            wrap_itkRead);
  
  ADDOBJECTVAR_IMFUNC_NAME( "IsoContourDist",
                            itkIsoContourDist);
  
  // Vars.AddVar(type_c_image_function,"BasicNLMeans2D", (void*) itkBasicNLMeans2D, OBJECT_CONTEXT_NUMBER);
  // Vars.AddVar(type_c_image_function,"BasicNLMeans3D", (void*) itkBasicNLMeans3D, OBJECT_CONTEXT_NUMBER);
  ADDOBJECTVAR_PROC_NAME("Write", wrap_itkWrite);

  ADDOBJECTVAR_IMFUNC_NAME( "RecursiveGaussianImageFilter2D",
                            itkRecursiveGaussianImageFilter2D);
  ADDOBJECTVAR_IMFUNC_NAME( "RecursiveGaussianImageFilter3D",
                            itkRecursiveGaussianImageFilter3D);
  ADDOBJECTVAR_IMFUNC_NAME( "FastMarchingImageFilter2D",
                            itkFastMarchingImageFilter2D);
  ADDOBJECTVAR_IMFUNC_NAME( "FastMarchingImageFilter3D",
                            itkFastMarchingImageFilter3D);
  ADDOBJECTVAR_IMFUNC_NAME( "WaterShedImageFilter2D",
                            itkWaterShedImageFilter2D);
  ADDOBJECTVAR_IMFUNC_NAME( "WaterShedImageFilter3D",
                            itkWaterShedImageFilter3D);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // Add the new object (namespace)
  Vars.AddVar<AMIObject>(amiobject->GetName().c_str(), amiobject);
}


/**
 * Adds the ITK wrapping
 * @param p 
 */
void wrap_ITK( ParamList* p)
{
    char functionname[] = "ITK";
    char description[]=" \n\
      Adds wrapping for ITK. \n\
            ";
    char parameters[] =" \n\
            ";

  AddWrapITK();
}
