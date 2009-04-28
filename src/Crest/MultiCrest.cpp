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
 * $Revision: 1.4 $
 * $Log: MultiCrest.cpp,v $
 * Revision 1.4  2005/11/16 14:03:08  karl
 * added LGPL license
 *
 * Revision 1.3  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.2  2004/04/30 20:10:15  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:06  karl
 * Sources code
 *
 */
//
//

#include "MultiCrest.hpp"


#define PROJETTE_AVANT    -3.0
#define PROJETTE_APRES    -2.0
#define PAS_DE_PROJECTION -1.0

//---------------------------------------------------------------------
//
ostream& operator<<(ostream& o, const multipoint& p)
{
  return o << " ( num = " << p.num << "; ligne = "
          	   << p.ligne << "; point = "
          	   << p.point << " )";
}


//---------------------------------------------------------------------
//
ostream& operator<<(ostream& o, const multiligne& l)
{
  return o << " ( num = " << l.num << "; ligne = "
          	   << l.ligne << " )";
}


//---------------------------------------------------------------------
//
ostream& operator<<(ostream& o, const multipoint_ligne& p)
{
  return o << " ( point = " << p.mpoint << "; coeff = "
          	   << p.coeff  << " )";
}

//=====================================================================
//  MEMBRES PRIVES
//=====================================================================

//---------------------------------------------------------------------
unsigned char MultiCrest :: EstConnecte( const multipoint& p)
//                             -----------
{

  
    Point3D          pt1;
    tab_multipoints  points;
    int           nb_points,i;
    multipoint       mpt;

  pt1 = Point(p);

  try{
    points = ListePoints( (int) pt1.x, (int) pt1.y, (int) pt1.z);
  }
  catch (ExceptionListeVide)
  {
    points.VideTableau();
    // points ne contient par defaut aucun elt
  }   

  // Parcours des multipoints dans le voxel courants
  nb_points = 0;
  Pour(i,0,points.NbElts()-1)
    mpt = points[i];
    Si Non(Ligne(mpt) == Ligne(p)) Et Distance(mpt,p) < 1E-5 Alors
      nb_points++;
    FinSi
  FinPour

  return (nb_points>=1);
 
} // EstConnecte()


//---------------------------------------------------------------------
Vect3D<float> MultiCrest :: CoordReelles( const Vect3D<float>& vect_image)
//                                   ------------
{


  return Vect3D<float>( vect_image.x * _image->_size_x,
			  vect_image.y * _image->_size_y,
			  vect_image.z * _image->_size_z );

} // CoordReelles()


//---------------------------------------------------------------------
Vect3D<float> MultiCrest :: CoordImage( const Vect3D<float>& vect_image)
//                                   ----------
{


  return Vect3D<float>( vect_image.x / _image->_size_x,
			  vect_image.y / _image->_size_y,
			  vect_image.z / _image->_size_z );

} // CoordReelles()


//---------------------------------------------------------------------
float MultiCrest :: Distance( const multipoint& p1, const multipoint& p2)
//                          --------
{

  
    Point3D      pt1,pt2;

  try{
    pt1 = Point( p1);
    pt2 = Point( p2);
  }
  catch (OutOfArray)
  {
    cout << " Distance " << p1 << "<-->" << p2 << endl;
  }

  return Norme( CoordReelles(pt2-pt1)); 

} // Distance()


//---------------------------------------------------------------------
float MultiCrest :: Distance( const multiligne& ligne, int p1, int p2)
//                          --------
{

  
    Point3D        pt1,pt2;

  pt1 = Point( ligne, p1);
  pt2 = Point( ligne, p2);

  return Norme( CoordReelles(pt2-pt1)); 

} // Distance()


//---------------------------------------------------------------------
/**
  Tableau des points associ� au voxel (x,y,z)
 */
tab_multipoints& MultiCrest ::  ListePoints( int x, 
//                                        -----------
						 int y, int z)
  throw (ExceptionListeVide)
{

   
    int n;

  n = (int) ((*_image)(x,y,z));

  Si (n==NB_LISTES_MAX) Alors
    throw ExceptionListeVide();
//    return _tab_liste_points[0];
  FinSi

  Si (n<0) Ou (n>=_tab_liste_points.NbElts()) Alors
    fprintf(stderr,"ListePoints(x,y,z)\n erreur indice incorrect\n");
    return _tab_liste_points[0];
  FinSi
  
  return _tab_liste_points[ n];

} // ListePoints()


//---------------------------------------------------------------------
//
void MultiCrest :: AddPoint( int x, int y, int z, 
				      const multipoint& pt )
//
{

  
    tab_multipoints* liste;
    tab_multipoints  liste1;
    int           k,point_existe;

  try{
    liste1 = ListePoints(x,y,z);
  }
  catch (ExceptionListeVide) 
  {
    // Cr�tion d'une nouvelle liste
    liste = new tab_multipoints;
    _tab_liste_points += (*liste);

    // Ajout de cette liste
    _image->BufferPos(x,y,z);
    _image->FixeValeur( _tab_liste_points.NbElts()-1 );

    liste1 = ListePoints(x,y,z);
  }  

  point_existe = false;
  k = 0;
  TantQue (k < liste1.NbElts())Et(Non(point_existe)) Faire
    Si Ligne(liste1[k]) == Ligne(pt) Alors
      try{
      point_existe = (Distance(liste1[k], pt) < 0.01);
      }
      catch(OutOfArray)
      {
        cout << "k=" << k << endl;
        cout << "pt =" << pt << endl;
        cout << "liste1=" << (TableauDyn<multipoint>) liste1 << endl;
      }
    FinSi
    k++;
  FinTantQue

  Si Non(point_existe) AlorsFait ListePoints(x,y,z) += pt;

} // AddPoint()


//---------------------------------------------------------------------
//
void MultiCrest :: MAJImagePoints()
//
{

  
    int     n,l,p;
    multipoint multi_pt;
    Point3D    pt;

  Pour(n,0,1)
    Pour(l,0,lignes[n]->NbLignes()-1)
      Pour(p,0,lignes[n]->NbPoints(l)-1)

        multi_pt.num=n;
        multi_pt.ligne=l;
        multi_pt.point=p;
        pt = lignes[n]->Point(l,p);
        AddPoint( (int) pt.x, (int) pt.y, (int) pt.z, multi_pt);

      FinPour
    FinPour
  FinPour

} // MAJImagePoints()


