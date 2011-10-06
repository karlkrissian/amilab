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




#ifndef CURVATURAS_PRINCIPALES_HPP
#define CURVATURAS_PRINCIPALES_HPP

#include "CommonConfigure.h"

COMMON_EXPORT
int CurvaturasPrincipales(float H[3][3],
			  float p[3],
			  float vmax[3],
			  float vmin[3],
			  float *lmax,
			  float *lmin,
			  float umbral);

// Without eigenvectors
COMMON_EXPORT
int CurvaturasPrincipales(float H[3][3],
			  float p[3],
			  float *lmax,
			  float *lmin,
			  float umbral);

#endif // CURVATURAS_PRINCIPALES_HPP
