
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
#include <iosfwd>

#include "DefineClass.hpp"
#include <wx/richtext/richtextctrl.h>
#include <wx/richtext/richtextstyles.h>

#define wxTextCtrlClass wxRichTextCtrl
#include <vector>

class TextControl : public wxTextCtrlClass {

  DEFINE_CLASS(TextControl)

protected:

//  wxString   alltext;
  wxString   title_text;
  wxString   text;

  //! saved previous lines
  std::vector<wxString>  cmd_lines; 
  
  //! backup of the current commandline to allow navigating in the history
  wxString   current_commandline;
  
  //! position of the currently displayed command line
  int        cmdline_displaypos;
  
  wxString   last_line;
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
              const wxValidator &      validator = wxDefaultValidator);


  void InitRichText();

  ~TextControl() {
    //std::cout << "~TextControl()" << std::endl;
    delete _basic_style;
  }

  void ConsoleReset();
  void ConsoleClear();

  void AddCommand( const wxString& cmd);

  void IncCommand( const wxString& cmd);
  void IncCommand( const std::string& cmd);

  void AddPrompt(bool newline=true);

  const wxString GetText() { return (const wxString) text; }

  /**
  * @brief Return the size of the accepted text (including prompts but not title)
  *
  * @return int
  **/
  size_t GetAcceptedSize() const { return text.Len(); }

  void UpdateText(bool setendinsertion=true);


  void OnContentInserted( wxRichTextEvent& event);
  void OnReturn(          wxRichTextEvent& event);
  void OnUpdate (         wxCommandEvent&  event);
  void ProcessKeyEvent(   wxKeyEvent& event);

  //void OnCharacter   ( wxRichTextEvent& event);
  //void OnTextUpdated ( wxCommandEvent&  event);
  //void OnEnter       ( wxCommandEvent&  event);
  //void TextOnKeyDown ( wxKeyEvent&      event);
  //void OnKeyDown     ( wxKeyEvent&      event);
  
  /**
   * @brief Returns the contents of the console without the title.
   *
   * @return wxString
   **/
  wxString GetContents();

  void DisplayCompletion();

  void ProcessTab();

  bool ProcessReturn();


  void DoIdle( wxIdleEvent &event )
  {
    //m_bIgnoreNextTextEdit = false;
    event.Skip();
  }

  void PreviousCommand();
  void NextCommand();
  
  wxTextCtrl* GetLog()      { return _logtextctrl;     }
  void SetLog(wxTextCtrl* log) { _logtextctrl=log; }

private:
  DECLARE_EVENT_TABLE()
  wxTextAttrEx* _basic_style;
  bool in_changed_value;
  bool _protect;

};


#endif
