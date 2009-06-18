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
 * $Revision: 1.2 $
 * $Log: isosurface.cpp,v $
 * Revision 1.2  2005/11/16 14:03:10  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.4  2000/11/08 16:23:23  karl
 * *** empty log message ***
 *
 * Revision 1.3  2000/10/30 13:12:21  karl
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

#if defined(WIN32)
  #include <windows.h>
#endif

#include "isosurface.hpp"
#include "Timing.hpp"


//--------------------------------------------------
ImagePoints ::  Constructeur ImagePoints( int tx, int ty, int tz)
//
{

  
    int x,y,z;

  _tx = tx;
  _ty = ty;
  _tz = tz;

  ptInters = new Intersection***[_tx];

  Pour(x,0,_tx-1)
    ptInters[x] = new Intersection**[_ty];
    Pour(y,0,_ty-1)
      ptInters[x][y] = new Intersection*[_tz];
      Pour(z,0,_tz-1)
        ptInters[x][y][z] = (Intersection*) NULL;
      FinPour
    FinPour
  FinPour

  activation = new unsigned char**[_tx];

  Pour(x,0,_tx-1)
    activation[x] = new unsigned char*[_ty];
    Pour(y,0,_ty-1)
      activation[x][y] = new unsigned char[_tz];
      Pour(z,0,_tz-1)
        activation[x][y][z] = 0;
      FinPour
    FinPour
  FinPour

} // Constructeur


//--------------------------------------------------
ImagePoints ::  Destructeur ImagePoints( )
//
{

  
    int x,y,z;

  Pour(x,0,_tx-1)
    Pour(y,0,_ty-1)
      Pour(z,0,_tz-1)
        Si ptInters[x][y][z]!= NULL Alors
          delete ptInters[x][y][z];
        FinSi
      FinPour
      delete [] ptInters[x][y];
    FinPour
    delete [] ptInters[x];
  FinPour
  delete [] ptInters;
     
  Pour(x,0,_tx-1)
    Pour(y,0,_ty-1)
      delete [] activation[x][y];
    FinPour
    delete [] activation[x];
  FinPour
  delete [] activation;
 

} // Destructeur


//--------------------------------------------------
EnLigne
int ImagePoints :: AddPoint( int x, int y, int z, 
                      Segment& seg, pt3D& pt )
//
{

  
    int px,py,pz;
    int n;

  px = x + _voxel.PosX(seg.point[0]);
  py = y + _voxel.PosY(seg.point[0]);
  pz = z + _voxel.PosZ(seg.point[0]);

  tab_points += pt;
  n = tab_points.NbElts()-1;

  Si ptInters[px][py][pz] == NULL Alors
    ptInters[px][py][pz] = new Intersection();
  FinSi

  SelonQue seg.point[1]-seg.point[0] Vaut
  
    Valeur 1: ptInters[px][py][pz]->FixeVal(0,n);  FinValeur
    Valeur 2: ptInters[px][py][pz]->FixeVal(1,n);  FinValeur
    Valeur 4: ptInters[px][py][pz]->FixeVal(2,n);  FinValeur

  FinSelonQue

  return n;

} // AddPoint()


//--------------------------------------------------
int ImagePoints :: AddPoint( int x, int y, int z, 
                      int seg, pt3D& pt )
//
{

  
    int n;


  tab_points += pt;
  n = tab_points.NbElts()-1;

  Si ptInters[x][y][z] == NULL Alors
    ptInters[x][y][z] = new Intersection();
  FinSi

  ptInters[x][y][z]->FixeVal(seg,n);

  return n;

} // AddPoint()


//--------------------------------------------------
int ImagePoints :: Point( int x, int y, int z, 
                       Segment& seg )
//
{

  
    int px,py,pz;

  px = x + _voxel.PosX(seg.point[0]);
  py = y + _voxel.PosY(seg.point[0]);
  pz = z + _voxel.PosZ(seg.point[0]);


  Si ptInters[px][py][pz] == NULL Alors
    return -1;
  FinSi

  SelonQue seg.point[1]-seg.point[0] Vaut
  
    Valeur 1: return ptInters[px][py][pz]->Val(0);
    Valeur 2: return ptInters[px][py][pz]->Val(1);
    Valeur 4: return ptInters[px][py][pz]->Val(2);

  FinSelonQue

  return -1;

}  // Point( x,y,z, seg)

