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

#include "wx/app.h"
#include "wx/grid.h"
#include "wx/spinctrl.h"
#include "wx/artprov.h"
#include "wx/clipbrd.h"
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
#include <wx/gauge.h>
#include <iostream>
#include <cstring>
#ifndef AMI_USE_DATAVIEW
  #include "myTreeCtrl.h"
#endif
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
#include "LoadImage_Icon3.xpm"

#include "amilab_messages.h"
#include "about.xpm"

#include "surface.hpp"
using namespace amilab;

#include "ami_object.h"
#include "wxStcFrame.h"
#include "ParamPanel.hpp"

#include "wrapfunction_class.h"
#include <map>
#include <string>

//#include "Bluecurve/32x32/actions/reload.xpm"

#include "AMILabConfigure.h"
AMILab_VAR_IMPORT wxString    GB_scripts_dir;
AMILab_VAR_IMPORT wxString    GB_help_dir;
AMILab_VAR_IMPORT MainFrame*  GB_main_wxFrame;
AMILab_VAR_IMPORT wxApp*      GB_wxApp;
AMILab_VAR_IMPORT wxConfig*   GB_Config;

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

// limit the recursions since we don't check for loops
#define MAX_VARTREE_LEVEL 10

// in function.cpp
int AskScript(std::string& name);
int AskImage(std::string& name);
int AskVarName(wxWindow*,
               const std::string title, 
               const std::string label,
               const std::string def, 
               std::string& name);
int AskSurface(     std::string& name);




enum
{
    ID_File_OpenImage=200,
    ID_File_OpenPolydata,
    ID_File_LoadScript,
    ID_View_Reset,
    ID_View_Output,
    ID_View_Param_book,
    ID_View_Main_book,
    ID_View_Var_book,
    ID_View_aui_Main_bar,
    ID_View_aui_Script_bar,
    ID_View_aui_Status_bar,
    wxID_HelpTokens,
    wxID_HelpRules,
    wxID_HelpScripts,
    wxID_HelpBack,
    wxID_HelpForward,
    
    ID_Help_View,
    ID_Help_Keywords,
//    ID_Help_About,

    wxID_ProgressBar,
    ID_CloseAboutPanel,
    ID_kp_textCtrl,
    ID_sample,
};

enum {
  wxID_ScriptsPath = 300,
  wxID_HelpPath
};

enum {
    wxID_Images_History  = 400,
    wxID_Scripts_History = 450
};

enum {
  wxID_ConsoleReset = 600,
  wxID_ConsoleClear,
  wxID_UpdateVars,
  wxID_ToolLoadImage,
  wxID_ToolHelp,
  wxID_ToolQuit,
  wxID_VarList,
  wxID_VarList_Filter,
};

//========================================================================
// CustomAboutMenu Class
//========================================================================

//------------------------------------------------------------------------
void CustomAboutMenu::OnClose(wxCommandEvent& event )
{
  this->Show(false);
}

//------------------------------------------------------------------------
CustomAboutMenu::CustomAboutMenu(wxWindow* parent)
{
    wxBoxSizer *BoxSizer1,*BoxSizer2,*BoxSizer4,*BoxSizer5,*BoxSizer6,*BoxSizer7;

    Create(parent, wxID_ANY, _("About ..."), wxDefaultPosition, wxSize(-1,-1), 
           wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));

    //dialogAbout->SetSize(wxSize(200,400));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);

    wxStaticBitmap* StaticBitmap1 = new wxStaticBitmap( 
          this,
          wxID_ANY, wxBitmap(about_xpm),  
          // wxBitmap((wxImage(amilab_splash_xpm)).Rescale(350,200))*/
          wxDefaultPosition, wxDefaultSize,
          0, 
          _T("ID_STATICBITMAP1"));

    BoxSizer2->Add(StaticBitmap1, 1, 
                   wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 
                   5);
    
    BoxSizer1->Add(BoxSizer2,     0, 
                   wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL,
                   4);

    wxNotebook* Notebook1 = new wxNotebook(this, wxID_ANY, 
                                           wxDefaultPosition, wxSize(-1,260), 
                                           1, _T("ID_NOTEBOOK1"));
    wxPanel* Panel1 = new wxPanel(Notebook1, wxID_ANY, 
                                  wxDefaultPosition, 
                                  wxDefaultSize, 
                                  wxTAB_TRAVERSAL|wxRESIZE_BORDER, 
                                  _T("ID_PANEL1"));
    wxPanel* Panel2 = new wxPanel(Notebook1, wxID_ANY, 
                                  wxDefaultPosition, 
                                  wxDefaultSize, 
                                  wxTAB_TRAVERSAL|wxRESIZE_BORDER, 
                                  _T("ID_PANEL2"));
    wxPanel* Panel3 = new wxPanel(Notebook1, wxID_ANY, 
                                  wxDefaultPosition, wxDefaultSize, 
                                  wxTAB_TRAVERSAL|wxRESIZE_BORDER, 
                                  _T("ID_PANEL3"));
    wxPanel* Panel4 = new wxPanel(Notebook1, wxID_ANY, 
                                  wxDefaultPosition, wxDefaultSize, 
                                  wxTAB_TRAVERSAL|wxRESIZE_BORDER, 
                                  _T("ID_PANEL4"));
       
    Notebook1->AddPage(Panel1, _("Description"), false);
    Notebook1->AddPage(Panel2, _("Info"),        false);
    Notebook1->AddPage(Panel3, _("Thanks"),      false);
    Notebook1->AddPage(Panel4, _("License"),     false);

    BoxSizer1->Add(Notebook1, 1, 
                   wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 
                   5);

    wxButton* Button2 = new wxButton(this, ID_CloseAboutPanel, _("Quit"));

    BoxSizer1->Add(Button2, 0, 
                   wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 
                   4);

    this->SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);


    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *StaticText4 = new wxStaticText(Panel4, wxID_ANY, 
          _("This program is licensed under the terms\nof the LGPL license"));
    //GNU General Public License version 3\n\nAvailable online under:\nhttp://www.gnu.org/licenses/gpl-3.0.html"));
    BoxSizer4->Add(StaticText4, 1, wxALL, 5);
    Panel4->SetSizer(BoxSizer4);
    
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *StaticText3 = new wxStaticText(Panel3, wxID_ANY, _(
      "\n\
    Active Developers:\n\
        Karl Krissian      : Developer - Project leader\n\
        Francisco Santana  : Developer\n\
        Daniel E. Santana  : Developer\n\
        Carlos M. Falcón   : Developer\n\
        Sara Illera        : Developer\n\
        \n\
    Contributors and previous developers:\n\
        Luis Álvarez\n\
        Sara Arencibia\n\
        Claire Chalopin\n\
        Agustín Trujillo\n\
        "));
    BoxSizer5->Add(StaticText3, 1, wxALL, 5);
    Panel3->SetSizer(BoxSizer5);

    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *StaticText2 = new wxStaticText(Panel2, wxID_ANY,
                                                 GetwxStr("Name: AMIlab\n")+
                                                 GetwxStr("Version:")+GetwxStr(AMILAB_VERSION)+GetwxStr("\n")+
                                                 GetwxStr("Author: AMILab Team\n")+
                                                 GetwxStr("Contact: amilab@ctim.es\n")+
                                                 GetwxStr("         www.amilab.org\n"));
    BoxSizer6->Add(StaticText2, 1, wxALL, 5);
    Panel2->SetSizer(BoxSizer6);
    
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *StaticText1 = new wxStaticText(Panel1, wxID_ANY, _(
      "AMILab is an interpreted language for image processing designed using:\n\
      - C/C++\n\
      - Flex and Bison (gnu versions of Lex and Yacc)\n\
      - wxWidgets\n\
      - OpenGL\n\
      - VTK\n\
      - ITK\n\
      AMILab has a lot a features, and has been especially used for academic research in medical image processing. The tool is under development.\n\
      Visit amilab.org for more information about AMILab\n"));
    BoxSizer7->Add(StaticText1, 1, wxALL, 5);
    Panel1->SetSizer(BoxSizer7);
    
    
    Connect(ID_CloseAboutPanel,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CustomAboutMenu::OnClose);
}




BEGIN_EVENT_TABLE(MainFrame, wxFrame)

/*EVT_TEXT_ENTER*/EVT_TEXT(ID_kp_textCtrl, MainFrame::OnFindKeywords)
    EVT_MENU(ID_File_OpenImage,    MainFrame::OnFileOpenImage)
    EVT_MENU_RANGE(wxID_Images_History, wxID_Images_History+8, MainFrame::OnFileOpenImageHistory)

    EVT_MENU(ID_File_OpenPolydata, MainFrame::OnFileOpenPolydata)

    EVT_MENU(ID_File_LoadScript,   MainFrame::OnFileLoadScript)
    EVT_MENU_RANGE(wxID_Scripts_History, wxID_Scripts_History+8, MainFrame::OnFileOpenScriptHistory)

    EVT_MENU(wxID_EXIT,              MainFrame::OnQuit)

    EVT_MENU(ID_View_Reset,        MainFrame::OnViewReset)
    EVT_MENU(ID_View_Var_book,     MainFrame::OnViewVar_book)
    EVT_MENU(ID_View_Main_book,    MainFrame::OnViewMain_book)
    EVT_MENU(ID_View_Output,       MainFrame::OnViewOutput)
    EVT_MENU(ID_View_Param_book,   MainFrame::OnViewParam_book)
    
    EVT_MENU(ID_View_aui_Main_bar,      MainFrame::OnViewMain_bar)
    EVT_MENU(ID_View_aui_Status_bar,    MainFrame::OnViewMain_bar2)
    EVT_MENU(ID_View_aui_Script_bar,    MainFrame::OnViewScript_bar)
    
    EVT_MENU(ID_Help_Keywords,      MainFrame::OnHelpKeywords)
    
    EVT_MENU(wxID_ABOUT,            MainFrame::OnAbout)
    EVT_CLOSE(MainFrame::OnClose)
    
    EVT_UPDATE_UI(wxID_ANY,MainFrame::OnUpdate)
   //EVT_BUTTON(ID_CloseAboutPanel, MainFrame::OnCloseAboutPanel) 
//    EVT_BUTTON(wxID_ConsoleReset, MainFrame::ConsoleReset)
    EVT_TOOL(wxID_ToolLoadImage, MainFrame::OnFileOpenImage)
    EVT_TOOL(wxID_ConsoleClear, MainFrame::ConsoleClear)
#if (wxCHECK_VERSION(2,9,0))
    EVT_TOOL_RCLICKED(wxID_ConsoleClear, MainFrame::ConsoleReset)
#else
    EVT_AUITOOLBAR_RIGHT_CLICK(wxID_ConsoleClear, MainFrame::ConsoleReset)
#endif
    EVT_TOOL(wxID_UpdateVars,   MainFrame::CB_UpdateVars)
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

    EVT_COMBOBOX(wxID_VarList_Filter, MainFrame::CB_UpdateVars)

    EVT_DIRPICKER_CHANGED(wxID_ScriptsPath, MainFrame::OnScriptsPath)
    EVT_DIRPICKER_CHANGED(wxID_HelpPath,    MainFrame::OnHelpPath   )

///@cond wxCHECK
#if (wxCHECK_VERSION(2,9,1) && wxUSE_FILECTRL)
    EVT_FILECTRL_FILEACTIVATED( wxID_ANY, MainFrame::OnFileCtrl )
#endif

END_EVENT_TABLE()


