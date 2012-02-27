//
// C++ Implementation: AnisoGS
//
// Description: Denoising Filter
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "amiAnisoGS_NRAD.h"


#include "localstats.h"
#include "func_globalstats.h"
#include "func_imagebasictools.h"
#include "Eigen.hpp"
#include "CurvaturasPrincipales.hpp"
#include "filtrage_rec.hpp"

#define IncX(I)  ((x<tx-1)?(I+1):I)
#define Inc2X(I) ((x<tx-2)?(I+1):I)
#define DecX(I)  ((x>0)?(I-1):I)

#define IncY(I)  ((y<ty-1)?(I+tx):I)
#define Inc2Y(I) ((y<ty-2)?(I+tx):I)
#define DecY(I)  ((y>0)?(I-tx):I)

#define IncZ(I)  ((z<tz-1)?(I+txy):I)
#define Inc2Z(I) ((z<tz-2)?(I+txy):I)
#define DecZ(I)  ((z>0)?(I-txy):I)


//#define phi0(x)         exp(-((x)*(x)/k/k))
#define phi0(x)         exp(-0.5*((x)*(x)/k/k))
#define phi1(x)         tang_coeff

//#define phi3D_0(x) exp(-((x)*(x)/k/k))
//#define phi3D_0(x) exp(-0.5*((x)*(x)/k/k))
//#define phi3D_0(x) 1.0/(x+0.001)
//#define phi3D_0(x) tanh((x)/k)/(x)
#define phi3D_0(x) 1.0/(1.0+(x)*(x)/k/k)


#define phi3D_1(x) maxcurv_coeff
#define phi3D_2(x) mincurv_coeff

#ifndef macro_min
  #define macro_min(n1,n2) ((n1)<(n2)?(n1):(n2))
#endif

#ifndef macro_max
  #define macro_max(n1,n2) ((n1)>(n2)?(n1):(n2))
#endif 

#include <limits>
#ifdef min
  #undef min
#endif
#ifdef max
  #undef max
#endif

template<typename T>
inline bool ispositivevalue(const T& value)
{
  return  (value==0) 
          ||
          ( (value >= std::numeric_limits<T>::min()) 
            && 
            (value <= std::numeric_limits<T>::max()));
}


//------------------------------------------------------------------------------
// Destructor
ami::AnisoGS_NRAD::~AnisoGS_NRAD()
{

}


//------------------------------------------------------------------------------
void ami::AnisoGS_NRAD::ComputeImage_c(InrImage* im)
{

  int x,y,z; //,n,i;
  double I,Ixm,Iym,Izm,Ixp,Iyp,Izp,mean1,mean2,q0_2=0.0,q2;
  double sigma2=0.0;


  if ( this->image_c == NULL ) 
    this->image_c = new InrImage(WT_FLOAT, "image_c.ami.gz", im);

  // we limit for the moment to Kuan's function with Yu's neighborhood

  // precompute image of coefficients
  switch (noise_model)
    {
    case NOISE_LEE:
    case NOISE_KUAN:
      q0_2= Compute_q0_subvol(im);
      printf("q0_2 = %f \n",q0_2);
      break;

    case NOISE_GAUSSIAN_ADDITIVE:
      sigma2 = Compute_sigma2_Gaussian_mode(im);
      printf("noise SD = %3.2f \t",sqrt(sigma2));
      break;

    case NOISE_RICIAN:
      /*        sigma2 = Compute_sigma2_MRI(im);
              printf("sigma = %f \n",sqrt(sigma2));
      */
      sigma2 = Compute_sigma2_MRI_mode(im);
      printf("noise SD = %3.2f \t",sqrt(sigma2));
      break;
    }

  // Precompute mean of I and mean of I^2
  InrImage* image_mean_I  = NULL;
  InrImage* image_I2      = NULL;
  InrImage* image_mean_I2 = NULL;

  image_mean_I  = Func_localmean2(im,neighborhood);
  image_I2 = (*im)*(*im);
  image_mean_I2 = Func_localmean2(image_I2, neighborhood);
  delete image_I2;
  image_I2= NULL;

  // 1. Compute c
  for (z=0;z<tz;z++)
    {
      for (y=0;y<ty;y++)
        {
          for (x=0;x<tx;x++)
            {
              I = (*im)(x,y,z);
              if (fabsf(I)<1) I=1;
              if (x>0)     Ixm = (*im)(x-1,y,z);
              else Ixm = I;
              if (y>0)     Iym = (*im)(x,y-1,z);
              else Iym = I;
              if (z>0)     Izm = (*im)(x,y,z-1);
              else Izm = I;

              if (x<tx-1)  Ixp = (*im)(x+1,y,z);
              else Ixp = I;
              if (y<ty-1)  Iyp = (*im)(x,y+1,z);
              else Iyp = I;
              if (z<tz-1)  Izp = (*im)(x,y,z+1);
              else Izp = I;

              // other (simpler version of q2):
              switch (neighborhood)
                {
                case 0:
                  mean1 = Ixm+Ixp+Iym+Iyp;
                  mean2 = Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp;
                  if (tz==1)
                    {
                      mean1/=4.0;
                      mean2/=4.0;
                    }
                  else
                    {
                      mean1+=Izm+Izp;
                      mean2+=Izm*Izm+Izp*Izp;
                      mean1/=6.0;
                      mean2/=6.0;
                    }
                  break;
                  /*
                        //mean1 = (Ixm+Ixp+Iym+Iyp)/4.0;
                        //mean2 = (Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp)/4.0;
                        // adding the central point for stability
                        mean1 = (Ixm+Ixp+Iym+Iyp+I)/5.0;
                        mean2 = (Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp+I*I)/5.0;
                  */
                  break;
                default:
                  mean1 = (*image_mean_I) (x,y,z);
                  mean2 = (*image_mean_I2)(x,y,z);
                }

              if (fabsf(mean1)>1E-6)
                q2    = mean2/(mean1*mean1)-1;
              else q2 = 0;

              image_c->BufferPos(x,y,z);
              switch (noise_model)
                {
                case NOISE_LEE:
                  image_c->FixeValeur( function_c_Lee( q2, q0_2));
                  break;
                case NOISE_KUAN:
                  image_c->FixeValeur( function_c_Kuan( q2, q0_2));
                  break;
                case NOISE_GAUSSIAN_ADDITIVE: 
                  image_c->FixeValeur( function_c_additive(mean2-mean1*mean1,
                                                            sigma2)); 
                  break;
                case NOISE_RICIAN:
                  image_c->FixeValeur( function_c_MRI( sigma2, 
                                                        mean2-mean1*mean1, 
                                                        mean1));
                  break;
                }
            }
        }
    } // for z

  if (neighborhood>0)
    {
      delete image_mean_I;
      image_mean_I  = NULL;
      delete image_mean_I2;
      image_mean_I2 = NULL;
    }

//  image_c->Sauve();

}


