//
// C++ Interface: AboutBox
//
// Description: A plugin that display the About dialog box.
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef ABOUTBOX_H
#define ABOUTBOX_H

#include "wxPluginBase.h"
#include "AMILabConfig.h"
#include <wx/aboutdlg.h>
#include "amilab_logo_new_32x32_alpha.xpm"

/**
 * @brief Class that contains a plugins that display the About dialog box.
 **/
class WX_AMILAB_EXPORT AboutBox : public wxPluginBase
{
  PLUGIN_DEFINE();

public:
  AboutBox();

private:
  wxWindow* m_win;           // The plugin wxWindow.
  void _Init(void);          // Initializes the class
  void _CreateMenuBar(void); // Create the menu bar
};

#endif // ABOUTBOX_H
