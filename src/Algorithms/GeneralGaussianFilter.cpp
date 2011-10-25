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
//  fichier GeneralGaussianFilter.cpp
//
//  Karl Krissian    Sophia Antipolis, le 17-07-98
//


#include "GeneralGaussianFilter.h"

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_verbose;



//======================================================================
// MEMBRES PRIVES
//======================================================================

//----------------------------------------------------------------------
void GeneralGaussianFilter ::  InitCoeffDerivees( )
//                                -----------------
{

  _derivees[IM_sigma][DIM_X] = 0;  
  _derivees[IM_sigma][DIM_Y] = 0;
  _derivees[IM_sigma][DIM_Z] = 0;

  _derivees[IMx_sigma][DIM_X] = 1;  
  _derivees[IMx_sigma][DIM_Y] = 0;
  _derivees[IMx_sigma][DIM_Z] = 0;

  _derivees[IMy_sigma][DIM_X] = 0;  
  _derivees[IMy_sigma][DIM_Y] = 1;
  _derivees[IMy_sigma][DIM_Z] = 0;

  _derivees[IMz_sigma][DIM_X] = 0;  
  _derivees[IMz_sigma][DIM_Y] = 0;
  _derivees[IMz_sigma][DIM_Z] = 1;

  _derivees[IMxx_sigma][DIM_X] = 2;  
  _derivees[IMxx_sigma][DIM_Y] = 0;
  _derivees[IMxx_sigma][DIM_Z] = 0;

  _derivees[IMxy_sigma][DIM_X] = 1;  
  _derivees[IMxy_sigma][DIM_Y] = 1;
  _derivees[IMxy_sigma][DIM_Z] = 0;

  _derivees[IMyy_sigma][DIM_X] = 0;  
  _derivees[IMyy_sigma][DIM_Y] = 2;
  _derivees[IMyy_sigma][DIM_Z] = 0;

  _derivees[IMzx_sigma][DIM_X] = 1;  
  _derivees[IMzx_sigma][DIM_Y] = 0;
  _derivees[IMzx_sigma][DIM_Z] = 1;

  _derivees[IMzy_sigma][DIM_X] = 0;  
  _derivees[IMzy_sigma][DIM_Y] = 1;
  _derivees[IMzy_sigma][DIM_Z] = 1;

  _derivees[IMzz_sigma][DIM_X] = 0;  
  _derivees[IMzz_sigma][DIM_Y] = 0;
  _derivees[IMzz_sigma][DIM_Z] = 2;

} // InitCoeffDerivees()

//----------------------------------------------------------------------
void GeneralGaussianFilter ::  InitNomDerivees( )
//                                ---------------
{

  _ImageNom[IM_sigma]   = "IM_sigma";
  _ImageNom[IMx_sigma]  = "IMx_sigma";
  _ImageNom[IMxx_sigma] = "IMxx_sigma";
  _ImageNom[IMxy_sigma] = "IMxy_sigma";
  _ImageNom[IMy_sigma]  = "IMy_sigma";
  _ImageNom[IMyy_sigma] = "IMyy_sigma";
  _ImageNom[IMz_sigma]  = "IMz_sigma";
  _ImageNom[IMzx_sigma] = "IMzx_sigma";
  _ImageNom[IMzy_sigma] = "IMzy_sigma";
  _ImageNom[IMzz_sigma] = "IMzz_sigma";

} // InitNomDerivees()

//======================================================================
// MEMBRES PUBLICS
//======================================================================-


/*
///
GeneralGaussianFilter ::   GeneralGaussianFilter( PTRINRIMAGE image, int dim ) 

{

  
    int i;

    _silencieux = false;

    _image_tmp  = (InrImage*) NULL;
    _image_tmp1 = (InrImage*) NULL;
    _image_tmp2 = (InrImage*) NULL;
 
    _image_initiale = image;

    _InrImage_initiale = new InrImage( _image_initiale, 
               "InrImage_initiale.inr.gz");

    _vx = image->vx;
    _vy = image->vy;
    _vz = image->vz;
    _dim = dim;

    _utilise_image    = false;
    _utilise_hessien  = false;
    _utilise_gradient = true;

    _derivees_compressees = false;

    _gamma_normalisation = false;
    _gamma = 1.0;
    _normx = _normy = _normz = 1.0;

    _sigma = _sigmax = _sigmay = _sigmaz = 0.0;

//    _sigma_unit = PIXEL_SPACE;
    _sigma_unit = REAL_SPACE;

    _OptFiltrage = false;

    _masque          = false;
    _masque_gradient = false;
    _image_masque          = (InrImage*) NULL;
    _image_masque_gradient = (InrImage*) NULL;

    Pour(i,0,NB_IMAGES-1)
      _utilise_Image_sigma[i] = false;
    FinPour

}
*/


///
GeneralGaussianFilter ::   GeneralGaussianFilter( InrImage* image, int dim ) 

{

  
    int i;

    _silencieux = false;

    _image_tmp  = (InrImage*) NULL;
    _image_tmp1 = (InrImage*) NULL;
    _image_tmp2 = (InrImage*) NULL;

   
    _InrImage_initiale = image;

_vx = image->VoxSizeX();
_vy = image->VoxSizeY();
_vz = image->VoxSizeZ();
    _dim = dim;

    _utilise_image    = false;
    _utilise_hessien  = false;
    _utilise_gradient = true;

    _derivees_compressees = false;

    _gamma_normalisation = false;
    _gamma = 1.0;
    _normx = _normy = _normz = 1.0;

    _point_spread_function_standard_deviation[0] = 0;
    _point_spread_function_standard_deviation[1] = 0;
    _point_spread_function_standard_deviation[2] = 0;
    
    _sigma = _sigmax = _sigmay = _sigmaz = 0.0;

//    _sigma_unit = PIXEL_SPACE;
    _sigma_unit = REAL_SPACE;

    _OptFiltrage = false;

    _masque          = false;
    _masque_gradient = false;
    _image_masque          = (InrImage*) NULL;
    _image_masque_gradient = (InrImage*) NULL;

    Pour(i,0,NB_IMAGES-1)
      _utilise_Image_sigma[i] = false;
    FinPour

}


