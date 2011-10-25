/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#include "fonctions.h"
#include "localstats.h"
#include "DiscNormGrad.h"

#define MODE_LEE       0
#define MODE_KUAN      1
#define MODE_ADDITIVE  2
#define MODE_MRI       3
#define MODE_MRI_NEW   4


static float c_max;

//--------------------------------------------------------------------------------
double Cmad(InrImage* im)
//
{
  InrImage* im1 =  new InrImage( WT_FLOAT, "im1.inr.gz", im);

  // get the logarithm
  im1->InitBuffer();
  im->InitBuffer();
  Repeter					       
    im1->FixeValeur( log(im->ValeurBuffer()) );    
    im->IncBuffer();
  JusquA Non(im1->IncBuffer()) FinRepeter

  // Compute discrete norm of the gradient
  InrImage* gradnorm =  Func_DiscNormGrad(im1);
  delete im1;
  float median = Func_med(gradnorm);

  printf("median %f \n",median);

  gradnorm->InitBuffer();
  Repeter					       
    gradnorm->FixeValeur( fabsf(gradnorm->ValeurBuffer()-median) );    
  JusquA Non(gradnorm->IncBuffer()) FinRepeter

  
  float median2 = Func_med(gradnorm);

  delete gradnorm;

  // return median2; ??
  return median2*median2;
  // 1. compute the discrete norm of the gradient of the logarithm of the image
}


//--------------------------------------------------------------------------------
double Compute_q0_subvol(InrImage* im, int mode, ImageExtent<float>* extent)
//
{
  InrImage* subvol;
  //  InrImage* im1;
  //  InrImage* im2;
  double var;
  double mean;

  extent->SetRelative(im);
  subvol = Func_SubImage(im,
			 (int) extent->Xmin(),(int)extent->Ymin(),(int)extent->Zmin(),
			 (int)extent->Xmax(),(int)extent->Ymax(),(int)extent->Zmax());			 
  
  mean   = Func_mean(subvol);

  //  im1=(*subvol)-mean;
  //  im2=(*im1)*(*im1);
  //  var     = Func_mean(im2);

  double tmp,total;
  subvol->InitBuffer();
  total =0;
  do {
    tmp = subvol->ValeurBuffer()-mean;
    total += tmp*tmp;
  }
  while(subvol->IncBuffer());

  total = total/subvol->Size();
  // printf("total = %f, size = %d \n", total,subvol->Size());
  var=total;

  //  delete im1;
  //  delete im2;
  delete subvol;
  // printf("mean of sample = %f \n",mean);
  // printf("variance of sample = %f \n", var);

  switch (mode) {
  case MODE_LEE:
  case MODE_KUAN:  if (mean>0) return var/mean/mean;   else return 0;
  case MODE_ADDITIVE: return var;
  }
  return 0;
}


//--------------------------------------------------------------------------------
double Compute_q0_2(InrImage* im, int mode, ImageExtent<float>* extent)
//
{

  if (extent!=NULL) 
    return Compute_q0_subvol(im,mode, extent);
  else
    return Cmad(im);

}

//--------------------------------------------------------------------------------
double Compute_sigma2_MRI(InrImage* im, ImageExtent<float>* extent)
//
{
  InrImage* subvol;
  //  InrImage* im1;
  //  InrImage* im2;
  double mean;

  extent->SetRelative(im);
  subvol = Func_SubImage(im,
             (int) extent->Xmin(),(int)extent->Ymin(),(int)extent->Zmin(),
             (int) extent->Xmax(),(int)extent->Ymax(),(int)extent->Zmax());

  mean   = Func_mean(subvol);

  double tmp,total,var;
  subvol->InitBuffer();
  total =0;
  do {
    tmp = subvol->ValeurBuffer()-mean;
    total += tmp*tmp;
  }
  while(subvol->IncBuffer());
  total = total/subvol->Size();
  var=total;

  delete subvol;
 
  if (mean*mean<var) {
    printf("Compute_sigma2_MRI() mean*mean < var ...\n");
    return mean/2.0;
  } else {
    return (mean-sqrt(mean*mean-var))/2.0;

  }
}


