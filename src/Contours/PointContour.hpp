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
 * $Revision: 1.3 $
 * $Log: PointContour.hpp,v $
 * Revision 1.3  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.2  2005/01/29 01:56:36  karl
 * changing sign definition for IsoContour2 and also for Computing Connected Components
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:15  karl
 * Sources code
 *
 * Revision 1.1  1999/05/31 16:25:49  kkrissia
 * *** empty log message ***
 *
 ***************************************************************************/


#ifndef _POINT_CONTOUR_HPP
#define _POINT_CONTOUR_HPP

#if defined(_MSC_VER) || defined(__MINGW32__)
  #include <windows.h>
#endif

//#include "style.hpp"
#include "inrimage.hpp"

#define EPSILON 1E-2

#ifndef SIGNE
#define SIGNE(val) ((val>0)?1:-1)
#endif


//======================================================================

/* A definir : 
   image_contours
*/

///
class PointContour
//
{

  /// sens de propagation en x (+1, -1)
  int pas_x;
  /// sens de propagation en y (+1, -1)
  int pas_y;
  /// sens de propagation en z (+1, -1)
  int pas_z;


  ///
  float   val;
  ///
  int contour;

  //
  InrImage* _image_contours;

public:

  ///
  int x;
  ///
  int y;
  ///
  int z;

  ///
  Constructeur PointContour() 
  //
  {

    x = y = z = 0;
    val = 0;
    contour = -1;

    pas_x = pas_y = pas_z = 1;

    _image_contours = (InrImage*) NULL;

  } // Constructeur


  ///
  void Init( int x, int y, int z, int contour)
  //
  {

    x       = x;
    y       = y;
    z       = z;
    contour = contour;

  } // Init()

  ///
  void InitImage(  InrImage* imcontours)
  //
  {

    _image_contours = imcontours;

  }

  ///
  void InitVal( )
  //
  {

    val = (*_image_contours)(x,y,z);
  } // InitVal()

  ///
  float Val()
  //
  {
    return val;
  } // Val()

  ///
  int Signe()
  //
  {

    return SIGNE(val);

  } // Signe()

  ///
  void operator=(const PointContour& pt)
  //
  {

    x       = pt.x;
    y       = pt.y;
    z       = pt.z;
    pas_x   = pt.pas_x;
    pas_y   = pt.pas_y;
    pas_z   = pt.pas_z;
    val     = pt.val;
    contour = pt.contour;
    _image_contours = pt._image_contours;

  } // operator =

  ///
  unsigned char operator++(int );
  //

}; // PointContour




#endif // _POINT_CONTOUR_HPP
