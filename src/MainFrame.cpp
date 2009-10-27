//
// C++ Implementation: MainFrame
//
// Description:
//
//
// Author:  Karl Krissian <>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "MainFrame.h"

#include <wx/dirctrl.h>
#include <wx/stattext.h>
#include <wx/utils.h>
#include <wx/stdpaths.h>
#include <wx/dir.h>
#include <wx/filefn.h>
#include <wx/filepicker.h>
#include <wx/bmpbuttn.h>
#include <wx/tooltip.h>
#include <wx/toolbar.h>
#include <wx/combobox.h>
#include <iostream>

#include "myTreeCtrl.h"

#include <sys/stat.h>
#ifndef WIN32
#include <unistd.h>
#endif

#include "VarContexts.hpp"

#ifndef _WITHOUT_VTK_
#include "vtkMultiThreader.h"
#endif

#include "token_list.h"

#include "wxParamTypes.hpp"

#include "xmtext.hpp"

#include "slick/16x16/actions/reload.xpm"
#include "gtk-clear.xpm"

#include "amilab_messages.h"

#include "surface.hpp"

//#include "Bluecurve/32x32/actions/reload.xpm"

extern wxString        GB_help_dir;
extern wxString        GB_scripts_dir;
extern VarContexts  Vars;



// in function.cpp
int AskScript(std::string& name);
int AskImage(std::string& name);
int AskVarName(wxWindow*,const string title, const string label,const string def, std::string& name);
int AskSurface(     std::string& name);

enum
{
    ID_Quit = 200,
    ID_About,

    ID_File_OpenImage,
    ID_File_OpenPolydata,
    ID_File_LoadScript,

    ID_View_Reset,

    wxID_HelpTokens,
    wxID_HelpRules,
    wxID_HelpScripts,
    wxID_HelpBack,
    wxID_HelpForward,

    wxID_ProgressBar,
};

enum {
  wxID_ScriptsPath = 300,
  wxID_HelpPath
};

enum {
  wxID_ConsoleReset = 2000,
  wxID_ConsoleClear,
  wxID_UpdateVars,
  wxID_ToolHelp,
  wxID_ToolQuit,
  wxID_VarList,
  wxID_VarList_Filter,
};

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_File_OpenImage,    MainFrame::OnFileOpenImage)
    EVT_MENU(ID_File_OpenPolydata, MainFrame::OnFileOpenPolydata)
    EVT_MENU(ID_File_LoadScript,   MainFrame::OnFileLoadScript)
    EVT_MENU(ID_Quit,              MainFrame::OnQuit)

    EVT_MENU(ID_View_Reset,        MainFrame::OnViewReset)

    EVT_CLOSE(MainFrame::OnClose)

//    EVT_BUTTON(wxID_ConsoleReset, MainFrame::ConsoleReset)
    EVT_TOOL(         wxID_ConsoleClear, MainFrame::ConsoleClear)
#if (wxCHECK_VERSION(2,9,0))
    EVT_TOOL_RCLICKED(wxID_ConsoleClear, MainFrame::ConsoleReset)
#else
    EVT_AUITOOLBAR_RIGHT_CLICK(wxID_ConsoleClear, MainFrame::ConsoleReset)
#endif
    EVT_TOOL(wxID_UpdateVars,   MainFrame::UpdateVars)
    EVT_TOOL(wxID_ToolHelp,     MainFrame::OnToolHelp)
    EVT_TOOL(wxID_ToolQuit,     MainFrame::OnQuit)

    EVT_TOOL (wxID_HelpTokens,  MainFrame::OnHelpTokens)
    //EVT_TOOL_RCLICKED(wxID_HelpTokens, MainFrame::OnHelpRules)
    EVT_TOOL (wxID_HelpRules,   MainFrame::OnHelpRules)
    EVT_TOOL (wxID_HelpScripts, MainFrame::OnHelpScripts)
    EVT_TOOL (wxID_HelpBack,    MainFrame::OnHelpBack)
    EVT_TOOL (wxID_HelpForward, MainFrame::OnHelpForward)

    EVT_LIST_ITEM_MIDDLE_CLICK(wxID_VarList, MainFrame::VarListRightClick)
    EVT_LIST_ITEM_RIGHT_CLICK(wxID_VarList, MainFrame::VarListRightClick)

    EVT_COMBOBOX(wxID_VarList_Filter, MainFrame::UpdateVars)

    EVT_DIRPICKER_CHANGED(wxID_ScriptsPath, MainFrame::OnScriptsPath)
    EVT_DIRPICKER_CHANGED(wxID_HelpPath,    MainFrame::OnHelpPath   )
END_EVENT_TABLE()


static int CompareStringLen(const wxString& first, const wxString& second)
{
    return second.CmpNoCase(first);
}

BEGIN_EVENT_TABLE(CustomStatusBar, wxStatusBar)
  EVT_SIZE(CustomStatusBar::OnSize)
//  EVT_IDLE(OnIdle)
END_EVENT_TABLE()

CustomStatusBar::CustomStatusBar(wxWindow* parent, wxWindowID id ) : wxStatusBar(parent,id)
{
  // This status bar has three fields
  SetFieldsCount(2);
  SetStatusText( GetwxStr("Welcome to AMILab!"),0);

  progressbar = new wxGauge(this,
        wxID_ProgressBar,
        100);
  // set the initial position of the checkbox
  Reposition();
}

void CustomStatusBar::SetProgress(int val)
{
  if (val<0) val=0;
  if (val>100) val = 100;
  progressbar->SetValue(val);
  progressbar->Update();
}

void CustomStatusBar::OnSize( wxSizeEvent& evt)
{
   Reposition();  // for normal size events
  //Set a flag so the idle time handler will also do the repositioning.
  // It is done this way to get around a buglet where GetFieldRect is not
  // accurate during the EVT_SIZE resulting from a frame maximize.
  //sizeChanged = True
}



