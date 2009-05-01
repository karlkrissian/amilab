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


#include "ami_wxGLCanvas.hpp"
//#include "DessinImageParam.hpp"
#include "Voxels.h"
#include "VolumeRender.hpp"
#include "Viewer3D.hpp"

#include <ostream>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/stream.hpp>
//namespace io = boost::iostreams;

boost::iostreams::stream_buffer<boost::iostreams::file_sink> buf("log.txt");
std::ostream                     out(&buf);


extern unsigned char      GB_debug;
extern unsigned char      GB_verbose;
extern wxApp*    GB_wxApp;


static const std::string glErrorString( GLenum err)
{
  switch(err) {
  case GL_NO_ERROR: return "GL_NO_ERROR";
  case GL_INVALID_ENUM: return "GL_INVALID_ENUM";
  case GL_INVALID_VALUE: return "GL_INVALID_VALUE";
  case GL_INVALID_OPERATION: return "GL_INVALID_OPERATION";
  case GL_STACK_OVERFLOW:return "GL_STACK_OVERFLOW";
  case GL_STACK_UNDERFLOW: return "GL_STACK_UNDERFLOW";
  case GL_OUT_OF_MEMORY: return "GL_OUT_OF_MEMORY";
#if !(defined(_MSC_VER) || defined(__MINGW32__))
    //  case GL_TABLE_TOO_LARGE_EXT: return "GL_TABLE_TOO_LARGE_EXT";
#endif
#ifndef _solaris_
    //  case GL_TEXTURE_TOO_LARGE_EXT: return "GL_TEXTURE_TOO_LARGE_EXT";
#endif
  default: return "unknown error";
  }
}


/*
 * ami_wxGLCanvas implementation
 */

// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

// control ids
enum
{
    Animation_Timer = wxID_HIGHEST,
};


BEGIN_EVENT_TABLE(ami_wxGLCanvas, wxGLCanvas)
    EVT_SIZE(                 ami_wxGLCanvas::OnSize)
    EVT_PAINT(                ami_wxGLCanvas::OnPaint)
    EVT_CHAR(                 ami_wxGLCanvas::OnChar)
    EVT_MOUSE_EVENTS(         ami_wxGLCanvas::OnMouseEvent)
    EVT_ERASE_BACKGROUND(     ami_wxGLCanvas::OnEraseBackground)
    EVT_TIMER(Animation_Timer,ami_wxGLCanvas::OnAnimationTimer)
END_EVENT_TABLE()


  // JACS
#ifdef __WXMSW__
    int *gl_attrib = NULL;
#else
    int gl_attrib[20] = { WX_GL_RGBA,
    WX_GL_MIN_RED, 1, 
    WX_GL_MIN_GREEN, 1,
    WX_GL_MIN_BLUE, 1, 
    WX_GL_DEPTH_SIZE, 1,
    WX_GL_DOUBLEBUFFER,
#  if defined(__WXMAC__) || defined(__WXCOCOA__)
        GL_NONE };
#  else
        None };
#  endif
#endif

ami_wxGLCanvas::ami_wxGLCanvas(
        wxWindow *parent,
        wxWindowID id,
        const wxPoint& pos,
        const wxSize& size,
        long style,
        const wxString& name)
    :

    // using older constructor because of pbs with nxviewer
    wxGLCanvas( parent,
                id,
                pos,
                size,
                style
                |wxFULL_REPAINT_ON_RESIZE
                |wxBORDER_RAISED,
                name 
                ,gl_attrib
                )
/*
    wxGLCanvas(parent,
                id,
                NULL, // gl attributes
                pos,
                size,
                style
                |wxFULL_REPAINT_ON_RESIZE
                |wxBORDER_RAISED,
                name)
*/
{

/* Maybe put it back on wxpython 2.9 ???
    // Create opengl context
    _opengl_context = wxGLContext_ptr(
                  new wxGLContext(this));

    SetCurrentContext();
*/

    // out writes to log.txt

    if (GB_debug) out << "*** begin ami_wxGLCanvas::ami_wxGLCanvas() ***" << endl;
    _parent_window = (Viewer3D*) parent;
    if (GB_debug) out << "***2***" << endl;

/*  Seems to work without those commands
    parent->Show(true);
cout << "***3***" << endl;
    SetCurrent();
cout << "***4***" << endl;

*/

    int i;

  Si GB_debug AlorsFait fprintf(stderr,"Constructeur ami_wxGLCanvas \n");

  Si GB_debug AlorsFait fprintf(stderr,"Constructeur ami_wxGLCanvas 1 \n");

  Si GB_debug AlorsFait fprintf(stderr,"Constructeur ami_wxGLCanvas 2 \n");

  Pour(i,0,MAX_LIGHTS-1)
    _GLLight[i]._num_light=i;
  FinPour

  _light_number = 0;
  _GLLight[0]._ambient.FixeValeur(100, 100, 100);
  _GLLight[0]._diffuse.FixeValeur(180, 180,  80);
  _GLLight[0].SetPosition(1.0,1.0,2.0);
  _GLLight[0]._enabled=true;

  _GLLight[1].SetPosition( 3.0, 3.0,2.0);

  _GLLight[2]._ambient.FixeValeur(100, 100, 100);
  _GLLight[2]._diffuse.FixeValeur(100, 100, 100);
  _GLLight[2].SetPosition(3.0,3.0,2.0);

  _GLLight[3]._ambient.FixeValeur(100, 100, 100);
  _GLLight[3].SetPosition(-3.0,3.0,2.0);


  _GLLight[4].SetPosition(3.0,-3.0,2.0);

  _GLLight_display = _GLLight[0];

  scale = 0.2;

  _translate_x =
  _translate_y =
  _translate_z = 0;

  _type_surface = SURFACE_NONE;

//  InitSurface();
  _SURFACE       = 0;
  _LINES         = 0;
  _SURFVECTORS   = 0;
  _CURSOR        = 0;

  _VOLVECTORS1   = 0;
  _VOLVECTORS2   = 0;

  _display_volvectors1 = true;
  _display_volvectors2 = false;

  _vectfieldcol_type = VECTFIELDCOL_RGBCYM;

  _REPERE        = 0;
  _VECTOR_COLORS = 0;
  _ISOSURFACE    = 0;

  _VOXELS        = 0;
  _GLMIP         = 0;

  _volren        = NULL;

  _SECTION[0] = _SECTION[1] = _SECTION[2] = 0;
  _section_pos[0] = _section_pos[1] = _section_pos[2] = -1;
  _section_visible[0] =
  _section_visible[1] =
  _section_visible[2] = false;

  Pour(i,0,MAX_FREE_SECTIONS-1)
    _FREE_SECTION[i]         =  0;
    _free_section_visible[i] =  false;
  FinPour

  _display_basis = false;
  _display_color_basis = false;
  _mouse_action  = MOUSE_MOVE_OBJECT;
  _Tfar.SetTranslation(0.0,0.0,0.00);


  _cursor_x = _cursor_y = _cursor_z = 0.0;
  _display_cursor = false;

  if (GB_debug) out << "***  ami_wxGLCanvas::ami_wxGLCanvas() 4 ***" << endl;
  Si GB_debug AlorsFait fprintf(stderr,"Constructeur ami_wxGLCanvas 4 \n");

/*
  X_Expression =
  Y_Expression =
  Z_Expression = NULL;

  XExprString = "U";
  YExprString = "V";
  ZExprString = "sin(U)*sin(V)";

  _u_min = 0;
  _u_max = PI;
  _nbpoints_u = 50;
  _close_u = false;

  _v_min = 0;
  _v_max = PI;
  _nbpoints_v = 50;
  _close_v = false;
*/

  _line_action  = LINE_INFO;
  _point_action = POINT_INFO;
  _cc_action    = CC_INFO;


  _plus_grande_cc = false;

  Si GB_debug AlorsFait fprintf(stderr,"Constructeur ami_wxGLCanvas 5 \n");

  _initialized = false;

/*
  Show();
  SetCurrentContext();
  InitGL();
  EmpileMatrice();
  glLoadIdentity();
  _GLTransform.GetCurrentMatrix((GLdouble*) _current_matrix );

  _object_center[0] =
  _object_center[1] =
  _object_center[2] = 0.0;

    { // for help debugging, report any OpenGL errors that occur per frame
        GLenum error;
        while((error = glGetError()) != GL_NO_ERROR)
            fprintf(stderr, "Constructeur GL error: %s\n",
            glErrorString(error));
    }
*/

  _limits_set = false;
  _mode_affichage = MODE_SURFACE;

  Si GB_debug AlorsFait fprintf(stderr,"Constructeur ami_wxGLCanvas Fin \n");

  if (GB_debug) out << "*** end ami_wxGLCanvas::ami_wxGLCanvas() ***" << endl;

} // ami_wxGLCanvas


//----------------------------------------------
bool ami_wxGLCanvas::SetCurrentContext()
{

    if (GB_debug) out << "*** begin ami_wxGLCanvas::SetCurrentContext() ***" << endl;

//    if (!GetContext()) return false;
    SetCurrent();

    if (GB_debug) out << "*** end ami_wxGLCanvas::SetCurrentContext() ***" << endl;

    return true;
/*
  if (_opengl_context.use_count()) {
    #if (wxCHECK_VERSION(2,9,0))
      bool res= SetCurrent(*_opengl_context);
      if (!res) cerr << "ami_wxGLCanvas::SetCurrentContext()"
                    << "\t failed " << endl;
      return res;
    #else
      SetCurrent(*_opengl_context);
    #endif
  }
  else {
    cerr  << "ami_wxGLCanvas::SetCurrentContext() \t"
          << "context not initialized ! "
          << endl;
    return false;
  }
  return true;
*/

} // SetCurrentContext()


//----------------------------------------------
GLObject::ptr ami_wxGLCanvas::GetGLObject(int i)
{

  if ((i<0)||(i>=(int)_globject.size())) {
    return GLObject::ptr();
  }

  int n=0;
  GLObject::ptr_list::iterator Iter;

  Iter  = _globject.begin();
  while (n<i) { Iter++; n++; }

  return (*Iter);

} // GetGLObject()


