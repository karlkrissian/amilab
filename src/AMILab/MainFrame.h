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
#pragma once
#ifndef _MainFrame_h
#define _MainFrame_h

#include "wx/wxprec.h"
#include <wx/version.h>
#ifdef __BORLANDC__
#pragma hdrstop
#endif


#include "wx/treectrl.h"

///@cond wxCHECK
#if (wxCHECK_VERSION(2,9,0) && wxUSE_FILECTRL)
  #include "wx/filectrl.h"
#endif
/// @endcond

#include <wx/dirctrl.h>

//#include "wx/app.h"
//#include "wx/grid.h"
//#include "wx/spinctrl.h"
//#include "wx/artprov.h"
//#include "wx/clipbrd.h"
#include "wx/image.h"
#include "wx/colordlg.h"
#include "wx/wxhtml.h"
//#include "wx/imaglist.h"
//#include "wx/dataobj.h"
//#include "wx/dcclient.h"
#include "wx/bmpbuttn.h"
#include "wx/menu.h"
#include "wx/toolbar.h"
#include "wx/statusbr.h"
#include "wx/msgdlg.h"
#include "wx/textdlg.h"
#include "wx/aui/aui.h"

class myTreeCtrl;
class wxGauge;
//#include "myTreeCtrl.h"

//class myDataViewCtrl;
//class AMILabTreeModel;
//class wxDataViewItem;

#include "amiDataViewTreeList.h"

///@cond wxCHECK
#if (wxCHECK_VERSION(2,9,0))
//  #define AMI_USE_DATAVIEW
  #include "myDataViewCtrl.h"
#endif
/// @endcond

#ifdef AMI_USE_DATAVIEW
//  #define TREE_VAR       m_amilab_model
  #define TREE_VAR       _var_dataview
  #define TREE_VAR_CTRL  _var_dataview
  #define TREE_ITEM_TYPE wxDataViewItem
  
#else
  #define TREE_VAR       _var_tree
  #define TREE_VAR_CTRL  _var_tree
  #define TREE_ITEM_TYPE wxTreeItemId
#endif


#include "wx/listctrl.h"
#include "wx/wxhtml.h"
#include <wx/html/helpwnd.h>
#include <wx/html/helpctrl.h>
#include <wx/filepicker.h>
#include <wx/combobox.h>

#include <wx/docview.h>

//#include "xmtext.hpp"
class TextControl;

//#include "ParamPanel.hpp"
class ParamPanel;

#include "Variables.hpp"

#include <iosfwd>
#include <list>
#include <map>
#include <set>

class wxStcFrame;

#include "DefineClass.hpp"
#include "wx/aui/aui.h"

class CustomAboutMenu : public wxDialog
{
  public:
    CustomAboutMenu(wxWindow* parent);
    void OnClose(wxCommandEvent& event);
 // DECLARE_EVENT_TABLE();
}; // CustomAboutMenu


//----------------------------------------------------------------
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

  wxStcFrame*  GetAmilabEditor();
  void OnCloseAmilabEditor() {
    amilab_editor = NULL;
  }
  
  void LoadToolBar();
  wxAuiManager& GetAuiManager() {return m_mgr; };

  boost::shared_ptr<TextControl> GetConsole() { return TC; }

  bool AddMainPage(wxWindow* page, const wxString& caption,
                    bool select = false, const wxBitmap& bitmap = wxNullBitmap);
  bool RemoveMainPage(wxWindow* page);

  // Deal with standard wxWindow* pages
  bool AddParamPage(wxWindow* page, const wxString& caption,
                    bool select = false, const wxBitmap& bitmap = wxNullBitmap);
  bool RemoveParamPage(wxWindow* page);

  // Deal with ParamPanel::ptr pages
  bool AddParamPanelPage(const boost::shared_ptr<ParamPanel>& panel, const wxString& caption,
                    bool select = false, const wxBitmap& bitmap = wxNullBitmap);
  bool RemoveParamPanelPage(const boost::shared_ptr<ParamPanel>& panel);

  void OnFileOpenImage         ( wxCommandEvent& event );
  void OnFileOpenImageHistory  ( wxCommandEvent& event );

  bool TryToOpenImage( const wxString& filename);

  void OnFileOpenPolydata ( wxCommandEvent& event );
  void OnFileLoadScript   ( wxCommandEvent& event );
  void OnFileOpenScriptHistory  ( wxCommandEvent& event );

  void OnViewReset ( wxCommandEvent& event );
  void OnViewOutput ( wxCommandEvent& event );
  void OnViewParam_book (wxCommandEvent& event );
  void OnViewMain_book( wxCommandEvent& event );
  void OnViewVar_book( wxCommandEvent& event );
  void OnViewMain_bar( wxCommandEvent& event );
  void OnViewMain_bar2( wxCommandEvent& event );
  void OnViewScript_bar( wxCommandEvent& event );
  
  void OnHelpKeywords( wxCommandEvent& event );
  
  void OnQuit ( wxCommandEvent& event );
  void OnClose ( wxCloseEvent& event );
  void OnUpdate(wxUpdateUIEvent& event );
  void OnAbout ( wxCommandEvent& event );
  void OnCloseAboutPanel(wxCommandEvent& event );
  
  void OnFindKeywords( wxCommandEvent& event );