//static int CompareStringLen(const wxString& first, const wxString& second)
//{
//    return second.CmpNoCase(first);
//}

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
  dialogAbout= new CustomAboutMenu(this); 
  // Images and Scripts history
  images_history = boost::shared_ptr<wxFileHistory>(
    new wxFileHistory(9,wxID_Images_History));

  scripts_history = boost::shared_ptr<wxFileHistory>(
    new wxFileHistory(9,wxID_Scripts_History));

  GB_Config->SetPath(wxT("/ImagesHistory"));
  images_history->Load(*GB_Config);
  GB_Config->SetPath(wxT("/ScriptsHistory"));
  scripts_history->Load(*GB_Config);

  images_history_menu  = new wxMenu;
  scripts_history_menu = new wxMenu;
  images_history->UseMenu( images_history_menu);
  images_history->AddFilesToMenu();
  scripts_history->UseMenu(scripts_history_menu);
  scripts_history->AddFilesToMenu();

  menuFile = new wxMenu;
  menuFile->Append( ID_File_OpenImage,    GetwxStr("Open &image") );
  menuFile->AppendSubMenu( images_history_menu, GetwxStr("Recent images"));
  menuFile->Append( ID_File_OpenPolydata, GetwxStr("Open &polydata") );
  menuFile->Append( ID_File_LoadScript, GetwxStr("Load &script") );
  menuFile->AppendSubMenu( scripts_history_menu, GetwxStr("Recent scripts"));

  menuFile->Append( wxID_EXIT, GetwxStr("E&xit") );

  menuView = new wxMenu;
  menuView2 = new wxMenu;
  menuView3 = new wxMenu;
  
  menuView->Append( ID_View_Reset, GetwxStr("&Reset") );
  menuView->InsertSeparator(1);
    
  menuView->AppendSubMenu(menuView2, GetwxStr("&Panels"));
  menuView->AppendSubMenu(menuView3, GetwxStr("&Tool bars"));
    
  //menuView2->AppendCheckItem(ID_View_Main_book,  GetwxStr("&Main book"));
  //menuView2->Check(ID_View_Main_book, true);
  menuView2->AppendCheckItem(ID_View_Var_book,  GetwxStr("&Variables tree"));
  menuView2->Check(ID_View_Var_book, true);
  menuView2->AppendCheckItem(ID_View_Output,  GetwxStr("&Output"));
  menuView2->Check(ID_View_Output, true);
  menuView2->AppendCheckItem(ID_View_Param_book,  GetwxStr("&Param book"));
  menuView2->Check(ID_View_Param_book, false);
  menuView3->AppendCheckItem(ID_View_aui_Main_bar,  GetwxStr("&Main toolbar"));
  menuView3->Check(ID_View_aui_Main_bar, true);
  
  menuView3->AppendCheckItem(ID_View_aui_Script_bar,  GetwxStr("&Script toolbar"));
  menuView3->Check(ID_View_aui_Script_bar, true);
  
  menuView3->AppendCheckItem(ID_View_aui_Status_bar,  GetwxStr("&Status toolbar"));
  menuView3->Check(ID_View_aui_Status_bar, true);
  

  menuHelp = new wxMenu;
  //menuHelp->Append( ID_Help_View, GetwxStr("What's This?") );
  menuHelp->Append( ID_Help_Keywords, GetwxStr("Keywords") );  
  menuHelp->AppendSeparator();
  menuHelp->Append( wxID_ABOUT, GetwxStr("About ...") );  
  
  menuScripts = new wxMenu;


  menuBar = new wxMenuBar;
  menuBar->Append( menuFile,    GetwxStr("&File") );
  menuBar->Append( menuView,    GetwxStr("&View") );
  menuBar->Append( menuScripts, GetwxStr("&Scripts") );
  //menuBar->Append( menuScripts, GetwxStr("&Scripts") );
  //menuBar->Append( menuScripts, GetwxStr("&Scripts") );
  menuBar->Append( menuHelp, GetwxStr("&Help") );
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
                  size),
                  amilab_editor(NULL)
{

  SetUpdatingDataView(false);
//  CreateToolbar();
  m_mgr.SetManagedWindow(this);

  CreateMenu();

  m_mgr.SetFlags( 
                  wxAUI_MGR_ALLOW_FLOATING |
                  // Avoid problem with KDE desktop composing effect
                  #if defined(__WXGTK__) && !(wxCHECK_VERSION(2,9,4))
                    wxAUI_MGR_VENETIAN_BLINDS_HINT |
                      //wxAUI_MGR_RECTANGLE_HINT |
                  #else
                    wxAUI_MGR_TRANSPARENT_HINT |
                  #endif
                  wxAUI_MGR_HINT_FADE |
                  wxAUI_MGR_NO_VENETIAN_BLINDS_FADE |
                  wxAUI_MGR_ALLOW_ACTIVE_PANE |
                  wxAUI_MGR_LIVE_RESIZE
                );
  
  // Set Sash size big enough to be able to resize easily the different panels
  m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_SASH_SIZE,4);
  
     // tell the manager to "commit" all the changes just made

  CreateMainBook(this);
  m_mgr.AddPane(_main_book,  wxAuiPaneInfo()
                  .Name(wxT("Main Book"))
                  //.MinSize(wxSize(200,200))
                  .Center()
                  .CloseButton(false)
                  .MaximizeButton(true));

/// @cond wxCHECK

  CreateVarBook(this);
  
#if wxCHECK_VERSION(2,9,0)
  CreateVarDataViewPanel(this);
#else
  CreateVarTreePanel(this);
#endif
  CreateVarDirCtrl(this);

  /// @endcond
  m_mgr.AddPane(_var_book,
                  wxAuiPaneInfo()
                  .Name(wxT("VariablesTree"))
                  .Caption(wxT("Variables Tree"))
                  .Left().Layer(1)
                  .MaximizeButton(true)
                  .BestSize(wxSize(200,200)));

  CreateLogText(this);
  m_mgr.AddPane(_log_text,
                  wxAuiPaneInfo()
                  .Name(wxT("Log"))
                  .Caption(wxT("Output"))
                  .Bottom()
                  .MaximizeButton(true)
                  .MinSize(wxSize(100,50)));

  CreateParamBook(this);
  m_mgr.AddPane(_param_book,
                  wxAuiPaneInfo()
                  .Name(wxT("Param Book"))
                  .Caption(wxT("User Interface"))
                  .MinSize(wxSize(200,100))
                  .BestSize(wxSize(300,100))
                  .Right().Layer(1)
                  .MaximizeButton(true)
                  .PinButton(true)
                  .Hide());
  
  CreateKeywordsPanel(this); 
  m_mgr.AddPane(_keywords_panel,
                  wxAuiPaneInfo()
                  .Name(wxT("Keywords"))
                  .Caption(wxT("Keywords"))
                  .MinSize(wxSize(220,300))
                  .BestSize(wxSize(220,300))
                  .Floatable()
                  .MaximizeButton(false)
                  .Hide());
  
  /// @cond wxCHECK

    // create some toolbars
  #if (wxCHECK_VERSION(2,9,0)) && !WIN32 && (!__WXMAC__)
    tb1 = new wxAuiToolBar(this, ID_View_aui_Main_bar,
                        wxDefaultPosition, wxDefaultSize,
                        wxAUI_TB_DEFAULT_STYLE |
                        wxAUI_TB_OVERFLOW);
   
    tb2 = new wxAuiToolBar(this, ID_View_aui_Main_bar,
                    wxDefaultPosition, wxDefaultSize,
                    wxAUI_TB_DEFAULT_STYLE |
                    wxAUI_TB_OVERFLOW);
    
  #else
    tb1 = new wxAuiToolBar(this, ID_View_aui_Main_bar,
                        wxDefaultPosition, wxDefaultSize,
                        wxAUI_TB_DEFAULT_STYLE |
                        wxAUI_TB_OVERFLOW);
    tb2 = new wxAuiToolBar(this, ID_View_aui_Status_bar,
                        wxDefaultPosition, wxDefaultSize,
                        wxAUI_TB_DEFAULT_STYLE |
                        wxAUI_TB_OVERFLOW); 
  #endif
  /// @endcond


  _status_bar = new CustomStatusBar(this,wxID_ANY);
  SetStatusBar(_status_bar);
  _status_bar->SetProgress(0);

  Centre(wxBOTH);

}


//------------------------------------------------------------------------
wxStcFrame* MainFrame::GetAmilabEditor()
{
  if (!GetChildren().Find(amilab_editor)) {
    amilab_editor = new wxStcFrame ( this, wxT("AMILab Editor"));    
  }
  return amilab_editor;  
}

//------------------------------------------------------------------------
void MainFrame::CreateMainBook(wxWindow* parent)
{
   // create the notebook off-window to avoid flicker
   wxSize client_size = GetClientSize();

   _main_book = new wxAuiNotebook(this, wxID_ANY,
                                    wxPoint(client_size.x, client_size.y),
                                    wxDefaultSize,
                                    wxAUI_NB_TOP          
                                    #if !defined(__WXGTK__) || (wxCHECK_VERSION(2,9,4))
                                      |wxAUI_NB_TAB_SPLIT
                                    #endif
                                    |wxAUI_NB_TAB_MOVE     
                                    |wxAUI_NB_WINDOWLIST_BUTTON
                                    |wxAUI_NB_SCROLL_BUTTONS
                                  );

   wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16));

  CreateConsoleText(this);
  _main_book->AddPage( _prompt_panel,  wxT("Console"), false, page_bmp );

//  CreateHtmlPanel(this);
//  _main_book->AddPage( _html_panel , wxT("Help") );
  

