/*
 * AMILab
 *
 */

//-------------------------------------------------


#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include "wx/app.h"

#include "wx/bmpbuttn.h"


#include "wx/toolbar.h"
#include "wxParamTypes.hpp"
#include "MyToolBar.h"
#include <wx/msgdlg.h>
#include <wx/bmpcbox.h>

#include <sys/stat.h>
#ifndef WIN32
#include <unistd.h>
#endif



#ifdef __APPLE__
#include <ApplicationServices/ApplicationServices.h>
#endif

#include <iostream>
using namespace std;


// include pixmaps
#include "loadvrml.xpm"
#include "savevrml.xpm"
#include "center_normalize.xpm"
#include "proj_ortho.xpm"
#include "proj_persp.xpm"
#include "fog.xpm"
#include "nofog.xpm"
#include "light.xpm"
#include "nolight.xpm"
#include "nobb.xpm"
#include "bb.xpm"
#include "gl_point.xpm"
#include "gl_line.xpm"
#include "gl_fill.xpm"

// Toolbar buttons
enum {
    wx_toolbar_id = 2000,
    wxID_TB_LoadPoly = 1000,
    wxID_TB_SavePoly,
    wxID_TB_CenterNormalize,
    wxID_TB_Projection,
    wxID_TB_Fog,
    wxID_TB_NoFog,
    wxID_TB_BB,
    wxID_TB_NoBB,
    wxID_TB_GLmode_Point,
    wxID_TB_GLmode_Line,
    wxID_TB_GLmode_Fill,
    wxID_TB_COMBO,
};

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

//----------------------------------------------------------------
/*!
  \brief MainFrame: the main window of AMILab
*/
class MainFrame: public wxFrame
//    ---------
{
public:
  MainFrame ( const wxString& title, const wxPoint& pos,
              const wxSize& size );

  ~MainFrame() {
  }

  static void CB_redessine           (void* cd)
  {
    wxMessageBox(_T("CB_redessine\n"));
  }

  static void CB_proj           (void* cd)
  {
    wxMessageBox(_T("CB_proj\n"));
  }

  int proj_id;
  int type_proj;

protected:

private:
  virtual wxToolBar* OnCreateToolBar(long style,
        wxWindowID id, const wxString& name);


  DECLARE_EVENT_TABLE();

}; // MainFrame




// rewrite it to set the colors
// wxwidget was recompiled ...
// send email to wxwidgets to propose modification?
bool MyApp::OnInitGui()
{
  SetClassName("test_toolbar");
  return wxApp::OnInitGui();

}



//-----------------------------------------
bool MyApp::OnInit()
{

#ifdef __APPLE__
  ProcessSerialNumber PSN;
  GetCurrentProcess(&PSN);
  TransformProcessType(&PSN,kProcessTransformToForegroundApplication);
#endif

/*    if ( !wxApp::OnInit() )
        return false;
*/


  MainFrame *frame = new MainFrame(
                "test_toolbar",
                wxDefaultPosition,
                wxSize(900,700));


  frame->Show(true);
  SetTopWindow(frame);


  return true;

}

int MyApp::OnExit()
{
  cout << "MyApp::OnExit()" << endl;
  return 0;
}

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
END_EVENT_TABLE()

//-------------------------------------------------------
MainFrame::MainFrame( const wxString& title,
                  const wxPoint& pos,
                  const wxSize& size
                )
                : wxFrame((wxFrame *)NULL,
                  wxID_ANY,
                  title,
                  pos,
                  size)
{

  type_proj = 0;

  MyToolBar* toolBar = (MyToolBar*) this->CreateToolBar();
  toolBar->SetToolBitmapSize(wxSize(30,30));
  toolBar->SetToolSeparation(0);
  toolBar->SetMargins(0,0);

  toolBar->AddTool(wxID_TB_LoadPoly,
      _T("Load PolyData"),
      wxBitmap(loadvrml_string),
      _T("Load PolyData"));

  toolBar->AddTool(wxID_TB_SavePoly,
      _T("Save PolyData"),
      wxBitmap(savevrml_string),
      _T("Save PolyData"));

  toolBar->AddTool(wxID_TB_CenterNormalize,
      _T("Center Normalize"),
      wxBitmap(center_normalize_string),
      _T("Center+Normalize (use 'Shift' to popup param.)"));

//#ifndef WIN32
  proj_id = toolBar->AddEnum( &this->type_proj,
                              _T("Projection"),
                              _T("Projection type [Ortho|Persp] \n Right click --> parameters"),
                              (void*) MainFrame::CB_redessine,
                              (void*) this);
  toolBar->AddEnumChoice( proj_id, wxID_TB_Projection, 0,
                          wxBitmap(proj_ortho_string),"orth");
  toolBar->AddEnumChoice( proj_id, wxID_TB_Projection, 1,
                          wxBitmap(proj_persp_string),"pers");

//  toolBar->RemoveTool(wxID_TB_ProjectionOrtho);

  toolBar->AddRightClick(   proj_id,
                            (void*) MainFrame::CB_proj,
                            (void*) this);

  toolBar->Update(proj_id);

/*
#else
  toolBar->AddTool(wxID_TB_ProjectionOrtho,
       _T("Projection"),
      wxBitmap(proj_ortho_string),
      _T("Projection type [Ortho|Persp] \n Right click --> parameters"));

  toolBar->AddTool(wxID_TB_ProjectionPersp,
       _T("Projection"),
      wxBitmap(proj_persp_string),
      _T("Projection type [Ortho|Persp] \n Right click --> parameters"));

#endif
*/

/*
  wxBitmapComboBox *combo = new wxBitmapComboBox(toolBar, wxID_TB_COMBO, wxEmptyString, wxDefaultPosition, wxSize(100,-1) ,0,NULL, wxCB_READONLY  );
  combo->Append(_T("orth"),wxBitmap(proj_ortho_string));
  combo->Append(_T("pers"),wxBitmap(proj_persp_string));
  combo->Select(0);
  combo->SetToolTip(_T("Projection type [Ortho|Persp] \n Right click --> parameters"));

*/


  toolBar->Realize();



}


//------------------------------------------------
wxToolBar* MainFrame::OnCreateToolBar(long style,
      wxWindowID id, const wxString& name)
{
  return new MyToolBar(this,wx_toolbar_id,
          wxDefaultPosition,
          wxDefaultSize,
          wxTB_HORIZONTAL | wxNO_BORDER,
          _T("MyToolBar"));
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