// Compute the local directional mean and standard deviation,
// using a Gaussian of standard deviation sd
void  ami::AnisoGS_NRAD::ComputeLocalPlanStats(InrImage* im, float x, float y, float z, 
    t_3Point d1,t_3Point d2,
    float sd, double& mean, double& var)
{
//#define MAX_VALUES 100
  // 1. store intensity values
//  double intensities[MAX_VALUES];
//  double Gaussian[MAX_VALUES];

  float p1,p2;

  double fp1x,fp1y,fp1z;
  double fp2x,fp2y,fp2z;

  int px,py,pz;
  int px1,py1,pz1;
//  int i,index=0;
//  double sum_gauss = 0.0,twosd2;
  float p1_step = 1;
  float p2_step = 1;
  float size = 2*sd;
  double mean2,val;
  int nval=0;

//  twosd2 = 2*sd*sd;

  fp2x = x-size*d2.x-size*d1.x+0.5;
  fp2y = y-size*d2.y-size*d1.y+0.5;
  fp2z = z-size*d2.z-size*d1.z+0.5;
  mean  = 0.0;
  mean2 = 0.0;

  for(p2=-size;p2<=size;p2+=p2_step,fp2x+=d2.x,fp2y+=d2.y,fp2z+=d2.z) {
    fp1x = fp2x;
    fp1y = fp2y;
    fp1z = fp2z;
    px1=py1=pz1=-100;
    for(p1=-size;p1<=size;p1+=p1_step,fp1x+=d1.x,fp1y+=d1.y,fp1z+=d1.z) {
        px=(int) fp1x;
        py=(int) fp1y;
        pz=(int) fp1z;
        // don't add twice the same point
        if (((px!=px1)||(py!=py1)||(pz!=pz1))&
            ((px!=(int)(fp1x-d2.x))||(py!=(int)(fp1y-d2.y))||(pz!=(int)(fp1z-d2.z))))
        {
        val = (*im)(px,py,pz);
        mean  += val;
        mean2 += val*val;
        nval++;
        }
      px1 = px;
      py1 = py;
      pz1 = pz;
    }
  }

  if (nval==0) {
    printf("ComputeLocalPlanStats\n at %0.1f %0.1f %0.1f , no point found within the image domain ...\n",x,y,z);
    printf(" d1 %f %f %f d2 %f %f %f \n",d1.x,d1.y,d1.z,d2.x,d2.y,d2.z);
    mean=var=0;
  } else {
    mean  /= nval;
    mean2 /= nval;
    var = mean2-mean*mean;
  }


} // ComputeLocalPlanStats


