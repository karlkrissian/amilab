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

#include "wrapfunctions.hpp"
#include "UltrasonixPlugin.h"
#include "VarContexts.hpp"
#include "ami_object.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts Vars;

#include "addwrap_Ultrasonix.h"


PLUGIN_ENTRY_FUNCTION(UltrasonixPlugin);

UltrasonixPlugin::UltrasonixPlugin()
{
  SetName("Ultrasonix");
  SetDescription("Ultrasonix API wrapping.");
  SetAuthor("...");
  SetVersion("1.0.0");
}

bool UltrasonixPlugin::Execute(void)
{
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("Ultrasonix");

   // wrap_Ultrasonix_classes(  amiobject->GetContext());

  // Add wx context to builtin
  // Could be in global with a default context
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

    // Putting Ultrasonix classes here
     wrap_Ultrasonix_classes(  amiobject->GetContext());


  // Set as default
  Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());

  return true;
}
