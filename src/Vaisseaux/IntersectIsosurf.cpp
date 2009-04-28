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
 * $Log: IntersectIsosurf.cpp,v $
 * Revision 1.3  2005/11/16 14:03:10  karl
 * added LGPL license
 *
 * Revision 1.2  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:11:34  karl
 * Sources code
 *
 */

#include "IntersectIsosurf.hpp"

#define min(a,b) ((a)<(b)?(a):(b))

static Chaine     ce_fichier = "CalculIsoLignes.cpp";




//---------------------------------------------------------
EnLigne unsigned char  IntersectIsosurf :: PassageParZero( int& signe, 
//                                            --------------
							      double valeur)
{

  Si valeur > 1E-5 Alors 
    Si signe == 0 AlorsFait signe = 1;
    Si signe == -1 Alors
      return true;
    FinSi
  FinSi
  Si valeur < -1E-5 Alors 
    Si signe == 0 AlorsFait signe = -1;
    Si signe == 1 Alors
      return true;
    FinSi
  FinSi
  Si fabs(valeur) < 1E-5 Alors 
     return true;
  FinSi

  return false;

} // PassageParZero()





//---------------------------------------------------------
float IntersectIsosurf :: ZeroCrossing(  float* values1, float* values2,
//                                 ------------
						  int x, int y, int z)
{

  MethodeCourante("GradZero", ce_fichier);

  
    int          signe, zero_detecte, zero_face;
    int          i;
    int          nb_points=0;
    PtPosition  pts_trouves[16];
    PtPosition      pt;
    pt3DReel        p1,p2;
    int          sommet;
    int          som;


//  printf(" Debut GradZero\n");

  _x = x;
  _y = y;
  _z = z;

  zero_detecte = false;

  Si (x < image1->_tx - 1) Et
     (y < image1->_ty - 1) Et
     (z < image1->_tz - 1)
  Alors


    // Pour eviter de parcourir deux fois chaque face,
    // On associe a chaque voxel ces 3 premieres faces

    Pour( _face, 0, 2)

      zero_face = false;

      // Produits scalaires avec vec0
      signe = 0;
      Pour( sommet, 0, 3)
        // numero du sommet dans le voxel
        som = _voxel.NumSommet(_face,sommet);
        // produit scalaire (gradient, vecteur propre)
        val1[_face][sommet] = values1[som];
        Si PassageParZero( signe, val1[_face][sommet]) AlorsFait
            zero_face = true;
      FinPour // sommet

      Si zero_face Alors
        zero_face = false;
        // Produits scalaires avec vec1
        signe = 0;
        Pour( sommet, 0, 3)
          // numero du sommet dans le voxel
          som = _voxel.NumSommet(_face,sommet);
          // produit scalaire (gradient, vecteur propre)
          val2[_face][sommet] = values2[som];
          Si PassageParZero( signe, val2[_face][sommet]) AlorsFait
              zero_face = true;
        FinPour // sommet

      FinSi

      // On a detecte un zero sur une des faces
      Si zero_face Alors
	zero_detecte = true;

        iso_ligne->FixeValeursFace( _face, val1[_face], val2[_face] );
        try {
          nb_points = iso_ligne->PointsFace( _face, pts_trouves);
        }
        catch (ExceptionErreur e)
        {
        }
        catch (ExceptionWarning w)
        {
        }

        Pour( i, 0, nb_points-1)

          // Tester si le point est proche d'une arete
          // ou d'un sommet,
          // Si c'est le cas, r�-estimer le point ... pour trouver un autre point
          // proche mais plus pr�cis
          pt = pts_trouves[i];


          p1.Init( x+pt.x, y+pt.y, z+pt.z);
          p1.rayon = 1.0;
          p1.proba = 1.0; //FonctionVap( vap);
          crest_lignes ->AddPoint( x,y,z, p1); 
          crest_lignes2->AddPoint( x,y,z, p1); 

          SelonQue _face Vaut

  	    Valeur 0: 
              Si z>0 Alors
                crest_lignes ->AddPoint( x,y,z-1, p1); 
                crest_lignes2->AddPoint( x,y,z-1, p1); 
              FinSi
	    FinValeur

  	    Valeur 1: 
              Si y>0 Alors
                crest_lignes->AddPoint( x,y-1,z, p1);
                crest_lignes2->AddPoint( x,y-1,z, p1);
              FinSi
	    FinValeur

  	    Valeur 2: 
              Si x>0 Alors
                crest_lignes->AddPoint( x-1,y,z, p1);
                crest_lignes2->AddPoint( x-1,y,z, p1);
              FinSi
	    FinValeur

          FinSelonQue

        FinPour

      FinSi

    FinPour // _face

  FinSi
 
  Si zero_detecte Alors

    nb_points = crest_lignes->NbPointsVoxel( x, y, z);
    FinMethode();
    return nb_points;

  Sinon

    FinMethode();
    return -3;
  FinSi

  FinMethode();
  return -4;

} // ZeroCrossing()
