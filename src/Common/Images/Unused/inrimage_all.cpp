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
 * $Log: inrimage_all.cpp,v $
 * Revision 1.2  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:12:08  karl
 * Sources code
 *
 * Revision 1.2  1998/10/02 20:10:01  kkrissia
 * Creation d'une classe InrImage Template
 *
 ***************************************************************************/

//  Fichier inrimage_all.cpp
// 



#include "style.hpp"
#include "chaine.hpp"

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/chaine.doc  /user/jmontagn/src/Zinrimage/*.h

#include "inrimage_all.hpp"



//------------------------------------------------------------
//
//------------------------------------------------------------
InrImageBase* new_image( char* nom)
{
  INRIMAGE_HEADER* ptr;
  inrimage*        ptr_image;

 std::cout << "lecture de l'ent�e de " << nom << std::endl;

  Si (strcmp(nom,"-")==0) Alors
    // entree standard
   std::cout << "InrImage::LitEntete()\t on ne lit pas que "
	 << "l'entete sur l'entree standard\n";
    ptr_image = readZInrimage( NULL);
  Sinon
    ptr = readZInrimageHeader( (char*) nom);
    ptr_image = ptr->inr;
  FinSi

  Si ptr_image == NULL Alors
    E_SETERR(E_ERRR, "reading in file", (char*) nom);
    return false;
  FinSi

  Si (strcmp(nom,"-")==0) Alors
    switch ( ptr_image->type ){
      case WT_UNSIGNED_CHAR :
        return new InrImageTemplate<unsigned char> (ptr_image);
      case WT_UNSIGNED_SHORT:
        return new InrImageTemplate<unsigned short>(ptr_image);
      case WT_SIGNED_SHORT  :
        return new InrImageTemplate<signed short>  (ptr_image);
      
      case WT_UNSIGNED_INT  :
        return new InrImageTemplate<unsigned int>  (ptr_image);
      case WT_SIGNED_INT    :
        return new InrImageTemplate<signed int>    (ptr_image);
      case WT_UNSIGNED_LONG :
        return new InrImageTemplate<unsigned long> (ptr_image);
      case WT_SIGNED_LONG   :
        return new InrImageTemplate<signed long>   (ptr_image);
      
      case WT_FLOAT         :
        return new InrImageTemplate<float>         (ptr_image);
      
      case WT_DOUBLE        :
        return new InrImageTemplate<double>        (ptr_image);


      //------------------------
      // Images de Vecteurs
      //------------------------

      case WT_RGB           :
        return new InrImageVectTemplate<unsigned char> (ptr_image);
      case WT_FLOAT_VECTOR  :
        return new InrImageVectTemplate<float>         (ptr_image);
      case WT_DOUBLE_VECTOR  :
        return new InrImageVectTemplate<double>        (ptr_image);
      default:
	break;

    } // end switch

  Sinon

    switch ( ptr_image->type ){
      case WT_UNSIGNED_CHAR :
        return new InrImageTemplate<unsigned char> (nom);
      case WT_UNSIGNED_SHORT:
        return new InrImageTemplate<unsigned short>(nom);
      case WT_SIGNED_SHORT  :
        return new InrImageTemplate<signed short>  (nom);

      case WT_UNSIGNED_INT  :
        return new InrImageTemplate<unsigned int>  (nom);
      case WT_SIGNED_INT    :
        return new InrImageTemplate<signed int>    (nom);
      case WT_UNSIGNED_LONG :
        return new InrImageTemplate<unsigned long> (nom);
      case WT_SIGNED_LONG   :
        return new InrImageTemplate<signed long>   (nom);

      case WT_FLOAT         :
        return new InrImageTemplate<float>         (nom);

      case WT_DOUBLE        :
        return new InrImageTemplate<double>        (nom);

      //------------------------
      // Images de Vecteurs
      //------------------------

      case WT_RGB           :
        return new InrImageVectTemplate<unsigned char> (nom);
      case WT_FLOAT_VECTOR  :
        return new InrImageVectTemplate<float>         (nom);
      case WT_DOUBLE_VECTOR  :
        return new InrImageVectTemplate<double>        (nom);

    } // end switch

  FinSi

  return NULL;

} // new_image()


//------------------------------------------------------------
void delete_image( InrImageBase* image)
{
  Si (strcmp(image->GetName(),"-")==0) Alors
    printf("liberation de %s \n", image->GetName() );
    freeInrimage( (inrimage*) image );
  FinSi

  delete image;

} // delete_image()


