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
 * $Revision: 1.14 $
 * $Log: inrimage.hpp,v $
 * Revision 1.14  2006/02/21 18:26:18  karl
 * many changes
 *
 * Revision 1.13  2006/01/17 17:39:23  karl
 * Improving video for Fluid project
 *
 * Revision 1.12  2005/12/19 19:41:34  karl
 * Fluid project visualization
 *
 * Revision 1.11  2005/11/16 17:46:36  karl
 * fixed pbs
 *
 * Revision 1.10  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.9  2005/11/08 15:15:00  karl
 * last changes, allowing to disable libmagick library
 *
 * Revision 1.8  2005/11/08 15:09:19  karl
 * last changes, allowing to disable libmagick library
 *
 * Revision 1.7  2005/10/04 23:11:56  karl
 * fixes in SRAD and AnisoGS
 *
 * Revision 1.6  2005/02/12 01:36:19  karl
 * improved EstimeRayons
 *
 * Revision 1.5  2004/08/25 22:37:38  karl
 * displaying vector field from amilab + read vtk vector field
 *
 * Revision 1.4  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.3  2004/04/30 20:10:16  karl
 * several improcements
 *
 * Revision 1.2  2004/02/17 23:34:04  karl
 * add Derivatives function, Get/Set image name
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2003/08/14 07:16:05  karl
 * Source code
 *
 * Revision 1.4  2001/03/02 11:49:33  karl
 * *** empty log message ***
 *
 * Revision 1.3  2000/11/08 16:23:21  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/19 12:19:09  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:12:10  karl
 * Sources code
 *
 * Revision 1.6  1998/10/02 20:08:15  kkrissia
 * Creation d'une classe InrImage Template
 *
 ***************************************************************************/
//  Fichier inrimage2.hpp
//
// Creation d'une classe InrImage permettant de
// manipuler les images dans le format inrimage
//
// Version sans la librairie epidaure
//
// Karl KRISSIAN    Sophia Antipolis, le 30-05-96
//

// Ce qui peut etre interessant :
//
// 1. definition d'une region d'interet :
//    i.e. d'un tableau de booleen


// 2. Gerer les affichages Maple a l'aide
//    d'une classe speciale
//


// 3. Penser a la gestion des erreurs ...
//
//


// Creer des operations independantes du type de l'image
//

// Operation de conversion de types
//


#ifndef _INRIMAGE_HPP
#define _INRIMAGE_HPP


#include <boost/shared_ptr.hpp>

#ifdef _MSC_VER
  #pragma warning( disable : 4290 )
#endif

#ifndef _WITHOUT_VTK_
// avoiding including vtk files for faster compilation ...
class vtkImageData;
typedef boost::shared_ptr<vtkImageData>  vtkImageData_ptr;
#endif // _WITHOUT_VTK_

/*
#ifndef _WITHOUT_VTK_
#include "vtkImageData.h"
#include "vtk_common.h"
#endif // _WITHOUT_VTK_
*/

#include "style.hpp"
//#include "chaine.hpp"
#include "DefineClass.hpp"

#if defined(_MSC_VER) 
//|| defined(__MINGW32__)
int   rint(const float& a);
float roundf(const float& a);
#endif

//#include "Coordonnees.hpp"

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/chaine.doc  /user/jmontagn/src/Zinrimage/*.h

#include "AMILabConfig.h"
#include "CommonConfigure.h"

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif

#include "ImagePositionsBase.h"
#include "InrImageIteratorBase.h"

#include "ImageLinearInterpolator.h"

#include <math.h>

// for memcpy
#include <string.h>

// taken from Zinrimage.h
typedef enum {
  WT_UNSIGNED_CHAR,  /* Unsigned 8 bits */
  WT_UNSIGNED_SHORT, /* Unsigned 16 bits */
  WT_SIGNED_SHORT,   /* Signed 16 bits */
  WT_UNSIGNED_INT,   /* Unsigned 32 bits */
  WT_SIGNED_INT,     /* Signed 32 bits */
  WT_UNSIGNED_LONG,  /* Unsigned 64 bits */
  WT_SIGNED_LONG,    /* Signed 64 bits */
  WT_FLOAT,          /* Float 32 bits */
  WT_DOUBLE,         /* Float 64 bits */
  WT_RGB,            /* R, G, B, 8 bits each */
  WT_RGBA,           /* R, G, B, A, 8 bits each */
  WT_FLOAT_VECTOR,   /* Vector of 32 bit floats */
  WT_DOUBLE_VECTOR,   /* Vector of 64 bit floats */
  WT_UNKOWN_TYPE,
} WORDTYPE;
/* The different size of words for a 3D image */


#include "amimage.hpp"

#define NB_FORMATS 13

#if defined(_MSC_VER) || defined(__MINGW32__)
inline double round( double d )
{
return floor( d + 0.5 );
}
#endif

