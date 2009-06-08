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

#ifndef _LOCALSTATS_H
#define _LOCALSTATS_H


#include "inrimage.hpp"

// slow version
InrImage*     Func_localmean( InrImage* im, int size);

class image_extent {
public:
  image_extent() {
    for(int i=0; i<3; i++)
      for(int j=0; j<2; j++) extent[i][j]=0;
  }
  image_extent(InrImage* im);

  int extent[3][2]; // limits for each of the 3 dimensions

  bool check_axis(const int& i) const;
  void SetMin(const int& i, const int& min);
  void SetMax(const int& i, const int& max);
  void SetMinMax(const int& i, const int& min, const int& max);
  int GetMin(const int& i) const;
  int GetMax(const int& i) const;
  int GetSize(const int& i) const;
};

// separable optimized version
template <class T>
void     Func_localsum( InrImage* im, InrImage*& res,
                        InrImage*& tmp, int size,
                        image_extent& extent);

// separable optimized version 
// version with smart pointers
// using temporary image as input
template <class T>
void     Func_localsum( InrImage::ptr& tmp, InrImage::ptr& res,
                        int size,
                        image_extent& extent);


// separable optimized version
void     Func_localmean2( InrImage* im, InrImage*& res, InrImage*& tmp, int size);

// separable optimized version
InrImage*     Func_localmean2( InrImage* im, int size);


InrImage*     Func_localSD( InrImage* im, InrImage* mean, int size);
InrImage*     Func_localSD2( InrImage* im, InrImage* mean, int size, bool unbiased=false);

InrImage*     Func_localdirectionalmean( InrImage* im, InrImage* directions,
			      int size);
InrImage*     Func_localdirectionalSD( InrImage* im, InrImage* directions,
				       InrImage* mean, int size);

//
//  im     is the squared of the original image
//  im_ROI defined the region of interest: area without background
//
double        Func_Compute_sigma2_MRI_mode(InrImage* im, InrImage* im_ROI, int neigh_size=2);

#include "localstats.tpp"

#endif
