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

#include "wrap_ImageAddScalar.h"

#include "AMILabConfig.h"
#include "wrapfunctions.hpp"
#include "ImageToImageFilter.h"
#include "ImageAddScalar.h"

void wrap_ImageAddScalar( ParamList* p)
{
    char functionname[] = "ImageAddScalar";
    char description[]=" \n\
            Adds a scalar to an image";
    char parameters[] =" \n\
            - Input Image\n\
            - Number: value to add (def:0)\n\
            - Number of threads (def:1)\n\
            - Mode (def:1) 1: use iterators, 2: use pointers\n\
            ";

    InrImage::ptr input;
    float val = 0;
    int num_threads = 1;
    int mode = 1;
    int n=0;

  if (!get_imageptr_param( input,       p, n)) HelpAndReturn;
  if (!get_float_param(    val,         p, n)) HelpAndReturn;
  if (!get_int_param(      num_threads, p, n)) HelpAndReturn;
  if (!get_int_param(      mode,        p, n)) HelpAndReturn;

  ImageToImageFilterParam param;
  ImageAddScalar add_scalar;

  param.SetInput(input);
  param.SetNumberOfThreads(num_threads);

  add_scalar.SetParameters(param);
  add_scalar.SetScalarValue(val);
  cout << "mode = " << mode << endl;
  add_scalar.SetMode(mode);
  add_scalar.Run();

}

