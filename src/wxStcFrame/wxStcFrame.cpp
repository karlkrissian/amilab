//////////////////////////////////////////////////////////////////////////////
// File:        contrib/samples/stc/wxStcFrame.cpp
// Purpose:     STC test application
// Maintainer:  Otto Wyss
// Created:     2003-09-01
// RCS-ID:      $Id: wxStcFrame.cpp 39402 2006-05-28 23:32:12Z VZ $
// Copyright:   (c) wxGuide
// Licence:     wxWindows licence
//////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all 'standard' wxWidgets headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

//! wxWidgets headers
#include "wx/config.h"   // configuration support
#include "wx/filedlg.h"  // file dialog support
#include "wx/filename.h" // filename support
#include "wx/notebook.h" // notebook support
#include "wx/settings.h" // system settings
#include "wx/string.h"   // strings support
#include "wx/image.h"    // images support

//! application headers
#include "defsext.h"     // Additional definitions
#include "wxEditor.h"        // wxEditor module
#include "prefs.h"       // Prefs
#include "wxStcFrame.h"


#include <wx/artprov.h>
//----------------------------------------------------------------------------
// resources
//----------------------------------------------------------------------------

// the application icon (under Windows and OS/2 it is in resources)
#if defined(__WXGTK__) || defined(__WXMOTIF__) || defined(__WXMAC__) || defined(__WXMGL__) || defined(__WXX11__)
    #include "mondrian.xpm"
#endif

//============================================================================
// declarations
//============================================================================

#define APP_NAME _T("STC-Test")
#define APP_DESCR _("See http://wxguide.sourceforge.net/")

#define APP_MAINT _T("Otto Wyss")
#define APP_VENDOR _T("wxWidgets")
#define APP_COPYRIGTH _T("(C) 2003 Otto Wyss")
#define APP_LICENCE _T("wxWidgets")

#define APP_VERSION _T("0.1.alpha")
#define APP_BUILD __DATE__

#define APP_WEBSITE _T("http://www.wxWidgets.org")
#define APP_MAIL _T("mailto://???")

#define NONAME _("<untitled>")

class AppBook;

enum {
  wxID_NOTEBOOK = 1000
};

//----------------------------------------------------------------------------

#if wxUSE_PRINTING_ARCHITECTURE

//! global print data, to remember settings during the session
wxPrintData *g_printData = (wxPrintData*) NULL;
wxPageSetupData *g_pageSetupData = (wxPageSetupData*) NULL;

#endif // wxUSE_PRINTING_ARCHITECTURE


class wxStcFrame;



//----------------------------------------------------------------------------
//! about box of the application APP_VENDOR-APP_NAME
class AppAbout: public wxDialog {

public:
    //! constructor
    AppAbout (wxWindow *parent,
              int milliseconds = 0,
              long style = 0);

    //! destructor
    ~AppAbout ();

    // event handlers
    void OnTimerEvent (wxTimerEvent &event);

private:
    // timer
    wxTimer *m_timer;

    DECLARE_EVENT_TABLE();
};


//============================================================================
// implementation
//============================================================================

//----------------------------------------------------------------------------
// wxStcFrame
//----------------------------------------------------------------------------

