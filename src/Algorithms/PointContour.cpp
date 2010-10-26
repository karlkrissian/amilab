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
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.2 $
 * $Log: PointContour.cpp,v $
 * Revision 1.2  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:13  karl
 * Sources code
 *
 * Revision 1.1  1999/05/31 16:30:04  kkrissia
 * *** empty log message ***
 *
 ***************************************************************************/

#include "PointContour.hpp"


//======================================================================
// class PointContour
//======================================================================



//----------------------------------------------------------------------
unsigned char PointContour::operator++(int)
//
  {

    x+= pas_x;

    Si (x>=_image_contours->_tx) Alors
      x = _image_contours->_tx - 1;
      pas_x = - pas_x;
      y += pas_y;
    FinSi

    Si (x<0) Alors
      x = 0;
      pas_x = - pas_x;
      y += pas_y;
    FinSi


    Si (y>=_image_contours->_ty) Alors
      y = _image_contours->_ty - 1;
      pas_y = - pas_y;
      z += pas_z;
    FinSi

    Si (y<0) Alors
      y = 0;
      pas_y = - pas_y;
      z += pas_z;
    FinSi

    return (z<_image_contours->_tz);

} // operator ++()