//---------------------------------------------------------------------
//
unsigned char MultiCrest :: CoordOK( int x, int y, int z)
//
{

  return ( (x>=0)Et(y>=0)Et(z>=0)
             Et
             (x<_image->_tx) Et (y<_image->_ty) Et (z<_image->_tz) 
            );
      
} // CoordOK()


//---------------------------------------------------------------------
//
float MultiCrest :: Projection( const multipoint& p, 
//   ----------
					const multipoint& p1, const multipoint& p2,
					multipoint_ligne& proj)
//
{

  
    Vect3D<float> v1,v2;
    Point3D pt,pt1,pt2;
    float    norme_p1p2;
    float    ps;

  pt  = Point(p);
  pt1 = Point(p1);
  pt2 = Point(p2);

  v1 = CoordReelles(pt2 - pt1);
  v2 = CoordReelles(pt - pt1);

  norme_p1p2 = Norme( v1);

  try {
  v1.Normalise();
  }
  catch (NormeFaible) { 
    cerr << "Projection: distance entre p1 et p2 trop faible \n";
    return PAS_DE_PROJECTION;
  }

  ps = v1*v2;

//  cout << "Projection coeff " << ps/norme_p1p2 << endl;
  Si ps/norme_p1p2 < -5E-2   AlorsRetourne PROJETTE_AVANT;
  Si ps/norme_p1p2 > 1+5E-2  AlorsRetourne PROJETTE_APRES;

  proj.Init( p1, ps/norme_p1p2);
//  cout << proj << endl;
//  cout << Point(proj) << endl;
//  cout << pt << endl;
  return Norme( CoordReelles( Point(proj)-pt));

} // Projection()


//---------------------------------------------------------------------
//
float MultiCrest :: Projection( const multipoint& p, 
//   ----------
					const multipoint& p1, multipoint_ligne& proj)
{

  
    multipoint        p2;
    float              dist1,dist2;
    multipoint_ligne  proj1,proj2;

  dist1 = dist2 = PAS_DE_PROJECTION;
  p2 = p1;

  Si p1.point > 0 Alors
    p2.point = p1.point-1;
    dist1 = Projection( p, p2, p1, proj1);
  FinSi

  Si p1.point < NbPoints(Ligne(p1))-1 Alors
    p2.point = p1.point+1;
    dist2 = Projection( p, p1, p2, proj2);
  FinSi

  //  cout << "Projection " << Point(p1) <<" dist1 = " << dist1;
  //  cout << "\t dist2 = " << dist2 << endl;

  Si (dist1<-0.5) Alors
    Si (dist2<-0.5) Alors
      Si (dist1==PROJETTE_APRES) Et (dist2==PROJETTE_AVANT) Alors
        proj.Init(p1,1.0);
        return Distance(p,p1);
      Sinon
        return -1;
      FinSi
    Sinon
      proj = proj2;
      return dist2;
    FinSi
  Sinon
    Si (dist2<-0.5) Alors
      proj = proj1;
      return dist1;
    Sinon
      Si (dist1<dist2) Alors
        proj = proj1;
        return dist1;
      Sinon
        proj = proj2;
        return dist2;
      FinSi
    FinSi
  FinSi

} // Projection()



//---------------------------------------------------------------------
//
float MultiCrest :: PointPlusProche( multipoint p1, multipoint& p2)
//
{

  
    Point3D         pt1;
    int          x1,y1,z1;
    int          x,y,z;
    float            distmin,dist;
    tab_multipoints points;
    int          i;
    multipoint      mpt;

  distmin = -1;

  pt1 = Point( p1 );
  x1 = (int) pt1.x;
  y1 = (int) pt1.y;
  z1 = (int) pt1.z;

  // Parcours des voxels voisins
  Pour( x, x1-_voisx, x1+_voisx)
  Pour( y, y1-_voisy, y1+_voisy)
  Pour( z, z1-_voisz, z1+_voisz)

    Si CoordOK(x,y,z) Alors

      try{
        points = ListePoints(x,y,z);
      }
      catch (ExceptionListeVide)
      {
        points.VideTableau();
        // points ne contient par defaut aucun elt
      }   

      // Parcours des multipoints dans le voxel courants
      Pour(i,0,points.NbElts()-1)

        mpt = points[i];
        // Si le multipoint courant n'appartient pas a l'ensemble de
        // lignes de p1, calcul de sa distance avec p1
        Si mpt.num != p1.num Alors
          dist = Distance(p1,mpt);
          Si (distmin==-1)Ou(dist<distmin) Alors
            distmin=dist;
            p2 = mpt;
          FinSi
        FinSi

      FinPour
    FinSi

  FinPour
  FinPour
  FinPour

  return distmin;

} // PointPlusProche()


//---------------------------------------------------------------------
//
float MultiCrest :: ProjectionPlusProche( multipoint p1, 
//
						  multipoint_ligne& p2 )
{

  
    Point3D          pt1;
    int           x1,y1,z1;
    int           x,y,z;
    float             distmin,dist;
    tab_multipoints  points;
    int           i;
    multipoint       mpt;
    multipoint_ligne proj;

  Si EstConnecte(p1) Alors
    cout << "ProjectionPlusProche  le point est d��connecte \n";
    return -1;
  FinSi

  distmin = -1;

  pt1 = Point( p1 );
  x1 = (int) pt1.x;
  y1 = (int) pt1.y;
  z1 = (int) pt1.z;

//  cout << "ProjectionPlusProche()\t"
//       << pt1 << "\n";

  // Parcours des voxels voisins
  Pour( x, x1-_voisx, x1+_voisx)
  Pour( y, y1-_voisy, y1+_voisy)
  Pour( z, z1-_voisz, z1+_voisz)

    Si CoordOK(x,y,z) Alors

      try{
        points = ListePoints(x,y,z);
      }
      catch (ExceptionListeVide)
      {
        points.VideTableau();
        // points ne contient par defaut aucun elt
      }   

      // Parcours des multipoints dans le voxel courants
      Pour(i,0,points.NbElts()-1)

        mpt = points[i];

        // Si le point est �al �un point de l'ensemble 2,
        // la ligne se prolonge et on ignore les projection �entuelles
        Si (mpt.num == 2) Et (Distance(mpt,p1) < 1E-5) Alors
  	  cout << "Le point sur prolonge sur l'ensemble 2\n";
          return -1;
        FinSi

        // Si le multipoint courant n'appartient pas a l'ensemble de
        // lignes de p1, calcul de sa distance avec p1
        Si mpt.num != p1.num Alors
          dist = Projection( p1, mpt, proj);
          Si dist>-1E-5 Alors
            Si (distmin==-1)Ou(dist<distmin) Alors
              distmin=dist;
              p2 = proj;
            FinSi
          FinSi
        FinSi

      FinPour
    FinSi

  FinPour
  FinPour
  FinPour

  return distmin;

} // ProjectionPlusProche()