//#include "epi_err.hpp"

/*
   \begin{center}
   {\bf MACROS: Diff�ents formats}\\
   \begin{tabular}{lll}
   {\bf FORMAT_UNSIGNED_CHAR}  &  unsigned char       &  1 byte  \\
   {\bf FORMAT_UNSIGNED_SHORT} &  unsigned short int  &  2 bytes \\
   {\bf FORMAT_SIGNED_SHORT}   &  short int           &  2 bytes \\
   {\bf FORMAT_SIGNED_INT}     &  signed int          &  4 bytes \\
   {\bf FORMAT_FLOAT}          &  float               &  4 bytes \\
   {\bf FORMAT_DOUBLE}         &  double              &  8 bytes \\
   {\bf FORMAT_RGB}            &  RGB                 &  3x1 bytes vdim = 3 \\
   {\bf FORMAT_FLOAT_VECTOR}   &  float               &  3x4 bytes vdim = 3 \\
   \end{tabular}
   \end{center}
*/

//=========================================================================
//  DEFINE
//

/**  @name Formats
*/
//@{
/// format unsigned char 1 byte
#define FORMAT_UNSIGNED_CHAR    unsigned char

/// 2 bytes
#define FORMAT_UNSIGNED_SHORT   unsigned short int

/// 2 bytes
#define FORMAT_SIGNED_SHORT     short int

/// 4 bytes
#define FORMAT_UNSIGNED_INT     unsigned int

/// 4 bytes
#define FORMAT_SIGNED_INT       int

/// 4 bytes
#define FORMAT_FLOAT            float

/// 8 bytes
#define FORMAT_DOUBLE           double

/// 3x1 bytes vdim = 3
#define FORMAT_RGB              unsigned char

/// 3x8 bytes vdim = 2,3,etc...
#define FORMAT_FLOAT_VECTOR     float

/// 6x8 bytes vdim = 6
#define FORMAT_3DSYMMAT         float
//@}

#define TYPE_MAPLE 0

// disable the magick library
#ifdef USE_MAGICK
//#undefine USE_MAGICK
#endif

#ifdef USE_MAGICK
// Uses ImageMagick to write several image formats
//
int IM_WriteImage ( const char *name,
            const float *r,
            const float *g,
            const float *b,
            const unsigned int w, const unsigned int h  );
#endif // USE_MAGICK





/**
 Image Class, not templated
 */
