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
#include "amiImageExtent.h"




// slow version
InrImage*     Func_localmean( InrImage* im, int size);


// separable optimized version
template <class T>
void     Func_localsum( InrImage* im, InrImage*& res,
                        InrImage*& tmp, int size,
                        ami::ImageExtent<int>& extent);

// separable optimized version 
// version with smart pointers
// using temporary image as input
template <class T>
void     Func_localsum( InrImage::ptr& tmp, InrImage::ptr& res,
                        int size,
                        ami::ImageExtent<int>& extent);


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


/**
 * @brief estimated the variance of the noise based on the mode of the
 * histogram of the local variance in the case of Rician model.
 *
 * @param im squared of the original image
 * @param im_ROI region of interest: area without background
 * @param neigh_size neighborhood size to compute the local variance
 * Vale 2 por omisión.
 * @return double
 **/
double        Func_Compute_sigma2_MRI_mode(InrImage* im, InrImage::ptr im_ROI, 
                                           int neigh_size=2);

/**
 * @brief estimated the variance of the noise based on the mode of the
 * histogram of the local variance in the case of additive Gaussian model.
 *
 * @param im squared of the original image
 * @param im_ROI region of interest: area without background
 * @param neigh_size neighborhood size to compute the local variance
 * Vale 2 por omisión.
 * @return double
 **/
double        Func_Compute_sigma2_Gaussian_mode(InrImage* im, 
                                                InrImage::ptr im_ROI, 
                                                int neigh_size=2);

#include "localstats.tpp"

#endif
