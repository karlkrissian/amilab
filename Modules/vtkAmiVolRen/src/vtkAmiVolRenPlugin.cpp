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

#include "vtkAmiVolRenPlugin.h"
#include "VarContexts.hpp"
#include "ami_object.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts Vars;

#include "addwrap_vtkAmiVolRen.h"

PLUGIN_ENTRY_FUNCTION(vtkAmiVolRenPlugin);

vtkAmiVolRenPlugin::vtkAmiVolRenPlugin()
{
  SetName("vtkAmiVolRen");
  SetDescription("Plugin of ExamplePlugin class.");
  SetAuthor("Karl Krissian");
  SetVersion("1.2.0");
}

bool vtkAmiVolRenPlugin::Execute(void)
{
  std::cout << "vtkAmiVolRenPlugin::Execute() " << GetVersion() << std::endl;
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName(this->GetName().c_str());

    wrap_vtkAmiVolRen_classes(  amiobject->GetContext());

  // Add wx context to builtin
  // Could be in global with a default context
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

  return true;
}


void vtkAmiVolRenPlugin::Destroy()
{
  std::cout << "vtkAmiVolRenPlugin::Destroy()" << std::endl;
  Vars.GetBuiltinContext()->deleteVar(this->GetName().c_str());
}