/*
  void OnInternalIdle();
*/

  void OnHelpTokens ( wxCommandEvent& event );
  void OnHelpRules ( wxCommandEvent& event );
  void OnHelpScripts ( wxCommandEvent& event );

  void OnHelpBack ( wxCommandEvent& event );
  void OnHelpForward ( wxCommandEvent& event );

  /// @cond wxCHECK
  #if (wxCHECK_VERSION(2,9,0))
    void ConsoleReset ( wxCommandEvent& event );
  #else
    void ConsoleReset ( wxAuiToolBarEvent& event );
  #endif
  /// @endcond

  void ConsoleClear ( wxCommandEvent& event );
  void UpdateVarsDisplay();
  void UpdateDataViewVarDisplay();
  void UpdateVars();
  void CB_UpdateVars   ( wxCommandEvent& event);
  void OnToolHelp   ( wxCommandEvent& event);

  void VarListRightClick( wxListEvent& event);

  void OnScriptsPath( wxFileDirPickerEvent& event);
  void OnHelpPath   ( wxFileDirPickerEvent& event);

  void UpdateVarList();

  void UpdateVarTree( const TREE_ITEM_TYPE& rootbranch, Variables::ptr context,
                      int rec_level, std::string varpath="");

///@cond wxCHECK
#if wxCHECK_VERSION(2,9,0)
  void UpdateVarDataView( const wxDataViewItem& rootbranch, 
                          Variables::ptr context,
                          int rec_level, 
                          std::string varpath="");
  
  // avoid dealing with expand events when updating 
  void SetUpdatingDataView(bool up) { _updating_vardvt = up; }
  bool GetUpdatingDataView() { return _updating_vardvt; }
#endif
/// @endcond

  wxAuiNotebook* _param_book;
  wxPanel*       GetPromptPanel() { return _prompt_panel; }

  void SetProgress(   int val);
  void SetStatusText( const std::string& text);

  void AddMenuScript( const std::string& script_category, 
                      const std::string& script_label, 
                      const std::string& script_name);

  void AddToMenu(     const std::string& menu_name,
                      const std::string& script_category, 
                      const std::string& script_label, 
                      const std::string& script_name);

  void OnParametricSurfaces(  wxCommandEvent& event);
  void OnCreateTorus(         wxCommandEvent& event);
  void OnCreateSphere(        wxCommandEvent& event);
  void OnAddNoise(            wxCommandEvent& event);
  void OnUserMenuScript(      wxCommandEvent& event);

  
  boost::shared_ptr<wxFileHistory> GetImagesHistory()  { return images_history;  }
  boost::shared_ptr<wxFileHistory> GetScriptsHistory() { return scripts_history; }


  wxAuiNotebook* GetMainBook() { return _main_book; }

  wxAuiNotebook* GetParamBook() { return _param_book; }

protected:

//   void OnBeginDrag( wxDataViewEvent &event );
//   void OnDropPossible( wxDataViewEvent &event );
//   void OnDrop( wxDataViewEvent &event );
  //
  CustomAboutMenu *dialogAbout;
  wxAuiToolBar* tb1, *tb2;
  wxStcFrame* amilab_editor;
  
  // history of opened images
  boost::shared_ptr<wxFileHistory> images_history;
  wxMenu *images_history_menu;

  // history of opened scripts
  boost::shared_ptr<wxFileHistory> scripts_history;
  wxMenu *scripts_history_menu;

  // menus
  wxMenuBar *menuBar;
  wxMenu *menuFile;
  wxMenu *menuView,*menuView2,*menuView3;
  wxMenu *menuScripts;
  wxMenu *menuHelp;
  wxMenu *menuSegmentation;
  wxMenu *menuNoiseReduction;
  wxMenu *menuVisualization;
  wxMenu *menuSyntheticImages;

  long usermenu_id;
  std::map<long,std::string> usermenu_scripts; // Scripts added to the menu by the user

  CustomStatusBar* _status_bar;

  wxAuiNotebook* _main_book;
  //wxAuiNotebook* _param_book;
  wxString       _initial_perspective;
  // store the smart pointers of the used param panels for protection
  std::list<boost::shared_ptr<ParamPanel> > _parampanel_ptrs;

  wxPanel*     _prompt_panel;

  wxPanel*     _varlist_panel;
  wxBoxSizer*  varlistpanel_sizer;

  wxAuiNotebook*    _var_book;
  wxPanel*          _vartree_panel;

