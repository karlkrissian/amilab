
#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "LocalStructure.h"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "VarContexts.hpp"
#include "style.hpp"
//#include "math1.hpp"
#include "inrimage.hpp"
#include "GeneralGaussianFilter.h"
#include "FloatMatrix.hpp"
#include "Eigen.hpp"

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;
COMMON_VAR_IMPORT unsigned char GB_verbose;


namespace ami {

  /**
   * Func_StructureTensorHessian
   *  the mask is used in the filtering part  for the moment
   */
  unsigned char StructureTensorH( InrImage* image_initiale, 
  //            ----------------
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
      FloatMatrix     matriceinit(3,3);
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

      int type_filtre;
      int dimension;

    //  verbose = true;

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
    filtre->Set_use_new_filter(true);
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


}
