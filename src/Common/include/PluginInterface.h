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

/**
 * @brief Class that contains the plugin interface.
 **/
class PluginInterface
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
     * @brief Execute the plugin.
     *
     * @return return true if the plugin executes correctly
     **/
    virtual bool Execute (void) = 0;

}; // PluginInterface

#endif // PLUGININTERFACE_H