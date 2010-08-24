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
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.12 $
 * $Log: GLparam.hpp,v $
 * Revision 1.12  2006/01/12 12:50:42  karl
 * changing light colors, fixed vectors drawing for fluid, paint option for surfdraw in AMILab
 *
 * Revision 1.11  2006/01/11 13:42:39  karl
 * using GLdouble in GLTransfMatrix and read/write of matrix
 *
 * Revision 1.10  2005/12/19 19:41:34  karl
 * Fluid project visualization
 *
 * Revision 1.9  2005/11/16 15:51:03  karl
 * near --> _near and far --> _far
 *
 * Revision 1.8  2005/11/16 14:03:10  karl
 * added LGPL license
 *
 * Revision 1.7  2004/08/13 15:17:27  karl
 * fixed pb with CC and removed points in surface.cpp
 *
 * Revision 1.6  2004/06/24 04:46:19  karl
 * warnings and trying to unify texture and object matrices
 *
 * Revision 1.5  2004/06/18 23:37:37  karl
 * trying to set volume rendering rotation
 *
 * Revision 1.4  2004/06/17 21:37:32  karl
 * Changing the matrix operations
 *
 * Revision 1.3  2004/06/16 21:47:01  karl
 * Volume Rendering starting to work
 *
 * Revision 1.2  2004/04/30 20:10:16  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.2  2000/10/31 11:40:07  karl
 *
 * Option cullface activee par defaut
 * Option normalize activee par defaut
 * Couleur du fond plus claire
 * Inversion de la transformation scale si s>1E-6 au lieu de 1E-2
 *
 * Revision 1.2  2000/10/06 22:52:07  karl
 * *** empty log message ***
 *
 * Revision 1.1  2000/09/19 12:19:15  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:09:34  karl
 * Sources code
 *
 *
 ***************************************************************************/

#ifndef _GL_PARAM_HPP
#define _GL_PARAM_HPP

#ifdef WIN32
  #include <windows.h>
#endif

#if defined(__APPLE__)
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#include "couleur.hpp"
#include "DefineClass.hpp"
#include "inrimage.hpp"
//class ClasseCouleur;

#define GL_MODE_POINT       0
#define GL_MODE_LINE        1
#define GL_MODE_FILL        2
#define GL_MODE_FILL_LINE   3


#define GL_MODE_MODELVIEW  0
#define GL_MODE_PROJECTION 1

#define PROJ_ORTHO 0
#define PROJ_PERSP 1

#define FACE_FRONT          0
#define FACE_BACK           1
#define FACE_FRONT_AND_BACK 2


#define FOG_EXP    0
#define FOG_EXP2   1
#define FOG_LINEAR 2


#define SHADE_FLAT   0
#define SHADE_SMOOTH 1


#define DISPLAY_VECT_ORIENTATION 0
#define DISPLAY_VECT_DIRECTION   1
#define DISPLAY_VECT_ARROW       2


#define BACKGROUND_ONECOLOR 0
#define BACKGROUND_GRADIENT 1

#define COLORMATERIALMODE_EMISSION  0
#define COLORMATERIALMODE_AMBIENT   1
#define COLORMATERIALMODE_DIFFUSE   2
#define COLORMATERIALMODE_SPECULAR  3
#define COLORMATERIALMODE_AMBIENT_AND_DIFFUSE 4

#include "DefineClass.hpp"


class GLMaterialParam
//     ===============
{

public:

  unsigned char       _colormaterial;
  int           _colormaterial_mode;

  int        _face_ambient;
  ClasseCouleur _ambient;

  int        _face_diffuse;
  ClasseCouleur _diffuse;

  int        _face_specular;
  ClasseCouleur _specular;

  int        _face_emission;
  ClasseCouleur _emission;

  int        _face_shininess;
  float          _shininess;

  float          _opacity;


   GLMaterialParam()
  //
  {

    _colormaterial = false;
    _colormaterial_mode = COLORMATERIALMODE_AMBIENT_AND_DIFFUSE;

    _face_ambient  =
    _face_diffuse  =
    _face_specular =
    _face_emission = FACE_FRONT_AND_BACK;

    _ambient.FixeValeur( 50,  50,   50);
    _diffuse.FixeValeur( 200, 200, 200);
    _specular.FixeValeur(150, 150, 150);
    _emission.FixeValeur(0,   0,   0);

    _face_shininess = FACE_FRONT_AND_BACK;
    _shininess = 30.0;

    _opacity = 1.0;

  }

  ~GLMaterialParam()
  {  }

  GLenum GLenum_face( int face)
  {
    switch ( face ){
      case FACE_FRONT:           return GL_FRONT;
      case FACE_BACK:            return GL_BACK;
      case FACE_FRONT_AND_BACK:  return GL_FRONT_AND_BACK;
    } // end switch

    return GL_FRONT_AND_BACK;

  }


  void SetGLfloat( ClasseCouleur* coul, GLfloat* params)
  {
    params[0] = (GLfloat) (1.0*coul->Red()  / 256.0);
    params[1] = (GLfloat) (1.0*coul->Green()/ 256.0);
    params[2] = (GLfloat) (1.0*coul->Blue() / 256.0);
    params[3] = _opacity;

  }

  void GLSet();

}; // GLMaterialParam



