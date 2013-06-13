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
 * $Revision: 1.8 $
 * $Log: StructureTensor.c,v $
 * Revision 1.8  2006/02/21 18:26:17  karl
 * many changes
 *
 * Revision 1.7  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.6  2005/02/17 00:46:33  karl
 * remove some warning + matrix support in AMILab
 *
 * Revision 1.5  2004/10/09 10:40:16  karl
 * last modifs
 *
 * Revision 1.4  2004/09/16 14:39:13  karl
 * Hessian based Structure Tensor
 *
 * Revision 1.3  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.2  2004/04/30 20:08:24  karl
 * several modif: set private colormap, get distmap in LevelSets, ...
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.5  2001/03/16 23:55:22  karl
 * *** empty log message ***
 ***************************************************************************/


#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "VarContexts.hpp"
#include "style.hpp"
#include "math1.hpp"
#include "inrimage.hpp"
#include "GeneralGaussianFilter.h"
#include "FloatMatrix.hpp"
#include "Eigen.hpp"
//#include "fonctions.h"
#include "Timing.hpp"
#include <omp.h>

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;
COMMON_VAR_IMPORT unsigned char GB_verbose;


// not thread-safe !!!
static InrImage* tenseur_xx;
static InrImage* tenseur_xy;
static InrImage* tenseur_xz;
static InrImage* tenseur_yy;
static InrImage* tenseur_yz;
static InrImage* tenseur_zz;


// Filtrage de l'image et de ses d�riv�es
static int type_filtre;
static int dimension;


//----------------------------------------------------------------------
void Lissage( InrImage* image, float sigma, InrImage* mask)
//
{
  GeneralGaussianFilter::ptr filtre;

  filtre = GeneralGaussianFilter::New(image, dimension);
//  filtre->SetScaleUnit(PIXEL_SPACE);
  filtre->Utilise_Image(   true);
  filtre->UtiliseGradient( false);
  filtre->InitDerivees();
  filtre->SetSupportSize(4);

  filtre->GammaNormalise(  true);

  filtre->InitFiltre( sigma, type_filtre);
  filtre->CalculFiltres( mask);
  (*image) = (*(*filtre)(IM_sigma));

} // Lissage()


//---------------------------------------------------------
// Func_StructureTensor
//---------------------------------------------------------

