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
 * $Log: inrimage_vect_template.hpp,v $
 * Revision 1.3  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.2  2004/09/21 16:12:41  karl
 * fixing gcc compiling pb and filtering default options
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:12:12  karl
 * Sources code
 *
 * Revision 1.2  1998/10/02 20:08:17  kkrissia
 * Creation d'une classe InrImage Template
 *
 ***************************************************************************/

//  Fichier inrimage_vect_template.hpp
// 


#ifndef _INRIMAGE_VECT_TEMPLATE_HPP
#define _INRIMAGE_VECT_TEMPLATE_HPP

#include "style.hpp"
#include "chaine.hpp"

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/chaine.doc  /user/jmontagn/src/Zinrimage/*.h

#include "inrimage_template.hpp"


//=========================================================================


/** 
  class de template contenant des variables et fonctions
  communes a tous les types d'images
*/
template <typename T>
class InrImageVectTemplate : public InrImageTemplate<T>
//     ====================
{

public:

  /** @name 2-Diff�rents constructeurs  et le destructeur */
  //@{
    ///
     InrImageVectTemplate( const char* nom)
      : InrImageTemplate<T>(nom)  {    }

    /// Pour des fichier d'un autre format
     InrImageVectTemplate( const char* nom, int type)
      : InrImageTemplate<T>(nom, type) {  }

    ///
     InrImageVectTemplate( inrimage* image, 
				       const char* nom="sansnom.inr")
      : InrImageTemplate<T>( image, nom) {  }
 
    ///
     InrImageVectTemplate( int dimx, 
				   int dimy, 
				   int dimz, const char* nom=NULL)
    {
      Si nom == NULL Alors
        this->_nom = "sans_nom.inr";
      Sinon
        this->_nom = nom;
      FinSi
      this->_tx = dimx;
      this->_ty = dimy;
      this->_tz = dimz;
      this->_txy = this->_tx*this->_ty;
      this->_size_x = this->_size_y = this->_size_z = 1;

      this->_format = GetFormat();
      this->_vdim   = VectorDim[this->_format];
     std::cout << TailleFormat[this->_format] << std::endl;
     std::cout << this->_vdim << std::endl;
     std::cout << sizeof(T) << std::endl;
      Si sizeof(T)*this->_vdim != TailleFormat[this->_format]*this->_vdim Alors
       std::cout << "probleme entre le format et le type donne...\n";
      FinSi
      this->Alloue();
      this->InitPositions();    
     }

    ///
    ~InrImageVectTemplate( ) {}

  //@}

  virtual WORDTYPE GetFormat();// { return _format;}

  /** @name 4-M�thode li�es � la gestion du buffer */
  //@{
    /** Op�ration de parcours de buffer inter-formats
     */
    void InitBuffer( int pos = 0);
    //   ----------

    ///  
    void BufferPos( int x, int y, int z);
    //   ---------

    /**
       Fonction en ligne
       Incr�mentation du buffer
    */
    void IncBuffer( int inc=1);
    //   ---------

    /**
      Renvoie la valeur du buffer pour la coordonnee i (0:x, 1:y, 2:z)
    */
    double VectValeurBuffer( int i );
    //         ----------------


    /// Fixe la valeur de l'image au point courant du buffer
    void VectFixeValeurs( double valx, 
    //   ---------------
			  double valy, 
			  double valz);

  //@}



  /** @name 6-Red�finitions d'op�rateurs */
  //@{

    //  {\bf Operator(x,y,z) }
    double operator()( int x, int y, int z);
    //         --------
    //  {\em Operator(x,y,z,coord) }
    double operator()( int x, int y, int z, int coord);
    //         --------

  //@}


}; // InrImageVectTemplate


//=======================================================================================
// Definition des methodes publiques
//=======================================================================================


//-----------------------------------------------------------------------
// Fonction li�es au buffer
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
template <class T>
inline void InrImageVectTemplate<T>::InitBuffer( int pos )
{
  this->_buffer = (T*) this->_inrimage->data + this->_vdim*pos;  
}

//-----------------------------------------------------------------------
template <class T>
inline void InrImageVectTemplate<T>::BufferPos( int x, int y, int z)
{
  this->_buffer = (this->_positions[z][y] + this->_vdim*x); 
}

//-----------------------------------------------------------------------
template <class T>
inline void InrImageVectTemplate<T>::IncBuffer( int inc)
{
  this->_buffer += this->_vdim*inc;
}

//-----------------------------------------------------------------------
template <class T>
inline double InrImageVectTemplate<T>::VectValeurBuffer( int i )
{
  return (double) this->_buffer[i];
}

//-----------------------------------------------------------------------
template <class T>
inline void InrImageVectTemplate<T>::VectFixeValeurs( double valx, 
					   double valy, 
					   double valz)
{
  this->_buffer[0]   = (T)  valx;
  this->_buffer[1]   = (T)  valy;
  this->_buffer[2]   = (T)  valz;
}

//-----------------------------------------------------------------------
// Red�finitions d'op�rateurs
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
template <class T>
inline double InrImageVectTemplate<T>::operator()( int x, int y, int z)
{
   return (double)(this->_positions[z][y][x]);
}
 
//-----------------------------------------------------------------------
template <class T>
inline double InrImageVectTemplate<T>::operator()( int x, int y, int z, 
					       int coord)
{
  return (double)(this->_positions[z][y][this->_vdim*x+coord]);
}


#endif // _INRIMAGE_VECT_TEMPLATE_HPP