//  CreateSettingsPanel(this);
//  _main_book->AddPage( _settings_panel , wxT("Paths") );
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
                                     wxAUI_NB_TOP
                                    #if !defined(__WXGTK__) || (wxCHECK_VERSION(2,9,4))
                                      |wxAUI_NB_TAB_SPLIT
                                    #endif
                                    |wxAUI_NB_TAB_MOVE     
                                    |wxAUI_NB_SCROLL_BUTTONS
                                    |wxAUI_NB_WINDOWLIST_BUTTON
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
bool MainFrame::AddParamPanelPage(const ParamPanel::ptr& page, const wxString& caption,
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
bool MainFrame::RemoveParamPanelPage(const ParamPanel::ptr& page)
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
void MainFrame::CreateVarBook ( wxWindow* parent)
{
   wxSize client_size = GetClientSize();

   _var_book  = new wxAuiNotebook(parent, wxID_ANY,
                                    wxPoint(client_size.x, client_size.y),
                                                //wxDefaultPosition,
                                    wxDefaultSize,
                                    wxAUI_NB_TOP
                                    #ifndef __WXGTK__
                                      |wxAUI_NB_TAB_SPLIT
                                    #else
                                      #if wxCHECK_VERSION(2,9,4)
                                        |wxAUI_NB_TAB_SPLIT
                                      #endif
                                    #endif
                                    |wxAUI_NB_TAB_MOVE     
                                    |wxAUI_NB_WINDOWLIST_BUTTON
                                    |wxAUI_NB_SCROLL_BUTTONS);
  _var_book->Fit();

} // CreateVarBook()

//--------------------------------------------------------
void MainFrame::CreateVarDirCtrl ( wxWindow* parent)
{
  // File Selection
  typedef std::pair<std::string,std::string> file_format;
  typedef std::map<std::string,std::string>  file_format_map;

  std::map<std::string,std::string> formats;

  formats.insert(file_format( "All ext",
                              "*.*"));
  formats.insert(file_format( "Amilab Images",
                              "*.ami;*.ami.gz"));
  formats.insert(file_format( "Amilab scripts",
                              "*.amil"));
  formats.insert(file_format( "VTK Files",
                              "*.vtk"));
  formats.insert(file_format( "Standard images",
                              "*.jpg;*.JPG;*.jpeg;*.JPEG;*.png;*.PNG;*.bmp;*.BMP;*.tif;*.TIF;*.tiff;*.TIFF;*.nhdr"));
  formats.insert(file_format( "ITK",
                              "*.mhd"));
  formats.insert(file_format( "All",
                              "*"));

  wxString format_choices;

  for(file_format_map::iterator p = formats.begin();
      p!=formats.end();
      ++p)
  {
    if (p!=formats.begin())
      format_choices << wxString("|", wxConvUTF8);
    format_choices << wxString(str(boost::format(" %1% (%2%) |%2%") 
      % p->first % p->second).c_str(), wxConvUTF8);
  }

// @cond wxCHECK
#if (wxCHECK_VERSION(2,9,1) && (wxUSE_FILECTRL))
  _var_fileCtrl = new wxFileCtrl(parent,wxID_ANY,
                     wxEmptyString,
                     wxEmptyString,
                     format_choices,
                     wxFC_OPEN,
                     wxDefaultPosition,
                     wxDefaultSize
                 );
#endif
// @endcond
  _var_dirctrl = new wxGenericDirCtrl(parent,wxID_ANY,
                      wxDirDialogDefaultFolderStr,
                      wxDefaultPosition,
                      wxDefaultSize,
                      wxDIRCTRL_3D_INTERNAL
                      |
                      //wxBORDER_SUNKEN
                      //|
                      wxDIRCTRL_SHOW_FILTERS
                      #if (wxCHECK_VERSION(2,9,1))
                        |
                        wxDIRCTRL_MULTIPLE
                      #endif // wxCHECK_VERSION(2,9,1)
                      ,
                      format_choices, // filters
                      0 // default filter
                      );

  // try to allow multiple selections
  //_var_dirctrl->GetTreeCtrl()->SetWindowStyle(_var_dirctrl->GetTreeCtrl()->SetWindowStyle() |wxTR_EXTENDED);

  _var_dirctrl->GetTreeCtrl()->Connect(wxEVT_COMMAND_TREE_ITEM_ACTIVATED,
                                       wxCommandEventHandler(MainFrame::OnFileActivated),NULL,this);

  _var_book->AddPage(_var_dirctrl,wxT("Dir"));

// @cond wxCHECK
#if (wxCHECK_VERSION(2,9,1) && (wxUSE_FILECTRL)) 
  _var_book->AddPage(_var_fileCtrl,wxT("File"));
#endif
// @endcond

  //std::cout << res << std::endl;
  _var_book->Fit();

} // CreateVarDirCtrl 

//--------------------------------------------------------
void MainFrame::CreateVarTreePanel ( wxWindow* parent)
{
#if (!wxCHECK_VERSION(2,9,0))
//  CreateDrawingPanel(this);
//  _main_book->AddPage( _drawing_panel , wxT("Drawing") );


  // Add TreeList Page to notebook
//   _vartree_panel = new wxPanel(this);
//   
//   vartreepanel_sizer  = new wxBoxSizer( wxVERTICAL );
//   _vartree_panel->SetSizer(vartreepanel_sizer);

//   _var_tree = new myTreeCtrl( _vartree_panel,
  _var_tree = new myTreeCtrl( _var_book,
                              wxID_ANY,
                              wxDefaultPosition,
                              wxDefaultSize,
                              ((
                              wxTR_HAS_BUTTONS 
                              | wxTR_HIDE_ROOT 
                              | wxTR_FULL_ROW_HIGHLIGHT 
                              | wxTR_LINES_AT_ROOT
                              ) 
                              & (~wxTR_NO_LINES))  ^ wxTR_COLUMN_LINES 
                            );

  _vartree_col_main = _var_tree->GetColumnCount();
  _var_tree->AddColumn (_T("Name"), 250, wxALIGN_LEFT);
  _var_tree->SetColumnEditable (_vartree_col_main, false);

  _vartree_col_type = _var_tree->GetColumnCount();
  _var_tree->AddColumn (_T("Type"), 100, wxALIGN_CENTER);
  _var_tree->SetColumnEditable (_vartree_col_type, false);

  _vartree_col_val = _var_tree->GetColumnCount();
  _var_tree->AddColumn (_T("Val"), 60, wxALIGN_CENTER);
  _var_tree->SetColumnEditable (_vartree_col_val, false);

  _vartree_col_desc = _var_tree->GetColumnCount();
  _var_tree->AddColumn (_T("Details"), 250, wxALIGN_CENTER);
  _var_tree->SetColumnEditable (_vartree_col_desc, false);

  // TODO/FIXME:
  // Problems with GetWindowStyle method.
  
// @cond wxCHECK
//#if (wxCHECK_VERSION(2,9,1))
//  _var_tree->SetWindowStyle(wxTR_NO_LINES ^ wxTR_COLUMN_LINES);
//#else
//  _var_tree->SetWindowStyle(_var_tree->GetWindowStyle() ^ wxTR_NO_LINES ^ wxTR_COLUMN_LINES);
//#endif
// @endcond
  //_var_tree->SetToolTip(_T("Tree Control for current variables"));

  wxFont font(10,wxMODERN,wxNORMAL,wxNORMAL);
  if (font.IsOk())
    _var_tree->SetFont(font ); // try a fixed pitch font
  else 
    _var_tree->SetFont(*wxSMALL_FONT);
  _var_tree->SetIndent(2);

  _vartree_root        = _var_tree->AddRoot(_T("Root"));
  _vartree_global      = _var_tree->AppendItem(_vartree_root,_T("Global"));
  _vartree_builtin     = _var_tree->AppendItem(_vartree_root,_T("Builtin"));

//   vartreepanel_sizer->Add(_var_tree, 1, wxEXPAND , 5);
//   vartreepanel_sizer->Fit(_vartree_panel);

  _var_book->AddPage(_var_tree,wxT("Tree"));

#endif // #if (!wxCHECK_VERSION(2,9,0))

  
} // CreateVarTreePanel()


//--------------------------------------------------------
void MainFrame::OnFileActivated(wxCommandEvent& WXUNUSED(event))
{
  #if (wxCHECK_VERSION(2,9,1))
    wxArrayString paths;
    wxString filename;
    _var_dirctrl->GetFilePaths(paths);
    for (size_t n=0; n<paths.GetCount(); n++ )
    {
      filename = paths[n];
      if (filename != wxEmptyString) {
        //std::cout << filename.mb_str(wxConvUTF8)<< "Activated !!!" << std::endl;
        TryToOpenImage(filename);
      }
    }
  #else// (wxCHECK_VERSION(2,9,1))
    wxString filename = _var_dirctrl->GetFilePath();
    if (filename != wxEmptyString) {
      //std::cout << filename.mb_str(wxConvUTF8)<< "Activated !!!" << std::endl;
      TryToOpenImage(filename);
    }
  #endif // (wxCHECK_VERSION(2,9,1))
}

///@cond wxCHECK
#if (wxCHECK_VERSION(2,9,1) && wxUSE_FILECTRL)
//--------------------------------------------------------
void MainFrame::OnFileCtrl( wxFileCtrlEvent& event )
{
  // Some documentation
  // On wxEVT_FILECTRL_FILEACTIVATED, GetDirectory returns the current directory
  // for the wxFileCtrl and GetFiles returns the names of the file(s) activated.
  wxArrayString paths;
  wxString filename;
  _var_fileCtrl->GetPaths(paths);
  for (size_t n=0; n<paths.GetCount(); n++ )
  {
    filename = paths[n];
    if (filename != wxEmptyString) {
      //std::cout << filename.mb_str(wxConvUTF8)<< "Activated !!!" << std::endl;
      TryToOpenImage(filename);
    }
  }
} // OnFileCtrl
#endif
///@endcond

///@cond wxCHECK

#if wxCHECK_VERSION(2,9,0)
//--------------------------------------------------------
void MainFrame::CreateVarDataViewPanel( wxWindow* parent)
{

  
   _vardataview_panel = new wxPanel(_var_book);
   vardataviewpanel_sizer  = new wxBoxSizer( wxVERTICAL );
   _vardataview_panel->SetSizer(vardataviewpanel_sizer);
  
//  _var_dataview = new myDataViewCtrl( _vardataview_panel,
  _var_dataview = new myDataViewTreeListCtrl( _vardataview_panel,
                              wxID_ANY,
                              wxDefaultPosition,
                              wxDefaultSize,
                              wxDV_ROW_LINES | 
                              wxDV_HORIZ_RULES |
                              wxDV_VERT_RULES
                            );


  _var_dataview->GetColumn(0)->SetTitle(_T("Name"));
  _var_dataview->GetColumn(0)->ChangeFlag(wxDATAVIEW_COL_RESIZABLE, true);
//  _var_dataview->GetColumn(0)->ChangeFlag(wxDATAVIEW_COL_SORTABLE,  true);
  _var_dataview->GetColumn(0)->SetMinWidth(200);
  
//   _var_dataview->AppendIconTextColumn
//                 (
//                     wxString("Name"),           // no label (header is not shown anyhow)
//                     wxDATAVIEW_CELL_EDITABLE,
//                     -1,                         // default width
//                     wxALIGN_NOT,                //  and alignment
//                     wxDATAVIEW_COL_RESIZABLE    // not resizable
//                 );

  _var_dataview->AppendTextColumn(_T("Type"),   
                                  wxDATAVIEW_CELL_INERT,
                                  -1,
                                  wxALIGN_NOT, 
                                  wxDATAVIEW_COL_RESIZABLE);
  _var_dataview->AppendTextColumn(_T("Val"),    
                                  wxDATAVIEW_CELL_INERT,
                                  -1,
                                  wxALIGN_NOT, 
                                  wxDATAVIEW_COL_RESIZABLE 
//                                  |
//                                  wxDATAVIEW_COL_SORTABLE
                                 );
  _var_dataview->AppendTextColumn(_T("Details"),
                                  wxDATAVIEW_CELL_INERT,
                                  -1,
                                  wxALIGN_NOT, 
                                  wxDATAVIEW_COL_RESIZABLE);

  _var_dataview->EnableDragSource( wxDF_UNICODETEXT );
  _var_dataview->EnableDropTarget( wxDF_UNICODETEXT );

  wxFont font(10,wxMODERN,wxNORMAL,wxNORMAL);

  if (font.IsOk())
     _var_dataview->SetFont(font ); // try a fixed pitch font
  else
     _var_dataview->SetFont(*wxSMALL_FONT);
   _var_dataview->SetIndent(2);

   vardataviewpanel_sizer->Add(_var_dataview,
                               1,
                               wxEXPAND,   // make vertically stretchable and make border all around
                               5);         // set border width to 5
 

   
   vardataviewpanel_sizer->Fit(_vardataview_panel);

//             wxDataViewItem root_node =
//                 _var_dataview->AppendContainer( wxDataViewItem(0), "The Root", 0 );
//             _var_dataview->AppendItem( root_node, "Child 1", 0 );
//             _var_dataview->AppendItem( root_node, "Child 2", 0 );
//             _var_dataview->AppendItem( root_node, "Child 3, very long, long, long, long", 0 );
// 
//             wxDataViewItem cont =
//                 _var_dataview->AppendContainer( root_node, "Container child", 0 );
//             _var_dataview->AppendItem( cont, "Child 4", 0 );
//             _var_dataview->AppendItem( cont, "Child 5", 0 );
// 
//             _var_dataview->Expand(cont);

  wxDataViewItemAttr main_attr;
  main_attr.SetBold(true);
  main_attr.SetItalic(true);

  _vardvt_root    = _var_dataview->AppendContainer( wxDataViewItem(0),
                                                    _T("Root"));
  _var_dataview->SetAttr(_vardvt_root,0,main_attr);
  _var_dataview->SetValue(
      wxVariant(_T("Root branch of variable tree")),
      _vardvt_root,
      3);

  
  _vardvt_global  = _var_dataview->AppendContainer( _vardvt_root,
                                                    _T("Global"));
  _var_dataview->SetAttr(_vardvt_global,0,main_attr);
  amiDataViewClientData* cd = new amiDataViewClientData(_T("Global"));
  _var_dataview->SetItemData(_vardvt_global,cd);

  _vardvt_builtin = _var_dataview->AppendContainer( _vardvt_root,
                                                    _T("Builtin"));
  _var_dataview->SetAttr(_vardvt_builtin,0,main_attr);
  cd = new amiDataViewClientData(_T("Builtin"));
  _var_dataview->SetItemData(_vardvt_builtin,cd);
  
   _var_book->AddPage(_vardataview_panel,wxT("DVT"));

} // CreateVarDataViewPanel()
#endif
/// @endcond 
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

  this->TC = TextControl::ptr(new TextControl( _prompt_panel,
                        wxID_ANY,
                        GetwxStr("Console"),
                          wxTE_MULTILINE
                        //| wxHSCROLL
                        | wxFULL_REPAINT_ON_RESIZE
                        //|wxTE_RICH|wxTE_RICH2
                        , (*_textcontrol_validator)
                        ));

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
  sbox_sizer->Add(TC.get(), 1, wxEXPAND | wxALL, 2);

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

  if (TC.get())
    TC->SetLog(_log_text);

} // CreateLogText()


