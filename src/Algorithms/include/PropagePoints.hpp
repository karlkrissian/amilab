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
 * $Log: PropagePoints.hpp,v $
 * Revision 1.2  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:10:16  karl
 * Sources code
 *
 * Revision 1.1  1999/05/31 16:25:50  kkrissia
 * *** empty log message ***
 *
 ***************************************************************************/


#ifndef _PROPAGE_POINTS_HPP
#define _PROPAGE_POINTS_HPP


#include "style.hpp"
#include <iosfwd>

#include "CommonConfigure.h"
COMMON_VAR_IMPORT unsigned char GB_debug;
COMMON_VAR_IMPORT unsigned char GB_verbose;

//======================================================================
class PropagePoints
//
{

public:
  /// Exceptions
  class TropDePoints
  //
  {
  public:
    TropDePoints( char* message, int max)
      {
	std::cerr << " PropagePoints Exception\t trop de points" 
             << " max = " << max << std::endl;
        std::cerr << message << std::endl;
      }
  };

private:

  /// position plus ancien point non traite
  long   _depart;

  /// position du dernier point ajoute
  long   _fin;

  /**
       _pos_depart = _depart modulo _taille_max
       _pos_fin    = _fin    modulo _taille_max
   */
  int       _pos_depart,_pos_fin;

  ///
  int   PtsATraiter;
  ///
  int*  posx;
  ///
  int*  posy;
  ///
  int*  posz;
  ///
  unsigned char* point_traite;

  ///
  long _taille_max;

  ///
  void Resize()
  //
  {

    
      int   new_size;
      int*  new_posx;
      int*  new_posy;
      int*  new_posz;
      unsigned char* new_point_traite;
      int   i,j,k;

    std::cout << "Resize() \n";

    new_size = _taille_max * 2;

    new_posx         = new int[new_size];
    new_posy         = new int[new_size];
    new_posz         = new int[new_size];
    new_point_traite = new unsigned char[new_size];

    j = _pos_depart;
    k = 0;
    Pour(i,_depart,_fin)

      new_posx[k] = posx[j];
      new_posy[k] = posy[j];
      new_posz[k] = posz[j];

      new_point_traite[k] = point_traite[j];

      j++;
      Si j>=_taille_max AlorsFait j = 0;

      k++;

    FinPour

    delete[] posx;
    delete[] posy;
    delete[] posz;
    delete[] point_traite;

    posx = new_posx;
    posy = new_posy;
    posz = new_posz;
    point_traite = new_point_traite;

    _fin   = _pos_fin   = _taille_max;
    _depart = _pos_depart = 0;

    _taille_max = new_size;

  } // Resize()


public:
  
  ///
   PropagePoints( int taille_max = 1000)
  //
  {

  
    _taille_max = taille_max;
    posx         = new int [_taille_max];
    posy         = new int [_taille_max];
    posz         = new int [_taille_max];
    point_traite = new unsigned char[_taille_max];

    Si GB_debug AlorsFait
     std::cout << " PropagePoints() constructeur\n";

    PtsATraiter = 0;
    posx[0] = 0;
    posy[0] = 0;
    posz[0] = 0;  
    point_traite[0] = false;  
  
  }; // Constructor

  ///
  ~PropagePoints() 
  //
  {

    delete[] posx;
    delete[] posy;
    delete[] posz;
    delete[] point_traite;

  }


  ///
  void Init( int x, int y, int z)
  //
  {

    PtsATraiter = 1;
    posx[0] = x;
    posy[0] = y;
    posz[0] = z;  
    point_traite[0] = false;  

    _depart = _pos_depart = 0;
    _fin    = _pos_fin    = 0;

  } // Init()
    
  ///
  int PointsATraiter()
  //
  {

    return PtsATraiter;

  } // PointsATraiter()


  ///
  unsigned char ProchainPoint( int& x1, int& y1, int& z1)
  //
  {

    TantQue ((bool)point_traite[_pos_depart] == true) Et (_depart<=_fin) Faire 
      _depart++;
      _pos_depart++;
      Si _pos_depart == _taille_max AlorsFait _pos_depart = 0;
    FinTantQue

    Si _depart > _fin Alors
      std::cerr << " _depart > _fin  \n";
      return false;
    FinSi

    x1 = posx[_pos_depart];
    y1 = posy[_pos_depart];
    z1 = posz[_pos_depart];    

    return true;

  }

  ///
  unsigned char AjoutePoint( int x, int y, int z) throw (TropDePoints)
  //
  {

    _fin++;
    _pos_fin++;
    Si _pos_fin == _taille_max AlorsFait _pos_fin = 0;

    Si  _fin-_depart == _taille_max Alors
     std::cout << "_depart " << _depart << " _fin " << _fin << std::endl;
      Resize();
    FinSi
 
    posx[_pos_fin] = x;
    posy[_pos_fin] = y;
    posz[_pos_fin] = z;
    point_traite[_pos_fin] = false;
    PtsATraiter++;

//    Si (_fin%100 == 0) AlorsFaitstd::cout << "_fin = " << _fin << std::endl;


    return true;

  } // AjoutePoint()


  ///
  void EnlevePointCourant()
  //
  {

    point_traite[_pos_depart]=true;

    _depart++;
    _pos_depart++;
    Si _pos_depart == _taille_max AlorsFait _pos_depart = 0;

    PtsATraiter--;

  } // EnlevePointCourant()


}; // PropagePoints


#endif // _PROPAGE_POINTS_HPP
