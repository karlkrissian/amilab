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
 * $Revision: 1.19 $
 * Revision 1.9  2000/11/08 16:23:23  karl
 * *** empty log message ***
 *
 * Revision 1.8  2000/10/31 11:47:24  karl
 * *** empty log message ***
 *
 * Revision 1.7  2000/10/30 13:10:06  karl
 * *** empty log message ***
 *
 * Revision 1.6  2000/10/30 12:59:16  karl
 *
 * Vue surfacique d'une image
 *
 * Revision 1.2  2000/10/06 22:52:07  karl
 * *** empty log message ***
 *
 * Revision 1.4  2000/10/03 10:12:37  karl
 * *** empty log message ***
 *
 * Revision 1.3  2000/10/03 10:10:54  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/10/02 16:57:20  karl
 * *** empty log message ***
 *
 * Revision 1.1  2000/09/19 12:19:16  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:09:34  karl
 * Sources code
 *
 *
 ***************************************************************************/

#include "dijkstra.h"


#ifndef _WITHOUT_VTK_
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkFloatArray.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPolyDataWriter.h> 
#include <vtkPolyDataReader.h> 
#include <vtkTriangleFilter.h>
#endif // _WITHOUT_VTK_

#include "vtk_common.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "StringUtils.hpp"

#include "surface.hpp"
#include "ami_wxGLCanvas.hpp"
#include "style.hpp"

//#include "FloatMatrix.hpp"

extern unsigned char      GB_debug;
extern unsigned char      GB_verbose;

//extern std::ostream  out;


#define my_glGenLists(a,b) \
  { \
    if (GB_debug) \
      cerr << format("%1% = glGenLists( %2% ); // value %3% ") % #a %b % a << endl; \
    a=glGenLists(b);\
  }

#define my_glNewLists(a,b) \
  { \
    if (GB_debug) \
      cerr << format("%1% = glNewLists( %2%); // value %3% ") % #a %b % a << endl; \
    a=glNewLists(b);\
  }

#define my_glNewList(a,b) \
  { \
    if (GB_debug) \
      cerr << format("glNewList( %1%, %2%);") % #a %b << endl; \
    glNewList(a,b); \
  }

#define my_glDeleteLists(a,b) \
  { \
    if (GB_debug) \
      cerr << format("glDeleteLists(%1%,%2%);") % a % b << endl; \
      glDeleteLists(a,b);\
  }

#define my_glBegin_GL_TRIANGLE_FAN  {\
  if (GB_debug) \
     cerr << "glBegin(GL_TRIANGLE_FAN);" << endl; \
  glBegin(GL_TRIANGLE_FAN); }
 
#define my_glEnd  {\
  if (GB_debug) \
     cerr << "glEnd();" << endl; \
  glEnd(); }
 
#define my_glEndList  {\
  if (GB_debug) \
     cerr << "glEndList();" << endl; \
  glEndList(); }
 

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

#define  glReportErrors() \
  { \
    /* for help debugging, report any OpenGL errors that occur per frame */ \
        GLenum error; \
        while((error = glGetError()) != GL_NO_ERROR) { \
            if (GB_debug) cerr << "!!! GL error at " \
              << __FILE__  \
              << " function " << __func__ \
              <<" line " << __LINE__ \
              << ": " << glErrorString(error) << endl; \
        } \
  }

//======================================================================
//  GLObject
//======================================================================


//----------------------------------------------------------
int  GLObject::MakeContextCurrent()
//
{

  GLint render_mode;

  if (GB_debug) cerr << " begin GLObject::MakeContextCurrent() " << endl;
//  if (_context==NULL) return 0;
  if (!_wxGL_canvas) {
    cerr << "GLObject::MakeContextCurrent() \t_wxGL_canvas not initialized " << endl;
    return 0;
  }

  // pb here: can not get the render mode
  // before setting the current context!

  glGetIntegerv(GL_RENDER_MODE,&render_mode);
  switch (render_mode) {
  case GL_RENDER: 
    if (_wxGL_canvas) {
      // TODO: use SetCurrentContext from myGLCanvas instead ???

      bool res = _wxGL_canvas->SetCurrentContext();

      if (GB_debug) cerr << " end 1 GLObject::MakeContextCurrent() " << endl;
      return res;
    }
    break;
  case GL_SELECT: return 1;
  default: cerr << "GLObject::MakeCurrentContext()"
                << " render mode " << render_mode
                << " not treated "
                << " GL_RENDER =  " << GL_RENDER
                << " GL_SELECT =  " << GL_SELECT
                << endl;
          glRenderMode(GL_RENDER);
          bool res = _wxGL_canvas->SetCurrentContext();
          if (GB_debug) cerr << " end 2 GLObject::MakeContextCurrent() " << endl;
          return res;
  }

  if (GB_debug) cerr << " end 3 GLObject::MakeContextCurrent() " << endl;
  return 0;

  
}

//----------------------------------------------------------------------
void GLObject :: DisplayBB()
//
{

   
    GLint linewidth;
    GLboolean light_enabled;

//  printf("GLObject::DisplayBB() %u \n", _display_bb);

  if (!MakeContextCurrent()) return;
  Si Non(_display_bb) AlorsFait return;


  Si _bounding_box == 0 Alors
    my_glGenLists(_bounding_box,1);
    my_glNewList(_bounding_box, GL_COMPILE);   
      glColor3f(0.1,   0.7, 0.2);
      glBegin(GL_LINE_LOOP);
        glVertex3f(_xmin, _ymin, _zmin);
        glVertex3f(_xmin, _ymax, _zmin);
        glVertex3f(_xmax, _ymax, _zmin);
        glVertex3f(_xmax, _ymin, _zmin);
      my_glEnd;
      glBegin(GL_LINE_LOOP);
        glVertex3f(_xmin, _ymin, _zmax);
        glVertex3f(_xmin, _ymax, _zmax);
        glVertex3f(_xmax, _ymax, _zmax);
        glVertex3f(_xmax, _ymin, _zmax);
      my_glEnd;
      glBegin(GL_LINES);
        glVertex3f(_xmin, _ymin, _zmin);
        glVertex3f(_xmin, _ymin, _zmax);
        glVertex3f(_xmin, _ymax, _zmin);
        glVertex3f(_xmin, _ymax, _zmax);
        glVertex3f(_xmax, _ymax, _zmin);
        glVertex3f(_xmax, _ymax, _zmax);
        glVertex3f(_xmax, _ymin, _zmin);
        glVertex3f(_xmax, _ymin, _zmax);
      my_glEnd;
    glEndList();
    
  FinSi

  glGetIntegerv(GL_LINE_WIDTH, &linewidth);
  glLineWidth(3);
  glGetBooleanv(GL_LIGHTING, &light_enabled);
  glDisable(GL_LIGHTING);

  glCallList(_bounding_box);

  Si light_enabled AlorsFait glEnable(GL_LIGHTING);
  glLineWidth(linewidth);

} // DisplayBB()


//----------------------------------------------------------------------
void GLObject  :: DisplayObject(GLMaterialParam* mat)
//
{

   
    GLMaterialParam* theMat;
    GLboolean light_enabled;

  Si GB_debug AlorsFait fprintf(stderr,"GLObject DisplayObject() begin\n");
  if (!MakeContextCurrent()) return;
  Si GB_debug AlorsFait fprintf(stderr,"GLObject DisplayObject() 1\n");
  if (GB_debug) fprintf(stderr,"ownmaterial %d \n",(int)_ownmaterial);
  Si _ownmaterial Alors 
    theMat = &_material;
  Sinon
    theMat = mat;
  FinSi

  DisplayBB();

  Si _display Alors
 
    glLineWidth(_line_width);
    glPointSize(_point_size);

    Si _ownmaterial Alors 
      glGetBooleanv(GL_LIGHTING, &light_enabled);
      Si _enable_light Alors
        glEnable(GL_LIGHTING);
      Sinon
        glDisable(GL_LIGHTING);
      FinSi
    FinSi

    Si theMat->_opacity < 0.99 Alors
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glDepthMask(GL_FALSE);
    FinSi

    theMat->GLSet();

    Si _GL_list == 0 AlorsFait
      GLRecomputeList(); 

    glCallList(_GL_list);

    Si theMat->_opacity < 0.99 Alors
      glDisable(GL_BLEND);
      glDepthMask(GL_TRUE);
    FinSi
  FinSi

  Si _ownmaterial Alors 
    Si light_enabled Alors
      glEnable(GL_LIGHTING);
    Sinon
      glDisable(GL_LIGHTING);
    FinSi
  FinSi

} // DisplayObject()


//======================================================================
// Surface
//======================================================================

Surface :: Destructeur Surface()
//
{

  Si _image_allouee Et (_image != NULL) AlorsFait delete _image;
  Si _image_couleurs_allouee  AlorsFait delete _image_couleurs;

  Desalloue();

}


//----------------------------------------------------------
void  Surface :: Alloue( int dimu, int dimv)
//
{

  
    int u,v;

  Si (dimu == _dim_u) Et (dimv == _dim_v)
  AlorsFait return;

  Desalloue();

  _dim_u = dimu; 
  _dim_v = dimv; 

  _umin = 0;
  _vmin = 0;
  _umax = _dim_u-1;
  _vmax = _dim_v-1;

  pt = new point3Dreel*[_dim_u];
  Pour(u,0,_dim_u-1)
    pt[u] = new point3Dreel[_dim_v];
  FinPour

  Pour(u,0,_dim_u-1)
  Pour(v,0,_dim_v-1)

    pt[u][v].x = 
    pt[u][v].y =
    pt[u][v].z = 0.0;

  FinPour
  FinPour

} // Alloue()



//----------------------------------------------------------
void  Surface :: Desalloue( )
//
{

  
    int u;

  Si _dim_v != 0 Alors

    Pour(u,0,_dim_u-1)
      delete [] pt[u];
    FinPour
    delete [] pt;

    _dim_u = _dim_v = 0;

  FinSi
 
} // Alloue()

//----------------------------------------------------------
void  Surface :: LitDonnees( Chaine nom_fic)
//
{

  
    FILE*   fichier;
    int  u,v;
    int  dimu,dimv;
    float    x,y,z;

  Si _image_allouee Et (_image != NULL) Alors
    delete _image;
    _image = NULL;
  FinSi


  cout << "Lecture du fichier " << nom_fic << endl;

  fichier = fopen( nom_fic, "r");
  Si fichier == NULL Alors
    printf(" Erreur dans l'ouverture du fichier de parametres %s \n"
           , (char*) nom_fic);
    return;
  FinSi

  //----- Debut
  fscanf( fichier, "%d %d\n", &dimu, &dimv);

//  printf("%d x %d points\n", dimu, dimv);

  //---- Allocation des points
  Alloue(dimu, dimv);

  _moy_x = _moy_y = _moy_z = 0;

  Pour(u,0,_dim_u-1)
  Pour(v,0,_dim_v-1)

    fscanf( fichier, 
	    "%f %f %f\n", 
	    &x, 
	    &y, 
	    &z);

    pt[u][v].x = x;
    pt[u][v].y = y;
    pt[u][v].z = z;

    _moy_x += pt[u][v].x;
    _moy_y += pt[u][v].y;
    _moy_z += pt[u][v].z;

  FinPour
  //    Si verbose Alors
      Si u > 0 Alors 
        printf("\b\b\b");
      Sinon
        printf("ligne : ");
      FinSi
      printf("%3d",u); 
      fflush(stdout);
//    FinSi
  FinPour

  _moy_x = _moy_x / (_dim_u*_dim_v);
  _moy_y = _moy_y / (_dim_u*_dim_v);
  _moy_z = _moy_z / (_dim_u*_dim_v);

  _et_x = _et_y = _et_z = 0;


  Pour(u,0,_dim_u-1)
  Pour(v,0,_dim_v-1)

    _et_x += (pt[u][v].x-_moy_x)*(pt[u][v].x-_moy_x);
    _et_y += (pt[u][v].y-_moy_y)*(pt[u][v].y-_moy_y);
    _et_z += (pt[u][v].z-_moy_z)*(pt[u][v].z-_moy_z);

  FinPour
  FinPour

  _et_x = sqrt(_et_x / (_dim_u*_dim_v));
  _et_y = sqrt(_et_y / (_dim_u*_dim_v));
  _et_z = sqrt(_et_z / (_dim_u*_dim_v));

  printf(" lecture terminee \n");

  printf(" moyennes   x %f y %f z %f \n", _moy_x, _moy_y, _moy_z );
  printf(" ecart type x %f y %f z %f \n", _et_x,  _et_y,  _et_z  );
 
} // LitDonnees()


//----------------------------------------------------------
void  Surface :: LitImage( Chaine nom_image)
//
{
    int u,v;

  Si _image_allouee Et (_image != NULL) Alors
    delete _image;
    _image = NULL;
  FinSi

  _image = new InrImage( nom_image);
  _image_allouee = true;
  _posZ = 0;

  //---- Allocation des points
  Alloue(_image->_tx, _image->_ty);

  Pour(u,0,_dim_u-1)
  Pour(v,0,_dim_v-1)

    pt[u][v].x = u;
    pt[u][v].y = v;
    pt[u][v].z = (*_image)(u,_dim_v-1-v,0);

  FinPour
  //    Si verbose Alors
      Si u > 0 Alors 
        printf("\b\b\b");
      Sinon
        printf("ligne : ");
      FinSi
      printf("%3d",u); 
      fflush(stdout);
//    FinSi
  FinPour



} // LitImage()


//----------------------------------------------------------
void  Surface :: LitImage( InrImage* image, int posZ,
				     float zscale, float min, float max)
//
{
    int u,v;

  Si _image_allouee Et (_image != NULL) Alors
    delete _image;
    _image = NULL;
  FinSi

  _image = image;
  _image_allouee = false;

  Si posZ<0 Ou posZ>_image->_tz-1 AlorsFait posZ = 0;

  _posZ = posZ;
  _Imin = min;
  _Imax = max;

  //---- Allocation des points
  Alloue(_image->_tx, _image->_ty);

  Pour(u,0,_dim_u-1)
  Pour(v,0,_dim_v-1)

    pt[u][v].x = u;
    pt[u][v].y = v;
    pt[u][v].z = (*_image)(u,_dim_v-1-v,posZ)*zscale;

  FinPour
  //    Si verbose Alors
      Si u > 0 Alors 
        printf("\b\b\b");
      Sinon
        printf("ligne : ");
      FinSi
      printf("%3d",u); 
      fflush(stdout);
//    FinSi
  FinPour

} // LitImage()


//----------------------------------------------------------
unsigned char  Surface :: LitImageCouleurs( Chaine nom_image)
//
{

   
  //    int u,v;

  Si _image_couleurs_allouee Alors
    delete _image_couleurs;
    _image_couleurs = NULL;
  FinSi


  try{
    _image_couleurs = new InrImage( nom_image);
    _image_couleurs_allouee = true;
  }
  catch(InrImage::ErreurLecture){
    cout << "Erreur de lecture de l'image" << endl;
    _image_couleurs         = NULL;
    _image_couleurs_allouee = false;
    return false;
  }


  return true;

} // LitImageCouleurs()


//----------------------------------------------------------------------
point3Dreel& Surface :: operator()( int u, int v)
//
{

  return pt[u][v];

} // operator()


//----------------------------------------------------------------------
int Surface :: RColor( int u, int v)
//
{

  float i,di;

  Si (_image != NULL) Et fabsf(_Imax-_Imin)>1E-3 Alors
    i = (*_image)(u,_dim_v-1-v,_posZ);
    Si i>_Imax Alors
      di = 255;
    Autrement
    Si i<_Imin Alors
      di = 0;
    Autrement
      di = (i-_Imin)/(_Imax-_Imin)*255;
    return (unsigned char) di;
  FinSi

  Si (_image_couleurs          != NULL  ) Et
     (_image_couleurs->_format == WT_RGB) AlorsFait
    return (unsigned char) ((*_image_couleurs)(u,_dim_v-1-v,0,0));

  return 127;

} // RColor()