/*
void CustomStatusBar::OnIdle( wxIdleEvent evt)
{
   if (sizeChanged) Reposition();
}
*/

// reposition the checkbox
void CustomStatusBar::Reposition()
{
  wxRect rect;
  GetFieldRect(1,rect);
  progressbar->SetPosition(rect.GetPosition()+wxPoint(2,2));
  progressbar->SetSize(    wxSize(rect.GetWidth()-2,rect.GetHeight()-2));
}

//-------------------------------------------------------
void MainFrame::CreateMenu()
//            ----------
{
  usermenu_id = 1000;

  menuFile = new wxMenu;
  menuFile->Append( ID_File_OpenImage,    GetwxStr("Open &image") );
  menuFile->Append( ID_File_OpenPolydata, GetwxStr("Open &polydata") );
  menuFile->Append( ID_File_LoadScript, GetwxStr("Load &script") );
  menuFile->Append( ID_Quit, GetwxStr("E&xit") );

  menuView = new wxMenu;
  menuView->Append( ID_View_Reset, GetwxStr("&Reset") );



  menuScripts = new wxMenu;


  menuBar = new wxMenuBar;
  menuBar->Append( menuFile,    GetwxStr("&File") );
  menuBar->Append( menuView,    GetwxStr("&View") );
  menuBar->Append( menuScripts, GetwxStr("&Scripts") );

  SetMenuBar( menuBar );


} // CreateMenu()


//-------------------------------------------------------
wxToolBar* MainFrame::CreateToolbar( wxWindow* parent)
//                  -------------
{
  // try a toolbar
  #include "wx_helpicon.xpm"
  #include "wx_helpback.xpm"
  #include "wx_helpforward.xpm"

  wxToolBar* toolBar;

  if (parent==this)
    toolBar = CreateToolBar();
  else
    toolBar = new wxToolBar(
                    parent
                  , wxID_ANY
                  , wxDefaultPosition
                  , wxDefaultSize
                  , wxTB_VERTICAL);

  toolBar->SetMargins(0,0);
  toolBar->SetToolBitmapSize(wxSize(32,32));

  toolBar->AddTool(wxID_HelpTokens, GetwxStr("Help Tokens"),
        wxBitmap( helpicon_xpm), GetwxStr("Help language tokens"));
  toolBar->AddTool(wxID_HelpRules, GetwxStr("Help Rules"),
        wxBitmap( helpicon_xpm), GetwxStr("Help language rules"));
  toolBar->AddTool(wxID_HelpScripts, GetwxStr("Help Scripts"),
        wxBitmap( helpicon_xpm), GetwxStr("Help language scripts"));
  toolBar->AddTool(wxID_HelpBack, GetwxStr("Help back"),
        wxBitmap( helpback_xpm), GetwxStr("Help back"));
  toolBar->AddTool(wxID_HelpForward, GetwxStr("Help forward"),
        wxBitmap(helpforward_xpm), GetwxStr("Help forward"));
  toolBar->Realize();

  return toolBar;

} // CreateToolbar()


//-------------------------------------------------------
MainFrame::MainFrame( const wxString& title,
                  const wxPoint& pos,
                  const wxSize& size
                )
                : wxFrame((wxWindow *)NULL,
                  wxID_ANY,
                  title,
                  pos,
                  size)
{

  CreateMenu();
//  CreateToolbar();

  m_mgr.SetManagedWindow(this);

     // tell the manager to "commit" all the changes just made

  CreateMainBook(this);
  m_mgr.AddPane(_main_book,  wxAuiPaneInfo()
                  .Name(wxT("Main Book"))
                  //.MinSize(wxSize(200,200))
                  .Center()
                  .MaximizeButton(true));

  CreateVarListPanel(this);
  m_mgr.AddPane(_varlist_panel,
                  wxAuiPaneInfo()
                  .Name(wxT("VariablesList"))
                  .Caption(wxT("Variables List"))
                  .Left().Layer(1)
                  .MinimizeButton(true));

  CreateVarTreePanel(this);
  m_mgr.AddPane(_vartree_panel,
                  wxAuiPaneInfo()
                  .Name(wxT("VariablesTree"))
                  .Caption(wxT("Variables Tree"))
                  .Left().Layer(1)
                  .MaximizeButton(true));

  CreateLogText(this);
  m_mgr.AddPane(_log_text,
                  wxAuiPaneInfo()
                  .Name(wxT("Log"))
                  .Caption(wxT("Output"))
                  .Bottom()
                  .MinimizeButton(true));

  CreateParamBook(this);
  m_mgr.AddPane(_param_book,
                  wxAuiPaneInfo()
                  .Name(wxT("Param Book"))
                  .Caption(wxT("User Interface"))
                  .MinSize(wxSize(200,100))
                  .BestSize(wxSize(300,100))
                  .Right().Layer(1)
                  .MaximizeButton(true)
                  .Hide());

    // create some toolbars
  #if (wxCHECK_VERSION(2,9,0))
    wxToolBar* tb1 = new wxToolBar(this, wxID_ANY,
                        wxDefaultPosition, wxDefaultSize);
  #else
    wxAuiToolBar* tb1 = new wxAuiToolBar(this, wxID_ANY,
                        wxDefaultPosition, wxDefaultSize,
                        wxAUI_TB_DEFAULT_STYLE |
                        wxAUI_TB_OVERFLOW);
  #endif
    tb1->SetToolBitmapSize(wxSize(48,48));
//    tb1->AddTool(wxID_ANY, wxT("Test"), wxArtProvider::GetBitmap(wxART_ERROR));
//    tb1->AddSeparator();
    tb1->AddTool(wxID_UpdateVars, wxT("Update variables"), wxBitmap(reload),
        wxT("Update variables"));
    tb1->AddSeparator();
    tb1->AddTool(wxID_ConsoleClear, wxT("Clear console"), wxBitmap(gtk_clear),
        wxT("Console: left button -> clear last command, right button-> clear all"));

//   wxBitmapButton* but_clear = new wxBitmapButton(_prompt_panel,
//           wxID_ConsoleClear,
//           wxBitmap(gtk_clear));
//   wxToolTip::Enable(true);
//   but_clear->SetToolTip(GetwxStr("Clear current line"));
    tb1->AddSeparator();
    tb1->AddTool(wxID_ToolHelp, wxT("Help"), wxArtProvider::GetBitmap(wxART_HELP),
        wxT("Help (load in default browser)"));

    tb1->AddTool(wxID_ToolQuit, wxT("Quit"), wxArtProvider::GetBitmap(wxART_QUIT),
        wxT("Quit AMILab"));


//    tb1->AddTool(ID_SampleItem+3, wxT("Test"), wxArtProvider::GetBitmap(wxART_INFORMATION));
//    tb1->AddTool(ID_SampleItem+4, wxT("Test"), wxArtProvider::GetBitmap(wxART_WARNING));
//    tb1->AddTool(ID_SampleItem+5, wxT("Test"), wxArtProvider::GetBitmap(wxART_MISSING_IMAGE));
//    tb1->SetCustomOverflowItems(prepend_items, append_items);
    tb1->Realize();

    // add the toolbars to the manager
    m_mgr.AddPane(tb1, wxAuiPaneInfo().
                  Name(wxT("tb1")).Caption(wxT("Big Toolbar")).
                  ToolbarPane().Top().
                  LeftDockable(false).RightDockable(false));

  // tell the manager to "commit" all the changes just made
  m_mgr.Update();

  _initial_perspective = m_mgr.SavePerspective();

  _status_bar = new CustomStatusBar(this,wxID_ANY);
  SetStatusBar(_status_bar);
  _status_bar->SetProgress(0);

  Centre(wxBOTH);

}


