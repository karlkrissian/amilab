/////////////////////////////////////////////////////////////////////////////
// Name:        isosurf.cpp
// Purpose:     wxGLCanvas demo program
// Author:      Brian Paul (original gltk version), Wolfram Gloger
// Modified by: Julian Smart
// Created:     04/01/98
// RCS-ID:      $Id: isosurf.cpp,v 1.18 2005/02/26 20:03:26 JS Exp $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

extern unsigned char GB_debug;

#include "Viewer3D.hpp"
#include "MyToolBar.h"

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
#include "gl_fill_line.xpm"

/*
// Pixmaps for setting 3D view
#include "center.xpm"
#include "normalize.xpm"
#include "XY.xpm"
#include "XZ.xpm"
#include "YZ.xpm"
#include "rot_x1.xpm"
#include "rot_y1.xpm"
#include "rot_z1.xpm"
#include  "rot_x2.xpm"
#include  "rot_y2.xpm"
#include  "rot_z2.xpm"
*/

//#include "../../sample.xpm"



enum
{
  // File menu
    ID_MenuFile = 500,
    ID_MenuFile_LoadVRML,
    ID_MenuFile_Image,
    ID_MenuFile_Points,
    ID_MenuFile_SaveVRML,
    ID_MenuFile_ReLoad,
    ID_MenuFile_Close,

    // View menu
    ID_MenuView_backgroundcolor,
    ID_MenuView_material_param,
    ID_MenuView_projection_param,
    ID_MenuView_lighting_param,
    ID_MenuView_fog_param,
    ID_MenuView_vectors_param,
    ID_MenuView_lines_param,
    ID_MenuView_points_param,

    // Options menu
    ID_MenuOptions_move_object,
    ID_MenuOptions_move_base,

    ID_MenuOptions_GLPoints,
    ID_MenuOptions_GLLines,
    ID_MenuOptions_GLFill,

    ID_MenuOptions_Flat,
    ID_MenuOptions_Smooth,

    ID_MenuOption_lighting,
      ID_MenuOption_enablelighting,
    ID_MenuOption_enablecullface,
};

// Toolbar buttons
enum {
    wx_toolbar_id = 2000,
    wxID_TB_LoadPoly = 1000,
    wxID_TB_SavePoly,
    wxID_TB_CenterNormalize,
    wxID_TB_Projection,
    wxID_TB_Fog,
    wxID_TB_BB,
    wxID_TB_GLmode,
};



BEGIN_EVENT_TABLE(Viewer3D, wxFrame)

    EVT_CLOSE       (Viewer3D::OnClose)
    EVT_CHAR        (Viewer3D::OnChar)
    EVT_MOUSE_EVENTS(Viewer3D::OnMouseEvent)
//    EVT_BUTTON(Viewer3D::OnMouseEvent)
    EVT_SIZE        (Viewer3D::OnSize)

    EVT_MENU(ID_MenuFile_Close,
                  Viewer3D::CB_Close)
    EVT_MENU(ID_MenuView_backgroundcolor,
                  Viewer3D::CB_BackgroundColor)
    EVT_MENU(ID_MenuOption_enablelighting,
                  Viewer3D::ReDraw )
    EVT_MENU(ID_MenuOption_enablecullface,
                  Viewer3D::ReDraw )
    EVT_MENU(ID_MenuView_material_param,
                  Viewer3D::CB_material_visible)
    EVT_MENU(ID_MenuView_projection_param,
                  Viewer3D::CB_proj_visible)
    EVT_MENU(ID_MenuView_lighting_param,
                  Viewer3D::CB_lighting_visible)
    EVT_MENU(ID_MenuView_fog_param,
                  Viewer3D::CB_fog_visible)
    EVT_MENU(ID_MenuView_vectors_param,
                  Viewer3D::CB_vectors_visible)
    EVT_MENU(ID_MenuView_lines_param,
                  Viewer3D::CB_lines_visible)
    EVT_MENU(ID_MenuView_points_param,
                  Viewer3D::CB_points_visible)

    EVT_TOOL (wxID_TB_LoadPoly,
                        Viewer3D::CB_Ouvrir_surface)
    EVT_TOOL(wxID_TB_CenterNormalize, Viewer3D::CB_PixmapCenterNormalize)
    EVT_TOOL_RCLICKED (wxID_TB_CenterNormalize, Viewer3D::CB_ViewParam)


