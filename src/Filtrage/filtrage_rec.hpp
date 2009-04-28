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
 * $Log: filtrage_rec.hpp,v $
 * Revision 1.2  2005/11/16 14:03:08  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1  2000/10/02 17:03:30  karl
 * *** empty log message ***
 *
 * 
 */

#ifndef _FILTRAGE_REC_HPP
#define _FILTRAGE_REC_HPP


#include "style.hpp"
#include "inrimage.hpp"



//======================================================================
class FiltrageRec
//     ===========
{

private:

  int     tx,ty,tz;
  int     txy;
  int     pas_x,pas_y,pas_z;
  InrImage*  _image;

  //--------------------------------------------------
  void FiltreRecX( float* entree, double mu, double lambda);
  //   ----------

  //--------------------------------------------------
  void FiltreRecY( float* entree, double mu, double lambda);
  //   ----------

  //--------------------------------------------------
  void FiltreRecZ( float* entree, double mu, double lambda);
  //   ----------

public:

  //--------------------------------------------------
  Constructeur FiltrageRec(InrImage* im)
  {
    tx = im->_tx;
    ty = im->_ty;
    tz = im->_tz;
    
    pas_x = 1;
    pas_y = tx;
    pas_z = txy = tx*ty;

    _image = im;
  }


  //--------------------------------------------------
  void Filtre(  float sigma, int nb_iter);
  //   ------

}; // FiltrageRec


#endif // _FILTRAGE_REC_HPP
