/*
 * AMILab
 *
 */

//-------------------------------------------------

#include "MainFrame.h"
#include <wx/stdpaths.h>
#include <wx/dir.h>


#include "DessinImage.hpp"
#include "fonctions.h"
#include "math1.hpp"
#include "myscan.h"
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
#endif

#include "amilab_logo_new_16x16.xpm"

#ifdef WIN32
#include "guicon.h"
#endif

Pile<NomMethode*> GB_pile_nom_methode((NomMethode*)NULL);
unsigned char GB_AfficheWarning = false;
unsigned char GB_AfficheErreur  = false;

//XtAppContext  GB_contexte;
unsigned char       GB_debug;
unsigned char       GB_verbose;
unsigned char       GB_nofile;


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

 void init_gr_output();
 void gr_print(const char* st);
// void close_gr_output();

 void init_err_output();
 void err_print(char* st);
// void close_err_output();

 void init_res_output();
 void res_print(char* st);
// void close_res_output();

 void init_cmdhistory();
 void ws_print(const char* st);
// void close_cmdhistory();


#include "xmtext.hpp"



DessinImage* CreateIDraw(  std::string GetwxStritle, InrImage::ptr image)
{
  if (GB_debug)
    fprintf(stderr,"CreateIDraw(%s, image) \n", GetwxStritle.c_str());

    DessinParam::ptr parametres;

    DessinImage* di = new DessinImage(
            GB_main_wxFrame,
            GetwxStritle,
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
};


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
  bool foundenv = wxGetEnv(envname,&res);
  if (!foundenv) {
    cerr << "Environment variable " << envname << " not defined. " << endl;

  }

  if (!wxDir::Exists(res)) {
    cerr << "Error accessing directory " << res;
    res=::wxGetCwd();
    cerr << " , set to " << res << endl
         << "check the environment variable " << envname << endl;
  }
// else {
      // look recursively for the file needed
      cout  << "looking for the file " << lookforfile << " in " << res << endl;
      wxDir directory(res);
      if (lookforfile != wxEmptyString) {
        wxString path = directory.FindFirst(res,lookforfile);
        if (path!=wxEmptyString)
            res = wxFileName(path).GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
        else {
          wxFileName execpath(wxStandardPaths::Get().GetExecutablePath());
          // if last directory is bin, remove it
          if (execpath.GetDirs().Last().MakeUpper()==wxT("BIN"))
              execpath.RemoveLastDir();
          res = execpath.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
          cout  << "looking for the file " << lookforfile << " in " << res << endl;
          wxDir directory(res);
          if (lookforfile != wxEmptyString) {
            wxString path = directory.FindFirst(res,lookforfile);
            if (path!=wxEmptyString)
                res = wxFileName(path).GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
            else 
              cerr << "file not found." << endl;
          }
        }
      }


//  }
  return foundenv;
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
  Chaine cmd_line;

  GB_nofile = false;

  GB_argc  = argc;
  GB_argv  = argv;

  // print the command line as a comment in the cmdhistory
  // TODO: check for binary path and command line before adding /usr/bin
  if (argv[0][0]!='/')
    cmd_line = "#!/usr/bin/";
  else
    cmd_line = "";
  for(n=0;n<argc;n++)
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

  cout << "GB_help_dir = " << GB_help_dir << endl;
  cout << "GB_scripts_dir = " << GB_scripts_dir << endl;

  init_gr_output();
  init_err_output();
  init_res_output();
  init_cmdhistory();

  ws_print(cmd_line);


//  printf("MyApp::OnInit()\n");
//  wxFont::SetDefaultEncoding(wxFONTENCODING_ISO8859_15);
//  GB_contexte  = (XtAppContext) this->GetAppContext();
  GB_wxApp = this;

  MainFrame *frame = new MainFrame(
                GetwxStr("AMILab: Image Processing and Visualization"),
                wxDefaultPosition,
                wxSize(900,700));

  frame->SetIcon(wxIcon(amilab_logo_new_16x16_xpm));

//  printf("frame->Show(true)\n");


//  printf("application name = \"%s\" \n",wxGetApp().GetClassName().c_str());
  GB_main_wxFrame = frame;

  frame->Show(true);
  SetTopWindow(frame);
//  frame->Fit();
//  frame->Show(true);
//  frame->Update();

  if (GB_main_wxFrame->GetConsole()!=NULL) {
    GB_main_wxFrame->GetConsole()->AddPrompt(false);
    yyiplineno=1;
    GB_current_file="Command line prompt";

    Si argc>GB_num_arg_parsed  Alors
      try {
        // run the file
        yyip_switch_to_file(wxString(argv[GB_num_arg_parsed]).mb_str(wxConvUTF8));
        GB_num_arg_parsed++;
        yyip_parse();
        yyip_popup_buffer();
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