//--------------------------------------------------------------------------------
double Compute_sigma2_MRI_mode(InrImage* im, ImageExtent<float>* extent)
//
{
  InrImage* im1;
  InrImage* im1_mean;
  InrImage* im1_var;
  double mean,std;
  double tmp,total,val;
  int neigh_size;

  InrImage* subvol;

  extent->SetRelative(im);
  subvol = Func_SubImage(im,
             (int)extent->Xmin(),(int)extent->Ymin(),(int)extent->Zmin(),
             (int)extent->Xmax(),(int)extent->Ymax(),(int)extent->Zmax());

  // compute square root of image
  im1 = new InrImage(WT_FLOAT,"im1.ami.gz",subvol);
  im1->InitBuffer();
  subvol->InitBuffer();
  do {
    tmp = subvol->ValeurBuffer();
    if (tmp<0) tmp = 0;
    im1->FixeValeur(sqrt(tmp));
    subvol->IncBuffer();
  }
  while(im1->IncBuffer());

  delete subvol;
  
//  if (im1->DimZ()==1)
//	neigh_size=3;
//  else
  neigh_size=2;

  im1_mean = Func_localmean2(im1,neigh_size);
  im1_var = Func_localSD2(im1,im1_mean,neigh_size);

/*
  // get square of im2  for variance
  im1_var->InitBuffer();
  do {
    im1_var->FixeValeur(im1_var->ValeurBuffer()*im1_var->ValeurBuffer());
  }
  while(im1_var->IncBuffer());
*/  

  mean   = Func_mean(im1_var);
  im1_var->InitBuffer();
  total =0;
  do {
    tmp = im1_var->ValeurBuffer()-mean;
    total += tmp*tmp;
  }
  while(im1_var->IncBuffer());
  total = total/im1_var->Size();
  std=sqrt(total);

//  printf("mean %f std %f  \n",mean,std);

  // histogram of values between mean +/- 2*std
  double hist_min = 0;
  double hist_max = mean+2*std;
  int hist_size = (int)((hist_max-hist_min+1.0)*3.0);
  int maxpos = 0;
  double hist_step = (hist_max-hist_min)/hist_size;
  int* hist = new int[hist_size];
  memset((void*)hist,0,hist_size*sizeof(int));

  int pos;

//  printf("histo limits %f %f \n",hist_min,hist_min+4.0*std);

  im1_var->InitBuffer();
  do {
    val= im1_var->ValeurBuffer();
    if ((val>hist_min)&&(val<hist_max)) {
      pos = (int) floor((val-hist_min)/hist_step);
      if ((pos>=0)&&(pos<hist_size)) {
        hist[pos]++;
        if (hist[pos]>hist[maxpos]) maxpos = pos;
      }
    }
  }
  while(im1_var->IncBuffer());

  delete im1;
  delete im1_mean;
  delete im1_var;
  delete [] hist;

//  return (hist_min+maxpos*hist_step);
  return (hist_min+maxpos*hist_step)*(hist_min+maxpos*hist_step);

}