class COMMON_EXPORT InrImage
//                  ========
{

  DEFINE_CLASS(InrImage);

public:
  /// Exceptions
  //@{
    class ErreurLecture
    {
    };

    class ErreurAllocation
    {
    };

    class ImageWriteError
    {
    };

    class DepassementLimites
    {
    public:
        DepassementLimites( const std::string message);
/*
     {
       std::cout << "InrImage "
                << " Out of image limits"
            << "\t " << message  << std::endl;
     }
*/
    };
  //@}

protected:

   static int TailleFormat[NB_FORMATS];


  ///
    //  inrimage*   _inrimage;

  /// pointer to the data
  boost::shared_ptr<amimage>           _amimage;
  //unsigned char    _amimage_allocated;

  ///
  int     _vdim; // image scalar (1), vectorial (2,3,etc...)


  ///
  long _taille;
  ///
  long _pos_buf;

  ///
  std::string     _nom;   // nom du fichier sur disque

  ///
  std::string     _message_erreur;

  ///
  //  unsigned char    _inrimage_allouee;

  ///
  unsigned char    _positions_allocated;

  // buffer permettant la gestion d'images

/** @name Buffers for the different available pixel types */
  InrImageIteratorBase::ptr _Iterator;

  /**
   * Object that allows access to a pixel by indirection,
   * storing the beginning of each line of pixels/voxels.
   **/
  ImagePositionsBase* _positions;

//  ImageLinearInterpolator* test;
  ImageLinearInterpolator::ptr _linear_interpolator;

private:


  ///
  unsigned char   ReadAMI() throw (ErreurLecture);

#ifdef USE_MAGICK
  ///
  unsigned char   ReadMagick() throw (ErreurLecture);
#endif

  ///
  unsigned char   ReadVTK() throw (ErreurLecture);

  ///
  unsigned char   ReadVTKImage() throw (ErreurLecture);

  // Op�ation d'allocation, de lecture, d'ecriture
  ///
  unsigned char   Read() throw (ErreurLecture);

  ///
  unsigned char   LitEntete() throw (ErreurLecture);
  ///
  unsigned char   Alloue() throw (ErreurAllocation);
  ///
  unsigned char   Ecrit() throw (ImageWriteError);
  ///
  unsigned char   Desalloue();

  ///
  unsigned char   LitMaple( const char* nom);
  ///
  unsigned char   EcritMaple(const char* nom);

  /// initialisation du tableau de positions _positions[z][y]
  virtual unsigned char   InitPositions();

  /// initialisation du tableau de positions _positions[z][y]
  virtual unsigned char   FreePositions();

  ///
  WORDTYPE  ZimageFormat( int format);

  void      InitParams();

public:

/**@name 1- public variables  */
//@{
  /** @name dimensions de l'image */
  //@{

    ///
    int     _tx;

    ///
    int     _ty;

    ///
    int     _tz;

  //@}

  /** @name translation in space coord for the point (0,0,0) */
  //@{

    ///
    float      _translation_x;
    ///
    float      _translation_y;
    ///
    float      _translation_z;


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


  // Transformation matrix
  float  _transf_matrix[4][4];

//@}


  /** @name 2-Constructors  and destructor */
  //@{
    /**
     * This constructor is used for InrImageCompressee class
     * @return 
     */
     InrImage( );

     InrImage( const char* nom);

    // Pour des fichier d'un autre format
     InrImage( const char* nom, int type);

     InrImage( int dimx, int dimy,
                           int dimz, WORDTYPE format, const char* nom=(const char*)NULL);

     InrImage(
               int   dimx,
               int   dimy,
               int   dimz,
               int   vdim,
               WORDTYPE format,
               const char*    nom=(const char*)NULL
               );


#ifndef _WITHOUT_VTK_
     InrImage( vtkImageData* image);
#endif // _WITHOUT_VTK_

    /**
     *  Creates a new image with the given format 
     *  using parameters of another image (size, translation, voxel size),
     *  !!! however, the new image is usually scalar !!!
     * @param format 
     * @param vdim 
     * @param nom 
     * @param image 
     * @return 
     */
     InrImage(  WORDTYPE format,
                            const char* nom,
                            const InrImage* image);

    /**
     *  Creates a new image with the given format 
     *  using parameters of another image (size, translation, voxel size),
     *  the new image has the given number of components.
     * @param format 
     * @param vdim number of components of the new image.
     * @param nom 
     * @param image 
     * @return 
     */
     InrImage(  WORDTYPE format, int vdim,
                            const char* nom,
                            const InrImage* image);

    static InrImage::ptr New( WORDTYPE format, int vdim,
                              const char* nom,
                              InrImage::ptr image)
    {
      return InrImage::ptr(new InrImage(format,vdim,nom,image.get()));
    }

    virtual ~ InrImage();
  //@}

  /** @name 2.1- Initialisation de l'image */
  //@{


    ///
    unsigned char GetFormatFromAMI(amimage* im, WORDTYPE& type);

    ///
    bool AMIFromWT( int vdim, WORDTYPE type, amimage* amim);

    ///
    bool AMIFromWT( int vdim, WORDTYPE type, boost::shared_ptr<amimage>& amim);

    ///
    void SetAMImage( const amimage::ptr& amim);
    //   ----------

    ///
    void SetImageData( int dimx, int dimy, int dimz,
    //   ------------
               WORDTYPE format, void* data, int vdim=1);

    ///
    void SetImageData( int dimx, int dimy, int dimz, int vdim,
    //   ------------
               WORDTYPE format, void* data);

    ///
    void SetVoxelSize( float sx, float sy, float sz);
    //   ------------------

    /// Initialisation tous les voxels a 0
    void InitZero( );
    //   --------

    /// Initialisation tous les voxels a la valeurs val
    void InitImage( double val);
    //   ---------

    /// Initialisation tous les voxels a la valeurs val
    /// pour une image RGB ou de vecteurs
    void InitImage( double val0, double val1, double val2);
    //   ---------

    /// Initialisation tous les voxels a la valeur d'un vecteur
    void InitImage( double* values, int size);
    //   ---------

    /// Copie d'images
    bool operator=( InrImage& im);
    //   ---------

  /*
    /// Recuperation des positions SIGNED_INT pour la compression
    FORMAT_SIGNED_INT***   GetSignedIntPos() { return  _positions_SIGNED_INT;}
  */

  //@}

  /** @name 3- Image class access to the members and values */
  //@{

    /**
     * Creates an interator to the image data
     **/
    InrImageIteratorBase::ptr CreateIterator();

    /**
     * Creates an interator to the image data
     **/
    InrImageIteratorBase::ptr CreateConstIterator() const;


    /**
      @return pointeur sur les donnees
    */
    void*     Buffer() { return _amimage->GetData(); }
    //        ------

    void*     GetData() { return _amimage->GetData(); }
    //        -------

    void const *     GetConstData() const { return _amimage->GetData(); }
    //               ------------

    ///
    void      FixeBuffer( void* buf) { _amimage->data = (char*) buf; }
    //        ----------

    ///
    const char*    GetName() const { return _nom.c_str();}
    //            ---

    ///
    void          FixeNom( char* name) { _nom=name; }
    //            -------

    ///
    const std::string FormatName();
    //               ----------

    //
    const WORDTYPE& GetFormat() const { return _format;}
    //

    //
    unsigned char   ScalarFormat() const
    {
      switch ( (WORDTYPE) _format ) {
        case WT_RGB:            return false;
        case WT_FLOAT_VECTOR:   return false;
        case WT_DOUBLE:         return (_vdim==1);
        case WT_FLOAT:          return (_vdim==1);
        case WT_RGBA:
        case WT_UNSIGNED_CHAR:
          return (_vdim==1);
        case WT_UNSIGNED_SHORT: return (_vdim==1);
        case WT_SIGNED_SHORT:   return (_vdim==1);
        case WT_UNSIGNED_INT:   return (_vdim==1);
        case WT_SIGNED_INT:     return (_vdim==1);
        default: printf("InrImage::ScalarFormat()\t format non gere %d ...\n",_format);
      } // end switch

      return false;
    }

    //
    unsigned char   VectorialFormat() const
    {
      switch ( (WORDTYPE) _format ) {

        case WT_RGB:
        case WT_RGBA:
        case WT_FLOAT_VECTOR:   return true;

        case WT_DOUBLE:
        case WT_FLOAT:
        case WT_UNSIGNED_CHAR:
        case WT_UNSIGNED_SHORT:
        case WT_SIGNED_SHORT:
        case WT_UNSIGNED_INT:
        case WT_SIGNED_INT:     return (_vdim>1);
        default: printf("InrImage::ScalarFormat()\t format non gere %d ...\n",_format);
      } // end switch

      return false;
    }

    ImagePositionsBase* GetPositions() { return _positions; }
    ImagePositionsBase const* GetPositionsConst() const { return _positions; }

  //@}

  /** @name 4-M�hode li�s �la gestion du buffer */
  //@{
    /**
     * Init local iterator
     * @param pos 
     */
    void InitBuffer( int pos = 0);
    //             ----------

    /** Verifie si les coordonnees sont dans le domaine
        de definition de l'image
     */
    unsigned char CoordOK( int x, int y, int z)
    //      -------
    {
      return ( (x>=0) Et (x<_tx) Et
                 (y>=0) Et (y<_ty) Et
                 (z>=0) Et (z<_tz) );
    } // CoordOK()

    int GetVDim() const {return _vdim;}


    void SetTranslation( float tx, float ty, float tz)
    {
      _translation_x = tx;
      _translation_y = ty;
      _translation_z = tz;
      _amimage->SetTranslation(_translation_x,
                   _translation_y,
                   _translation_z);
    }

    void GetTranslation( float& tx, float& ty, float& tz)
    {
      tx = _translation_x;
      ty = _translation_y;
      tz = _translation_z;
    }

    void          GetTransfMatrix(float m[4][4])
    {
      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
      m[i][j] = _transf_matrix[i][j];
    }

/*
    float* GetTranslation( )
    {
      tx = _translation_x;
      ty = _translation_y;
      tz = _translation_z;
    }
*/
    int DimX() const { return _tx; }
    int DimY() const { return _ty; }
    int DimZ() const { return _tz; }

    float TrX() const { return _translation_x; }
    float TrY() const { return _translation_y; }
    float TrZ() const { return _translation_z; }

    long Size() const { return _taille; }

    unsigned long  GetDataSize() const 
    {
      return _amimage->GetDataSize(); 
    }

    float VoxSizeX() const { return _size_x; }
    float VoxSizeY() const { return _size_y; }
    float VoxSizeZ() const { return _size_z; }
    float VoxSize(int coord) const {
      switch(coord) {
        case 0:  return _size_x;
        case 1:  return _size_y;
        case 2:  return _size_z;
      }
      return 1;
    }

    /// Conversion from voxel position to space position
    float SpacePosX( float x) const { return x*_size_x+_translation_x; }

    /// Conversion from voxel position to space position
    float SpacePosY( float y) const { return y*_size_y+_translation_y; }

    /// Conversion from voxel position to space position
    float SpacePosZ( float z) const { return z*_size_z+_translation_z; }

    /// Conversion from voxel position to space position
    float SpacePos(const int coord, const float& val) const
    {
      switch(coord) {
        case 0:  return SpacePosX(val);
        case 1:  return SpacePosY(val);
        case 2:  return SpacePosZ(val);
      }
      return 0.0;
    }

    /// Conversion from space position to voxel position
    float SpaceToVoxelX( float x) const { return (x-_translation_x)/_size_x; }

    /// Conversion from space position to voxel position
    float SpaceToVoxelY( float y) const { return (y-_translation_y)/_size_y; }

    /// Conversion from space position to voxel position
    float SpaceToVoxelZ( float z) const { return (z-_translation_z)/_size_z; }

    //
    void BufferPos( int x, int y, int z=0) throw (DepassementLimites);

    void GetBufferIncrements( int& incx, int& incy, int& incz) const
    {
      incx = _vdim;
      incy = _tx*_vdim;
      incz = _tx*_ty*_vdim;
    }

    /**
       Pointeur sur la position courante du buffer
    */
    void*  BufferPtr( int x, int y, int z=0) const
    //     ---------
    {
      return _positions->GetVoidPos(x,y,z);
    } // BufferPtr()

    /**
       Pointeur sur la position courante du buffer
    */
    void*  BufferPtr()
    //     ---------
    {
      return _Iterator->PosPointer(); 
    } // BufferPtr()


    /**
       Fonction en ligne
       Incr�entation du buffer
    */
    inline bool IncBuffer( int inc)
    //          ---------
    {
      return _Iterator->Inc(inc);
    } // IncBuffer()

    /**
       Fonction en ligne
       Incr�entation du buffer
    */
    inline void IncScalarBufferFast()
    //          -------------------
    {
      _Iterator->IncScalarBufferFast();
    } // IncScalarBufferFast()

    inline bool IncBuffer( )
    //         ---------
    {
      return ++(*_Iterator.get());
    } // IncBuffer()


    /**
       Fonction en ligne
       Incr�entation du buffer
    */
/*
    int operator ++()
    //     -----------
    {
      return IncBuffer();
    } // operator ++()
*/
    /**
       Fonction en ligne
       Incr�entation du buffer
    */
/*
    int operator +=(int n)
    //     -----------
    {
      return IncBuffer(n);
    } // operator +=()
*/

    /**
       Renvoie la case de l'image �la position courante du buffer
    */
    inline  double ValeurBuffer( ) const
    //             ------------
    {
      return _Iterator->GetDoubleValue();

/*        case WT_RGB:   return
      (double) (_buffer_RGB[0]+_buffer_RGB[1]+_buffer_RGB[2])/3.0;
        case WT_FLOAT_VECTOR:   return
      (double) _buffer_FLOAT_VECTOR[0];
*/

    } // ValeurBuffer()

    //
    double ValeurBuffer( long inc)
    //                   ------------
    // Renvoie la Valeur du buffer+inc
    {
      return _Iterator->GetDoubleValue(inc);
    } // ValeurBuffer()

    /**
      Renvoie la valeur du buffer pour la coordonnee i (0:x, 1:y, 2:z)
    */
    double VectValeurBuffer( int i )
    //     ----------------
    {
      // same as ValeurBuffer(int inc) ...
      return _Iterator->GetDoubleValue(i);
    } // VectValeurBuffer()



    void FixeValeur( double val)
    //             ----------
    // Fixe la valeur de l'image au point courant du buffer
    {

      _Iterator->SetDoubleValue(val);

    } // FixeValeur()

    //
    void VectFixeValeurs( double valx, double valy, double valz)
    //   ---------------
    // Fixe la valeur de l'image au point courant du buffer
    {
      _Iterator->SetDoubleVectorValues(valx,valy,valz);

      /*
        case WT_RGB:
          _buffer_RGB[0]   = (FORMAT_UNSIGNED_CHAR)    (valx+0.05);
          _buffer_RGB[1]   = (FORMAT_UNSIGNED_CHAR)    (valy+0.05);
          _buffer_RGB[2]   = (FORMAT_UNSIGNED_CHAR)    (valz+0.05);
        break;
      */
    } // VectFixeValeurs()

    //
    void VectFixeValeur( unsigned char coord, double val)
    //   --------------
    // Fixe la valeur de l'image au point courant du buffer
    {

      _Iterator->SetDoubleValue(coord,val);

       /*
       case WT_RGBA:
       case WT_UNSIGNED_CHAR:
          _buffer_UNSIGNED_CHAR[coord]   = (FORMAT_UNSIGNED_CHAR)    (val+0.05);
       break;

       case WT_UNSIGNED_SHORT:
          _buffer_UNSIGNED_SHORT[coord]   = (FORMAT_UNSIGNED_SHORT)    (val+0.05);
       break;

       case WT_SIGNED_SHORT:
          _buffer_SIGNED_SHORT[coord]   = (FORMAT_SIGNED_SHORT)    round(val);
       break;

       case WT_SIGNED_INT:
          _buffer_SIGNED_INT[coord]   = (FORMAT_SIGNED_INT)    (round(val));
       break;

       case WT_UNSIGNED_INT:
          _buffer_UNSIGNED_INT[coord]   = (FORMAT_UNSIGNED_INT)    (val+0.05);
       break;

       case WT_RGB:
          _buffer_RGB[coord]   = (FORMAT_UNSIGNED_CHAR)    (val+0.05);
        break;
       */

    } // VectFixeValeur()


  //@}


  /** @name 5- Lecture-Ecriture, Sauvegarde de l'image */
  //@{

    ///
    virtual unsigned char Sauve( const char* nom = (char*)NULL);
    //                -----


    ///
    unsigned char SauveMaple( const char* nom = (char*)NULL)
    //      ----------
    {
      Si nom==NULL AlorsRetourne false;
      return EcritMaple(nom);
    }

    ///
    const std::string& MessageErreur();
    //          -------------

  //@}


  /** @name 6-Red�initions d'op�ateurs */
  //@{
    /**
     */
    operator double()
    //       ------
    { return ValeurBuffer(); }
    /**
     */

    //
    operator amimage*();
    //       -------


#ifndef _WITHOUT_VTK_
    //
    operator vtkImageData*();
    //       ------------

    operator vtkImageData_ptr();
    //       ------------
#endif // _WITHOUT_VTK_


    //  {\bf Operator(x,y,z) }
    double operator()( int x, int y, int z) const throw (DepassementLimites)
    //         --------
    {

      #ifdef _debug_
        Si x<0 Ou x>=_tx Ou y<0 Ou y>=_ty Ou z<0 Ou z>=_tz Alors
          char message[100];
          sprintf(message, " image %s ( %d %d %d )", (char*) _nom, x, y, z);
          throw DepassementLimites( message);
        FinSi
      #endif

      return (*_positions)(x,y,z);

    }


    //  {\bf Operator(x,y,z) }
    double operator()( int x, int y) const throw (DepassementLimites)
    //         --------
    {

      #ifdef _debug_
        Si x<0 Ou x>=_tx Ou y<0 Ou y>=_ty  Alors
          char message[100];
          sprintf(message, " image %s ( %d %d  )", (char*) _nom, x, y);
          throw DepassementLimites( message);
        FinSi
      #endif

      return (*_positions)(x,y);
    }


    //  {\em Operator(x,y,z,coord) }
    double GetValue( int x, int y, int z, int coord) const
    //         --------
    {
      return _positions->GetValue(x,y,z,coord);
    }

    //  {\em Operator(x,y,z,coord) }
    double operator()( int x, int y, int z, int coord) const
    {
        return GetValue(x,y,z,coord);
    }

  //@}


  /** @name 7-M�hodes plus �olu�s */
  //@{

  //
  InrImage* CreeSousImage( int min_x, int max_x,
                           int min_y, int max_y,
                           int min_z, int max_z);

  //
  void MinMax(float* min, float* max);

  /** Si l'image n'est pas de type WT_UNSIGNED_CHAR, alloue une nouvelle image
      et la convertit en TYPE_256
      avec le minimum �0 et le maximum �255
   */
  InrImage* Convert256( float min, float max);
  //        ----------

  /** Si l'image n'est pas de type WT_UNSIGNED_CHAR, alloue une nouvelle image
      et la convertit en TYPE_256
      avec le minimum �0 et le maximum �255
   */
  InrImage* Convert256( );
  //        ----------



  /** Interpolation Lineaire de l'intensite au point (x,y) avec z = 0
   en coordonnees reelles
   Prendre en compte la taille des voxels ???
   Pour une image 2D ...
  */
  double InterpLinIntensite( float x, float y)
  //         ------------------
  {

    return _linear_interpolator->InterpLinIntensite(x,y);
  } // InterpLinIntensite(x,y)


  /** Interpolation Linéaire de l'intensité au point (x,y,z)
   en coordonnées réelles
   Prendre en compte la taille des voxels ???
   Pour une image 3D ...
  */
  double InterpLinIntensite( float x, float y, float z)
  //         ------------------
  {
    return _linear_interpolator->InterpLinIntensite(x,y,z);
  } // InterpLinIntensite()


  /** Interpolation Lineaire de l'intensite au point (x,y,z)
   en coordonnees reelles
   Prendre en compte la taille des voxels ???
   Pour une image 3D ...
  */
  double InterpLinIntensite( float x, float y, float z, int coord)
  //         ------------------
  {
    return _linear_interpolator->InterpLinIntensite(x,y,z,coord);
  }

  //
  void VoisinageYZ( int x, int y, int z, float** vois)
  //   -----------
  {
        vois[0][0] = (float) (*_positions)(x,y,z);
        vois[0][1] = (float) (*_positions)(x,y,z+1);
        vois[1][0] = (float) (*_positions)(x,y+1,z);
        vois[1][1] = (float) (*_positions)(x,y+1,z+1);
  } // VoisinageYZ()

  float** create_float_positions_2D(int order=0);
  void    free_float_positions_2D(float** pos, int order=0);

  template <class T>  T*** create_positions_3D();

  template <class T>  void free_positions_3D(T*** pos);

  //@}

}; // InrImage


