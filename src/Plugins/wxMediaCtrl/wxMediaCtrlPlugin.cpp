//
// C++ Interface: wxMediaCtrlPlugin
//
// Description:  A plugin that wrapper the wxMediaCtrl class of wxWidgets 2.8
//               version and adds it in AMILAB.
//
//
// Author: xXx <xXX>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//

#include "wxMediaCtrlPlugin.h"
#include "VarContexts.hpp"

extern VarContexts  Vars;

PLUGIN_ENTRY_FUNCTION(wxMediaCtrlPlugin);

wxMediaCtrlPlugin::wxMediaCtrlPlugin()
{
  SetName("wxMediaCtrl");
  SetDescription("A plugin that wrapper the wxMediaCtrl class of wxWidgets 2.8 version and adds it in AMILAB.");
  SetAuthor("xXx");
  SetVersion("0.0.1");
}

bool wxMediaCtrlPlugin::Execute(void)
{
  // Create a new context (or namespace)
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("plugins");

  // Add classes to wx context
  WrapClasswxMediaCtrl_AddStaticMethods(amiobject->GetContext());

  // Add wx context to builtin
  Vars.GetBuiltinContext()->AddVar<AMIObject>( amiobject->GetName().c_str(),
      amiobject,Vars.GetBuiltinContext());  

  return true;
}