//======================================================================
//  CUBE: MEMBRES PUBLICS
//======================================================================


//--------------------------------------------------
Cube :: Constructeur Cube( )
//
{
 
    tabSeg[ 0].InitPoints( 0, 1);
    tabSeg[ 1].InitPoints( 0, 2);
    tabSeg[ 2].InitPoints( 0, 4);
    tabSeg[ 3].InitPoints( 1, 3);
    tabSeg[ 4].InitPoints( 1, 5);
    tabSeg[ 5].InitPoints( 2, 3);
    tabSeg[ 6].InitPoints( 2, 6);
    tabSeg[ 7].InitPoints( 3, 7);
    tabSeg[ 8].InitPoints( 4, 5);
    tabSeg[ 9].InitPoints( 4, 6);
    tabSeg[10].InitPoints( 5, 7);
    tabSeg[11].InitPoints( 6, 7);

    tabFace[0].InitPoints(0,1,3,2);
    tabFace[1].InitPoints(0,1,5,4);
    tabFace[2].InitPoints(0,2,6,4);
    tabFace[3].InitPoints(4,5,7,6);
    tabFace[4].InitPoints(2,3,7,6);
    tabFace[5].InitPoints(1,3,7,5);

    InitSegFace( 0, 0, 3,  5, 1);
    InitSegFace( 1, 0, 4,  8, 2);
    InitSegFace( 2, 1, 6,  9, 2);
    InitSegFace( 3, 8, 10,11, 9);
    InitSegFace( 4, 5, 7, 11, 6);
    InitSegFace( 5, 3, 7, 10, 4);

} // Constructeur Cube()


//--------------------------------------------------
void Cube :: Constructeur InitVoxel( int x, int y, int z, 
                           float* valeurs)
//
{
 
  
    int s,f;

  _valeurs = valeurs;
  _x = x;
  _y = y;
  _z = z;

  nb_inters_a_traiter = 0;

  Pour(s,0,11) 
    tabSeg[s].SetState( SEGMENT_NON_TESTE);
  FinPour

  Pour(f,0,5)
    tabFace[f].nb_pts_inters = 0;
  FinPour

} // InitVoxel()


