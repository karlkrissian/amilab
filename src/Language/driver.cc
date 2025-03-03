
/*
  taken from http://idlebox.net/2007/flex-bison-cpp-example/
  Thanks to the authors:
    Timo Bingmann
  and http://ioctl.org/jan/bison/
*/

// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the example::Driver class. */

#include <fstream>
#include <sstream>

#include "wxParamTypes.hpp"
#include "driver.h"
#include "scanner.h"
#include "VarContexts.hpp"
#include "CoutwxString.h"
#include "MainFrame.h"
#include "xmtext.hpp"
#include "ImageStack.h"
#include "wxStcFrame.h"

#include <wx/filename.h>
#include "CommonConfigure.h"

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

#include "AMILabConfigure.h"
AMILab_VAR_IMPORT wxString    GB_scripts_dir;
AMILab_VAR_IMPORT MainFrame*  GB_main_wxFrame;

COMMON_VAR_IMPORT unsigned char  GB_nofile;




namespace yyip {

//------------------------------------------------------
Driver::Driver()
    : 
      yyiplineno(1),
      current_file(""),
      trace_scanning(false),
      trace_parsing(false)
{
  in_console = true;

  procedure_declaration = false;

  nomessagedialog = false;

//  init_debug_stream();
  init_err_output();
  init_res_output();
  init_cmdhistory();

}

//------------------------------------------------------
Driver::~Driver() {
//  close_debug_stream();
}

//------------------------------------------------------
bool Driver::parse_stream(std::istream& in, 
                          const std::string& sname,
                          bool inconsole)
{
  //OutputDebugStringA("---------------------------------\n");
  //OutputDebugString(L"Driver::parse_stream()\n");
  class Scanner* previous_lexer;

  bool   in_console_bak   = in_console;
  in_console   = inconsole;

  streamname = sname;
//std::cout << "parse_stream" << std::endl;
//std::cout << "yyiplineno" << yyiplineno << std::endl;
  yyiplineno_lastparser = yyiplineno;

  previous_lexer = this->lexer;
  Scanner scanner(&in);
  scanner.set_debug(trace_scanning);
  this->lexer = &scanner;

  // Parse ...
  Parser parser(*this);
  #if YYDEBUG
    parser.set_debug_level(trace_parsing);
    if (language_debug_stream.good()) 
      parser.set_debug_stream(language_debug_stream);
    else
      parser.set_debug_stream(std::cout);
  #endif

  int res = 0;
  try {
    res = parser.parse();
    if (res!=0) {
     std::cout << __func__ << " returned " << res << std::endl;
    }
  }
  catch(std::exception const& e) {
    err_print( "std::exception catched during parsing \n");
    err_print( e.what());
//    err_print( (boost::format("std::exception catched during parsing \n %1%") % e.what()).str().c_str());
  }
  catch(...) { 
    err_print("Unknown exception catched during parsing");
  }

  this->lexer = previous_lexer;

  in_console   = in_console_bak;
  CLASS_MESSAGE((boost::format(" parsing result = %1%")%res).str().c_str());
  return ( res==0);
}

//-----------------------------------------------------------
bool Driver::parse_file(const std::string &filename)
{

  //OutputDebugStringA("---------------------------------\n");
  //OutputDebugStringA("Driver::parse_file()\n");
  //OutputDebugStringA(filename.c_str());
  //OutputDebugStringA("\n");
  //std::cout << "parse_file for " << filename  << std::endl;
  std::ifstream in(filename.c_str());
  if (!in.good()) return false;

  string current_file_bak          = this->current_file;
  int    yyiplineno_bak            = yyiplineno;
  int    yyiplineno_lastparser_bak = yyiplineno_lastparser;
  this->SetCurrentFile( filename.c_str());
  yyiplineno   = 1;
  yyiplineno_lastparser = yyiplineno;

  bool res = parse_stream(in, filename);

  current_file            = current_file_bak;
  yyiplineno              = yyiplineno_bak;
  yyiplineno_lastparser   = yyiplineno_lastparser_bak;

  return res;
}

//-----------------------------------------------------------
bool Driver::parse_string(const std::string &input, const std::string& sname)
{
  //OutputDebugStringA("---------------------------------\n");
  //OutputDebugStringA("Driver::parse_string()\n");
  //OutputDebugStringA(input.c_str());
  //OutputDebugStringA("\n");
  std::istringstream iss(input);
    return parse_stream(iss, sname);
}

//-----------------------------------------------------------
bool Driver::parse_commandline(const std::string &input, const std::string& sname)
{
  std::istringstream iss(input);
  return parse_stream(iss, sname,true);
  
}

//-----------------------------------------------------------
int Driver::error(const class location& l,
       const std::string& m)
{
    stringstream tmpstr;
    tmpstr  << l 
            << std::endl
            << " current_file = " << current_file << std::endl
            << " from line: " << yyiplineno_lastparser - 1 + l.begin.line << ", column: " << l.begin.column
            << " to   line: " << yyiplineno_lastparser - 1 + l.end.line   << ", column: " << l.end.column
            << std::endl
            << "yyiplineno = "            << yyiplineno
            << "yyiplineno_lastparser = " << yyiplineno_lastparser
            << std::endl
            << m 
            << std::endl;
    return err_print(tmpstr.str().c_str(),l);
}

//-----------------------------------------------------------
int Driver::error(const std::string& m)
{
    stringstream tmpstr;
    tmpstr << m << std::endl;
    return err_print(tmpstr.str().c_str());
}


//-----------------------------------------------------------
bool Driver::parse_block( const AmiInstructionBlock::ptr& b )
{
  //OutputDebugStringA("---------------------------------\n");
  //OutputDebugStringA("Driver::parse_block()\n");
  //OutputDebugStringA(b->GetBody().c_str());
  //OutputDebugStringA("\n");
  yyiplineno = b->GetStartingLine();
  std::string body = b->GetBody(); // +"  ";
  // fill last too characters with 0
  //body[body.length() - 1] = '\0';
  //body[body.length() - 2] = '\0';
  return parse_string(body);

}

//-----------------------------------------------------------
void Driver::ParseClassBody(const AMIClass::ptr& oclass)
{
  //OutputDebugStringA("---------------------------------\n");
  //OutputDebugStringA("Driver::ParseClassBody()\n");
  string previous_filename = this->current_file;
  if (oclass.get()) {
    // recursive call to possible parent
    for(int i=0;i<oclass->GetNumberOfParentClasses();i++)
      this->ParseClassBody(oclass->GetParentClass(i));
    // call to its body after setting the current filename
    this->SetCurrentFile(oclass->GetFileName().c_str());
    parse_block(oclass->GetBody());
  }
  this->SetCurrentFile(previous_filename.c_str());
}

//-----------------------------------------------------------
void Driver::yyip_instanciate_object(  AMIClass::ptr& oclass,
      AMIObject::ptr& object)
{

  int    previous_lineno   = yyiplineno;
  int    previous_lineno_lastparser   = yyiplineno_lastparser;
 // int    i;
 // char*  name;

  // Set the new local context
  std::string contextname = (boost::format("local_%1%")%object->GetName()).str();

  int previous_context = Vars.GetCurrentContextNumber();
  Vars.NewContext(contextname.c_str());
  Vars.SetLastContext();

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(object->GetContext());

  // Add some default variables as information
  // this

  // class variable
  object->GetContext()->AddVar<AMIClass>(oclass->GetName(),oclass,object->GetContext());

  // classname
  string_ptr classname(new string(oclass->GetName()));
  object->GetContext()->AddVar<string>("classname",classname,object->GetContext());
  // classfilename
  string_ptr classfname(new string(oclass->GetFileName()));
  object->GetContext()->AddVar<string>("classfilename",classfname,object->GetContext());

  string_ptr objfname(new string(this->current_file));
  object->GetContext()->AddVar<string>("objectfilename",objfname,object->GetContext());

  // Inheritence need to be recursive
  // Call the class body
  ParseClassBody(oclass);

  // Remove the previous context from the list
  Vars.DeleteLastContext();
  Vars.SetCurrentContextNumber(previous_context);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // Restore position and filename
  yyiplineno = previous_lineno;
  yyiplineno_lastparser = previous_lineno_lastparser;
}

//-----------------------------------------------------------
BasicVariable::ptr Driver::yyip_call_function( AMIFunction* f, const ParamList::ptr& param)
//                        --------------------------
{
  int    previous_lineno   = yyiplineno;
  int    previous_lineno_lastparser   = yyiplineno_lastparser;
  string previous_filename = this->current_file;
  int    i;
  char*  name;

/*
  // check that v is a function variable
  if (v->Type()!=type_ami_function) {
    error("Variable is not a function");
    return;
  }
  // Get the function
  AMIFunction::ptr f;
  f = *(AMIFunction::ptr*) (v->Pointer());
*/

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(f->GetContext());

  int previous_context = Vars.GetCurrentContextNumber();
  // Set the new context
  Variables::ptr local_context = Vars.NewContext(f->GetName().c_str());
  Vars.SetLastContext();

  // Creates the variables if needed
  if (param.get()) {
    // Verifier les parametres
    if (f->GetParamList( )->CheckParam(param.get())) {
      for(i=0;i<param->GetNumParam();i++) {
        name = f->GetParamList( )->GetName(i);
        if (Vars.GetCurrentContext()->ExistVar(name)) {
          std::cerr  << "variable " << name 
                << " already exists ... " 
                << "in context " << Vars.GetCurrentContext()->GetName()
                << std::endl;
        }
        else {
          
          //if (GB_debug)
          //  std::cerr << format("Vars.AddVarPtr( %1%, %2%, %3% )")
          //        % param->GetType(i) % name % param->GetParam(i)
          //      << std::endl;
          BasicVariable::ptr paramvar( param->GetParam(i));
          local_context->AddVar(name, paramvar,local_context);
        }
      } // end for
    } else {
      err_print("Error checking for parameters: check parameters types in function call (NUM is float, IMAGE is image variable, etc ...).");
    }
  }

  // Call the function
  this->SetCurrentFile(f->GetFileName().c_str());
  parse_block(f->GetBody());

  // check for a return variable
  BasicVariable::ptr return_var = Vars.GetVar("return");

  // Restore the previous context
  // destroy the context and its variables
  // removing each parameter is not necessary
  // cause it will be done by DeleteLastContext()
  Vars.DeleteLastContext();
  Vars.SetCurrentContextNumber(previous_context);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // Restore position and filename
  yyiplineno = previous_lineno;
  yyiplineno_lastparser = previous_lineno_lastparser;
  this->SetCurrentFile( previous_filename.c_str());

  return return_var;
}

//------------------------------------------------------
bool Driver::parse_script(  const char* filename)
//   --------------------
{

  string  fullname;
  string tmp_string;

  CLASS_MESSAGE( (boost::format("Switching to %1% ") % filename).str().c_str());

  // Looking for the filename
  wxFileName current_filename(GetwxStr(current_file.c_str()));
  wxFileName inputname(GetwxStr(filename));
  wxFileName newname(GetwxStr(filename));

  if (!inputname.IsOk()) {
    tmp_string = (boost::format("Problem with the filename %s\n") 
               % inputname.GetFullPath().mb_str()).str();
    err_print(tmp_string.c_str());
    return 0;
  }

  // could check first if there is another extension ...
  if (inputname.GetExt().Cmp(wxT(""))==0)
    inputname.SetExt(_T("amil"));

  //cout << "current wd = "  <<  wxGetCwd() << std::endl; 
  if (!inputname.DirExists(inputname.GetPath())) 
  {
    // try with current directory
    newname.Assign(
            wxGetCwd() 
            +
            inputname.GetPathSeparator()
            +
            inputname.GetPath(),
            inputname.GetFullName());
  }

  if (!newname.IsFileReadable()) 
  {
    CLASS_MESSAGE((boost::format(" current_filename.GetPath() = %1%")   
                % current_filename.GetPath().mb_str() ) .str().c_str());
    // try in the directory of the runnning script
    newname.Assign(
            current_filename.GetPath() 
            +
            inputname.GetPathSeparator()
            +
            inputname.GetPath(),
            inputname.GetFullName());
  }

  if (!newname.IsFileReadable()) 
  {
    // try with AMI_SCRIPTS environment variable
    newname.Assign(GB_scripts_dir
            +
            inputname.GetPathSeparator()
            +
            inputname.GetPath(),
            inputname.GetFullName());
  }

  if (!newname.IsFileReadable()) {
    string mess =  (boost::format("Error in reading %s \n") % inputname.GetFullPath().mb_str()).str();
    err_print(mess.c_str());
    return 0;
  }

/*
 std::cout << "current name " << newname.GetFullPath() << std::endl;
  yyipin=fopen(newname.GetFullPath().mb_str(),"r");
  if (!yyipin) {
    string mess =  (boost::format("Error in reading %s \n") % newname.GetFullPath().c_str()).str();
    wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),wxT("Error"),wxOK | wxICON_ERROR);
    err_msg->ShowModal();
    return 0;
  }

*/

  // replace / by \ in directories to avoid problems
  newname.Normalize();
  wxString newfilename = newname.GetFullPath();
  newfilename.Replace(wxT("\\"),wxT("/"),true);

  // add to history if written from the console
  if (InConsole())
    GB_main_wxFrame->GetScriptsHistory()->AddFileToHistory(newfilename);

  bool res = parse_file(string(newfilename.mb_str()));
  //cout << "current wd = "  <<  wxGetCwd() << std::endl; 
  return res;

} // Driver::parse_script()






//-------------------------------------------------
void Driver::yyiperror(const char *s) 
//           ---------
{
  string tmpstr;
  if ((yyiplineno)&&(this->lexer)) {
    const char* text = this->lexer->YYText();
    if (text) {
      tmpstr = str(boost::format("%s:%d\t %s \n\t ==> at '%s'  \n")
        %this->current_file.c_str()
        %this->yyiplineno
        %s
        %text
      );
    } else tmpstr = str(boost::format("%s \n")%s);
    err_print(tmpstr.c_str());
  } else {
    tmpstr = str(boost::format("%s \n")%s);
    err_print(tmpstr.c_str());
  } // end else 
  //fflush(stdout);
  //yyERROR = 1;

} // Driver::yyerror() 


//----------------------------------------------
void Driver::init_debug_stream()
//   -------------------------
{
  std::string filename(".improcess/language_debug");

  language_debug_stream.open(filename.c_str());
  if (!language_debug_stream.good()) 
    std::cerr << "Error in opening " << filename << std::endl;

} // Driver::init_debug_stream()


//----------------------------------------------
void Driver::close_debug_stream()
//   -------------------------
{
  if (language_debug_stream.is_open())
    language_debug_stream.close();
} // Driver::close_debug_stream()

//-----------------------------------------------
void Driver::init_err_output()
{
  //  char filename[100];

  err_output=&std::cerr;
  /*
  sprintf(filename,"improcess.err");
  err_output=fopen(filename,"w");
  if (!err_output) {
    fprintf(stderr,"Error in opening %s\n",filename);
    err_output=stderr;
  }
  */
} // Driver::init_err_output()


//--------------------------------------------------
int Driver::err_print(const char* st) 
//   -----------------
{
  if (GB_main_wxFrame)
    *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString(st,wxConvUTF8);
  std::cout << "Error: " << st << std::endl;
  string mess =  (boost::format("Error %s \n") % st).str();
  if (InConsole()) 
    mess = mess + " Abort current parsing ?";
  else 
    mess = mess + " Abort current parsing and open file?";

  // check if the message should be skipped
  if (SkipMessage(mess))
    return wxID_NO;
    
  if ((!nomessagedialog)&&(GB_main_wxFrame)) {
    wxMessageDialog* err_msg = new wxMessageDialog(GB_main_wxFrame,GetwxStr(mess),GetwxStr("Error"),wxYES_NO |  wxYES_DEFAULT  | wxICON_ERROR | wxSTAY_ON_TOP );
    int res = err_msg->ShowModal();
    err_msg->Destroy();

    if ((!InConsole())&&(res==wxID_YES)) {
      // create application frame
      wxStcFrame*  m_frame =  GB_main_wxFrame->GetAmilabEditor();
      // open application frame
      m_frame->Layout ();
      m_frame->Show (true);
      m_frame->FileOpen (wxString(this->current_file.c_str(),wxConvUTF8));
      wxEditor* editor = m_frame->GetActiveEditor();
      // TODO: 
      // - set show line numbers
      // - set highlight C++
      // - go to specific line
      editor->ShowLineNumbers(true);
      editor->GotoLine(this->yyiplineno-1);
    }
    
    wxMessageDialog* errskip_msg = 
      new wxMessageDialog(GB_main_wxFrame,
                          _T("Skip the next occurences of this message assuming 'NO'"),
                          GetwxStr("Skip"),
                          wxYES_NO | wxNO_DEFAULT  | 
                          wxICON_ERROR | wxSTAY_ON_TOP );
    int res1 = errskip_msg->ShowModal();
    errskip_msg->Destroy();
    if (res1==wxID_YES) {
      AddSkipMessage(mess);
    }
    
    return res;
  }

  return wxID_YES;
} // Driver::err_print()


//--------------------------------------------------
int Driver::err_print(const char* st, const class location& l) 
//   -----------------
{
  if (GB_main_wxFrame)
    *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString(st,wxConvUTF8);
  std::cout << "Error: " << st << std::endl;
  string mess =  (boost::format("Error %s \n") % st).str();
  if (InConsole()) 
    mess = mess + " Abort current parsing ?";
  else 
    mess = mess + " Abort current parsing and open file?";

  // check if the message should be skipped
  if (SkipMessage(mess))
    return wxID_NO;

  if ((!nomessagedialog)&&(GB_main_wxFrame)) {
    wxMessageDialog* err_msg = new wxMessageDialog(GB_main_wxFrame,GetwxStr(mess),GetwxStr("Error"),wxYES_NO |  wxYES_DEFAULT  | wxICON_ERROR | wxSTAY_ON_TOP );
    int res = err_msg->ShowModal();
    err_msg->Destroy();

    if ((!InConsole())&&(res==wxID_YES)) {
      // create application frame
      wxStcFrame*  m_frame =  GB_main_wxFrame->GetAmilabEditor();
      // open application frame
      m_frame->Layout ();
      m_frame->Show (true);
      m_frame->FileOpen (wxString(this->current_file.c_str(),wxConvUTF8));
      wxEditor* editor = m_frame->GetActiveEditor();
      // TODO: 
      // - set show line numbers
      // - set highlight C++
      // - go to specific line
      editor->ShowLineNumbers(true);
      int pos1 = editor->FindColumn(this->yyiplineno_lastparser-1+l.begin.line-1,l.begin.column-1);
      int pos2 = editor->FindColumn(this->yyiplineno_lastparser-1+l.end  .line-1,l.end  .column-1);
      editor->GotoPos(pos1);
      editor->SetSelectionStart(pos1);
      editor->SetSelectionEnd(pos2);
    }
    
    wxMessageDialog* errskip_msg = 
      new wxMessageDialog(GB_main_wxFrame,
                          _T("Skip the next occurences of this message assuming 'NO'"),
                          GetwxStr("Skip"),
                          wxYES_NO | wxNO_DEFAULT  | 
                          wxICON_ERROR | wxSTAY_ON_TOP );
    int res1 = errskip_msg->ShowModal();
    errskip_msg->Destroy();
    if (res1==wxID_YES) {
      AddSkipMessage(mess);
    }

    return res;
  }

  return wxID_YES;
} // Driver::err_print()


//--------------------------------------------------
void Driver::info_print(const char* st) 
//   -----------------
{
  if (GB_main_wxFrame)
    *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString(st,wxConvUTF8);
  string mess =  (boost::format("Information: %s \n") % st).str();
  if (!nomessagedialog) {
    wxMessageDialog* err_msg = new wxMessageDialog(GB_main_wxFrame,GetwxStr(mess),GetwxStr("Info"),wxOK | wxICON_INFORMATION | wxSTAY_ON_TOP );
    err_msg->ShowModal();
    err_msg->Destroy();
  }
} // Driver::err_print()


//---------------------------------------------
void Driver::close_err_output(void)
//   ------------------------
{
 if (err_output!=&std::cerr) {}
 //fclose(err_output);
} // Driver::close_err_output()


//--------------------------------------------------------
void Driver::init_res_output()
//   -----------------------
{
  //  char filename[100];

  res_output = &std::cout;
  /*
  sprintf(filename,"improcess.res");
  res_output=fopen(filename,"w");
  if (!res_output) {
    fprintf(stderr,"Error in opening %s\n",filename);
    err_output=stdout;
  }
  */
} // Driver::init_res_output()


//--------------------------------------------
void Driver::res_print(const char* st) 
//   -----------------
{
  if (GB_main_wxFrame)
    *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString(st, wxConvUTF8);
  std::cout << st << std::endl;
//  OutputDebugStringA(st);
} // Driver::res_print()

//--------------------------------------------
void Driver::res_print(const wxString& st) 
//   -----------------
{
  if (GB_main_wxFrame)
    *(GB_main_wxFrame->GetConsole()->GetLog()) << st;
//  std::cout << st << std::endl;
} // Driver::res_print()

//----------------------------------------
void Driver::close_res_output() 
//   ------------------------
{
if (res_output!=&std::cout) {}
 //  fclose(res_output);
} // Driver::close_res_output()



#include <sys/types.h>
#include <sys/stat.h>
#ifndef WIN32
#include <unistd.h>
#endif

//---------------------------------------------
void Driver::init_cmdhistory()
//   -----------------------
{
  std::string dirname;
  std::string filename;
  struct stat file_stat;
  //int res;
  int isdir;
  int  i;

  if (GB_nofile) return;

  // write in a local directory called .improcess
  // check if directory .improcess exists, otherwise create it
  dirname = ".improcess";
  //res=
  stat(dirname.c_str(),&file_stat);
  #ifndef S_ISDIR
    #define S_ISDIR(a) (a & _S_IFDIR)
  #endif
  isdir=S_ISDIR(file_stat.st_mode);
  if (!isdir)
    std::system("mkdir .improcess");

  i = 0;
  boost::format ws_filename_format(".improcess/cmdhistory%03d");
  filename = str( ws_filename_format % i);
#ifndef F_OK
#define F_OK 0
#endif
  TantQue access( filename.c_str(), F_OK) == 0 Faire
    i++;
    filename = str( ws_filename_format % i);
  FinTantQue

 std::cout << boost::format("Opening %1% \n") % filename;
  cmdhistory=FILE_ptr(fopen(filename.c_str(),"w"),file_deleter());

  // change properties to allow execution
  #ifndef WIN32
  chmod(filename.c_str(),S_IRUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
  #endif

  if (!cmdhistory) {
    std::cerr << boost::format("Error in opening %s\n") % filename;
    FILE_ptr stdout_ptr = CreateSmartPointer<FILE>()(stdout);
    cmdhistory.swap(stdout_ptr);
  } else
    cmdhistory_filename = filename;
} // Driver::init_cmdhistory()


//------------------------------------------------------------
void Driver::ws_print(const char* st)
//   ----------------
{
//printf("GB_nofile = %d \n",(int)GB_nofile);
  if (GB_nofile) return;
  fprintf(cmdhistory.get(),st);
  fflush(cmdhistory.get());
} // Driver::ws_print()


//-------------------------------------------
void Driver::close_cmdhistory()
//   ------------------------
{
  if (GB_nofile) return;
  if (cmdhistory.get()!=stdout) {
    cmdhistory.reset();
    // change properties to allow execution
    #ifndef WIN32
    chmod(cmdhistory_filename.c_str(),S_IRUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
    #endif
  }
} // Driver::close_cmdhistory()


} // namespace yyip