//-------------------------------------------------------
void MainFrame::OnFindKeywords( wxCommandEvent& event )
{

  wxString aux;
  wxString text=   textCtrl->GetStringSelection();
  wxArrayString keywords;
  cout << text.mb_str()  <<endl;
  //if (text.size()>0)
  {
    int i = 0,j=0;
    while (token_list[i]!=0) {
      keywords.Add(GetwxStr(token_list[i]));
      i++;
    }
    keywords.Sort(); 

    while(j<i)
    {
      aux=keywords[j].SubString(0, text.size()-1);
      int out=aux.Cmp(text);
      if (out==0 )
	  break;
      j++;
    }
    cout << j<< text.mb_str() << endl;
   //m_listBox->Selection(j);
  }

}

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


  wxBoxSizer *keywordspanel_sizer= new wxBoxSizer(wxVERTICAL);


  _keywords_panel->SetSizer(keywordspanel_sizer);

  
  //textCtrl = new wxTextCtrl(_keywords_panel, ID_kp_textCtrl);
  // starts a list
  wxListBox* m_lbox = new wxListBox(_keywords_panel, wxID_ANY,
                           wxDefaultPosition, wxDefaultSize,
                           0, NULL,
                           wxLB_HSCROLL);

  

  
  wxArrayString keywords;

  int i = 0;
  while (token_list[i]!=0) {
    keywords.Add(GetwxStr(token_list[i]));
    i++;
  }


  keywords.Sort();

  m_lbox->InsertItems(keywords,0);
  //keywordspanel_sizer->Add(textCtrl,  0, wxEXPAND | wxALL, 5);
  keywordspanel_sizer->Add(m_lbox,  1, wxEXPAND | wxALL, 5);


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
// std::cout << GB_scripts_dir << std::endl;

  wxStaticText* scripts_label = new wxStaticText(_settings_panel,wxID_ANY,GetwxStr("Scripts path:"));

  scripts_path_picker = boost::shared_ptr<wxDirPickerCtrl>(new wxDirPickerCtrl(_settings_panel,
        wxID_ScriptsPath,
        GB_scripts_dir, GetwxStr("Scripts path")));

  wxStaticText* help_label = new wxStaticText(_settings_panel,wxID_ANY,GetwxStr("Help path:"));
  help_path_picker = boost::shared_ptr<wxDirPickerCtrl>(new wxDirPickerCtrl(_settings_panel,
        wxID_HelpPath,
        GB_help_dir, GetwxStr("Help path"),
        wxDefaultPosition, 
        wxDefaultSize,
        wxDIRP_DIR_MUST_EXIST | wxDIRP_USE_TEXTCTRL ));

  wxBoxSizer* scriptspath_sizer  = new wxBoxSizer(
            wxHORIZONTAL
          );
  scriptspath_sizer->Add(scripts_label,  0, wxEXPAND | wxALL, 5);
  scriptspath_sizer->Add(scripts_path_picker.get(),   1, wxEXPAND | wxALL, 5);

  wxBoxSizer* helppath_sizer  = new wxBoxSizer(
            wxHORIZONTAL
          );
  helppath_sizer->Add(help_label,             0, wxEXPAND | wxALL, 5);
  helppath_sizer->Add(help_path_picker.get(), 1, wxEXPAND | wxALL, 5);

  settingspanel_sizer->Add(scriptspath_sizer, 0, wxEXPAND | wxALL, 5);
  settingspanel_sizer->Add(helppath_sizer,    0, wxEXPAND | wxALL, 5);

  settingspanel_sizer->Fit(_settings_panel);

  scripts_path_picker->SetPath(GB_scripts_dir);
  scripts_path_picker->Update();

} // CreateSettingsPanel()


/*
//-------------------------------------------------------
void MainFrame::CreateDrawingPanel(wxWindow* parent)
//            --------------------
{
  // Setting
  _drawing_panel = new wxPanel(
          parent,
          wxID_ANY,
          wxDefaultPosition,
          wxDefaultSize,
            wxFULL_REPAINT_ON_RESIZE
          | wxTAB_TRAVERSAL
          );

  wxStaticBox* drawing_box = new wxStaticBox(
          _drawing_panel,
          wxID_ANY,
          GetwxStr("Drawing") );

  wxStaticBoxSizer* drawingpanel_sizer  = new wxStaticBoxSizer(
            drawing_box
          , wxVERTICAL
          //, wxHORIZONTAL
          );

  _drawing_panel->SetSizer(drawingpanel_sizer);

  _drawing_window = new wxDrawingWindow(
      _drawing_panel,
      wxID_ANY,
      wxDefaultPosition,
      wxSize(300,300),
      wxHSCROLL);

  drawingpanel_sizer->Add(_drawing_window,  1,  wxALL | wxEXPAND, 0);
  drawingpanel_sizer->Fit(_drawing_panel);


} // CreateDrawingPanel()
*/


void MainFrame::OnClose(wxCloseEvent& event)
{
  CLASS_MESSAGE("closing main frame ...");
  // save filehistories
  GB_Config->SetPath(wxT("/ImagesHistory"));
  images_history ->Save(*GB_Config);
  GB_Config->SetPath(wxT("/ScriptsHistory"));
  scripts_history->Save(*GB_Config);

  // important: clear variables now before the childrens are deleted
  Vars.EmptyVariables();
  Destroy();
  GB_main_wxFrame = NULL;
/* std::cout << "OnClose " << std::endl;

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
/*
  _var_list->Hide();

  _var_list->DeleteAllItems();
  boost::shared_ptr<wxArrayString> variables;

  // loop vars
  variables = Vars.SearchCompletions(GetwxStr(""));


  for(int i=0;i<(int)variables->GetCount();i++) {
    //cout << "set item variable " << i << std::endl;

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
*/
}



//-----------------------------------------------------
/**
 * @brief Update the information in the variable tree control, recursive.
 *
 * @param rootbranch ...
 * @param context ...
 * @return void
 **/
void MainFrame::UpdateVarTree(  const TREE_ITEM_TYPE& rootbranch, 
                                Variables::ptr context, int rec_level, 
                                std::string varpath)
{
#if (!wxCHECK_VERSION(2,9,0))
  if (rec_level>MAX_VARTREE_LEVEL) return;  
    // delete children of root
  TREE_VAR->DeleteChildren(rootbranch);
  boost::shared_ptr<wxArrayString> variables;
  BasicVariable::ptr emptyvar;

  std::map<std::string,TREE_ITEM_TYPE> categories_id;
  std::string cat[] = { "Images", "Surfaces", "Numbers", "Strings", 
                        "Functions", "Classes", "Objects", 
                        "Wrapped Image Functions", "Wrapped Procedures",
                        "Wrapped Var. Func.", "Others", ""
                      }; 

  // create all the first branches
  wxFont root_font = TREE_VAR->GetItemFont(rootbranch);
  wxColour vartype_colour = *wxBLUE;
  root_font.SetStyle(wxFONTSTYLE_ITALIC);
  root_font.SetWeight(wxLIGHT);
  
  int n=0;
  std::string current_cat;
  TREE_ITEM_TYPE current_id;

  while (cat[n]!="") 
  {
    current_id =  TREE_VAR->AppendItem( rootbranch,
                                         wxString(cat[n].c_str(), wxConvUTF8),
                                         -1,-1,
                                         new MyTreeItemData(emptyvar,varpath));
    categories_id[cat[n]] = current_id;
    _var_tree->SetItemFont(      current_id,root_font);
    _var_tree->SetItemTextColour(current_id,vartype_colour);
    categories_id[cat[n]] = current_id;
    n++;
  }

  root_font.SetFamily(wxFONTFAMILY_MODERN);
  //wxFONTSTYLE_NORMAL);
  root_font.SetWeight(wxNORMAL);
  TREE_ITEM_TYPE itemid;

  // loop vars
  variables = boost::shared_ptr<wxArrayString>(new wxArrayString());
  context->SearchCompletions(GetwxStr(""),variables);
  unsigned long total_image_size = 0;

  for(int i=0;i<(int)variables->GetCount();i++) {
    //cout << "set item variable " << i << std::endl;

    wxString type_str;
    BasicVariable::ptr var = context->GetVar((*variables)[i].mb_str());

    TREE_ITEM_TYPE append_id;
    std::string text;
    std::string valtext;

    if (var.get()) {
      if (var->Type() == type_image) {
        // create text with image information
        DYNAMIC_CAST_VARIABLE(InrImage,var,varim);
        InrImage::ptr im (varim->Pointer());
        if (im.get()) {
          text = (boost::format("%1% (%2%x%3%x%4%)x%5% %|6$+5| Mb")
                              % im->FormatName()
                              % im->DimX()
                              % im->DimY()
                              % im->DimZ()
                              % im->GetVDim()
                              % (im->GetDataSize()/1000000)).str();
          //cout << text << std::endl;
          append_id = categories_id[std::string("Images")];
          total_image_size += im->GetDataSize();
        } else {
          text = "Empty variable";
          append_id = categories_id[std::string("Images")];
        }
      } else
      if (var->IsNumeric())
      {
        text = var->TreeCtrlInfo();
        valtext = var->GetValueAsString();
        append_id = categories_id[std::string("Numbers")];
      } else
      if (var->Type() == type_string)
      {
        text = var->TreeCtrlInfo();
        valtext = (boost::format("'%1%'") %var->GetValueAsString()).str();
        append_id = categories_id[std::string("Strings")];
      } else
      if (var->Type() == type_ami_function)
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Functions")];
      } else
      if (var->Type() == type_ami_class)
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Classes")];
      } else
      if ((var->Type() == type_ami_object))
      {
        text = var->TreeCtrlInfo();
        // Get the class name is possible
        DYNAMIC_CAST_VARIABLE(AMIObject, var, varobj)
        if (varobj.get()) { 
          WrapClassBase::ptr wrapped_base(varobj->Pointer()->GetWrappedObject());
          if (wrapped_base.get()) 
            valtext = (boost::format("[%1%]") % 
                          wrapped_base->ObjPointerAsString()).str();
        }
        append_id = categories_id[std::string("Objects")];
      } else
      if (var->Type() == type_c_image_function)
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Wrapped Image Functions")];
      } else
      if ((var->Type() == type_c_procedure))
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Wrapped Procedures")];
      } else
      if ((var->Type() == type_c_function)||(var->Type() == type_class_member))
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Wrapped Var. Func.")];
      } else {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Others")];
      }

      itemid = TREE_VAR->AppendItem(
            append_id       ,
             wxString(var->Name().c_str(), wxConvUTF8),
             -1,-1,
             new MyTreeItemData(var,varpath));

      TREE_VAR->SetItemText(itemid,_vartree_col_type,
          wxString(var->GetTypeName().c_str(), wxConvUTF8));

      //_var_tree->SetItemToolTip(itemid,
      //    wxString(var->GetTypeName().c_str(), wxConvUTF8));

      TREE_VAR->SetItemText(itemid,_vartree_col_val,
          wxString(valtext.c_str(), wxConvUTF8));

      TREE_VAR->SetItemText(itemid,_vartree_col_desc,
          wxString(text.c_str(), wxConvUTF8));

      TREE_VAR->SetItemFont(itemid,root_font);

      if ((var->Type() == type_ami_object)) 
      {
        // Expand if needed
        if (expanded_items.find(varpath+"->"+var->Name())!=expanded_items.end())
        {
          // get the pointer to the objet
          DYNAMIC_CAST_VARIABLE(AMIObject,var,varobj);
          AMIObject::ptr obj( varobj->Pointer());
          // create the tree by recursive call
          std::string path = varpath;
          if ((path!="")&&(path!="global::")) path +=".";
          path += var->Name();
//          this->UpdateVarTree(itemid, obj->GetContext(),rec_level+1,path);
          TREE_VAR_CTRL->Expand(itemid);
        } else {
          // add an element to allow expanding
          TREE_VAR->AppendItem(itemid,_T("to expand ..."));
        }
      }
    } // end if var.get()

  } // end for

  // Display the total size of images in Mb
  if (total_image_size != 0) {
    std::string text = (boost::format(" %45t total = %55t %|1$+5| Mb")
                        % (total_image_size/1000000)).str();
    TREE_VAR->AppendItem(categories_id[std::string("Images")],
                          wxString(text.c_str(), wxConvUTF8));
  }

  // update category item expansion and remove empty ones
  n=0;
  while (cat[n]!="") 
  {
    current_id = categories_id[cat[n]];

    if (expanded_items.find(varpath+"->"+cat[n])!=expanded_items.end()) 
      TREE_VAR_CTRL->Expand(current_id);
    if (_var_tree->GetChildrenCount(current_id)==0) 
      _var_tree->Delete(current_id);
    n++;
  }

  //_var_list->Show();
