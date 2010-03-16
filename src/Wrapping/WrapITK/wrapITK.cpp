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

#include "AMILabConfig.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapITK.h"
#include "wrapitkRead_3D_US.h"
#include "wrapitkRead.h"
#include "wrapitkRecursiveGaussianImageFilter.h"
#include "wrapitkIsoContourDist.h"
#include "wrapitkBasicNLMeansFilter.h"
#include "wrapitkWrite.h"
#include "wrapitkFastMarchingImageFilter.h"
#include "wrapitkWaterShedImageFilter.h"
#include "wrapitkMultiScaleVesselnessFilter.h"
#include "wrapitkDICOMReadWrite.h"
#include "wrapitkSigmoidImageFilter.h"
#include "wrapitkLevelSet.h"
#include "wrapitkBinaryThresholdImageFilter.h"
#include "wrapitkBackTrackingMeshFilter.h"
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

  Vars.AddVar(type_c_image_function,"Read_3D_US", (void*) wrap_itkRead_3D_US, OBJECT_CONTEXT_NUMBER);
  
  Vars.AddVar(type_c_image_function,"Read", (void*) wrap_itkRead, OBJECT_CONTEXT_NUMBER);
  
  Vars.AddVar(type_c_image_function,"IsoContourDist", (void*) wrap_itkIsoContourDist, OBJECT_CONTEXT_NUMBER);
  

 Vars.AddVar(type_c_image_function,"BasicNLMeans2D", (void*) wrap_itkBasicNLMeans2D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"BasicNLMeans3D", (void*) wrap_itkBasicNLMeans3D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"RecursiveGaussianImageFilter2D", (void*) wrap_itkRecursiveGaussianImageFilter2D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"RecursiveGaussianImageFilter3D", (void*) wrap_itkRecursiveGaussianImageFilter3D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_procedure,     "Write"                         , (void*) wrap_itkWrite, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"FastMarchingImageFilter2D"     , (void*) wrap_itkFastMarchingImageFilter2D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"FastMarchingImageFilter3D"     , (void*) wrap_itkFastMarchingImageFilter3D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"WaterShedImageFilter2D"     , (void*) wrap_itkWaterShedImageFilter2D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"WaterShedImageFilter3D"     , (void*) wrap_itkWaterShedImageFilter3D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"MultiScaleVesselnessFilter2D"     , (void*) wrap_itkMultiScaleVesselnessFilter2D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"MultiScaleVesselnessFilter3D"     , (void*) wrap_itkMultiScaleVesselnessFilter3D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,     "DICOMRead"                         , (void*) wrap_itkDICOMRead, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"SigmoidImageFilter2D"     , (void*) wrap_itkSigmoidImageFilter2D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"SigmoidImageFilter3D"     , (void*) wrap_itkSigmoidImageFilter3D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"LevelSetFilter2D"     , (void*) wrap_itkLevelSetFilter2D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"LevelSetFilter3D"     , (void*) wrap_itkLevelSetFilter3D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"BinaryThresholdImageFilter2D"     , (void*) wrap_itkBinaryThresholdImageFilter2D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_image_function,"BinaryThresholdImageFilter3D"     , (void*) wrap_itkBinaryThresholdImageFilter3D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_function,"BackTrackingMeshFilter2D"     , (void*) wrap_itkBackTrackingMeshFilter2D, OBJECT_CONTEXT_NUMBER);
 Vars.AddVar(type_c_function,"BackTrackingMeshFilter3D"     , (void*) wrap_itkBackTrackingMeshFilter3D, OBJECT_CONTEXT_NUMBER);

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