//----------------------------------------------
int ami_wxGLCanvas::GetCurrentObjectNum()
{
  int n=0;
  GLObject::ptr_list::iterator Iter;

  Iter  = _globject.begin();
  while (((*Iter)!=_current_globject)&& Iter!=_globject.end())
  {
    Iter++;
    n++;
  }

  if (n>=(int)_globject.size()) {
    fprintf(stderr,"ami_wxGLCanvas::GetCurrentObjectNum()\t current object not found !\n");
    return 0;
  } else
    return n;

} // GetCurrentObjectNum()


//----------------------------------------------
int ami_wxGLCanvas::SetCurrentObject(int i)
{

  if (i<0) return 0;
  if (i>=(int)_globject.size()) return _globject.size()-1;

  int n=0;
  GLObject::ptr_list::iterator Iter;

  Iter  = _globject.begin();
  while (n<i) { Iter++; n++; }

  if ((*Iter).use_count()) {
    _current_globject = (*Iter);
    return i;
  } else {
    fprintf(stderr,"ami_wxGLCanvas::SetCurrentObject(%d) \t empty object\n",i);
  }

  return 0;

} // SetCurrentObject()

//----------------------------------------------
void ami_wxGLCanvas::OnPaint( wxPaintEvent& WXUNUSED(event) )
{
    if (GB_debug) out << "*** begin ami_wxGLCanvas::OnPaint() ***" << endl;

    // This is a dummy, to avoid an endless succession of paint messages.
    // OnPaint handlers must always create a wxPaintDC.
    wxPaintDC dc(this);

//    if (!GetContext()) return;

  if (!dc.IsOk()) {
    cerr  << "ami_wxGLCanvas::OnPaint()"
          << "\t PaintDC not OK" << endl;
    return;
  }

  if (!SetCurrentContext()) return;
  if (!_initialized) {
    InitGL();
    _initialized = true;
  }
  this->Paint();

  if (GB_debug) out << "*** end ami_wxGLCanvas::OnPaint() ***" << endl;
}

void ami_wxGLCanvas::OnSize(wxSizeEvent& event)
{
    if (GB_debug) out << "*** begin ami_wxGLCanvas::OnSize() ***" << endl;

    // this is also necessary to update the context on some platforms
    wxGLCanvas::OnSize(event);

    if (GB_debug) out << "*** ami_wxGLCanvas::OnSize()  1 ***" << endl;

   // set GL viewport (not called by wxGLCanvas::OnSize on all platforms...)
    int w, h;
    GetClientSize(&w, &h);
    _largeur = w;
    _hauteur = h;
    if (GB_debug)
      cerr << "OnSize() "
            << _largeur << " "
            << _hauteur << " "
            << endl;

    if (GB_debug) out << "*** ami_wxGLCanvas::OnSize()  2 ***" << endl;
//    if (SetCurrentContext())
    {
      ReDimensionne();
    }


    if (GB_debug) out << "*** end ami_wxGLCanvas::OnSize() ***" << endl;
}

void ami_wxGLCanvas::OnChar(wxKeyEvent& event)
{
    switch( event.GetKeyCode() )
    {
    case WXK_ESCAPE:
    case WXK_LEFT:
    case WXK_RIGHT:
    case WXK_UP:
    case WXK_DOWN:
    case 's': case 'S':
    case 'l': case 'L':
    default:
        event.Skip();
        return;
    }

    //Refresh(false);
}

void ami_wxGLCanvas::OnMouseEvent(wxMouseEvent& event)
{
    _souris_x = (int)event.GetX();
    _souris_y = (int)event.GetY();

    if(event.LeftDown())
      if (event.ShiftDown())
        ShiftBout1_Presse();
      else
        Boutton_Presse();
    if(event.LeftUp())   Boutton_Relache();
    if(event.LeftIsDown() && event.Dragging())
        DeplaceSourisBout1();


#ifdef __APPLE__
    if(event.ControlDown())
        if(event.LeftDown()) Boutton2_Presse();
        if(event.LeftUp())   Boutton2_Relache();
        if(event.LeftIsDown() && event.Dragging())
          if (event.ShiftDown())
            DeplaceSourisShiftBout2();
          else
            DeplaceSourisBout2();
#else
    if(event.MiddleDown()) Boutton2_Presse();
    if(event.MiddleUp())   Boutton2_Relache();
    if(event.MiddleIsDown() && event.Dragging())
      if (event.ShiftDown())
        DeplaceSourisShiftBout2();
      else
        DeplaceSourisBout2();
#endif

    if(event.RightDown()) Boutton3_Presse();
    if(event.RightUp())   Boutton3_Relache();
    if(event.RightIsDown() && event.Dragging())
      DeplaceSourisBout3();
}


//-------------------------------------------------------
void ami_wxGLCanvas::OnAnimationTimer( wxTimerEvent& event)
{
   MAJ_rotation();
} // OnAnimationTimer()


//-------------------------------------------------------
void ami_wxGLCanvas::OnEraseBackground( wxEraseEvent& WXUNUSED(event) )
{
    // Do nothing, to avoid flashing.
}


//-----------------------------------------------------
void ami_wxGLCanvas::DessineFond()
//
{
/*
  Si (_mode_affichage==MODE_GLMIP)Ou(_mode_affichage==MODE_VOLREN) Alors
    glClearColor( 0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  Sinon
*/
    _GLParam.ClearBackground();
/*
  FinSi
*/
} // DessineFond()


//---------------------------------------------
void ami_wxGLCanvas::EmpileMatrice(  )
//                   -------------
{
  glPushMatrix();
} // DepileMatrice()


//---------------------------------------------
void ami_wxGLCanvas::DepileMatrice(  )
//                   -------------
{
  glPopMatrix();
} // DepileMatrice()


//-----------------------------------------
void ami_wxGLCanvas::AfficheBuffer()
//
{
    SwapBuffers();

} // AfficheBuffer()



//-----------------------------------------------
void ami_wxGLCanvas::UpdateObjectList( )
//
{
  GLObject::ptr_list::iterator Iter;

  for (Iter  = _globject.begin();
       Iter != _globject.end()  ; Iter++ )
  {
    if (!(*Iter).use_count()) {
      Iter = _globject.erase(Iter);
    }
  }

} // UpdateObjectList()


//--------------------------------------------
void ami_wxGLCanvas::AddSurface( SurfacePoly::ptr surf)
//
{
if (GB_debug) fprintf(stderr,"ami_wxGLCanvas::AddSurface()\n");
  // Set OpenGL tasks to this drawing area
  if (!this->SetCurrentContext()) return;

  _globject.push_back(surf);
  _current_globject = surf;

  if (_current_globject.use_count()) {
    _current_globject->SetwxGLCanvas(this);
    _SURFACE      =  _current_globject->GenerateGLList();
    _type_surface = SURFACE_POLY;
  }

  _parent_window->UpdateObjectListGui();

if (GB_debug) fprintf(stderr,"ami_wxGLCanvas::AddSurface() end\n");
} // AddSurface()



//----------------------------------------------
void ami_wxGLCanvas::RemoveSurface( SurfacePoly::ptr surf)
//
{
  // Set OpenGL tasks to this drawing area
  if (!this->SetCurrentContext()) return;

  // Search for the surface
  // use iterator
  int n=0;
  GLObject::ptr_list::iterator Iter;

  Iter  = _globject.begin();
  while (((*Iter)!=surf)&& Iter!=_globject.end())
  {
    Iter++;
    n++;
  }

  if (n==(int)_globject.size()) {
    fprintf(stderr,"ami_wxGLCanvas::RemoveSurface() \t surface not found ...\n");
    return;
  }

  _globject.erase(Iter);

  if (_current_globject==surf)
    _current_globject = _globject.front();

} // RemoveSurface()


//----------------------------------------------
void ami_wxGLCanvas::SetVectors1(InrImage::ptr v)
//
{
    SurfacePoly*  surf_poly = (SurfacePoly*) _current_globject.get();

    Si v.use_count()==0 AlorsFait return;
    Si (v->VectorialFormat()) Alors
        if (GB_debug) fprintf(stderr,"ami_wxGLCanvas::SetVectors1() \t _GLParam.SetVector(1,v); \n");
        _GLParam.SetVector(1,v);
        // Update on the surface
        if (surf_poly!=NULL) surf_poly->NewVectors1();
        if (GB_debug) fprintf(stderr,"ami_wxGLCanvas::SetVectors1() \t NewVolumeVectors1(); \n");
        // Update the volume vectors
        NewVolumeVectors1();
        Refresh(false);
    Sinon
        cerr << "ami_wxGLCanvas::SetVectors1()"
            << "\t Image not vectorial " << endl;
    FinSi

} // SetVectors1()


//----------------------------------------------------------------
void ami_wxGLCanvas::SetVectors2(InrImage::ptr v)
//
{
    SurfacePoly*  surf_poly = (SurfacePoly*) _current_globject.get();

    Si v.use_count()==0 AlorsFait return;
    Si (v->VectorialFormat()) Alors
        if (GB_debug) fprintf(stderr,"ami_wxGLCanvas::SetVectors1() \t _GLParam.SetVector(2,v); \n");
        _GLParam.SetVector(2,v);
        // Update on the surface
        if (surf_poly!=NULL) surf_poly->NewVectors2();
        if (GB_debug) fprintf(stderr,"ami_wxGLCanvas::SetVectors2() \t NewVolumeVectors2(); \n");
        // Update the volume vectors
        NewVolumeVectors2();
        Refresh(false);
    Sinon
        cerr << "ami_wxGLCanvas::SetVectors2()"
            << "\t Image not vectorial " << endl;
    FinSi

} // SetVectors2()


//----------------------------------------------------------------
void ami_wxGLCanvas::NewVolumeVectors1()
//
{

  Si _VOLVECTORS1 != 0 Alors
    glDeleteLists(_VOLVECTORS1, 1);
    _VOLVECTORS1 = 0;
  FinSi

} // NewVolumeVectors1()