//==================================================
class GLLightParam
//     ============
{

public:

  int        _num_light;

  unsigned char       _enabled;

  ClasseCouleur _ambient;
  ClasseCouleur _diffuse;
  ClasseCouleur _specular;

  GLfloat       _position[4];

  GLfloat       _spot_direction[3];

  unsigned char       _directional;

  ///
   GLLightParam( int light=0)
  //
  {

    _num_light = light;

    _enabled = false;
    _directional = true;

    _ambient.FixeValeur(100, 100, 100);
    _diffuse.FixeValeur(50,   50,  50);
    _specular.FixeValeur(155,155, 155);

    SetPosition(0.0,0.0,-1.0);

    SetSpotDirection(0.0,0.0,1.0);

    Si _directional Alors
      _position[3]= 0.0;
    Sinon
      _position[3]= 1.0;
    FinSi

  }

  ///
  virtual ~GLLightParam() {}
  //

  ///
  void SetPosition( float x, float y, float z)
  //
  {
    _position[0]= x;
    _position[1]= y;
    _position[2]= z;
  }

  ///
  void SetSpotDirection( float x, float y, float z)
  //
  {
    _spot_direction[0]= x;
    _spot_direction[1]= y;
    _spot_direction[2]= z;
  }


  void SetGLfloat( ClasseCouleur* coul, GLfloat* params)
  {
    params[0] = (GLfloat) (1.0*coul->Red()  / 256.0);
    params[1] = (GLfloat) (1.0*coul->Green()/ 256.0);
    params[2] = (GLfloat) (1.0*coul->Blue() / 256.0);
    params[3] = 1.0;

  }


  void GLSet()
  {


      GLfloat   params[4];
      GLenum    light;
      //      GLboolean enabled;

    light = GL_LIGHT0 + (unsigned short) _num_light;

    //    glGetBooleanv(light, &enabled);
    Si _enabled Alors
      //Si enabled == GL_false  AlorsFait
      glEnable( light);
    Sinon
      //Si enabled == GL_TRUE  AlorsFait
      glDisable( light);
      return;
    FinSi

    SetGLfloat(&_ambient, params);
    glLightfv(light,  GL_AMBIENT,  params);

    SetGLfloat(&_diffuse, params);
    glLightfv(light,  GL_DIFFUSE,  params);

    SetGLfloat(&_specular, params);
    glLightfv(light, GL_SPECULAR,  params);

    Si _directional Alors
      _position[3]= 0.0;
    Sinon
      _position[3]= 1.0;
    FinSi

    glLightfv(light, GL_POSITION,  _position);


    glLightfv(light, GL_SPOT_DIRECTION,  _spot_direction);


  }

  GLLightParam& operator=(const GLLightParam& l)
  {
    _enabled   = l._enabled;
    _ambient  = l._ambient;
    _diffuse  = l._diffuse;
    _specular = l._specular;
    _position[0] = l._position[0];
    _position[1] = l._position[1];
    _position[2] = l._position[2];

    _spot_direction[0] = l._spot_direction[0];
    _spot_direction[1] = l._spot_direction[1];
    _spot_direction[2] = l._spot_direction[2];

    _directional = l._directional;

    return (*this);
  }



}; // GLLightParam



