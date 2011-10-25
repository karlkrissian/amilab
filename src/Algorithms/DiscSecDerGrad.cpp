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
 * $Log: DiscSecDerGradr.c,v $
 * Revision 1.4  2006/02/21 18:26:17  karl
 * many changes
 *
 * Revision 1.3  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.2  2005/08/08 17:24:54  karl
 * SRAD implementation + warnings fix
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2003/08/14 07:16:14  karl
 * Source code
 *
 * Revision 1.5  2001/03/16 23:55:22  karl
 * *** empty log message ***
 ***************************************************************************/

#include "DiscSecDerGrad.h"

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "fonctions.h"
#include "VarContexts.hpp"
#include "math1.hpp"
#include "inrimage.hpp"
#include "FloatMatrix.hpp"

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;

/*
//----------------------------------------------------------------------
// Bad discrete version
// now should be more accurate and continuous version
//
InrImage* Func_SecDerGradOld( InrImage* im, float sigma )
{
  
    InrImage*       image_entree;
    InrImage*       image_res;
    InrImage*       image_lissee;
    GeneralGaussianFilter* filtre;
    int             mode;
    std::string     resname;

  Si (im->_format == WT_FLOAT) Alors
    image_entree = im;
  Sinon
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", 
                 im);
    (*image_entree) = (*im);
  FinSi

  Si image_entree->_tz > 1 Alors
    mode = MODE_3D; 
  Sinon
    mode = MODE_2D; 
  FinSi

  filtre = new GeneralGaussianFilter( im,  mode);
  filtre->GammaNormalise(false);
  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  


  resname = (boost::format("%s.smoothed") % im->GetName()).str();
  image_lissee = new InrImage(WT_FLOAT, resname.c_str() , im);

  Si mode == MODE_3D Alors
    filtre->MyFiltre( image_entree, image_lissee, 0, -1, -1);
    filtre->MyFiltre( image_lissee, image_lissee, -1, 0, -1);
    filtre->MyFiltre( image_lissee, image_lissee, -1, -1, 0);
  Sinon
    filtre->MyFiltre( image_entree, image_lissee, 0,0,-1);
  FinSi

  delete filtre;

  resname = (boost::format("%s.d2grad") % image_entree->GetName()).str();
  image_res = new InrImage(WT_FLOAT, resname.c_str() , image_entree);
  image_res->InitImage(0.0);

  Func_DiscSecDerGrad(image_lissee, image_res, NULL);

  delete image_lissee;
  Si image_entree!=im AlorsFait delete image_entree;

  return image_res;

} // Func_SecDerGradOld()

*/


//----------------------------------------------------------------------
//
// Calcul de la derivee seconde dans la direction du gradient
//
float CalculDerSecGrad(float* Iconv, float gradient[3], 
              float hessien[3][3],
              int x, int y, int z,
              int tx, int ty, int tz)
