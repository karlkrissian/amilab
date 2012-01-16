//
// C++ Implementation: GrayscaleMorpho
//
// Description: 
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

#include "amiGrayscaleMorpho.h"
#include "amiImageExtent.h"
#include "amilab_messages.h"
#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>

namespace ami {

template <class T>
void GrayscaleMorpho::TemplateProcess( int threadid)
{
  // process using precomputed extent number threadid
//  int nt = params.GetNumberOfThreads();

  // Get input extent
  InrImage::ptr in = params.GetInput();
  extenttype in_extent(in.get());
  int in_xmin = in_extent.GetMin(0);
  int in_xmax = in_extent.GetMax(0);
  int in_ymin = in_extent.GetMin(1);
  int in_ymax = in_extent.GetMax(1);
  int in_zmin = in_extent.GetMin(2);
  int in_zmax = in_extent.GetMax(2);

  double rad2 = radius*radius;
  
  extenttype extent = extents[threadid];
  int x,y,z;
  int dx,dy,dz;
  int x1,y1,z1;
  double dist_x,dist_y,dist;
  T valmin;
  T valmax;
  T val;

  int incx,incy,incz;
  in->GetBufferIncrements(incx,incy,incz);
  T* in_data  = (T*) in    ->GetData();
  T* out_data = (T*) output->GetData();

/*  std::cout << "threadid = " << threadid 
            << "extent = " 
            << extent.GetMin(0) << "-" << extent.GetMax(0) << ", "
            << extent.GetMin(1) << "-" << extent.GetMax(1) << ", "
            << extent.GetMin(2) << "-" << extent.GetMax(2) << ", "
            <<  std::endl;*/

  //
  // precompute kernel positions and displacements
  // this should be done outside of the threads
  //
  kernel_info kpt;
  
  std::vector<kernel_info> kernel_points;
  for(dx=-radius;dx<=radius;dx++) {
    dist_x = dx*dx;
    for(dy=-radius;dy<=radius;dy++) {
      dist_y = dy*dy;
      for(dz=-radius;dz<=radius;dz++) {
        dist = dist_x+dist_y+dz*dz;
        if (dist<rad2+1E-5) {
          kpt.dx  = dx;
          kpt.dy  = dy;
          kpt.dz  = dz;
          kpt.inc = dz*incz + dy*incy + dx*incx;
          kernel_points.push_back(kpt);
        }
      }
    }
  }
  // Here should send a warning message !!!
  if (kernel_points.size()==0) return;

  bool need_check_x;
  bool need_check_y;
  bool need_check_z;

  for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
  {
    need_check_z = (z<=radius)||(z>=in->DimZ()-1-radius);
    for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
    {
      need_check_y = (y<=radius)||(y>=in->DimY()-1-radius);
      T* out_data1 = out_data + z*incz + y*incy + extent.GetMin(0)*incx;
      for(x=extent.GetMin(0);x<=extent.GetMax(0); x++,out_data1++)
      {
        need_check_x = (x<=radius)||(x>=in->DimX()-1-radius);
        // now need to compute the minimum or maximum within the circle
        // not taking spacing into consideration here
        // 2D and 3D is not the same, only 3D for now
        // all this will be very slow, better precompute kernel !!!
        // but would still need to check for boundaries

        if (use_intensity_range) {
          val = *(in_data + z*incz + y*incy + x*incx);
          if ((val<intensity_min)||(val>intensity_max)) continue;
          if ((morpho_operator==Dilate)&&
              (fabs(val-intensity_max)<1E-6)) continue;
          if ((morpho_operator==Erode) &&
              (fabs(val-intensity_min)<1E-6)) continue;
        }

        // get a pointer at the current position of the image
        T* in_data1 = in_data + z*incz + y*incy + x*incx;

        if (morpho_operator==Dilate)
          valmax = *in_data1; //std::numeric_limits<T>::min();
        else
          if (morpho_operator==Erode)
            valmin = *in_data1; // std::numeric_limits<T>::max();
        
        bool pos_ok;
        
        if ((!need_check_x)&&(!need_check_y)&&(!need_check_z))
        {
          // fast version for most of the voxels/pixels ...
          if (morpho_operator==Dilate) {
            if (use_intensity_range) {
              //--- Dilation with intensity range
              for(int n=0; n<kernel_points.size(); n++)  {
                val = *(in_data1 + kernel_points[n].inc);
                if ((val>=intensity_min)&&(val<=intensity_max))
                  if (val>valmax) valmax=val;
              } // end for kernel_points
            } else {
              //--- Dilation without intensity range
              for(int n=0; n<kernel_points.size(); n++)  {
                val = *(in_data1 + kernel_points[n].inc);
                if (val>valmax) valmax=val;
              } // end for kernel_points
            }
          } else 
          if (morpho_operator==Erode) {
            if (use_intensity_range) {
              //--- Erosion with intensity range
              for(int n=0; n<kernel_points.size(); n++)  {
                val = *(in_data1 + kernel_points[n].inc);
                if ((val>=intensity_min)&&(val<=intensity_max))
                  if (val<valmin) valmin=val;
              } // end for kernel_points
            } else {
              //--- Erosion without intensity range
              for(int n=0; n<kernel_points.size(); n++)  {
                val = *(in_data1 + kernel_points[n].inc);
                  if (val<valmin) valmin=val;
              } // end for kernel_points
            }
          }
        } else 
        // need to check for limits, slower version
        {
          for(int n=0; n<kernel_points.size(); n++) 
          {
            kpt = kernel_points[n];
            if (need_check_x) {
              x1 = x+kpt.dx;
              if ((x1<in_xmin)||(x1>in_xmax)) continue;
            }
            if (need_check_y) {
              y1 = y+kpt.dy;
              if ((y1<in_ymin)||(y1>in_ymax)) continue;
            }
            if (need_check_z) {
              z1 = z+kpt.dz;
              if ((z1<in_zmin)||(z1>in_zmax)) continue;
            }
            // now we can compute the min or max
            val = *(in_data1 + kpt.inc);
            if (use_intensity_range) {
              if ((val<intensity_min)||(val>intensity_max)) continue;
            }
            if (morpho_operator==Dilate) {
              if (val>valmax) valmax=val;
            } else {
              if (val<valmin) valmin=val;
            }
          } // end for kernel_points
        }
          
        
        if (morpho_operator==Dilate)
          *out_data1 = valmax;
        //*(in_data + z*incz + y*incy + x*incx) +x+y+z; //valmax; 
        else
          *out_data1 = valmin;
      } // end for x
    } // end for y
  } // end for z

}


void GrayscaleMorpho::Process( int threadid)
{
  // process using precomputed extent number threadid
  InrImage::ptr in = params.GetInput();
  
  switch (in->GetFormat()) {
    case WT_UNSIGNED_CHAR:  TemplateProcess<unsigned char>  (threadid); break;
    case WT_UNSIGNED_SHORT: TemplateProcess<unsigned short> (threadid); break;
    case WT_SIGNED_SHORT:   TemplateProcess<short>          (threadid); break;
    case WT_UNSIGNED_INT:   TemplateProcess<unsigned int>   (threadid); break;
    case WT_SIGNED_INT:     TemplateProcess<int>            (threadid); break;
    case WT_FLOAT:          TemplateProcess<float>          (threadid); break;
    case WT_DOUBLE:         TemplateProcess<double>         (threadid); break;
    default: CLASS_ERROR((boost::format(" format %1% not available")%in->GetFormat()).str().c_str());
  }

}

void GrayscaleMorpho::Run() 
{
  InrImage::ptr in = params.GetInput();
  // Create output
  output = InrImage::ptr(new InrImage(in->GetFormat(),"grayscalemorpho.ami.gz",in.get()));
  // copy input
  (*output)=(*in);
  
  ImageToImageFilter::Run();
}

} // end namespace ami