//----------------------------------------------------------------
void ami_wxGLCanvas::NewVolumeVectors2()
//
{

  Si _VOLVECTORS2 != 0 Alors
    glDeleteLists(_VOLVECTORS2, 1);
    _VOLVECTORS2 = 0;
  FinSi

} // NewVolumeVectors2()

//----------------------------------------------
SurfacePoly::ptr ami_wxGLCanvas::CreeIsosurface( InrImage::ptr image,
                              float seuil,
                              InrImage* mask)
{

    TPolygone     polygone;
    int        p,n;
    Vect3D<float> norm;
    pt3D          pt;
    GLObject::ptr current = _current_globject;

  // Set OpenGL tasks to this drawing area
  this->SetCurrentContext();

  IsoSurface::ptr isosurface(new IsoSurface( image));
  isosurface->CalculSurface( seuil, mask);

  SurfacePoly::ptr  surf_poly(new SurfacePoly());
  AddSurface(surf_poly);

  surf_poly->NewSurface();

  Pour( n, 0, isosurface->_image_points->NbPoints()-1)
    pt = isosurface->_image_points->Point(n);
    surf_poly->AddPoint( image->SpacePosX(pt.x),
             image->SpacePosY(pt.y),
             image->SpacePosZ(pt.z));
    // Ajout de la normale (-gradient)
    isosurface->CalculNormale(pt, norm);

    // Vectors are already normalized ...
    surf_poly->SetNorm( norm.x,norm.y,norm.z);
  FinPour


  // Write the polygones
  Pour(p, 0, isosurface->tabPoly.NbElts()-1)

    surf_poly->NewPoly();

    polygone = isosurface->tabPoly[p];
    Pour( n, 0, polygone.NbElts()-1)
      surf_poly->PolyAddPointNumber(polygone[n]);
    FinPour  // n

    surf_poly->EndPoly();

  FinPour

  _SURFACE = surf_poly->GenerateGLList();

  _type_surface = SURFACE_POLY;

/*
  _xmin = image->SpacePosX(-0.5);
  _ymin = image->SpacePosY(-0.5);
  _zmin = image->SpacePosZ(-0.5);
  _xmax = image->SpacePosX(image->DimX()-0.5);
  _ymax = image->SpacePosY(image->DimY()-0.5);
  _zmax = image->SpacePosZ(image->DimZ()-0.5);
  _limits_set = true;
*/

  _mode_affichage = MODE_SURFACE;
  if (GB_debug) printf("_SURFACE = %d \n",_SURFACE);

  return surf_poly;

} // CreeIsosurface()


//-----------------------------------------------
void ami_wxGLCanvas::SetColors( InrImage* image, float min, float max)
//
{


    SurfacePoly*  surf_poly = (SurfacePoly*) _current_globject.get();

  if (surf_poly==NULL) return;

  Si _type_surface != SURFACE_POLY AlorsFait return;

  // Set OpenGL tasks to this drawing area
  this->SetCurrentContext();

  printf("ami_wxGLCanvas::SetColors()\t %f %f \n",min,max);
  _SURFACE = surf_poly->SetColors(image,min,max);

} // SetColors()


//----------------------------------------------------------------
void ami_wxGLCanvas::CreeImageSurface(InrImage::ptr image, int planZ,
                       float zscale,
                       float min, float max)
//
{
  _surf.LitImage(image.get(), planZ, zscale, min, max);
  _type_surface = SURFACE_U_V;
  _mode_affichage = MODE_SURFACE;
  _SURFACE = 0;

} // CreeImageSurface()


//----------------------------------------------
void ami_wxGLCanvas::DessineSurfaceCC(  int cc )
//
{
    TPolygone    polygone;
    pt3D         pt;
    SurfacePoly*  surf_poly = (SurfacePoly*) _current_globject.get();

  if (surf_poly==NULL) return;

  // Set OpenGL tasks to this drawing area
  this->SetCurrentContext();
  Si _type_surface != SURFACE_POLY AlorsFait return;

  Si Non(surf_poly->_cc_calculees) Alors
    surf_poly->CalculCC();
  FinSi

  surf_poly->GLSurfaceDrawOnlyCC( _SURFACE, cc);

  _type_surface   = SURFACE_POLY;
  _mode_affichage = MODE_SURFACE;

} // DessineSurfaceCC


//----------------------------------------------------
void ami_wxGLCanvas::CreeVoxels3D(  InrImage* image,
               float seuilbas,
           float seuilhaut,
           float Imin, float Imax,
           float sx, float sy, float sz)
{
  Si _VOXELS != 0 AlorsFait glDeleteLists(_VOXELS, 1);
  _VOXELS = glGenLists(1);

  glNewList( _VOXELS, GL_COMPILE);

  PintaVoxels( image,
           (short int) seuilbas,
           seuilhaut,
           Imin,
           Imax
           );

  glEndList();


  // Limites de l'image
  _xmin = image->SpacePosX(0);
  _ymin = image->SpacePosY(0);
  _zmin = image->SpacePosZ(0);
  _xmax = image->SpacePosX(image->DimX()-1);
  _ymax = image->SpacePosY(image->DimY()-1);
  _zmax = image->SpacePosZ(image->DimZ()-1);
  _limits_set = true;

  _mode_affichage = MODE_VOXELS;

} // CreeVoxels3D()


//----------------------------------------------------
void ami_wxGLCanvas::CreeGLMIP( InrImage::ptr image,
        float seuilbas,
        float seuilhaut,
        float Imin, float Imax,
        int max_quads)
//
{
  Si _GLMIP != 0 AlorsFait glDeleteLists(_GLMIP, 1);
  _GLMIP = glGenLists(1);

  glNewList( _GLMIP, GL_COMPILE);

  Si seuilbas < 1 AlorsFait seuilbas=1;
  CreateMIP(
        image,
        seuilbas,
        seuilhaut,
        Imin,
        Imax,
        max_quads
  );

  glEndList();

  // Limites de l'image
  _xmin = image->SpacePosX(0);
  _ymin = image->SpacePosY(0);
  _zmin = image->SpacePosZ(0);
  _xmax = image->SpacePosX(image->DimX()-1);
  _ymax = image->SpacePosY(image->DimY()-1);
  _zmax = image->SpacePosZ(image->DimZ()-1);
  _limits_set = true;

  this->SetBG(0,0,0);

  _mode_affichage = MODE_GLMIP;

} // CreeGLMIP()


//---------------------------------------------------
void ami_wxGLCanvas::InitVolRen(  InrImage* image,
          float Imin, float Imax,
          DessinImageBase* di,
          InrImage* opacity)
//
{
  if (_volren!=NULL)
    delete _volren;

  _volren = new VolumeRender(image);
  if (di!=NULL)
    _volren->SetDessinImage(di);
    _volren->SetOpacityImage(opacity);
    _volren->SetMinMax(Imin,Imax);
    Si GB_debug AlorsFait PrintMatrices();
    _volren->SetTextureTransform(&_Ttexture);
//  _volren->SetTextureTransform(&_Tobject);
    _volren->InitRender();

  // Limites de l'image
  _xmin = image->SpacePosX(0);
  _ymin = image->SpacePosY(0);
  _zmin = image->SpacePosZ(0);
  _xmax = image->SpacePosX(image->DimX()-1);
  _ymax = image->SpacePosY(image->DimY()-1);
  _zmax = image->SpacePosZ(image->DimZ()-1);

  this->SetBG(0,0,0);

/*  _xmin = _ymin = _zmin = 0;
  _xmax = (image->_tx-1)*image->_size_x;
  _ymax = (image->_ty-1)*image->_size_y;
  _zmax = (image->_tz-1)*image->_size_z;
*/
  _limits_set = true;

  _mode_affichage = MODE_VOLREN;

} // InitVolRen()


//----------------------------------------------------------------
void ami_wxGLCanvas::InitSection(InrImage* image,
             int section,
             int pos,
             unsigned char active,
             float Imin, float Imax,
             ParamZoom zoom)
//
{


  Si Non(active) Alors
    _section_visible[section] = false;
  Sinon
    Si _SECTION[section] == 0 Ou _section_pos[section] != pos Alors

      Si _SECTION[section] != 0 AlorsFait
        glDeleteLists(_SECTION[section], 1);

      _SECTION[section] = glGenLists(1);
      glNewList( _SECTION[section], GL_COMPILE);
      PintaSeccionVoxels( image,
              section+1,
              pos,
              Imin,
              Imax,
              zoom
        );
      glEndList();
      _section_pos[section] = pos;

    FinSi
    _section_visible[section] = true;
  FinSi
  _mode_affichage = MODE_VOXELS;
} // InitSection()


//-------------------------------------------------------
void ami_wxGLCanvas::ShowFreeSection( int num, InrImage* image,
      int orientation,
      int pos,
      float Imin, float Imax)
//
{
    ParamZoom zoom;

  Si (num<0) Ou (num>=MAX_FREE_SECTIONS) AlorsFait return;

  Si _FREE_SECTION[num] != 0 Alors
    glDeleteLists(_FREE_SECTION[num], 1);
    _FREE_SECTION[num] = 0;
  FinSi

  _FREE_SECTION[num] = glGenLists(1);
  glNewList( _FREE_SECTION[num], GL_COMPILE);

  zoom._xmin = zoom._ymin = zoom._zmin = 0;
  zoom._xmax = image->DimX()-1;
  zoom._ymax = image->DimY()-1;
  zoom._zmax = image->DimZ()-1;

    PintaSeccionVoxels( image,
              orientation+1,
              pos,
              Imin,
              Imax,
            zoom
        );

  glEndList();

  _free_section_visible[num] = true;
  _mode_affichage = MODE_VOXELS;
} // ShowFreeSection()


//------------------------------------------------------------
void ami_wxGLCanvas:: HideFreeSection( int num)
//
{

  Si (num<0) Ou (num>=MAX_FREE_SECTIONS) AlorsFait return;
  _free_section_visible[num] = false;

} // HideFreeSection()



