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
  SetVersion("1.0.0");
}

bool vtkAmiVolRenPlugin::Execute(void)
{
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkAmiVolRen");

    wrap_vtkAmiVolRen_classes(  amiobject->GetContext());

  // Add wx context to builtin
  // Could be in global with a default context
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

  return true;
}
