/////////////////////////////////////////////////////////////////////////////
// Name:        isosurf.h
// Purpose:     wxGLCanvas demo program
// Author:      Brian Paul (original gltk version), Wolfram Gloger
// Modified by: Julian Smart
// Created:     04/01/98
// RCS-ID:      $Id: isosurf.h,v 1.5 2004/10/06 20:53:53 ABX Exp $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _AMI_WXGLCANVAS_H_
#define _AMI_WXGLCANVAS_H_

#ifdef WIN32
  #include <windows.h>
#endif

#include "inrimage.hpp"

#include "DefineClass.hpp"
#include <list>

#if defined(__APPLE__)
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#ifdef __GNUG__
#pragma implementation
#pragma interface
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if !wxUSE_GLCANVAS
    #error "OpenGL required: set wxUSE_GLCANVAS to 1 and rebuild the library"
#endif

#include "wx/glcanvas.h"
#include "wx/sizer.h"

#if wxUSE_GLCANVAS
#include "wx/glcanvas.h"
#include "wx/sizer.h"



// disabled because this has apparently changed in OpenGL 1.2, so doesn't link
// correctly if this is on...
#ifdef GL_EXT_vertex_array
#undef GL_EXT_vertex_array
#endif


#include "GLparam.hpp"
#include "inrimage.hpp"
#include "isosurface.hpp"
#include "surface.hpp"
using namespace amilab;


#include <fstream>
//#include <boost/iostreams/device/file.hpp>
//#include <boost/iostreams/stream.hpp>

#define MAX_LIGHTS 8

#define MOUSE_MOVE_OBJECT 0
#define MOUSE_MOVE_BASIS  1

#define SURFACE_NONE 0
#define SURFACE_U_V  1
#define SURFACE_POLY 2
#define POINTS_3D    3


#define LINE_INFO     0
#define LINE_SELECT   1
#define LINE_REMOVE   2
#define LINE_CONNECT  3
#define LINE_JUNCTION 4
//#define LINE_UNDO     5


#define POINT_INFO     0
#define POINT_SELECT   1
#define POINT_REMOVE   2
#define POINT_CONNECT  3
#define POINT_JUNCTION 4
#define POINT_MINPATH  5

#define CC_INFO     0
#define CC_SELECT   1
#define CC_REMOVE   2

#define MODE_SURFACE 0
#define MODE_VOXELS  1
#define MODE_GLMIP   2
#define MODE_VOLREN  3


#define VECTFIELDCOL_CONST  0
#define VECTFIELDCOL_RGB    1
#define VECTFIELDCOL_RGBCYM 2

class ParamZoom;
class VolumeRender;
class DessinImageBase;
class Viewer3D;

typedef shared_ptr<wxGLContext> wxGLContext_ptr;

/**
  OpenGL viewer for 3D polydata objects
 */
class ami_wxGLCanvas:  public wxGLCanvas
{

  DEFINE_CLASS(ami_wxGLCanvas)

protected:
  // TODO : remove this class and manage the comparing windows from this class !!!
  Viewer3D*       _parent_window;
  wxGLContext_ptr _opengl_context;

public:

  bool            _is_created;
  bool            _initialized;

//  std::iostreams::stream_buffer<boost::iostreams::file_sink>* buf; //("ami_wxGLCanvas_trace.txt");
  std::ofstream                     out; //(&buf);

  GLboolean       doubleBuffer;

  GLTransfMatrix _Tfar;
  GLTransfMatrix _Tbasis;
  GLTransfMatrix _Tobject;
  GLTransfMatrix _Ttexture;

  GLfloat _current_matrix[4][4];

  GLfloat _object_center[3];

  // Image from which the isosurface was extracted
// InrImage* _image;
  unsigned char _limits_set;
  float    _xmin, _ymin, _zmin;
  float    _xmax, _ymax, _zmax;


  // Lines info
  int _line_action;

  // Points info
  int _point_action;

  // CC info
  int _cc_action;

  int _mode_affichage; // MODE_SURFACE ou MODE_VOXELS ou MODE_GLMIP or MODE_VOLREN


  GLuint _ISOSURFACE;
  GLuint _LINES;
  GLuint _SURFVECTORS; // vectors on the surfaces

  GLuint _VOLVECTORS1; // vectors on the volume
  GLuint _VOLVECTORS2; // vectors on the volume

  unsigned char _display_volvectors1;
  unsigned char _display_volvectors2;