//------------------------------------------------------------------------
void MainFrame::CreateMainBook(wxWindow* parent)
{
   // create the notebook off-window to avoid flicker
   wxSize client_size = GetClientSize();

   _main_book = new wxAuiNotebook(this, wxID_ANY,
                                    wxPoint(client_size.x, client_size.y),
                                    wxDefaultSize,
                                    wxAUI_NB_TOP          |
                                    wxAUI_NB_TAB_SPLIT    |
                                    wxAUI_NB_TAB_MOVE     |
                                    wxAUI_NB_SCROLL_BUTTONS
                                  );

   wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16));

  CreateConsoleText(this);
  _main_book->AddPage( _prompt_panel,  wxT("Console"), false, page_bmp );

  CreateHtmlPanel(this);
  _main_book->AddPage( _html_panel , wxT("Help") );

  CreateSettingsPanel(this);
  _main_book->AddPage( _settings_panel , wxT("Paths") );

  CreateKeywordsPanel(this);
  _main_book->AddPage( _keywords_panel , wxT("Keywords") );

  _main_book->Fit();

}

//------------------------------------------------------------------------
void MainFrame::CreateParamBook(wxWindow* parent)
{
   // create the notebook off-window to avoid flicker
   wxSize client_size = GetClientSize();

   _param_book = new wxAuiNotebook(this, wxID_ANY,
                                    wxPoint(client_size.x, client_size.y),
                                    wxDefaultSize,
                                    wxAUI_NB_TOP          |
                                    wxAUI_NB_TAB_SPLIT    |
                                    wxAUI_NB_TAB_MOVE     |
                                    wxAUI_NB_SCROLL_BUTTONS
                                  );

  _param_book->Fit();

}

//--------------------------------------------------------
bool MainFrame::AddMainPage(wxWindow* page, const wxString& caption,
                            bool select, const wxBitmap& bitmap)
{
  bool result = _main_book->AddPage( page,caption,select,bitmap );
  _main_book->Fit();
   m_mgr.Update();
  return result;
} // AddPage()


//--------------------------------------------------------
bool MainFrame::RemoveMainPage(wxWindow* page)
{
  bool result = _main_book->RemovePage( _main_book->GetPageIndex(page) );
  _main_book->Fit();
   m_mgr.Update();
  return result;
} // RemoveMainPage()

//--------------------------------------------------------
bool MainFrame::AddParamPage(wxWindow* page, const wxString& caption,
                            bool select, const wxBitmap& bitmap)
{
  if (_param_book->GetPageIndex(page)!=wxNOT_FOUND)
    return false;
  bool result = _param_book->AddPage( page,caption,select,bitmap );
  _param_book->Fit();
   m_mgr.GetPane(_param_book).Show();
   m_mgr.Update();
  return result;
} // AddParamPage()

//--------------------------------------------------------
bool MainFrame::RemoveParamPage(wxWindow* page)
{
  bool result = _param_book->RemovePage( _param_book->GetPageIndex(page) );
  _param_book->Fit();
  if (_main_book->GetPageCount()==0)
     m_mgr.GetPane(_param_book).Hide();
  m_mgr.Update();
  return result;
} // RemoveParamPage()


//--------------------------------------------------------
bool MainFrame::AddParamPanelPage(ParamPanel::ptr& page, const wxString& caption,
                            bool select, const wxBitmap& bitmap)
{
  bool res;
  if (page.get()) {
    res = AddParamPage((wxWindow*) page.get(), caption,
                        select, bitmap);
    page->Show();
    if (res) _parampanel_ptrs.push_back(page);
    return res;
  } else
    return false;
} // AddParamPanelPage()

