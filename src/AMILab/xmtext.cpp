/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ==================================================
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

// #include <X11/Intrinsic.h>
// #include <X11/Shell.h>
// #include <X11/StringDefs.h>
#include "AMILabConfig.h"

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "xmtext.hpp"
//#include "myscan.h"
#include <stdio.h>
#include <iostream>

#include <wx/strconv.h>
#include <wx/regex.h>

#include "token_list.h"

#include "amilab_messages.h"

#include "fonctions.h"
#include "ami_object.h"

#include "DriverBase.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT DriverBase::ptr  GB_DriverBase;

#include "AMILabConfigure.h"
#include "MainFrame.h"
AMILab_VAR_IMPORT MainFrame* GB_main_wxFrame;

// for completion search
#include "VarContexts.hpp"
//#include <wx/unichar.h> 
#include <wx/filename.h>

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;


using namespace std;


/*
enum
{
  wxID_OnTextInserted = 2000,
  wxID_OnCharacter,
  wxID_OnReturn,
  wxID_OnEnter,
};
*/

// now seems to work on windows, why?? does wxID_ANY have importance ??
BEGIN_EVENT_TABLE(TextControl, wxTextCtrlClass)
  EVT_RICHTEXT_CONTENT_INSERTED(  wxID_ANY, TextControl::OnContentInserted)
  EVT_RICHTEXT_RETURN(            wxID_ANY, TextControl::OnReturn)
  EVT_TEXT(                       wxID_ANY, TextControl::OnUpdate)
  EVT_KEY_DOWN(                   TextControl::ProcessKeyEvent)
  EVT_CHAR(                       TextControl::ProcessKeyEvent)
END_EVENT_TABLE()

  //EVT_RICHTEXT_CHARACTER(         wxID_ANY, TextControl::OnCharacter)
  //EVT_SET_CURSOR(TextControl::OnSetCursor)
  //EVT_TEXT(                       wxID_ANY, TextControl::OnTextUpdated)
  //EVT_IDLE(TextControl::DoIdle)
  //EVT_TEXT_ENTER(        wxID_ANY,     TextControl::OnEnter)



TextControl::TextControl(wxWindow *parent,
             wxWindowID id,
              const wxString& value,
              int flags,
              const wxValidator & validator)
        : wxTextCtrlClass(
                      parent,
                      id,
                      value,
                      wxDefaultPosition,
                      wxDefaultSize,
                      wxWANTS_CHARS|wxRE_MULTILINE
//                      flags
//                      | wxTE_PROCESS_TAB
//                      | wxHSCROLL
                      ,
                      validator
                    )
{
  cmd_lines.empty();
  cmdline_displaypos = 0;
  in_completion      = 0;
  in_changed_value   = false;
  completions =  boost::shared_ptr<wxArrayString>(new wxArrayString());
  completion_count   = 0;
  SetSizeHints(wxSize(200,100));
  SetToolTip(_T("Amilab command line console, \n \tKeyboard shortcuts: \n \tCtrl-F: load a filename as a string. \n \tTab: complete a keyword or a variable name. \n \tUp-Down arrows to browse command history. "));    
  
  this->title_text=_T("  AMILab Console  \n");
  InitRichText();
};