//--------------------------------------------------
int Cube :: CalculIntersection(int seg)
//
{

  
    int       p0,p1;
    float         v0,v1;


  p0 = tabSeg[seg].point[0];
  p1 = tabSeg[seg].point[1];

  v0 = _valeurs[p0];
  v1 = _valeurs[p1];

  Si (v0> EPSILON_ISOSURFACE Et v1> EPSILON_ISOSURFACE) Ou
     (v0<-EPSILON_ISOSURFACE Et v1<-EPSILON_ISOSURFACE) 
  Alors
    tabSeg[seg].SetState(SEGMENT_VIDE);
    return tabSeg[seg]._etat;
  FinSi

  Si (v0<-EPSILON_ISOSURFACE Et v1> EPSILON_ISOSURFACE) Ou
     (v0> EPSILON_ISOSURFACE Et v1<-EPSILON_ISOSURFACE)
  Alors

    
      float           c0,c1;
      pt3D           pt0,pt1,pt;
      int         numpoint;

    numpoint =  _isosurface->_image_points->Point( _x, _y, _z, tabSeg[seg]);
    Si numpoint == -1 Alors

      pt0.Init( _x + _voxel.PosX(p0),
        _y + _voxel.PosY(p0),
        _z + _voxel.PosZ(p0));

      pt1.Init( _x + _voxel.PosX(p1),
        _y + _voxel.PosY(p1),
        _z + _voxel.PosZ(p1));

      c0 = v1 / (v1-v0);
      c1 = 1-c0;

      pt.Init( pt0.x*c0+pt1.x*c1,
           pt0.y*c0+pt1.y*c1,
           pt0.z*c0+pt1.z*c1);

      numpoint = _isosurface->_image_points->AddPoint( _x, _y, _z, 
                               tabSeg[seg], pt);

    FinSi


    tabInters[seg].Init( numpoint);
    nb_inters_a_traiter++;

    tabFace[tabSeg[seg].faces[0]].NouveauPoint(seg);
    tabFace[tabSeg[seg].faces[1]].NouveauPoint(seg);

    tabSeg[seg].SetState(SEGMENT_POINT_LIBRE);
    return tabSeg[seg]._etat;

  FinSi

  // We consider the value 0 to be positive
  Si  v1<-EPSILON_ISOSURFACE
  Alors
    
      pt3D           pt;
      int         numpoint;
    numpoint =  _isosurface->_image_points->Point( _x, _y, _z, tabSeg[seg]);
    Si numpoint == -1 Alors
      pt.Init( _x+_voxel.PosX(p0), _y+_voxel.PosY(p0), _z+_voxel.PosZ(p0));
      numpoint = _isosurface->_image_points->AddPoint( _x, _y, _z, 
                               tabSeg[seg], pt);
    FinSi
    tabInters[seg].Init( numpoint);
    nb_inters_a_traiter++;
    tabFace[tabSeg[seg].faces[0]].NouveauPoint(seg);
    tabFace[tabSeg[seg].faces[1]].NouveauPoint(seg);
    tabSeg[seg].SetState(SEGMENT_POINT_LIBRE);
    return tabSeg[seg]._etat;
  FinSi

  Si v0<-EPSILON_ISOSURFACE
  Alors
    
      pt3D           pt;
      int         numpoint;
    numpoint =  _isosurface->_image_points->Point( _x, _y, _z, tabSeg[seg]);
    Si numpoint == -1 Alors
      pt.Init( _x+_voxel.PosX(p1), _y+_voxel.PosY(p1), _z+_voxel.PosZ(p1));
      numpoint = _isosurface->_image_points->AddPoint( _x, _y, _z, 
                               tabSeg[seg], pt);
    FinSi
    tabInters[seg].Init( numpoint);
    nb_inters_a_traiter++;
    tabFace[tabSeg[seg].faces[0]].NouveauPoint(seg);
    tabFace[tabSeg[seg].faces[1]].NouveauPoint(seg);
    tabSeg[seg].SetState(SEGMENT_POINT_LIBRE);
    return tabSeg[seg]._etat;
  FinSi

  tabSeg[seg].SetState(SEGMENT_VIDE);
  return tabSeg[seg]._etat;

} // CalculIntersection()


