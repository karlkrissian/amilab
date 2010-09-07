//////////////////////////////////////////////////////////////////////////////
// File:        contrib/samples/stc/edit.cpp
// Purpose:     STC test module
// Maintainer:  Wyo
// Created:     2003-09-01
// RCS-ID:      $Id: edit.cpp 39402 2006-05-28 23:32:12Z VZ $
// Copyright:   (c) wxGuide
// Licence:     wxWindows licence
//////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------
// informations
//----------------------------------------------------------------------------


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
#include "wx/file.h"     // raw file io support
#include "wx/filename.h" // filename support

//! application headers
#include "defsext.h"     // additional definitions

#include "wxEditor.h"        // edit module
#include "wxStcFrame.h"
#include <iostream>

//----------------------------------------------------------------------------
// resources
//----------------------------------------------------------------------------


//============================================================================
// declarations
//============================================================================


//============================================================================
// implementation
//============================================================================

//----------------------------------------------------------------------------
// wxEditor
//----------------------------------------------------------------------------

BEGIN_EVENT_TABLE (wxEditor, wxStyledTextCtrl)
    // common
    EVT_SIZE (                         wxEditor::OnSize)
    // edit
    EVT_MENU (wxID_CLEAR,              wxEditor::OnEditClear)
    EVT_MENU (wxID_CUT,                wxEditor::OnEditCut)
    EVT_MENU (wxID_COPY,               wxEditor::OnEditCopy)
    EVT_MENU (wxID_PASTE,              wxEditor::OnEditPaste)
    EVT_MENU (myID_INDENTINC,          wxEditor::OnEditIndentInc)
    EVT_MENU (myID_INDENTRED,          wxEditor::OnEditIndentRed)
    EVT_MENU (wxID_SELECTALL,          wxEditor::OnEditSelectAll)
    EVT_MENU (myID_SELECTLINE,         wxEditor::OnEditSelectLine)
    EVT_MENU (wxID_REDO,               wxEditor::OnEditRedo)
    EVT_MENU (wxID_UNDO,               wxEditor::OnEditUndo)
    // find
    EVT_MENU (wxID_FIND,               wxEditor::OnFind)
    EVT_MENU (myID_FINDNEXT,           wxEditor::OnFindNext)
    EVT_MENU (myID_REPLACE,            wxEditor::OnReplace)
    EVT_MENU (myID_REPLACENEXT,        wxEditor::OnReplaceNext)
    EVT_MENU (myID_BRACEMATCH,         wxEditor::OnBraceMatch)
    EVT_MENU (myID_GOTO,               wxEditor::OnGoto)
    // view
    EVT_MENU_RANGE (myID_HILIGHTFIRST, myID_HILIGHTLAST,
                                       wxEditor::OnHilightLang)
    EVT_MENU (myID_DISPLAYEOL,         wxEditor::OnDisplayEOL)
    EVT_MENU (myID_INDENTGUIDE,        wxEditor::OnIndentGuide)
    EVT_MENU (myID_LINENUMBER,         wxEditor::OnLineNumber)
    EVT_MENU (myID_LONGLINEON,         wxEditor::OnLongLineOn)
    EVT_MENU (myID_WHITESPACE,         wxEditor::OnWhiteSpace)
    EVT_MENU (myID_FOLDTOGGLE,         wxEditor::OnFoldToggle)
    EVT_MENU (myID_OVERTYPE,           wxEditor::OnSetOverType)
    EVT_MENU (myID_READONLY,           wxEditor::OnSetReadOnly)
    EVT_MENU (myID_WRAPMODEON,         wxEditor::OnWrapmodeOn)
    EVT_MENU (myID_CHARSETANSI,        wxEditor::OnUseCharset)
    EVT_MENU (myID_CHARSETMAC,         wxEditor::OnUseCharset)
    // extra
    EVT_MENU (myID_CHANGELOWER,        wxEditor::OnChangeCase)
    EVT_MENU (myID_CHANGEUPPER,        wxEditor::OnChangeCase)
    EVT_MENU (myID_CONVERTCR,          wxEditor::OnConvertEOL)
    EVT_MENU (myID_CONVERTCRLF,        wxEditor::OnConvertEOL)
    EVT_MENU (myID_CONVERTLF,          wxEditor::OnConvertEOL)
    // stc
    EVT_STC_MARGINCLICK (wxID_ANY,     wxEditor::OnMarginClick)
    EVT_STC_CHARADDED (wxID_ANY,       wxEditor::OnCharAdded)
END_EVENT_TABLE()

//----------------------------------------------------------------------------
//My find and replace buttons IDs
enum 
{
  ID_DONE = 1,
  ID_NEXT = 2,
  ID_PREV = 3,
  ID_REPL = 4,
  ID_REPL_ALL = 5,
  ID_LINE_TEXT = 6
};

//Find and replace event table
BEGIN_EVENT_TABLE(FindAndReplace, wxFrame)
  //Button events
  EVT_BUTTON(ID_DONE,     FindAndReplace::OnDoneButtonClick)
  EVT_BUTTON(ID_NEXT,     FindAndReplace::OnNextButtonClick)
  EVT_BUTTON(ID_PREV,     FindAndReplace::OnPrevButtonClick)
  EVT_BUTTON(ID_REPL,     FindAndReplace::OnReplaceButtonClick)
  EVT_BUTTON(ID_REPL_ALL, FindAndReplace::OnReplaceAllButtonClick)
  //Key events (control F3 and F2 function keys, enter and escape)
  EVT_CHAR(FindAndReplace::OnFunKeyDown)
END_EVENT_TABLE()

//gotoLine event table
BEGIN_EVENT_TABLE(gotoLine, wxFrame)
  //Button events
  EVT_BUTTON(wxID_OK, gotoLine::onOKButtonClick)
  EVT_BUTTON(wxID_CANCEL, gotoLine::onCancelButtonClick)
  //Enter key on text control
  EVT_TEXT_ENTER(ID_LINE_TEXT, gotoLine::OnNumTextEnter)
END_EVENT_TABLE()
//----------------------------------------------------------------------------