// Compute the local directional mean and standard deviation,
// using a Gaussian of standard deviation sd
void  ami::AnisoGS_NRAD::ComputeLocalDirStats(InrImage* im, float x, float y, float z, t_3Point e,
    float sd, double& mean, double& var)
{
//#define MAX_VALUES 100
  // 1. store intensity values
//  double intensities[MAX_VALUES];
//  double Gaussian[MAX_VALUES];

  float p;
  double fpx,fpy,fpz;
  int px,py,pz;
  int px1,py1,pz1;
//  int i,index=0;
//  double sum_gauss = 0.0,twosd2;
  float p_step = 1;
  float size = 2*sd;
  double mean2,val;
  int nval=0;

  px1=py1=pz1=-100;
//  twosd2 = 2*sd*sd;

  fpx = x-size*e.x+0.5;
  fpy = y-size*e.y+0.5;
  fpz = z-size*e.z+0.5;
  mean  = 0.0;
  mean2 = 0.0;

  for(p=-size;p<=size;p+=p_step,fpx+=e.x,fpy+=e.y,fpz+=e.z) {
    px=(int) fpx;
    py=(int) fpy;
    pz=(int) fpz;
    // don't add twice the same point
    if ((px!=px1)||(py!=py1)||(pz!=pz1))
    {
      val = (*im)(px,py,pz);
      mean  += val;
      mean2 += val*val;
      nval++;
    }
    px1 = px;
    py1 = py;
    pz1 = pz;
  }

  if (nval==0) {
    printf("ComputeLocalDirStats\n e= %f %f %f no point found within the image domain ...\n",e.x,e.y,e.z);
    mean=var=0;
  } else {
    mean  /= nval;
    mean2 /= nval;
    var = mean2-mean*mean;
  }

/*
  for(p=-3*sd;p<=3*sd;p+=p_step) {
    px=(int) (0.5+x+p*e.x);
    py=(int) (0.5+y+p*e.y);
    pz=(int) (0.5+z+p*e.z);
    // don't add twice the same point
    if ((px!=px1)||(py!=py1)||(pz!=pz1))
    if (im->CoordOK(px,py,pz)) {
  //    intensities[index] = im->InterpLinIntensite(px,py,pz);
      intensities[index] = (*im)(px,py,pz);
      // for now don't check boundaries since the linear interpolation method can deal with them
      Gaussian[index] = exp(-p*p/(twosd2)); // this could be pre-computed ...
      sum_gauss += Gaussian[index];
      if (index<MAX_VALUES-1)
        index++;
      else {
        fprintf(stderr,"ami::AnisoGS::ComputeLocalDirStats() \t Too many values \n");
        break;
      }
    }
  }

  if (sum_gauss==0) {
    printf("ComputeLocalDirStats\n e= %f %f %f no point found within the image domain ...\n",e.x,e.y,e.z);
  }

  // mean
  mean = 0.0;
  for(i=0;i<index;i++) {
    mean += intensities[i]*Gaussian[i];
  }
  mean /= sum_gauss;

  // variance
  var = 0.0;
  for(i=0;i<index;i++) {
    var += (intensities[i]-mean)*(intensities[i]-mean)*Gaussian[i];
  }
  var /= sum_gauss;
*/ 

} // ComputeLocalDirStats



