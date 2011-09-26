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
 * $Log: gnuplot.hpp,v $
 * Revision 1.3  2005/11/16 14:03:08  karl
 * added LGPL license
 *
 * Revision 1.2  2005/09/28 17:30:25  karl
 * adding title
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:09:49  karl
 * Sources code
 *
 *
 ***************************************************************************/


#ifndef _GNUPLOT_HPP
#define _GNUPLOT_HPP

#include "style.hpp"
extern "C" {
#include <stdlib.h>
}
#include <stdio.h>
#include "chaine.hpp"

#define TYPE_GNUPLOT 0
#define TYPE_SECTION 1

// using -- namespace std;

///----------------------------------------------------------------------
class GnuPlot
//
{ 

public:

  /// Exceptions
  class ErreurLecture
  {
  public:
    ErreurLecture( Chaine message)
      {
	std::cerr << "GnuPlot Erreur de Lecture " << message << std::endl;
      }
  };

private:

  ///
  int*  _nb_points;

  ///
  float    _xmin;
  ///
  float    _xmax;
  ///
  float    _ymin;
  ///
  float    _ymax;

  ///
  float    _xtics;
  ///
  float    _ytics;

  ///
  unsigned char _grid;

  ///
  unsigned char _auto_sup;

  ///
  unsigned char _auto_inf;

  ///
  float**   _tabx;
  ///
  float**   _taby;

  ///
  int   _nb_courbes;
  ///
  int   _nb_courbes_max;

  /// nom du fichier pour la sauvegarde des donnees
  Chaine*          _nom_donnees;

  Chaine*          _titles;

  ///
  FILE*            fic_script;
  ///
  Chaine           nom_script;

  ///
  Chaine           size;

public:

  ///
   GnuPlot( );
  //

  ///
  ~GnuPlot();
  //
   
  ///
  int AddCourbe( int nb_points, float* tabx, float* taby, Chaine nom, Chaine title="");
  //

  ///
  int ReadData( Chaine nom_donnees, Chaine title="") throw ( ErreurLecture);
  //

  void SetSize(Chaine s) { size = s; }


  ///
  void SaveData( int num_courbe, int type=TYPE_GNUPLOT);
  //
 
  ///
  void LimitesInf( float xmin, float ymin)
  //
  {

  //  printf("gnuplot::LimitesInf() \n");

    _xmin = xmin;
    _ymin = ymin;

    _auto_inf = false;

  } // LimitesInf()


  ///
  void LimitesSup( float xmax, float ymax)
  //
  {

    _xmax = xmax;
    _ymax = ymax;

    _auto_sup = false;

  } // LimitesInf()


  ///
  void SetTics( float xtics, float ytics)
  ///
  {

    _xtics = xtics;
    _ytics = ytics;

  } // SetTics()

  ///
  void SetGrid( unsigned char grid)
  //
  {

    _grid = grid;

  } // SetGrid()


  ///
  void XPlot( Chaine nom, int pause=2);
  //

  ///
  void PSPlot( Chaine nom);
  //

}; // GnuPlot


#endif // _GNUPLOT_HPP