//--------------------------------------------------------------------------------
double Compute_q0_2(InrImage* im, InrImage* meanI, InrImage* meanI2, int mode, int neighborhood)
//
{

  int    x,y,z;
  double Ixm,Iym,Izm,Ixp,Iyp,Izp,I;
  double mean1,mean2,q2;

  InrImage* imq0;
  InrImage* mask;

  imq0 = new InrImage(WT_FLOAT,"imq0.ami.gz",im);
  mask = new InrImage(WT_UNSIGNED_CHAR,"imq0_mask.ami.gz",im);
  mask->InitImage(255);

  imq0->InitBuffer();
  mask->InitBuffer();

  // 1. Compute c
  for (z=0;z<im->DimZ();z++) {
  for (y=0;y<im->DimY();y++) {
  for (x=0;x<im->DimX();x++) {
    I = (*im)(x,y,z);
    if (fabsf(I)<1) I=1;
    if (x>0)  Ixm = (*im)(x-1,y,z); else Ixm = I;
    if (y>0)  Iym = (*im)(x,y-1,z); else Iym = I;
    if (z>0)  Izm = (*im)(x,y,z-1); else Izm = I;

    if (x<im->DimX()-1)  Ixp = (*im)(x+1,y,z); else Ixp = I;
    if (y<im->DimY()-1)  Iyp = (*im)(x,y+1,z); else Iyp = I;
    if (z<im->DimZ()-1)  Izp = (*im)(x,y,z+1); else Izp = I;


    // other (simpler version of q2):
    switch (neighborhood) {
    case 0: 
      mean1 = Ixm+Ixp+Iym+Iyp;
      mean2 = Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp;
      if (im->DimZ()==1) {
	mean1/=4.0;
	mean2/=4.0;
      }
      else {
	mean1+=Izm+Izp;
	mean2+=Izm*Izm+Izp*Izp;
	mean1/=6.0;
	mean2/=6.0;
      }
      break;
    default:
      mean1 = (*meanI) (x,y,z);
      mean2 = (*meanI2)(x,y,z);
    }
    
    if (fabsf(mean1)>1E-6) 
      q2    = mean2/(mean1*mean1)-1;
    else q2 = 0;
    
    imq0->FixeValeur(q2);
    if (q2==0)
      mask->FixeValeur(0);
    imq0->IncBuffer();
    mask->IncBuffer();
  }
  }
  }

  float median = Func_med(imq0,0.5,mask);
  printf("median %f \n",median);
  delete imq0;
  delete mask;

  return median;
}



//--------------------------------------------------------------------------------
double function_c(double q_2, double q0_2)
//     ----------
{

  double tmp;
  if (fabsf(q0_2)<1E-4) return 0;
  if (q_2<0) {
    //    printf("function_c(q_2<0,q0_2) ...\n");
    q_2 = 0;
  }
  tmp = 1.0/(1.0+(q_2-q0_2)/(q0_2*(1+q0_2)));
  // try to limit the maximal value to 1
  if (tmp>1) tmp = 1;
  return tmp;
}

//--------------------------------------------------------------------------------
double function_c_Kuan(double q_2, double q0_2)
//     ---------------
{

  double tmp;
  if (fabsf(q0_2)<1E-4) return 0;
  if (q_2<0) {
    //    printf("function_c(q_2<0,q0_2) ...\n");
    q_2 = 0;
  }
  tmp =(1.0+1.0/q_2)/(1.0+1.0/q0_2);

  double limit=q0_2/4.0;
  limit = (1.0+1.0/limit)/(1.0+1.0/q0_2);
  //  double limit = 1;
  if (tmp>limit) tmp=limit;

  //  if (tmp>1) tmp = 1;
  return tmp;
}

//--------------------------------------------------------------------------------
double function_c_MRI(double sigma2, double vg, double meang)
//     ---------------
{

  double tmp;
  if (fabsf(vg)<1E-4) return 0.0;
  if (meang<=sigma2) return 0.0;
  tmp =4.0*sigma2*(meang-sigma2)/vg;

  return tmp;
}

//--------------------------------------------------------------------------------
double function_c_additive(double q_2, double q0_2)
//     -------------------
{

  double tmp;
  if (fabsf(q0_2)<1E-4) return 0;
  if (q_2<1E-3*q0_2) {
    //    printf("function_c(q_2<0,q0_2) ...\n");
    return 0;
  }
  tmp = q0_2/q_2;
  return tmp;
}

