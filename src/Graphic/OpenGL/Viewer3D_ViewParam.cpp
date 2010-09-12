
//#include "3DViewParameters.h"
#include "Viewer3D.hpp"
#include "ParamPanel.hpp"
#include "Viewer3D_ViewParam.h"

// Pixmaps for setting 3D view
#include "center.xpm"
#include "normalize.xpm"
#include "XY.xpm"
#include "XZ2.xpm"
#include "YZ2.xpm"
#include "rot_x1.xpm"
#include "rot_y1.xpm"
#include "rot_z1.xpm"
#include  "rot_x2.xpm"
#include  "rot_y2.xpm"
#include  "rot_z2.xpm"


Viewer3D_ViewParam::Viewer3D_ViewParam(Viewer3D* parent):
    ParamPanel(parent->GetParamBook(),"View")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("View and Orientation Control"));
}

void Viewer3D_ViewParam::CreateParameters()
{

  BeginHorizontal();
    //----------------
    AddPixmapButton( 
                    &_id_boutton_center,  "Center",
                    (void*)CB_Center, (void*)parent_class,
                    center_string,
                    "Center the scene");
    // Set proportional position
    SetLastPositionProperties(1);
  
    //----------------
    AddPixmapButton( 
                    &_id_boutton_normalize,  
                    "Normalize",
                    (void*)CB_Normalize, 
                    (void*)parent_class,
                    normalize_string,
                    "Normalize the view to fit in the display");
    // Set proportional position
    SetLastPositionProperties(1);
  
  EndHorizontal();
  BeginHorizontal();
    //----------------
    AddPixmapButton( &_id_boutton_XY,  
                    "XY projection",
                    (void*)CB_XY_proj, 
                    (void*)parent_class,
                    XY_string,
                    "XY projection");
    // Set proportional position
    SetLastPositionProperties(1);
  
    AddPixmapButton( &_id_boutton_XZ,  "XZ projection",
                    (void*)CB_XZ_proj, 
                    (void*)parent_class,
                    XZ2_string,
                    "XZ projection");
    // Set proportional position
    SetLastPositionProperties(1);
  
    AddPixmapButton( &_id_boutton_YZ,  "YZ projection",
                    (void*)CB_YZ_proj, 
                    (void*)parent_class,
                    YZ2_string,
                    "YZ projection");
    // Set proportional position
    SetLastPositionProperties(1);
  EndHorizontal();
  BeginHorizontal();
    //----------------
    AddPixmapButton( &_id_rotX_plus,  "rot X +",
                    (void*)CB_rotX_plus, 
                    (void*)parent_class,
                    rot_x1_string);
    // Set proportional position
    SetLastPositionProperties(1);
  
    AddPixmapButton( &_id_rotY_plus,  "rot Y +",
                    (void*)CB_rotY_plus, 
                    (void*)parent_class,
                    rot_y1_string);
    // Set proportional position
    SetLastPositionProperties(1);
  
    AddPixmapButton( &_id_rotZ_plus,  "rot Z +",
                  (void*)CB_rotZ_plus, 
                  (void*)parent_class,
                  rot_z1_string);
    // Set proportional position
    SetLastPositionProperties(1);
  EndHorizontal();

  BeginHorizontal();
    //----------------
    AddPixmapButton( &_id_rotX_moins,  "rot X -",
                (void*)CB_rotX_moins, 
                (void*)parent_class,
                rot_x2_string);
    // Set proportional position
    SetLastPositionProperties(1);
  
    AddPixmapButton( &_id_rotY_moins,  "rot Y -",
                (void*)CB_rotY_moins, 
                (void*)parent_class,
                rot_y2_string);
    // Set proportional position
    SetLastPositionProperties(1);
  
    AddPixmapButton( &_id_rotZ_moins,  "rot Z -",
                (void*)CB_rotZ_moins, 
                (void*)parent_class,
                rot_z2_string);
    // Set proportional position
    SetLastPositionProperties(1);
  EndHorizontal();

  //----------------
  AddButton( &_id_boutton_sauve,  
			   "save as animation",
		           (void*)CB_SauveImage, 
			   (void*)parent_class);


  //--------------
  EnleveBouttons();

  CreeDialogue( );
  ReAfficheParametres( );
  MAJ();
}



//----------------------------------------------------
void Viewer3D_ViewParam::CB_Center( void* cd)
//                       ---------
{
    Viewer3D* tgl = (Viewer3D*) cd;

  tgl->m_canvas->Center();
  tgl->m_canvas->Paint();
} // CB_Center()