BEGIN_EVENT_TABLE (wxStcFrame, wxFrame)
    // common
    EVT_CLOSE (                      wxStcFrame::OnClose)
    // file
    EVT_MENU (wxID_OPEN,             wxStcFrame::OnFileOpen)
    EVT_MENU (wxID_SAVE,             wxStcFrame::OnFileSave)
    EVT_MENU (wxID_SAVEAS,           wxStcFrame::OnFileSaveAs)
    EVT_MENU (wxID_CLOSE,            wxStcFrame::OnFileClose)
    // properties
    EVT_MENU (myID_PROPERTIES,       wxStcFrame::OnProperties)
    // print and exit
    EVT_MENU (wxID_PRINT_SETUP,      wxStcFrame::OnPrintSetup)
    EVT_MENU (wxID_PREVIEW,          wxStcFrame::OnPrintPreview)
    EVT_MENU (wxID_PRINT,            wxStcFrame::OnPrint)
    EVT_MENU (wxID_EXIT,             wxStcFrame::OnExit)
    // edit
    EVT_MENU (wxID_CLEAR,            wxStcFrame::OnEdit)
    EVT_MENU (wxID_CUT,              wxStcFrame::OnEdit)
    EVT_MENU (wxID_COPY,             wxStcFrame::OnEdit)
    EVT_MENU (wxID_PASTE,            wxStcFrame::OnEdit)
    EVT_MENU (myID_INDENTINC,        wxStcFrame::OnEdit)
    EVT_MENU (myID_INDENTRED,        wxStcFrame::OnEdit)
    EVT_MENU (wxID_SELECTALL,        wxStcFrame::OnEdit)
    EVT_MENU (myID_SELECTLINE,       wxStcFrame::OnEdit)
    EVT_MENU (wxID_REDO,             wxStcFrame::OnEdit)
    EVT_MENU (wxID_UNDO,             wxStcFrame::OnEdit)
    // find
    EVT_MENU (wxID_FIND,             wxStcFrame::OnEdit)
    EVT_MENU (myID_FINDNEXT,         wxStcFrame::OnEdit)
    EVT_MENU (myID_REPLACE,          wxStcFrame::OnEdit)
    EVT_MENU (myID_REPLACENEXT,      wxStcFrame::OnEdit)
    EVT_MENU (myID_BRACEMATCH,       wxStcFrame::OnEdit)
    EVT_MENU (myID_GOTO,             wxStcFrame::OnEdit)
    // view
    EVT_MENU_RANGE (myID_HILIGHTFIRST, myID_HILIGHTLAST,
                                     wxStcFrame::OnEdit)
    EVT_MENU (myID_DISPLAYEOL,       wxStcFrame::OnEdit)
    EVT_MENU (myID_INDENTGUIDE,      wxStcFrame::OnEdit)
    EVT_MENU (myID_LINENUMBER,       wxStcFrame::OnEdit)
    EVT_MENU (myID_LONGLINEON,       wxStcFrame::OnEdit)
    EVT_MENU (myID_WHITESPACE,       wxStcFrame::OnEdit)
    EVT_MENU (myID_FOLDTOGGLE,       wxStcFrame::OnEdit)
    EVT_MENU (myID_OVERTYPE,         wxStcFrame::OnEdit)
    EVT_MENU (myID_READONLY,         wxStcFrame::OnEdit)
    EVT_MENU (myID_WRAPMODEON,       wxStcFrame::OnEdit)
    // extra
    EVT_MENU (myID_CHANGELOWER,      wxStcFrame::OnEdit)
    EVT_MENU (myID_CHANGEUPPER,      wxStcFrame::OnEdit)
    EVT_MENU (myID_CONVERTCR,        wxStcFrame::OnEdit)
    EVT_MENU (myID_CONVERTCRLF,      wxStcFrame::OnEdit)
    EVT_MENU (myID_CONVERTLF,        wxStcFrame::OnEdit)
    EVT_MENU (myID_CHARSETANSI,      wxStcFrame::OnEdit)
    EVT_MENU (myID_CHARSETMAC,       wxStcFrame::OnEdit)
    // help
    EVT_MENU (wxID_ABOUT,            wxStcFrame::OnAbout)
    //Event when close a tab
    EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_NOTEBOOK, wxStcFrame::OnCloseTab)
END_EVENT_TABLE ()

//----------------------------------------------------------------------------
//epf contructor & destructor
epf::epf (wxEditor* e, wxWindow* p, wxString f) {
  ed = e;
  pag = p;
  filena = f;
}

epf::~epf () {}

wxEditor* epf::getEd() {
  return ed;
}

wxWindow* epf::getPag() {
  return pag;
}

wxString epf::getFilena() {
  return filena;
}

//tabsVector methods
tabsVector::tabsVector () {}

tabsVector::~tabsVector () {}

void tabsVector::addTab (wxEditor* editor, wxWindow* page, const wxString& filename) {
  epf tab(editor, page, filename);
  vec.push_back(tab);
}

void tabsVector::delTab (wxWindow* page) {
  vector<epf>::iterator it;
  for (it = vec.begin(); it != vec.end(); it++) {
    if (page == it->getPag()) {
      it = vec.erase(it);
      return;
    }
  }
}

wxEditor* tabsVector::getEdit (wxWindow* page) {
  vector<epf>::iterator it;
  for (it = vec.begin(); it != vec.end() ; it++) {
    if (page == it->getPag()) {
      return it->getEd();
    }
  }
  return NULL;
}

wxWindow* tabsVector::getPage (const wxString& filename) {
  vector<epf>::iterator it;
  for (it = vec.begin(); it != vec.end(); it++) {
    if (filename == it->getFilena()) {
      return it->getPag();
    }
  }
  return NULL;
}

wxWindow* tabsVector::getPage (wxEditor* ed) {
  vector<epf>::iterator it;
  for (it = vec.begin(); it != vec.end(); it++) {
    if (ed == it->getEd()) {
      return it->getPag();
    }
  }
  return NULL;
}

//----------------------------------------------------------------------------

