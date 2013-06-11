//
// C++ Implementation: NLmeans
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

#include "NLmeans.h"

#include "AMILabConfig.h"
#include "fonctions.h"
#include <pthread.h>
//#include "wrapfunctions.hpp"

#ifndef macro_min
  #define macro_min(n1,n2) ((n1)<(n2)?(n1):(n2))
#endif

#ifndef macro_max
  #define macro_max(n1,n2) ((n1)>(n2)?(n1):(n2))
#endif 

//------------------------------------------------------------------
double probability_weight2(InrImage* in, InrImage* smoothed,
                            int x,int y, int z, 
                            int dx, int dy, int dz, 
                            double* w, int f, int check_limits)
{
//  printf("b sd \n");
  //double mean = 0.0, var = 0.0;
  //int i,j,k;
  int tx,ty,tz,txy;

  //float* in_buf0;
  //float* in_buf1;
  //float* in_buf2;
  //double* w_buf0;
  //double* w_buf1;
  //double* w_buf2;


  //int displ_dxdy;
  //int displ_dxdydz;

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
    fi_min = macro_max(fi_min,fi1_min);
    fi_max = macro_min(fi_max,fi1_max);
    fj_min = macro_max(fj_min,fj1_min);
    fj_max = macro_min(fj_max,fj1_max);
    if (tz>1) {
      fk_min = macro_max(fk_min,fk1_min);
      fk_max = macro_min(fk_max,fk1_max);
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
  InrImage::ptr sub1_smoothed;
  InrImage::ptr sub2;
  InrImage* sub1diff;
  InrImage* sub2diff;


  sub1 =          Func_SubImageNew( in,
                                    x+fi_min,y+fj_min,z+fk_min,
                                    x+fi_max,y+fj_max,z+fk_max);
  sub1_smoothed = Func_SubImageNew( smoothed, 
                                    x+fi_min,y+fj_min,z+fk_min,
                                    x+fi_max,y+fj_max,z+fk_max);
  sub2 =          Func_SubImageNew( in,
                                    x+dx+fi_min,y+dy+fj_min,z+dz+fk_min,
                                    x+dx+fi_max,y+dy+fj_max,z+dz+fk_max);

  if (!sub2.get()) {
    std::cerr << "pb getting the subwindow sub ar x+dx,y+dy,z+dz" << std::endl;
    return 0;
  }

  sub1diff = (*sub1)-(*sub1_smoothed);
  sub2diff = (*sub2)-(*sub1_smoothed);

  if (!sub2diff) {
    std::cerr << "pb sub2 null" << std::endl;
    return 0;
  }


  double mean1 = Func_mean(sub1diff);
  double mean2 = Func_mean(sub2diff);


  if (!sub2diff) {
    std::cerr << "pb sub2 null" << std::endl;
    return 0;
  }

  sub1 = InrImage::ptr((*sub1diff)*(*sub1diff));
  sub2 = InrImage::ptr((*sub2diff)*(*sub2diff));

  double var1 = Func_mean(sub1.get())-mean1*mean1;
  double var2 = Func_mean(sub2.get())-mean2*mean2;

  double diff = mean1-mean2;
  double varsum = var1+var2+0.01;

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

  int fj_min=0,fj_max=0,fi_min,fi_max,fk_min=0,fk_max=0;
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
    fi_min = macro_max(fi_min,fi1_min);
    fi_max = macro_min(fi_max,fi1_max);
    fj_min = macro_max(fj_min,fj1_min);
    fj_max = macro_min(fj_max,fj1_max);
    if (tz>1) {
      fk_min = macro_max(fk_min,fk1_min);
      fk_max = macro_min(fk_max,fk1_max);
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

  int fj_min=0,fj_max=0,fi_min,fi_max,fk_min=0,fk_max=0;
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
    fi_min = macro_max(fi_min,fi1_min);
    fi_max = macro_min(fi_max,fi1_max);
    fj_min = macro_max(fj_min,fj1_min);
    fj_max = macro_min(fj_max,fj1_max);
    if (tz>1) {
      fk_min = macro_max(fk_min,fk1_min);
      fk_max = macro_min(fk_max,fk1_max);
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



//------------------------------------------------------------------
void create_weights_2d(double*& w, int f, float factor)
{
  int i,j,p;
  double sum;
  double sigma = f*factor;
//  printf("begin create_weights \n");
  FILE_MESSAGE((boost::format("factor = %1%")%factor).str().c_str());

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
void create_weights_3d(double*& w, int f, float factor)
{
  int i,j,k,p;
  double sum;
  double sigma = f*factor;
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
  float     pattern_weight_factor = args->pattern_weight_factor;
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
  register double wmax,dist, w=0, average, total_weight;

  int percentage=0;
  int new_percentage=0;
  int per_step;
  int point_index;

  printf("Thread %d / %d \n",args->thread_id+1,args->total_threads);

 std::cout << "smoothed_image.use_count() " << smoothed_image.use_count() << std::endl;

  if (tz>1)
    create_weights_3d(dist_weights,f,pattern_weight_factor);
  else
    create_weights_2d(dist_weights,f,pattern_weight_factor);


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
/*          if ((x==5)&&(y==5)) {
           std::cout << boost::format("dist_input(5,5) = %1%") % (*dist_input)(5,5) << std::endl;
           std::cout << boost::format("dx %1% dy %2% dist=%3% w=%4%")
                    %dx %dy %dist %w << std::endl;
          }*/
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
        /*
        if ((x==40)&&(y==20)) {
         std::cout  << __func__ 
                << boost::format(" (x,y) = (%1%,%2%) ") %x %y
                << boost::format(" (dx,dy,dz) = (%1%,%2%,%3%) ") %dx %dy %dz
                << boost::format(" (w,val) = (%1%,%2%) ") %w %intensity
                << std::endl;
        }
        */
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
      } // end if and for

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
  // no thread if only 1
  if (args->total_threads>1)
    pthread_exit(NULL);
  return NULL;
}