GeneralGaussianFilter :: ~GeneralGaussianFilter() 
  {

    //   std::cout << " ~Filtre Rec " << std::endl;
    /*
    Si _InrImage_initiale  != (InrImage*) NULL Alors
      //      std::cout << "delete _InrImage_initiale;" << std::endl;
       delete _InrImage_initiale;
       _InrImage_initiale = (InrImage*) NULL;
    FinSi
    */

    Si _image_tmp  != (InrImage*) NULL Alors
      //cout << "delete _image_tmp;" << std::endl;
       delete _image_tmp;
       _image_tmp = (InrImage*) NULL;
    FinSi

    Si _image_tmp1 != (InrImage*) NULL Alors
      //cout << "delete _image_tmp1;" << std::endl;
       delete _image_tmp1;
       _image_tmp1 = (InrImage*) NULL;
    FinSi

    Si _image_tmp2 != (InrImage*) NULL Alors 
      //cout << "delete _image_tmp2;" << std::endl;
       delete _image_tmp2;
       _image_tmp2 = (InrImage*) NULL;
    FinSi

      //cout << "LibereDerivees();" << std::endl;
    LibereDerivees();

    //cout << " Fin ~Filtre Rec \n";

  }




//------------------------------------------------------
void GeneralGaussianFilter ::  InitFiltre(float sigma, int type)
//                                ----------
{

  
    double sigma_utilise;

  _type = type;

  Si _OptFiltrage Alors

    Si sigma < _sigma Alors
      sigma_utilise = sigma;
      _OptFiltrage = false;
      std::cerr << " Pas d'optimisation possible si le nouveau sigma est ";
      std::cerr << " inferieur a l'ancien ...\n";
    Sinon

      Si fabs(_sigma) < 1E-5 Alors
        (*_InrImage_sigma[IM_sigma])=(*_InrImage_initiale);
      FinSi

      sigma_utilise = sqrt( sigma*sigma - _sigma*_sigma);
      Si Non(_silencieux) AlorsFait 
       std::cout << " sigma " << sigma << " _sigma " << _sigma 
             << " sigma_utilise " << sigma_utilise << std::endl;
      _sigma = sigma;

    FinSi

  Sinon
    sigma_utilise = sigma;
  FinSi

  Si _sigma_unit == REAL_SPACE Alors
    _sigmax = sigma_utilise/_vx;
    _sigmay = sigma_utilise/_vy;
    _sigmaz = sigma_utilise/_vz;
  Sinon
    _sigmax = sigma_utilise;
    _sigmay = sigma_utilise;
    _sigmaz = sigma_utilise;
  FinSi

  Si GB_verbose Et Non(_silencieux) AlorsFait
 std::cout << " sigma x = " << _sigmax 
       << " sigma y = " << _sigmay 
       << " sigma z = " << _sigmaz  << std::endl;

  Si _gamma_normalisation Alors
    _normx = pow(_point_spread_function_standard_deviation[0]+_sigmax,_gamma);
    _normy = pow(_point_spread_function_standard_deviation[1]+_sigmay,_gamma);
    _normz = pow(_point_spread_function_standard_deviation[2]+_sigmaz,_gamma);
  FinSi

  switch ( _type ){

    case FILTRE_REC:
    case FILTRE_CONV:
      _type =MY_FILTRE_CONV;
  /*
    //------------------------------
    case FILTRE_REC:
    //     ----------

      E_ErrorReset();
      E_InitRecFilters(&_param_filtre);

      _param_filtre.alphaX = _sigmax;
      _param_filtre.alphaY = _sigmay;
      _param_filtre.alphaZ = _sigmaz;

      _param_filtre.bord_typeX = 
      _param_filtre.bord_typeY = 
      _param_filtre.bord_typeZ = BORD_CONT;

      _param_filtre.bord_longX = (int) floor( 4 * _param_filtre.alphaX );
      _param_filtre.bord_longY = (int) floor( 4 * _param_filtre.alphaY );
      _param_filtre.bord_longZ = (int) floor( 4 * _param_filtre.alphaZ );

      _param_filtre.verb = true;
      _param_filtre.norm_mode |= NORM_INV;
//    _param_filtre.norm_mode |= NORM_DIFF;

      _param_filtre.deriveX = 0;
      _param_filtre.deriveY = 0;
      _param_filtre.deriveZ = 0;

    break;

    //------------------------------
    case FILTRE_CONV:
    //     ----------
    // Filtres Gaussiens : epi_filter.c
      E_DefaultSepFilter( &_param_filtre_conv);


      _param_filtre_conv.vSigma.x  = _sigmax;
      _param_filtre_conv.vSigma.y  = _sigmay;
      _param_filtre_conv.vSigma.z  = _sigmaz;

     printf("%f %f %f \n",_param_filtre_conv.vSigma.x,
      _param_filtre_conv.vSigma.y,
      _param_filtre_conv.vSigma.z);

//      T_3Form( _image_initiale->vx, 
//               _image_initiale->vy, 
//               _image_initiale->vz, 
//         & _param_filtre_conv.vScale );

      T_3IForm( (int) (7.0*_sigmax), 
    (int) (7.0*_sigmay),
    (int) (7.0*_sigmaz),
    &_param_filtre_conv.vSize );
    break;
  */

    //------------------------------
    case MY_FILTRE_CONV:
    //     --------------
      Si Non(_derivees_compressees) Alors 
       Si (_image_tmp != NULL) Et
           ((_image_tmp->_tx != _InrImage_initiale->_tx) Ou 
            (_image_tmp->_ty != _InrImage_initiale->_ty) Ou 
            (_image_tmp->_tz != _InrImage_initiale->_tz))  
        Alors
          delete _image_tmp;
          _image_tmp = (InrImage*) NULL;
        FinSi

        Si _image_tmp ==  (InrImage*) NULL AlorsFait
          _image_tmp = new InrImage( WT_FLOAT, "image_temp.inr.gz",
               _InrImage_initiale);
      Sinon
       Si (_image_tmp1 !=  (InrImage*) NULL) Et
           ((_image_tmp1->_tx != _InrImage_initiale->_tx) Ou 
            (_image_tmp1->_ty != _InrImage_initiale->_ty) Ou 
            (_image_tmp1->_tz != _InrImage_initiale->_tz))  
        Alors
          delete _image_tmp1;
          _image_tmp1 =  (InrImage*) NULL;
        FinSi

  /*
        Si _image_tmp1 ==  (InrImage*) NULL AlorsFait
          _image_tmp1 = new InrImage( WT_FLOAT, "image_temp1.inr.gz",
               _InrImage_initiale);
  */

       Si (_image_tmp2 !=  (InrImage*) NULL) Et
           ((_image_tmp2->_tx != _InrImage_initiale->_tx) Ou 
            (_image_tmp2->_ty != _InrImage_initiale->_ty) Ou 
            (_image_tmp2->_tz != _InrImage_initiale->_tz))  
        Alors
          delete _image_tmp2;
          _image_tmp2 =  (InrImage*) NULL;
        FinSi

  /*
        Si _image_tmp2 ==  (InrImage*) NULL AlorsFait
          _image_tmp2 = new InrImage( WT_FLOAT, "image_temp2.inr.gz",
               _InrImage_initiale);
  */
      FinSi

      _facteur_support = 7;
      _coeff_int_gauss = false;
    break;

    default:
      Si Non(_silencieux) AlorsFait
       std::cout << " GeneralGaussianFilter::InitFiltre() \t"
    << " type de filtrage non gere " << _type << "\n";

  } // end switch

} // InitFiltre()