END_EVENT_TABLE()

// My frame constructor
Viewer3D::Viewer3D(wxFrame *frame, const wxString& title, const wxPoint& pos,
    const wxSize& size, long style)
    : wxFrame(frame, wxID_ANY, title, pos, size, style )
{
    m_canvas = NULL;
    CloseFunction = CloseData = NULL;

//    SetIcon(wxIcon(sample_xpm));
    CreateGLCanvas();
    CreateParameterWindows();
   // this->Show(true);

    // Give it an icon
    //    frame->SetIcon(wxIcon(_T("mondrian")));

    Create_wxMenu();
    Create_Toolbar();
}

Viewer3D::~Viewer3D()
{
  if (GB_debug) fprintf(stderr, "calling ~Viewer3D\n");
    //delete m_canvas;
}

//-------------------------------------------------
void Viewer3D::AddCompSurf( Viewer3D_ptr comp_surf)
//             -----------
{
    int i;

  i = 0;
  TantQue (i<MAX_COMP_SURF) Et (!_compare_surf[i].expired()) Faire
    i++;
  FinTantQue

  Si i==MAX_COMP_SURF Alors
    fprintf(stderr,"Maximal number of comparaison reached \n");
    return;
  FinSi

  _compare_surf[i] = comp_surf;


} // AddCompSurf()


//-------------------------------------------------
void Viewer3D::OnSize( wxSizeEvent& event)
//                    -----------
{

  int i;
  // Resize event
  Pour(i,0,MAX_COMP_SURF-1)
    if (!_compare_surf[i].expired()) {
      Viewer3D_ptr viewer = _compare_surf[i].lock();
      viewer->SetSize(this->GetSize());
      viewer->Paint();
    }
  FinPour

  event.Skip();
}


//-------------------------------------------------------
void Viewer3D::CompSurfPaint()
//             -------------
{
    int i;

  Pour(i,0,MAX_COMP_SURF-1)
    Si (!_compare_surf[i].expired()) Alors
      Viewer3D_ptr viewer = _compare_surf[i].lock();
      viewer->GetCanvas()->SetObjectTransform(GetCanvas()->_Tobject);
      viewer->GetCanvas()->SetFog(            GetCanvas()->_GLFogParam);
      viewer->Paint();
    FinSi
  FinPour


} // CompSurfPaint()


//--------------------------------------------------
void Viewer3D::CreateGLCanvas()
{
    // not using the attributes because of some errors
    this->m_canvas = new ami_wxGLCanvas(this, wxID_ANY, wxDefaultPosition,
        wxDefaultSize, 0, _T("ami_wxGLCanvas"));

  //  this->Show(true);
  //this->m_canvas->Show(true);
  //  this->m_canvas->SetCurrentContext();

} // CreateGLCanvas()

//-------------------------------------------------------
void Viewer3D::CreateParameterWindows()
{
  // TODO: check why the dialog cannot have the viewer as parent
  _param_view            = new Viewer3D_ViewParam       (this);
  _param_proj            = new Viewer3D_ProjParam       (this);
  _param_material        = new Viewer3D_MaterialParam   (this);
  _param_backgroundcolor = new Viewer3D_BackgroundParam (this);
  _param_light           = new Viewer3D_LightingParam   (this);
  _param_fog             = new Viewer3D_FogParam        (this);
  _param_vectors         = new Viewer3D_VectorsParam    (this);
  _param_lines           = new Viewer3D_LineParam       (this);
  _param_points          = new Viewer3D_PointParam      (this);


/*

  CreeParametresPoints();
  _param_points_visible = false;

  CreeParametresCC();
  _param_cc_visible = false;

  // Parametric Surface
  CreeParametresParamSurf();
*/

} // CreateParameterWindows()