//----------------------------------------------------------------------
int Surface :: GColor( int u, int v)
//
{

  float i,di;

  Si (_image != NULL) Et fabsf(_Imax-_Imin)>1E-3 Alors
    i = (*_image)(u,_dim_v-1-v,_posZ);
    Si i>_Imax Alors
      di = 255;
    Autrement
    Si i<_Imin Alors
      di = 0;
    Autrement
      di = (i-_Imin)/(_Imax-_Imin)*255;
    return (unsigned char) di;
  FinSi

  Si (_image_couleurs != NULL)Et
     (_image_couleurs->_format ==WT_RGB) Et
     (u>=0)Et(u<_image_couleurs->_tx) Et
     (v>=0)Et(v<_image_couleurs->_ty) 
  AlorsFait
    return (unsigned char) ((*_image_couleurs)(u,_dim_v-1-v,0,1));

  return 127;

} // GColor()

//----------------------------------------------------------------------
int Surface :: BColor( int u, int v)
//
{

  float i,di;

  Si (_image != NULL) Et fabsf(_Imax-_Imin)>1E-3 Alors
    i = (*_image)(u,_dim_v-1-v,_posZ);
    Si i>_Imax Alors
      di = 255;
    Autrement
    Si i<_Imin Alors
      di = 0;
    Autrement
      di = (i-_Imin)/(_Imax-_Imin)*255;
    return (unsigned char) di;
  FinSi

  Si (_image_couleurs != NULL)Et
     (_image_couleurs->_format ==WT_RGB) AlorsFait
    return (unsigned char) ((*_image_couleurs)(u,_dim_v-1-v,0,2));

  return 127;

} // BColor()


//======================================================================
// Point3DPoly
//======================================================================

#define my_glNormal3f(a,b,c) \
  if (GB_debug) \
    cerr << format(" glNormal3f(%1%, %2%, %3%);") %a %b %c << endl; \
    glNormal3f(a, b, c);

#define my_glVertex3f(a,b,c) \
  if (GB_debug) \
    cerr << format(" glVertex3f(%1%, %2%, %3%);") %a %b %c << endl; \
    glVertex3f(a, b, c);


 void Point3DPoly::AddGLPolygon()
  //
  {


    Si fabsf(alpha-1.0)<1E-5 Alors
      glColor3ub( (GLubyte) red,
              (GLubyte) green,
              (GLubyte) blue);
    Sinon
      glColor4ub((GLubyte) red,
             (GLubyte) green,
             (GLubyte) blue,
         (GLubyte) (alpha*255));
    FinSi


    norm.Normalise();

    //my_glNormal3f(norm.x, norm.y, norm.z);
    //my_glVertex3f(pt.x,   pt.y,   pt.z  );
    glNormal3f(norm.x, norm.y, norm.z);
    glVertex3f(pt.x,   pt.y,   pt.z  );

  }



  void Point3DPoly::AddGLPolygon( float r, float g, float b)
  //
  {

    Si fabsf(alpha-1.0)<1E-2 Alors
      glColor3ub( 
              (GLubyte) (r*255),
          (GLubyte) (g*255),
          (GLubyte) (b*255));
    Sinon
      glColor4ub( 
         (GLubyte) (r*255),
         (GLubyte) (g*255),
         (GLubyte) (b*255), 
         (GLubyte) (alpha*255));
    FinSi

    norm.Normalise();

    my_glNormal3f(norm.x, norm.y, norm.z);
    my_glVertex3f(pt.x,   pt.y,   pt.z  );

  }

//======================================================================
// SurfacePoly
//======================================================================


//----------------------------------------------------------------------
SurfacePoly :: Constructeur SurfacePoly()
//
{

  _vectors1     = 0;
  _vectors2     = 0;
  _normals      = 0;

  _cc_calculees = false;
  _nb_cc = 0;
  _sort_tab_cc = NULL;
//  _draw_cc     = NULL;

  _show_all_cc = true;

  _obj_type = OBJTYPE_SURFPOLY;

  _picked_line = -1;

} // Constructeur SurfacePoly()


#ifndef _WITHOUT_VTK_
//----------------------------------------------------------------------
SurfacePoly :: Constructeur SurfacePoly( vtkPolyData* vtkpoly)
//
{

  _vectors1     = 0;
  _vectors2     = 0;
  _normals      = 0;

  _cc_calculees = false;
  _nb_cc = 0;
  _sort_tab_cc = NULL;
  _show_all_cc = true;

  _obj_type = OBJTYPE_SURFPOLY;


  // Copy from vtk structure
  //

  AddVTKPoly(vtkpoly);

} // Constructeur SurfacePoly()
#endif // _WITHOUT_VTK_


//----------------------------------------------------------------------
SurfacePoly :: Destructeur SurfacePoly()
//
{
 // printf("called ~SurfacePoly() nb points %d\n",
 //NbPoints() );
} // Destructeur SurfacePoly()


#ifndef _WITHOUT_VTK_
//----------------------------------------------------------------------
void SurfacePoly :: AddVTKPoly( vtkPolyData* vtkpoly)
//
{

  
    vtkFloatingPointType             triangle[3];
    vtkCellArray*      polys_res;
    vtkCellArray*      lines;
    vtkTriangleFilter* triangle_filter=NULL;
    vtkPolyData*       poly_triangles;
    int                i,j;
    vtkIdType                nb_pts=0;
    vtkIdType*               res_points=NULL;
    unsigned char      poly_create;
    vtkDataArray       *vtk_colors;
    unsigned char      get_colors;


  poly_create = (vtkpoly->GetNumberOfStrips() >0);
  Si poly_create Alors
    fprintf(stderr,"number of strips %d  \n",
	    (int)vtkpoly->GetNumberOfStrips());
    triangle_filter = vtkTriangleFilter::New();
    triangle_filter->SetInput(vtkpoly);
    triangle_filter->Update();
    poly_triangles = triangle_filter->GetOutput();
    vtkpoly = poly_triangles;
  FinSi


Si GB_debug AlorsFait fprintf(stderr,"SurfacePoly::AddVTKPoly() \t Insert Points \n");
  // Insert points

  fprintf(stderr,"number of points %d  \n",
	  (int)vtkpoly->GetNumberOfPoints());

  vtk_colors = vtkpoly->GetPointData()->GetScalars();
  get_colors = ((vtk_colors!=NULL)&&(vtk_colors->GetDataType()==VTK_UNSIGNED_CHAR));

  fprintf(stderr,"get_colors=%u \n",get_colors);

  Pour(i,0,vtkpoly->GetNumberOfPoints()-1)

    vtkpoly->GetPoint(i,triangle);
    AddPoint(triangle[0],
	     triangle[1],
	     triangle[2]);
    if (get_colors) {
      _tab_pts[i].SetColor( (unsigned char) vtk_colors->GetComponent(i,0),
			    (unsigned char) vtk_colors->GetComponent(i,1),
			    (unsigned char) vtk_colors->GetComponent(i,2));
     if (i==0)
        fprintf(stderr," %f \n", vtk_colors->GetComponent(i,0));
   }

  FinPour

  polys_res = vtkpoly->GetPolys();

  fprintf(stderr,"number of polygons %d  \n",
	  (int)polys_res->GetNumberOfCells());

Si GB_debug AlorsFait fprintf(stderr,"SurfacePoly::AddVTKPoly() \t Insert Polygons \n");
  // Insert polygons

  polys_res->SetTraversalLocation(0); 
  Pour(i,0,polys_res->GetNumberOfCells()-1)

    //    polys_res->GetCell(i,nb_pts,res_points);
    polys_res->GetNextCell(nb_pts,res_points);

    Si GB_debug AlorsFait fprintf(stderr," %d nbpoints %d \n",(int)i,(int)nb_pts);

    Si nb_pts==0 AlorsFait continue;

    NewPoly();
      Pour(j,0,nb_pts-1)
        PolyAddPointNumber(res_points[j]);
      FinPour
    EndPoly();

  FinPour

  // Get the lines
  lines = vtkpoly->GetLines();

  fprintf(stderr,"number of lines %d  \n",
	  (int)lines->GetNumberOfCells());

  lines->SetTraversalLocation(0); 
  Pour(i,0,lines->GetNumberOfCells()-1)

    lines->GetNextCell(nb_pts,res_points);

//    Si GB_debug AlorsFait fprintf(stderr," %d nbpoints %d \n",i,nb_pts);

    Si nb_pts==0 AlorsFait continue;

    NewLine();
      Pour(j,0,nb_pts-1)
	LineAddPointNumber(res_points[j]);
      FinPour
    EndLine();

  FinPour

  fprintf(stderr,"AddVTKPoly() end  \n");

  Si poly_create Alors
  //    vtkpoly->Delete();
    triangle_filter->Delete();
  FinSi

  fprintf(stderr,"AddVTKPoly() end 2 \n");

} // AddVTKPoly()
#endif // _WITHOUT_VTK_


//----------------------------------------------------------------------
void SurfacePoly :: NewSurface()
//
{

  _tab_pts.VideTableau();
  _tab_poly.VideTableau();

  Si _cc_calculees Alors 

     
      int i;

    Pour(i,0,_tab_cc.NbElts()-1)
      _tab_cc[i].VideTableau();
    FinSi

    _tab_cc.VideTableau();

    Si _sort_tab_cc != NULL Alors
      delete[] _sort_tab_cc;
      _sort_tab_cc = NULL;
    FinSi

    /*
    Si _draw_cc != NULL Alors
      delete[] _draw_cc;
      _draw_cc = NULL;
    FinSi
    */

    _cc_calculees = false;
    _show_all_cc  = true;

  FinSi


} // NewSurface()


//----------------------------------------------------------------------
void SurfacePoly :: Scale( float sx, float sy, float sz, unsigned char recompute)
//
{

  
    int i;

  Pour(i,0,GetNumberOfPoints()-1)

    _tab_pts[i].pt.x *= sx;
    _tab_pts[i].pt.y *= sy;
    _tab_pts[i].pt.z *= sz;

    _xmin *= sx;
    _ymin *= sy;
    _zmin *= sz;

    _center_x *= sx;
    _center_y *= sy;
    _center_z *= sz;

  FinPour

  if (recompute) GLRecomputeList( );

} // Scale()


//----------------------------------------------------------------------
void SurfacePoly :: AddPoint( float x, float y, float z)
//
{

/*
  Si _tab_pts.NbElts() == 0 Alors
    _xmin = _xmax = x;
    _ymin = _ymax = y;
    _zmin = _zmax = z;
  Sinon
    Si x < _xmin AlorsFait _xmin = x;
    Si x > _xmax AlorsFait _xmax = x;
    Si y < _ymin AlorsFait _ymin = y;
    Si y > _ymax AlorsFait _ymax = y;
    Si z < _zmin AlorsFait _zmin = z;
    Si z > _zmax AlorsFait _zmax = z;
  FinSi
   */

  _tab_pts += Point3DPoly(x,y,z);


} // AddPoint()


//----------------------------------------------------------------------
void SurfacePoly :: AddPoint( Point_3D<float> pt)
//
{

  _tab_pts += Point3DPoly(pt.x,pt.y,pt.z);


} // AddPoint()


//----------------------------------------------------------------------
void SurfacePoly :: SetNorm( float x, float y, float z)
//
{

  
    int n;

  n = _tab_pts.NbElts() -1 ;
  _tab_pts[n].SetNormal(x,y,z);

} // SetNorm()


//----------------------------------------------------------------------
void SurfacePoly :: SetColor( float r, float g, float b, float alpha)
//
{

  
    int n;

  n = _tab_pts.NbElts() -1 ;
  _tab_pts[n].SetColor( (unsigned char) (r*255),
			(unsigned char) (g*255),
		        (unsigned char) (b*255));
  _tab_pts[n].SetAlpha(alpha);

} // SetColor()


//----------------------------------------------------------------------
void SurfacePoly :: SetColor( unsigned char r, 
					unsigned char g, 
					unsigned char b,
					float alpha)
//
{

  
    int n;

  n = _tab_pts.NbElts() -1 ;
  _tab_pts[n].SetColor( r,g,b);
  _tab_pts[n].SetAlpha(alpha);

} // SetColor()


//----------------------------------------------------------------------
void SurfacePoly :: SetOpacity( float alpha)
//
{

  
    int n;

  n = _tab_pts.NbElts() -1 ;
  _tab_pts[n].SetAlpha(alpha);

} // SetOpacity()


//----------------------------------------------------------------------
Point3DPoly& SurfacePoly :: operator[]( int i)
//
{

  return _tab_pts[i];

} //  operator[]()

#ifndef _WITHOUT_VTK_
//----------------------------------------------------------------------
SurfacePoly :: operator vtkPolyData* (void) const
//
{
    vtkPoints*         points;
    int                i,j,n;
    vtkCellArray*      polys=NULL;
    vtkCellArray*      lines;
    SurfPoly           poly;
    vtkPolyData*       vtk_surf;
    vtkDataArray       *vtk_normals;
    vtkDataArray       *vtk_colors;
    vector<vtkIdType>        pts(1000);

    // Renumerotation pour ne sauver que les points utilises
    unsigned char            show_poly;
    int*            pts_sauves;
    int             num_point=0;
    int                numcc;


//printf("operator vtkPolyData* 1\n");

// Write the points

  Si _cc_calculees Et (_show_all_cc == false) Alors
    pts_sauves = new int [this->_tab_pts.NbElts()];
    num_point  = 0;
  Sinon
    pts_sauves = NULL;
  FinSi

  points      = vtkPoints ::New();
  vtk_normals = vtkFloatArray::New(); 
  vtk_normals->SetNumberOfComponents(3);

  vtk_colors = vtkUnsignedCharArray::New(); 
  vtk_colors->SetNumberOfComponents(3);

//printf("operator vtkPolyData* 2 number of points %d \n",GetNumberOfPoints());
//printf("operator vtkPolyData* 2 number of cc %d \n",_draw_cc.NbElts());

  Pour(i,0,GetNumberOfPoints()-1)

//if (i>0) printf("\b\b\b\b\b\b");
//printf("%06d",i);
//fflush(stdout);

    Si pts_sauves!= NULL Alors
      numcc=_tab_pts[i].num_cc;
      if ((numcc>=0)&&(numcc<_draw_cc.NbElts()))
        Si _draw_cc[numcc] Alors
          pts_sauves[i] = num_point;

          points->InsertPoint(num_point,
			    _tab_pts[i].pt.x,
			    _tab_pts[i].pt.y,
			    _tab_pts[i].pt.z);

          // Write the normal
          vtk_normals->InsertTuple3( num_point,
				   _tab_pts[i].norm.x,
				   _tab_pts[i].norm.y,
				   _tab_pts[i].norm.z);

          // Write the colors
          vtk_colors->InsertTuple3( num_point,
				  (unsigned char) _tab_pts[i].red,
				  (unsigned char) _tab_pts[i].green,
				  (unsigned char) _tab_pts[i].blue);
         if (num_point==0)
            fprintf(stderr," %u \n",(unsigned char) _tab_pts[i].red);
 
          num_point++;
        Sinon
          pts_sauves[i] = -1;
          continue;
        FinSi  
      else
        printf("point %d cc=%d not valid\n",i,numcc);
   Sinon
     points->InsertPoint(i,
			 _tab_pts[i].pt.x,
			 _tab_pts[i].pt.y,
			 _tab_pts[i].pt.z);

     // Write the normal
     vtk_normals->InsertTuple3( i,
				_tab_pts[i].norm.x,
				_tab_pts[i].norm.y,
				_tab_pts[i].norm.z);

     // Write the colors
     vtk_colors->InsertTuple3( i,
			       _tab_pts[i].red,
			       _tab_pts[i].green,
			       _tab_pts[i].blue);

   FinSi


  FinPour

printf("operator vtkPolyData* 2\n");
  // Write the polygons

   try {
  polys = vtkCellArray::New();

  polys->SetTraversalLocation(0); 
  Pour(i,0,GetNumberOfPolys()-1)

    poly = _tab_poly[i];
    // Temporary solution
    // in case of the computation of connex component
    // save only the main connex component
    // otherwise save all the polygons
    show_poly = true;
    Si _cc_calculees Et (_show_all_cc == false) AlorsFait
      show_poly=_draw_cc[_tab_pts[poly[0]].num_cc];

    Si show_poly 
    Alors
      Pour(j,0,poly.NbElts()-1)
        Si pts_sauves != NULL Alors
          pts.push_back( pts_sauves[poly[j]]);
        Sinon
          pts[j] = poly[j];
        FinSi
      FinPour
      polys->InsertNextCell(poly.NbElts(),
			    &pts.front());
    FinSi

  FinPour

      }
catch (OutOfArray) {
  fprintf(stderr,"OutofArray cached ...");
}
printf("operator vtkPolyData* 3\n");
  // Write the lines
  lines = vtkCellArray::New();

  lines->SetTraversalLocation(0); 
  Pour( i, 0, GetNumberOfLines()-1)
    n = _tab_lines[i].NbElts();
    Si n>0 Alors
      Pour(j,0,_tab_lines[i].NbElts()-1)
        pts.push_back(_tab_lines[i][j]);
      FinPour
      lines->InsertNextCell(_tab_lines[i].NbElts(), &pts.front());
    /*
    Sinon
      Si n>=1000 AlorsFait
        fprintf(stderr,"SurfacePoly::SaveVTK() \t Too many points in line. \n");
    */
    FinSi
  FinPour  //i


  vtk_surf = vtkPolyData::New();  
  vtk_surf->SetPoints(points);
  vtk_surf->SetPolys(polys);
  vtk_surf->SetLines(lines);

  vtk_surf->GetPointData()->SetNormals(vtk_normals);
  vtk_surf->GetPointData()->SetScalars(vtk_colors);

  delete [] pts_sauves;
  polys      ->Delete();
  points     ->Delete();
  lines      ->Delete();
  vtk_normals->Delete(); 
  vtk_colors ->Delete(); 

printf("operator vtkPolyData* end\n");

  return vtk_surf;

} //  operator vtkPolyData* (void) const
//----------------------------------------------------------------------
#endif // _WITHOUT_VTK_


