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
#include "wrapFilters.h"
#include "LeastSquares.h"
#include "wrap_StructureTensor.h"
#include <pthread.h>

extern VarContexts  Vars;

//---------------------------------------------------------
void AddWrapFilters(){
 Vars.AddVar(type_c_image_function,"NSim",             (void*) NSim );
 Vars.AddVar(type_c_procedure,     "NSim2",         (void*) NSim2 );
 Vars.AddVar(type_c_image_function,"NLmeans",          (void*) NLmeans   );
 Vars.AddVar(type_c_image_function,"NLmeans_fast",     (void*) NLmeans_fast   );
 Vars.AddVar(type_c_image_function,"NLmeans_MRI",      (void*) NLmeans_MRI   );
 Vars.AddVar(type_c_image_function,"LeastSquares",     (void*) WrapLeastSquares   );
 Vars.AddVar(type_c_function,      "EigenDecomp",      (void*) Wrap_EigenDecomp   );
 Vars.AddVar(type_c_image_function,"StructureTensorH", (void*) wrap_StructureTensorHessianNew  );
 Vars.AddVar(type_c_function,      "SplineResample",   (void*) Wrap_SmoothLinesToSplines );
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

  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
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

    InrImage* result;

  if (!get_image_param(  input,        p, n)) HelpAndReturn;
  if (!get_image_param(  local_mean,   p, n)) HelpAndReturn;
  if (!get_image_param(  local_var,    p, n)) HelpAndReturn;
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

//------------------------------------------------------------------
void create_weights_2d(double*& w, int f)
{
  int i,j,p;
  double sum;
  double sigma = f/2.0;
//  printf("begin create_weights \n");

  w = new double [(2*f+1)*(2*f+1)];
  sum = 0;
  p = 0;

  for(j=-f;j<=f;j++)
  for(i=-f;i<=f;i++)
  {
    w[p]= exp(-(i*i+j*j)/sigma/sigma);
    sum += w[p];
    p++;
  }

  // normalize the weights
  p = 0;
  for(j=-f;j<=f;j++)
  for(i=-f;i<=f;i++)
  {
    w[p] /= sum;
    p++;
  }

//  printf("end create_weights \n");
}

//------------------------------------------------------------------
void create_weights_3d(double*& w, int f)
{
  int i,j,k,p;
  double sum;
  double sigma = f/2.0;
//  printf("begin create_weights \n");

  w = new double [(2*f+1)*(2*f+1)*(2*f+1)];
  sum = 0;
  p = 0;

  for(k=-f;k<=f;k++)
  for(j=-f;j<=f;j++)
  for(i=-f;i<=f;i++)
  {
    w[p]= exp(-(i*i+j*j+k*k)/sigma/sigma);
    sum += w[p];
    p++;
  }

  // normalize the weights
  p = 0;
  for(k=-f;k<=f;k++)
  for(j=-f;j<=f;j++)
  for(i=-f;i<=f;i++)
  {
    w[p] /= sum;
    p++;
  }

//  printf("end create_weights \n");
}

//------------------------------------------------------------------
void free_weights(double*& w)
{
  delete[] w;
  w = NULL;
}


//------------------------------------------------------------------
double probability_weight2(InrImage* in, InrImage* smoothed,
                            int x,int y, int z, 
                            int dx, int dy, int dz, 
                            double* w, int f, int check_limits)
{
//  printf("b sd \n");
  double mean = 0.0, var = 0.0;
  int i,j,k,tx,ty,tz,txy;

  float* in_buf0;
  float* in_buf1;
  float* in_buf2;
  double* w_buf0;
  double* w_buf1;
  double* w_buf2;


  int displ_dxdy;
  int displ_dxdydz;

  tx = in->DimX();
  ty = in->DimY();
  tz = in->DimZ();
  txy = tx*in->DimY();

  int fj_min,fj_max,fi_min,fi_max,fk_min,fk_max;
  if (check_limits) {
    // check limit for patch center on x,y,z
    fi_min = (x-f>=0   ?-f:-x);
    fi_max = (x+f<=tx-1?+f:tx-1-x);
    fj_min = (y-f>=0   ?-f:-y);
    fj_max = (y+f<=ty-1?+f:ty-1-y);
    if (tz>1) {
      fk_min = (z-f>=0   ?-f:-z);
      fk_max = (z+f<=tz-1?+f:tz-1-z);
    } else    fk_min=fk_max = 0;

    // check limit for patch center on x+dx,y+dy,z+dz
    int fj1_min,fj1_max,fi1_min,fi1_max,fk1_min,fk1_max;
    fi1_min = (x+dx-f>=0   ?-f:-(x+dx));
    fi1_max = (x+dx+f<=tx-1?+f:tx-1-(x+dx));
    fj1_min = (y+dy-f>=0   ?-f:-(y+dy));
    fj1_max = (y+dy+f<=ty-1?+f:ty-1-(y+dy));
    if (tz>1) {
      fk1_min = (z+dz-f>=0   ?-f:-(z+dz));
      fk1_max = (z+dz+f<=tz-1?+f:tz-1-(z+dz));
    }else    fk1_min=fk1_max = 0;

    // combine restrictions
    fi_min = max(fi_min,fi1_min);
    fi_max = min(fi_max,fi1_max);
    fj_min = max(fj_min,fj1_min);
    fj_max = min(fj_max,fj1_max);
    if (tz>1) {
      fk_min = max(fk_min,fk1_min);
      fk_max = min(fk_max,fk1_max);
    }else    fk_min=fk_max = 0;
  } else {
    if (tz>1) {
      fi_min = fj_min = fk_min = -f;
      fi_max = fj_max = fk_max = f;
    } else {
      fi_min = fj_min =  -f;
      fi_max = fj_max =  f;
      fk_min = fk_max = 0;
    }
  }

  // extract subimages
  InrImage::ptr sub1;
  InrImage* sub1_smoothed;
  InrImage::ptr sub2;
  InrImage* sub1diff;
  InrImage* sub2diff;


  sub1 = InrImage::ptr(Func_SubImage(in,
                          x+fi_min,y+fj_min,z+fk_min,
                          x+fi_max,y+fj_max,z+fk_max));
  sub1_smoothed = Func_SubImage(smoothed, 
                          x+fi_min,y+fj_min,z+fk_min,
                          x+fi_max,y+fj_max,z+fk_max);
  sub2 = InrImage::ptr(Func_SubImage(in,
                          x+dx+fi_min,y+dy+fj_min,z+dz+fk_min,
                          x+dx+fi_max,y+dy+fj_max,z+dz+fk_max));

  if (!sub2) {
    cerr << "pb getting the subwindow sub ar x+dx,y+dy,z+dz" << endl;
    return 0;
  }

  sub1diff = (*sub1)-(*sub1_smoothed);
  sub2diff = (*sub2)-(*sub1_smoothed);

  if (!sub2diff) {
    cerr << "pb sub2 null" << endl;
    return 0;
  }


  double mean1 = Func_mean(sub1diff);
  double mean2 = Func_mean(sub2diff);


  if (!sub2diff) {
    cerr << "pb sub2 null" << endl;
    return 0;
  }

  sub1 = InrImage::ptr((*sub1diff)*(*sub1diff));
  sub2 = InrImage::ptr((*sub2diff)*(*sub2diff));

  double var1 = Func_mean(sub1.get())-mean1*mean1;
  double var2 = Func_mean(sub2.get())-mean2*mean2;

  double diff = mean1-mean2;
  double varsum = var1+var2+0.01;

  delete sub1_smoothed;
  delete sub1diff;
  delete sub2diff;

 
  return (1.0/sqrt(varsum))*exp(-diff*diff/(2.0*(varsum)));
//  printf("e sd \n");

}  // probability_weight2


//------------------------------------------------------------------
double probability_weight(InrImage* in, int x,int y, int z, 
                                        int dx, int dy, int dz, 
                                        double* w, int f, int check_limits)
{
//  printf("b sd \n");
  double mean = 0.0, var = 0.0;
  double diff;
  int i,j,k,tx,ty,tz,txy;

  float* in_buf0;
  float* in_buf1;
  float* in_buf2;
  double* w_buf0;
  double* w_buf1;
  double* w_buf2;


  int displ_dxdy;
  int displ_dxdydz;

  tx = in->DimX();
  ty = in->DimY();
  tz = in->DimZ();
  txy = tx*in->DimY();

  int fj_min,fj_max,fi_min,fi_max,fk_min,fk_max;
  if (check_limits) {
    // check limit for patch center on x,y,z
    fi_min = (x-f>=0   ?-f:-x);
    fi_max = (x+f<=tx-1?+f:tx-1-x);
    fj_min = (y-f>=0   ?-f:-y);
    fj_max = (y+f<=ty-1?+f:ty-1-y);
    if (tz>1) {
      fk_min = (z-f>=0   ?-f:-z);
      fk_max = (z+f<=tz-1?+f:tz-1-z);
    }

    // check limit for patch center on x+dx,y+dy,z+dz
    int fj1_min,fj1_max,fi1_min,fi1_max,fk1_min,fk1_max;
    fi1_min = (x+dx-f>=0   ?-f:-(x+dx));
    fi1_max = (x+dx+f<=tx-1?+f:tx-1-(x+dx));
    fj1_min = (y+dy-f>=0   ?-f:-(y+dy));
    fj1_max = (y+dy+f<=ty-1?+f:ty-1-(y+dy));
    if (tz>1) {
      fk1_min = (z+dz-f>=0   ?-f:-(z+dz));
      fk1_max = (z+dz+f<=tz-1?+f:tz-1-(z+dz));
    }

    // combine restrictions
    fi_min = max(fi_min,fi1_min);
    fi_max = min(fi_max,fi1_max);
    fj_min = max(fj_min,fj1_min);
    fj_max = min(fj_max,fj1_max);
    if (tz>1) {
      fk_min = max(fk_min,fk1_min);
      fk_max = min(fk_max,fk1_max);
    }
  } else {
    fi_min = fj_min = fk_min = -f;
    fi_max = fj_max = fk_max = f;
  }

  // steps in j and k for the weights
  int tij,ti,t0;
  ti = 2*f+1;
  tij = ti*ti;

  // position at (x,y,z)
  in_buf0 = (float*)in->Buffer()+z*txy+y*tx+x;

  //
  // 3D version
  //
  if (tz>1) {

    t0 = f*(tij+ti+1); // step to the central weight;
    w_buf0   = w+t0;

    // increment to go from (x,y,z) to (x+dx,y+dy,z+dz)
    displ_dxdydz = dz*txy+dy*tx+dx;

    // set initial displacement: (fi_min,fj_min,k)
    in_buf0 += fk_min*txy+fj_min*tx+fi_min;
    w_buf0  += fk_min*tij+fj_min*ti+fi_min;

    for(k=fk_min;k<=fk_max;k++) {
      in_buf1 = in_buf0;
      w_buf1   = w_buf0;
      for(j=fj_min;j<=fj_max;j++) {
        in_buf2 = in_buf1;
        w_buf2   = w_buf1;
    for(i=fi_min;i<=fi_max;i++) {
        diff  =  *in_buf2 - in_buf2[displ_dxdydz];
        mean += diff*(*w_buf2);
        var  += diff*diff* (*w_buf2);
        w_buf2++;
        in_buf2++;
    }
        // step to next line
        in_buf1 += tx;
        w_buf1  += ti;
      }  // j
      // step to next plane (without flying :))
      in_buf0 += txy;
      w_buf0  += tij;
    }  // k
  } else {
  //
  // 2D version
  //
    // steps in j and k for the weights
    t0 = f*(ti+1); // step to the central weight;
    w_buf0   = w+t0;

    // set initial displacement: (fi_min,fj_min)
    in_buf0 += fj_min*tx+fi_min;
    w_buf0  += fj_min*ti+fi_min;
    // increment to go from (x,y) to (x+dx,y+dy)
    displ_dxdy = dy*tx+dx;

    for(j=fj_min;j<=fj_max;j++) {
    in_buf1 = in_buf0;
    w_buf1  = w_buf0;
    for(i=fi_min;i<=fi_max;i++) {
        diff  =  *in_buf1 - in_buf1[displ_dxdy];
        mean += diff*(*w_buf1);
        var  += diff*diff* (*w_buf1);
        w_buf1++;
        in_buf1++;
    }
        // step to next line
    in_buf0 += tx;
    w_buf0 += ti;
    }
  }

  var = var-mean*mean;
  if (var<1E-4) var=1E-4;
  //_in = exp(-mu_Y*mu_Y/(var_Y*2))/sqrt(var_Y)

  return (1.0/sqrt(var))*exp(-mean*mean/(2.0*var));
//  printf("e sd \n");

}  // probability_weight


//------------------------------------------------------------------
double square_distance(InrImage* in, int x,int y, int z, int dx, int dy, int dz, double* w, int f, int check_limits)
{
//  printf("b sd \n");
  double dist=0;
  double diff;
  int i,j,k,tx,ty,tz,txy;

  float* in_buf0;
  float* in_buf1;
  float* in_buf2;
  double* w_buf0;
  double* w_buf1;
  double* w_buf2;

  int displ_dxdy;
  int displ_dxdydz;

  tx = in->DimX();
  ty = in->DimY();
  tz = in->DimZ();
  txy = tx*in->DimY();

  int fj_min,fj_max,fi_min,fi_max,fk_min,fk_max;
  if (check_limits) {
    // check limit for patch center on x,y,z
    fi_min = (x-f>=0   ?-f:-x);
    fi_max = (x+f<=tx-1?+f:tx-1-x);
    fj_min = (y-f>=0   ?-f:-y);
    fj_max = (y+f<=ty-1?+f:ty-1-y);
    if (tz>1) {
      fk_min = (z-f>=0   ?-f:-z);
      fk_max = (z+f<=tz-1?+f:tz-1-z);
    }

    // check limit for patch center on x+dx,y+dy,z+dz
    int fj1_min,fj1_max,fi1_min,fi1_max,fk1_min,fk1_max;
    fi1_min = (x+dx-f>=0   ?-f:-(x+dx));
    fi1_max = (x+dx+f<=tx-1?+f:tx-1-(x+dx));
    fj1_min = (y+dy-f>=0   ?-f:-(y+dy));
    fj1_max = (y+dy+f<=ty-1?+f:ty-1-(y+dy));
    if (tz>1) {
      fk1_min = (z+dz-f>=0   ?-f:-(z+dz));
      fk1_max = (z+dz+f<=tz-1?+f:tz-1-(z+dz));
    }

    // combine restrictions
    fi_min = max(fi_min,fi1_min);
    fi_max = min(fi_max,fi1_max);
    fj_min = max(fj_min,fj1_min);
    fj_max = min(fj_max,fj1_max);
    if (tz>1) {
      fk_min = max(fk_min,fk1_min);
      fk_max = min(fk_max,fk1_max);
    }
  } else {
    fi_min = fj_min = fk_min = -f;
    fi_max = fj_max = fk_max = f;
  }

  // steps in j and k for the weights
  int tij,ti,t0;
  ti = 2*f+1;
  tij = ti*ti;

  // position at (x,y,z)
  in_buf0 = (float*)in->Buffer()+z*txy+y*tx+x;

  //
  // 3D version
  //
  if (tz>1) {

    t0 = f*(tij+ti+1); // step to the central weight;
    w_buf0   = w+t0;

    // increment to go from (x,y,z) to (x+dx,y+dy,z+dz)
    displ_dxdydz = dz*txy+dy*tx+dx;

    // set initial displacement: (fi_min,fj_min,k)
    in_buf0 += fk_min*txy+fj_min*tx+fi_min;
    w_buf0  += fk_min*tij+fj_min*ti+fi_min;

    for(k=fk_min;k<=fk_max;k++) {
      in_buf1 = in_buf0;
      w_buf1   = w_buf0;
      for(j=fj_min;j<=fj_max;j++) {
        in_buf2 = in_buf1;
        w_buf2   = w_buf1;
    for(i=fi_min;i<=fi_max;i++) {
        diff  =  *in_buf2 - in_buf2[displ_dxdydz];
        dist += diff*diff* (*w_buf2);
        w_buf2++;
        in_buf2++;
    }
        // step to next line
    in_buf1 += tx;
        w_buf1  += ti;
      }  // j
      // step to next plane (without flying :))
      in_buf0 += txy;
      w_buf0  += tij;
    }  // k
  } else {
  //
  // 2D version
  //
    // steps in j and k for the weights
    t0 = f*(ti+1); // step to the central weight;
    w_buf0   = w+t0;

    // set initial displacement: (fi_min,fj_min)
    in_buf0 += fj_min*tx+fi_min;
    w_buf0  += fj_min*ti+fi_min;
    // increment to go from (x,y) to (x+dx,y+dy)
    displ_dxdy = dy*tx+dx;

    for(j=fj_min;j<=fj_max;j++) {
    in_buf1 = in_buf0;
    w_buf1  = w_buf0;
    for(i=fi_min;i<=fi_max;i++) {
        diff  =  *in_buf1 - in_buf1[displ_dxdy];
        dist += diff*diff* (*w_buf1);
        w_buf1++;
        in_buf1++;
    }
        // step to next line
    in_buf0 += tx;
    w_buf0 += ti;
    }
  }

  return dist;
//  printf("e sd \n");

} // square_distance


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
};


