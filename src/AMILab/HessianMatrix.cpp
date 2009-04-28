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
 * $Revision: 1.7 $
 * $Log: HessianMatrix.c,v $
 * Revision 1.7  2006/02/21 18:26:17  karl
 * many changes
 *
 * Revision 1.6  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.5  2004/10/09 10:40:16  karl
 * last modifs
 *
 * Revision 1.4  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.3  2004/04/30 20:08:24  karl
 * several modif: set private colormap, get distmap in LevelSets, ...
 *
 * Revision 1.2  2004/02/17 23:34:03  karl
 * add Derivatives function, Get/Set image name
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.5  2001/03/16 23:55:22  karl
 * *** empty log message ***
 ***************************************************************************/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "fonctions.h"
#include "VarContexts.hpp"
#include "chaine.hpp"
#include "inrimage.hpp"
#include "FiltreRec.hpp"
#include "FloatMatrix.hpp"
#include "Eigen.hpp"

extern    VarContexts  Vars;
extern    unsigned char GB_debug;

//extern unsigned char verbose;


// Filtrage de l'image et de ses d�riv�es
static int type_filtre;
static int dimension;


//---------------------------------------------------------
// Func_Derivatives
//---------------------------------------------------------
//
// Get first and second order derivatives:
// H1: 1st eigenvector or eigenvalue of the Hessian matrix
// H2: 2nd eigenvector or eigenvalue of the Hessian matrix
// H3: 3rd eigenvector or eigenvalue of the Hessian matrix
// G : gradient vector
// values: 0 do not save
//         1 save the eigenvector (or vector)
//         2 save the eigenvalue
//         3 save both
//
unsigned char      Func_Derivatives( InrImage* image_initiale, 
                   char* varname,
                   float Sigma, 
                   float Gamma,
                   InrImage* mask,
                   int H1,
                   int H2,
                   int H3,
                   int _G)
{

  //  verbose = true;

  Si image_initiale->_tz == 1 AlorsFait return false;

  

    FloatMatrix     H_3D(3,3);
    FloatMatrix     VP_3D(3,3);
    float           vap[3];
    int             num_rot;
    unsigned char         VapHessien = false;

    int          x,y,z;
    double          hessien[9];
    InrImage*       image;
    InrImage*       image_vep1 = NULL;
    InrImage*       image_vep2 = NULL;
    InrImage*       image_vep3 = NULL;
    InrImage*       image_vap1 = NULL;
    InrImage*       image_vap2 = NULL;
    InrImage*       image_vap3 = NULL;
    InrImage*       image_grad = NULL;
    FiltreRecursif* filtre;
    char            resname[100];
    // int             i;

  type_filtre = MY_FILTRE_CONV;
  Si (image_initiale->_format == WT_FLOAT) Alors
    image = image_initiale;
  Sinon
    // conversion de l'image initiale en float
    image    = new InrImage( WT_FLOAT, "image_reel.inr.gz", image_initiale);
    (*image) = (*image_initiale);
  FinSi

  dimension = MODE_3D;

  if (H1&1) {
    image_vep1 =  new InrImage( WT_FLOAT, 3, "H-vep1.inr.gz", image);
    image_vep1->InitImage( 0.0, 0.0, 0.0);
  }

  if (H1&2) {
    image_vap1 =  new InrImage( WT_FLOAT,  "H-vap1.inr.gz", image);
    image_vap1->InitImage( 0.0);
  }

  if (H2&1) {
    image_vep2 =  new InrImage( WT_FLOAT, 3, "H-vep2.inr.gz", image);
    image_vep2->InitImage( 0.0, 0.0, 0.0);
  }

  if (H2&2) {
    image_vap2 =  new InrImage( WT_FLOAT,  "H-vap2.inr.gz", image);
    image_vap2->InitImage( 0.0);
  }

  if (H3&1) {
    image_vep3 =  new InrImage( WT_FLOAT, 3, "H-vep3.inr.gz", image);
    image_vep3->InitImage( 0.0, 0.0, 0.0);
  }

  if (H3&2) {
    image_vap3 =  new InrImage( WT_FLOAT,  "H-vap3.inr.gz", image);
    image_vap3->InitImage( 0.0);
  }

  if (_G&1) {
    image_grad =  new InrImage( WT_FLOAT, 3, "grad.inr.gz", image);
    image_grad->InitImage( 0.0, 0.0, 0.0);
  }


  // Initialisation des images des d�riv�es 
  filtre = new FiltreRecursif(image, dimension);

  Si (mask != NULL) Alors
    filtre->FixeMasqueGradient( mask);
  FinSi

  filtre->Utilise_Image(   false);
  if (H1||H2||H3)  filtre->UtiliseHessien(  true);
  if (_G)           filtre->UtiliseGradient( true);

  filtre->InitDerivees();

  Si Gamma>0 Alors
    filtre->GammaNormalise(true);
    filtre->FixeGamma(Gamma);
  Sinon
    filtre->GammaNormalise(false);
  FinSi

  filtre->InitFiltre( Sigma, type_filtre);  
  filtre->CalculFiltres( );

  if (H1&1) image_vep1->InitBuffer();  
  if (H2&1) image_vep2->InitBuffer();  
  if (H3&1) image_vep3->InitBuffer();  
  if (_G)    image_grad->InitBuffer();  

  if (H1&2) image_vap1->InitBuffer();  
  if (H2&2) image_vap2->InitBuffer();  
  if (H3&2) image_vap3->InitBuffer();  

  long int n=0;
//  int per;
  int prev_per=0;

  Pour( z, 0, image->_tz - 1)
  Pour( y, 0, image->_ty - 1)
  Pour( x, 0, image->_tx - 1)
    int per = (int)((100.0*n)/image->Size());
    if ((int)(per/10) != (int)(prev_per/10)) {
      printf("done %d %% \n",per);
      prev_per = per;
    }

    Si (mask==NULL) Ou (*mask)(x,y,z)>0.5 Alors

      filtre->Hessien( hessien, x,y,z);

      H_3D[0][0] = hessien[0];
      H_3D[0][1] = hessien[1];
      H_3D[0][2] = hessien[2];
      H_3D[1][0] = hessien[3];
      H_3D[1][1] = hessien[4];
      H_3D[1][2] = hessien[5];
      H_3D[2][0] = hessien[6];
      H_3D[2][1] = hessien[7];
      H_3D[2][2] = hessien[8];

      VapHessien = jacobi( H_3D, 3, vap, VP_3D, &num_rot );

      Si VapHessien Alors
        eigsrt_abs(vap, VP_3D, 3);
        if (H1&1) image_vep1->VectFixeValeurs( VP_3D[0][0],  VP_3D[1][0],  VP_3D[2][0]);
        if (H2&1) image_vep2->VectFixeValeurs( VP_3D[0][1],  VP_3D[1][1],  VP_3D[2][1]);
        if (H3&1) image_vep3->VectFixeValeurs( VP_3D[0][2],  VP_3D[1][2],  VP_3D[2][2]);
        if (H1&2) image_vap1->FixeValeur( vap[0]);
        if (H2&2) image_vap2->FixeValeur( vap[1]);
        if (H3&2) image_vap3->FixeValeur( vap[2]);
      FinSi

      if (_G) {
    Vect3D<double> grad;
    grad = filtre->Gradient(x,y,z);
    image_grad->VectFixeValeurs( grad.x,  grad.y,  grad.z);
      }
    FinSi

    if (H1&1) image_vep1->IncBuffer();  
    if (H2&1) image_vep2->IncBuffer();  
    if (H3&1) image_vep3->IncBuffer();  
    if (_G)    image_grad->IncBuffer();  

    if (H1&2) image_vap1->IncBuffer();  
    if (H2&2) image_vap2->IncBuffer();  
    if (H3&2) image_vap3->IncBuffer();  
    n++;
  FinPour
  FinPour
  FinPour

  if (H1&1) {
    sprintf(resname,"%s_Hvep1",varname);
    Vars.AddVar(type_image,resname,image_vep1);
  }

  if (H2&1) {
    sprintf(resname,"%s_Hvep2",varname);
    Vars.AddVar(type_image,resname,image_vep2);
  }

  if (H3&1) {
    sprintf(resname,"%s_Hvep3",varname);
    Vars.AddVar(type_image,resname,image_vep3);
  }

  if (_G&1) {
    sprintf(resname,"%s_grad",varname);
    Vars.AddVar(type_image,resname,image_grad);
  }

  if (H1&2) {
    sprintf(resname,"%s_Hvap1",varname);
    Vars.AddVar(type_image,resname,image_vap1);
  }

  if (H2&2) {
    sprintf(resname,"%s_Hvap2",varname);
    Vars.AddVar(type_image,resname,image_vap2);
  }

  if (H3&2) {
    sprintf(resname,"%s_Hvap3",varname);
    Vars.AddVar(type_image,resname,image_vap3);
  }

  delete filtre;
  if (image!=image_initiale) delete image;

  return true;

} //  Func_Derivatives()

