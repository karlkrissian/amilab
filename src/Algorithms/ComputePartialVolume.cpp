//
// C++ Implementation: ComputePartialVolume
//
// Description: Estimate the partial volume creating an image
//  between 0 and 1 (0 for negative intensity values, 1 for positive values)
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "ComputePartialVolume.h"
#include <iostream>
using namespace std;

//---------------------------------------------------
//ComputePartialVolume methods
//---------------------------------------------------

//2D analytic sinthetic images
//---------------------------------------------------------------------
// volume is the volume of cube
double ComputePartialVolume::AnalyticRecursivePositiveSurface( double val[4], double subvols[4], double size, int subdiv_level,
                                                    double x, double y)
{
  int i,j,n;
  int i1,j1;
  int num_pos=0;
  double volume = size*size;

  // if all positive return 1
  for(i=0;i<4;i++) if (val[i]>=0) num_pos++;
  if (num_pos==4) {
    for(i=0;i<4;i++) subvols[i]=volume/4.0;
    return volume;
  }
  if (num_pos==0) {
    for(i=0;i<4;i++) subvols[i]=0;
    return 0;
  }
  // else decide if subdivide or not
  AnalyticFunctionBase::ptr fun(analyticfunc.lock());
  if (fun.get())
  {
    if (subdiv_level>0) {
      // create 8 more cubes to compute
      double corners[3][3];
      size = size/2.0;
      // fill values
      n=0;
      // fill the corners of the big cube
      for(j=0;j<3;j++)
      for(i=0;i<3;i++) {
        corners[j][i] = (*fun)(x+size*(double)i,y+size*(double)j,0);
      }

      // call the computation for each new smaller cube
      double total = 0;
      double newval[4];
      double local_subvols[4];
      n=0;
      for(j=0;j<2;j++)
      for(i=0;i<2;i++,n++) {
        // fill the values
        int n1=0;
        for(j1=0;j1<2;j1++)
        for(i1=0;i1<2;i1++,n1++) {
          newval[n1] = corners[j+j1][i+i1];
        }
        subvols[n] = AnalyticRecursivePositiveSurface(newval,local_subvols,size,subdiv_level-1,
                                                      x+size*(double)i,y+size*(double)j);
        total += subvols[n];
      } // end for i,j
      return total;
    } else
      return num_pos*volume/4.0;
  }
  return 0;
}



//---------------------------------------------------------------------
//
// subdiv is the number of subdivisions
//
InrImage::ptr ComputePartialVolume::ComputeAnalyticPartialSurfaceSubdiv(float ipos, float ineg)
{
  int x,y,n;
  int z = 0;
  int i,j;
  double val[4];
  double vol[4];
  float* inbuf;
  float* resbuf;

  InrImage::ptr iml(input.lock());
  if (iml.get())
  {
    if (iml->GetFormat()!=WT_FLOAT) {
      cerr << "ComputeAnalyticPartialSurface only for float images for now !" << endl;
      return InrImage::ptr();
    }
  
    InrImage::ptr res = InrImage::ptr(new InrImage(iml->DimX(), iml->DimY(), iml->DimZ(), WT_FLOAT,"PV.ami.gz"));
    res->InitImage(0);

    long size = iml->Size();
    long count=0;
    int previous_percentage = 0;
    int percentage_step = 5;
    AnalyticFunctionBase::ptr fun(analyticfunc.lock());
    if (fun.get())
    {
      for (y=0;y<iml->DimY()-1;y++)
      {
        if (count/(1.0*size)*100.0>previous_percentage+percentage_step) {
          previous_percentage += percentage_step;
          cout << boost::format(" %1%%% ") % previous_percentage;
          cout.flush();
        }
        for (x=0;x<iml->DimX()-1;x++,count++)
        {
          inbuf = (float*)iml->BufferPtr(x,y,z);
          // Process cube between (x,y,z) and (x+1,y+1,z+1)
          n=0; 
          for(j=0;j<2;j++)
          for(i=0;i<2;i++)
            val[n++] = (*fun)(x+(double)i,y+(double)j,0);

          AnalyticRecursivePositiveSurface(val,vol,1,subdiv,x,y);

          n=0; 
          for(j=0;j<2;j++)
          for(i=0;i<2;i++) {
            resbuf = (float*)res->BufferPtr(x+i,y+j,z);
            (*resbuf) += vol[n++];
          }
        } // end for x
      } // end for y

      for(int y=0; y<iml->DimY(); y++)
      {
        for(int x=0; x<iml->DimX(); x++)
        {
          resbuf = (float*)res->BufferPtr(x,y,z);
          res->BufferPos(x,y,z);
          res->FixeValeur(ineg+(ipos-ineg)*(*resbuf));
        }
      }
      
      cout << endl;

      return res;
    }
  }
  else
  {
    cerr << "It isn't posible to get the image smart pointer." << endl;
    return InrImage::ptr();
  }
  return InrImage::ptr();
} // RunSubDiv()