#endif // (!wxCHECK_VERSION(2,9,0))

}

///@cond wxCHECK
#if wxCHECK_VERSION(2,9,0)
//---------------------------------------------------------------
void MainFrame::UpdateVarDataView(  const wxDataViewItem& rootbranch, 
                                    Variables::ptr context, int rec_level, 
                                    std::string varpath)
{
  bool previous_updating_state = GetUpdatingDataView();
  SetUpdatingDataView(true);
  
//   std::cout << "UpdateVarDataView  from " << 
//                 _var_dataview->GetItemText(rootbranch) << std::endl; 
  // Create default attributes for category and object items
  wxDataViewItemAttr cat_attr;
  cat_attr.SetItalic(true);
  cat_attr.SetColour(*wxBLUE);

  wxDataViewItemAttr obj_attr;
  obj_attr.SetItalic(true);
  
  if (rec_level>MAX_VARTREE_LEVEL) return;  
    // delete children of root
  _var_dataview->DeleteChildren(rootbranch);
  boost::shared_ptr<wxArrayString> variables;
  BasicVariable::ptr emptyvar;

  std::map<std::string,wxDataViewItem> categories_id;
  std::string cat[] = { "Images", "Surfaces", "Numbers", "Strings", 
                        "Functions", "Classes", "Objects", 
                        "Wrapped Image Functions", "Wrapped Procedures",
                        "Wrapped Var. Func.", "Others", ""
                      }; 
  
  int n=0;
  std::string current_cat;
  wxDataViewItem current_id;

  while (cat[n]!="") 
  {
    //std::cout << "Creating branch for " << cat[n].c_str() << std::endl;
    current_id = _var_dataview->AppendContainer(
                                                rootbranch,
                                                wxString( cat[n].c_str(),
                                                          wxConvUTF8));
    _var_dataview->SetAttr(current_id,0,cat_attr);
    amiDataViewClientData* cd = new amiDataViewClientData(
          wxString(cat[n].c_str(), wxConvUTF8));
    cd->SetPath(varpath);
    _var_dataview->SetItemData(current_id,cd);
    categories_id[cat[n]] = current_id;
    n++;
  }

  wxDataViewItem itemid;

  // loop vars
  variables = boost::shared_ptr<wxArrayString>(new wxArrayString());
  context->SearchCompletions(GetwxStr(""),variables);
  unsigned long total_image_size = 0;

  for(int i=0;i<(int)variables->GetCount();i++) {
    //cout << "set item variable " << i << std::endl;

    wxString type_str;
    BasicVariable::ptr var = context->GetVar((*variables)[i].mb_str());

    wxDataViewItem append_id;
    std::string text;
    std::string valtext;

    if (var.get()) {
      if (var->Type() == type_image) {
        // create text with image information
        DYNAMIC_CAST_VARIABLE(InrImage,var,varim);
        InrImage::ptr im (varim->Pointer());
        if (im.get()) {
          valtext = (boost::format("%1% (%2%x%3%x%4%)x%5% ")
                              % im->FormatName()
                              % im->DimX()
                              % im->DimY()
                              % im->DimZ()
                              % im->GetVDim()).str();
          text = (boost::format(" %|1$+5| Mb")
                              % (im->GetDataSize()/1000000)).str();
          //cout << text << std::endl;
          append_id = categories_id[std::string("Images")];
          total_image_size += im->GetDataSize();
        } else {
          text = "Empty variable";
          append_id = categories_id[std::string("Images")];
        }
      } else
      if (var->IsNumeric())
      {
        text = var->TreeCtrlInfo();
        valtext = var->GetValueAsString();
        append_id = categories_id[std::string("Numbers")];
      } else
      if (var->Type() == type_string)
      {
        text = var->TreeCtrlInfo();
        valtext = (boost::format("'%1%'") %var->GetValueAsString()).str();
        append_id = categories_id[std::string("Strings")];
      } else
      if (var->Type() == type_ami_function)
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Functions")];
      } else
      if (var->Type() == type_ami_class)
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Classes")];
      } else
      if ((var->Type() == type_ami_object))
      {
        text = var->TreeCtrlInfo();
        // Get the class name is possible
        DYNAMIC_CAST_VARIABLE(AMIObject, var, varobj)
        if (varobj.get()) { 
          WrapClassBase::ptr wrapped_base(varobj->Pointer()->GetWrappedObject());
          if (wrapped_base.get()) {
            valtext = (boost::format("(c++)[%1%]") % 
                          wrapped_base->ObjPointerAsString()).str();
          } else {
            // try to get amilab classname
            AMIClass::ptr oclass = varobj->Pointer()->GetClass();
            if (oclass.get()) {
              valtext = (boost::format("(ami)[%1%]") % 
                            oclass->GetName()).str();
            }
          }
        }
        append_id = categories_id[std::string("Objects")];
      } else
      if (var->Type() == type_c_image_function)
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Wrapped Image Functions")];
      } else
      if ((var->Type() == type_c_procedure))
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Wrapped Procedures")];
      } else
      if ((var->Type() == type_c_function)||(var->Type() == type_class_member))
      {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Wrapped Var. Func.")];
      } else {
        text = var->TreeCtrlInfo();
        append_id = categories_id[std::string("Others")];
      }

      if ((var->Type() == type_ami_object)) 
      {
        itemid = _var_dataview->AppendContainer(
                  append_id,
                  wxString(var->Name().c_str(), wxConvUTF8));
        _var_dataview->SetAttr(itemid,0,obj_attr);
      }
      else
        itemid = _var_dataview->AppendItem(
                  append_id,
                  wxString(var->Name().c_str(), wxConvUTF8));

      amiDataViewClientData* cd = new amiDataViewClientData(
            wxString(var->Name().c_str()),
            var
            );
      cd->SetPath   (varpath);
      _var_dataview->SetItemData(itemid,cd);
      
      _var_dataview->SetValue(
          wxVariant(wxString(var->GetTypeName().c_str(), wxConvUTF8)),
          itemid,
          1);

      _var_dataview->SetValue(
          wxVariant(wxString(valtext.c_str(), wxConvUTF8)),
          itemid,
          2);
      
      _var_dataview->SetValue(
          wxVariant(wxString(text.c_str(), wxConvUTF8)),
          itemid,
          3);

      //TREE_VAR->BuildAbsoluteName(itemid);

      if ((var->Type() == type_ami_object)) 
      {
//        std:cout  << "looking if '" << varpath+"->"+var->Name()
//                  << "' is expanded " << std::endl;
        // Expand if needed
        if (dv_expanded_items.find(varpath+"->"+var->Name())!=
            dv_expanded_items.end())
        {
//          std::cout << "YES" << std::endl;
          // get the pointer to the objet
          DYNAMIC_CAST_VARIABLE(AMIObject,var,varobj);
          AMIObject::ptr obj( varobj->Pointer());
          // create the tree by recursive call
          std::string path = varpath;
          if ((path!="")&&(path!="global::")) path +=".";
          path += var->Name();
          _var_dataview->Expand(rootbranch);
          _var_dataview->Expand(append_id);
          this->UpdateVarDataView(itemid, obj->GetContext(),rec_level+1,path);
          _var_dataview->Expand(itemid);
        } else {
          // add an element to allow expanding
          _var_dataview->AppendItem(itemid,_T("to expand ..."));
        }
      }
    } // end if var.get()

  } // end for

  // Display the total size of images in Mb
  if (total_image_size != 0) {
    itemid = _var_dataview->AppendItem(categories_id[std::string("Images")],
                          _T("Total size"));
    std::string text = (boost::format(" %|1$+5| Mb")
                        % (total_image_size/1000000)).str();
    _var_dataview->SetValue(
        wxVariant(wxString(text.c_str(), wxConvUTF8)),
        itemid,
        3);
  }

  // update category item expansion and remove empty ones
  n=0;
  while (cat[n]!="") 
  {
    current_id = categories_id[cat[n]];
    if (_var_dataview->GetChildCount(current_id)==0) 
      _var_dataview->DeleteItem(current_id);
    else {
//      std::cout  << "looking if '" << varpath+"->"+cat[n] 
//                << "' is expanded " << std::endl;
      if (dv_expanded_items.find(varpath+"->"+cat[n])!=dv_expanded_items.end()) {
//        std::cout << "YES, calling Expand() ..." << std::endl;
        _var_dataview->Expand(rootbranch);
        _var_dataview->Expand(current_id);
//        std::cout << "Is Expanded = " << _var_dataview->IsExpanded(current_id) << std::endl;
       }
    }
    n++;
  }

  SetUpdatingDataView(previous_updating_state);

/*
 *  boost::shared_ptr<wxArrayString> variables;

  // create all the first branches  
  wxDataViewItem vartree_images    = m_amilab_model->CreateBranchNode(rootbranch,_T("Images"));
  wxDataViewItem vartree_surfaces  = m_amilab_model->CreateBranchNode(rootbranch,_T("Surfaces"));
  wxDataViewItem vartree_numbers   = m_amilab_model->CreateBranchNode(rootbranch,_T("Numbers"));
  wxDataViewItem vartree_strings   = m_amilab_model->CreateBranchNode(rootbranch,_T("Strings"));
  wxDataViewItem vartree_functions = m_amilab_model->CreateBranchNode(rootbranch,_T("Functions"));
  wxDataViewItem vartree_classes   = m_amilab_model->CreateBranchNode(rootbranch,_T("Classes"));
  wxDataViewItem vartree_objects   = m_amilab_model->CreateBranchNode(rootbranch,_T("Objects"));
  wxDataViewItem vartree_wrapped_functions = m_amilab_model->CreateBranchNode(rootbranch,_T("Wrapped Image Functions"));
  wxDataViewItem vartree_wrapped_procedures = m_amilab_model->CreateBranchNode(rootbranch,_T("Wrapped Procedures"));
  wxDataViewItem vartree_wrapped_var_functions = m_amilab_model->CreateBranchNode(rootbranch,_T("Wrapped Var. Func."));
  wxDataViewItem vartree_others    = m_amilab_model->CreateBranchNode(rootbranch,_T("Others"));

  // loop vars
  variables = boost::shared_ptr<wxArrayString>(new wxArrayString());
  context->SearchCompletions(GetwxStr(""),variables);
  unsigned long total_image_size = 0;
  wxDataViewItem itemid;

  for(int i=0;i<(int)variables->GetCount();i++) {
    //cout << "set item variable " << i << endl;

    wxString type_str;
    BasicVariable::ptr var = context->GetVar((*variables)[i].mb_str());

    wxDataViewItem append_id;
    std::string text;
    std::string valtext;

    if (var.get()) {
      if (var->Type() == type_image) {
        // create text with image information
        DYNAMIC_CAST_VARIABLE(InrImage,var,varim);
        InrImage::ptr im (varim->Pointer());
        text = (boost::format("%1% (%2%x%3%x%4%)x%5% %|6$+5| Mb")
                            % im->FormatName()
                            % im->DimX()
                            % im->DimY()
                            % im->DimZ()
                            % im->GetVDim()
                            % (im->GetDataSize()/1000000)).str();
        //cout << text << endl;
        append_id = vartree_images;
        total_image_size += im->GetDataSize();
      } else
        */
