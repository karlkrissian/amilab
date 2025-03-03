
#include "Gradient.h"
#include "GeneralGaussianFilter.h"
#include "boost/format.hpp"

//--------------------------------------------------
InrImage::ptr Gradient::Execute( )
{

  InrImage*       image_entree;
  InrImage*       image_res;
  GeneralGaussianFilter* filtre;
  std::string     resname;
  int             mode;
  int             x,y,z;
  Vect3D<double>   Grad;

  resname = (boost::format("%1%.normgrad") % input->GetName()).str();

  Si (input->_format == WT_FLOAT) Alors
    image_entree = input;
  Sinon
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", 
                 input);
    (*image_entree) = (*input);
  FinSi

  Si image_entree->_tz > 1 Alors
    mode = MODE_3D; 
    image_res = new InrImage(WT_FLOAT, 3,resname.c_str(), input);
  Sinon
    mode = MODE_2D; 
    image_res = new InrImage(WT_FLOAT, 2,resname.c_str(), input);
  FinSi

  resname = (boost::format("%1%.filter") % input->GetName()).str();

  filtre = new GeneralGaussianFilter( image_entree,  mode);
  filtre->Set_use_new_filter(true);
  filtre->Utilise_Image(   false);
  filtre->UtiliseHessien(  false);
  filtre->UtiliseGradient( true);
  filtre->SetPointSpreadFunctionStandDev(PSF[0],PSF[1],PSF[2]);

  std::cout << "normalize = " << normalize << std::endl;
  filtre->GammaNormalise(normalize);
  filtre->FixeGamma(1);
  filtre->InitDerivees();

  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  
  filtre->CalculFiltres( );

  // todo: improve this slow part
  image_res->InitBuffer();
  Pour( z, 0, image_res->_tz - 1)
  Pour( y, 0, image_res->_ty - 1)
  Pour( x, 0, image_res->_tx - 1)

    Grad = filtre->Gradient(x,y,z);
    image_res->VectFixeValeur(0, Grad.x);
    image_res->VectFixeValeur(1, Grad.y);
    image_res->VectFixeValeur(2, Grad.z);
    image_res->IncBuffer();

  FinPour
  FinPour
  FinPour

/*
  InrImage*       image_der;
  image_der = new InrImage(WT_FLOAT, resname.c_str() , input);

  Si mode == MODE_2D Alors

    filtre->MyFiltre( image_entree, image_der, 1, 0, -1);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(0, image_der->ValeurBuffer()
                   /input->_size_x);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

    filtre->MyFiltre( image_entree, image_der, 0, 1, -1);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(1, image_der->ValeurBuffer()
                   /input->_size_y);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

  Autrement
  Si mode == MODE_3D Alors

    filtre->MyFiltre( image_entree, image_der, 1, 0, 0);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(0, image_der->ValeurBuffer()
                   /input->_size_x);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

    filtre->MyFiltre( image_entree, image_der, 0, 1, 0);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(1, image_der->ValeurBuffer()
                   /input->_size_y);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

    filtre->MyFiltre( image_entree, image_der, 0, 0, 1);
 
    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      image_res->VectFixeValeur(2, image_der->ValeurBuffer()
                   /input->_size_z);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter
  FinSi
*/

  Si image_entree!=input AlorsFait delete image_entree;
  delete filtre;
//  delete image_der;

  return boost::shared_ptr<InrImage>(image_res);

}