//--------------------------------------------------------------------------------
double function_q2(double dI_I_2, double d2I_I) {
//     ----------
  double tmp;

  tmp = (1.0+0.25*d2I_I);
  return (0.25*(dI_I_2)-(1.0/16.0)*d2I_I*d2I_I)/tmp/tmp;
}


//--------------------------------------------------------------------------------
double function_q0(double t, double rho, double q0) {
  return q0*exp(-rho*t);
}

//--------------------------------------------------------------------------------
void Compute_q_coeff(InrImage* image_in, InrImage* image_q ){
//   ---------------

  int x,y,z;

  double drx,dry,dlx,dly,d2;
  double I,Ixp,Ixm,Iyp,Iym,Izm,Izp;
  //  double C,Cxp,Cxm,Cyp,Cym,Czm,Czp;
  double dI_I_2;

  int tx = image_in->_tx;
  int ty = image_in->_ty;
  int tz = image_in->_tz;


  // 1. Compute c
  for (z=0;z<tz;z++) {
  for (y=0;y<ty;y++) {
  for (x=0;x<tx;x++) {
    I = (*image_in)(x,y,z);

    // don't allow 0 values to avoid numerical problems
    if (I==0) I=1;

    if (x>0)  Ixm = (*image_in)(x-1,y,z); else Ixm = I;
    if (y>0)  Iym = (*image_in)(x,y-1,z); else Iym = I;
    if (z>0)  Izm = (*image_in)(x,y,z-1); else Izm = I;

    if (x<tx-1)  Ixp = (*image_in)(x+1,y,z); else Ixp = I;
    if (y<ty-1)  Iyp = (*image_in)(x,y+1,z); else Iyp = I;
    if (z<tz-1)  Izp = (*image_in)(x,y,z+1); else Izp = I;

    drx=Ixp-I;
    dry=Iyp-I;
    dlx=I-Ixm;
    dly=I-Iym;

    d2 = drx+dry-dlx-dly;

    dI_I_2 = (drx*drx+dry*dry+dlx*dlx+dly*dly)/I/I;

    image_q->BufferPos(x,y,z);
    image_q->FixeValeur(function_q2(dI_I_2,d2/I));
  }
  }
  }

}