//---------------------------------------------------------------------
//
float MultiCrest :: ProjectionPlusProche2( multipoint p1, 
//
						  multipoint_ligne& p2 )
{

  
    Point3D          pt1;
    int           x1,y1,z1;
    int           x,y,z;
    float             distmin,dist;
    tab_multipoints  points;
    int           i;
    multipoint       mpt;
    multipoint_ligne proj;

/*
  Si EstConnecte(p1) Alors
    cout << "ProjectionPlusProche2 le point est d��connecte \n";
    return -1;
  FinSi
*/

  distmin = -1;

  pt1 = Point( p1 );
  x1 = (int) pt1.x;
  y1 = (int) pt1.y;
  z1 = (int) pt1.z;

//  cout << "ProjectionPlusProche()\t"
//       << pt1 << "\n";

      cout << p1 <<  endl;

  // Parcours des voxels voisins
  Pour(x,x1-8,x1+8)
  Pour(y,y1-8,y1+8)
  Pour(z,z1-8,z1+8)

    Si CoordOK(x,y,z) Alors

      try{
        points = ListePoints(x,y,z);
      }
      catch (ExceptionListeVide)
      {
        points.VideTableau();
        // points ne contient par defaut aucun elt
      }   


      // Parcours des multipoints dans le voxel courants
      Pour(i,0,points.NbElts()-1)

        mpt = points[i];

        // Si le point est �al �un point de l'ensemble 2,
        // la ligne se prolonge et on ignore les projection �entuelles
        Si mpt.num != p1.num Alors
          continue;
        FinSi

        Si mpt.ligne == p1.ligne Alors
          continue;
        FinSi

//        cout << mpt <<  endl;
//	cout <<" i="<< i << " ";

        // Si le multipoint courant n'appartient pas a l'ensemble de
        // lignes de p1, calcul de sa distance avec p1
        dist = Projection( p1, mpt, proj);  
        Si dist>-1E-5 Alors
	//  	  cout << " dist=" << dist << " distmin=" << distmin <<" |";
          Si (distmin==-1)Ou(dist<distmin) Alors
	//    cout << " OK ? ";
            distmin=dist;
            p2 = proj;
          FinSi
        FinSi

      FinPour
      
	  //      Si points.NbElts()>0 AlorsFait 
	  //        cout << endl;

    FinSi

  FinPour
  FinPour
  FinPour
  
	  //  Si distmin > 0 AlorsFait
	  //    cout << "\n distmin = " << distmin << "\n";
  return distmin;

} // ProjectionPlusProche2()


//---------------------------------------------------------------------
//
void MultiCrest :: AjouteSegment( multipoint& p1, multipoint& p2 )
//
{
  
    LigneCrest  ligne_crest;
    Point3D     pt;       
    int      pos1, pos2;

  pt =  Point( p1);
  pos1 = _CREST_tab_points.NbElts();
  _CREST_tab_points += pt;

  pt =  Point( p2);
  pos2 = _CREST_tab_points.NbElts();
  _CREST_tab_points += pt;

  ligne_crest.liste_points += pos1;
  ligne_crest.liste_points += pos2;
  ligne_crest.nb_points+=2;

  _CREST_tab_lignes += ligne_crest;

} // AjouteSegment()


//---------------------------------------------------------------------
//
void MultiCrest :: AjouteSegment( const Point3D& p1, const Point3D& p2 )
//
{
  
    LigneCrest  ligne_crest;
    int      pos1, pos2;

  pos1 = _CREST_tab_points.NbElts();
  _CREST_tab_points += p1;

  pos2 = _CREST_tab_points.NbElts();
  _CREST_tab_points += p2;

  ligne_crest.liste_points += pos1;
  ligne_crest.liste_points += pos2;
  ligne_crest.nb_points+=2;

  _CREST_tab_lignes += ligne_crest;

} // AjouteSegment()


//---------------------------------------------------------------------
//
void MultiCrest :: EffaceLigne( const multiligne& ligne)
//
{

  
    int           p;
    multipoint       multi_pt;
    Point3D          pt;
    int           k;
    int           x,y,z;
    tab_multipoints  points;

//  cout << "EffaceLigne " << num << "; " << ligne << endl;

  Pour(p,0,NbPoints(ligne)-1)

    multi_pt.Init( ligne, p);
    pt = Point( multi_pt);

    x=(int) pt.x;
    y=(int) pt.y;
    z=(int) pt.z;

    // Supprime du voxel tous les points de la ligne 'ligne'
    try{
      points = ListePoints(x,y,z);
    }
    catch (ExceptionListeVide)
    {
      continue;
    }

    k = 0;
    TantQue k < ListePoints(x,y,z).NbElts() Faire
      multi_pt = ListePoints(x,y,z)[k];
      Si (Ligne(multi_pt) == ligne) Alors
        ListePoints(x,y,z).Supprime(k);
      Sinon
        k++;
      FinSi
    FinTantQue

  FinPour

  // Suppression des points de la ligne
  // mais conservation de la ligne pour ne pas
  // avoir a remanier les numeros de ligne
  lignes[ ligne.Ensemble()]->VideLigne( ligne.ligne );

} // EffaceLigne()


//---------------------------------------------------------------------
//
void MultiCrest :: AjouteLigne( int num, const LigneCrest& ligne_crest)
//
{

  
    int           p;
    multipoint       multi_pt;
    Point3D          pt;
    int           numligne;

  // Suppression dans la liste de lignes associ�
  numligne = lignes[num]->AjouteLigne(ligne_crest);

  Pour( p, 0, ligne_crest.nb_points -1)

    //    cout << "p=" << p << "numligne="<< numligne <<"\n";
    multi_pt.Init( num, numligne, p);
    pt = Point( multi_pt);

    try{
    // Ajout du point au voxel (x,y,z)
    AddPoint( (int) pt.x, (int) pt.y, (int) pt.z, multi_pt);
    }
    catch(OutOfArray)
    {
      cout << "pt=" << pt << endl;
      cout << "multi_pt=" << multi_pt  << endl;
    }

  FinPour

} // AjouteLigne()

 
//---------------------------------------------------------------------
//
float MultiCrest :: LongueurLigne( const multiligne& ligne, 
					   int pos1, int pos2)
