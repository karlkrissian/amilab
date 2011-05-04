/*
 * AMILab
 *
 */

//-------------------------------------------------

// configuration information, including version number ..
#include "AMILabConfig.h"

#include "MainFrame.h"
#include <wx/stdpaths.h>
#include <wx/dir.h>

#include "CoutwxString.h"

#include "DessinImage.hpp"
#include "fonctions.h"
#include "math1.hpp"
//#include "myscan.h"
#include "Erreurs.hpp"
#include <iostream>

#include <sys/stat.h>
#ifndef WIN32
#include <unistd.h>
#endif

#include "VarContexts.hpp"

#ifndef _WITHOUT_VTK_
#include "vtkMultiThreader.h"
#endif

#include "token_list.h"
#include "amilab_messages.h"

#ifdef __APPLE__
  #include <ApplicationServices/ApplicationServices.h>
//  #include "amilab_logo_new_32x32_alpha.xpm"
#endif

#if defined(WIN32) 
  #include "guicon.h"
//  #include "amilab_logo_new_32x32_alpha.xpm"
#endif
#include "amilab_logo_new_32x32_alpha.xpm"

#include "driver.h"

#include <wx/apptrait.h>
#include <wx/stdpaths.h>
#include "wrap_imports.h"

#include <wx/config.h>

Pile<NomMethode*> GB_pile_nom_methode((NomMethode*)NULL);
unsigned char GB_AfficheWarning = false;
unsigned char GB_AfficheErreur  = false;

//XtAppContext  GB_contexte;
unsigned char       GB_debug;
unsigned char       GB_debug_opengl;
unsigned char       GB_verbose;
unsigned char       GB_nofile;


yyip::Driver  GB_driver;
VarContexts   Vars;

MainFrame*    GB_main_wxFrame;
wxApp*        GB_wxApp;
wxConfig*     GB_Config;

wxString        GB_help_dir;
wxString        GB_scripts_dir;

unsigned char DELETE_IDRAW;

extern VarContexts  Vars;


int        GB_argc;
wxChar**   GB_argv;
int        GB_num_arg_parsed;

char program[80];
unsigned char verbose;

#include "xmtext.hpp"


DessinImage* CreateIDraw( const std::string& title, InrImage::ptr image)
{
  if (GB_debug)
    fprintf(stderr,"CreateIDraw(%s, image) \n", title.c_str());

    DessinParam::ptr parametres;

    DessinImage* di = new DessinImage(
            GB_main_wxFrame,
            title,
            image,
            parametres,
            400,400,
            CREATE_TOPLEVEL_SHELL);

  return di;

}


//-------------------------------------------
void CB_ParamWin(void* cd)
{
  AMIFunction* func_ptr = (AMIFunction*) (cd);
  //cout << "CB_ParamWin pointer is " << func_ptr << std::endl;
  GB_driver.yyip_call_function(func_ptr);
} // CB_ParamWin( void* cd )


//-------------------------------------------
void CallAmiFunction(AMIFunction* f, const ParamList::ptr& p)
{
  //cout << "CB_ParamWin pointer is " << func_ptr << std::endl;
  GB_driver.yyip_call_function(f,p);
} // CB_ParamWin( void* cd )


//-----------------------------------------
void CB_delete_variable( void* var)
{
  BasicVariable* vartodelete = (BasicVariable*) var;

  FILE_MESSAGE((boost::format("deleting %1%") % vartodelete->Name()).str().c_str());
  if (!Vars.deleteVar(vartodelete))
    FILE_ERROR("Could not delete variable "); 

}