//--------------------------------------------------------------------------------
void Compute_d_coeff(InrImage* image_res,InrImage* image_c,InrImage* image_d, double& dt1, int mode, 
//   ---------------
		     int neighborhood, ImageExtent<float>* extent) 
{

  int x,y,z;

  //  double drx,dry,dlx,dly,d2;
  double I,Ixp,Ixm,Iyp,Iym,Izm,Izp;
  double C,Cxp,Cxm,Cyp,Cym,Czm,Czp;
  //  double dI_I_2,tmp;

  int tx = image_res->_tx;
  int ty = image_res->_ty;
  int tz = image_res->_tz;

  float q0_2;
  
  double mean1,mean2,q2;
  InrImage::ptr image_mean_I;
  InrImage::ptr image_mean_I2;

  // if neighborhood > 0, pre-compute mean(I) and mean(I^2)
  if (neighborhood>0) {
    InrImage::ptr image_I2;
    image_mean_I  = InrImage::ptr(
        Func_localmean2(image_res,neighborhood));
    image_I2      = InrImage::ptr((*image_res)*(*image_res));
    image_mean_I2 = InrImage::ptr(
      Func_localmean2(image_I2.get(), neighborhood)); 
  }


  q0_2= Compute_q0_2(image_res,mode, extent);

  printf("q0_2 = %f",q0_2);
  //  printf("c max should be %f \t ",1.0/(1.0-1./(1.+q0_2)));
  //  printf("max dt for Lee: %f \n",q0_2/(1+q0_2));

  if (dt1>(q0_2/(1+q0_2))) {
    //printf("limiting dt to %f*0.99 \n",q0_2/(1+q0_2));
    dt1 = q0_2/(1+q0_2)*0.99;
  }

  // 1. Compute c
  for (z=0;z<tz;z++) {
  for (y=0;y<ty;y++) {
  for (x=0;x<tx;x++) {
    I = (*image_res)(x,y,z);
    if (fabsf(I)<1) I=1;
    if (x>0)  Ixm = (*image_res)(x-1,y,z); else Ixm = I;
    if (y>0)  Iym = (*image_res)(x,y-1,z); else Iym = I;
    if (z>0)  Izm = (*image_res)(x,y,z-1); else Izm = I;

    if (x<tx-1)  Ixp = (*image_res)(x+1,y,z); else Ixp = I;
    if (y<ty-1)  Iyp = (*image_res)(x,y+1,z); else Iyp = I;
    if (z<tz-1)  Izp = (*image_res)(x,y,z+1); else Izp = I;

    image_c->BufferPos(x,y,z);


    // other (simpler version of q2):
    switch (neighborhood) {
    case 0: 
      mean1 = Ixm+Ixp+Iym+Iyp;
      mean2 = Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp;
      if (tz==1) {
	mean1/=4.0;
	mean2/=4.0;
      }
      else {
	mean1+=Izm+Izp;
	mean2+=Izm*Izm+Izp*Izp;
	mean1/=6.0;
	mean2/=6.0;
      }
      break;
    default:
      mean1 = (*image_mean_I) (x,y,z);
      mean2 = (*image_mean_I2)(x,y,z);
    }
 
    if (fabsf(mean1)>1E-6) 
      q2    = mean2/(mean1*mean1)-1;
    else q2 = 0;

    image_c->BufferPos(x,y,z);
    switch (mode) {
    case MODE_LEE:      image_c->FixeValeur( function_c(         q2,               q0_2)); break;
    case MODE_KUAN:     image_c->FixeValeur( function_c_Kuan(    q2,               q0_2)); break;
    case MODE_ADDITIVE: image_c->FixeValeur( function_c_additive(mean2-mean1*mean1,q0_2)); break;
    }

  }
  }
  }

  // free useless memory
  image_mean_I.reset();
  image_mean_I2.reset();


  // 2. Compute d
  image_res->InitBuffer();
  image_c  ->InitBuffer();
  image_d  ->InitBuffer();

  for (z=0;z<tz;z++) {
  for (y=0;y<ty;y++) {
  for (x=0;x<tx;x++) {
    I = image_res->ValeurBuffer();
    C = image_c  ->ValeurBuffer();
    if (C>c_max) c_max = C;

    if (x>0)     Ixm =  image_res->ValeurBuffer(-1);  else Ixm = I;
    if (y>0)     Iym =  image_res->ValeurBuffer(-tx); else Iym = I;
    if (z>0)     Izm =  (*image_res)(x,y,z-1); else Izm = I;

    if (x<tx-1)  Ixp = image_res->ValeurBuffer(1);   else Ixp = I;
    if (y<ty-1)  Iyp = image_res->ValeurBuffer(tx);  else Iyp = I;
    if (z<tz-1)  Izp = (*image_res)(x,y,z+1); else Izp = I;

    if (x>0)     Cxm =  image_c->ValeurBuffer(-1);  else Cxm = C;
    if (y>0)     Cym =  image_c->ValeurBuffer(-tx); else Cym = C;
    if (z>0)     Czm =  (*image_c)(x,y,z-1); else Czm = C;

    if (x<tx-1)  Cxp = image_c->ValeurBuffer(1);  else Cxp = C;
    if (y<ty-1)  Cyp = image_c->ValeurBuffer(tx); else Cyp = C;
    if (z<tz-1)  Czp = (*image_c)(x,y,z+1); else Czp = C;

    //    image_d->FixeValeur(Cxp*(Ixp-I)+C*(Ixm-I)+Cyp*(Iyp-I)+C*(Iym-I));
    double sum=0;
    if (tx>1) sum += (Cxp+C)*(Ixp-I)+(Cxm+C)*(Ixm-I);
    if (ty>1) sum += (Cyp+C)*(Iyp-I)+(Cym+C)*(Iym-I);
    if (tz>1) sum += (Czp+C)*(Izp-I)+(Czm+C)*(Izm-I);
    sum /= 2.0;

    image_d->FixeValeur(sum);

    image_res->IncBuffer();
    image_c  ->IncBuffer();
    image_d  ->IncBuffer();
  }
  }
  }
  

}