/* TODO: arrange tree display for type_ami_object
      if (var->Type() == type_surface) {
        DYNAMIC_CAST_VARIABLE(SurfacePoly,var,varsurf);
        SurfacePoly::ptr surf (varsurf->Pointer());
        std::string text = (boost::format("%1% %15t pts: %2% %25t poly:%3%")
                            % var->Name()
                            % surf->GetNumberOfPoints()
                            % surf->GetNumberOfPolys()).str();
        //cout << text << endl;
        itemid = _var_tree->AppendItem(
              vartree_surfaces,
              wxString(text.c_str(), wxConvUTF8),
              -1,-1,
              new MyTreeItemData(var));
        _var_tree->SetItemFont(itemid,root_font);
      } else
*/
/*
 *      if (var->IsNumeric())
      {
        text = var->TreeCtrlInfo();
        valtext = var->GetValueAsString();
        append_id = vartree_numbers;
      } else
      if (var->Type() == type_string)
      {
        text = var->TreeCtrlInfo();
        valtext = (boost::format("'%1%'") %var->GetValueAsString()).str();
        append_id = vartree_strings;
      } else
      if (var->Type() == type_ami_function)
      {
        text = var->TreeCtrlInfo();
        append_id = vartree_functions;
      } else
      if (var->Type() == type_ami_class)
      {
        text = var->TreeCtrlInfo();
        append_id = vartree_classes;
      } else
      if ((var->Type() == type_ami_object))
      {
        text = var->TreeCtrlInfo();
        append_id = vartree_objects;
      } else
      if (var->Type() == type_c_image_function)
      {
        text = var->TreeCtrlInfo();
        append_id = vartree_wrapped_functions;
      } else
      if ((var->Type() == type_c_procedure))
      {
        text = var->TreeCtrlInfo();
        append_id = vartree_wrapped_procedures;
      } else
      if ((var->Type() == type_c_function)||(var->Type() == type_class_member))
      {
        text = var->TreeCtrlInfo();
        append_id = vartree_wrapped_var_functions;
      } else {
        text = var->TreeCtrlInfo();
        append_id = vartree_others;
      }

      if ((var->Type() == type_ami_object))
      {
        itemid = m_amilab_model->CreateBranchNode(append_id,
          wxString(var->Name().c_str(), wxConvUTF8));

        m_amilab_model->SetVar(itemid, var);

//         AMILabTreeModelNode *node = (AMILabTreeModelNode*) itemid.GetID();
//         std::cout << "itemid="
//                   << " node: "      << node->m_Name
//                   << " parent: "    << node->GetParent()->m_Name
//                   << " type: "      << node->m_Type
//                   << " container: " << node->m_container
//                   << std::endl;
      }
      else
        itemid = m_amilab_model->CreateLeafNode(append_id,
          wxString(var->Name().c_str(), wxConvUTF8),
          wxString(var->GetTypeName().c_str(), wxConvUTF8),
          wxString(valtext.c_str(), wxConvUTF8),
          wxString(text.c_str(), wxConvUTF8),
          var
          );

      m_amilab_model->BuildAbsoluteName(itemid);

      if ((var->Type() == type_ami_object)) {
        // get the pointer to the objet
        DYNAMIC_CAST_VARIABLE(AMIObject,var,varobj);
        AMIObject::ptr obj( varobj->Pointer());
        // create the tree by recursive call
        this->UpdateVarDataView(itemid, obj->GetContext());
      }
    } // end if var.get()

  } // end for

  // TODO/FIXME: I don't understand this part.

  // Display the total size of images in Mb
  if (total_image_size != 0) {
    std::string text = (boost::format(" %45t total = %55t %|1$+5| Mb")
                        % (total_image_size/1000000)).str();
//    _var_tree->AppendItem(vartree_images,wxString(text.c_str(), wxConvUTF8));
    m_amilab_model->CreateBranchNode(vartree_images, wxString(text.c_str(), wxConvUTF8));
  }

  // delete empty branches
  if (!m_amilab_model->HasChildren(vartree_images))
    m_amilab_model->Delete(vartree_images);
  if (!m_amilab_model->HasChildren(vartree_surfaces))
    m_amilab_model->Delete(vartree_surfaces);
  if (!m_amilab_model->HasChildren(vartree_numbers))
    m_amilab_model->Delete(vartree_numbers);
  if (!m_amilab_model->HasChildren(vartree_strings))
    m_amilab_model->Delete(vartree_strings);
  if (!m_amilab_model->HasChildren(vartree_functions))
    m_amilab_model->Delete(vartree_functions);
  if (!m_amilab_model->HasChildren(vartree_classes))
    m_amilab_model->Delete(vartree_classes);
  if (!m_amilab_model->HasChildren(vartree_objects))
    m_amilab_model->Delete(vartree_objects);
  if (!m_amilab_model->HasChildren(vartree_wrapped_functions))
    m_amilab_model->Delete(vartree_wrapped_functions);
  if (!m_amilab_model->HasChildren(vartree_wrapped_procedures))
    m_amilab_model->Delete(vartree_wrapped_procedures);
  if (!m_amilab_model->HasChildren(vartree_wrapped_var_functions))
    m_amilab_model->Delete(vartree_wrapped_var_functions);
  if (!m_amilab_model->HasChildren(vartree_others))
    m_amilab_model->Delete(vartree_others);
  */
}
#endif
/// @endcond
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
  m_mgr.LoadPerspective(_initial_perspective);
  m_mgr.Update();
}

//---------------------------------------------------------------
void MainFrame::OnViewOutput( wxCommandEvent& event )
{
  if ( !m_mgr.GetPane(_log_text).IsShown())
     m_mgr.GetPane(_log_text).Show(); 
  else
     m_mgr.GetPane(_log_text).Hide(); 
  m_mgr.Update();
}

//---------------------------------------------------------------
void MainFrame::OnViewVar_book( wxCommandEvent& event )
{
  if ( !m_mgr.GetPane(_var_book).IsShown())
     m_mgr.GetPane(_var_book).Show(); 
  else
     m_mgr.GetPane(_var_book).Hide(); 
  m_mgr.Update();
}

//---------------------------------------------------------------
void MainFrame::OnViewMain_bar( wxCommandEvent& event )
{
  if ( !m_mgr.GetPane(this->tb1).IsShown())
  {
    m_mgr.GetPane(this->tb1).Show(); 
    m_mgr.GetPane(this->tb1).Top();
    m_mgr.GetPane(this->tb1).Dock(); 
//     m_mgr.GetPane(this->tb1).Position(pos++);
//     if (m_mgr.GetPane(this->tb2).IsShown())
//       m_mgr.GetPane(this->tb2).Position(pos++);
  }
  else
     m_mgr.GetPane(this->tb1).Hide(); 
  m_mgr.Update();
}

//---------------------------------------------------------------
void MainFrame::OnViewMain_bar2( wxCommandEvent& event )
{
  if ( !m_mgr.GetPane(this->tb2).IsShown())
  {
    m_mgr.GetPane(this->tb2).Show(); 
    m_mgr.GetPane(this->tb2).Top();
    m_mgr.GetPane(this->tb2).Dock(); 
//     if (m_mgr.GetPane(this->tb1).IsShown())
//       m_mgr.GetPane(this->tb1).Position(pos++);
//     m_mgr.GetPane(this->tb1).Position(pos++);
  }
  else
     m_mgr.GetPane(this->tb2).Hide(); 
  m_mgr.Update();
}


//---------------------------------------------------------------
void MainFrame::OnViewMain_book( wxCommandEvent& event )
{
  if ( !m_mgr.GetPane(_main_book).IsShown())
    m_mgr.GetPane(_main_book).Show(); 
  else
     m_mgr.GetPane(_main_book).Hide(); 
  m_mgr.Update();
}

//---------------------------------------------------------------
void MainFrame::OnViewParam_book( wxCommandEvent& event )
{
  if ( !m_mgr.GetPane(this->_param_book).IsShown())
    m_mgr.GetPane(this->_param_book).Show(); 
  else
     m_mgr.GetPane(_param_book).Hide(); 
  m_mgr.Update();
}

void MainFrame::OnViewScript_bar( wxCommandEvent& event )
{
  if ( !m_mgr.GetPane(_("scripts_tb")).IsShown())
  {
    m_mgr.GetPane(_("scripts_tb")).Show(); 
    m_mgr.GetPane(_("scripts_tb")).Right();
    m_mgr.GetPane(_("scripts_tb")).Dock(); 
  }
  else
     m_mgr.GetPane(_("scripts_tb")).Hide(); 
  m_mgr.Update();
}



//-----------------------------------------------------
void MainFrame::OnFileOpenImage    ( wxCommandEvent& event )
{
  int res;
  std::string name;
  std::string varname;
//  string cmd; // increment the command line string

  res=AskImage(name);
  if (!res) {
    std::cerr << " Image not found " << std::endl;
    return;
  }

  TryToOpenImage(wxString(name.c_str(),wxConvUTF8));
}

//-----------------------------------------------------
bool MainFrame::TryToOpenImage( const wxString& string_filename)
{
  std::string varname;
  
  // Create possible variable name
  wxString possible_name = wxFileName(string_filename).GetName();
  // remove all extensions
  while (wxFileName(possible_name).HasExt()) {
    wxFileName fn(possible_name);
    fn.ClearExt();
    possible_name = fn.GetName();
  }
  possible_name.Replace(wxT(" "),wxT("_"));
  possible_name.Replace(wxT("."),wxT("_"));
  possible_name.Replace(wxT("("),wxT("_"));
  possible_name.Replace(wxT(")"),wxT("_"));
  possible_name.Replace(wxT("-"),wxT("_"));

  std::string st = std::string(possible_name.mb_str());
  if (((st[0]<'A') || (st[0]>'Z')) &&
      ((st[0]<'a') || (st[0]>'z')) &&
      (st[0]!='_'))
    st = std::string("_")+st;

  int res=AskVarName( this,
                  std::string("Image variable name"),
                  std::string("Enter name:"),
                  st,
                  varname);
  if (!res) {
    std::cerr << " Var name error " << std::endl;
    return false;
  }

  wxFileName filename(string_filename);
  filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
  wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                      filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                      filename.GetPathSeparator(wxPATH_UNIX)+
                      filename.GetFullName());

  images_history->AddFileToHistory(newname);

  wxString wxst_cmd;
  wxst_cmd = wxString(varname.c_str(),wxConvUTF8)+wxT(" = Image \"")+newname+wxT("\" // from menu");
//  cmd = varname + string(" = Image \"");
//  cmd += newname.mb_str();
//  cmd += string("\" // from menu");
  this->TC->IncCommand(wxst_cmd);
  bool return_res = this->TC->ProcessReturn(); 
  if (!return_res) {
    wxString mess = wxT("Failed to open '");
    mess += string_filename;
    mess += wxT("' ...");
    wxMessageDialog dialog( 
      this,mess,wxT("Info"),
      wxOK|wxICON_INFORMATION|wxSTAY_ON_TOP 
      );
    dialog.ShowModal();
    this->TC->ConsoleClear();
  }
  return return_res;
}

