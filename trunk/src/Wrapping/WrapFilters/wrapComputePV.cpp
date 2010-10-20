//
// C++ Implementation: wrapComputePV
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrapComputePV.h"
#include "wrapfunctions.hpp"
#include "ComputePartialVolume.h"

InrImage* wrapComputePV(ParamList* p)
{
    char functionname[] = "wrapComputePV";
    char description[]=" \n\
        Compute an estimation of percentage of positive intensity \n\
        for each voxel.\n\
        \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image: Scalar float input image\n\
              resolution (def:5): integer, represents the subdivision used in each direction, combined with linear interpolation, to estimate the Partial Volume\n\
            ";

    InrImage* input = NULL;
    int resolution=5;
    int n=0;

    InrImage* result;

  if (!get_val_ptr_param<InrImage>(  input,        p, n)) HelpAndReturnNULL;
  get_int_param(    resolution,   p, n,false);

  result = ComputePartialVolume(input,resolution);

  return result;
} // wrapComputePV()


//---------------------------------------------------------------
InrImage* wrapComputePV_subdiv(ParamList* p)
{
    char functionname[] = "wrapComputePV_subdiv";
    char description[]=" \n\
        Compute an estimation of percentage of positive intensity \n\
        for each voxel, by recursive subdivision of the volume.\n\
        \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image: Scalar float input image\n\
              subdiv_levels (def:2): number of subdivision levels \n\
            ";

    InrImage* input;
    int subdiv_levels=2;
    int n=0;

    InrImage* result;

  if (!get_val_ptr_param<InrImage>(  input,  p, n)) HelpAndReturnNULL;
  get_int_param(    subdiv_levels, p, n,false); // parameter not required

  result = ComputePartialVolumeSubdiv(input,subdiv_levels);

  return result;
} // wrapComputePV_subdiv()

