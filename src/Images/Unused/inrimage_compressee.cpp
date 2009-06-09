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
 * $Log: inrimage_compressee.cpp,v $
 * Revision 1.3  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.2  2004/04/30 20:10:16  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:12:09  karl
 * Sources code
 *
 * Revision 1.7  1998/10/02 20:10:01  kkrissia
 * Creation d'une classe InrImage Template
 *
 */

//  Fichier inrimage2.cpp
// 
// Creation d'une classe InrImage permettant de
// manipuler les images dans le format inrimage
//
// Version sans la librairie epidaure
//
// Karl KRISSIAN	Sophia Antipolis, le 08-12-96
//

#include "style.hpp"

#include "inrimage_compressee.hpp"

/*
static int TailleFormat[NB_FORMATS] = { 1,   // WT_UNSIGNED_CHAR
                                           2,   // WT_UNSIGNED_SHORT
                                           2,   // WT_SIGNED_SHORT
                                           4,   // WT_UNSIGNED_INT
                                           4,   // WT_SIGNED_INT
                                           8,   // WT_UNSIGNED_LONG
                                           8,   // WT_SIGNED_LONG
                                           4,   // WT_FLOAT
                                           8,   // WT_DOUBLE
					   1,   // WT_RGB
					   1   // WT_FLOAT_VECTOR
};
*/

//==========================================================================
// FUNCTIONS
//==========================================================================


//----------------------------------------------------------
void InitMasque( InrImage* image_mask, InrImage*& image_mask2, long& nbpoints)
//   ----------
{

//  cout << " Initialisation du masque \n"; 

  image_mask2 = new InrImage( WT_SIGNED_INT, "mask2", image_mask);

  nbpoints = 0;
  image_mask ->InitBuffer();
  image_mask2->InitBuffer();
  Repeter

    Si image_mask->ValeurBuffer() > 127 Alors
       nbpoints++;
      image_mask2->FixeValeur( nbpoints);
    Sinon
      image_mask2->FixeValeur( 0);
    FinSi

    image_mask2->IncBuffer();
  JusquA Non(image_mask->IncBuffer()) FinRepeter

  //  cout << " Nb Points " << nbpoints << endl;
  
} // InitMasque()



//==========================================================================
// MEMBRES PRIVES
//==========================================================================



//--------------------------------------------------------------------------
unsigned char InrImageCompressee :: Alloue( )
//                           ------ 
{

  


  printf("allocation de %s \t taille = %d \n", (char*) _nom, 
         _nb_points*TailleFormat[_format]*_vdim);

  SelonQue (WORDTYPE) _format Vaut

  //    Valeur WT_DOUBLE:        
  //   Valeur WT_UNSIGNED_CHAR: 
  //  Valeur WT_UNSIGNED_SHORT:
  //  Valeur WT_SIGNED_SHORT:  
  //  Valeur WT_SIGNED_INT:  

    Valeur WT_FLOAT:         
      _valeurs_FLOAT = new FORMAT_FLOAT[_nb_points+1];
      _valeurs_FLOAT[0] = 0;
    FinValeur

  //  Valeur WT_RGB:

    Valeur WT_FLOAT_VECTOR:
      _valeurs_FLOAT_VECTOR = new FORMAT_FLOAT_VECTOR[3*(_nb_points+1)];
      _valeurs_FLOAT_VECTOR[0] =
      _valeurs_FLOAT_VECTOR[1] =
      _valeurs_FLOAT_VECTOR[2] = 0.0;
    FinValeur

    default:
	break;

  FinSelonQue

    _amimage = (amimage*) (*_masque_positions);
  _amimage_allocated = false;

    //  _inrimage = (inrimage*) (*_masque_positions);

    //  _inrimage_allouee = true;

  return true;

} // Alloue()


//--------------------------------------------------------------------------
unsigned char InrImageCompressee :: Desalloue( )
//                         ---------       
{

  printf("liberation de %s \n", (char*) _nom);

  SelonQue (WORDTYPE) _format Vaut

  //    Valeur WT_DOUBLE:        
  //   Valeur WT_UNSIGNED_CHAR: 
  //  Valeur WT_UNSIGNED_SHORT:
  //  Valeur WT_SIGNED_SHORT:  
  //  Valeur WT_SIGNED_INT:  
  //  Valeur WT_RGB:

    Valeur WT_FLOAT:         delete [] _valeurs_FLOAT;         FinValeur
    Valeur WT_FLOAT_VECTOR:  delete [] _valeurs_FLOAT_VECTOR;  FinValeur
    Defaut:
    fprintf(stderr,"inrimage_compressee, only FLOAT and FLOAT_VECTOR available\n");

  FinSelonQue

  _amimage_allocated = false;
//  _inrimage_allouee = false;

  return true;

} // Desalloue()


//--------------------------------------------------------------------------
unsigned char InrImageCompressee :: InitPositions( )
//                         -----------
{

  _positions_SIGNED_INT = _masque_positions->GetSignedIntPos();

  return 1;
  
} // InitPositions()


//==========================================================================
// MEMBRES PUBLICS
//==========================================================================



//--------------------------------------------------------------------------
// Defaut  char* nom=NULL
//
InrImageCompressee :: Constructeur InrImageCompressee(  WORDTYPE format, 
//                                 --------  
					      char* nom, InrImage* image, 
					      int nb_points)
{


  _masque_positions = image;

  Si nom == NULL Alors
    _nom = "sans_nom.inr";
  Sinon
    _nom = nom;
  FinSi

  Si image->_format != WT_SIGNED_INT Alors
    cerr << " ImrImageCompressee " << nom 
         << " le masque n'est pas au bon format \n";
  FinSi

  _tx = image->_tx;
  _ty = image->_ty;
  _tz = image->_tz;
  _txy = _tx*_ty;
  _taille = (unsigned long) _tx * _ty * _tz;
 
  _size_x = image->_size_x;
  _size_y = image->_size_y;
  _size_z = image->_size_z;

  _format = (WORDTYPE) format;

  _nb_points = nb_points;
  Alloue();

  InitPositions();


} // Construteur


//--------------------------------------------------------------------------
InrImageCompressee :: Destructeur InrImageCompressee()
//                    -----------
{

  Si _amimage_allocated AlorsFait Desalloue();

} // Destructeur


//----------------------------------------------------------------
void InrImageCompressee :: InitImage( double val)
//                         ---------
{

  InitBuffer();
  Repeter
    FixeValeur( val);
  JusquA Non(IncBuffer()) FinRepeter
  
} // InitImage()


//----------------------------------------------------------------
unsigned char InrImageCompressee :: operator=(InrImage& im)
//                            ---------
{

  Si (_tx != im._tx) Ou (_ty != im._ty) Ou (_tz != im._tz) Alors
    return false;
  FinSi

  InitBuffer();
  im.InitBuffer();
  Repeter
    FixeValeur( im.ValeurBuffer());
    im.IncBuffer();
  JusquA Non(IncBuffer()) FinRepeter

  return true;
  
} // InitImage()


//----------------------------------------------------------------
// Initialisation du buffer correspondant au type de l'image
// a la position souhait�
// Defaut int pos = 0
void InrImageCompressee :: InitBuffer( int pos )
//                         ---------
{

  _pos_buf = pos;
  _buffer_SIGNED_INT    = (FORMAT_SIGNED_INT*)  _amimage->data + pos;  

} // InitBuffer()







//--------------------------------------------------------------------------------------
Chaine* InrImageCompressee :: MessageErreur()
//                            -------------
{

  return &_message_erreur;

} // MessageErreur()
