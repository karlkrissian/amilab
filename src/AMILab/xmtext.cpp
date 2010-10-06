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



#include "xmtext.hpp"
//#include "myscan.h"
#include <stdio.h>
#include <iostream>

#include <wx/strconv.h>
#include <wx/regex.h>

#include "token_list.h"

#include "MainFrame.h"
#include "driver.h"
#include "amilab_messages.h"

#include "fonctions.h"

extern yyip::Driver GB_driver;
extern MainFrame*   GB_main_wxFrame;

// for completion search
#include "VarContexts.hpp"
extern    VarContexts  Vars;


using namespace std;

static unsigned char in_changed_value = 0;


BEGIN_EVENT_TABLE(TextControl, wxTextCtrl)
  EVT_CHAR(       TextControl::OnChar)
  EVT_TEXT(       wxID_ANY,   TextControl::OnUpdate)
  //EVT_KEY_DOWN(   TextControl::OnKeyDown)
  //EVT_TEXT(       wxID_PASTE, TextControl::OnPaste)
  //EVT_IDLE(TextControl::DoIdle)
END_EVENT_TABLE()


//--------------------------------------------------
void TextControl::ConsoleReset()
{
  CLASS_MESSAGE("Resetting the console");
  this->text=_T("");
  this->AddPrompt(false);
}

//--------------------------------------------------
void TextControl::ConsoleClear()
{
  CLASS_MESSAGE("Clear the console");
  UpdateText();
}

//--------------------------------------------------
void TextControl::AddCommand( const wxString& cmd)
{
  text.Append(cmd);
  wxString unformat_cmd = cmd;
  unformat_cmd.Replace(_T("%"),_T("%%"));
  GB_driver.ws_print((const char*) unformat_cmd.mb_str(wxConvUTF8));

  cmd_lines[cmdlines_pos] = cmd;
  // get rid of the "\n" character at the end
  cmd_lines[cmdlines_pos].RemoveLast();
  cmdlines_pos = (cmdlines_pos+1)%MAX_SAVED_COMMANDS;
  cmdline_displaypos = -1;
}



//--------------------------------------------------
void TextControl::IncCommand( const wxString& cmd)
{
//  text.Append(" ");
//  text.Append(cmd);
  AppendText(wxString::FromAscii(" "));
  AppendText(cmd);
  //GB_driver.ws_print(cmd.c_str());
  //this->UpdateText();
}


//--------------------------------------------------
void TextControl::IncCommand( const std::string& cmd)
{
  const char* stval = cmd.c_str();
  // conversion failed ...
  wxString val(stval,wxConvUTF8);
  std::cout << "val = " << stval << "; "<< val.mb_str(wxConvUTF8) << std::endl;
  IncCommand(val);
}

