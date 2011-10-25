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

#include "NormGrad.h"

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
#include "Eigen.hpp"

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;



//----------------------------------------------------------------------
InrImage* Func_NormGrad( InrImage* im, float sigma, 
//        -------------
             int support)
{

  InrImage*       image_entree;
  InrImage*       image_der;
  InrImage*       image_res;
  GeneralGaussianFilter* filtre;
  std::string     resname;
  int             mode;
  double          tmp;

  Si (im->_format == WT_FLOAT) Alors
    image_entree = im;
  Sinon
    // conversion de l'image initiale en float
    image_entree = new InrImage( WT_FLOAT, "image_reel.inr.gz", 
                 im);
    (*image_entree) = (*im);
  FinSi

  resname = (boost::format("%s.normgrad") % im->GetName()).str();
  image_res = new InrImage(WT_FLOAT, resname.c_str() , im);

  resname = (boost::format("%s.filter") % im->GetName()).str();
  image_der = new InrImage(WT_FLOAT, resname.c_str() , im);

  Si image_entree->_tz > 1 Alors
    mode = MODE_3D; 
  Sinon
    mode = MODE_2D; 
  FinSi

  filtre = new GeneralGaussianFilter( image_entree,  mode);

  filtre->GammaNormalise(false);
  filtre->InitFiltre( sigma, MY_FILTRE_CONV );  
  filtre->SetSupportSize(support);


  Si mode == MODE_2D Alors

    filtre->MyFiltre( image_entree, image_der, 1, 0, -1);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      tmp=image_der->ValeurBuffer();
      image_res->FixeValeur(tmp*tmp);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

    filtre->MyFiltre( image_entree, image_der, 0, 1, -1);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      tmp=image_der->ValeurBuffer();
      image_res->FixeValeur(image_res->ValeurBuffer() + tmp*tmp);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

  Autrement
  Si mode == MODE_3D Alors

    filtre->MyFiltre( image_entree, image_der, 1, 0, 0);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      tmp=image_der->ValeurBuffer();
      image_res->FixeValeur(tmp*tmp);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

    filtre->MyFiltre( image_entree, image_der, 0, 1, 0);

    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      tmp=image_der->ValeurBuffer();
      image_res->FixeValeur(image_res->ValeurBuffer() + tmp*tmp);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter

    filtre->MyFiltre( image_entree, image_der, 0, 0, 1);
 
    image_res->InitBuffer();
    image_der->InitBuffer();
    Repeter
      tmp=image_der->ValeurBuffer();
      image_res->FixeValeur(image_res->ValeurBuffer() + tmp*tmp);
      image_der->IncBuffer();
    JusquA Non(image_res->IncBuffer()) FinRepeter
  FinSi
  
  image_res->InitBuffer();
  Repeter
    image_res->FixeValeur(sqrt(image_res->ValeurBuffer()));
  JusquA Non(image_res->IncBuffer()) FinRepeter

  Si image_entree!=im AlorsFait delete image_entree;
  delete filtre;
  delete image_der;

  return image_res;

}