//--------------------------------------------------
void TextControl::InitRichText()
{
  // many new, no delete !!!
  
  // Create fonts ...
  wxFont romanFont(12, wxROMAN, wxNORMAL, wxNORMAL);

  wxRichTextParagraphStyleDefinition* normalPara = new \
    wxRichTextParagraphStyleDefinition(_T("Normal"));
  wxRichTextAttr* normalAttr = new wxRichTextAttr();
  normalAttr->SetFontFaceName(romanFont.GetFaceName());
  normalAttr->SetFontSize(12);
  // Let's set all attributes for this style
  normalAttr->SetFlags(wxTEXT_ATTR_FONT | wxTEXT_ATTR_BACKGROUND_COLOUR | 
                      wxTEXT_ATTR_TEXT_COLOUR|wxTEXT_ATTR_ALIGNMENT|
                      wxTEXT_ATTR_LEFT_INDENT|wxTEXT_ATTR_RIGHT_INDENT|
                      wxTEXT_ATTR_TABS|
                      wxTEXT_ATTR_PARA_SPACING_BEFORE|
                      wxTEXT_ATTR_PARA_SPACING_AFTER|
                      wxTEXT_ATTR_LINE_SPACING|
                      wxTEXT_ATTR_BULLET_STYLE|wxTEXT_ATTR_BULLET_NUMBER);
  normalPara->SetStyle(*normalAttr);

  wxRichTextStyleSheet* m_styleSheet = new wxRichTextStyleSheet();
  m_styleSheet->AddParagraphStyle(normalPara);

  this->SetStyleSheet(m_styleSheet);
  wxFont * font = new wxFont(11, wxROMAN, wxNORMAL, wxNORMAL);
  this->SetFont(*font);
  _basic_style = new wxTextAttrEx();
  _basic_style->SetTextColour(wxColour(0,0,0));
  _basic_style->SetFont(*font);
  //_basic_style->SetLeftIndent(50);
  SetDefaultStyle(*_basic_style);
  SetBasicStyle(*_basic_style);
}

//--------------------------------------------------
void TextControl::ConsoleReset()
{
  CLASS_MESSAGE("Resetting the console");
/*  BeginAlignment(wxTEXT_ALIGNMENT_CENTRE);
    WriteText(title_text);
  EndAlignment();*/
  text=_T("");
  this->AddPrompt(false);
}

//--------------------------------------------------
void TextControl::ConsoleClear()
{
  CLASS_MESSAGE("Clear the console");
  UpdateText();
  //MoveEnd();
}

//--------------------------------------------------
void TextControl::AddCommand( const wxString& cmd)
{
  //std::cout << "AddCommand( '" << cmd.ToAscii() << "')" << std::endl;
  text.Append(cmd);
  wxString unformat_cmd = cmd;
  unformat_cmd.Replace(_T("%"),_T("%%"));
  GB_DriverBase->ws_print((const char*) unformat_cmd.mb_str(wxConvUTF8));

  cmd_lines.push_back(cmd);
  // get rid of the "\n" character at the end
  cmd_lines.back().RemoveLast();
  //cmd_lines.size() = (cmd_lines.size()+1)%MAX_SAVED_COMMANDS;
  cmdline_displaypos = cmd_lines.size();
  //std::cout << "cmd_lines.size() = " << cmd_lines.size() << std::endl;
}



//--------------------------------------------------
void TextControl::IncCommand( const wxString& cmd)
{
  //std::cout << "IncCommand( '" << cmd.ToAscii() << "')" << std::endl;
//  text.Append(" ");
//  text.Append(cmd);
  WriteText(wxString::FromAscii(" "));
  WriteText(cmd);
  //GB_driver.ws_print(cmd.c_str());
  //this->UpdateText();
}


//--------------------------------------------------
void TextControl::IncCommand( const std::string& cmd)
{
  const char* stval = cmd.c_str();
  // conversion failed ...
  wxString val(stval,wxConvUTF8);
  //std::cout << "val = " << stval << "; "<< val.mb_str(wxConvUTF8) << std::endl;
  IncCommand(val);
}

//--------------------------------------------------
void TextControl::AddPrompt(bool newline)
{
  if (newline) {
    text.Append(wxString::FromAscii("\n"));
    // adds it to the file too
    GB_DriverBase->ws_print("\n");
  }
  text.Append(wxString::FromAscii("> "));
  UpdateText();
  lastprompt_position = GetLastPosition();
  //if (HasScrollbar(wxHORIZONTAL))
  //  SetScrollPos(wxHORIZONTAL,0);

  //SetForegroundColour(*wxBLUE);
  //SetBackgroundColour(*wxLIGHT_GREY);
  //SetFont(*wxITALIC_FONT);
  //(*this) << _T(" Italic?");
  //SetFont(*wxNORMAL_FONT);
}


