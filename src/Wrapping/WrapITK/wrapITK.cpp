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
  AMIObject* amiobject = new AMIObject;
  amiobject->SetName("itk");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  Vars.AddVar(type_c_image_function,"Read_3D_US", (void*) itkRead_3D_US, OBJECT_CONTEXT_NUMBER);
  
  Vars.AddVar(type_c_image_function,"Read", (void*) wrap_itkRead, OBJECT_CONTEXT_NUMBER);
  
  Vars.AddVar(type_c_image_function,"IsoContourDist", (void*) itkIsoContourDist, OBJECT_CONTEXT_NUMBER);
  
  // Vars.AddVar(type_c_image_function,"BasicNLMeans2D", (void*) itkBasicNLMeans2D, OBJECT_CONTEXT_NUMBER);
  // Vars.AddVar(type_c_image_function,"BasicNLMeans3D", (void*) itkBasicNLMeans3D, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_image_function,"RecursiveGaussianImageFilter2D", (void*) itkRecursiveGaussianImageFilter2D, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_image_function,"RecursiveGaussianImageFilter3D", (void*) itkRecursiveGaussianImageFilter3D, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_procedure,     "Write"                         , (void*) wrap_itkWrite, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_image_function,"FastMarchingImageFilter2D"     , (void*) itkFastMarchingImageFilter2D, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_image_function,"FastMarchingImageFilter3D"     , (void*) itkFastMarchingImageFilter3D, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_image_function,"WaterShedImageFilter2D"     , (void*) itkWaterShedImageFilter2D, OBJECT_CONTEXT_NUMBER);
  Vars.AddVar(type_c_image_function,"WaterShedImageFilter3D"     , (void*) itkWaterShedImageFilter3D, OBJECT_CONTEXT_NUMBER);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // Add the new object (namespace)
  Vars.AddVar( type_ami_object, amiobject->GetName().c_str(), (void*) amiobject);
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