//----------------------------------------------------------------------
void SurfacePoly :: NewPoly()
//
{

   _poly.VideTableau();

} // NewPoly()


//----------------------------------------------------------------------
void SurfacePoly :: PolyAddPointNumber(int num)
//
{

  float x,y,z;

  x = _tab_pts[num].pt.x;
  y = _tab_pts[num].pt.y;
  z = _tab_pts[num].pt.z;

  Si (_tab_poly.NbElts()==0) Et (_poly.NbElts() == 0) Alors
    _xmin = _xmax = x;
    _ymin = _ymax = y;
    _zmin = _zmax = z;
  Sinon
    Si x < _xmin AlorsFait _xmin = x;
    Si x > _xmax AlorsFait _xmax = x;
    Si y < _ymin AlorsFait _ymin = y;
    Si y > _ymax AlorsFait _ymax = y;
    Si z < _zmin AlorsFait _zmin = z;
    Si z > _zmax AlorsFait _zmax = z;
  FinSi

  _poly += num;

} // PolyAddPointNumber()



//----------------------------------------------------------------------
void SurfacePoly :: EndPoly()
//
{

   
    int         i0,i1,i2;
//    Point3DPoly&   pt;
    Point_3D<float> p0,p1,p2;
    Vect3D<float>   n,n1,n2;
    unsigned char        AddNormal;


  // Si la normale est fixee, verification de l'orientation du polygone

  Si _tab_pts[_poly[0]].norm_fixed Alors

  /*
    i0 = _poly.NbElts()-1;
    i1 = 0;
    i2 = 1;

    p0 = _tab_pts[_poly[i0]].pt;
    p1 = _tab_pts[_poly[i1]].pt;
    p2 = _tab_pts[_poly[i2]].pt;

    n = (p1-p0)^(p2-p1);

    // Si l'orientation n'est pas en accord avec la normale
    // Alors on re-oriente le polygone
    Si n*_tab_pts[_poly[0]].norm < 0 Alors
      TableauDyn<int>  newpoly;
      
      Pour(i0,0,_poly.NbElts()-1)
        newpoly += _poly[_poly.NbElts()-1-i0];
      FinPour
    
      _poly = newpoly;

    FinSi
  */

  FinSi


  Pour(i1,0,_poly.NbElts()-1)


    Si _tab_pts[_poly[i1]].norm_fixed AlorsFait continue;

    i0 = (i1+_poly.NbElts()-1) % _poly.NbElts();
    i2 = (i1               +1) % _poly.NbElts();

    p0 = _tab_pts[_poly[i0]].pt;
    p1 = _tab_pts[_poly[i1]].pt;
    p2 = _tab_pts[_poly[i2]].pt;

    n = (p1-p0)^(p2-p1);

    AddNormal = true;

    try {
      n.Normalise();
    }
    catch (NormeFaible) {

      Si GB_debug AlorsFait 
	fprintf(stderr,"SurfacePoly:EndPoly() \t poly %d nbpts %d \n", _tab_poly.NbElts(),_poly.NbElts());

      try{
        n1 = p1-p0;
        n1.Normalise();

        n2 = p2-p1;
        n2.Normalise();

        n = n1^n2;
        n.Normalise();
      }
      catch (NormeFaible) {
        fprintf(stderr,"probleme normalisation vecteur normal \n");
        AddNormal = false;
      }
      
    }
    
    Si AddNormal AlorsFait _tab_pts[_poly[i1]].AddNormal( n);

  FinPour

  _tab_poly += _poly;

} // EndPoly()


//----------------------------------------------------------------------
void SurfacePoly :: NewLine()
//
{

   _line.VideTableau();

} // NewLine()


//----------------------------------------------------------------------
void SurfacePoly :: LineAddPointNumber(int num)
//
{

  float x,y,z;

  x = _tab_pts[num].pt.x;
  y = _tab_pts[num].pt.y;
  z = _tab_pts[num].pt.z;

  Si (_tab_lines.NbElts()==0) Et (_line.NbElts() == 0) Alors
    _xmin = _xmax = x;
    _ymin = _ymax = y;
    _zmin = _zmax = z;
  Sinon
    Si x < _xmin AlorsFait _xmin = x;
    Si x > _xmax AlorsFait _xmax = x;
    Si y < _ymin AlorsFait _ymin = y;
    Si y > _ymax AlorsFait _ymax = y;
    Si z < _zmin AlorsFait _zmin = z;
    Si z > _zmax AlorsFait _zmax = z;
  FinSi

  _line += num;

} // LineAddPointNumber()



//----------------------------------------------------------------------
void SurfacePoly :: EndLine()
//
{


  _tab_lines += _line;

} // EndLine()


//----------------------------------------------------------------------
GLuint SurfacePoly :: NewGLSurface()
//
{

  if (!MakeContextCurrent()) return 0;

  Si _GL_list != 0 AlorsFait my_glDeleteLists(_GL_list, 1);
  my_glGenLists(_GL_list,1);

  Si _bounding_box != 0 Alors
    my_glDeleteLists(_bounding_box, 1);
    _bounding_box = 0;
  FinSi

  Si _vectors1 != 0 Alors
    my_glDeleteLists(_vectors1, 1);
    _vectors1 = 0;
  FinSi

  Si _vectors2 != 0 Alors
    my_glDeleteLists(_vectors2, 1);
    _vectors2 = 0;
  FinSi

  Si _normals != 0 Alors
    my_glDeleteLists(_normals, 1);
    _normals = 0;
  FinSi

  return _GL_list;

} // NewGLSurface()


//----------------------------------------------------------------------
void SurfacePoly :: EndGLSurface()
//
{

   
    int         i,j,n;
    Point3DPoly    pt;
//    float x,y,z;

  if (GB_debug) printf("EndGLSurface begin\n");


  if (!MakeContextCurrent()) return;

    my_glNewList( _GL_list, GL_COMPILE);   

  if ((_tab_poly.NbElts()> 0)       ||
      (_tab_lines.NbElts()> 0)      ||
      (_selected_points.NbElts()>0) ||
      (_tab_pts.NbElts()-1>0)
      )
  {
    
    Si _tab_poly.NbElts()> 0 Alors
  
      Pour(i,0,_tab_poly.NbElts()-1)
        _poly = _tab_poly[i];
        n =_tab_pts[_poly[0]].num_cc;
        // glBegin(GL_POLYGON);
  
        if ((_show_all_cc) Ou (n<0)) {
            my_glBegin_GL_TRIANGLE_FAN
            Pour(j,0,_poly.NbElts()-1)
              pt = _tab_pts[_poly[j]];
              try{ pt.AddGLPolygon();  }
              catch (NormeFaible) { 
                Si GB_verbose AlorsFait
                  cerr << "Poly " << i << "Norme faible pour la normale" << endl;
              }
            FinPour
            my_glEnd
        } else { // if ((_show_all_cc) Ou (n<0))
          if (_draw_cc[n]) 
            if (_selected_cc.Position(n) != -1) {
              my_glBegin_GL_TRIANGLE_FAN
              Pour(j,0,_poly.NbElts()-1)
                pt = _tab_pts[_poly[j]];
                try{ pt.AddGLPolygon( 0.9,0.5,0); }
                catch (NormeFaible) { 
                  Si GB_verbose AlorsFait
                    cerr << "Poly " << i << "Norme faible pour la normale" << endl;
                }
              FinPour
              my_glEnd
            } else { // if (_selected_cc.Position(n) != -1)
              my_glBegin_GL_TRIANGLE_FAN
              Pour(j,0,_poly.NbElts()-1)
                pt = _tab_pts[_poly[j]];
                try{ pt.AddGLPolygon();  }
                catch (NormeFaible) { 
                  Si GB_verbose AlorsFait
                    cerr << "Poly " << i << "Norme faible pour la normale" << endl;
                }
              FinPour
              my_glEnd
            } // if (_selected_cc.Position(n) != -1)
  
  
        } // if ((_show_all_cc) Ou (n<0))
      FinPour
  
    FinSi
  
   glReportErrors();
  
    Si _tab_lines.NbElts()> 0 Alors
  
      glDisable(GL_LIGHTING);
  //    glPolygonMode (GL_FRONT_AND_BACK, GL_MODE_LINE);
  
      Pour(i,0,_tab_lines.NbElts()-1)
        //      fprintf(stderr,"line %d ",i);fflush(stderr);
        _line = _tab_lines[i];
  
        Si i == _picked_line Alors
          glLineWidth(3);
        FinSi
  
        glBegin(GL_LINE_STRIP);
  
          Pour(j,0,_line.NbElts()-1)
            pt = _tab_pts[_line[j]];
            pt.AddGLLine();
          FinPour
        glEnd();
  
        Si i == _picked_line Alors
          glLineWidth(_line_width);
        FinSi
  
      FinPour
  
   glReportErrors();
  
      glLineWidth(3);
      Pour(i,0,_selected_lines.NbElts()-1)
        //      fprintf(stderr,"line %d ",i);fflush(stderr);
        _line = _tab_lines[_selected_lines[i]];
  
  
        glBegin(GL_LINE_STRIP);
  
          Pour(j,0,_line.NbElts()-1)
            pt = _tab_pts[_line[j]];
            pt.AddGLLine(1,0,0);
          FinPour
        glEnd();
  
      FinPour
      glLineWidth(_line_width);
  
  
    FinSi
   glReportErrors();
  
    glPointSize(5);
    Si _selected_points.NbElts()>0 Alors
      glDisable(GL_LIGHTING);
      Si GB_debug AlorsFait fprintf(stderr,"Points Selected ... \n");
      glBegin(GL_POINTS);
      Pour(i,0,_selected_points.NbElts()-1)
        _tab_pts[_selected_points[i]].AddGLPoint(0,0,1);
      FinPour
      glEnd();
    FinSi
  
      //  fprintf(stderr,"end lines \n");
  
    Si _tab_poly.NbElts() == 0 Et _tab_lines.NbElts() == 0 Alors
  
      glBegin(GL_POINTS);
      //cout << "_tab_pts.NbElts()()" << _tab_pts.NbElts() << endl;
      Pour(i,0,_tab_pts.NbElts()-1)
        _tab_pts[i].AddGLPoint();
      FinPour
  
      glEnd();
    FinSi

  }

   glReportErrors();
    my_glEndList;
   glReportErrors();
  
    this->UpdateLimits();

  if (GB_debug) printf("EndGLSurface end\n");

} //  EndGLSurface()


//----------------------------------------------------------------------
void SurfacePoly :: UpdateLimits( )
//
{
  int i;
  float x,y,z;

// update limits
  Pour(i,0,_tab_pts.NbElts()-1)
    x = _tab_pts[i].pt.x;
    y = _tab_pts[i].pt.y;
    z = _tab_pts[i].pt.z;
    if (i==0) {
      _xmin=_xmax =x;
      _ymin=_ymax =y;
      _zmin=_zmax =z;
    }
    else {
      Si x < _xmin AlorsFait _xmin = x;
      Si x > _xmax AlorsFait _xmax = x;
      Si y < _ymin AlorsFait _ymin = y;
      Si y > _ymax AlorsFait _ymax = y;
      Si z < _zmin AlorsFait _zmin = z;
      Si z > _zmax AlorsFait _zmax = z;
    }
  FinPour

  _center_x = (_xmin + _xmax)/2.0;
  _center_y = (_ymin + _ymax)/2.0;
  _center_z = (_zmin + _zmax)/2.0;

} // UpdateLimits( )

//----------------------------------------------------------------------
void SurfacePoly :: ComputeNeighbors( )
//
{

   
    int         i,j;

  // Empty neighbors first
  Pour(i,0,_tab_pts.NbElts()-1)
    _tab_pts[i]._neighbors.VideTableau();
  FinPour

  Pour(i,0,_tab_poly.NbElts()-1)
    _poly = _tab_poly[i];
    Pour(j,0,_poly.NbElts()-1)
      _tab_pts[_poly[j]]._neighbors += i;
    FinPour
  FinPour


    // Check if the neighbors are correct
  Pour(i,0,_tab_pts.NbElts()-1)
    Pour(j,0,_tab_pts[i]._neighbors.NbElts()-1)
      if ((_tab_pts[i]._neighbors[j] >= _tab_poly.NbElts()) || (_tab_pts[i]._neighbors[j]<0)) {
	fprintf(stderr, " Pb point %d neighbor %d = %d \n",i,j,_tab_pts[i]._neighbors[j]);
      }
    FinPour
  FinPour
  

} // ComputeNeighbors()



//----------------------------------------------------------------------
//
void SurfacePoly :: Statistics(InrImage* image) 
//
{

  float* values;
  double valmean,valmin,valmax,sd;
  int i;

  values = new float[_tab_pts.NbElts()];
  valmean = 0;
  valmin  = 1E10;
  valmax  = -1E10;
  sd = 0;

  Pour(i,0,_tab_pts.NbElts()-1)
      values[i] = image->InterpLinIntensite(
					    ((float) _tab_pts[i].X())/image->VoxSizeX(),
					    ((float) _tab_pts[i].Y())/image->VoxSizeY(),
					    ((float) _tab_pts[i].Z())/image->VoxSizeZ());
    valmean += values[i];
    if (values[i]<valmin) valmin = values[i];
    if (values[i]>valmax) valmax = values[i];
  FinPour

  valmean /= (1.0*_tab_pts.NbElts());

  Pour(i,0,_tab_pts.NbElts()-1)
    sd +=  (values[i]-valmean)*(values[i]-valmean);
  FinPour

  sd = sqrt (sd/(1.0*_tab_pts.NbElts()));

  printf("Statistics: min,max = [%f,%f] \t mean = %f \t sd = %f \n",valmin,valmax,valmean,sd);

  delete [] values;

} // Statistics