//--------------------------------------------------------------------------------
InrImage* Func_SRAD_qcoeff( InrImage* input) {
//        ----------------------

  
    InrImage* image_in;
    InrImage* image_q;
    //    char resname[100];
    //    double t;
    //    int n;


  // conversion de l'image initiale en float
  image_in = new InrImage( WT_FLOAT, "image_reel.inr.gz", input);
  (*image_in) = (*input);

  image_q = new InrImage( WT_FLOAT, "image_q.ami.gz", input);
  Compute_q_coeff(image_in,image_q);
  
  return image_q;

}

//--------------------------------------------------------------------------------
// explicit scheme
InrImage* Func_SRAD( InrImage* input, float dt, int numit, int mode,  
//        ---------
		     int neighborhood,
		     ImageExtent<float>* extent) 
{

  
    InrImage* image_res;
    InrImage* image_c;
    InrImage* image_d;
    char resname[100];
    double t,new_val;
    int n;
    double dt1;


  //--- image_resultat
  sprintf(resname,"%s.SRAD",input->GetName());
  image_res = new InrImage( WT_FLOAT, resname, input);

  image_c = new InrImage( WT_FLOAT, "image_c.ami.gz", input);
  image_d = new InrImage( WT_FLOAT, "image_d.ami.gz", input);
  
  (*image_res)=(*input);

  // set the minimal intensity value to 1 ...
  image_res->InitBuffer();
  do {
    if (image_res->ValeurBuffer()<1)
      image_res->FixeValeur(1);
  }
  while (image_res->IncBuffer());

  t=0;
  for(n=1;n<=numit;n++) {

    c_max = 0;

    if (n%10==0)
      printf("%03d/%03d \n",n,numit-1);
    dt1 = dt;
    Compute_d_coeff(image_res,image_c,image_d,dt1,mode, neighborhood, extent);
    image_res->InitBuffer();
    image_d->InitBuffer();

    do {

      if (image_res->DimZ()==1)
	new_val = image_res->ValeurBuffer()+image_d->ValeurBuffer()*dt1/4.0;
      else
	new_val = image_res->ValeurBuffer()+image_d->ValeurBuffer()*dt1/6.0;
      
      // prevent negative values ...
      if (new_val>0)
	image_res->FixeValeur(new_val);
      image_d->IncBuffer();
    }
    while (image_res->IncBuffer());
    t += dt;

    //    printf("c_max =  %f \n",c_max);
  }

  delete image_c;
  delete image_d;

  return image_res;

}