//-----------------------------------------
void CB_delete_varlist( void* var)
{
  if (!var) return;

  std::list<BasicVariable::wptr>* varlist = (std::list<BasicVariable::wptr>*) var;

  if (varlist) {
    // iterate over the list
    std::list<BasicVariable::wptr>::iterator it;
    for(it=varlist->begin(); it!=varlist->end(); it++) {
      BasicVariable::wptr vartodelete = *it;
      if (BasicVariable::ptr lockedvar = vartodelete.lock()) 
      {
        bool deleted=false;
        FILE_MESSAGE((boost::format("Pointer counter = %1%") % lockedvar->GetPtrCounter()).str().c_str());
        std::string name = lockedvar->Name();
        FILE_MESSAGE((boost::format("deleting %1%") % name).str().c_str());
        Variables::ptr context = lockedvar->GetContext();

        // free lock first
        lockedvar.reset();
        if (context.get()) {
          deleted = context->deleteVar(name.c_str());
        }
        if (!deleted)
          FILE_ERROR((boost::format("Could not delete variable %1%") % name).str().c_str()); 
      }
    }

    // should be safe to delete varlist if the window is now closed!!!
    delete varlist;
  }
}

//----------------------------------------------------------------------
// wxWidget specific ...
//
class MyApp: public wxApp
//    -----
{
  virtual bool OnInitGui();
  virtual bool OnInit();
  virtual int  OnExit();

  void OnChar(wxKeyEvent& event)
  {
    //std::cout << "MyApp::OnChar()" << std::endl;
    switch( event.GetKeyCode() )
    {
    case 'h': 
      if (event.ControlDown()) {
        std::cout << "should hide window" << std::endl;
      }
      else
        event.Skip();
    break;
    case 'i': 
      if (event.AltDown()) {
        std::cout << "should iconize window" << std::endl;
        GB_main_wxFrame->Iconize(!GB_main_wxFrame->IsIconized());
      }
      else
        event.Skip();
    break;
    default:
        event.Skip();
        return;
    }
  }


  wxConfig* GetConfig() { return config; }

private:
  //MainFrame::ptr mainframe;
  MainFrame* mainframe;

  // Global configuration file
  wxConfig * config;

private:
  DECLARE_EVENT_TABLE();
};


BEGIN_EVENT_TABLE(MyApp, wxApp)
    EVT_CHAR        ( MyApp::OnChar       )
END_EVENT_TABLE();


IMPLEMENT_APP(MyApp)


// rewrite it to set the colors
// wxwidget was recompiled ...
// send email to wxwidgets to propose modification?
bool MyApp::OnInitGui()
{
  SetClassName(GetwxStr("amilab"));
  return wxApp::OnInitGui();

}


//-----------------------------------------
bool CheckEnvDir(const wxString& envname, wxString& res, const wxString& lookforfile = wxEmptyString)
{

  // Looking for the environment variable
  bool foundenv = wxGetEnv(envname,&res);
  if (!foundenv) {
    std::cerr << "Environment variable " << envname << " not defined. " << std::endl;
  } else
  if (!wxDir::Exists(res)) {
    std::cerr << "Error accessing directory " << res.mb_str();
  } else
    return true;

  // First check relative to the executable path
  wxFileName execpath(wxStandardPaths::Get().GetExecutablePath());
  // if last directory is bin, remove it
  wxString LastDir = execpath.GetDirs().Last();
  if (LastDir.MakeUpper()==wxT("BIN")) {
      execpath.RemoveLastDir();
      execpath.AppendDir(_T("share"));
      execpath.AppendDir(GetwxStr("amilab-")+GetwxStr(AMILAB_VERSION));
  }
  res = execpath.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
 std::cout  << "looking for the file " << lookforfile.mb_str() << " in " << res.mb_str() << std::endl;
  wxDir directory(res);
  if (lookforfile != wxEmptyString) {
    wxString path = directory.FindFirst(res,lookforfile);
    if (path!=wxEmptyString) {
        res = wxFileName(path).GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
        return true;
    }
  }


  std::cerr << "file not found, set the path manually from the interface." << std::endl;

  res=::wxGetCwd();
  std::cerr << " , set to " << res << std::endl
        << "check the environment variable " << envname.mb_str() << std::endl;
  return false;

  // look  for the file needed
  /*
 std::cout  << "looking for the file " << lookforfile.mb_str() << " in " << res.mb_str() << std::endl;
  wxDir directory(res);
  if (lookforfile != wxEmptyString) {
    wxString path = directory.FindFirst(res,lookforfile);
    if (path!=wxEmptyString)
        res = wxFileName(path).GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
    else {
    */
  /*
    }
  }
  */


}



