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
 * $Log: inrimage_all.hpp,v $
 * Revision 1.3  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.2  2004/09/21 16:12:41  karl
 * fixing gcc compiling pb and filtering default options
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.2  2000/09/19 12:19:09  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:12:12  karl
 * Sources code
 *
 * Revision 1.2  1998/10/02 20:08:16  kkrissia
 * Creation d'une classe InrImage Template
 *
 ***************************************************************************/

//  Fichier inrimage_all.hpp
// 


#ifndef _INRIMAGE_ALL_HPP
#define _INRIMAGE_ALL_HPP

#include "style.hpp"
#include "chaine.hpp"

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/chaine.doc  /user/jmontagn/src/Zinrimage/*.h

#include "inrimage_base.hpp"
#include "inrimage_template.hpp"
#include "inrimage_vect_template.hpp"

/*
//-----------------------------------------------------------------------
WORDTYPE InrImageTemplate<unsigned char>::GetFormat() 
{ return WT_UNSIGNED_CHAR; }

//-----------------------------------------------------------------------
WORDTYPE InrImageTemplate<unsigned short>::GetFormat() 
{ return WT_UNSIGNED_SHORT; }

//-----------------------------------------------------------------------
WORDTYPE InrImageTemplate<signed short>::GetFormat() 
{ return WT_SIGNED_SHORT; }

//-----------------------------------------------------------------------
WORDTYPE InrImageTemplate<unsigned int>::GetFormat() 
{ return WT_UNSIGNED_INT; }

//-----------------------------------------------------------------------
WORDTYPE InrImageTemplate<signed int>::GetFormat() 
{ return WT_SIGNED_INT; }

//-----------------------------------------------------------------------
WORDTYPE InrImageTemplate<unsigned long>::GetFormat() 
{ return WT_UNSIGNED_LONG; }

//-----------------------------------------------------------------------
WORDTYPE InrImageTemplate<signed long>::GetFormat() 
{ return WT_SIGNED_LONG; }

//-----------------------------------------------------------------------
WORDTYPE InrImageTemplate<float>::GetFormat() 
{ return WT_FLOAT; }

//-----------------------------------------------------------------------
WORDTYPE InrImageTemplate<double>::GetFormat() 
{ return WT_DOUBLE; }


//-----------------------------------------------------------------------
//  Images de Vecteurs
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
WORDTYPE InrImageVectTemplate<unsigned char>::GetFormat() 
{ return WT_RGB; }

//-----------------------------------------------------------------------
WORDTYPE InrImageVectTemplate<float>::GetFormat() 
{ return WT_FLOAT_VECTOR; }

//-----------------------------------------------------------------------
WORDTYPE InrImageVectTemplate<double>::GetFormat() 
{ return WT_DOUBLE_VECTOR; }
*/

//------------------------------------------------------------
extern InrImageBase* new_image( char* nom);

//------------------------------------------------------------
extern void delete_image( InrImageBase* image);


#endif // _INRIMAGE_ALL_HPP
