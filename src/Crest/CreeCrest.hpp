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
 * $Log: CreeCrest.hpp,v $
 * Revision 1.3  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.2  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:08  karl
 * Sources code
 *
 */
//
// Fichier CreeCrest.hpp
//
// Creation d'un fichier crest : centre estim� des vaisseaux
// A partir d'un ensemble de points par voxel
//

#ifndef CREE_CREST_HPP
#define CREE_CREST_HPP

#include "style.hpp"
#include "inrimage.hpp"
#include "TableauDyn.hpp"
#include "Crest.hpp"
#include "Coordonnees.hpp"
#include "Voisins27.hpp"

#define NB_LISTES_MAX 1E9

#define NB_LIGNES_MAX 1E9

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/*.doc /u/broca/0/kkrissia/Sources/Prog/Math/include/Coordonnees.doc 

static TableauDyn<Voisin27> t;

typedef 
/**
 @name pt3DReel
 point 3D r�l
 */
class pt3DReel : public Point_3D<float>
{

public:

  float rayon;
  float proba;

   pt3DReel() : Point_3D<float>(), rayon(1.0), proba(0.0) {}

} pt3DReel;



typedef 
/**
 @name tab_points
 tableau de points 3D R�ls
 */
TableauDyn<pt3DReel> tab_points;


//===========================================================
/**
  Cretion d'un ensemble de lignes dans un fichier '.crest' \\
  a partir d'un ensemble de points par voxel
 */
class CreeCrest : public Crest
//     ---------
{

protected:

  /// Tableau de listes de points
  TableauDyn< tab_points > _tab_liste_points;
 
  /**
    Image d'entier qui sont la position dans le tableau \\
    {\it _tab_liste_points} de la liste de points associ� �chaque voxel
   */
  InrImage*           _image;

  /**
    Image d'entier qui sont, pour chaque voxel, le numero de la ligne a\\
    laquelle il appartient si elle existe, sinon NB_LIGNES_MAX
   */
  InrImage*           _image_lignes;

  /**
   Recherche du voisinage du voxel v1 qui a en commun la face, l'arrete ou le sommet
   par lequel passe p1
   */
  TableauDyn<Voisin27>  Voisinage( pt3DReel p1, Point_3D<int> v1 );


  ///
  unsigned char  Voisinage_p1( TableauDyn<Voisin27> voisins,
  //                              ------------
                     pt3DReel               p1, 
                 Point_3D<int>       v1, 
                     pt3DReel&              pt_proche,
                 pt3DReel&              pt_suivant,
                 Point_3D<int>&      voxel_suivant  );


  /**
    Prolonge la ligne par le point donn� dans le voisinage du voxel \\
    tant que possible et ajoute les points trouv� dans la ligne \\
    en partant de l'extr�it�
   */
  void ProlongeDebut( LigneCrest& ligne, pt3DReel p1, Point_3D<int> v1 );

  /**
    Prolonge la ligne par le point donn� dans le voisinage du voxel \\
    tant que possible et ajoute les points trouv� dans la ligne \\
    en partant de p1 jusqu'�l'extr�it�
   */
  void ProlongeFin( LigneCrest& ligne, pt3DReel p1, Point_3D<int> v1 );


  /**
    Connecte les lignes reliees par un voxel ayant plus de 2 points
  */
  void ConnecteLignes();
 

  /**  
    Re-oriente la ligne numero l
   */
//  void ReOrienteLigne( int l);

  /**
    Regroupe deux lignes, ces lignes doivent avoir des extremites communes
    Met a jour l'image {\em _image_lignes }
   */
  void RegroupeLignes( int l1, int l2);

public:

/** @name constructeur(s), destructeur 
 */
//@{
  /**
   {\em Constructor}
   @param tx dimension en X de l'image
   @param ty dimension en Y de l'image
   @param tz dimension en Z de l'image
   */
   CreeCrest( int tx, int ty, int tz);

  ///
  ~CreeCrest();
//@}

  /**
    Ajoute au voxel (x,y,z) le point pt
   */
  void AddPoint( int x, int y, int z, pt3DReel pt );
  

  /**
    Nombre de points detecte au voxel (x,y,z)
   */
  int NbPointsVoxel( int x, int y, int z)
  {
    Si (*_image)(x,y,z)==NB_LISTES_MAX Alors
      return 0;
    Sinon
       return _tab_liste_points[(int)(*_image)(x,y,z)].NbElts();
    FinSi
  }  

  /**
    Tableau des points associ� au voxel (x,y,z)
   */
  tab_points&  ListePoints( int x, int y, int z);


  /**
    Cree les lignes pour les voxels ayant 2 points
   */
  void  CreeLignes();
  //    ----------

  /**
    Recherche la ligne passant par un ensemble \\
    de voxels ayant exactement 2 points de passage par z�o \\
    et ajoute cette ligne dans la structure Crest \\
    en enlevant des voxels les points lui appartenant.
    @param voxel position du voxel dans l'image
    @param p1,p2 les 2 points d�ect� pour ce voxel
  */
  void RechercheLigne( Point_3D<int> voxel, pt3DReel& p1, pt3DReel& p2);
  //   --------------


  /**
    Ajoute un segment constitu�des points p1 et p2
   */
  void  AjouteSegment( pt3DReel& p1, pt3DReel& p2 );
  //    -------------

  /**
    Ajoute une ligne constitu� des points p1 et p2
   */
  void  AjouteLigne( pt3DReel& p1, pt3DReel& p2, Point_3D<int> voxel);
  //    -----------


}; // CreeCrest


#endif // CREE_CREST_HPP
