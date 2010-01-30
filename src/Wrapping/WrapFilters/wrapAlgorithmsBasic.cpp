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
#include "localstats.h"
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
  // adding to the current object context
   Vars.AddVar(type_c_image_function,"FastLocalSumDir", (void*) wrapFastLocalSumDir, OBJECT_CONTEXT_NUMBER);
}


//--------------------------------------------------------------------------------
InrImage* wrapFastLocalSumDir(ParamList* p)
{
    char functionname[] = "FastLocalSumDir";
    char description[]=" \n\
      Computes the local average of pixel (or voxel) values in a window \n\
      and along the X axis direction, new version \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              wsize: (def:1) window will be (2*wsize+1)^n\n\
              axis: (def:0) 0,1 or 2 for X, Y or Z\n\
              mode: (def:0) \n\
                0: using FastLocalSumDir \n\
                1: using FastLocalSumX_noborder, FastLocalSumY_noborder, FastLocalSumZ_noborder\n\
                2: using FastLocalSumX_noborder, FastLocalSumY_noborder, FastLocalSumZ_noborder_2 \n\
                3: using FastLocalSumX and FastLocalSumDirNonX \n\
                4: using FastLocalMeanX_noborder \n\
              stepsize: (def:4) \n\
            ";

  InrImage* input = NULL;
  InrImage::ptr input1;
  int wsize=1;
  int n = 0;
  int axis=0;
  int mode=0;
  int stepsize=4;
  InrImage* result;

  if (!get_var_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(    wsize,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(    axis,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(    mode,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(    stepsize,   p, n)) HelpAndReturnNULL;

  if (input->GetFormat() != WT_FLOAT) {
    input1 = InrImage::ptr(new InrImage( WT_FLOAT, "input_float.ami.gz", input));
    (*input1)=(*input);
  } else {
    input1 = InrImage::ptr(input,smartpointer_nodeleter<InrImage>());
  }

  result = new InrImage( WT_FLOAT, "FastLocalSumDir2.ami.gz", input);
  (*result)=(*input);

  ImageExtent<int> extent(input);

  if (mode==0)
    FastLocalSumDir<float>(input1.get(),result,wsize,axis,extent);
  else
    if (axis==0) 
      switch (mode) {
        case 1:
        case 2:
          // input and output extents are set equal
          FastLocalSumX_noborder<float,unsigned char> (input1.get(),result,wsize,extent,extent);
        break;
        case 3:
          FastLocalSumX<float,unsigned char> (input1.get(),result,wsize,axis,extent,stepsize);
        break;
        case 4:
          FastLocalMeanX_noborder<float,unsigned char> (input1.get(),result,wsize,extent);
        break;
      }
    else
    if (axis==1)
      switch (mode) {
        case 1:
        case 2:
          FastLocalSumY_noborder<float,unsigned short>(input1.get(),result,wsize,extent,extent,stepsize);
        break;
        case 3:
          FastLocalSumDirNonX<float,unsigned short>  (input1.get(),result,wsize,axis,extent,stepsize);
        break;
      }
    else
    if (axis==2)
      switch (mode) {
        case 1:
          FastLocalSumZ_noborder<float,unsigned int>  (input1.get(),result,wsize,extent,stepsize);
        break;
        case 2:
          FastLocalSumZ_noborder_2<float,unsigned int>  (input1.get(),result,wsize,extent,extent,stepsize);
        break;
        case 3:
          FastLocalSumDirNonX<float,unsigned int>  (input1.get(),result,wsize,axis,extent,stepsize);
        break;
      }
    else
      FILE_ERROR("Wrong axis number (0,1 or 2 for X,Y or Z)");

  return result;
}


