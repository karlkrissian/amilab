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

#ifndef FUNC_GLOBALSTATS_H
#define FUNC_GLOBALSTATS_H

#include "inrimage.hpp"

// count the number of positive points of the image
int         Func_count( InrImage* im);
double        Func_mean( InrImage* im);
double        Func_max(  InrImage* im, InrImage* mask);
int         Func_argmax(  InrImage* im, InrImage* mask=NULL);
double        Func_min(  InrImage* im, InrImage* mask);
// Median value of the image
double        Func_med(  InrImage* im, float percent=50, InrImage* mask=NULL);
double        Func_mean( InrImage* im, InrImage* mask);
InrImage*   Func_Histogram( InrImage* im, float min, float max, int ninterv);


#endif // FUNC_GLOBALSTATS_H