wxEditor::wxEditor (wxWindow *parent, wxWindowID id,
            const wxPoint &pos,
            const wxSize &size,
            long style)
    : wxStyledTextCtrl (parent, id, pos, size, style) {

    m_filename = wxEmptyString;

    m_LineNrID = 0;
    m_DividerID = 1;
    m_FoldingID = 2;

    // initialize language
    m_language = NULL;

    // default font for all styles
    SetViewEOL (g_CommonPrefs.displayEOLEnable);
    SetIndentationGuides (g_CommonPrefs.indentGuideEnable);
    SetEdgeMode (g_CommonPrefs.longLineOnEnable?
                 wxSTC_EDGE_LINE: wxSTC_EDGE_NONE);
    SetViewWhiteSpace (g_CommonPrefs.whiteSpaceEnable?
                       wxSTC_WS_VISIBLEALWAYS: wxSTC_WS_INVISIBLE);
    SetOvertype (g_CommonPrefs.overTypeInitial);
    SetReadOnly (g_CommonPrefs.readOnlyInitial);
    SetWrapMode (g_CommonPrefs.wrapModeInitial?
                 wxSTC_WRAP_WORD: wxSTC_WRAP_NONE);
    wxFont font (10, wxMODERN, wxNORMAL, wxNORMAL);
    StyleSetFont (wxSTC_STYLE_DEFAULT, font);
    StyleSetForeground (wxSTC_STYLE_DEFAULT, *wxBLACK);
    StyleSetBackground (wxSTC_STYLE_DEFAULT, *wxWHITE);
    StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (_T("DARK GREY")));
    StyleSetBackground (wxSTC_STYLE_LINENUMBER, *wxWHITE);
    StyleSetForeground(wxSTC_STYLE_INDENTGUIDE, wxColour (_T("DARK GREY")));
    InitializePrefs (DEFAULT_LANGUAGE);

    // set visibility
    SetVisiblePolicy (wxSTC_VISIBLE_STRICT|wxSTC_VISIBLE_SLOP, 1);
    SetXCaretPolicy (wxSTC_CARET_EVEN|wxSTC_VISIBLE_STRICT|wxSTC_CARET_SLOP, 1);
    SetYCaretPolicy (wxSTC_CARET_EVEN|wxSTC_VISIBLE_STRICT|wxSTC_CARET_SLOP, 1);

    // markers
    MarkerDefine (wxSTC_MARKNUM_FOLDER,        wxSTC_MARK_DOTDOTDOT, _T("BLACK"), _T("BLACK"));
    MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_ARROWDOWN, _T("BLACK"), _T("BLACK"));
    MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_EMPTY,     _T("BLACK"), _T("BLACK"));
    MarkerDefine (wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_DOTDOTDOT, _T("BLACK"), _T("WHITE"));
    MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN, _T("BLACK"), _T("WHITE"));
    MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY,     _T("BLACK"), _T("BLACK"));
    MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_EMPTY,     _T("BLACK"), _T("BLACK"));

    // miscelaneous
    m_LineNrMargin = TextWidth (wxSTC_STYLE_LINENUMBER, _T("_999999"));
    m_FoldingMargin = 16;
    CmdKeyClear (wxSTC_KEY_TAB, 0); // this is done by the menu accelerator key
    SetLayoutCache (wxSTC_CACHE_PAGE);
      
    //*****21/04/2010
    //book = new wxListbook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_TOP, wxT(""));

}

wxEditor::~wxEditor () {}

//----------------------------------------------------------------------------
// common event handlers
void wxEditor::OnSize( wxSizeEvent& event ) {
    int x = GetClientSize().x +
            (g_CommonPrefs.lineNumberEnable? m_LineNrMargin: 0) +
            (g_CommonPrefs.foldEnable? m_FoldingMargin: 0);
    if (x > 0) SetScrollWidth (x);
    event.Skip();
}

// edit event handlers
void wxEditor::OnEditRedo (wxCommandEvent &WXUNUSED(event)) {
    if (!CanRedo()) return;
    Redo ();
}

void wxEditor::OnEditUndo (wxCommandEvent &WXUNUSED(event)) {
    if (!CanUndo()) return;
    Undo ();
}

void wxEditor::OnEditClear (wxCommandEvent &WXUNUSED(event)) {
    if (GetReadOnly()) return;
    Clear ();
}

void wxEditor::OnEditCut (wxCommandEvent &WXUNUSED(event)) {
    if (GetReadOnly() || (GetSelectionEnd()-GetSelectionStart() <= 0)) return;
    Cut ();
}

void wxEditor::OnEditCopy (wxCommandEvent &WXUNUSED(event)) {
    if (GetSelectionEnd()-GetSelectionStart() <= 0) return;
    Copy ();
}

void wxEditor::OnEditPaste (wxCommandEvent &WXUNUSED(event)) {
    if (!CanPaste()) return;
    Paste ();
}

//----------------------------------------------------------------------------
//==>FIND AND REPLACE<==

//Boolean internal function. Returns true if the text is found
bool isFound (wxEditor* editor, wxString* findText, bool wholeWord, bool matchCase) {
  int result = 0;
  int minPos = 0;
  int maxPos = editor->GetLength();
  //Must make the appropiate search
  if (wholeWord) {
    //The search is case sensitive
    if (matchCase) {
      result = editor->FindText(minPos, maxPos, *findText, wxSTC_FIND_WHOLEWORD | wxSTC_FIND_MATCHCASE);
    }
    else {
      result = editor->FindText(minPos, maxPos, *findText, wxSTC_FIND_WHOLEWORD);
    }
  }
  //Match case can be checked
  else {
    if (matchCase) {
      result = editor->FindText(minPos, maxPos, *findText, wxSTC_FIND_MATCHCASE);
    }
    else { //Else we only find the text without flags
      result = editor->FindText(minPos, maxPos, *findText, NULL);
    }
  }
  if (result != -1) {
    return true;
  }
  else {
    return false;
  }
}

