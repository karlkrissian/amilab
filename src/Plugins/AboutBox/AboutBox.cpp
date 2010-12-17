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

#include "AboutBox.h"
#include "VarContexts.hpp"

extern VarContexts  Vars;


PLUGIN_ENTRY_FUNCTION(AboutBox);

void AboutBox::_Init(void)
{
  SetGraphicMode();
  m_win = GetwxWindow();  
  SetName(wxT("AboutBox"));
  SetDescription(wxT("A plugin that display the About dialog box."));
  SetAuthor(wxT("XXX XXX"));
  SetVersion(wxT("1.0.0"));
}

AboutBox::AboutBox()
{
  _Init();
}

bool AboutBox::Execute(void)
{
  BasicVariable::ptr v = AMILabType<int>::CreateVar(5);
  Vars.AddVar("plugin_var",v);
  
  wxAboutDialogInfo info;

  info.SetName(wxT("AMILab"));
  info.SetVersion(wxT(AMILAB_VERSION));
  info.SetIcon(wxIcon(amilab_logo_new_32x32_alpha_xpm));
  info.SetDescription(wxT("AMILab is a tool for image processing that includes its own scripting language, and an interface for visualizing 2d/3d images and 3d surfaces. Its main application is medical image processing."));
  info.SetCopyright(wxT("(C) 2007 Karl Krissian <krissian@dis.ulpgc.es>>"));

  #if wxCHECK_VERSION(2,9,0)
    wxAboutBox(info, m_win);
  #else
    wxAboutBox(info);
  #endif
  return true;
}