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
 * $Log: MultiCrest.hpp,v $
 * Revision 1.3  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.2  2004/04/30 20:10:15  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:09  karl
 * Sources code
 *
 */
//
// Combinaison de 2 ensembles de lignes
// 
//

#ifndef MULTI_CREST_HPP
#define MULTI_CREST_HPP

#include "style.hpp"
#include "inrimage.hpp"
#include "TableauDyn.hpp"
#include "Crest.hpp"
#include "Coordonnees.hpp"
#include "Voisins27.hpp"

#define NB_LISTES_MAX 65530

#ifdef _sgi_
float Norme( const Vect3D<float>&);
#endif

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/*.doc /u/broca/0/kkrissia/Sources/Prog/Math/include/Coordonnees.doc 

static TableauDyn<Voisin27> t;

typedef 
/**
 @name pt3DReel
 point 3D r�el
 */
class pt3DReel : public Point_3D<float>
{

public:

  ///
  float rayon;
  ///
  float proba;

  ///
   pt3DReel() : Point_3D<float>(), rayon(1.0), proba(0.0) {}

} pt3DReel;


//----------------------------------------------------------------------------
typedef
/**
 @name multiligne
 */
class multiligne
{

public:

  /** num�ro de l'ensemble de lignes
      auquel le point appartient (0 ou 1)
   */
  int num;

  /** numero de la ligne dans l'ensemble 
      auquel le point appartient
  */
  int ligne;
  
  /// constructeur
  //  Constructor multiligne(): num(0), ligne(0) {}

 /// constructeur
   multiligne(int n=0,int l=0): num(n), ligne(l) {}
  
  ///
  multiligne& operator =( const multiligne& p)
  {
    num=p.num; ligne=p.ligne; 
    return *this;
  }

  ///
  int operator ==( const multiligne& p) const
  {
    return ((num==p.num)&&(ligne==p.ligne)); 
  }

  ///
  void Init( int n, int l) { num=n; ligne=l; }

  ///
  int Ensemble() const { return num; }
  
  ///
  friend ostream& operator<<(ostream& o, const multiligne& p);

} multiligne;


//----------------------------------------------------------------------------
typedef
/**
 @name multipoint
 */
class multipoint
{

public:

  /** num�ro de l'ensemble de lignes
      auquel le point appartient (0 ou 1)
   */
  int num;

  /** numero de la ligne dans l'ensemble 
      auquel le point appartient
  */
  int ligne;
  
  /** numero du point dans la ligne
   */
  int point;

  /// constructeur
   multipoint(): num(0), ligne(0), point(0){}
  
  /// constructeur
   multipoint( int n, int l, int p): num(n), ligne(l), 
    point(p) {}
  
  ///
  multipoint& operator =( const multipoint& p)
  {
    num=p.num; ligne=p.ligne; point=p.point;
    return *this;
  }

  ///
  void Init( int n, int l, int p) 
  { num=n; ligne=l; point=p;  }

  ///
  void Init( const multiligne& l, int p) { num=l.num; ligne=l.ligne; point=p;}

  ///
  int Ensemble(const multipoint& l) { return num; }

  ///
  friend ostream& operator<<(ostream& o, const multipoint& p);

} multipoint;


//----------------------------------------------------------------------------
typedef
/**
 @name multipoint_ligne
 position dans une ligne d�finie par deux point et un coefficient dans [0,1]
 si le coefficient = 1, le point est le premier point
 sinon, c'est le barycentre (p1,1-coeff), (p2,coeff)
 */
class multipoint_ligne 
{

public:

  multipoint mpoint;
  float       coeff;

  /// constructeur
   multipoint_ligne(): coeff(0) {}
  
  ///
  multipoint_ligne& operator =( const multipoint_ligne& p)
  {
    mpoint=p.mpoint; coeff = p.coeff;
    return *this;
  }

  ///
  multipoint PlusProche()
  {
    Si coeff < 0.5 Alors
      return mpoint;
    Sinon
      return multipoint(mpoint.num,mpoint.ligne,mpoint.point+1);
    FinSi
  }

