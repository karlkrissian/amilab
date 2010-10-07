
#ifndef _XMTEXT_HPP
#define _XMTEXT_HPP


#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

//#include <wx/stc/stc.h>
//#include "wx/stc/stc.h"

#define MAX_SAVED_COMMANDS 50

//#include "wx/richtext/richtextctrl.h"

#include <string>
#include <iostream>
//using namespace std;

#include "DefineClass.hpp"

class TextControl : public wxTextCtrl {

  DEFINE_CLASS(TextControl)

protected:

//  wxString   alltext;
  wxString   text;
  wxString*  cmd_lines; // saved previous lines
  int        cmdlines_pos;
  int        cmdline_displaypos;
  wxString   last_line;
  unsigned char _protect;
  wxTextCtrl*  _logtextctrl;

  wxString        completion_lastcommand;
  wxString        completion_lastword;

  boost::shared_ptr<wxArrayString>  completions;
  unsigned char                     in_completion;
  int                               completion_count;
  wxTextPos                         lastprompt_position;

 public:

 TextControl(wxWindow *parent,
             wxWindowID id,
              const wxString& value,
              int flags,
              const wxValidator &      validator = wxDefaultValidator)
        : wxTextCtrl(
                      parent,
                      id,
                      value,
                      wxDefaultPosition,
                      wxDefaultSize,
                      flags
                      | wxTE_PROCESS_ENTER
                      | wxTE_PROCESS_TAB
//                      | wxHSCROLL
                      ,
                      validator
                    )
  {
    cmd_lines = new wxString[MAX_SAVED_COMMANDS];
    for(int i=0; i<MAX_SAVED_COMMANDS; i++) cmd_lines[i]=wxString::FromAscii("");
    cmdline_displaypos = -1;
    cmdlines_pos       = 0;
    in_completion      = 0;
    completions =  boost::shared_ptr<wxArrayString>(new wxArrayString());
    completion_count   = 0;
    SetSizeHints(wxSize(200,100));
    SetToolTip(_T("Amilab command line console, \n \tKeyboard shortcuts: \n \tCtrl-F: load a filename as a string. \n \tTab: complete a keyword or a variable name. \n \tUp-Down arrows to browse command history. "));    
  };

  ~TextControl() {
    //std::cout << "~TextControl()" << std::endl;
    delete[] cmd_lines;
  }

  void ConsoleReset();
  void ConsoleClear();

  void AddCommand( const wxString& cmd);

  void IncCommand( const wxString& cmd);
  void IncCommand( const std::string& cmd);

  void AddPrompt(bool newline=true);

  const wxString GetText() { return (const wxString) text; }

  int GetAcceptedSize() { return text.Len(); }

  void UpdateText();

  void OnPaste  (wxCommandEvent& event);
  void OnUpdate (wxCommandEvent& event);

  void DisplayCompletion();

  void ProcessTab();

  void ProcessReturn();

  void OnEnter(wxCommandEvent& event);

  void DoIdle( wxIdleEvent &event )
  {
    //m_bIgnoreNextTextEdit = false;
    event.Skip();
  }

  void PreviousCommand();
  void NextCommand();

  void OnChar(wxKeyEvent& event);
  wxTextCtrl* GetLog()      { return _logtextctrl;     }
  void SetLog(wxTextCtrl* log) { _logtextctrl=log; }

  void OnKeyDown(wxKeyEvent& event) {}

private:
  DECLARE_EVENT_TABLE()
};


#endif