  int     _vectfieldcol_type;

  GLuint _SURFACE;
  GLuint _VOXELS;
  GLuint _GLMIP;
  GLuint _VOLREN;

  GLuint  _SECTION[3];
  unsigned char _section_visible[3];
  int     _section_pos[3];

  // allow 10 free section for playing with AMILab
#define MAX_FREE_SECTIONS 10
  GLuint  _FREE_SECTION        [MAX_FREE_SECTIONS];
  unsigned char _free_section_visible[MAX_FREE_SECTIONS];

  GLuint _REPERE;
  GLuint _VECTOR_COLORS;
  GLuint _CURSOR;

  GLfloat ctlpoints[4][4][3];

//  GLUnurbsObj *theNurb;

  float scale;

  float _scale_x;
  float _scale_y;
  float _scale_z;

  float _translate_x;
  float _translate_y;
  float _translate_z;


  GLParam         _GLParam;

  GLTransform     _GLTransform;
  GLProjParam     _GLProjParam;
  GLMaterialParam _GLMaterial;

  int          _light_number;
  GLLightParam    _GLLight[MAX_LIGHTS];
  GLLightParam    _GLLight_display;

  GLFogParam      _GLFogParam;

  int  _mouse_action;

  boost::shared_ptr<wxTimer>  _animation_timer;

  unsigned char _display_basis;
  unsigned char _display_color_basis;
  unsigned char _display_bounding_box;
  unsigned char _display_cursor;

  float    _cursor_x;
  float    _cursor_y;
  float    _cursor_z;

  unsigned char AvionEnPapierCree;

   ///
   int _souris_position_initiale_x;
   ///
   int _souris_position_initiale_y;

   //
   float   _initial_scale;

   //
   GLfloat _initial_translation[3];

   //
   GLdouble _initial_rotation[4][4];


   // Variables pour le dessin de la position du curseur
   unsigned char      _curseur_ON;
   int       _curseur_x, _curseur_y, _curseur_z;


   //-----------------------------------------------------

   Surface       _surf;

   GLObject::ptr_list  _globject;
   GLObject::ptr       _current_globject;

   int        _type_surface;

   unsigned char _plus_grande_cc;
   int _largeur;
   int _hauteur;
   int _souris_x;
   int _souris_y;

   //--------------------------------------------------
   // Expression mathematique
   //
/*
   float       _u_min,_u_max;
   int     _nbpoints_u;
   unsigned char    _close_u;
   float       _v_min,_v_max;
   int     _nbpoints_v;
   unsigned char    _close_v;
   ExprMath*  X_Expression;
   ExprMath*  Y_Expression;
   ExprMath*  Z_Expression;

   std::string     XExprString;
   std::string     YExprString;
   std::string     ZExprString;
*/
   //---------------------------------------------------
   // Picking parameters
   //
#define BUFSIZE 512
  GLuint   _selectBuf[BUFSIZE];

  //--------------------------------------------------
  // Volume Rendering
  //
  VolumeRender* _volren;

private:

public:
    ami_wxGLCanvas(wxWindow *parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = _T("ami_wxGLCanvas"));

  virtual ~ami_wxGLCanvas()
  {
    if (out.is_open()) out.close();
  };

  bool SetCurrentContext();

  void DessineFond();
  void EmpileMatrice(  );
  void DepileMatrice(  );
  void AfficheBuffer();
//  void InitSurface();
//  void ComputeParamSurface();

  void UpdateObjectList();

  GLObject::ptr  GetGLObject(int i);
  int           GetCurrentObjectNum();
  int           SetCurrentObject( int i);
//  void ChargeIsosurface( Chaine nom_fichier);

  void AddSurface   ( SurfacePoly::ptr surf);

  void RemoveSurface( SurfacePoly::ptr surf);

  void SetVectors1( InrImage::ptr v1);
  void SetVectors2( InrImage::ptr v2);

//  void LitVRML( Chaine nom_fichier);
  SurfacePoly::ptr CreeIsosurface(  InrImage::ptr image, float seuil, InrImage* mask = NULL );
  void SetColors(  InrImage* image, float min, float max);

  void CreeImageSurface(  InrImage::ptr image, int planZ, float zscale,
             float min, float max);
  // Dessin d'une composante connexe de la surface
  void DessineSurfaceCC( int cc);
  // Choose to draw or not a given connex component
  void DessineSurfaceCC( int cc, unsigned char draw);