//--------------------------------------------------
void TextControl::UpdateText( bool setendinsertion)
{
  CLASS_MESSAGE("begin")
  _protect = false;
  BeginSuppressUndo();
  Clear();

  SetAndShowDefaultStyle(*_basic_style);
  BeginAlignment(wxTEXT_ALIGNMENT_CENTRE);
    wxTextAttrEx ta;
    ta.SetBackgroundColour(wxColour(230,230,230));
    BeginStyle(ta);
      WriteText(title_text);
    EndStyle();
  EndAlignment();

  BeginItalic();
    BeginTextColour(*wxBLUE);
      this->WriteText(text);
    EndTextColour();
  EndItalic();

  if (setendinsertion)
    this->SetInsertionPointEnd();
  ShowPosition(GetLastPosition());
  SetAndShowDefaultStyle(*_basic_style);
  //SetDefaultStyleToCursorStyle();
  EndSuppressUndo();
  _protect = true;
  if (GB_debug) {
    std::cerr << "TextControl::Update() text ="
         << text.Len()
         << "Is ASCII ?" << text.IsAscii()
         << std::endl;
  }
  CLASS_MESSAGE("end")
}

//--------------------------------------------------
void TextControl::OnContentInserted(wxRichTextEvent& event)
//                -------
{
  CLASS_MESSAGE("begin");
  //std::cout << "Position " << event.GetPosition() << std::endl;
  //std::cout << "lastprompt_position " << lastprompt_position << std::endl;
  
  if (in_changed_value) {
    //printf("in_changed_value\n");
    event.Skip(); 
    return;
  }
  
  if (!_protect)        {
    //printf("!_protect\n");
    event.Skip();
    return;
  }

  if (event.GetPosition()>=lastprompt_position) {
    event.Skip();
  } else {
    ConsoleClear();
    MoveEnd();
    // the Veto does not seem to affect ...
    event.Veto();
  }
}


/*
//------------------------------------------------------------------------------
void TextControl::OnTextUpdated(  wxCommandEvent& event)
{
  std::cout << "OnTextUpdated()" << std::endl;
  if (this->GetInsertionPoint() < lastprompt_position) {
    ConsoleClear();
    MoveEnd();
  } else 
    event.Skip();
}
*/

//------------------------------------------------------------------------------
void TextControl::OnUpdate(wxCommandEvent&  event)
{

  CLASS_MESSAGE("begin");

  if (in_changed_value) {
    //printf("in_changed_value\n");
    event.Skip(); 
    return;
  }
  
  if (!_protect)        {
    //printf("!_protect\n");
    event.Skip();
    return;
  }

  //event.Skip();
  if (GB_debug)
    std::cerr  << " insertion position "
          << (int) this->GetInsertionPoint()
          << " " << lastprompt_position << std::endl;

  if (this->GetInsertionPoint() < lastprompt_position) {
    ConsoleClear();
    MoveEnd();
  }
}

//--------------------------------------------------
void TextControl::DisplayCompletion()
{
    this->UpdateText();
    this->WriteText ( completion_lastcommand+(*completions)[completion_count]);

}

//--------------------------------------------------
wxString TextControl::GetContents()
{
  return this->GetRange(title_text.Length(),GetLastPosition());
}

