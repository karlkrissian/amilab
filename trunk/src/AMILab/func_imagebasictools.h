/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@ctm.ulpgc.es

    OSRAD is a noise reducing filter program
    ==================================================
    Copyright (C) 2008  Karl Krissian

    OSRAD is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    OSRAD is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in LesserGPL_license.txt
*/

#ifndef FUNC_BASICTOOLS_H
#define FUNC_BASICTOOLS_H

#include "inrimage.hpp"

InrImage* Func_AutoCrop( InrImage* im, int margin);

InrImage* Func_SubImage( InrImage* im, 
			 int x1, int y1, int z1,
			 int x2, int y2, int z2);

void      Func_PutImage( InrImage* i1, 
			 InrImage* i2,
			 int x, int y, int z);

#endif // FUNC_BASICTOOLS_H
