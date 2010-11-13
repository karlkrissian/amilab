//
// C++ Interface: PluginInterface
//
// Description: It manages the life-cycle of the plugins.
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
class WX_AMILAB_EXPORT PluginInterface : public wxObject
{
  //DECLARE_ABSTRACT_CLASS(PluginInterface)

  public:
    // Get information of the plugin. 
    virtual const wxString & GetName(void) const = 0;
    virtual const wxString & GetDescription(void) const = 0;
    virtual const wxString & GetVersion(void) const = 0;
    virtual const wxString & GetAuthor(void) const = 0;
    virtual const wxString & GetStatus(void) const = 0;
    virtual const wxString & GetPath(void) const = 0;
//     virtual void SetStatus( const wxString& Status );
//     virtual void SetPath( const wxString& Path );

    // Get the GUI of the plugin.
    virtual wxWindow  *CreateGui (wxWindow *parent) = 0;
}; // PluginInterface

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
  typedef PluginInterface* ( *CreatePlugin_function)();

}
//@}

// ----------------------------------------------------------------------------
// macros for module declaration/implementation.
//
// This macros must be used inside the class declaration for any module class.
// ----------------------------------------------------------------------------

#define PLUGIN_DEFINE() \
public: \
  virtual const wxString & GetName(void) const; \
  virtual const wxString & GetDescription(void) const; \
  virtual const wxString & GetVersion(void) const; \
  virtual const wxString & GetAuthor(void) const; \
  virtual const wxString & GetStatus(void) const; \
  virtual const wxString & GetPath(void) const; \
  virtual void SetStatus( const wxString& Status ) ; \
  virtual void SetPath( const wxString& Path ) ; \
  virtual wxWindow  *CreateGui (wxWindow *parent);

#define PLUGIN_ENTRY_FUNCTION(name) \
extern "C" PLUGIN_AMILAB_DLLEXPORT PluginInterface* CreatePlugin() \
{ \
  return new name(); \
};

#endif // PLUGININTERFACE_H