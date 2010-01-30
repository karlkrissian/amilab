/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

// Visualisation 
// fichier TestGL.hpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 27-01-99
//

#ifndef _TESTGL_HPP
#define _TESTGL_HPP


#include "FenetreDessin.hpp"
//#include "inrimage.hpp"
//#include "BarreDefil.hpp"
#include "ParamBox.hpp"
#include "TypeParams.hpp"
#include "wxParamTypes.hpp"
#include "ErrorDialog.hpp"
#include "style.hpp"
#include "boutton.hpp"
#include "palette.hpp"

#include "Menu.hpp"

#include "TGA.h"

extern "C" {

#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL/glx.h>	      /* this includes the necessary X headers */


#include <math.h>
}


#include "GLparam.hpp"
#include "surface.hpp"
#include "DessinImageParam.hpp"

#include "TableauDyn.hpp"
#include "inrimage.hpp"
#include "isosurface.hpp"
#include "math1.hpp"

#include "VolumeRender.hpp"

//TableauDyn<point3Dreel>  tab_point3Dreel_init;

//#define MAX_PLANES 15

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


enum
{
    ID_MenuFile = 500,
    ID_MenuFile_LoadVRML,
    ID_MenuFile_Image,
    ID_MenuFile_Points,
    ID_MenuFile_SaveVRML,
    ID_MenuFile_ReLoad,
    ID_MenuFile_Close,
};


