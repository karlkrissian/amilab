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
 * $Log: fonction2D.hpp,v $
 * Revision 1.2  2005/11/16 14:03:08  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:09:49  karl
 * Sources code
 *
 *
 ***************************************************************************/


#ifndef _FONCTION2D_HPP
#define _FONCTION2D_HPP

#include "style.hpp"
extern "C" {
#include <stdlib.h>
}
#include <stdio.h>
#include "chaine.hpp"
#include "Coordonnees.hpp"
#include "TableauDyn.hpp"


//----------------------------------------------------------------------
class Fonction2D
//
{ 

public:

  /// Exceptions
  class ErreurLecture
  {
  public:
    ErreurLecture( Chaine message)
      {
	cerr << "Fonction2D Erreur de Lecture " << message << endl;
      }
  };

private:

  ///
  float    _xmin;
  ///
  float    _xmax;
  ///
  float    _ymin;
  ///
  float    _ymax;

  ///
  TableauDyn< Point2D<float> > _points;

  ///
  Chaine  _nom;


public:

  ///
   Fonction2D( );
  //

  ///
   Fonction2D( Chaine nom );
  //

  ///
   Fonction2D( const Fonction2D & );
  //

  ///
  ~Fonction2D();
  //
   
  ///
  void Read( Chaine nom) throw( ErreurLecture);
  //

  ///
  void Sauve( Chaine nom="");
  //
 
  ///
  int NbElts() { return _points.NbElts(); }
  //

  ///
  Point2D<float>& operator[]( int n) { return _points[n];}
  //

  ///
  Fonction2D& operator+=( const Point2D<float>& pt);
  //

  ///
  Fonction2D& operator=(const Fonction2D&);
  //

  ///
  Fonction2D& operator=( float r);
  //

  ///
  Fonction2D& operator+=( float r);
  //

  ///
  Fonction2D& operator*=( float r);
  //

  ///
  Fonction2D& RacineCarree( );
  //

  ///
  void MinMax( float& min, float& max)
  //
  {
    min = _xmin; 
    max = _xmax;
  }

  /// 
  Point2D<float> Min();
  //

  ///
  void Rescale( float facteur);
  //

  ///
  float Moyenne( float min, float max);
  //

  ///
  float EcartType( float min, float max);
  //

  ///
  float operator()( float x);
  //

}; // Fonction2D


#endif // _FONCTION2D_HPP
