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
//     Karl Krissian
//     Las Palmas, le 14-05-2000
//


#ifndef _COULEUR_HPP
#define _COULEUR_HPP

/*
//--------------------------------------------------
// includes for wxWidgets
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
*/

#include "wx/colour.h"

//#include "style.hpp"
//#include "palette.hpp"
//#include <iostream>
//using namespace std;

struct rgb_color { 
    unsigned char r,g,b; 
};

//============================================================================
///
class ClasseCouleur : public wxColour
//    =============
{
 rgb_color compact_color;

public:

  ///
  ClasseCouleur( )
  //           -------------
  {
    Set(0,0,0);
    compact_color.r = compact_color.g = compact_color.b = 0;
  }

  ///
  ClasseCouleur( int r, int g, int b)
  //           -------------
  {
    Set(r,g,b);
    compact_color.r = r;
    compact_color.g = g;
    compact_color.b = b;
  }

  ///
  void FixeValeur(
  //   ----------
                  unsigned char r,
                  unsigned char g,
                  unsigned char b,
                  unsigned char a = 255
                 )
  {
    Set(r,g,b,a);
    compact_color.r = r;
    compact_color.g = g;
    compact_color.b = b;
  }


  const rgb_color& GetCompactColor() const
  { 
    return compact_color;
/*
    rgb_color res;
    res.r = Red();
    res.g = Green();
    res.b = Blue();
    return res; 
*/
  }

  /*
  ///
  unsigned char* RetourneCouleur( ) const
  //   ---------------
  {
    return GetPixel();
  }

  ///
  unsigned char* RetourneCouleurDistincte( ) const
  //       ------------------------
  {
    wxColour distinct((Red()+128) % 256,
                      (Green()+128) % 256,
                      (Blue()+128) % 256);

    return distinct.GetPixel( );
    if (palette->_type_palette == PALETTE_RGB) {
      return palette->RGB( (unsigned short) ( (red+128) % 256 ),
                             (unsigned short) ( (green+128) % 256),
                             (unsigned short) ( (blue+128) % 256) );
    Sinon
      cerr << "RetourneCouleurDistincte only for RGB palette" << endl;
      return 0;
    } // end if
//    return 0;
  }
  */

};  // Classecouleur

#endif // _COULEUR_HPP