wxStcFrame::wxStcFrame (wxWindow* parent,const wxString &title)
        : wxFrame (parent, wxID_ANY, title, wxDefaultPosition, wxSize(750,550),
                    wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE) {

    // intitialize important variables
    //m_edit = NULL;

    // set icon and background
    SetTitle (title);
    SetIcon (wxICON (mondrian));
    SetBackgroundColour (_T("WHITE"));

    // about box shown for 1 seconds
    AppAbout dlg(this, 1000);

    // create menu
    m_menuBar = new wxMenuBar;
    CreateMenu ();

    // open first page
    //m_edit = new wxEditor (this, wxID_ANY);
    //m_edit->SetFocus();
    //Create notebook
    notebook = new wxAuiNotebook(this, wxID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
    pageCount = 1;
}

wxStcFrame::~wxStcFrame () {
}

// common event handlers
/*void wxStcFrame::OnClose (wxCloseEvent &event) {
    wxCommandEvent evt;
    OnFileClose (evt);
    if (m_edit && m_edit->Modified()) {
        if (event.CanVeto()) event.Veto (true);
        return;
    }
    Destroy();
}*/

//With AuiNotebook
void wxStcFrame::OnClose (wxCloseEvent &event) {
  wxCommandEvent evt;
  OnFileClose (evt);
  wxEditor* e = GetActiveEditor();
  if (e == NULL) return;
  
  if (e && e->Modified()) {
      if (event.CanVeto()) event.Veto (true);
      return;
  }
}

void wxStcFrame::OnAbout (wxCommandEvent &WXUNUSED(event)) {
    AppAbout dlg(this);
}

void wxStcFrame::OnExit (wxCommandEvent &WXUNUSED(event)) {
  //Is necessary test if there are changes in tabs
  while (notebook->GetPageCount() > 0) {
    wxEditor* e          = GetActiveEditor();
    wxFileName f     = e->GetFilename();
    wxString close   = wxT("Close: ");
    wxString message = wxT("Path: ");
    
    message.append(f.GetFullPath());
    message.append(wxT("\n\nText is not saved, save before closing?"));
    close.append(f.GetFullName());
    
    if (e->Modified()) {
      if (wxMessageBox (message, close,
                        wxYES_NO | wxICON_QUESTION) == wxYES) {
          e->SaveFile();
          if (e->Modified()) {
              wxMessageBox (_("Text could not be saved!"), _("Close abort"),
                            wxOK | wxICON_EXCLAMATION);
              return;
          }
      }
    }
    
    wxWindow* p = tabs.getPage(e);
    tabs.delTab(p);
    int page_idx = notebook->GetPageIndex(p);
    if (page_idx != wxNOT_FOUND) {
      notebook->DeletePage(size_t(page_idx));
    }
  }
  Destroy();
}

// file event handlers
/*void wxStcFrame::OnFileOpen (wxCommandEvent &WXUNUSED(event)) {
    if (!m_edit) return;
#if wxUSE_FILEDLG
    wxString fname;
    wxFileDialog dlg (this, _T("Open file"), wxEmptyString, wxEmptyString, _T("Any file (*)|*"),
                      wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR);
    if (dlg.ShowModal() != wxID_OK) return;
    fname = dlg.GetPath ();
    FileOpen (fname);
#endif // wxUSE_FILEDLG
}*/
//With AuiNotebook
void wxStcFrame::OnFileOpen (wxCommandEvent &WXUNUSED(event)) {
  if (!notebook) return;
#if wxUSE_FILEDLG
  wxString fname;
  wxFileDialog dlg (this, _T("Open file"), wxEmptyString, wxEmptyString, _T("Any file (*)|*|amilab scripts (*.amil)"),
                    wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR);
  if (dlg.ShowModal() != wxID_OK) return;
  fname = dlg.GetPath ();
  FileOpen (fname);
#endif // wxUSE_FILEDLG
}

/*void wxStcFrame::OnFileSave (wxCommandEvent &WXUNUSED(event)) {
    if (!m_edit) return;
    if (!m_edit->Modified()) {
        wxMessageBox (_("There is nothing to save!"), _("Save file"),
                      wxOK | wxICON_EXCLAMATION);
        return;
    }
    m_edit->SaveFile ();
}*/
//With AuiNotebook
void wxStcFrame::OnFileSave (wxCommandEvent &WXUNUSED(event)) {
  if (!notebook) return;
  wxEditor* e = GetActiveEditor();
  if (!e->Modified()) {
    wxMessageBox (_("There is nothing to save!"), _("Save file"),
                  wxOK | wxICON_EXCLAMATION);
    return;
  }
  e->SaveFile ();
}

/*void wxStcFrame::OnFileSaveAs (wxCommandEvent &WXUNUSED(event)) {
    if (!m_edit) return;
#if wxUSE_FILEDLG
    wxString filename = wxEmptyString;
    wxFileDialog dlg (this, _T("Save file"), wxEmptyString, wxEmptyString, _T("Any file (*)|*"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (dlg.ShowModal() != wxID_OK) return;
    filename = dlg.GetPath();
    m_edit->SaveFile (filename);
#endif // wxUSE_FILEDLG
}*/
//With AuiNotebook
void wxStcFrame::OnFileSaveAs (wxCommandEvent &WXUNUSED(event)) {
  if (!notebook) return;
#if wxUSE_FILEDLG
  wxEditor* e           = GetActiveEditor();
  wxWindow* p       = tabs.getPage(e);
  wxString filename = wxEmptyString;
  
  wxFileDialog dlg (this, _T("Save file"), wxEmptyString, wxEmptyString, _T("Any file (*)|*"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
  if (dlg.ShowModal() != wxID_OK) return;
  filename = dlg.GetPath();
  e->SaveFile(filename);
  tabs.delTab(p); //Delete old entry on tabs
  tabs.addTab(e, p, filename); //Add the new entry
  wxFileName f(filename);
  notebook->RemovePage(size_t(notebook->GetPageIndex(p)));
  notebook->AddPage(p, f.GetFullName(), true, wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16)));
#endif // wxUSE_FILEDLG
}

/*void wxStcFrame::OnFileClose (wxCommandEvent &WXUNUSED(event)) {
    if (!m_edit) return;
    if (m_edit->Modified()) {
        if (wxMessageBox (_("Text is not saved, save before closing?"), _("Close"),
                          wxYES_NO | wxICON_QUESTION) == wxYES) {
            m_edit->SaveFile();
            if (m_edit->Modified()) {
                wxMessageBox (_("Text could not be saved!"), _("Close abort"),
                              wxOK | wxICON_EXCLAMATION);
                return;
            }
        }
    }
    m_edit->SetFilename (wxEmptyString);
    m_edit->ClearAll();
    m_edit->SetSavePoint();
}*/
//With AuiNotebook
void wxStcFrame::OnFileClose (wxCommandEvent &WXUNUSED(event)) {
  if (!notebook) return;
  //If there aren't tabs, close editor directly
  if (notebook->GetPageCount() == 0) {
    Destroy();
    return;
  }
  wxEditor* e          = GetActiveEditor();
  wxFileName f     = e->GetFilename();
  wxString close   = wxT("Close: ");
  wxString message = wxT("Path: ");
  
  message.append(f.GetFullPath());
  message.append(wxT("\n\nText is not saved, save before closing?"));
  close.append(f.GetFullName());
  
  if (e->Modified()) {
    if (wxMessageBox (message, close,
                      wxYES_NO | wxICON_QUESTION) == wxYES) {
        e->SaveFile();
        if (e->Modified()) {
            wxMessageBox (_("Text could not be saved!"), _("Close abort"),
                          wxOK | wxICON_EXCLAMATION);
            return;
        }
    }
  }
  
  e->Clear();
  e->SetSavePoint();
  //Erase the edit pointer of the tab vector
  wxWindow* p = tabs.getPage(e);
  //e->SetFilename (wxEmptyString);
  tabs.delTab(p);
  
  if (notebook->GetPageCount() == 1) {
    Destroy();
    return;
  }
  
  int page_idx = notebook->GetPageIndex(p);
  if (page_idx != wxNOT_FOUND) {
    notebook->DeletePage(size_t(page_idx));
  }
 
}

// properties event handlers
/*void wxStcFrame::OnProperties (wxCommandEvent &WXUNUSED(event)) {
    if (!m_edit) return;
    EditProperties dlg(m_edit, 0);
}*/
// properties event handlers with AuiNotebook
void wxStcFrame::OnProperties (wxCommandEvent &WXUNUSED(event)) {
  wxEditor* e = GetActiveEditor();
  if (!e) return;
  EditProperties dlg(e, 0);
}

// print event handlers
void wxStcFrame::OnPrintSetup (wxCommandEvent &WXUNUSED(event)) {
#if wxUSE_PRINTING_ARCHITECTURE
    (*g_pageSetupData) = * g_printData;
    wxPageSetupDialog pageSetupDialog(this, g_pageSetupData);
    pageSetupDialog.ShowModal();
    (*g_printData) = pageSetupDialog.GetPageSetupData().GetPrintData();
    (*g_pageSetupData) = pageSetupDialog.GetPageSetupData();
#endif // wxUSE_PRINTING_ARCHITECTURE
}

/*void wxStcFrame::OnPrintPreview (wxCommandEvent &WXUNUSED(event)) {
#if wxUSE_PRINTING_ARCHITECTURE
    wxPrintDialogData printDialogData( *g_printData);
    wxPrintPreview *preview =
        new wxPrintPreview (new EditPrint (m_edit),
                            new EditPrint (m_edit),
                            &printDialogData);
    if (!preview->Ok()) {
        delete preview;
        wxMessageBox (_("There was a problem with previewing.\n\
                         Perhaps your current printer is not correctly?"),
                      _("Previewing"), wxOK);
        return;
    }
    wxRect rect = DeterminePrintSize();
    wxPreviewFrame *frame = new wxPreviewFrame (preview, this, _("Print Preview"));
    frame->SetSize (rect);
    frame->Centre(wxBOTH);
    frame->Initialize();
    frame->Show(true);
#endif // wxUSE_PRINTING_ARCHITECTURE
}*/

//With AuiNotebook
void wxStcFrame::OnPrintPreview (wxCommandEvent &WXUNUSED(event)) {
#if wxUSE_PRINTING_ARCHITECTURE
  wxEditor* e = GetActiveEditor();
  wxPrintDialogData printDialogData( *g_printData);
  wxPrintPreview *preview =
      new wxPrintPreview (new EditPrint (e),
                          new EditPrint (e),
                          &printDialogData);
  if (!preview->Ok()) {
      delete preview;
      wxMessageBox (_("There was a problem with previewing.\n\
                       Perhaps your current printer is not correctly?"),
                    _("Previewing"), wxOK);
      return;
  }
  wxRect rect = DeterminePrintSize();
  wxPreviewFrame *frame = new wxPreviewFrame (preview, this, _("Print Preview"));
  frame->SetSize (rect);
  frame->Centre(wxBOTH);
  frame->Initialize();
  frame->Show(true);
#endif // wxUSE_PRINTING_ARCHITECTURE
}

/*void wxStcFrame::OnPrint (wxCommandEvent &WXUNUSED(event)) {
#if wxUSE_PRINTING_ARCHITECTURE
    wxPrintDialogData printDialogData( *g_printData);
    wxPrinter printer (&printDialogData);
    EditPrint printout (m_edit);
    if (!printer.Print (this, &printout, true)) {
        if (wxPrinter::GetLastError() == wxPRINTER_ERROR) {
        wxMessageBox (_("There was a problem with printing.\n\
                         Perhaps your current printer is not correctly?"),
                      _("Previewing"), wxOK);
            return;
        }
    }
    (*g_printData) = printer.GetPrintDialogData().GetPrintData();
#endif // wxUSE_PRINTING_ARCHITECTURE
}*/

//With AuiNotebook
void wxStcFrame::OnPrint (wxCommandEvent &WXUNUSED(event)) {
#if wxUSE_PRINTING_ARCHITECTURE
  wxEditor* e = GetActiveEditor();
  wxPrintDialogData printDialogData( *g_printData);
  wxPrinter printer (&printDialogData);
  EditPrint printout (e);
  if (!printer.Print (this, &printout, true)) {
      if (wxPrinter::GetLastError() == wxPRINTER_ERROR) {
      wxMessageBox (_("There was a problem with printing.\n\
                       Perhaps your current printer is not correctly?"),
                    _("Previewing"), wxOK);
          return;
      }
  }
  (*g_printData) = printer.GetPrintDialogData().GetPrintData();
#endif // wxUSE_PRINTING_ARCHITECTURE
}

// edit events
/*void wxStcFrame::OnEdit (wxCommandEvent &event) {
    if (m_edit) m_edit->ProcessEvent (event);
}*/

// edit events with AuiNotebook
void wxStcFrame::OnEdit (wxCommandEvent &event) {
  wxEditor* e = GetActiveEditor();
  if (e) e->GetEventHandler()->ProcessEvent (event);
}

//----------------------------------------------------------------------------
//Returns a pointer to the active editor in the notebook
wxEditor* wxStcFrame::GetActiveEditor () {
  if (!notebook) return NULL;
  wxEditor* e      = NULL;
  int page_idx = notebook->GetSelection();
  wxWindow* p  = notebook->GetPage(size_t(page_idx));
  e            = tabs.getEdit(p);
  return e;
}
//It's called when click on tab close button
void wxStcFrame::OnCloseTab (wxAuiNotebookEvent & event) {
  if (!notebook) return;
  //If there aren't tabs, close editor directly
  if (notebook->GetPageCount() == 0) {
    Destroy();
    return;
  }
  wxEditor* e          = GetActiveEditor();
  wxFileName f     = e->GetFilename();
  wxString close   = wxT("Close: ");
  wxString message = wxT("Path: ");

  
  message.append(f.GetFullPath());
  message.append(wxT("\n\nText is not saved, save before closing?"));
  close.append(f.GetFullName());
  
  if (e->Modified()) {
      if (wxMessageBox (message, close,
                        wxYES_NO | wxICON_QUESTION) == wxYES) {
          e->SaveFile();
          if (e->Modified()) {
              wxMessageBox (_("Text could not be saved!"), _("Close abort"),
                            wxOK | wxICON_EXCLAMATION);
              return;
          }
      }
  }
  
  e->Clear();
  e->SetSavePoint();
  //Erase the edit pointer of the tab vector
  wxWindow* p = tabs.getPage(e);
  tabs.delTab(p);
  
  //If is the last tab, close the editor
  if (notebook->GetPageCount() == 1) {
    Destroy();
    return;
  }
}
//----------------------------------------------------------------------------


// private functions
void wxStcFrame::CreateMenu ()
{
    // File menu
    wxMenu *menuFile = new wxMenu;
    menuFile->Append (wxID_OPEN, _("&Open ..\tCtrl+O"));
    menuFile->Append (wxID_SAVE, _("&Save\tCtrl+S"));
    menuFile->Append (wxID_SAVEAS, _("Save &as ..\tCtrl+Shift+S"));
    menuFile->Append (wxID_CLOSE, _("&Close\tCtrl+W"));
    menuFile->AppendSeparator();
    menuFile->Append (myID_PROPERTIES, _("Proper&ties ..\tCtrl+I"));
    menuFile->AppendSeparator();
    menuFile->Append (wxID_PRINT_SETUP, _("Print Set&up .."));
    menuFile->Append (wxID_PREVIEW, _("Print Pre&view\tCtrl+Shift+P"));
    menuFile->Append (wxID_PRINT, _("&Print ..\tCtrl+P"));
    menuFile->AppendSeparator();
    menuFile->Append (wxID_EXIT, _("&Quit\tCtrl+Q"));

    // wxEditor menu
    wxMenu *menuEdit = new wxMenu;
    menuEdit->Append (wxID_UNDO, _("&Undo\tCtrl+Z"));
    menuEdit->Append (wxID_REDO, _("&Redo\tCtrl+Shift+Z"));
    menuEdit->AppendSeparator();
    menuEdit->Append (wxID_CUT, _("Cu&t\tCtrl+X"));
    menuEdit->Append (wxID_COPY, _("&Copy\tCtrl+C"));
    menuEdit->Append (wxID_PASTE, _("&Paste\tCtrl+V"));
    menuEdit->Append (wxID_CLEAR, _("&Delete\tDel"));
    menuEdit->AppendSeparator();
    menuEdit->Append (wxID_FIND, _("&Find and replace\tCtrl+F"));
//    menuEdit->Enable (wxID_FIND, false);
    /*menuEdit->Append (myID_FINDNEXT, _("Find &next\tF3"));
    menuEdit->Enable (myID_FINDNEXT, false);
    menuEdit->Append (myID_REPLACE, _("&Replace\tCtrl+H"));
    menuEdit->Enable (myID_REPLACE, false);
    menuEdit->Append (myID_REPLACENEXT, _("Replace &again\tShift+F4"));
    menuEdit->Enable (myID_REPLACENEXT, false);*/
    menuEdit->AppendSeparator();
    menuEdit->Append (myID_BRACEMATCH, _("&Match brace\tCtrl+M"));
    menuEdit->Append (myID_GOTO, _("&Goto\tCtrl+G"));
//    menuEdit->Enable (myID_GOTO, false);
    menuEdit->AppendSeparator();
    menuEdit->Append (myID_INDENTINC, _("&Indent increase\tTab"));
    menuEdit->Append (myID_INDENTRED, _("I&ndent reduce\tBksp"));
    menuEdit->AppendSeparator();
    menuEdit->Append (wxID_SELECTALL, _("&Select all\tCtrl+A"));
    menuEdit->Append (myID_SELECTLINE, _("Select &line\tCtrl+L"));

    // hilight submenu
    wxMenu *menuHilight = new wxMenu;
    int Nr;
    for (Nr = 0; Nr < g_LanguagePrefsSize; Nr++) {
        menuHilight->Append (myID_HILIGHTFIRST + Nr,
                             g_LanguagePrefs [Nr].name);
    }

    // charset submenu
    wxMenu *menuCharset = new wxMenu;
    menuCharset->Append (myID_CHARSETANSI, _("&ANSI (Windows)"));
    menuCharset->Append (myID_CHARSETMAC, _("&MAC (Macintosh)"));

    // View menu
    wxMenu *menuView = new wxMenu;
    menuView->Append (myID_HILIGHTLANG, _("&Hilight language .."), menuHilight);
    menuView->AppendSeparator();
    menuView->AppendCheckItem (myID_FOLDTOGGLE, _("&Toggle current fold\tCtrl+T"));
    menuView->AppendCheckItem (myID_OVERTYPE, _("&Overwrite mode\tIns"));
    menuView->AppendCheckItem (myID_WRAPMODEON, _("&Wrap mode\tCtrl+U"));
    menuView->AppendSeparator();
    menuView->AppendCheckItem (myID_DISPLAYEOL, _("Show line &endings"));
    menuView->AppendCheckItem (myID_INDENTGUIDE, _("Show &indent guides"));
    menuView->AppendCheckItem (myID_LINENUMBER, _("Show line &numbers"));
    menuView->AppendCheckItem (myID_LONGLINEON, _("Show &long line marker"));
    menuView->AppendCheckItem (myID_WHITESPACE, _("Show white&space"));
    menuView->AppendSeparator();
    menuView->Append (myID_USECHARSET, _("Use &code page of .."), menuCharset);

    // change case submenu
    wxMenu *menuChangeCase = new wxMenu;
    menuChangeCase->Append (myID_CHANGEUPPER, _("&Upper case"));
    menuChangeCase->Append (myID_CHANGELOWER, _("&Lower case"));

    // convert EOL submenu
    wxMenu *menuConvertEOL = new wxMenu;
    menuConvertEOL->Append (myID_CONVERTCR, _("CR (&Linux)"));
    menuConvertEOL->Append (myID_CONVERTCRLF, _("CR+LF (&Windows)"));
    menuConvertEOL->Append (myID_CONVERTLF, _("LF (&Macintosh)"));

    // Extra menu
    wxMenu *menuExtra = new wxMenu;
    menuExtra->AppendCheckItem (myID_READONLY, _("&Readonly mode"));
    menuExtra->AppendSeparator();
    menuExtra->Append (myID_CHANGECASE, _("Change &case to .."), menuChangeCase);
    menuExtra->AppendSeparator();
    menuExtra->Append (myID_CONVERTEOL, _("Convert line &endings to .."), menuConvertEOL);

    // Window menu
    wxMenu *menuWindow = new wxMenu;
    menuWindow->Append (myID_PAGEPREV, _("&Previous\tCtrl+Shift+Tab"));
    menuWindow->Append (myID_PAGENEXT, _("&Next\tCtrl+Tab"));

    // Help menu
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append (wxID_ABOUT, _("&About ..\tShift+F1"));

    // construct menu
    m_menuBar->Append (menuFile, _("&File"));
    m_menuBar->Append (menuEdit, _("&wxEditor"));
    m_menuBar->Append (menuView, _("&View"));
    m_menuBar->Append (menuExtra, _("E&xtra"));
    m_menuBar->Append (menuWindow, _("&Window"));
    m_menuBar->Append (menuHelp, _("&Help"));
    SetMenuBar (m_menuBar);
}

/*void wxStcFrame::FileOpen (wxString fname)
{
    wxFileName w(fname); w.Normalize(); fname = w.GetFullPath();
    m_edit->LoadFile (fname);
}*/

//With AuiNotebook
void wxStcFrame::FileOpen (wxString fname)
{
  //Empty file (when open a new tab)
  /*if (fname.IsEmpty()) {
    wxString tabName = "unnamed ";
    tabName.append(wxString() << pageCount);
    pageCount++;
    wxPanel* page = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, "");
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxEditor* editor = new wxEditor(page, wxID_ANY, wxDefaultPosition, wxSize(730,530), wxSUNKEN_BORDER | wxVSCROLL);
    editor->SetMinSize(wxSize(73,53));
    sizer->Add(editor, 1, wxEXPAND | wxALL, 0);
    page->SetSizer(sizer);
      
    wxFileName w(fname); w.Normalize(); fname = w.GetFullPath();
    editor->ShowLineNumbers(true);
    
    //Add the new page to the notebook editor
    notebook->AddPage(page, wxT(w.GetFullName()), true, wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16)));
    //Add editor pointer to tab vector
    tabs.addTab(editor, page, fname);
    return;
  }*/
  
 
  wxWindow* w = tabs.getPage(fname);
  //Is file open already??
  if (w != NULL) {
    //Build the message dialog
    wxString message = wxT("The file ");
    message.append(fname);
    message.append(wxT(" is already open.\n Do you want to open it again? (WARNING: not controlled)"));
    wxMessageDialog* dialog = new wxMessageDialog(this, message, wxT("WARNING"), wxYES_NO | wxCENTER | wxICON_EXCLAMATION);
    int answer = dialog->ShowModal();
    
    //Create a new tab and split it on the right side
    if (answer == wxID_YES) {
      wxPanel* page     = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, wxT(""));
      wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
      wxEditor* editor      = new wxEditor(page, wxID_ANY, wxDefaultPosition, wxSize(730,530), wxSUNKEN_BORDER | wxVSCROLL);
      editor->SetMinSize(wxSize(73,53));
      sizer->Add(editor, 1, wxEXPAND | wxALL, 0);
      page->SetSizer(sizer);
      wxFileName f(fname);
      editor->LoadFile (fname);
      editor->ShowLineNumbers(true);
      editor->SetCaretLineVisible(1);
      editor->SetCaretLineBackground(wxColour(230,230,230,wxALPHA_OPAQUE));
      notebook->AddPage(page, f.GetFullName(), true, wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16)));
      notebook->Split(size_t(notebook->GetPageIndex(page)), wxRIGHT);
      tabs.addTab(editor, page, fname);
    }
    //Else, set focus on the file tab
    else {
      int page_idx = notebook->GetPageIndex(w);
      notebook->SetSelection(size_t(page_idx));
    }
  }
  else {
    //Isn't open
    wxPanel* page     = new wxPanel(notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, wxT(""));
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxEditor* editor      = new wxEditor(page, wxID_ANY, wxDefaultPosition, wxSize(730,530), wxSUNKEN_BORDER | wxVSCROLL);
    editor->SetMinSize(wxSize(73,53));
    sizer->Add(editor, 1, wxEXPAND | wxALL, 0);
    page->SetSizer(sizer);
      
    wxFileName w(fname); w.Normalize(); fname = w.GetFullPath();
    editor->LoadFile (fname);
    editor->ShowLineNumbers(true);
    editor->SetCaretLineVisible(1);
    editor->SetCaretLineBackground(wxColour(230,230,230,wxALPHA_OPAQUE));
    
    //Add the new page to the notebook editor
    notebook->AddPage(page, w.GetFullName(), true, wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16)));
    //Add editor pointer to tabVector
    tabs.addTab(editor, page, fname);
  }
}