//---------------------------------------------------------
void Viewer3D::Create_wxMenu()
{

    menuBar = new wxMenuBar;

    // Image Menu
    menuFile = new wxMenu;
    menuFile->Append( ID_MenuFile_LoadVRML,
                        GetwxStr("&Load PolyData"));
    menuFile->Append( ID_MenuFile_Image,
                        GetwxStr("&Image"));
    menuFile->Append( ID_MenuFile_Points,
                        GetwxStr("&Points") );
    menuFile->Append( ID_MenuFile_SaveVRML,
                        GetwxStr("&Save PolyData" ));
    menuFile->Append( ID_MenuFile_ReLoad,
                        GetwxStr("&ReLoad") );
    menuFile->Append( ID_MenuFile_Close,
                        GetwxStr("&Close\tF1"), GetwxStr("Close Window") );

    menuBar->Append( menuFile, GetwxStr("&File") );
    //menuBar->SetOwnBackgroundColour("GREEN");

    //=============================================================

    menuView    = new wxMenu;

    //---------------
    menuView->AppendCheckItem(ID_MenuView_backgroundcolor,
        GetwxStr("&Background"));

    //---------------
    menuView->AppendCheckItem(ID_MenuView_material_param,
                                 GetwxStr("&Object"));
    menuView->Check(ID_MenuView_material_param,
                      _param_material->IsShown());

    //---------------
    menuView->AppendCheckItem(ID_MenuView_projection_param,
                                GetwxStr("&Projection"));
    menuView->Check(ID_MenuView_projection_param,
                      _param_proj->IsShown());

    //---------------
    menuView->AppendCheckItem(ID_MenuView_lighting_param,
      GetwxStr("&Light"));
    menuView->Check(ID_MenuView_lighting_param, _param_light->IsShown());

    //---------------
    menuView->AppendCheckItem(ID_MenuView_fog_param,
      GetwxStr("&Fog"));
    menuView->Check(ID_MenuView_fog_param, _param_fog->IsShown());

    //---------------
    menuView->AppendCheckItem(ID_MenuView_vectors_param,
      GetwxStr("&Vectors"));
    menuView->Check(ID_MenuView_vectors_param, _param_vectors->IsShown());

    //---------------
    menuView->AppendCheckItem(ID_MenuView_lines_param,
      GetwxStr("&Lines"));
    menuView->Check(ID_MenuView_lines_param, _param_lines->IsShown());

    //---------------
    menuView->AppendCheckItem(ID_MenuView_points_param,
      GetwxStr("&Points"));
    menuView->Check(ID_MenuView_points_param, _param_points->IsShown());

     menuBar->Append( menuView, GetwxStr("&View") );

    //=============================================================

    menuOptions = new wxMenu;

    //----- Mouse Action -----
    _wxm_options_move = new wxMenuEnum(menuOptions,
        &m_canvas->_mouse_action,"Mouse &action");
    _wxm_options_move->AddChoice(ID_MenuOptions_move_object,
        GetwxStr("Move &Object"),     GetwxStr("Move Object"));
    _wxm_options_move->AddChoice(ID_MenuOptions_move_base,
        GetwxStr("Move &Base"),     GetwxStr("Move Base"));
    _wxm_options_move->SetSelection(ID_MenuOptions_move_object);

    //----- GL Mode -----
    _wxm_options_GLmode = new wxMenuEnum(menuOptions,
        &m_canvas->_GLParam._GLmode, "&GL mode");
    _wxm_options_GLmode->AddChoice(ID_MenuOptions_GLPoints,
        GetwxStr("GL_POINT"), GetwxStr("GL Point"));
    _wxm_options_GLmode->AddChoice(ID_MenuOptions_GLLines,
        GetwxStr("GL_LINE"), GetwxStr("GL Line"));
    _wxm_options_GLmode->AddChoice(ID_MenuOptions_GLFill,
        GetwxStr("GL_FILL"), GetwxStr("GL_FILL"));

    _wxm_options_GLmode->SetSelection( ID_MenuOptions_GLFill);


    //----- Shading Options -----
    _wxm_options_shade = new wxMenuEnum(menuOptions,
        &m_canvas->_GLParam._shade_model,
        "Shade model");
    _wxm_options_shade->AddChoice(ID_MenuOptions_Flat,
        GetwxStr("GL_FLAT"),GetwxStr("GL_FLAT"));
    _wxm_options_shade->AddChoice(ID_MenuOptions_Smooth,
        GetwxStr("GL_SMOOTH"), GetwxStr("GL_SMOOTH"));
    _wxm_options_shade->Update();

    // ----- Lighting -----
    wxMenu* lighting_submenu = new wxMenu;
    lighting_submenu->AppendCheckItem(ID_MenuOption_enablelighting, GetwxStr("Enable &Lighting"));
    lighting_submenu->Check(ID_MenuOption_enablelighting, m_canvas->_GLParam._lighting);

    menuOptions->Append(ID_MenuOption_lighting,  GetwxStr("&Lighting"), lighting_submenu);
//  _Moptions_lighting_enabled->FixeAccelerateur( "<Key>l", "l");

   menuOptions->AppendCheckItem(ID_MenuOption_enablecullface,
      GetwxStr("Enable &Cullface"));
   menuOptions->Check(ID_MenuOption_enablecullface, m_canvas->_GLParam._cullface);



/*

  //--------------------
  _Moptions_normalize_enabled = new ParametreCaractere( _Moptions->PullDown(),
               &_GLParam._normalize,
               "Enable normalize",
               CaractereToggle);
  _Moptions_normalize_enabled->CreeParametre(NULL,NULL);
  _Moptions_normalize_enabled->ChangedValueCallback( (void*) CB_redessine,
              (void*) this);

  //--------------------
  _Moptions_display_normals = new ParametreCaractere( _Moptions->PullDown(),
               &_GLParam._display_normals,
               "Display normals",
               CaractereToggle);
  _Moptions_display_normals->CreeParametre(NULL,NULL);
  _Moptions_display_normals->ChangedValueCallback( (void*) CB_redessine,
              (void*) this);

  //====================
  _Moptions_display_basis = new ParametreCaractere( _Moptions->PullDown(),
               &_display_basis,
               "Display basis",
               CaractereToggle);
  _Moptions_display_basis->CreeParametre(NULL,NULL);
  _Moptions_display_basis->ChangedValueCallback( (void*) CB_redessine,
             (void*) this);
  _Moptions_display_basis->FixeAccelerateur( "<Key>b", "b");


  //====================
  _Moptions_display_color_basis = new ParametreCaractere( _Moptions->PullDown(),
               &_display_color_basis,
               "Display color basis",
               CaractereToggle);
  _Moptions_display_color_basis->CreeParametre(NULL,NULL);
  _Moptions_display_color_basis->ChangedValueCallback( (void*) CB_redessine,
             (void*) this);
//  _Moptions_display_basis->FixeAccelerateur( "<Key>b", "b");


  //====================
  _Moptions_display_bb = new ParametreCaractere( _Moptions->PullDown(),
                              &_GLParam._current_bounding_box,
               "Display bounding box",
               CaractereToggle);
  _Moptions_display_bb->CreeParametre(NULL,NULL);
  _Moptions_display_bb->ChangedValueCallback( (void*) CB_redessine,
                      (void*) this);


  //====================
  _Moptions_dither = new ParametreCaractere( _Moptions->PullDown(),
             &_GLParam._dither,
             "Enable Dither",
             CaractereToggle);
  _Moptions_dither->CreeParametre(NULL,NULL);
  _Moptions_dither->ChangedValueCallback( (void*) CB_redessine,
            (void*) this);


  //---------------
  _Moptions_material_visible =
    new ParametreCaractere( _Moptions->PullDown(),
        &_param_material_visible,
        "display material",
        CaractereToggle);

  _Moptions_material_visible->CreeParametre(NULL,NULL);
  _Moptions_material_visible->ChangedValueCallback(
                    (void*) CB_material_visible,
        (void*) this);
*/

/*
  //---------------
  _Moptions_light_visible =
    new ParametreCaractere( _Moptions->PullDown(),
        &_param_light_visible,
        "display light",
        CaractereToggle);

  _Moptions_light_visible->CreeParametre(NULL);
  _Moptions_light_visible->ChangedValueCallback(
                    (void*) CB_light_visible,
        (void*) this);

*/

  menuBar->Append( menuOptions, GetwxStr("&Options") );


    SetMenuBar( menuBar );

} // Create_wxMenu()