//--------------------------------------------------------
bool MainFrame::RemoveParamPanelPage(ParamPanel::ptr& page)
{
  if (page.get()) {
    page->Hide();
    // remove the corresponding smart pointers from the list
    _parampanel_ptrs.remove(page);
    return RemoveParamPage((wxWindow*) page.get());
  } else
    return false;
} // RemoveParamPanelPage()


//--------------------------------------------------------
void MainFrame::CreateVarListPanel ( wxWindow* parent)
{

  _varlist_panel = new wxPanel(parent);
  varlistpanel_sizer  = new wxBoxSizer( wxVERTICAL );
  _varlist_panel->SetSizer(varlistpanel_sizer);

  _var_list = new wxListCtrl( _varlist_panel,
                              wxID_ANY,
                              wxDefaultPosition,
                              wxDefaultSize,
                              wxSUNKEN_BORDER
                              | wxLC_REPORT
                            );

    wxListItem itemCol;
    itemCol.SetText(wxT("Name"));
    //itemCol.SetImage(-1);
    _var_list->InsertColumn(0, itemCol);

    itemCol.SetText(wxT("Type"));
    _var_list->InsertColumn(1, itemCol);

    _var_list->SetColumnWidth( 0, wxLIST_AUTOSIZE_USEHEADER );
    _var_list->SetColumnWidth( 1, wxLIST_AUTOSIZE_USEHEADER );


//  wxButton* but_upvar = new wxButton(_varlist_panel, wxID_UpdateVars,GetwxStr("Update"));
/*
  wxBitmapButton* but_upvar = new wxBitmapButton(_varlist_panel, wxID_UpdateVars,
      wxBitmap(reload));

  wxBoxSizer* buttons_sizer = new wxBoxSizer(wxHORIZONTAL);
  buttons_sizer->Add(but_upvar,   0, wxEXPAND , 5);

  varlistpanel_sizer->Add(buttons_sizer, 0, wxEXPAND , 5);
*/

  // ComboBox to select the type of variables
  wxString filter_choices[] = {
                              _T("all"),
                              _T("images"),
                              _T("surfaces"),
                              _T("AMI functions")};
  _var_list_filter = new wxComboBox(_varlist_panel,wxID_VarList_Filter,_T("all"),
                              wxDefaultPosition,
                              wxDefaultSize,
                              4,
                              filter_choices);

  varlistpanel_sizer->Add(_var_list_filter, 0, wxEXPAND , 5);
  varlistpanel_sizer->Add(_var_list, 1, wxEXPAND , 5);
  varlistpanel_sizer->Fit(_varlist_panel);

} // CreateVarListPanel()

//--------------------------------------------------------
void MainFrame::CreateVarTreePanel ( wxWindow* parent)
{

  _vartree_panel = new wxPanel(parent);
  vartreepanel_sizer  = new wxBoxSizer( wxVERTICAL );
  _vartree_panel->SetSizer(vartreepanel_sizer);

  _var_tree = new myTreeCtrl( _vartree_panel,
                              wxID_ANY,
                              wxDefaultPosition,
                              wxDefaultSize,
                              wxTR_HAS_BUTTONS | wxTR_HIDE_ROOT 
                            );
  _var_tree->SetFont( wxFont(10,wxMODERN,wxNORMAL,wxNORMAL)); // try a fixed pitch font
  _var_tree->SetIndent(5);

  _vartree_root      = _var_tree->AddRoot(_T("Variables"));
  _vartree_images    = _var_tree->AppendItem(_vartree_root,_T("Images"));
  _vartree_surfaces  = _var_tree->AppendItem(_vartree_root,_T("Surfaces"));
  _vartree_numbers   = _var_tree->AppendItem(_vartree_root,_T("Numbers"));
  _vartree_strings   = _var_tree->AppendItem(_vartree_root,_T("Strings"));
  _vartree_functions = _var_tree->AppendItem(_vartree_root,_T("Functions"));
  _vartree_wrapped_functions = _var_tree->AppendItem(_vartree_root,_T("Wrapped Functions"));
  _vartree_others    = _var_tree->AppendItem(_vartree_root,_T("Others"));

  vartreepanel_sizer->Add(_var_tree, 1, wxEXPAND , 5);
  vartreepanel_sizer->Fit(_vartree_panel);

} // CreateVarTreePanel()

//--------------------------------------------------------
void MainFrame::CreateConsoleText( wxWindow* parent)
{

  _prompt_panel = new wxPanel(parent, wxID_ANY,
                    wxDefaultPosition, wxDefaultSize,
                      wxCLIP_CHILDREN
                    |
                      wxTAB_TRAVERSAL
                    |
                      wxFULL_REPAINT_ON_RESIZE
                    // | wxNO_FULL_REPAINT_ON_RESIZE
                    );

  wxStaticBox* sbox=  new wxStaticBox(_prompt_panel,wxID_ANY,GetwxStr("Working area"));
  wxStaticBoxSizer* sbox_sizer  = new wxStaticBoxSizer(
          sbox,
          wxVERTICAL
          );

  _prompt_panel->SetSizer(sbox_sizer);


  // Then create a text control
  _textcontrol_validator = boost::shared_ptr<wxTextValidator>(new wxTextValidator(wxFILTER_ASCII));
  _textcontrol_validator->SetBellOnError(TRUE);

  this->TC = new TextControl( _prompt_panel,
                        wxID_ANY,
                        GetwxStr("Console"),
                          wxTE_MULTILINE
                        | wxHSCROLL
                        | wxFULL_REPAINT_ON_RESIZE
                        //|wxTE_RICH|wxTE_RICH2
                        , (*_textcontrol_validator)
                        );

//   wxButton* but_reset = new wxButton(_prompt_panel,
//           wxID_ConsoleReset,GetwxStr("Reset"));
// //  wxButton* but_clear = new wxButton(_prompt_panel,
// //          wxID_ConsoleClear,GetwxStr("Clear"));
//   wxBitmapButton* but_clear = new wxBitmapButton(_prompt_panel,
//           wxID_ConsoleClear,
//           wxBitmap(gtk_clear));
//   wxToolTip::Enable(true);
//   but_clear->SetToolTip(GetwxStr("Clear current line"));

  wxBoxSizer* buttons_sizer = new wxBoxSizer(wxHORIZONTAL);
//   buttons_sizer->Add(but_clear,   0, wxEXPAND , 5);
//   buttons_sizer->Add(but_reset,   0, wxEXPAND , 5);

  sbox_sizer->Add(buttons_sizer, 0, wxEXPAND , 5);
  sbox_sizer->Add(TC, 1, wxEXPAND | wxALL, 2);

} // CreateConsoleText()