COMMON_EXPORT InrImage* operator-(  InrImage& i1,  InrImage& i2);
//

COMMON_EXPORT InrImage* operator-(  InrImage& i, double r );
//

COMMON_EXPORT InrImage* operator+(  InrImage& i1,  InrImage& i2);
//


/**
 * += operator operates on 2 images, either both scalar or both vectorial, the second image is added to the first one, and the resulting first image is returned
 * @param i1 first image
 * @param i2 second image
 * @return possibly modified i1
 */
COMMON_EXPORT InrImage& operator +=(  InrImage& i1,  InrImage& i2);


COMMON_EXPORT InrImage* operator*( const InrImage& i1, const InrImage& i2);
//

COMMON_EXPORT InrImage* operator/(  InrImage& i1,  InrImage& i2);
//

// Vectorial product
COMMON_EXPORT InrImage* operator^(  InrImage& i1,  InrImage& i2);
//

// Norm (for vectorial images) or absolute value for scalars
COMMON_EXPORT InrImage* Norm(  InrImage& i1);

//
//
//

#ifndef ami_malloc3d
#define ami_malloc3d(direccion,tipo,depth,height,width) {int ml,mu; \
          direccion=(tipo ***) malloc(sizeof(tipo **)*(depth)); \
          direccion[0]=(tipo **)malloc(sizeof(tipo *)*(depth)*(height)); \
          direccion[0][0]=(tipo *)malloc(sizeof(tipo)*(depth)*(height)*(width)); \
          for(mu=0;mu<depth;mu++){ \
            for(ml=0;ml<(height);ml++) \
              direccion[0][ml+mu*(height)]=&(direccion[0][0][ml*(width)+mu*(width)*(height)]); \
            direccion[mu]=&(direccion[0][mu*(height)]);}\
        }
