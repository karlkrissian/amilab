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

#include "PDIModule2Plugin.h"
#include "VarContexts.hpp"
#include "ami_object.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts Vars;

#include "addwrap_PDIModule2.h"



PLUGIN_ENTRY_FUNCTION(PDIModule2Plugin);

PDIModule2Plugin::PDIModule2Plugin()
{
  SetName("PDIModule2");
  SetDescription("Several algorithms for analysis of noise in images.");
  SetAuthor("...");
  SetVersion("1.0.0");
}

bool PDIModule2Plugin::Execute(void)
{
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("PDIModule2");

   // wrap_PDIModule2_classes(  amiobject->GetContext());

  // Add wx context to builtin
  // Could be in global with a default context
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

  // Add manually wrapped classes here
    // Putting PDIModule2 and SubVoxel classes here in Algorithms
     wrap_PDIModule2_classes(  amiobject->GetContext());


  // Set as default
  Vars.GetBuiltinContext()->AddDefault(amiobject->GetContext());

  return true;
}
