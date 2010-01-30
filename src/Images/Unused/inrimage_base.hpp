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
 * $Log: inrimage_base.hpp,v $
 * Revision 1.2  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:12:12  karl
 * Sources code
 *
 * Revision 1.2  1998/10/02 20:08:16  kkrissia
 * Creation d'une classe InrImage Template
 *
 ***************************************************************************/

//  Fichier inrimage_base.hpp
// 


#ifndef _INRIMAGE_BASE_HPP
#define _INRIMAGE_BASE_HPP

#include "style.hpp"
#include "chaine.hpp"

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/chaine.doc  /user/jmontagn/src/Zinrimage/*.h

extern "C" {
#include <math.h>
#include "Zinrimage.h"
}

#include "epi_err.hpp"

#define TYPE_MAPLE 0

#define NB_FORMATS 13

static int TailleFormat[NB_FORMATS] = { 1,   // WT_UNSIGNED_CHAR
                                           2,   // WT_UNSIGNED_SHORT
                                           2,   // WT_SIGNED_SHORT
                                           4,   // WT_UNSIGNED_INT
                                           4,   // WT_SIGNED_INT
                                           8,   // WT_UNSIGNED_LONG
                                           8,   // WT_SIGNED_LONG
                                           4,   // WT_FLOAT
                                           8,   // WT_DOUBLE
					   1,   // WT_RGB, vdim = 3
					   1,   // WT_RGBA, vdim = 4
					   4,  // WT_FLOAT_VECTOR
					   8   // WT_DOUBLE_VECTOR
};

static int VectorDim[NB_FORMATS] = { 1,   // WT_UNSIGNED_CHAR
                                        1,   // WT_UNSIGNED_SHORT
                                        1,   // WT_SIGNED_SHORT
                                        1,   // WT_UNSIGNED_INT
                                        1,   // WT_SIGNED_INT
                                        1,   // WT_UNSIGNED_LONG
                                        1,   // WT_SIGNED_LONG
                                        1,   // WT_FLOAT
                                        1,   // WT_DOUBLE
					3,   // WT_RGB
					4,   // WT_RGBA
					3,   // WT_FLOAT_VECTOR
					3    // WT_DOUBLE_VECTOR
};


//=========================================================================


/** 
  class de base contenant des variables et fonctions
  communes a tous les types d'images
*/
class InrImageBase
//     ============
{

protected:
  //
  inrimage*   _inrimage; 
  //
  int     nb_dimensions; // image 1D, 2D, 3D
  //
  long _taille;
  //
  Chaine     _nom;   // nom du fichier sur disque
  //
  Chaine     _message_erreur;
  //
  unsigned char    _inrimage_allouee;


protected:

  // Op�ation d'allocation, de lecture, d'ecriture
  ///
  unsigned char   Read();

  ///
  unsigned char   LitEntete();

  ///
  void      init_from_inrimage(inrimage*);

  ///
  unsigned char   LitMaple( const char* nom );

  ///
  unsigned char   EcritMaple(const char* nom );

  ///
  unsigned char   Alloue();

  ///
  unsigned char   Ecrit();

  ///
  unsigned char   Desalloue();

  /// initialisation du tableau de positions _positions[z][y]
  virtual unsigned char   InitPositions() = 0;

  /// initialisation du tableau de positions _positions[z][y]
  virtual unsigned char   EffacePositions() = 0;

  ///
  WORDTYPE  ZimageFormat( int format);

public:

/**@name 1-variables public */
//@{
  /** @name dimensions de l'image */
  //@{

    ///
    int     _tx;

    ///
    int     _ty;

    ///
    int     _tz;

    ///
    int     _vdim;

  //@}

  /** @name dimensions d'un voxel */
  //@{

    ///
    float       _size_x;

    ///
    float       _size_y;

    ///
    float       _size_z; 
  //@}

  ///
  int     _txy;               


  /// format
  WORDTYPE     _format;
//@}


  /** @name 2-Diff�ents constructeurs  et le destructeur */
  //@{
     InrImageBase( ) {}

     InrImageBase( const char* nom);

    // Pour des fichier d'un autre format
     InrImageBase( const char* nom, int type);

     InrImageBase( int dimx, 
			       int dimy, 
			       int dimz, 
			       const char* nom=NULL);

    virtual ~ InrImageBase();
  //@}

  ///
  void SetVoxelSize( float sx, float sy, float sz);
  //   ------------------

  ///
  virtual WORDTYPE GetFormat() { return _format; }
  //               ---------

  /** @name 3-Acc� aux champs de la classe */
  //@{
    /** 
      @return pointeur sur les donnees
    */
    void*     Buffer()  { return _inrimage->data; }
    //        ------

    ///
    void      FixeBuffer( void* buf)  { _inrimage->data = (char*) buf; }
    //        ----------

    ///
    char*    Nom() { return _nom;}
    //            ---

  //@}

  /** @name 4-M�hode li�s �la gestion du buffer */
  //@{
    /** Op�ation de parcours de buffer inter-formats
     */
    virtual void InitBuffer( int pos = 0) = 0;
    //           ----------

    //  
    virtual void BufferPos( int x, int y, int z) = 0;
    //           ---------

    /**
       Fonction en ligne
       Incr�entation du buffer
    */
    virtual void IncBuffer( int inc=1) = 0;
    //           ---------

    /**
       Renvoie la valeur de l'image �la position courante du buffer
    */
    virtual double ValeurBuffer( ) = 0;
    //                 ------------

    //
    virtual double ValeurBuffer( int inc) = 0;
    //                 ------------
    // Renvoie la valeur du buffer+inc

    /**
      Renvoie la valeur du buffer pour la coordonnee i (0:x, 1:y, 2:z)
    */
    virtual double VectValeurBuffer( int i ) = 0;
    //                 ----------------


    /// Fixe la valeur de l'image au point courant du buffer
    virtual void FixeValeur( double val) = 0;
    //           ----------

    /// Fixe la valeur de l'image au point courant du buffer
    virtual void VectFixeValeurs( double valx, 
    //           ---------------
				  double valy, 
				  double valz) = 0;

  //@}


  /** @name 5- Lecture-Ecriture, Sauvegarde de l'image */
  //@{

    ///
    unsigned char Sauve( const char* nom = NULL);
    //      -----

    ///
    Chaine* MessageErreur() { return &_message_erreur; }
    //      -------------

  //@}


  /** @name 6-Red�initions d'op�ateurs */
  //@{
    // 
    operator inrimage() { return( *_inrimage); }
    //       --------

    //  {\bf Operator(x,y,z) }
    virtual double operator()( int x, int y, int z) = 0;
    //                 --------

    //  {\em Operator(x,y,z,coord) }
    virtual double operator()( int x, int y, int z, 
    //                 --------
				   int coord) = 0;

  //@}


  /** @name 7-M�hodes plus �olu�s */
  //@{

  //
  virtual InrImageBase* CreeSousImage( int min_x, int max_x, 
				       int min_y, int max_y,
				       int min_z, int max_z) = 0;

  //
  virtual void MinMax(float* min, float* max) = 0;

  // Interpolation Lin�ire de l'intensit�au point (x,y,z)
  virtual double InterpLinIntensite2( float dx1, float dx2, 
  //                 -------------------
					  int tx1, int tx2) = 0;

  /** Interpolation Lin�ire de l'intensit�au point (x,y,z)
   en coordonn�s r�lles
   Prendre en compte la taille des voxels ???
   Pour une image 3D ...
  */
  virtual double InterpLinIntensite( float x, float y, float z) = 0;
  //                 ------------------

  //
  virtual void VoisinageYZ( int x, int y, int z, float** vois) = 0;
  //           -----------

  //@}

}; // InrImageBase

#endif // _INRIMAGE_BASE_HPP
