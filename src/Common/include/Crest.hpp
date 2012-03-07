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
 * $Revision: 1.6 $
 * $Log: Crest.hpp,v $
 * Revision 1.6  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.5  2005/08/08 17:29:56  karl
 * few changes in Crest and inrimage
 *
 * Revision 1.4  2005/04/04 05:05:30  karl
 * Improving Skeletonization: better line connextion and avoiding some local loops
 *
 * Revision 1.3  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.2  2004/02/06 15:25:14  karl
 * bug not found, comme back to original saveVTK
 *
 * Revision 1.1.1.1  2003/08/14 07:16:03  karl
 * Source code
 *
 * Revision 1.2  2000/10/02 16:57:15  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:10:07  karl
 * Sources code
 *
 */

// Lecture de fichier .crest
// Classer Crest
// fichier Crest.hpp
//
// Karl KRISSIAN 
//
// Sophia Antipolis le 02-09-97
//

// Objectif de cet objet:
//   Pour les axes des vaisseaux
//   Lecture d'un fichier .crest dans une structure de donnees
//   Acces au nombre de lignes et au nombre de points par ligne
//   Lissage des lignes
//

#ifndef _CREST_HPP
#define _CREST_HPP

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#include "math1.hpp"
#include "TableauDyn.hpp"
#include "Coordonnees.hpp"
#include "Point3D.hpp"
#include "CommonConfigure.h"

#ifndef _WITHOUT_VTK_
class vtkPolyData;
class vtkPoints;
class vtkCellArray;
//#include "vtkPolyData.h"
#endif // _WITHOUT_VTK_

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/*.doc 

//----------------------------------------------------------------------
//
const int FIRST=0;

//
const int LAST=1;



//============================================================================
/**
 */
class LigneCrest  
//     ==========
{

public:

  ///
  int             nb_points;

  ///
  TableauDyn<int> liste_points; // position dans le tableau de points

  ///
   LigneCrest() { nb_points = 0; liste_points.VideTableau(); }

  ///
   LigneCrest( const LigneCrest& lignecrest)
  {
    nb_points = lignecrest.nb_points;
    liste_points = lignecrest.liste_points;
  }

  ///
  LigneCrest& operator=( const LigneCrest& lignecrest) 
  {
    nb_points = lignecrest.nb_points;
    liste_points = lignecrest.liste_points;
    return *this;
  }  

  ///
  LigneCrest& operator+=( int point)
  {
    liste_points+=point;
    nb_points++;
    return (*this);
  }

  ///
  void EmptyLine()
  { 
    nb_points = 0; 
    liste_points.VideTableau();
  }

};

//============================================================================



/**
  Gestion des lignes et des fichiers au format {\it crest}
 */
