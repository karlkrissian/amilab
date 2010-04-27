//
// C++ Interface: stctest
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _stctest_h_
#define _stctest_h_


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

/*
//! wxWidgets headers
#include "wx/config.h"   // configuration support
#include "wx/filedlg.h"  // file dialog support
#include "wx/filename.h" // filename support
#include "wx/notebook.h" // notebook support
#include "wx/settings.h" // system settings
#include "wx/string.h"   // strings support
#include "wx/image.h"    // images support

*/
//! application headers
#include "defsext.h"     // Additional definitions
#include "edit.h"        // Edit module
#include "prefs.h"       // Prefs

#include <wx/aui/auibook.h> //wxAuiNotebook for editor
#include <vector>
using namespace std;


//----------------------------------------------------------------------------
/**
 *  epf class. Represent a structure with two pointers (editor and page -wxAuiNotebook page-) and a wxString, the filename
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
//class for tabs (edit + page + filename)
class epf {

public:
  /**
   *  Create an "epf" object.
   *  @param e A pointer to Edit.
   *  @param p A pointer to wxWindow (wxAuiNotebook tab).
   *  @param f Filename.
   */
  epf (Edit* e, wxWindow* p, wxString f);
 
  //Destructor
  ~epf ();
  
  /**
   *  Method to get the Edit pointer.
   *  @return This function returns a pointer to Edit object.
   */
  Edit* getEd ();
  
  /**
   *  Method to get the tab pointer.
   *  @return This function returns a pointer to wxWindow object.
   */
  wxWindow* getPag ();
  
  /**
   *  Method to get the filename.
   *  @return This function returns a wxString with the filename.
   */
  wxString getFilena ();
  
private:
  Edit* ed;
  wxWindow* pag;
  wxString filena;
};

/**
 *  tabsVector class. Use a STL vector<T> where T is epf
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class tabsVector {

public:
  /**
   *  Create a tabsVector object.
   */
  tabsVector ();
  
  //Destructor
  ~tabsVector ();
  
  /**
   *  When add a page to wxAuiNotebook, add a tab to the vector's end.
   *  @param editor A pointer to Edit object.
   *  @param page A pointer to wxWindow object (the page inside wxAuiNotebook).
   *  @param filename A const wxString whith the filename.
   *  @return Nothing
   */
  void addTab (Edit* editor, wxWindow* page, const wxString& filename);
  
  /**
   *  Delete the appropiate tab, searching the pointer to a wxWindow object.
   *  @param page A pointer to wxWindow object.
   *  @return Nothing
   */
  void delTab (wxWindow* page);
  
  /**
   *  Method to get a pointer to Edit object, searching the pointer to a wxWindow object.
   *  @param page A pointer to wxWindow object.
   *  @return A pointer to Edit object.
   */
  Edit* getEdit (wxWindow* page);
  
  /**
   *  Method to get a pointer to wxWindow object, searching the filename. It's used to determine if a file is open.
   *  @param filename A const wxString with the filename.
   *  @return A pointer to wxWindow object.
   */
  wxWindow* getPage (const wxString& filename);
  
  /**
   *  Method to get a pointer to wxWindow object, searching the pointer to an Edit object. It's used when close a tab.
   *  @param ed A pointer to Edit object.
   *  @return A pointer to wxWindow object.
   */
  wxWindow* getPage (Edit* ed);
  
private:
  vector<epf> vec;
};
//----------------------------------------------------------------------------
//! frame of the application APP_VENDOR-APP_NAME.
class StcTestFrame: public wxFrame {
    friend class App;
    friend class AppBook;
    friend class AppAbout;

public:
    //! constructor
    StcTestFrame (wxWindow* parent, const wxString &title);

    //! destructor
    ~StcTestFrame ();

    //! event handlers
    //! common
    void OnClose (wxCloseEvent &event);
    void OnAbout (wxCommandEvent &event);
    void OnExit (wxCommandEvent &event);
    void OnTimerEvent (wxTimerEvent &event);
    //! file
    void OnFileNew (wxCommandEvent &event);
    void OnFileNewFrame (wxCommandEvent &event);
    void OnFileOpen (wxCommandEvent &event);
    void OnFileOpenFrame (wxCommandEvent &event);
    void OnFileSave (wxCommandEvent &event);
    void OnFileSaveAs (wxCommandEvent &event);
    void OnFileClose (wxCommandEvent &event);
    //! properties
    void OnProperties (wxCommandEvent &event);
    //! print
    void OnPrintSetup (wxCommandEvent &event);
    void OnPrintPreview (wxCommandEvent &event);
    void OnPrint (wxCommandEvent &event);
    //! edit events
    void OnEdit (wxCommandEvent &event);

  //Edit* GetEditor() { return m_edit; }
    Edit* GetEditor() {
      int page_idx = notebook->GetSelection();
      wxWindow* page = notebook->GetPage(size_t(page_idx));
      return tabs.getEdit(page);
    }
    void FileOpen (wxString fname);

    Edit* getActiveEditor ();
  
    void OnCloseTab (wxAuiNotebookEvent& event);
  
private:
    // edit object
    //Edit *m_edit;
    //wxAUINotebook object
    wxAuiNotebook* notebook;
  
    //Tabs vector
    tabsVector tabs;

    //Empty pages counter
    int pageCount;
  
    //! creates the application menu bar
    wxMenuBar *m_menuBar;
    void CreateMenu ();

    // print preview position and size
    wxRect DeterminePrintSize ();
  

    DECLARE_EVENT_TABLE();
};

#endif // not defined _stctest_h_