//----------------------------------------------------
void Viewer3D_ViewParam::CB_Normalize( void* cd)
//                ---------
{
    Viewer3D* tgl = (Viewer3D*) cd;

  tgl->m_canvas->Normalize();
  tgl->m_canvas->Paint();
} // CB_Normalize()


//--------------------------------------------------
void Viewer3D_ViewParam::CB_CenterNormalize( void* cd)
//                        ---------
{
  	Viewer3D* tgl = (Viewer3D*) cd;

  tgl->m_canvas->Center();
  tgl->m_canvas->Normalize();
  tgl->m_canvas->Paint();

} // CB_CenterNormalize()


//---------------------------------------------------------------------
void Viewer3D_ViewParam::CB_XY_proj( void* cd)
//                        ---------
{
    Viewer3D* tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* glc = tgl->m_canvas;
    GLdouble    matrix[4][4];

  // Calcul de la nouvelle rotation de l'objet
  glc->EmpileMatrice();
    glLoadIdentity();
    glRotatef(180.0,1.0,0.0,0.0);
//    glRotatef(180.0,0.0,0.0,1.0);
    glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
  glc->DepileMatrice();

  switch ( glc->_mouse_action ){
    case MOUSE_MOVE_OBJECT:
      glc->_Tobject.SetRotation(matrix);
    break;
    case MOUSE_MOVE_BASIS:
      glc->_Tbasis.SetRotation(matrix);
    break;
  } // end switch

  glc->Paint();

} // CB_XY_proj()

//-----------------------------------------------------
void Viewer3D_ViewParam::CB_XZ_proj( void* cd)
//                        ---------
{
    Viewer3D* tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* glc = tgl->m_canvas;
    GLdouble    matrix[4][4];

  // Calcul de la nouvelle rotation de l'objet
  glc->EmpileMatrice();
    glLoadIdentity();
    glRotatef(90.0,1.0,0.0,0.0);
    glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
  glc->DepileMatrice();

  switch ( glc->_mouse_action ){
    case MOUSE_MOVE_OBJECT:
      glc->_Tobject.SetRotation(matrix);
    break;
    case MOUSE_MOVE_BASIS:
      glc->_Tbasis.SetRotation(matrix);
    break;
  } // end switch

  glc->Paint();

} // CB_XY_proj()


//---------------------------------------------------------------------
void Viewer3D_ViewParam::CB_YZ_proj( void* cd)
//                        ---------
{
    Viewer3D* tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* glc = tgl->m_canvas;
    GLdouble    matrix[4][4];

  // Calcul de la nouvelle rotation de l'objet
  glc->EmpileMatrice();
    glLoadIdentity();
    glRotatef(90.0,0.0,1.0,0.0);
    glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
  glc->DepileMatrice();

  switch ( glc->_mouse_action ){
    case MOUSE_MOVE_OBJECT:
      glc->_Tobject.SetRotation(matrix);
    break;
    case MOUSE_MOVE_BASIS:
      glc->_Tbasis.SetRotation(matrix);
    break;
  } // end switch

  glc->Paint();

} // CB_XY_proj()


//----------------------------------------------------
void Viewer3D_ViewParam::CB_rotX_plus( void* cd)
{
  Viewer3D* tgl = (Viewer3D*) cd;
  ami_wxGLCanvas* glc = tgl->m_canvas;

  glc->UserRotate(45,0,0);
  glc->Paint();

} //  CB_rotX_plus()


//---------------------------------------------------
void Viewer3D_ViewParam::CB_rotY_plus( void* cd)
{
    Viewer3D* tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* glc = tgl->m_canvas;

  glc->UserRotate(0,45,0);
  glc->Paint();
} //  CB_rotY_plus()


//---------------------------------------------------
void Viewer3D_ViewParam::CB_rotZ_plus( void* cd)
{
    Viewer3D* tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* glc = tgl->m_canvas;

  glc->UserRotate(0,0,45);
  glc->Paint();

} //  CB_rotZ_plus()


//---------------------------------------------------
void Viewer3D_ViewParam::CB_rotX_moins(  void* cd)
{
    Viewer3D* tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* glc = tgl->m_canvas;

  glc->UserRotate(-45,0,0);
  glc->Paint();

} //  CB_rotX_moins()


//-----------------------------------------------------
void Viewer3D_ViewParam::CB_rotY_moins( void* cd)
{
    Viewer3D* tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* glc = tgl->m_canvas;

  glc->UserRotate(0,-45,0);
  glc->Paint();
} //  CB_rotY_moins()


//----------------------------------------------------
void Viewer3D_ViewParam::CB_rotZ_moins( void* cd)
{
    Viewer3D* tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* glc = tgl->m_canvas;

  glc->UserRotate(0,0,-45);
  glc->Paint();
} //  CB_rotZ_moins()