//------------------------------------------------
wxToolBar* Viewer3D::OnCreateToolBar(long style,
      wxWindowID id, const wxString& name)
{
  return new MyToolBar(this,wx_toolbar_id,
          wxDefaultPosition,
          wxDefaultSize,
          wxTB_HORIZONTAL | wxNO_BORDER,
          _T("MyToolBar"));
}

//---------------------------------------------------------
void Viewer3D::UpdateMenu()
{

  menuView->Check(ID_MenuView_backgroundcolor,
                   _param_material->IsShown());

  menuView->Check(ID_MenuView_material_param,
                   _param_material->IsShown());

  menuView->Check(ID_MenuView_projection_param,
                   _param_proj->IsShown());

  menuView->Check(ID_MenuView_lighting_param,
                   _param_light->IsShown());

  menuView->Check(ID_MenuView_fog_param,
                   _param_fog->IsShown());

// tgl->_Moptions_light_visible->MAJ();

} // UpdateMenu()

//------------------------------------------------
void Viewer3D::Create_Toolbar()
{

//      long  style =  (wxTB_FLAT | wxTB_DOCKABLE | wxTB_TEXT ) & ~wxTB_HORIZONTAL| wxTB_VERTICAL;

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


  proj_id = toolBar->AddEnum( &m_canvas->_GLProjParam.type_proj,
                              _T("Projection"),
                              _T("Projection type [Ortho|Persp] \n Right click --> parameters"),
                              (void*) Viewer3D::CB_redessine,
                              (void*) this);
  toolBar->AddEnumChoice( proj_id, 
                          wxID_TB_Projection, PROJ_ORTHO,
                          wxBitmap(proj_ortho_string), _T("ortho"));
  toolBar->AddEnumChoice( proj_id, 
                          wxID_TB_Projection, PROJ_PERSP,
                          wxBitmap(proj_persp_string), _T("persp"));
  toolBar->AddRightClick( proj_id,
                          (void*) Viewer3D::CB_ProjParam,
                          (void*) this);

  toolBar->Update(proj_id);


//#ifndef WIN32

  fog_id = toolBar->AddEnum(&m_canvas->_GLFogParam._enabled,
                            _T("Fog"),
                            _T("Fog On/Off \n Right click --> parameters"),
                            (void*) Viewer3D::CB_redessine,
                            (void*) this);

  toolBar->AddEnumChoice(fog_id, wxID_TB_Fog, 0, 
    wxBitmap(nofog_string),_T("No Fog"));
  toolBar->AddEnumChoice(fog_id, wxID_TB_Fog, 1, 
    wxBitmap(fog_string),_T("Fog"));
  toolBar->AddRightClick( fog_id,
                            (void*) Viewer3D::CB_FogParam,
                            (void*) this);
  toolBar->Update(fog_id);


  bb_id = toolBar->AddEnum(&m_canvas->_GLParam._current_bounding_box,
                                _T("BB"), _T("Bounding Box On/Off"),
                                (void*) Viewer3D::CB_redessine,
                                (void*) this);

  toolBar->AddEnumChoice(bb_id, wxID_TB_BB, 0, wxBitmap(nobb_string), _T("No BB"));
  toolBar->AddEnumChoice(bb_id, wxID_TB_BB, 1, wxBitmap(bb_string), _T("BB"));
  toolBar->Update(bb_id);


  glmode_id = toolBar->AddEnum<int>(&m_canvas->_GLParam._GLmode,
                                _T("GL mode"), _T("GL mode [Point|Line|Fill]"),
                                (void*) Viewer3D::CB_redessine,
                                (void*) this);

  toolBar->AddEnumChoice(glmode_id, wxID_TB_GLmode, GL_MODE_POINT, wxBitmap(gl_point_string),_T("Points"));
  toolBar->AddEnumChoice(glmode_id, wxID_TB_GLmode,  GL_MODE_LINE,  wxBitmap(gl_line_string),_T("Lines"));
  toolBar->AddEnumChoice(glmode_id, wxID_TB_GLmode,  GL_MODE_FILL,  wxBitmap(gl_fill_xpm),_T("Fill"));
  toolBar->AddEnumChoice(glmode_id, wxID_TB_GLmode,  GL_MODE_FILL_LINE,  wxBitmap(gl_fill_line_string),_T("Fill & Lines"));
  toolBar->Update(glmode_id);

//#endif // not WIN32

  toolBar->Realize();

//  toolBar->Hide();
//  toolBar->RemoveTool(wxID_TB_ProjectionPersp);
//  toolBar->Realize();
//  toolBar->Show();

} // Create_Toolbar()