class GLParam
//    =======
{

public:

  int  _GLmode;
  int  _line_width;
  int  _point_size;
  unsigned char _lighting;
  unsigned char _cullface;
//  unsigned char _colormaterial;
  unsigned char _dither;
  unsigned char _normalize;
  int  _shade_model;

  int     _background_type;
  ClasseCouleur _background;
  ClasseCouleur _bg_topleft;
  ClasseCouleur _bg_topright;
  ClasseCouleur _bg_botleft;
  ClasseCouleur _bg_botright;

  unsigned char _display_normals;

  int     _vector_type;

  unsigned char       _display_vect1;
  ClasseCouleur _vect1_color;
  float          _vect1_size;
  int        _vect1_width;
  std::string   _vect1_image_name;
  InrImage::ptr _vect1_image;

  unsigned char       _display_vect2;
  ClasseCouleur _vect2_color;
  float          _vect2_size;
  int        _vect2_width;
  std::string   _vect2_image_name;
  InrImage::ptr _vect2_image;

  int _current_bounding_box;


  GLenum GLenum_mode()
  {
    switch ( _GLmode ){
      case GL_MODE_POINT: return GL_POINT;
      case GL_MODE_LINE:  return GL_LINE;
      case GL_MODE_FILL:  return GL_FILL;
    } // end switch

    return GL_FILL;
  }

  GLenum GLenum_shade()
  {
    switch ( _shade_model ){
      case SHADE_FLAT:    return GL_FLAT;
      case SHADE_SMOOTH:  return GL_SMOOTH;
    } // end switch

    return GL_SMOOTH;
  }

  unsigned char CheckVector(int num)
  {
    switch (num) {
      case 1:   return (_vect1_image.use_count());
      case 2:   return (_vect2_image.use_count());
      default: return 0;
    }
    return 0;

  } // CheckVector()


  void SetVector(int num, const InrImage::ptr& im)
  {
    switch (num) {
    case 1:  _vect1_image = im;  break;
    case 2:  _vect2_image = im;  break;
    }
  } // SetVector

  InrImage::ptr GetVector(int num)
  {
    switch (num) {
    case 1: return _vect1_image; break;
    case 2: return _vect2_image; break;
    }
    return InrImage::ptr();
  }


  void ClearBackground()
  {
    float width, height;

    switch (_background_type) {
    case BACKGROUND_ONECOLOR:
      glClearColor( _background.Red()/255.0,
		    _background.Green()/255.0,
		    _background.Blue()/255.0,
		    1.0);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      break;
    case BACKGROUND_GRADIENT:
      width = height = 1;
      glDisable(GL_DEPTH_TEST);
      glDisable( GL_LIGHTING);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      glShadeModel(GL_SMOOTH);
      glPushMatrix();
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glOrtho(0,width,0,height,-1,1);
      // DrawBackground();
      glPushMatrix();
      glBegin(GL_POLYGON);

      glColor3ub(_bg_botleft.Red(),
		 _bg_botleft.Green(),
		 _bg_botleft.Blue());
      glVertex3f( 0,     0, -1.0);

      glColor3ub(_bg_botright.Red(),
		 _bg_botright.Green(),
		 _bg_botright.Blue());
      glVertex3f( width, 0, -1.0);

      glColor3ub(_bg_topright.Red(),
		 _bg_topright.Green(),
		 _bg_topright.Blue());
      glVertex3f( width,  height, -1.0);

      glColor3ub(_bg_topleft.Red(),
		 _bg_topleft.Green(),
		 _bg_topleft.Blue());
      glVertex3f( 0,      height, -1.0);

      glEnd();
      glPopMatrix();

      glClear(GL_DEPTH_BUFFER_BIT);

      glEnable(GL_DEPTH_TEST);
      glPopMatrix();
      break;
    }
  }


   GLParam()
  //           -------
  {

    _GLmode        = GL_MODE_FILL;
    _lighting      = true;
    _cullface      = true;
    _normalize     = true;
    _dither        = true;
    _shade_model   = SHADE_SMOOTH;
    _line_width    = 2;
    _point_size    = 2;
    _display_normals = false;

    _background_type = BACKGROUND_ONECOLOR;
    _background.FixeValeur( 255, 255, 255);
    _bg_topleft.FixeValeur(    0,   0, 200);
    _bg_topright.FixeValeur(   0,  50, 200);
    _bg_botleft.FixeValeur(  200,  50,   0);
    _bg_botright.FixeValeur( 200,   0,   0);

    _vector_type   = DISPLAY_VECT_ORIENTATION;

    _display_vect1 = false;
    _vect1_size    = 0.05f;
    _vect1_width   = 2;
    _vect1_color.FixeValeur(200, 50, 50);
    _vect1_image_name="";

    _display_vect2 = false;
    _vect2_size    = 0.05f;
    _vect2_width   = 2;
    _vect2_color.FixeValeur(50, 50, 200);
    _vect2_image_name="";

    _current_bounding_box=0;

  }


  virtual ~GLParam(){}

}; // GLParam


