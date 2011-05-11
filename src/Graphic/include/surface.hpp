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
 * $Revision: 1.8 $
 * $Log: surface.hpp,v $
 * Revision 1.8  2006/02/21 18:26:18  karl
 * many changes
 *
 * Revision 1.7  2006/01/09 17:59:04  karl
 * current version
 *
 * Revision 1.6  2005/11/16 14:03:10  karl
 * added LGPL license
 *
 * Revision 1.5  2005/03/31 20:06:55  karl
 * allowing pruning of centerlines
 *
 * Revision 1.4  2004/08/12 23:54:20  karl
 * interactivity for surfaces
 *
 * Revision 1.3  2004/06/24 04:46:19  karl
 * warnings and trying to unify texture and object matrices
 *
 * Revision 1.2  2004/04/06 19:04:24  karl
 * 2 functions added: Surface.Statistics(Image) and Surface.GetIntensities(Image)
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.7  2000/11/08 16:54:51  karl
 * *** empty log message ***
 *
 * Revision 1.5  2000/10/30 13:09:36  karl
 * *** empty log message ***
 *
 * Revision 1.4  2000/10/30 12:59:12  karl
 *
 * Vue surfacique d'une image
 *
 * Revision 1.2  2000/10/06 22:52:07  karl
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
 *  18/09/2000       calcul des composantes connexes
 *
 ***************************************************************************/

#ifndef _SURFACE_HPP
#define _SURFACE_HPP

/*
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
*/
class ami_wxGLCanvas;

//#ifndef _WITHOUT_VTK_
//#include <vtkPolyData.h>
//#endif // _WITHOUT_VTK_

class vtkPolyData;

//#include "ami_wxGLCanvas.hpp"

#include "style.hpp"
#include "chaine.hpp"
#include "Coordonnees.hpp"
#include "TableauDyn.hpp"

/*
#include <GL/gl.h>
#include <GL/glx.h>      
*/

#include "math1.hpp"
#include "GLparam.hpp"
#include "inrimage.hpp"

#ifdef _use_vrml97_
#include "SceneGraph.h"
#endif
#include "DefineClass.hpp"

#define OBJTYPE_UNKNOWN   -1
#define OBJTYPE_SURFPOLY   0
#define OBJTYPE_SURFPARAM  1
#define OBJTYPE_USERLIST   2



typedef  class TableauDyn<int> SurfPoly;
typedef  class TableauDyn<int> T_Line;
typedef  class TableauDyn<int> PolyNeighbors;

// Composante connexe: liste de points
typedef class TableauDyn<int> CompCon;

/// tableau de composantes connexes
/// Declaree a part car utile pour la fonction de comparaison
/// du tri 'qsort()'.


// Pb ... BUG ???
// A mettre dans la classe ...
static  TableauDyn<CompCon>   static_tab_cc;

#include <boost/shared_ptr.hpp>


class ami_wxGLCanvas;

namespace amilab {

//=========================================================
//
class GLObject 
{

  DEFINE_CLASS(GLObject);

protected:

  GLuint                  _bounding_box;
  int                     _obj_type;
  GLuint                  _GL_list;

  GLMaterialParam         _material;

  // Temporal solution
  unsigned char           _ownmaterial;
  bool                    _enable_light;

//  Display*                ;
//  GLXDrawable             _drawable;
//  GLXContext              _context;

  boost::weak_ptr<ami_wxGLCanvas>      _wxGL_canvas;

public:

  unsigned char        _display;
  int                  _line_width;
  int                  _point_size;

  unsigned char            _display_bb;
  float                    _xmin, _xmax;
  float                    _ymin, _ymax;
  float                    _zmin, _zmax;

  float                    _center_x, _center_y, _center_z;

  GLObject()
  {

    _line_width    = 1;
    _point_size    = 1;

    _xmin = _ymin = _zmin = -1;
    _xmax = _ymax = _zmax =  1;

    _center_x = _center_y = _center_z = 0;

    _bounding_box = 0;
    _display_bb   = false;
    _display = true;

    _obj_type = OBJTYPE_UNKNOWN;
    _GL_list  = 0;

    _ownmaterial   = true;
    _enable_light  = true;

//    _wxGL_canvas   = NULL;
//    _glx_display   = NULL;
//    _context       = NULL;
  }