//
{

  
    double l;
    int     i;
    Point3D    p0,p1;
    int     debut,fin;
    Vect3D<float> vect;

  Si pos1 > pos2 Alors
    debut = pos2;
    fin   = pos1;
  Sinon
    debut = pos1;
    fin   = pos2;
  FinSi

  l=0;

  Pour( i, debut+1, fin)
    p0 = Point(ligne,i-1);
    p1 = Point(ligne,i);

    l += Norme( CoordReelles(p1-p0));

  FinPour

  return l;


} // LongueurLigne()


//---------------------------------------------------------------------
/**
    @return le barycentre de (p1,coeff) et (p2,1-coeff)
 */
Point3D  MultiCrest :: CombLineaire( const Point3D& p1, 
//                              ------------
					       const Point3D& p2, float coeff)
{

  
    Point3D res;

//  cout << "CombLineaire " << p1 << p2 << coeff << endl;

  res.x = p1.x*coeff + p2.x*(1-coeff);
  res.y = p1.y*coeff + p2.y*(1-coeff);
  res.z = p1.z*coeff + p2.z*(1-coeff);

  res.proba = p1.proba*coeff + p2.proba*(1-coeff);
  res.rayon = p1.rayon*coeff + p2.rayon*(1-coeff);

  return res;

} // ComLineaire()


//---------------------------------------------------------------------
/**

 */
void  MultiCrest :: AjouteCombLineaire
//                           ------------------
             ( int num, LigneCrest& ligne_crest,
	       const multiligne& ligne1, int pos12, int pos11, float coeff1,
	       const multiligne& ligne2, int pos22, int pos21, float coeff2 )
{

  
    int     i,nb_points;
    int     nouv_pt;
    Point3D    point1, point2, point;
    float       longueur1, longueur2, lmax;
    double t1, t2 , dt1, dt2; // abscisse curviligne

    int     n1;    // dernier point parcourue sur la ligne1
    double dist1; // longueur de la ligne1 jusqu'a n1

    int     n2;    // dernier point parcourue sur la ligne2
    double dist2; // longueur de la ligne1 jusqu'a n2

    int     pas1, pas2; // sens de parcours pour chaque ligne

    double d1,d2;

//  cout << "AjouteCombLineaire\t" 
//  << ligne1 << ": " << pos12 << "->" << pos11 << "\t"
//  << ligne2 << ": " << pos22 << "->" << pos21 << endl;

  // Calculer la taille de chaque partie de ligne
  longueur1 = LongueurLigne( ligne1, pos12, pos11);
  longueur2 = LongueurLigne( ligne2, pos22, pos21);

//  cout 
//    << "longueur1 = " << longueur1
//    << "longueur2 = " << longueur2 << endl;


  Si longueur1>longueur2 Alors 
    lmax = longueur1; 
  Sinon 
    lmax = longueur2; 
  FinSi

  Si pos11 > pos12 Alors 
    pas1=1; 
  Autrement
  Si pos11 < pos12 Alors 
    pas1=-1;
  Sinon 
    pas1=0;
  FinSi

  Si pos21 > pos22 Alors 
    pas2=1; 
  Autrement
  Si pos21 < pos22 Alors
    pas2=-1; 
  Sinon
    pas2=0;
  FinSi

  //  cout << "pas1 " << pas1 << "pas2 " << pas2 << endl;

  nb_points = 2*((int)(lmax+1));
  dt1 = longueur1/nb_points;
  dt2 = longueur2/nb_points;

/*
  // On ne prend pas les bords
  t1 = dt1;
  t2 = dt2;
*/
  t1 = 0;
  t2 = 0;
  n1 = pos12;
  n2 = pos22;
  dist1 = dist2 = 0;

/*
  Pour(i,1,nb_points-1)
*/
  Pour(i,0,nb_points)

  try{
    Si pas1!=0 Alors
      d1 = Distance( ligne1, n1, n1+pas1);    
      TantQue (dist1+d1 < t1-1E-5) Faire
        dist1+=d1;
        n1+=pas1;
        d1 = Distance( ligne1, n1, n1+pas1);    
      FinTantQue

      point1 = CombLineaire( Point(ligne1,n1),
	  		     Point(ligne1,n1+pas1),
			     1-(t1-dist1)/d1);
    Sinon
      point1 = Point(ligne1,n1);
    FinSi

    Si pas2!=0 Alors
      d2 = Distance( ligne2, n2, n2+pas2);    
      TantQue (dist2+d2 < t2-1E-5) Faire
        dist2+=d2;
        n2+=pas2;
        d2 = Distance( ligne2, n2, n2+pas2);    
      FinTantQue

      point2 = CombLineaire( Point(ligne2,n2),
	  		     Point(ligne2,n2+pas2),
			     1-(t2-dist2)/d2);
    Sinon
      point2 = Point(ligne2,n2);
    FinSi

      //    cout << "COEFF=" << coeff1+(coeff2-coeff1)*i/nb_points << endl;
    point = CombLineaire( point1, point2, coeff1+(coeff2-coeff1)*i/nb_points);

    // Ajout du nouveau point
    nouv_pt = lignes[num]->AddPoint( point );
    ligne_crest.liste_points += nouv_pt;
    ligne_crest.nb_points++;

    t1+=dt1;
    t2+=dt2;
  }
  catch(OutOfArray)
  {
    cout << "\ti= " << i << " nb_points=" << nb_points <<endl;
    cout << "\tn1=" << n1 << "\tpas1=" << pas1 << endl;
    cout << "\tn2=" << n2 << "\tpas2=" << pas2 << endl;
  } 
  FinPour

} // AjouteCombLineaire()


//---------------------------------------------------------------------
/**
  Ajoute a ligne_crest
  la partie de la ligne1 complementaire au segment [pos11,pos12],
  en incluant pos12 et en partant de l'extremite.
  @param pos11 est une extremite de ligne1
 */
void MultiCrest :: AjouteDebutLigne( int num, LigneCrest& ligne_crest, 
//                          ----------------
					      const multiligne& ligne1, 
					      int pos11, int pos12)
{

  
    int     pas, pos;
    int     nouv_pt;


  // Portion de la ligne ligne1
  Si (pos11==0) Alors
    pos=NbPoints(ligne1)-1;
    pas=-1;
  Sinon
    pos=0;
    pas=1;
  FinSi

  //  cout << "pos11 " << pos11 << "\t pos12 " << pos12 << "\t pas " << pas << endl;

  TantQue (pos!=pos12+pas) Faire
  //    cout << "pos = " << pos << "\n"; 
    nouv_pt = lignes[num]->AddPoint( Point(ligne1,pos) );
    ligne_crest.liste_points += nouv_pt;
    ligne_crest.nb_points++;
    pos+=pas;
  FinTantQue

} // AjouteDebutLigne()