//------------------------------------------------------------------------------
// using minimal and maximal curvature directions
//
// Extension for taking into account the noise characteristics:
// Rician Noise
// Use of the structure tensor for filtering
//
// Use a mask for the processing if the mask image is set.
//
float ami::AnisoGS_NRAD::Itere3D_ST_RNRAD( InrImage* im )
//
{
    int x,y,z; //,n,i;
    double   val0,val1,val1prev;
    double   val1_implicit=0;
    double   val1div;
    double   u_e0;
    double   u_e1;
    double   u_e2;
    double   alpha1_x, gamma1_x;
    double   alpha1_y, gamma1_y;
    double   alpha1_z, gamma1_z;
    float*  in;
    register float    *Iconv=NULL; 
//    float gradient[3];
//    float hessien[3][3];
    unsigned long outoflimits=0;

    t_3Point e0;
    t_3Point e1;
    t_3Point e2;

    t_Gradient grad;

    float   erreur = 0; //,norm_grad;
    double diff;
    int nb_points_instables;
    int erreur_x=0,erreur_y=0,erreur_z=0;

    // Sum over all the points
    float     sum_divF;
    long int  nb_calculated_points;

    // Sum over the points that don't evolve too much
    float     sum_divF2;
    long int  nb_calculated_points2;

    float     u,u0;
    float     divF=0;
    std::string    divFname;

    unsigned char mask_test;
//    double    phi0_value=0;
    double    lambda0=0,lambda1=0,lambda2=0;
    double    sigma2=0.0; // variance of the noise
 
/*
    double   planstats_sigma = 1.0;
    double   dirstats_sigma  = 1.5;
*/
//    double lambda_threshold = 0.6;

//    double        diff_coeff;
    /// skip heavy code because of speedup
    bool          speedup_skip;
    long          speedup_counter = 0;

    int      xp,xm,yp,ym,zp,zm,incx,incy,incz;
    double mean,var;
  // pre-compute information

  // printf("Itere3D_2_new \n");

  ComputeImage_c(im);
  // TODO: should not recompute sigma2 already computed in ComputeImage_c ...
  switch (noise_model) 
  {
    case NOISE_GAUSSIAN_ADDITIVE:
      sigma2 = Compute_sigma2_Gaussian_mode(im); break;
    case NOISE_RICIAN: 
      sigma2 = Compute_sigma2_MRI_mode(im); break;
  }

  if (SpeedUp_c) {
    // in case of speedup, need to compute eigenvectors at each iteration
    ComputeStructureTensor(im,0.7,sigma);
    ComputeEigenVectors();
  } else {
    if ((iteration==1)&&(loop==2)) {
      ComputeStructureTensor(im,0.7,sigma);
      ComputeEigenVectors();
    }
    if (iteration==loop) {
      ComputeStructureTensor(im,0.7,sigma);
      ComputeEigenVectors();
      loop+=2;
    }
  }

  ResetCoefficients();


  // pb: the coefficients are not good for multi-threading ???

  if ( this->im_tmp == NULL ) 
    this->im_tmp = new InrImage(WT_FLOAT, "im_tmp.inr.gz", im);
  if ( divFim == NULL ) {
    divFim = new InrImage(WT_FLOAT, divFname.c_str() , im);
  } // end if

  divFim->InitImage(0);
  im->InitBuffer();
  erreur = 0;
  nb_points_instables = 0;
  in = (float*) im->Buffer();

  diff = 0;

  nb_calculated_points = 0;
  sum_divF = 0;

  nb_calculated_points2 = 0;
  sum_divF2 = 0;

//printf("diff eigen mode : %d\n",diffusion_eigenvalues_mode);

  for(z=ROI_zmin;z<=ROI_zmax;z++) {
    if ( z==ROI_zmin ) {
      printf("z = %3d",z);
      fflush(stdout);
    } else 
    if ( (z-ROI_zmin)%5 == 0 ) {
      printf("\b\b\b");
      printf("%3d",z);
      fflush(stdout);
    } // end if

  // reset Y coefficients
  for(x=0;x<=tx-1;x++) {
    alpha_y[x] = gamma_y[x] = 0;
  } // endfor

  for(y=ROI_ymin;y<=ROI_ymax;y++) {
  // reset X coefficients
  alpha_x = gamma_x = 0;
  im->BufferPos(ROI_xmin,y,z);
  in = (float*) im->BufferPtr();

  for(x=ROI_xmin;x<=ROI_xmax;x++) {
  
    val1 = val0 = *in;
    mask_test = (!mask.get())||
                ((mask.get())&&((*mask)(x-ROI_xmin,y-ROI_ymin,z-ROI_zmin)>0.5));
    xp=1;
    xm=-1;
    incx=1;

// not necessary since boundary is taken care of
//    if (x==tx-1) { xp=0; incx=0; }
//    if (x==0)    xm=0;

    yp=tx;
    ym=-tx;
    incy=1;
//    if (y==ty-1) { yp=0; incy = 0; }
//    if (y==0)    ym=0;

    zp=txy;
    zm=-txy;
    incz=1;
//    if (z==tz-1) { zp=0; incz = 0; }
//    if (z==0)    zm=0;

    speedup_skip = false;

    if (SpeedUp_c) {
      double diff_coeff = ( *image_c ) ( x,y,z );
      // do a scalar diffusion to speed-up the process
      if (diff_coeff>SpeedUp_c_lowerbound) {
        alpha1_x =  ( diff_coeff + (*image_c)(x+incx,y,z) ) /2.0;;
        alpha1_y =  ( diff_coeff + (*image_c)(x,y+incy,z) ) /2.0;;
        alpha1_z =  ( diff_coeff + (*image_c)(x,y,z+incz) ) /2.0;;

        gamma1_x = gamma1_y = gamma1_z = 0;
        speedup_skip = true;
        speedup_counter++;
      }
    }

    if (!speedup_skip) {
      InitNeighborhood(Iconv,x,y,z);

      // Gradient en (x+1/2,y,z)
      //----- Calcul de alpha1_x, gamma1_x
      grad.x = *(in+xp) - *(in);
      grad.y = ( *(in+yp) - *(in+ym) + *(in+yp+xp) -*(in+ym+xp) )/ 4.0;
      grad.z = ( *(in+zp) - *(in+zm) + *(in+zp+xp)- *(in+zm+xp) )/ 4.0;

      // get vectors
      this->GetVectors(0,x,y,z,e0,e1,e2);

      lambda0 = ( (*image_c)(x,y,z) + (*image_c)(x+incx,y,z) ) /2.0; 
//      if (lambda0>2) lambda0=2;
      if (lambda0<1) {
        ComputeLocalPlanStats(im, 
                              (float)x+((float)incx)/2.0, (float) y, (float) z,  
                              e1,e2, planstats_sigma, mean,var);
        switch (noise_model) 
        {
          case NOISE_GAUSSIAN_ADDITIVE:
            lambda1 = function_c_additive(var, sigma2);   break;
          case NOISE_RICIAN: 
            lambda1 = function_c_MRI( sigma2, var, mean); break;
        }
        lambda1 *= 6./4.; // convert for 2D normalization
          switch (diffusion_eigenvalues_mode) {
          case DIFF_MATRIX_EIGEN_SUM:
            lambda1 = lambda0 + lambda1; 
            break;
          case DIFF_MATRIX_EIGEN_MAX:
            lambda1 = MAX(lambda0,lambda1); 
            break;
          }
      } else lambda1 = lambda0;
      if (lambda1<1) {
        ComputeLocalDirStats(im, (float)x+((float)incx)/2.0, (float) y, 
                             (float) z,  e2, dirstats_sigma, mean,var);
        switch (noise_model) 
        {
          case NOISE_GAUSSIAN_ADDITIVE:
            lambda2 = function_c_additive(var, sigma2);   break;
          case NOISE_RICIAN: 
            lambda2 = function_c_MRI( sigma2, var, mean); break;
        }
        lambda2 *= 6./2.; // convert for 1D normalization
          switch (diffusion_eigenvalues_mode) {
          case DIFF_MATRIX_EIGEN_SUM:
            lambda2 += lambda1;
            break;
          case DIFF_MATRIX_EIGEN_MAX:
            lambda2 = MAX(lambda1,lambda2);
            break;
          }
      } else lambda2 = lambda1;
      if (lambda1>1) lambda1=1;
      if (lambda2>1) lambda2=1;

      //    lambda2 = 0;

      alpha1_x = lambda0 *e0.x*e0.x + 
                 lambda1 *e1.x*e1.x +
                 lambda2 *e2.x*e2.x;

      gamma1_x = (grad.y*e0.y + grad.z*e0.z)* lambda0 *e0.x + 
                 (grad.y*e1.y + grad.z*e1.z)* lambda1 *e1.x +
                 (grad.y*e2.y + grad.z*e2.z)* lambda2 *e2.x;


      //----- Calcul de alpha1_y, gamma1_y 
   
      // Gradient en (x,y+1/2)
      grad.x = (*(in+xp)-*(in+xm)+*(in+xp+yp)-*(in+xm+yp))/4.0;
      grad.y =  *(in+yp) - *(in);
      grad.z = (*(in+zp)-*(in+zm)+*(in+zp+yp)-*(in+zm+yp))/4.0;

      this->GetVectors(1,x,y,z,e0,e1,e2);

      lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y+incy,z))/2.0;
      // if (lambda0>2) lambda0=2;
      if (lambda0<1) {
        ComputeLocalPlanStats(im, 
                              (float)x, (float) y+((float)incy)/2.0, (float) z,
                              e1,e2, planstats_sigma, mean,var);
        switch (noise_model) 
        {
          case NOISE_GAUSSIAN_ADDITIVE:
            lambda1 = function_c_additive(var, sigma2);   break;
          case NOISE_RICIAN: 
            lambda1 = function_c_MRI( sigma2, var, mean); break;
        }
        lambda1 *= 6./4.; // convert for 2D normalization
          switch (diffusion_eigenvalues_mode) {
          case DIFF_MATRIX_EIGEN_SUM:
            lambda1 += lambda0; 
            break;
          case DIFF_MATRIX_EIGEN_MAX:
            lambda1 = MAX(lambda0,lambda1); 
            break;
          }
      } else lambda1 = lambda0;
      if (lambda1<1) {
        ComputeLocalDirStats(im, 
                             (float)x, (float) y+((float)incy)/2.00,  (float) z,
                             e2, dirstats_sigma, mean,var);
        switch (noise_model) 
        {
          case NOISE_GAUSSIAN_ADDITIVE:
            lambda2 = function_c_additive(var, sigma2);   break;
          case NOISE_RICIAN: 
            lambda2 = function_c_MRI( sigma2, var, mean); break;
        }
        lambda2 *= 6./2.; // convert for 1D normalization
          switch (diffusion_eigenvalues_mode) {
          case DIFF_MATRIX_EIGEN_SUM:
            lambda2 += lambda1;
            break;
          case DIFF_MATRIX_EIGEN_MAX:
            lambda2 = MAX(lambda1,lambda2);
            break;
          }
      } else lambda2 = lambda1;
      if (lambda1>1) lambda1=1;
      if (lambda2>1) lambda2=1;

      //    lambda2 = 0;

      alpha1_y = lambda0 *e0.y*e0.y + 
                 lambda1 *e1.y*e1.y +
                 lambda2 *e2.y*e2.y;

      gamma1_y = (grad.x*e0.x + grad.z*e0.z)* lambda0 *e0.y + 
                 (grad.x*e1.x + grad.z*e1.z)* lambda1 *e1.y +
                 (grad.x*e2.x + grad.z*e2.z)* lambda2 *e2.y;


      //----- Calcul de alpha1_z, gamma1_z 
      grad.x = (*(in+xp) - *(in+xm) + *(in+xp+zp) - *(in+xm+zp))/4.0;
      grad.y = (*(in+yp) - *(in+ym) + *(in+yp+zp) - *(in+ym+zp))/4.0; 
      grad.z = *(in+zp)-*in;

      this->GetVectors(2,x,y,z,e0,e1,e2);

      lambda0 = ((*image_c)(x,y,z)+(*image_c)(x,y,z+incz))/2.0;
      //        if (lambda0>2) lambda0=2;
      if (lambda0<1) {
        ComputeLocalPlanStats(im, 
                              (float)x, (float) y, (float) z+((float)incz)/2.0,
                              e1,e2, planstats_sigma, mean,var);
        switch (noise_model) 
        {
          case NOISE_GAUSSIAN_ADDITIVE:
            lambda1 = function_c_additive(var, sigma2);   break;
          case NOISE_RICIAN: 
            lambda1 = function_c_MRI( sigma2, var, mean); break;
        }
        lambda1 *= 6./4.; // convert for 2D normalization
          switch (diffusion_eigenvalues_mode) {
          case DIFF_MATRIX_EIGEN_SUM:
            lambda1 += lambda0 ; 
            break;
          case DIFF_MATRIX_EIGEN_MAX:
            lambda1 = MAX(lambda0,lambda1); 
            break;
          }
      } else lambda1 = lambda0;
      if (lambda1<1) {
        ComputeLocalDirStats(im,
                             (float)x, (float) y, (float) z+((float)incz)/2.0,
                             e2, dirstats_sigma, mean,var);
        switch (noise_model) 
        {
          case NOISE_GAUSSIAN_ADDITIVE:
            lambda2 = function_c_additive(var, sigma2);   break;
          case NOISE_RICIAN: 
            lambda2 = function_c_MRI( sigma2, var, mean); break;
        }
        lambda2 *= 6./2.; // convert for 1D normalization
          switch (diffusion_eigenvalues_mode) {
          case DIFF_MATRIX_EIGEN_SUM:
            lambda2 += lambda1;
            break;
          case DIFF_MATRIX_EIGEN_MAX:
            lambda2 = MAX(lambda1,lambda2);
            break;
          }
      } else lambda2 = lambda1;
      if (lambda1>1) lambda1=1;
      if (lambda2>1) lambda2=1;

      // lambda2 = 0;

      alpha1_z = lambda0 *e0.z*e0.z + 
                 lambda1 *e1.z*e1.z +
                 lambda2 *e2.z*e2.z;

      gamma1_z = (grad.x*e0.x + grad.y*e0.y) * lambda0 *e0.z + 
                 (grad.x*e1.x + grad.y*e1.y) * lambda1 *e1.z +
                 (grad.x*e2.x + grad.y*e2.y) * lambda2 *e2.z;

     } // speedup_skip
      //----- Mise a jour de l'image

      val1    =  0;
      val1div =  0;


      val1    += alpha1_x    * (*(in+xp  )) +
                 alpha_x     * (*(in+xm  )) +
                 gamma1_x  - gamma_x;

      val1div += alpha1_x + alpha_x;

      if (!ispositivevalue(fabs(val1)))  {
       std::cout << "pb 1: " << val1 << std::endl;
       std::cout << boost::format("at %1%,%2%,%3% ") % x % y % z  << std::endl;

       std::cout << boost::format(" alpha1_x = %1%, *(in+xp) = %2%, alpha_x = %3%, *(in+xm) = %4%, gamma1_x = %5%, gamma_x = %6%") % alpha1_x % *(in+xp) % alpha_x % *(in+xm  ) % gamma1_x % gamma_x << std::endl;
      }

      val1    += alpha1_y     * (*(in+yp )) +
                 alpha_y[x]   * (*(in+ym )) +
                 gamma1_y  - gamma_y[x];

      val1div += alpha1_y + alpha_y[x];


      if (!ispositivevalue(fabs(val1)))  {
       std::cout << "pb 2" << std::endl;
      }

      val1    += alpha1_z      * (*(in+zp  )) +
                 alpha_z[x][y] * (*(in+zm  )) +
                 gamma1_z  - gamma_z[x][y];

      val1div += alpha1_z + alpha_z[x][y];

      if (!ispositivevalue(fabs(val1)))  {
       std::cout << "pb 3" << std::endl;
      }

/*    switch ( noise_type )
    {
    case GAUSSIAN_NOISE:*/
        if ( mask_test )
        {
          divF = ( val1 - *in * val1div ) * ( *in- ( *image_entree ) ( x,y,z ) );
          sum_divF += divF;
          nb_calculated_points++;
        }
    

        val1    += this->beta* ( *image_entree ) ( x,y,z );
        val1div += this->beta;
    
        val1prev = val1;
        val1 = ( *in + dt*val1 ) / ( 1+dt*val1div );
        if (val1<0)
        if (sqrt(val1)>300) {
          std::cout << "beta = " << this->beta << std::endl;
          std::cout << "image_entree (x,y,z) = " 
                    << ( *image_entree ) ( x,y,z ) << std::endl;
          std::cout << boost::format("lambda0,1,2 = %1% %2% %3%") % lambda0 
                        % lambda1 % lambda2 << std::endl;
          std::cout << "val1prev = " << val1prev << std::endl;
          std::cout << boost::format("at %1%,%2%,%3%  --> sqrt(in) = %4% dt = %5% val1prev = %6% sqrt(val1) = %7%") % x % y % z 
              % sqrt(*in) % dt % val1prev % sqrt(val1) << std::endl;
        }
    
//         break;
    
//     case SPECKLE_NOISE:
//         u0 = ( *image_entree ) ( x,y,z );
//         u  = *in;
//     
//         if ( mask_test&& ( fabsf ( u+u0 ) >1E-4 ) && ( u>1 ) && ( u0>1 ) )
//         {
//             divF = ( val1 - u * val1div ) * ( u-u0 ) / ( u+u0 ) *u;
//             /*
//             if (divF<-1000) {
//               printf("val1 %03.1f, u %03.1f, val1div %03.1f, u0  %03.1f --> divF  %03.1f\n",
//                  val1,u,val1div,u0,divF);
//             }
//             */
//             sum_divF += divF;
//             nb_calculated_points++;
//         }
//         else
//             divF = 0;
//     
//         if ( ( u>1 ) && ( u0>1 ) )
//         {
//             //
//             // See if we can get a more implicit scheme
//             // by solving a 3rd order equation:
//             //
//     #ifdef IMPLICIT
//             double w[3];
//             int nb_solutions;
//             Solve3rdOrder ( val1div,- ( val1-this->beta ),
//                             -this->beta* ( u0*u0 ),w,nb_solutions );
//             if ( nb_solutions==1 )
//                 val1_implicit = w[0];
//             else
//             {
//                 /*
//                 printf(" 3rd order equation %d solutions %3.2f %3.2f %3.2f \n",
//                    nb_solutions,w[0],w[1],w[2]);
//                 */
//                 if ( w[0] >=0 ) val1_implicit = w[0];
//                 else
//                     if ( w[1] >=0 ) val1_implicit = w[1];
//                     else
//                         if ( w[2] >=0 ) val1_implicit = w[2];
//             }
//             val1=val1_implicit;
//     #else
//             val1  += beta* ( ( u0*u0 ) / ( u*u )-1 );
//             if ( fabsf ( val1div ) >1E-4 ) {
//             val1 /= val1div;
//             } else {
//             fprintf ( stderr,"AnisoGaussSeidel.c:Itere3D() \t fabsf(val1div)<1E-4 \n" );
//             } // end if
//     #endif
//         }
//     
//         break;
//     } // switch noise type

      if (fabsf(val1-*in)<0.1) {
        sum_divF2 += divF;
        nb_calculated_points2++;
      }

      if (divFim!=NULL) {
        divFim->BufferPos(x,y,z);
        divFim->FixeValeur(divF);
      }


      alpha_z[x][y] = alpha1_z;
      alpha_y[x]    = alpha1_y;
      alpha_x       = alpha1_x;

      gamma_z[x][y] = gamma1_z;
      gamma_y[x]    = gamma1_y;
      gamma_x       = gamma1_x;

/*
    } else {

      val1 = *in;
    
      alpha_z[x][y] = 
      alpha_y[x]    = 
      alpha_x       = 
      gamma_z[x][y] = 
      gamma_y[x]    = 
      gamma_x       = 0;

    } // end if
*/

    if ( fabsf(val1-val0) > epsilon ) {
      nb_points_instables++;
    } // end if

    diff += (val1-val0)*(val1-val0);
    if ( fabsf(val1-val0) > erreur ) {
      erreur = fabsf(val1-val0);
      erreur_x = x;
      erreur_y = y;
      erreur_z = z;
    } // end if

    this->im_tmp->BufferPos(x,y,z);

    if (val1<min_intensity) {
      if (verbose) fprintf(stderr,"I=%3.2f<min, (%3d,%3d,%3d) \n",val1,x,y,z);
      val1=min_intensity;
      outoflimits++;
    }
    if (val1>max_intensity) {
      if (verbose) fprintf(stderr,"I=%3.2f>max, (%3d,%3d,%3d) \n",val1,x,y,z);
      val1=max_intensity;
      outoflimits++;
    }

    this->im_tmp->FixeValeur(val1);

    in++;
    Iconv++;

  } // endfor
  } // endfor
  } // endfor


  if (outoflimits>0) {
   std::cout << " Number of pixels out of the intensity range :" << outoflimits << std::endl;
  }

  // backup previous image in image_c
  ExtendBoundariesVonNeumann(im_tmp);
  //if (image_c!=NULL)  (*image_c) = (*im);
  (*im) = (*this->im_tmp);

  printf(" speedup is %3.3f %% of voxels\n",speedup_counter/(1.0*txy*tz)*100.0);