  virtual ~GLObject()
  {

    if (_GL_list != 0) {
      glDeleteLists(_GL_list, 1);
      _GL_list = 0;
    }

    if  (_bounding_box != 0) {
      glDeleteLists(_bounding_box, 1);
      _bounding_box = 0;
    }
  }

  void SetwxGLCanvas( boost::shared_ptr<ami_wxGLCanvas> wxglc );

  int  MakeContextCurrent();

  virtual void DeleteGLLists() 
  {

    if (!MakeContextCurrent()) return;

    Si _GL_list != 0 Alors
      glDeleteLists(_GL_list, 1);
      _GL_list = 0;
    FinSi

    Si _bounding_box != 0 Alors
      glDeleteLists(_bounding_box, 1);
      _bounding_box = 0;
    FinSi
  }

  virtual void GLRecomputeList(  ) {

    if (!MakeContextCurrent()) return;
    Si _GL_list != 0 AlorsFait glDeleteLists( _GL_list, 1);
    _GL_list=glGenLists(1);
  }

  int GetLineWidth()      { return _line_width; }
  void SetLineWidth(int w) { _line_width = w; }

  void SetOwnMaterial( unsigned char val)   {    _ownmaterial  = val;    }
  bool GetEnableLight()           { return _enable_light;  } 
  void SetEnableLight( bool val)  { _enable_light=val;     } 
  void EnableLight()              { _enable_light = true;   }
  void DisableLight()             { _enable_light = false;  }
  void SetColorMaterial( unsigned char val) {    _material._colormaterial = val; }

  GLMaterialParam& GetMaterial() { return _material; }
  void SetMaterial( const GLMaterialParam& mat) 
      { _material = mat; }

  float GetOpacity() { return _material._opacity; }
  unsigned char Transparent() { return _material._opacity<0.99; }

  int ObjType() { return _obj_type; }

  unsigned char Visible() { return _display; }
  void    SetVisible(int visible) { this->_display=visible; }

  void DisplayObject(GLMaterialParam* mat);

  void DisplayBB();
  
  virtual GLuint GenerateGLList() { return 0;}

  //--------------------------------------------------
  virtual unsigned char ReadVRML( const char* nom) { return 0; }

  //--------------------------------------------------
  virtual unsigned char Read( const char* nom) { return 0; }

