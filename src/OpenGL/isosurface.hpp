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
 * $Revision: 1.3 $
 * $Log: isosurface.hpp,v $
 * Revision 1.3  2005/11/16 14:03:10  karl
 * added LGPL license
 *
 * Revision 1.2  2004/04/30 20:10:16  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.3  2000/11/08 16:23:23  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/10/02 16:57:20  karl
 * *** empty log message ***
 *
 * Revision 1.1  2000/09/19 12:19:15  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:09:34  karl
 * Sources code
 *
 *
 *
 ***************************************************************************/

#ifndef _ISOSURFACE_HPP
#define _ISOSURFACE_HPP

#include "style.hpp"

#include "TableauDyn.hpp"
#include "Coordonnees.hpp"
#include <stdio.h>
#include "inrimage.hpp"
#include "Voxel.hpp"
#include "DefineClass.hpp"

//#include "SceneGraph.h"

//#include "surface.hpp"

#define EPSILON_ISOSURFACE 1E-5

#define SEGMENT_NON_TESTE     0
#define SEGMENT_VIDE          1
#define SEGMENT_POINT_LIBRE   2
#define SEGMENT_POINT_OCCUPE  3


#define OUTPUT_TRIANGLES 0
#define OUTPUT_POLYGONS  1


//typedef  class TableauDyn<int> TPolygone;
#define TPolygone  TableauDyn<int>


//==================================================
class Segment
//
{

public:

  int nbre_faces;
  int point[2];
  int faces[2];
  int _etat;

  Constructeur Segment()
    {
      nbre_faces = 0;
      _etat = SEGMENT_NON_TESTE;
    }

  void InitPoints( int p0, int p1)
    {
      point[0] = p0;
      point[1] = p1;
    }

  void AddFace( int n)
    {
      Si nbre_faces < 2 Alors
    faces[nbre_faces] = n;
        nbre_faces++;
      FinSi
    }

  void SetState(int etat)
  {
    _etat = etat;
  }

}; // Segment


//==================================================
class Face
//
{

public:

  int nb_pts_inters;
  int segments[4];
  int points[4];
  int pts_trouves[4];

  Constructeur Face()
  {
    nb_pts_inters = 0;
  }

  void InitSegments( int s0, int s1, int s2, int s3)
  {
    segments[0] = s0;
    segments[1] = s1;
    segments[2] = s2;
    segments[3] = s3;
  }

  void InitPoints( int p0, int p1, int p2, int p3)
  {
    points[0] = p0;
    points[1] = p1;
    points[2] = p2;
    points[3] = p3;
  }

  void NouveauPoint( int p)
  {
    pts_trouves[nb_pts_inters] = p;
    nb_pts_inters++;
  }

}; // Face


//==================================================
class PointIntersection
//
{

public:

  int  _numpoint;
  unsigned char ATraiter;
  int     pts_voisins[2];
  int     nb_voisins;

  Constructeur PointIntersection() 
  {
    ATraiter   = true;
    nb_voisins = 0;
    _numpoint  = -1;
  }

  void AddVoisin(int pt)
  {

    Si nb_voisins < 2 Alors
      pts_voisins[nb_voisins] = pt;
      nb_voisins++;
    FinSi
  }

  void Init( int numpoint)
  {
    _numpoint = numpoint;
    nb_voisins = 0;
  }

  int VoisinDiffDe( int point)
  {

    Si nb_voisins == 2 Alors
      Si pts_voisins[0] == point Alors
        return pts_voisins[1];
      Sinon
        return pts_voisins[0];
      FinSi      
    FinSi

    cout << "VoisinDiffDe() \t nb_voisins != 2" << endl;

    return -1;
    
  }

}; // PointIntersection


//======================================================================
//
//======================================================================


class Intersection
//     ===========
{

public:

  int pt[3];

  Constructeur Intersection()
  {
    pt[0] =
    pt[1] =
    pt[2] = -1;
  }

  void FixeVal( int n, int pos_point)
  {
    pt[n] = pos_point;
  }

  int Val(int n) { return pt[n];}

};

typedef  Point_3D<float> pt3D;


//======================================================================
//  class ImagePoints
//======================================================================

class ImagePoints
//
{

  /// Pour  chaque voxels, 
  /// numeros des 3 points d'intersection
  /// ou pointeur NULL
  Intersection**** ptInters;

  // for each voxel, activation means that there is a intersection
  // of the isosurface with this voxel
  unsigned char*** activation;

  TableauDyn<pt3D> tab_points;

  int _tx;
  int _ty;
  int _tz;

  Voxel           _voxel;

public:

  Constructeur ImagePoints( int tx, int ty, int tz);

  Destructeur ImagePoints();

  int AddPoint( int x, int y, int z, Segment& seg, pt3D& pt);

  int AddPoint( int x, int y, int z, int seg, pt3D& pt);

  int Point( int x, int y, int z, Segment& seg);

  pt3D&  Point(int num) { return tab_points[num]; }

  int NbPoints() { return tab_points.NbElts();}

  void ActiveCube(int x,int y,int z)
  {
    Si (x>=0)Et(y>=0)Et(z>=0) AlorsFait
      activation[x][y][z] = 1;
  }

  unsigned char CubeActivated(int x,int y,int z)
  {
    return activation[x][y][z];
  }

}; // ImagePoints


//======================================================================
//  class IsoSurface
//======================================================================