//--------------------------------------------------------------------------------
void UpdateResult2(InrImage* image_res,float dt, InrImage* image_c, InrImage* image_d, int neighborhood, int mode, ImageExtent<float>* extent) {
//   -------------

  int x,y,z;

  //  double drx,dry,dlx,dly,d2;
  double I,Ixp,Ixm,Iyp,Iym,Izm,Izp;
  double C,Cxp,Cxm,Cyp,Cym,Czm,Czp;
  //  double dI_I_2;

  int tx = image_res->_tx;
  int ty = image_res->_ty;
  int tz = image_res->_tz;

  float q0_2 = 0.0;
  float sigma2 = 0.0;
  //  float tmp;
  double mean1,mean2,q2;
  InrImage::ptr image_mean_I;
  InrImage::ptr image_I2;
  InrImage::ptr image_mean_I2;
  
  switch (mode) {
    case MODE_LEE:
    case MODE_KUAN:
    case MODE_ADDITIVE:
        q0_2= Compute_q0_2(image_res,mode, extent);
        printf("q0_2 = %f \n",q0_2);
        break;
    case MODE_MRI:
    case MODE_MRI_NEW:
//        sigma2 = Compute_sigma2_MRI(image_res,extent);
//        printf("sigma based on ROI = %f \n",sqrt(sigma2));

        sigma2 = Compute_sigma2_MRI_mode(image_res,extent);
        printf("sigma automatic = %f \n",sqrt(sigma2));
        break;
  }

  // if neighborhood > 0, pre-compute mean(I) and mean(I^2)
  if (neighborhood>0) {
    image_mean_I  = InrImage::ptr(Func_localmean2(image_res,neighborhood));
    image_I2      = InrImage::ptr((*image_res)*(*image_res));
    image_mean_I2 = InrImage::ptr(Func_localmean2(image_I2.get(), neighborhood));
    image_I2.reset();
  }

  //Compute_q0_2(image_res,image_mean_I,image_mean_I2,mode,neighborhood);


  // 1. Compute c
  for (z=0;z<tz;z++) {
  for (y=0;y<ty;y++) {
  for (x=0;x<tx;x++) {
    I = (*image_res)(x,y,z);
    if (fabsf(I)<1) I=1;
    if (x>0)     Ixm = (*image_res)(x-1,y,z); else Ixm = I;
    if (y>0)     Iym = (*image_res)(x,y-1,z); else Iym = I;
    if (z>0)     Izm = (*image_res)(x,y,z-1); else Izm = I;

    if (x<tx-1)  Ixp = (*image_res)(x+1,y,z); else Ixp = I;
    if (y<ty-1)  Iyp = (*image_res)(x,y+1,z); else Iyp = I;
    if (z<tz-1)  Izp = (*image_res)(x,y,z+1); else Izp = I;

    // other (simpler version of q2):
    switch (neighborhood) {
    case 0: 
      mean1 = Ixm+Ixp+Iym+Iyp;
      mean2 = Ixm*Ixm+Ixp*Ixp+Iym*Iym+Iyp*Iyp;
      if (tz==1) {
	mean1/=4.0;
	mean2/=4.0;
      }
      else {
	mean1+=Izm+Izp;
	mean2+=Izm*Izm+Izp*Izp;
	mean1/=6.0;
	mean2/=6.0;
      }
      break;
    default:
      mean1 = (*image_mean_I) (x,y,z);
      mean2 = (*image_mean_I2)(x,y,z);
    }
 
    if (fabsf(mean1)>1E-6) 
      q2    = mean2/(mean1*mean1)-1;
    else q2 = 0;

    image_c->BufferPos(x,y,z);
    switch (mode) {
    case MODE_LEE:      image_c->FixeValeur( function_c(         q2,               q0_2)); break;
    case MODE_KUAN:     image_c->FixeValeur( function_c_Kuan(    q2,               q0_2)); break;
    case MODE_ADDITIVE: 
      image_c->FixeValeur( function_c_additive(mean2-mean1*mean1,q0_2)); break;
    case MODE_MRI:
    case MODE_MRI_NEW:
      image_c->FixeValeur( function_c_MRI( sigma2, mean2-mean1*mean1, mean1)); break;
    } 

  }
  }
  }

  image_mean_I.reset();
  image_mean_I2.reset();

  // 2. Compute d
  image_res->InitBuffer();
  image_c  ->InitBuffer();
  image_d  ->InitBuffer();

  double neighbors_coeff;
  double center_coeff;

  for (z=0;z<tz;z++) {
  for (y=0;y<ty;y++) {
  for (x=0;x<tx;x++) {
    I = image_res->ValeurBuffer();
    C = image_c  ->ValeurBuffer();
    if (x>0)     Ixm =  image_res->ValeurBuffer(-1);  else Ixm = I;
    if (y>0)     Iym =  image_res->ValeurBuffer(-tx); else Iym = I;
    if (z>0)     Izm =  (*image_res)(x,y,z-1); else Izm = I;

    if (x<tx-1)  Ixp = image_res->ValeurBuffer(1);   else Ixp = I;
    if (y<ty-1)  Iyp = image_res->ValeurBuffer(tx);  else Iyp = I;
    if (z<tz-1)  Izp = (*image_res)(x,y,z+1); else Izp = I;

    if (x>0)     Cxm =  image_c->ValeurBuffer(-1);  else Cxm = C;
    if (y>0)     Cym =  image_c->ValeurBuffer(-tx); else Cym = C;
    if (z>0)     Czm =  (*image_c)(x,y,z-1); else Czm = C;

    if (x<tx-1)  Cxp = image_c->ValeurBuffer(1);  else Cxp = C;
    if (y<ty-1)  Cyp = image_c->ValeurBuffer(tx); else Cyp = C;
    if (z<tz-1)  Czp = (*image_c)(x,y,z+1); else Czp = C;

    //    image_d->FixeValeur(Cxp*(Ixp-I)+C*(Ixm-I)+Cyp*(Iyp-I)+C*(Iym-I));
    if (tz==1) {
      neighbors_coeff = ((Cxp+C)*Ixp+(Cxm+C)*Ixm+(Cyp+C)*Iyp+(Cym+C)*Iym)/2.0;
      center_coeff    = (Cxp+Cxm+Cyp+Cym+4*C)/2.0; 
    } else {
      neighbors_coeff = ((Cxp+C)*Ixp+(Cxm+C)*Ixm+
			 (Cyp+C)*Iyp+(Cym+C)*Iym+
			 (Czp+C)*Izp+(Czm+C)*Izm)/2.0;
      center_coeff    = (Cxp+Cxm+Cyp+Cym+Czp+Czm+6*C)/2.0; 
    }
    image_d->FixeValeur( (I + dt*neighbors_coeff)/(1+dt*center_coeff));

    image_res->IncBuffer();
    image_c  ->IncBuffer();
    image_d  ->IncBuffer();
  }
  }
  }
  

}


