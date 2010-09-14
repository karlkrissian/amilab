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
#include "wrapFilters.h"
#include "LeastSquares.h"
#include "wrap_StructureTensor.h"
#include "RegionGrowingTest.h"
#include <pthread.h>

#include "AMILabConfig.h"
#ifdef AMI_USE_FASTNLMEANS
  #include "Wrap_NewNLMeans.h"
#endif // AMI_USE_FASTNLMEANS
#include "wrapAlgorithmsBasic.h"
#include "wrapComputePV.h"
#include "wrap_DirSum.h"
#include "wrap_ImTranslate.h"
#include "wrap_AddSubImage.h"
#include "wrap_MaxSubImage.h"
#include "wrap_ImageAddScalar.h"
#include "wrap_ImageCos.h"
#include "wrap_AnisoGS.h"
#include "ami_object.h"
#include "VarArray.h"

//Basic Edge Detection Filters added
#include "wrapBasicEdgeDetection.h"

#include "wrapSubPixel2D.h"
#include "wrapGenerateRamp.h"
#include "wrap_SurfacePoly.h"

#include "wrap_ContinuousMorphology.h"

extern VarContexts  Vars;

//---------------------------------------------------------
void AddWrapFilters(){

  // Create new instance of the class
  AMIObject::ptr amiobject (new AMIObject);
  amiobject->SetName("filters");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  wrapAlgorithmsBasic();

//  Vars.AddVar(type_c_image_function,"ImTranslation",             (void*) ImTranslation );
  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"NSim",NSim);

  ADDOBJECTVAR_NAME(C_wrap_procedure,"NSim2",NSim2);

  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"NLmeans",     NLmeans);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"NLmeans_fast",NLmeans_fast);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"NLmeans_MRI", NLmeans_MRI);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"LeastSquares",WrapLeastSquares);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"StructureTensorH",wrap_StructureTensorHessianNew);

  ADDOBJECTVAR_NAME(C_wrap_varfunction,"EigenDecomp",Wrap_EigenDecomp);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"SplineResample",Wrap_SmoothLinesToSplines);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"RegionGrow",Wrap_RegionGrow);
  
  #ifdef AMI_USE_FASTNLMEANS
    ADDOBJECTVAR_NAME(C_wrap_imagefunction,"NewNLmeans",    Wrap_NewNLmeans);
  #endif // AMI_USE_FASTNLMEANS

  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"ComputePV",       wrapComputePV);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"ComputePV_subdiv",wrapComputePV_subdiv);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"DirSum",          wrap_DirSum);
  ADDOBJECTVAR_NAME(C_wrap_imagefunction,"ImTranslate",     wrap_ImTranslate);

  ADDOBJECTVAR_NAME(C_wrap_procedure,"AddSubImage",wrap_AddSubImage);
  ADDOBJECTVAR_NAME(C_wrap_procedure,"MaxSubImage",wrap_MaxSubImage);

  ADDOBJECTVAR_NAME(C_wrap_procedure,"ImageAddScalar",wrap_ImageAddScalar);
  ADDOBJECTVAR_NAME(C_wrap_procedure,"ImageCos",wrap_ImageCos);

	//Basic Edge Detection
	ADDOBJECTVAR_NAME(C_wrap_imagefunction, "Roberts",	wrapRoberts);
	ADDOBJECTVAR_NAME(C_wrap_imagefunction, "PSF",			wrapPSF);
	ADDOBJECTVAR_NAME(C_wrap_imagefunction, "Gradient", wrapGradient);
	ADDOBJECTVAR_NAME(C_wrap_imagefunction, "Laplace",	wrapLaplace);
  
  //2D SUBPIXEL METHOD
 // ADDOBJECTVAR_NAME(C_wrap_imagefunction, "SintheticRamp", wrapSintheticRamp);
  ADDOBJECTVAR_NAME(C_wrap_varfunction, "Subpixel2D", wrapSubpixel2D);

  // Add AnisoGS
  AddVar_AnisoGS( amiobject->GetContext());

  // Add ContinuousMorphology
  AddVar_ContinuousMorphology( amiobject->GetContext());

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.AddVar<AMIObject>(amiobject->GetName().c_str(), amiobject);

}


/**
 * Adds the Filters wrapping
 * @param p 
 */
void wrap_Filters( ParamList* p)
{
/*
  char functionname[] = "Filters";
  char description[]=" \n\
    Adds wrapping for Filters. \n\
          ";
  char parameters[] =" \n\
          ";
*/
  AddWrapFilters();
}