//----------------------------------------------------------------------------------------
void* thread_NLmeans( void* threadarg)
{
  // loading arguments
  thread_NLmeans_info* args = (thread_NLmeans_info*) threadarg;

  InrImage* input_float = args->input_float;
  InrImage* result      = args->result;
  int       t           = args->t;
  int       f           = args->f;
  float     h           = args->h;
  int       noisetype   = args->noisetype;
  long*     pts_processed = args->points_processed;
  int       probability_variant = args->probability_variant;
  InrImage::ptr       smoothed_image;
  if (args->smoothed_image.use_count()) smoothed_image=args->smoothed_image;

  int tx=input_float->DimX();
  int ty=input_float->DimY();
  int tz=input_float->DimZ();
//  int vdim=input_field->GetVDim();

#define MAX_WEIGHTS 4
  // store the highest weights
  float max_weights[MAX_WEIGHTS] = {0,0,0,0};
  float max_weights_intensities[MAX_WEIGHTS] = {0,0,0,0};

  double *dist_weights;

  int x,y,z;
  register int dx,dy,dz;
  register double wmax,dist, w, average, total_weight;

  int percentage=0;
  int new_percentage=0;
  int per_step;
  int point_index;

  printf("Thread %d / %d \n",args->thread_id+1,args->total_threads);

  cout << "smoothed_image.use_count() " << smoothed_image.use_count() << endl;

  if (tz>1)
    create_weights_3d(dist_weights,f);
  else
    create_weights_2d(dist_weights,f);


/*
For each pixel x {

  - We take a window centered in x and size 2t+1 x 2t+1, A(x,t).

A(x,t) denotes the learning window of pixels which will be averaged. Theoretically A(x,t) should be all the image but in practice t= 7, 9 gives good results. This means a learning window of 15x15 or 18x18.
    - We take a window centered in x and size 2f+1 x 2f+1, W(x,f).

W(x,f) denotes the comparison window (f should be smaller than t). In a non-noisy image it can be set to f=1 (3x3). The value of f increases with the amount of noise. In general for noisy images, f=3, 4 is a good value. This means a window 7x7 or 9x9.
    wmax=0;
*/
  int dx_min,dy_min,dz_min,dx_max,dy_max,dz_max;
  int check_limits=0;
  double intensity,tmp;
  float* result_buf;

  // BufferPos if not thread safe ...
  result_buf = (float*)result->Buffer();

  if (tz>10)
    per_step = 1;
  else
    per_step = 10;

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
//    printf(" x y z %d %d %d \n",x,y, z);

    tmp = 1.0/(tx*ty*tz)*(100.0/per_step);
    percentage     = (int) ((*pts_processed)*tmp);
    (*pts_processed)++;
    new_percentage = (int) ((*pts_processed)*tmp);
    if (new_percentage!=percentage) {
    percentage=new_percentage;
        printf(" %d %% \t",percentage*per_step);
        fflush(stdout);
    }

/*
The distance between x and itself is zero. This would concentrate the probaility distribution too much. For this reason x is treated in a special way.
    For each pixel y in A(x,t) && y different from x {

All the pixels inside A(x,t) are used even when W(y,f) is not totally contained in A(x,t). We have all the image and so we can compute the window difference using the pixels outside A(x,t).
      - We compute the difference between W(x,f) and W(y,f), d(x,y).

This difference is based on the square euclidean distance of the two windows and detailed below.
*/

    dx_min = (x-t>=0?-t:-x);
    dy_min = (y-t>=0?-t:-y);
    dz_min = (z-t>=0?-t:-z);

    dx_max = (x+t<tx?t:tx-1-x);
    dy_max = (y+t<ty?t:ty-1-y);
    dz_max = (z+t<tz?t:tz-1-z);

    check_limits = (x-f-t<0)||(y-f-t<0)||
           (x+f+t>tx-1)||(y+f+t>ty-1);

    // 3D case
    if (tz>1)
    check_limits = check_limits || (z-f-t<0) ||
            (z+f+t>tz-1);

    for(int i=0;i<MAX_WEIGHTS;i++) {
      max_weights[i]=0;
      max_weights_intensities[i]=0;
    }

    for(dx=dx_min;dx<=dx_max;dx++)
    for(dy=dy_min;dy<=dy_max;dy++)
    for(dz=dz_min;dz<=dz_max;dz++)

      if ((dx!=0)||(dy!=0)||(dz!=0)) {

/*
      - We compute the weight from the distance d(x,y), w(x,y).
          w(x,y) = exp(- d(x,y) / h);
The weight is given by a decreasing function of the distance. The parameter h measures the degree of filtering of the obtained image. When we know the standard deviation of the noise, sigma, the value of h should depend on it. (a good value is between 10*sigma and 15*sigma).
*/
        if (probability_variant==0) {
          InrImage* dist_input = input_float;
          if (smoothed_image.use_count()) dist_input = smoothed_image.get();
          dist = square_distance(dist_input,
              x,y,z,dx,dy,dz,
              dist_weights,f, check_limits);
          w = exp(-dist/(h*h));
        } else 
        if (probability_variant==1) {
          InrImage* dist_input = input_float;
          if (smoothed_image.use_count())  dist_input = smoothed_image.get();
          w = probability_weight( dist_input,
                x,y,z,dx,dy,dz,
                dist_weights,f, check_limits);
        } else 
        if (probability_variant==2) {
          InrImage* dist_input = input_float;
          if (smoothed_image.use_count())  dist_input = smoothed_image.get();
          w = probability_weight2( input_float, dist_input,
                x,y,z,dx,dy,dz,
                dist_weights,f, 1);
//check_limits);
        }

/*
      - If w(x,y) is bigger than wmax then
          wmax = w(x,y);
We compute the maximum weight obtained with a point different from x.
      - We compute the average
        average + = w(x,y) * u(y);
     - We carry the sum of the weights
        totalweight + = w( x, y);
x has the maximum weight obtained by a point y different from it.
    }
*/

        if (w>wmax) wmax=w;
        intensity = (*input_float)(x+dx,y+dy,z+dz);
        // check if within the maximal weights
        int i = 0;
        while ((i<MAX_WEIGHTS)&&(w>max_weights[i])) {
          i++;
        }
        if (i>0) {
          i--;
          max_weights[i] = w;
          max_weights_intensities[i] = intensity;
        }
        switch (noisetype) {
            case 0: average += w*intensity; break;
            // Rician noise, average the square of the intensity
            case 1: average += w*intensity*intensity; break;
        }
        total_weight += w;
      }
/*
   - We give to x the maximum of the other weights
      average += wmax * u(x);
      totalweight + = wmax;
   - We compute the restored value
      rest(x) = average / totalweight;
*/
     if (probability_variant) {
/*
        average = total_weight = 0;
        for(int i=0;i<MAX_WEIGHTS;i++) {
          switch (noisetype) {
            case 0: average += max_weights[i]*max_weights_intensities[i]; break;
            // Rician noise, average the square of the intensity
            case 1: average += max_weights[i]*max_weights_intensities[i]*max_weights_intensities[i]; break;
          }
          total_weight += max_weights[i];
        }
*/
     }


     // result->BufferPos(x,y,z);
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
  }

  free_weights(dist_weights);
   pthread_exit(NULL);
	return NULL;
}


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
            ";

    InrImage* input;
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
    InrImage::ptr smoothed_image;

  if (!get_image_param(  input,       p, n)) HelpAndReturnNULL;
  if (!get_int_param(    t,           p, n)) HelpAndReturnNULL;
  if (!get_int_param(    f,           p, n)) HelpAndReturnNULL;
  if (!get_float_param(  h,           p, n)) HelpAndReturnNULL;
  if (!get_int_param(    noisetype,   p, n)) HelpAndReturnNULL;
  if (!get_int_param(    num_threads, p, n)) HelpAndReturnNULL;
  if (!get_int_param(    probability_variant, p, n)) HelpAndReturnNULL;
  if (!get_float_param(  presmooth_sd,        p, n)) HelpAndReturnNULL;

  if (fabs(h)<1E-2) {
    fprintf(stderr,"NLmeans error \t the coefficient h cannot be too small, it is set to 10 !\n");
    h = 10;
  }

  if (input->GetFormat()!=WT_FLOAT) {
   input_float = new InrImage(WT_FLOAT,"NLmeans_result.ami.gz",input);
   (*input_float)=(*input);
  } else {
    input_float=input;
  }

  result = new InrImage(WT_FLOAT,"NLmeans_result.ami.gz",input);
  (*result)=(*input);


    // num_threads
    thread_NLmeans_info* thread_info;
    int i;
    pthread_t* threads;
    pthread_attr_t attr;
    int rc,status;
    long points_processed = 0;


  if (presmooth_sd>0) {
    smoothed_image = InrImage::ptr(Func_Filter( input_float, presmooth_sd,0,0,0));
  } else {
    cout << "no smoothing" << endl; 
  }


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
   }

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

  if (!get_image_param(      input,       p, n)) HelpAndReturnNULL;
  if (!get_image_param(      input_field, p, n)) HelpAndReturnNULL;
  if (!get_int_param(        t,           p, n)) HelpAndReturnNULL;
  if (!get_float_param(      h,           p, n)) HelpAndReturnNULL;
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
    InrImage* input_roi;
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

  if (!get_image_param(      input,       p, n)) HelpAndReturnNULL;
  if (!get_image_param(      input_roi,   p, n)) HelpAndReturnNULL;
  if (!get_int_param(        t,           p, n)) HelpAndReturnNULL;
  if (!get_float_param(      h,           p, n)) HelpAndReturnNULL;
  if (!get_float_param(      sigma,       p, n)) HelpAndReturnNULL;
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

  if (!get_image_param(      input,       p, n)) HelpAndReturnNULL;
  if (!get_image_param(      basis,       p, n)) HelpAndReturnNULL;
  if (!get_image_param(      weights,     p, n)) HelpAndReturnNULL;
  if (!get_image_param(      mask,        p, n)) HelpAndReturnNULL;

  return Func_LeastSquares( input, basis, weights, mask);
}


