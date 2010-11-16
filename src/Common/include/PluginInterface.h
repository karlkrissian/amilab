//
// C++ Interface: PluginInterface
//
// Description: Define the plugin interface.
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#ifdef WIN32
#   define WX_AMILAB_EXPORT WXEXPORT
#else
#   define WX_AMILAB_EXPORT
#endif

#ifdef WIN32
#   if defined (_MSC_VER) || defined (__BORLANDC__)
#      define PLUGIN_AMILAB_DLLEXPORT __declspec( dllexport )
#   else
#      error "don't know how export functions from DLL with this compiler"
#   endif
#else
#   define PLUGIN_AMILAB_DLLEXPORT 
#endif

//--------------------------------------------------
// includes for wxWidgets
//--------------------------------------------------
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "DefineClass.hpp"

/**
 * @brief Class that contains the protocol of communication.
 **/
class WX_AMILAB_EXPORT PluginBase : public wxObject
{
  public:
    /**
     * @brief Get the plugin name.
     *
     * @return return a wxString with the plugin name
     **/
    virtual const wxString & GetName(void) const = 0;

    /**
     * @brief Get the plugin description.
     *
     * @return return a wxString with the plugin description
     **/
    virtual const wxString & GetDescription(void) const = 0;

    /**
     * @brief Get the plugin version.
     *
     * @return return a wxString with the plugin version
     **/
    virtual const wxString & GetVersion(void) const = 0;

    /**
     * @brief Get the plugin author.
     *
     * @return return a wxString with the plugin author
     **/
    virtual const wxString & GetAuthor(void) const = 0;

    /**
     * @brief Get the plugin status.
     *
     * @return return a wxString with the plugin status
     **/
    virtual const wxString & GetStatus(void) const = 0;

    /**
     * @brief Get the plugin path.
     *
     * @return return a wxString with the plugin path
     **/
    virtual const wxString & GetPath(void) const = 0;

    /**
     * @brief Set the plugin Path.
     *
     * @param Path The absolute path of the PLUGIN
     **/       
     virtual void SetPath( const wxString& Path ) = 0;

    /**
     * @brief Set the plugin status.
     *
     * @param MyStatus Indicates if the plugin this one activated
     **/
    virtual void SetStatus( const wxString& MyStatus) = 0;

    /**
     * @brief Execute the plugin.
     *
     * @return return true if the plugin executes correctly
     **/
    virtual bool Execute (void) const = 0;
}; // PluginBase


/**
 * @brief Class that contains the protocol of communication.
 **/
class WX_AMILAB_EXPORT WX_Plugin : public PluginBase
{
  public:
    /**
     * @brief  Get the wxWindow of the plugin.
     *
     * @return return a wxString with the plugin path
     **/
    virtual wxWindow* GetwxWindow(void) const = 0;

    /**
     * @brief Set the wxWindow of the plugin.
     *
     * @param Parent The wxWindow of the plugin
     **/
     virtual void SetwxWindow( wxWindow *Parent ) = 0;

}; // WX_Plugin

//IMPLEMENT_ABSTRACT_CLASS(PluginInterface, wxObject)

/** @name This is the API that each AMILAB shared lib must implement. */
//@{
extern "C"
{
   /**
    Each module DLL must implement a function CreatePlugin of this
    type which will be called to initialise it. That function must
    return the new object representing this module.
   */  
  typedef PluginBase* ( *CreatePlugin_BASE_function)();
  typedef WX_Plugin* ( *CreatePlugin_WX_function)();

}
//@}

// ----------------------------------------------------------------------------
// macros for module declaration/implementation.
//
// This macros must be used inside the class declaration for any module class.
// ----------------------------------------------------------------------------

#define PLUGIN_BASE_DEFINE() \
public: \
  virtual const wxString & GetName(void) const; \
  virtual const wxString & GetDescription(void) const; \
  virtual const wxString & GetVersion(void) const; \
  virtual const wxString & GetAuthor(void) const; \
  virtual const wxString & GetStatus(void) const = 0; \
  virtual const wxString & GetPath(void) const = 0; \
  virtual void SetPath( const wxString& Path ) = 0; \
  virtual void SetStatus( const wxString& MyStatus) = 0; \
  virtual bool Execute (void) const = 0;

#define PLUGIN_WX_DEFINE() \
  PLUGIN_BASE_DEFINE(); \
  virtual wxWindow* GetwxWindow(void) const = 0; \
  virtual void SetwxWindow( wxWindow *Parent ) = 0;

#define PLUGIN_BASE_ENTRY_FUNCTION(name) \
extern "C" PLUGIN_AMILAB_DLLEXPORT PluginBase* CreatePlugin() \
{ \
  return new name(); \
};

#define PLUGIN_WX_ENTRY_FUNCTION(name) \
extern "C" PLUGIN_AMILAB_DLLEXPORT WX_Plugin* CreatePlugin() \
{ \
  return new name(); \
};
#endif // PLUGININTERFACE_H