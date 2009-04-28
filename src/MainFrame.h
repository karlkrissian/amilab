//
// C++ Interface: MainFrame
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _MainFrame_h
#define _MainFrame_h

#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include "wx/app.h"
#include "wx/grid.h"
#include "wx/treectrl.h"
#include "wx/spinctrl.h"
#include "wx/artprov.h"
#include "wx/clipbrd.h"
#include "wx/image.h"
#include "wx/colordlg.h"
#include "wx/wxhtml.h"
#include "wx/imaglist.h"
#include "wx/dataobj.h"
#include "wx/dcclient.h"
#include "wx/bmpbuttn.h"
#include "wx/menu.h"
#include "wx/toolbar.h"
#include "wx/statusbr.h"
#include "wx/msgdlg.h"
#include "wx/textdlg.h"
#include "wx/aui/aui.h"

#include "wx/listctrl.h"
#include "wx/wxhtml.h"
#include <wx/html/helpwnd.h>
#include <wx/html/helpctrl.h>
#include <wx/filepicker.h>
#include <wx/combobox.h>

#include "xmtext.hpp"

#include <iostream>
using namespace std;

class CustomStatusBar : public wxStatusBar
{
  public:
    CustomStatusBar(wxWindow* parent, wxWindowID id = wxID_ANY); 
    void SetProgress(int val);

  private:
    void OnSize(wxSizeEvent& evt);
    void OnIdle(wxIdleEvent& evt);
    // reposition the checkbox
    void Reposition();

    wxGauge* progressbar;

  DECLARE_EVENT_TABLE();
}; // CustomStatusBar

//----------------------------------------------------------------
/*!
  \brief MainFrame: the main window of AMILab
*/
class MainFrame: public wxFrame
//    ---------
{
public:
  MainFrame ( const wxString& title, const wxPoint& pos, 
              const wxSize& size );

  ~MainFrame() {
     m_mgr.UnInit();
  }

  wxAuiManager& GetAuiManager() {return m_mgr; };

  TextControl* GetConsole() { return TC; }

  bool AddMainPage(wxWindow* page, const wxString& caption, 
                    bool select = false, const wxBitmap& bitmap = wxNullBitmap);
  bool RemoveMainPage(wxWindow* page);

  bool AddParamPage(wxWindow* page, const wxString& caption, 
                    bool select = false, const wxBitmap& bitmap = wxNullBitmap);
  bool RemoveParamPage(wxWindow* page);

  void OnFileOpenImage    ( wxCommandEvent& event );
  void OnFileOpenPolydata ( wxCommandEvent& event );
  void OnFileLoadScript   ( wxCommandEvent& event );

  void OnViewReset        ( wxCommandEvent& event );

  void OnQuit ( wxCommandEvent& event );
  void OnClose ( wxCloseEvent& event );

  void OnHelpTokens ( wxCommandEvent& event );
  void OnHelpRules ( wxCommandEvent& event );
  void OnHelpScripts ( wxCommandEvent& event );

  void OnHelpBack ( wxCommandEvent& event );
  void OnHelpForward ( wxCommandEvent& event );

  #if (wxCHECK_VERSION(2,9,0)) 
    void ConsoleReset ( wxCommandEvent& event );
  #else
    void ConsoleReset ( wxAuiToolBarEvent& event );
  #endif
  void ConsoleClear ( wxCommandEvent& event );
  void UpdateVars   ( wxCommandEvent& event);
  void OnToolHelp   ( wxCommandEvent& event);

  void VarListRightClick( wxListEvent& event);

  void OnScriptsPath( wxFileDirPickerEvent& event);
  void OnHelpPath   ( wxFileDirPickerEvent& event);

  void UpdateVarList();

  wxPanel* GetPromptPanel() { return _prompt_panel; }

  void SetProgress(int val);

protected:
  CustomStatusBar* _status_bar;

  wxAuiNotebook* _main_book;
  wxAuiNotebook* _param_book;
  wxString       _initial_perspective;

  wxPanel*     _prompt_panel;

  wxPanel*     _varlist_panel;
  wxBoxSizer*  varlistpanel_sizer;

  TextControl* TC;
  wxTextCtrl*  _log_text;
  wxPanel*     _keywords_panel;
  wxPanel*     _var_panel;
  wxPanel*     _html_panel;
  wxPanel*     _settings_panel;
  wxListCtrl*  _var_list;
  wxComboBox*  _var_list_filter;
  wxHtmlWindow* _htmltext;

  void CreateMenu();

  wxToolBar* CreateToolbar ( wxWindow* parent );

  void CreateMainBook     ( wxWindow*);
  void CreateParamBook    ( wxWindow*);

  void CreateConsoleText  ( wxWindow*);
  void CreateVarListPanel ( wxWindow*);
  void CreateLogText      ( wxWindow*);
  void CreateKeywordsPanel( wxWindow*);
  void CreateVarPanel     ( wxWindow*);
  void CreateHtmlPanel    ( wxWindow*);
  void CreateSettingsPanel( wxWindow*);

private:
  wxAuiManager m_mgr;
  DECLARE_EVENT_TABLE();

}; // MainFrame


#endif // _MainFrame_h