class IsoSurface 
//
{

  DEFINE_CLASS(IsoSurface)

private:

  float         _seuil;

  int          _output_type;  

public:

  ImagePoints*         _image_points;
  InrImage::ptr         _image;
  TableauDyn<TPolygone> tabPoly;


  Constructeur IsoSurface(  InrImage::ptr image);
  //

  virtual ~IsoSurface();
  //

  void SetOutputType( int type) 
  {
    switch (type) {
    case OUTPUT_TRIANGLES:
    case OUTPUT_POLYGONS: 
      _output_type = type;
      break;
    default: 
      fprintf(stderr,"IsoSurface::SetOutputType() \t invalid type, set to triangles \n");
      _output_type = OUTPUT_TRIANGLES;
    }
  }

  int GetOutputType() { return _output_type; }
  // 

  void CalculSurface( float seuil, InrImage* masque=NULL);
  //
  // Masque is an image that allows 
  // to select the points included in the surface calculation
  // the points with (*masque)(x,y,z) >= 127 are selected
  // for the calculation

  //--------------------------------------------------
  void CalculNormale( pt3D& pt, Vect3D<float>& norm);


  //--------------------------------------------------
  void WriteFile( char* nom);

  //--------------------------------------------------
  void WriteVRML( char* nom);

  //--------------------------------------------------
//  void WriteSurfPoly( SurfacePoly* surf_poly);


}; // IsoSurface



//======================================================================
//  class Cube
//======================================================================


//==================================================
class Cube
//
{

  float*           _valeurs;

  PointIntersection  tabInters[12];

  Voxel           _voxel;
  Segment         tabSeg[12];
  Face            tabFace[6];
  int             nb_inters_a_traiter;
  int             _x,_y,_z;

  TPolygone        _poly;
  IsoSurface*     _isosurface;

public:  

  //--------------------------------------------------
  Constructeur Cube( );


  //--------------------------------------------------
  void InitVoxel( int x, int y, int z, float* valeurs);
  

  //--------------------------------------------------
  int CalculIntersection(int seg);

  //--------------------------------------------------
  void ResoudAmbiguite(int face)
  {

     
      float   a,b,c,d,S,f;

//    cout << "ResoudAmbiguite()" << endl;


// segment 0 = [a,b]
// segment 1 = [b,d]
// segment 2 = [d,c]
// segment 3 = [c,a]

  a = _valeurs[tabFace[face].points[0]];
  b = _valeurs[tabFace[face].points[1]];
  c = _valeurs[tabFace[face].points[3]];
  d = _valeurs[tabFace[face].points[2]];

// f(x,y) = a + (b-a)x + (c-a)y + (d-c-b-a)xy
// df/dx  = (b-a) + (d+a-c-b)y
// df/dy  = (c-a) + (d+a-c-b)x
//
// on note S = c+b-(d+a)
//   x0 = (c-a)/S
//   y0 = (b-a)/S
//
// f(x0,y0) = a + y0 S x0 + x0 S y0 - S x0 y0
//          = a + x0 y0 S
//          = a + (c-a)(b-a)/(c+b-d-a)

  S = c+b-d-a;

  Si fabs((double)S)<1E-10 Alors
    fprintf(stderr,"Cube::ResoudAmbiguite() \t fabsf(S) < 1E-10 \n");
  Sinon
    f = a + (c-a)*(b-a)/S;

    // If a and f have the same sign, connect a to d
    Si ((a>0)Et(f>0)) Ou ((a<0)Et(f<0)) Alors
      ConnectePoints( tabFace[face].segments[0], tabFace[face].segments[1]);
      ConnectePoints( tabFace[face].segments[2], tabFace[face].segments[3]);
    Sinon
      ConnectePoints( tabFace[face].segments[0], tabFace[face].segments[3]);
      ConnectePoints( tabFace[face].segments[1], tabFace[face].segments[2]);
    FinSi
  FinSi


  } // ResoudAmbiguite()


  //--------------------------------------------------
  void ConnectePoints(int p0, int p1)
  {

    Point_3D<float> pt1, pt2;
    Vect3D<float> diff;
    //float         dist;
 
    tabInters[p0].AddVoisin(p1);
    tabInters[p1].AddVoisin(p0);

    // Test on the distance between the 2 points
/*
    pt1 = _isosurface->_image_points->Point(tabInters[p0]._numpoint);
    pt2 = _isosurface->_image_points->Point(tabInters[p1]._numpoint);

    diff = pt1 - pt2;
    dist = diff*diff;

    Si dist< 1E-4 Alors
      fprintf(stderr, "small distance %d %d \n",tabInters[p0]._numpoint,
          tabInters[p1]._numpoint);
    FinSi
*/

  } // ConnectePoints()


  //--------------------------------------------------
  void InitSegFace(int face, int seg0, int seg1, int seg2, int seg3)
  {
    tabFace[face].InitSegments(seg0, seg1, seg2, seg3);
    tabSeg[seg0].AddFace(face);
    tabSeg[seg1].AddFace(face);
    tabSeg[seg2].AddFace(face);
    tabSeg[seg3].AddFace(face);
  } // InitSegFace()


  //--------------------------------------------------
  void CreePolygones(  IsoSurface* isosurface);

  //--------------------------------------------------
  void CreateTriangles(  IsoSurface* isosurface);

  //--------------------------------------------------
  void NewPoly( )  
  {
     _poly.VideTableau(); 
  }

  //--------------------------------------------------
  void PolyAddPoint(  int point)
  {
    _poly += tabInters[point]._numpoint;
    tabSeg[point]._etat =  SEGMENT_POINT_OCCUPE;
    nb_inters_a_traiter--;
  }


}; // Cube





#endif // _ISOSURFACE_HPP