//----------------------------------------------------------------------
//
GLuint SurfacePoly :: SetColors( InrImage* image, 
				  float min, 
				  float max,
				  float alpha)
//
{

   
    int         i;
    Point3DPoly    pt;
    float           intensity;
    int            bg,obj;

  Si GB_debug AlorsFait fprintf(stderr,"SetColors() Debut \n");

  bg  = 0;
  obj = 255;

  Si fabsf(min - max)<1E-5 Alors
    fprintf(stderr,"SurfacePoly::SetColors() \t min == max \n");
    max = min + 1;
  FinSi

  Si GB_debug AlorsFait fprintf(stderr,"SetColors() Set Colors to Points \n");

  Pour(i,0,_tab_pts.NbElts()-1)

    Si image->_format != WT_RGB Alors
      intensity = image->InterpLinIntensite(
					    ((float) _tab_pts[i].X()-image->TrX())/image->VoxSizeX(),
					    ((float) _tab_pts[i].Y()-image->TrY())/image->VoxSizeY(),
					    ((float) _tab_pts[i].Z()-image->TrZ())/image->VoxSizeZ());
      Si (intensity-min)/(max-min)<0 Alors
        intensity = bg;
      Autrement
      Si (intensity-min)/(max-min)>1 Alors
        intensity = obj;
      Sinon
        Si fabsf(max-min)>1E-2 Alors
          intensity = 1.0*bg + 1.0*(intensity-min)/(max-min)*(obj-bg);
        Sinon
          fprintf(stderr,"SurfacePoly::SetColors()\t|max-min|<1E-2\n");
          intensity = bg;
        FinSi
      FinSi
    
      _tab_pts[i].SetColor( (unsigned char) (intensity),
			    (unsigned char) (intensity),
			    (unsigned char) (intensity));
    Sinon
      unsigned char r,g,b;
      int x,y,z;

      x = (int) ((_tab_pts[i].X()-image->TrX())/(1.0*image->VoxSizeX()));
      y = (int) ((_tab_pts[i].Y()-image->TrY())/(1.0*image->VoxSizeY()));
      z = (int) ((_tab_pts[i].Z()-image->TrZ())/(1.0*image->VoxSizeZ()));
      Si image->CoordOK(x,y,z) Alors
        r = (unsigned char) (*image)(x,y,z,0);
        g = (unsigned char) (*image)(x,y,z,1);
        b = (unsigned char) (*image)(x,y,z,2);
        _tab_pts[i].SetColor(r,g,b);
      Sinon
        _tab_pts[i].SetColor(127,127,127);
      FinSi
    FinSi
    _tab_pts[i].SetAlpha(alpha);
  FinPour

  GLRecomputeList();
  Si GB_debug AlorsFait fprintf(stderr,"SurfacePoly::SetColors() End \n");
  return _GL_list;

} // SetColors()

//----------------------------------------------------------------------
//
GLuint SurfacePoly::SetColorOpacity( float alpha)
{
  
   
    int         i;

  Pour(i,0,_tab_pts.NbElts()-1)
      _tab_pts[i].SetAlpha(alpha);
  FinPour

  GLRecomputeList();
  return _GL_list;

} // SetColorOpacity()


//----------------------------------------------------------------------
//
GLuint SurfacePoly :: SetPointsColors(InrImage* image, 
						float min, 
						float max)
//
{

   
    int         i;
    Point3DPoly    pt;
    float           intensity;
    int            bg,obj;

  Si GB_debug AlorsFait fprintf(stderr,"SetPointsColors() Debut \n");
  if (!MakeContextCurrent()) return 0;

  bg  = 0;
  obj = 255;

  Si fabsf(min - max)<1E-5 Alors
    fprintf(stderr,"SurfacePoly::SetPointsColors() \t min == max \n");
    max = min + 1;
  FinSi


  Si image->_tx != _tab_pts.NbElts() Alors
    fprintf(stderr,"SurfacePoly::SetPointsColors() \t image size in X is not equal to the number of points \n");
    return _GL_list;
  FinSi

  Si GB_debug AlorsFait fprintf(stderr,"SetPointsColors() Set Colors to Points \n");

  Pour(i,0,_tab_pts.NbElts()-1)

    Si image->_format != WT_RGB Alors
      intensity = (*image)(i,0,0);
      Si (intensity-min)/(max-min)<0 Alors
        intensity = bg;
      Autrement
      Si (intensity-min)/(max-min)>1 Alors
        intensity = obj;
      Sinon
        Si fabsf(max-min)>1E-2 Alors
          intensity = 1.0*bg + 1.0*(intensity-min)/(max-min)*(obj-bg);
        Sinon
          fprintf(stderr,"SurfacePoly::SetPointsColors()\t|max-min|<1E-2\n");
          intensity = bg;
        FinSi
      FinSi
    
      _tab_pts[i].SetColor( (unsigned char) (intensity),
			    (unsigned char) (intensity),
			    (unsigned char) (intensity));
    Sinon
      unsigned char r,g,b;

      r = (unsigned char) (*image)(i,0,0,0);
      g = (unsigned char) (*image)(i,0,0,1);
      b = (unsigned char) (*image)(i,0,0,2);
      _tab_pts[i].SetColor(r,g,b);

    FinSi
  FinPour

  GLRecomputeList();

  return _GL_list;

} // SetPointsColors()


//----------------------------------------------------------------------
void SurfacePoly :: GLSurfaceSetDrawCC( GLuint& surf, int cc, unsigned char draw)
//
{

  Si Non(_cc_calculees) AlorsFait CalculCC();

  Si cc==-1 Alors
    _show_all_cc               = true;
  Sinon
    _show_all_cc               = false;
    _draw_cc[_sort_tab_cc[cc]] = draw;
  FinSi

  GLRecomputeList();
  surf = _GL_list;

} //  GLSurfaceSetDrawCC()


//----------------------------------------------------------------------
void SurfacePoly :: GLSurfaceDrawOnlyCC( GLuint& surf, int cc)
//
{

  
    int i;

  Si Non(_cc_calculees) AlorsFait CalculCC();

  Si cc==-1 Alors
    _show_all_cc               = true;
  Sinon
    _show_all_cc               = false;
    Pour(i,0,_nb_cc-1)
      _draw_cc[_sort_tab_cc[i]] = (i==cc);
    FinPour
  FinSi

  GLRecomputeList();
  surf = _GL_list;

} //  GLSurfaceDrawOnlyCC()


//----------------------------------------------------------------------
void SurfacePoly :: GLSurfaceMinThCC( GLuint& surf, int min_points)
//
{

    int i;

  Si Non(_cc_calculees) AlorsFait CalculCC();

  _show_all_cc               = false;
  Pour(i,0,_nb_cc-1)
    _draw_cc[i] = (_tab_cc[i].NbElts()>min_points);
  FinPour

  GLRecomputeList();
  surf = _GL_list;

} //  GLSurfaceMinThCC()


//----------------------------------------------------------------------
void SurfacePoly :: GLRecomputeList( )
//
{

   
    Point3DPoly    pt;

  if (GB_debug) printf("GLRecomputeList running\n");

  if (!MakeContextCurrent()) {
    _GL_list = 0;
    return;
  }
 
  Si _GL_list != 0 AlorsFait my_glDeleteLists( _GL_list, 1);
  my_glGenLists(_GL_list,1);

  EndGLSurface();

/*
  glNewList( _GL_list, GL_COMPILE);   
  
  Si _tab_poly.NbElts()> 0 Alors

    Pour(i,0,_tab_poly.NbElts()-1)
      _poly = _tab_poly[i];

      Si (_show_all_cc) Ou (_draw_cc[_tab_pts[_poly[0]].num_cc]) Alors
        glBegin(GL_TRIANGLE_FAN);
        Pour(j,0,_poly.NbElts()-1)
          pt = _tab_pts[_poly[j]];
          try{
           pt.AddGLPolygon();
          }
          catch (NormeFaible)
          { 
            cerr << "Poly " << i << "Norme faible pour la normale" << endl;
          }
        FinPour
        glEnd();
      FinSi

    FinPour


  Si _tab_lines.NbElts()> 0 Alors

    glDisable(GL_LIGHTING);
    glPolygonMode (GL_FRONT_AND_BACK, GL_MODE_LINE);

    Pour(i,0,_tab_lines.NbElts()-1)
      //      fprintf(stderr,"line %d ",i);fflush(stderr);
      _line = _tab_lines[i];

      Si i == _picked_line Alors
        glLineWidth(3);
      FinSi

      glBegin(GL_LINE_STRIP);

        Pour(j,0,_line.NbElts()-1)
          pt = _tab_pts[_line[j]];
          pt.AddGLLine();
        FinPour
      glEnd();

      Si i == _picked_line Alors
        glLineWidth(_line_width);
      FinSi

    FinPour

  FinSi

  Si _tab_poly.NbElts() == 0 Et _tab_lines.NbElts() == 0 Alors
    glBegin(GL_POINTS);
    Pour(i,0,_tab_pts.NbElts()-1)
      _tab_pts[i].AddGLPoint();
    FinPour
    glEnd();
  FinSi

  my_glEndList;



//  _center_x = (_xmin + _xmax)/2.0;
//  _center_y = (_ymin + _ymax)/2.0;
//  _center_z = (_zmin + _zmax)/2.0;
*/

} //  GLRecomputeList()


//----------------------------------------------------------------------
// Calcul des composantes connexes de la surface
void SurfacePoly :: CalculCC()
//
{

  
    int         i,j; 
    Point3DPoly    pt;
    int         nb_cc_displayed;


  Si _cc_calculees == true AlorsFait return;

  _tab_cc.VideTableau();
  _nb_cc = 0;

  if (GB_verbose) printf("SurfacePoly::CalculCC() liaison des points \n");
  if (GB_verbose) printf(" nb de poly %d \n",_tab_poly.NbElts());
  Pour(i,0,_tab_poly.NbElts()-1)

    Si i%1000==0 Alors
      Si i>0 Alors
        printf("\b\b\b\b\b\b");
      Sinon 
        printf("poly ");
      FinSi
      printf("%6d",i);fflush(stdout);
    FinSi    

    _poly = _tab_poly[i];

    Pour(j,1,_poly.NbElts()-1)
      RelieCC( _poly[0], _poly[j]);
    FinPour

  FinPour



  Si _sort_tab_cc != NULL Alors
    delete[] _sort_tab_cc;
//    delete[] _draw_cc;
  FinSi

  //  printf("SurfacePoly::CalculCC() tri des cc \n");
  _sort_tab_cc = new int          [_nb_cc];

  Si GB_debug AlorsFait fprintf(stderr,"Number of Connex Components  = %d \n",_nb_cc);
  Si GB_debug AlorsFait fprintf(stderr,"_tab_cc.NbElts()  = %d \n",_tab_cc.NbElts());

  _draw_cc.Resize(_tab_cc.NbElts());
//  _draw_cc     = new unsigned char[_nb_cc];

  j = 0;
  Pour(i,0,_nb_cc-1)
    //    printf(" %3d"); fflush(stdout);
    TantQue _tab_cc[j].NbElts() == 0 Faire
      j++;
      _draw_cc  += false;
    FinTantQue

    _sort_tab_cc[i] = j;
    _draw_cc  += true;
    j++;
  FinSi

  Si GB_debug AlorsFait fprintf(stderr,"j = %d \n",j);

  
//printf("Premieres Composantes connexes \n");
//  Pour(i,0,_nb_cc -1)
//    printf(" cc%3d:%3d:%3d \t",
//	   i,
//	   _sort_tab_cc[i],
//	   _tab_cc[_sort_tab_cc[i]].NbElts());
//    fflush(stdout);
//  FinSi


  // update the static array of Connex components for use in CompareCC
  static_tab_cc = _tab_cc;

  qsort(_sort_tab_cc,_nb_cc,sizeof(int),SurfacePoly::CompareCC);

  Si _nb_cc > 5 Alors
    nb_cc_displayed = 4;
  Sinon
    nb_cc_displayed = _nb_cc;
  FinSi

  if (GB_verbose) {
    printf("%d First Connex Components \n",nb_cc_displayed);
    Pour(i,0, nb_cc_displayed -1)
      printf(" cc%3d:%6d:%6d \t",
	     i,
	     _sort_tab_cc[i],
	     _tab_cc[_sort_tab_cc[i]].NbElts());
    fflush(stdout);
    FinSi
      }
  _cc_calculees = true;

} // CalculCC()


//----------------------------------------------------------------------
// Calcul des composantes connexes de la surface
void SurfacePoly :: RelieCC( int pt1, int pt2)
//
{

  
    int cc1, cc2;
    int pt;

  cc1 = _tab_pts[pt1].num_cc;
  cc2 = _tab_pts[pt2].num_cc;

//printf("RelieCC() %d %d\n",cc1,cc2);

  Si cc1 == -1 Et cc2 == -1 Alors

      CompCon cc;

    cc += pt1;
    cc += pt2;
    _tab_cc += cc;
    _nb_cc++;

    _tab_pts[pt1].num_cc =
    _tab_pts[pt2].num_cc = _tab_cc.NbElts()-1;

  Autrement
  Si cc1 == -1 Alors

    _tab_cc[cc2] += pt1;
    _tab_pts[pt1].num_cc = cc2;

  Autrement
  Si _tab_pts[pt2].num_cc == -1 Alors

    _tab_cc[cc1] += pt2;
    _tab_pts[pt2].num_cc = cc1;

  Autrement
  Si cc1 != cc2 Alors

    Si _tab_cc[cc1].NbElts() > _tab_cc[cc2].NbElts() Alors
       CompCon& cc = _tab_cc[cc2];

      Pour(pt, 0, cc.NbElts()-1)
        _tab_cc[cc1] += cc[pt];
        _tab_pts[cc[pt]].num_cc = cc1;
      FinPour

      cc.VideTableau();
      _nb_cc--;
    Sinon
       CompCon& cc = _tab_cc[cc1];

      Pour(pt, 0, cc.NbElts()-1)
        _tab_cc[cc2] += cc[pt];
        _tab_pts[cc[pt]].num_cc = cc2;
      FinPour

      cc.VideTableau();
      _nb_cc--;
    FinSi

  FinSi


} // RelieCC()


//----------------------------------------------------------------------
// Comparaison pour la fonction de trie qsort()
//
int SurfacePoly :: CompareCC( const void* pcc1, const void* pcc2 )
//
{

  int cc1,cc2;

  cc1 = *((int*) pcc1);
  cc2 = *((int*) pcc2);

  Si static_tab_cc[cc1].NbElts() > static_tab_cc[cc2].NbElts()
  Alors
    return -1;
  Autrement
  Si static_tab_cc[cc1].NbElts() < static_tab_cc[cc2].NbElts()
  Alors
    return 1;
  Sinon
    return 0;
  FinSi

} // CompareCC()


//----------------------------------------------------------------------
void SurfacePoly :: NewVectors1( )
//
{

  Si _vectors1 != 0 Alors
    my_glDeleteLists(_vectors1, 1);
    _vectors1 = 0;
  FinSi

} // NewVectors1()


//----------------------------------------------------------------------
void SurfacePoly :: NewVectors2( )
//
{

  Si _vectors2 != 0 Alors
    my_glDeleteLists(_vectors2, 1);
    _vectors2 = 0;
  FinSi

} // NewVectors2()


