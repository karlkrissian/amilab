//////////////////////////////////////////////////////////////////////////////
// File:        edit.h
// Purpose:     STC test module
// Maintainer:  Wyo
// Created:     2003-09-01
// RCS-ID:      $Id: edit.h 35523 2005-09-16 18:25:44Z ABX $
// Copyright:   (c) wxGuide
// Licence:     wxWindows licence
//////////////////////////////////////////////////////////////////////////////

#ifndef _EDIT_H_
#define _EDIT_H_

//----------------------------------------------------------------------------
// informations
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

//! wxWidgets headers

//! wxWidgets/contrib headers
#include "wx/stc/stc.h"  // styled text control

//! application headers
#include "prefs.h"       // preferences

//Event up propagation
#include "wxPropagateEvent.h"

//============================================================================
// declarations
//============================================================================

class EditPrint;
class EditProperties;


//----------------------------------------------------------------------------
//! Edit
class Edit: public wxStyledTextCtrl {
    friend class EditProperties;
    friend class EditPrint;

public:
    //! constructor
    Edit (wxWindow *parent, wxWindowID id = wxID_ANY,
          const wxPoint &pos = wxDefaultPosition,
          const wxSize &size = wxDefaultSize,
          long style = wxSUNKEN_BORDER|wxVSCROLL
         );

    //! destructor
    ~Edit ();

    // event handlers
    // common
    void OnSize( wxSizeEvent &event );
    // edit
    void OnEditRedo (wxCommandEvent &event);
    void OnEditUndo (wxCommandEvent &event);
    void OnEditClear (wxCommandEvent &event);
    void OnEditCut (wxCommandEvent &event);
    void OnEditCopy (wxCommandEvent &event);
    void OnEditPaste (wxCommandEvent &event);
    // find
    void OnFind (wxCommandEvent &event);
    void OnFindNext (wxCommandEvent &event);
    void OnReplace (wxCommandEvent &event);
    void OnReplaceNext (wxCommandEvent &event);
    void OnBraceMatch (wxCommandEvent &event);
    void OnGoto (wxCommandEvent &event);
    void OnEditIndentInc (wxCommandEvent &event);
    void OnEditIndentRed (wxCommandEvent &event);
    void OnEditSelectAll (wxCommandEvent &event);
    void OnEditSelectLine (wxCommandEvent &event);
    //! view
    void OnHilightLang (wxCommandEvent &event);
    void OnDisplayEOL (wxCommandEvent &event);
    void OnIndentGuide (wxCommandEvent &event);
    void OnLineNumber (wxCommandEvent &event);
    void OnLongLineOn (wxCommandEvent &event);
    void OnWhiteSpace (wxCommandEvent &event);
    void OnFoldToggle (wxCommandEvent &event);
    void OnSetOverType (wxCommandEvent &event);
    void OnSetReadOnly (wxCommandEvent &event);
    void OnWrapmodeOn (wxCommandEvent &event);
    void OnUseCharset (wxCommandEvent &event);
    //! extra
    void OnChangeCase (wxCommandEvent &event);
    void OnConvertEOL (wxCommandEvent &event);
    // stc
    void OnMarginClick (wxStyledTextEvent &event);
    void OnCharAdded  (wxStyledTextEvent &event);

    //! language/lexer
    wxString DeterminePrefs (const wxString &filename);
    bool InitializePrefs (const wxString &filename);
    bool UserSettings (const wxString &filename);
    LanguageInfo const* GetLanguageInfo () {return m_language;};

    //! load/save file
    bool LoadFile ();
    bool LoadFile (const wxString &filename);
    bool SaveFile ();
    bool SaveFile (const wxString &filename);
    bool Modified ();
    wxString GetFilename () {return m_filename;};
    void SetFilename (const wxString &filename) {m_filename = filename;};

    void ShowLineNumbers(bool sln=true);

private:
    // file
    wxString m_filename;

    // lanugage properties
    LanguageInfo const* m_language;

    // margin variables
    int m_LineNrID;
    int m_LineNrMargin;
    int m_FoldingID;
    int m_FoldingMargin;
    int m_DividerID;
  
    //Listbook
    //wxListbook* book;

    DECLARE_EVENT_TABLE()
};

//----------------------------------------------------------------------------
//! EditProperties
class EditProperties: public wxDialog {

public:

    //! constructor
    EditProperties (Edit *edit, long style = 0);

private:

};

#if wxUSE_PRINTING_ARCHITECTURE

