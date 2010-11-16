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

PLUGIN_ENTRY_FUNCTION(AboutBox);

AboutBox::AboutBox()
{
  m_Name        = wxT("AboutBox");
  m_Description = wxT("A plugin that display the About dialog box.");
  m_Version     = wxT("1.0.0");
  m_Author      = wxT("Karl Krissian");
  m_Status      = wxT("Disabled");
  m_Path        = wxT("NOT-FOUND");
}

const wxString & AboutBox::GetName(void) const
  { return m_Name; }

const wxString & AboutBox::GetDescription(void) const
  { return m_Description; }

const wxString & AboutBox::GetVersion(void) const
  { return m_Version; }

const wxString & AboutBox::GetAuthor(void) const
  { return m_Author; }

const wxString & AboutBox::GetStatus(void) const
  { return m_Status; }

const wxString & AboutBox::GetPath(void)  const
  { return m_Path; }

void AboutBox::SetStatus( const wxString& MyStatus )
  { m_Status = MyStatus; }
  
void AboutBox::SetPath( const wxString& Path )
  { m_Path = Path; }

void AboutBox::SetwxWindow( wxWindow *Parent )
  { m_win = Parent; }

wxWindow* AboutBox::GetwxWindow(void)
  { return m_win; }
  
bool AboutBox::Execute (void)
{
  wxAboutDialogInfo info;

  info.SetName(wxT("AMILab"));
  info.SetVersion(AMILAB_VERSION);
  info.SetIcon(wxIcon(amilab_logo_new_32x32_alpha_xpm));
  info.SetDescription(wxT("AMILab is a tool for image processing that includes its own scripting language, and an interface for visualizing 2d/3d images and 3d surfaces. Its main application is medical image processing."));
  info.SetCopyright(wxT("(C) 2007 Karl Krissian <krissian@dis.ulpgc.es>>"));

  wxAboutBox(info, m_win);
  return true;
}