//
{

  
    int txy;
    double           normgrad2;

  txy=tx*ty;

  // Calcul du gradient et du Hessien
  Si x>0 Et x<tx-1 Alors
    gradient[0] = (*(Iconv+1) - *(Iconv-1))/2.0;
    hessien[0][0] = (*(Iconv+1) - 2*(*Iconv) + *(Iconv-1));

    Si y>0 Et y<ty-1 Alors
      hessien[1][0] = hessien[0][1] = 
          ((*(Iconv+1+tx) - *(Iconv-1+tx))
         -
           (*(Iconv+1-tx) - *(Iconv-1-tx)))
          /4.0;
    Sinon
      hessien[1][0] = hessien[0][1] = 0.0;
    FinSi

    Si z>0 Et z<tz-1 Alors
      hessien[2][0] = hessien[0][2] = 
          ((*(Iconv+1+txy) - *(Iconv-1+txy))
         -
           (*(Iconv+1-txy) - *(Iconv-1-txy)))
          /4.0;
    Sinon
      hessien[2][0] = hessien[0][2] = 0.0;
    FinSi

  Sinon
    gradient[0] = 0.0;
    hessien[0][0] = 0.0;
    hessien[1][0] = hessien[0][1] = 0.0;
    hessien[2][0] = hessien[0][2] = 0.0;
  FinSi


  Si y>0 Et y<ty-1 Alors
    gradient[1] = (*(Iconv+tx) - *(Iconv-tx))/2.0;
    hessien[1][1] = (*(Iconv+tx) - 2*(*Iconv) + *(Iconv-tx));

    Si z>0 Et z<tz-1 Alors
      hessien[2][1] = hessien[1][2] = 
          ((*(Iconv+tx+txy) - *(Iconv-tx+txy))
         -
           (*(Iconv+tx-txy) - *(Iconv-tx-txy)))
          /4.0;
    Sinon
      hessien[2][1] = hessien[1][2] = 0.0;
    FinSi

  Sinon
    gradient[1] = 0.0;
    hessien[1][1] = 0.0;
    hessien[2][1] = hessien[1][2] = 0.0;
  FinSi


  Si z>0 Et z<tz-1 Alors
    gradient[2] = (*(Iconv+txy) - *(Iconv-txy))/2.0;
    hessien[2][2] = (*(Iconv+txy) - 2*(*Iconv) + *(Iconv-txy));
  Sinon
    gradient[2] = 0.0;
    hessien[2][2] = 0.0;
  FinSi


  normgrad2 = gradient[0]*gradient[0]+
          gradient[1]*gradient[1]+
              gradient[2]*gradient[2];

  if (normgrad2>1E-5)
  return (( gradient[0]*(    hessien[0][0]*gradient[0]+
                 2*hessien[1][0]*gradient[1]+
                 2*hessien[2][0]*gradient[2]) +
          gradient[1]*(    hessien[1][1]*gradient[1]+
                 2*hessien[2][1]*gradient[2]) +
          gradient[2]*     hessien[2][2]*gradient[2]    )/normgrad2);

  else
  return ( gradient[0]*(    hessien[0][0]*gradient[0]+
                2*hessien[1][0]*gradient[1]+
                2*hessien[2][0]*gradient[2]) +
         gradient[1]*(    hessien[1][1]*gradient[1]+
                2*hessien[2][1]*gradient[2]) +
         gradient[2]*     hessien[2][2]*gradient[2]    );


} // CalculDerSecGrad()




//----------------------------------------------------------------------
void Func_DiscSecDerGrad( InrImage* image_entree, InrImage* dersec, InrImage* normgrad )
//   -------------------
{
  
    int             mode;
    int           x,y,z;
    register float    *Idersec; 
    register float    *Inormgrad=NULL; 
    register float    *Input; 
    float             val1;
    float             gradient[3];
    float             hessien[3][3];


  Si (dersec->_format != WT_FLOAT) Alors
    fprintf(stderr,"Func_DiscSecDerGrad() \t Input Image must be of type float \n");
    return;
  FinSi

  Si (normgrad != NULL) Et (normgrad->_format != WT_FLOAT) Alors
    fprintf(stderr,"Func_DiscSecDerGrad() \t Input NormGrad Image must be of type float \n");
    normgrad = NULL;
  FinSi


  Si image_entree->_tz > 1 Alors
    mode = MODE_3D; 
  Sinon
    mode = MODE_2D; 
  FinSi


  Input       = (float*)  image_entree->Buffer();  
  Idersec     = (float*)  dersec      ->Buffer(); 
  if (normgrad!=NULL)  Inormgrad = (float*)  normgrad->Buffer();

  Pour(z,0,image_entree->_tz-1)
  Pour(y,0,image_entree->_ty-1)
  Pour(x,0,image_entree->_tx-1)

    val1 = CalculDerSecGrad( Input, 
                 gradient, 
                 hessien,
                 x,y,z,
                 image_entree->_tx,
                 image_entree->_ty,
                 image_entree->_tz);


    (*Idersec) = val1;

    Input++;
    Idersec++;
    if (normgrad!=NULL) {
      *Inormgrad = sqrt(gradient[0]*gradient[0]+
            gradient[1]*gradient[1]+
            gradient[2]*gradient[2]);

      Inormgrad++;
    }

  FinPour
  FinPour
  FinPour


} // Func_DiscSecDerGrad()

//extern unsigned char verbose;