//-----------------------------------------------------
void MainFrame::OnFileOpenImageHistory ( wxCommandEvent& event )
{
  std::cout << "OnFileOpenImageHistory" << std::endl;
//  string cmd; // increment the command line string
  std::string varname;
  size_t pos = event.GetId() - wxID_Images_History;
  wxString filename(images_history->GetHistoryFile(pos));
  
  TryToOpenImage(filename);


//  images_history->RemoveFileFromHistory(pos);
//  images_history->AddFileToHistory(filename);

}

//-----------------------------------------------------
void MainFrame::OnFileOpenScriptHistory ( wxCommandEvent& event )
{
//  string cmd; // increment the command line string
  std::cout << "OnFileOpenScriptHistory" << std::endl;
  std::string varname;
  size_t pos = event.GetId() - wxID_Scripts_History;
  wxString filename(scripts_history->GetHistoryFile(pos));


  scripts_history->RemoveFileFromHistory(pos);
  scripts_history->AddFileToHistory(filename);

//  cmd = string("func \"");
//  cmd += filename.mb_str();
//  cmd += string("\" // from menu");
  wxString wxst_cmd;
  wxst_cmd = wxT("func \"")+filename+wxT("\" // from menu");
  this->TC->IncCommand(wxst_cmd);
  this->TC->ProcessReturn();

}

//-----------------------------------------------------
void MainFrame::OnFileOpenPolydata ( wxCommandEvent& event )
{
  int res;
  std::string name;
  std::string varname;
//  string cmd; // increment the command line string

  res=AskSurface(name);
  if (!res) {
    std::cerr << " Surface not found " << std::endl;
    return;
  }

  // Create possible variable name
  wxString possible_name = wxFileName(wxString(name.c_str(),wxConvUTF8)).GetName();
  // remove all extensions
  while (wxFileName(possible_name).HasExt()) {
    wxFileName fn(possible_name);
    fn.ClearExt();
    possible_name = fn.GetName();
  }
  possible_name.Replace(wxT(" "),wxT("_"));
  possible_name.Replace(wxT("."),wxT("_"));
  possible_name.Replace(wxT("("),wxT("_"));
  possible_name.Replace(wxT(")"),wxT("_"));

  res=AskVarName(this,
        std::string("Surface variable name"),
        std::string("Enter name:"),
        std::string(possible_name.mb_str(wxConvUTF8)),
        varname);
  if (!res) {
    std::cerr << " Var name error " << std::endl;
    return;
  }

  wxFileName filename(GetwxStr(name));
  filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
  wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                      filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                      filename.GetPathSeparator(wxPATH_UNIX)+
                      filename.GetFullName());

//  cmd = varname + string(" = Surface \"");
//  cmd += newname.mb_str();
//  cmd += string("\" // from menu");
  wxString wxst_cmd;
  wxst_cmd = wxString(varname.c_str(),wxConvUTF8)+wxT(" = Surface \"")+newname+wxT("\" // from menu");
  this->TC->IncCommand(wxst_cmd);
  this->TC->ProcessReturn();
}

//-----------------------------------------------------
void MainFrame::OnFileLoadScript   ( wxCommandEvent& event )
{
  //cout << "Load script" << std::endl;
  int res;
  std::string name;
//  string cmd; // increment the command line string

  res=AskScript(name);
  if (!res) {
    std::cerr << " Script filename not found " << std::endl;
    return;
  }

  wxFileName filename(GetwxStr(name));
  filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
  wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                      filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                      filename.GetPathSeparator(wxPATH_UNIX)+
                      filename.GetFullName());

  scripts_history->AddFileToHistory(newname);

//  cmd = string("func \"");
//  cmd += newname.mb_str();
//  cmd += string("\" // from menu");
  wxString wxst_cmd;
  wxst_cmd = wxT("func \"")+newname+wxT("\" // from menu");
  this->TC->IncCommand(wxst_cmd);
  this->TC->ProcessReturn();
}

//-----------------------------------------------------
void MainFrame::OnQuit(wxCommandEvent& event)
{
      // Check if not already displaying a message
      // to avoid problems
      wxMessageDialog dialog( 
        this,
        _T("Are you sure that you want to close this window ?"),
        _T("Confirmation"), 
         wxNO_DEFAULT
        |wxYES_NO
        |wxCANCEL
        |wxICON_INFORMATION
        );

        switch ( dialog.ShowModal() )
        {
        case wxID_NO:
        case wxID_CANCEL:
//            event.Veto();
            return;

        default:;
        }


//  event.Veto();
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
  wxFileName scripts(GB_help_dir,_T("scripts.html"));
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

//------------------------------------------------------------------------------
void MainFrame::ConsoleClear( wxCommandEvent& event)
{
  TC->ConsoleClear();
}

//------------------------------------------------------------------------------
void MainFrame::UpdateVarsDisplay()
{
#if (!wxCHECK_VERSION(2,9,0))
//   std::cout << "UpdateVarsDisplay()" << std::endl;
  // get list of expanded items
  wxTreeItemId itemid;
  MyTreeItemData *item;
  wxString text;
  std::string current_item_name;
  
  expanded_items.clear();
  
  itemid = _var_tree->GetFirstExpandedItem();
  while (itemid.IsOk()) {
    current_item_name = "";
    if (_var_tree->IsExpanded(itemid)) {
      item = (MyTreeItemData *)_var_tree->GetItemData(itemid);
      if (item != NULL) {
        current_item_name += item->GetPath();
      }
      text = _var_tree->GetItemText(itemid);
      current_item_name += "->";
      current_item_name += text.ToAscii();
      //std::cout << " item: '" << current_item_name << "'"<< std::endl;
      expanded_items.insert(current_item_name);
    }
    itemid = _var_tree->GetNextExpanded(itemid);
  }
  
  wxFont root_font = _var_tree->GetItemFont(_vartree_root);
  root_font.SetStyle(wxFONTSTYLE_ITALIC);
  root_font.SetWeight(wxFONTWEIGHT_BOLD);
  root_font.SetPointSize(10);
  _var_tree->SetItemFont(_vartree_root,root_font);
  _var_tree->SetItemFont(_vartree_global, root_font);
  _var_tree->SetItemFont(_vartree_builtin,root_font);

  _var_tree->Expand(  _vartree_root);

  UpdateVarTree(_vartree_global, Vars.GetCurrentContext(),0,"global::");
  _var_tree->Expand(  _vartree_global);

  UpdateVarTree(_vartree_builtin, Vars.GetBuiltinContext(),0);
  _var_tree->Expand(  _vartree_builtin);
#endif // #if (!wxCHECK_VERSION(2,9,0))

}

//------------------------------------------------------------------------------
void MainFrame::UpdateDataViewVarDisplay()
{
  
  //std::cout << "UpdateDataViewVarDisplay" << std::endl;
  // get list of expanded items
  amiDataViewClientData *item_data;
  std::string text;
  std::string current_item_name;
  
  dv_expanded_items.clear();
  std::list<wxDataViewItem> current_expanded_items;

  wxDataViewItem item;
  wxDataViewItemArray children;
  unsigned int nb_children =
    _var_dataview->GetStore()->GetChildren(_vardvt_root,children);
  int i;
  
  for(i=0;i<children.Count();i++)
    if (_var_dataview->IsExpanded(children[i])) 
      current_expanded_items.push_back(children[i]);
    
  while (!current_expanded_items.empty())  {
    current_item_name = "";
    item = current_expanded_items.front();
    current_expanded_items.pop_front();
    if (_var_dataview->IsExpanded(item)) {
      item_data = (amiDataViewClientData*) _var_dataview->GetItemData(item);
      if (item_data != NULL) {
        current_item_name += item_data->GetPath();
        text = item_data->GetName();
        current_item_name += "->";
        current_item_name += text;
        //std::cout << " expanded item: '" << current_item_name << "'"<< std::endl;
        dv_expanded_items.insert(current_item_name);
      }
      else {
        std::cout << "item null for " 
                  << _var_dataview->GetItemText(children[i])
                  << std::endl;
      }
      children.Empty();
      _var_dataview->GetStore()->GetChildren(item,children);
      for(i=0;i<children.Count();i++)
        if (_var_dataview->IsExpanded(children[i])) 
          current_expanded_items.push_back(children[i]);
    }
  }

//  m_amilab_model->CreateMainBranches();

  _var_dataview->Expand( _vardvt_root );

  CLASS_MESSAGE("Update global node");
//   UpdateVarTree(_vartree_global, Vars.GetCurrentContext(),0,"global::");
  UpdateVarDataView(_vardvt_global, Vars.GetCurrentContext(),0,"global::");
  _var_dataview->Expand(_vardvt_global);

  CLASS_MESSAGE("Update builtin node");
//   UpdateVarTree(_vartree_builtin, Vars.GetBuiltinContext(),0);
  UpdateVarDataView(_vardvt_builtin, Vars.GetBuiltinContext(),0);
  _var_dataview->Expand( _vardvt_builtin );  

//  CLASS_MESSAGE("Notifies the control that data model have been updated");
//  m_amilab_model->Cleared(); 
//  wxDataViewItemArray nodes;
//  m_amilab_model->GetChildren(m_amilab_model->GetRootNode(),nodes);
//  m_amilab_model->ItemsChanged(nodes); 


}

//--------------------------------------------------
void MainFrame::UpdateVars( )
{
#if wxCHECK_VERSION(2,9,0)
  UpdateDataViewVarDisplay();
#else
  UpdateVarsDisplay();
#endif
}

//--------------------------------------------------
void MainFrame::CB_UpdateVars( wxCommandEvent& event)
{
  UpdateVars();
}

//--------------------------------------------------
void MainFrame::OnToolHelp( wxCommandEvent& event)
{
  wxLaunchDefaultBrowser(_T("http://amilab.sourceforge.net:80/dokuwiki/doku.php?id=Help"));
}

//--------------------------------------------------
void MainFrame::VarListRightClick( wxListEvent& event)
{
 std::cout << "Right click on item \n";
}

//--------------------------------------------------
void MainFrame::OnScriptsPath( wxFileDirPickerEvent& event)
{
 std::cout << "Scripts path changed" << std::endl;
 GB_scripts_dir = event.GetPath();
}

//--------------------------------------------------
void MainFrame::OnHelpPath   ( wxFileDirPickerEvent& event)
{
 std::cout << "Help path changed" << std::endl;
  GB_help_dir = event.GetPath();
}


//--------------------------------------------------
void MainFrame::AddMenuScript(  const std::string& script_category,
                                const std::string& script_label,
                                const std::string& script_name)
{
  wxMenu* parent = menuScripts;

  // first try to find the menu corresponding to the given category
  int menuid = menuScripts->FindItem(wxString(script_category.c_str(), wxConvUTF8));
  if (menuid != wxNOT_FOUND) {
    // category found, adding as submenu
    CLASS_MESSAGE("category found");
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
    } else
      return;
  }
  // adding script
  wxMenuItem* mi = new wxMenuItem(parent,wxID_ANY,GetwxStr(script_label.c_str()));
  parent->Append(mi );
  usermenu_id = mi->GetId();
  usermenu_scripts[usermenu_id] = script_name;
  //parent->Append(usermenu_id, GetwxStr(script_label.c_str()));

  // connecting
  //std::cout << "Connecting menu event with id = " << usermenu_id << std::endl;
  Connect(usermenu_id,wxEVT_COMMAND_MENU_SELECTED,
     wxCommandEventHandler(MainFrame::OnUserMenuScript));

}