//----------------------------------------------
void ami_wxGLCanvas::DessineSurfaceCC(  int cc, unsigned char draw )
//
{
    TPolygone    polygone;
    pt3D         pt;
    SurfacePoly*  surf_poly = (SurfacePoly*) _current_globject.get();

  if (surf_poly==NULL) return;

  // Set OpenGL tasks to this drawing area
  this->SetCurrentContext();

  Si _type_surface != SURFACE_POLY AlorsFait return;

  Si Non(surf_poly->_cc_calculees) Alors
    surf_poly->CalculCC();
  FinSi

  surf_poly->GLSurfaceSetDrawCC( _SURFACE, cc, draw);

  _type_surface   = SURFACE_POLY;
  _mode_affichage = MODE_SURFACE;

} // DessineSurfaceCC

//----------------------------------------------
void ami_wxGLCanvas::InitProprietes( )
//                   --------------
{
    int i;

    glShadeModel( _GLParam.GLenum_shade() );

//printf("lighting %d \n",_GLParam._lighting);
    Si _GLParam._lighting Alors
      glEnable(GL_LIGHTING);
    Sinon
      glDisable( GL_LIGHTING);
    FinSi

    Si _GLParam._cullface Alors
      glEnable(GL_CULL_FACE);
      glCullFace(GL_BACK);
    Sinon
      glDisable( GL_CULL_FACE);
    FinSi

    Pour(i,0,MAX_LIGHTS-1)
      _GLLight[i].GLSet();
    FinPour

    glEnable(GL_DEPTH_TEST);

    { /* for help debugging, report any OpenGL errors that occur per frame */
        GLenum error;
        while((error = glGetError()) != GL_NO_ERROR) {
            fprintf(stderr, "GL error: %s\n",
            glErrorString(error).c_str());
            if (GB_debug) out << "!!! GL error " << glErrorString(error) << endl;
        }
    }

    Si _GLParam._dither Alors
      glEnable(GL_DITHER);
    Sinon
      glDisable(GL_DITHER);
    FinSi

    { /* for help debugging, report any OpenGL errors that occur per frame */
        GLenum error;
        while((error = glGetError()) != GL_NO_ERROR) {
            fprintf(stderr, "GL error: %s\n",
            glErrorString(error).c_str());
            if (GB_debug) out << "!!! GL error " << glErrorString(error) << endl;
        }
    }


    _GLProjParam.SetProjection();

/*    if (_GLProjParam.ProjectionType()==PROJ_ORTHO)
      _GLFogParam.GLSet(0.0);
    else
*/
      _GLFogParam.GLSet(_GLProjParam.EyeDistance());

    _GLFogParam.SetBGColor( &(_GLParam._background));

    { /* for help debugging, report any OpenGL errors that occur per frame */
        GLenum error;
        while((error = glGetError()) != GL_NO_ERROR) {
            fprintf(stderr, "GL error: %s\n",
            glErrorString(error).c_str());
            if (GB_debug) out << "!!! GL error " << glErrorString(error) << endl;
        }
    }

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_AUTO_NORMAL);

    Si _GLParam._normalize Alors
      glEnable(GL_NORMALIZE);
    Sinon
      glDisable( GL_NORMALIZE);
    FinSi

} // InitProprietes()


//----------------------------------------------
void ami_wxGLCanvas::DessineSurface()
//
{
/*
    gluBeginSurface(theNurb);
    gluNurbsSurface(theNurb,
        8, knots,
        8, knots,
        4 * 3,
        3,
        &ctlpoints[0][0][0],
        4, 4,
        GL_MAP2_VERTEX_3);
    gluEndSurface(theNurb);
*/
} // DessineSurface()

//--------------------------------------------------
void ami_wxGLCanvas::DessineSurface2()
//
{
    int        i,i00,i10,i01,i11;
    int        iu,iv;
    int        du,dv;

  SurfacePoly*  surf_poly = (SurfacePoly*) _current_globject.get();

  if (surf_poly==NULL) {
    // create a surface
    SurfacePoly::ptr  newsurf(new SurfacePoly());
    AddSurface(newsurf);
    surf_poly = (SurfacePoly*) _current_globject.get();
  }

  Si (_type_surface == SURFACE_U_V) Et (_SURFACE==0) Alors

    surf_poly->NewSurface();

    i = 0;
    Pour( iv, _surf._vmin, _surf._vmax)
    Pour( iu, _surf._umin, _surf._umax)

      surf_poly->AddPoint(_surf(iu,iv).x, _surf(iu,iv).y, _surf(iu,iv).z);

      (*surf_poly)[i].SetColor(
                 _surf.RColor(iu,iv),
                 _surf.GColor(iu,iv),
                 _surf.BColor(iu,iv));

      i++;

    FinPour
    FinPour

    du = (_surf._umax - _surf._umin +1);
    dv = (_surf._vmax - _surf._vmin +1);

    Pour( iu, 0, du-2)

    Pour( iv, 0, dv-2)

      i00 = iv*du+iu;
      i01 = i00+1;
      i10 = i00+du;
      i11 = i00+du+1;

      /*
      Si (_close_u) Et (iu == du-2) Alors
        i01 -= du-1;
        i11 -= du-1;
      FinSi

      Si (_close_v) Et (iv == dv-2) Alors
        i10 -= (dv-1)*du;
        i11 -= (dv-1)*du;
      FinSi
      */

      surf_poly->NewPoly();
      surf_poly->PolyAddPointNumber(i00);
      surf_poly->PolyAddPointNumber(i01);
      surf_poly->PolyAddPointNumber(i10);
      surf_poly->EndPoly();

      surf_poly->NewPoly();
      surf_poly->PolyAddPointNumber(i01);
      surf_poly->PolyAddPointNumber(i11);
      surf_poly->PolyAddPointNumber(i10);
      surf_poly->EndPoly();
    FinPour
    FinPour
    _SURFACE = surf_poly->GenerateGLList();
    // Reduce the specular value
    surf_poly->SetColorMaterial(true);
    surf_poly->GetMaterial()._specular.FixeValeur(20, 20, 20);
  FinSi

  DisplayObjects();

} // DessineSurface2()


//----------------------------------------------------------------
void ami_wxGLCanvas::DisplayObject(GLObject::ptr& obj)
//
{
    if (!obj.use_count()) return;
    if (!obj->Visible())    return;

      if (GB_debug) fprintf(stderr,"ami_wxGLCanvas::DisplayObject() object \n");
      SelonQue obj->ObjType() Vaut
        Valeur OBJTYPE_SURFPOLY:{
          SurfacePoly* surf = (SurfacePoly*) (obj.get());
          surf->SetwxGLCanvas(this);
          surf->DisplayObject( &_GLMaterial);
          Si _GLParam._display_normals AlorsFait
            surf->DisplayNormals();
          Si _GLParam._display_vect1   AlorsFait
            surf->DisplayVectors1( &_GLParam);
          Si _GLParam._display_vect2   AlorsFait
            surf->DisplayVectors2( &_GLParam);}
        FinValeur

        Valeur OBJTYPE_USERLIST:{
         obj->SetwxGLCanvas(this);
         obj->DisplayObject( &_GLMaterial);}
        FinValeur
        Defaut: fprintf(stderr,
            "ami_wxGLCanvas::DisplayObject() \t unknown object type \n");
      FinSelonQue

      { // for help debugging, report any OpenGL errors that occur per frame
        GLenum error;
        while((error = glGetError()) != GL_NO_ERROR) {
           fprintf(stderr, "GL error: %s\n",glErrorString(error).c_str());
           if (GB_debug) out << "!!! GL error " << glErrorString(error) << endl;

        }
      }

} // DisplayObject()

//------------------------------------------------------
// return true if first object is more opaque than second
// (or, equivalently, less transparent)
bool compare_opacity (GLObject::ptr first,
                      GLObject::ptr second)
{
  float op1=0,op2=0;
  if (first. use_count()) op1 = first ->GetOpacity();
  if (second.use_count()) op2 = second->GetOpacity();

  if (op1==op2) return first.get()<second.get();
  return (op1>op2);
}

//----------------------------------------------------------------
void ami_wxGLCanvas::DisplayObjects()
//
{

  if (GB_debug) fprintf(stderr,"ami_wxGLCanvas::DisplayObjects() Begin \n");

  // Better solution: order the objects by opacity ...
  // most opaque first
  GLObject::ptr_list sorted_list(_globject);
  if (GB_debug) 
    fprintf(stderr,
      "ami_wxGLCanvas::DisplayObjects() sorting elts \n");
  sorted_list.sort(compare_opacity);
  GLObject::ptr_list::iterator Iter;


  if (_GLParam._GLmode != GL_MODE_FILL_LINE) {
    glPolygonMode (GL_FRONT_AND_BACK, _GLParam.GLenum_mode());
    glLineWidth(_GLParam._line_width);
    glPointSize(_GLParam._point_size);
    if (GB_debug) fprintf(stderr,
      "ami_wxGLCanvas::DisplayObjects() iterating throught sorted elts \n");
    for (Iter  = sorted_list.begin();
        Iter != sorted_list.end()  ; Iter++ )
      if ((*Iter).use_count()) DisplayObject(*Iter);
  } else { // FILL and LINE
    glLineWidth(_GLParam._line_width);
    glPointSize(_GLParam._point_size);
    if (GB_debug) fprintf(stderr,
      "ami_wxGLCanvas::DisplayObjects() iterating throught sorted elts \n");
    for (Iter  = sorted_list.begin();
        Iter != sorted_list.end()  ; Iter++ )
      if ((*Iter).use_count()) {
        // First with FILL
        glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
        DisplayObject(*Iter);

        // Second with LINES and without light
        glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
        int  lw = (*Iter)->GetLineWidth();
        bool light_enabled = (*Iter)->GetEnableLight();
        (*Iter)->SetLineWidth(lw+1);
        (*Iter)->SetEnableLight(false);
        DisplayObject(*Iter);
        (*Iter)->SetLineWidth(lw);
        (*Iter)->SetEnableLight(light_enabled);
      }

  }

  if (GB_debug) fprintf(stderr,"ami_wxGLCanvas::DisplayObjects() End \n");

} // DisplayObjects()


