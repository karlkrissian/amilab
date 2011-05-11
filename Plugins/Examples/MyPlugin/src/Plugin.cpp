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

#include "Plugin.h"
#include "VarContexts.hpp"

extern VarContexts  Vars;

PLUGIN_ENTRY_FUNCTION(Plugin);

Plugin::Plugin()
{
  SetName("Plugin");
  SetDescription("Plugin of ExamplePlugin class.");
  SetAuthor("xXx");
  SetVersion("x.y.z");
}

bool Plugin::Execute(void)
{
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("plugins");

  // Add classes to plugin context
  WrapClassExamplePlugin_AddStaticMethods(amiobject->GetContext());

  WrapClassFoo__LT__int__COMMA____SPACE__10__GT___AddStaticMethods( amiobject->GetContext() );

  WrapClassFoo2__LT__int__COMMA____SPACE__float__COMMA____SPACE__bool__GT___AddStaticMethods( amiobject->GetContext() );

  // Add wx context to builtin
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

  return true;
}