  //--------------------------------------------------
  virtual void WriteVRML( const char* nom, 
              GLTransfMatrix* transf    = NULL,
              GLMaterialParam* material = NULL,
              GLLightParam* light       = NULL,
              GLParam* param            = NULL) {}

};


//============================================================
//
class GLListObject : public GLObject
//
//
{

  DEFINE_CLASS(GLListObject);

public:

   GLListObject() { _obj_type = OBJTYPE_USERLIST; }

  ~GLListObject() {}

  void SetXMin( float xmin) { _xmin = xmin; }
  void SetXMax( float xmax) { _xmax = xmax; }

  void SetYMin( float ymin) { _ymin = ymin; }
  void SetYMax( float ymax) { _ymax = ymax; }

  void SetZMin( float zmin) { _zmin = zmin; }
  void SetZMax( float zmax) { _zmax = zmax; }

  void SetGLList( GLuint list) { _GL_list = list; }

  GLuint GenerateGLList() { return _GL_list;}

}; // GLListObject


//======================================================================
//

struct point3Dreel
//        ===========
{

  float x;
  float y; 
  float z;

};

//======================================================================
//

class Surface
//     =======
{


public:

  int _dim_u;
  int _dim_v;

  float _moy_x;
  float _moy_y;
  float _moy_z;

  float _et_x;
  float _et_y;
  float _et_z;

  point3Dreel** pt;
  
  int _umin, _umax;
  int _vmin, _vmax;


  InrImage* _image;
  unsigned char   _image_allouee;
  int    _posZ;
  float      _Imin, _Imax;


  InrImage* _image_couleurs;
  unsigned char   _image_couleurs_allouee;

   Surface()
  //           -------
  {

    _dim_u = _dim_v = 0;
    _umin = 0; _umax = 0;
    _vmin = 0; _vmax = 0;

    _moy_x = _moy_y = _moy_z = 0;
    _et_x  = _et_y  = _et_z  = 0;

    _image = NULL;
    _image_allouee = false;

    _image_couleurs         = NULL;
    _image_couleurs_allouee = false;

  }

  ~Surface();

  void Alloue( int dimu, int dimv);

  void Desalloue();

  point3Dreel& operator()( int u, int v);
  
  void LitDonnees( Chaine nom_fic);

  void LitImage( Chaine nom_image);

  void LitImage( InrImage* image, int posZ, float zscale,
         float min, float max);

  unsigned char LitImageCouleurs( Chaine nom_image);

  int RColor(int u, int v);
  int GColor(int u, int v);
  int BColor(int u, int v);

}; // Surface



//
class Point3DPoly
//
{

public:


  int             num_cc;   // numero de la composante connexe

  Point_3D<float>  pt;       // le point
  Vect3D<float>    norm;     // vecteur normal a la surface
  int          num_norm; // nombre de vecteurs moyennes pour calculer norm
  unsigned char   red;
  unsigned char   green;
  unsigned char   blue;
  unsigned char         norm_fixed;
  float            alpha;

  PolyNeighbors _neighbors; // list of polygons which contain this point
  
  
   Point3DPoly()
  //
  {

    num_cc = -1;

    pt.Init(0.0, 0.0, 0.0);
    norm.Init(0.0, 0.0, 0.0); // set a non-null norm to try ??
    num_norm = 0;
    red = green = blue = 0;
    norm_fixed = false;

    alpha = 1.0;

  }


   Point3DPoly(float x, float y, float z)
  //
  {

    num_cc = -1;

    pt.Init(x,y,z);
    norm.Init(0.0, 0.0, 0.0);
    num_norm = 0;
    red = green = blue = 0;
    norm_fixed = false;

    alpha = 1.0;
  }

  float X() { return pt.x; }
  float Y() { return pt.y; }
  float Z() { return pt.z; }

  int GetCC() { return num_cc; }

  void AddNormal( Vect3D<float> n)
  //
  {
    Si norm_fixed AlorsFait return;
    norm = norm + n;
    num_norm++;
  }


  void SetNormal( float x, float y, float z)
  //
  {
    norm_fixed = true;
    norm.Init( x,y,z);
  }


  void SetColor( unsigned char r, unsigned char g, unsigned char b)
  //
  {

    red   = r;
    green = g;
    blue  = b;

  }


  void GetColor( unsigned char& r, unsigned char& g, unsigned char& b)
  //
  {

    r = red   ;
    g = green ;
    b = blue  ;

  }


  void SetAlpha( float a)
  //
  {

    alpha = a;

  }

  void AddGLPolygon();
  //



  void AddGLPolygon( float r, float g, float b);
  //


  void AddGLLine()
  //
  {

    glColor3ub( red,
            green,
            blue);

    glVertex3f(pt.x,   pt.y,   pt.z  );

  }


  void AddGLLine(float r, float g, float b)
  //
  {

    glColor3ub( (GLubyte) (r*255),(GLubyte) (g*255),(GLubyte) (b*255));
    glVertex3f(pt.x,   pt.y,   pt.z  );

  }


  void AddGLPoint()
  //
  {

    glColor3ub( red,
           green,
           blue);
    glVertex3f(pt.x,   pt.y,   pt.z  );

  }

  void AddGLPoint(float r, float g, float b)
  //
  {

    glColor3ub(  (GLubyte) (r*255),
         (GLubyte) (g*255),
         (GLubyte) (b*255));
    glVertex3f(pt.x,   pt.y,   pt.z  );

  }


}; // Point3DPoly




//============================================================
//
class SurfacePoly : public GLObject
//
//
{

  DEFINE_CLASS(SurfacePoly);

private:
  TableauDyn<Point3DPoly> _tab_pts;

  SurfPoly                _poly;
  TableauDyn<SurfPoly>    _tab_poly;

  T_Line                  _line;
  TableauDyn<T_Line>      _tab_lines;
  TableauDyn<T_Line>      _tab_lines_backup;



  GLuint                  _vectors1;
  GLuint                  _vectors2;
  GLuint                  _normals;

  // tableau des positions des composantes connexes non vides,
  // trie par ordre decroissant du nombre de points
  TableauDyn<CompCon>        _tab_cc;
  int*                       _sort_tab_cc;
  TableauDyn<unsigned char>  _draw_cc;

  // nombre de composantes connexes non vides
  int   _nb_cc;

  // the number of the connex component that is displayed
  // if show_cc == -1, all the cc are displayed
  unsigned char   _show_all_cc;

  int _picked_line;
  TableauDyn<int>  _selected_lines;
  TableauDyn<int>  _selected_lines_backup;

  int _picked_point;
  TableauDyn<int>  _selected_points;

  int _picked_cc;
  TableauDyn<int>  _selected_cc;

public:

  unsigned char                 _cc_calculees; // dit si le calcul des composantes
                                        // connexes a ete realise


   SurfacePoly();

#ifndef _WITHOUT_VTK_
   SurfacePoly( vtkPolyData* vtkpoly);
#endif // _WITHOUT_VTK_

  ~SurfacePoly();

  CompCon& GetCC( int n) { return _tab_cc[n]; }

  void DeleteGLLists() 
  {

    if (!MakeContextCurrent()) return;
    GLObject::DeleteGLLists();

    Si _vectors1 != 0 Alors
      glDeleteLists(_vectors1, 1);
      _vectors1 = 0;
    FinSi

    Si _vectors2 != 0 Alors
      glDeleteLists(_vectors2, 1);
      _vectors2 = 0;
    FinSi

    Si _normals != 0 Alors
      glDeleteLists(_normals, 1);
      _normals = 0;
    FinSi

  }

#ifndef _WITHOUT_VTK_
  void AddVTKPoly( vtkPolyData* vtkpoly);
#endif // _WITHOUT_VTK_

  void   NewSurface();

  void Scale( float sx, float sy, float sz, unsigned char recompute=1);

  void AddPoint( float x, float y, float z);
  void AddPoint( Point_3D<float> pt);
  void SetNorm ( float x, float y, float z);
  void SetColor( float r, float g, float b, float alpha=1.0);
  void SetColor( unsigned char r, unsigned char g, unsigned char b, float alpha=1.0);
  void SetOpacity( float alpha);

  int NbPoints() { return _tab_pts.NbElts(); }

  Point3DPoly& operator[]( int i);

#ifndef _WITHOUT_VTK_
  // cast to vtkPolyData
  operator vtkPolyData* (void) const;
#endif // _WITHOUT_VTK_

  void NewPoly();
  void PolyAddPointNumber(int num);
  void EndPoly();

  /**
   * Adds a new line to the polydata.
   */
  void NewLine();
  void LineAddPointNumber(int num);
  void EndLine();

  GLuint NewGLSurface();
  void EndGLSurface();

  void UpdateLimits();

  int GetNumberOfPoints() const { return  _tab_pts.NbElts(); }
  Point3DPoly& GetPoint(int i)      { return _tab_pts[i]; }


  int GetNumberOfPolys()  const { return  _tab_poly.NbElts(); }
  SurfPoly& GetPoly(int i)      { return _tab_poly[i]; }

  int GetNumberOfLines()  const { return  _tab_lines.NbElts(); }
  T_Line& GetLine(int i)        { return _tab_lines[i]; }

  // Compute the list of polygons that contain each point and store it in the point structure
  void ComputeNeighbors();
   
  PolyNeighbors& GetPolyNeighbors( int point_indice) { return _tab_pts[point_indice]._neighbors; }

  // Triangulates the surface
  void Triangulate();
  //

  // Remove a line
  void RemoveLine(  int line);
  //   ----------

  // Connect 2 lines
  void ConnectLines(  int line1, int line2);
  //   ------------

  // backup the current line configuration
  void BackupLines();

  // Undo last operation
  void UndoLast();

  /**
   * Merges the points which distance is smaller than dist
   * @param dist 
   */
  void MergePoints(  float dist);
  //   -----------

  // Curvatures
  // Compute principal curvature and associated directions
  // for each point of the surface
  void ComputeCurvatures(InrImage* Icmin, InrImage* Icmax, 
  //   -----------------
             InrImage* Idmin, InrImage* Idmax,
             int depth);

  // return an 1D image of the length of each line
  InrImage* GetImageLinesLength( );
  //        --------------

  // return an 1D image of the number of connection of each point
  InrImage* GetImageConnections( );
  //        --------------

  // return an 1D image point indexes of the line number l
  InrImage* GetImageLinesExtremities( );
  //        ------------------------

  //
  InrImage* GetIntensities( InrImage* image);

  // Recompute the normals
  void RecomputeNormals();
  //   ----------------

  // Invert the normals
  void InvertNormals();
  //   -------------

  // Translate all the points
  void Translate( float tx, float ty, float tz );
  //   ---------


  /**
   * Displaces each point in the normal direction
   * with a distance given by the image
   * @param Idist 
   */
  void DisplacePoints( InrImage* Idist );
  //   --------------

  GLuint GenerateGLList();

  //
  // Functions for line selection
  //
  void SetPickedLine(int line) { _picked_line = line;  }
  void PrintPickedLine() {
    int i;
    T_Line l = GetLine(_picked_line);
    for (i=0;i<l.NbElts();i++) {
      int p = l[i];
      printf(" point (%d,%d), ( %3.3f, %3.3f %3.3f ) \n",
            i,p,
            _tab_pts[p].X(),_tab_pts[p].Y(),_tab_pts[p].Z());
    }
  }

  void SelectLine(int line);
  void ClearSelectedLines()    { _selected_lines.VideTableau();  }
  void ConnectSelection();
  void RemoveSelection();
  // Remove the non-selected lines
  void RemoveNonSelected();
  // Save the selected lines in a vtk format file
  void SaveSelectedLines( char* name);

  // values higher than one will be selected
  void SelectLines( InrImage* lines_selection);

  //
  // Functions for point selection
  //
  void SetPickedPoint(int pt)  {  _picked_point = pt;  }
  void SelectPoint(   int pt);
  void SelectMinPath(   int pt);
  void ClearSelectedPoints()  {  _selected_points.VideTableau();  }
  void ConnectSelectedPoints();
  void RemovePoly(           int poly, unsigned char update_neighbors=0);
  void RemovePoint(          int pt);
  void RemoveSelectedPoints( );
//  void CreatePolyFromSelectedPoints( );

  // try to close an open surface from the last selected point
  void CloseSurface( );

  //
  // Functions for Connected Components selection
  //
  void SetPickedCC(int cc)  {  _picked_cc = cc;  }
  void ClearSelectedCC()  {  _selected_cc.VideTableau();  }
  void SelectCC(   int CC);
  void HideSelectedCC();
  void HideNonSelectedCC();


  /**
   * Statistics of the input image at the position of the vertices.
   * @param image 
   */
  void Statistics( InrImage* image);

  /**
   * Sets the colors of the surface based on the colors of a 3D image, looking at the color in the image at the position of each vertex.
   * @param image 3D input RGB or greyscale image
   * @param min for greyscale image: minimal value (black)
   * @param max for greyscale image: maximal value (white)
   * @param alpha opacity value for all vertices.
   * @return 
   */
  GLuint SetColors( InrImage* image, float min=0, float max=255, float alpha=1.0);
  
  GLuint SetColorOpacity( float alpha);
  /**
   * Sets the colors of the surface based on the colors of a 1D image of length the number of vertices of the polydata.
   * @param image 3D input RGB or greyscale image
   * @param min for greyscale image: minimal value (black)
   * @param max for greyscale image: maximal value (white)
   * @return 
   */
  GLuint SetPointsColors( InrImage* image, float min=0, float max=255);

  // Choose if drawing a particular connex component
  void GLSurfaceSetDrawCC(  GLuint& surf, int cc, unsigned char draw);

  /**
   * Choose to draw only the specified connex component
   * @param surf 
   * @param cc if -1 draws all connected components, otherwise only draws the one selected.
   */
  void GLSurfaceDrawOnlyCC( GLuint& surf, int cc);

  // Choose to draw the connext component with more than n points
  void GLSurfaceMinThCC( GLuint& surf, int min_points);

  void GLRecomputeList(  );

  void DisplayNormals();

  void NewVectors1();
  void NewVectors2();

  void DisplayVectors1( GLParam* param);
  void DisplayVectors2( GLParam* param);

  // Calcul des composantes connexes de la surface
  void CalculCC();

  void RelieCC( int pt1, int pt2 );

  static int CompareCC( const void*, const void*);

  //--------------------------------------------------
  unsigned char ReadVRML( const char* nom);

  //--------------------------------------------------
  unsigned char ReadVTK( const char* nom);

  //--------------------------------------------------
  unsigned char Read( const char* nom);

  //--------------------------------------------------
  void WriteVRML( const char* nom, 
          GLTransfMatrix* transf    = NULL,
          GLMaterialParam* material = NULL,
          GLLightParam* light       = NULL,
          GLParam* param            = NULL);
  
  //--------------------------------------------------
  void WriteVTK( const char* nom);

  //--------------------------------------------------
  void Write( const char* nom);


}; // SurfacePoly

}

#endif // _SURFACE_HPP

