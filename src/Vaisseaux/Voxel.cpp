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
//
// fichier Voxel.cpp
//
// Karl Krissian Sophia Antipolis le 25-08-98
//


#include "style.hpp"
#include "Voxel.hpp"


//============================================================================
//  MEMBRES PRIVES
//============================================================================

//-----------------------------------------------------------------------------------------
// 
PtPosition Voxel :: Face2Voxel( int num_face, PtFace pt0 )
//
{

  
    PtPosition pt;

  pt.x = PosX(num_face,0) +  pt0.x * (PosX(num_face,1) - PosX(num_face,0)) +
                             pt0.y * (PosX(num_face,3) - PosX(num_face,0));
  pt.y = PosY(num_face,0) +  pt0.x * (PosY(num_face,1) - PosY(num_face,0)) +
                             pt0.y * (PosY(num_face,3) - PosY(num_face,0));
  pt.z = PosZ(num_face,0) +  pt0.x * (PosZ(num_face,1) - PosZ(num_face,0)) +
                             pt0.y * (PosZ(num_face,3) - PosZ(num_face,0));

  return pt;

} // Face2Voxel()
  

//-----------------------------------------------------------------------------------------
// Initialisation des 4 positions des sommets de la face
void Voxel :: InitFace( int num, int s1, int s2, int s3, int s4)
//
{

  _face[num][0] = s1;
  _face[num][1] = s2;
  _face[num][2] = s3;
  _face[num][3] = s4;

} // InitFace()
  

//-----------------------------------------------------------------------------------------
//
float Voxel :: Distance( PtPosition& pt1, PtPosition& pt2)
//
{

  return sqrt( (pt1.x-pt2.x)*(pt1.x-pt2.x) +
                 (pt1.y-pt2.y)*(pt1.y-pt2.y) +
                 (pt1.z-pt2.z)*(pt1.z-pt2.z) 
               );

} // Distance()


//-----------------------------------------------------------------------------------------
/**
  Distance euclidienne entre les 2 points
 */
float Voxel :: Distance( PtFace& pt1, PtFace& pt2)
//
{

  return sqrt( (pt1.x-pt2.x)*(pt1.x-pt2.x) +
                 (pt1.y-pt2.y)*(pt1.y-pt2.y) 
               );

} // Distance()


//-----------------------------------------------------------------------------------------
/**
  Revoie le num�ro du sommet associ� au point pt
  ou -1 si pt n'est pas un sommet
 */
int Voxel :: DetermineSommet( PtFace& pt)
//
{

  Si fabs(pt.x) < EPSILON Alors
    Si fabs(pt.y) < EPSILON Alors
      return 0;
    Autrement
    Si fabs(pt.y-1) < EPSILON Alors
      return 3;
    Sinon
      return -1;
    FinSi
  Autrement
  Si fabs(pt.x-1) < EPSILON Alors
    Si fabs(pt.y) < EPSILON Alors
      return 1;
    Autrement
    Si fabs(pt.y-1) < EPSILON Alors
      return 2;
    Sinon
      return -1;
    FinSi
  Sinon
    return -1;
  FinSi

} // DetermineSommet()




    

//============================================================================
//  MEMBRES PUBLICS
//============================================================================


//-----------------------------------------------------------------------------------------
/** <b> Constructeur </b>
 */
Voxel :: Constructeur Voxel( ) 
  : GestionErreurs(Chaine("Voxel"))
//
{

  // Initialisation des 6 faces
  InitFace(0,0,1,3,2);
  InitFace(1,0,1,5,4);
  InitFace(2,0,2,6,4);
  InitFace(3,4,5,7,6);
  InitFace(4,2,3,7,6);
  InitFace(5,1,3,7,5);

  _coord_sommet[0].x = 0;
  _coord_sommet[0].y = 0;

  _coord_sommet[1].x = 1;
  _coord_sommet[1].y = 0;

  _coord_sommet[2].x = 1;
  _coord_sommet[2].y = 1;

  _coord_sommet[3].x = 0;
  _coord_sommet[3].y = 1;

}


//-----------------------------------------------------------------------------------------
/** <b> Destructeur </b>
 */
Voxel :: Destructeur Voxel()
//
{

}