//Void function for not found message
void notFound(wxString* text, bool wholeWord, bool matchCase) {
  wxString message = wxT("Text \"");
  message.append(*text);
  message.append(wxT("\" not found."));
  if (wholeWord) {
    message.append(wxT("\n You have whole word active. Maybe isn't a whole word."));
  }
  if (matchCase) {
    message.append(wxT("\n You have match case active. Check find text."));
  }
  wxMessageDialog* advice = new wxMessageDialog(NULL, message, wxT("Not found"), wxOK |  wxCENTER | wxICON_ERROR);
  advice->ShowModal();
}
// ------------------------------------------------------------------------------------
//-->Constructor<--
FindAndReplace::FindAndReplace (wxEditor* openEditor) : wxFrame(openEditor,wxID_ANY, wxT("Find & Replace"), wxDefaultPosition, wxSize(509,207), wxDEFAULT_FRAME_STYLE | wxFRAME_FLOAT_ON_PARENT, wxT("frame"))
{
  
  //Find and replace frame size
  this->SetMinSize(wxSize(509,207));
  this->CenterOnScreen(wxBOTH);
  
  wxPanel* panel   = new wxPanel(this, wxID_ANY);
  
  wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
  wxGridSizer* gs  = new wxGridSizer(2,4,8,8);
  
  wxButton* done             = new wxButton(panel, ID_DONE, wxT("Done"));
  wxButton* next             = new wxButton(panel, ID_NEXT, wxT("Next ->"));
  wxButton* prev             = new wxButton(panel, ID_PREV, wxT("<- Prev"));
  wxButton* replace          = new wxButton(panel, ID_REPL, wxT("Replace"));
  wxButton* replaceAll       = new wxButton(panel, ID_REPL_ALL, wxT("Replace All"));
  wxStaticText* findLabel    = new wxStaticText(panel, -1, wxT("Text to Find: "));

  wxStaticText* replaceLabel = new wxStaticText(panel, wxID_ANY, wxT("Replacement Text: "));
  findBox                    = new wxTextCtrl(panel, wxID_ANY, 
                                              //wxT(""),
                                              openEditor->GetSelectedText(),
                                              wxPoint(-1, -1), wxSize(-1, -1), wxTE_LEFT | wxTE_PROCESS_ENTER);
  replaceBox                 = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_LEFT | wxTE_PROCESS_ENTER);

  wholeWord                  = new wxCheckBox(panel, wxID_ANY, wxT("Whole word"));
  matchCase                  = new wxCheckBox(panel, wxID_ANY, wxT("Match case"));

  wxBoxSizer* line = new wxBoxSizer(wxHORIZONTAL);
  line->Add(findLabel, 0, wxRIGHT | wxTOP, 4);
  line->Add(findBox, 1, wxLEFT | wxTOP, 4);
  sizer->Add(line, 0, wxEXPAND | wxALL, 4);
  
  line = new wxBoxSizer(wxHORIZONTAL);
  line->Add(replaceLabel, 0, wxRIGHT | wxTOP, 4);
  line->Add(replaceBox, 1, wxLEFT | wxTOP, 4);
  sizer->Add(line, 1, wxEXPAND | wxALL, 4);
  
  //Fill the gridSizer
  gs->Add(prev, 0, wxEXPAND);
  gs->Add(next, 0, wxEXPAND);
  gs->Add(replace, 0, wxEXPAND);
  gs->Add(replaceAll, 0, wxEXPAND);
  
  gs->Add(wholeWord, 0, wxEXPAND);
  gs->Add(matchCase, 0, wxEXPAND);
  gs->Add(0, 0, 0, wxEXPAND);
  gs->Add(done, 0, wxEXPAND);
  
  sizer->Add(gs, 2, wxALL | wxEXPAND, 4);
  panel->SetSizer(sizer);
  
  //Initialize reference to editor
  editor = openEditor;
  
  //Set focus on find box, where text to find will be written
  findBox->SetFocus();

  //Propagate events
  CEventPropagator::registerFor(panel);
  panel->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(FindAndReplace::OnFunKeyDown), NULL, this);
  
  this->Show(true);
}

//-->Destructor<--
FindAndReplace::~FindAndReplace () {}

//Event handlers
//-->Done button click<--
void FindAndReplace::OnDoneButtonClick (wxCommandEvent &event) {
  this->Close(true);
  editor->SetFocus();
  editor->GotoLine(editor->LineFromPosition(editor->GetCurrentPos()));
  //editor->SetCaretLineVisible(true);
}

//-->Next button click<--
void FindAndReplace::OnNextButtonClick (wxCommandEvent &event) {
  int result;
  editor->SetCurrentPos(editor->GetAnchor()); //Realocate cursor
  editor->SearchAnchor();
  wxString findText = findBox->GetValue();
  //If findBox is empty show a message dialog
  if (findBox->IsEmpty()) {
    wxMessageDialog* warning = new wxMessageDialog(NULL, wxT("On Next operation: You must insert a find text."), wxT("WARNING"), wxOK | wxCENTER | wxICON_EXCLAMATION);
    warning->Raise();
    warning->ShowModal();
  }
  else {
    //Is the word in the document?
    if (isFound(editor, &findText, wholeWord->IsChecked(), matchCase->IsChecked()) == false) {
      notFound(&findText, wholeWord->IsChecked(), matchCase->IsChecked());
      return;
    }
    //Search the whole word in the text
    if (wholeWord->IsChecked()) {
      //The search is case sensitive
      if (matchCase->IsChecked()) {
        result = editor->SearchNext(wxSTC_FIND_WHOLEWORD | wxSTC_FIND_MATCHCASE, findText);
      }
      else {
        result = editor->SearchNext(wxSTC_FIND_WHOLEWORD, findText);
      }
    }
    //Match case can be checked
    else {
      if (matchCase->IsChecked()) {
        result = editor->SearchNext(wxSTC_FIND_MATCHCASE, findText);
      }
      else { //Else we only search the text without flags
        result = editor->SearchNext(NULL, findText);
      }
    }
    int line = editor->LineFromPosition(editor->GetCurrentPos());
    //If the line is not visible, show it
    editor->EnsureVisibleEnforcePolicy(line);
    //End of the document
    if (result == -1) {
      //Do you want go on?
      wxMessageDialog* end = new wxMessageDialog(NULL, wxT("Do you want to go to the beginning?"), wxT("End of document"), wxYES_NO | wxCENTER | wxICON_QUESTION);
      int answer = end->ShowModal();
      if(answer == wxID_NO) {
        return;
      }
      else { //Set cursor to the beginning
        editor->SetCurrentPos(0);
        editor->SetAnchor(0);
        editor->SearchAnchor();
        //And search the next match
        if (wholeWord->IsChecked()) {
          if (matchCase->IsChecked()) {
            result = editor->SearchNext(wxSTC_FIND_WHOLEWORD | wxSTC_FIND_MATCHCASE, findText);
          }
          else {
            result = editor->SearchNext(wxSTC_FIND_WHOLEWORD, findText);
          }
        }
        else {
          if (matchCase->IsChecked()) {
            result = editor->SearchNext(wxSTC_FIND_MATCHCASE, findText);
          }
          else {
            result = editor->SearchNext(NULL, findText);
          }
        }
        int line = editor->LineFromPosition(editor->GetCurrentPos());
        editor->EnsureVisibleEnforcePolicy(line);
      }
    }
  }
}