//--------------------------------------------------
void TextControl::ProcessTab()
{
  if (in_completion) {
    completion_count = (completion_count+1)%(completions->GetCount());
    //printf("in_completion %d / %d \n",completion_count, completions->GetCount());
    DisplayCompletion();
    return;
  }

  // get the last word
  wxString   alltext;
  alltext = this->GetContents(); //this->GetValue();
  
  if (alltext==wxEmptyString) {
    CLASS_ERROR("Empty string");
    return;
  }
  
//  wxRegEx last_variable_regex (wxT(".*((global::|)([_[:alpha:]][_[:alnum]]*->)*([_[:alpha:]][_[:alnum]]*))$"));
  wxString expr = wxT(".*[^[:alnum:]_\\.\\:]((global\\:\\:)?([_[:alpha:]][_[:alnum:]]*\\.)*([_[:alpha:]][_[:alnum:]]*)?)$");
  wxRegEx last_variable_regex (expr);
  wxString last_variable;
  if (!last_variable_regex.IsValid()) {
   std::cout << "Expression not valid !!!" << std::endl;
  }
  if (last_variable_regex.Matches(alltext))
  {
    // need to call Matches before GetMatch !!!
    last_variable = last_variable_regex.GetMatch(alltext,1);
    std::cout << "expression " << expr.mb_str() << std::endl;
    std::cout << "alltext: '"
        << alltext.mb_str(wxConvUTF8) << "'" << std::endl;
    std::cout << "last pending variable name: '"
        << last_variable.mb_str(wxConvUTF8) << "'" << std::endl;
  } else 
  {
   std::cout << "no match !!!" << std::endl;
   return;
  }

  // find the corresponding context if any
  // allow global or builtin ...
  bool inglobal=true;
  int seppos;
  Variables::ptr context = Vars.GetCurrentContext();
  while ((seppos = last_variable.Find(wxT("."))) != wxNOT_FOUND) 
  {
    wxString varname = last_variable.BeforeFirst('.');
    BasicVariable::ptr var;
    if (varname.Contains(wxT("global::"))) {
      varname = varname.AfterLast(':'); // get rid of global::
      var = context->GetVar(varname.mb_str(wxConvUTF8));
    }
    else
    {
      if (inglobal)
        var = Vars.GetVar(varname.mb_str(wxConvUTF8));
      else
        var = context->GetVar(varname.mb_str(wxConvUTF8));        
      }
    if (!var.get()) {
      std::cout << "Completion failed, check variable ..." << std::endl;
      return;
    }
    DYNAMIC_CAST_VARIABLE(AMIObject,var,var1);
    if (!var1.get()) {
      std::cout << "variable " << var->get_name() 
                << " is not of type AMIObject" << std::endl;
      return;
    }
    context = var1->Pointer()->GetContext();
    inglobal = false;
    last_variable = last_variable.AfterFirst('.');
  }

  if (inglobal)
  {
    if (last_variable.Contains(wxT("global::"))) {
      last_variable = last_variable.AfterLast(':'); // get rid of global::
      completions->Clear();
      context->SearchCompletions(last_variable, completions);
    }
    else
    {
      completions = Vars.SearchCompletions(last_variable);
      // add keywords
      int i = 0;
      while (token_list[i]!=0) {
        wxString token=wxString::FromAscii(token_list[i]);
        if (token.First(last_variable) == 0)
            completions->Add(token);
        i++;
      }
    }
  }
  else
  {
    completions->Clear();
    context->SearchCompletions(last_variable, completions);
  }

  /*
  completion_lastword = alltext.AfterLast(' ');
  completion_lastword = completion_lastword.AfterLast('(');
  completion_lastword = completion_lastword.AfterLast(',');
  completion_lastword = completion_lastword.AfterLast('.');
  //completion_lastword.RemoveLast();

 std::cout << "last word to complete "
       << completion_lastword << std::endl;
  completions = Vars.SearchCompletions(completion_lastword);

  */

  if (GB_debug)
   std::cout << "going for it " << completions->GetCount() << std::endl;
  if (completions->GetCount()>0) {
    //int last_command_size = this->GetValue().Length()-this->text.Length()-last_variable.Length();
    //completion_lastcommand = this->GetValue().Mid ( this->text.Len(), last_command_size );
    int last_command_size = this->GetContents().Length()-this->text.Length()-last_variable.Length();
    completion_lastcommand = this->GetContents().Mid ( this->text.Len(), last_command_size );
    in_completion = 1;
    completion_count = 0;
    DisplayCompletion();
    printf("Found %d completions \n",(int)completions->GetCount());
    for(int i=0;i<(int)completions->GetCount();i++) {
     std::cout << (*completions)[i].mb_str() << std::endl;
    }
  }
} // ProcessTab()