//----------------------------------------------------------------------
void SurfacePoly :: DisplayVectors1( GLParam* param)
//
{

   
    GLint linewidth;
    GLboolean light_enabled;
    int i;
    float x,y,z;
    float vx,vy,vz;

  Si _vectors1 == 0 Alors
    my_glGenLists(_vectors1,1);
    my_glNewList(_vectors1, GL_COMPILE);   
      glColor3f(param->_vect1_color.Red()   / 255.0,
		param->_vect1_color.Green() / 255.0,
		param->_vect1_color.Blue()  / 255.0);


      Pour(i,0,_tab_pts.NbElts()-1)
        glBegin(GL_LINES);

          x = _tab_pts[i].pt.x;
          y = _tab_pts[i].pt.y;
          z = _tab_pts[i].pt.z;

          Si param->GetVector(1) == NULL Alors
            vx = _tab_pts[i].norm.x;
            vy = _tab_pts[i].norm.y;
            vz = _tab_pts[i].norm.z;
          Sinon
  	    param->_vect1_image->FixeVecteurCoord(0);
            vx = param->_vect1_image->InterpLinIntensite(x,y,z);
  	    param->_vect1_image->FixeVecteurCoord(1);
            vy = param->_vect1_image->InterpLinIntensite(x,y,z);
  	    param->_vect1_image->FixeVecteurCoord(2);
            vz = param->_vect1_image->InterpLinIntensite(x,y,z);
	  FinSi

          vx *= param->_vect1_size;
          vy *= param->_vect1_size;
          vz *= param->_vect1_size;

          SelonQue param->_vector_type Vaut
  	    Valeur DISPLAY_VECT_ORIENTATION:
              glVertex3f( x - vx/2.0,  y - vy/2.0,  z - vz/2.0 );
              glVertex3f( x + vx/2.0,  y + vy/2.0,  z + vz/2.0 );
            FinValeur
  	    Valeur DISPLAY_VECT_DIRECTION:
              glVertex3f( x,y,z);
              glVertex3f( x + vx,  y + vy,  z + vz );
            FinValeur
          FinSelonQue

        glEnd();

      FinPour


    my_glEndList;
    
  FinSi

  glGetIntegerv(GL_LINE_WIDTH, &linewidth);
  glLineWidth(param->_vect1_width);
  glGetBooleanv(GL_LIGHTING, &light_enabled);
  glDisable(GL_LIGHTING);

  glCallList(_vectors1);

  Si light_enabled AlorsFait glEnable(GL_LIGHTING);
  glLineWidth(linewidth);

} // DisplayVectors1()



//----------------------------------------------------------------------
void SurfacePoly :: DisplayVectors2( GLParam* param)
//
{

   
    GLint linewidth;
    GLboolean light_enabled;
    int i;
    float x,y,z;
    float vx,vy,vz;

  Si _vectors2 == 0 Alors
    my_glGenLists(_vectors2,1);
    my_glNewList(_vectors2, GL_COMPILE);   
      glColor3f(param->_vect2_color.Red()   / 255.0,
		param->_vect2_color.Green() / 255.0,
		param->_vect2_color.Blue()  / 255.0);


      Pour(i,0,_tab_pts.NbElts()-1)
        glBegin(GL_LINES);

          x = _tab_pts[i].pt.x;
          y = _tab_pts[i].pt.y;
          z = _tab_pts[i].pt.z;

          Si param->GetVector(2) == NULL Alors
            vx = _tab_pts[i].norm.x;
            vy = _tab_pts[i].norm.y;
            vz = _tab_pts[i].norm.z;
          Sinon
  	    param->_vect2_image->FixeVecteurCoord(0);
            vx = param->_vect2_image->InterpLinIntensite(x,y,z);
  	    param->_vect2_image->FixeVecteurCoord(1);
            vy = param->_vect2_image->InterpLinIntensite(x,y,z);
  	    param->_vect2_image->FixeVecteurCoord(2);
            vz = param->_vect2_image->InterpLinIntensite(x,y,z);
	  FinSi

          vx *= param->_vect2_size;
          vy *= param->_vect2_size;
          vz *= param->_vect2_size;

          SelonQue param->_vector_type Vaut
  	    Valeur DISPLAY_VECT_ORIENTATION:
              glVertex3f( x - vx/2.0,  y - vy/2.0,  z - vz/2.0 );
              glVertex3f( x + vx/2.0,  y + vy/2.0,  z + vz/2.0 );
            FinValeur
  	    Valeur DISPLAY_VECT_DIRECTION:
              glVertex3f( x,y,z);
              glVertex3f( x + vx,  y + vy,  z + vz );
            FinValeur
          FinSelonQue

        glEnd();

      FinPour


    my_glEndList;
    
  FinSi

  glGetIntegerv(GL_LINE_WIDTH, &linewidth);
  glLineWidth(param->_vect2_width);
  glGetBooleanv(GL_LIGHTING, &light_enabled);
  glDisable(GL_LIGHTING);

  glCallList(_vectors2);

  Si light_enabled AlorsFait glEnable(GL_LIGHTING);
  glLineWidth(linewidth);

} // DisplayVectors2()


//----------------------------------------------------------------------
void SurfacePoly :: DisplayNormals()
//
{

   
    GLint linewidth;
    GLboolean light_enabled;
    int i;

  Si _normals == 0 Alors
    my_glGenLists(_normals,1);
    my_glNewList(_normals, GL_COMPILE);   
      glColor3f(0.9,   0.2, 0.2);


      Pour(i,0,_tab_pts.NbElts()-1)
        glBegin(GL_LINES);
          glVertex3f( _tab_pts[i].pt.x, 
		      _tab_pts[i].pt.y,
		      _tab_pts[i].pt.z);
          glVertex3f( _tab_pts[i].pt.x+1*_tab_pts[i].norm.x, 
		      _tab_pts[i].pt.y+1*_tab_pts[i].norm.y,
		      _tab_pts[i].pt.z+1*_tab_pts[i].norm.z);
        glEnd();

      FinPour


    my_glEndList;
    
  FinSi

  glGetIntegerv(GL_LINE_WIDTH, &linewidth);
  glLineWidth(3);
  glGetBooleanv(GL_LIGHTING, &light_enabled);
  glDisable(GL_LIGHTING);

  glCallList(_normals);

  Si light_enabled AlorsFait glEnable(GL_LIGHTING);
  glLineWidth(linewidth);

} // DisplayNormals()


//--------------------------------------------------    
unsigned char SurfacePoly :: ReadVRML( char* nom )
  //					GLTransfMatrix* transf,
  //					GLMaterialParam* material,
  //					GLLightParam* light)
//
{

#ifdef _use_vrml97_
   
    SceneGraph         sg; 
  
  Si GB_debug AlorsFait  fprintf(stderr,"ReadVRML(%s) \n", nom);

  sg.load(nom); 

  Si GB_debug AlorsFait  fprintf(stderr,"ReadVRML() 1 \n");

  if (!(sg.isOK())) {
    printf("lectura de %s  error\n", nom);
    return false;
  }

  Si GB_debug AlorsFait  fprintf(stderr,"ReadVRML() 2 \n");

  NewSurface();

  IndexedFaceSetNode *indexfaceset = sg.findIndexedFaceSetNode();
  IndexedLineSetNode *indexlineset = sg.findIndexedLineSetNode();
  CoordinateNode     *coord        = sg.findCoordinateNode();
  ColorNode          *color        = sg.findColorNode();
  NormalNode         *normals      = sg.findNormalNode();
  
  Si GB_debug AlorsFait   fprintf(stderr,"ReadVRML() 3 \n");

  if (coord != NULL) {
    
    int n = coord->getNPoints();  
    int i;
    float p[3];

    int   n_colors;
    float c[3];
    
    int   n_normals;
    float norm[3];

    Si color!=NULL Alors
      n_colors = color->getNColors();  
      Si n_colors != n Alors
        printf("WARNING \n le nombre de couleurs est != du nombre de points\n");
      FinSi
    Sinon
      n_colors = 0;
    FinSi

    Si normals != NULL Alors
      n_normals= normals->getNVectors();
    Sinon
      n_normals=0;
    FinSi

      //    printf("\n Points %d \n",n);
    
    Pour(i,0,n-1)

      if (i%100 == 0)
	{
	  if (i>0) printf("\b\b\b\b\b\b");
          printf("%6d",i);
	  fflush(stdout);
	}

      // Ajout du point
      coord->getPoint(i, p);
      AddPoint(p[0], p[1], p[2]);

      // Ajout d'une eventuelle couleur
      Si i< n_colors Alors
        color->getColor(i, c);
        SetColor(c[0],c[1],c[2]);
      FinSi

      // Ajout d'une eventuelle normale
      Si i< n_normals Alors
        normals->getVector(i, norm);
        SetNorm(norm[0],norm[1],norm[2]);
      FinSi

    FinPour

    printf("\b\b\b\b\b\b");
    fflush(stdout);

  }

//  fprintf(stderr,"ReadVRML() 4 \n");
  
  // Ajout des polygones    
  Si indexfaceset != NULL Alors

    int n = indexfaceset->getNCoordIndexes();
    int i,coord;
    
    // printf("\n Polygones indexes:%d \n", n);
    
    coord = -1;
    for (i=0;i<n;i++) {

      if (i%100 == 0)
	{
	  if (i>0) printf("\b\b\b\b\b\b");
          printf("%6d",i);
	  fflush(stdout);
	}

      if (coord==-1) {
	NewPoly();
      }
      coord = indexfaceset->getCoordIndex(i);
      if (coord>=0) 
	PolyAddPointNumber(coord);
      else
	EndPoly();
    }

    printf("\b\b\b\b\b\b");
    fflush(stdout);

  FinSi


  // Ajout des lignes
  Si indexlineset != NULL Alors

    int n = indexlineset->getNCoordIndexes();
    int i,coord;
    
    // printf("\n Lines indexes:%d \n", n);
    
    coord = -1;
    for (i=0;i<n;i++) {

      if (i%100 == 0)
	{
	  if (i>0) printf("\b\b\b\b\b\b");
          printf("%6d",i);
	  fflush(stdout);
	}

      if (coord==-1) {
	NewLine();
      }
      coord = indexlineset->getCoordIndex(i);
      if (coord>=0) 
	LineAddPointNumber(coord);
      else
	EndLine();
    }

    printf("\b\b\b\b\b\b");
    fflush(stdout);
  FinSi

  //  NewGLSurface();
  //  EndGLSurface();

  Si GB_debug AlorsFait  fprintf(stderr,"ReadVRML() End \n");
  return true;
#else
  return 0;
#endif

} // ReadVRML()


//----------------------------------------------------------------------
unsigned char SurfacePoly :: ReadVTK( char* nom )
//                               -------
{

#ifndef _WITHOUT_VTK_
  
  boost::shared_ptr<vtkPolyDataReader> reader;
  vtkPolyData* poly; 

  fprintf(stderr,"SurfacePoly::ReadVTK() begin \n");

  reader = vtk_new<vtkPolyDataReader>()();
  reader->SetFileName(nom);
  if (reader->IsFilePolyData( )) {
    reader->Update();
    poly = reader->GetOutput();
    AddVTKPoly(poly);
    //fprintf(stderr,"SurfacePoly::ReadVTK() end \n");
    return true;
  } else {
    return false;
  }

#else
  fprintf(stderr,"SurfacePoly::ReadVTK()\t VTK not available ...\n");
  return false;
#endif // _WITHOUT_VTK_
} // ReadVTK()



 //----------------------------------------------------------------------
unsigned char SurfacePoly :: Read( char* nom )
//                               ----
{
  bool result = false;
  result = ReadVTK(nom);
  if (!result)
    result = ReadVRML(nom);

  return result;
} // Read()

//----------------------------------------------------------------------
void SurfacePoly :: WriteVRML( char* nom,
					 GLTransfMatrix*  transf,
					 GLMaterialParam* material,
					 GLLightParam*    light,
					 GLParam*         param)