//--------------------------------------------------
void Cube :: CreePolygones( IsoSurface* isosurface)
//
{

  
    int         face,segment;
    unsigned char        trouve;
    int         p0=0, p1, p2, p3;
    int         nbpoints, nbpoly;
    pt3D           pt0,pt1,pt2;
    Vect3D<float>   n1,n2;
    Voxel          vox;

  _isosurface = isosurface;



  Pour(segment,0,11)
    CalculIntersection(segment);
  FinPour

  

  Pour(face,0,5)
    Si tabFace[face].nb_pts_inters == 0 Alors
      continue;
    Autrement
    Si tabFace[face].nb_pts_inters == 2 Alors
      ConnectePoints( tabFace[face].pts_trouves[0],
              tabFace[face].pts_trouves[1]);
    Autrement
    Si tabFace[face].nb_pts_inters == 4 Alors
      ResoudAmbiguite(face);
    Sinon
      fprintf(stderr, "voxel %d %d %d, face %d, nb inters %d \n",
          _x, _y, _z, face, tabFace[face].nb_pts_inters);
      fprintf(stderr, "\t  %f %f %f %f \n",
          _valeurs[tabFace[face].points[0]],
          _valeurs[tabFace[face].points[1]],
          _valeurs[tabFace[face].points[2]],
          _valeurs[tabFace[face].points[3]]
          );
      return;
    FinSi
  FinPour


  nbpoly = 0;
  TantQue (nb_inters_a_traiter > 0)Et(nbpoly<=4) Faire

    // Recherche du 1er point a traiter
    segment = 0;
    trouve  = false;
    TantQue (segment < 12) Et (trouve == false) Faire
      Si tabSeg[segment]._etat == SEGMENT_POINT_LIBRE Alors
        trouve = true;
        p0 = segment;
      FinSi
      segment++;
    FinTantQue

    // Suivi du point
    NewPoly();
    PolyAddPoint(p0);
    nbpoints = 1;

    // Look for the right orientation
    p1 = tabInters[p0].pts_voisins[0];
    p2 = tabInters[p0].pts_voisins[1];

    pt0 = _isosurface->_image_points->Point(tabInters[p0]._numpoint);
    pt1 = _isosurface->_image_points->Point(tabInters[p1]._numpoint);
    pt2 = _isosurface->_image_points->Point(tabInters[p2]._numpoint);

    n1 = (pt1-pt0)^(pt2-pt0);

    // n2 is the segment oriented in the direction of the minimal intensity
    Si _valeurs[tabSeg[p0].point[0]] > _valeurs[tabSeg[p0].point[1]] Alors
      n2.x = vox.PosX(tabSeg[p0].point[1]) - vox.PosX(tabSeg[p0].point[0]);
      n2.y = vox.PosY(tabSeg[p0].point[1]) - vox.PosY(tabSeg[p0].point[0]);
      n2.z = vox.PosZ(tabSeg[p0].point[1]) - vox.PosZ(tabSeg[p0].point[0]);
    Sinon
      n2.x = vox.PosX(tabSeg[p0].point[0]) - vox.PosX(tabSeg[p0].point[1]);
      n2.y = vox.PosY(tabSeg[p0].point[0]) - vox.PosY(tabSeg[p0].point[1]);
      n2.z = vox.PosZ(tabSeg[p0].point[0]) - vox.PosZ(tabSeg[p0].point[1]);
    FinSi

    p1 = p0;
    Si n1*n2 >0 Alors
      p2 = tabInters[p0].pts_voisins[0];
    Sinon
      p2 = tabInters[p0].pts_voisins[1];
    FinSi


    // Extract the  polygon
    
    TantQue (p2 != p0)Et(p2!=-1)Et(nbpoints<=12) Faire
      PolyAddPoint(p2);
      nbpoints++;
      p3 = tabInters[p2].VoisinDiffDe(p1);
      p1 = p2;
      p2 = p3;
    FinTantQue

    Si (p2 != p0) AlorsFait
      fprintf(stderr, 
          " voxel  %d %d %d \t Non closed polygon %d \n",
          _x, 
          _y, 
          _z,
          _isosurface->tabPoly.NbElts()
          );

    Si (nbpoints>12) AlorsFait
      fprintf(stderr,
          " voxel  %d %d %d \t mas de 12 puntos\n",
          _x, 
          _y, 
          _z);

    _isosurface->tabPoly += _poly;
    nbpoly++;

  FinTantQue

  Si (nbpoly>4) AlorsFait
      fprintf(stderr," voxel  %d %d %d \t mas de 4 polygonos\n",
          _x, _y, _z);

} // CreePolygones


