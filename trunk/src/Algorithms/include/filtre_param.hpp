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
//  filtre_param.hpp
//
//
//


#ifndef _FILTRE_PARAM_HPP
#define _FILTRE_PARAM_HPP

#include "style.hpp"

typedef 
/** @name type_filtre
 */
enum type_filtre 
{
  ///
 UNKNOWN = 0,
  ///
 FILTRE_MOYEN = 1,
  ///
 FILTRE_MEDIAN, 
  ///
 FILTRE_ECART_TYPE,
 ///
 FILTRE_GAUSSIEN
} type_filtre;


/// 
class ParamFiltrage
//     -------------
{

public:

/** @name fenetre (2*_nx+1) * (2*_ny+1) * (2*_nz+1)
 */
//@{
  ///
  int     _nx;
  ///
  int     _ny;
  ///
  int     _nz;        
//@}

//@{
  ///
  float     _sigmax;
  ///
  float     _sigmay;
  ///
  float     _sigmaz;        
//@}

  ///
  type_filtre     _type_filtre;

  ///
   ParamFiltrage( type_filtre type=FILTRE_GAUSSIEN) 
  //           -------------
  {
     InitDefauts(); 
     _type_filtre = type;
  }
  

  ///
  ~ ParamFiltrage() {}
  //           -------------

  ///
  void InitDefauts() 
  //   -----------
  {
    _nx = _ny = _nz = 0;
    _type_filtre = UNKNOWN;
  }

}; // ParamFiltrage

#endif // _FILTRE_PARAM_HPP
