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
#include <wx/version.h>
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

#include "myTreeCtrl.h"

#include "wx/listctrl.h"
#include "wx/wxhtml.h"
#include <wx/html/helpwnd.h>
#include <wx/html/helpctrl.h>
#include <wx/filepicker.h>
#include <wx/combobox.h>

#include "xmtext.hpp"

#include <iostream>
using namespace std;

#include "DefineClass.hpp"

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
  DEFINE_CLASS(MainFrame);

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

  void UpdateVarTree();

  wxPanel*       GetPromptPanel() { return _prompt_panel; }
  wxAuiNotebook* GetParamBook() { return _param_book; }

  void SetProgress(int val);

protected:
  CustomStatusBar* _status_bar;

  wxAuiNotebook* _main_book;
  wxAuiNotebook* _param_book;
  wxString       _initial_perspective;

  wxPanel*     _prompt_panel;

  wxPanel*     _varlist_panel;
  wxBoxSizer*  varlistpanel_sizer;

  wxPanel*     _vartree_panel;
  wxBoxSizer*  vartreepanel_sizer;

  boost::shared_ptr<wxTextValidator> _textcontrol_validator;
  TextControl* TC;
  wxTextCtrl*  _log_text;
  wxPanel*     _keywords_panel;
  wxPanel*     _var_panel;
  wxPanel*     _html_panel;

//  boost::shared_ptr<wxDirPickerCtrl> 
  wxPanel*     _settings_panel;

  wxListCtrl*  _var_list;
  wxComboBox*  _var_list_filter;
  wxHtmlWindow* _htmltext;

  myTreeCtrl*  _var_tree;
  wxTreeItemId _vartree_root;
  wxTreeItemId _vartree_images;
  wxTreeItemId _vartree_surfaces;
  wxTreeItemId _vartree_numbers;
  wxTreeItemId _vartree_strings;
  wxTreeItemId _vartree_functions;
  wxTreeItemId _vartree_wrapped_functions;
  wxTreeItemId _vartree_others;

  void CreateMenu();

  wxToolBar* CreateToolbar ( wxWindow* parent );

  void CreateMainBook     ( wxWindow*);
  void CreateParamBook    ( wxWindow*);

  void CreateConsoleText  ( wxWindow*);
  void CreateVarListPanel ( wxWindow*);
  void CreateVarTreePanel ( wxWindow*);
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