//--------------------------------------------------------
void MainFrame::CreateLogText( wxWindow* parent)
{

  _log_text = new wxTextCtrl( parent,
                            wxID_ANY,
                            GetwxStr("This is the log window.\n"),
                            wxDefaultPosition,
                            wxDefaultSize,
                            wxTE_MULTILINE
                            | wxTE_READONLY
                            | wxHSCROLL
                            | wxFULL_REPAINT_ON_RESIZE
                            );

  if (TC)
    TC->SetLog(_log_text);

} // CreateLogText()



//-------------------------------------------------------
void MainFrame::CreateKeywordsPanel( wxWindow* parent)
//            -----------------
{
  // Help Panel
  //panel->SetBackgroundColour( wxColour( GetwxStr("MAROON") ) );
  _keywords_panel = new wxPanel(parent,
                            wxID_ANY,
                            wxDefaultPosition, wxDefaultSize,
                              wxFULL_REPAINT_ON_RESIZE
                            | wxCLIP_CHILDREN
                            | wxTAB_TRAVERSAL
                            );


  wxStaticBox* keywordspanel_box = new wxStaticBox(
          _keywords_panel,
          wxID_ANY,
          GetwxStr("Here we should list the functions of the program")
          );

  wxStaticBoxSizer* keywordspanel_sizer  = new wxStaticBoxSizer(
          keywordspanel_box,
          wxVERTICAL
          );
  _keywords_panel->SetSizer(keywordspanel_sizer);

  // starts a list
  wxListCtrl* m_listCtrl = new wxListCtrl(
          _keywords_panel,
          wxID_ANY,
          wxDefaultPosition,
          wxDefaultSize,
          wxLC_LIST | wxSUNKEN_BORDER);

  wxArrayString keywords;

  int i = 0;
  while (token_list[i]!=0) {
    keywords.Add(GetwxStr(token_list[i]));
    //m_listCtrl->InsertItem(0,token_list[i]);
    i++;
  }


  keywords.Sort(CompareStringLen);
  i = 0;
  while (i<(int)keywords.Count()) {
    m_listCtrl->InsertItem(0,keywords[i]);
    i++;
  }

  keywordspanel_sizer->Add(m_listCtrl,  1, wxEXPAND | wxALL, 5);

} // CreateKeywordsPanel()


//-------------------------------------------------------
void MainFrame::CreateVarPanel(wxWindow* parent)
//            --------------
{
  // Variables
  _var_panel = new wxPanel(
          parent,
          wxID_ANY,
          wxDefaultPosition,
          wxDefaultSize,
            wxFULL_REPAINT_ON_RESIZE
          | wxTAB_TRAVERSAL
          );

  wxStaticBox* var_box = new wxStaticBox(
          _var_panel,
          wxID_ANY,
          GetwxStr("Here we should list the variables") );

  wxStaticBoxSizer* varpanel_sizer  = new wxStaticBoxSizer(
          var_box,
          wxVERTICAL );

  _var_panel->SetSizer(varpanel_sizer);

  // starts a list
  wxListCtrl* m_varlist = new wxListCtrl(
          _var_panel,
          wxID_VarList,
          wxDefaultPosition,
          wxDefaultSize,
          wxLC_REPORT | wxSUNKEN_BORDER);
  varpanel_sizer->Add(m_varlist,  1, wxEXPAND | wxALL, 5);

} // CreateVarPanel()


//-------------------------------------------------------
void MainFrame::CreateHtmlPanel(wxWindow* parent)
//            --------------
{
  // Variables
  _html_panel = new wxPanel(
          parent,
          wxID_ANY,
          wxDefaultPosition,
          wxDefaultSize,
            wxFULL_REPAINT_ON_RESIZE
          | wxTAB_TRAVERSAL
          );

  wxStaticBox* html_box = new wxStaticBox(
          _html_panel,
          wxID_ANY,
          GetwxStr("HTML help") );
  wxStaticBoxSizer* htmlpanel_sizer  = new wxStaticBoxSizer(
            html_box
          //, wxVERTICAL
          , wxHORIZONTAL
          );
  /*
  wxBoxSizer* htmlpanel_sizer  = new wxBoxSizer(
          wxVERTICAL );
  */
  _html_panel->SetSizer(htmlpanel_sizer);

  // starts html text within a panel to improve resizing
  wxPanel* htmltext_panel = new wxPanel(
          _html_panel,
          wxID_ANY,
          wxDefaultPosition,
          wxDefaultSize,
            wxFULL_REPAINT_ON_RESIZE
          | wxTAB_TRAVERSAL
          | wxRAISED_BORDER
          );

  wxBoxSizer* htmltext_sizer  = new wxBoxSizer(
          wxVERTICAL );

  htmltext_panel->SetSizer(htmltext_sizer);

  _htmltext = new wxHtmlWindow(
      htmltext_panel,
      wxID_ANY,
      wxDefaultPosition,
      //      wxDefaultSize,
      wxSize(300,300),
      wxHW_SCROLLBAR_AUTO);


  //      wxDefaultSize,
  //      wxHW_SCROLLBAR_AUTO);
  _htmltext-> SetBorders(1);

  htmltext_sizer->Add(_htmltext,  1,  wxALL | wxEXPAND, 0);
  htmltext_sizer->Fit(htmltext_panel);

  /*
  _htmltext-> LoadPage(GetwxStr("/home/karl/projects/Fluid_motif/Karl/doc/tokens.html"));
  */

  /*  htmltext->SetSize(htmltext->GetInternalRepresentation()->GetWidth(),
                    htmltext->GetInternalRepresentation()->GetHeight());
  */
  wxToolBar* tb = CreateToolbar(_html_panel);

  htmlpanel_sizer->Add(tb,  0,
                  wxLEFT
                | wxTOP
                | wxBOTTOM
                | wxEXPAND, 2);
  htmlpanel_sizer->Add(htmltext_panel
                  ,  1
                  ,  wxTOP | wxBOTTOM | wxRIGHT | wxEXPAND
                  , 2
                  );
  htmlpanel_sizer->Fit(_html_panel);
  _htmltext->Fit();

} // CreateHtmlPanel()


