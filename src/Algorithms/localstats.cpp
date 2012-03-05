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

#include "localstats.h"
#include "func_globalstats.h"
#include "func_imagebasictools.h"
#include <limits>

//--------------------------------------------------
InrImage*     Func_localmean( InrImage* im, int size)
{
  double mean;
  InrImage* res;
  int       x,y,z;
  int       x1,y1,z1;
  int       num_values;

  res = new InrImage( WT_FLOAT,"localmean.ami.gz",im);
  res->InitImage(0.0);

  res->InitBuffer();

  // along X
  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)

    mean = 0;
    num_values=0;

    Pour(z1,z-size,z+size)
    Pour(y1,y-size,y+size)
    Pour(x1,x-size,x+size)
      if (im->CoordOK(x1,y1,z1)) {
	      mean += (*im)(x1,y1,z1);
	      num_values++;
      }
    FinPour
    FinPour
    FinPour

    res->BufferPos(x,y,z);
    res->FixeValeur(mean/num_values);

  FinPour
  FinPour
  FinPour
  
  return res;
}


//--------------------------------------------------
// separable optimized version
void     Func_localmean2( InrImage* im, InrImage*& res, 
                          InrImage*& tmp, int size)
{
  //InrImage* tmp1;
  //#define swap_pointers(p1,p2) 
  //  { tmp1=p1; p1 = p2; p2 = tmp1; }
  int numpoints;
  
  ami::ImageExtent<int> extent(im);

  Func_localsum<float>(im,res,tmp,size,extent);

  numpoints = (2*size+1)*(2*size+1);
  if ( im->DimZ() >1 ) {
    numpoints *= (2*size+1);
  }

  // divide by the number of points here
  // could be numerically more accurate to do it after each direction 
  float* res_buf = (float*) res->Buffer();
  for(int i=0;i<res->Size();
      i++,res_buf++) 
    *res_buf = (*res_buf)/(1.0*numpoints);

}


//--------------------------------------------------
InrImage*     Func_localmean2( InrImage* im, int size)
{
  InrImage* res;
  InrImage* tmp;

  tmp = new InrImage ( WT_FLOAT,"localmean.ami.gz",im );
  res = new InrImage ( WT_FLOAT,"localmean.ami.gz",im );

  Func_localmean2(im,res,tmp,size);

  delete tmp;
  return res;
}

//--------------------------------------------------
InrImage*     Func_localSD( InrImage* im, InrImage* mean, int size)
{
  double SD,tmp;
  InrImage* res;
  int       x,y,z;
  int       x1,y1,z1;
  int       num_values;

  res = new InrImage( WT_FLOAT,"localmean.ami.gz",im);
  res->InitImage(0.0);

  res->InitBuffer();

  Pour(z,0,im->_tz-1)
  Pour(y,0,im->_ty-1)
  Pour(x,0,im->_tx-1)

    SD = 0;
    num_values=0;

    Pour(z1,z-size,z+size)
    Pour(y1,y-size,y+size)
    Pour(x1,x-size,x+size)
      if (im->CoordOK(x1,y1,z1)) {
	tmp = ((*im)(x1,y1,z1)-(*mean)(x,y,z));
	SD += tmp*tmp;
	num_values++;
      }
    FinPour
    FinPour
    FinPour

    res->BufferPos(x,y,z);
    res->FixeValeur(sqrt(SD/num_values));

  FinPour
  FinPour
  FinPour
  



  return res;
}


//--------------------------------------------------
InrImage* Func_localSD2( InrImage* im, InrImage* mean, int size, bool unbiased)
{
  double tmp;
  InrImage* res;
  InrImage* res2;
  float nb_values,correction=0.0;
//  int       x,y,z;
//  int       x1,y1,z1;
//  int       num_values;

  res = new InrImage( WT_FLOAT,"im_2.ami.gz",im);
  res->InitImage(0.0);

  res ->InitBuffer();
  im  ->InitBuffer();

  do {
    tmp = im->ValeurBuffer();
    res->FixeValeur(tmp*tmp);
    im->IncBuffer();
  }
  while (res->IncBuffer());

  res2 = Func_localmean2(res,size);
  res2->InitBuffer();
  mean->InitBuffer();
#define M_MAX(a,b) ((a)>(b)?(a):(b))
  if (unbiased) {
    nb_values = M_MAX(im->DimX(),(2*size+1))*
                M_MAX(im->DimY(),(2*size+1))*
                M_MAX(im->DimZ(),(2*size+1));
    correction = nb_values/(nb_values-1.0);
  }
#undef M_MAX
    int i=0;
  do {
    tmp = res2->ValeurBuffer()-
          mean->ValeurBuffer()*mean->ValeurBuffer();
    if (unbiased) tmp=tmp*correction;
    if (tmp<0.00001) tmp=0.00001;
    res2->FixeValeur(sqrt(tmp));
    i++;
    mean->IncBuffer();
  }
  while (res2->IncBuffer());
  
  delete res;
  return res2;
}

