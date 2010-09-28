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


#include "style.hpp"
#include "math1.hpp"

extern "C" {
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
}

//#include "chaine.hpp"
#include "inrimage.hpp"
#include "Coordonnees.hpp"
#include "Voxel.hpp"
#include "IsoLigne2.hpp"
#include "CreeCrest.hpp"
#include "GeneralGaussianFilter.h"
#include "CalculIsoLignes.hpp"
#include "Eigen.hpp"
#include "FloatMatrix.hpp"
#include "func_isoline.hpp"

#define macro_permute(a,b) temp=a; a=b; b=temp;
//#define macro_min(a,b) ((a)<(b)?(a):(b))
#define val_abs( x) (((x)>=0)?(x):-(x))
#define epsilon  1E-2

//static Chaine  ce_fichier = "IsoLigneMain.cpp";

extern char program[80];
extern unsigned char verbose;
extern unsigned char GB_debug;


//---------------------------------------------------------
static void SupprimeDoublons( CreeCrest* crest, float eps)
//            ----------------
{
    int            i,j;
    Point3D        p1,p2;
    Vect3D<double> v;
    float          dist;
 
 std::cout << "SupprimeDoublons\n";

  Pour( i, 0, crest->NbLignes()-1)
    Si crest->NbPoints(i) > 1 Alors
      p1 = crest->Point(i,0);
      Pour( j, 1, crest->NbPoints(i)-1)
        p2 = crest->Point(i,j);
        v.Init( p2.x-p1.x, p2.y-p1.y, p2.z-p1.z);

        dist = Norme(v);
        Si dist < eps Alors
  	 std::cout << "Norme(v) < eps :" << p2 << std::endl;
          crest->Ligne(i).liste_points.Supprime(j);
          crest->Ligne(i).nb_points--;
          j--;
        Sinon
          p1 = p2;
        FinSi
      FinPour
    FinSi
  FinPour

} // SupprimeDoublons()




//---------------------------------------------------------
/**
 Moyenne au centre de 8 voxels d'une image � partir du buffer courant
 */
static double MoyenneVoxel( InrImage* image, int x, int y, int z)
//              ------------
{

  
    double moy;

  Si (x == image->_tx - 1) Ou
     (y == image->_ty - 1) Ou
     (z == image->_tz - 1) 
  AlorsFait return (*image)(x,y,z);

  moy = 0;
 
  moy = (*image)(x  ,y  ,z  ) +
        (*image)(x+1,y  ,z  ) +
        (*image)(x  ,y+1,z  ) +
        (*image)(x+1,y+1,z  ) +
        (*image)(x  ,y  ,z+1) +
        (*image)(x+1,y  ,z+1) +
        (*image)(x  ,y+1,z+1) +
        (*image)(x+1,y+1,z+1) ;

  moy /= 8.0;

  return moy;

} // MoyenneVoxel()