//------------------------------------------------------
void GeneralGaussianFilter ::  MyFiltre( InrImage* im, 
//                                --------
              InrImage* res,
               int der_x, int der_y, int der_z,
         InrImage* ImMasque)
{

  
//    GaussianFilter  filtre;
    unsigned char   continuer;
    InrImage* imageIn;
    InrImage* imageOut;
    InrImage* image_masque;
    Chaine    nom;
//    int    i;
    int       Support[3] = { 4,5,6};

  if (GB_verbose) 
    printf("MyFiltre(%d %d %d) (%2.2f, %2.2f, %2.2f)\n",der_x,der_y,der_z, 
          _sigmax,_sigmay,_sigmaz);

  Si ImMasque !=  (InrImage*) NULL Alors
    image_masque = ImMasque;
  Sinon
    image_masque =  (InrImage*) NULL;
  FinSi

  Si (_image_tmp == NULL) 
  Alors
    Si Non(_silencieux) AlorsFait
     std::cout << " GeneralGaussianFilter::MyFiltre() \t"
           << " filtre non initialise \n";
    return;
  FinSi

  _filtre.SetSupportSize( _facteur_support);
  Si _coeff_int_gauss AlorsFait _filtre.IntegraleCoeffGaussienne();


  switch ( _type ){

    case MY_FILTRE_CONV:
    //     --------------

      try
      {
        Si im==res Alors
          imageIn  = res;
          imageOut = _image_tmp;
        Sinon
          imageIn  = im;
          imageOut = res;
        FinSi
 
        Si (der_x >= 0)Et(der_x<=2) Alors

          _filtre.SetSupportSize( Support[der_x]);
          _filtre.Filtre1D( imageIn, imageOut, image_masque, 
         DIR_X, (double) _sigmax, der_x );

    Si imageOut==res Alors
            imageIn = res;        imageOut = _image_tmp;
          Sinon
            imageIn = _image_tmp; imageOut = res;
          FinSi

        FinSi

        Si (der_y >= 0)Et(der_y<=2) Alors

          Si _dim >= MODE_2D Alors

            _filtre.SetSupportSize( Support[der_y]);
            _filtre.Filtre1D( imageIn, imageOut, image_masque, 
           DIR_Y, (double) _sigmay, der_y );

      Si imageOut==res Alors
              imageIn = res;        imageOut = _image_tmp;
            Sinon
              imageIn = _image_tmp; imageOut = res;
            FinSi
          Sinon
      std::cerr<< "GeneralGaussianFilter::MyFilre()\t GaussianFilter en Y en mode < 2D.\n";
          FinSi

        FinSi

        Si (der_z >= 0)Et(der_z<=2) Alors

          Si _dim == MODE_3D Alors

            _filtre.SetSupportSize( Support[der_z]);
            _filtre.Filtre1D( imageIn, imageOut, image_masque, 
         DIR_Z, (double) _sigmaz, der_z );

      Si imageOut==res Alors
              imageIn = res;        imageOut = _image_tmp;
            Sinon
              imageIn = _image_tmp; imageOut = res;
            FinSi

          Sinon
//      std::cerr<< "GeneralGaussianFilter::MyFilre()\t GaussianFilter en Z en mode non 3D.\n";
          FinSi

        FinSi

        Si (imageIn == im)Et(im!=res) Alors
          Si Non(_silencieux) AlorsFait        
         std::cout << " GeneralGaussianFilter::MyFiltre() \t "
           << " aucun filtrage n'a ete realise ... \n";
        FinSi
        
  // imageIn est le pointeur sur l'image contenant le resultat
        Si imageIn == _image_tmp Alors
          // copie de num_image_res dans res
          _image_tmp->InitBuffer();
          res       ->InitBuffer();
          Repeter
            res->FixeValeur( _image_tmp->ValeurBuffer());
            _image_tmp->IncBuffer();
            continuer = res->IncBuffer();
          JusquA Non(continuer) FinRepeter

        FinSi

      }
      catch (GaussianFilter::OrdreNonTraite )
      {
        Si Non(_silencieux) AlorsFait        
     std::cout << " GeneralGaussianFilter::MyFiltre() \t "
         << " ordre non traite \n";
      }
      catch (GaussianFilter::BadImageType )
      {
        Si Non(_silencieux) AlorsFait        
   std::cout << " GeneralGaussianFilter::MyFiltre() \t "
               << " mauvais format d'image \n";
      }
      catch (GaussianFilter::ImagesDiffDim )
      {
        Si Non(_silencieux) AlorsFait        
     std::cout << " GeneralGaussianFilter::MyFiltre() \t "
               << " images de differentes dimensions \n";
      }

    break;

    default:
      Si Non(_silencieux) AlorsFait        
       std::cout << " GeneralGaussianFilter::MyFiltre() \t"
             << " type non traite \n";

  } // end switch


} // MyFiltre()