#define ami_free3d(direccion) { free(direccion[0][0]); free(direccion[0]); free(direccion); }
#endif

template <class T>
T*** InrImage::create_positions_3D() {
    T*** pos;
    int     i,j,k;

    // make allocations and copies to avoid problems ???
    // could create memory problems ...
    // libami convention:  columns index first ...
    // amimage convention: line index first ...

    ami_malloc3d(pos,T,this->DimX(),this->DimY(),this->DimZ());
    this->InitBuffer();
    for(k=0;k<this->DimZ();k++)
      for(j=0;j<this->DimY();j++)
        for(i=0;i<this->DimX();i++) {
          memcpy((void*)&pos[i][j][k],this->BufferPtr(),
                  sizeof(T));
      this->IncBuffer();
        }

    return pos;
}

// free the positions and copy the values to the image
template <class T>
void    InrImage::free_positions_3D(T*** pos)
{
  int     i,j,k;

  this->InitBuffer();
  for(k=0;k<DimZ();k++)
    for(j=0;j<DimY();j++)
      for(i=0;i<DimX();i++) {
        memcpy(this->BufferPtr(),(void*)&pos[i][j][k],sizeof(T));
        this->IncBuffer();
      }

  ami_free3d(pos);
}

//----------------------------------------------------------------
inline bool InrImage::operator=( InrImage& im)
//                    ---------
{

  Si (_tx != im._tx) Ou (_ty != im._ty) Ou (_tz != im._tz) Alors
    return false;
  FinSi

  //  fprintf(stderr,"InrImage::operator=() \t begin \n");

  // Do a memcpy if possible ...
  Si (im._format == _format)&&(im.GetVDim()==GetVDim()) Alors
    memcpy(Buffer(), im.Buffer(), _taille*TailleFormat[_format]*_vdim);
    return 1;
  FinSi

  Si ScalarFormat() Alors

    InitBuffer();
    im.InitBuffer();
    Repeter
      FixeValeur( im.ValeurBuffer());
      im.IncBuffer();
    JusquA Non(IncBuffer()) FinRepeter
  Autrement
  Si VectorialFormat() Et im.VectorialFormat() Alors
    InitBuffer();
    im.InitBuffer();
    Repeter
      for(int i=0;i<im.GetVDim();i++)
        if (i<GetVDim())
        VectFixeValeur( i, im.VectValeurBuffer(i));
      im.IncBuffer();
    JusquA Non(IncBuffer()) FinRepeter
  Autrement
  Si VectorialFormat() Et im.ScalarFormat() Alors
    //    printf(" vect et scal \n");
    InitBuffer();
    im.InitBuffer();
    Repeter
      for(int i=0;i<im.GetVDim();i++)
        VectFixeValeur(i, im.ValeurBuffer());
      im.IncBuffer();
    JusquA Non(IncBuffer()) FinRepeter
  Sinon
    fprintf(stderr,"InrImage::operator=  \t Error: vector = scalar \n");
  FinSi

  //if (GB_debug)  fprintf(stderr,"InrImage::operator=() \t end \n");

  return true;
} // operator=()


