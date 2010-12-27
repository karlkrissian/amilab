//
// C++ Interface: wxPluginInterface
//
// Description: Define the plugin interface.
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef wxPluginInterface_H
#define wxPluginInterface_H

/**
 * @brief Class that contains the plugin interface.
 **/
class wxPluginInterface
{
  public:
    /**
     * @brief Get the plugin name.
     *
     * @return return a wxString with the plugin name
     **/
    virtual std::string GetName(void) const = 0;

    /**
     * @brief Get the plugin description.
     *
     * @return return a wxString with the plugin description
     **/
    virtual std::string GetDescription(void) const = 0;

    /**
     * @brief Get the plugin version.
     *
     * @return return a wxString with the plugin version
     **/
    virtual std::string GetVersion(void) const = 0;

    /**
     * @brief Get the plugin author.
     *
     * @return return a wxString with the plugin author
     **/
    virtual std::string GetAuthor(void) const = 0;

    /**
     * @brief Execute the plugin.
     *
     * @return return true if the plugin executes correctly
     **/
    virtual bool Execute (void) = 0;

}; // wxPluginInterface

#endif // wxPluginInterface_H