//-------------------------------------------------------
void MainFrame::CreateSettingsPanel(wxWindow* parent)
//            --------------------
{
  // Setting
  _settings_panel = new wxPanel(
          parent,
          wxID_ANY,
          wxDefaultPosition,
          wxDefaultSize,
            wxFULL_REPAINT_ON_RESIZE
          | wxTAB_TRAVERSAL
          );

  wxStaticBox* settings_box = new wxStaticBox(
          _settings_panel,
          wxID_ANY,
          GetwxStr("Program settings") );
  wxStaticBoxSizer* settingspanel_sizer  = new wxStaticBoxSizer(
            settings_box
          , wxVERTICAL
          //, wxHORIZONTAL
          );

  _settings_panel->SetSizer(settingspanel_sizer);
//  cout << GB_scripts_dir << endl;

  wxStaticText* scripts_label = new wxStaticText(_settings_panel,wxID_ANY,GetwxStr("Scripts path:"));

  wxDirPickerCtrl* scripts_path = new wxDirPickerCtrl(_settings_panel,
        wxID_ScriptsPath,
        GB_scripts_dir, GetwxStr("Scripts path"));

  wxStaticText* help_label = new wxStaticText(_settings_panel,wxID_ANY,GetwxStr("Help path:"));
  wxDirPickerCtrl* help_path = new wxDirPickerCtrl(_settings_panel,
        wxID_HelpPath,
        GB_help_dir, GetwxStr("Help path"));

  wxBoxSizer* scriptspath_sizer  = new wxBoxSizer(
            wxHORIZONTAL
          );
  scriptspath_sizer->Add(scripts_label,  0, wxEXPAND | wxALL, 5);
  scriptspath_sizer->Add(scripts_path,   1, wxEXPAND | wxALL, 5);

  wxBoxSizer* helppath_sizer  = new wxBoxSizer(
            wxHORIZONTAL
          );
  helppath_sizer->Add(help_label,     0, wxEXPAND | wxALL, 5);
  helppath_sizer->Add(help_path,      1, wxEXPAND | wxALL, 5);

  settingspanel_sizer->Add(scriptspath_sizer, 0, wxEXPAND | wxALL, 5);
  settingspanel_sizer->Add(helppath_sizer,    0, wxEXPAND | wxALL, 5);

  settingspanel_sizer->Fit(_settings_panel);

  scripts_path->SetPath(GB_scripts_dir);
  scripts_path->Update();

} // CreateSettingsPanel()



void MainFrame::OnClose(wxCloseEvent& event)
{
  CLASS_MESSAGE("closing main frame ...");

  // important: clear variables now before the childrens are deleted
  Vars.EmptyVariables();
  Destroy();
/*  cout << "OnClose " << endl;

    if ( event.CanVeto()  )
    {
        wxString msg("Closing AMILab");
        if ( wxMessageBox(msg, GetwxStr("Please confirm"),
                          wxICON_QUESTION | wxYES_NO) != wxYES )
        {
            event.Veto();
            //event.Skip();
            return;
        }
    }

//  printf("closing files \n");
  event.Skip();
//    Close(true);
*/
}

/*
//-----------------------------------------------------
void MainFrame::OnInternalIdle()
{
    if (wxUpdateUIEvent::CanUpdate(this))
        UpdateWindowUI(wxUPDATE_UI_FROMIDLE);
}
*/
//-----------------------------------------------------
void MainFrame::UpdateVarList()
{
  _var_list->Hide();

  _var_list->DeleteAllItems();
  boost::shared_ptr<wxArrayString> variables;

  // loop vars
  variables = Vars.SearchCompletions(GetwxStr(""));


  for(int i=0;i<(int)variables->GetCount();i++) {
    //cout << "set item variable " << i << endl;

    Variable* var;
    wxString type_str;
    bool varfound = Vars.GetVar((*variables)[i].mb_str(),&var);

    if (varfound) {
      // check for filter
      if ((_var_list_filter->GetValue().Cmp(_T("images"))==0) &&
          (var->Type() != type_image)) continue;

      if ((_var_list_filter->GetValue().Cmp(_T("surfaces"))==0) &&
          (var->Type() != type_surface)) continue;

      if ((_var_list_filter->GetValue().Cmp(_T("AMI functions"))==0) &&
          (var->Type() != type_ami_function)) continue;

      // add an item to the list
      long tmp =_var_list->InsertItem(i,(*variables)[i]);
      _var_list->SetItemData(tmp, i);
      _var_list->SetItem(tmp, 1, wxString( var->GetTypeName().c_str(),wxConvUTF8));

    } else

      if (_var_list_filter->GetValue().Cmp(_T("all"))==0) {
        // add an item to the list
        long tmp =_var_list->InsertItem(i,(*variables)[i]);
        _var_list->SetItemData(tmp, i);
        _var_list->SetItem(tmp, 1, wxString("deleted",wxConvUTF8));
      }

  }

  _var_list->SetColumnWidth( 0, wxLIST_AUTOSIZE );
  _var_list->SetColumnWidth( 1, wxLIST_AUTOSIZE );

//  _var_list->Fit();
  _var_list->Show();
}


