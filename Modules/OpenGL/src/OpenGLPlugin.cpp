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

#include "OpenGLPlugin.h"
#include "VarContexts.hpp"
#include "ami_object.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts Vars;

#include "addwrap_OpenGL.h"

PLUGIN_ENTRY_FUNCTION(OpenGLPlugin);

OpenGLPlugin::OpenGLPlugin()
{
  SetName("OpenGL");
  SetDescription("Several algorithms for image processing.");
  SetAuthor("Karl Krissian");
  SetVersion("1.0.0");
}

bool OpenGLPlugin::Execute(void)
{
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("OpenGL");

    wrap_OpenGL_classes  (  amiobject->GetContext());
    wrap_OpenGL_functions(  amiobject->GetContext());

  // Add wx context to builtin
  // Could be in global with a default context
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

  // Set as default
  Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());

  return true;
}