//--------------------------------------------------
void Cube :: CreateTriangles( IsoSurface* isosurface)
//
{

  
    int         face,segment;
    unsigned char        trouve;
    int         p0=0, p1, p2, p3;
    int         nbpoints, nbpoly;
    pt3D           pt0,pt1,pt2;
    Vect3D<float>   n1,n2;
    Voxel          vox;

  _isosurface = isosurface;



  Pour(segment,0,11)
    CalculIntersection(segment);
  FinPour

  

  Pour(face,0,5)
    Si tabFace[face].nb_pts_inters == 0 Alors
      continue;
    Autrement
    Si tabFace[face].nb_pts_inters == 2 Alors
      ConnectePoints( tabFace[face].pts_trouves[0],
              tabFace[face].pts_trouves[1]);
    Autrement
    Si tabFace[face].nb_pts_inters == 4 Alors
      ResoudAmbiguite(face);
    Sinon
      fprintf(stderr, "voxel %d %d %d, face %d, nb inters %d \n",
          _x, _y, _z, face, tabFace[face].nb_pts_inters);
      fprintf(stderr, "\t  %f %f %f %f \n",
          _valeurs[tabFace[face].points[0]],
          _valeurs[tabFace[face].points[1]],
          _valeurs[tabFace[face].points[2]],
          _valeurs[tabFace[face].points[3]]
          );
      return;
    FinSi
  FinPour


  nbpoly = 0;
  TantQue (nb_inters_a_traiter > 0) Faire

    // Recherche du 1er point a traiter
    segment = 0;
    trouve  = false;
    TantQue (segment < 12) Et (trouve == false) Faire
      Si tabSeg[segment]._etat == SEGMENT_POINT_LIBRE Alors
        trouve = true;
        p0 = segment;
      FinSi
      segment++;
    FinTantQue


    // Look for the right orientation
    p1 = tabInters[p0].pts_voisins[0];
    p2 = tabInters[p0].pts_voisins[1];

    pt0 = _isosurface->_image_points->Point(tabInters[p0]._numpoint);
    pt1 = _isosurface->_image_points->Point(tabInters[p1]._numpoint);
    pt2 = _isosurface->_image_points->Point(tabInters[p2]._numpoint);

    n1 = (pt1-pt0)^(pt2-pt0);

    // n2 is the segment oriented in the direction of the minimal intensity
    Si _valeurs[tabSeg[p0].point[0]] > _valeurs[tabSeg[p0].point[1]] Alors
      n2.x = vox.PosX(tabSeg[p0].point[1]) - vox.PosX(tabSeg[p0].point[0]);
      n2.y = vox.PosY(tabSeg[p0].point[1]) - vox.PosY(tabSeg[p0].point[0]);
      n2.z = vox.PosZ(tabSeg[p0].point[1]) - vox.PosZ(tabSeg[p0].point[0]);
    Sinon
      n2.x = vox.PosX(tabSeg[p0].point[0]) - vox.PosX(tabSeg[p0].point[1]);
      n2.y = vox.PosY(tabSeg[p0].point[0]) - vox.PosY(tabSeg[p0].point[1]);
      n2.z = vox.PosZ(tabSeg[p0].point[0]) - vox.PosZ(tabSeg[p0].point[1]);
    FinSi

    p1 = p0;
    Si n1*n2 >0 Alors
      p2 = tabInters[p0].pts_voisins[0];
    Sinon
      p2 = tabInters[p0].pts_voisins[1];
    FinSi


    // Extract the  polygon
    
    // Suivi du point
    NewPoly();
    PolyAddPoint(p0);
    PolyAddPoint(p2);
    nbpoints = 2;

    p3 = tabInters[p2].VoisinDiffDe(p1);
    p1 = p2;
    p2 = p3;

    TantQue (p2 != p0)Et(p2!=-1) Et (nbpoints<=12)
    Faire

      PolyAddPoint(p2);
      nbpoints++;

      _isosurface->tabPoly += _poly;
      nbpoly++;

      NewPoly();
      //   Replaced because decreases the counter of the number of points to treat
      //   PolyAddPoint(p0);
      //   PolyAddPoint(p2);
      _poly += tabInters[p0]._numpoint;
      _poly += tabInters[p2]._numpoint;

      p3 = tabInters[p2].VoisinDiffDe(p1);
      p1 = p2;
      p2 = p3;

    FinTantQue

    Si nbpoints<3 AlorsFait fprintf(stderr," nbpoints < 3 \n");

    Si (p2 != p0) AlorsFait
      fprintf(stderr, 
          " voxel  %d %d %d \t Non closed polygon %d \n",
          _x, 
          _y, 
          _z,
          _isosurface->tabPoly.NbElts()
          );

    Si (nbpoints>12) AlorsFait
      fprintf(stderr,
          " voxel  %d %d %d \t mas de 12 puntos\n",
          _x, 
          _y, 
          _z);


  FinTantQue


} // CreateTriangles()

 

//======================================================================
// IsoSurface
//======================================================================



//----------------------------------------------------------------------
IsoSurface :: Constructeur IsoSurface(  InrImage::ptr image)
//
{

  _image = image;
  _image_points = new ImagePoints( _image->_tx, _image->_ty, _image->_tz);

  _output_type = OUTPUT_TRIANGLES;

} // Constructeur


//----------------------------------------------------------------------
IsoSurface :: Destructeur IsoSurface()
//
{

  delete _image_points;  

} // Destructeur