//------------------------------------------------
void ami_wxGLCanvas::DessineVoxels3D()
//
{

  glPolygonMode (GL_FRONT_AND_BACK, _GLParam.GLenum_mode());
  glLineWidth(_GLParam._line_width);

  glCallList(_VOXELS);

} // DessineVoxels3D()


//------------------------------------------------
void ami_wxGLCanvas::DessineGLMIP()
//
{

  glPolygonMode (GL_FRONT_AND_BACK, _GLParam.GLenum_mode());
  glLineWidth(_GLParam._line_width);
  glCallList(_GLMIP);

} // DessineGLMIP()


//-------------------------------------------------
void ami_wxGLCanvas::DrawVolRen()
//
{

  if (_volren!=NULL)
    _volren->Render();

} // DrawVolRen()

//----------------------------------------------------
void ami_wxGLCanvas::DessineSections()
//
{
    int i;
    GLboolean light_enabled;

  glGetBooleanv(GL_LIGHTING, &light_enabled);
  glDisable(GL_LIGHTING);
  glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);

  Pour(i,0,2)
    Si _section_visible[i] AlorsFait glCallList(_SECTION[i]);
  FinPour

  Pour(i,0,MAX_FREE_SECTIONS-1)
    Si _free_section_visible[i] AlorsFait glCallList(_FREE_SECTION[i]);
  FinPour

  Si light_enabled AlorsFait glEnable(GL_LIGHTING);

} // DessineSections()


//------------------------------------------------------
void ami_wxGLCanvas::DisplayBasis()
//                   ------------
{
    GLint linewidth;
    GLboolean light_enabled;

  glGetBooleanv(GL_LIGHTING, &light_enabled);
  glDisable(GL_LIGHTING);

  Si _REPERE == 0 Alors
    _REPERE=glGenLists(1);
    glNewList(_REPERE, GL_COMPILE);
      glBegin(GL_LINES);

        glColor3f(1.0,   0.0, 0.0);
        glVertex3f(0.0,  0.0, 0.0);
        glVertex3f(0.5, 0.0, 0.0);

        glColor3f(0.0,   1.0, 0.0);
        glVertex3f(0.0,  0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);

        glColor3f(0.0,   0.0, 1.0);
        glVertex3f(0.0,  0.0, 0.0);
        glVertex3f(0.0,  0.0, 0.5);

      glEnd();
    glEndList();
  FinSi

  Si _display_basis Alors
    glGetIntegerv(GL_LINE_WIDTH, &linewidth);
    glLineWidth(3);
    glCallList(_REPERE);
    glLineWidth(linewidth);
  FinSi

  Si light_enabled AlorsFait glEnable(GL_LIGHTING);

} // DisplayBasis()


//----------------------------------------------------------------
void ami_wxGLCanvas::SetCursor( float x, float y, float z, unsigned char display)
//                        -----
{
  _cursor_x = x;
  _cursor_y = y;
  _cursor_z = z;

  Si _CURSOR != 0 Alors
//    printf("deleting _CURSOR %d \n",_CURSOR);
    glDeleteLists(_CURSOR, 1);
    _CURSOR = 0;
  FinSi

  _display_cursor = display;

} // SetCursor()



//------------------------------------------------------
void ami_wxGLCanvas::DisplayCursor()
//                   -------------
{
    GLint          linewidth;
    GLObject::ptr   current = _current_globject;

  if (!current.use_count()) return;

  Si _CURSOR == 0 Alors
    _CURSOR=glGenLists(1);
    glNewList(_CURSOR, GL_COMPILE);
      glBegin(GL_LINES);
        Si _limits_set Alors
          glVertex3f(_xmin,      _cursor_y, _cursor_z);
          glVertex3f(_xmax,      _cursor_y, _cursor_z);
          glVertex3f( _cursor_x, _ymin,     _cursor_z);
          glVertex3f( _cursor_x, _ymax,     _cursor_z);
          glVertex3f( _cursor_x, _cursor_y, _zmin    );
          glVertex3f( _cursor_x, _cursor_y, _zmax    );
        Sinon
          glVertex3f( _current_globject->_xmin,      _cursor_y, _cursor_z);
          glVertex3f( _current_globject->_xmax,      _cursor_y, _cursor_z);
          glVertex3f( _cursor_x, _current_globject->_ymin,      _cursor_z);
          glVertex3f( _cursor_x, _current_globject->_ymax,      _cursor_z);
          glVertex3f( _cursor_x, _cursor_y, _current_globject->_zmin    );
          glVertex3f( _cursor_x, _cursor_y, _current_globject->_zmax    );
        FinSi
      glEnd();
    glEndList();
  FinSi

  Si _display_cursor Alors
    glGetIntegerv(GL_LINE_WIDTH, &linewidth);
    glLineWidth(3);
    glCallList(_CURSOR);
    glLineWidth(linewidth);
  FinSi

} // DisplayCursor()


//--------------------------------------------------
void ami_wxGLCanvas::SetObjectTransform( const GLTransfMatrix& obj_transf)
{

  _Tobject = obj_transf;

} // SetObjectTransform()


//----------------------------------------------------------------
void ami_wxGLCanvas::SetFog( const GLFogParam& f)
//                   ------
{
  _GLFogParam = f;
} // SetFog()


//------------------------------------------------------
void ami_wxGLCanvas::Paint( const bool& affiche)
//                   -----
{

  if (GB_debug) out << "*** begin ami_wxGLCanvas::Paint() ***" << endl;

if (!_initialized) return;

  Si GB_debug AlorsFait  PrintMatrices();

  GLint render_mode;

  Si GB_debug AlorsFait fprintf(stderr,"ami_wxGLCanvas::Paint() Begin \n");

/*
  if (!SetCurrentContext()) {
    return;
  }
  if (!_initialized) {
    InitGL();
    _initialized = true;
  }
*/

  GLObject::ptr current = _current_globject;

  if (current!=NULL)
    current->_display_bb = _GLParam._current_bounding_box;

  glGetIntegerv(GL_RENDER_MODE,&render_mode);

  Si render_mode == GL_RENDER Alors
    Si GB_debug AlorsFait fprintf(stderr,"ami_wxGLCanvas::Paint() 0.5 \n");
    // Set OpenGL tasks to this drawing area
    this->SetCurrentContext();
  FinSi

  Si GB_debug AlorsFait fprintf(stderr,"ami_wxGLCanvas::Paint() 1 \n");
  if (GB_debug) out << "*** ami_wxGLCanvas::Paint() 1 ***" << endl;

  //Si Non( XtIsRealized(_parent)) AlorsFait return;

  DessineFond();
  //InitSurface();
  InitProprietes();

  Si GB_debug AlorsFait fprintf(stderr,"ami_wxGLCanvas::Paint() 2 \n");
  if (GB_debug) out << "*** ami_wxGLCanvas::Paint() 2 ***" << endl;

  Si GB_debug AlorsFait fprintf(stderr,"ami_wxGLCanvas::Paint() Draw objects \n");
  if (GB_debug) out << "*** ami_wxGLCanvas::Paint() 3 ***" << endl;

  EmpileMatrice();

  if (_mode_affichage!=MODE_VOLREN) {
    _Tfar.GLApplyMatrix();

    _Tbasis.GLApplyMatrix();
    DisplayBasis();

    _Tobject.GLApplyMatrix();
// TODO    if (_display_color_basis) DisplayVectorColors();

    DessineSections();
    DisplayCursor();

    // Display the vectors if any
// TODO    DisplayVolumeVectors1();
// TODO    DisplayVolumeVectors2();
  }


    SelonQue _mode_affichage Vaut
      Valeur MODE_SURFACE: DessineSurface2(); FinValeur
      Valeur MODE_VOXELS:  DessineVoxels3D(); FinValeur
      Valeur MODE_GLMIP:   DessineGLMIP(); FinValeur
      Valeur MODE_VOLREN:  DrawVolRen();   FinValeur
    FinSelonQue


  DepileMatrice();
  if (affiche)
    AfficheBuffer( );

  { /* for help debugging, report any OpenGL errors that occur per frame */
       GLenum error;
       while((error = glGetError()) != GL_NO_ERROR)
           fprintf(stderr, "GL error: %s\n",
           glErrorString(error).c_str());
  }

  Si GB_debug AlorsFait fprintf(stderr,"ami_wxGLCanvas::Paint() Draw comparison surf \n");
  if (GB_debug) out << "*** ami_wxGLCanvas::Paint() 4 ***" << endl;

  // Paint the Comparison Surfaces
  _parent_window->CompSurfPaint();

  Si render_mode == GL_RENDER Alors
    Si GB_debug AlorsFait fprintf(stderr,"ami_wxGLCanvas::Paint() come back to context \n");
    // Set OpenGL tasks to this drawing area
    this->SetCurrentContext();
  FinSi
  //SetCurrentContext();

  Si GB_debug AlorsFait fprintf(stderr,"ami_wxGLCanvas::Paint() End \n");

  if (GB_debug) out << "*** end ami_wxGLCanvas::Paint() ***" << endl;

} // Paint()


//------------------------------------------------------
void ami_wxGLCanvas::Normalize()
//                   ---------
{
#define macro_max(n1,n2) ((n1)>(n2)?(n1):(n2))
    float   max_dim;
    float   tx,ty,tz;
    GLObject::ptr current = _current_globject;

  Si _limits_set Alors
    tx = _xmax - _xmin;
    ty = _ymax - _ymin;
    tz = _zmax - _zmin;
  Sinon
    if (!current.use_count()) return;
    tx = current->_xmax - current->_xmin;
    ty = current->_ymax - current->_ymin;
    tz = current->_zmax - current->_zmin;
  FinSi

  max_dim = tx;
  max_dim = macro_max(max_dim, ty);
  max_dim = macro_max(max_dim, tz);

  _Tobject.SetScale(2.0/max_dim);

} // Normalize()