unsigned char Func_StructureTensor2D( InrImage* image_initiale, 
//      ----------------------
                const char* varname,
                float Sigma1, float Sigma2,
                InrImage* mask)
{
    FloatMatrix     matrice(2,2);
//    FloatMatrix     matriceinit(2,2);
    float           vap[2];
    FloatMatrix     vec_propre(2,2);
    int          x,y;
    unsigned char         Diagonale = false;
//    InrImage*       im2 = NULL;
//    double          temp,ps1,ps2;
    Vect3D<double>  grad;
    int             niter;
    InrImage*                   image;
    InrImage::ptr                   image_vep1;
    InrImage::ptr                   image_vep2;
    InrImage::ptr                   image_vap1;
    InrImage::ptr                   image_vap2;
    GeneralGaussianFilter::ptr  filtre;
  std::string                 resname;

  type_filtre = MY_FILTRE_CONV;
  Si (image_initiale->_format == WT_FLOAT) Alors
    image = image_initiale;
  Sinon
    // conversion de l'image initiale en float
    image    = new InrImage( WT_FLOAT, "image_reel.inr.gz", image_initiale);
    (*image) = (*image_initiale);
  FinSi

  dimension = MODE_2D;

  tenseur_xx = new InrImage( WT_FLOAT, "Tenseur_xx", image);
  tenseur_xy = new InrImage( WT_FLOAT, "Tenseur_xy", image);
  tenseur_yy = new InrImage( WT_FLOAT, "Tenseur_yy", image);


  image_vep1 =  InrImage::ptr(new InrImage( WT_FLOAT, 3,
                  "ST-vep1.inr.gz", image));
  image_vep2 =  InrImage::ptr(new InrImage( WT_FLOAT, 3,
                  "ST-vep2.inr.gz", image));

  image_vap1 =  InrImage::ptr(new InrImage( WT_FLOAT, 
                  "ST-vap1.inr.gz", image));
  image_vap2 =  InrImage::ptr(new InrImage( WT_FLOAT, 
                  "ST-vap2.inr.gz", image));

    // Initialisation des images des d�riv�es 
    filtre = GeneralGaussianFilter::New(image, dimension);
    filtre->Utilise_Image(   false);
    filtre->UtiliseGradient( true);
    filtre->InitDerivees();
    filtre->GammaNormalise( false);
    filtre->InitFiltre( Sigma1, type_filtre);  
    filtre->CalculFiltres( );
  
    // Calcul des coefficients du tenseur non liss�
  
    tenseur_xx->InitBuffer();
    tenseur_xy->InitBuffer();
    tenseur_yy->InitBuffer();
  
    Pour( y, 0, image->_ty - 1)
    Pour( x, 0, image->_tx - 1)
  
      grad = filtre->Gradient(x,y,0);
      tenseur_xx->FixeValeur( grad.x*grad.x);
      tenseur_xy->FixeValeur( grad.x*grad.y);
      tenseur_yy->FixeValeur( grad.y*grad.y);
  
      tenseur_xx->IncBuffer();
      tenseur_xy->IncBuffer();
      tenseur_yy->IncBuffer();
  
    FinPour
    FinPour
    filtre.reset(); // freeing memory of filter
  
  // Lissage du tenseur
  // Pas optimise...
  Lissage( tenseur_xx, Sigma2, NULL);
  Lissage( tenseur_xy, Sigma2, NULL);
  Lissage( tenseur_yy, Sigma2, NULL);

  tenseur_xx->InitBuffer();
  tenseur_xy->InitBuffer();
  tenseur_yy->InitBuffer();
  image_vep1->InitBuffer();  
  image_vep2->InitBuffer();  
  image_vap1->InitBuffer();  
  image_vap2->InitBuffer();  


  Pour( y, 0, image->_ty - 1)
  Pour( x, 0, image->_tx - 1)

    matrice[0][0] = tenseur_xx->ValeurBuffer();
    matrice[0][1] = 
    matrice[1][0] = tenseur_xy->ValeurBuffer();
    matrice[1][1] = tenseur_yy->ValeurBuffer();

    // Calcul des vep et des vap dans les images associ�es
    Diagonale = jacobi( matrice, 2, 
            vap, 
                vec_propre, 
            &niter );

    Si Diagonale Alors


      eigsrt(vap,  vec_propre, 2);

      image_vep1->VectFixeValeurs( vec_propre[0][0], 
                   vec_propre[1][0], 
                   0);

      image_vep2->VectFixeValeurs( vec_propre[0][1], 
                   vec_propre[1][1], 
                   0);

      image_vap1->FixeValeur( vap[0]);
      image_vap2->FixeValeur( vap[1]);
    Sinon
      image_vep1->VectFixeValeurs( 0.0, 0.0, 0.0);
      image_vep2->VectFixeValeurs( 0.0, 0.0, 0.0);
     
      image_vap1->FixeValeur( 0.0);
      image_vap2->FixeValeur( 0.0);
    FinSi

    tenseur_xx->IncBuffer();
    tenseur_xy->IncBuffer();
    tenseur_yy->IncBuffer();
    image_vep1->IncBuffer();  
    image_vep2->IncBuffer();  
    image_vap1->IncBuffer();  
    image_vap2->IncBuffer();  

  FinPour
  FinPour

  BasicVariable::ptr var;

  resname = (boost::format("%s_STvep1") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep1);

  resname = (boost::format("%s_STvep2") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep2);

  resname = (boost::format("%s_STvap1") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap1);

  resname = (boost::format("%s_STvap2") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap2);

  delete tenseur_xx;
  delete tenseur_xy;
  delete tenseur_yy;

  if (image!=image_initiale) delete image;

  return true;

} // end Func_StructureTensor2D() 