//---------------------------------------------------------
// Func_HessianMatrix
//---------------------------------------------------------

unsigned char Func_HessianMatrix( InrImage* image_initiale, 
//      ------------------
                    char* varname,
                    float Sigma, 
                float Gamma,
                    InrImage* mask)
{

//  verbose = true;

  Si image_initiale->_tz == 1 AlorsFait return false;
printf("Func_HessianMatrix\n");

  

    FloatMatrix     H_3D(3,3);
    FloatMatrix     VP_3D(3,3);
    float           vap[3];
    int             num_rot;
    unsigned char         VapHessien = false;

    int          x,y,z;
    double          hessien[9];
    InrImage*       image;
    InrImage*       image_vep1;
    InrImage*       image_vep2;
    InrImage*       image_vep3;
    InrImage*       image_vap1;
    InrImage*       image_vap2;
    InrImage*       image_vap3;
    FiltreRecursif* filtre;
    char            resname[100];
// int             i;

  type_filtre = MY_FILTRE_CONV;
  Si (image_initiale->_format == WT_FLOAT) Alors
    image = image_initiale;
  Sinon
    // conversion de l'image initiale en float
    image    = new InrImage( WT_FLOAT, "image_reel.inr.gz", image_initiale);
    (*image) = (*image_initiale);
  FinSi

  dimension = MODE_3D;

  image_vep1 =  new InrImage( WT_FLOAT, 3, "H-vep1.inr.gz", image);
  image_vep2 =  new InrImage( WT_FLOAT, 3, "H-vep2.inr.gz", image);
  image_vep3 =  new InrImage( WT_FLOAT, 3, "H-vep3.inr.gz", image);
  image_vep1->InitImage( 0.0, 0.0, 0.0);
  image_vep2->InitImage( 0.0, 0.0, 0.0);
  image_vep3->InitImage( 0.0, 0.0, 0.0);

  image_vap1 =  new InrImage( WT_FLOAT,  "H-vap1.inr.gz", image);
  image_vap2 =  new InrImage( WT_FLOAT,  "H-vap2.inr.gz", image);
  image_vap3 =  new InrImage( WT_FLOAT,  "H-vap3.inr.gz", image);
  image_vap1->InitImage( 0.0);
  image_vap2->InitImage( 0.0);
  image_vap3->InitImage( 0.0);


  // Initialisation des images des d�riv�es 
  filtre = new FiltreRecursif(image, dimension);

  Si (mask != NULL) Alors
    filtre->FixeMasqueGradient( mask);
  FinSi

  filtre->Utilise_Image(   false);
  filtre->UtiliseHessien(  true);
  filtre->UtiliseGradient( true);

  filtre->InitDerivees();

  Si Gamma>0 Alors
    filtre->GammaNormalise(true);
    filtre->FixeGamma(Gamma);
  Sinon
    filtre->GammaNormalise(false);
  FinSi

  filtre->InitFiltre( Sigma, type_filtre);  
  filtre->CalculFiltres( );

  image_vep1->InitBuffer();  
  image_vep2->InitBuffer();  
  image_vep3->InitBuffer();  

  image_vap1->InitBuffer();  
  image_vap2->InitBuffer();  
  image_vap3->InitBuffer();  


  long int n=0;
//  int per;
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

      filtre->Hessien( hessien, x,y,z);

      H_3D[0][0] = hessien[0];
      H_3D[0][1] = hessien[1];
      H_3D[0][2] = hessien[2];
      H_3D[1][0] = hessien[3];
      H_3D[1][1] = hessien[4];
      H_3D[1][2] = hessien[5];
      H_3D[2][0] = hessien[6];
      H_3D[2][1] = hessien[7];
      H_3D[2][2] = hessien[8];

      VapHessien = jacobi( H_3D, 3, vap, VP_3D, &num_rot );

      Si VapHessien Alors
        eigsrt_abs(vap, VP_3D, 3);
        image_vep1->VectFixeValeurs( VP_3D[0][0],  VP_3D[1][0],  VP_3D[2][0]);
        image_vep2->VectFixeValeurs( VP_3D[0][1],  VP_3D[1][1],  VP_3D[2][1]);
        image_vep3->VectFixeValeurs( VP_3D[0][2],  VP_3D[1][2],  VP_3D[2][2]);
        image_vap1->FixeValeur( vap[0]);
        image_vap2->FixeValeur( vap[1]);
        image_vap3->FixeValeur( vap[2]);
      FinSi
    FinSi

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

  sprintf(resname,"%s_Hvep1",varname);
  Vars.AddVar(type_image,resname,image_vep1);

  sprintf(resname,"%s_Hvep2",varname);
  Vars.AddVar(type_image,resname,image_vep2);

  sprintf(resname,"%s_Hvep3",varname);
  Vars.AddVar(type_image,resname,image_vep3);

  sprintf(resname,"%s_Hvap1",varname);
  Vars.AddVar(type_image,resname,image_vap1);

  sprintf(resname,"%s_Hvap2",varname);
  Vars.AddVar(type_image,resname,image_vap2);

  sprintf(resname,"%s_Hvap3",varname);
  Vars.AddVar(type_image,resname,image_vap3);

  delete filtre;
  if (image!=image_initiale) delete image;

  return true;

} // end Func_HessianMatrix() 



