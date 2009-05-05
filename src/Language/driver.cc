
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

#include "driver.h"
#include "scanner.h"
#include "VarContexts.hpp"

extern VarContexts       Vars;

namespace yyip {

//------------------------------------------------------
Driver::Driver()
    : trace_scanning(false),
      trace_parsing(false),
      yyiplineno(1),
      current_file("")
{
  in_console = true;

  procedure_declaration = false;

  init_debug_stream();
  init_err_output();
  init_res_output();
  init_cmdhistory();

}

//------------------------------------------------------
Driver::~Driver() {
  close_debug_stream();
}

//------------------------------------------------------
bool Driver::parse_stream(std::istream& in, const std::string& sname)
{
    class Scanner* previous_lexer;

    streamname = sname;

    previous_lexer = this->lexer;
    Scanner scanner(&in);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    // Parse ...
    Parser parser(*this);
    parser.set_debug_level(trace_parsing);
    if (language_debug_stream.good()) 
      parser.set_debug_stream(language_debug_stream);
    int res = parser.parse();

    this->lexer = previous_lexer;

    return ( res== 0);
}

//-----------------------------------------------------------
bool Driver::parse_file(const std::string &filename)
{
  std::ifstream in(filename.c_str());
  if (!in.good()) return false;

  string current_file_bak = current_file;
  bool   in_console_bak   = in_console;
  int    yyiplineno_bak   = yyiplineno;
  current_file = filename;
  in_console   = false;
  yyiplineno   = 1;

  bool res = parse_stream(in, filename);

  current_file = current_file_bak;
  in_console   = in_console_bak;
  yyiplineno   = yyiplineno_bak;

  return res;
}

//-----------------------------------------------------------
bool Driver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

//-----------------------------------------------------------
void Driver::error(const class location& l,
		   const std::string& m)
{
    stringstream tmpstr;
    tmpstr  << l 
            << endl
            << " current_file = " << current_file << endl
            << " lineno = "  
              << yyiplineno -1
              << "-"
              << yyiplineno 
              << endl
            << m 
            << std::endl;
    err_print(tmpstr.str().c_str());
}

//-----------------------------------------------------------
void Driver::error(const std::string& m)
{
    stringstream tmpstr;
    tmpstr << m << std::endl;
    err_print(tmpstr.str().c_str());
}


//-----------------------------------------------------------
bool Driver::parse_block( const AmiInstructionBlock::ptr& b )
{
  yyiplineno = b->GetStartingLine();
  return parse_string((b->GetBody()+"\0\0").c_str());

}


//-----------------------------------------------------------
void Driver::yyip_call_function( const AMIFunction::ptr& f, const ParamList::ptr& param)
//   --------------------------
{
  int    previous_lineno   = yyiplineno;
  string previous_filename = this->current_file;
  int    i;
  char*  name;

  // Set the new context
  Vars.NewContext(f->GetName().c_str());
  Vars.SetLastContext();

  // Creates the variables if needed
  if (param.get())
    // Verifier les parametres
    if (f->GetParamList( )->CheckParam(param.get())) 
      for(i=0;i<param->GetNumParam();i++) {
        name = f->GetParamList( )->GetName(i);
        if (Vars.GetCurrentContext()->ExistVar(name)) {
          cerr  << "variable " << name 
                << " already exists ... " 
                << "in context " << Vars.GetCurrentContext()->GetName()
                << endl;
        }
        else {
          cout << format("Vars.AddVarPtr( %1%, %2%, %3% )")
                  % param->GetType(i) % name % param->GetParam(i)
                << endl;
          // LOTS OF CARE HERE, now GetParam is a pointer
          // to a smart pointer !!!
          Vars.AddVarPtr( param->GetType(i),
                          name,
                          param->GetParam(i)
                        );
        }
      } // end for
    else
      cerr  << "Driver::yyip_call_function "
            << "\t Error checking for parameters."
            << endl;

  // Call the function
  this->current_file = f->GetFileName();
  parse_block(f->GetBody());

  // Restore the previous context
  // destroy the context and its variables
  // removing each parameter is not necessary
  // cause it will be done by DeleteLastContext()
  Vars.DeleteLastContext();

  // Restore position and filename
  yyiplineno = previous_lineno;
  this->current_file = previous_filename;

}

//------------------------------------------------------
bool Driver::parse_script(  const char* filename)
//   --------------------
{

  string  fullname;
  string tmp_string;

  cout << "yyip_switch_to_file(" << filename << ")" << endl;

  // Looking for the filename
  wxFileName currentname(GetwxStr(filename));
  wxFileName newname(GetwxStr(filename));

  if (!currentname.IsOk()) {
    tmp_string = (format("Problem with the filename %s\n") 
               % currentname.GetFullPath().c_str()).str();
    err_print(tmp_string.c_str());
    return 0;
  }

  // could check first if there is another extension ...
  currentname.SetExt(_T("amil"));

  //cout << "current wd = "  <<  wxGetCwd() << endl; 
  if (!currentname.DirExists(currentname.GetPath())) 
  {
    // try with current directory
    newname.Assign(
            wxGetCwd() 
            +
            currentname.GetPathSeparator()
            +
            currentname.GetPath(),
            currentname.GetName(),_T("amil"));
  }

  if (!newname.IsFileReadable()) 
  {
    // try with AMI_SCRIPTS environment variable
    newname.Assign(GB_scripts_dir
            +
            currentname.GetPathSeparator()
            +
            currentname.GetPath(),
            currentname.GetName(),_T("amil"));
  }

  if (!newname.IsFileReadable()) {
   string mess =  (format("Error in reading %s \n") % currentname.GetFullPath().c_str()).str();
   wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),GetwxStr("Error"),wxOK | wxICON_ERROR);
   err_msg->ShowModal();
   return 0;
  }