//------------------------------------------------------
void GeneralGaussianFilter ::  MyFiltre1D( InrImage* entree, 
//                                --------
                InrImage* sortie, InrImage* masque,
                direction_filtre dir, 
                double sigma, int ordre)
{

  
  _filtre.SetSupportSize( _facteur_support);
  Si _coeff_int_gauss AlorsFait _filtre.IntegraleCoeffGaussienne();

  _filtre.Filtre1D( entree, sortie, masque, 
        dir, sigma, ordre );


} // MyFiltre1D()


//------------------------------------------------------
void GeneralGaussianFilter ::  InitDerivees( )
//                                ------------
{

  
    int i;

  InitNomDerivees();
  InitCoeffDerivees();

  Pour(i,0,NB_IMAGES-1)
    _utilise_Image_sigma[i] = true;
  FinPour

  Si Non(_utilise_image) Alors
    _utilise_Image_sigma[ IM_sigma ] = false;
  FinSi

  Si Non(_utilise_hessien) Alors
    _utilise_Image_sigma[ IMxx_sigma ] = false;
    _utilise_Image_sigma[ IMxy_sigma ] = false;
    _utilise_Image_sigma[ IMyy_sigma ] = false;
    _utilise_Image_sigma[ IMzx_sigma ] = false;
    _utilise_Image_sigma[ IMzy_sigma ] = false;
    _utilise_Image_sigma[ IMzz_sigma ] = false;
  FinSi

  Si Non(_utilise_gradient) Alors
    _utilise_Image_sigma[ IMx_sigma ] = false;
    _utilise_Image_sigma[ IMy_sigma ] = false;
    _utilise_Image_sigma[ IMz_sigma ] = false;
  FinSi


  Si _dim == MODE_2D Alors
    _utilise_Image_sigma[ IMz_sigma  ] = false;
    _utilise_Image_sigma[ IMzx_sigma ] = false;
    _utilise_Image_sigma[ IMzy_sigma ] = false;
    _utilise_Image_sigma[ IMzz_sigma ] = false;

    Pour(i,0,NB_IMAGES-1)
      _derivees[i][DIM_Z] = -1;
    FinPour
  FinSi

  Pour(i,0,NB_IMAGES-1)
    Si _utilise_Image_sigma[i] Alors
      _InrImage_sigma[i] = new InrImage( WT_FLOAT, (char*) _ImageNom[i],_InrImage_initiale);
    FinSi
  FinPour

  _derivees_compressees = false;

} // InitDerivees()

/*
//------------------------------------------------------
void GeneralGaussianFilter ::  InitDeriveesCompressees( InrImage* masque, 
//                                -----------------------
                 int nb_points)
{

  
    int i;

  InitNomDerivees();
  InitCoeffDerivees();

  Pour(i,0,NB_IMAGES-1)
    _utilise_Image_sigma[i] = true;
  FinPour

  Si Non(_utilise_image) Alors
    _utilise_Image_sigma[ IM_sigma ] = false;
  FinSi

  Si Non(_utilise_hessien) Alors
    _utilise_Image_sigma[ IMxx_sigma ] = false;
    _utilise_Image_sigma[ IMxy_sigma ] = false;
    _utilise_Image_sigma[ IMyy_sigma ] = false;
    _utilise_Image_sigma[ IMzx_sigma ] = false;
    _utilise_Image_sigma[ IMzy_sigma ] = false;
    _utilise_Image_sigma[ IMzz_sigma ] = false;
  FinSi

  Si Non(_utilise_gradient) Alors
    _utilise_Image_sigma[ IMx_sigma ] = false;
    _utilise_Image_sigma[ IMy_sigma ] = false;
    _utilise_Image_sigma[ IMz_sigma ] = false;
  FinSi


  Si _dim == MODE_2D Alors
    _utilise_Image_sigma[ IMz_sigma  ] = false;
    _utilise_Image_sigma[ IMzx_sigma ] = false;
    _utilise_Image_sigma[ IMzy_sigma ] = false;
    _utilise_Image_sigma[ IMzz_sigma ] = false;

    Pour(i,0,NB_IMAGES-1)
      _derivees[i][DIM_Z] = -1;
    FinPour
  FinSi

  // image lissee et derivees premieres non compressee
  Pour(i,0,3)
    Si _utilise_Image_sigma[i] Alors
      _InrImage_sigma[i] = new InrImage( WT_FLOAT,  _ImageNom[i], masque);
    FinSi
  FinPour

  // derivees secondes compressees
  Pour(i,4,9)
    Si _utilise_Image_sigma[i] Alors
      _InrImage_sigma[i] = new InrImageCompressee( WT_FLOAT,  _ImageNom[i],
               masque,    nb_points );
    FinSi
  FinPour

  _derivees_compressees = true;

} // InitDeriveesCompressees()
*/

//------------------------------------------------------
void GeneralGaussianFilter ::  LibereDerivees( )
//                                --------------
{

  
    int i;

//std::cout << "Libere Derivees " << std::endl;

  Pour(i,0,NB_IMAGES-1)
    Si _utilise_Image_sigma[i] Alors
      Si _InrImage_sigma[i] != (InrImage*) NULL Alors 
      // std::cout << " delete _InrImage_sigma " << i << std::endl;
        delete _InrImage_sigma[i];
        _InrImage_sigma[i] = (InrImage*) NULL;
      FinSi
    FinSi
  FinPour


} // LibereDerivees()