//--------------------------------------------------
InrImage* Func_localVAR2( InrImage* im, InrImage* mean, int size, bool unbiased)
{
  double tmp;
  InrImage* res;
  InrImage* res2;
  float nb_values,correction=0.0;

  res = new InrImage( WT_FLOAT,"im_2.ami.gz",im);
  res->InitImage(0.0);

  res ->InitBuffer();
  im  ->InitBuffer();

  do {
    tmp = im->ValeurBuffer();
    res->FixeValeur(tmp*tmp);
    im->IncBuffer();
  }
  while (res->IncBuffer());

  res2 = Func_localmean2(res,size);
  res2->InitBuffer();
  mean->InitBuffer();
#define M_MAX(a,b) ((a)>(b)?(a):(b))
  if (unbiased) {
    nb_values = M_MAX(im->DimX(),(2*size+1))*
                M_MAX(im->DimY(),(2*size+1))*
                M_MAX(im->DimZ(),(2*size+1));
    correction = nb_values/(nb_values-1.0);
  }
#undef M_MAX
  int i=0;
  do {
    tmp = res2->ValeurBuffer()-
          mean->ValeurBuffer()*mean->ValeurBuffer();
    if (unbiased) tmp=tmp*correction;
    if (tmp<0.00001) tmp=0.00001;
    res2->FixeValeur(tmp);
    i++;
    mean->IncBuffer();
  }
  while (res2->IncBuffer());
  
  delete res;
  return res2;
}

//--------------------------------------------------
InrImage*     Func_localdirectionalmean( InrImage* im, InrImage* directions,
			      int size)
{
  /*
  InrImage* res;
  int x,y,z;
  double mean,dp;
  double pos;
  double dirx,diry,dirz;

  res = new InrImage(WT_FLOAT,"localdirmean.ami.gz",im);
  res->InitImage(0.0);

  res->InitBuffer();
  directions->InitBuffer();

  Pour(z,0,im->DimZ()-1)
  Pour(y,0,im->DimY()-1)
  Pour(x,0,im->DimX()-1)

    mean = 0;
    num_values=0;

    dirx=directions->VectValeurBuffer(0);
    dirY=directions->VectValeurBuffer(1);
    dirZ=directions->VectValeurBuffer(2);

    if (dirx*dirx+diry*diry+dirz*dirz > 1E-6) {

      pos = -size;
      dp = 0.5;
      do {
	
	pos += dp;
      }
      while( pos<size);
	
      res->FixeValeur(sqrt(SD/num_values));
    }

    res       ->IncBuffer();
    directions->IncBuffer();

  FinPour
  FinPour
  FinPour


  return res;
  */
return NULL;
}

//--------------------------------------------------
InrImage*     Func_localdirectionalSD( InrImage* im, InrImage* directions,
				       InrImage* mean, int size)
{
return NULL;
}

//------------------------------------------------------------------------------
double Func_Compute_sigma2_MRI_mode(InrImage* im, InrImage::ptr im_ROI, 
                                    int neigh_size)
//
{

  if (!im_ROI.get())
    {
      fprintf(stderr,"Func_Compute_sigma2_MRI_mode() \t im_ROI==NULL\n");
      return 0.0;
    }

  InrImage::ptr im2 = im_ROI;
  int xmin,xmax,ymin,ymax,zmin,zmax;

  xmin = (int) (im->SpaceToVoxelX(im2->SpacePosX(0))+0.5);
  ymin = (int) (im->SpaceToVoxelY(im2->SpacePosY(0))+0.5);
  zmin = (int) (im->SpaceToVoxelZ(im2->SpacePosZ(0))+0.5);
  xmax = (int) (im->SpaceToVoxelX(im2->SpacePosX(im2->DimX()-1))+0.5);
  ymax = (int) (im->SpaceToVoxelY(im2->SpacePosY(im2->DimY()-1))+0.5);
  zmax = (int) (im->SpaceToVoxelZ(im2->SpacePosZ(im2->DimZ()-1))+0.5);

  //----------------------------------------------------------
  InrImage::ptr im1;
  InrImage::ptr im1_mean;
  InrImage::ptr im1_var;
  double mean,std;
  double tmp,total;

  {
    InrImage::ptr subvol;
    subvol = InrImage::ptr(Func_SubImage( im, xmin,ymin,zmin, xmax,ymax,zmax));

    // compute square root of image
    im1 = InrImage::ptr(new InrImage(WT_FLOAT,"im1.ami.gz",subvol.get()));
    im1->InitBuffer();
    subvol->InitBuffer();
    do {
      tmp = subvol->ValeurBuffer();
      if (tmp<0) tmp = 0.01;
      im1->FixeValeur(sqrt(tmp));
      subvol->IncBuffer();
    }
    while(im1->IncBuffer());
  
    //delete subvol;
  } // subvol will get deleted here

//  neigh_size=2;

  im1_mean = InrImage::ptr(Func_localmean2(im1.get(),neigh_size));
  // unbiased version
  im1_var  = InrImage::ptr(Func_localSD2(im1.get(),im1_mean.get(),neigh_size,1));

  mean   = Func_mean(im1_var.get());
  im1_var->InitBuffer();
  total =0;
  do {
    tmp = im1_var->ValeurBuffer()-mean;
    total += tmp*tmp;
  }
  while(im1_var->IncBuffer());
  total = total/im1_var->Size();
  std=sqrt(total);

  // histogram of values between mean +/- 2*std
  double hist_min = 0;
  double hist_max = mean+2*std;
  int hist_size = (int)((hist_max-hist_min+1.0)*5.0);

  InrImage::ptr im_hist( 
                  Func_Histogram( im1_var.get(),
                                  hist_min,
                                  hist_max,
                                  hist_size));


  int maxpos = 0;
  int val,valmax = 0;
  int pos=0;

  im_hist->InitBuffer();
  do {
    val= (int) im_hist->ValeurBuffer();
    if (val>valmax) {
        valmax = val;
        maxpos = pos;
    }
    pos++;
  }
  while(im_hist->IncBuffer());

  float sigma_max = im_hist->SpacePosX(maxpos);

  //delete im1_mean;
  //delete im1_var;
  //delete im_hist;

  return sigma_max*sigma_max;

} // Func_Compute_sigma2_MRI_mode()


