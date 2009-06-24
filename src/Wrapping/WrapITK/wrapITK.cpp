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



#include "VarContexts.hpp"
#include "wrapfunctions.hpp" 
#include "wrapITK.h"

extern VarContexts  Vars;

//---------------------------------------------------------
void AddWrapITK(){
 Vars.AddVar(type_c_image_function,"itkRead_3D_US",     (void*) itkRead_3D_US);
 Vars.AddVar(type_c_image_function,"itkRead",     (void*) itkRead);
 Vars.AddVar(type_c_image_function,"itkIsoContourDist", (void*) itkIsoContourDist);
 //Vars.AddVar(type_c_image_function,"itkBasicNLMeans2D", (void*) itkBasicNLMeans2D);
 //Vars.AddVar(type_c_image_function,"itkBasicNLMeans3D", (void*) itkBasicNLMeans3D);
 Vars.AddVar(type_c_image_function,"itkRecursiveGaussianImageFilter2D", (void*) itkRecursiveGaussianImageFilter2D);
 Vars.AddVar(type_c_image_function,"itkRecursiveGaussianImageFilter3D", (void*) itkRecursiveGaussianImageFilter3D);
}