//------------------------------------------------------
void GeneralGaussianFilter ::  CalculMyFiltres2D( InrImage* image_depart)
//                                -----------------
{

     // Utiliser un masque est tres difficile
     // (il faudrait le dilater en fonction de la taille du support) 
     // dans les filtrages intermedaires

     // Calcul Hxx
     Si GB_verbose Et Non(_silencieux) 
  Alors  printf(" 20 "); fflush(stdout); FinSi
     MyFiltre( image_depart,
     _InrImage_sigma[IMxx_sigma],      2,  0,  -1);


     // Convolution Derivee Gaussienne en X:
     // Factorisation pour Gx,Hxy,Hxz
     Si GB_verbose Et Non(_silencieux) 
       Alors  printf(" 1. "); fflush(stdout); FinSi
     MyFiltre( image_depart,
     _InrImage_sigma[IMxy_sigma],      1, -1, -1);

       // Gaussienne en Y: Gx
       Si GB_verbose Et Non(_silencieux) 
   Alors  printf(" 10 "); fflush(stdout); FinSi
       MyFiltre( _InrImage_sigma[IMxy_sigma],
       _InrImage_sigma[IMx_sigma],    -1,  0, -1);

       // Hxy
       Si GB_verbose Et Non(_silencieux) 
   Alors  printf(" 11 "); fflush(stdout); FinSi
       MyFiltre( _InrImage_sigma[IMxy_sigma], 
       _InrImage_sigma[IMxy_sigma],   -1,  1, -1);

     // Convolution Gaussienne en X:
     // Factorisation pour Gy,Gz,Hyy,Hyz,Hzz

     Si GB_verbose Et Non(_silencieux) 
       Alors  printf(" 0. "); fflush(stdout); FinSi
     MyFiltre( image_depart,
     _InrImage_sigma[IMyy_sigma],      0, -1, -1);

       // Derivee Gaussienne en Y: Gy
       Si GB_verbose Et Non(_silencieux) 
   Alors  printf(" 01 "); fflush(stdout); FinSi
       MyFiltre( _InrImage_sigma[IMyy_sigma],
       _InrImage_sigma[IMy_sigma],    -1,  1, -1);


       // Gaussienne en Y: I

         // I
         Si _utilise_image Alors
           Si GB_verbose Alors  printf(" *00 "); fflush(stdout); FinSi
           MyFiltre( _InrImage_sigma[IMyy_sigma], 
         _InrImage_sigma[IM_sigma],  -1, 0,  -1 );
         FinSi


       // Hyy
       Si GB_verbose Et Non(_silencieux) 
     Alors  printf(" 02 "); fflush(stdout); FinSi
       MyFiltre( _InrImage_sigma[IMyy_sigma], 
       _InrImage_sigma[IMyy_sigma],   -1,  2,  -1);


     Si GB_verbose Et Non(_silencieux) AlorsFait
       printf("\n");


} // CalculMyFiltres2D()


//------------------------------------------------------
void GeneralGaussianFilter ::  CalculMyFiltres( InrImage* image_depart)
//                                ---------------
{


  Si _dim == MODE_2D Alors
    CalculMyFiltres2D( image_depart);
    return;
  FinSi

     // Utiliser un masque est tres difficile
     // (il faudrait le dillater en fonction de la taille du support) 
     // dans les filtrages intermedaires

     // Calcul Hxx
     Si GB_verbose Et Non(_silencieux) 
       Alors  printf(" 200 "); fflush(stdout); FinSi
     MyFiltre( image_depart,
     _InrImage_sigma[IMxx_sigma],      2,  0,  -1);

     MyFiltre( _InrImage_sigma[IMxx_sigma],
     _InrImage_sigma[IMxx_sigma],     -1, -1,   0,
     _image_masque);

     // Convolution Derivee Gaussienne en X:
     // Factorisation pour Gx,Hxy,Hxz
     Si GB_verbose Et Non(_silencieux) 
       Alors  printf(" 1.. "); fflush(stdout); FinSi
     MyFiltre( image_depart,
     _InrImage_sigma[IMxy_sigma],      1, -1, -1);

       // Gaussienne en Y: Gx, Hxz
       Si GB_verbose Et Non(_silencieux) 
   Alors  printf(" 10. "); fflush(stdout); FinSi
       MyFiltre( _InrImage_sigma[IMxy_sigma],
       _InrImage_sigma[IMx_sigma],    -1,  0, -1);

         // Hxz
         Si GB_verbose Et Non(_silencieux) 
     Alors  printf(" 101 "); fflush(stdout); FinSi
         MyFiltre( _InrImage_sigma[IMx_sigma], 
         _InrImage_sigma[IMxz_sigma], -1, -1,  1,
         _image_masque );

         // Gx
         Si GB_verbose Et Non(_silencieux) 
     Alors  printf(" 100 "); fflush(stdout); FinSi
         MyFiltre( _InrImage_sigma[IMx_sigma], 
         _InrImage_sigma[IMx_sigma],  -1, -1,  0,
         _image_masque_gradient);

       // Hxy
       Si GB_verbose Et Non(_silencieux) 
   Alors  printf(" 110 "); fflush(stdout); FinSi
       MyFiltre( _InrImage_sigma[IMxy_sigma], 
       _InrImage_sigma[IMxy_sigma],   -1,  1, -1);
       MyFiltre( _InrImage_sigma[IMxy_sigma], 
       _InrImage_sigma[IMxy_sigma],   -1, -1,  0,
       _image_masque);


     // Convolution Gaussienne en X:
     // Factorisation pour Gy,Gz,Hyy,Hyz,Hzz

     Si GB_verbose Et Non(_silencieux) 
       Alors  printf(" 0.. "); fflush(stdout); FinSi
     MyFiltre( image_depart,
     _InrImage_sigma[IMyy_sigma],      0, -1, -1);

       // Derivee Gaussienne en Y: Gy, Hyz
       Si GB_verbose Et Non(_silencieux) 
   Alors  printf(" 01. "); fflush(stdout); FinSi
       MyFiltre( _InrImage_sigma[IMyy_sigma],
       _InrImage_sigma[IMy_sigma],    -1,  1, -1);

         // Hyz
         Si GB_verbose Et Non(_silencieux) 
     Alors  printf(" 011 "); fflush(stdout); FinSi
         MyFiltre( _InrImage_sigma[IMy_sigma], 
         _InrImage_sigma[IMyz_sigma], -1, -1,  1, 
         _image_masque);

         // Gy
         Si GB_verbose Et Non(_silencieux) 
     Alors  printf(" 010 "); fflush(stdout); FinSi
         MyFiltre( _InrImage_sigma[IMy_sigma], 
         _InrImage_sigma[IMy_sigma],  -1, -1,  0,
         _image_masque_gradient);

       // Gaussienne en Y: Hyz, Gz
       Si GB_verbose Et Non(_silencieux) 
   Alors  printf(" 00. "); fflush(stdout); FinSi
       MyFiltre( _InrImage_sigma[IMyy_sigma],
       _InrImage_sigma[IMz_sigma],    -1,  0, -1);

         // I
         Si _utilise_image Alors
           Si GB_verbose Et Non(_silencieux) 
       Alors  printf(" *000 "); fflush(stdout); FinSi
           MyFiltre( _InrImage_sigma[IMz_sigma], 
         _InrImage_sigma[IM_sigma],  -1, -1,  0 );
         FinSi

         // Hzz
         Si GB_verbose Et Non(_silencieux) 
     Alors  printf(" 002 "); fflush(stdout); FinSi
         MyFiltre( _InrImage_sigma[IMz_sigma], 
         _InrImage_sigma[IMzz_sigma], -1, -1,  2,
         _image_masque);

         // Gz
         Si GB_verbose Et Non(_silencieux) 
     Alors  printf(" 001 "); fflush(stdout); FinSi
         MyFiltre( _InrImage_sigma[IMz_sigma], 
         _InrImage_sigma[IMz_sigma],  -1, -1,  1,
         _image_masque_gradient);


       // Hyy
       Si GB_verbose Et Non(_silencieux) 
   Alors  printf(" 020 "); fflush(stdout); FinSi
       MyFiltre( _InrImage_sigma[IMyy_sigma], 
       _InrImage_sigma[IMyy_sigma],   -1,  2,  -1);
       MyFiltre( _InrImage_sigma[IMyy_sigma], 
       _InrImage_sigma[IMyy_sigma],   -1, -1,   0,
       _image_masque);


     Si GB_verbose Et Non(_silencieux) AlorsFait
       printf("\n");


} // CalculMyFiltres()