wxRect wxStcFrame::DeterminePrintSize () {

    wxSize scr = wxGetDisplaySize();

    // determine position and size (shifting 16 left and down)
    wxRect rect = GetRect();
    rect.x += 16;
    rect.y += 16;
    rect.width = wxMin (rect.width, (scr.x - rect.x));
    rect.height = wxMin (rect.height, (scr.x - rect.y));

    return rect;
}


//----------------------------------------------------------------------------
// AppAbout
//----------------------------------------------------------------------------

BEGIN_EVENT_TABLE (AppAbout, wxDialog)
    EVT_TIMER (myID_ABOUTTIMER, AppAbout::OnTimerEvent)
END_EVENT_TABLE ()

AppAbout::AppAbout (wxWindow *parent,
                    int milliseconds,
                    long style)
        : wxDialog (parent, wxID_ANY, wxEmptyString,
                    wxDefaultPosition, wxDefaultSize,
                    style | wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER) {

    // set timer if any
    m_timer = NULL;
    if (milliseconds > 0) {
        m_timer = new wxTimer (this, myID_ABOUTTIMER);
        m_timer->Start (milliseconds, wxTIMER_ONE_SHOT);
    }

    // sets the application title
    SetTitle (_("About .."));

    // about info
    wxGridSizer *aboutinfo = new wxGridSizer (2, 0, 2);
    aboutinfo->Add (new wxStaticText(this, wxID_ANY, _("Written by: ")),
                    0, wxALIGN_LEFT);
    aboutinfo->Add (new wxStaticText(this, wxID_ANY, APP_MAINT),
                    1, wxEXPAND | wxALIGN_LEFT);
    aboutinfo->Add (new wxStaticText(this, wxID_ANY, _("Version: ")),
                    0, wxALIGN_LEFT);
    aboutinfo->Add (new wxStaticText(this, wxID_ANY, APP_VERSION),
                    1, wxEXPAND | wxALIGN_LEFT);
    aboutinfo->Add (new wxStaticText(this, wxID_ANY, _("Licence type: ")),
                    0, wxALIGN_LEFT);
    aboutinfo->Add (new wxStaticText(this, wxID_ANY, APP_LICENCE),
                    1, wxEXPAND | wxALIGN_LEFT);
    aboutinfo->Add (new wxStaticText(this, wxID_ANY, _("Copyright: ")),
                    0, wxALIGN_LEFT);
    aboutinfo->Add (new wxStaticText(this, wxID_ANY, APP_COPYRIGTH),
                    1, wxEXPAND | wxALIGN_LEFT);

    // about icontitle//info
    wxBoxSizer *aboutpane = new wxBoxSizer (wxHORIZONTAL);
    wxBitmap bitmap = wxBitmap(wxICON (mondrian));
    aboutpane->Add (new wxStaticBitmap (this, wxID_ANY, bitmap),
                    0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 20);
    aboutpane->Add (aboutinfo, 1, wxEXPAND);
    aboutpane->Add (60, 0);

    // about complete
    wxBoxSizer *totalpane = new wxBoxSizer (wxVERTICAL);
    totalpane->Add (0, 20);
    totalpane->Add (0, 10);
    totalpane->Add (aboutpane, 0, wxEXPAND | wxALL, 4);
    totalpane->Add (new wxStaticText(this, wxID_ANY, APP_DESCR),
                    0, wxALIGN_CENTER | wxALL, 10);
    wxButton *okButton = new wxButton (this, wxID_OK, _("OK"));
    okButton->SetDefault();
    totalpane->Add (okButton, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT | wxBOTTOM, 10);

    SetSizerAndFit (totalpane);

    CenterOnScreen();
    ShowModal();
}

AppAbout::~AppAbout () {
    if (m_timer)  {
        delete m_timer;
        m_timer = NULL;
    }
}

//----------------------------------------------------------------------------
// event handlers
void AppAbout::OnTimerEvent (wxTimerEvent &WXUNUSED(event)) {
    if (m_timer) delete m_timer;
    m_timer = NULL;
    EndModal (wxID_OK);
}
