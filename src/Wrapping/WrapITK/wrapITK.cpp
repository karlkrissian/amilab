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
#include "wrapitkDICOMRead.h"
#include "wrapitkSigmoidImageFilter.h"
#include "wrapitkLevelSet.h"
#include "wrapitkBinaryThresholdImageFilter.h"
#include "wrapitkBackTrackingMeshFilter.h"
#include "wrapitkTranslateImageFilter.h"
#include "wrapitkLocalMeanImageFilter.h"

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

  ADDOBJECTVAR_NAME(C_wrap_procedure,     "Write",                          wrap_itkWrite);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "WaterShedImageFilter2D",         wrap_itkWaterShedImageFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "WaterShedImageFilter3D",         wrap_itkWaterShedImageFilter3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "SigmoidImageFilter2D",           wrap_itkSigmoidImageFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "SigmoidImageFilter3D",           wrap_itkSigmoidImageFilter3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "Read_3D_US",                     wrap_itkRead_3D_US);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "Read",                           wrap_itkRead);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "RecursiveGaussianImageFilter2D", wrap_itkRecursiveGaussianImageFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "RecursiveGaussianImageFilter3D", wrap_itkRecursiveGaussianImageFilter3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "MultiScaleVesselnessFilter2D",   wrap_itkMultiScaleVesselnessFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "MultiScaleVesselnessFilter3D",   wrap_itkMultiScaleVesselnessFilter3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "LevelSetFilter2D",               wrap_itkLevelSetFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "LevelSetFilter3D",               wrap_itkLevelSetFilter3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "IsoContourDist2D",               wrap_itkIsoContourDist2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "IsoContourDist3D",               wrap_itkIsoContourDist3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "FastMarchingImageFilter2D",      wrap_itkFastMarchingImageFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "FastMarchingImageFilter3D",      wrap_itkFastMarchingImageFilter3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "DICOMRead",                      wrap_itkDICOMRead);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "BinaryThresholdImageFilter2D",   wrap_itkBinaryThresholdImageFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "BinaryThresholdImageFilter3D",   wrap_itkBinaryThresholdImageFilter3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "BasicNLMeans2D",                 wrap_itkBasicNLMeans2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "BasicNLMeans3D",                 wrap_itkBasicNLMeans3D);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,   "BackTrackingMeshFilter2D",       wrap_itkBackTrackingMeshFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,   "BackTrackingMeshFilter3D",       wrap_itkBackTrackingMeshFilter3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "LocalMeanImageFilter2D",         wrap_itkLocalMeanImageFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "LocalMeanImageFilter3D",         wrap_itkLocalMeanImageFilter3D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "TranslateImageFilter2D",         wrap_itkTranslateImageFilter2D);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction, "TranslateImageFilter3D",         wrap_itkTranslateImageFilter3D);

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
