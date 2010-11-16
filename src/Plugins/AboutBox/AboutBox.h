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

#include "PluginInterface.h"
#include <wx/aboutdlg.h>
#include "amilab_logo_new_32x32_alpha.xpm"

/**
 * @brief Class that contains a plugins that display the About dialog box.
 **/
class WX_AMILAB_EXPORT AboutBox : public WX_Plugin
{
  PLUGIN_WX_DEFINE();

public:
  AboutBox();

private:
    wxString m_Name;
    wxString m_Description;
    wxString m_Version;
    wxString m_Author;
    wxString m_Status;
    wxString m_Path;
    wxWindow *m_win;
};

#endif // ABOUTBOX_H