//----------------------------------------------------------------
void ami_wxGLCanvas::Center()
//                   ------
{
    float cx,cy,cz;
    GLObject::ptr current = _current_globject;

  Si _limits_set Alors
    cx = (_xmin + _xmax)/2.0;
    cy = (_ymin + _ymax)/2.0;
    cz = (_zmin + _zmax)/2.0;
   Sinon
    if (!current.use_count()) return;
    cx = current->_center_x;
    cy = current->_center_y;
    cz = current->_center_z;
  FinSi

  _Tobject.SetTranslation( -cx, -cy, -cz);

} // Center()


//-----------------------------------------------
InrImage* ami_wxGLCanvas::GetGLImage()
//
{
    int h,l,x,y,n;
    unsigned char* pixels_r;
    unsigned char* pixels_g;
    unsigned char* pixels_b;
    InrImage*      im;

    Si GB_debug AlorsFait fprintf ( stderr,"TestGL::GetGLImage() begin \n" );

    // Set OpenGL tasks to this drawing area
    SetCurrentContext();
    AfficheBuffer();

    l = _largeur;
    h = _hauteur;

    GLint viewport[4] ;
    glGetIntegerv ( GL_VIEWPORT, viewport ) ;
    int initx=viewport[0], inity=viewport[1] ;
    int width=viewport[2], height=viewport[3] ;

    if ( ( l!=width ) || ( h!=height ) || ( initx!=0 ) || ( inity!=0 ) ) {
        fprintf(stderr,"ami_wxGLCanvas::GetGLImage() l,h=%d %d, initx,inity,width,height=%d %d %d %d\n",l,h,initx,inity,width,height);
        return NULL;
    }

    l=width-initx;
    h=height-inity;

//  printf("GetGLImage() %d %d \n",l,h);

    pixels_r = ( unsigned char* ) malloc ( sizeof ( unsigned char ) *l*h );
    pixels_g = ( unsigned char* ) malloc ( sizeof ( unsigned char ) *l*h );
    pixels_b = ( unsigned char* ) malloc ( sizeof ( unsigned char ) *l*h );
    im = new InrImage ( width-initx,height-inity,1,WT_RGB,"im.inr.gz" );

    Si GB_debug AlorsFait fprintf ( stderr,"TestGL::GetGLImage() 1 \n" );

    GLint pack_alignment;
    glGetIntegerv ( GL_PACK_ALIGNMENT,&pack_alignment );
//printf("pack alignment %d \n",pack_alignment);
    glPixelStorei ( GL_PACK_ALIGNMENT,1 );


    glReadPixels ( ( GLint ) initx, ( GLint ) inity,
                   ( GLsizei ) width, ( GLsizei ) height,
                   GL_RED,       GL_UNSIGNED_BYTE,
                   ( GLvoid* ) pixels_r );

    glReadPixels ( ( GLint ) initx, ( GLint ) inity,
                   ( GLsizei ) width, ( GLsizei ) height,
                   GL_GREEN,       GL_UNSIGNED_BYTE,
                   ( GLvoid* ) pixels_g );
    glReadPixels ( ( GLint ) initx, ( GLint ) inity,
                   ( GLsizei ) width, ( GLsizei ) height,
                   GL_BLUE,       GL_UNSIGNED_BYTE,
                   ( GLvoid* ) pixels_b );

    glPixelStorei ( GL_PACK_ALIGNMENT,pack_alignment );

    Si GB_debug AlorsFait fprintf ( stderr,"TestGL::GetGLImage() 2 \n" );

    n = 0;
    Pour ( y,0,height-inity-1 )
    Pour ( x,0,width-initx-1 )
    im  ->BufferPos ( x,h-1-y,0 );
    im  ->VectFixeValeurs ( pixels_r[n],
                            pixels_g[n],
                            pixels_b[n] );
    n++;
    FinPour
    FinPour

    Si GB_debug AlorsFait fprintf ( stderr,"TestGL::GetGLImage() 3 \n" );

    free ( pixels_r );
    free ( pixels_g );
    free ( pixels_b );

    Si GB_debug AlorsFait fprintf ( stderr,"TestGL::GetGLImage() end \n" );

    return im;
} // GetGLImage()


//------------------------------------------------------
void ami_wxGLCanvas:: ReDimensionne( )
//                    -------------
{
  if (GB_debug) out << "*** begin ami_wxGLCanvas::ReDimensionne() ***" << endl;
  if (GB_debug)
    cerr << "ami_wxGLCanvas::ReDimensionne( )" << endl;
  //glXWaitX();
  glViewport(0, 0, _largeur, _hauteur);
  _GLProjParam.SetWindowSize(_largeur,_hauteur);
  glMatrixMode(_GLTransform.GLenum_mode());

//  Recupere_fenetre_dimensions(&l, &h);
  //DessineFond();
  //AfficheBuffer();

//  Paint();
//  Update();
  Refresh(false);

  if (GB_debug) out << "*** end ami_wxGLCanvas::ReDimensionne() ***" << endl;
} // ReDimensionne()


// ------------------------------------------------------
void ami_wxGLCanvas::InitGL()
//                   ------
{
  if (GB_debug) out << "*** begin ami_wxGLCanvas::InitGL() ***" << endl;

  if (GB_debug) cerr << "InitGL() begin" << endl;
//    this->SetCurrentContext();
//    this->Show();
//  Show();
  if (!SetCurrentContext()) {
    cerr  << "ami_wxGLCanvas::InitGL()\t"
          << "SetCurrentContext() failed " << endl;
    return;
  }
//  InitGL();

  glRenderMode(GL_RENDER);

  EmpileMatrice();
  glLoadIdentity();
  _GLTransform.GetCurrentMatrix((GLdouble*) _current_matrix );

  _object_center[0] =
  _object_center[1] =
  _object_center[2] = 0.0;

    { // for help debugging, report any OpenGL errors that occur per frame
        GLenum error;
        while((error = glGetError()) != GL_NO_ERROR) {
            fprintf(stderr, "Constructeur GL error: %s\n",
            glErrorString(error).c_str());
            if (GB_debug) out << "!!! GL error " << glErrorString(error) << endl;
        }
    }


    _largeur = this->GetSize().GetWidth();
    _hauteur = this->GetSize().GetHeight();
    printf(" w x h = %d %d \n",_largeur,_hauteur);

    glViewport(0, 0, _largeur, _hauteur);

    _GLProjParam.SetWindowSize(_largeur,_hauteur);
    _GLProjParam.SetProjection();

    glMatrixMode(_GLTransform.GLenum_mode());

  if (GB_debug) cerr << "InitGL() end" << endl;

  if (GB_debug) out << "*** end ami_wxGLCanvas::InitGL() ***" << endl;

} // InitGL()

// -------------------------------------------------------------------------
//
void ami_wxGLCanvas :: Boutton_Presse()
//                         ---------------
{

  if (GB_debug) fprintf(stderr,"Boutton_Presse() begin \n");

  PickObjects();
  _souris_position_initiale_x = _souris_x;
  _souris_position_initiale_y = _souris_y;


  SelonQue _mouse_action Vaut
    Valeur MOUSE_MOVE_OBJECT:
      _Tobject.GetTranslation(_initial_translation);
    FinValeur
    Valeur MOUSE_MOVE_BASIS:
      _Tbasis.GetTranslation(_initial_translation);
    FinValeur
  FinSelonQue

  if (_mode_affichage==MODE_VOLREN)
    _Ttexture.GetTranslation(_initial_translation);

  if (GB_debug) fprintf(stderr,"Boutton_Presse() end \n");

} // Boutton_Presse()



// -------------------------------------------------------------------------
//
void ami_wxGLCanvas :: ShiftBout1_Presse()
//                         ---------------
{

    PickObjects();

} // ShiftBout1_Presse()


//-----------------------------------------------------
void ami_wxGLCanvas :: Boutton_Relache()
//                         ---------------
{
    float var_x;
    float var_y;
    GLdouble matrix[4][4];

  // First Reset initial values to compute displacements
  SelonQue _mouse_action Vaut
    Valeur MOUSE_MOVE_OBJECT:
      _Tobject.SetTranslation(_initial_translation);
    FinValeur
    Valeur MOUSE_MOVE_BASIS:
      _Tbasis.SetTranslation(_initial_translation);
    FinValeur
  FinSelonQue

  if (_mode_affichage==MODE_VOLREN)
    _Ttexture.SetTranslation(_initial_translation);


  var_y = _souris_y - _souris_position_initiale_y;
  var_x = _souris_x - _souris_position_initiale_x;
  //printf("%f %f \n",var_x,var_y);
  var_x = var_x / _largeur * 2.0;
  var_y = var_y / _hauteur * 2.0;
  //printf("Boutton_Relache() %d %d %f %f \n",_largeur,_hauteur,var_x,var_y);

  if (_mode_affichage==MODE_VOLREN) {
    glMatrixMode(GL_MODELVIEW);
    EmpileMatrice();
    glLoadIdentity();
    _Ttexture.GLApplyInvRotation();
    _Ttexture.GLApplyInvScale();
    glTranslatef( var_x, -var_y, 0.0);
    _Ttexture.GLApplyMatrix();
    glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
    DepileMatrice();
    _Ttexture.SetTranslation(matrix[3][0],
                 matrix[3][1],
                 matrix[3][2]);
  }

  // Calcul de la nouvelle translation de l'objet
  EmpileMatrice();

    glLoadIdentity();

    SelonQue _mouse_action Vaut

      Valeur MOUSE_MOVE_OBJECT:
        _Tobject.GLApplyInvRotation();
        _Tobject.GLApplyInvScale();
        _Tbasis.GLApplyInvMatrix();
        glTranslatef( var_x, -var_y, 0.0);
        _Tbasis.GLApplyMatrix();
        _Tobject.GLApplyMatrix();
    FinValeur

      Valeur MOUSE_MOVE_BASIS:
        _Tbasis.GLApplyInvRotation();
        _Tbasis.GLApplyInvScale();
        glTranslatef( var_x, -var_y, 0.0);
        _Tbasis.GLApplyMatrix();
      FinValeur

    FinSelonQue

    glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);

  DepileMatrice();

  SelonQue _mouse_action Vaut
    Valeur MOUSE_MOVE_OBJECT:
      if (GB_debug) cout << "  Setting new translation " <<  matrix[3][0]<< " ; " <<  matrix[3][1] << " ;" <<  matrix[3][2]<< endl;
      _Tobject.SetTranslation(matrix[3][0],
                  matrix[3][1],
                  matrix[3][2]);
      if (GB_debug) PrintMatrices();
    FinValeur
    Valeur MOUSE_MOVE_BASIS:
      _Tbasis.SetTranslation(matrix[3][0],
                 matrix[3][1],
                 matrix[3][2]);
    FinValeur
  FinSelonQue

