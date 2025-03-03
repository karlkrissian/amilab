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

#ifndef wxPluginManager_H
#define wxPluginManager_H

#include "CommonConfigure.h"
#include "wxPluginBase.h"

#include <wx/dynlib.h>
#include "DefineClass.hpp"

/**
 * @brief Class that manages the life-cycle of the plugins.
 **/
class COMMON_EXPORT wxPluginManager
{
  DEFINE_CLASS(wxPluginManager);
public:

  /// Destructor
  ~wxPluginManager();
  
  /**
   * @brief Load the library with the given name (full or not), return true if ok.
   *
   * @param LibName the library name
   * @return return true if load library with the given name
   **/
  bool Load (const char * LibName);

  /**
   * @brief Detaches this object from its library handle.
   *
   * Forces that the library is unloaded manually by the method UnLoad().
   **/
  void Detach (void);

  /**
   * @brief Unloads the library from memory.
   *
   * Works when previously the Detach method has been invoked.
   **/  
  bool Unload (void);

  /**
   * @brief Gets the plugin handler.
   *
   * @return return the plugin handler
   **/
  boost::shared_ptr<wxPluginBase> Getplugin() { return m_plugin;}
  
  wxDynamicLibrary& Getdll() { return m_dll; }
  

private:
  wxDllType         m_Detach; // Library handle
  wxDynamicLibrary  m_dll;    // Library manager.
  boost::shared_ptr<wxPluginBase>     m_plugin; // Plugin handle.

}; // wxPluginManager

#endif // wxPluginManager_H