//------------------------------------------------
void Viewer3D::ReDraw(wxCommandEvent& event)
{
  m_canvas->_GLParam._lighting = menuOptions->IsChecked(ID_MenuOption_enablelighting);

  m_canvas->_GLParam._cullface = menuOptions->IsChecked(ID_MenuOption_enablecullface);

  m_canvas->Refresh(false);
} // ReDraw()


//------------------------------------------------
void Viewer3D::CB_material_visible(wxCommandEvent& event)
{
  int visible;
  visible =  menuView->IsChecked(ID_MenuView_material_param);

  Si visible Alors
    _param_material->AfficheDialogue();
  Sinon
    _param_material->FermeDialogue( );
  FinSi
} // CB_material_visible()


//------------------------------------------------
void Viewer3D::CB_proj_visible(wxCommandEvent& event)
{
  int visible;
  visible =  menuView->IsChecked(ID_MenuView_projection_param);

  Si visible Alors
    _param_proj->AfficheDialogue();
  Sinon
    _param_proj->FermeDialogue( );
  FinSi
} // CB_proj_visible()


//------------------------------------------------
void Viewer3D::CB_lighting_visible(wxCommandEvent& event)
{
  int visible;
  visible =  menuView->IsChecked(ID_MenuView_lighting_param);

  Si visible Alors
    _param_light->AfficheDialogue();
  Sinon
    _param_light->FermeDialogue( );
  FinSi
} // CB_lighting_visible()