class GLTransform
//     ===========
{

public:

  int _GLmode;


  GLenum GLenum_mode()
  {
    switch ( _GLmode ){
      case GL_MODE_MODELVIEW:   return GL_MODELVIEW;
      case GL_MODE_PROJECTION:  return GL_PROJECTION;
    } // end switch

    return GL_MODELVIEW;
  }


   GLTransform()
  //           -----------
  {

    _GLmode = GL_MODE_MODELVIEW;

  }

  void GetCurrentMatrix( GLdouble* mat)
  //
  {

    switch ( _GLmode ){
      case GL_MODE_MODELVIEW:
        glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) mat);
      break;

      case GL_MODE_PROJECTION:
        glGetDoublev(GL_PROJECTION_MATRIX, (GLdouble*) mat);
      break;

    } // end switch

  }

}; // GLTransform


class GLProjParam
{

public:

  int type_proj;

  float left;
  float right;
  float bottom;
  float top;
  float _near;
  float _far;

  float eye_distance;
  float persp_near;

  int  win_width;
  int  win_height;

  unsigned char _picking;
  int     _pick_cursorx;
  int     _pick_cursory;

   GLProjParam();

  int   ProjectionType() { return type_proj; }
  float EyeDistance() { return eye_distance; }

  void SetPicking(unsigned char picking)
  {
    _picking = picking;
  }

  void SetPickPosition(int x, int y)
  {
    _pick_cursorx = x;
    _pick_cursory = y;
  }

  void SetWindowSize(int width, int height)
  {
    win_width  = width;
    win_height = height;
  }


  void SetProjection();

};



class GLFogParam
//
{

public:

  unsigned char   _enabled;
  int   _fogmode;

  ClasseCouleur _color;

  unsigned char        _use_bg_color;
  ClasseCouleur* _bg_color;

  float    _density;
  float    _start;
  float    _end;

   GLFogParam();


  void SetBGColor( ClasseCouleur* col)
  {
    //    _use_bg_color = val;
    _bg_color = col;
  }

  void SetGLfloat( ClasseCouleur* coul, GLfloat* params);
  /*
  {
    params[0] = (GLfloat) (1.0*coul->Red()  / 255.0);
    params[1] = (GLfloat) (1.0*coul->Green()/ 255.0);
    params[2] = (GLfloat) (1.0*coul->Blue() / 255.0);
    params[3] = 1.0;

  }
  */

  GLenum GLmode()
  {
    switch ( _fogmode ){
      case FOG_EXP:      return GL_EXP;
      case FOG_EXP2:     return GL_EXP2;
      case FOG_LINEAR:   return GL_LINEAR;
    } // end switch

    return GL_EXP;
  }


  void GLSet(float basis_far = 0.0)
  {


      GLfloat color[4];

    Si Non(_enabled) Alors
      glDisable(GL_FOG);
      return;
    FinSi

    glEnable(GL_FOG);

    glFogi(  GL_FOG_MODE,  GLmode());

    Si _use_bg_color Et _bg_color != NULL Alors
      SetGLfloat(_bg_color, color);
    Sinon
      SetGLfloat(&_color, color);
    FinSi

    glFogfv( GL_FOG_COLOR, color);

    glFogf(  GL_FOG_DENSITY, _density);
    glHint(  GL_FOG_HINT,    GL_DONT_CARE);
    glFogf(  GL_FOG_START,   basis_far+_start);
    glFogf(  GL_FOG_END,     basis_far+_end);
 }

  GLFogParam& operator=(const GLFogParam& f)
  {

     _enabled = f._enabled;
     _fogmode = f._fogmode;

     _density  = f._density;
     _start    = f._start;
     _end      = f._end;

     return (*this);
  }

}; // GLFogParam



