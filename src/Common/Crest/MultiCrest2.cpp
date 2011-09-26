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
 * $Log: MultiCrest2.cpp,v $
 * Revision 1.3  2005/11/16 14:03:08  karl
 * added LGPL license
 *
 * Revision 1.2  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:05  karl
 * Sources code
 *
 */
//
//

#include "MultiCrest2.hpp"


//---------------------------------------------------------------------
//
std::ostream& operator<<(std::ostream& o, const t_point& p)
{
  return o << " (  ligne = "
          	   << p.ligne << "; point = "
          	   << p.point << " )";
}


//---------------------------------------------------------------------
//
std::ostream& operator<<(std::ostream& o, const point_ligne& p)
{
  return o << " ( point = " << p.mpoint << "; coeff = "
          	   << p.coeff  << " )";
}

//=====================================================================
//  MEMBRES PRIVES
//=====================================================================

//---------------------------------------------------------------------
Vect3D<float> MultiCrest2 :: CoordReelles( const Vect3D<float>& vect_image)
//                                   ------------
{


  return Vect3D<float>( vect_image.x * _image->_size_x,
			  vect_image.y * _image->_size_y,
			  vect_image.z * _image->_size_z );

} // CoordReelles()


//---------------------------------------------------------------------
Vect3D<float> MultiCrest2 :: CoordImage( const Vect3D<float>& vect_image)
//                                   ----------
{


  return Vect3D<float>( vect_image.x / _image->_size_x,
			  vect_image.y / _image->_size_y,
			  vect_image.z / _image->_size_z );

} // CoordReelles()


//---------------------------------------------------------------------
float MultiCrest2 :: Distance( const t_point& p1, const t_point& p2)
//                          --------
{

  
    Point3D      pt1,pt2;

  try{
    pt1 = Point( p1);
    pt2 = Point( p2);
  }
  catch (OutOfArray)
  {
   std::cout << " Distance " << p1 << "<-->" << p2 << std::endl;
  }

  return Norme( CoordReelles(pt2-pt1)); 

} // Distance()


//---------------------------------------------------------------------
float MultiCrest2 :: Distance( const int& ligne, int p1, int p2)
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
tab_points& MultiCrest2 ::  ListePoints( int x, 
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
void MultiCrest2 :: AddPoint( int x, int y, int z, 
				      const t_point& pt )
//
{

  
    tab_points* liste;
    tab_points  liste1;
    int           k,point_existe;

  try{
    liste1 = ListePoints(x,y,z);
  }
  catch (ExceptionListeVide) 
  {
    // Cr�tion d'une nouvelle liste
    liste = new tab_points;
    _tab_liste_points += (*liste);

    // Ajout de cette liste
    _image->BufferPos(x,y,z);
    _image->FixeValeur( _tab_liste_points.NbElts()-1 );

    liste1 = ListePoints(x,y,z);
  }  

  point_existe = false;
  k = 0;
  TantQue (k < liste1.NbElts())Et(Non(point_existe)) Faire
    try{
    point_existe = (Distance(liste1[k], pt) < 0.01);
    }
    catch(OutOfArray)
    {
     std::cout << "k=" << k << std::endl;
     std::cout << "pt =" << pt << std::endl;
     std::cout << "liste1=" << (TableauDyn<t_point>) liste1 << std::endl;
    }
    k++;
  FinTantQue

  Si Non(point_existe) AlorsFait ListePoints(x,y,z) += pt;

} // AddPoint()


//---------------------------------------------------------------------
//
void MultiCrest2 :: MAJImagePoints()
//
{

  
    int     l,p;
    t_point multi_pt;
    Point3D    pt;

    Pour(l,0,lignes->NbLignes()-1)
      Pour(p,0,lignes->NbPoints(l)-1)

        multi_pt.ligne=l;
        multi_pt.point=p;
        pt = lignes->Point(l,p);
        AddPoint( (int) pt.x, (int) pt.y, (int) pt.z, multi_pt);

      FinPour
    FinPour

} // MAJImagePoints()


//---------------------------------------------------------------------
//
unsigned char MultiCrest2 :: CoordOK( int x, int y, int z)
//
{

  return ( (x>=0)Et(y>=0)Et(z>=0)
             Et
             (x<_image->_tx) Et (y<_image->_ty) Et (z<_image->_tz) 
            );
      
} // CoordOK()


//---------------------------------------------------------------------
//
float MultiCrest2 :: Projection( const t_point& p, 
//   ----------
					const t_point& p1, const t_point& p2,
					point_ligne& proj)
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
    std::cerr << "Projection: distance entre p1 et p2 trop faible \n";
    return -1;
  }

  ps = v1*v2;

  Si ps < -5E-2            AlorsRetourne -2;
  Si ps > norme_p1p2+5E-2  AlorsRetourne -1;

  proj.Init( p1, ps/norme_p1p2);
  return Norme( CoordReelles( Point(proj)-pt));

} // Projection()


