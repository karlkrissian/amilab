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

#include "wrap_imports.h"

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

wxString        GB_help_dir;
wxString        GB_scripts_dir;

unsigned char DELETE_IDRAW;

extern VarContexts  Vars;

#include "xmtext.hpp"
extern TextControl* TC;

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
    //std::cout << "MyApp::OnChar()" << endl;
    switch( event.GetKeyCode() )
    {
    case 'h': 
      if (event.ControlDown()) {
        std::cout << "should hide window" << endl;
      }
      else
        event.Skip();
    break;
    case 'i': 
      if (event.AltDown()) {
        std::cout << "should iconize window" << endl;
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

private:
  //MainFrame::ptr mainframe;
  MainFrame* mainframe;

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
    cerr << "Environment variable " << envname << " not defined. " << endl;
  } else
  if (!wxDir::Exists(res)) {
    cerr << "Error accessing directory " << res.mb_str();
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
  cout  << "looking for the file " << lookforfile.mb_str() << " in " << res.mb_str() << endl;
  wxDir directory(res);
  if (lookforfile != wxEmptyString) {
    wxString path = directory.FindFirst(res,lookforfile);
    if (path!=wxEmptyString) {
        res = wxFileName(path).GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
        return true;
    }
  }


  cerr << "file not found, set the path manually from the interface." << endl;

  res=::wxGetCwd();
  cerr << " , set to " << res << endl
        << "check the environment variable " << envname.mb_str() << endl;
  return false;

  // look  for the file needed
  /*
  cout  << "looking for the file " << lookforfile.mb_str() << " in " << res.mb_str() << endl;
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

  cout << argc << endl;
  cout << cmd_line << endl;

  GB_num_arg_parsed = 1;
  Si  argc>GB_num_arg_parsed Et
      strcmp(wxString(argv[GB_num_arg_parsed]).mb_str(wxConvUTF8),"-debug")==0
  Alors
    cout << "Debug On" << endl;
    GB_debug = true;
    GB_num_arg_parsed++;
  FinSi

  Si  argc>GB_num_arg_parsed Et
      strcmp(wxString(argv[GB_num_arg_parsed]).mb_str(wxConvUTF8),"-nofile")==0
  Alors
    GB_nofile = true;
    //printf("no file \n");
    GB_num_arg_parsed++;
  FinSi

  // Get environment variables
  CheckEnvDir( _T("AMI_HELP"),    GB_help_dir,    _T("tokens.html"));
  CheckEnvDir( _T("AMI_SCRIPTS"), GB_scripts_dir, _T("scripts.amil"));

  cout << "GB_help_dir = " << GB_help_dir.mb_str() << endl;
  cout << "GB_scripts_dir = " << GB_scripts_dir.mb_str() << endl;


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

  mainframe->Show(true);
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
    wxString homedir = ::wxGetUserHome();
    wxFileName amilab_config;
    amilab_config.AssignHomeDir();
    amilab_config.AppendDir(wxT(".amilab"));
    amilab_config.SetFullName(wxT("config.amil"));

    if (amilab_config.FileExists())
    try {
        GB_driver.parse_file(string(amilab_config.GetFullPath().mb_str(wxConvUTF8)));
        GB_main_wxFrame->GetConsole()->ProcessReturn();
    }
    catch (char * str ) {
        cerr << "Error catched ! " << str << endl;
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
        cerr << "Error catched ! " << str << endl;
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
        GB_driver.parse_file(string(input_file.mb_str(wxConvUTF8)));
        GB_main_wxFrame->GetConsole()->ProcessReturn();

      } catch (char * str ) {
        cerr << "Error catched ! " << str << endl;
      }
    FinSi
    #ifdef __UNICODE__
      cout << "USING UNICODE ..." << endl;
    #endif
  }



  return true;

}

int MyApp::OnExit()
{
  cout << "MyApp::OnExit()" << endl;
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