//-->Prev button click<--
void FindAndReplace::OnPrevButtonClick (wxCommandEvent &event) {
  int result;
  editor->SearchAnchor();
  wxString findText = findBox->GetValue();
  //If findBox is empty show a message dialog
  if (findBox->IsEmpty()) {
    wxMessageDialog* warning = new wxMessageDialog(NULL, wxT("On Prev operation: You must insert a find text."), wxT("WARNING"), wxOK | wxCENTER | wxICON_EXCLAMATION);
    warning->Raise();
    warning->ShowModal();
  }
  else {
    //Is the word in the document?
    if (isFound(editor, &findText, wholeWord->IsChecked(), matchCase->IsChecked()) == false) {
      notFound(&findText, wholeWord->IsChecked(), matchCase->IsChecked());
      return;
    }
    //Search the whole word in the text
    if (wholeWord->IsChecked()) {
      //The search is case sensitive
      if (matchCase->IsChecked()) {
        result = editor->SearchPrev(wxSTC_FIND_WHOLEWORD | wxSTC_FIND_MATCHCASE, findText);
      }
      else {
        result = editor->SearchPrev(wxSTC_FIND_WHOLEWORD, findText);
      }
    }
    //Match case can be checked
    else {
      if (matchCase->IsChecked()) {
        result = editor->SearchPrev(wxSTC_FIND_MATCHCASE, findText);
      }
      else { //Else we only search the text without flags
        result = editor->SearchPrev(NULL, findText);
      }
    }
    int line = editor->LineFromPosition(editor->GetCurrentPos());
    //If the line is not visible, show it
    editor->EnsureVisibleEnforcePolicy(line);
    //End of the document
    if (result == -1) {
      //Do you want go on?
      wxMessageDialog* end = new wxMessageDialog(NULL, wxT("Do you want to go to the end?"), wxT("Begin of document"), wxYES_NO | wxCENTER | wxICON_QUESTION);
      int answer = end->ShowModal();
      if(answer == wxID_NO) {
        return;
      }
      else { //Set cursor to the beginning
        editor->SetCurrentPos(editor->GetLength());
        editor->SetAnchor(editor->GetLength());
        editor->SearchAnchor();
        //And search the prev match
        if (wholeWord->IsChecked()) {
          if (matchCase->IsChecked()) {
            result = editor->SearchPrev(wxSTC_FIND_WHOLEWORD | wxSTC_FIND_MATCHCASE, findText);
          }
          else {
            result = editor->SearchPrev(wxSTC_FIND_WHOLEWORD, findText);
          }
        }
        else {
          if (matchCase->IsChecked()) {
            result = editor->SearchPrev(wxSTC_FIND_MATCHCASE, findText);
          }
          else {
            result = editor->SearchPrev(NULL, findText);
          }
        }
        int line = editor->LineFromPosition(editor->GetCurrentPos());
        editor->EnsureVisibleEnforcePolicy(line);
      }
    }
  }
}
#include <iostream>
using namespace std;
//-->On function key down<--
void FindAndReplace::OnFunKeyDown (wxKeyEvent &event) {
  //std::cout << __func__ << std::endl;
  wxCommandEvent e; //We must pass to methods a wxCommandEvent variable
  long keycode = event.GetKeyCode();
  //Calls based on keycode value
  switch (keycode) {
    case WXK_F3:
      OnNextButtonClick(e);
      break;
    case WXK_RETURN:
      OnNextButtonClick(e);
      break;
    case WXK_F2:
      OnPrevButtonClick(e);
      break;
    case WXK_ESCAPE:
      OnDoneButtonClick(e);
      break;
    default:
      event.Skip();
      break;
  }
  event.Skip();
}

//-->Replace button click<--
void FindAndReplace::OnReplaceButtonClick (wxCommandEvent &event) {
  wxString findText    = findBox->GetValue();
  wxString replaceText = replaceBox->GetValue();
  //If findBox is empty show a message dialog
  if (findBox->IsEmpty()) {
    wxMessageDialog* warning = new wxMessageDialog(NULL, wxT("On Replace operation: You must insert a find text."), wxT("WARNING"), wxOK | wxCENTER | wxICON_EXCLAMATION);
    warning->Raise();
    warning->ShowModal();
  }
  else {
    //Is the word in the document?
    if (isFound(editor, &findText, wholeWord->IsChecked(), matchCase->IsChecked()) == false) {
      notFound(&findText, wholeWord->IsChecked(), matchCase->IsChecked());
      return;
    }
    wxString selection = editor->GetSelectedText();
    if (selection.Length() == 0) //There isn't selected text, we must find it before
      OnNextButtonClick(event);
    
    //Replace selected text
    editor->ReplaceSelection(replaceText);
    
    //And find the next match
    OnNextButtonClick(event);
  }
}

//-->Replace all button click<--
void FindAndReplace::OnReplaceAllButtonClick( wxCommandEvent &event) {
  wxString findText    = findBox->GetValue();
  wxString replaceText = replaceBox->GetValue();
  //If findBox is empty show a message dialog
  if (findBox->IsEmpty()) {
    wxMessageDialog* warning = new wxMessageDialog(NULL, wxT("On Replace All operation: You must insert a find text."), wxT("WARNING"), wxOK | wxCENTER | wxICON_EXCLAMATION);
    warning->Raise();
    warning->ShowModal();
  }
  else {
    //Is the word in the document?
    if (isFound(editor, &findText, wholeWord->IsChecked(), matchCase->IsChecked()) == false) {
      notFound(&findText, wholeWord->IsChecked(), matchCase->IsChecked());
      return;
    }
    //Really do you want replace all????
    wxMessageDialog* ask = new wxMessageDialog(NULL, wxT("Do you want to replace all matches?"), wxT("Are you sure?"), wxYES_NO | wxCENTER | wxICON_QUESTION);
    int answer = ask->ShowModal();
    if (answer == wxID_YES) {
      int replacements = 0;
      int result       = 0;
      editor->SetCurrentPos(0);
      editor->SetAnchor(0);
      editor->SearchAnchor();
      while (result != -1) {
        //Must make the appropiate search
        if (wholeWord->IsChecked()) {
          //The search is case sensitive
          if (matchCase->IsChecked()) {
            result = editor->SearchNext(wxSTC_FIND_WHOLEWORD | wxSTC_FIND_MATCHCASE, findText);
          }
          else {
            result = editor->SearchNext(wxSTC_FIND_WHOLEWORD, findText);
          }
        }
        //Match case can be checked
        else {
          if (matchCase->IsChecked()) {
            result = editor->SearchNext(wxSTC_FIND_MATCHCASE, findText);
          }
          else { //Else we only search the text without flags
            result = editor->SearchNext(NULL, findText);
          }
        }
        if (result != -1) {
          editor->ReplaceSelection(replaceText);
          replacements++;
        }
      }
      //Show total number of replacements
      wxString rep = wxString::Format(_T("%d"), replacements);
      wxString message = wxT("Total number of replacements: ");
      message.append(rep);
      wxMessageDialog* totalReplacements = new wxMessageDialog(NULL, message, wxT("Replacements"), wxOK | wxCENTER | wxICON_INFORMATION);
      totalReplacements->ShowModal();
    }
    else {
      return;
    }
  }
}
//----------------------------------------------------------------------------

void wxEditor::OnFind (wxCommandEvent &WXUNUSED(event)) {
  //Pass to the constructor a reference to editor ('this' pointer)
  FindAndReplace* findWindow = new FindAndReplace(this);
}

void wxEditor::OnFindNext (wxCommandEvent &WXUNUSED(event)) {
}

void wxEditor::OnReplace (wxCommandEvent &WXUNUSED(event)) {
  //Pass to the constructor a reference to editor ('this' pointer)
  FindAndReplace* findWindow = new FindAndReplace(this);
}

