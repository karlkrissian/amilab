//
// C++ Implementation: NewNLmeans
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "Wrap_NewNLMeans.h"
#include "FastNLmeans.hpp"


//------------------------------------------------------
InrImage* Wrap_NewNLmeans(ParamList* p)
{
    char functionname[] = "NewNLmeans";
    char description[]=" \n\
        Fast implementation of the NL-means algorithms\n\
        proposed by Buades et al.\n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
          t (def: 7): define a window of size (2t+1)^n \n\
            used to search for similar pixels/voxels\n\
          f (def: 3): define a window of size (2f+1)^n\n\
            for the pixel/voxel pattern to match (f<t)\n\
          h (def: 10): threshold for the distance between\n\
            patches, suggested 10*standard deviation of the noise\n\
          threads (def: 2): number of threads\n\
          minweight (def: 15):  minimal weight threshold is exp(-minweight) \n\
            ";

  FastNLmeans_params params;
  int n=0;

  if (!get_image_param(  params.input,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(    params.t,           p, n)) HelpAndReturnNULL;
  if (!get_int_param(    params.f,           p, n)) HelpAndReturnNULL;
  if (!get_float_param(  params.h,           p, n)) HelpAndReturnNULL;
  if (!get_int_param(    params.num_threads, p, n)) HelpAndReturnNULL;
  if (!get_float_param(  params.minweight,   p, n)) HelpAndReturnNULL;

  FastNLmeans fast_nlmeans(params);
  fast_nlmeans.Init();
  fast_nlmeans.Run();
  //printf("finished !...\n");

  return fast_nlmeans.GetResult();

} // Wrap_NewNLmeans


