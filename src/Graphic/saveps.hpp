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
//
// Fichier saveps.hpp
//
// Karl Krissian       Sophia Antipolis, le 26-05-98
//
// Inspir� du programme "xv"
// version simplifi�e
//

#ifndef _SAVEPS_CPP
#define _SAVEPS_CPP

#include "style.hpp"

DebutDeclareC
//#include <X11/Intrinsic.h>
//#include <X11/Shell.h>
#include <stdio.h>
FinDeclareC

#define F_FULLCOLOR 0
#define F_GREYSCALE 1

#define REVDATE "??"

#define byte unsigned char

// Format A4
#define  psizex  8.266999999
#define  psizey  11.811


//static void psColorImage( FILE* ) {}
//          ------------

//void writePS( const char* filename, XImage* image, XColor* colors, int colorType);
//   -------

//void writePS( char* filename, InrImage* image);
//   -------

#endif 