//-----------------------------------------
bool MyApp::OnInit()
{

  config = new wxConfig(wxT("AMILab"));
/*
                        wxEmptyString,
                        wxEmptyString,
                        wxCONFIG_USE_SUBDIR);
*/
  GB_Config = config;

#ifdef __APPLE__
  ProcessSerialNumber PSN;
  GetCurrentProcess(&PSN);
  TransformProcessType(&PSN,kProcessTransformToForegroundApplication);
#endif

#ifdef WIN32
  RedirectIOToConsole();
#endif

/*    if ( !wxApp::OnInit() )
    return false;
*/

 // this was  main()
  int  n;
  bool no_interaction = false;
  bool hide_mainframe = false;
  std::string cmd_line;

  GB_debug = false;
  GB_debug_opengl = false;
  GB_nofile = false;

  GB_argc  = argc;
  GB_argv  = argv;

  // print the command line as a comment in the cmdhistory
  //  if (argv[0][0]!='/') {
    cmd_line = "#!";
    cmd_line += (const char*) wxStandardPaths::Get().GetExecutablePath().mb_str();
    cmd_line += " ";
/*  }
  else
    cmd_line = "#!";
*/
  for(n=1;n<argc;n++)
    {
      cmd_line += wxString(argv[n]).mb_str(wxConvUTF8);
      cmd_line += " ";
    }
  cmd_line += "\n";

  std::cout << argc << std::endl;
  std::cout << cmd_line << std::endl;

  GB_num_arg_parsed = 1;
  Si  argc>GB_num_arg_parsed Et
      strcmp(wxString(argv[GB_num_arg_parsed]).mb_str(wxConvUTF8),"-debug")==0
  Alors
   std::cout << "Debug On" << std::endl;
    GB_debug = true;
    GB_num_arg_parsed++;
  FinSi

  Si  argc>GB_num_arg_parsed Et
      strcmp(wxString(argv[GB_num_arg_parsed]).mb_str(wxConvUTF8),"-hide")==0
  Alors
    hide_mainframe = true;
    GB_num_arg_parsed++;
  FinSi

  Si  argc>GB_num_arg_parsed Et
      strcmp(wxString(argv[GB_num_arg_parsed]).mb_str(wxConvUTF8),"-nofile")==0
  Alors
    GB_nofile = true;
    //printf("no file \n");
    GB_num_arg_parsed++;
  FinSi

  Si  argc>GB_num_arg_parsed Et
      strcmp(wxString(argv[GB_num_arg_parsed]).mb_str(wxConvUTF8),"-quit")==0
  Alors
   std::cout << "Quit without console interation" << std::endl;
    no_interaction = true;
    GB_num_arg_parsed++;
  FinSi

  // Get environment variables
  CheckEnvDir( _T("AMI_HELP"),    GB_help_dir,    _T("tokens.html"));
  CheckEnvDir( _T("AMI_SCRIPTS"), GB_scripts_dir, _T("scripts.amil"));

 std::cout << "GB_help_dir = " << GB_help_dir.mb_str() << std::endl;
 std::cout << "GB_scripts_dir = " << GB_scripts_dir.mb_str() << std::endl;


  GB_driver.ws_print(cmd_line.c_str());



//  printf("MyApp::OnInit()\n");
//  wxFont::SetDefaultEncoding(wxFONTENCODING_ISO8859_15);
//  GB_contexte  = (XtAppContext) this->GetAppContext();
  GB_wxApp = this;

  mainframe = new MainFrame(
                GetwxStr("AMILab ")+GetwxStr(AMILAB_VERSION),
//                _T("AMILab: Image Processing and Visualization"),
                wxDefaultPosition,
                wxSize(900,700));

//  #if defined(WIN32) || defined(__APPLE__)
    mainframe->SetIcon(wxIcon(amilab_logo_new_32x32_alpha_xpm));
//  #endif

//  printf("frame->Show(true)\n");


//  printf("application name = \"%s\" \n",wxGetApp().GetClassName().c_str());
  // TODO: avoid using get() here ...
  GB_main_wxFrame = mainframe;


  // Add imports language, needs to do it after initialization of MainFrame
  AddWrapImports();

  ::wxInitAllImageHandlers();

  mainframe->Show(!hide_mainframe);
  SetTopWindow(mainframe);
//  frame->Fit();
//  frame->Show(true);
//  frame->Update();

  //GB_driver.trace_parsing=true;
  //GB_driver.trace_scanning=true;

  if (GB_main_wxFrame->GetConsole().get()) {
    GB_main_wxFrame->GetConsole()->AddPrompt(false);
    GB_driver.yyiplineno=1;
    GB_driver.current_file="Command line prompt";

    // check for existence of config file
    // 1. in current directory
    wxString homedir = ::wxGetUserHome();
    wxFileName amilab_config;
    amilab_config.AssignCwd();
    amilab_config.SetFullName(wxT("config.amil"));

    if (!amilab_config.FileExists()) {
      // 2. in binary directory
      amilab_config = wxStandardPaths::Get().GetExecutablePath();
      amilab_config.SetFullName(wxT("config.amil"));
    }
    
    // 3. in user home directory ~/.amilab/config.amil
    if (!amilab_config.FileExists()) {
      amilab_config.AssignHomeDir();
      amilab_config.AppendDir(wxT(".amilab"));
      amilab_config.SetFullName(wxT("config.amil"));
    }

    if (amilab_config.FileExists())
      try {
          GB_driver.parse_file(string(amilab_config.GetFullPath().mb_str(wxConvUTF8)));
          GB_main_wxFrame->GetConsole()->ProcessReturn();
      }
      catch (char * str ) {
          std::cerr << "Error catched ! " << str << std::endl;
      }

    // check for existence of Menus for scripts
    wxFileName amilab_menuscripts;
    amilab_menuscripts.AssignDir(GB_scripts_dir);
    amilab_menuscripts.SetFullName(wxT("Add2Menu.amil"));

    if (amilab_menuscripts.FileExists())
    try {
        GB_driver.parse_file(string(amilab_menuscripts.GetFullPath().mb_str(wxConvUTF8)));
        GB_main_wxFrame->GetConsole()->ProcessReturn();
    }
    catch (char * str ) {
        std::cerr << "Error catched ! " << str << std::endl;
    }

    Si argc>GB_num_arg_parsed  Alors
      try {
        wxString input_file(argv[GB_num_arg_parsed]);
        GB_num_arg_parsed++;

        // run the file
        /*
        GB_driver.yyip_switch_to_file(input_file.mb_str(wxConvUTF8));
        GB_driver.yyip_parse();
        GB_driver.yyip_popup_buffer();
        */
        // Use parse_script instead of parse_file to allow looking in the scripts directory
        GB_driver.parse_script(string(input_file.mb_str(wxConvUTF8)).c_str());
        if (GB_main_wxFrame)
        {
          if (no_interaction)
            GB_main_wxFrame->Close(true);
          else
            GB_main_wxFrame->GetConsole()->ProcessReturn();
        }
      } catch (char * str ) {
        std::cerr << "Error catched ! " << str << std::endl;
      }
    FinSi
    #ifdef __UNICODE__
     std::cout << "USING UNICODE ..." << std::endl;
    #endif
  }



  return true;

}

int MyApp::OnExit()
{
 // mainframe->Close();
  delete config;
  Vars.EmptyVariables();
 std::cout << "MyApp::OnExit()" << std::endl;
  return 0;
}


//----------------------------------------------------------------------
// main
//
// needs to define the global variables:
//  GB_contexte, GB_app_shell
//

#ifdef _MSC_VER // I don't know why it is needed on windows ...
int main(int argc, char **argv)
{

} // main()
#endif
