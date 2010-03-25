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

#include "VarContexts.hpp"
#include "paramlist.h"
#include "inrimage.hpp"
#include "DeriveesLissees.hpp"
#include "CurvaturasPrincipales.hpp"
#include "DirPrincipales.hpp"
//#include "gradiente3D.c"
#include "FloatMatrix.hpp"

extern    VarContexts  Vars;
extern    unsigned char GB_debug;


// TODO: get rid of those static variables !!!
static InrImage::ptr        im_graddir;
static InrImage::ptr        im_gradnorm;

static InrImage::ptr        im_maxcurv;
static InrImage::ptr        im_mincurv;

static InrImage::ptr        imdir_maxcurv;
static InrImage::ptr        imdir_mincurv;

//----------------------------------------------------------------------
void EstimeCourbures( float gradient[3], float hessien[3][3], void* data)
//   ---------------
{

  

    float vmax[3];
    float vmin[3];
    float lmin;
    float lmax;

    unsigned char          fixe_zero;

    float norm;

  //---------- Calcul des vecteurs propres et des valeurs propres 
  //           de la matrice de diffusion : grad, e1, e2

  fixe_zero = false;

  Si (gradient[0]*gradient[0]+
      gradient[1]*gradient[1]+
      gradient[2]*gradient[2])<1E-6 Alors
  
    fixe_zero = true;
  FinSi


  Si Non(fixe_zero) Alors

      Si CurvaturasPrincipales(  hessien, 
				 (float*) gradient, 
				 (float*) vmax, 
				 (float*) vmin, 
				 &lmax, &lmin,
				 1E-2) != -1 Alors

    	  im_mincurv->FixeValeur(lmin);
   	  im_maxcurv->FixeValeur(lmax);

          imdir_mincurv->VectFixeValeurs(vmin[0], vmin[1], vmin[2]);
    	  imdir_maxcurv->VectFixeValeurs(vmax[0], vmax[1], vmax[2]);

	  norm = sqrt(
		      gradient[0]*gradient[0]+
		      gradient[1]*gradient[1]+
		      gradient[2]*gradient[2]
		      );
          im_gradnorm->FixeValeur( norm);

          Si norm > 1E-2 Alors
            im_graddir->VectFixeValeurs(gradient[0]/norm,
					gradient[1]/norm,
					gradient[2]/norm);
          Sinon
  	    im_graddir->VectFixeValeurs(0,0,0);
          FinSi
      Sinon
        fixe_zero = true;
      FinSi

  FinSi

  Si fixe_zero Alors

      im_gradnorm->FixeValeur(0.0);
      im_graddir->VectFixeValeurs(0.0, 0.0, 0.0);
      im_mincurv->FixeValeur(0.0);
      im_maxcurv->FixeValeur(0.0);

      imdir_mincurv->VectFixeValeurs(0.0, 0.0, 0.0);
      imdir_maxcurv->VectFixeValeurs(0.0, 0.0, 0.0);

  FinSi

  im_gradnorm  ->IncBuffer();
  im_graddir   ->IncBuffer();
  im_mincurv   ->IncBuffer();
  im_maxcurv   ->IncBuffer();
  imdir_mincurv->IncBuffer();
  imdir_maxcurv->IncBuffer();

} // EstimeCourbures()


//----------------------------------------------------------------------
unsigned char  Func_Curvatures( InrImage* image_initiale, const char* varname, 
//       ---------------
			  float sigma)
{

  
    InrImage* image_entree;
    char      resname[100];
    DeriveesLissees* DerLiss;


  Si (image_initiale->_format == WT_FLOAT) Alors
    image_entree = image_initiale;
  Sinon
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_float.inr.gz", 
				 image_initiale);
    (*image_entree) = (*image_initiale);
  FinSi


  DerLiss = new DeriveesLissees(image_entree, sigma,MODE_3D);


  im_gradnorm = InrImage::ptr(new InrImage(WT_FLOAT,"curv-gradnorm.inr.gz", image_entree));
  im_mincurv  = InrImage::ptr(new InrImage(WT_FLOAT, "curv-mincurv.inr.gz", image_entree));
  im_maxcurv  = InrImage::ptr(new InrImage(WT_FLOAT, "curv-maxcurv.inr.gz", image_entree));

  im_graddir    = InrImage::ptr(new InrImage(WT_FLOAT, 3,"curv-graddir.inr.gz", 
			       image_entree));
  imdir_mincurv = InrImage::ptr(new InrImage(WT_FLOAT, 3,"curv-dirmincurv.inr.gz", 
			       image_entree));
  imdir_maxcurv = InrImage::ptr(new InrImage(WT_FLOAT, 3,"curv-dirmaxcurv.inr.gz", 
			       image_entree));

  //
  // Initialisation des buffers et calcul des courbures
  //
  image_entree ->InitBuffer();
  im_gradnorm  ->InitBuffer();
  im_graddir   ->InitBuffer();
  im_mincurv   ->InitBuffer();
  im_maxcurv   ->InitBuffer();
  imdir_mincurv->InitBuffer();
  imdir_maxcurv->InitBuffer();


  DerLiss->CalculFonction3D( image_entree, 
			     (void*) EstimeCourbures,
			     (void*) NULL ); 

  delete DerLiss;


  // Creation des nouvelles variables 
  sprintf(resname,"%s_gnorm",varname);

  Vars.AddVar<InrImage>(resname,im_gradnorm);

  sprintf(resname,"%s_gdir",varname);
  Vars.AddVar<InrImage>(resname,im_graddir);

  sprintf(resname,"%s_mcurv",varname);
  Vars.AddVar<InrImage>(resname,im_mincurv);

  sprintf(resname,"%s_Mcurv",varname);
  Vars.AddVar<InrImage>(resname,im_maxcurv);

  sprintf(resname,"%s_mcurvdir",varname);
  Vars.AddVar<InrImage>(resname,imdir_mincurv);

  sprintf(resname,"%s_Mcurvdir",varname);
  Vars.AddVar<InrImage>(resname,imdir_maxcurv);


  Si image_entree != image_initiale AlorsFait
    delete image_entree;


  return true;

} // Func_Curvatures()
