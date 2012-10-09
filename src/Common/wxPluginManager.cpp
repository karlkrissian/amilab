//
// C++ Interface: wxPluginManager
//
// Description: It manages the life-cycle of the plugins.
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//

#include "wxPluginManager.h"
//#include <iostream>

//=======================================================
wxPluginManager::~wxPluginManager()
{
  //std::cout << "~wxPluginManager::wxPluginManager()" << std::endl;
  //m_plugin->Destroy();
  m_plugin.reset();
  Unload();
}

  
//=======================================================
bool wxPluginManager::Load (const char* LibName)
{
  m_dll.Load(wxString(LibName, wxConvUTF8));
  if(m_dll.IsLoaded())
  {
    //Create a valid function pointer using the function pointer type in PluginBase.h
    wxDYNLIB_FUNCTION(CreatePlugin_function,CreatePlugin,m_dll);
    //check if the function is found
    if(pfnCreatePlugin)
    {
      //Create the plugin
      m_plugin = boost::shared_ptr<wxPluginBase>(pfnCreatePlugin());
      return true;
    }
  }
  return false;
} //LoadPlugins definition.

//=======================================================
void wxPluginManager::Detach (void)
{
  if(m_dll.IsLoaded())
    m_Detach = m_dll.Detach();
} //Detach definition.

//=======================================================
bool wxPluginManager::Unload (void)
{
  if(m_dll.IsLoaded()) {
    //m_Detach = m_dll.Detach();
    //m_dll.Unload(m_Detach);
    m_dll.Unload();
    return true;
  }
  return false;
} //Unload definition.

