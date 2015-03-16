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

#include "itkRecGaussPlugin.h"
#include "VarContexts.hpp"
#include "ami_object.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts Vars;

#include "addwrap_itkRecGauss.h"



PLUGIN_ENTRY_FUNCTION(itkRecGaussPlugin);

itkRecGaussPlugin::itkRecGaussPlugin()
{
  SetName("itkRecGauss");
  SetDescription("Several algorithms for analysis of noise in images.");
  SetAuthor("...");
  SetVersion("1.0.0");
}

bool itkRecGaussPlugin::Execute(void)
{
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("itkRecGauss");

   // wrap_itkRecGauss_classes(  amiobject->GetContext());

  // Add wx context to builtin
  // Could be in global with a default context
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

  // Add manually wrapped classes here
    // Putting itkRecGauss and SubVoxel classes here in Algorithms
     wrap_itkRecGauss_classes(  amiobject->GetContext());


  // Set as default
  Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());

  return true;
}

void itkRecGaussPlugin::Destroy()
{
  Vars.GetBuiltinContext()->deleteVar(this->GetName().c_str());
}
