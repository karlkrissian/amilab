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
 * $Log: CalculIsoLignes.hpp,v $
 * Revision 1.4  2005/11/16 14:03:10  karl
 * added LGPL license
 *
 * Revision 1.3  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.2  2004/02/05 16:15:27  karl
 * some commented lines removed
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:11:38  karl
 * Sources code
 *
 */


#ifndef CALCUL_ISO_LIGNES_HPP
#define CALCUL_ISO_LIGNES_HPP


#include "style.hpp"

extern "C" {
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
}

#include "Coordonnees.hpp"
#include "Voxel.hpp"
#include "IsoLigne2.hpp"
#include "CreeCrest.hpp"
#include "GeneralGaussianFilter.h"

#include "FloatMatrix.hpp"


#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;

///
class CalculIsoLignes : public GestionErreurs
//     ---------------
{

  /// External Parameters
  ///
  int          type_filtre;
  ///
  GeneralGaussianFilter* filtre;
  ///
  InrImage*       image;
  ///
  CreeCrest*      crest_lignes;
  ///
//  CreeCrest*      crest_lignes2;

  ///
  int _x;
  ///
  int _y;
  ///
  int _z;
  
  ///
  int _face;

  ///
  Voxel  _voxel;

  /// pour chaque face, valeurs1 aux 4 sommets et au centre
  double**        val1;
  /// pour chaque face, valeurs2 aux 4 sommets et au centre
  double**        val2;

  ///
  double hessien[9];

  //
  FloatMatrix H_3D;

  ///
  float  vap[3];

  ///
  double vec_propre[9];
  //
  FloatMatrix VP_3D;

  ///
  Vect3D<double>  gradient_voisins[8];
  ///
  Vect3D<double>  vep_face[3];
  ///
  Vect3D<double>  grad;

  ///
  IsoLigne2*      iso_ligne;

  // Deux extremites d'une arete
  ///
  Point_3D<int> arete_p1;
  ///
  Point_3D<int> arete_p2;
  ///
  double       coeff_arete;

protected:

  ///
  double MoyenneFace( InrImage* image );
  ///
  unsigned char CalculVepFace( Vect3D<double> *vep_face);
  ///
  unsigned char PassageParZero( int& signe, double valeur);


  ///
  double MoyenneArete(  InrImage* image );
  ///
  unsigned char CalculVepArete( Vect3D<double> *vep_arete );
  ///
  void    CalculeArete( PtPosition* pt );

  ///
  void    ReEvalue( PtPosition* pt);

public:

  ///
   CalculIsoLignes(  int          p_type_filtre,
                 GeneralGaussianFilter* p_filtre,
                 InrImage*       p_image,
                 CreeCrest*      p_crest_lignes):
    GestionErreurs("CalculIsoLignes"),H_3D(3,3), VP_3D(3,3)
  {
    
      int i;

    // set the parameters
    type_filtre=p_type_filtre;
    filtre = p_filtre;
    image  = p_image;
    crest_lignes  = p_crest_lignes;

    val1 = new double*[6];
    val2 = new double*[6];
    Pour(i,0,5)
      val1[i] = new double[5];
      val2[i] = new double[5];
    FinPour

    iso_ligne = new IsoLigne2((double**) val1, (double**) val2);
    iso_ligne->SetDebug( GB_debug);
  }

  ///
  ~ CalculIsoLignes()
  {
    
      int i;

    delete iso_ligne;
    Pour(i,0,5)
      delete []val1[i];
      delete []val2[i];
    FinPour
    delete []val1;
    delete []val2;
  }  


  ///
  float GradZero( Vect3D<double> *vep, float* vap,
             int x, int y, int z );

}; // CalculIsoLignes

#endif // CALCUL_ISO_LIGNES_HPP