  ///
  void Init( const multipoint p, float c) 
  {
     mpoint = p;
     coeff=c;
  }

  ///
  friend ostream& operator<<(ostream& o, const multipoint_ligne& p);

} multipoint_ligne;


typedef 
/**
 @name tab_multipoints
 */
TableauDyn<multipoint> tab_multipoints;



//===========================================================
/**
  Combinaison de 2 ensembles de lignes
 */
class MultiCrest : public Crest
//     ---------
{

  class ExceptionListeVide {};

  class ExceptionBadPointNumber {
  public:
     multipoint _p;
     int     _lmax;

    ExceptionBadPointNumber( multipoint p, int lmax): _p(p), _lmax(lmax) {}   
  };

protected:

/** Trois ensembles de lignes
  lignes[0] et lignes[1] lignes d�tect�es � 2 �chelles diff�rentes
  lignes[2] portions de lignes nouvelles cr�es par combinaison de parties de lignes
            de lignes[0] et de lignes[1]
 */
  Crest* lignes[3];

  /// Tableau de listes de points
  TableauDyn< tab_multipoints > _tab_liste_points;
 
  /**
    Image d'entier qui sont la position dans le tableau \\
    {\it _tab_liste_points} de la liste de points associ�e � chaque voxel
   */
  InrImage*           _image;

  /**
    Taille des voisinages sur lequels on cherche les points ou les projections
    les plus proches
   */
//@{
  ///
  int         _voisx;
  ///
  int         _voisy;
  ///
  int         _voisz;
//@}

  ///
  Point3D& Point( const multipoint& p) throw (ExceptionBadPointNumber)
  //       -----
  {
    Si (p.point < 0) Ou (p.point >= lignes[p.num]->NbPoints(p.ligne)) Alors
     throw ExceptionBadPointNumber( p, lignes[p.num]->NbPoints(p.ligne));
    FinSi
    return lignes[p.num]->Point(p.ligne, p.point);
  } 

  /** Un point est connecte s'il existe plusieurs point ayant appartenant
     � des lignes diff�rentes et ayant les coordonnees de
     ce point
  */
  unsigned char EstConnecte( const multipoint& p);


  ///
  Point3D Point( const multipoint_ligne& p)
  //      -----
  {
    
      multipoint pt;

    Si fabsf( p.coeff ) < 1E-3 Alors
      return Point(p.mpoint);
    Sinon
      pt = p.mpoint;
      pt.point++;
      try {
      return CombLineaire( Point(p.mpoint), Point(pt),  1-p.coeff);
      }
      catch (ExceptionBadPointNumber& e)
      {
        std::cerr << "BadPointNumber " << p.mpoint << "\t" << pt << std::endl;
        std::cerr << e._p << e._lmax << std::endl;
        cin >> pt.num;
      }
    FinSi
    return Point(p.mpoint);
  } 

  ///
  multiligne Ligne(const multipoint& p) { return multiligne(p.num,p.ligne); }

  ///
  multiligne Ligne(const multipoint_ligne& p) 
  { return multiligne(p.mpoint.num,p.mpoint.ligne); }

  ///
  Point3D& Point( const multiligne& l, int p)
  //       -----
  {
    return lignes[l.num]->Point(l.ligne, p);
  } 


  ///
  int NbPoints( const multiligne& l) { return lignes[l.num]->NbPoints(l.ligne); }
  //     --------


  ///
  Vect3D<float> CoordReelles( const Vect3D<float>& vect_image);
  //            ------------

  ///
  Vect3D<float> CoordImage( const Vect3D<float>& vect_image);
  //            ----------

  /// distance entre 2 multipoints
  float Distance( const multipoint& p1, const multipoint& p2);
  //   --------

  /** distance entre 2 points de la meme ligne
   */
  float Distance( const multiligne& ligne, int p1, int p2);
  //   --------
  

  /**
    Tableau des points associ�s au voxel (x,y,z)
   */
  tab_multipoints&  ListePoints( int x, int y, int z) 
  //                -----------
    throw (ExceptionListeVide);


  /**
    Ajoute au voxel (x,y,z) le multipoint pt
   */
  void AddPoint( int x, int y, int z, const multipoint& pt );
  //   --------


  /**
    Met a jour la liste des points par voxels
  */
  void MAJImagePoints();
  //   --------------


/**
  teste si les coordonnees (x,y,z) sont dans le domaine de definition
  de l'image image
 */
  unsigned char CoordOK( int x, int y, int z);
  //      -------


/**
  Projection du point p sur le segment [p1,p2],
  Si p se projette a l'interieur du segment, 
    retourne la distance
  Sinon 
    retourne -1

  proj est la projection si elle existe

 */
  float Projection( const multipoint& p, 
  //   ----------
		   const multipoint& p1, const multipoint& p2,
		   multipoint_ligne& proj);


/**
  Projection du point p sur un des segments de la ligne de p1 contenant p1.
  Si la projection existe, 
    proj est la projection 
    retourne la distance,
  Sinon
    retourne -1

 */
  float Projection( const multipoint& p, 
  //   ----------
		   const multipoint& p1, multipoint_ligne& proj);

/**
  Recherche le point le plus proche de p1 dans un 27 voisinage
  du voxel auquel p1 appartient et parmis les points de l'autre
  ensemble de lignes.
  @param p1 point de reference.
  @param p2 retourne le resultat.
  @return la valeur de retour est la distance entre les points trouves
  ou -1 si aucun point n'est trouv�.
 */
  float PointPlusProche( multipoint p1, multipoint& p2);
  //   ---------------


/**
  Recherche la projection de p1 sur les lignes voisines dans un 27 voisinage
  du voxel auquel p1 appartient et parmis les points de l'autre
  ensemble de lignes.
  @param p1 point de reference.
  @param p2  multipoint qui a permis de trouver la projection.
  @param pt2 coordonnees de la projection
  @return la valeur de retour est la distance entre les points trouves
  ou -1 si aucun point n'est trouv�.
 */
  float ProjectionPlusProche( multipoint p1,  multipoint_ligne& p2);
  //   --------------------


/**
  Recherche la projection de p1 sur les lignes voisines dans un 27 voisinage
  du voxel auquel p1 appartient et parmis les points 
  du meme ensemble de lignes que p1.
  @param p1 point de reference.
  @param p2  multipoint qui a permis de trouver la projection.
  @param pt2 coordonnees de la projection
  @return la valeur de retour est la distance entre les points trouves
  ou -1 si aucun point n'est trouv�.
 */
  float ProjectionPlusProche2( multipoint p1,  multipoint_ligne& p2);
  //   ---------------------



  /**
    Ajoute un segment constitu� des points p1 et p2
   */
  void  AjouteSegment( multipoint& p1, multipoint& p2 );
  //    -------------

  /**
    Ajoute un segment constitu� des points p1 et p2
   */
  void  AjouteSegment( const Point3D& p1, const Point3D& p2 );
  //    -------------

/** @name Operations sur le 1er ensemble de lignes
 */
//@{
  /**
    Efface la ligne et met a jour l'image des multipoints
    la ligne n'est pas supprimee du tableau pour eviter
    de changer tous les numeros de ligne des multipoints.
    @param num   0 ou 1, ensemble de lignes 
    @param ligne numero de la ligne
   */
  void EffaceLigne( const multiligne& ligne);
  //   -----------

  /**
    Ajoute la ligne dans l'ensemble 1 et met a jour l'image des multipoints
    @param ligne   ligne a ajouter
    @param num     numero de l'ensemble de lignes auquel on l'ajoute
   */
  void AjouteLigne( int num, const LigneCrest& ligne_crest);
  //   -----------

  /**
    longueur de la ligne entre les points numeros pos1 et pos2
   */
  float LongueurLigne( const multiligne& ligne, int pos1, int pos2);
  //   ------------- 

  /**
    Ajoute a ligne_crest
    la partie de la ligne1 complementaire au segment [pos11,pos12],
    en incluant pos12 et en partant de l'extremite.
    @param pos11 est une extremite de ligne1
   */
  void  AjouteDebutLigne( int num, LigneCrest& ligne_crest, 
  //    -------------
			  const multiligne& ligne1, int pos11, int pos12);

  /**
    Ajoute a ligne_crest
    la partie de la ligne2 complementaire au segment [pos21,pos22],
    en partant de pos22.
    @param pos21 est une extremite de ligne2
   */
  void  AjouteFinLigne( int num, LigneCrest& ligne_crest, 
  //    -------------
			const multiligne& ligne2, int pos21, int pos22 );


  /**
    Ajoute a ligne_crest
    la partie de la ligne2 correspondant au segment [debut,fin],
    en partant de debut.
   */
  void  AjoutePartieLigne( int num, LigneCrest& ligne_crest, 
  //    -----------------
			const multiligne& ligne2, int debut, int fin );


  /**
    @return le barycentre de (p1,coeff) et (p2,1-coeff)
   */
  Point3D CombLineaire( const Point3D& p1, const Point3D& p2, float coeff);
  //      ------------

  /**
    Ajoute a la ligne ligne_crest
    un ensemble de point forme d'une combinaison lineaire
    des parties definies des lignes ligne1 et ligne2,
    avec un coefficient de ponderation sur la ligne1 qui varie
    lineairement entre coeff1 et coeff2
   */
  void AjouteCombLineaire( int num, LigneCrest& ligne_crest,
  //   ------------------
			   const multiligne& ligne1, int pos12, int pos11, 
			   float coeff1,
			   const multiligne& ligne2, int pos22, int pos21, 
			   float coeff2);
 

  /**
     Fusion de 2 parties connexes de lignes, met la ligne dans le deuxieme ensemble

     @param ligne1 numero de la ligne dans le 1er  ensemble de lignes.
     @param ligne2 numero de la ligne dans le 2eme ensemble de lignes.
     @param pos11  extremite de ligne1 se projetant en pos21 sur ligne2.
     @param pos12  point de ligne2 (pas une extremite) se projetant en pos22 sur ligne2.
     @param pos21
     @param pos22
     @param num    ensemble dans lequel on ajoute la nouvelle ligne.
   */
  void Fusionne( const multiligne& ligne1, int pos11, int pos12, 
  //   --------
		 const multiligne& ligne2, int pos21, int pos22,
		 int num);


//@}

public:

/** @name constructeur(s), destructeur 
 */
//@{
  /**
   {\em Constructor}
   @param lignes1 ensemble de lignes 1.
   @param lignes2 ensemble de lignes 2.
   @param lignes3 nouvelles portions de lignes cr��es.
   */
   MultiCrest( Crest* lignes1, Crest* lignes2, Crest* lignes3,
			   InrImage* image);

  ///
  ~MultiCrest();
//@}


  /**
    Cree des segments qui representent les liens entre lignes[0]
    et lignes[1]
   */
  void CreeLiens( float seuil);
  //   ---------


  /**
    Cree des segments qui representent les liens entre lignes[0]
    et lignes[1]
   */
  void CreeProjections( );
  //   ---------------

  /**
    Cree des segments qui representent les liens entre lignes[0]
    et lignes[1]
   */
  void CreeJonctions( );
  //   -------------


  /**
    Cree des segments qui representent les liens entre lignes[0]
    et lignes[1]
   */
  void CreeJonction(  int nouv_l, int l , int pos);
  //   ------------

  /**
    Reconnecte les 3 ensembles de lignes et met le r�sultat 
    dans lignes[0]
   */
  void CreeResultat( );
  //   ------------


  /**
    Projette les lignes de l'ensemble e1 sur les lignes des
    autres ensembles et met le resultat dans e3
   */
  void Projete( int e1, int e3);
  //   -------


  /**
     Combinaison des 2 ensembles de lignes
   */
  void CombineLignes( );
  //   -------------


}; // MultiCrest


#endif // MULTI_CREST_HPP
