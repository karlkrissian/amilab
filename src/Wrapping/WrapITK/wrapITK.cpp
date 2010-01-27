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


extern VarContexts  Vars;

//---------------------------------------------------------
void AddWrapITK(){

 Vars.AddVar(type_c_image_function,"itkRead_3D_US", (void*) wrap_itkRead_3D_US);

 Vars.AddVar(type_c_image_function,"itkRead", (void*) wrap_itkRead);

 Vars.AddVar(type_c_image_function,"itkIsoContourDist", (void*) wrap_itkIsoContourDist);

 Vars.AddVar(type_c_image_function,"itkBasicNLMeans2D", (void*) wrap_itkBasicNLMeans2D);
 Vars.AddVar(type_c_image_function,"itkBasicNLMeans3D", (void*) wrap_itkBasicNLMeans3D);
 Vars.AddVar(type_c_image_function,"itkRecursiveGaussianImageFilter2D", (void*) wrap_itkRecursiveGaussianImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkRecursiveGaussianImageFilter3D", (void*) wrap_itkRecursiveGaussianImageFilter3D);
 Vars.AddVar(type_c_procedure,     "itkWrite"                         , (void*) wrap_itkWrite);
 Vars.AddVar(type_c_image_function,"itkFastMarchingImageFilter2D"     , (void*) wrap_itkFastMarchingImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkFastMarchingImageFilter3D"     , (void*) wrap_itkFastMarchingImageFilter3D);
 Vars.AddVar(type_c_image_function,"itkWaterShedImageFilter2D"     , (void*) wrap_itkWaterShedImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkWaterShedImageFilter3D"     , (void*) wrap_itkWaterShedImageFilter3D);
 Vars.AddVar(type_c_image_function,"itkMultiScaleVesselnessFilter2D"     , (void*) wrap_itkMultiScaleVesselnessFilter2D);
 Vars.AddVar(type_c_image_function,"itkMultiScaleVesselnessFilter3D"     , (void*) wrap_itkMultiScaleVesselnessFilter3D);
 Vars.AddVar(type_c_procedure,     "itkDICOMReadWrite"                         , (void*) wrap_itkDICOMReadWrite);
 Vars.AddVar(type_c_image_function,"itkSigmoidImageFilter2D"     , (void*) wrap_itkSigmoidImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkSigmoidImageFilter3D"     , (void*) wrap_itkSigmoidImageFilter3D);
 Vars.AddVar(type_c_image_function,"itkLevelSetFilter2D"     , (void*) wrap_itkLevelSetFilter2D);
 Vars.AddVar(type_c_image_function,"itkLevelSetFilter3D"     , (void*) wrap_itkLevelSetFilter3D);
 Vars.AddVar(type_c_image_function,"itkBinaryThresholdImageFilter2D"     , (void*) wrap_itkBinaryThresholdImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkBinaryThresholdImageFilter3D"     , (void*) wrap_itkBinaryThresholdImageFilter3D);
}
