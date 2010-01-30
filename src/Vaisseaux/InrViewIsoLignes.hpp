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
// Projet Epidaure
// Fichier InrView.hpp
//
// Karl KRISSIAN, Florence Guirardel 
//
//  Sophia, le 16-07-98
//
 

#ifndef INRVIEW_ISOLIGNES_HPP
#define INRVIEW_ISOLIGNES_HPP

#include "style.hpp"
#include "DessinImage.hpp"
#include "CompareImage.hpp"
#include <iostream.h>

//extern ostream         cout;

//============================================================================
/**
 */
class InrView : public DessinImage
//     -------
{

public:
  
  ///
   InrView( Widget AParent, char* ATitle, char* nom_image, DessinParam* param) :
  //           -------
       DessinImage( AParent, ATitle, nom_image, param, USE_PARENT_WINDOW) 
  {
  }

  ///
  void FermerFenetre()
  //   -------------
  {
    int answer = wxMessageBox("Quit program?", "Confirm",
                            wxYES_NO | wxCANCEL, NULL);
    if (answer == wxYES) this->Close();

  } 

  ///
  void Comparaisons_Redessine( )
  //   ----------------------
  {

  
    int i; 

    for(  i = 0 ;  i < _compare_max ;  i++ Faire
      Si _tab_compare_image[i] != NULL Alors
    //((CompareImage*) _tab_compare_image[i])->
        _MAJ_intensite = true;
        ((CompareImage*) _tab_compare_image[i])->Paint();
      FinSi
    } // end for // i 

  } // Comparaisons_Redessine()


  ///
  void Boutton3_Presse ()
  //   ---------------
  {

    
        int     im_x, im_y, im_z;
        int     trouve;
        int     i;
        tab_points liste_points;

    CurseurToImage(&im_x, &im_y, &im_z, &trouve);

    Si trouve != -1 Alors

      printf( " \n (%d %d %d) : nb_points = %d \n", 
	      im_x, im_y, im_z, 
	      crest_lignes2->NbPointsVoxel( im_x, im_y, im_z));

      liste_points = crest_lignes2->ListePoints( im_x, im_y, im_z);

      Pour( i, 0, liste_points.NbElts()-1)
        cout << " Point " << i << "\t" << liste_points[i] << "\n";
//        printf(" Point %d (%f %f %f) \n", i, liste_points[i]);
      FinPour

    FinSi

    DessinImage::Boutton3_Presse();

  }

}; // InrView


#endif // INRVIEW_ISOLIGNES_HPP