class COMMON_EXPORT Crest
//                  -----
{

public:

// Exceptions

  ///
  class BadLineNumber {

    int num_ligne;
  public:

    BadLineNumber( int l) {
     std::cout << "Exception: BadLineNumber, "<< l << std::endl;
    }
  };

  ///
  class BadPointNumber {};

protected:

/** @name ensemble de lignes
 */
//@{
   ///
//   int                    _nb_points;

   /// tableau des points de du fichier initial
   TableauDyn<Point3D>       _CREST_tab_points; 


   // au format *.crest
   char                _CREST_nom_image[200];

   // nombre de lignes
//   int                   _nb_lignes;  

   /// points par ligne   
   TableauDyn<LigneCrest>  _CREST_tab_lignes; 
//@}


/** @name lignes lissees
 */
//@{
   ///
   unsigned char                 _lissage_alloue;
   /// tableau des points apres lissage
   TableauDyn<Point3D>     _LISSE_tab_points; 
   /// points par ligne
   TableauDyn<LigneCrest>  _LISSE_tab_lignes;

   unsigned char                 _sauve_lissage;
//@}

  /** Criteres de connexion
      distance maximale entre deux etremites de lignes
      valeur maximale de la norme au carre de la somme des vecteurs
      tangents extremaux
  */
   float            _connexion_dist_max;

  ///
   float            _connexion_tangent_max;

private:

  ///
  unsigned char AlloueCrest();
  //      -----------

  ///
  void AlloueLissage();
  //   -------------

  ///
  void LibereCrest();
  //   -----------

  ///
  void LibereLissage();
  //   -------------

public:

  static LigneCrest _lignecrest_defaut;

  /** @name Constructeurs, ~*/
  //@{

  ///
   Crest( char* nom_fichier );  
  //           ----- 

  ///
   Crest( );  
  //           -----

  ///
  ~Crest();
  //          -----

  //@}


  ///
  int NbLignes() const
  //     ----------
  { 
    return _CREST_tab_lignes.NbElts(); 
  }

  ///
  int NbPoints()
  //     --------
  { 
    return _CREST_tab_points.NbElts();
    //_nb_points; 
  }

  ///
  LigneCrest& Ligne( int l) //throw (BadLineNumber)
  //          -----
  { 
     Si (l<0) Ou (l>=NbLignes()) Alors
       throw BadLineNumber( l );
     FinSi

     return _CREST_tab_lignes[l];
  }

  ///
  int NbPoints( int l) const  //throw (BadLineNumber)
  //     --------
  {
     Si l<0 Ou l>=NbLignes() Alors
       throw BadLineNumber(l);
     FinSi
     return _CREST_tab_lignes[l].nb_points;
  }

  ///
  // Set a constant radius for all points
  //
  void SetRadius( float r) 
  //   ---------
  {
    int n;
    Pour(n,0,NbPoints()-1)
      Point(n).SetRadius(r);
    FinPour
  }

  ///
  int NbLiens( int id_point)
  //     -------
  {
    return _CREST_tab_points[id_point].nb_liens;
  }

  ///
  int Longueur( int id_ligne)
  //     --------
  {
    return (_CREST_tab_lignes[id_ligne].nb_points-1);
  }

  ///
  Point3D& Point(int l, int n) const
  //       -----
  {
     return _CREST_tab_points[_CREST_tab_lignes[l].liste_points[n]];
  }

  ///
  Point3D& Point( int n) const
  //       -----
  {
     return _CREST_tab_points[n];
  }

  ///
  Point3D& PointLisse( int n) const
  //       ----------
  {
     return _LISSE_tab_points[n];
  }

  ///
  int NumPoint(int l, int n) const
  //     --------
  {
     return _CREST_tab_lignes[l].liste_points[n];
  }

  ///
  Point3D& PointLisse(int l, int n)
  //       ----------
  {
     return _LISSE_tab_points[_LISSE_tab_lignes[l].liste_points[n]];
  }

  /**
    Change les positions en fonction des coordonnees de l'image
  */
  void ResizeVoxel( float tx, float ty, float tz, float vx, float vy, float vz);
  //   -----------

  /** Lissage de chacune des lignes
     par minimisation de l'integrale de la norme de la derivee au carre
     avec regularisation
     @param  N      nombre d'iterations
     @param  alpha  parametre de vitesse d'evolution
     @param  beta   parametre de la regularisation
  */
  void LisseLignes( int N, float alpha, float beta);
  //   -----------


  /// Supprime les lignes inferieures ou egales a taille.
  void SupprimeBarbules( int taille);
  //   ----------------

  //
  unsigned char ReadJulio( const char* nom);
  //            ---------

  //
  unsigned char SaveJulio( const char* nom, unsigned char lissage=false);
  //            ---------

#ifndef _WITHOUT_VTK_
  //
  unsigned char ImportVTK( vtkPolyData* poly);
  //      ---------

  //
  unsigned char ReadVTK( const char* nom);
  //      -------

  // cast to vtkPolyData
  operator vtkPolyData* (void);

  void ToPolyData(vtkPolyData** vtk_lines,
		   vtkPoints** points,
		   vtkCellArray** lines);

  //
  unsigned char SaveVTK( const char* nom, unsigned char lissage=false);
  //      -------
#endif // _WITHOUT_VTK_

  //
  unsigned char SauveLissage( const char* nom);
  //      ------------
 
  ///
  unsigned char SauveSousImage( int x_min, int x_max, 
  //      --------------
			  int y_min, int y_max, 
			  int z_min, int z_max, char* nom);

  ///
  unsigned char Sauve( const char* nom, unsigned char lissage=false);
  //      -----

  ///
  unsigned char SauveWireFrame( int ligne, float voxel_size, char* nom);
  //      --------------


  ///
  unsigned char SaveVRML( const char* name, unsigned char lissage=false);
  //      --------

  ///
  unsigned char ReadVRML( const char* name);
  //      --------

  /**  
    Re-oriente la ligne numero l
   */
  void ReOrienteLigne( int l);

  ///
  void FixeCriteresConnexion(float dist, float tang)
  //   ---------------------
  {
    _connexion_dist_max    = dist;
    _connexion_tangent_max = tang;
  }

  ///
  unsigned char Proche(Point3D p1, Point3D p2);
  //      ------

  ///
  unsigned char Proche(Vect3D<float> v1, Vect3D<float> v2);
  //      ------


  /// Longueur d'une ligne
  double LongueurLigne( int ligne);
  //         -------------

  /// Abscisse curviligne d'un point
  double AbscisseCurv( int ligne, int point);
  //         ------------

  /* Position dans une ligne a partir d'une abscisse curviligne.
     return le numero du dernier point dont l'abscisse est inferieure a abscisse.
  */
  int  Position( int ligne, float abscisse, Point3D& pt);
  //      --------

  ///
  unsigned char ConnecteLigne(int ligne1, int ligne2, int e1, int e2);
  //      -------------

  ///
  int ConnecteLignes();
  //     --------------


  /// Supprime les points multiples
  int SupprimePointsMultiples();
  //     -----------------------

  /// Regroupe deux connectes a leurs extremites
  int RegroupeLignesConnectees( int l1, int l2);
  //     ------------------------

  ///
  void ComputeLinks();
  //   ------------

  ///
  int ConnecteJonction();
  //     ----------------

  /// probabilite minimal et probabilite maximal
  void ProbaMinMax( float* min, float* max);
  //   -----------

  /// rayon minimal et rayon maximal
  void RayonMinMax( float* min, float* max);
  //   -----------

  /// Suppression d'une ligne
  void SupprimeLigne( int l);
  //   -------------

  /// Efface tous les points de la ligne
  void VideLigne( int l);
  //   ---------

  /** 
      Ajout d'une ligne
      on suppose que tous les points sont deja dans le tableau de points
      return le numero de la ligne
   */
  int AjouteLigne( const LigneCrest& ligne);
  //     -----------

  /** 
      Ajout d'une ligne
      venant d'un autre ensemble de lignes
   */
  int AjouteLigne( const Crest& crest, int numligne);
  //     -----------


  /**
    Ajout d'un point au tableau des points
    _CREST_tab_points
    retourne le numero du point
   */
  int AddPoint( const Point3D& pt);
  //     --------

  /**
   Ajout d'un point
   */
  Crest& operator+=( const Point3D& pt);

  /**
   Ajout d'une ligne
   */
  Crest& operator+=( const LigneCrest& pt);

}; // Crest


#endif // _CREST_HPP