/*
 std::cout << std::endl;
 std::cout << " Erreur = " << erreur << std::endl;
 std::cout << "( " << erreur_x << ", " 
               << erreur_y << ", " 
               << erreur_z << " )" << std::endl; 
 std::cout << "nb de points variables " << nb_points_instables << std::endl;
*/
  diff /= txy*tz;

 std::cout << "\t diff =" << sqrt(diff) << "\t";

  
  // This code is somehow messy since it combines different types of filters
  // TODO: some cleanup here
  if (noise_standard_deviation <0) {
/*    fprintf(stderr,"noise SD <0 ?\n");
    estimated_DA_coeff = sum_divF/(1.0*nb_calculated_points);
    fprintf(stderr,"lambda estimation for noise/sigma_noise^2 = %f \n", 
        estimated_DA_coeff);
*/
  }
  else {
    estimated_DA_coeff =sum_divF/(1.0*nb_calculated_points)/this->variance;
    fprintf(stderr,"sum_divF=%3.2f, nb_calculated_points = %5d, variance = %3.3f, \n ===  lambda estimation for noise = %f \n", 
        sum_divF,(int)nb_calculated_points,this->variance, estimated_DA_coeff);

      if ((noise_SD_preset)&&(estimated_DA_coeff>0))
    this->beta = estimated_DA_coeff;
      fprintf(stderr, "\n  Setting beta to %2.2f \n\n",beta);

    estimated_DA_coeff =sum_divF2/(1.0*nb_calculated_points2)/this->variance;
    fprintf(stderr,
        " ===  lambda2 estimation for noise = %f, %02.2f percent of points \n", 
        estimated_DA_coeff,
        (nb_calculated_points2*100.0/nb_calculated_points));

    /*
    // set to the 2nd estimation
    if ( (nb_calculated_points2*100.0/nb_calculated_points) > 80 ) {
      if ((noise_SD_preset)&&(estimated_DA_coeff>0))
    this->beta = estimated_DA_coeff;
      fprintf(stderr, "\n  Setting beta to %2.2f \n\n",beta);
    }
    */
  }

  divFname = (boost::format("divF_%03d.ami.gz") % iteration).str();
//divFim->Sauve(divFname);


  return erreur;

} // ami::AnisoGS::Itere3D_ST_RNRAD()





//------------------------------------------------------------------------------
float ami::AnisoGS_NRAD::Iterate()
//   ----------------
{

  float       erreur = 0;

  if ( this->result_image==NULL ) {
    std::cerr << __func__ << " result_image==NULL, AnisoGS not initialized " << std::endl;
    return 0.0;
  } // end if

  // check if the standard deviation of the noise has been set
  if (iteration==0) {
    noise_SD_preset = (noise_standard_deviation!=-1);
    if (noise_SD_preset)
      this->variance = this->noise_standard_deviation*
  this->noise_standard_deviation;
  } 

  iteration++;
  printf("\n -- Iter. %d, beta = %03.2f \t", iteration,beta);

  erreur = Itere3D_ST_RNRAD( this->result_image);

  if (!noise_SD_preset)
    //    EstimateNoiseStandardDeviation(this->result_image);
  printf(" Max. Intens. change = %3.2f --  ",erreur);
  
  return erreur;

} // ami::AnisoGS::Iterate()