//3D analytic sinthetic images
//---------------------------------------------------------------------
// volume is the volume of cube
double ComputePartialVolume::AnalyticRecursivePositiveVolume( double val[8], double subvols[8], double size, int subdiv_level,
                                        double x, double y, double z)
{
  int i,j,k,n;
  int i1,j1,k1;
  int num_pos=0;
  double volume = size*size*size;

  // if all positive return 1
  for(i=0;i<8;i++) if (val[i]>=0) num_pos++;
  if (num_pos==8) {
    for(i=0;i<8;i++) subvols[i]=volume/8.0;
    return volume;
  }
  if (num_pos==0) {
    for(i=0;i<8;i++) subvols[i]=0;
    return 0;
  }
  // else decide if subdivide or not
  AnalyticFunctionBase::ptr fun(analyticfunc.lock());
  if (fun.get())
  {
    if (subdiv_level>0) {
      // create 8 more cubes to compute
      double corners[3][3][3];
      size = size/2.0;
      // fill values
      n=0;
      // fill the corners of the big cube
      for(k=0;k<3;k++)
      for(j=0;j<3;j++)
      for(i=0;i<3;i++) {
        corners[k][j][i] = (*fun)(x+size*(double)i,y+size*(double)j,z+size*(double)k);
      }

      // call the computation for each new smaller cube
      double total = 0;
      double newval[8];
      double local_subvols[8];
      n=0;
      for(k=0;k<2;k++)
      for(j=0;j<2;j++)
      for(i=0;i<2;i++,n++) {
        // fill the values
        int n1=0;
        for(k1=0;k1<2;k1++)
        for(j1=0;j1<2;j1++)
        for(i1=0;i1<2;i1++,n1++) {
          newval[n1] = corners[k+k1][j+j1][i+i1];
        }
        subvols[n] = AnalyticRecursivePositiveVolume(newval,local_subvols,size,subdiv_level-1,
                                                     x+size*(double)i,y+size*(double)j,z+size*(double)k);
        total += subvols[n];
      } // end for i,j,k
      return total;
    } else
      return num_pos*volume/8.0;
  }
  return 0;
}



//---------------------------------------------------------------------
//
// subdiv is the number of subdivisions
//
InrImage::ptr ComputePartialVolume::RunAnalyticSubdiv(float ipos, float ineg)
{
  int x,y,z,n;
  int i,j,k;
  double val[8];
  double vol[8];
  float* inbuf;
  float* resbuf;

  InrImage::ptr iml(input.lock());
  if (iml.get())
  {
    if (iml->GetFormat()!=WT_FLOAT) {
      cerr << "ComputeAnalyticPartialVolume only for float images for now !" << endl;
      return InrImage::ptr();
    }
 
    InrImage::ptr res = InrImage::ptr(new InrImage(iml->DimX(), iml->DimY(), iml->DimZ(), WT_FLOAT,"PV.ami.gz"));
    res->InitImage(0);

    long size = iml->Size();
    long count=0;
    int previous_percentage = 0;
    int percentage_step = 5;
    AnalyticFunctionBase::ptr fun(analyticfunc.lock());

    if (fun.get())
    {
      for (z=0;z<iml->DimZ()-1;z++)
      {
        for (y=0;y<iml->DimY()-1;y++)
        {
          if (count/(1.0*size)*100.0>previous_percentage+percentage_step) {
            previous_percentage += percentage_step;
            cout << boost::format(" %1%%% ") % previous_percentage;
            cout.flush();
          }
          for (x=0;x<iml->DimX()-1;x++,count++)
          {
    //        if ((x==29)&&(y==48)&&(z==51)) {
    //          n=0;
    //        }
            inbuf = (float*)iml->BufferPtr(x,y,z);
            // Process cube between (x,y,z) and (x+1,y+1,z+1)
            n=0;
            for(k=0;k<2;k++) 
            for(j=0;j<2;j++)
            for(i=0;i<2;i++)
              val[n++] = (*fun)(x+(double)i,y+(double)j,z+(double)k);

            AnalyticRecursivePositiveVolume(val,vol,1,subdiv,x,y,z);

            n=0;
            for(k=0;k<2;k++) 
            for(j=0;j<2;j++)
            for(i=0;i<2;i++) {
              resbuf = (float*)res->BufferPtr(x+i,y+j,z+k);
              (*resbuf) += vol[n++];
            }
          } // end for x
        } // end fory
      } // end for z
      
      for(int z=0; z<iml->DimZ(); z++)
      {
        for(int y=0; y<iml->DimY(); y++)
        {
          for(int x=0; x<iml->DimX(); x++)
          {
            resbuf = (float*)res->BufferPtr(x,y,z);
            res->BufferPos(x,y,z);
            res->FixeValeur(ineg+(ipos-ineg)*(*resbuf));
          }
        }
      }
      
      cout << endl;

      return res;
    }
  }
  else
  {
    cerr << "It isn't posible to get the image smart pointer." << endl;
    return InrImage::ptr();
  }
  return InrImage::ptr();
} // RunAnalyticSubdiv()


