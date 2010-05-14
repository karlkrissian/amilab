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
/* Calcul des courbures principales
 *
 *
 * Karl KRISSIAN
 * fichier AnisoGaussSeidel.c
 *
 * 2D and 3D Restoration with Anisotropic diffusion
 * 
 */

#include <pthread.h>

#include "style.hpp"
#include "inrimage.hpp"
#include "math1.hpp"
#include "DeriveesLissees.hpp"
#include "filtrage_rec.hpp"
#include "Wrap_AnisoGS.h"
#include "stdio.h"
//#include "fonctions.h"

#include "func_imagebasictools.h"

#include "DefineClass.hpp"
#include "amilab_messages.h"

#include "AnisoGS.h"





static AnisoGS* static_AnisoGS = NULL;


//static float   *in;


//----------------------------------------------------------------------
void Func_InitAnisoGS(InrImage* in, 
			   float p_sigma, 
			   float p_k,
			   float p_beta
			   )
{

  if (static_AnisoGS!=NULL) delete static_AnisoGS;
  static_AnisoGS=new AnisoGS();
  static_AnisoGS->Init(in,p_sigma,p_k,p_beta);

} // Func_InitAnisoGS()

//----------------------------------------------------------------------
void Func_SetCoeffAnisoGS( float p_tang  )
{
  static_AnisoGS->Settang_coeff(p_tang);
}

//----------------------------------------------------------------------
void Func_SetCoeffAnisoGS3D( float cmin, float cmax  )
{
  static_AnisoGS->Setmincurv_coeff(cmin);
  static_AnisoGS->Setmaxcurv_coeff(cmax);
}

//----------------------------------------------------------------------
void      Func_AnisoGS_SetNoiseType( int nt)
//
{
  switch (nt) {
  case GAUSSIAN_NOISE:
  case SPECKLE_NOISE:
    static_AnisoGS->Setnoise_type( nt);
    break;
  default:
    fprintf(stderr,"Func_AnisoGS_SetNoiseType(%d) \t bad noise type \n",nt);
  }
}

//----------------------------------------------------------------------
void      Func_AnisoGS_SetDistanceMap( unsigned char dm)
//
{
  static_AnisoGS->SetDistanceMap(dm);
}

//----------------------------------------------------------------------
void Func_AnisoGS_SetMask( InrImage* m  )
{
  static_AnisoGS->Setmask(m);
}

//----------------------------------------------------------------------
void      Func_AnisoGS_SetDataCoeff( float datacoeff  )
//
{
  static_AnisoGS->Setbeta(datacoeff);
}


//----------------------------------------------------------------------
void      Func_AnisoGS_SetNoiseSD( float noiseSD  )
//
{
  static_AnisoGS->Setnoise_standard_deviation( noiseSD);
}

//----------------------------------------------------------------------
float      Func_AnisoGS_GetNoiseSD(  )
//
{
  return static_AnisoGS->Getnoise_standard_deviation();
}

//----------------------------------------------------------------------
float      Func_AnisoGS_GetDAcoeff(  )
//
{
  return static_AnisoGS->Getestimated_DA_coeff();
}

//----------------------------------------------------------------------
void Func_SetSmoothedParam( unsigned char sp  )
{
  static_AnisoGS->SetSmoothedParam( sp);
}



//----------------------------------------------------------------------
void Func_AnisoGS_SetSRAD_ROI( InrImage* SRAD_roi)
{
  printf("Func_AnisoGS_SetSRAD_ROI()\n");
  static_AnisoGS->SetSRAD_ROI(      SRAD_roi);
  static_AnisoGS->Setcontours_mode( CONTOURS_SRAD);
}

//----------------------------------------------------------------------
void Func_AnisoGS_SetRNRAD_ROI( InrImage* RNRAD_roi)
{
  printf("Func_AnisoGS_SetRNRAD_ROI()\n");
  static_AnisoGS->SetSRAD_ROI(      RNRAD_roi);
  static_AnisoGS->Setcontours_mode( CONTOURS_RNRAD);
}

