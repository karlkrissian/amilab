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
// 26 voisinage
//

#ifndef VOISINS27_HPP
#define VOISINS27_HPP

#include "style.hpp"

#define MASQUE_X 3  // 1+2
#define MASQUE_Y 12 // 4+8
#define MASQUE_Z 48 // 16+32


//===========================================================
/**
  D�finition d'un 27 voisinage i.e. un point dont chaque
  coordonnees varie dans  {-1,0,1} dans un espace � 3 dimensions
*/
class Voisin27
//     --------
{

  /** cod� sur 6 bits, 3x2bits, 2 bits par coordonn�e \\
    \begin{itemize} 
      \item -1 est cod� 00 \\
      \item  0 est cod� 01 \\
      \item  1 est cod� 10 \\
    \end{itemize}
  */
  int voisin;

public:

  /// Constructeur par d�faut
  Constructeur Voisin27(  ) { voisin = 21; } // 21 = 1+4+16 = (0,0,0)

  /// Constructeur par d�faut
  Constructeur Voisin27( int x, int y, int z)
  { voisin = (x+1) + ((y+1)<<2) + ((z+1)<<4);}

  ///
  int X() { return (voisin & MASQUE_X)-1;}
 
  ///
  int Y() { return ((voisin & MASQUE_Y)>>2) -1;}

  ///
  int Z() { return ((voisin & MASQUE_Z)>>4)-1;}

  ///
  void FixeX( int x) { voisin = (voisin&~MASQUE_X)|(x+1);}
 
  ///
  void FixeY( int y) { voisin = (voisin&~MASQUE_Y)|((y+1)<<2);}

  ///
  void FixeZ( int z) { voisin = (voisin&~MASQUE_Z)|((z+1)<<4);}

  ///
  unsigned char operator==( Voisin27& v) { return (voisin==v.voisin); }

  /**
   */
  friend ostream& operator<<( ostream&s, Voisin27& pt)
  {
    return s <<'(' << pt.X()  << ',' << pt.Y()  << ',' << pt.Z()  << ')';
  }

};

//-----------------------------------------------------------
///
//ostream& operator<<( ostream&s, Voisin27& pt)
//
//{
//  return s <<'(' << pt.X()  << ',' << pt.Y()  << ',' << pt.Z()  << ')';
//}


#endif // VOISINS27_HPP