  void CreeVoxels3D( InrImage* image, float seuilbas, float seuilhaut,
             float Imin, float Imax,
             float sx, float sy, float sz);

  void CreeGLMIP( InrImage::ptr image, float seuilbas, float seuilhaut,
          float Imin, float Imax,
          int max_quads);

  void InitVolRen( InrImage* image,
           float Imin, float Imax, DessinImageBase* di,
           InrImage::ptr opacity);

  VolumeRender* GetVolRen() { return _volren; }

  void PrintMatrices() {
/*
    printf("\nFAR:\n");
    _Tfar.Print();
    printf("\nBASIS:\n");
    _Tbasis.Print();
*/
    printf("\nOBJECT:\n");
    _Tobject.Print();
/*
    printf("\nTEXTURE:\n");
    _Ttexture.Print();
*/
  }

  void SetLimits( float xmin, float xmax, float ymin, float ymax, float zmin, float zmax)
  {
    _xmin=xmin;
    _xmax=xmax;
    _ymin=ymin;
    _ymax=ymax;
    _zmin=zmin;
    _zmax=zmax;
    _limits_set = 1;
  }

  void InitSection( InrImage* image,
            int section,
            int pos,
            unsigned char active,
            float Imin, float Imax,
            ParamZoom zoom
            );

  void ShowFreeSection( int num,
            InrImage* image,
            int orientation, // 0, 1 or 2
            int pos,
            float Imin, float Imax
            );

  void HideFreeSection( int num);

/*
  void LitPoints( Chaine nom_fichier);
*/
  void InitProprietes();
  void DessineSurface();
  void DessineSurface2();

  void DisplayObject(GLObject::ptr& obj);
  void DisplayObjects();

  void NewVolumeVectors1();
  void NewVolumeVectors2();
/*
  void DisplayOneColorVector( GLfloat center[3],
                  GLfloat dirx, GLfloat diry, GLfloat dirz,
                  int vector_type);
  void GetVectorColor( float vx, float vy, float vz, GLubyte colors[3]);

  void DisplayVolumeVectors1();
  void DisplayVolumeVectors2();

*/
  void DessineVoxels3D();
  void DessineGLMIP();
  void DrawVolRen();

  void DessineSections();
  void DisplayBasis();


//  void DisplayVectorColors();

  void SetCursor( float x, float y, float z, unsigned char display =true);

  void DisplayCursor();

  GLTransfMatrix& GetObjectTransform( )
  {
    return this->_Tobject;
  }

  void SetBG(int r, int g, int b) {
    this->_GLParam._background.FixeValeur(r,g,b);
  }

  void SetObjectTransform( const GLTransfMatrix& obj_transf);
  void SetFog(             const GLFogParam&     f);

  GLLightParam& GetLight(int n) {
    if (n<MAX_LIGHTS)
      return _GLLight[n];
    else
      return _GLLight[0];
  }

  void Paint( const bool& affiche = true );
  void Normalize();
  void Center();

  InrImage* GetGLImage();

  void ReDimensionne();
  void InitGL();
/*
  void AfficheFenetre();

*/

  void TranslationStart();
  void TranslationMotion();
  void TranslationEnd();

  void ApplyPicking();

  void MAJ_rotation();
  void UserRotate( float rotX, float rotY, float rotZ);

  void RotationStart();
  void RotationMotion();
  void RotationEnd();
  void AnimateRotation();

  void ZoomStart();
  void ZoomEnd();
  void ZoomMotion();

  void ApplyZoomFactor(double factor);

  // Look for the closest line
  void LineInfo( float x, float y, float z);

  // Look for the closest point
  void PointInfo( float x, float y, float z);

  // Look for the closest connected component
  void CCInfo( float x, float y, float z);

  // Pick objects
  void PickObjects();

  void OnPaint(          wxPaintEvent& event);
  void OnSize(           wxSizeEvent& event);
  void OnEraseBackground(wxEraseEvent& event);
  void OnChar(           wxKeyEvent& event);
  void OnMouseEvent(     wxMouseEvent& event);
  void OnAnimationTimer( wxTimerEvent& event);

  #ifndef WIN32
    void onCreate(wxWindowCreateEvent& event);
  #endif

    DECLARE_EVENT_TABLE()
};

#endif // #if wxUSE_GLCANVAS
#endif // #ifndef_AMI_WXGLCANVAS_H_