/*
//------------------------------------------------------
void GeneralGaussianFilter ::  CalculMyFiltresCompressees( InrImage* image_depart)
//                                --------------------------
{
  GaussianFilter  filtre;

  Si _image_tmp1 ==  (InrImage*) NULL AlorsFait
    _image_tmp1 = new InrImage( WT_FLOAT, "image_temp1.inr.gz",
               _InrImage_initiale);

  Si _image_tmp2 ==  (InrImage*) NULL AlorsFait
    _image_tmp2 = new InrImage( WT_FLOAT, "image_temp2.inr.gz",
               _InrImage_initiale);

  Si (_image_tmp1 == (InrImage*) NULL) Ou 
     (_image_tmp2 == (InrImage*) NULL)  Alors
    Si Non(_silencieux) AlorsFait 
     std::cout << " GeneralGaussianFilter::CalculMyFiltresCompressees() \t"
           << " filtre non initialise \n";
    return;
  FinSi

  filtre.SetSupportSize( _facteur_support);
  Si _coeff_int_gauss AlorsFait filtre.IntegraleCoeffGaussienne();

     // Utiliser un masque est tres difficile
     // (il faudrait le dillater en fonction de la taille du support) 
     // dans les filtrages intermedaires

     // Calcul Hxx
     Si GB_verbose Alors  printf(" 200 "); fflush(stdout); FinSi

     filtre.Filtre1D( image_depart, _image_tmp1, (InrImage*) NULL, 
          DIR_X, _sigmax, 2 );
     filtre.Filtre1D( _image_tmp1,   _image_tmp2, (InrImage*) NULL,
          DIR_Y, _sigmay, 0 );

     filtre.Filtre1DCompressee( _image_tmp2, 
        (InrImageCompressee*) _InrImage_sigma[IMxx_sigma], 
        _image_masque, 
        DIR_Z, _sigmaz, 0 );

     // Convolution Derivee Gaussienne en X:
     // Factorisation pour Gx,Hxy,Hxz
     Si GB_verbose Alors  printf(" 1.. "); fflush(stdout); FinSi

     filtre.Filtre1D( image_depart, _image_tmp1, (InrImage*) NULL, 
          DIR_X, _sigmax, 1 );

       // Gaussienne en Y: Gx, Hxz
       Si GB_verbose Alors  printf(" 10. "); fflush(stdout); FinSi
       filtre.Filtre1D( _image_tmp1,   _image_tmp2, (InrImage*) NULL,
              DIR_Y, _sigmay, 0 );

         // Hxz
         Si GB_verbose Alors  printf(" 101 "); fflush(stdout); FinSi
         filtre.Filtre1DCompressee( _image_tmp2, 
            (InrImageCompressee*) _InrImage_sigma[IMxz_sigma], 
            _image_masque, 
            DIR_Z, _sigmaz, 1 );

         // Gx
         Si GB_verbose Alors  printf(" 100 "); fflush(stdout); FinSi
         filtre.Filtre1D( _image_tmp2, _InrImage_sigma[IMx_sigma], 
            _image_masque_gradient, 
            DIR_Z, _sigmaz, 0 );

       // Hxy
       Si GB_verbose Alors  printf(" 110 "); fflush(stdout); FinSi
       filtre.Filtre1D( _image_tmp1,   _image_tmp2, (InrImage*) NULL,
              DIR_Y, _sigmay, 1 );

       filtre.Filtre1DCompressee( _image_tmp2, 
          (InrImageCompressee*) _InrImage_sigma[IMxy_sigma], 
          _image_masque, 
          DIR_Z, _sigmaz, 0 );

     // Convolution Gaussienne en X:
     // Factorisation pour Gy,Gz,Hyy,Hyz,Hzz

     Si GB_verbose Alors  printf(" 0.. "); fflush(stdout); FinSi
     filtre.Filtre1D( image_depart, _image_tmp1, (InrImage*) NULL, 
          DIR_X, _sigmax, 0 );

       // Derivee Gaussienne en Y: Gy, Hyz
       Si GB_verbose Alors  printf(" 01. "); fflush(stdout); FinSi
       filtre.Filtre1D( _image_tmp1,   _image_tmp2, (InrImage*) NULL,
              DIR_Y, _sigmay, 1 );

         // Hyz
         Si GB_verbose Alors  printf(" 011 "); fflush(stdout); FinSi
         filtre.Filtre1DCompressee( _image_tmp2, 
            (InrImageCompressee*) _InrImage_sigma[IMyz_sigma], 
            _image_masque, 
            DIR_Z, _sigmaz, 1 );

         // Gy
         Si GB_verbose Alors  printf(" 010 "); fflush(stdout); FinSi
         filtre.Filtre1D( _image_tmp2, _InrImage_sigma[IMy_sigma], 
            _image_masque_gradient, 
            DIR_Z, _sigmaz, 0 );

       // Gaussienne en Y: Hyz, Gz
       Si GB_verbose Alors  printf(" 00. "); fflush(stdout); FinSi
       filtre.Filtre1D( _image_tmp1,   _image_tmp2, (InrImage*) NULL,
              DIR_Y, _sigmay, 0 );

         // I
         Si _utilise_image Alors
           Si GB_verbose Alors  printf(" *000 "); fflush(stdout); FinSi
           filtre.Filtre1D( _image_tmp2, _InrImage_sigma[IM_sigma], 
          (InrImage*) NULL, 
          DIR_Z, _sigmaz, 0 );
         FinSi

         // Hzz
         Si GB_verbose Alors  printf(" 002 "); fflush(stdout); FinSi
         filtre.Filtre1DCompressee( _image_tmp2, 
            (InrImageCompressee*) _InrImage_sigma[IMzz_sigma], 
            _image_masque, 
            DIR_Z, _sigmaz, 2 );

         // Gz
         Si GB_verbose Alors  printf(" 001 "); fflush(stdout); FinSi
         filtre.Filtre1D( _image_tmp2, _InrImage_sigma[IMz_sigma], 
            _image_masque_gradient, 
            DIR_Z, _sigmaz, 1 );

       // Hyy
       Si GB_verbose Alors  printf(" 020 "); fflush(stdout); FinSi
       filtre.Filtre1D( _image_tmp1,   _image_tmp2, (InrImage*) NULL,
              DIR_Y, _sigmay, 2 );
       filtre.Filtre1DCompressee( _image_tmp2, 
          (InrImageCompressee*) _InrImage_sigma[IMyy_sigma], 
          _image_masque, 
          DIR_Z, _sigmaz, 0 );

     Si GB_verbose AlorsFait
       printf("\n");


} // CalculMyFiltresCompressees()

*/
//------------------------------------------------------
void GeneralGaussianFilter ::  CalculFiltres( InrImage* mask )
//                                -------------
{

   
    int    i;
    InrImage* image_depart;

  // Optimisation particuliere
  Si _utilise_gradient Et _utilise_hessien Et _type==MY_FILTRE_CONV Alors


     Si _OptFiltrage Alors
       image_depart = _InrImage_sigma[IM_sigma];
     Sinon
       image_depart = _InrImage_initiale;
     FinSi

     Si Non(_derivees_compressees) Alors
       CalculMyFiltres( image_depart);   
     Sinon
//       CalculMyFiltresCompressees( image_depart);   
     FinSi

  Sinon

  Pour(i,0,NB_IMAGES-1)
    Si _utilise_Image_sigma[i] Alors
     Si GB_verbose  Et Non(_silencieux) Alors
       printf(" %s ",(char*) _ImageNom[i]);
       fflush(stdout);
     FinSi


      switch ( _type ){
  
        case FILTRE_CONV:
        case FILTRE_REC :
        //     -----------
  fprintf(stderr,"GeneralGaussianFilter::CalculFiltres() options FILTRE_CONV or FILTRE_REC not available anymore ... \n");
        break;

       case MY_FILTRE_CONV :
       //     --------------
         MyFiltre( _InrImage_initiale, _InrImage_sigma[i],  
       _derivees[i][DIM_X], 
       _derivees[i][DIM_Y],
       _derivees[i][DIM_Z],
       mask);

       break;

      } // end switch
    FinSi
  FinPour
  Si GB_verbose  Et Non(_silencieux) AlorsFait printf("\n");

  FinSi

} // CalculFiltres()