//-----------------------------------------------------
void MainFrame::UpdateVarTree()
{
  // delete second level children
  wxTreeItemIdValue cookie;
  wxTreeItemId item = _var_tree->GetFirstChild( _vartree_root, cookie );
  while(item.IsOk()) {
    _var_tree->DeleteChildren(item);
    item = _var_tree->GetNextChild( _vartree_root, cookie);
  }


  boost::shared_ptr<wxArrayString> variables;

  // loop vars
  variables = Vars.SearchCompletions(GetwxStr(""));
  unsigned long total_image_size = 0;

  for(int i=0;i<(int)variables->GetCount();i++) {
    //cout << "set item variable " << i << endl;

    Variable* var;
    wxString type_str;
    bool varfound = Vars.GetVar((*variables)[i].mb_str(),&var);

    if (varfound) {
      if (var->Type() == type_image) {
        // create text with image information
        InrImage::ptr im = *((InrImage::ptr*)var->Pointer());
        std::string text = (boost::format("%1% %20t %2% %35t %3%x%4%x%5%  %55t %|6$+5| Mb")
                            % var->Name()
                            % im->FormatName()
                            % im->DimX()
                            % im->DimY()
                            % im->DimZ()
                            % (im->GetDataSize()/1000000)).str();
        //cout << text << endl;
        _var_tree->AppendItem(_vartree_images,wxString(text.c_str(), wxConvUTF8));
        total_image_size += im->GetDataSize();
      } else
      if (var->Type() == type_surface) {
        SurfacePoly::ptr surf = (*(SurfacePoly::ptr*)var->Pointer());
        std::string text = (boost::format("%1% %15t pts: %2% %25t poly:%3%")
                            % var->Name()
                            % surf->GetNumberOfPoints()
                            % surf->GetNumberOfPolys()).str();
        //cout << text << endl;
        _var_tree->AppendItem(_vartree_surfaces,wxString(text.c_str(), wxConvUTF8));
      } else
      if ((var->Type() == type_float)||
          (var->Type() == type_int)  ||
          (var->Type() == type_uchar))
      {
        _var_tree->AppendItem(_vartree_numbers,(*variables)[i]);
      } else
      if (var->Type() == type_string)
      {
        _var_tree->AppendItem(_vartree_strings,(*variables)[i]);
      } else
      if (var->Type() == type_ami_function)
      {
        _var_tree->AppendItem(_vartree_functions,(*variables)[i]);
      } else
      if (var->Type() == type_c_image_function)
      {
        _var_tree->AppendItem(_vartree_wrapped_functions,(*variables)[i]);
      } else
        _var_tree->AppendItem(_vartree_others,(*variables)[i]);
    }
  } // end for

  // Display the total size of images in Mb
  if (total_image_size != 0) {
    std::string text = (boost::format(" %45t total = %55t %|1$+5| Mb")
                        % (total_image_size/1000000)).str();
    _var_tree->AppendItem(_vartree_images,wxString(text.c_str(), wxConvUTF8));
  }

  _var_list->Show();
}


//---------------------------------------------------------------
void MainFrame::SetProgress( int val )
{
  _status_bar->SetProgress(val);
}

//---------------------------------------------------------------
void MainFrame::SetStatusText( const std::string& text )
{
  _status_bar->SetStatusText( GetwxStr(text.c_str()));
}

//---------------------------------------------------------------
void MainFrame::OnViewReset( wxCommandEvent& event )
{
  m_mgr.GetPane(_main_book).Show();
  m_mgr.GetPane(_log_text).Show();
  m_mgr.GetPane(_var_panel).Show();

  m_mgr.LoadPerspective(_initial_perspective);

//  cout << _param_book->GetPageCount()>0 << endl;
  m_mgr.GetPane(_param_book).Show(_param_book->GetPageCount()>0);
  m_mgr.Update();
}


//-----------------------------------------------------
void MainFrame::OnFileOpenImage    ( wxCommandEvent& event )
{
  int res;
  string name;
  string varname;
  string cmd; // increment the command line string

  res=AskImage(name);
  if (!res) {
    cerr << " Image not found " << endl;
    return;
  }

  res=AskVarName( this,
                  string("Image variable name"),
                  string("Enter name:"),
                  string("i"),
                  varname);
  if (!res) {
    cerr << " Var name error " << endl;
    return;
  }

  wxFileName filename(GetwxStr(name));
  filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
  wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                      filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                      filename.GetPathSeparator(wxPATH_UNIX)+
                      filename.GetFullName());

  cmd = varname + string(" = Image \"");
  cmd += newname.mb_str();
  cmd += string("\" // from menu");
  this->TC->IncCommand(cmd);
  this->TC->ProcessReturn();
}