//----------------------------------------------------------------------
void IsoSurface :: CalculSurface(float seuil, 
//
                       InrImage* masque) 
{

  
    int x,y,z;
    int n;//,tx,txy;
    Voxel  voxel;
    float   val[8];
    Cube   cube;
    Timing  temps_calcul;
    pt3D   pt;
    double coeff;
    float   val0, val1, valx;

    _seuil = seuil;


//cout << "format de l'image " << _image->_format << endl;

//  tx = _image->_tx;
//  txy = _image->_txy;

//  temps_calcul.InitCumul();

//  temps_calcul.Debut();

  // 1er Parcours: creation des intersections
//  printf("Calcul Intersections \n");

  for(z=_image->_tz-2; z>=0; z--) {
    Si z > 0 Alors 
      printf("\b\b\b");
    Sinon
      printf(" z = ");
    FinSi
    printf("%3d",z); 
    fflush(stdout);
  for(y=_image->_ty-2; y>=0; y--){
    //    _image->BufferPos(_image->_tx-1,y,z);
    valx = (*_image)(_image->_tx-1,y,z) - _seuil;
    //    _image->IncBuffer(-1);
  for(x=_image->_tx-2; x>=0; x--){


    val0 = (*_image)(x,y,z) - _seuil;

    Si masque != NULL Et (*masque)(x,y,z)<127 Alors
      valx = val0;
      continue;
    FinSi
    
    Si val0>EPSILON_ISOSURFACE Alors
      val1 = valx;
      Si  val1<-EPSILON_ISOSURFACE Alors
        coeff = val0/(val0-val1);
        pt.Init(x+coeff,y,z);
        _image_points->AddPoint( x, y, z, 0, pt);

        _image_points->ActiveCube(x,y,  z);
        _image_points->ActiveCube(x,y-1,z);
        _image_points->ActiveCube(x,y-1,z-1);
        _image_points->ActiveCube(x,y,  z-1);
      FinSi

      val1 = (*_image)(x,y+1,z) - _seuil;
      //      val1 = _image->ValeurBuffer(tx) - _seuil;
      Si val1<-EPSILON_ISOSURFACE Alors
        coeff = val0/(val0-val1);
        pt.Init(x,y+coeff,z);
        _image_points->AddPoint( x, y, z, 1, pt);

        _image_points->ActiveCube(x,  y,z  );
        _image_points->ActiveCube(x-1,y,z  );
        _image_points->ActiveCube(x-1,y,z-1);
        _image_points->ActiveCube(x,  y,z-1);
      FinSi
 
      val1 = (*_image)(x,y,z+1) - _seuil;
      //      val1 = _image->ValeurBuffer(txy) - _seuil;
      Si  val1<-EPSILON_ISOSURFACE Alors
        coeff = val0/(val0-val1);
        pt.Init(x,y,z+coeff);
        _image_points->AddPoint( x, y, z, 2, pt);

        _image_points->ActiveCube(x,  y,  z);
        _image_points->ActiveCube(x,  y-1,z);
        _image_points->ActiveCube(x-1,y-1,z);
        _image_points->ActiveCube(x-1,y,  z);
      FinSi
    Autrement
    Si val0<-EPSILON_ISOSURFACE Alors
      val1 = valx;
      Si  val1>EPSILON_ISOSURFACE Alors
        coeff = val0/(val0-val1);
        pt.Init(x+coeff,y,z);
        _image_points->AddPoint( x, y, z, 0, pt);

        _image_points->ActiveCube(x,y,  z);
        _image_points->ActiveCube(x,y-1,z);
        _image_points->ActiveCube(x,y-1,z-1);
        _image_points->ActiveCube(x,y,  z-1);
      FinSi

      val1 = (*_image)(x,y+1,z) - _seuil;
      // val1 = _image->ValeurBuffer(tx) - _seuil;
      Si  val1>EPSILON_ISOSURFACE Alors
        coeff = val0/(val0-val1);
        pt.Init(x,y+coeff,z);
        _image_points->AddPoint( x, y, z, 1, pt);

        _image_points->ActiveCube(x,  y,z  );
        _image_points->ActiveCube(x-1,y,z  );
        _image_points->ActiveCube(x-1,y,z-1);
        _image_points->ActiveCube(x,  y,z-1);
      FinSi
 
      val1 = (*_image)(x,y,z+1) - _seuil;
      //      val1 = _image->ValeurBuffer(txy) - _seuil;
      Si  val1>EPSILON_ISOSURFACE Alors
        coeff = val0/(val0-val1);
        pt.Init(x,y,z+coeff);
        _image_points->AddPoint( x, y, z, 2, pt);

        _image_points->ActiveCube(x,  y,  z);
        _image_points->ActiveCube(x,  y-1,z);
        _image_points->ActiveCube(x-1,y-1,z);
        _image_points->ActiveCube(x-1,y,  z);
      FinSi
    FinSi
    
    valx = val0;
     

      //    _image->IncBuffer(-1);

    } // x
  } // y
  }// z

  printf("\b\b\b\b\b\b\b\b");

//  cout << endl;

//  temps_calcul.Fin();
//  temps_calcul.AddCumul();
//  cout << endl << temps_calcul << endl;

  // 2e Parcours: creation des polygones
//  printf("Calcul Polygones \n");

//  temps_calcul.Debut();  

  Pour(x,0,_image->_tx-2)
    Si x > 0 Alors 
      printf("\b\b\b");
    Sinon
      printf(" x = ");
    FinSi
    printf("%3d",x); 
    fflush(stdout);

    Pour(y,0,_image->_ty-2)
    Pour(z,0,_image->_tz-2)


      Si Non(_image_points->CubeActivated(x,y,z)) 
      AlorsFait continue;

      Pour(n,0,7) 
        val[n]=(*_image)(x+voxel.PosX(n),
             y+voxel.PosY(n),
             z+voxel.PosZ(n))
               - _seuil;
      FinPour

      cube.InitVoxel( x,y,z, val);
      switch (_output_type) {
       case  OUTPUT_TRIANGLES:       
     cube.CreateTriangles( this); break;
       case OUTPUT_POLYGONS:       
     cube.CreePolygones( this); break;
       default: 
     fprintf(stderr,"IsoSurface::CalculSurface() \t invalid output type \n");
     cube.CreateTriangles( this); break;
      }

    FinPour
    FinPour
  FinPour

    //  cout << endl;

    //  temps_calcul.Fin();
    //  temps_calcul.AddCumul();
    //  cout << endl << temps_calcul << endl;


    //  cout << "Calcul IsoSurface " << endl;
    //  temps_calcul.AfficheCumul(cout);

  printf("\b\b\b\b\b\b\b\b");

  cout << "Number of points   " << _image_points->NbPoints() << endl;
  cout << "Number of polygons " << tabPoly.NbElts() << endl;

} // CalculSurface()