void wxEditor::OnReplaceNext (wxCommandEvent &WXUNUSED(event)) {
}

void wxEditor::OnBraceMatch (wxCommandEvent &WXUNUSED(event)) {
    int min = GetCurrentPos ();
    int max = BraceMatch (min);
    if (max > (min+1)) {
        BraceHighlight (min+1, max);
        SetSelection (min+1, max);
    }else{
        BraceBadLight (min);
    }
}

//----------------------------------------------------------------------------
//==>gotoLine class methods<==
//Constructor
gotoLine::gotoLine (wxEditor* openEditor) : wxFrame(openEditor, wxID_ANY, wxT("Go to Line"), wxDefaultPosition, wxSize(245,151), wxDEFAULT_FRAME_STYLE | wxFRAME_FLOAT_ON_PARENT, wxT("gotoLineFrame")) {
  //GUI members
  wxPanel* panel      = new wxPanel(this, wxID_ANY);
  wxGridSizer* grid   = new wxGridSizer(2,2,4,4);
  wxStaticText* label = new wxStaticText(panel, wxID_ANY, wxT("Line number: "));
  numberLine          = new wxTextCtrl(panel, ID_LINE_TEXT, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_LEFT | wxTE_PROCESS_ENTER);
  wxButton* OK        = new wxButton(panel, wxID_OK, wxT("OK"));
  wxButton* Cancel    = new wxButton(panel, wxID_CANCEL, wxT("Cancel"));
  
  //Fill the GridSizer
  grid->Add(label, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
  grid->Add(numberLine, 0, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
  grid->Add(OK, 0, wxALIGN_CENTER | wxALL);
  grid->Add(Cancel, 0, wxALIGN_CENTER | wxALL);
  //Set focus on the text control
  numberLine->SetFocus();
  panel->SetSizer(grid);
  //Pointer to actual editor
  editor = openEditor;
  //Block frame size
  this->SetMinSize(wxSize(245,151));
  this->SetMaxSize(wxSize(245,151));
  this->CenterOnScreen(wxBOTH);
  this->Show(true);
}
//destructor
gotoLine::~gotoLine () {}

//-->onOKButtonClick<--
void gotoLine::onOKButtonClick (wxCommandEvent &event) {
  //Get the count of file lines and the number inserted by the user
  int maxlines = editor->GetLineCount();
  int num = wxAtoi(numberLine->GetValue());
  //Is a valid line??
  if (num > maxlines || num < 1) {
    //Show a message error, whith number line range
    wxString message = wxT("Wrong line number: You must insert a line number between 1 and ");
    message.append(wxString() << maxlines);
    wxMessageDialog* error = new wxMessageDialog(NULL, message, wxT("Error line number"), wxOK |  wxCENTER | wxICON_ERROR);
    error->ShowModal();
    return;
  }
  else {
    editor->GotoLine(num-1);
  }

}

//-->onCancelButtonClick<--
void gotoLine::onCancelButtonClick (wxCommandEvent &event) {
  //Close the frame
  this->Close(true);
}

void gotoLine::OnNumTextEnter (wxCommandEvent &event) {
  onOKButtonClick(event);
}
//----------------------------------------------------------------------------


void wxEditor::OnGoto (wxCommandEvent &WXUNUSED(event)) {
  gotoLine* gt = new gotoLine(this);
}

void wxEditor::OnEditIndentInc (wxCommandEvent &WXUNUSED(event)) {
    CmdKeyExecute (wxSTC_CMD_TAB);
}

void wxEditor::OnEditIndentRed (wxCommandEvent &WXUNUSED(event)) {
    CmdKeyExecute (wxSTC_CMD_DELETEBACK);
}

void wxEditor::OnEditSelectAll (wxCommandEvent &WXUNUSED(event)) {
    SetSelection (0, GetTextLength ());
}

void wxEditor::OnEditSelectLine (wxCommandEvent &WXUNUSED(event)) {
    int lineStart = PositionFromLine (GetCurrentLine());
    int lineEnd = PositionFromLine (GetCurrentLine() + 1);
    SetSelection (lineStart, lineEnd);
}

void wxEditor::OnHilightLang (wxCommandEvent &event) {
    InitializePrefs (g_LanguagePrefs [event.GetId() - myID_HILIGHTFIRST].name);
}

void wxEditor::OnDisplayEOL (wxCommandEvent &WXUNUSED(event)) {
    SetViewEOL (!GetViewEOL());
}

void wxEditor::OnIndentGuide (wxCommandEvent &WXUNUSED(event)) {
    SetIndentationGuides (!GetIndentationGuides());
}

void wxEditor::OnLineNumber (wxCommandEvent &WXUNUSED(event)) {
    SetMarginWidth (m_LineNrID,
                    GetMarginWidth (m_LineNrID) == 0? m_LineNrMargin: 0);
}

void wxEditor::OnLongLineOn (wxCommandEvent &WXUNUSED(event)) {
    SetEdgeMode (GetEdgeMode() == 0? wxSTC_EDGE_LINE: wxSTC_EDGE_NONE);
}

void wxEditor::OnWhiteSpace (wxCommandEvent &WXUNUSED(event)) {
    SetViewWhiteSpace (GetViewWhiteSpace() == 0?
                       wxSTC_WS_VISIBLEALWAYS: wxSTC_WS_INVISIBLE);
}

void wxEditor::OnFoldToggle (wxCommandEvent &WXUNUSED(event)) {
    ToggleFold (GetFoldParent(GetCurrentLine()));
}

void wxEditor::OnSetOverType (wxCommandEvent &WXUNUSED(event)) {
    SetOvertype (!GetOvertype());
}

void wxEditor::OnSetReadOnly (wxCommandEvent &WXUNUSED(event)) {
    SetReadOnly (!GetReadOnly());
}

void wxEditor::OnWrapmodeOn (wxCommandEvent &WXUNUSED(event)) {
    SetWrapMode (GetWrapMode() == 0? wxSTC_WRAP_WORD: wxSTC_WRAP_NONE);
}

void wxEditor::OnUseCharset (wxCommandEvent &event) {
    int Nr;
    int charset = GetCodePage();
    switch (event.GetId()) {
        case myID_CHARSETANSI: {charset = wxSTC_CHARSET_ANSI; break;}
        case myID_CHARSETMAC: {charset = wxSTC_CHARSET_ANSI; break;}
    }
    for (Nr = 0; Nr < wxSTC_STYLE_LASTPREDEFINED; Nr++) {
        StyleSetCharacterSet (Nr, charset);
    }
    SetCodePage (charset);
}

void wxEditor::OnChangeCase (wxCommandEvent &event) {
    switch (event.GetId()) {
        case myID_CHANGELOWER: {
            CmdKeyExecute (wxSTC_CMD_LOWERCASE);
            break;
        }
        case myID_CHANGEUPPER: {
            CmdKeyExecute (wxSTC_CMD_UPPERCASE);
            break;
        }
    }
}

void wxEditor::OnConvertEOL (wxCommandEvent &event) {
    int eolMode = GetEOLMode();
    switch (event.GetId()) {
        case myID_CONVERTCR: { eolMode = wxSTC_EOL_CR; break;}
        case myID_CONVERTCRLF: { eolMode = wxSTC_EOL_CRLF; break;}
        case myID_CONVERTLF: { eolMode = wxSTC_EOL_LF; break;}
    }
    ConvertEOLs (eolMode);
    SetEOLMode (eolMode);
}

//! misc
void wxEditor::OnMarginClick (wxStyledTextEvent &event) {
    if (event.GetMargin() == 2) {
        int lineClick = LineFromPosition (event.GetPosition());
        int levelClick = GetFoldLevel (lineClick);
        if ((levelClick & wxSTC_FOLDLEVELHEADERFLAG) > 0) {
            ToggleFold (lineClick);
        }
    }
}

void wxEditor::OnCharAdded (wxStyledTextEvent &event) {
    char chr = (char)event.GetKey();
    int currentLine = GetCurrentLine();
    // Change this if support for mac files with \r is needed
    if (chr == '\n') {
        int lineInd = 0;
        if (currentLine > 0) {
            lineInd = GetLineIndentation(currentLine - 1);
        }
        if (lineInd == 0) return;
        SetLineIndentation (currentLine, lineInd);
        GotoPos(PositionFromLine (currentLine) + lineInd);
    }
}


void wxEditor::ShowLineNumbers(bool sln)
{
  if (sln) {
    SetMarginWidth (m_LineNrID, m_LineNrMargin);
  } else {
    SetMarginWidth (m_LineNrID,0);
  }
}

//----------------------------------------------------------------------------
// private functions
wxString wxEditor::DeterminePrefs (const wxString &filename) {

    LanguageInfo const* curInfo;

    // determine language from filepatterns
    int languageNr;
    for (languageNr = 0; languageNr < g_LanguagePrefsSize; languageNr++) {
        curInfo = &g_LanguagePrefs [languageNr];
        wxString filepattern = curInfo->filepattern;
        filepattern.Lower();
        while (!filepattern.empty()) {
            wxString cur = filepattern.BeforeFirst (';');
            if ((cur == filename) ||
                (cur == (filename.BeforeLast ('.') + _T(".*"))) ||
                (cur == (_T("*.") + filename.AfterLast ('.')))) {
                return curInfo->name;
            }
            filepattern = filepattern.AfterFirst (';');
        }
    }
    return wxEmptyString;

}

bool wxEditor::InitializePrefs (const wxString &name) {

    // initialize styles
    StyleClearAll();
    LanguageInfo const* curInfo = NULL;

    // determine language
    bool found = false;
    int languageNr;
    for (languageNr = 0; languageNr < g_LanguagePrefsSize; languageNr++) {
        curInfo = &g_LanguagePrefs [languageNr];
        if (curInfo->name == name) {
            found = true;
            break;
        }
    }
    if (!found) return false;

    // set lexer and language
    SetLexer (curInfo->lexer);
    m_language = curInfo;

    // set margin for line numbers
    SetMarginType (m_LineNrID, wxSTC_MARGIN_NUMBER);
    StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (_T("DARK GREY")));
    StyleSetBackground (wxSTC_STYLE_LINENUMBER, *wxWHITE);
    SetMarginWidth (m_LineNrID, 0); // start out not visible

    // default fonts for all styles!
    int Nr;
    for (Nr = 0; Nr < wxSTC_STYLE_LASTPREDEFINED; Nr++) {
        wxFont font (10, wxMODERN, wxNORMAL, wxNORMAL);
        StyleSetFont (Nr, font);
    }

    // set common styles
    StyleSetForeground (wxSTC_STYLE_DEFAULT, wxColour (_T("DARK GREY")));
    StyleSetForeground (wxSTC_STYLE_INDENTGUIDE, wxColour (_T("DARK GREY")));

    // initialize settings
    if (g_CommonPrefs.syntaxEnable) {
        int keywordnr = 0;
        for (Nr = 0; Nr < STYLE_TYPES_COUNT; Nr++) {
            if (curInfo->styles[Nr].type == -1) continue;
            const StyleInfo &curType = g_StylePrefs [curInfo->styles[Nr].type];
            wxFont font (curType.fontsize, wxMODERN, wxNORMAL, wxNORMAL, false,
                         curType.fontname);
            StyleSetFont (Nr, font);
            if (curType.foreground) {
                StyleSetForeground (Nr, wxColour (curType.foreground));
            }
            if (curType.background) {
                StyleSetBackground (Nr, wxColour (curType.background));
            }
            StyleSetBold (Nr, (curType.fontstyle & mySTC_STYLE_BOLD) > 0);
            StyleSetItalic (Nr, (curType.fontstyle & mySTC_STYLE_ITALIC) > 0);
            StyleSetUnderline (Nr, (curType.fontstyle & mySTC_STYLE_UNDERL) > 0);
            StyleSetVisible (Nr, (curType.fontstyle & mySTC_STYLE_HIDDEN) == 0);
            StyleSetCase (Nr, curType.lettercase);
            const wxChar *pwords = curInfo->styles[Nr].words;
            if (pwords) {
                SetKeyWords (keywordnr, pwords);
                keywordnr += 1;
            }
        }
    }

    // set margin as unused
    SetMarginType (m_DividerID, wxSTC_MARGIN_SYMBOL);
    SetMarginWidth (m_DividerID, 0);
    SetMarginSensitive (m_DividerID, false);

    // folding
    SetMarginType (m_FoldingID, wxSTC_MARGIN_SYMBOL);
    SetMarginMask (m_FoldingID, wxSTC_MASK_FOLDERS);
    StyleSetBackground (m_FoldingID, *wxWHITE);
    SetMarginWidth (m_FoldingID, 0);
    SetMarginSensitive (m_FoldingID, false);
    if (g_CommonPrefs.foldEnable) {
        SetMarginWidth (m_FoldingID, curInfo->folds != 0? m_FoldingMargin: 0);
        SetMarginSensitive (m_FoldingID, curInfo->folds != 0);
        SetProperty (_T("fold"), curInfo->folds != 0? _T("1"): _T("0"));
        SetProperty (_T("fold.comment"),
                     (curInfo->folds & mySTC_FOLD_COMMENT) > 0? _T("1"): _T("0"));
        SetProperty (_T("fold.compact"),
                     (curInfo->folds & mySTC_FOLD_COMPACT) > 0? _T("1"): _T("0"));
        SetProperty (_T("fold.preprocessor"),
                     (curInfo->folds & mySTC_FOLD_PREPROC) > 0? _T("1"): _T("0"));
        SetProperty (_T("fold.html"),
                     (curInfo->folds & mySTC_FOLD_HTML) > 0? _T("1"): _T("0"));
        SetProperty (_T("fold.html.preprocessor"),
                     (curInfo->folds & mySTC_FOLD_HTMLPREP) > 0? _T("1"): _T("0"));
        SetProperty (_T("fold.comment.python"),
                     (curInfo->folds & mySTC_FOLD_COMMENTPY) > 0? _T("1"): _T("0"));
        SetProperty (_T("fold.quotes.python"),
                     (curInfo->folds & mySTC_FOLD_QUOTESPY) > 0? _T("1"): _T("0"));
    }
    SetFoldFlags (wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED |
                  wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);

    // set spaces and indention
    SetTabWidth (4);
    SetUseTabs (false);
    SetTabIndents (true);
    SetBackSpaceUnIndents (true);
    SetIndent (g_CommonPrefs.indentEnable? 4: 0);

    // others
    SetViewEOL (g_CommonPrefs.displayEOLEnable);
    SetIndentationGuides (g_CommonPrefs.indentGuideEnable);
    SetEdgeColumn (80);
    SetEdgeMode (g_CommonPrefs.longLineOnEnable? wxSTC_EDGE_LINE: wxSTC_EDGE_NONE);
    SetViewWhiteSpace (g_CommonPrefs.whiteSpaceEnable?
                       wxSTC_WS_VISIBLEALWAYS: wxSTC_WS_INVISIBLE);
    SetOvertype (g_CommonPrefs.overTypeInitial);
    SetReadOnly (g_CommonPrefs.readOnlyInitial);
    SetWrapMode (g_CommonPrefs.wrapModeInitial?
                 wxSTC_WRAP_WORD: wxSTC_WRAP_NONE);

    return true;
}

bool wxEditor::LoadFile ()
{
#if wxUSE_FILEDLG
    // get filname
    if (!m_filename) {
        wxFileDialog dlg (this, _T("Open file"), wxEmptyString, wxEmptyString,
                          _T("Any file (*)|*"), wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR);
        if (dlg.ShowModal() != wxID_OK) return false;
        m_filename = dlg.GetPath();
    }

    // load file
    return LoadFile (m_filename);
#else
    return false;
#endif // wxUSE_FILEDLG
}

bool wxEditor::LoadFile (const wxString &filename) {

    // load file in edit and clear undo
    if (!filename.empty()) m_filename = filename;
//     wxFile file (m_filename);
//     if (!file.IsOpened()) return false;
    ClearAll ();
//     long lng = file.Length ();
//     if (lng > 0) {
//         wxString buf;
//         wxChar *buff = buf.GetWriteBuf (lng);
//         file.Read (buff, lng);
//         buf.UngetWriteBuf ();
//         InsertText (0, buf);
//     }
//     file.Close();

    wxStyledTextCtrl::LoadFile(m_filename);

    EmptyUndoBuffer();

    // determine lexer language
    wxFileName fname (m_filename);
    InitializePrefs (DeterminePrefs (fname.GetFullName()));

    return true;
}

bool wxEditor::SaveFile ()
{
#if wxUSE_FILEDLG
    // return if no change
    if (!Modified()) return true;

    // get filname
    if (!m_filename) {
        wxFileDialog dlg (this, _T("Save file"), wxEmptyString, wxEmptyString, _T("Any file (*)|*"),
                          wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
        if (dlg.ShowModal() != wxID_OK) return false;
        m_filename = dlg.GetPath();
    }

    // save file
    return wxStyledTextCtrl::SaveFile(m_filename);
#else
    return false;
#endif // wxUSE_FILEDLG
}

bool wxEditor::SaveFile (const wxString &filename) {

    // return if no change
    //if (!Modified()) return true;
    //if is the same file
    if (m_filename == filename) {
      SaveFile();
    }

//     // save edit in file and clear undo
//     if (!filename.empty()) m_filename = filename;
//     wxFile file (m_filename, wxFile::write);
//     if (!file.IsOpened()) return false;
//     wxString buf = GetText();
//     bool okay = file.Write (buf);
//     file.Close();
//     if (!okay) return false;
//     EmptyUndoBuffer();
//     SetSavePoint();

//     return true;

    return wxStyledTextCtrl::SaveFile(filename);

}

bool wxEditor::Modified () {

    // return modified state
    return (GetModify() && !GetReadOnly());
}

//----------------------------------------------------------------------------
// EditProperties
//----------------------------------------------------------------------------

EditProperties::EditProperties (wxEditor *edit,
                                long style)
        : wxDialog (edit, wxID_ANY, wxEmptyString,
                    wxDefaultPosition, wxDefaultSize,
                    style | wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER) {

    // sets the application title
    SetTitle (_("Properties"));
    
    wxString text;

    // fullname
    wxBoxSizer *fullname = new wxBoxSizer (wxHORIZONTAL);
    fullname->Add (10, 0);
    fullname->Add (new wxStaticText (this, wxID_ANY, _("Full filename"),
                                     wxDefaultPosition, wxSize(80, wxDefaultCoord)),
                   0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    fullname->Add (new wxStaticText (this, wxID_ANY, edit->GetFilename()),
                   0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);

    // text info
    wxGridSizer *textinfo = new wxGridSizer (4, 0, 2);
    textinfo->Add (new wxStaticText (this, wxID_ANY, _("Language"),
                                     wxDefaultPosition, wxSize(80, wxDefaultCoord)),
                   0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT, 4);
    textinfo->Add (new wxStaticText (this, wxID_ANY, edit->m_language->name),
                   0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxRIGHT, 4);
    textinfo->Add (new wxStaticText (this, wxID_ANY, _("Lexer-ID: "),
                                     wxDefaultPosition, wxSize(80, wxDefaultCoord)),
                   0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT, 4);
    text = wxString::Format (_T("%d"), edit->GetLexer());
    textinfo->Add (new wxStaticText (this, wxID_ANY, text),
                   0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxRIGHT, 4);
    wxString EOLtype = wxEmptyString;
    switch (edit->GetEOLMode()) {
        case wxSTC_EOL_CR: {EOLtype = _T("CR (Unix)"); break; }
        case wxSTC_EOL_CRLF: {EOLtype = _T("CRLF (Windows)"); break; }
        case wxSTC_EOL_LF: {EOLtype = _T("CR (Macintosh)"); break; }
    }
    textinfo->Add (new wxStaticText (this, wxID_ANY, _("Line endings"),
                                     wxDefaultPosition, wxSize(80, wxDefaultCoord)),
                   0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT, 4);
    textinfo->Add (new wxStaticText (this, wxID_ANY, EOLtype),
                   0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxRIGHT, 4);

    // text info box
    wxStaticBoxSizer *textinfos = new wxStaticBoxSizer (
                     new wxStaticBox (this, wxID_ANY, _("Informations")),
                     wxVERTICAL);
    textinfos->Add (textinfo, 0, wxEXPAND);
    textinfos->Add (0, 6);

    // statistic
    wxGridSizer *statistic = new wxGridSizer (4, 0, 2);
    statistic->Add (new wxStaticText (this, wxID_ANY, _("Total lines"),
                                     wxDefaultPosition, wxSize(80, wxDefaultCoord)),
                    0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT, 4);
    text = wxString::Format (_T("%d"), edit->GetLineCount());
    statistic->Add (new wxStaticText (this, wxID_ANY, text),
                    0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxRIGHT, 4);
    statistic->Add (new wxStaticText (this, wxID_ANY, _("Total chars"),
                                     wxDefaultPosition, wxSize(80, wxDefaultCoord)),
                    0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT, 4);
    text = wxString::Format (_T("%d"), edit->GetTextLength());
    statistic->Add (new wxStaticText (this, wxID_ANY, text),
                    0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxRIGHT, 4);
    statistic->Add (new wxStaticText (this, wxID_ANY, _("Current line"),
                                     wxDefaultPosition, wxSize(80, wxDefaultCoord)),
                    0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT, 4);
    text = wxString::Format (_T("%d"), edit->GetCurrentLine());
    statistic->Add (new wxStaticText (this, wxID_ANY, text),
                    0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxRIGHT, 4);
    statistic->Add (new wxStaticText (this, wxID_ANY, _("Current pos"),
                                     wxDefaultPosition, wxSize(80, wxDefaultCoord)),
                    0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT, 4);
    text = wxString::Format (_T("%d"), edit->GetCurrentPos());
    statistic->Add (new wxStaticText (this, wxID_ANY, text),
                    0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxRIGHT, 4);

    // char/line statistics
    wxStaticBoxSizer *statistics = new wxStaticBoxSizer (
                     new wxStaticBox (this, wxID_ANY, _("Statistics")),
                     wxVERTICAL);
    statistics->Add (statistic, 0, wxEXPAND);
    statistics->Add (0, 6);

    // total pane
    wxBoxSizer *totalpane = new wxBoxSizer (wxVERTICAL);
    totalpane->Add (fullname, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    totalpane->Add (0, 6);
    totalpane->Add (textinfos, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    totalpane->Add (0, 10);
    totalpane->Add (statistics, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    totalpane->Add (0, 6);
    wxButton *okButton = new wxButton (this, wxID_OK, _("OK"));
    okButton->SetDefault();
    totalpane->Add (okButton, 0, wxALIGN_CENTER | wxALL, 10);

    SetSizerAndFit (totalpane);

    ShowModal();
}

#if wxUSE_PRINTING_ARCHITECTURE

//----------------------------------------------------------------------------
// EditPrint
//----------------------------------------------------------------------------

EditPrint::EditPrint (wxEditor *edit, const wxChar *title)
              : wxPrintout(title) {
    m_edit = edit;
    m_printed = 0;

}

bool EditPrint::OnPrintPage (int page) {

    wxDC *dc = GetDC();
    if (!dc) return false;

    // scale DC
    PrintScaling (dc);

    // print page
    if (page == 1) m_printed = 0;
    m_printed = m_edit->FormatRange (1, m_printed, m_edit->GetLength(),
                                     dc, dc, m_printRect, m_pageRect);

    return true;
}

bool EditPrint::OnBeginDocument (int startPage, int endPage) {

    if (!wxPrintout::OnBeginDocument (startPage, endPage)) {
        return false;
    }

    return true;
}

void EditPrint::GetPageInfo (int *minPage, int *maxPage, int *selPageFrom, int *selPageTo) {

    // initialize values
    *minPage = 0;
    *maxPage = 0;
    *selPageFrom = 0;
    *selPageTo = 0;

    // scale DC if possible
    wxDC *dc = GetDC();
    if (!dc) return;
    PrintScaling (dc);

    // get print page informations and convert to printer pixels
    wxSize ppiScr;
    GetPPIScreen (&ppiScr.x, &ppiScr.y);
    wxSize page = g_pageSetupData->GetPaperSize();
    page.x = static_cast<int> (page.x * ppiScr.x / 25.4);
    page.y = static_cast<int> (page.y * ppiScr.y / 25.4);
    m_pageRect = wxRect (0,
                         0,
                         page.x,
                         page.y);

    // get margins informations and convert to printer pixels
    wxPoint pt = g_pageSetupData->GetMarginTopLeft();
    int left = pt.x;
    int top = pt.y;
    pt = g_pageSetupData->GetMarginBottomRight();
    int right = pt.x;
    int bottom = pt.y;

    top = static_cast<int> (top * ppiScr.y / 25.4);
    bottom = static_cast<int> (bottom * ppiScr.y / 25.4);
    left = static_cast<int> (left * ppiScr.x / 25.4);
    right = static_cast<int> (right * ppiScr.x / 25.4);

    m_printRect = wxRect (left,
                          top,
                          page.x - (left + right),
                          page.y - (top + bottom));

    // count pages
    while (HasPage (*maxPage)) {
        m_printed = m_edit->FormatRange (0, m_printed, m_edit->GetLength(),
                                       dc, dc, m_printRect, m_pageRect);
        *maxPage += 1;
    }
    if (*maxPage > 0) *minPage = 1;
    *selPageFrom = *minPage;
    *selPageTo = *maxPage;
}

bool EditPrint::HasPage (int WXUNUSED(page)) {

    return (m_printed < m_edit->GetLength());
}

bool EditPrint::PrintScaling (wxDC *dc){

    // check for dc, return if none
    if (!dc) return false;

    // get printer and screen sizing values
    wxSize ppiScr;
    GetPPIScreen (&ppiScr.x, &ppiScr.y);
    if (ppiScr.x == 0) { // most possible guess 96 dpi
        ppiScr.x = 96;
        ppiScr.y = 96;
    }
    wxSize ppiPrt;
    GetPPIPrinter (&ppiPrt.x, &ppiPrt.y);
    if (ppiPrt.x == 0) { // scaling factor to 1
        ppiPrt.x = ppiScr.x;
        ppiPrt.y = ppiScr.y;
    }
    wxSize dcSize = dc->GetSize();
    wxSize pageSize;
    GetPageSizePixels (&pageSize.x, &pageSize.y);

    // set user scale
    float scale_x = (float)(ppiPrt.x * dcSize.x) /
                    (float)(ppiScr.x * pageSize.x);
    float scale_y = (float)(ppiPrt.y * dcSize.y) /
                    (float)(ppiScr.y * pageSize.y);
    dc->SetUserScale (scale_x, scale_y);

    return true;
}

#endif // wxUSE_PRINTING_ARCHITECTURE