// volume is the volume of cube
double ComputePartialVolume::RecursivePositiveVolume( double val[8], double subvols[8], double volume, int subdiv_level )
{
  int i,j,k,n;
  int i1,j1,k1;
  int num_pos=0;
  // if all positive return 1
  for(i=0;i<8;i++) if (val[i]>=0) num_pos++;
  if (num_pos==8) {
    for(i=0;i<8;i++) subvols[i]=volume/8.0;
    return volume;
  }
  if (num_pos==0) {
    for(i=0;i<8;i++) subvols[i]=0;
    return 0;
  }
  // else decide if subdivide or not
  if (subdiv_level>0) {
    // create 8 more cubes to compute
    double corners[3][3][3];
    // fill values
    n=0;
    // fill the corners of the big cube
    for(k=0;k<2;k++)
    for(j=0;j<2;j++)
    for(i=0;i<2;i++,n++) {
      corners[k*2][j*2][i*2] = val[n];
    }
    // fill the middle of lines in X
    for(k=0;k<2;k++)
    for(j=0;j<2;j++) {
      double* cl = corners[k*2][j*2];
      cl[1] = (cl[0]+cl[2])/2.0;
    }
    // fill the middle of plane in Y
    for(k=0;k<2;k++)
    for(i=0;i<3;i++)
    {
      corners[k*2][1][i] = (corners[k*2][0][i]+corners[k*2][2][i])/2.0;
    }
    // fill the middle in Z dir
    for(j=0;j<3;j++)
    for(i=0;i<3;i++)
    {
      corners[1][j][i] = (corners[0][j][i]+corners[2][j][i])/2.0;
    }
    // call the computation for each new smaller cube
    double total = 0;
    double newval[8];
    double local_subvols[8];
    n=0;
    for(k=0;k<2;k++)
    for(j=0;j<2;j++)
    for(i=0;i<2;i++,n++) {
      // fill the values
      int n1=0;
      for(k1=0;k1<2;k1++)
      for(j1=0;j1<2;j1++)
      for(i1=0;i1<2;i1++,n1++) {
        newval[n1] = corners[k+k1][j+j1][i+i1];
      }
      subvols[n] = RecursivePositiveVolume(newval,local_subvols,volume/8.0,subdiv_level-1);
      total += subvols[n];
    } // end for i,j,k
    return total;
  } else
    return num_pos*volume/8.0;
}



//---------------------------------------------------------------------
//
// subdiv is the number of subdivisions
//
InrImage::ptr ComputePartialVolume::RunSubdiv()
{
  int x,y,z,n;
  int i,j,k;
  double val[8];
  double vol[8];
  float* inbuf;
  float* resbuf;

  InrImage::ptr iml(input.lock());
  if (iml.get()) 
  {
    if (iml->GetFormat()!=WT_FLOAT) {
      cerr << "ComputePartialVolume only for float images for now !" << endl;
      return InrImage::ptr();
    }

    InrImage::ptr res = InrImage::ptr(new InrImage(iml->DimX(), iml->DimY(), iml->DimZ(), WT_FLOAT,"PV.ami.gz"));
    res->InitImage(0);

    long size = iml->Size();
    long count=0;
    int previous_percentage = 0;
    int percentage_step = 5;

    for (z=0;z<iml->DimZ()-1;z++)
    {
      for (y=0;y<iml->DimY()-1;y++)
      {
        if (count/(1.0*size)*100.0>previous_percentage+percentage_step) {
          previous_percentage += percentage_step;
          cout << boost::format(" %1%%% ") % previous_percentage;
          cout.flush();
        }
        for (x=0;x<iml->DimX()-1;x++,count++)
        {
          inbuf = (float*)iml->BufferPtr(x,y,z);
          // Process cube between (x,y,z) and (x+1,y+1,z+1)
          n=0;
          for(k=0;k<2;k++) 
          for(j=0;j<2;j++)
          for(i=0;i<2;i++)
            val[n++] = (*iml)(x+i,y+j,z+k);

          RecursivePositiveVolume(val,vol,1,subdiv);

          n=0;
          for(k=0;k<2;k++) 
          for(j=0;j<2;j++)
          for(i=0;i<2;i++) {
            resbuf = (float*)res->BufferPtr(x+i,y+j,z+k);
            (*resbuf) += vol[n++];
          }
        } // end for x
      } // end fory
    } // end for z
    cout << endl;

    return res;
  }
  else
  {
    cerr << "It isn't posible to get the image smart pointer." << endl;
    return InrImage::ptr();
  }
} // RunSubdiv()