//  Paint();

  Refresh(false);
  Update();


} // Boutton_Relache()


//---------------------------------------------------
void ami_wxGLCanvas :: DeplaceSourisBout1()
//                         ------------------
{

  Boutton_Relache();

/*
  SelonQue _mouse_action Vaut
    Valeur MOUSE_MOVE_OBJECT:
      _Tobject.SetTranslation(_initial_translation);
    FinValeur
    Valeur MOUSE_MOVE_BASIS:
      _Tbasis.SetTranslation(_initial_translation);
    FinValeur
  FinSelonQue

  if (_mode_affichage==MODE_VOLREN)
    _Ttexture.SetTranslation(_initial_translation);
*/
} // DeplaceSourisBout1()


//-------------------------------------------------------
void ami_wxGLCanvas :: Boutton2_Presse()
//                         --------------
{

  _souris_position_initiale_x = _souris_x;
  _souris_position_initiale_y = _souris_y;

  SelonQue _mouse_action Vaut
    Valeur MOUSE_MOVE_OBJECT:
      _Tobject.GetRotation(_initial_rotation);
    FinValeur
    Valeur MOUSE_MOVE_BASIS:
      _Tbasis.GetRotation(_initial_rotation);
    FinValeur
  FinSelonQue

  if (_mode_affichage==MODE_VOLREN)
    _Ttexture.GetRotation(_initial_rotation);

} // Boutton2_Presse()


//----------------------------------------------------------
void ami_wxGLCanvas :: DeplaceSourisShiftBout2()
//                         -----------------------
{
  _souris_position_initiale_x = (int) (_largeur/2.0);
  _souris_position_initiale_y = (int) (_hauteur/2.0);

  _animation_timer = boost::shared_ptr<wxTimer>(
      new wxTimer(this,Animation_Timer));
  _animation_timer->Start(20);

/*
  TantQue _animation == true Faire

    MAJ_rotation();

    // process one hundred events ...
    int i = 0;
    while ((i<100)&&(GB_wxApp->Pending())) {
      GB_wxApp->Dispatch();
      i++;
    }

  FinTantQue
*/

} // DeplaceSourisShiftBout2()




//---------------------------------------------------
//
void ami_wxGLCanvas :: MAJ_rotation()
//                         ----------------
{
    float var_x,var_x0;
    float var_y,var_y0;

  var_y0 = _souris_y - _souris_position_initiale_y;
  var_x0 = _souris_x - _souris_position_initiale_x;

  var_x = var_x0 / _largeur * 180.0;
  var_y = var_y0 / _hauteur * 180.0;

  if (_animation_timer.use_count())
  if (_animation_timer->IsRunning()) {
//     var_x = var_x0 / _largeur * 30.0;
    var_y = var_y0 / _hauteur * 30.0;

    Si fabsf(var_x) > fabsf(var_y) Alors
      var_y = 0;
    Sinon
      var_x = 0;
    FinSi
  }

  UserRotate(var_y,var_x,0);

  //Paint();

  Refresh(false);
  Update();


} // MAJ_rotation()


//-----------------------------------------------------
//
void ami_wxGLCanvas :: UserRotate( float rotX, float rotY, float rotZ)
//                         ----------
{
    GLdouble matrix[4][4];

  if (_mode_affichage==MODE_VOLREN) {
    glMatrixMode(GL_MODELVIEW);
    EmpileMatrice();
    glLoadIdentity();
    glRotatef(  rotX, 1.0, 0.0, 0.0);
    glRotatef(  rotY, 0.0, 1.0, 0.0);
    glRotatef(  rotZ, 0.0, 0.0, 1.0);
    _Ttexture.GLApplyRotation();
    glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
    DepileMatrice();
    _Ttexture.SetRotation(matrix);
  }

  // Calcul de la nouvelle rotation de l'objet
  EmpileMatrice();

    glLoadIdentity();

    SelonQue _mouse_action Vaut
      Valeur MOUSE_MOVE_OBJECT:
        _Tbasis.GLApplyInvRotation();
        glRotatef( rotX, 1.0, 0.0, 0.0);
        glRotatef( rotY, 0.0, 1.0, 0.0);
        glRotatef( rotZ, 0.0, 0.0, 1.0);
        _Tbasis.GLApplyRotation();
        _Tobject.GLApplyRotation();
        glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
      FinValeur
      Valeur MOUSE_MOVE_BASIS:
        glRotatef( rotX, 1.0, 0.0, 0.0);
        glRotatef( rotY, 0.0, 1.0, 0.0);
        glRotatef( rotZ, 0.0, 0.0, 1.0);
        _Tbasis.GLApplyRotation();
        glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
      FinValeur
    FinSelonQue

  DepileMatrice();

  SelonQue _mouse_action Vaut
    Valeur MOUSE_MOVE_OBJECT:
      _Tobject.SetRotation(matrix);
    FinValeur
    Valeur MOUSE_MOVE_BASIS:
      _Tbasis.SetRotation(matrix);
    FinValeur
  FinSelonQue

} // UserRotate()


//------------------------------------------------------
void ami_wxGLCanvas :: Boutton2_Relache()
//                         ----------------
{

  if (_animation_timer.use_count())
    if (_animation_timer->IsRunning())
      _animation_timer->Stop();

  // First reset initial values to compute the motion from them
  if (_mode_affichage==MODE_VOLREN)
    _Ttexture.SetRotation(_initial_rotation);

  SelonQue _mouse_action Vaut
    Valeur MOUSE_MOVE_OBJECT:
      _Tobject.SetRotation(_initial_rotation);
    FinValeur
    Valeur MOUSE_MOVE_BASIS:
      _Tbasis.SetRotation(_initial_rotation);
    FinValeur
  FinSelonQue

  MAJ_rotation();

} // Boutton2_Relache()


//--------------------------------------------------
void ami_wxGLCanvas :: DeplaceSourisBout2()
//                         ------------------
{

  // First reset initial values to compute the motion from them
  if (_mode_affichage==MODE_VOLREN)
    _Ttexture.SetRotation(_initial_rotation);

  SelonQue _mouse_action Vaut
    Valeur MOUSE_MOVE_OBJECT:
      _Tobject.SetRotation(_initial_rotation);
    FinValeur
    Valeur MOUSE_MOVE_BASIS:
      _Tbasis.SetRotation(_initial_rotation);
    FinValeur
  FinSelonQue

  MAJ_rotation();

/*
  if (_mode_affichage==MODE_VOLREN)
    _Ttexture.SetRotation(_initial_rotation);

  SelonQue _mouse_action Vaut
    Valeur MOUSE_MOVE_OBJECT:
      _Tobject.SetRotation(_initial_rotation);
    FinValeur
    Valeur MOUSE_MOVE_BASIS:
      _Tbasis.SetRotation(_initial_rotation);
    FinValeur
  FinSelonQue
*/

} // DeplaceSourisBout2()


// ----------------------------------------------------
void ami_wxGLCanvas :: Boutton3_Presse()
//                          --------------
{

  _souris_position_initiale_x = _souris_x;
  _souris_position_initiale_y = _souris_y;


  _initial_scale = _Tobject._scale[0];

  if (_mode_affichage==MODE_VOLREN)
    _initial_scale = _Ttexture._scale[0];

} // Boutton3_Presse()


// ---------------------------------------------------------
//
void ami_wxGLCanvas::Boutton3_Relache()
//                   ----------------
{

} // Boutton3_Relache()


//-----------------------------------------------------
void ami_wxGLCanvas :: DeplaceSourisBout3()
//                     ------------------
{
    int var_y;

  var_y = _souris_y - _souris_position_initiale_y;

  if (_mode_affichage==MODE_VOLREN)
    _Ttexture.SetScale( exp( -var_y/100.0)*_initial_scale );

  _Tobject.SetScale( exp( -var_y/100.0)*_initial_scale );

  Refresh(false);
  Update();

} // DeplaceSourisBout3()


// -------------------------------------------------------------------------
// Finds the objects at the position of the cursor
//
void ami_wxGLCanvas:: LineInfo( float x, float y, float z)
//                         --------
{

    SurfacePoly* lines;
    int l,p;
    Point3DPoly pt,pt0,pt1;
    int   selected_line = -1;
    float dist_min,dist;

  dist_min = 1E10;

  if (!_current_globject.use_count()) return;
  lines = (SurfacePoly*) _current_globject.get();
  if (lines==NULL) return;

  Pour(l,0,lines->GetNumberOfLines()-1)
    Si GB_debug AlorsFait printf("line %d nb points %d \n",
                 l,
                 lines->GetLine(l).NbElts());
    Pour(p,0,lines->GetLine(l).NbElts()-1)
      pt   = (*lines)[lines->GetLine(l)[p]];
      dist = sqrt((pt.X()-x)*(pt.X()-x)+
              (pt.Y()-y)*(pt.Y()-y)+
              (pt.Z()-z)*(pt.Z()-z));
      Si GB_debug AlorsFait printf("point %d (%f %f %f) dist %f \n",
                   p,pt.X(),pt.Y(),pt.Z(),dist);
      Si selected_line == -1 Ou dist<dist_min Alors
        dist_min = dist;
        selected_line = l;
        Si GB_debug AlorsFait printf("selected %d dist_min %f \n",
                     selected_line,dist_min);
      FinSi
    FinPour
  FinPour

  Si selected_line >= 0 Alors
    // Compute line length
    dist = 0;
    pt0   = (*lines)[lines->GetLine(selected_line)[0]];
    Pour(p,1,lines->GetLine(selected_line).NbElts()-1)
      pt1   = (*lines)[lines->GetLine(selected_line)[p]];
      dist += sqrt((pt1.X()-pt0.X())*(pt1.X()-pt0.X())+
           (pt1.Y()-pt0.Y())*(pt1.Y()-pt0.Y())+
           (pt1.Z()-pt0.Z())*(pt1.Z()-pt0.Z()));
      pt0 = pt1;
    FinPour

    printf("Closest line %d ",selected_line);
    printf(" Line Length = %f mm \n", dist);

    SelonQue _line_action Vaut

      Valeur LINE_INFO:
        lines->SetPickedLine(selected_line);
        lines->PrintPickedLine();
        lines->GLRecomputeList();
      FinValeur

      Valeur LINE_SELECT:
        lines->SelectLine(selected_line);
        lines->GLRecomputeList();
      FinValeur

      Valeur LINE_REMOVE:
        printf("Remove line \n");
        lines->RemoveLine(selected_line);
        lines->GLRecomputeList();
      FinValeur

    FinSelonQue

  FinSi
}