//---------------------------------------------------------
// Func_StructureTensor
//---------------------------------------------------------

unsigned char Func_StructureTensor( InrImage* image_initiale, 
//      --------------------
                  const char* varname,
                  float Sigma1, float Sigma2,
                  InrImage* mask)
{

  Si image_initiale->_tz == 1 AlorsFait
    return Func_StructureTensor2D(image_initiale,varname,
                  Sigma1,Sigma2, mask);


  
    FloatMatrix     matrice(3,3);
//    FloatMatrix     matriceinit(3,3);
    float           vap[3];
    FloatMatrix     vec_propre(3,3);
    int          x,y,z;
    unsigned char         Diagonale = false;
//    InrImage*       im2 = NULL;
//    double          temp,ps1,ps2;
    Vect3D<double>  grad;
    int             niter;
    InrImage*       image;

    InrImage::ptr       image_vep1;
    InrImage::ptr       image_vep2;
    InrImage::ptr       image_vep3;

    InrImage::ptr       image_vap1;
    InrImage::ptr       image_vap2;
    InrImage::ptr       image_vap3;
    GeneralGaussianFilter::ptr filtre;
  std::string     resname;
//    int             i;

  type_filtre = MY_FILTRE_CONV;
  Si (image_initiale->_format == WT_FLOAT) Alors
    image = image_initiale;
  Sinon
    // conversion de l'image initiale en float
    image    = new InrImage( WT_FLOAT, "image_reel.inr.gz", image_initiale);
    (*image) = (*image_initiale);
  FinSi

  dimension = MODE_3D;

  tenseur_xx = new InrImage( WT_FLOAT, "Tenseur_xx", image);
  tenseur_xy = new InrImage( WT_FLOAT, "Tenseur_xy", image);
  tenseur_xz = new InrImage( WT_FLOAT, "Tenseur_xz", image);
  tenseur_yy = new InrImage( WT_FLOAT, "Tenseur_yy", image);
  tenseur_yz = new InrImage( WT_FLOAT, "Tenseur_yz", image);
  tenseur_zz = new InrImage( WT_FLOAT, "Tenseur_zz", image);


  image_vep1 = InrImage::ptr( new InrImage( WT_FLOAT, 3,
                  "ST-vep1.inr.gz", image));
  image_vep2 = InrImage::ptr( new InrImage( WT_FLOAT, 3,
                  "ST-vep2.inr.gz", image));
  image_vep3 = InrImage::ptr( new InrImage( WT_FLOAT, 3,
                  "ST-vep3.inr.gz", image));

  image_vap1 = InrImage::ptr( new InrImage( WT_FLOAT, 
                  "ST-vap1.inr.gz", image));
  image_vap2 = InrImage::ptr( new InrImage( WT_FLOAT, 
                  "ST-vap2.inr.gz", image));
  image_vap3 = InrImage::ptr( new InrImage( WT_FLOAT, 
                  "ST-vap3.inr.gz", image));


  // Initialisation des images des d�riv�es 
  filtre = GeneralGaussianFilter::ptr(new GeneralGaussianFilter(image, dimension));
//  filtre->SetScaleUnit(PIXEL_SPACE);
  filtre->Utilise_Image(   false);
  filtre->UtiliseGradient( true);
  filtre->InitDerivees();
  filtre->GammaNormalise( true);
  filtre->SetSupportSize(5);
  filtre->InitFiltre( Sigma1, type_filtre);  
  filtre->CalculFiltres( );

  // Calcul des coefficients du tenseur non liss�

  tenseur_xx->InitBuffer();
  tenseur_xy->InitBuffer();
  tenseur_xz->InitBuffer();
  tenseur_yy->InitBuffer();
  tenseur_yz->InitBuffer();
  tenseur_zz->InitBuffer();


  Pour( z, 0, image->_tz - 1)
  Pour( y, 0, image->_ty - 1)
  Pour( x, 0, image->_tx - 1)

    grad = filtre->Gradient(x,y,z);
    tenseur_xx->FixeValeur( grad.x*grad.x);
    tenseur_xy->FixeValeur( grad.x*grad.y);
    tenseur_xz->FixeValeur( grad.x*grad.z);
    tenseur_yy->FixeValeur( grad.y*grad.y);
    tenseur_yz->FixeValeur( grad.y*grad.z);
    tenseur_zz->FixeValeur( grad.z*grad.z);

    tenseur_xx->IncBuffer();
    tenseur_xy->IncBuffer();
    tenseur_xz->IncBuffer();
    tenseur_yy->IncBuffer();
    tenseur_yz->IncBuffer();
    tenseur_zz->IncBuffer();

  FinPour
  FinPour
  FinPour

  filtre.reset();


  // Lissage du tenseur
  // Pas optimise...
printf("smoothing xx\n");
  Lissage( tenseur_xx, Sigma2, NULL);
printf("smoothing xy\n");
  Lissage( tenseur_xy, Sigma2, NULL);
printf("smoothing xz\n");
  Lissage( tenseur_xz, Sigma2, NULL);
printf("smoothing yy\n");
  Lissage( tenseur_yy, Sigma2, NULL);
printf("smoothing yz\n");
  Lissage( tenseur_yz, Sigma2, NULL);
printf("smoothing zz\n");
  Lissage( tenseur_zz, Sigma2, NULL);

  image_vep1->InitImage( 0.0, 0.0, 0.0);
  image_vep2->InitImage( 0.0, 0.0, 0.0);
  image_vep3->InitImage( 0.0, 0.0, 0.0);
     
  image_vap1->InitImage( 0.0);
  image_vap2->InitImage( 0.0);
  image_vap3->InitImage( 0.0);

  tenseur_xx->InitBuffer();
  tenseur_xy->InitBuffer();
  tenseur_xz->InitBuffer();
  tenseur_yy->InitBuffer();
  tenseur_yz->InitBuffer();
  tenseur_zz->InitBuffer();

  image_vep1->InitBuffer();  
  image_vep2->InitBuffer();  
  image_vep3->InitBuffer();  

  image_vap1->InitBuffer();  
  image_vap2->InitBuffer();  
  image_vap3->InitBuffer();  

  long int n=0;
  int prev_per=0;

  Pour( z, 0, image->_tz - 1)
  Pour( y, 0, image->_ty - 1)
  Pour( x, 0, image->_tx - 1)
    int per = (int)((100.0*n)/image->Size());
    if ((int)(per/10) != (int)(prev_per/10)) {
      printf("done %d %% \n",per);
      prev_per = per;
    }


    Si (mask==NULL) Ou (*mask)(x,y,z)>127 Alors

      matrice[0][0] = tenseur_xx->ValeurBuffer();
      matrice[0][1] = 
      matrice[1][0] = tenseur_xy->ValeurBuffer();
      matrice[0][2] =
      matrice[2][0] = tenseur_xz->ValeurBuffer();
      matrice[1][1] = tenseur_yy->ValeurBuffer();
      matrice[1][2] =
      matrice[2][1] = tenseur_yz->ValeurBuffer();
      matrice[2][2] = tenseur_zz->ValeurBuffer();

      // Calcul des vep et des vap dans les images associ�es

      Diagonale = jacobi( matrice, 3, 
              vap, 
              vec_propre, 
              &niter );

      Si Diagonale Alors


        eigsrt(vap,  vec_propre, 3);

        image_vep1->VectFixeValeurs( vec_propre[0][0], 
                     vec_propre[1][0], 
                     vec_propre[2][0]);

        image_vep2->VectFixeValeurs( vec_propre[0][1], 
                     vec_propre[1][1], 
                     vec_propre[2][1]);

        image_vep3->VectFixeValeurs( vec_propre[0][2], 
                     vec_propre[1][2], 
                     vec_propre[2][2]);
     
        image_vap1->FixeValeur( vap[0]);
        image_vap2->FixeValeur( vap[1]);
        image_vap3->FixeValeur( vap[2]);
      FinSi
    FinSi

    tenseur_xx->IncBuffer();
    tenseur_xy->IncBuffer();
    tenseur_xz->IncBuffer();
    tenseur_yy->IncBuffer();
    tenseur_yz->IncBuffer();
    tenseur_zz->IncBuffer();

    image_vep1->IncBuffer();  
    image_vep2->IncBuffer();  
    image_vep3->IncBuffer();  

    image_vap1->IncBuffer();  
    image_vap2->IncBuffer();  
    image_vap3->IncBuffer();  

    n++;

  FinPour
  FinPour
  FinPour

  resname = (boost::format("%s_STvep1") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep1);

  resname = (boost::format("%s_STvep2") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep2);

  resname = (boost::format("%s_STvep3") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vep3);

  resname = (boost::format("%s_STvap1") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap1);

  resname = (boost::format("%s_STvap2") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap2);

  resname = (boost::format("%s_STvap3") % varname).str();
  Vars.AddVar<InrImage>(resname,image_vap3);

  delete tenseur_xx;
  delete tenseur_xy;
  delete tenseur_xz;
  delete tenseur_yy;
  delete tenseur_yz;
  delete tenseur_zz;

  if (image!=image_initiale) delete image;

  return true;

} // end Func_StructureTensor() 