//--------------------------------------------------
void MainFrame::AddToMenu(  const std::string& menu_name,
                            const std::string& script_category, 
                            const std::string& script_label, 
                            const std::string& script_name)
{
  // 1. Find the menu in the menu bar
  int menuid = menuBar->FindMenu(wxString(menu_name.c_str(),wxConvUTF8));
  if (menuid == wxNOT_FOUND) {
    wxMenu* newmenu = new wxMenu;
    // need to set the title in wxWidgets 2.9.4 on MacOS ...
    newmenu->SetTitle(wxString(menu_name.c_str(),wxConvUTF8));
    menuBar->Insert(menuBar->FindMenu(_("&Help")), newmenu, wxString(menu_name.c_str(),wxConvUTF8));
    menuid = menuBar->FindMenu(wxString(menu_name.c_str(),wxConvUTF8));
  }
  if (menuid ==wxNOT_FOUND) {
    CLASS_ERROR((boost::format("Problem in adding the menu '%1%'.") % menu_name.c_str()).str().c_str())
    return;
  }
  
  wxMenu* current_menu = menuBar->GetMenu(menuid); // current main menu
  wxMenu* cat_menu = NULL; // category menu

  // first try to find the menu corresponding to the given category
  wxString menu_cat=wxString(script_category.c_str(), wxConvUTF8);
  menuid = current_menu->FindItem(menu_cat);
  if (menuid != wxNOT_FOUND) {
    // category found, adding as submenu
    CLASS_MESSAGE("category found");
    wxMenuItem* menuitem = current_menu->FindItem(menuid);
    if (menuitem!=NULL) {
      if (menuitem->GetSubMenu())
        cat_menu = menuitem->GetSubMenu();
      else
        cat_menu = menuitem->GetMenu();
    }
  } else {
    if (script_category.length()>1) {
      wxMenu* newsubmenu = new wxMenu;
      // add new category
      current_menu->AppendSubMenu( newsubmenu,   GetwxStr(script_category.c_str()));
      cat_menu = newsubmenu;
    } else
      return;
  }
 
  // adding or replacing script
  menuid = cat_menu->FindItem(GetwxStr(script_label.c_str()));
  if (menuid!=wxNOT_FOUND) 
    cat_menu->Remove(menuid);
  
  wxMenuItem* mi=new wxMenuItem (cat_menu,wxID_ANY,GetwxStr(script_label.c_str()));
  cat_menu->Append(mi );
  usermenu_id = mi->GetId();
  //usermenu_id = wxNewId();
  usermenu_scripts[usermenu_id] = script_name;

  // connecting
  //std::cout << "Connecting menu event with id = " << usermenu_id << std::endl;
  Connect(usermenu_id,wxEVT_COMMAND_MENU_SELECTED,
     wxCommandEventHandler(MainFrame::OnUserMenuScript));

  

  
}

//--------------------------------------------------
void MainFrame::OnUserMenuScript(  wxCommandEvent& event)
{
  //cout << "MainFrame::OnUserMenuScript() ";
  //cout << "GetId() = "<< event.GetId() << std::endl;
  //cout << "script = " << usermenu_scripts[event.GetId()] << std::endl;
  std::string cmd; // increment the command line string

  
  wxString filename(usermenu_scripts[event.GetId()].c_str(),wxConvUTF8);
  scripts_history->AddFileToHistory(filename);


  cmd = (boost::format("func \"%1%\" // from menu") % usermenu_scripts[event.GetId()]).str();
  TC->ConsoleClear();
  this->TC->IncCommand(cmd);
  this->TC->ProcessReturn();
  
}


void MainFrame::OnUpdate(wxUpdateUIEvent& event)
{

  //Check Panels Status
  tb2->ToggleTool(ID_View_Output,m_mgr.GetPane(_log_text).IsShown());
  tb2->ToggleTool(ID_View_Param_book,m_mgr.GetPane(_param_book).IsShown());
  //tb2->ToggleTool(ID_View_Main_book,m_mgr.GetPane(_main_book).IsShown());
  tb2->ToggleTool(ID_View_Var_book,m_mgr.GetPane(_var_book).IsShown());

  tb2->ToggleTool(ID_View_aui_Main_bar,m_mgr.GetPane(this->tb1).IsShown());
  tb2->ToggleTool(ID_View_aui_Script_bar,m_mgr.GetPane(_("scripts_tb")).IsShown());
  tb2->ToggleTool(ID_View_aui_Status_bar,m_mgr.GetPane(this->tb2).IsShown());
  
  menuView2->Check(ID_View_Output, m_mgr.GetPane(_log_text).IsShown());
  menuView2->Check(ID_View_Param_book, m_mgr.GetPane(_param_book).IsShown());
  //menuView2->Check(ID_View_Main_book, m_mgr.GetPane(_main_book).IsShown());
  menuView2->Check(ID_View_Var_book, m_mgr.GetPane(_var_book).IsShown());

  menuView3->Check(ID_View_aui_Main_bar, m_mgr.GetPane(this->tb1).IsShown());
  menuView3->Check(ID_View_aui_Script_bar, m_mgr.GetPane(_("scripts_tb")).IsShown());  
  menuView3->Check(ID_View_aui_Status_bar,m_mgr.GetPane(this->tb2).IsShown());
//   if (!toolbar_status ==m_mgr.GetPane(this->tb1).IsShown())
//   {
//     int pos=1;
//     if (!toolbar_status)
//     {
//        m_mgr.GetPane(this->tb1).Position(pos++);
//        m_mgr.GetPane(this->tb2).Position(pos++);
//     }
//     else
//        m_mgr.GetPane(this->tb2).Position(pos++);
//     m_mgr.Update();
//       
//   }
//   toolbar_status= m_mgr.GetPane(this->tb1).IsShown();

  
 
 //this->Refresh(-1); //force repaint gnome (it's not a good idea)
  
}


// //helper functions
// enum wxbuildinfoformat {
//     short_f, long_f };
// wxString wxbuildinfo(wxbuildinfoformat format)
// {
//     wxString wxbuild(wxVERSION_STRING);
// 
//     if (format == long_f )
//     {
// #if defined(__WXMSW__)
//         wxbuild << _T("-Windows");
// #elif defined(__WXMAC__)
//         wxbuild << _T("-Mac");
// #elif defined(__UNIX__)
//         wxbuild << _T("-Linux");
// #endif
// 
// #if wxUSE_UNICODE
//         wxbuild << _T("-Unicode build");
// #else
//         wxbuild << _T("-ANSI build");
// #endif // wxUSE_UNICODE
//     }
// 
//     return wxbuild;
// }

void MainFrame::OnAbout(wxCommandEvent &event)
{
  dialogAbout->Show();
    //wxMessageBox(_("AMILab is an interpreted language for image processing designed using:\n   - C/C++\n   - Flex and Bison (gnu versions of Lex and Yacc)\n   - wxWidgets\n   - OpenGL\n   - VTK (not for rendering at the moment)\n   - ITK (not used much now, but will be more in the future)\nAMILab has a lot a features, and has been especially used for academic research in medical image processing. The tool is under development.\nVisit http://www.ctm.ulpgc.es/amilab_dokuwiki/ for more information about AMILab\n"), _("About AMILab"));
}


//--------------------------------------------------
void MainFrame::LoadToolBar   ( )
{
  toolbar_status=true;
  tb1->SetToolBitmapSize(wxSize(16,16));
//    tb1->AddTool(wxID_ANY, wxT("Test"), wxArtProvider::GetBitmap(wxART_ERROR));
//    tb1->AddSeparator();
  ::wxInitAllImageHandlers();
    //wxImage loadim(wxT("MRA_32_39.png"));
    //wxBitmap a(_("/Icons/png/32x32/Wait.png"),wxBITMAP_TYPE_PNG/*wxBitmap(LoadImage_Icon3_xpm)*/ );
    //std::cout << a.IsOk()<<endl;
    ;

  #define BITMAP_16x16(bmp_filename)\
    wxBitmap((wxImage(GB_scripts_dir+_T(bmp_filename),\
                      wxBITMAP_TYPE_PNG)).Rescale(16,16))

  tb1->AddTool( wxID_ToolLoadImage,
                wxT("Load Image"),
                BITMAP_16x16("/Icons/png/32x32/Open.png"),
                wxT("Load Image"));
  tb1->AddTool(wxID_UpdateVars, wxT("Update variables"), wxBitmap(reload),wxT("Update variables"));
  tb1->AddSeparator();
   
  tb1->AddTool(wxID_ConsoleClear, wxT("Clear console"), wxBitmap(gtk_clear),
      wxT("Console: left button -> clear last command, right button-> clear all"));

//   wxBitmapButton* but_clear = new wxBitmapButton(_prompt_panel,
//           wxID_ConsoleClear,
//           wxBitmap(gtk_clear));
//   wxToolTip::Enable(true);
//   but_clear->SetToolTip(GetwxStr("Clear current line"));
  tb1->AddSeparator();
  tb1->AddTool(wxID_ToolHelp, wxT("Help"), wxArtProvider::GetBitmap(wxART_HELP,wxART_OTHER,wxSize(16,16)),
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
                  ToolbarPane().Top().Position(1).
                  LeftDockable(false).RightDockable(false));
    

  tb2->Realize();

  //carlos
  tb2->AddTool( ID_View_Output, 
                BITMAP_16x16("/Icons/png/32x32/Writing pencil.png"),
                BITMAP_16x16("/Icons/png/32x32/Writing pencil.png"),
                true,NULL,
                _("Show/Hide Output") );
//   tb2->AddTool( ID_View_Main_book,   
//                 BITMAP_16x16("/Icons/png/32x32/Console.png"),
//                 BITMAP_16x16("/Icons/png/32x32/Console.png"),
//                 true,NULL,
//                 _("Show/Hide Main book") );
  tb2->AddTool( ID_View_Var_book,
                BITMAP_16x16("/Icons/png/32x32/Flow block.png"),
                BITMAP_16x16("/Icons/png/32x32/Flow block.png"),
                true,
                NULL,
                _("Show/Hide Var book") );
  tb2->AddTool( ID_View_Param_book,
                BITMAP_16x16("/Icons/png/32x32/Script.png"),
                BITMAP_16x16("/Icons/png/32x32/Script.png"),
                true,
                NULL,
                _("Show/Hide Param book") );
  tb2->AddSeparator();
  tb2->AddTool( ID_View_aui_Main_bar,
                BITMAP_16x16("/Icons/png/32x32/Tools.png"),
                BITMAP_16x16("/Icons/png/32x32/Tools.png"),
                true,
                NULL,
                _("Show/Hide Main toolbar") );
  tb2->AddTool( ID_View_aui_Script_bar,  
                BITMAP_16x16("/Icons/png/32x32/ToolsScript.png"),
                BITMAP_16x16("/Icons/png/32x32/ToolsScript.png"),
               true,
               NULL,
               _("Show/Hide Script toolbar") );
  tb2->AddSeparator();
  tb2->AddTool( ID_View_aui_Status_bar,
                BITMAP_16x16("/Icons/png/32x32/ToolsView.png"),
                BITMAP_16x16("/Icons/png/32x32/ToolsView.png"),
               true,NULL,_("Show/Hide Status toolbar") );
  tb2->AddSeparator();
  tb2->AddTool( ID_View_Reset,  
                BITMAP_16x16("/Icons/png/32x32/ResetView.png"),
                BITMAP_16x16("/Icons/png/32x32/ResetView.png"),
                false,NULL,
                _("Reset view") );

     // add the toolbars to the manager
  m_mgr.AddPane(tb2, wxAuiPaneInfo().
                  Name(wxT("tb2")).Caption(wxT("View Toolbar")).
                  ToolbarPane().Bottom()./*Position(2).*/
                  LeftDockable(false).RightDockable(false));
  

  // tell the manager to "commit" all the changes just made
  _initial_perspective = m_mgr.SavePerspective();
  m_mgr.Update();

  #undef BITMAP_16x16
}

//--------------------------------------------------
void MainFrame::OnHelpKeywords( wxCommandEvent& event )
{
  if ( !m_mgr.GetPane(_keywords_panel).IsShown())
  {
     m_mgr.GetPane(_keywords_panel).Show(); 
  }
  else
     m_mgr.GetPane(_keywords_panel).Hide(); 
  m_mgr.Update();
}