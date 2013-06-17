/*
 * AMILab
 *
 */

//-------------------------------------------------
#include <wx/splash.h>
#include "amilab_splash.xpm"

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


#include "common_global_import.h"
#include "amilab_global_import.h"

//XtAppContext  GB_contexte;


#include "LanguageConfigure.h"
Language_VAR_IMPORT yyip::Driver  GB_driver;

#include "DriverBase.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT DriverBase::ptr  GB_DriverBase;

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;


unsigned char DELETE_IDRAW;

#include "amilab_global_import.h"

char program[80];

//COMMON_EXPORT unsigned char GB_verbose;

#include "xmtext.hpp"
/*
#include <boost/format/format_implementation.hpp>
boost::format test;*/

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


//-------------------------------------------

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


void CB_ParamWin(void* cd)
{
  AMIFunction* func_ptr = (AMIFunction*) (cd);
  //cout << "CB_ParamWin pointer is " << func_ptr << std::endl;
  GB_driver.yyip_call_function(func_ptr);
} // CB_ParamWin( void* cd )





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


  //wxConfig* GetConfig() { return config; }

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
bool MyApp::OnInit()
{
  // Initialize GB_DriverBase
  GB_DriverBase = DriverBase::ptr(&GB_driver,smartpointer_nodeleter<DriverBase>());

 ::wxInitAllImageHandlers();

  // here need a smart pointer !!!
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
  bool noscriptsmenu = false;
  std::string cmd_line;

  GB_debug = false;
  GB_debug_opengl = false;
  GB_nofile = false;

  GB_argc  = argc;
  GB_argv  = argv;
  GB_cmdline = "";

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

  
  std::cout << "Number of arguments: "<< argc << std::endl;
  std::cout << "Command line: "<< cmd_line << std::endl;

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
      strcmp(wxString(argv[GB_num_arg_parsed]).mb_str(wxConvUTF8),"-noscriptsmenu")==0
  Alors
    noscriptsmenu = true;
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

  if (!hide_mainframe) {
    //wxBitmap bitmap;
    wxBitmap bitmap(amilab_splash_xpm );
    if (bitmap.IsOk())
    {
    wxSplashScreen *splash;
    splash = new wxSplashScreen(bitmap,
        wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
        1500, NULL, -1, wxDefaultPosition, wxDefaultSize,
        wxSIMPLE_BORDER|wxSTAY_ON_TOP);
    }
    wxYield();
  }


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

  int screen_size_x = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
  int screen_size_y = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);

  mainframe = new MainFrame(
                GetwxStr("AMILab ")+GetwxStr(AMILAB_VERSION),
//                _T("AMILab: Image Processing and Visualization"),
                wxDefaultPosition,
                // 80% of screen size?
                wxSize(screen_size_x*0.85,screen_size_y*0.85));

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
    

    if (amilab_config.FileExists())
      try {
          GB_driver.parse_file(string(amilab_config.GetFullPath().mb_str(wxConvUTF8)));
          //GB_main_wxFrame->GetConsole()->ProcessReturn();
      }
      catch (char * str ) {
          std::cerr << "Error catched ! " << str << std::endl;
      }

    // also run the config.amil here
    // 3. in user home directory ~/.amilab/config.amil
    //if (!amilab_config.FileExists()) {

    //amilab_config.AssignHomeDir();
    //amilab_config.AppendDir(wxT(".amilab"));
    amilab_config.AssignDir(wxStandardPaths::Get().GetUserLocalDataDir());
    
    amilab_config.SetFullName(wxT("config.amil"));
    if (amilab_config.FileExists())
      try {
          GB_driver.parse_file(string(amilab_config.GetFullPath().mb_str(wxConvUTF8)));
          //GB_main_wxFrame->GetConsole()->ProcessReturn();
      }
      catch (char * str ) {
          std::cerr << "Error catched ! " << str << std::endl;
      }
    //}

    // check for existence of Menus for scripts
    wxFileName amilab_menuscripts;
    amilab_menuscripts.AssignDir(GB_scripts_dir);
    amilab_menuscripts.SetFullName(wxT("Add2Menu.amil"));

    if (amilab_menuscripts.FileExists()&&(!noscriptsmenu))
    try {
        GB_driver.parse_file(string(amilab_menuscripts.GetFullPath().mb_str(wxConvUTF8)));
        //GB_main_wxFrame->GetConsole()->ProcessReturn();
    }
    catch (char * str ) {
        std::cerr << "Error catched ! " << str << std::endl;
    }

    Si argc>GB_num_arg_parsed  Alors
      try {
        wxString input_file(argv[GB_num_arg_parsed]);
        GB_num_arg_parsed++;

        // Create command line arguments
        for(n=GB_num_arg_parsed;n<argc;n++)
          {
            GB_cmdline += wxString(argv[n]).mb_str(wxConvUTF8);
            GB_cmdline += " ";
          }

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

  mainframe->LoadToolBar();
  mainframe->UpdateVars();

  return true;

}

int MyApp::OnExit()
{
  std::cout << "MyApp::OnExit()" << std::endl;
  std::cout << "Emptying variables" << std::endl;
  //Vars.EmptyVariables();
  std::cout << "deleting config" << std::endl;
  delete config;
  std::cout << "returning 0" << std::endl;
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