//------------------------------------------------------
Vect3D<double> GeneralGaussianFilter :: Gradient( int x, int y, int z)
//                                         --------
      throw (GradientNotComputed)
{

  double gx,gy,gz; 

  Si Non(_utilise_gradient) Alors
    throw GradientNotComputed();
  FinSi

  gx = gy = gz = 0.0;

  switch ( _type ){

    case FILTRE_REC:
        gx =  (*(*this)(IMx_sigma))(x,y,z);
        gy =  (*(*this)(IMy_sigma))(x,y,z);
        Si _dim == MODE_3D AlorsFait gz =  (*(*this)(IMz_sigma))(x,y,z);
    break;

    case FILTRE_CONV:
        gx =  -(*(*this)(IMx_sigma))(x,y,z);
        gy =  -(*(*this)(IMy_sigma))(x,y,z);
        Si _dim == MODE_3D AlorsFait gz =  -(*(*this)(IMz_sigma))(x,y,z);
    break;

    case MY_FILTRE_CONV:
        gx =  (*(*this)(IMx_sigma))(x,y,z);
        gy =  (*(*this)(IMy_sigma))(x,y,z);
        Si _dim == MODE_3D AlorsFait gz =  (*(*this)(IMz_sigma))(x,y,z);
    break;

  } // end switch

  gx /= _vx;
  gy /= _vy;
  gz /= _vz;

  Si _gamma_normalisation Alors
    gx *= _normx;
    gy *= _normy;
    gz *= _normz;
  FinSi

  return Vect3D<double>(gx,gy,gz);

} // Gradient()


//------------------------------------------------------
Vect2D<double> GeneralGaussianFilter :: Gradient( int x, int y)
//                                         --------
      throw (GradientNotComputed)
{

  double gx,gy; 

  Si Non(_utilise_gradient) Alors
    throw GradientNotComputed();
  FinSi

  gx = gy = 0.0;

  switch ( _type ){

    case FILTRE_REC:
        gx =  (*(*this)(IMx_sigma))(x,y);
        gy =  (*(*this)(IMy_sigma))(x,y);
    break;

    case FILTRE_CONV:
        gx =  -(*(*this)(IMx_sigma))(x,y);
        gy =  -(*(*this)(IMy_sigma))(x,y);
    break;

    case MY_FILTRE_CONV:
        gx =  (*(*this)(IMx_sigma))(x,y);
        gy =  (*(*this)(IMy_sigma))(x,y);
    break;

  } // end switch

  gx /= _vx;
  gy /= _vy;

  Si _gamma_normalisation Alors
    gx *= _normx;
    gy *= _normy;
  FinSi

  return Vect2D<double>(gx,gy);

} // Gradient()