//--------------------------------------------------
bool TextControl::ProcessReturn()
{
  wxString   alltext;
  wxString   last_cmd;
  int  TCsize;
  CLASS_MESSAGE("begin")

  in_changed_value = true;

  //alltext = this->GetValue();
  alltext = this->GetContents();
  TCsize  = this->GetAcceptedSize();

  // substring
  last_cmd =alltext.Mid(TCsize);

  // check for special case:
  // 1. if last word is Image
  wxRegEx image_keyword (wxT(".*[^[:alnum:]]+Image[[:blank:]]*$"));
  if (image_keyword.Matches(last_cmd)) {
    cout << "ends with Image" << endl;

    int res;
    string name;

    res=AskImage(name);
    if (!res) {
      GB_DriverBase->yyiperror(" Need Image \n");
      in_changed_value = false;
      return false;
    }

    wxFileName filename(wxString::FromAscii(name.c_str()));
    filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
    wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                        filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                        filename.GetPathSeparator(wxPATH_UNIX)+
                        filename.GetFullName());
    wxString inc_cmd; // increment the command line string
    inc_cmd = wxT(" \"")+newname+wxT("\" // from browser ");
    IncCommand(inc_cmd);
  }
  
  // 2. if last word is Surface
  wxRegEx surface_keyword (wxT(".*[^[:alnum:]]+Surface[[:blank:]]*$"));
  if (surface_keyword.Matches(last_cmd)) {
    cout << "ends with Surface" << endl;

    int res;
    string name;

    res=AskSurface(name);
    if (!res) {
      GB_DriverBase->yyiperror(" Need Image \n");
      in_changed_value = false;
      return false;
    }

    wxFileName filename(wxString::FromAscii(name.c_str()));
    filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
    wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                        filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                        filename.GetPathSeparator(wxPATH_UNIX)+
                        filename.GetFullName());
    wxString inc_cmd; // increment the command line string
    inc_cmd = wxT(" \"")+newname+wxT("\" // from browser ");
    IncCommand(inc_cmd);
  }
  

  //alltext = this->GetValue();
  alltext = this->GetContents();
  TCsize  = this->GetAcceptedSize();
  // substring
  last_cmd =alltext.Mid(TCsize);
  //this->AddCommand(last_cmd);
  last_cmd += wxT('\n');
  last_cmd.Append(wxT('\0'),2);

  /*
  GB_driver.yyip_switch_to_string(last_cmd.mb_str(wxConvUTF8));
  //  yyiplineno=1;
  bool parseok = .yyip_parse();
  GB_driver.yyip_popup_buffer();
  */
  bool parseok = GB_DriverBase->parse_commandline(string(last_cmd.mb_str(wxConvUTF8)));

  if (!parseok) {
    CLASS_ERROR("Error in last command");
    //yyERROR=0;
  } else {
    //alltext = this->GetValue();
    alltext = this->GetContents();
    last_cmd =alltext.Mid(TCsize);
    last_cmd += '\n';
    this->AddCommand(last_cmd);
    this->AddPrompt(false);
    current_commandline = _T("");
  }

  // Add now the newline character ...
  //in_changed_value = true;

  // Too slow now, need a clever way to update only visible information ...
  if (GB_main_wxFrame)
    GB_main_wxFrame->UpdateVars();

  in_changed_value = false;
  return parseok;
  // event.Skip();
}

/*
//--------------------------------------------------
void TextControl::OnEnter(wxCommandEvent&  event)
{
  if (in_changed_value)
    event.Skip();
  else
    this->ProcessReturn();
  return;
}
*/