//------------------------------------------------
void Viewer3D::CB_fog_visible(wxCommandEvent& event)
{
  int visible;
  visible =  menuView->IsChecked(ID_MenuView_fog_param);

  Si visible Alors
    _param_fog->AfficheDialogue();
  Sinon
    _param_fog->FermeDialogue( );
  FinSi
} // CB_lighting_visible()


//------------------------------------------------
void Viewer3D::CB_vectors_visible(wxCommandEvent& event)
{
  int visible;
  visible =  menuView->IsChecked(ID_MenuView_vectors_param);

  Si visible Alors
    _param_vectors->AfficheDialogue();
  Sinon
    _param_vectors->FermeDialogue( );
  FinSi
} // CB_vectors_visible()


//------------------------------------------------
void Viewer3D::CB_lines_visible(wxCommandEvent& event)
{
  int visible;
  visible =  menuView->IsChecked(ID_MenuView_lines_param);

  Si visible Alors
    _param_lines->AfficheDialogue();
  Sinon
    _param_lines->FermeDialogue( );
  FinSi
} // CB_line_visible()


//------------------------------------------------
void Viewer3D::CB_points_visible(wxCommandEvent& event)
{
  int visible;
  visible =  menuView->IsChecked(ID_MenuView_points_param);

  Si visible Alors
    _param_points->AfficheDialogue();
  Sinon
    _param_points->FermeDialogue( );
  FinSi
} // CB_points_visible()


 //---------------------------------------------------------------------