//---------------------------------------------------------------------
/**
  Ajoute a ligne_crest
  la partie de la ligne2 complementaire au segment [pos21,pos22],
  en partant de pos22.
  @param pos21 est une extremite de ligne2
 */
void MultiCrest :: AjouteFinLigne( int num, LigneCrest& ligne_crest, 
//                          -------------
					    const multiligne& ligne2, 
				            int pos21, int pos22 )
{

  
    int     pas, pos;
    int     nouv_pt;
    int     posfin;

  // Portion de la ligne ligne2

  //  pos21 est une extremite 
  Si (pos21==0) Alors
    posfin=NbPoints(ligne2)-1;
    pas=1;
  Autrement
  Si (pos21==NbPoints(ligne2)-1) Alors
    posfin=0;
    pas=-1;
  Sinon
    cerr << "Erreur \t AjouteFinLigne,  pos21 n'est pas une extremite\n";
    return;
  FinSi

  pos = pos22;

  TantQue (pos!=posfin+pas) Faire
    nouv_pt = lignes[num]->AddPoint( Point(ligne2,pos) );
    ligne_crest.liste_points += nouv_pt;
    ligne_crest.nb_points++;
    pos+=pas;
  FinTantQue

} // AjouteFinLigne()


//---------------------------------------------------------------------
/**
  Ajoute a ligne_crest
  la partie de la ligne2 correspondant au segment [debut,fin],
  en partant de pos22.
 */
void MultiCrest :: AjoutePartieLigne( int num, LigneCrest& ligne_crest, 
//                          -----------------
					    const multiligne& ligne2, 
				            int debut, int fin )
{

  
    int     pas, pos;
    int     nouv_pt;


  // Portion de la ligne ligne2
  Si (debut<fin) Alors
    pas=1;
  Autrement
  Si (debut>fin) Alors
    pas=-1;
  Sinon
    nouv_pt = lignes[num]->AddPoint( Point(ligne2,debut) );
    ligne_crest.liste_points += nouv_pt;
    ligne_crest.nb_points++;
    return;
  FinSi

  pos = debut;

  TantQue (pos!=fin+pas) Faire
    nouv_pt = lignes[num]->AddPoint( Point(ligne2,pos) );
    ligne_crest.liste_points += nouv_pt;
    ligne_crest.nb_points++;
    pos+=pas;
  FinTantQue

} // AjoutePartieLigne()


//---------------------------------------------------------------------
void MultiCrest :: Fusionne( const multiligne& ligne1, 
//                          --------
				      int pos11, int pos12, 
				      const multiligne& ligne2, 
				      int pos21, int pos22,
				      int num)
{

  
    LigneCrest lr1,lr2,lr3,lr4,lr5; // lignes resultat
    int     nouv_pt;
    Point3D    p1,p2,pt_jonction;
    int     n;

  cout << endl;
  cout << "Fusionne() {\n";
  cout << "pos11 " << pos11 << " pos12 " << pos12 << endl;
  cout << "pos21 " << pos21 << " pos22 " << pos22 << endl;

  // Si pos21 et pos22 sont les 2 extremites de ligne2,
  // on supprime la ligne2
  Si (macro_abs(pos22-pos21)+1) == NbPoints(ligne2) Alors

    cout << "cas 1\n";
    try{

    EffaceLigne(ligne2);
    // Desactiver les points de la ligne dans l'image ...
    return;

    } catch (OutOfArray) {  cin >> n;    }

  FinSi

  // ----------------------------------------
  // Si pos21 est une extremite de la ligne 2
  // ----------------------------------------
  Si (pos21==0) Ou (pos21==NbPoints(ligne2)-1)
  Alors

    cout << "cas 2\n";
    try{

    // Creation de la 1ere ligne
    // -----------------------------

    // Portion de la ligne ligne1
    // cout << "AjouteDebutLigne \n";
    AjouteDebutLigne( ligne1.Ensemble(), lr1, ligne1, pos11, pos12);
 
    // Point de jonction
    //   cout << "jonction \n";
    p1 = Point( ligne1, pos12);
    p2 = Point( ligne2, pos22);
    pt_jonction = CombLineaire( p1, p2, 0.5);

    nouv_pt = lignes[2]->AddPoint( p1 );
    lr2.liste_points += nouv_pt;
    lr2.nb_points++;

    nouv_pt = lignes[2]->AddPoint( pt_jonction );
    lr2.liste_points += nouv_pt;
    lr2.nb_points++;

    nouv_pt = lignes[2]->AddPoint( p2 );
    lr2.liste_points += nouv_pt;
    lr2.nb_points++;


    // Portion de la ligne ligne2
    //  cout << "AjouteFinLigne \n";
    AjouteFinLigne( ligne2.Ensemble(), lr3, ligne2, pos21, pos22 );

    // Creation de la 2eme ligne
    // -----------------------------
    //   cout << "2eme ligne, AjouteCombLineaire \n";
    Si pos12 != pos11 AlorsFait
      AjouteCombLineaire( 2, lr4,
	 		  ligne1, pos12, pos11, 0.5,
			  ligne2, pos22, pos21, 0.5 );
    // Suppression des lignes initiales
    //   cout << "EffaceLignes \n";
    EffaceLigne( ligne1);
    EffaceLigne( ligne2);

    // Ajout des nouvelles lignes dans E0
    //   cout << "AjouteLigne1 \n";
    AjouteLigne( ligne1.Ensemble(), lr1 );
    AjouteLigne( 2,                 lr2 );
    AjouteLigne( ligne2.Ensemble(), lr3 );

    //    cout << "AjouteLigne2 \n";
    Si pos12 != pos11 AlorsFait
      AjouteLigne( 2, lr4);

    } catch (OutOfArray) {  cin >> n;    }

  Autrement

  // ----------------------------------------
  // Si pos22 est une extremite de la ligne 2
  // ----------------------------------------
  Si (pos22==0) Ou (pos22==NbPoints(ligne2)-1)
  Alors

    cout << "cas 3\n";
    try{

    // Portion de la ligne ligne1
    //   cout << "AjouteDebutLigne \n";
    AjouteDebutLigne( ligne1.Ensemble(), lr1, ligne1, pos11, pos12);

    // Portion Commune
    //   cout << "AjouteCombLineaire \n";
    AjouteCombLineaire( 2, lr2,
			ligne1, pos12, pos11, 1.0,
			ligne2, pos22, pos21, 0.0);

    // Portion de la ligne ligne2
    //    cout << "AjouteFinLigne \n";
    AjouteFinLigne( ligne2.Ensemble(), lr3, ligne2, pos22, pos21);

    // Suppression des lignes initiales
    //   cout << " Suppression \n";
    EffaceLigne( ligne1);
    EffaceLigne( ligne2);

    // Ajout des nouvelles lignes dans E1
    //   cout << " AjouteLigne\n";
    AjouteLigne( ligne1.Ensemble(), lr1);
    AjouteLigne( 2, lr2);
    AjouteLigne( ligne2.Ensemble(), lr3);

    } catch (OutOfArray) {  cin >> n;    }

  // ---------------------------------------------------------
  // une partie de ligne1 se projette a l'interieur de ligne2
  // ---------------------------------------------------------
  Sinon

    cout << "cas 4\n";
//    cin >> n;
    try{

    // Portion de la ligne ligne1
    AjouteDebutLigne( ligne1.Ensemble(), lr1, ligne1, pos11, pos12);

    // Portion Commune
    AjouteCombLineaire( 2, lr2,
			ligne1, pos12, pos11, 1.0,
			ligne2, pos22, pos21, 0.0 );

    
    // Portion de la ligne ligne2
    //    cout << "AjouteFinLigne \n";
    Si pos21>pos22 Alors
      AjoutePartieLigne( ligne2.Ensemble(), lr3, ligne2, pos21, NbPoints(ligne2)-1);
      AjoutePartieLigne( ligne2.Ensemble(), lr4, ligne2, pos22, 0);
    Sinon
      AjoutePartieLigne( ligne2.Ensemble(), lr3, ligne2, pos21, 0);
      AjoutePartieLigne( ligne2.Ensemble(), lr4, ligne2, pos22, NbPoints(ligne2)-1);
    FinSi

    p1 = Point( ligne2, pos22);
    p2 = Point( ligne1, pos12);

    nouv_pt = lignes[2]->AddPoint( p1 );
    lr5.liste_points += nouv_pt;
    lr5.nb_points++;

    nouv_pt = lignes[2]->AddPoint( p2 );
    lr5.liste_points += nouv_pt;
    lr5.nb_points++;

    } 
    catch (OutOfArray) {  cout << "creation lignes\n"; cin >> n;    }

    try{
    
    // Suppression de ligne1
    EffaceLigne( ligne1);
    EffaceLigne( ligne2);
    

    // Ajout des nouvelles lignes dans E1
    AjouteLigne( ligne1.Ensemble(), lr1 );
    AjouteLigne( 2, lr2);
    AjouteLigne( ligne2.Ensemble(), lr3);
    AjouteLigne( ligne2.Ensemble(), lr4);
    AjouteLigne( 2, lr5);

    } catch (OutOfArray) {  cout << "efface - ajoute lignes\n"; cin >> n;    }

  FinSi

  cout << "} // Fusionne()\n";

} // Fusionne() 