/*
//--------------------------------------------------
void TextControl::TextOnKeyDown(wxKeyEvent& event)
{
  CLASS_MESSAGE("Begin");
  wxString key;
  long keycode = event.GetKeyCode();
  event.Skip();

}
*/

//--------------------------------------------------
void TextControl::ProcessKeyEvent(wxKeyEvent& event)
{
  CLASS_MESSAGE("ProcessKeyEvent");
  wxString key;
  long keycode = event.GetKeyCode();

  if (this->GetInsertionPoint()<lastprompt_position) {
   this->SetInsertionPoint(lastprompt_position);
  if (GB_debug) std::cerr << boost::format("TextControl::OnKeyDown  insertion point %1% <  last position %2% ")
      % GetInsertionPoint()
      % lastprompt_position
      << "text = [" << this->text << "]"
      << std::endl;
     return;
  }

  if ((keycode != WXK_TAB)&&(in_completion)) {
    in_completion=0;
    this->UpdateText(false);
    if (!completion_lastcommand.IsEmpty())
      this->WriteText ( completion_lastcommand);
    if (keycode != WXK_BACK)
      this->WriteText((*completions)[completion_count]);
    this->SetInsertionPointEnd();
  }

  if (!(keycode>0)&&(keycode<128)) {
    char c[2];
    c[0] = keycode;
    c[1] = 0;
    if (GB_debug) std::cerr << boost::format(" OnKeyDown() \t non ASCII character %s") % c << std::endl;
  }

  {
    switch ( keycode )
    {
      case WXK_TAB:
        // process the new line
        this->ProcessTab();
        return;

      case WXK_RETURN: //key = _T("RETURN"); break;
        // process the new line
        //cout << "OnKeyDown return" << std::endl;
        if (in_changed_value)
          event.Skip();
        else
          this->ProcessReturn();
        return;


      case WXK_BACK:
        /*std::cout << "WXK_BACK" << std::endl;
        std::cout << this->GetInsertionPoint() << "; " << lastprompt_position << std::endl;
        std::cout << (title_text+text).Len() << std::endl;*/
        // Don't allow deleting the prompt ...
        if (GB_debug) std::cerr << "OnKeyDown BACK" << std::endl;
        if (this->GetInsertionPoint()<=lastprompt_position)
          this->SetInsertionPoint((title_text+text).Len());
        if ((int)this->GetInsertionPoint()>lastprompt_position) event.Skip();
        return;


      case WXK_UP:
        this->PreviousCommand();
        return;

      case WXK_DOWN:
        this->NextCommand();
        return;

      case WXK_HOME:
        this->SetInsertionPoint(this->text.Len());
        return;

      case WXK_LEFT:
       if (this->GetInsertionPoint()==lastprompt_position)
          return;

      case '.':
      case ',':
      case '(':
      case '[':
        // Check for putting color to last word
      break;

      case WXK_ESCAPE: key = _T("ESCAPE"); break;
      case WXK_START: key = _T("START"); break;
      case WXK_LBUTTON: key = _T("LBUTTON"); break;
      case WXK_RBUTTON: key = _T("RBUTTON"); break;
      case WXK_CANCEL: key = _T("CANCEL"); break;
      case WXK_MBUTTON: key = _T("MBUTTON"); break;
      case WXK_CLEAR: key = _T("CLEAR"); break;
      case WXK_SHIFT: key = _T("SHIFT"); break;
      case WXK_ALT: key = _T("ALT"); break;
      case WXK_CONTROL: key = _T("CONTROL"); break;
      case WXK_MENU: key = _T("MENU"); break;
      case WXK_PAUSE: key = _T("PAUSE"); break;
      case WXK_CAPITAL: key = _T("CAPITAL"); break;

      //case WXK_PRIOR: key = _T("PRIOR"); break;
      //case WXK_NEXT: key = _T("NEXT"); break;

      case WXK_END: key = _T("END"); break;
      case WXK_SELECT: key = _T("SELECT"); break;
      case WXK_PRINT: key = _T("PRINT"); break;
      case WXK_EXECUTE: key = _T("EXECUTE"); break;
      case WXK_SNAPSHOT: key = _T("SNAPSHOT"); break;
      case WXK_INSERT: key = _T("INSERT"); break;
      case WXK_HELP: key = _T("HELP"); break;
      case WXK_NUMPAD0: key = _T("NUMPAD0"); break;
      case WXK_NUMPAD1: key = _T("NUMPAD1"); break;
      case WXK_NUMPAD2: key = _T("NUMPAD2"); break;
      case WXK_NUMPAD3: key = _T("NUMPAD3"); break;
      case WXK_NUMPAD4: key = _T("NUMPAD4"); break;
      case WXK_NUMPAD5: key = _T("NUMPAD5"); break;
      case WXK_NUMPAD6: key = _T("NUMPAD6"); break;
      case WXK_NUMPAD7: key = _T("NUMPAD7"); break;
      case WXK_NUMPAD8: key = _T("NUMPAD8"); break;
      case WXK_NUMPAD9: key = _T("NUMPAD9"); break;
      case WXK_MULTIPLY: key = _T("MULTIPLY"); break;
      case WXK_ADD: key = _T("ADD"); break;
      case WXK_SEPARATOR: key = _T("SEPARATOR"); break;
      case WXK_SUBTRACT: key = _T("SUBTRACT"); break;
      case WXK_DECIMAL: key = _T("DECIMAL"); break;
      case WXK_DIVIDE: key = _T("DIVIDE"); break;
      case WXK_F1: key = _T("F1"); break;
      case WXK_F2: key = _T("F2"); break;
      case WXK_F3: key = _T("F3"); break;
      case WXK_F4: key = _T("F4"); break;
      case WXK_F5: key = _T("F5"); break;
      case WXK_F6: key = _T("F6"); break;
      case WXK_F7: key = _T("F7"); break;
      case WXK_F8: key = _T("F8"); break;
      case WXK_F9: key = _T("F9"); break;
      case WXK_F10: key = _T("F10"); break;
      case WXK_F11: key = _T("F11"); break;
      case WXK_F12: key = _T("F12"); break;
      case WXK_F13: key = _T("F13"); break;
      case WXK_F14: key = _T("F14"); break;
      case WXK_F15: key = _T("F15"); break;
      case WXK_F16: key = _T("F16"); break;
      case WXK_F17: key = _T("F17"); break;
      case WXK_F18: key = _T("F18"); break;
      case WXK_F19: key = _T("F19"); break;
      case WXK_F20: key = _T("F20"); break;
      case WXK_F21: key = _T("F21"); break;
      case WXK_F22: key = _T("F22"); break;
      case WXK_F23: key = _T("F23"); break;
      case WXK_F24: key = _T("F24"); break;
      case WXK_NUMLOCK: key = _T("NUMLOCK"); break;
      case WXK_SCROLL: key = _T("SCROLL"); break;
      //            case WXK_PAGEUP: key = _T("PAGEUP"); break;
      //            case WXK_PAGEDOWN: key = _T("PAGEDOWN"); break;
      default:
      {
        if ( wxIsprint((int)keycode) )
            key.Printf(_T("'%c'"), (char)keycode);
        else if ( keycode > 0 && keycode < 27 ) {
          key.Printf(_("Ctrl-%c"), _T('A') + keycode - 1);
          // remove the last character

          // Use Ctrl-F to write a filename in the console
          if (_T('A') + keycode - 1 == _T('F')) {

            int res;
            string name;
            string inc_cmd; // increment the command line string

            res=AskFilename(name);
            if (!res) {
              GB_DriverBase->yyiperror(" No filename given! \n");
            } else {

              wxFileName filename(wxString(name.c_str(), wxConvUTF8));
              filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
              wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                                  filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                                  filename.GetPathSeparator(wxPATH_UNIX)+
                                  filename.GetFullName());
              inc_cmd = str(boost::format(" \"%1%\" ") % newname.mb_str());
              this->IncCommand(wxString(inc_cmd.c_str(),wxConvUTF8));
            }
          }
        }
        else
            key.Printf(_T("unknown (%ld)"), keycode);
      }
    }
  }

  if (GB_debug) std::cerr <<  key << std::endl;
  SetAndShowDefaultStyle(*_basic_style);
  //SetDefaultStyleToCursorStyle();
  event.Skip();
} // OnKeyDown()


