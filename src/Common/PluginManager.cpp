//
// C++ Interface: PluginManager
//
// Description: It manages the life-cycle of the plugins.
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//

#include "PluginManager.h"

//=======================================================

bool PluginManager::LoadPlugins (const wxString& LibName)
{
  m_dll.Load(LibName);
  if(m_dll.IsLoaded())
  {
    //Create a valid function pointer using the function pointer type in PluginInterface.h
    wxDYNLIB_FUNCTION(CreatePlugin_function,CreatePlugin,m_dll);
    //check if the function is found
    if(pfnCreatePlugin)
    {
      //Important: Use Detach(), otherwise the DLL will be unloaded once the wxDynamibLibrary object
      //goes out of scope
      m_dll.Detach();
      //Create the plugin
      m_plugin = pfnCreatePlugin();
      return true;
    }
  }
  return false;
} //LoadPlugins definition.

