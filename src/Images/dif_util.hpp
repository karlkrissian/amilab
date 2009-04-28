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
// Procedure de copie d'une image dans une autre avec ou sans conversion.
//
//
// Les 2 images doivent deja etre allouees.


#ifndef _DIF_UTIL_HPP
#define _DIF_UTIL_HPP

#include "style.hpp"

DebutDeclareC
#include <epidaure.h>
#include <epidaure.ee>
//#include <dif_fusion.h>
#include <malloc.h>
FinDeclareC

#include "inrimage.hpp"

int DIF_CopyImage( t_Image *theIm /* input image */,
		   t_Image *resIm /* output image */,
		   int flag /* if true, then conversion */ );

#endif // _DIF_UTIL_HPP