//---------------------------------------------------------
// Func_StructureTensorHessian
//
//
//  the mask in the filtering part  for the moment
//---------------------------------------------------------

unsigned char Func_StructureTensorHessian( InrImage* image_initiale, 
//      ---------------------------
                     const char* varname,
                     float sigma,
                     float beta,
                     InrImage* mask,
                     bool save_grad)
{

/* To do: 2D version
  Si image_initiale->_tz == 1 AlorsFait
    return Func_StructureTensorHessian2D(image_initiale,varname,
                     sigma,beta, mask);
*/

  
    FloatMatrix     matrice(3,3);
//    FloatMatrix     matriceinit(3,3);
    FloatMatrix     H_3D(3,3);
    float           vap[3];
    FloatMatrix     vec_propre(3,3);
    int          x,y,z;
    unsigned char         Diagonale = false;
    Vect3D<double>  grad;
    double          gradarray[3];
    int             niter;
    InrImage*       image;

    InrImage::ptr       image_vep1;
    InrImage::ptr       image_vep2;
    InrImage::ptr       image_vep3;

    InrImage::ptr       image_vap1;
    InrImage::ptr       image_vap2;
    InrImage::ptr       image_vap3;

    InrImage::ptr        image_grad;

    GeneralGaussianFilter::ptr filtre;
  std::string     resname;
    double          hessien[9];
    int             i,j,k;

  type_filtre = MY_FILTRE_CONV;
  Si (image_initiale->_format == WT_FLOAT) Alors
    image = image_initiale;
  Sinon
    // conversion de l'image initiale en float
    image    = new InrImage( WT_FLOAT, "image_reel.inr.gz", image_initiale);
    (*image) = (*image_initiale);
  FinSi

  dimension = MODE_3D;

  // Initialisation des images des d�riv�es 
  filtre = GeneralGaussianFilter::ptr(new GeneralGaussianFilter(image, dimension));
//  filtre->SetScaleUnit(PIXEL_SPACE);
  filtre->FixeMasque(mask);
  filtre->Utilise_Image(   false);
  filtre->UtiliseHessien(  true);
  filtre->UtiliseGradient( true);
  filtre->InitDerivees();
  filtre->GammaNormalise( true);
  filtre->SetSupportSize(5);
  filtre->InitFiltre( sigma, type_filtre);  
  filtre->CalculFiltres( );

  image_vep1 = InrImage::ptr( new InrImage( WT_FLOAT, 3,
                  "STH-vep1.inr.gz", image));
  image_vep2 = InrImage::ptr( new InrImage( WT_FLOAT, 3,
                  "STH-vep2.inr.gz", image));
  image_vep3 = InrImage::ptr( new InrImage( WT_FLOAT, 3,
                  "STH-vep3.inr.gz", image));

  image_vap1 = InrImage::ptr( new InrImage( WT_FLOAT, 
                  "STH-vap1.inr.gz", image));
  image_vap2 = InrImage::ptr( new InrImage( WT_FLOAT, 
                  "STH-vap2.inr.gz", image));
  image_vap3 = InrImage::ptr( new InrImage( WT_FLOAT, 
                  "STH-vap3.inr.gz", image));

  if (save_grad)
     image_grad = InrImage::ptr( new InrImage( WT_FLOAT, 3,
                 "STH-grad.inr.gz", image));


  // Calcul des coefficients du tenseur non liss�

  image_vep1->InitImage( 0.0, 0.0, 0.0);
  image_vep2->InitImage( 0.0, 0.0, 0.0);
  image_vep3->InitImage( 0.0, 0.0, 0.0);
  if (save_grad) image_grad->InitImage( 0.0, 0.0, 0.0);
     
  image_vap1->InitImage( 0.0);
  image_vap2->InitImage( 0.0);
  image_vap3->InitImage( 0.0);

  image_vep1->InitBuffer();  
  image_vep2->InitBuffer();  
  image_vep3->InitBuffer();  

  image_vap1->InitBuffer();  
  image_vap2->InitBuffer();  
  image_vap3->InitBuffer();  

  if (save_grad) image_grad->InitBuffer();

  long int n=0;
  int prev_per=0;
  printf("Struct Tensor: ");

  Pour( z, 0, image->_tz - 1)
  Pour( y, 0, image->_ty - 1)
  Pour( x, 0, image->_tx - 1)
    int per = (int)((100.0*n)/image->Size());
    if ((int)(per/10) != (int)(prev_per/10)) {
      printf(" %d %% ",per);
      fflush(stdout);
      prev_per = per;
    }

    Si (mask==NULL) Ou (*mask)(x,y,z)>0.5 Alors

      grad = filtre->Gradient(x,y,z);
      gradarray[0]=grad.x;
      gradarray[1]=grad.y;
      gradarray[2]=grad.z;
      filtre->Hessien( hessien, x,y,z);

      if (save_grad) {
        image_grad->VectFixeValeurs(grad.x,grad.y,grad.z);
      }

      // Compute squared hessian
      H_3D[0][0] = hessien[0];
      H_3D[0][1] = hessien[1];
      H_3D[0][2] = hessien[2];
      H_3D[1][0] = hessien[3];
      H_3D[1][1] = hessien[4];
      H_3D[1][2] = hessien[5];
      H_3D[2][0] = hessien[6];
      H_3D[2][1] = hessien[7];
      H_3D[2][2] = hessien[8];

      Pour(i,0,2)
      Pour(j,0,2)
        if (i<=j) {
          matrice[i][j]=0;
      Pour(k,0,2)
        matrice[i][j] += H_3D[i][k]*H_3D[k][j];
      FinPour
          matrice[i][j] += beta*gradarray[i]*gradarray[j];
        }
        else
    matrice[i][j]=matrice[j][i];
      FinPour
      FinPour

      // Calcul des vep et des vap dans les images associ�es

      Diagonale = jacobi( matrice, 3, 
              vap, 
              vec_propre, 
              &niter );

      Si Diagonale Alors
        eigsrt(vap,  vec_propre, 3);
        image_vep1->VectFixeValeurs( vec_propre[0][0], 
                     vec_propre[1][0], 
                     vec_propre[2][0]);
        image_vep2->VectFixeValeurs( vec_propre[0][1], 
                     vec_propre[1][1], 
                     vec_propre[2][1]);
        image_vep3->VectFixeValeurs( vec_propre[0][2], 
                     vec_propre[1][2], 
                     vec_propre[2][2]);
        image_vap1->FixeValeur( vap[0]);
        image_vap2->FixeValeur( vap[1]);
        image_vap3->FixeValeur( vap[2]);
      FinSi
    FinSi

    if (save_grad) {
      image_grad->IncBuffer();
    }

    image_vep1->IncBuffer();  
    image_vep2->IncBuffer();  
    image_vep3->IncBuffer();  

    image_vap1->IncBuffer();  
    image_vap2->IncBuffer();  
    image_vap3->IncBuffer();  

    n++;

  FinPour
  FinPour
  FinPour

    printf("\n");
    if (GB_debug) printf("deleting filter \n");

  filtre.reset();

  resname = (boost::format("%s_STHvep1")%varname).str();
  Vars.AddVar<InrImage>(resname,image_vep1);

  resname = (boost::format("%s_STHvep2")%varname).str();
  Vars.AddVar<InrImage>(resname,image_vep2);

  resname = (boost::format("%s_STHvep3")%varname).str();
  Vars.AddVar<InrImage>(resname,image_vep3);

  resname = (boost::format("%s_STHvap1")%varname).str();
  Vars.AddVar<InrImage>(resname,image_vap1);

  resname = (boost::format("%s_STHvap2")%varname).str();
  Vars.AddVar<InrImage>(resname,image_vap2);

  resname = (boost::format("%s_STHvap3")%varname).str();
  Vars.AddVar<InrImage>(resname,image_vap3);

  if (save_grad) {
    resname = (boost::format("%s_STHgrad") %varname).str();
    Vars.AddVar<InrImage>(resname,image_grad);
  }


  if (image!=image_initiale) {
    printf("deleting image \n");
    delete image;
  }

  return true;

} // end Func_StructureTensorHessian () 


