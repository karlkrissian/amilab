
#include "Gradient.h"
#include "GeneralGaussianFilter.h"
#include "boost/format.hpp"

//--------------------------------------------------
InrImage::ptr Gradient::Execute( )
{

  InrImage*       image_entree;
  InrImage*       image_der;
  InrImage*       image_res;
  GeneralGaussianFilter* filtre;
  std::string     resname;
  int             mode;

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

  image_der = new InrImage(WT_FLOAT, resname.c_str() , input);


  filtre = new GeneralGaussianFilter( image_entree,  mode);

  filtre->GammaNormalise(normalize);
  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  


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
  
  Si image_entree!=input AlorsFait delete image_entree;
  delete filtre;
  delete image_der;

  return boost::shared_ptr<InrImage>(image_res);

}