//--------------------------------------------------------------------------------
// semi-implicit scheme
//
InrImage* Func_SRAD2( InrImage* input, float dt, int numit, 
		      int mode, 
		      int neighborhood,
		      ImageExtent<float>* extent)
{
//
// neighborhood:
//      0: initial Lee 2+2(+2 in 3D) neighboors
//      1: 3x3(x3) neighboors
//      n>0: (2n+1)x(2n+1)[x(2n+1)] neighboors
// mode 0: Lee
// mode 1: Kuan
// mode 2: Additive
// mode 3: MRI
// mode 4: MRI_NEW : check the diff with MRI contoursnrad_new ?
//        ----------

  
    InrImage* image_res;
    InrImage* image_c;
    InrImage* image_d;
    char resname[100];
    int n;


  //--- image_resultat
  sprintf(resname,"%s.SRAD",input->GetName());
  image_res = new InrImage( WT_FLOAT, resname, input);

  image_c = new InrImage( WT_FLOAT, "image_c.ami.gz", input);
  image_d = new InrImage( WT_FLOAT, "image_d.ami.gz", input);
  
  (*image_res)=(*input);

  // TODO: only to this part for specific noise type !
  // set the minimal intensity value to 1 ...
  image_res->InitBuffer();
  do {
    if (image_res->ValeurBuffer()<1)
      image_res->FixeValeur(1);
  }
  while (image_res->IncBuffer());

  for(n=1;n<=numit;n++) {
    if (n%10==0)
      printf("%03d/%03d \n",n,numit-1);
    UpdateResult2(image_res,dt, image_c,image_d,neighborhood,mode,extent);
    (*image_res)=(*image_d);
  }

  delete image_c;
  delete image_d;

  return image_res;

}