class GLTransfMatrix
//
{
  DEFINE_CLASS(GLTransfMatrix);

public:

  // Dependance for comparison
  unsigned char _depend_T;
  unsigned char _depend_S;
  unsigned char _depend_R;

  GLdouble _matrix[4][4];

  GLfloat _translation[3];
  GLdouble _rotation[4][4];
  GLdouble _scale[3];

   GLTransfMatrix()
  //
  {

    SetIdentity();
    _depend_T = _depend_S = _depend_R = true;

  }

  void SetIdentity()
  //
  {


      int i,j;

    _translation[0] =
    _translation[1] =
    _translation[2] = 0.0;


    Pour(i,0,3)
    Pour(j,0,3)
      Si (i!=j) Alors
        _rotation[i][j] = 0.0;
      Sinon
        _rotation[i][j] = 1.0;
      FinSi
    FinPour
    FinPour

    _scale[0]=_scale[1]=_scale[2] = 1.0;

  }


  void SetTranslation( float x, float y, float z)
  //
  {
    _translation[0] = (GLfloat) x;
    _translation[1] = (GLfloat) y;
    _translation[2] = (GLfloat) z;
  }

  void SetTranslation(  GLfloat tr[3])
  //
  {
    _translation[0] = tr[0];
    _translation[1] = tr[1];
    _translation[2] = tr[2];
  }

  void GetTranslation( GLfloat tr[3])
  //
  {
    tr[0] = _translation[0];
    tr[1] = _translation[1];
    tr[2] = _translation[2];
  }


  void SetRotation( GLdouble mat[4][4])
  //
  {


      int i,j;

    Pour(i,0,3)
    Pour(j,0,3)
      _rotation[i][j] = mat[i][j];
    FinPour
    FinPour

  }

  void GetRotation( GLdouble mat[4][4])
  //
  {

      int i,j;

    Pour(i,0,3)
    Pour(j,0,3)
      mat[i][j] = _rotation[i][j];
    FinPour
    FinPour
  }


  void SetScale( float scalex, float scaley, float scalez)
  //
  {
    _scale[0]=scalex;
    _scale[1]=scaley;
    _scale[2]=scalez;
  }

  void SetScale( float scale)
  //
  {
    _scale[0]=_scale[1]=_scale[2] = scale;
  }

  float GetScale(int i=0 )
  //
  {
    return _scale[i];
  }

  void DecomposeMatrix()
  //
  {

  }


  void GLApplyMatrix()
  //
  {
    GLApplyScale();
    GLApplyRotation();
    GLApplyTranslation();
  }

  void GLApplyInvMatrix()
  //
  {
    GLApplyInvTranslation();
    GLApplyInvRotation();
    GLApplyInvScale();
  }


  void GLApplyScale()
  //
  {
    glScaled(_scale[0],_scale[1],_scale[2]);
  }


  void GLApplyInvScale()
  //
  {
    Si (fabs(_scale[0]) < 1E-9) Ou
       (fabs(_scale[1]) < 1E-9) Ou
       (fabs(_scale[2]) < 1E-9) Alors
      fprintf(stderr,"GLApplyInvScale() \t Error, Scale lower than 1E-9\n");
      return;
    FinSi
    glScaled(1.0/_scale[0],1.0/_scale[1],1.0/_scale[2]);
  }

  void GLApplyTranslation()
  //
  {
    glTranslatef(_translation[0],
		 _translation[1],
		 _translation[2]);
  }

  void GLApplyInvTranslation()
  //
  {
    glTranslatef( -_translation[0],
		  -_translation[1],
		  -_translation[2]);
  }

  void GLApplyRotation()
  //
  {
    glMultMatrixd((const GLdouble*) _rotation);
  }

  void GLApplyInvRotation()
  //
  {


      int i,j;
      GLdouble _inv_rot[4][4];

    Pour(i,0,3)
    Pour(j,0,3)
      _inv_rot[i][j] = _rotation[j][i];
    FinPour
    FinPour

    glMultMatrixd((const GLdouble*) _inv_rot);

  }


  GLdouble* GLGetMatrix()
  //
  {

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
      glLoadIdentity();
      GLApplyMatrix();
      glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble*) _matrix);
    glPopMatrix();

    return (GLdouble*) _matrix;

  }


  GLTransfMatrix& operator=(const GLTransfMatrix& t)
  {


      int i,j;

    Si _depend_R AlorsFait
    Pour(i,0,3)
    Pour(j,0,3)
      //      _matrix  [i][j] = t._matrix  [i][j];
      _rotation[i][j] = t._rotation[i][j];
    FinPour
    FinPour

    Si _depend_T AlorsFait
    Pour(i,0,2)
      _translation[i] = t._translation[i];
    FinPour

    Si _depend_S Alors
     _scale[0] = t._scale[0];
     _scale[1] = t._scale[1];
     _scale[2] = t._scale[2];
   FinSi

    return (*this);
  }

  void Print();

  void Save(FILE* f);

  void Load(FILE* f);

};

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<GLTransfMatrix> GLTransfMatrix_ptr;

#endif // _GL_PARAM_HPP