/*
//--------------------------------------------------
void TextControl::OnKeyDown(wxKeyEvent& event)
{
  CLASS_MESSAGE("OnKeyDown");
  ProcessKeyEvent(event);
}
*/

//--------------------------------------------------
void TextControl::PreviousCommand()
{
  //std::cout << "cmdline_displaypos = " << cmdline_displaypos << std::endl;
  //std::cout << "current_commandline = '" << current_commandline.ToAscii() << "'" << std::endl;
  //for(int i=0;i<(int)cmd_lines.size();i++) {
    //std::cout << " command " << i << ": '" <<  cmd_lines[i].ToAscii() << "'" << std::endl;
  //}

  // Do nothing if we are at the first command or there is only one command
  if ((cmdline_displaypos==0)||(cmd_lines.size()==0)) { return; }
  
  // 1. if displaypos==-1 save current line
  // 2. go up in the command list
  if (cmdline_displaypos == cmd_lines.size())
  {
      // to do: save current line
      current_commandline = this->GetContents().Mid ( this->text.Len() );
      //cmd_lines.size()++;
      //std::cout << "saving command " << cmdline_displaypos << " : '"
                //<< current_commandline.ToAscii() << "'" << std::endl;
      // show the previous line
      cmdline_displaypos--;
      this->UpdateText();
      this->WriteText(cmd_lines[cmdline_displaypos] );
      this->SetInsertionPointEnd();
  }
  else
  {
    if (cmdline_displaypos>0) {
      cmdline_displaypos--;
      this->UpdateText();
      //this->AppendText(cmd_lines[cmdline_displaypos].Left(cmd_lines[cmdline_displaypos].Len()-1));
      if (cmd_lines[cmdline_displaypos].Length() != 0)
        this->WriteText ( cmd_lines[cmdline_displaypos] );
      this->SetInsertionPointEnd();
    }
  }
}

