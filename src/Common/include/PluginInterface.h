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

//--------------------------------------------------
// Definition of macros to determine the mode of use
// of the Plugin.
//--------------------------------------------------
#define PLUGIN_IN_CONSOLE_MODE  0
#define PLUGIN_IN_GRAPHIC_MODE  1

/**
 * @brief Class that contains the protocol of communication.
 **/
class WX_AMILAB_EXPORT PluginInterface //: public wxObject
{
  public:
    /**
     * @brief Get the plugin name.
     *
     * @return return a wxString with the plugin name
     **/
    virtual wxString GetName(void) const = 0;

    /**
     * @brief Get the plugin description.
     *
     * @return return a wxString with the plugin description
     **/
    virtual wxString GetDescription(void) const = 0;

    /**
     * @brief Get the plugin version.
     *
     * @return return a wxString with the plugin version
     **/
    virtual wxString GetVersion(void) const = 0;

    /**
     * @brief Get the plugin author.
     *
     * @return return a wxString with the plugin author
     **/
    virtual wxString GetAuthor(void) const = 0;

    /**
     * @brief Get the plugin status.
     *
     * @return return a wxString with the plugin status
     **/
    virtual wxString GetStatus(void) const = 0;

    /**
     * @brief Get the plugin path.
     *
     * @return return a wxString with the plugin path
     **/
    virtual wxString GetPath(void) const = 0;

    /**
     * @brief  Get the wxWindow of the plugin.
     *
     * @return return a wxString with the wxWindow of the plugin
     **/
    virtual wxWindow* GetwxWindow(void) const = 0;

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
     * @brief Set the wxWindow of the plugin.
     *
     * @param Parent The wxWindow of the plugin
     **/
     virtual void SetwxWindow( wxWindow *Parent ) = 0;

    /**
     * @brief Set that the plugin executes in mode console.
     *
     * The plugin does not require the graphical environment(wxWindow) to work.
     **/     
     virtual void SetConsoleMode(void)
      { m_plugin_mode = PLUGIN_IN_CONSOLE_MODE; }

    /**
     * @brief Set that the plugin executes in mode graphic.
     *
     * The plugin requires the graphical environment(wxWindow) to work.
     **/  
     virtual void SetGraphicMode(void)
      { m_plugin_mode = PLUGIN_IN_GRAPHIC_MODE; }

    /**
     * @brief Checks if this in console mode.
     *
     * @return Returns true if this in console mode.
     **/
    virtual bool IsConsoleMode(void) const
      { return (m_plugin_mode == PLUGIN_IN_CONSOLE_MODE); }

    /**
     * @brief Checks if this in graphic mode.
     *
     * @return Returns true if this in graphic mode.
     **/
    virtual bool IsGraphicMode(void) const
      { return (m_plugin_mode == PLUGIN_IN_GRAPHIC_MODE); }

    /**
     * @brief Execute the plugin.
     *
     * @return return true if the plugin executes correctly
     **/
    virtual bool Execute (void) = 0;

  private:
    unsigned char m_plugin_mode; // Determines the mode in which the plugin is executed.

}; // PluginInterface

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
    virtual wxString  GetName(void)        const ; \
    virtual wxString  GetDescription(void) const ; \
    virtual wxString  GetVersion(void)     const ; \
    virtual wxString  GetAuthor(void)      const ; \
    virtual wxString  GetStatus(void)      const ; \
    virtual wxString  GetPath(void)        const ; \
    virtual wxWindow* GetwxWindow(void)    const ; \
    virtual void SetPath( const wxString& Path ) ; \
    virtual void SetStatus( const wxString& MyStatus) ; \
    virtual void SetwxWindow( wxWindow *Parent ) ; \
    virtual bool Execute (void);

#define PLUGIN_ENTRY_FUNCTION(name) \
extern "C" PLUGIN_AMILAB_DLLEXPORT PluginInterface* CreatePlugin() \
{ \
  return new name(); \
};

#endif // PLUGININTERFACE_H