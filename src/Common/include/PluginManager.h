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

#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "PluginInterface.h"

#include <wx/dynlib.h>
#include "DefineClass.hpp"

/**
 * @brief Class that manages the life-cycle of the plugins.
 **/
class PluginManager
{
  DEFINE_CLASS(PluginManager);
public:
  /** Constructor. */
  PluginManager()
  {
    //TODO
  }; //Constructor definition.

  /** Destructor. */
  virtual ~PluginManager()
  {
    //TODO
  }; //Destructor definition.

  /**
   * @brief Load the library with the given name (full or not), return true if ok.
   *
   * @param LibName the library name
   * @return return true if load library with the given name
   **/
  bool LoadPlugins (const wxString& LibName);

  /**
   * @brief Gets the plugin handler.
   *
   * @return return the plugin handler
   **/
  PluginInterface* GetPluginHandle () { return m_plugin; };

private:
  wxDynamicLibrary  m_dll;     // DLL handle.
  PluginInterface*  m_plugin;  // Plugin handle.

}; // PluginManager

#endif // PLUGINMANAGER_H