//---------------------------------------------------------------------
//
// resolution is the number of subdivision along each axis
//
InrImage::ptr ComputePartialVolume::Run()
{
  int x,y,z;
  int n=resolution,n3;
  int i,j,k;
  float val;
  int sum_pos;
  int sum_neg;
  float* inbuf;
  float* resbuf;
  float posx,posy,posz;
  double possum[2][2][2]; // precomputed contributions to the corner voxels of fully positive cube

  n3 = n*n*n;
  double sum_elt = 1.0/(1.0*n3);

  // precompute possum
  for(i=0;i<2;i++)
  for(j=0;j<2;j++)
  for(k=0;k<2;k++) possum[i][j][k] = 0;

  for(k=0;k<n;k++) 
  for(j=0;j<n;j++)
  for(i=0;i<n;i++)
  {
    posx = round(i*1.0/n);
    posy = round(j*1.0/n);
    posz = round(k*1.0/n);
    possum[(int)posx][(int)posy][(int)posz]+=sum_elt;
  }
  InrImage::ptr iml(input.lock());
  if (iml.get())
  {
    if (iml->GetFormat()!=WT_FLOAT) {
      cerr << "ComputePartialVolume only for float images for now !" << endl;
      return InrImage::ptr();
    }
    
    InrImage::ptr res = InrImage::ptr(new InrImage(iml->DimX(), iml->DimY(), iml->DimZ(), WT_FLOAT,"PV.ami.gz"));
    res->InitImage(0);

    long size = iml->Size();
    long count=0;
    int previous_percentage = 0;
    int percentage_step = 5;

    for (z=0;z<iml->DimZ()-1;z++)
    {
      for (y=0;y<iml->DimY()-1;y++)
      {
        if (count/(1.0*size)*100.0>previous_percentage+percentage_step) {
          previous_percentage += percentage_step;
          cout << boost::format(" %1%%% ") % previous_percentage;
          cout.flush();
        }
        for (x=0;x<iml->DimX()-1;x++,count++)
        {
          inbuf = (float*)iml->BufferPtr(x,y,z);
          // Process cube between (x,y,z) and (x+1,y+1,z+1)
          sum_pos = 0;
          sum_neg = 0;
          for(k=0;k<2;k++) 
          for(j=0;j<2;j++)
          for(i=0;i<2;i++)
          {
            val = (*iml)(x+i,y+j,z+k);
            if (val>=0) sum_pos++;
            if (val<0) sum_neg++;
          }
          if (sum_pos==8) {
            for(i=0;i<2;i++)
            for(j=0;j<2;j++)
            for(k=0;k<2;k++) {
              resbuf = (float*)res->BufferPtr(x+i,y+j,z+k);
              (*resbuf)+=possum[i][j][k];
            }
          } else
          if (sum_neg>0) {
            // positive and negative values, need to downsample
            sum_pos = 0;
            sum_neg = 0;
            for(k=0;k<n;k++) 
            for(j=0;j<n;j++)
            for(i=0;i<n;i++)
            {
              posx = x+i*1.0/n;
              posy = y+j*1.0/n;
              posz = z+k*1.0/n;
              val = iml->InterpLinIntensite(posx,posy,posz);
              resbuf = (float*)res->BufferPtr(round(posx),
                                              round(posy),
                                              round(posz));
              if (val>=0) (*resbuf) += sum_elt;
            }
          }
        } // end for x
      } // end fory
    } // end for z
    cout << endl;

    return res;
  } 
  else
  {
    cerr << "It isn't possible to get the image smart pointer." << endl;
    return InrImage::ptr();
  }
} // Run

//Set and get subdivision level methods
void ComputePartialVolume::setSubdiv(int s)
{
  subdiv = s;
}

int  ComputePartialVolume::getSubdiv()
{
  return subdiv;
}

//Set and get AnalyticFunction methods
void ComputePartialVolume::setAnalyticFunction(AnalyticFunctionBase::ptr fun)
{
  analyticfunc = AnalyticFunctionBase::wptr(fun);
}

AnalyticFunctionBase::wptr ComputePartialVolume::getAnalyticFunction()
{
  return analyticfunc;
}

//Set and get InputImage methods
void ComputePartialVolume::setInputImage(InrImage::ptr input_image)
{
  input = InrImage::wptr(input_image);
}

InrImage::wptr ComputePartialVolume::getInputImage()
{
  return input;
}

//Set and get Resolution methods
void ComputePartialVolume::setResolution(int resol)
{
  resolution = resol;
}

int ComputePartialVolume::getResolution()
{
  return resolution;
}

