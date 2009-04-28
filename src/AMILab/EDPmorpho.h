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

#ifndef  _EDPMORPHO_H_
#define _EDPMORPHO_H_

#include "inrimage.hpp"

#define SCHEMA_OS    1 // Osher    & Sethian
#define SCHEMA_BM    2 // Brockett & Maragos
#define SCHEMA_AUTRE 3 //

InrImage* Func_EDP_dilate( InrImage* input, 
			   float size, float step, int schema=SCHEMA_BM);

InrImage* Func_EDP_erode( InrImage* input, 
			  float size, float step, int schema=SCHEMA_BM);

InrImage* Func_EDP_open( InrImage* input, 
			 float size, float step, int schema=SCHEMA_BM);

InrImage* Func_EDP_close( InrImage* input, 
			  float size, float step, int schema=SCHEMA_BM);


InrImage* Func_EDP_dilate( InrImage* input, 
			   float size, float step, 
			   float min, float max, int schema=SCHEMA_BM);

InrImage* Func_EDP_erode( InrImage* input, 
			  float size, float step,  
			   float min, float max, int schema=SCHEMA_BM);

InrImage* Func_EDP_open( InrImage* input, 
			 float size, float step,  
			   float min, float max, int schema=SCHEMA_BM);

InrImage* Func_EDP_close( InrImage* input, 
			  float size, float step,  
			   float min, float max, int schema=SCHEMA_BM);


#endif // _EDPMORPHO_H_