//============================================================================
class TestGL : public FenetreDessin
//     ------
{

/** @name Menu
 */

  
   wxMenuBar*  menuBar;
   wxMenu*     menuFile;


//@{
   ///
   KmMenu*           _menu;

//@{
   ///
   KmSousMenus*        _Mfichiers;
   ///
   KmSousMenu*           _Mfichiers_ouvrir;
   ///
   KmSousMenu*           _Mfichiers_surface;
   ///
   KmSousMenu*           _Mfichiers_image;
   ///
   KmSousMenu*           _Mfichiers_points;
   ///
   KmSousMenu*           _Mfichiers_sauver;
   ///
   KmSousMenu*           _Mfichiers_relire;
   ///
   ///
   KmSeparateur*         _Mfichiers_sep1;
   ///
   KmSousMenu*           _Mfichiers_sortir;
//@}

//@{
   ///
   KmSousMenus*        _Moptions;
   ///

   ///
   ParametreEnumeration* _Moptions_move;
   ///
   int                  _id_move_object;
   ///
   int                  _id_move_basis;


   ///
   ParametreEnumeration* _Moptions_GLmode;
   ///
   int                  _id_mode_points;
   ///
   int                  _id_mode_lines;
   ///
   int                  _id_mode_fill;

   ///
   ParametreEnumeration* _Moptions_shade;
   ///
   int                  _id_shade_flat;
   ///
   int                  _id_shade_smooth;

   ///
   KmSousMenu*           _Moptions_backgroundcolor;

   ///
   KmOptions*            _Moptions_lighting;

   ///
   ParametreCaractere*     _Moptions_lighting_enabled;

   ///
   ParametreCaractere*     _Moptions_cullface_enabled;

   ///
   ParametreCaractere*     _Moptions_normalize_enabled;

   ///
   ParametreCaractere*     _Moptions_display_basis;

   ///
   ParametreCaractere*     _Moptions_display_color_basis;

   ///
   ParametreCaractere*     _Moptions_display_normals;

   ///
   ParametreCaractere*     _Moptions_display_bb;

   ///
   ParametreCaractere*     _Moptions_dither;

   ///
//   ParametreCaractere*     _Moptions_colormaterial;

   ///
   ParametreCaractere*     _Moptions_material_visible;

   ///
   ParametreCaractere*     _Moptions_light_visible;

   ///
   ParametreCaractere*     _Moptions_surfvectors_visible;

   ///
   ParametreCaractere*     _Moptions_fog_visible;

   ///
   ParametreCaractere*     _Moptions_surf_visible;

   ///
   ParametreCaractere*     _Moptions_objets_visible;

   ///
   ParametreCaractere*     _Moptions_proj_visible;

   ///
   ParametreCaractere*     _Moptions_lines_visible;

   ///
   ParametreCaractere*     _Moptions_points_visible;

   /// Affichage de la plus grande composante connexe
   ParametreCaractere*     _Moptions_cc_visible;
//@}

//@{
   ///
   KmSousMenus*        _Mobjects;
   ///

   ///
   KmSousMenu*           _Mobjects_newparamsurf;

#define MAX_OBJECTS 10

   ///
   KmOptions*           _Mobjects_num[MAX_OBJECTS];

   unsigned char _object_visible[MAX_OBJECTS];

   ///
   ParametreCaractere*    _Mobjects_visible[MAX_OBJECTS];

//@}

//@{
   ///
   KmSousMenus*        _Maide;
   ///
   KmSousMenu*           _Maide_html;
   ///
   KmSousMenu*           _Maide_motcle;
   ///
   KmSousMenu*           _Maide_version;
//@}

//@}

/** name set of pixmap buttons 
 */
//@{

#define MAX_BUTTONS 10

  ///
  Widget _buttons_form;

  ///
  NoyauParametre* _tab_but[MAX_BUTTONS];

  ///
  int _nb_buttons;

  ///
  Widget        _buttonmenu_form;
  ///
  Widget        _last_button;

//@}


//@}

   ///
   unsigned char           _menu_visible;

/** @name     Ouverture d'une image
 */
//@{
   ParamBox*	_param_nom_image;
   int		_id_nom_image;
   std::string          _nom_nouvelle_image;

//@}

/** @name  Gestion des parametres des objets
*/
//@{

   ParamBox* _param_objets;

   int    _id_boutton_center;
   int    _id_boutton_normalize;

   int    _id_boutton_XY;
   int    _id_boutton_XZ;
   int    _id_boutton_YZ;

   int    _id_rotX_plus;
   int    _id_rotX_moins;

   int    _id_rotY_plus;
   int    _id_rotY_moins;

   int    _id_rotZ_plus;
   int    _id_rotZ_moins;

   int    _id_boutton_sauve;

   int       _id_scalex;
   int       _id_scaley;
   int       _id_scalez;

   int       _id_rot_X;
   int       _id_rot_Y;
   int       _id_rot_Z;


   int       _id_boutton_fermer;

   int       _etat_param_objets;

//@}

  unsigned char _param_objets_visible;

  unsigned char _plus_grande_cc;


/** @name  Gestion des parametres des objets
*/
//@{

   ParamBox* _param_proj;
 
   int    _id_type_proj;
   int      _id_proj_ortho;
   int      _id_proj_persp;

   int    _id_left;
   int    _id_right;
   int    _id_bottom;
   int    _id_top;
   int    _id_near;
   int    _id_far;

   int    _id_persp_near;
   int    _id_persp_far;

   int    _id_basis_far;

   int    _id_proj_fermer;

   int    _etat_param_proj;

//@}

  unsigned char _param_proj_visible;

/** @name  Background Color
*/
//@{

   ParamBox* _param_backgroundcolor;
 
   int   _id_backgroundtype;
   int     _id_bg_onecolor;
   int     _id_bg_gradient;

   int   _id_backgroundcolor;

   int   _id_bg_tl; // top left color
   int   _id_bg_tr; // top right color
   int   _id_bg_bl; // bottom left color
   int   _id_bg_br; // bottom right color

   int   _id_bc_close;

   int    _etat_param_backgroundcolor;

//@}


/** @name  Surface Vectors param
*/
//@{

   ParamBox* _param_surfvectors;
 
   int   _id_vecttype;
   int    _id_vecttype_orient;
   int    _id_vecttype_dir;

   int   _id_vect1image;
   int   _id_display_vect1;
   int   _id_vect1color;
   int   _id_vect1size;
   int   _id_vect1width;

   int   _id_vect2image;
   int   _id_display_vect2;
   int   _id_vect2color;
   int   _id_vect2size;
   int   _id_vect2width;

   int   _id_surfvectors_fermer;

   int    _etat_param_surfvectors;

//@}

  unsigned char       _param_surfvectors_visible;


/** @name  Lines param
*/
//@{

   ParamBox* _param_lines;
 
   int   _id_line_action;
   int    _id_line_info;
   int    _id_line_select;
   int    _id_line_remove;
   int    _id_line_connect;
   int    _id_line_junction;


   int   _id_lines_remove_selection;
   int   _id_lines_remove_non_selected;
   int   _id_lines_connect_selection;
   int   _id_lines_new_selection;
   int   _id_lines_save_selection;
   int   _id_lines_undo;

   int   _id_lines_width;
   int   _id_lines_color;

   int   _id_lines_fermer;

   int    _etat_param_lines;

//@}

  unsigned char       _param_lines_visible;

/** @name  Points param
*/
//@{

   ParamBox* _param_points;
 
   int   _id_point_action;
   int    _id_point_info;
   int    _id_point_select;
   int    _id_point_remove;
   int    _id_point_connect;
   int    _id_point_junction;


   int   _id_points_remove_selection;
   int   _id_points_remove_non_selected;
   int   _id_points_connect_selection;
   int   _id_points_new_selection;
   int   _id_points_save_selection;

   int   _id_points_width;
   int   _id_points_color;

   int   _id_points_fermer;

   int    _etat_param_points;

//@}

  unsigned char       _param_points_visible;

/** @name  Connected Components param
*/
//@{

   ParamBox* _param_cc;
 
   int   _id_cc_action;
   int    _id_cc_info;
   int    _id_cc_select;
   int    _id_cc_remove;

   int   _id_cc_remove_selection;
   int   _id_cc_remove_non_selected;
   int   _id_cc_connect_selection;
   int   _id_cc_new_selection;
   int   _id_cc_save_selection;

   int   _id_cc_width;
   int   _id_cc_color;

   int   _id_cc_fermer;

   int    _etat_param_cc;

//@}

  unsigned char       _param_cc_visible;

/** @name  Gestion des parametres des objets
*/
//@{

   ParamBox* _param_material;
 
   int   _id_object_number;

   int   _id_display_object;
   int   _id_point_size;
   int   _id_line_width;

   int   _id_colormaterial;

   int   _id_colormaterial_mode;
   int    _id_colormaterial_emission;
   int    _id_colormaterial_ambient;
   int    _id_colormaterial_diffuse;
   int    _id_colormaterial_specular;
   int    _id_colormaterial_ambient_and_diffuse;

   int   _id_mat_ambient;
   int   _id_mat_diffuse;
   int   _id_mat_specular;
   int   _id_mat_emission;
   int   _id_mat_shininess;

   int   _id_mat_opacity;

   int   _id_mat_fermer;

   int    _etat_param_material;

//@}

  unsigned char _param_material_visible;


/** @name  Gestion des parametres des objets
*/
//@{

   ParamBox* _param_light;

   int   _id_light_number;
 
   int   _id_light_enabled;

   int   _id_light_ambient;
   int   _id_light_diffuse;
   int   _id_light_specular;

   int   _id_light_position_x;
   int   _id_light_position_y;
   int   _id_light_position_z;

   int   _id_light_directional;

   int   _id_light_valider;
   int   _id_light_fermer;

   int    _etat_param_light;

//@}

  unsigned char _param_light_visible;

//@{

  ParamBox* _param_fog;

  int   _id_fog_enabled;

  int   _id_fog_mode;
  int     _id_mode_exp;
  int     _id_mode_exp2;
  int     _id_mode_linear;

  int   _id_fog_use_backgroundcolor;
  int   _id_fog_color;
  int   _id_fog_density;
  int   _id_fog_start;
  int   _id_fog_end;

  int   _id_fog_fermer;

  int    _etat_param_fog;

//@}

  unsigned char _param_fog_visible;

//@{

  ParamBox* _param_surf;

  int   _id_surf_couleurs;

  int   _id_surf_alpha;

  int   _id_surf_umin;
  int   _id_surf_umax;
  int   _id_surf_vmin;
  int   _id_surf_vmax;

  int   _id_surf_valider;
  int   _id_surf_fermer;

  int    _etat_param_surf;

//@}

  unsigned char   _param_surf_visible;
  std::string _nom_image_couleurs;
  float      _surf_alpha;

//const

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
  GLMaterialParam _GLMaterial_display;
  unsigned char         _current_object_visible;

  int          _light_number;
  GLLightParam    _GLLight[MAX_LIGHTS];
  GLLightParam    _GLLight_display;

  GLFogParam      _GLFogParam;

  int  _mouse_action;

  unsigned char _animation;

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


   Error_Dialog*  _message_erreur;
   int         _etat_message;

   //-----------------------------------------------------
   //------ Fenetre d'affichage de l'image

   ParametreLabel* _label_souris;
   char       _label_texte[100];

   unsigned char      _MAJ_intensite;

   //-----------------------------------------------------
   //------ Gestion des parametres

//   float         _a;
//   float         _b;


   // Variables pour le dessin de la position du curseur
   unsigned char      _curseur_ON;
   int       _curseur_x, _curseur_y, _curseur_z; 


   //-----------------------------------------------------

   Surface       _surf;

#define MAX_GLOBJECTS 50
   GLObject*     _globject[MAX_GLOBJECTS];
   unsigned char       _globject_allocated[MAX_GLOBJECTS];
   int        _num_globjects;
//   GLObject*     _current_globject;
   int        _current_globject_num;

#define CURRENT_GLOBJECT GetGLObject(_current_globject_num)

#define STATIC_CURRENT_GLOBJECT(tgl) tgl->GetGLObject(tgl->_current_globject_num)

   int        _type_surface;


#define MAX_COMP_SURF 10

  TestGL*       _compare_surf[MAX_COMP_SURF];
  unsigned char       _compare_surf_active[MAX_COMP_SURF];

/** @name  Parametric Surface
*/
//@{

   ParamBox* _param_paramsurf;
 
   int   _id_umin;
   int   _id_umax;
   int   _id_nbpts_u;
   int   _id_close_u;

   int   _id_vmin;
   int   _id_vmax;
   int   _id_nbpts_v;
   int   _id_close_v;

   int   _id_expr_X;
   int   _id_expr_Y;
   int   _id_expr_Z;

   int    _etat_param_paramsurf;

//@}

   //--------------------------------------------------
   // Expression mathematique
   //
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
//===========

  // Check if the object exist,
  // and if the link is still valid (inheritance from the class DefineClass)
  // if the link is not valid, remove the object from the list.
  // return NULL if the object is not accessible
  GLObject*  GetGLObject(int i);

public:
  
   TestGL( Widget AParent, char* ATitle, 
                            int type = CREATE_GLWINDOW);

  ~TestGL();

  ///
  void CreeMenu();

  ///
  void Create_wxMenu();

  ///
  void FreeMenu();

  ///
  void FreeParamWindows();

  ///
  void FreePixmaps();

  ///
  void CreatePixmapButtons();

  ///
  void CreeParametresObjets();

  ///
  void CreeParametresProj();

  ///
  void CreeParametresMaterial();

  ///
  void CreeParametresBackgroundColor();

  ///
  void CreeParametresParamSurf();

  ///
  void CreeParametresLight();

  ///
  void CreeParametresFog();

  ///
  void CreeParametresSurf();

  ///
  void CreeParametresSurfvectors();

  ///
  void CreeParametresLines();

  ///
  void CreeParametresPoints();

  ///
  void CreeParametresCC();

  void DessineFond();

  void EmpileMatrice(  );

  void DepileMatrice(  );

  void AfficheBuffer();

  void InitSurface();

  void ComputeParamSurface();

  int  GetCurrentObjectNum();

  int  AddGLObject( );

  unsigned char SetCurrentGLObject( int i);

  void ChargeIsosurface( Chaine nom_fichier);

  void SetSurface   ( SurfacePoly* surf);

  void RemoveSurface( SurfacePoly* surf);

  void SetGLList( GLuint list, float pmin[3], float pmax[3]);

  void SetVectors1( InrImage* v1);
  void SetVectors2( InrImage* v2);

  void LitVRML( Chaine nom_fichier);

  void CreeIsosurface( InrImage* image, float seuil, InrImage* mask = NULL );

  void SetColors( InrImage* image, float min, float max);

  void CreeImageSurface( InrImage* image, int planZ, float zscale,
			 float min, float max);

  // Dessin d'une composante connexe de la surface
  void DessineSurfaceCC( int cc);

  // Choose to draw or not a given connex component
  void DessineSurfaceCC( int cc, unsigned char draw);

  void CreeVoxels3D( InrImage* image, float seuilbas, float seuilhaut,
		     float Imin, float Imax,
		     float sx, float sy, float sz);

  void CreeGLMIP( InrImage* image, float seuilbas, float seuilhaut,
		  float Imin, float Imax,
		  float sx, float sy, float sz,
		  int max_quads);

  void InitVolRen( InrImage* image,
		   float Imin, float Imax, DessinImageBase* di,
		   InrImage* opacity=NULL);

  VolumeRender* GetVolRen() { return _volren; }

  void PrintMatrices() {
    printf("\nFAR:\n");
    _Tfar.Print();
    printf("\nBASIS:\n");
    _Tbasis.Print();
    printf("\nOBJECT:\n");
    _Tobject.Print();
    printf("\nTEXTURE:\n");
    _Ttexture.Print();    
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


  void LitPoints( Chaine nom_fichier);

  void InitProprietes();

  void DessineSurface();

  float FonctionSurface(float u, float v);

  void DessineSurface2();

  void DisplayObject(int);
  void DisplayObjects();

  void NewVolumeVectors1();
  void NewVolumeVectors2();

  void DisplayOneColorVector( GLfloat center[3], 
			      GLfloat dirx, GLfloat diry, GLfloat dirz,
			      int vector_type);
  void GetVectorColor( float vx, float vy, float vz, GLubyte colors[3]);

  void DisplayVolumeVectors1();
  void DisplayVolumeVectors2();

  void DessineVoxels3D();
  void DessineGLMIP();
  void DrawVolRen();

  void DessineSections();

  void DisplayBasis();

  void DisplayVectorColors();

  void SetCursor( float x, float y, float z, unsigned char display =true);
  void DisplayCursor();

  void AddCompSurf( TestGL* comp_surf);

  GLTransfMatrix& GetObjectTransform( )
  {
    return this->_Tobject;
  }

  void SetBG(int r, int g, int b) {
    this->_GLParam._background.FixeValeur(r,g,b);
  }


  void SetObjectTransform( const GLTransfMatrix& obj_transf);
  void SetFog(             const GLFogParam&     f);
  void CompSurfPaint();
  GLLightParam& GetLight(int n) {
    if (n<MAX_LIGHTS) 
      return _GLLight[n];
    else
      return _GLLight[0];
  }

  void Paint( unsigned char affiche = true );

  void Normalize();

  void Center();

  InrImage* GetGLImage();

  void ReDimensionne();

  void InitGL();

  void AfficheFenetre();

  void SauveImageTGA(char* nom_image);

//  void CreeDrawingArea();

//  void CreateContext();
//  void FreeContext();

  void Boutton_Presse();
  void ShiftBout1_Presse();
  void Boutton_Relache();
  void DeplaceSourisBout1();


  void MAJ_rotation();
  void UserRotate( float rotX, float rotY, float rotZ);
  void Boutton2_Presse();
  void Boutton2_Relache();
  void DeplaceSourisBout2();

  void DeplaceSourisShiftBout2();

  void Boutton3_Presse();
  void Boutton3_Relache();
  void DeplaceSourisBout3();

  // Look for the closest line 
  void LineInfo( float x, float y, float z);

  // Look for the closest point 
  void PointInfo( float x, float y, float z);

  // Look for the closest connected component
  void CCInfo( float x, float y, float z);

  // Pick objects
  void PickObjects();

  ///
  void SwapMenuVisible();

  ///
  void SwapInfoVisible();

  ///
  void TouchePressee( KeySym keysym);

 
  static void CB_Ouvrir( Widget, void* cd, void*);

  static void CB_Ouvrir_surface( Widget, void* cd, void*);

  static void CB_Ouvrir_image( Widget, void* cd, void*);

  static void CB_Ouvrir_points( Widget, void* cd, void*);

  static void CB_Sauver( Widget, void* cd, void*);


  static void CB_redessine( void* cd );

  ///
  static void CB_Center( Widget, void* cd, void*);

  ///
  static void CB_Normalize( Widget, void* cd, void*);

  ///
  static void CB_CenterNormalize( Widget, void* cd, void*);

  ///
  static void CB_XY_proj( Widget, void* cd, void*);

  ///
  static void CB_XZ_proj( Widget, void* cd, void*);

  ///
  static void CB_YZ_proj( Widget, void* cd, void*);

  ///
  static void CB_rotX_plus( Widget, void* cd, void*);
  ///
  static void CB_rotY_plus( Widget, void* cd, void*);
  ///
  static void CB_rotZ_plus( Widget, void* cd, void*);

  ///
  static void CB_rotX_moins( Widget, void* cd, void*);
  ///
  static void CB_rotY_moins( Widget, void* cd, void*);
  ///
  static void CB_rotZ_moins( Widget, void* cd, void*);

  ///
  static void CB_SauveImage( Widget, void* cd, void*);

  ///
  static void CB_object_number( void* cd);

  ///
  static void CB_material_visible( void* cd);

  ///
  static void CB_material_update( void* cd);

  ///
  static void CB_material_fermer(Widget, void* cd, void*);

  ///
  static void CB_BackgroundColor( Widget, void* cd, void*);

  ///
  static void CB_BackgroundColorClose( Widget, void* cd, void*);

  ///
  static void CB_light_number( void* cd);

  ///
  static void CB_light_visible( void* cd);

  ///
  static void CB_pixmap_light_visible( void* cd);

  ///
  static void CB_light_valider(Widget, void* cd, void*);

  ///
  static void CB_light_update( void* cd);

  ///
  static void CB_light_fermer(Widget, void* cd, void*);

  ///
  static void CB_vect1_image( void* cd);

  ///
  static void CB_vect2_image( void* cd);

  ///
  static void CB_surfvectors_visible( void* cd);

  ///
  static void CB_lines_visible( void* cd);

  ///
  static void CB_points_visible( void* cd);

  ///
  static void CB_cc_visible( void* cd);

  ///
  static void CB_recompute_allvect( void* cd);

  ///
  static void CB_recompute_vect1( void* cd);

  ///
  static void CB_recompute_vect2( void* cd);

  ///
  static void CB_surfvectors_fermer(Widget, void* cd, void*);

  ///
  static void CB_lines_remove(Widget, void* cd, void*);

  ///
  static void CB_lines_remove_non_selected(Widget, void* cd, void*);

  ///
  static void CB_lines_connect(Widget, void* cd, void*);

  ///
  static void CB_lines_new(Widget, void* cd, void*);

  ///
  static void CB_lines_save_selection(Widget, void* cd, void*);

  ///
  static void CB_lines_undo(Widget, void* cd, void*);

  ///
  static void CB_lines_fermer(Widget, void* cd, void*);

  ///
  static void CB_points_remove(Widget, void* cd, void*);

  ///
  static void CB_points_remove_non_selected(Widget, void* cd, void*);

  ///
  static void CB_points_connect(Widget, void* cd, void*);

  ///
  static void CB_points_new(Widget, void* cd, void*);

  ///
  static void CB_points_save_selection(Widget, void* cd, void*);

  ///
  static void CB_points_fermer(Widget, void* cd, void*);

  ///
  static void CB_cc_remove(Widget, void* cd, void*);

  ///
  static void CB_cc_remove_non_selected(Widget, void* cd, void*);

  ///
  static void CB_cc_new(Widget, void* cd, void*);

  ///
  static void CB_cc_save_selection(Widget, void* cd, void*);

  ///
  static void CB_cc_fermer(Widget, void* cd, void*);

  ///
  static void CB_fog_visible( void* cd);

  ///
  static void CB_pixmap_fog_visible( void* cd);

  ///
  static void CB_fog_use_bg_color( void* cd);

  ///
  static void CB_fog_fermer(Widget, void* cd, void*);

  ///
  static void CB_surf_couleurs( void* cd );

  ///
  static void CB_surf_valider(Widget, void* cd, void*);

  ///
  static void CB_surf_visible( void* cd);

  ///
  static void CB_surf_fermer(Widget, void* cd, void*);

  ///
  static void CB_objets_visible( void* cd);

  ///
  static void CB_pixmap_objets_visible( void* cd);

  ///
  static void CB_objets_fermer( Widget, void* cd, void*);

  ///
  static void CB_proj_param( void* cd);

  ///
  static void CB_proj_type( void* cd);

  ///
  static void CB_proj_visible( void* cd);

  ///
  static void CB_pixmap_proj_visible( void* cd);

  ///
  static void CB_plus_grande_cc( void* cd);

  ///
  static void CB_proj_fermer(Widget, void* cd, void*);

  ///
  static void CB_newparamsurf( Widget, void* cd, void*);

  ///
  static void CB_Expose( 	Widget, void*, void* );
  ///
  static void CB_Input( 	Widget, void*, void* );
  ///
  static void CB_Resize( 	Widget, void*, void* );

}; // TestGL
//============================================================================

#endif // _TESTGL_HPP