//=====================================================================
//  MEMBRES PUBLICS
//=====================================================================

//---------------------------------------------------------------------
//
MultiCrest :: Constructeur MultiCrest( Crest* lignes1, Crest* lignes2,
						 Crest* lignes3,
						 InrImage* image) : Crest()
//
{

  
    int x,y,z;
    tab_multipoints* liste;

  _voisx = _voisy = _voisz = 2;

  lignes[0] = lignes1;
  lignes[1] = lignes2;
  lignes[2] = lignes3;

  _image  = new InrImage( WT_UNSIGNED_SHORT, "multipoints.inr", image);

  Pour(x,0,_image->_tx-1)
  Pour(y,0,_image->_ty-1)
  Pour(z,0,_image->_tz-1)

    _image->BufferPos(x,y,z);
    _image->FixeValeur( NB_LISTES_MAX );

  FinPour
  FinPour
  FinPour

  // On met le premier elt de _tab_liste_points 
  // comme etant une liste vide
  liste = new tab_multipoints;
  _tab_liste_points += (*liste);

  MAJImagePoints();

} // Constructeur


//---------------------------------------------------------------------
///
MultiCrest :: Destructeur MultiCrest()
//
{

  delete _image;

} // Destructeur

  
//---------------------------------------------------------------------
void MultiCrest :: CreeLiens( float seuil)
//                           ---------
{

  
    int     l,p;
    multipoint multi_pt, multi_proche;
    Point3D    pt;
    float       distance;
    float       seuil_local;

  Pour(l,0,lignes[0]->NbLignes()-1)
    cout << "{ " ;
    Pour(p,0,lignes[0]->NbPoints(l)-1)

      multi_pt.num=0;
      multi_pt.ligne=l;
      multi_pt.point=p;

      distance = PointPlusProche( multi_pt, multi_proche);

      Si distance>0 Alors

        pt = Point( multi_proche);

        Si seuil<1E-5 Alors
          seuil_local = pt.rayon;
        Sinon
          seuil_local = seuil;
        FinSi

        Si distance < seuil_local Alors

          AjouteSegment( multi_pt, multi_proche);
        FinSi
      FinSi

    FinPour

  FinPour


} // CreeLiens()


//---------------------------------------------------------------------
void MultiCrest :: CreeJonctions( )
//                           -------------
{

  
    int           l,nouvelle_ligne;
    Point3D          pt;
    LigneCrest       ligne;

cout << "Debut CreeJonctions \n";

  cout << " size x = " << _image->_size_x 
       << " size y = " << _image->_size_y 
       << " size z = " << _image->_size_z << endl;

  Pour(l,0,lignes[0]->NbLignes()-1)

    /*
    ligne.nb_points = 0;
    ligne.liste_points.VideTableau();
    Pour( p, 0, lignes[0]->NbPoints(l) -1)
      pt = lignes[0]->Point(l,p);

      // Ajout du point
      _CREST_tab_points += pt;
      _CREST_tab_points[_nb_points].nb_liens = 1;
      _nb_points++;
      numpoint = _nb_points-1;

      ligne += numpoint;
    FinPour
    _CREST_tab_lignes += ligne;
    _nb_lignes++;

    nouvelle_ligne = _nb_lignes-1;
    */
    nouvelle_ligne = Crest::AjouteLigne( (const Crest&) (*lignes[0]),l);


    cout << " l = " << l+1  << " / " << lignes[0]->NbLignes() << "\n";
    CreeJonction( nouvelle_ligne, l, 0);
    CreeJonction( nouvelle_ligne, l, lignes[0]->NbPoints(l)-1);
  FinPour

} // CreeJonctions()