//--------------------------------------------------
void TextControl::AddPrompt(bool newline)
{
  if (newline) {
    text.Append(wxString::FromAscii("\n"));
    // adds it to the file too
    GB_driver.ws_print("\n");
  }
  text.Append(wxString::FromAscii("[AMILab] "));
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
void TextControl::UpdateText()
{
  _protect = 0;
  this->SetDefaultStyle(wxTextAttr(*wxBLUE));
  this->SetValue(text);
  this->SetDefaultStyle(wxTextAttr(*wxBLACK));
  this->SetInsertionPointEnd();
  _protect = 1;
  if (GB_debug) {
    std::cerr << "TextControl::Update() text ="
         << text.Len()
         << "Is ASCII ?" << text.IsAscii()
         << std::endl;
  }
}

//--------------------------------------------------
void TextControl::OnPaste(wxCommandEvent& event)
//                -------
{
  CLASS_MESSAGE("begin");
  event.Skip();
}


//--------------------------------------------------
void TextControl::OnUpdate(wxCommandEvent&  event)
{

  CLASS_MESSAGE("begin");

  if (in_changed_value) {
    //printf("in_changed_value\n");
    event.Skip(); return;}
  if (!_protect)        {
    //printf("!_protect\n");
    event.Skip(); return;}

  if (GB_debug)
    std::cerr  << " insertion position "
          << (int) this->GetInsertionPoint()
          << " " << lastprompt_position << std::endl;
}

//--------------------------------------------------
void TextControl::DisplayCompletion()
{
    this->UpdateText();
    this->WriteText ( completion_lastcommand+(*completions)[completion_count]);

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
  alltext = this->GetValue();
  if (alltext==wxEmptyString) {
    CLASS_ERROR("Empty string");
    return;
  }
  completion_lastword = alltext.AfterLast(' ');
  completion_lastword = completion_lastword.AfterLast('(');
  completion_lastword = completion_lastword.AfterLast(',');
  completion_lastword = completion_lastword.AfterLast('.');
  //completion_lastword.RemoveLast();

 std::cout << "last word to complete "
       << completion_lastword << std::endl;
  completions = Vars.SearchCompletions(completion_lastword);

  // add keywords
  int i = 0;
  while (token_list[i]!=0) {
    wxString token=wxString::FromAscii(token_list[i]);
    if (token.First(completion_lastword) == 0)
        completions->Add(token);
    i++;
  }

  if (GB_debug)
   std::cout << "going for it " << completions->GetCount() << std::endl;
  if (completions->GetCount()>0) {
    int last_command_size = this->GetValue().Length()-this->text.Length()-completion_lastword.Length();
    completion_lastcommand = this->GetValue().Mid ( this->text.Len(), last_command_size );
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
void TextControl::ProcessReturn()
{
  wxString   alltext;
  wxString   last_cmd;
  int  TCsize;
  CLASS_MESSAGE("begin")

  in_changed_value = 1;

  alltext = this->GetValue();
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
      GB_driver.yyiperror(" Need Image \n");
      return;
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
      GB_driver.yyiperror(" Need Image \n");
      return;
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
  

  alltext = this->GetValue();
  TCsize  = this->GetAcceptedSize();
  // substring
  last_cmd =alltext.Mid(TCsize);
  //this->AddCommand(last_cmd);
  last_cmd += wxT('\n');
  last_cmd.Append(wxT('\0'),2);

  /*
  GB_driver.yyip_switch_to_string(last_cmd.mb_str(wxConvUTF8));
  //  yyiplineno=1;
  bool parseok = GB_driver.yyip_parse();
  GB_driver.yyip_popup_buffer();
  */
  bool parseok = GB_driver.parse_commandline(string(last_cmd.mb_str(wxConvUTF8)));

  if (!parseok) {
    CLASS_ERROR("Error in last command");
    //yyERROR=0;
  } else {
    alltext = this->GetValue();
    last_cmd =alltext.Mid(TCsize);
    last_cmd += '\n';
    this->AddCommand(last_cmd);
    this->AddPrompt(false);
  }

  // Add now the newline character ...
  in_changed_value = 0;
  if (GB_main_wxFrame)
    GB_main_wxFrame->UpdateVarsDisplay();

  // event.Skip();
}

//--------------------------------------------------
void TextControl::OnEnter(wxCommandEvent&  event)
{
  printf("OnEnter\n");
  event.Skip();
}



//--------------------------------------------------
void TextControl::OnChar(wxKeyEvent& event)
{
    CLASS_MESSAGE("OnChar");
    wxString key;
    long keycode = event.GetKeyCode();

   if (this->GetInsertionPoint()<lastprompt_position) {
     this->SetInsertionPoint(this->text.Len());
    if (GB_debug) std::cerr << format("TextControl::OnChar  insertion point %1% <  last position %2% ")
        % GetInsertionPoint()
        % lastprompt_position
        << "text = [" << this->text << "]"
        << std::endl;
     return;
   }

      if ((keycode != WXK_TAB)&&(in_completion)) {
              in_completion=0;
              this->UpdateText();
              this->AppendText ( completion_lastcommand);
              if (keycode != WXK_BACK)
                this->AppendText((*completions)[completion_count]);
              this->SetInsertionPointEnd();
      }

     if (!(keycode>0)&&(keycode<128)) {
      char c[2];
      c[0] = keycode;
      c[1] = 0;
      if (GB_debug) std::cerr << format(" OnChar() \t non ASCII character %s") % c << std::endl;
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
              //cout << "OnChar return" << std::endl;
              if (in_changed_value)
                event.Skip();
              else
                this->ProcessReturn();
              return;


            case WXK_BACK:
                // Don't allow deleting the prompt ...
                if (GB_debug) std::cerr << "OnChar BACK" << std::endl;
                if (this->GetInsertionPoint()==lastprompt_position)
                  this->SetInsertionPoint(this->text.Len());
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
                    GB_driver.yyiperror(" No filename given! \n");
                  } else {
  
                    wxFileName filename(wxString(name.c_str(), wxConvUTF8));
                    filename.Normalize(wxPATH_NORM_ALL,wxEmptyString,wxPATH_UNIX);
                    wxString newname(   filename.GetVolume()+filename.GetVolumeSeparator()+
                                        filename.GetPath(wxPATH_GET_VOLUME,wxPATH_UNIX)+
                                        filename.GetPathSeparator(wxPATH_UNIX)+
                                        filename.GetFullName());
                    inc_cmd = str(format(" \"%1%\" ") % newname.mb_str());
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
    event.Skip();
} // OnChar()


//--------------------------------------------------
void TextControl::PreviousCommand()
{
    // 1. if displaypos==-1 save current line
    // 2. go up in the command list
    if ( ( cmdline_displaypos==-1 ) || ( cmdline_displaypos == cmdlines_pos ) )
    {
        // to do: save current line
        cmdline_displaypos = cmdlines_pos;
        cmd_lines[cmdline_displaypos] = this->GetValue().Mid ( this->text.Len() );
        // show the previous line
        cmdline_displaypos = ( cmdline_displaypos+MAX_SAVED_COMMANDS-1 ) %MAX_SAVED_COMMANDS;
        this->UpdateText();
        this->WriteText ( cmd_lines[cmdline_displaypos] );
        this->SetInsertionPointEnd();
    }
    else
    {
       if (cmdline_displaypos>0) {
        cmdline_displaypos = ( cmdline_displaypos+MAX_SAVED_COMMANDS-1 ) %MAX_SAVED_COMMANDS;
        this->UpdateText();
//                    this->AppendText(cmd_lines[cmdline_displaypos].Left(cmd_lines[cmdline_displaypos].Len()-1));
        this->WriteText ( cmd_lines[cmdline_displaypos] );
        this->SetInsertionPointEnd();
       }
    }
}

//--------------------------------------------------
void TextControl::NextCommand()
{
    // 1. if displaypos==-1 do nothing
    // 2. otherwise go down in the command list
    if ( ( cmdline_displaypos!=-1 ) && ( cmdline_displaypos!=cmdlines_pos ) )
    {
        cmdline_displaypos = ( cmdline_displaypos+1 ) %MAX_SAVED_COMMANDS;
        this->UpdateText();
        this->WriteText ( cmd_lines[cmdline_displaypos] );
        this->SetInsertionPointEnd();
    }
}