// -------------------------------------------------------------------------
// Finds the objects at the position of the cursor
//
void ami_wxGLCanvas :: PointInfo( float x, float y, float z)
//                     ---------
{
    SurfacePoly* lines;
    int l,p,i;
    Point3DPoly pt,pt0,pt1;
    int   selected_line  = -1;
    int   selected_point = -1;
    float dist_min=0,dist;


  Si GB_debug AlorsFait fprintf(stderr,"PointInfo() begin \n");

  if (!_current_globject.use_count()) return;
  lines = (SurfacePoly*) _current_globject.get();
  if (lines==NULL) return;

  if (lines->GetNumberOfLines()>0) {
    Pour(l,0,lines->GetNumberOfLines()-1)
      Si GB_debug AlorsFait printf("line %d nb points %d \n",
                   l,
                   lines->GetLine(l).NbElts());
      Pour(p,0,lines->GetLine(l).NbElts()-1)
        pt   = (*lines)[lines->GetLine(l)[p]];
        dist = sqrt((pt.X()-x)*(pt.X()-x)+
            (pt.Y()-y)*(pt.Y()-y)+
            (pt.Z()-z)*(pt.Z()-z));
        Si GB_debug AlorsFait printf("point %d (%f %f %f) dist %f \n",
                   p,pt.X(),pt.Y(),pt.Z(),dist);
        Si selected_line == -1 Ou dist<dist_min Alors
          dist_min = dist;
          selected_line  = l;
          selected_point = lines->GetLine(l)[p];
          Si GB_debug AlorsFait printf("line %d point %d dist_min %f \n",
                     selected_line,selected_point,dist_min);
        FinSi
      FinPour
    FinPour
  } else {
    // look up in the list of points
    Pour(i,0,lines->GetNumberOfPoints()-1)
        pt   = lines->GetPoint(i);
        dist = sqrt((pt.X()-x)*(pt.X()-x)+
            (pt.Y()-y)*(pt.Y()-y)+
            (pt.Z()-z)*(pt.Z()-z));
       Si selected_point == -1 Ou dist<dist_min Alors
          dist_min = dist;
          selected_point = i;
          Si GB_debug AlorsFait printf(" point %d dist_min %f \n",
                     selected_point,dist_min);
       FinSi
    FinPour
  }

  Si selected_point >= 0 Alors

    SelonQue _point_action Vaut

      Valeur POINT_INFO:
      //        lines->SetPickedLine( selected_line);
        lines->SetPickedPoint(selected_point);
        lines->GLRecomputeList();
      FinValeur

      Valeur POINT_SELECT:
      //        lines->SelectLine( selected_line);
        lines->SelectPoint(selected_point);
        lines->GLRecomputeList();
      FinValeur

      // Enligth minimal path from the last selected point
      Valeur POINT_MINPATH:
        lines->SelectMinPath(selected_point);
        lines->GLRecomputeList();
      FinValeur

    FinSelonQue

  FinSi

} // PointInfo()


// -------------------------------------------------------------------------
// Finds the objects at the position of the cursor
//
void ami_wxGLCanvas:: CCInfo( float x, float y, float z)
//                         ------
{
/* TODO

    SurfacePoly* surf;
    int          p;
    Point3DPoly  pt,pt0,pt1;
    int          selected_cc    = -1;
    int          selected_point = -1;
    float        dist_min,dist;

  dist_min = 1E10;

  Si GB_debug AlorsFait fprintf(stderr,"CCInfo() begin \n");

  surf = (SurfacePoly*) _current_globject.get();
  if (surf==NULL) return;

  Si Non(surf->_cc_calculees) AlorsFait surf->CalculCC();

  Pour(p,0,surf->GetNumberOfPoints()-1)
      pt   = (*surf)[p];
      dist = sqrt((pt.X()-x)*(pt.X()-x)+
              (pt.Y()-y)*(pt.Y()-y)+
              (pt.Z()-z)*(pt.Z()-z));
      Si selected_cc == -1 Ou dist<dist_min Alors
        dist_min = dist;
        selected_cc     = pt.GetCC();
        selected_point = p;
        Si GB_debug AlorsFait printf("cc %d point %d dist_min %f cc size %d\n",
                     selected_cc,selected_point,dist_min,
                     surf->GetCC(selected_cc).NbElts());
      FinSi
  FinPour

  Si selected_cc >= 0 Alors

    SelonQue _cc_action Vaut

      Valeur CC_INFO:
      //        surf->SetPickedLine( seleted_cc);
        surf->SetPickedCC(selected_cc);
        surf->GLRecomputeList();
      FinValeur

      Valeur CC_SELECT:
      //        surf->SelectLine( seleted_cc);
        surf->SelectCC(selected_cc);
        surf->GLRecomputeList();
      FinValeur

    FinSelonQue

  FinSi
*/
} // CCInfo()




//-------------------------------------------------------
// Finds the objects at the position of the cursor
//
void ami_wxGLCanvas :: PickObjects()
//                     -----------
{

  int hits;
  int i, j;
  GLuint names, *ptr, minZ,*ptrNames=NULL, numberOfNames = 0;

  if (_GLParam._background_type==BACKGROUND_GRADIENT) {
    fprintf(stderr,"No picking with gradient background for the moment !\n");
    return;
  }

  Si GB_debug AlorsFait printf("PickObjects() 1 \n");
  this->SetCurrentContext();
  Si GB_debug AlorsFait printf("PickObjects() 2 \n");

   glSelectBuffer(BUFSIZE,_selectBuf);
   glRenderMode(GL_SELECT);

   _GLProjParam.SetPicking(true);
   _GLProjParam.SetPickPosition(_souris_x, _souris_y);
  Si GB_debug AlorsFait printf("PickObjects() 3 \n");

  Refresh(false);
  Update();

  Si GB_debug AlorsFait printf("PickObjects() 4 \n");
   glFlush();

  Si GB_debug AlorsFait printf("PickObjects() 5 \n");
   // returning to normal rendering mode
   hits = glRenderMode(GL_RENDER);
   _GLProjParam.SetPicking(false);

  // Process hits


//  printf ("hits = %d\n", hits);

  Si hits>0 Alors
    ptr = (GLuint *) _selectBuf;
    minZ = 0xffffffff;
   for (i = 0; i < hits; i++) {
      names = *ptr;
      ptr++;
      //      printf("hit %d, min depth = %g , max depth %g \n",
      //     i,
      //         (*ptr)*1.0/(pow(2,32) -1) ,
      //     (*(ptr+1))*1.0/(pow(2,32) -1));


      //--------------------------------------------------
      // Unproject
      //
      {
    GLint viewport[4];
    GLdouble mvmatrix[16], projmatrix[16];
    GLint realy;  //  OpenGL y coordinate position
        GLdouble wx, wy, wz;  //  returned world x, y, z coords
        GLdouble ox, oy, oz;  //  returned object x, y, z coords

    glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev (GL_MODELVIEW_MATRIX, mvmatrix);
    glGetDoublev (GL_PROJECTION_MATRIX, projmatrix);

    //  note viewport[3] is height of window in pixels
    realy = viewport[3] - (GLint) _souris_y - 1;

    gluUnProject ((GLdouble) _souris_x, (GLdouble) realy,
              (*ptr)*1.0/(pow(2.0,32) -1),
              mvmatrix, projmatrix, viewport, &wx, &wy, &wz);

    //  printf ("World coords are (%f, %f, %f)\n",wx, wy, wz);

    // Object Coordinates
    GLdouble matrix[4][4];

    glPushMatrix();
    glLoadIdentity();
        _Tobject.GLApplyInvMatrix();
        _Tbasis.GLApplyInvMatrix();
        _Tfar.GLApplyInvMatrix();
    glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
    glPopMatrix();

    ox = matrix[0][0]*wx+ matrix[1][0]*wy + matrix[2][0]*wz + matrix[3][0];
    oy = matrix[0][1]*wx+ matrix[1][1]*wy + matrix[2][1]*wz + matrix[3][1];
    oz = matrix[0][2]*wx+ matrix[1][2]*wy + matrix[2][2]*wz + matrix[3][2];

    if (GB_verbose)  printf ("Object coords are (%f, %f, %f)\n",ox, oy, oz);

/* TODO
    Si _param_points_visible Alors
      PointInfo(ox,oy,oz);
        Autrement
        Si _param_cc_visible Alors
      CCInfo(ox,oy,oz);
    Sinon
*/
      if (_parent_window->_param_points->IsShown())
        PointInfo(ox,oy,oz);
      else
        LineInfo(ox,oy,oz);
//    FinSi
      }
      if (*ptr < minZ) {
        numberOfNames = names;
        minZ = *ptr;
        ptrNames = ptr+2;
      }

      ptr += names+2;
    }

    if (numberOfNames>0) {
      printf ("The closest hit names are ");
      ptr = ptrNames;
      for (j = 0; j < (int)numberOfNames; j++,ptr++) {
        printf ("%d ", *ptr);
      }
      printf ("\n");
    }
  FinSi


} // PickObjects()