//--------------------------------------------------------------------------
inline void InrImage :: MinMax( float* min, float* max)
//                         ------
{
       long n,size;

  size = _tx*_ty*_tz;
  int vdim = GetVDim();

  switch ( (WORDTYPE) _format ) {

    case WT_DOUBLE:
      register FORMAT_DOUBLE*         buf_DOUBLE;

      buf_DOUBLE = (FORMAT_DOUBLE*) this->GetData();
      *min = *max = (float) (*buf_DOUBLE);
      for(  n=0 ;  n < size ;  n++ Faire
        Si *buf_DOUBLE < *min AlorsFait *min =(float)  *buf_DOUBLE;
        Si *buf_DOUBLE > *max AlorsFait *max =(float)  *buf_DOUBLE;
        buf_DOUBLE+=vdim;
      } // end for // n

    break;

    case WT_FLOAT:
      register  FORMAT_FLOAT*          buf_FLOAT;
      buf_FLOAT = (FORMAT_FLOAT*) this->GetData();
      *min = *max = *buf_FLOAT;
      for(  n=0 ;  n < size ;  n++ Faire
        Si *buf_FLOAT < *min AlorsFait *min = *buf_FLOAT;
        Si *buf_FLOAT > *max AlorsFait *max = *buf_FLOAT;
        buf_FLOAT+=vdim;
      } // end for // n

    break;

    case WT_UNSIGNED_CHAR:
      register FORMAT_UNSIGNED_CHAR*  buf_UNSIGNED_CHAR;

      buf_UNSIGNED_CHAR = (FORMAT_UNSIGNED_CHAR*) this->GetData();
      *min = *max = (float) *buf_UNSIGNED_CHAR;
      for(  n=0 ;  n < size ;  n++ Faire
        Si *buf_UNSIGNED_CHAR < *min AlorsFait *min = (float) *buf_UNSIGNED_CHAR;
        Si *buf_UNSIGNED_CHAR > *max AlorsFait *max = (float) *buf_UNSIGNED_CHAR;
        buf_UNSIGNED_CHAR+=vdim;
      } // end for // n

    break;

    case WT_UNSIGNED_SHORT:
      register FORMAT_UNSIGNED_SHORT* buf_UNSIGNED_SHORT;

      buf_UNSIGNED_SHORT = (FORMAT_UNSIGNED_SHORT*) this->GetData();
      *min = *max = (float) *buf_UNSIGNED_SHORT;
      for(  n=0 ;  n < size ;  n++ Faire
        Si *buf_UNSIGNED_SHORT < *min AlorsFait *min = (float) *buf_UNSIGNED_SHORT;
        Si *buf_UNSIGNED_SHORT > *max AlorsFait *max = (float) *buf_UNSIGNED_SHORT;
        buf_UNSIGNED_SHORT+=vdim;
      } // end for // n

    break;

    case WT_SIGNED_SHORT:
      register FORMAT_SIGNED_SHORT*   buf_SIGNED_SHORT;

      buf_SIGNED_SHORT = (FORMAT_SIGNED_SHORT*) this->GetData();
      *min = *max = (float) *buf_SIGNED_SHORT;
      for(  n=0 ;  n < size ;  n++ Faire
        Si *buf_SIGNED_SHORT < *min AlorsFait *min = (float) *buf_SIGNED_SHORT;
        Si *buf_SIGNED_SHORT > *max AlorsFait *max = (float) *buf_SIGNED_SHORT;
        buf_SIGNED_SHORT+=vdim;
      } // end for // n

    break;

    case WT_UNSIGNED_INT:
      register FORMAT_UNSIGNED_INT*   buf_UNSIGNED_INT;

      buf_UNSIGNED_INT = (FORMAT_UNSIGNED_INT*) this->GetData();
      *min = *max = (float) *buf_UNSIGNED_INT;
      for(  n=0 ;  n < size ;  n++ Faire
        Si *buf_UNSIGNED_INT < *min AlorsFait *min = (float) *buf_UNSIGNED_INT;
        Si *buf_UNSIGNED_INT > *max AlorsFait *max = (float) *buf_UNSIGNED_INT;
        buf_UNSIGNED_INT+=vdim;
      } // end for // n

    break;

    case WT_SIGNED_INT:
      register FORMAT_SIGNED_INT*   buf_SIGNED_INT;

      buf_SIGNED_INT = (FORMAT_SIGNED_INT*) this->GetData();
      *min = *max = (float) (*buf_SIGNED_INT);
      for(  n=0 ;  n < size ;  n++ Faire
        Si *buf_SIGNED_INT < *min AlorsFait *min = (float) (*buf_SIGNED_INT);
        Si *buf_SIGNED_INT > *max AlorsFait *max = (float) (*buf_SIGNED_INT);
        buf_SIGNED_INT+=vdim;
      } // end for // n

    break;

    case WT_RGB:
    case WT_RGBA:

      *min = 0;
      *max = 255;

    break;

    default: printf("InrImage::MinMax()\t format non gere..\n");

  } // end switch

  return;

} // MinMax()

#endif // _INRIMAGE_HPP
