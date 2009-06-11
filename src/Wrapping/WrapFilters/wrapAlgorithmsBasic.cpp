//
// C++ Implementation: wrapAMIFluid
//
// Description:
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "fonctions.h"
#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include <pthread.h>

#include "AMILabConfig.h"
#include "amilab_messages.h"

extern VarContexts  Vars;

#include "wrapAlgorithmsBasic.h"
#include "imageextent.h"

//-------

void wrapAlgorithmsBasic()
{
   Vars.AddVar(type_c_image_function,"FastLocalSumDir", (void*) wrapFastLocalSumDir);
   Vars.AddVar(type_c_image_function,"FastLocalSumDir2",(void*) wrapFastLocalSumDir2);
}


// Wrapping functions:
//--------------------------------------------------------------------------------
InrImage* wrapFastLocalSumDir(ParamList* p)
{
    char functionname[] = "FastLocalSumDir";
    char description[]=" \n\
      Computes the local average of pixel (or voxel) values in a window \n\
      and along the given axis direction \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              wsize: (def:1) window will be (2*wsize+1)^n\n\
              axis: (def:0) 0,1 or 2 for X, Y or Z\n\
            ";

  InrImage* input;
  InrImage::ptr input1;
  int wsize=1;
  int axis=0;
  int n = 0;
  InrImage* result;

  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(    wsize,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(    axis,       p, n)) HelpAndReturnNULL;

  if (input->GetFormat() != WT_FLOAT) {
    input1 = InrImage::ptr(new InrImage( WT_FLOAT, "input_float.ami.gz", input));
    (*input1)=(*input);
  } else {
    input1 = InrImage::ptr(input,smartpointer_nodeleter<InrImage>());
  }

  result = new InrImage( WT_FLOAT, "FastLocalSumDir.ami.gz", input);
  (*result)=(*input);

  ImageExtent<int> extent(input);

  FastLocalSumDir<float>(input1.get(),result,wsize,axis,extent);

  return result;
} // wrapFastLocalSumDir


//--------------------------------------------------------------------------------
InrImage* wrapFastLocalSumDir2(ParamList* p)
{
    char functionname[] = "FastLocalSumDir2";
    char description[]=" \n\
      Computes the local average of pixel (or voxel) values in a window \n\
      and along the X axis direction, new version \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              wsize: (def:1) window will be (2*wsize+1)^n\n\
              axis: (def:0) 0,1 or 2 for X, Y or Z\n\
            ";

  InrImage* input;
  InrImage::ptr input1;
  int wsize=1;
  int n = 0;
  int axis=0;
  InrImage* result;

  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(    wsize,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(    axis,       p, n)) HelpAndReturnNULL;

  if (input->GetFormat() != WT_FLOAT) {
    input1 = InrImage::ptr(new InrImage( WT_FLOAT, "input_float.ami.gz", input));
    (*input1)=(*input);
  } else {
    input1 = InrImage::ptr(input,smartpointer_nodeleter<InrImage>());
  }

  result = new InrImage( WT_FLOAT, "FastLocalSumDir2.ami.gz", input);
  (*result)=(*input);

  ImageExtent<int> extent(input);

  if (axis==0)
    FastLocalSumX_noborder<float,unsigned char> (input1.get(),result,wsize,extent);
  else
  if (axis==1)
    FastLocalSumY_noborder<float,unsigned short>(input1.get(),result,wsize,extent);
  else
  if (axis==2)
    FastLocalSumZ_noborder<float,unsigned int>  (input1.get(),result,wsize,extent);
  else
    FILE_ERROR("Wrong axis number (0,1 or 2 for X,Y or Z)");

  return result;
}