//--------------------------------------------------------------------
//  Return a vector of images including
//  eigenvalues and eigenvectors depending on flags
//  use image dimensions to call the 2D or the 3D versions
//
// TODO: allow returning a list or something more evolved !!!
//

Variable::ptr Wrap_EigenDecomp(ParamList* p) {
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

  if (!get_image_param(         input,       p, n)) HelpAndReturnVarPtr;
  if (!get_int_param(           value_flag,  p, n)) HelpAndReturnVarPtr;
  if (!get_int_param(           vector_flag, p, n)) HelpAndReturnVarPtr;
  if (!get_optionalimage_param( mask,        p, n)) HelpAndReturnVarPtr;


  vector<InrImage::ptr> result;

  // how to do with smart pointers ???
  // should be managed by ParamList ...
  // got rid of them for now
  result = EigenDecomp( input, value_flag, vector_flag, mask);

  // Create the resulting variable array
  VarArray* array;
  array = new VarArray();
  array->Init(type_image,result.size());

  for(n=0;n<(int)result.size();n++)
    if (result[n]!=NULL)
      array->InitElement<InrImage>(n,
           result[n],
           str(format("eigen_decomp_%d") %n).c_str());

  Variable::ptr varres(new Variable());
  varres->Init(type_array,"EigenDecomp_result",array);

  return varres;
}



// Resample lines using splines
Variable::ptr Wrap_SmoothLinesToSplines(ParamList* p)
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

    SurfacePoly* input;
    float samplingstep = 0.1;
    int n=0;

  if (!get_surface_param(  input,        p, n)) HelpAndReturnVarPtr;
  if (!get_float_param(    samplingstep, p, n)) HelpAndReturnVarPtr;


  SurfacePoly* surf_result = Func_SmoothLinesToSplines( input, samplingstep );

  Variable::ptr varres(new Variable());
  varres->Init(type_surface,"interpolatedsplines_result",surf_result);

  return varres;


} // Wrap_SmoothLinesToSplines()