//
{

   
#ifdef _use_vrml97_
    SceneGraph         sg; 
    ShapeNode          *shape;
    IndexedFaceSetNode *indexfaceset;
    IndexedLineSetNode *indexlineset=NULL;
    CoordinateNode     *coord;
    NormalNode         *normals;
    ColorNode          *colors;
    float normal[3];
    float scale[3];
    float tr[3];
    float rgb[3];
#define SetRGB(a,b,c)    {rgb[0]=a;  rgb[1]=b;  rgb[2]=c;}

    TransformNode       *transform;
    BackgroundNode      *background;

    int        n,p;
    Point3DPoly   point;
    T_Line        line;
    SurfPoly      poly;
    float          NormNormal;

    unsigned char show_poly;

    // Renumerotation pour ne sauver que les points utilises
    int*       pts_sauves;
    int        num_point=0;

printf("SurfacePoly::WriteVRML()\n");


  shape        = NULL;
  indexfaceset = NULL;
  coord        = NULL;
  normals      = NULL;
  colors       = NULL;
  transform    = NULL;
  colors       = NULL;

  // Background
  //
  Si param != NULL Alors
    float color[3];

    background = new BackgroundNode();
    sg.addNode(background);


    color[0] = param->_background.red  /255.0;
    color[1] = param->_background.green/255.0;
    color[2] = param->_background.blue /255.0;
    background->addSkyColor( color);
  FinSi

  // Navigation Info
  //
  NavigationInfoNode nav;
  sg.addNode(&nav);
  nav.addType("EXAMINE");
  nav.addType("ANY");

  nav.addAvatarSize(0.25);
  nav.addAvatarSize(1.6);
  nav.addAvatarSize(0.75);
  nav.setHeadlight(false);
  nav.setVisibilityLimit(0.0);

  // Viewpoint
  //
  ViewpointNode viewpoint;
  sg.addNode(&viewpoint);
  viewpoint.setPosition(    0,0,0);
  viewpoint.setOrientation( 0,1,0,180);
  viewpoint.setFieldOfView( 0.628);
 
  Si (param!=NULL) Et (param->_lighting) AlorsFait
  Si (light != NULL)Et(light->_enabled) Alors
    Si light->_directional Alors
      DirectionalLightNode*  l = new DirectionalLightNode();
      sg.addNode(l);

      l->setDirection       (light->_position[0], 
			     light->_position[1], 
			     light->_position[2]);

      l->setColor    (light->_diffuse.red  /255.0,
		      light->_diffuse.green/255.0, 
		      light->_diffuse.blue /255.0);

      l->setAmbientIntensity(
			     (light->_ambient.red+
			      light->_ambient.green+
			      light->_ambient.blue
			      )/3.0/255.0
			     );
    Sinon
      PointLightNode* l = new PointLightNode();
      sg.addNode(l);

      l->setAmbientIntensity(
			     (light->_ambient.red+
			      light->_ambient.green+
			      light->_ambient.blue
			      )/3.0/255.0
			     );

      l->setLocation       (light->_position[0], 
			    light->_position[1], 
			    light->_position[2]);

//    l->SetRadius();
//    l->SetAttenuation();

      l->setColor    (light->_diffuse.red  /255.0,
		      light->_diffuse.green/255.0, 
		      light->_diffuse.blue /255.0);


    FinSi
  FinSi


  // Transformation
  //
  Si transf != NULL Alors
    transform = new TransformNode();
    sg.addNode(transform);

    scale[0] = transf->_scale[0];
    scale[1] = transf->_scale[1];
    scale[2] =  transf->_scale[2];
    transform->setScale(  scale);

//    transform->setRotation(   transf->_rotation);
    tr[0] = transf->_translation[0]*scale[0];
    tr[1] = transf->_translation[1]*scale[1];
    tr[2] = transf->_translation[2]*scale[2];
    transform->setTranslation( tr);
  FinSi


  // Add a new shape 
  shape = new ShapeNode(); 
  sg.addNode(shape); 

  if (transform != NULL) transform->addChildNode(shape); 
 
  Si (param!=NULL)Et (param->_lighting) AlorsFait
  Si material != NULL Alors
    AppearanceNode* app = new AppearanceNode();
    MaterialNode*   mat = new MaterialNode();
 
    shape->addChildNode(app);
    app->addChildNode(mat);
 
//    mat->setAmbientIntensity();
 
    mat->setDiffuseColor(material->_diffuse.red  /255.0,
			 material->_diffuse.green/255.0,
			 material->_diffuse.blue /255.0);
 
    mat->setSpecularColor(material->_specular.red  /255.0,
			  material->_specular.green/255.0,
			  material->_specular.blue /255.0);
 
    mat->setEmissiveColor(material->_emission.red  /255.0,
			  material->_emission.green/255.0,
			  material->_emission.blue /255.0);
//    mat->setShininess(material->_shininess);
 
    mat->setTransparency(1-material->_opacity);
 
  FinSi


  if (_tab_poly.NbElts()!=0) {
    // IndexedFaceSet
    indexfaceset = new IndexedFaceSetNode();
    shape->addChildNode(indexfaceset);
    // Cull Face
    Si param!=NULL AlorsFait
      indexfaceset->setSolid(param->_cullface);
  }

  if (_tab_lines.NbElts()!=0) {
    // IndexedLineSet
    indexlineset = new IndexedLineSetNode();
    shape->addChildNode(indexlineset);
  }



// Write the points

  Si _cc_calculees Et (_show_all_cc == false) Alors
    pts_sauves = new int [_tab_pts.NbElts()];
    num_point  = 0;
  Sinon
    pts_sauves = NULL;
  FinSi

  coord   = new CoordinateNode();
  if (_tab_poly.NbElts()!=0) 
    indexfaceset->addChildNode( coord   );
  else
  if (_tab_lines.NbElts()!=0)
    indexlineset->addChildNode( coord   );

  Si (param!=NULL) Et Non(param->_lighting) Alors
    colors  = new ColorNode();
    if (_tab_poly.NbElts()!=0) 
      indexfaceset->addChildNode( colors  );
  FinSi

  Si (param!=NULL) Et (param->_lighting) Alors
    normals = new NormalNode();
    if (_tab_poly.NbElts()!=0) 
      indexfaceset->addChildNode( normals );
  FinSi

  Pour( n, 0, _tab_pts.NbElts()-1)

    point = _tab_pts[n];

    Si pts_sauves!= NULL AlorsFait
    Si _draw_cc[point.num_cc] Alors
      pts_sauves[n] = num_point;
      num_point++;
    Sinon
      pts_sauves[n] = -1;
      continue;
    FinSi   

    coord->addPoint(point.pt.x,
		    point.pt.y,
		    point.pt.z);

    // Ajout de la normale (-gradient)

    Si (param!=NULL) Et  (param->_lighting) Alors
      normal[0] = point.norm.x;
      normal[1] = point.norm.y;
      normal[2] = point.norm.z;

      NormNormal = sqrt(
			normal[0]*normal[0] +
			normal[1]*normal[1] +
			normal[2]*normal[2]
			);

      Si NormNormal > 1E-2 Alors
        normal[0] = point.norm.x/NormNormal;
        normal[1] = point.norm.y/NormNormal;
        normal[2] = point.norm.z/NormNormal;
      Sinon
        normal[0] =
        normal[1] =
        normal[2] = 0.0;
      FinSi

      normals->addVector(normal);
    FinSi

    SetRGB(point.red  /255.0,
	   point.green/255.0,
	   point.blue /255.0);

    Si (param!=NULL) Et Non(param->_lighting) Alors
      SetRGB(point.red  /255.0,
	     point.green/255.0,
	     point.blue /255.0);
      colors->addColor(rgb);
    FinSi

  FinPour


  // Write the polygons
  Pour(p, 0, _tab_poly.NbElts()-1) 
    poly = _tab_poly[p];

    // Temporary solution
    // in case of the computation of connex component
    // save only the main connex component
    // otherwise save all the polygons

    show_poly = true;
    Si _cc_calculees Et (_show_all_cc == false) AlorsFait
      show_poly=_draw_cc[_tab_pts[poly[0]].num_cc];

    Si show_poly 
    Alors
      Pour( n, 0, poly.NbElts()-1)
        Si pts_sauves != NULL Alors
          indexfaceset->addCoordIndex(pts_sauves[poly[n]]);
        Sinon
          indexfaceset->addCoordIndex(poly[n]);
        FinSi
      FinPour  //i
      indexfaceset->addCoordIndex(-1);
    FinSi

  FinPour 

  // Write the lines
  Pour(p, 0, _tab_lines.NbElts()-1) 
    line = _tab_lines[p];
    Pour(n,0,line.NbElts()-1)
      indexlineset->addCoordIndex(line[n]);
    FinPour
    indexlineset->addCoordIndex(-1);
  FinPour

  Si pts_sauves != NULL AlorsFait delete[] pts_sauves;

  sg.save(nom);

/*
  Si shape        != NULL AlorsFait delete shape;
  Si indexfaceset != NULL AlorsFait delete indexfaceset;
  Si coord        != NULL AlorsFait delete coord;
  Si normals      != NULL AlorsFait delete normals;
  Si colors       != NULL AlorsFait delete colors;
  Si transform    != NULL AlorsFait delete transform;
  Si colors       != NULL AlorsFait delete colors;
*/
#endif // _use_vrml97_

} // WriteVRML()


//----------------------------------------------------------------------
void SurfacePoly :: WriteVTK( char* nom)
//                            --------
{

#ifndef _WITHOUT_VTK_

  
    vtkPolyData*       vtk_surf;
    vtkPolyDataWriter* writer;

fprintf(stderr,"writing vtk ...\n");
  vtk_surf = (vtkPolyData*) (*this);
fprintf(stderr,"writing vtk 2 ...\n");

  writer = vtkPolyDataWriter::New();

  writer->SetInput( vtk_surf);
  writer->SetFileTypeToBinary();
  //  writer->SetFileTypeToASCII();
  writer->SetFileName(nom);
  writer->Write();

  writer  ->Delete();
  vtk_surf->Delete();

#else
  fprintf(stderr,"SurfacePoly::WriteVTK()\t VTK not available ...\n");
#endif // _WITHOUT_VTK_

} // WriteVTK()


//----------------------------------------------------------------------
void SurfacePoly :: Write( char* nom)
//                            -----
{

  Si CheckEndString(nom,".vtk") Alors
    WriteVTK(nom);
  Sinon
    WriteVRML(nom);
  FinSi

} // Write()


//----------------------------------------------------------------------
// Triangulates the surface
//
void SurfacePoly :: Triangulate()
//                            -----------
{

    int i,nb_polys;
    int j,nb_vert;
    int nb_poly[13]; // number of polygons with 3,4,5,6,..,12 vertices

  nb_polys = GetNumberOfPolys();

  Pour(i,0,12)  
    nb_poly[i] = 0;
  FinPour

  Pour(i,0,nb_polys-1)
    nb_poly[_tab_poly[i].NbElts()]++;
  FinPour

  Pour(i,0,12)  
    printf("number of polygons with %2d vertices : %6d \n",
	   i,nb_poly[i]);
  FinPour
  
  Pour(i,0,nb_polys-1)

    nb_vert = _tab_poly[i].NbElts();
    Si nb_vert < 4 AlorsFait continue;
    Pour(j,2,nb_vert-1)
      // To Finish
    FinPour

  FinPour

} // Triangulate()


//----------------------------------------------------------------------
// 
// Remove a line
//
void SurfacePoly :: RemoveLine(  int line)
//                            ----------
{

  // save current configuration
  BackupLines();

  Si line<0 Ou line>=_tab_lines.NbElts() Alors
    fprintf(stderr,"SurfacePoly::RemoveLine() \t incorrect line number \n");
    return;
  FinSi

  _tab_lines[line].VideTableau();
    
} // RemoveLine()



//----------------------------------------------------------------------
// 
// Connect 2 lines
//
void SurfacePoly :: ConnectLines(  int line1, int line2)
//                            ------------
{

  
    int         p[2][2];
    int         n1,n2;
    int         i,j;
    T_Line      newline;
    Point3DPoly p1,p2;
    int         emin1=0,emin2=0;
    float       d[2][2];
    float       dmin=0;
    int         pos;
  
  // save current configuration
  BackupLines();

  Si line1<0 Ou line1>_tab_lines.NbElts()-1 Ou
     line2<0 Ou line2>_tab_lines.NbElts()-1 Ou
    _tab_lines[line1].NbElts() <2 Ou
    _tab_lines[line2].NbElts() <2 
  Alors
    fprintf(stderr,"SurfacePoly::ConnectLines() \t incorrect line numbers \n");
    return;
  FinSi

  n1 = _tab_lines[line1].NbElts();
  n2 = _tab_lines[line2].NbElts();

  p[0][0] = _tab_lines[line1][0];
  p[0][1] = _tab_lines[line1][n1-1];

  p[1][0] = _tab_lines[line2][0];
  p[1][1] = _tab_lines[line2][n2-1];

  // Check for the closest extremities
  Pour(i,0,1)
  Pour(j,0,1)
    p1 = _tab_pts[p[0][i]];
    p2 = _tab_pts[p[1][j]];
    d[i][j]=sqrt((p1.pt.x-p2.pt.x)*(p1.pt.x-p2.pt.x)+
		 (p1.pt.y-p2.pt.y)*(p1.pt.y-p2.pt.y)+
		 (p1.pt.z-p2.pt.z)*(p1.pt.z-p2.pt.z)
		 );
    Si i==0 Et j==0 Alors
      emin1 = i;
      emin2 = j;
      dmin=d[i][j];
    Sinon
      Si d[i][j]<dmin Alors
        emin1 = i;
        emin2 = j;
        dmin=d[i][j];
      FinSi
    FinSi
  FinPour
  FinPour
 
  // Create a new line

  // Add line 1
  Si emin1==1 Alors
    Pour(i,0,n1-1)
	newline+=_tab_lines[line1][i];
    FinPour
  Sinon
    Pour(i,0,n1-1)
	newline+=_tab_lines[line1][n1-1-i];
    FinPour
  FinSi
    
  // Add line 2
  Si emin2==0 Alors
    Si newline[n1-1]!=_tab_lines[line2][0] AlorsFait
      newline+=_tab_lines[line2][0];
    Pour(i,1,n2-1)
      newline+=_tab_lines[line2][i];
    FinPour
  Sinon
    Si newline[n1-1]!=_tab_lines[line2][n2-1] AlorsFait
      newline+=_tab_lines[line2][n2-1];
    Pour(i,1,n2-1)
	newline+=_tab_lines[line2][n2-1-i];
    FinPour
  FinSi

  _tab_lines[line1] = newline;

  pos = _selected_lines.Position(line2);
  Si pos != -1 Alors
    _selected_lines.Supprime(pos);
  FinSi
  _tab_lines[line2].VideTableau();
  
    
} // ConnectLines()


//----------------------------------------------------------------------
// Undo last operation on lines
//
void SurfacePoly :: BackupLines()
//                            --------
{

  // save current configuration
  _tab_lines_backup      = _tab_lines;
  _selected_lines_backup = _selected_lines;

}


//----------------------------------------------------------------------
// Undo last operation on lines
//
void SurfacePoly :: UndoLast()
//                            --------
{

  // save current configuration
  _tab_lines             = _tab_lines_backup;
  _selected_lines_backup = _selected_lines;

}

//----------------------------------------------------------------------
// Merge the points which distance is smaller than dist
// and returns a new object of type "SurfacePoly"
//
void SurfacePoly :: MergePoints(  float dist)
//                            -----------
{

  
    int            i,j,n,l;
    int            pos0,pos1;
    Point3DPoly    p;
    Point3DPoly    p0;
    Point3DPoly    p1;
    Vect3D<float>  d;
    float          dist2;
    int            poly,poly_pos1,poly_pos0;
    TableauDyn<SurfPoly>    old_tab_poly;

  ComputeNeighbors();

  i = 0;
  TantQue i < GetNumberOfPolys() Faire

  if (i==0) {
    printf("poly number %6d",i);
    fflush(stdout);
  } else
  if (i%1000==0) { 
    printf("\b\b\b\b\b\b%6d",i); 
    fflush(stdout); 
  }

    n = _tab_poly[i].NbElts();
    Si n<=1 Alors
      i++;
      continue;
    FinSi
    pos0 = _tab_poly[i][0];
    p0   = (*this)[pos0];
    Pour(j,1,n)
      pos1 = _tab_poly[i][j%n];
      p1   = (*this)[pos1];
   
      // Check distance
      d = p1.pt - p0.pt;
      dist2 = d*d;
      Si dist2 < dist*dist Alors 
      //        fprintf(stderr,"MergePoints() \t Merge %d %d \n", pos0, pos1);
        Si GB_debug AlorsFait fprintf(stderr,"p1._neighbors.NbElts() = %d \n",     p1._neighbors.NbElts());

        // Removal of the point number p1 in the polygons
        Pour(l,0,p1._neighbors.NbElts()-1)

          Si GB_debug AlorsFait  fprintf(stderr,"l = %d \n", l);

          poly      = p1._neighbors[l];
          poly_pos0 = _tab_poly[poly].Position(pos0);
          poly_pos1 = _tab_poly[poly].Position(pos1);
          Si poly_pos1>=0 Alors
            Si poly_pos0>=0 Alors
              Si GB_debug AlorsFait  fprintf(stderr,"case 1 \n");
              _tab_poly[poly].Supprime( poly_pos1);
            Sinon
              Si GB_debug AlorsFait  fprintf(stderr,"case 2 \n");
  	      _tab_poly[poly][poly_pos1] = pos0;
              // Update of the list of neighbors of the point p0
              Si Non(p0._neighbors.Existe(poly)) AlorsFait
  	        (*this)[pos0]._neighbors += poly;
            FinSi
          FinSi
          

        FinPour

        i--;
        break;

      FinSi
      p0   = p1;
      pos0 = pos1;
    FinPour

    i++;
  FinTantQue

  printf("\b\b\b\b\b\b\n");
  fprintf(stderr,"Removal of polygons \n");

  // Removal of the polygons with less than three points ?
  
  old_tab_poly = _tab_poly;

  i = 0;
  j = 0;
  n = GetNumberOfPolys();
  TantQue i < n Faire

    Si old_tab_poly[i].NbElts() > 2 Alors
      _tab_poly[j] = old_tab_poly[i];
      j++;
    FinSi
    i++;

  FinTantQue

  Pour(i,j,n-1)
    _tab_poly.Supprime(_tab_poly.NbElts()-1);
  FinPour

} // MergePoints()



