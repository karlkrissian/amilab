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
// Programme de courbes dans l'espace
// fichier interpol.hpp
// interpolation de courbes de B�zier et de Splines dans le plan
// Evry,		le 5/11/94  par Karl KRISSIAN

#ifndef HISTO_POINTS_HPP
#define HISTO_POINTS_HPP

// Fichiers � inclure
#include <stdio.h>
#include <math.h>
#include "DrawingArea.hpp"

// ========================================================================
Structure TPoint2D
//        =======
DebutStructure

  float x,y;

FinStructure // TPoint2D

// ========================================================================
typedef struct {

  int x,y;

} IntPoint;


// ========================================================================
// class Interpole
//

#define NBMAX 30


class Interpole : public DrawingArea
//     =========
{

protected:

  int     _nb_calculs;        // nombre de points calcules pour l'affichage de la courbe
  float       _xmin,_xmax,_ymin,_ymax;
  TPoint2D    _pt_repere[NBMAX]; // Liste des points dans les coordonnees du repere
  IntPoint   _pt[NBMAX];        // Liste des points dans les coordonnees de la fenetre
  int     _Coeff[NBMAX];
  int     _NbPoints;
  int     _PointADeplacer;
  int     _NbPoints_min;

  // fonction permettant de generer un evenement exterieur lorsque la fonction est modifiee
  void*  _callback;
  void*  _calldata;

private:

  void DessinRepere( );
  void CarreVide( int, int, int, int);

public: // BUG, mettre certaines m�thodes en priv� ...

  int     Selection;

  Constructeur Interpole( Widget AParent, char* ATitle, 
                          float xmin, float xmax, float ymin, float ymax );
  virtual Destructeur  Interpole();

  void SetCallBack( void* callback, void* calldata)
  {
    _callback = callback;
    _calldata = calldata;
  }

  // Actions a faire apres toute modification des points: deplacement, suppression ...
  void  FonctionModifiee();
  //    ----------------

  // return l'ordonnee du point d'abscisse x pour la fonction interpolee
  // A mettre en 'inline' ???
  unsigned char FonctionIntensite( float x);

  TPoint2D RepereUtilisateur( int, int);
  IntPoint   RepereFenetre( float, float);
  int  AddPoint ( int, IntPoint);
  int  SuppPoint( int);
  IntPoint*  DeterminePoint( IntPoint, int&);
  void    PosSouris( int&, int&);

  // met a jour (pour les splines) les coefficients si le point n
  // a ete modifie
  virtual void Modifie( int ) {}

  virtual void Paint( );
  virtual void ReDimensionne();

  virtual void InitWidget();

  // Cette fonction permet de calculer et donc d'initialiser
  // les coefficients de l'interpolation,
  // a partir de l'ensemble des points
  // (ex: bezier ou spline)
  virtual void CalculCoeff() {}
  
  // parametres (float t, int& x, int& y)
  // renvoie le point (x,y), dans les coordonnees de la fenetre,
  // correspondant a l'abscisse curviligne t
  virtual void Calcul( float , int& , int& ) { }

  virtual void Boutton_Presse();
  virtual void Boutton_Relache();
  virtual void DeplaceSourisBout1();

  virtual void Boutton2_Presse(); 
  virtual void Boutton2_Relache();

  virtual void Boutton3_Presse(); 
  virtual void Boutton3_Relache();


}; // Interpole
 

// =======================================================================
// class InterpoleLigne
//

class InterpoleLigne : public Interpole
//     ==============
{

public:

  Constructeur InterpoleLigne( Widget AParent, char* ATitle, 
                          float xmin, float xmax, float ymin, float ymax ):
               Interpole(AParent, ATitle, xmin, xmax, ymin, ymax) {}

  void CalculCoeff();
  void Calcul( float t, int& x, int& y);

}; // InterpoleLigne


#endif // HISTO_POINTS_HPP
