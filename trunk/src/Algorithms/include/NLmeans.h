//
// C++ Interface: NLmeans
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _NLmeans_h_
#define _NLmeans_h_

#include "inrimage.hpp"

struct thread_NLmeans_info {
    int  thread_id;                 /* number of current thread */
    int  total_threads;             /* number of threads */
    InrImage* input_float;          /* input image in float format */
    InrImage* result;               /* result */
    InrImage::ptr smoothed_image;   /* smoothed version of the image if any */
    int       t;                    /* searching window size */
    int       f;                    /* pattern window size */
    float     h;                    /* threshold */
    int       noisetype;            /* noise type */
    long*     points_processed;     /* number of pixels/voxels already processed */
    int       probability_variant;  /* variant of the algorithm that uses the local statistics to define the weights */
    float     pattern_weight_factor; /* create Gaussian weight of SD f*factor for each pattern */
};


//------------------------------------------------------------------
void* thread_NLmeans( void* threadarg);



#endif // _NLmeans_h_
