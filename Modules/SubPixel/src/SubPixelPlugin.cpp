//
// C++ File:Plugin.cpp
//
// Description: A plugin example.
//
//
// Author: Author: xXx <xXx@xXx.com>, (C) YYYY
//
// Copyright: See COPYING file that comes with this distribution
//

#include "SubPixelPlugin.h"
#include "VarContexts.hpp"
#include "ami_object.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts Vars;

//#include "addwrap_SubPixel.h"

// include SubPixel and SubVoxel wrapped classes
#include "wrap_AnalyticFunctionBase.h"
#include "wrap_AnalyticLine.h"
#include "wrap_AnalyticCircle.h"
#include "wrap_AnalyticStraightVessel2D.h"
#include "wrap_AnalyticRing2D.h"
#include "wrap_AnalyticPlane.h"
#include "wrap_AnalyticCube.h"
#include "wrap_AnalyticCylinder.h"
#include "wrap_AnalyticSphere.h"
#include "wrap_AnalyticTorus.h"
#include "wrap_AnalyticHelix.h"
#include "wrap_ComputePartialVolume.h"
#include "wrap_SubPixel2D.h"
#include "wrap_SubVoxel3D.h"


PLUGIN_ENTRY_FUNCTION(SubPixelPlugin);

SubPixelPlugin::SubPixelPlugin()
{
  SetName("SubPixel");
  SetDescription("Several algorithms for analysis of noise in images.");
  SetAuthor("...");
  SetVersion("1.0.0");
}

bool SubPixelPlugin::Execute(void)
{
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName(this->GetName());

   // wrap_SubPixel_classes(  amiobject->GetContext());

  // Add wx context to builtin
  // Could be in global with a default context
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

  // Add manually wrapped classes here
    // Putting SubPixel and SubVoxel classes here in Algorithms
    WrapClass_AnalyticFunctionBase    ::AddVar_AnalyticFunctionBase(      
      amiobject->GetContext());
    WrapClass_AnalyticCircle          ::AddVar_AnalyticCircle(            
      amiobject->GetContext());
    WrapClass_AnalyticLine            ::AddVar_AnalyticLine(              
      amiobject->GetContext());
    WrapClass_AnalyticStraightVessel2D::AddVar_AnalyticStraightVessel2D(  
      amiobject->GetContext());
    WrapClass_AnalyticRing2D          ::AddVar_AnalyticRing2D(
      amiobject->GetContext());
    WrapClass_AnalyticPlane           ::AddVar_AnalyticPlane(
      amiobject->GetContext());
    WrapClass_AnalyticCube            ::AddVar_AnalyticCube(
      amiobject->GetContext());
    WrapClass_AnalyticCylinder        ::AddVar_AnalyticCylinder(
      amiobject->GetContext());
    WrapClass_AnalyticSphere          ::AddVar_AnalyticSphere(
      amiobject->GetContext());
    WrapClass_AnalyticTorus           ::AddVar_AnalyticTorus(
      amiobject->GetContext());
    WrapClass_AnalyticHelix           ::AddVar_AnalyticHelix(
      amiobject->GetContext());
    WrapClass_ComputePartialVolume    :: AddVar_ComputePartialVolume(
      amiobject->GetContext());
    WrapClass_SubPixel2D              ::AddVar_SubPixel2D(
      amiobject->GetContext());
    WrapClass_SubVoxel3D              ::AddVar_SubVoxel3D(
      amiobject->GetContext());
  
  // Set as default
  Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());

  return true;
}


void SubPixelPlugin::Destroy()
{
  std::cout << "SubPixelPlugin::Destroy()" << std::endl;
  Vars.GetBuiltinContext()->deleteVar(this->GetName().c_str());
}