//-------------------------------------------------------
CreeCrest* Func_IsoLine( InrImage* input, float Sigma, InrImage* image_masque, InrImage* image_resultat)
//     ----
{

  
    //Chaine           nom_fic_param;

    double           hessien[9];
    float            vap[3];
//    double          gradient[3];

    Vect3D<double>   vep[3];
    Vect3D<double>   grad;

    double           resultat;
    int           x,y,z;
    unsigned char          VapHessien = false;

    CalculIsoLignes* calcul_isolignes;

    //Chaine           nom_crest;

    FloatMatrix H(3,3);
    FloatMatrix vp(3,3);
    int   num_rot;

    InrImage*       image;
    CreeCrest*      crest_lignes;
    // Filtrage de l'image et de ses d�riv�es
    GeneralGaussianFilter* filtre;


    // conversion de l'image initiale en float
    image           = new InrImage( WT_FLOAT, 
				    "image_float.inr.gz", input);
    (*image) = (*input);

//  image_resultat->InitImage( 0.0);

    Si (image_masque->_tx != image->_tx) Ou 
       (image_masque->_ty != image->_ty) Ou 
       (image_masque->_tz != image->_tz) Alors
      printf("Erreur \t masque de dimensions differentes de l'image initiale\n");
      image_masque = NULL;
    FinSi 

  // Initialisation des images des derivees jusqu'a l'ordre 2
  Si verbose AlorsFait
    printf("Allocation des images lissees (image initiale et derivees a l'ordre 2)\n");

  // Calcul des images des derivees avec filtrage Gaussien

  filtre = new GeneralGaussianFilter( image);

  filtre->UtiliseImage(    false);
  filtre->UtiliseGradient( true);
  filtre->UtiliseHessien(  true);
  filtre->InitDerivees();
  filtre->InitFiltre( Sigma, MY_FILTRE_CONV);  
  Si image_masque != NULL AlorsFait filtre->FixeMasque(image_masque);
  filtre->CalculFiltres();

  // Calcul de la fonction (Resultat)
//  image_resultat->InitBuffer();
  //
 std::cout << "Creation des objets CreeCrest ...\n";
  crest_lignes  = new CreeCrest( image->_tx, image->_ty, image->_tz);

  calcul_isolignes = new CalculIsoLignes(MY_FILTRE_CONV,
                filtre,
                image,crest_lignes);


  Pour( z, 0, image->_tz - 1)
  Pour( y, 0, image->_ty - 1)
  Pour( x, 0, image->_tx - 1)

    Si (image_masque != NULL) Et ((*image_masque)(x,y,z)<=127) Alors
      //image_resultat->IncBuffer();
      continue;
    FinSi

    // Calcul des valeurs propres et vecteurs propres du Hessien

    resultat = 0;

   // On va faire une moyenne des d�riv�es au centre des 8 voxels voisins

    grad.x = MoyenneVoxel((*filtre)(IMx_sigma),x,y,z);
    grad.y = MoyenneVoxel((*filtre)(IMy_sigma),x,y,z);
    grad.z = MoyenneVoxel((*filtre)(IMz_sigma),x,y,z);

    grad.x = grad.x/ image->_size_x;
    grad.y = grad.y/ image->_size_y;
    grad.z = grad.z/ image->_size_z;

    Si filtre->_utilise_hessien Alors
      hessien[0] =               MoyenneVoxel((*filtre)(IMxx_sigma),x,y,z)
                                 /image->_size_x/image->_size_x;

      hessien[1] = hessien[3] =  MoyenneVoxel((*filtre)(IMxy_sigma),x,y,z)
                                 /image->_size_x/image->_size_y;

      hessien[2] = hessien[6] =  MoyenneVoxel((*filtre)(IMzx_sigma),x,y,z)
                                 /image->_size_x/image->_size_z;

      hessien[4] =               MoyenneVoxel((*filtre)(IMyy_sigma),x,y,z)
                                 /image->_size_y/image->_size_y;

      hessien[5] = hessien[7] =  MoyenneVoxel((*filtre)(IMzy_sigma),x,y,z)
                                 /image->_size_z/image->_size_y;

      hessien[8] =               MoyenneVoxel((*filtre)(IMzz_sigma),x,y,z)
                                 /image->_size_z/image->_size_z;

      // les valeurs propres sont class�e par ordre croissant dans 'vap'
      // par rapport � l'article de Sato:


      H[0][0] = hessien[0];
      H[1][0] = 
      H[0][1] = hessien[1];
      H[2][0] = 
      H[0][2] = hessien[2];
      H[1][1] = hessien[4];
      H[2][1] = 
      H[1][2] = hessien[5];
      H[2][2] = hessien[8];

      VapHessien = jacobi( H, 3, vap, vp, &num_rot );

      eigsrt_inc(vap, vp, 3);

      vep[0].Init( vp[0][0], vp[1][0], vp[2][0]);
      vep[1].Init( vp[0][1], vp[1][1], vp[2][1]);
      vep[2].Init( vp[0][2], vp[1][2], vp[2][2]);


    FinSi
      
    Si VapHessien Alors
        resultat = calcul_isolignes->GradZero( vep, vap, x,y,z);
    Sinon 
        resultat = 0;
    FinSi
    //image_resultat->FixeValeur(resultat);
    //image_resultat->IncBuffer();
  FinPour
  FinPour

    Si verbose Alors
      Si z > 0 Alors 
        printf("\b\b\b");
      Sinon
        printf("Calcul de la reponse : ");
      FinSi
      printf("%3d",z); 
      fflush(stdout);
    FinSi

  FinPour

  Si GB_debug AlorsFait fprintf(stderr,"MAJ nb points / voxel \n");

  if (image_resultat!=NULL) {
    // Mise a jour du nombre de points par voxel
    image_resultat->InitBuffer();
    
    Pour( z, 0, image->_tz - 1)
    Pour( y, 0, image->_ty - 1)
    Pour( x, 0, image->_tx - 1)
    
        resultat=crest_lignes->NbPointsVoxel( x, y, z);
        Si resultat > 0 Alors
            image_resultat->FixeValeur(resultat);
        Sinon
            image_resultat->FixeValeur(0);
        FinSi
        image_resultat->IncBuffer();
        
    FinPour
    FinPour
    FinPour
  } // endif 

  fprintf(stderr,"nb points %d \n",crest_lignes->NbPoints());

  Si GB_debug AlorsFait fprintf(stderr,"CreeLignes() \n");
  crest_lignes->CreeLignes();

  fprintf(stderr,"nb points %d \n",crest_lignes->NbPoints());
  Si GB_debug AlorsFait fprintf(stderr,"Supprime Doublons() \n");
  SupprimeDoublons( crest_lignes, 0.05);

  fprintf(stderr,"nb points %d \n",crest_lignes->NbPoints());
  Si GB_debug AlorsFait fprintf(stderr,"SauveSousImage() \n");
  crest_lignes->ResizeVoxel(image->TrX(), image->TrY(), image->TrZ(),
			  image->VoxSizeX(),image->VoxSizeY(),image->VoxSizeZ());

   //--- Liberation des objets
  delete filtre;
  delete image;
  delete calcul_isolignes;
  return crest_lignes;

} // end Func_IsoLine()