//-----------------------------------------------------
void MainFrame::OnFileOpenPolydata ( wxCommandEvent& event )
{
  int res;
  string name;
  string varname;
  string cmd; // increment the command line string

  res=AskSurface(name);
  if (!res) {
    cerr << " Surface not found " << endl;
    return;
  }

  res=AskVarName(this,
        string("Surface variable name"),
        string("Enter name:"),
        string("s"),
        varname);
  if (!res) {
    cerr << " Var name error " << endl;
    return;
  }

  wxFileName filename(GetwxStr(name));
  filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
  wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                      filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                      filename.GetPathSeparator(wxPATH_UNIX)+
                      filename.GetFullName());

  cmd = varname + string(" = Surface \"");
  cmd += newname.mb_str();
  cmd += string("\" // from menu");
  this->TC->IncCommand(cmd);
  this->TC->ProcessReturn();
}

//-----------------------------------------------------
void MainFrame::OnFileLoadScript   ( wxCommandEvent& event )
{
  //cout << "Load script" << endl;
  int res;
  string name;
  string cmd; // increment the command line string

  res=AskScript(name);
  if (!res) {
    cerr << " Script filename not found " << endl;
    return;
  }

  wxFileName filename(GetwxStr(name));
  filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
  wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                      filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                      filename.GetPathSeparator(wxPATH_UNIX)+
                      filename.GetFullName());

  cmd = string("func \"");
  cmd += newname.mb_str();
  cmd += string("\" // from menu");
  this->TC->IncCommand(cmd);
  this->TC->ProcessReturn();
}

//-----------------------------------------------------
void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
  Close(true);
}


//-----------------------------------------------------
void MainFrame::OnHelpTokens(  wxCommandEvent& event)
{
  wxFileName tokens(GB_help_dir,_T("tokens.html"));
  _htmltext->LoadPage(tokens.GetFullPath());
//  _htmltext->LoadPage("http://amilab.sourceforge.net");
} // OnHelpTokens()


//-----------------------------------------------------
void MainFrame::OnHelpRules(  wxCommandEvent& event)
{
  wxFileName rules(GB_help_dir,_T("rules.html"));
  _htmltext->LoadPage(rules.GetFullPath());
} // OnHelpRules()


//-----------------------------------------------------
void MainFrame::OnHelpScripts(  wxCommandEvent& event)
{
  wxFileName scripts(GB_help_dir,_T("docamil_scripts.html"));
  _htmltext->LoadPage(scripts.GetFullPath());
} // OnHelpScrips()


//-----------------------------------------------------
void MainFrame::OnHelpBack(  wxCommandEvent& event)
{
  _htmltext->HistoryBack();
} // OnHelpBack()


//-----------------------------------------------------
void MainFrame::OnHelpForward(wxCommandEvent& event)
{
  _htmltext->HistoryForward();
} // OnHelpForward()

//--------------------------------------------------
#if (wxCHECK_VERSION(2,9,0))
  void MainFrame::ConsoleReset( wxCommandEvent& event)
#else
  void MainFrame::ConsoleReset( wxAuiToolBarEvent& event)
#endif
{
  TC->ConsoleReset();
  //UpdateVarList();
}

//--------------------------------------------------
void MainFrame::ConsoleClear( wxCommandEvent& event)
{
  TC->ConsoleClear();
}

//--------------------------------------------------
void MainFrame::UpdateVars( wxCommandEvent& event)
{
  UpdateVarList();
  UpdateVarTree();
}

//--------------------------------------------------
void MainFrame::OnToolHelp( wxCommandEvent& event)
{
  wxLaunchDefaultBrowser(_T("http://amilab.sourceforge.net:80/dokuwiki/doku.php?id=Help"));
}

//--------------------------------------------------
void MainFrame::VarListRightClick( wxListEvent& event)
{
  cout << "Right click on item \n";
}

//--------------------------------------------------
void MainFrame::OnScriptsPath( wxFileDirPickerEvent& event)
{
  cout << "Scripts path changed" << endl;
  GB_scripts_dir = event.GetPath();
}

//--------------------------------------------------
void MainFrame::OnHelpPath   ( wxFileDirPickerEvent& event)
{
  cout << "Help path changed" << endl;
  GB_help_dir = event.GetPath();
}


//--------------------------------------------------
void MainFrame::AddMenuScript(  const std::string& script_category,
                                const std::string& script_label,
                                const std::string& script_name)
{
  wxMenu* parent = menuScripts;

  usermenu_id++;
  usermenu_scripts[usermenu_id] = script_name;
  // first try to find the menu corresponding to the given category
  int menuid = menuScripts->FindItem(wxString(script_category.c_str(), wxConvUTF8));
  if (menuid != wxNOT_FOUND) {
    // category found, adding as submenu
    //cout << "category found" << endl;
    wxMenuItem* menuitem = menuScripts->FindItem(menuid);
    if (menuitem!=NULL) {
      if (menuitem->GetSubMenu())
        parent = menuitem->GetSubMenu();
      else
        parent = menuitem->GetMenu();
    }
  } else {
    if (script_category.length()>1) {
      wxMenu* newsubmenu = new wxMenu;
      // add new category
      menuScripts->AppendSubMenu( newsubmenu,   GetwxStr(script_category.c_str()));
      parent = newsubmenu;
    }
  }
  // adding script
  parent->Append(usermenu_id, GetwxStr(script_label.c_str()));

  // connecting
  Connect(usermenu_id,wxEVT_COMMAND_MENU_SELECTED,
     wxCommandEventHandler(MainFrame::OnUserMenuScript));
  
}

//--------------------------------------------------
void MainFrame::OnUserMenuScript(  wxCommandEvent& event)
{
  cout << "MainFrame::OnUserMenuScript() ";
  cout << "GetId() = "<< event.GetId() << endl;
  cout << "script = " << usermenu_scripts[event.GetId()] << endl;
  string cmd; // increment the command line string
  cmd = (boost::format("func \"%1%\" // from menu") % usermenu_scripts[event.GetId()]).str();
  TC->ConsoleClear();
  this->TC->IncCommand(cmd);
  this->TC->ProcessReturn();
}