//----------------------------------------------------------------------
// Merge the points which distance is smaller than dist
// and returns a new object of type "SurfacePoly"
// cmin and cmax min and max curvatures
// dmin and dmax directions of min and max curvatures
//
// Surface must be triangulated ...
//
// based on Steve Hacker code (thanks)
//
void SurfacePoly :: ComputeCurvatures(  InrImage* Icmin, InrImage* Icmax, 
//                            -----------------
						  InrImage* Idmin, InrImage* Idmax,
						  int depth)
{

  
    Vect3D<float>              normal,b1,b2;
    Vect3D<float>              vect;
    Vect3D<float>              Utz,U;
    double                    UtU[3][3];
    double                    I  [3][3];
    double                    C  [2][2];
    double                    cmax,cmin,D;
    int                    i,j,nbpts,n,l;

    TableauDyn<int>           neighbors;
//    TableauDyn<Vect3D<float>>  neighbors;

    unsigned char*            in_neighbors;
    Point3DPoly               p0,p1;
    int                       poly,pt;
    int                       prev_depth_pos,new_depth_pos;
    int                       current_depth;
    double                    x,y,z;
    double                    det;

    double                    mean_curv;
    double                    gauss_curv;
    double                    tmp;
    double                    dmin[2];

  nbpts = _tab_pts.NbElts();

  in_neighbors = new unsigned char[nbpts];
  Pour(i,0,nbpts-1)
    in_neighbors[i] = false;
  FinPour

  // Check the images
  Si (Icmin==NULL) Ou (Icmin->_tx != _tab_pts.NbElts()) AlorsFait
    fprintf(stderr,"SurfacePoly::ComputeCurvatures() \t cmin Image not valid \n");
  Si (Icmax==NULL) Ou (Icmax->_tx != _tab_pts.NbElts()) AlorsFait
    fprintf(stderr,"SurfacePoly::ComputeCurvatures() \t cmax Image not valid \n");
  Si (Idmin==NULL) Ou (Idmin->_tx != _tab_pts.NbElts()) AlorsFait
    fprintf(stderr,"SurfacePoly::ComputeCurvatures() \t dmin Image not valid \n");
  Si (Idmax==NULL) Ou (Idmax->_tx != _tab_pts.NbElts()) AlorsFait
    fprintf(stderr,"SurfacePoly::ComputeCurvatures() \t dmax Image not valid \n");

  ComputeNeighbors();

  // Compute normal to triangles ? 
  // to do ?

  Icmin->InitBuffer();
  Icmax->InitBuffer();
  Idmin->InitBuffer();
  Idmax->InitBuffer();

  // compute the curvatures for each point
  Pour(i,0,nbpts-1)

    // Compute the basis (normal,b1,b2)
    // ---------------------------------

    // for the moment, take the normal 
    //
    normal = _tab_pts[i].norm;

    try {
      normal.Normalise();
    }
    catch (NormeFaible) {
      //
      fprintf(stderr,"SurfacePoly::ComputeCurvatures() \t weak normal \n");
    }

    // find 2 other vectors for a 3D basis
    // find vector b1 
    if (fabs(normal.x)>=fabs(normal.y) && fabs(normal.x)>=fabs(normal.z))
      {
	b1.x = -normal.y-normal.z;
	b1.y = normal.x;
	b1.z = normal.x;
      }
    else {
      if (fabs(normal.y)>=fabs(normal.x) && fabs(normal.y)>=fabs(normal.z))
	{
	  b1.y = -normal.x-normal.z; 
	  b1.x = normal.y;
          b1.z = normal.y;
	}
      else
	{
	  b1.x = b1.y = normal.z; 
	  b1.z = -normal.x - normal.y;
	}
    }

    try {
      b1.Normalise();
    }
    catch (NormeFaible) {
      //
      fprintf(stderr,"SurfacePoly::ComputeCurvatures() \t weak b1 \n");
    }
      
    // find vector b2 (cross product) 
    b2 = normal^b1;

    // find vertex neighbors out to the desired depth
    // --------------------------------------------------

    neighbors.VideTableau();
    prev_depth_pos = 0;
    new_depth_pos  = 0;
    current_depth  = 0;

    neighbors      += i;
    in_neighbors[i] = true;
    p0 = (*this)[neighbors[0]];


    Repeter

      current_depth++;
      
      prev_depth_pos = new_depth_pos;
      new_depth_pos  = neighbors.NbElts();

      Pour( n, prev_depth_pos, new_depth_pos-1)

        p1 = (*this)[neighbors[n]];

        Pour(l,0,p1._neighbors.NbElts()-1)
   
          poly            = p1._neighbors[l];
	if (_tab_poly[poly].NbElts()!=3) fprintf(stderr," %d elts\n",_tab_poly[poly].NbElts());
          Pour(j,0,_tab_poly[poly].NbElts()-1)
            pt = _tab_poly[poly][j];
            Si Non(in_neighbors[pt]) Alors
  	      neighbors       += pt;
  	      in_neighbors[pt] = true;
            FinSi
          FinPour
       FinPour

      FinPour

    JusquA (current_depth >= depth) FinRepeter


    // Compute the  matrix and the vector for the min square minimization
    // --------------------------------------------------

    in_neighbors[i] = false;
    Utz.Init(0,0,0);
 
    UtU[0][0] =    UtU[0][1] =    UtU[0][2] =
    UtU[1][0] =    UtU[1][1] =    UtU[1][2] =
    UtU[2][0] =    UtU[2][1] =    UtU[2][2] = 0.0;
 
    Pour(n,1,neighbors.NbElts()-1)

      in_neighbors[neighbors[n]] = false;
      p1 = (*this)[neighbors[n]];
      vect   = p1.pt - p0.pt;
      x      = vect*b1;
      y      = vect*b2;
      z      = vect*normal;


      U.x = x*x; 
      U.y = 2*x*y; 
      U.z = y*y; 

      UtU[0][0] += U.x*U.x;
      UtU[0][1] += U.x*U.y;
      UtU[0][2] += U.x*U.z;
      UtU[1][1] += U.y*U.y;
      UtU[1][2] += U.y*U.z;
      UtU[2][2] += U.z*U.z;

      Utz.x += z*U.x;
      Utz.y += z*U.y;
      Utz.z += z*U.z;

    FinPour

    UtU[1][0] = UtU[0][1];
    UtU[2][0] = UtU[0][2];
    UtU[2][1] = UtU[1][2];
    

    // Invert UtU and deduce the parameters of the symetric matrix C(2,2)
    // --------------------------------------------------

    det =
          UtU[0][0]*( UtU[1][1]*UtU[2][2]-UtU[2][1]*UtU[1][2]) +
          UtU[0][1]*( UtU[1][2]*UtU[2][0]-UtU[2][2]*UtU[1][0]) +
          UtU[0][2]*( UtU[1][0]*UtU[2][1]-UtU[2][0]*UtU[1][1]) ;

    if (det==0.0) {
      det=1.0; 
      I[0][0]=I[1][1]=I[2][2]=1.0;
      I[0][1]=I[0][2]=I[1][2]=0.0;
    }
    else {
      I[0][0]=(UtU[1][1]*UtU[2][2]-UtU[1][2]*UtU[1][2])/det;
      I[0][1]=(UtU[0][2]*UtU[1][2]-UtU[0][1]*UtU[2][2])/det;
      I[0][2]=(UtU[0][1]*UtU[1][2]-UtU[0][2]*UtU[1][1])/det;
      I[1][1]=(UtU[0][0]*UtU[2][2]-UtU[0][2]*UtU[0][2])/det;
      I[1][2]=(UtU[0][1]*UtU[0][2]-UtU[0][0]*UtU[1][2])/det;
      I[2][2]=(UtU[0][0]*UtU[1][1]-UtU[0][1]*UtU[0][1])/det;
    }
    I[1][0]=I[0][1]; I[2][0]=I[0][2]; I[2][1]=I[1][2];

    // find c, mult by 2.0 
    C[0][0]=-2.0*(I[0][0]*Utz.x+I[0][1]*Utz.y+I[0][2]*Utz.z);
    C[0][1]=-2.0*(I[1][0]*Utz.x+I[1][1]*Utz.y+I[1][2]*Utz.z);
    C[1][1]=-2.0*(I[2][0]*Utz.x+I[2][1]*Utz.y+I[2][2]*Utz.z);
    C[1][0]=C[0][1];

    mean_curv  = (C[0][0]+C[1][1])*0.5;
    gauss_curv = (C[0][0]*C[1][1]-C[1][0]*C[0][1]);

    D    = sqrt(mean_curv*mean_curv-gauss_curv);
    cmin = mean_curv - D; 
    cmax = mean_curv + D; 

    Icmin->BufferPos(i,0,0);
    Icmin->FixeValeur(cmin);
    Icmax->BufferPos(i,0,0);
    Icmax->FixeValeur(cmax);

    // find eigenvectors
    C[0][0] -= cmin;
    C[1][1] -= cmin; // now with eigenvalue 0
     
    if ( fabs(C[0][0])>=fabs(C[0][1]) && fabs(C[0][0])>=fabs(C[1][1]) ) {
      tmp=(C[0][0]==0.0)?1.0:C[0][0];
      dmin[0]=-C[0][1]/tmp; 
      dmin[1]=1.0;
    }
    else  {
      if  ( fabs(C[0][1])>=fabs(C[0][0]) && fabs(C[0][1])>=fabs(C[1][1]) ){

	tmp=(C[0][1]==0.0)?1.0:C[0][1];
	dmin[0]=-C[1][1]/tmp; 
	dmin[1]=1.0;

      } else {

	tmp=(C[1][1]==0.0)?1.0:C[1][1];
	dmin[0]=1.0;
	dmin[1]=-C[0][1]/tmp;

      }
    }

    tmp = sqrt(dmin[0]*dmin[0]+dmin[1]*dmin[1]);
    Si tmp>1E-5 Alors
      dmin[0] /= tmp;
      dmin[1] /= tmp;
    FinSi
 
    Idmin->BufferPos(i,0,0);
    Idmin->VectFixeValeurs( dmin[0]*b1.x + dmin[1]*b2.x,
			    dmin[0]*b1.y + dmin[1]*b2.y,
			    dmin[0]*b1.z + dmin[1]*b2.z
			    );

    Idmax->BufferPos(i,0,0);
    Idmax->VectFixeValeurs( -dmin[1]*b1.x + dmin[0]*b2.x,
			    -dmin[1]*b1.y + dmin[0]*b2.y,
			    -dmin[1]*b1.z + dmin[0]*b2.z
			    );

    Icmin->IncBuffer();
    Icmax->IncBuffer();
    Idmin->IncBuffer();
    Idmax->IncBuffer();

  FinPour

  delete [] in_neighbors;

} // ComputeCurvatures()
 

// ----------------------------------------------------------------------
InrImage* SurfacePoly :: GetImageLinesLength()
//                                 --------------
{

  InrImage* res;
  int n;
  Point_3D<float> p0,p1;
  double length;
  int i,l;

  n=_tab_lines.NbElts();
  res = new InrImage(n,1,1,WT_FLOAT,"lines_length.ami.gz");

  res->InitBuffer();
  for (l=0;l<n;l++) {
    length=0;
    for(i=1;i<GetLine(l).NbElts();i++) {
      p0=GetPoint(GetLine(l)[i-1]).pt;
      p1=GetPoint(GetLine(l)[i]).pt;
      length += Norme(p0-p1);
    }
    res->FixeValeur(length);
    res->IncBuffer();
  }
  
  return res;

} // GetImageLinesLength()


// ----------------------------------------------------------------------
// nb of lines connected to each point
//
InrImage* SurfacePoly :: GetImageConnections()
//                       -------------------
{

  InrImage* res;
  int n,nl,l;
//  float x,y,z;

  n=_tab_pts.NbElts();
  res = new InrImage(n,1,1,WT_UNSIGNED_SHORT,"connections.ami.gz");
  res->InitImage(0);

  nl=_tab_lines.NbElts();
  for (l=0;l<nl;l++) {
    if (GetLine(l).NbElts()>0) {
      res->BufferPos(GetLine(l)[0],0,0);
      res->FixeValeur(res->ValeurBuffer()+1);
      res->BufferPos(GetLine(l)[GetLine(l).NbElts()-1],0,0);
      res->FixeValeur(res->ValeurBuffer()+1);
    }
  }


  return res;

} // GetImageConnections()


// ----------------------------------------------------------------------
// Image Mx2 where M is the number of lines and containing the 
// point id of the 2 extremities of each line
//  
InrImage* SurfacePoly ::  GetImageLinesExtremities( )
//                                  ------------------------
{

  InrImage* res;
  int n;
  int l;

  n=_tab_lines.NbElts();
  res = new InrImage(n,2,1,WT_UNSIGNED_INT,"linesextremities.ami.gz");

  for (l=0;l<n;l++) {
    if (GetLine(l).NbElts()>0) {
      res->BufferPos(l,0,0);
      res->FixeValeur(GetLine(l)[0]);
      res->BufferPos(l,1,0);
      res->FixeValeur(GetLine(l)[GetLine(l).NbElts()-1]);
    }
  }
  
  return res;


} // GetImageLinesExtremities()


// ----------------------------------------------------------------------
InrImage* SurfacePoly :: GetIntensities(  InrImage* image)
//                            --------------
{

  InrImage* res;
  int n,i;
  float x,y,z;

  n=_tab_pts.NbElts();
  res = new InrImage(n,1,1,image->_format,"intensities.ami.gz");

  res->InitBuffer();  
  for(i=0;i<n;i++) {
    x = ((float) _tab_pts[i].X())/image->VoxSizeX()-image->TrX();
    y = ((float) _tab_pts[i].Y())/image->VoxSizeY()-image->TrY();
    z = ((float) _tab_pts[i].Z())/image->VoxSizeZ()-image->TrZ();
    if (res->ScalarFormat())
      res->FixeValeur( image->InterpLinIntensite(x,y,z));
    else
      // Vectorial mode not implemented
      res->VectFixeValeurs(0,0,0);
    res->IncBuffer();
  }

  return res;

} // GetIntensities()


// ----------------------------------------------------------------------
// Recompute the normals
//
void SurfacePoly :: RecomputeNormals()
//                            -----------------
{
    int         i0,i1,i2,p,nbpts;
    Point_3D<float> p0,p1,p2;
    Vect3D<float>   n,n1,n2;
    unsigned char        AddNormal;

  // To optimize for a triangulated surface ?

  // Reset the normals to 0
  Pour(p,0,GetNumberOfPoints()-1)
    _tab_pts[p].norm.Init(0.01, 0.0, 0.0);
    _tab_pts[p].num_norm = 0.1;
    _tab_pts[p].norm_fixed = false;
  FinPour

  // 2. Compute the normals by parsing the polygons

  Pour(p,0,GetNumberOfPolys()-1)

    nbpts = _tab_poly[p].NbElts();

    Pour(i1,0,nbpts-1)

      i0 = (i1+nbpts-1) % nbpts;
      i2 = (i1      +1) % nbpts;

      p0 = _tab_pts[_tab_poly[p][i0]].pt;
      p1 = _tab_pts[_tab_poly[p][i1]].pt;
      p2 = _tab_pts[_tab_poly[p][i2]].pt;

      n = (p1-p0)^(p2-p1);

      AddNormal = true;

      try {
        n.Normalise();
      }
      catch (NormeFaible) {

        //     Si GB_debug AlorsFait 
	if (GB_verbose) fprintf(stderr,"SurfacePoly:RecomputeNormals() \t poly %d/%d   nbpts %d   i1=%d \n", p,GetNumberOfPolys()-1,nbpts,i1);


       try{
          n1 = p1-p0;
          // if n1 too small try with previous point
          int i = 0;
          while ((Norme(n1)<1E-5)&&(i<nbpts-1)) {
            i++;
            i0 = (i1+nbpts-1-i) % nbpts;
            p0 = _tab_pts[_tab_poly[p][i0]].pt;
            n1 = p1-p0;
          }
          n1.Normalise();

          n2 = p2-p1;
          i = 0;
          while ((Norme(n2)<1E-5)&&(i<nbpts-1)) {
            i++;
            i2 = (i1+1+i) % nbpts;
            p2 = _tab_pts[_tab_poly[p][i2]].pt;
            n2 = p2-p1;
          }
          n2.Normalise();
  
          n = n1^n2;
          n.Normalise();
        }
        catch (NormeFaible) {
          if (GB_verbose) fprintf(stderr,"probleme normalisation vecteur normal \n");
          AddNormal = false;
        }

      }
    
      Si AddNormal AlorsFait _tab_pts[_tab_poly[p][i1]].AddNormal( n);
    FinPour

  FinPour


} // RecomputeNormals()

// ----------------------------------------------------------------------
// Invert the normals
//
void SurfacePoly :: InvertNormals()
//                            -------------
{
  int p;
  // Invert the normals 
  Pour(p,0,GetNumberOfPoints()-1)
    _tab_pts[p].norm = (_tab_pts[p].norm)*((float)-1.0);
  FinPour

} // InvertNormals()


// ----------------------------------------------------------------------
// Displaces each point in the normal direction
// with a distance given by the image
//
void SurfacePoly :: Translate( float tx, float ty, float tz )
//                            --------------
{

  
    int n,i;

  n = _tab_pts.NbElts();

  Pour(i,0,n-1)
    _tab_pts[i].pt.x += tx;
    _tab_pts[i].pt.y += ty;
    _tab_pts[i].pt.z += tz;
  FinPour

  //  GLRecomputeList(); 

} // Translate()