//---------------------------------------------------------------------
//
float MultiCrest2 :: Projection( const t_point& p, 
//   ----------
					const t_point& p1, point_ligne& proj)
{

  
    t_point        p2;
    float              dist1,dist2;
    point_ligne  proj1,proj2;

  dist1 = dist2 = -1;
  p2 = p1;

  Si p1.point > 0 Alors
    p2.point = p1.point-1;
    dist1 = Projection( p, p2, p1, proj1);
  FinSi

  Si p1.point < NbPoints(Ligne(p1))-1 Alors
    p2.point = p1.point+1;
    dist2 = Projection( p, p1, p2, proj2);
  FinSi

  Si (dist1<-0.5) Alors
    Si (dist2<-0.5) Alors
      Si (dist1>-1.5) Et (dist2<-1.5) Alors
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
float MultiCrest2 :: PointPlusProche( t_point p1, t_point& p2)
//
{

  
    Point3D         pt1;
    int          x1,y1,z1;
    int          x,y,z;
    float            distmin,dist;
    tab_points points;
    int          i;
    t_point      mpt;

  distmin = -1;

  pt1 = Point( p1 );
  x1 = (int) pt1.x;
  y1 = (int) pt1.y;
  z1 = (int) pt1.z;

  // Parcours des voxels voisins
  Pour(x,x1-1,x1+1)
  Pour(y,y1-1,y1+1)
  Pour(z,z1-1,z1+1)

    Si CoordOK(x,y,z) Alors

      try{
        points = ListePoints(x,y,z);
      }
      catch (ExceptionListeVide)
      {
        points.VideTableau();
        // points ne contient par defaut aucun elt
      }   

      // Parcours des points dans le voxel courants
      Pour(i,0,points.NbElts()-1)

        mpt = points[i];
        // Si le point courant n'appartient pas a l'ensemble de
        // lignes de p1, calcul de sa distance avec p1
        Si mpt.ligne != p1.ligne Alors
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
float MultiCrest2 :: ProjectionPlusProche( t_point p1, 
//
						  point_ligne& p2 )
{

  
    Point3D          pt1;
    int           x1,y1,z1;
    int           x,y,z;
    float             distmin,dist;
    tab_points  points;
    int           i;
    t_point       mpt;
    point_ligne proj;

  distmin = -1;

  pt1 = Point( p1 );
  x1 = (int) pt1.x;
  y1 = (int) pt1.y;
  z1 = (int) pt1.z;

  // Parcours des voxels voisins
  Pour(x,x1-1,x1+1)
  Pour(y,y1-1,y1+1)
  Pour(z,z1-1,z1+1)

    Si CoordOK(x,y,z) Alors

      try{
        points = ListePoints(x,y,z);
      }
      catch (ExceptionListeVide)
      {
        points.VideTableau();
        // points ne contient par defaut aucun elt
      }   

      // Parcours des points dans le voxel courants
      Pour(i,0,points.NbElts()-1)

        mpt = points[i];
        // Si le point courant n'appartient pas a l'ensemble de
        // lignes de p1, calcul de sa distance avec p1
        Si mpt.ligne != p1.ligne Alors
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
void MultiCrest2 :: AjouteSegment( t_point& p1, t_point& p2 )
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
void MultiCrest2 :: AjouteSegment( const Point3D& p1, const Point3D& p2 )
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
void MultiCrest2 :: EffaceLigne( const int& ligne)
//
{

  
    int           p;
    t_point       multi_pt;
    Point3D          pt;
    int           k;
    int           x,y,z;
    tab_points  points;

// std::cout << "EffaceLigne " << num << "; " << ligne << std::endl;

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
  lignes->VideLigne( ligne );

} // EffaceLigne()


//---------------------------------------------------------------------
//
void MultiCrest2 :: AjouteLigne( const LigneCrest& ligne_crest)
//
{

  
    int           p;
    t_point       multi_pt;
    Point3D          pt;
    int           numligne;

  // Suppression dans la liste de lignes associ�
  numligne = lignes->AjouteLigne(ligne_crest);

  Pour( p, 0, ligne_crest.nb_points -1)

    //   std::cout << "p=" << p << "numligne="<< numligne <<"\n";
    multi_pt.Init( numligne, p);
    pt = Point( multi_pt);

    try{
    // Ajout du point au voxel (x,y,z)
    AddPoint( (int) pt.x, (int) pt.y, (int) pt.z, multi_pt);
    }
    catch(OutOfArray)
    {
     std::cout << "pt=" << pt << std::endl;
     std::cout << "multi_pt=" << multi_pt  << std::endl;
    }

  FinPour

} // AjouteLigne()

 
//---------------------------------------------------------------------
//
float MultiCrest2 :: LongueurLigne( const int& ligne, 
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
Point3D  MultiCrest2 :: CombLineaire( const Point3D& p1, 
//                              ------------
					       const Point3D& p2, float coeff)
{

  
    Point3D res;

// std::cout << "CombLineaire " << p1 << p2 << coeff << std::endl;

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
void  MultiCrest2 :: AjouteCombLineaire
//                           ------------------
             ( LigneCrest& ligne_crest,
	       const int& ligne1, int pos12, int pos11, float coeff1,
	       const int& ligne2, int pos22, int pos21, float coeff2 )
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

// std::cout << "AjouteCombLineaire\t" 
//  << ligne1 << ": " << pos12 << "->" << pos11 << "\t"
//  << ligne2 << ": " << pos22 << "->" << pos21 << std::endl;

  // Calculer la taille de chaque partie de ligne
  longueur1 = LongueurLigne( ligne1, pos12, pos11);
  longueur2 = LongueurLigne( ligne2, pos22, pos21);

// std::cout 
//    << "longueur1 = " << longueur1
//    << "longueur2 = " << longueur2 << std::endl;


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

  // std::cout << "pas1 " << pas1 << "pas2 " << pas2 << std::endl;

  nb_points = 2*((int)(lmax+1));
  dt1 = longueur1/nb_points;
  dt2 = longueur2/nb_points;

  // On ne prend pas les bords
  t1 = dt1;
  t2 = dt2;
  n1 = pos12;
  n2 = pos22;
  dist1 = dist2 = 0;

  Pour(i,1,nb_points-1)

  try{
    Si pas1!=0 Alors
      d1 = Distance( ligne1, n1, n1+pas1);    
      TantQue (dist1+d1 < t1) Faire
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
      TantQue (dist2+d2 < t2) Faire
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

      //   std::cout << "COEFF=" << coeff1+(coeff2-coeff1)*i/nb_points << std::endl;
    point = CombLineaire( point1, point2, coeff1+(coeff2-coeff1)*i/nb_points);

    // Ajout du nouveau point
    nouv_pt = lignes->AddPoint( point );
    ligne_crest.liste_points += nouv_pt;
    ligne_crest.nb_points++;

    t1+=dt1;
    t2+=dt2;
  }
  catch(OutOfArray)
  {
   std::cout << "\ti= " << i << " nb_points=" << nb_points <<std::endl;
   std::cout << "\tn1=" << n1 << "\tpas1=" << pas1 << std::endl;
   std::cout << "\tn2=" << n2 << "\tpas2=" << pas2 << std::endl;
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
void MultiCrest2 :: AjouteDebutLigne( LigneCrest& ligne_crest, 
//                          ----------------
					      const int& ligne1, 
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

  // std::cout << "pos11 " << pos11 << "\t pos12 " << pos12 << "\t pas " << pas << std::endl;

  TantQue (pos!=pos12+pas) Faire
  //   std::cout << "pos = " << pos << "\n"; 
    nouv_pt = lignes->AddPoint( Point(ligne1,pos) );
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
void MultiCrest2 :: AjouteFinLigne(  LigneCrest& ligne_crest, 
//                          -------------
					    const int& ligne2, 
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
    std::cerr << "Erreur \t AjouteFinLigne,  pos21 n'est pas une extremite\n";
    return;
  FinSi

  pos = pos22;

  TantQue (pos!=posfin+pas) Faire
    nouv_pt = lignes->AddPoint( Point(ligne2,pos) );
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
void MultiCrest2 :: AjoutePartieLigne( LigneCrest& ligne_crest, 
//                          -----------------
					    const int& ligne2, 
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
    nouv_pt = lignes->AddPoint( Point(ligne2,debut) );
    ligne_crest.liste_points += nouv_pt;
    ligne_crest.nb_points++;
    return;
  FinSi

  pos = debut;

  TantQue (pos!=fin+pas) Faire
    nouv_pt = lignes->AddPoint( Point(ligne2,pos) );
    ligne_crest.liste_points += nouv_pt;
    ligne_crest.nb_points++;
    pos+=pas;
  FinTantQue

} // AjoutePartieLigne()


//---------------------------------------------------------------------
void MultiCrest2 :: Fusionne( const int& ligne1, 
//                          --------
				      int pos11, int pos12, 
				      const int& ligne2, 
				      int pos21, int pos22 )
{

  
    LigneCrest lr1,lr2,lr3; // lignes resultat
    int     nouv_pt;
    Point3D    p1,p2,pt_jonction;
    int     n;

 std::cout << "Fusionne() {\n";

  // Si pos21 et pos22 sont les 2 extremites de ligne2,
  // on supprime la ligne2
  Si (macro_abs(pos22-pos21)+1) == NbPoints(ligne2) Alors

   std::cout << "cas 1\n";
    try{

    EffaceLigne(ligne2);
    // Desactiver les points de la ligne dans l'image ...
    return;

    } catch (OutOfArray) {  std::cin >> n;    }

  FinSi

  // ----------------------------------------
  // Si pos21 est une extremite de la ligne 2
  // ----------------------------------------
  Si (pos21==0) Ou (pos21==NbPoints(ligne2)-1)
  Alors

   std::cout << "cas 2\n";
    try{

    // Creation de la 1ere ligne
    // -----------------------------

    // Portion de la ligne ligne1
    //  std::cout << "AjouteDebutLigne \n";
    AjouteDebutLigne(  lr1, ligne1, pos11, pos12);
    // Point de jonction
    //   std::cout << "jonction \n";
    p1 = Point( ligne1, pos12);
    p2 = Point( ligne2, pos22);
    pt_jonction = CombLineaire( p1, p2, 0.5);

    nouv_pt = lignes->AddPoint( pt_jonction );
    lr1.liste_points += nouv_pt;
    lr1.nb_points++;
    // Portion de la ligne ligne2
    //   std::cout << "AjouteFinLigne \n";
    AjouteFinLigne(  lr1, ligne2, pos21, pos22 );

    // Creation de la 2eme ligne
    // -----------------------------
    //   std::cout << "2eme ligne, AjouteCombLineaire \n";
    AjouteCombLineaire( lr2,
			ligne1, pos12, pos11, 0.5,
			ligne2, pos22, pos21, 0.5 );
    // Suppression des lignes initiales
    //   std::cout << "EffaceLignes \n";
    EffaceLigne( ligne1);
    EffaceLigne( ligne2);

    // Ajout des nouvelles lignes dans E0
    //   std::cout << "AjouteLigne1 \n";
    AjouteLigne( lr1 );
    //   std::cout << "AjouteLigne2 \n";
    AjouteLigne(  lr2);

    } catch (OutOfArray) {  std::cin >> n;    }

  Autrement

  // ----------------------------------------
  // Si pos22 est une extremite de la ligne 2
  // ----------------------------------------
  Si (pos22==0) Ou (pos22==NbPoints(ligne2)-1)
  Alors

   std::cout << "cas 3\n";
    try{

    // Portion de la ligne ligne1
    //  std::cout << "AjouteDebutLigne \n";
    AjouteDebutLigne(  lr1, ligne1, pos11, pos12);

    // Portion Commune
    //  std::cout << "AjouteCombLineaire \n";
    AjouteCombLineaire(  lr1,
			ligne1, pos12, pos11, 1.0,
			ligne2, pos22, pos21, 0.0);

    // Portion de la ligne ligne2
    //   std::cout << "AjouteFinLigne \n";
    AjouteFinLigne(  lr1, ligne2, pos22, pos21);

    // Suppression des lignes initiales
    //  std::cout << " Suppression \n";
    EffaceLigne( ligne1);
    EffaceLigne( ligne2);

    // Ajout des nouvelles lignes dans E1
    //  std::cout << " AjouteLigne\n";
    AjouteLigne(  lr1);

    } catch (OutOfArray) {  std::cin >> n;    }

  // ---------------------------------------------------------
  // une partie de ligne1 se projette a l'interieur de ligne2
  // ---------------------------------------------------------
  Sinon

   std::cout << "cas 4\n";
//    cin >> n;
    try{

    // Portion de la ligne ligne1
    AjouteDebutLigne(  lr1, ligne1, pos11, pos12);

    // Portion Commune
    AjouteCombLineaire(  lr1,
			ligne1, pos12, pos11, 1.0,
			ligne2, pos22, pos21, 0.0 );

    // Portion de la ligne ligne2
    //   std::cout << "AjouteFinLigne \n";
    Si pos21>pos22 Alors
      AjoutePartieLigne(  lr1, ligne2, pos21, NbPoints(ligne2)-1);
      AjoutePartieLigne( lr2, ligne2, pos22, 0);
    Sinon
      AjoutePartieLigne(  lr1, ligne2, pos21, 0);
      AjoutePartieLigne(  lr2, ligne2, pos22, NbPoints(ligne2)-1);
    FinSi
    } catch (OutOfArray) { std::cout << "creation lignes\n"; std::cin >> n;    }
    try{

    // Suppression de ligne1
    EffaceLigne( ligne1);
    EffaceLigne( ligne2);

    // Ajout des nouvelles lignes dans E1
    AjouteLigne(  lr1 );
    AjouteLigne(  lr2);
    } catch (OutOfArray) { std::cout << "efface - ajoute lignes\n"; std::cin >> n;    }


  FinSi

 std::cout << "} // Fusionne()\n";

} // Fusionne() 


//=====================================================================
//  MEMBRES PUBLICS
//=====================================================================

//---------------------------------------------------------------------
//
MultiCrest2 ::  MultiCrest2( Crest* l,
						 InrImage* image) : Crest()
//
{

  
    int x,y,z;
    tab_points* liste;

  lignes = l;

  _image            = new InrImage( WT_UNSIGNED_SHORT, "points.inr", image);

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
  liste = new tab_points;
  _tab_liste_points += (*liste);

  MAJImagePoints();

} // Constructor


//---------------------------------------------------------------------
///
MultiCrest2 :: ~MultiCrest2()
//
{

  delete _image;

} // Destructor

  

//---------------------------------------------------------------------
void MultiCrest2 :: CreeProjections( )
//                           ---------------
{

  
    int              l,p,n;
    t_point          multi_pt;
    point_ligne    proj;
    float                distance;
    Point3D             pt;

 std::cout << " size x = " << _image->_size_x 
       << " size y = " << _image->_size_y 
       << " size z = " << _image->_size_z << std::endl;

  Pour(l,0,lignes->NbLignes()-1)
   std::cout << "{ " ;
    Pour(p,0,lignes->NbPoints(l)-1)

      multi_pt.ligne=l;
      multi_pt.point=p;
      distance = ProjectionPlusProche( multi_pt, proj);

      Si distance>0 Alors
        try {
          pt = Point(proj);
        }
        catch (ExceptionBadPointNumber)
        {
          std::cerr << "CreeProjections : probleme .. \n";
          std::cin >> n;
          continue;
        }
        Si distance < pt.rayon Alors
          AjouteSegment( Point(multi_pt), pt);
        Sinon
  	  std::cerr << "distance = " << distance << " proj.rayon = " << pt.rayon << std::endl;
          AjouteSegment( Point(multi_pt), pt);
        FinSi
      FinSi
    FinPour
  FinPour

} // CreeProjections()


//---------------------------------------------------------------------
void MultiCrest2 :: Projete( )
//                           -------
{

  // Parcours de toutes les lignes
  
    int       l;
    t_point       extrem1, extrem2;
    point_ligne proj_e1, proj_e2;
    float             distance1,distance2;
    int           n0,n1,m0,m1=0;
    float             dist;
    t_point       p1;
    point_ligne proj_p1;
    unsigned char          modif = false;

 std::cout << "lignes du 1er ensemble\n";
  l = 0;
  Repeter

    modif=false;

    TantQue ( l < lignes->NbLignes()) Et
            ( NbPoints(l) == 0) Faire 
      l++;
    FinTantQue

    Si (l==lignes->NbLignes()) Alors
      break;
    FinSi

   std::cout << "l=" << l << "/" << lignes->NbLignes() << std::endl;
//    cin >> n;


    // projection des 2 extremites de la lignes sur l'autre ensemble
    extrem1.Init( l, 0);
    distance1 = ProjectionPlusProche( extrem1, proj_e1);
    Si distance1>0 AlorsFait
      Si distance1 > Point(proj_e1).rayon AlorsFait distance1 = -1;

    extrem2.Init( l, NbPoints(l)-1);
    distance2 = ProjectionPlusProche( extrem2, proj_e2);
    Si distance2>0 AlorsFait
      Si distance2 > Point(proj_e2).rayon AlorsFait distance2 = -1;

//   std::cout
//         << "distance1 " << distance1
//        << "\tdistance2 " << distance2
//         << std::endl;
//    cin >> n;

    // Cas 1: Aucune extremite ne se projette,
    // on garde la ligne
    Si (distance1<0) Et (distance2<0) Alors
      l++;
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

     std::cout << "Suppression de la ligne "<<  l << std::endl;
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
     std::cout << "pb\n";
    }

    Fusionne( l,n0,n1, Ligne(proj_e1), m0, m1 );
// std::cout << "continue\n";
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

      Fusionne( l,n0,n1, Ligne(proj_e2), m0, m1 );
      modif=true;
      continue;
    FinSi

    // Sinon ...
    l++;

  JusquA (l>lignes->NbLignes()-1)  
  FinRepeter

 std::cout << "fin\n";

} // Projete()


//---------------------------------------------------------------------
void MultiCrest2 :: CombineLignes()
//                           -------------
{

  
    int nb_lignes;

  
  Repeter

    nb_lignes = lignes->NbLignes();
    Projete();

  JusquA  nb_lignes == lignes->NbLignes() FinRepeter

} // CombineLignes()