/* neighborhood similarity ...
*/
InrImage* NSim(ParamList* p)
{
    char functionname[] = "NSim";
    char description[]=" \n\
        compute the neighborhood similarity of a window center on a pixel \n\
        with all the windows of the same size in the image \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              integer x : center of the window\n\
              integer y : center of the window\n\
              integer z : center of the window\n\
              wsize: window will be (2*wsize+1)^n\n\
            ";

    InrImage* input;
    int posx=0;
    int posy=0;
    int posz=0;
    int wsize=3;
    int n=0;
    int x,y,z,x1,y1; //,z1;
//    int minx,maxx,miny,maxy,minz,maxz;
    double dist=0,val=0;

    InrImage* result;

  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(    posx,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(    posy,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(    posz,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(    wsize,      p, n)) HelpAndReturnNULL;

  result = new InrImage( WT_FLOAT, "NSim.ami.gz", input);
  (*result)=(*input);
  // 2D for now

  if ((!input->CoordOK(posx-wsize,posy-wsize,posz)) ||
      (!input->CoordOK(posx+wsize,posy+wsize,posz))) {
    printf("Error, NSim: the window does not fit at the current position \n");
    return NULL;
  }

  for(z=0;z<=input->DimZ()-1;z++)
  for(y=wsize;y<=input->DimY()-1-wsize;y++)
  for(x=wsize;x<=input->DimX()-1-wsize;x++) {
    dist = 0;
    for (x1=-wsize;x1<=wsize;x1++)
    for (y1=-wsize;y1<=wsize;y1++) {
      val = (*input)(x+x1,y+y1,posz)-(*input)(posx+x1,posy+y1,z);
      dist += val*val;
    }
    dist /= (2*wsize+1)*(2*wsize+1);
    result->BufferPos(x,y,z);
    result->FixeValeur(sqrt(dist));
  }

  return result;

}


/* 
  Experimental:
  From the local difference of the subwindows, compute the local mean and local standard deviation
*/
void NSim2(ParamList* p)
{
    char functionname[] = "NSim2";
    char description[]=" \n\
        compute the local statistics of the difference between a window center on a pixel \n\
        with all the windows of the same size in the image \n\
        \n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              local mean image\n\
              local var image\n\
              integer x : center of the window\n\
              integer y : center of the window\n\
              integer z : center of the window\n\
              wsize: window will be (2*wsize+1)^n\n\
            ";

    InrImage* input;
    InrImage* local_mean;
    InrImage* local_var;
    int posx=0;
    int posy=0;
    int posz=0;
    int wsize=3;
    int n=0;
    int x,y,z,x1,y1; //,z1;
//    int minx,maxx,miny,maxy,minz,maxz;
    double val=0,mean=0,var=0;

    //InrImage* result;

  if (!get_val_ptr_param<InrImage>(  input,        p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(  local_mean,   p, n)) HelpAndReturn;
  if (!get_val_ptr_param<InrImage>(  local_var,    p, n)) HelpAndReturn;
  if (!get_int_param(    posx,         p, n)) HelpAndReturn;
  if (!get_int_param(    posy,         p, n)) HelpAndReturn;
  if (!get_int_param(    posz,         p, n)) HelpAndReturn;
  if (!get_int_param(    wsize,        p, n)) HelpAndReturn;

  // 2D for now

  if ((input->DimX()!=local_mean->DimX())||
      (input->DimY()!=local_mean->DimY())||
      (input->DimZ()!=local_mean->DimZ()) )
  {
    cerr << "NSim2 input and local_mean images have different dimensions" << endl;
    return;
  }
  if ((input->DimX()!=local_var->DimX())||
      (input->DimY()!=local_var->DimY())||
      (input->DimZ()!=local_var->DimZ()) )
  {
    cerr << "NSim2 input and local_var images have different dimensions" << endl;
    return;
  }

  if ((!input->CoordOK(posx-wsize,posy-wsize,posz)) ||
      (!input->CoordOK(posx+wsize,posy+wsize,posz))) {
    printf("Error, NSim2: the window does not fit at the current position \n");
    return;
  }

  for(z=0;z<=input->DimZ()-1;z++)
  for(y=wsize;y<=input->DimY()-1-wsize;y++)
  for(x=wsize;x<=input->DimX()-1-wsize;x++) {
    mean = 0;
    var = 0;
    for (x1=-wsize;x1<=wsize;x1++)
    for (y1=-wsize;y1<=wsize;y1++) {
      val = (*input)(x+x1,y+y1,posz)-(*input)(posx+x1,posy+y1,z);
      mean += val;
      var += val*val;
    }
    mean /= (2*wsize+1)*(2*wsize+1);
    var = var/((2*wsize+1)*(2*wsize+1))-mean*mean;
    local_mean->BufferPos(x,y,z);
    local_mean->FixeValeur(mean);
    local_var ->BufferPos(x,y,z);
    local_var ->FixeValeur(var);
  }

} // NSim2





struct thread_fastNLmeans_info {
    int  thread_id;                 /* number of current thread */
    int  total_threads;             /* number of threads */
    InrImage* input_float;          /* input image in float format */
    InrImage* input_field;          /* input feature image */
    InrImage* result;               /* result */
    int       t;                    /* window size */
    float     h;                    /* threshold */
    int       noisetype;            /* noise type */
    long*     points_processed;     /* number of pixels/voxels already processed */
};

//----------------------------------------------------------------------------------------
void* thread_NLmeans_fast( void* threadarg)
{
  // loading arguments
  thread_fastNLmeans_info* args = (thread_fastNLmeans_info*) threadarg;

  InrImage* input_float = args->input_float;
  InrImage* input_field = args->input_field;
  InrImage* result      = args->result;
  int       t           = args->t;
  float     h           = args->h;
  int       noisetype   = args->noisetype;
  long*     pts_processed = args->points_processed;

  int tx=input_float->DimX();
  int ty=input_float->DimY();
  int tz=input_float->DimZ();
  int vdim=input_field->GetVDim();

  int x,y,z;
  register int dx,dy,dz;
  register double wmax,dist, w, average, total_weight;

  int percentage=0;
  int new_percentage=0;
  int per_step;
  int dx_min,dy_min,dz_min,dx_max,dy_max,dz_max;
  int stepx,stepy; // displacement of 1 line along 1 dimension
  register double h2 = h*h;
  register double tmp;
  long point_index;
  long point_index_window;

  float* result_buf;
  float* input_field_buf;  // points to the current voxel
  float* input_field_buf_d; // points to the displaced voxel in the searching window
  float* input_float_buf_d;  // points to the displaced voxel in the searching window
  double intensity;


  printf("Thread %d / %d \n",args->thread_id+1,args->total_threads);

  if (tz>10)
    per_step = 5;
  else
    per_step = 20;

  // BufferPos if not thread safe ...
  result_buf = (float*)result->Buffer();

  point_index = 0;
  for(z=0;z<tz;z++)
  for(y=0;y<ty;y++)
  for(x=0;x<tx;x++,point_index++) {
     // Computes the n^th point of every num_thread points
     if (point_index%args->total_threads != args->thread_id)
       continue;

    wmax = 0;
    average = 0;
    total_weight=0;
    // set voxel weights to 0
    tmp = 1.0/(tx*ty*tz)*(100.0/per_step);
    percentage     = (int) ((*pts_processed)*tmp);
    (*pts_processed)++;
    new_percentage = (int) ((*pts_processed)*tmp);
    if (new_percentage!=percentage) {
    percentage=new_percentage;
        printf(" %d %% \t",percentage*per_step);
        fflush(stdout);
    }


    dx_min = (x-t>=0?-t:-x);
    dy_min = (y-t>=0?-t:-y);
    dz_min = (z-t>=0?-t:-z);

    dx_max = (x+t<tx?t:tx-1-x);
    dy_max = (y+t<ty?t:ty-1-y);
    dz_max = (z+t<tz?t:tz-1-z);

    // position at (x,y,z) for the central voxel
    input_field_buf = (float*)input_field->Buffer()+point_index*vdim;

    // moving position at (x+dx,y+dy,z+dz)
    point_index_window = (dz_min*ty+dy_min)*tx+dx_min;
    input_field_buf_d = (float*)input_field->Buffer()+(point_index + point_index_window)*vdim;
    input_float_buf_d = (float*)input_float->Buffer()+point_index + point_index_window;

    stepx = dx_max-dx_min+1;
    stepy = (dy_max-dy_min+1)*tx;

    for(dz=dz_min;dz<=dz_max;dz++) {
        for(dy=dy_min;dy<=dy_max;dy++) {
            for(dx=dx_min;dx<=dx_max;dx++) {
                if ((dx!=0)||(dy!=0)||(dz!=0)) {
                    dist = 0;
                    // computes scalar product of input_fied at (x,y,z)
                    // and (x+dx,y+dy,z+dz)
                    for(int i=0;i<vdim;i++) {
                        tmp = input_field_buf[i]-input_field_buf_d[i];
                        dist += tmp*tmp;
                    }

                    w = exp(-dist/h2);
                    // set the values in voxel_weights array
                    //       voxel_weights[(dz+t)*(2*t+1)]
                    if (w>wmax) wmax=w;

                    intensity = (*input_float_buf_d);
                    switch (noisetype) {
                        case 0: average += w*intensity; break;
                        case 1: average += w*intensity*intensity; break;
                    }
                    total_weight += w;
                } // if not the center
                input_field_buf_d += vdim;
                input_float_buf_d++;
            } // for loop dx
            input_field_buf_d += (-stepx+tx)*vdim;
            input_float_buf_d += -stepx+tx;
        } // for loop dy
        input_field_buf_d += (-stepy+tx*ty)*vdim;
        input_float_buf_d += -stepy+tx*ty;
    } // for loop dz

//    result->BufferPos(x,y,z);

    switch (noisetype) {
    case 0:
        average += wmax*(*input_float)(x,y,z);
        total_weight += wmax;
        result_buf[point_index]=average/total_weight;
    break;
    case 1:
        average += wmax*(*input_float)(x,y,z)*(*input_float)(x,y,z);
        total_weight += wmax;
        result_buf[point_index]=sqrt(average/total_weight);
    break;
    }
  } // end for x,y,z
   pthread_exit(NULL);
  return(NULL);
}

//------------------------------------------------------------------
InrImage* NLmeans_fast(ParamList* p)
{
    char functionname[] = "NLmeans_fast";
    char description[]=" \n\
        implementation of the NL-means algorithms\n\
        proposed by Buades et al.\n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              input vectorial image for computing distance\n\
          t (def: 7): define a window of size (2t+1)^n \n\
            used to search for similar pixels/voxels\n\
          h (def: 10): threshold for the distance between\n\
            patches\n\
          noisetype (def:0): type of noise, \n\
            0: additive Gaussian \n\
            1: Rician noise (MRI) \n\
          threads (def: 2): number of threads\n\
            ";

    InrImage* input;
    InrImage* input_field;
    InrImage* input_float = NULL;
    InrImage* result = NULL;
    int   t=7;
    float h=10;
    int noisetype = 0;
    int num_threads = 2;
//    double *voxel_weights;
    int n=0;

  if (!get_val_ptr_param<InrImage>(      input,       p, n)) HelpAndReturnNULL;
  if (!get_val_ptr_param<InrImage>(      input_field, p, n)) HelpAndReturnNULL;
  if (!get_int_param(        t,           p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(      h,           p, n)) HelpAndReturnNULL;
  if (!get_int_param(        noisetype,   p, n)) HelpAndReturnNULL;
  if (!get_int_param(        num_threads, p, n)) HelpAndReturnNULL;

  if (fabs(h)<1E-2) {
    fprintf(stderr,"NLmeans error \t the coefficient h cannot be too small, it is set to 10 !\n");
    h = 10;
  }


  if (input->GetFormat()!=WT_FLOAT) {
   input_float = new InrImage(WT_FLOAT,"NLmeans_result.ami.gz",input);
   (*input_float)=(*input);
  } else input_float=input;

  result = new InrImage(WT_FLOAT,"NLmeans_result.ami.gz",input);
  (*result)=(*input);

    // num_threads
    thread_fastNLmeans_info* thread_info;
    int i;
    pthread_t* threads;
    pthread_attr_t attr;
    int rc,status;
    long points_processed = 0;


    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    thread_info = (thread_fastNLmeans_info*) malloc(num_threads*sizeof(thread_fastNLmeans_info));
    threads = (pthread_t*) malloc(num_threads*sizeof(pthread_t));

    for (i=0;i<num_threads;i++) {
      thread_info[i].thread_id      = i;
      thread_info[i].total_threads  = num_threads;
      thread_info[i].input_float    = input_float;
      thread_info[i].input_field    = input_field;
      thread_info[i].result         = result;
      thread_info[i].t              = t;
      thread_info[i].h              = h;
      thread_info[i].noisetype      = noisetype;
      thread_info[i].points_processed = &points_processed;

      rc = pthread_create(&threads[i],
        &attr,
        thread_NLmeans_fast,
        (void *) &thread_info[i]);
      if (rc) {
        printf("NLmeans_fast() \t ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
      }
   }

   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);
   for(i=0; i<num_threads; i++)
   {
      rc = (int) pthread_join((pthread_t)threads[i], (void **)&status);
      if (rc)
         printf("NLmeans_fast() \t ERROR; return code from pthread_join()  is %d\n", rc);
      //printf("Completed join with thread %d status= %d\n",i, status);
   }

  free(thread_info);
  free(threads);

  printf("finished !...\n");
  if (input->GetFormat()!=WT_FLOAT)
   delete input_float;
//  delete[] voxel_weights;

  return result;

}  // NLmeans_fast()


//------------------------------------------------------------------
struct thread_NLmeans_MRI_info {
    int  thread_id;                 /* number of current thread */
    int  total_threads;             /* number of threads */
    InrImage* input_float;          /* input image in float format */
    InrImage* input_lmean;          /* input local mean */
    InrImage* input_lsd;            /* input local sd */
    InrImage* result;               /* result */
    double    var_noise;            /* estimated noise variance */
    int       t;                    /* window size */
    float     h;                    /* threshold */
    long*     points_processed;     /* number of pixels/voxels already processed */
    InrImage* noise_reduction;
};



//----------------------------------------------------------------------------------------
void* thread_NLmeans_MRI( void* threadarg)
{
  // loading arguments
  thread_NLmeans_MRI_info* args = (thread_NLmeans_MRI_info*) threadarg;

  InrImage* input_float = args->input_float;
  InrImage* input_lmean = args->input_lmean;
  InrImage* input_lsd   = args->input_lsd;
  InrImage* result      = args->result;
  InrImage* noise_reduction_im      = args->noise_reduction;
  int       t           = args->t;
  float     h           = args->h;
  double    var_noise   = args->var_noise;
  long*     pts_processed = args->points_processed;

  int tx=input_float->DimX();
  int ty=input_float->DimY();
  int tz=input_float->DimZ();

  int x,y,z;
  int dx,dy,dz;
  double wmax,dist, w, average,average2, k,var, total_weight;
  double noise_reduction,lvar_noise;
  double h2 = h*h;

  int percentage=0;
  int new_percentage=0;
  int per_step;
  int dx_min,dy_min,dz_min,dx_max,dy_max,dz_max;
  int stepx,stepy; // displacement of 1 line along 1 dimension
  register double tmp;
  long point_index;
  long point_index_window;

  float* result_buf;
  float* noise_reduction_buf;
  float* input_lmean_buf;  // points to the current voxel
  float* input_lmean_buf_d; // points to the displaced voxel in the searching window
  float* input_lsd_buf;  // points to the current voxel
  float* input_lsd_buf_d; // points to the displaced voxel in the searching window

  float* input_float_buf_d;  // points to the displaced voxel in the searching window
  double intensity;
  double c_mean,c_var,d_mean,d_var; // central and displaced means and variances

  printf("Thread %d / %d \n",args->thread_id+1,args->total_threads);

  if (tz>10)
    per_step = 5;
  else
    per_step = 20;

  // BufferPos if not thread safe ...
  result_buf = (float*)result->Buffer();
  noise_reduction_buf = (float*) noise_reduction_im->Buffer();

  point_index = 0;
  for(z=0;z<tz;z++)
  for(y=0;y<ty;y++)
  for(x=0;x<tx;x++,point_index++) {
     // Computes the n^th point of every num_thread points
     if (point_index%args->total_threads != args->thread_id)
       continue;

    wmax = 0;
    average = 0;
    average2 = 0;
    total_weight=0;
    noise_reduction = 0.0;
    lvar_noise = var_noise*noise_reduction_buf[point_index];
    // set voxel weights to 0
    tmp = 1.0/(tx*ty*tz)*(100.0/per_step);
    percentage     = (int) ((*pts_processed)*tmp);
    (*pts_processed)++;
    new_percentage = (int) ((*pts_processed)*tmp);
    if (new_percentage!=percentage) {
    percentage=new_percentage;
        printf(" %d %% \t",percentage*per_step);
        fflush(stdout);
    }


    dx_min = (x-t>=0?-t:-x);
    dy_min = (y-t>=0?-t:-y);
    dz_min = (z-t>=0?-t:-z);

    dx_max = (x+t<tx?t:tx-1-x);
    dy_max = (y+t<ty?t:ty-1-y);
    dz_max = (z+t<tz?t:tz-1-z);

    // position at (x,y,z) for the central voxel
    input_lmean_buf = (float*)input_lmean->Buffer()+point_index;
    input_lsd_buf   = (float*)input_lsd->Buffer()  +point_index;

    // moving position at (x+dx,y+dy,z+dz)
    point_index_window = (dz_min*ty+dy_min)*tx+dx_min;

    input_lmean_buf_d = (float*)input_lmean->Buffer()+point_index + point_index_window;
    input_lsd_buf_d   = (float*)input_lsd->Buffer()  +point_index + point_index_window;
    input_float_buf_d = (float*)input_float->Buffer()+point_index + point_index_window;

    stepx = dx_max-dx_min+1;
    stepy = (dy_max-dy_min+1)*tx;

#define MAX(a,b) ((a)>(b)?(a):(b))

    // compute estimated denoised mean and sd at central point
    c_mean = *input_lmean_buf;
    c_var  = (*input_lsd_buf)*(*input_lsd_buf);
    //c_mean = MAX(0,*input_lmean_buf-2*var_noise);
    //c_var  = MAX(0,(*input_lsd_buf)*(*input_lsd_buf)-4*var_noise*(*input_lmean_buf-var_noise));

    //if ((x==25)&&(y==25))
    //  printf("%d %d --> %f \n",x,y,*input_lmean_buf);

    for(dz=dz_min;dz<=dz_max;dz++) {
        for(dy=dy_min;dy<=dy_max;dy++) {
            for(dx=dx_min;dx<=dx_max;dx++) {
                if ((dx!=0)||(dy!=0)||(dz!=0)) {
                    //dist = 0;
                    // computes estimated local sd
                    d_mean = *input_lmean_buf_d;
                    d_var  = (*input_lsd_buf_d)*(*input_lsd_buf_d);
                    //d_mean = MAX(0,*input_lmean_buf_d-2*var_noise);
                    //d_var  = MAX(0,(*input_lsd_buf_d)*(*input_lsd_buf_d)-
                    //         4*var_noise*(*input_lmean_buf_d-var_noise));
                    // weight is based on a probability of having same intensity at the center
                    //w = 1.0/sqrt(c_var+d_var+1)*exp(-(c_mean-d_mean)*(c_mean-d_mean)/(2*(c_var+d_var+1)))*exp(-fabsf(c_var-d_var)/(8*var_noise*var_noise+1));

                    /*w = exp(-fabsf(c_mean-d_mean)/sqrt(4*lvar_noise*(*input_lmean_buf-lvar_noise)));
*/
                    dist = *input_lmean_buf-*input_lmean_buf_d;
                    w = exp(-dist*dist/h2);

                    noise_reduction += w*w;
                    // set the values in voxel_weights array
                    //       voxel_weights[(dz+t)*(2*t+1)]
                    if (w>wmax) wmax=w;
                    intensity = (*input_float_buf_d);
//if (intensity>0) intensity = sqrt(intensity);
//else intensity = 0;
                    average += w*intensity;
                    average2 += w*intensity*intensity;
                    total_weight += w;
                } // if not the center
                input_lmean_buf_d++;
                input_lsd_buf_d++;
                input_float_buf_d++;
            } // for loop dx
            input_lmean_buf_d += -stepx+tx;
            input_lsd_buf_d   += -stepx+tx;
            input_float_buf_d += -stepx+tx;
        } // for loop dy
        input_lmean_buf_d += -stepy+tx*ty;
        input_lsd_buf_d   += -stepy+tx*ty;
        input_float_buf_d += -stepy+tx*ty;
    } // for loop dz

//    result->BufferPos(x,y,z);
    noise_reduction += wmax*wmax;
    intensity = (*input_float)(x,y,z);
//if (intensity>0) intensity = sqrt(intensity);
//else intensity = 0;
    average += wmax*intensity;
    average2 += wmax*intensity*intensity;
    total_weight += wmax;
    average  /= total_weight;
    average2 /= total_weight;
    var = average2-average*average;

    k = 1.-4.*lvar_noise*(average-lvar_noise)/var;
    if (k<0.0) k=0.0;
    if (k>1.0) k=1.0;
    double tmp;
    tmp = intensity + (1-k)*(average-intensity);
    result_buf[point_index]=sqrt(tmp);
    noise_reduction *= 1.0/total_weight/total_weight;
    noise_reduction = (k*k+(1.0-k*k)*noise_reduction); // à vérifier

    tmp = average*average-var;
    if (tmp<0) tmp = 0;
    tmp = average - sqrt(tmp);
    if (tmp<0) tmp = 0;
    noise_reduction_buf[point_index] = sqrt(tmp/2.0);
//    noise_reduction_buf[point_index] *= noise_reduction; //noise_reduction;

  } // end for x,y,z
   pthread_exit(NULL);
  return (NULL);
} // thread_NLmeans_MRI

//------------------------------------------------------------------
InrImage* NLmeans_MRI(ParamList* p)
{
    char functionname[] = "NLmeans_MRI";
    char description[]=" \n\
        implementation of a modified NL-means algorithm\n\
        adapted for Rician noise in MRI\n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              input subvolume as a Region Of Interest for estimating the noise\n\
              t (def: 7): define a window of size (2t+1)^n \n\
                used to search for similar pixels/voxels\n\
              h (def: 10): threshold for the distance between\n\
                patches\n\
              sigma (def:1): Gaussian standard deviation for smoothing \n\
              nb_it (def: 1): number of iterations\n\
              threads (def: 2): number of threads\n\
            ";

    InrImage* input;
    InrImage* noise_reduction;
    InrImage::ptr input_roi;
    InrImage* input_float = NULL;
    InrImage* result = NULL;
    int   t=7;
    float h = 10;
    float sigma=1.0;
    int nb_it = 1;
    int num_threads = 2;
    double var_noise;
//    double *voxel_weights;
    int n=0;

  if (!get_val_ptr_param<InrImage>(      input,       p, n)) HelpAndReturnNULL;
  if (!get_val_smtptr_param<InrImage>(   input_roi,   p, n)) HelpAndReturnNULL;
  if (!get_int_param(        t,           p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(      h,           p, n)) HelpAndReturnNULL;
  if (!get_val_param<float>(      sigma,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(        nb_it,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(        num_threads, p, n)) HelpAndReturnNULL;


//  input_float = new InrImage(WT_FLOAT,"NLmeans_input.ami.gz",input);
  input_float=(*input)*(*input);

  noise_reduction = new InrImage(WT_FLOAT,"noise_reduction.ami.gz",input);
  noise_reduction->InitImage(1);

  result = new InrImage(WT_FLOAT,"NLmeans_result.ami.gz",input);
  (*result)=(*input);

  // estimate the noise standard deviation
  InrImage* in_lmean = NULL;
  InrImage* in_lsd   = NULL;

  var_noise = Func_Compute_sigma2_MRI_mode(input_float, input_roi);

  printf("estimated noise sd = %f\n",sqrt(var_noise));

    // num_threads
    thread_NLmeans_MRI_info* thread_info;
    int i,it;
    pthread_t* threads;
    pthread_attr_t attr;
    int rc,status;
    long points_processed = 0;

  for (it=0;it<nb_it;it++) {

    if (it>0) {
      delete in_lmean;
      delete in_lsd;
    }
    in_lmean = Func_Filter(result,sigma,0,0,0);

    input_float->InitBuffer();
    result->InitBuffer();
    do {
      input_float->FixeValeur(result->ValeurBuffer()*result->ValeurBuffer());
      result->IncBuffer();
    } while (input_float->IncBuffer());

    // smoothing of square intensity image
    in_lsd   = Func_Filter(input_float,sigma,0,0,0);

    double tmp;
    in_lsd  ->InitBuffer();
    in_lmean->InitBuffer();
    do {
      tmp = in_lmean->ValeurBuffer();
      tmp = in_lsd->ValeurBuffer() - tmp*tmp;
      if (tmp<0) {
        if (tmp<-0.01) printf("NLmeans_MRI tmp <0 %f \n",tmp);
        tmp=0;
      }
      in_lsd->FixeValeur(sqrt(tmp));
      in_lmean->IncBuffer();
    } while (in_lsd->IncBuffer());

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


    thread_info = (thread_NLmeans_MRI_info*) malloc(num_threads*sizeof(thread_NLmeans_MRI_info));
    threads = (pthread_t*) malloc(num_threads*sizeof(pthread_t));

    for (i=0;i<num_threads;i++) {
      thread_info[i].thread_id      = i;
      thread_info[i].total_threads  = num_threads;
      thread_info[i].input_float    = input_float;
      thread_info[i].input_lmean    = in_lmean;
      thread_info[i].input_lsd      = in_lsd;
      thread_info[i].result         = result;
      thread_info[i].t              = t;
      thread_info[i].h              = h;
      thread_info[i].var_noise      = var_noise;
      thread_info[i].points_processed = &points_processed;
      thread_info[i].noise_reduction = noise_reduction;

      rc = pthread_create(&threads[i],
        &attr,
        thread_NLmeans_MRI,
        (void *) &thread_info[i]);
      if (rc) {
        printf("NLmeans_fast() \t ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
      }
   }

   // Free attribute and wait for the other threads
   pthread_attr_destroy(&attr);
   for(i=0; i<num_threads; i++)
   {
      rc = (int) pthread_join((pthread_t)threads[i], (void **)&status);
      if (rc)
         printf("NLmeans_fast() \t ERROR; return code from pthread_join()  is %d\n", rc);
      //printf("Completed join with thread %d status= %d\n",i, status);
   }

  free(thread_info);
  free(threads);
  }

  printf("finished !...\n");
//  if (input->GetFormat()!=WT_FLOAT)
   delete input_float;
//  delete[] voxel_weights;

  noise_reduction->Sauve();

  delete in_lmean;
  delete in_lsd;
  return result;

}  // NLmeans_MRI()


//-----------------------------------------------------
InrImage* WrapLeastSquares(ParamList* p)
{
    char functionname[] = "LeastSquares";
    char description[]=" \n\
        Run the Linear Weighted Least Square algorithm \n\
        for every pixel/voxel within a mask\n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input  image\n\
              basis  image\n\
              weight image\n\
              mask   image\n\
            ";

    InrImage* input;
    InrImage* basis;
    InrImage* weights;
    InrImage* mask;
    int n=0;

  if (!get_val_ptr_param<InrImage>(      input,       p, n)) HelpAndReturnNULL;
  if (!get_val_ptr_param<InrImage>(      basis,       p, n)) HelpAndReturnNULL;
  if (!get_val_ptr_param<InrImage>(      weights,     p, n)) HelpAndReturnNULL;
  if (!get_val_ptr_param<InrImage>(      mask,        p, n)) HelpAndReturnNULL;

  return Func_LeastSquares( input, basis, weights, mask);
}


//--------------------------------------------------------------------
//  Return a vector of images including
//  eigenvalues and eigenvectors depending on flags
//  use image dimensions to call the 2D or the 3D versions
//
// TODO: allow returning a list or something more evolved !!!
//

BasicVariable::ptr Wrap_EigenDecomp(ParamList* p) {
    char functionname[] = "EigenDecomp";
    char description[]=" \n\
        Eigenvalue and eigenvector decomposition\n\
        from an image of matrices, in 2D or 3D\n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              input       matrix image\n\
              value_flag  number (logical combination of \n\
                        1: get first, 2: get second, 4: get third)\n\
              vector_flag number (same flag for eigenvectors)\n\
              mask        image\n\
          Return:\n\
              Returns a variable as an image array contains the resulting images\n\
            ";

    InrImage* input;
    int       value_flag;
    int       vector_flag;
    InrImage* mask=NULL;
    int n=0;

  if (!get_val_ptr_param<InrImage>(         input,       p, n)) HelpAndReturnVarPtr;
  if (!get_int_param(           value_flag,  p, n))             HelpAndReturnVarPtr;
  if (!get_int_param(           vector_flag, p, n))             HelpAndReturnVarPtr;
  if (!get_val_ptr_param<InrImage>( mask,        p, n,false))   HelpAndReturnVarPtr;


  vector<InrImage::ptr> result;

  // how to do with smart pointers ???
  // should be managed by ParamList ...
  // got rid of them for now
  result = EigenDecomp( input, value_flag, vector_flag, mask);

  // Create the resulting variable array
  VarArray::ptr array(new VarArray());
  array->Init(type_image,result.size());

  for(n=0;n<(int)result.size();n++)
    if (result[n]!=NULL)
      array->InitElement<InrImage>( n,
           result[n],
           str(format("eigen_decomp_%d") %n).c_str());

  Variable<VarArray>::ptr varres(
    new Variable<VarArray>("EigenDecomp_result",array ));

  return varres;
}



// Resample lines using splines
BasicVariable::ptr Wrap_SmoothLinesToSplines(ParamList* p)
{

  char functionname[] = "SplineResample";
  char description[]=" \n\
      Resample all the lines using spline interpolation and the given sampling step\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
              input lines\n\
              number: sampling step (def: 0.1)\n\
          Return:\n\
              Resulting polydata as interpolated lines\n\
      ";

//    SurfacePoly* input;
    float samplingstep = 0.1f;
    int n=0;

  //using namespace amilab;
  FUNC_GET_OBJECT_PARAM(SurfacePoly,varsurf,objsurf);
  if (!objsurf.get()) HelpAndReturnVarPtr;
  if (!get_val_param<float>(    samplingstep, p, n)) HelpAndReturnVarPtr;


//  SurfacePoly::ptr surf_result (Func_SmoothLinesToSplines( input, samplingstep ));

  return WrapClass_SurfacePoly::CreateVar(Func_SmoothLinesToSplines( objsurf.get(),
                                  samplingstep ));
//Variable<SurfacePoly>::ptr varres(
//    new Variable<SurfacePoly>("interpolatedsplines_result",surf_result));

//  return varres;


} // Wrap_SmoothLinesToSplines()


// Region Growing
BasicVariable::ptr Wrap_RegionGrow(ParamList* p)
{

  char functionname[] = "RegionGrow";
  char description[]=" \n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
              input image\n\
              initial image image\n\
              min intensity \n\
              max intensity \n\
          Return:\n\
              Resulting state image\n\
      ";

  Variable<InrImage>::ptr input_var;
  Variable<InrImage>::ptr init_var;
  float int_min;
  float int_max;
  int n=0;

  if (!get_var_param<InrImage>( input_var, p, n)) HelpAndReturnVarPtr;
  if (!get_var_param<InrImage>( init_var, p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>( int_min, p, n)) HelpAndReturnVarPtr;
  if (!get_val_param<float>( int_max, p, n)) HelpAndReturnVarPtr;

  InrImage::ptr input( input_var->Pointer());
  InrImage::ptr init ( init_var ->Pointer());

  IntensityBasedRegionGrowing::ptr regiongrow(
    new IntensityBasedRegionGrowing(input,init)
    );
  regiongrow->SetMin(int_min);
  regiongrow->SetMax(int_max);
  regiongrow->Evolve();

  Variable<InrImage>::ptr varres(
    new Variable<InrImage>( "RegionGrowingResult",
                            regiongrow->GetStateImage()));

  return varres;


} // Wrap_RegionGrow()