/*
  cout << "current name " << newname.GetFullPath() << endl;
  yyipin=fopen(newname.GetFullPath().mb_str(),"r");
  if (!yyipin) {
    string mess =  (format("Error in reading %s \n") % newname.GetFullPath().c_str()).str();
    wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),wxT("Error"),wxOK | wxICON_ERROR);
    err_msg->ShowModal();
    return 0;
  }

*/

  bool res = parse_file(string(newname.GetFullPath().mb_str()));
  //cout << "current wd = "  <<  wxGetCwd() << endl; 
  return res;

} // Driver::parse_script()






//-------------------------------------------------
void Driver::yyiperror(const char *s) 
//           ---------
{
  string tmpstr;
  if (yyiplineno) {
    tmpstr = str(format("%s:%d\t %s \n\t ==> at '%s'  \n")
      %this->current_file.c_str()
      %this->yyiplineno
      %s
      %this->lexer->YYText()
    );
    err_print(tmpstr.c_str());
  } else {
    tmpstr = str(format("%s \n")%s);
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
    cerr << "Error in opening " << filename << endl;

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
void Driver::err_print(const char* st) 
//   -----------------
{
  *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString::FromAscii(st);
  string mess =  (format("Error %s \n") % st).str();
  wxMessageDialog* err_msg = new wxMessageDialog(NULL,GetwxStr(mess),GetwxStr("Error"),wxOK | wxICON_ERROR);
  err_msg->ShowModal();
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
  *(GB_main_wxFrame->GetConsole()->GetLog()) << wxString::FromAscii(st);
  printf(st);
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
  int res,isdir;
  int  i;

  if (GB_nofile) return;

  // write in a local directory called .improcess
  // check if directory .improcess exists, otherwise create it
  dirname = ".improcess";
  res=stat(dirname.c_str(),&file_stat);
  #ifndef S_ISDIR
    #define S_ISDIR(a) (a & _S_IFDIR)
  #endif
  isdir=S_ISDIR(file_stat.st_mode);
  if (!isdir)
    std::system("mkdir .improcess");

  i = 0;
  format ws_filename_format(".improcess/cmdhistory%03d");
  filename = str( ws_filename_format % i);
#ifndef F_OK
#define F_OK 0
#endif
  TantQue access( filename.c_str(), F_OK) == 0 Faire
    i++;
    filename = str( ws_filename_format % i);
  FinTantQue

  cout << format("Opening %1% \n") % filename;
  cmdhistory=FILE_ptr(fopen(filename.c_str(),"w"),file_deleter());

  // change properties to allow execution
  #ifndef WIN32
  chmod(filename.c_str(),S_IRUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
  #endif

  if (!cmdhistory) {
    cerr << format("Error in opening %s\n") % filename;
    FILE_ptr stdout_ptr = FILE_ptr(stdout);
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