//---------------------------------------------------------
// Func_HessianVap
//---------------------------------------------------------

unsigned char Func_HessianVap( InrImage* image_initiale, 
//      ---------------
             char* varname,
             float Sigma, 
             float Gamma,
             InrImage* mask,
             int vap_num)
{

//  verbose = true;

  Si image_initiale->_tz == 1 AlorsFait return false;
printf("Func_HessianVap\n");
  

    FloatMatrix     H_3D(3,3);
    FloatMatrix     VP_3D(3,3);
    float           vap[3];
    int             num_rot;
    unsigned char         VapHessien = false;

    int          x,y,z;
    double          hessien[9];
    InrImage*       image;
    InrImage*       image_vap;
    FiltreRecursif* filtre;
    char            resname[100];
    char            imname[100];
//int             i;
  
  Si (vap_num<1) Ou (vap_num>3) Alors
    fprintf(stderr,"Func_HessianVap() \t bad eigenvalue number \n");
    return false;
  FinSi

  type_filtre = MY_FILTRE_CONV;
  Si (image_initiale->_format == WT_FLOAT) Alors
    image = image_initiale;
  Sinon
    // conversion de l'image initiale en float
    image    = new InrImage( WT_FLOAT, "image_reel.inr.gz", image_initiale);
    (*image) = (*image_initiale);
  FinSi

  dimension = MODE_3D;

  sprintf(imname,"H-vap%d.inr.gz",vap_num);
  image_vap =  new InrImage( WT_FLOAT,  imname, image);


  // Initialisation des images des d�riv�es 
  filtre = new FiltreRecursif(image, dimension);

  Si (mask != NULL) Alors
    filtre->FixeMasqueGradient( mask);
  FinSi

  filtre->Utilise_Image(   false);
  filtre->UtiliseHessien(  true);
  filtre->UtiliseGradient( true);

  filtre->InitDerivees();

  Si Gamma>0 Alors
    filtre->GammaNormalise(true);
    filtre->FixeGamma(Gamma);
  Sinon
    filtre->GammaNormalise(false);
  FinSi

  filtre->InitFiltre( Sigma, type_filtre);  
  filtre->CalculFiltres( );

  image_vap->InitBuffer();  

  Pour( z, 0, image->_tz - 1)
  Pour( y, 0, image->_ty - 1)
  Pour( x, 0, image->_tx - 1)

    Si (mask==NULL) Ou (*mask)(x,y,z)>127 Alors

      filtre->Hessien( hessien, x,y,z);

      H_3D[0][0] = hessien[0];
      H_3D[0][1] = hessien[1];
      H_3D[0][2] = hessien[2];
      H_3D[1][0] = hessien[3];
      H_3D[1][1] = hessien[4];
      H_3D[1][2] = hessien[5];
      H_3D[2][0] = hessien[6];
      H_3D[2][1] = hessien[7];
      H_3D[2][2] = hessien[8];

      VapHessien = jacobi( H_3D, 3, vap, VP_3D, &num_rot );

      Si VapHessien Alors
        eigsrt_abs(vap, VP_3D, 3);
        image_vap->FixeValeur( vap[vap_num-1]);
      FinSi
    FinSi
    image_vap->IncBuffer();  

  FinPour
  FinPour
  FinPour

  sprintf(resname,"%s_Hvap%d",varname,vap_num);
  Vars.AddVar(type_image,resname,image_vap);

  delete filtre;
  if (image!=image_initiale) delete image;

  return true;

} // end Func_HessianVap() 