//--------------------------------------------------
void  IsoSurface :: CalculNormale( pt3D& pt, Vect3D<float>& norm)
//
{

  
    int x,y,z;
    float   d;

  x = (int) pt.x;
  y = (int) pt.y;
  z = (int) pt.z;


  Si (x>0)Et(x<_image->_tx-2) Alors
    d = pt.x -x;
    Si d<0.5 Alors
      norm.x = ((*_image)(x,y,z)-(*_image)(x-1,y,z)) +
               (0.5+d)*
               (   (*_image)(x+1,y,z) -
                 2*(*_image)(x,  y,z) +
                   (*_image)(x-1,y,z)
               );
    Sinon
      norm.x = ((*_image)(x+1,y,z)-(*_image)(x,y,z)) +
               (d-0.5)*
               (   (*_image)(x+2,y,z) -
                 2*(*_image)(x+1,y,z) +
                   (*_image)(x,  y,z)
               );
    FinSi
  Sinon
    Si (x>=0)Et(x<=_image->_tx-2) AlorsFait
      norm.x = (*_image)(x+1,y,z)-(*_image)(x,y,z);
  FinSi

  Si (y>0)Et(y<_image->_ty-2) Alors
    d = pt.y -y;
    Si d<0.5 Alors
      norm.y = ((*_image)(x,y,z)-(*_image)(x,y-1,z)) +
               (0.5+d)*
               (   (*_image)(x,y+1,z) -
                 2*(*_image)(x,y,  z) +
                   (*_image)(x,y-1,z)
               );
    Sinon
      norm.y = ((*_image)(x,y+1,z)-(*_image)(x,y,z)) +
               (d-0.5)*
               (   (*_image)(x,y+2,z) -
                 2*(*_image)(x,y+1,z) +
                   (*_image)(x,y,  z)
               );
    FinSi
  Sinon
    Si (y>=0)Et(y<=_image->_ty-2) AlorsFait
      norm.y = (*_image)(x,y+1,z)-(*_image)(x,y,z);
  FinSi

  Si (z>0)Et(z<_image->_tz-2) Alors
    d = pt.z -z;
    Si d<0.5 Alors
      norm.z = ((*_image)(x,y,z)-(*_image)(x,y,z-1)) +
               (0.5+d)*
               (   (*_image)(x,y,z+1) -
                 2*(*_image)(x,y,z  ) +
                   (*_image)(x,y,z-1)
               );
    Sinon
      norm.z = ((*_image)(x,y,z+1)-(*_image)(x,y,z)) +
               (d-0.5)*
               (   (*_image)(x,y,z+2) -
                 2*(*_image)(x,y,z+1) +
                   (*_image)(x,y,z  )
               );
    FinSi
  Sinon
    Si (z>=0)Et(z<=_image->_tz-2) AlorsFait
      norm.z = (*_image)(x,y,z+1)-(*_image)(x,y,z);
  FinSi

  // Reorientation : -gradient
  norm.x *= -1.0;
  norm.y *= -1.0;
  norm.z *= -1.0;

  norm.x /= _image->_size_x;
  norm.y /= _image->_size_y;
  norm.z /= _image->_size_z;

} // CalculNormale()


