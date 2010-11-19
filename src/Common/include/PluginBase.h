//
// C++ Interface: PluginBase
//
// Description: Sets the basis for the definition of a Plugin.
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef PLUGINBASE_H
#define PLUGINBASE_H

//--------------------------------------------------
// Specified how export functions from DLL or 
// shared library.
//--------------------------------------------------
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
// Definition of macros to determine the mode of use
// of the Plugin.
//--------------------------------------------------
#define PLUGIN_IN_CONSOLE_MODE  0
#define PLUGIN_IN_GRAPHIC_MODE  1

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

#include "PluginInterface.h"

/**
 * @brief Class that sets the basis for the definition of a Plugin.
 **/
class WX_AMILAB_EXPORT PluginBase: public PluginInterface
{
  public:
    /**
     * @brief Get the plugin name.
     *
     * @return return a wxString with the plugin name
     **/
    virtual wxString GetName(void) const
    {
      return m_Name;
    }

    /**
     * @brief Get the plugin description.
     *
     * @return return a wxString with the plugin description
     **/
    virtual wxString GetDescription(void) const
    {
      return m_Description;
    }

    /**
     * @brief Get the plugin version.
     *
     * @return return a wxString with the plugin version
     **/
    virtual wxString GetVersion(void) const
    {
      return m_Version;
    }

    /**
     * @brief Get the plugin author.
     *
     * @return return a wxString with the plugin author
     **/
    virtual wxString GetAuthor(void) const
    {
      return m_Author;
    }

    /**
     * @brief Set the plugin name.
     *
     * @param Name A wxString with the plugin name
     **/
    virtual void SetName(const wxString &Name)
    {
      m_Name = Name;
    }

    /**
     * @brief Set the plugin description.
     *
     * @param Description A wxString with the plugin description
     **/
    virtual void SetDescription(const wxString &Description)
    {
      m_Description = Description;
    }

    /**
     * @brief Set the plugin version.
     *
     * @param Version A wxString with the plugin version
     **/
    virtual void SetVersion(const wxString &Version)
    {
      m_Version = Version;
    }

    /**
     * @brief Set the plugin author.
     *
     * @param Author A wxString with the plugin author
     **/
    virtual void SetAuthor(const wxString &Author)
    {
      m_Author = Author;
    }
    
    /**
     * @brief  Get the wxWindow of the plugin.
     *
     * @return return a wxString with the wxWindow of the plugin
     **/
    virtual wxWindow* GetwxWindow(void) const
    {
      return m_win;
    }

    /**
     * @brief Set the wxWindow of the plugin.
     *
     * @param Parent The wxWindow of the plugin
     **/
    virtual void SetwxWindow( wxWindow *Parent )
    {
      m_win = Parent;
    }

    /**
     * @brief Set that the plugin executes in mode console.
     *
     * The plugin does not require the graphical environment(wxWindow) to work.
     **/     
    virtual void SetConsoleMode(void)
    {
      m_plugin_mode = PLUGIN_IN_CONSOLE_MODE;
    }

    /**
     * @brief Set that the plugin executes in mode graphic.
     *
     * The plugin requires the graphical environment(wxWindow) to work.
     **/  
    virtual void SetGraphicMode(void)
    {
      m_plugin_mode = PLUGIN_IN_GRAPHIC_MODE;
    }

    /**
     * @brief Checks if this in console mode.
     *
     * @return Returns true if this in console mode.
     **/
    virtual bool IsConsoleMode(void) const
    {
      return (m_plugin_mode == PLUGIN_IN_CONSOLE_MODE);
    }

    /**
     * @brief Checks if this in graphic mode.
     *
     * @return Returns true if this in graphic mode.
     **/
    virtual bool IsGraphicMode(void) const
    {
      return (m_plugin_mode == PLUGIN_IN_GRAPHIC_MODE);
    }

    /**
     * @brief Execute the plugin.
     *
     * @return return true if the plugin executes correctly
     **/
    virtual bool Execute (void)
    {
      //TODO
      return true;
    }      
  
  private:
    unsigned char m_plugin_mode;  // Determines the mode in which the plugin is executed.
    wxString      m_Name,         // The plugin name
                  m_Description,  // The plugin description 
                  m_Version,      // The plugin version
                  m_Author;       // The plugin Author
    wxWindow*     m_win;          // The plugin wxWindow.

}; // PluginBase


/** @name This is the API that each AMILAB shared lib must implement. */
//@{
extern "C"
{
   /**
    Each module DLL must implement a function CreatePlugin of this
    type which will be called to initialise it. That function must
    return the new object representing this module.
   */
  typedef PluginBase* ( *CreatePlugin_function)();

}
//@}

// ----------------------------------------------------------------------------
// macros for module declaration/implementation.
//
// This macros must be used inside the class declaration for any module class.
// ----------------------------------------------------------------------------

#define PLUGIN_DEFINE() \
public: \
    virtual bool Execute (void);

#define PLUGIN_ENTRY_FUNCTION(name) \
extern "C" PLUGIN_AMILAB_DLLEXPORT PluginBase* CreatePlugin() \
{ \
  return new name(); \
};

#endif // PLUGINBASE_H