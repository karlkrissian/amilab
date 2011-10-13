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

#include "ImageProcessingPlugin.h"
#include "VarContexts.hpp"
#include "ami_object.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts Vars;

#include "addwrap_ImageProcessing.h"

PLUGIN_ENTRY_FUNCTION(ImageProcessingPlugin);

ImageProcessingPlugin::ImageProcessingPlugin()
{
  SetName("ImageProcessing");
  SetDescription("Several algorithms for image processing.");
  SetAuthor("Karl Krissian");
  SetVersion("1.0.0");
}

bool ImageProcessingPlugin::Execute(void)
{
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("ImageProcessing");

    wrap_ImageProcessing_classes(  amiobject->GetContext());

  // Add wx context to builtin
  // Could be in global with a default context
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

  // Set as default
  Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());

  return true;
}