//--------------------------------------------------    
void IsoSurface :: WriteFile( char* nom)
//
{

   
    int n,p;
    pt3D   pt;
    Vect3D<float> norm;
    TPolygone poly;
    FILE*  file;

  file = fopen( (char*) nom, "w");
  Si file == NULL Alors
    fprintf(stderr," IsoSurface::WriteFile() \t");
    fprintf(stderr,"Erreur dans l'ouverture du fichier %s \n", 
        (char*) nom);
    return;
  FinSi

// Write the points

  fprintf( file, "======   NOMBRE DE POINTS %d ======\n", 
       _image_points->NbPoints());

  Pour( n, 0, _image_points->NbPoints()-1)

    pt = _image_points->Point(n);
    fprintf( file, "PT %5d ", n);
    fprintf( file, "( %f %f %f )",
         pt.x*_image->_size_x, 
         pt.y*_image->_size_y, 
         pt.z*_image->_size_z);

    // Ajout de la normale (-gradient)
    CalculNormale(pt, norm);

    fprintf( file, " ( %f %f %f )\n",
         norm.x*_image->_size_x, 
         norm.y*_image->_size_y,  
         norm.z*_image->_size_z);

  FinPour  


// Write the polygones

  fprintf( file, "======   NOMBRE DE POLYGONES %d ======\n", tabPoly.NbElts());

  Pour(p, 0, tabPoly.NbElts()-1) 
    poly = tabPoly[p];
    fprintf( file, "POLY %d [", poly.NbElts());
    Pour( n, 0, poly.NbElts()-1)
      fprintf( file, " %u", poly[n]);
    FinPour  //i
    fprintf( file, " ]\n");
  FinPour 

  fclose( file);

} // WriteFile()


//--------------------------------------------------    
void IsoSurface :: WriteVRML( char* nom)
//
{

   
#ifdef _use_vrml97_
    SceneGraph         sg; 
    ShapeNode          *shape;
    IndexedFaceSetNode *indexfaceset;
    CoordinateNode     *coord;
    NormalNode         *normals;
    float normal[3];

    int n,p;
    pt3D   pt;
    Vect3D<float> norm;
    TPolygone poly;

  // Add a new shape 
  shape = new ShapeNode(); 
  sg.addNode(shape); 

  indexfaceset = new IndexedFaceSetNode();
  shape->addChildNode(indexfaceset);

// Write the points

  coord   = new CoordinateNode();
  normals = new NormalNode();
  indexfaceset->addChildNode(coord);
  indexfaceset->addChildNode(normals);

  Pour( n, 0, _image_points->NbPoints()-1)

    pt = _image_points->Point(n);
    coord->addPoint(pt.x*_image->_size_x, 
            pt.y*_image->_size_y, 
            pt.z*_image->_size_z);

    // Ajout de la normale (-gradient)
    CalculNormale(pt, norm);

    normal[0] = norm.x*_image->_size_x; 
    normal[1] = norm.y*_image->_size_y; 
    normal[2] = norm.z*_image->_size_z; 

    normals->addVector(normal);

  FinPour  


  // Write the polygons

  Pour(p, 0, tabPoly.NbElts()-1) 
    poly = tabPoly[p];
    Pour( n, 0, poly.NbElts()-1)
     indexfaceset->addCoordIndex(poly[n]);
    FinPour  //i
    indexfaceset->addCoordIndex(-1);
  FinPour 

  sg.save(nom);
#endif

} // WriteVRML()


