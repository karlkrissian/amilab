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

InrImage*     Func_localmean( InrImage* im, int size);
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

#endif
