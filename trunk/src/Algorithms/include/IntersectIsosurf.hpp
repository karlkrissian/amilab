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
 * $Log: IntersectIsosurf.hpp,v $
 * Revision 1.2  2005/11/16 14:03:10  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:11:38  karl
 * Sources code
 *
 */


#ifndef INTERSECT_ISOSURF_HPP
#define INTERSECT_ISOSURF_HPP


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


extern unsigned char    GB_debug;
extern InrImage*  image1;
extern CreeCrest* crest_lignes;
extern CreeCrest* crest_lignes2;

///
class IntersectIsosurf : public GestionErreurs
//     ---------------
{

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
  unsigned char PassageParZero( int& signe, double valeur);

public:

  ///
   IntersectIsosurf(): GestionErreurs("IntersectIsosurf")
  {
    
      int i;

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
  ~ IntersectIsosurf()
  {
    
      int i;

    delete iso_ligne;
    Pour(i,0,5)
      delete val1[i];
      delete val2[i];
    FinPour
    delete val1;
    delete val2;
  }  


  float ZeroCrossing(  float* val1, float* val2,
		      int x, int y, int z );

}; // IntersectIsosurf

#endif // INTERSECT_ISOSURF_HPP