//-----------------------------------------------------
void Viewer3D_ViewParam::CB_SauveImage( void* cd)
//                       -------------
{
  wxMessageDialog* msg = new wxMessageDialog(NULL,
      wxString::FromAscii("This feature is not available at the moment."),
      wxString::FromAscii("Info"),wxOK | wxICON_INFORMATION | wxSTAY_ON_TOP  );
  msg->ShowModal();
  msg->Destroy();
// TODO: check segmentation fault in this code ... and improve its interface
/*    Viewer3D* tgl = (Viewer3D*) cd;
    ami_wxGLCanvas* glc = tgl->m_canvas;
    int i;
    int var_x, var_y;
    GLdouble matrix[4][4];


    GLint dim[4];
    int x, y, n;
    int l, h;
    unsigned char* pixels_r;
    unsigned char* pixels_g;
    unsigned char* pixels_b;
    InrImage* anim;
    InrImage* anim_r;


  glGetIntegerv( GL_VIEWPORT, dim );
  l = glc->_largeur;
  h = glc->_hauteur;

  printf(" _largeur %d _hauteur %d dim= { %d %d %d %d } \n", 
         l,h,dim[0], dim[1], dim[2], dim[3]);

  pixels_r = (unsigned char*) malloc (l*h);
  pixels_g = (unsigned char*) malloc (l*h);
  pixels_b = (unsigned char*) malloc (l*h);
  anim = new InrImage(l,h,90,WT_RGB,"anim.inr.gz");
  anim->InitImage(0,0,0);

  anim_r = new InrImage(l,h,90,WT_UNSIGNED_CHAR,"anim_r.inr.gz");
  anim_r->InitImage(0);

  var_x = 4;
  var_y = 0;

  // Sauvegarde des rotations
  Pour(i,1,90)

    Si i==1 Alors
      printf("rot = %3d",(int) i*var_x);fflush(stdout);
    Sinon
      printf("\b\b\b%3d",(int) i*var_x);fflush(stdout);
    FinSi

    // faire la rotation de 4 degres

    // Calcul de la nouvelle rotation de l'objet
    glc->EmpileMatrice();

      glLoadIdentity();

      switch ( glc->_mouse_action ){
        case MOUSE_MOVE_OBJECT:
          glc->_Tbasis.GLApplyInvRotation();
          glRotatef( var_x, 0.0, 1.0, 0.0);
          glRotatef( var_y, 1.0, 0.0, 0.0);
          glc->_Tbasis.GLApplyRotation();
          glc->_Tobject.GLApplyRotation();
          glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
        break;
        case MOUSE_MOVE_BASIS:
          glRotatef( var_x, 0.0, 1.0, 0.0);
          glRotatef( var_y, 1.0, 0.0, 0.0);
          glc->_Tbasis.GLApplyRotation();
          glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) matrix);
        break;
      } // end switch

    glc->DepileMatrice();

    switch ( glc->_mouse_action ){
      case MOUSE_MOVE_OBJECT:
        glc->_Tobject.SetRotation(matrix);
      break;
      case MOUSE_MOVE_BASIS:
        glc->_Tbasis.SetRotation(matrix);
      break;
    } // end switch

   glc->Paint();

//   sprintf(nom_image,"anim.%d.tga",i);


    glReadPixels( (GLint) 0,    (GLint) 0, 
	          (GLsizei) l,  (GLsizei) h,
		  GL_RED,       GL_UNSIGNED_BYTE,
	          (GLvoid*) pixels_r);
    glReadPixels( (GLint) 0,    (GLint) 0, 
	          (GLsizei) l,  (GLsizei) h,
		  GL_GREEN,       GL_UNSIGNED_BYTE,
	          (GLvoid*) pixels_g);
    glReadPixels( (GLint) 0,    (GLint) 0, 
	          (GLsizei) l,  (GLsizei) h,
		  GL_BLUE,       GL_UNSIGNED_BYTE,
	          (GLvoid*) pixels_b);

    n = 0;
    Pour(y,0,h-1)
    Pour(x,0,l-1)
      anim_r->BufferPos(x,h-1-y,i-1);
      anim  ->BufferPos(x,h-1-y,i-1);
      anim_r->FixeValeur(pixels_r[n]);
      anim  ->VectFixeValeurs(pixels_r[n], 
			      pixels_g[n], 
			      pixels_b[n]);
      n++;
    FinPour
    FinPour

  FinPour


  free( pixels_r);
  free( pixels_g);
  free( pixels_b);

  anim->Sauve();
  anim_r->Sauve();

  delete anim;
  delete anim_r;
*/
} // CB_SauveImage()