//--------------------------------------------------
void TextControl::NextCommand()
{
  //std::cout << "cmdline_displaypos = " << cmdline_displaypos << std::endl;
  //std::cout << "current_commandline = '" << current_commandline.ToAscii() << "'" << std::endl;
  //for(int i=0;i<(int)cmd_lines.size();i++) {
    //std::cout << " command " << i << ": '" <<  cmd_lines[i].ToAscii() << "'" << std::endl;
  //}
  // 1. if displaypos==-1 do nothing
  // 2. otherwise go down in the command list
  if  (cmdline_displaypos<(int)cmd_lines.size()-1)
  {
      cmdline_displaypos++;
      this->UpdateText();
      if (cmd_lines[cmdline_displaypos].Length() != 0)
        this->WriteText(cmd_lines[cmdline_displaypos]);
      this->SetInsertionPointEnd();
  } else 
    if (cmdline_displaypos==(int)cmd_lines.size()-1) {
      // bring back the command previously saved
      cmdline_displaypos++;
      this->UpdateText();
      if (current_commandline.Length()!=0) 
      {
        this->WriteText(current_commandline);
        this->SetInsertionPointEnd();
      }
    }
}


/*
void TextControl::OnCharacter(wxRichTextEvent& event)
{
  std::cout << "OnCharacter" << std::endl;
  event.Skip();
}
*/

void TextControl::OnReturn(wxRichTextEvent& event)
{
  //std::cout << "OnReturn" << std::endl;
  if (in_changed_value)
    event.Skip();
  else
    this->ProcessReturn();
}