// ----------------------------------------------------------------------
// Displaces each point in the normal direction
// with a distance given by the image
//
void SurfacePoly :: DisplacePoints( InrImage* Idist )
//                            --------------
{

  
    int n,i;

  n = _tab_pts.NbElts();

  Si Idist->_tx != n Alors
    fprintf(stderr,"SurfacePoly::DisplacePoints() \t image size in X incorrect \n");
    return;
  FinSi

  Pour(i,0,n-1)
    _tab_pts[i].pt = _tab_pts[i].pt +
                     (float)(*Idist)(i,0,0)*_tab_pts[i].norm;
  FinPour

  //  GLRecomputeList(); 

} // DisplacePoints()


// ----------------------------------------------------------------------
GLuint SurfacePoly :: GenerateGLList()
//                              --------------
{
   GLuint list;
   list=NewGLSurface();

   glReportErrors();
   EndGLSurface();
   glReportErrors();
   return list;

} // GenerateGLList()


// ----------------------------------------------------------------------
void SurfacePoly :: SelectLine(int line)
//                            ----------
{

    int pos;

  // backup the current line configuration
  BackupLines();

    pos = _selected_lines.Position(line);
    Si pos != -1 Alors
     _selected_lines.Supprime(pos);
    Sinon
     _selected_lines += line;
    FinSi

} //  SelectLine()


// ----------------------------------------------------------------------
void SurfacePoly :: ConnectSelection()
//                            ----------------
{

  // backup the current line configuration
  BackupLines();

    Si _selected_lines.NbElts()==2 Alors
      ConnectLines(_selected_lines[0],_selected_lines[1]);
    Sinon
      fprintf(stderr,"ConnectSelection() \t must have 2 lines selected \n");
    FinSi

} //  ConnectSelection()


// ----------------------------------------------------------------------
void SurfacePoly :: RemoveSelection()
//                            ---------------
{

  int l;

  printf("remove selection starts..\n");

  // backup the current line configuration
  BackupLines();

  Pour(l,0,_selected_lines.NbElts()-1)
    _tab_lines[_selected_lines[l]].VideTableau();
//RemoveLine(_selected_lines[l]);
  FinPour
  _selected_lines.VideTableau();

  printf("remove selection done..\n");

} //  RemoveSelection()


//----------------------------------------------------------------------
//
void SurfacePoly :: RemoveNonSelected()
//
{

  
    TableauDyn<unsigned char>  selected;
    int l;

  // backup the current line configuration
  BackupLines();

  try {

  selected.Resize( _tab_lines.NbElts());
  Pour(l,0,_tab_lines.NbElts()-1)
    selected += 0;
  FinPour

  Pour(l,0,_selected_lines.NbElts()-1)
    selected[_selected_lines[l]] = 1;
  FinPour

  Pour(l,0,_tab_lines.NbElts()-1)
    Si Non(selected[l]) AlorsFait
      _tab_lines[l].VideTableau();
  //RemoveLine(l);
  FinPour
    
  }
  catch (OutOfArray) {
    fprintf(stderr,"SurfacePoly::RemoveNonSelected() Failed, exception OutOfArray \n");
  }

} // RemoveNonSeleted()


//----------------------------------------------------------------------
//
void SurfacePoly :: SaveSelectedLines( char* name)
//
{

#ifndef _WITHOUT_VTK_
    vtkPoints*         points;
    int                i,j,n;
    vtkCellArray*      lines;
    SurfPoly           poly;
    vtkPolyData*       vtk_lines;
    vtkPolyDataWriter* writer;
    vector<vtkIdType>        pts(1000);

    // Renumerotation pour ne sauver que les points utilises


  // Write the points
  // Should only save the points which belong to the selected lines
  points      = vtkPoints ::New();

  Pour(i,0,GetNumberOfPoints()-1)
     points->InsertPoint(i,
			 _tab_pts[i].pt.x,
			 _tab_pts[i].pt.y,
			 _tab_pts[i].pt.z);
  FinPour


  // Write the lines
  lines = vtkCellArray::New();

  lines->SetTraversalLocation(0); 
  Pour( i, 0, _selected_lines.NbElts()-1)
    n = _tab_lines[_selected_lines[i]].NbElts();
    Si n>0 Alors
      Pour(j,0,n-1)
        pts.push_back(_tab_lines[_selected_lines[i]][j]);
      FinPour
      lines->InsertNextCell(n, &pts.front());
    FinSi
  FinPour  //i


  vtk_lines = vtkPolyData::New();  
  vtk_lines->SetPoints(points);
  vtk_lines->SetLines(lines);

  points     ->Delete();
  lines      ->Delete();


  writer = vtkPolyDataWriter::New();

  writer->SetInput( vtk_lines);
  writer->SetFileTypeToBinary();
  //  writer->SetFileTypeToASCII();
  writer->SetFileName(name);
  writer->Write();

  writer   ->Delete();
  vtk_lines->Delete();

#else
  fprintf(stderr,"SurfacePoly::SaveSelectedLines()\t VTK not available ...\n");
#endif // _WITHOUT_VTK_

} // SaveSelectedLines()

// ----------------------------------------------------------------------
void SurfacePoly :: SelectLines( InrImage* lines_selection)
//                            ----------
{

  int l;
  int pos;
  BackupLines();

  for(l=0;l<lines_selection->DimX();l++) {
    if ((l<_tab_lines.NbElts())&&((*lines_selection)(l,0,0)>0.5)) {
      pos = _selected_lines.Position(l);
      Si pos != -1 Alors
	_selected_lines.Supprime(pos);
      Sinon
	_selected_lines += l;
      FinSi
    }
  }

} // SelectLines()



// ----------------------------------------------------------------------
void SurfacePoly :: SelectPoint(int pt)
//                            ----------
{

    int pos;

    pos = _selected_points.Position(pt);
    Si pos != -1 Alors
     _selected_points.Supprime(pos);
    Sinon
     _selected_points += pt;
    FinSi

} //  SelectPoint(int pt)


// ----------------------------------------------------------------------
void SurfacePoly::SelectMinPath(int pt)
//                -------------

{
  int last_point;
  int current_point,previous_point;
  int initial_line = -1;
  int selected_line = -1;
  int p;

  if ( _selected_points.NbElts() ==0 )
  {
    cerr << "SurfacePoly::SelectMinPath()\t no seletec point" << endl;
    return;
  }

  // Get the last selected point
  last_point = _selected_points[_selected_points.NbElts()-1];

  // Create the graph
  Edge_vec    edges(_tab_lines.NbElts());
  weight_vec  weights(_tab_lines.NbElts());

  // Iterate through the lines and create edges and weights
  for (p= 0; p< _tab_lines.NbElts(); p++ ) {
    T_Line& line = _tab_lines[p];

    if (line.NbElts()>=2) {

      edges.push_back(Edge(line[0],line[line.NbElts()-1]));
      cout << "Adding Edge " << line[0] << " " << line.NbElts()-1 << endl;

      double length=0;
      Point_3D<float> p0,p1;
      for(int i=1;i<line.NbElts();i++) {
        p0=GetPoint(line[i-1]).pt;
        p1=GetPoint(line[i]).pt;
        length += Norme(p0-p1);
        if (line[i-1]==pt)         selected_line = p;
        if (line[i-1]==last_point) initial_line  = p;
      }
      weights.push_back((weight_type)length);
    }
  }

  if (selected_line==-1) {
    cerr << "Selected line not found, aborting " << endl;
    return;
  } else
    cout << "selected line = " << selected_line << endl;
  if (initial_line==-1) {
    cerr << "Initial line not found, aborting " << endl;
    return;
  } else
    cout << "initial line = " << initial_line << endl;

  // Create the graph
  graph_ptr graph = CreateUndirectedGraph(
      _tab_pts.NbElts(),
      edges,
      weights);

  // run Dijkstra
  PathInfo path;
  ShortestPath(*graph,_tab_lines[initial_line][0],path);

  // Create back the path from the seleted line to the last point
  // and select it
  T_Line line = _tab_lines[selected_line];
  float d1 = path.distance[line[0]];
  float d2 = path.distance[line[line.NbElts()-1]];

  if (d1>d2) 
    current_point = line[0];
  else
    current_point = line[line.NbElts()-1];

  // find the line of the current point
  if (path.distance[current_point]==
      numeric_limits<weight_type>::max())
  {
    cerr << "SurfacePoly::SelectMinPath() \tNo path between points " << endl;
    return;
  }

  // backup the current line configuration
  BackupLines();

  cout << "Selecting the path " << endl;
  while (current_point!=_tab_lines[initial_line][0]) {
    previous_point = path.previous[current_point];

    // not too efficient but accept it for now
    // look for the line number with extremities current and previous points
    for (p= 0; p< _tab_lines.NbElts(); p++ ) {
      T_Line& line = _tab_lines[p];
      if  ((line[0]==previous_point)&&
         (line[line.NbElts()-1]==current_point))
        break;
      if  ((line[0]==current_point)&&
         (line[line.NbElts()-1]==previous_point))
        break;
    }
    if (p==_tab_lines.NbElts()) {
      cerr << "Not able to follow path: should not happen! " << endl;
      return;
    }
    int pos = _selected_lines.Position(p);
    Si pos == -1 Alors
     _selected_lines += p;
    FinSi

    current_point = previous_point;
  } // end while

} //  SelectMinPath(int pt)


// ----------------------------------------------------------------------
void SurfacePoly :: ConnectSelectedPoints()
//                            --------------------
{

    Si _selected_points.NbElts()==2 Alors
      NewLine();
      LineAddPointNumber(_selected_points[0]);
      LineAddPointNumber(_selected_points[1]);
      EndLine();
    Sinon
      // try closing a surface ...
      CloseSurface();
      fprintf(stderr,"ConnectSelection() \t must have 2 lines selected \n");
    FinSi

} //  ConnectSelectedPoints()


// ----------------------------------------------------------------------
void SurfacePoly :: RemovePoly( int poly, unsigned char update_neighbors)
//                            ----------
{

  _tab_poly.Supprime(poly);
  if (update_neighbors) 
    ComputeNeighbors();

} //  RemovePoly()


// ----------------------------------------------------------------------
void SurfacePoly :: RemovePoint( int pt)
//                            -----------
{


  ComputeNeighbors();
  while (_tab_pts[pt]._neighbors.NbElts()>0) {
    this->RemovePoly(_tab_pts[pt]._neighbors[0],1);
  }
  // also removes the point: I can't delete the point without updating all triangles ...
//  _tab_pts.Supprime(pt);
  _cc_calculees = 0;

} //  RemovePoint()


// ----------------------------------------------------------------------
void SurfacePoly :: RemoveSelectedPoints( )
//                            --------------------
{


/*
  for(p=0;p<= _selected_points.NbElts()-1;p++) {
    this->RemovePoint(_selected_points[p]);
  }
*/
  this->RemovePoint(_selected_points[_selected_points.NbElts()-1]);
  ClearSelectedPoints();

} //  RemoveSelectedPoints()


// ----------------------------------------------------------------------
// try to close an open surface from the last selected point
//
void SurfacePoly :: CloseSurface( )
//                            ------------
{

  // closing polygon
  TableauDyn<int> poly;

  // neighbor points
  TableauDyn<int> pts_neighbors;
  // nb of poly containing each neighbor point
  TableauDyn<int> pts_neighbors_count;

  int             n=0,p,pt,i,p1;
  unsigned char   closed=0;
  unsigned char   nextpointfound=1;

  PolyNeighbors n0; // indices of the neighbor polygons of the current point
  PolyNeighbors n1; // indices of the neighbor polygons of a neighbor point 

  int last_poly=0;  
  int pos1;
  int pos2;
  int inverse=0;

  ComputeNeighbors();

  // Check is the surface is opened at this point:
  // 1. list the neighbor points
  // 2. compute how many of the neighbor polygons each neighbor point P1 contains
  // 3. if P1 is only contained in 1, the surface is opened in the segment [p0,p1]
  // 4. look for P2, P3,  ... until Pn==P0
  // 5. create the polygon P1,P2,P3,...Pn


  poly += _selected_points[_selected_points.NbElts()-1];
  n=0;
  nextpointfound=1;

  while ((!closed)&&(nextpointfound)) {
    pts_neighbors.VideTableau();
    pts_neighbors_count.VideTableau();
    //
    // 1. list the neighbor points of the current point
    //
    // loop over the neighboring polygons
    for(p=0;p<_tab_pts[poly[n]]._neighbors.NbElts();p++) {
      // neighbor polygon indice
      p1 = _tab_pts[poly[n]]._neighbors[p];
      for(pt=0;pt<_tab_poly[p1].NbElts();pt++) {

	if ((_tab_poly[p1][pt] != poly[n]) // don't add the current point
	    &&
            ((n==0)||((n>0)&&(_tab_poly[p1][pt] != poly[n-1]))))
            // don't add the previous point if any
	  if (!pts_neighbors.Existe(_tab_poly[p1][pt])) {
	    pts_neighbors       += _tab_poly[p1][pt];
	    pts_neighbors_count += 0;
	  }
      }
    }
    //
    // 2. compute how many of the neighbor polygons each neighbor point P1 contains
    //

    nextpointfound=0;
    n0 = this->GetPolyNeighbors(poly[n]);

    for(i=0;i<pts_neighbors.NbElts();i++) {
      n1 = this->GetPolyNeighbors(pts_neighbors[i]);
      for(p1=0;p1<n1.NbElts();p1++) {
	if (n0.Existe(n1[p1])) {
	  pts_neighbors_count[i]++;
	  last_poly = p1;
	}
      }
      // if count==1, this is the next point ...
      if (pts_neighbors_count[i]==1) {

	// check for orientation in case of first point:
	if (n==0) {
	  pos1 = _tab_poly[n1[last_poly]].Position(poly[n]);
	  pos2 = _tab_poly[n1[last_poly]].Position(pts_neighbors[i]);
	  if (pos2==(pos1+1)%(_tab_poly[n1[last_poly]].NbElts())) 
	    inverse=1;
	  else
	  if (pos2==(pos1+_tab_poly[n1[last_poly]].NbElts()-1)%(_tab_poly[n1[last_poly]].NbElts())) 
	    inverse=0;
	  else {
	    fprintf(stderr,"points not neighbors ... inverse = 0 \n");
	    inverse = 0;
	  }
	}

	if (pts_neighbors[i]==poly[0]) 
	  closed = 1;
	else {
	  poly += pts_neighbors[i];
	  n++;
	  nextpointfound=1;
	}
	break;
      }
    }
    
  }

  // Create the new triangles ... : the orientation may be wrong ...

  for(n=2;n<poly.NbElts();n++) {
    NewPoly();
    if (!inverse) {
      PolyAddPointNumber(poly[0]);
      PolyAddPointNumber(poly[n-1]);
      PolyAddPointNumber(poly[n]);
    } else {
      PolyAddPointNumber(poly[n]);
      PolyAddPointNumber(poly[n-1]);
      PolyAddPointNumber(poly[0]);
    }
    EndPoly();
  }


} //  CloseSurface()


// ----------------------------------------------------------------------
void SurfacePoly :: SelectCC(   int cc)
//                            --------
{

    int pos;

  pos = _selected_cc.Position(cc);
  Si pos != -1 Alors
     _selected_cc.Supprime(pos);
  Sinon
     _selected_cc += cc;
  FinSi

} //  SelectCC()



// ----------------------------------------------------------------------
void SurfacePoly :: HideSelectedCC()
//                            --------------
{

  
    int n;

  Pour(n,0,_selected_cc.NbElts()-1)
    _draw_cc[_selected_cc[n]] = 0;
  FinPour
  _show_all_cc = false;

} //  HideSelectedCC()



// ----------------------------------------------------------------------
void SurfacePoly :: HideNonSelectedCC()
//                            -----------------
{

  
    int n;

  Pour(n,0,_draw_cc.NbElts()-1)
    _draw_cc[n] = 0;
  FinPour

  Pour(n,0,_selected_cc.NbElts()-1)
    _draw_cc[_selected_cc[n]] = 1;
  FinPour
  _show_all_cc = false;


} //  HideNonSelectedCC()