//---------------------------------------------------------------------
// Quels sont les criteres pour avoir une jonctions:
// C1) angle entre les 2 vaisseaux: produit scalaire, a utiliser ?
// C2) les 3 directions s'intersectent a peu pres 
//     (le prolongement d'un vaisseau passe pres du centre de l'autre vaisseau),
// C3) la distance entre les 2 points est faible par rapport 
//    au rayon des vaisseaux,
// C4) le rayon du vaisseau prolonge est plus petit que celui de l'autre vaisseau.
//
void MultiCrest :: CreeJonction( int nouv_l, int l , int pos)
//                           ------------
{

  
    int              n;
    multipoint          multi_pt;
    multipoint_ligne    proj;
    float                distance;
    Point3D             pt,pt2;
   float                C3; //C1,C2,C4; // differents criteres de connexion


  multi_pt.Init(0,l,pos);

  C3 = distance = ProjectionPlusProche2( multi_pt, proj);
  Si distance>0 Alors
    cout << "E2 ... d=" << distance << endl;
    try {
      pt  = Point(proj);
      pt2 = Point(multi_pt);
    }
    catch (ExceptionBadPointNumber)
    {
      cerr << "CreeProjections : probleme .. \n";
      cin >> n;
      return;
    }

//    Si distance < pt.rayon*1.1 + 1.7 Alors
    Si distance < pt.rayon Alors

      cout << "Nouvelle jonction  ligne " << nouv_l << " Points "<< pt << "||" << pt2 << endl;

      Si pos == 0 Alors
        cout << "Reorientation \n";
        ReOrienteLigne( nouv_l);
      FinSi

      pt.jonction = 3;
      n = Crest::AddPoint(pt);
      _CREST_tab_lignes[nouv_l] += n;
//      _CREST_tab_points  += pt;
//      _nb_points++;
//      _CREST_tab_lignes[nouv_l].liste_points += _CREST_tab_points.NbElts()-1;
//      _CREST_tab_lignes[nouv_l].nb_points++;

//      AjouteSegment( Point(multi_pt), pt);

    Sinon

      cerr << "distance = "    << distance 
           << " proj.rayon = " << pt.rayon 
           << " point.rayon = " << pt2.rayon << endl;

//      AjouteSegment( Point(multi_pt), pt);

    FinSi
  FinSi

} // CreeJonction()


//---------------------------------------------------------------------
void MultiCrest :: CreeProjections( )
//                           -------------
{

  
    int              l,p,n;
    multipoint          multi_pt;
    multipoint_ligne    proj;
    float                distance;
    Point3D             pt;

  cout << " size x = " << _image->_size_x 
       << " size y = " << _image->_size_y 
       << " size z = " << _image->_size_z << endl;

  Pour(l,0,lignes[0]->NbLignes()-1)
    cout << "{ " ;
    Pour(p,0,lignes[0]->NbPoints(l)-1)

      multi_pt.num=0;
      multi_pt.ligne=l;
      multi_pt.point=p;
      distance = ProjectionPlusProche( multi_pt, proj);

      Si distance>0 Alors
        try {
          pt = Point(proj);
        }
        catch (ExceptionBadPointNumber)
        {
          cerr << "CreeProjections : probleme .. \n";
          cin >> n;
          continue;
        }
        Si distance < pt.rayon Alors
          AjouteSegment( Point(multi_pt), pt);
        Sinon
  	  cerr << "distance = " << distance << " proj.rayon = " << pt.rayon << endl;
          AjouteSegment( Point(multi_pt), pt);
        FinSi
      FinSi
    FinPour
  FinPour

} // CreeProjections()


//---------------------------------------------------------------------
void MultiCrest :: CreeResultat( )
//                           ------------
{

  
    int           x,y,z,i;
    tab_multipoints  points;
    multipoint       mpt,pt,dernier_point;
    int           nb_points;
    multiligne       l;
    unsigned char          connection_trouvee;
    Point3D          pt1;
    LigneCrest       lr1;

  l.Init(0,0);
  Repeter

  //    cout << "ligne =" << l.ligne << "\t";
    connection_trouvee = false;

    // ---------------------------------------
    // Connection avec la premiere extremite
    // ---------------------------------------
    Si NbPoints(l) >0 Alors

      lr1.nb_points = 0;
      lr1.liste_points.VideTableau ( );

      pt1 = Point( l, 0 );
      pt.Init(l,0);
      x = (int) pt1.x;
      y = (int) pt1.y;
      z = (int) pt1.z;

      try{
        points = ListePoints(x,y,z);
      }
      catch (ExceptionListeVide)
      {
        points.VideTableau();
        // points ne contient par defaut aucun elt
      }   

      // Parcours des multipoints dans le voxel courants
      nb_points = 0;
      Pour(i,0,points.NbElts()-1)
        mpt = points[i];
        Si Non(Ligne(mpt) == l) Et Distance(mpt,pt) < 1E-5 Alors
          nb_points++;
          dernier_point = mpt;
        FinSi
      FinPour

      Si (nb_points == 1) Et 
         ((dernier_point.point==0) Ou
	  (dernier_point.point==NbPoints(Ligne(dernier_point))-1) 
	  ) Alors

        AjouteDebutLigne( 0,  lr1, l, 0, 0);
        AjouteFinLigne(   0,  lr1, Ligne(dernier_point), 
	  		dernier_point.point, 
		  	dernier_point.point);
      
        EffaceLigne(l);
        EffaceLigne(Ligne(dernier_point));
  
        AjouteLigne( 0, lr1 );
        connection_trouvee = true;
      FinSi
    FinSi

    // ---------------------------------------
    // Connection avec la 2eme extremite
    // ---------------------------------------

    Si NbPoints(l) >0 Alors

      lr1.nb_points = 0;
      lr1.liste_points.VideTableau ( );

      pt1 = Point( l,   NbPoints(l)-1);
      pt.Init(l, NbPoints(l)-1);
      x = (int) pt1.x;
      y = (int) pt1.y;
      z = (int) pt1.z;

      try{
        points = ListePoints(x,y,z);
      }
      catch (ExceptionListeVide)
      {
        points.VideTableau();
        // points ne contient par defaut aucun elt
      }
      // Parcours des multipoints dans le voxel courants
      nb_points = 0;
      Pour(i,0,points.NbElts()-1)
        mpt = points[i];
        Si Non(Ligne(mpt) == l) Et Distance(mpt,pt) < 1E-5 Alors
          nb_points++;
          dernier_point = mpt;
        FinSi
      FinPour

      Si (nb_points == 1) Et
         ((dernier_point.point==0) Ou
	  (dernier_point.point==NbPoints(Ligne(dernier_point))-1) 
	  ) Alors

        AjouteDebutLigne( 0,  lr1, l, NbPoints(l)-1, NbPoints(l)-1);
        AjouteFinLigne(    0,  lr1, Ligne(dernier_point), 
	  		dernier_point.point, 
		  	dernier_point.point);
      
        EffaceLigne(l);
        EffaceLigne(Ligne(dernier_point));

        AjouteLigne( 0, lr1 );
        connection_trouvee = true;
      FinSi
    FinSi

    Si Non(connection_trouvee) AlorsFait l.ligne++;


  JusquA (l.ligne>lignes[0]->NbLignes()-1)  
  FinRepeter


} // CreeResultat()


