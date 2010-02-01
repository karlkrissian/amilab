//
// C++ Implementation: wrap_ImageAddScalar
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_ImageCos.h"

#include "AMILabConfig.h"
#include "wrapfunctions.hpp"
#include "ImageToImageFilter.h"
#include "ImageCos.h"

void wrap_ImageCos( ParamList* p)
{
    char functionname[] = "ImageCos";
    char description[]=" \n\
            Inplace computation of the cosinus of each pixel value of the image";
    char parameters[] =" \n\
            - Input Image\n\
            - Number of threads (def:1)\n\
            ";

    InrImage::ptr input;
    int num_threads = 1;
    int n=0;

  if (!get_val_smtptr_param<InrImage>( input,       p, n)) HelpAndReturn;
  if (!get_int_param(      num_threads, p, n)) HelpAndReturn;

  ImageToImageFilterParam param;
  ImageCos imcos;

  param.SetInput(input);
  param.SetNumberOfThreads(num_threads);

  imcos.SetParameters(param);
  imcos.Run();

}