void Viewer3D::CB_Close(wxCommandEvent& WXUNUSED(event))
//             --------
{
  Close();
} // CB_Close()


 //---------------------------------------------------------------------
void Viewer3D::CloseWindow()
//             -----------
{
  fprintf(stderr,"CloseWindow() \n");
  Si CloseFunction != NULL Alors
    void (*func)( void*) = (void (*)( void*)) CloseFunction;
  func( (void*) CloseData);
  Sinon
    // Call destructor
    this->Close(true);
    this->~Viewer3D();
  FinSi

  // true is to force the frame to close
  //    Close(true);
} // CloseWindow()


//-------------------------------------------------------------
void Viewer3D::CB_BackgroundColor(wxCommandEvent& event)
{
  int visible;
  visible =  menuView->IsChecked(ID_MenuView_backgroundcolor);

  Si visible Alors
    _param_backgroundcolor->AfficheDialogue();
  Sinon
    _param_backgroundcolor->FermeDialogue( );
  FinSi

}


//----------------------------------------------------------
void Viewer3D::CB_Ouvrir_surface(wxCommandEvent& event)
//              -----------------
{


  printf("CB_Ouvrir_surface()\n");
/* TODO
    int     etat;

   _param_nom_image->ContraintesNomFichier(
          _id_nom_image, "", ".", "*.wrl");
   _param_nom_image->MAJ();

   _param_nom_image->AfficheDialogue();


  Normalize();
  Center();
  Paint();
*/
} // CB_Ouvrir_surface()


//----------------------------------------------------------
void Viewer3D::CB_ViewParam(wxCommandEvent&)
{
  // TODO
  //    menuOptions->Checked(ID_MenuOption_,
  //      param_objects_visible);

  Si !(_param_view->IsShown()) Alors
    _param_view->AfficheDialogue();
  Sinon
    _param_view->FermeDialogue( );
  FinSi
} // CB_PixmapCenterNormalize()


//----------------------------------------------------------
void Viewer3D::CB_PixmapCenterNormalize(wxCommandEvent&)
{
  cout << "starts Viewer3D::CB_PixmapCenterNormalize() " << endl;
  // Check is shift is down in ToolBar
  m_canvas->Center();
  m_canvas->Normalize();
  m_canvas->Refresh(false);
  m_canvas->Update();

} // CB_PixmapCenterNormalize()


//----------------------------------------------------------
void Viewer3D::CB_ProjParam(void* cd)
{
  // TODO
  //    menuOptions->Checked(ID_MenuOption_,
  //      param_objects_visible);

  Viewer3D* tgl = (Viewer3D*) cd;

  Si !(tgl->_param_proj->IsShown()) Alors
    tgl->_param_proj->AfficheDialogue();
  Sinon
    tgl->_param_proj->FermeDialogue( );
  FinSi
} // CB_ProjParam()


//----------------------------------------------------------
void Viewer3D::CB_FogParam(void* cd)
{
  // TODO
  //    menuOptions->Checked(ID_MenuOption_,
  //      param_objects_visible);

  Viewer3D* tgl = (Viewer3D*) cd;

  Si !(tgl->_param_fog->IsShown()) Alors
    tgl->_param_fog->AfficheDialogue();
  Sinon
    tgl->_param_fog->FermeDialogue( );
  FinSi
} // CB_FogParam()


//----------------------------------------------
void Viewer3D::CB_redessine( void* cd)
//              ------------
{
  Viewer3D* tgl = (Viewer3D*) cd;
  tgl->m_canvas->Refresh(false);
  tgl->m_canvas->Update();

} // CB_redessine()

//-------------------------------------------------------------
void Viewer3D::OnClose(wxCloseEvent& event)
{
  cout << "Viewer3D::OnClose" << endl;
  CloseWindow();
}
