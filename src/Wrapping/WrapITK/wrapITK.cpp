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
#include "wrapitkBasicNLMeansFilter.h"
#include "wrapitkWrite.h"
#include "wrapitkFastMarchingImageFilter.h"
#include "wrapitkWaterShedImageFilter.h"
#include "wrapitkMultiScaleVesselnessFilter.h"
#include "wrapitkDICOMReadWrite.h"
#include "wrapitkSigmoidImageFilter.h"
#include "wrapitkLevelSet.h"
#include "wrapitkBinaryThresholdImageFilter.h"


extern VarContexts  Vars;

//---------------------------------------------------------
void AddWrapITK(){

 Vars.AddVar(type_c_image_function,"itkRead_3D_US", (void*) itkRead_3D_US);

 Vars.AddVar(type_c_image_function,"itkRead", (void*) wrap_itkRead);

 Vars.AddVar(type_c_image_function,"itkIsoContourDist", (void*) itkIsoContourDist);

 Vars.AddVar(type_c_image_function,"itkBasicNLMeans2D", (void*) itkBasicNLMeans2D);
 Vars.AddVar(type_c_image_function,"itkBasicNLMeans3D", (void*) itkBasicNLMeans3D);
 Vars.AddVar(type_c_image_function,"itkRecursiveGaussianImageFilter2D", (void*) itkRecursiveGaussianImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkRecursiveGaussianImageFilter3D", (void*) itkRecursiveGaussianImageFilter3D);
 Vars.AddVar(type_c_procedure,     "itkWrite"                         , (void*) wrap_itkWrite);
 Vars.AddVar(type_c_image_function,"itkFastMarchingImageFilter2D"     , (void*) itkFastMarchingImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkFastMarchingImageFilter3D"     , (void*) itkFastMarchingImageFilter3D);
 Vars.AddVar(type_c_image_function,"itkWaterShedImageFilter2D"     , (void*) itkWaterShedImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkWaterShedImageFilter3D"     , (void*) itkWaterShedImageFilter3D);
 Vars.AddVar(type_c_image_function,"itkMultiScaleVesselnessFilter2D"     , (void*) itkMultiScaleVesselnessFilter2D);
 Vars.AddVar(type_c_image_function,"itkMultiScaleVesselnessFilter3D"     , (void*) itkMultiScaleVesselnessFilter3D);
 Vars.AddVar(type_c_procedure,     "itkDICOMReadWrite"                         , (void*) itkDICOMReadWrite);
 Vars.AddVar(type_c_image_function,"itkSigmoidImageFilter2D"     , (void*) itkSigmoidImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkSigmoidImageFilter3D"     , (void*) itkSigmoidImageFilter3D);
 Vars.AddVar(type_c_image_function,"itkLevelSetFilter2D"     , (void*) itkLevelSetFilter2D);
 Vars.AddVar(type_c_image_function,"itkLevelSetFilter3D"     , (void*) itkLevelSetFilter3D);
 Vars.AddVar(type_c_image_function,"itkBinaryThresholdImageFilter2D"     , (void*) itkBinaryThresholdImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkBinaryThresholdImageFilter3D"     , (void*) itkBinaryThresholdImageFilter3D);
}
