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


// volume is the volume of cube
double RecursivePositiveVolume( double val[8], double subvols[8], double volume, int subdiv_level )
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
InrImage* ComputePartialVolumeSubdiv(InrImage* input, int subdiv)
{
  int x,y,z,n;
  int i,j,k;
  double val[8];
  double vol[8];
  float* inbuf;
  float* resbuf;


  if (input->GetFormat()!=WT_FLOAT) {
    std::cerr << "ComputePartialVolume only for float images for now !" << std::endl;
    return NULL;
  }

  InrImage* res = new InrImage(WT_FLOAT,"PV.ami.gz",input);
  res->InitImage(0);

  long size = input->Size();
  long count=0;
  int previous_percentage = 0;
  int percentage_step = 5;

  for (z=0;z<input->DimZ()-1;z++)
  {
    for (y=0;y<input->DimY()-1;y++)
    {
      if (count/(1.0*size)*100.0>previous_percentage+percentage_step) {
        previous_percentage += percentage_step;
       std::cout << boost::format(" %1%%% ") % previous_percentage;
       std::cout.flush();
      }
      for (x=0;x<input->DimX()-1;x++,count++)
      {
        inbuf = (float*)input->BufferPtr(x,y,z);
        // Process cube between (x,y,z) and (x+1,y+1,z+1)
        n=0;
        for(k=0;k<2;k++) 
        for(j=0;j<2;j++)
        for(i=0;i<2;i++)
          val[n++] = (*input)(x+i,y+j,z+k);

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
 std::cout << std::endl;

  return res;
} // ComputePartialVolumeSubdiv()


//---------------------------------------------------------------------
//
// resolution is the number of subdivision along each axis
//
InrImage* ComputePartialVolume(InrImage* input, int resolution)
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


  if (input->GetFormat()!=WT_FLOAT) {
    std::cerr << "ComputePartialVolume only for float images for now !" << std::endl;
    return NULL;
  }

  InrImage* res = new InrImage(WT_FLOAT,"PV.ami.gz",input);
  res->InitImage(0);

  long size = input->Size();
  long count=0;
  int previous_percentage = 0;
  int percentage_step = 5;

  for (z=0;z<input->DimZ()-1;z++)
  {
    for (y=0;y<input->DimY()-1;y++)
    {
      if (count/(1.0*size)*100.0>previous_percentage+percentage_step) {
        previous_percentage += percentage_step;
       std::cout << boost::format(" %1%%% ") % previous_percentage;
       std::cout.flush();
      }
      for (x=0;x<input->DimX()-1;x++,count++)
      {
        inbuf = (float*)input->BufferPtr(x,y,z);
        // Process cube between (x,y,z) and (x+1,y+1,z+1)
        sum_pos = 0;
        sum_neg = 0;
        for(k=0;k<2;k++) 
        for(j=0;j<2;j++)
        for(i=0;i<2;i++)
        {
          val = (*input)(x+i,y+j,z+k);
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
            val = input->InterpLinIntensite(posx,posy,posz);
            resbuf = (float*)res->BufferPtr(round(posx),
                                            round(posy),
                                            round(posz));
            if (val>=0) (*resbuf) += sum_elt;
          }
        }
      } // end for x
    } // end fory
  } // end for z
 std::cout << std::endl;

  return res;
} // ComputePartialVolume