//----------------------------------------------------------------------------
//! EditPrint
class EditPrint: public wxPrintout {

public:

    //! constructor
    EditPrint (Edit *edit, const wxChar *title = _T(""));

    //! event handlers
    bool OnPrintPage (int page);
    bool OnBeginDocument (int startPage, int endPage);

    //! print functions
    bool HasPage (int page);
    void GetPageInfo (int *minPage, int *maxPage, int *selPageFrom, int *selPageTo);

private:
    Edit *m_edit;
    int m_printed;
    wxRect m_pageRect;
    wxRect m_printRect;

    bool PrintScaling (wxDC *dc);
};

#endif // wxUSE_PRINTING_ARCHITECTURE

//----------------------------------------------------------------------------
/**
 *  Find and replace class. Allows find text (next and previous search supported), replace once and replace all matches.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class FindAndReplace : public wxFrame {

public:
  /**
   *  Create a FindAndReplace object.
   *  @param openEditor is a pointer to open editor.
   *  @return Show in the screen the find and replace window.
   */
  FindAndReplace (Edit* openEditor);
  //Destructor
  ~FindAndReplace ();
  
  /**
   *  Close the find and replace window.
   *  @param event
   */
  void OnDoneButtonClick (wxCommandEvent &event);
  
  /**
   *  Search the next match of find text and select it on the editor. When achieve the end of file, lets start from the beginning.
   *  If there aren't matches shows an advice.
   *  Requires a find text.
   *  @param event
   *  @return Nothing
   */
  void OnNextButtonClick (wxCommandEvent &event);
  
  /**
   *  Evaluates a key event. If F3 function key is pressed, calls to OnNextButtonClick. If F2 function key is pressed, calls to OnPrevButtonClick.
   *  @param event is the key event.
   *  @return Nothing
   */
  void OnFunKeyDown (wxKeyEvent &event);

  /**
   *  Search the previous match of find text and select it on the editor. When achieve the begin of file, lets start from the end.
   *  If there aren't matches shows an advice.
   *  Requires a find text.
   *  @param event
   *  @return Nothing
   */
  void OnPrevButtonClick (wxCommandEvent &event);
  
  /**
   *  Replace the selected text with replacement text. If text isn't selected, execute a find next. After replacement shows the next match of find text.
   *  Requires a find text. Replacement text could be empty.
   *  @param event
   *  @return Nothing
   */
  void OnReplaceButtonClick (wxCommandEvent &event);
  
  /**
   *  Replace all matches of find text. Previously ask to the user if he's sure to make this operation.
   *  Shows the total number of replacements on a dialog.
   *  Requires a find text. Replacement text could be empty.
   *  @param event
   *  @return Nothing
   */
  void OnReplaceAllButtonClick (wxCommandEvent &event);
  
private:
  /** Text to find. Initially set focus at this member */
  wxTextCtrl* findBox;
  /** Replacement text */
  wxTextCtrl* replaceBox;
  /** Whole word checkbox. Search exactly the find text like a whole word */
  wxCheckBox* wholeWord;
  /** Match case checkbox. The search is case sensitive */
  wxCheckBox* matchCase;
  /** Pointer to actual editor window */
  Edit* editor;
  
  DECLARE_EVENT_TABLE()
};
//----------------------------------------------------------------------------
/**
 *  Go to line class. Lets to the user go to an specific line.
 *  @author Karl Krissian (krissian@dis.ulpgc.es)
 *  @author Daniel Elías Santana Cedrés (daniel.santana104@estudiantes.ulpgc.es)
 */
class gotoLine : public wxFrame {
  
public:
  /**
   *  Create a gotoLine object.
   *  @param openEditor A pointer to the actual open editor.
   *  @return Show in screen the go to line window.
   */
  gotoLine (Edit* openEditor);
  
  //destructor
  ~gotoLine ();
  
  /**
   *  Go to specific line. If is a wrong line, show a message dialog with the correct number line range.
   *  @param event
   *  @return Set cursor in the editor line.
   */
  void onOKButtonClick (wxCommandEvent &event);
  
  /**
   *  Close go to line window.
   *  @param event
   *  @return Nothing
   */
  void onCancelButtonClick (wxCommandEvent &event);
  
  void OnNumTextEnter (wxCommandEvent &event);
private:
  wxTextCtrl* numberLine;
  Edit* editor;
  
  DECLARE_EVENT_TABLE()
};

#endif // _EDIT_H_