///@cond wxCHECK
#if (wxCHECK_VERSION(2,9,0) && wxUSE_FILECTRL)
  wxFileCtrl*       _var_fileCtrl;
#endif
/// @endcond

  wxGenericDirCtrl* _var_dirctrl;
  wxBoxSizer*  vartreepanel_sizer;

  wxPanel*     _vardataview_panel;
  wxBoxSizer*  vardataviewpanel_sizer;

  boost::shared_ptr<wxTextValidator> _textcontrol_validator;
  boost::shared_ptr<TextControl> TC;
  wxTextCtrl*  _log_text;
  wxPanel*     _keywords_panel;
  
  wxTextCtrl *textCtrl;
  //wxListBox* m_listBox; 
 
  wxPanel*     _var_panel;
  wxPanel*     _html_panel;
  wxPanel*     _drawing_panel;

  boost::shared_ptr<wxDirPickerCtrl> scripts_path_picker;
  boost::shared_ptr<wxDirPickerCtrl> help_path_picker;
  wxPanel*     _settings_panel;

  wxListCtrl*  _var_list;
  wxComboBox*  _var_list_filter;
  wxHtmlWindow* _htmltext;

  myTreeCtrl*  _var_tree;
  int _vartree_col_main;
  int _vartree_col_type;
  int _vartree_col_val;
  int _vartree_col_desc;
  wxTreeItemId _vartree_root;
  wxTreeItemId _vartree_global;
  wxTreeItemId _vartree_builtin;

  
  bool _updating_vardvt;
  wxDataViewItem _vardvt_root;
  wxDataViewItem _vardvt_global;
  wxDataViewItem _vardvt_builtin;
  
  std::set<std::string> expanded_items;
  std::set<std::string> dv_expanded_items;

///@cond wxCHECK
#if wxCHECK_VERSION(2,9,0)
  //  myDataViewCtrl* _var_dataview;
  wxDataViewTreeListCtrl* _var_dataview;
  wxObjectDataPtr<AMILabTreeModelNew> m_amilab_model; // the model associated.
#endif
/// @endcond

//  wxTreeItemId _vartree_images;
//  wxTreeItemId _vartree_surfaces;
//  wxTreeItemId _vartree_numbers;
//  wxTreeItemId _vartree_strings;
//  wxTreeItemId _vartree_functions;
//  wxTreeItemId _vartree_classes;
//  wxTreeItemId _vartree_objects;
//  wxTreeItemId _vartree_wrapped_functions;
//  wxTreeItemId _vartree_others;

  void CreateMenu();

  wxToolBar* CreateToolbar    ( wxWindow* parent );

  void CreateMainBook         ( wxWindow*);
  void CreateParamBook        ( wxWindow*);

  void CreateConsoleText      ( wxWindow*);
  void CreateVarListPanel     ( wxWindow*);
  void CreateVarBook          ( wxWindow*);
  void CreateVarDirCtrl       ( wxWindow*);
  void CreateVarTreePanel     ( wxWindow*);
  void CreateAboutPanel       (wxWindow* parent);

///@cond wxCHECK
#if wxCHECK_VERSION(2,9,0)
  void CreateVarDataViewPanel ( wxWindow*);
#endif
/// @endcond  

  void CreateLogText          ( wxWindow*);
  void CreateKeywordsPanel    ( wxWindow*);
  void CreateVarPanel         ( wxWindow*);
  void CreateHtmlPanel        ( wxWindow*);
  void CreateDrawingPanel     ( wxWindow*);
  void CreateSettingsPanel    ( wxWindow*);

///@cond wxCHECK
#if (wxCHECK_VERSION(2,9,0) && wxUSE_FILECTRL)
  void OnFileCtrl( wxFileCtrlEvent& event );
#endif
///@endcond

  void OnFileActivated(wxCommandEvent& event);

private:
  bool toolbar_status;
  wxAuiManager m_mgr;
  DECLARE_EVENT_TABLE();

}; // MainFrame


#endif // _MainFrame_h