//------------------------------------------------------------------------------
double Func_Compute_sigma2_Gaussian_mode(InrImage* im, InrImage::ptr im_ROI, 
                                    int neigh_size)
//
{

  if (!im_ROI.get())
    {
      fprintf(stderr,"Func_Compute_sigma2_MRI_mode() \t im_ROI==NULL\n");
      return 0.0;
    }

  InrImage::ptr im2 = im_ROI;
  int xmin,xmax,ymin,ymax,zmin,zmax;

  xmin = (int) (im->SpaceToVoxelX(im2->SpacePosX(0))+0.5);
  ymin = (int) (im->SpaceToVoxelY(im2->SpacePosY(0))+0.5);
  zmin = (int) (im->SpaceToVoxelZ(im2->SpacePosZ(0))+0.5);
  xmax = (int) (im->SpaceToVoxelX(im2->SpacePosX(im2->DimX()-1))+0.5);
  ymax = (int) (im->SpaceToVoxelY(im2->SpacePosY(im2->DimY()-1))+0.5);
  zmax = (int) (im->SpaceToVoxelZ(im2->SpacePosZ(im2->DimZ()-1))+0.5);

  //----------------------------------------------------------
  InrImage::ptr im1;
  InrImage::ptr im1_mean;
  InrImage::ptr im1_var;
  double mean,std;
  double tmp,total;

  {
    InrImage::ptr subvol;
    subvol = InrImage::ptr(Func_SubImage( im, xmin,ymin,zmin, xmax,ymax,zmax));
    im1 = InrImage::ptr(new InrImage(WT_FLOAT,"im1.ami.gz",subvol.get()));
    (*im1) = (*subvol);
  } // subvol will get deleted here

//  neigh_size=2;

  im1_mean = InrImage::ptr(Func_localmean2(im1.get(),neigh_size));
  // unbiased version
  im1_var  = InrImage::ptr(Func_localSD2(im1.get(),im1_mean.get(),neigh_size,1));

  mean   = Func_mean(im1_var.get());
  im1_var->InitBuffer();
  total =0;
  do {
    tmp = im1_var->ValeurBuffer()-mean;
    total += tmp*tmp;
  }
  while(im1_var->IncBuffer());
  total = total/im1_var->Size();
  std=sqrt(total);

  // histogram of values between mean +/- 2*std
  double hist_min = 0;
  double hist_max = mean+2*std;
  int hist_size = (int)((hist_max-hist_min+1.0)*5.0);

  InrImage::ptr im_hist( 
                  Func_Histogram( im1_var.get(),
                                  hist_min,
                                  hist_max,
                                  hist_size));


  int maxpos = 0;
  int val,valmax = 0;
  int pos=0;

  im_hist->InitBuffer();
  do {
    val= (int) im_hist->ValeurBuffer();
    if (val>valmax) {
        valmax = val;
        maxpos = pos;
    }
    pos++;
  }
  while(im_hist->IncBuffer());

  float sigma_max = im_hist->SpacePosX(maxpos);

  //delete im1_mean;
  //delete im1_var;
  //delete im_hist;

  return sigma_max*sigma_max;

} // Func_Compute_sigma2_Gaussian_mode()

