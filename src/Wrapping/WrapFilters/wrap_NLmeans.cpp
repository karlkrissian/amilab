//
// C++ Implementation: wrap_NLmeans
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "wrap_NLmeans.h"

#include "AMILabConfig.h"
#include "NLmeans.h"
#include "fonctions.h"
#include "wrapfunctions.hpp"
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include "ImageDerivatives.h"
#include "message_dialog.h"

//------------------------------------------------------------------
InrImage* NLmeans(ParamList* p)
{
    char functionname[] = "NLmeans";
    char description[]=" \n\
        implementation of the NL-means algorithms\n\
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
          noisetype (def:0): type of noise, \n\
            0: additive Gaussian \n\
            1: Rician noise (MRI) \n\
          threads (def: 2): number of threads\n\
          prob_variant (def:0) : decide if using a probability variant of the algorithm \n\
          presmooth S.T. (def:0) : Standard Deviation for Gaussian pre-smoothing, \n\
          pattern weight factor (def:0.5): creates Gaussian weights \n\
          within the patterns as function of the distance to the central\n\
          point. The Gaussian has a standard deviation of  f*factor.\n\
            ";

    InrImage* input = NULL;
    InrImage* input_float = NULL;
    InrImage* result = NULL;
    int   t=7;
    int   f=3;
    float h=10;
    int noisetype = 0;
    int num_threads = 2;
    int probability_variant = 0;
    int n=0;
    float presmooth_sd=0;
    float pattern_weight_factor = 0.5;
    InrImage::ptr smoothed_image;

  if (!get_val_ptr_param<InrImage>(  input,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(    t,           p, n)) HelpAndReturnNULL;
  if (!get_int_param(    f,           p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  h,           p, n)) HelpAndReturnNULL;
  if (!get_int_param(    noisetype,   p, n)) HelpAndReturnNULL;
  if (!get_int_param(    num_threads, p, n)) HelpAndReturnNULL;
  if (!get_int_param(    probability_variant,   p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  presmooth_sd,          p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(  pattern_weight_factor, p, n)) HelpAndReturnNULL;

  if (fabs(h)<1E-2) {
    fprintf(stderr,"NLmeans error \t the coefficient h cannot be too small, it is set to 10 !\n");
    h = 10;
  }

  FILE_MESSAGE((boost::format("Pattern weight factor = %1%")%pattern_weight_factor).str().c_str());

  if (input->GetFormat()!=WT_FLOAT) {
   input_float = new InrImage(WT_FLOAT,"NLmeans_result.ami.gz",input);
   (*input_float)=(*input);
  } else {
    input_float=input;
  }

  result = new InrImage(WT_FLOAT,"NLmeans_result.ami.gz",input);
  (*result)=(*input);


  if (presmooth_sd>0) {
    smoothed_image = Func_Filter( input_float, presmooth_sd,0,0,0);
  } else {
   std::cout << "no smoothing" << std::endl; 
  }

  long points_processed = 0;

  if (num_threads==1) {
    // with only 1 thread, don´t use threads...
    thread_NLmeans_info thread_info;
    thread_info.thread_id      = 0;
    thread_info.total_threads  = num_threads;
    thread_info.input_float    = input_float;
    thread_info.result         = result;
    thread_info.t              = t;
    thread_info.f              = f;
    thread_info.h              = h;
    thread_info.noisetype      = noisetype;
    thread_info.points_processed = &points_processed;
    thread_info.probability_variant = probability_variant;
    thread_info.pattern_weight_factor = pattern_weight_factor;
    if (presmooth_sd>0)
      thread_info.smoothed_image = smoothed_image;
    thread_NLmeans( (void *) &thread_info);
  } else {
    // num_threads
    thread_NLmeans_info* thread_info;
    int i;
    pthread_t* threads;
    pthread_attr_t attr;
    int rc,status;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    thread_info = new thread_NLmeans_info[num_threads];
    threads     = new pthread_t[num_threads];
    for (i=0;i<num_threads;i++) {
      thread_info[i].thread_id      = i;
      thread_info[i].total_threads  = num_threads;
      thread_info[i].input_float    = input_float;
      thread_info[i].result         = result;
      thread_info[i].t              = t;
      thread_info[i].f              = f;
      thread_info[i].h              = h;
      thread_info[i].noisetype      = noisetype;
      thread_info[i].points_processed = &points_processed;
      thread_info[i].probability_variant = probability_variant;
      thread_info[i].pattern_weight_factor = pattern_weight_factor;
      if (presmooth_sd>0)
        thread_info[i].smoothed_image = smoothed_image;

      rc = pthread_create(&threads[i],
        &attr,
        thread_NLmeans,
        (void *) &thread_info[i]);
      if (rc) {
        printf("NLmeans() \t ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
      }
    } // end for
  
    /* Free attribute and wait for the other threads */
    pthread_attr_destroy(&attr);
    for(i=0; i<num_threads; i++)
    {
        rc = (int) pthread_join((pthread_t)threads[i], (void **)&status);
        if (rc)
          printf("NLmeans() \t ERROR; return code from pthread_join()  is %d\n", rc);
        //printf("Completed join with thread %d status= %d\n",i, status);
    }
  
    delete [] thread_info;
    delete [] threads;
  } // else if  numthread==1

  printf("finished !...\n");
  if (input->GetFormat()!=WT_FLOAT)
   delete input_float;

  return result;

}


/*
Then each pixel at a distance d of the center is weighted by (1 / f ) sum_i=d, ..., f 1 / ( 2* i + 1 ) ^ 2 The center pixel is treated as a pixel at distance 1. The weighting window is not Gaussian but has the following form (f=5),

  function distance(x,y,f) {

    - distancetotal = 0 ;

    - distance = (u(x) - u(y) )^2;

   - for k= 1 until f {

      for each i=(i1,i2) pair of integer numbers such that max( |i1| , |i2|) = k {

        distance + = ( u(x+i) - u(y+i) ) ^ 2;

      }

    aux = distance / (2*k + 1 )^ 2;

    distancetotal + = aux;

  }

  - distancetotal / = f;
*/