//---------------------------------------------------------------------
void MultiCrest :: Projete(
				        int e1,
					// int e2,
 int e3)
//                           -------
{

  // Parcours de toutes les lignes
  
    multiligne       l;
    multipoint       extrem1, extrem2;
    multipoint_ligne proj_e1, proj_e2;
    float             distance1,distance2;
    int           n0,n1,m0,m1=0;
    float             dist;
    multipoint       p1;
    multipoint_ligne proj_p1;
//    char             nom_fichier[100];
    unsigned char          modif = false;

  cout << endl;
  cout << "lignes de l'ensemble " << e1 << "\n";
  cout << "--------------------\n";
  cout << endl;
  l.Init( e1,  0);
  Repeter

  //    cout << "Repeter\n";
  //  Si modif Alors
  //    sprintf(nom_fichier,"etape%d.0.crest",l);
  //    lignes[0]->Sauve(nom_fichier);
  //    sprintf(nom_fichier,"etape%d.1.crest",l);
  //    lignes[1]->Sauve(nom_fichier);
  //  FinSi
    modif=false;

    TantQue ( l.ligne < lignes[e1]->NbLignes()) Et
            ( NbPoints(l) == 0) Faire 
      l.ligne++;
    FinTantQue

    Si (l.ligne==lignes[e1]->NbLignes()) Alors
      break;
    FinSi

    cout << "l=" << l << "/" << lignes[e1]->NbLignes() << endl;
//    cin >> n;

   Si (l.num ==1)Et (l.ligne == 88) Alors
     cout << "break\n";
   FinSi

	

    // projection des 2 extremites de la lignes sur l'autre ensemble
    extrem1.Init( l, 0);
    distance1 = ProjectionPlusProche( extrem1, proj_e1);
    Si distance1>0 AlorsFait
      Si distance1 > Point(proj_e1).rayon AlorsFait distance1 = -1;

    extrem2.Init( l, NbPoints(l)-1);
    distance2 = ProjectionPlusProche( extrem2, proj_e2);
    Si distance2>0 AlorsFait
      Si distance2 > Point(proj_e2).rayon AlorsFait distance2 = -1;

    cout
         << "distance1 " << distance1
        << "\tdistance2 " << distance2
         << endl;
//    cin >> n;

    // Cas 1: Aucune extremite ne se projette,
    // on garde la ligne
    Si (distance1<0) Et (distance2<0) Alors
      l.ligne++;
      continue;
    FinSi

    // Cas 2: les 2 extremites se projettent sur une meme ligne
    //  on supprime la ligne 
    // (il faudrait verifier que tous les points 
    // se projettent sur une meme ligne) 

    Si (distance1>0) Et (distance2>0) Et
       ( Ligne(proj_e1) == Ligne(proj_e2))
    Alors

      EffaceLigne( l);
      // Desactiver les points de la ligne dans l'image ...

      cout << "Suppression de la ligne "<<  l << endl;
      continue;
    FinSi

    // Cas 3:
    // Une partie de la ligne contenant la premiere extremite
    // se projette sur une autre ligne
    Si (distance1>0) Alors

    try{
      n0 = n1 = extrem1.point;
      proj_p1 = proj_e1;

      dist = distance1;

      // m0 indice de la projection du 1er point
      m0 = proj_e1.PlusProche().point;

      TantQue (dist>0)Et(Ligne(proj_p1) == Ligne(proj_e1) ) Faire
        //Si proj_p1.point > m1 AlorsFait m1 = proj_p1.point;
        //Si proj_p1.point < m0 AlorsFait m0 = proj_p1.point;
        n1++;
        p1.Init( l, n1);

        // m1 indice de la projection du 2eme point
        m1 = proj_p1.PlusProche().point;
        dist = ProjectionPlusProche( p1, proj_p1);      
        Si (dist>0) Et (dist>Point(proj_p1).rayon) AlorsFait dist=-1;

      FinTantQue
      n1--;
    }
    catch (OutOfArray) {
      cout << "pb\n";
    }

      Fusionne( l,n0,n1, Ligne(proj_e1), m0, m1, e3 );
//  cout << "continue\n";
      modif=true;
      continue;
    FinSi

    Si (distance2>0) Alors
      n0 = n1 = extrem2.point;
      proj_p1 = proj_e2;

      dist = distance2;

      // m0 indice de la projection du 1er point
      m0 = proj_e2.PlusProche().point;

      TantQue (dist>0)Et(Ligne(proj_p1) == Ligne(proj_e2)) Faire
        //Si proj_p1.point > m1 AlorsFait m1 = proj_p1.point;
        //Si proj_p1.point < m0 AlorsFait m0 = proj_p1.point;
        n1--;
        p1.Init( l, n1);

        // m1 indice de la projection du 2eme point
        m1 = proj_p1.PlusProche().point;

        dist = ProjectionPlusProche( p1, proj_p1);      
        Si (dist>0) Et (dist>Point(proj_p1).rayon) AlorsFait dist=-1;
      FinTantQue
      n1++;

      Fusionne( l,n0,n1, Ligne(proj_e2), m0, m1, e3 );
      modif=true;
      continue;
    FinSi

    // Sinon ...
    l.ligne++;

  JusquA (l.ligne>lignes[e1]->NbLignes()-1)  
  FinRepeter

  cout << "fin\n";

} // Projete()


//---------------------------------------------------------------------
void MultiCrest :: CombineLignes()
//                           -------------
{

  Projete(0,0);

  Projete(1,1);

} // CombineLignes()