//------------------------------------------------------
Vect3D<double> GeneralGaussianFilter :: Gradient( const double& x, const double& y,  const double& z) 
      throw (GradientNotComputed)
{

  double gx,gy,gz; 

  Si Non(_utilise_gradient) Alors
    throw GradientNotComputed();
  FinSi

  gx =  (*this)(IMx_sigma)->InterpLinIntensite(x,y,z);
  gy =  (*this)(IMy_sigma)->InterpLinIntensite(x,y,z);
  gz =  (*this)(IMz_sigma)->InterpLinIntensite(x,y,z);

  // Pourquoi ???
  Si (_type == FILTRE_CONV) Alors
    gx*= -1.0;
    gy*= -1.0;
    gz*= -1.0;
  FinSi

  gx /= _vx;
  gy /= _vy;
  gz /= _vz;

  Si _gamma_normalisation Alors
    gx *= _normx;
    gy *= _normy;
    gz *= _normz;
  FinSi

  return Vect3D<double>(gx,gy,gz);

} // Gradient()


//------------------------------------------------------
void GeneralGaussianFilter :: InitHessienDepuisGrad( )
//                               ---------------------
{

  _filtre_x.InitGaussienne( _sigmax, 5, 1);
  _filtre_y.InitGaussienne( _sigmay, 5, 1);
  _filtre_z.InitGaussienne( _sigmaz, 5, 1);

} // InitHessienDepuisGrad()


//------------------------------------------------------
//
// filtre doit etre initialise dans les 3 directions 
// a l'aide de 
// InitHessienDepuisGrad( image)
// Cette procedure n'est pas equivalente
// au filtrage initial direct ...
//
void GeneralGaussianFilter :: HessienDepuisGrad( 
//                               -----------------
       double* hessien, int x, int y, int z
    )
    throw (GradientNotComputed)
{

  
    double Hxx,Hxy,Hxz,Hyy,Hyz,Hzz;
    double     coeffx, coeffy, coeffz;


  Si Non(_utilise_gradient) Alors
    throw GradientNotComputed();
  FinSi

  Hxx = _filtre_x .Filtre1DPoint( (*this)(IMx_sigma), DIR_X, x,y,z );

  Hxy = _filtre_y .Filtre1DPoint( (*this)(IMx_sigma), DIR_Y, x,y,z );
  Hyy = _filtre_y .Filtre1DPoint( (*this)(IMy_sigma), DIR_Y, x,y,z );

  Hxz = _filtre_z .Filtre1DPoint( (*this)(IMx_sigma), DIR_Z, x,y,z );
  Hyz = _filtre_z .Filtre1DPoint( (*this)(IMy_sigma), DIR_Z, x,y,z );
  Hzz = _filtre_z .Filtre1DPoint( (*this)(IMz_sigma), DIR_Z, x,y,z );


  coeffx = 1.0/_vx;  
  coeffy = 1.0/_vy;  
  coeffz = 1.0/_vz;  

  Si _gamma_normalisation Alors
    coeffx /= _normx;
    coeffy /= _normy;
    coeffz /= _normz;
  FinSi

  hessien[0] =               Hxx / coeffx / coeffx;
  hessien[1] = hessien[3] =  Hxy / coeffx / coeffy;
  hessien[2] = hessien[6] =  Hxz / coeffx / coeffz;
  hessien[4] =               Hyy / coeffy / coeffy;
  hessien[5] = hessien[7] =  Hyz / coeffz / coeffy;
  hessien[8] =               Hzz / coeffz / coeffz;

} // HessienDepuisGrad()


//------------------------------------------------------
void GeneralGaussianFilter :: Hessien2D( double* hessien,
//                               ---------
            int x, int y)
      throw (HessianNotComputed)
{

  
    double coeffx, coeffy;
    int z;

  z = 0;

  Si Non(_utilise_hessien) Alors
    throw HessianNotComputed();
  FinSi

  if (_sigma_unit!=REAL_SPACE) {
    coeffx = 1.0/_vx;  
    coeffy = 1.0/_vy;  
  }
  else {
    coeffx=coeffy=1.0;
  }


  Si _gamma_normalisation Alors
    coeffx /= _normx;
    coeffy /= _normy;
  FinSi

    hessien[0] =               (*(*this)(IMxx_sigma))(x,y,z) / coeffx / coeffx;
    hessien[1] = hessien[2] =  (*(*this)(IMxy_sigma))(x,y,z) / coeffx / coeffy;
    hessien[3] =               (*(*this)(IMyy_sigma))(x,y,z) / coeffy / coeffy;
 
} // Hessien2D()


//------------------------------------------------------
void GeneralGaussianFilter :: Hessien( double* hessien,
//                               -------
            int x, int y, int z)
      throw (HessianNotComputed)
{

  
    double coeffx, coeffy, coeffz;

  Si Non(_utilise_hessien) Alors
    throw HessianNotComputed();
  FinSi

  if (_sigma_unit!=REAL_SPACE) {
    coeffx = 1.0/_vx;  
    coeffy = 1.0/_vy;  
    coeffz = 1.0/_vz;  
  }
  else {
    coeffx=coeffy=coeffz=1.0;
  }


  Si _gamma_normalisation Alors
    coeffx /= _normx;
    coeffy /= _normy;
    coeffz /= _normz;
  FinSi

    hessien[0] =               (*(*this)(IMxx_sigma))(x,y,z) / coeffx / coeffx;
    hessien[1] = hessien[3] =  (*(*this)(IMxy_sigma))(x,y,z) / coeffx / coeffy;
    hessien[4] =               (*(*this)(IMyy_sigma))(x,y,z) / coeffy / coeffy;
    Si _dim == MODE_2D Alors
      hessien[2] = hessien[6] =  0.0;
      hessien[5] = hessien[7] =  0.0;
      hessien[8] =               0.0;
    Sinon
      hessien[2] = hessien[6] =  (*(*this)(IMzx_sigma))(x,y,z) / coeffx / coeffz;
      hessien[5] = hessien[7] =  (*(*this)(IMzy_sigma))(x,y,z) / coeffz / coeffy;
      hessien[8] =               (*(*this)(IMzz_sigma))(x,y,z) / coeffz / coeffz;
    FinSi

 
} // Hessien()