//----------------------------------------------------------------------
void Func_AnisoGS_SetRNRAD_ROI_NEW( InrImage* RNRAD_roi)
{
  printf("Func_AnisoGS_SetRNRAD_NEW_ROI()\n");
  static_AnisoGS->SetSRAD_ROI(      RNRAD_roi);
  static_AnisoGS->Setcontours_mode( CONTOURS_RNRAD_NEW);
}

//----------------------------------------------------------------------
void Func_AnisoGS_Setneighborhood( int n)
{
  static_AnisoGS->Setneighborhood( n);
}

//----------------------------------------------------------------------
void Func_AnisoGS_Setdt( float dt)
{
  static_AnisoGS->Setdt( dt);
}

//----------------------------------------------------------------------
void      Func_SetLocalStructureMode( int local_struct_mode)
{
  static_AnisoGS->Setlocal_structure_mode( local_struct_mode);
}

//----------------------------------------------------------------------
void      Func_SetEigenvaluesMode( int eigenvalues_mode)
{
  static_AnisoGS->Setdiffusion_eigenvalues_mode( eigenvalues_mode);
}

//----------------------------------------------------------------------
float Func_ItereAnisoGS()
//   -----------------
{

  if (static_AnisoGS != NULL)
    return static_AnisoGS->Iterate();
  else
    return 0;

} // Func_ItereAnisoGS()


//----------------------------------------------------------------------
float AnisoGS::IterateFlux( InrImage* vect, float coeff)
//   --------------------
{
  float       erreur;

  Si vect== NULL Alors
    fprintf(stderr,"Func_ItereFlux() \t NULL vector \n");
    return 0.0;
  FinSi

  Si Non(vect->VectorialFormat()) Alors
    fprintf(stderr,"Func_ItereFlux() \t input image not in  vectorial format \n");
    return 0.0;
  FinSi

  Si this->image_resultat==NULL Alors
    fprintf(stderr,"Func_ItereFlux() AnisoGS not initialized \n");
    return 0.0;
  FinSi

  iteration++;

  Si mode == MODE_2D Alors
    fprintf(stderr,"Func_ItereFlux() 2D mode not supported yet \n");
    return 0.0;
  //    erreur = Itere2D(    this->image_resultat);
  Sinon
    erreur = Itere3D_Flux( this->image_resultat, vect, coeff);
  FinSi
    
  printf(" iteration %d : %f \n", iteration,erreur);
  
  return erreur;

} // AnisoGS::IterateFlux()


//----------------------------------------------------------------------
float Func_ItereFlux( InrImage* vect, float coeff)
//   --------------
{

  if (static_AnisoGS != NULL)
    return static_AnisoGS->IterateFlux(vect,coeff);
  else
    return 0;

} // Func_ItereAnisoGS()


//----------------------------------------------------------------------
int Func_EndAnisoGS()
{

  delete static_AnisoGS;
  static_AnisoGS = NULL;

  return 1;

} // Func_EndAnisoGS()

//----------------------------------------------------------------------
InrImage* Func_AnisoGS_GetOutput()
{

  if (static_AnisoGS != NULL) {
    InrImage* imres = static_AnisoGS->image_resultat;
    InrImage* res;
    int bs = static_AnisoGS->boundary_extension_size;

    res = Func_SubImage( imres,
                          bs,bs,bs,
                          imres->DimX()-1-bs,
                          imres->DimY()-1-bs,
                          imres->DimZ()-1-bs);

    // Set translation and voxel size ?

    return res;
  }
  else
    return NULL;

} // Func_GetOutput()

//----------------------------------------------------------------------
InrImage* Func_AnisoGS_GetDiffusionCoeff()
{
  InrImage* res;

  if (static_AnisoGS != NULL) {
    if (static_AnisoGS->image_c!=NULL) {
      res = new InrImage(WT_FLOAT, "imagec_copy.ami.gz",  static_AnisoGS->image_c);
      (*res) = (*static_AnisoGS->image_c);
      return res;
    }
    else {
      printf("static_AnisoGS->image_c == NULL \n");
      return NULL;
    }
  }
  else
    return NULL;

} // Func_GetDiffusionCoeff()