//---------------------------------------------------------
// Func_StructureTensorHessianNew
//
//  the mask in the filtering part  for the moment
// this function returns the tensor instead of
// its eigenvalues and eigenvectors
// imgrad, if exists, should be a 3D vector field
// of the same dimensions as image_initiale
//---------------------------------------------------------

InrImage::ptr Func_StructureTensorHessianNew( InrImage::ptr image_initiale, 
//        ------------------------------
                        float sigma,
                        float beta,
                        InrImage::ptr mask,
                        InrImage::ptr imgrad,
                        std::vector<float> PSF,
                        int num_threads
                        )
{
  // TODO: 2D version
//    FloatMatrix         matriceinit(3,3);
    InrImage::ptr       image;
    InrImage::ptr       result;
    GeneralGaussianFilter::ptr filtre;

  Timing t0("Func_StructureTensorHessianNew() Filtering"); 
  t0.Debut();

  type_filtre = MY_FILTRE_CONV;
  Si (image_initiale->_format == WT_FLOAT) Alors
    image = image_initiale;
  Sinon
    // conversion de l'image initiale en float
    image    = InrImage::ptr(new InrImage( WT_FLOAT, "image_reel.inr.gz", image_initiale.get()));
    (*image) = (*image_initiale);
  FinSi

  dimension = MODE_3D;

  // Initialisation des images des d�riv�es 
  filtre = GeneralGaussianFilter::ptr(new GeneralGaussianFilter(image.get(), dimension));
//  filtre->SetScaleUnit(PIXEL_SPACE);
  filtre->Set_use_new_filter(true);
  if (mask.use_count()) filtre->FixeMasque(mask.get());
  filtre->Utilise_Image(   false);
  filtre->UtiliseHessien(  true);
  filtre->UtiliseGradient( true);
  filtre->SetPointSpreadFunctionStandDev(PSF[0],PSF[1],PSF[2]);
  filtre->InitDerivees();
  filtre->GammaNormalise( true);
  filtre->SetSupportSize(5);
  filtre->InitFiltre( sigma, type_filtre);  
  if (num_threads>0)
    filtre->Set_numthreads(num_threads);
  filtre->CalculFiltres( );

  if (mask.use_count())
    filtre->FixeMasque(mask.get());

  t0.Fin();
  std::cout << t0 << std::endl;

  Timing t("Func_StructureTensorHessianNew() Creating tensor"); 
  t.Debut();

  result =  InrImage::ptr(new InrImage( WT_FLOAT, 
                                        6, 
                                        "StructTensorH.ami.gz", 
                                        image.get()));

  // Calcul des coefficients du tenseur non liss�
  //double initval[6] = { 0,0,0,0,0,0};
  //result->InitImage(initval,6);
  result->InitZero();

  
  if (imgrad.get()) {
    //imgrad->InitImage(0,0,0);
    imgrad->InitZero();
  }

  long int n=0;
  int prev_per=0;
  bool process;
  printf("Struct Tensor: ");

  bool use_mask      = mask.use_count();
  bool save_gradient = imgrad.get();
  
  filtre->PreComputeCoeffs();
  
  #pragma omp parallel
  #pragma omp for
  for( int z=0; z<= image->_tz - 1; z++)
  {
    double              G[3];
    Vect3D<double>      grad;
    double              H[9];
    //FloatMatrix         matrice(3,3);

    for( int y=0; y<= image->_ty - 1; y++)
    for( int x=0; x<= image->_tx - 1; x++)
    {
  //     int per = (int)((100.0*n)/image->Size());
  //     if ((int)(per/10) != (int)(prev_per/10)) {
  //       printf(" %d %% ",per);
  //       fflush(stdout);
  //       prev_per = per;
  //     }

      if (!use_mask)
        process = true;
      else
        process = (*mask)(x,y,z)>0.5;

      if (process) {
        grad = filtre->Gradient(x,y,z);
        G[0]=grad.x;
        G[1]=grad.y;
        G[2]=grad.z;
        filtre->Hessien( H, x,y,z);
        
        double tens[6];

        // matrice at 0,0
        tens[0] = H[0]*H[0]+H[1]*H[1]+H[2]*H[2]+beta*(G[0]*G[0]);
        // matrice at 0,1
        tens[1] = H[0]*H[3]+H[1]*H[4]+H[2]*H[5]+beta*(G[0]*G[1]);
        // matrice at 0,2
        tens[2] = H[0]*H[6]+H[1]*H[7]+H[2]*H[8]+beta*(G[0]*G[2]);
        // matrice at 1,1
        tens[3] = H[3]*H[3]+H[4]*H[4]+H[5]*H[5]+beta*(G[1]*G[1]);
        // matrice at 1,2
        tens[4] = H[3]*H[6]+H[4]*H[7]+H[5]*H[8]+beta*(G[1]*G[2]);
        // matrice at 2,2
        tens[5] = H[6]*H[6]+H[7]*H[7]+H[8]*H[8]+beta*(G[2]*G[2]);

        result->SetVectorValue(x,y,z, tens);

        // Compute squared hessian
//         H_3D[0][0] = hessien[0];
//         H_3D[0][1] = hessien[1];
//         H_3D[0][2] = hessien[2];
//         H_3D[1][0] = hessien[3];
//         H_3D[1][1] = hessien[4];
//         H_3D[1][2] = hessien[5];
//         H_3D[2][0] = hessien[6];
//         H_3D[2][1] = hessien[7];
//         H_3D[2][2] = hessien[8];

//         for(int i=0;i<3;i++) 
//         {
//           for(int j=i;j<3;j++) 
//           {
//               matrice[i][j]=0;
//               for(int k=0;k<3;k++)
//                 matrice[i][j] += H_3D[i][k]*H_3D[k][j];
//               matrice[i][j] += beta*gradarray[i]*gradarray[j];
//               result->SetValue(x,y,z, pos++, matrice[i][j]);
//           }
//         }
        if (save_gradient) {
          imgrad->SetVectorValue(x,y,z, G);
        }
      }

    } // for x,y
  } // parallel for z

  printf("\n");

  t.Fin();
  std::cout << t << std::endl;

  return result;

} // end Func_StructureTensorHessianNew() 
