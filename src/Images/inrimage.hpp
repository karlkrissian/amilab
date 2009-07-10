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
using namespace boost;

#ifdef _MSC_VER
  #pragma warning( disable : 4290 )
#endif

#ifndef _WITHOUT_VTK_
// avoiding including vtk files for faster compilation ...
class vtkImageData;
typedef shared_ptr<vtkImageData>  vtkImageData_ptr;
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

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif

#include <math.h>

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

/**  @name Fomats
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



//=========================================================================


/** Operations de base
   copie d'une image vers une autre\\
         a partir d'un objet InrImage\\
         a partir d'une structure t_inrimage\\
   conversion de format\\
   Lecture a partir d'un fichier\\

   operations arithmetiques\\
   addition\\
   soustraction\\
   multiplication\\
   division\\
   log\\
   exp
*/
class InrImage
//    ========
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
       Constructeur DepassementLimites( const std::string message)
     {
       cout << "InrImage "
                << " Out of image limits"
            << "\t " << message  << endl;
     }
    };
  //@}

protected:

   static int TailleFormat[NB_FORMATS];


  ///
    //  inrimage*   _inrimage;

  /// pointer to the data
  amimage*           _amimage;
  unsigned char    _amimage_allocated;

  ///
  int     _vdim; // image scalar (1), vectorial (2,3,etc...)


  ///
  long _taille;
  ///
  long _pos_buf;

  ///
  std::string     _nom;   // nom du fichier sur disque


  ///
  int     _coord_vecteur;

  ///
  std::string     _message_erreur;

  ///
  //  unsigned char    _inrimage_allouee;

  ///
  unsigned char    _positions_allouees;

  // buffer permettant la gestion d'images

/** @name Buffers pour les diff�ents formats g�� */
  //@{
    ///
    FORMAT_UNSIGNED_CHAR*    _buffer_UNSIGNED_CHAR;

    ///
    FORMAT_UNSIGNED_SHORT*   _buffer_UNSIGNED_SHORT;

    ///
    FORMAT_SIGNED_SHORT*     _buffer_SIGNED_SHORT;

    ///
    FORMAT_UNSIGNED_INT*       _buffer_UNSIGNED_INT;

    ///
    FORMAT_SIGNED_INT*       _buffer_SIGNED_INT;

    ///
    FORMAT_FLOAT*            _buffer_FLOAT;

    ///
    FORMAT_DOUBLE*           _buffer_DOUBLE;

    /// RGB
    FORMAT_RGB*              _buffer_RGB;

    /// Vecteur de Float
    FORMAT_FLOAT_VECTOR*     _buffer_FLOAT_VECTOR;
//@}

/** @name Positions pour les diff�ents formats g��
  tableau de pointeurs permettant d'acc�er directement
   au debut de la ligne:
   _positions[z][y] pointe sur l'adresse de l'element (x=0,y,z)
   dans le buffer de l'image
*/
  //@{
    ///
    FORMAT_UNSIGNED_CHAR***    _positions_UNSIGNED_CHAR;

    ///
    FORMAT_UNSIGNED_SHORT***   _positions_UNSIGNED_SHORT;

    ///
    FORMAT_SIGNED_SHORT***     _positions_SIGNED_SHORT;

    ///
    FORMAT_UNSIGNED_INT***       _positions_UNSIGNED_INT;

    ///
    FORMAT_SIGNED_INT***       _positions_SIGNED_INT;

    ///
    FORMAT_FLOAT***            _positions_FLOAT;

    ///
    FORMAT_DOUBLE***           _positions_DOUBLE;

    /// RGB
    FORMAT_RGB***              _positions_RGB;

    /// Vecteur de Float
    FORMAT_FLOAT_VECTOR***     _positions_FLOAT_VECTOR;
  //@}

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
  unsigned char   Lit() throw (ErreurLecture);

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
  virtual unsigned char   EffacePositions();

  ///
  WORDTYPE  ZimageFormat( int format);

  void      InitParams();

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


  /** @name 2-Diff�ents constructeurs  et le destructeur */
  //@{
    // constructeur utile pour la classe InrimageCompressee
    Constructeur InrImage( );

    Constructeur InrImage( const char* nom);

    // Pour des fichier d'un autre format
    Constructeur InrImage( const char* nom, int type);

    Constructeur InrImage( int dimx, int dimy,
                           int dimz, WORDTYPE format, const char* nom=(const char*)NULL);

    Constructeur InrImage(
               int   dimx,
               int   dimy,
               int   dimz,
               int   vdim,
               WORDTYPE format,
               const char*    nom=(const char*)NULL
               );


#ifndef _WITHOUT_VTK_
    Constructeur InrImage( vtkImageData* image);
#endif // _WITHOUT_VTK_

    /**
      Cree une nouvelle image au format specifie en utilisant
      les dimensions de l'image image (taille, taille des voxels)
    */
    Constructeur InrImage(  WORDTYPE format,
                            const char* nom,
                            InrImage* image);
    Constructeur InrImage(  WORDTYPE format, int vdim,
                            const char* nom,
                            InrImage* image);

    static InrImage::ptr New( WORDTYPE format, int vdim,
                              const char* nom,
                              InrImage::ptr image)
    {
      return InrImage::ptr(new InrImage(format,vdim,nom,image.get()));
    }

    virtual Destructeur  InrImage();
  //@}

  /** @name 2.1- Initialisation de l'image */
  //@{

    ///
    unsigned char GetFormatFromAMI(amimage* im, WORDTYPE& type);

    ///
    unsigned char AMIFromWT( int vdim, WORDTYPE type, amimage* amim);

    ///
    void SetAMImage( amimage* amim);
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

    /// Recuperation des positions SIGNED_INT pour la compression
    FORMAT_SIGNED_INT***   GetSignedIntPos() { return  _positions_SIGNED_INT;}

  //@}

  /** @name 3-Acc� aux champs de la classe */
  //@{
    /**
      @return pointeur sur les donnees
    */
    void*     Buffer() { return _amimage->GetData(); }
    //        ------

    void*     GetData() { return _amimage->GetData(); }
    //        -------

    ///
    void      FixeBuffer( void* buf) { _amimage->data = (char*) buf; }
    //        ----------

    ///
    const char*    Nom() const { return _nom.c_str();}
    //            ---

    ///
    void          FixeNom( char* name) { _nom=name; }
    //            -------

    ///
    const string    FormatName();
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
        Defaut: printf("InrImage::FormatScalaire()\t format non gere...\n");
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
        Defaut: printf("InrImage::FormatScalaire()\t format non gere...\n");
      } // end switch

      return false;
    }

  //@}

  /** @name 4-M�hode li�s �la gestion du buffer */
  //@{
    /** Op�ation de parcours de buffer inter-formats
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

    int GetVDim() {return _vdim;}


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
    float SpacePos(const int& coord, const float& val) const
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


    ///
    void FixeVecteurCoord( int num)
    //
    {

      Si num < 0 AlorsFait num = 0;
      Si num > 2 AlorsFait num = 2;

      _coord_vecteur = num;

    }


    //
    void BufferPos( int x, int y, int z=0) throw (DepassementLimites)
    //             ---------
    {

#ifdef _debug_
      Si x<0 Ou x>=_tx Ou y<0 Ou y>=_ty Ou z<0 Ou z>=_tz Alors
        char message[100];
        sprintf(message, " image %s ( %d %d %d )", (char*)_nom, x, y, z);
        throw DepassementLimites( message);
      FinSi
#endif

    switch ( (WORDTYPE) _format ) {

      case WT_RGB:
        _buffer_RGB     = (_positions_RGB[z][y] + 3*x);
      break;

      case WT_FLOAT_VECTOR:
        _buffer_FLOAT_VECTOR     = (_positions_FLOAT_VECTOR[z][y] + _vdim*x);
      break;

      case WT_DOUBLE:
        _buffer_DOUBLE          = (_positions_DOUBLE[z][y]         + _vdim*x);
      break;

      case WT_FLOAT:
        _buffer_FLOAT           = (_positions_FLOAT[z][y]          + _vdim*x);
      break;

      case WT_RGBA:
      case WT_UNSIGNED_CHAR:
        _buffer_UNSIGNED_CHAR   = (_positions_UNSIGNED_CHAR[z][y]  + _vdim*x);
      break;

      case WT_UNSIGNED_SHORT:
        _buffer_UNSIGNED_SHORT  = (_positions_UNSIGNED_SHORT[z][y]   + _vdim*x);
      break;

      case WT_SIGNED_SHORT:
        _buffer_SIGNED_SHORT    = (_positions_SIGNED_SHORT[z][y] + _vdim*x);
      break;

      case WT_SIGNED_INT:
        _buffer_SIGNED_INT     = (_positions_SIGNED_INT[z][y] + _vdim*x);
      break;

      case WT_UNSIGNED_INT:
        _buffer_UNSIGNED_INT     = (_positions_UNSIGNED_INT[z][y] + _vdim*x);
      break;

      Defaut:  printf("InrImage::BufferPos() \t format non gere ...\n");

    } // end switch

    _pos_buf = ((unsigned long) z*_ty + y)* _tx + x;

    } // BufferPos()


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

      switch ( (WORDTYPE) _format ) {

        case WT_RGB:            return (void*) (_positions_RGB[z][y]           + _vdim*x);
        case WT_FLOAT_VECTOR:   return (void*) (_positions_FLOAT_VECTOR[z][y]  + _vdim*x);
        case WT_DOUBLE:         return (void*) (_positions_DOUBLE[z][y]        + _vdim*x);
        case WT_FLOAT:          return (void*) (_positions_FLOAT[z][y]         + _vdim*x);

        case WT_RGBA:
        case WT_UNSIGNED_CHAR:  return (void*) (_positions_UNSIGNED_CHAR[z][y] + _vdim*x);

        case WT_UNSIGNED_SHORT: return (void*) (_positions_UNSIGNED_SHORT[z][y]+ _vdim*x);
        case WT_SIGNED_SHORT:   return (void*) (_positions_SIGNED_SHORT[z][y]  + _vdim*x);
        case WT_UNSIGNED_INT:   return (void*) (_positions_UNSIGNED_INT[z][y]  + _vdim*x);
        case WT_SIGNED_INT:     return (void*) (_positions_SIGNED_INT[z][y]    + _vdim*x);

        Defaut: printf("InrImage::BufferPtr()\t format not available...\n");

      } // end switch

      return NULL;

    } // BufferPtr()

    /**
       Pointeur sur la position courante du buffer
    */
    void*  BufferPtr()
    //               ---------
    {

      switch ( (WORDTYPE) _format ) {

        case WT_RGB:            return (void*) _buffer_RGB;
        case WT_FLOAT_VECTOR:   return (void*) _buffer_FLOAT_VECTOR;
        case WT_DOUBLE:         return (void*) _buffer_DOUBLE;
        case WT_FLOAT:          return (void*) _buffer_FLOAT;

        case WT_RGBA:
        case WT_UNSIGNED_CHAR:  return (void*) _buffer_UNSIGNED_CHAR;

        case WT_UNSIGNED_SHORT: return (void*) _buffer_UNSIGNED_SHORT;
        case WT_SIGNED_SHORT:   return (void*) _buffer_SIGNED_SHORT;
        case WT_UNSIGNED_INT:     return (void*) _buffer_UNSIGNED_INT;
        case WT_SIGNED_INT:     return (void*) _buffer_SIGNED_INT;

        Defaut: printf("InrImage::BufferPtr()\t format non gere...\n");

      } // end switch

      return NULL;

    } // BufferPtr()


    /**
       Fonction en ligne
       Incr�entation du buffer
    */
    inline bool IncBuffer( int inc)
    //          ---------
    {
      Si ++_pos_buf >= _taille AlorsRetourne false;

      switch ( (WORDTYPE) _format ) {

        case WT_RGB:            _buffer_RGB            += 3*inc;  break;
        case WT_FLOAT_VECTOR:   _buffer_FLOAT_VECTOR   += _vdim*inc;  break;
        case WT_DOUBLE:         _buffer_DOUBLE         += _vdim*inc;    break;
        case WT_FLOAT:          _buffer_FLOAT          += _vdim*inc;    break;

        case WT_RGBA:
        case WT_UNSIGNED_CHAR:  _buffer_UNSIGNED_CHAR  += _vdim*inc;    break;

        case WT_UNSIGNED_SHORT: _buffer_UNSIGNED_SHORT += _vdim*inc;    break;
        case WT_SIGNED_SHORT:   _buffer_SIGNED_SHORT   += _vdim*inc;    break;
        case WT_UNSIGNED_INT:     _buffer_UNSIGNED_INT     += _vdim*inc;    break;
        case WT_SIGNED_INT:     _buffer_SIGNED_INT     += _vdim*inc;    break;

        Defaut: printf("InrImage::IncBuffer()\t format non gere...\n");

      } // end switch

      return true;

    } // IncBuffer()


    inline bool IncBuffer( )
    //         ---------
    {
      Si ++_pos_buf >= _taille AlorsRetourne false;

      switch ( (WORDTYPE) _format ) {
        case WT_RGB:            _buffer_RGB            += 3;  break;
        case WT_FLOAT_VECTOR:   _buffer_FLOAT_VECTOR   += _vdim;  break;
        case WT_DOUBLE:         _buffer_DOUBLE         += _vdim;    break;
        case WT_FLOAT:          _buffer_FLOAT          += _vdim;    break;
        case WT_RGBA:
        case WT_UNSIGNED_CHAR:
          _buffer_UNSIGNED_CHAR  += _vdim;    break;
        case WT_UNSIGNED_SHORT: _buffer_UNSIGNED_SHORT += _vdim;    break;
        case WT_SIGNED_SHORT:   _buffer_SIGNED_SHORT   += _vdim;    break;
        case WT_UNSIGNED_INT:     _buffer_UNSIGNED_INT += _vdim;    break;
        case WT_SIGNED_INT:     _buffer_SIGNED_INT     += _vdim;    break;

        Defaut: printf("InrImage::IncBuffer()\t format non gere...\n");

      } // end switch

      return true;

    } // IncBuffer()


    /**
       Fonction en ligne
       Incr�entation du buffer
    */
    int operator ++()
    //     -----------
    {
      return IncBuffer();
    } // operator ++()

    /**
       Fonction en ligne
       Incr�entation du buffer
    */
    int operator +=(int n)
    //     -----------
    {
      return IncBuffer(n);
    } // operator +=()


    /**
       Renvoie la case de l'image �la position courante du buffer
    */
    inline  double ValeurBuffer( ) const
    //             ------------
    {

      switch ( (WORDTYPE) _format ) {
        case WT_DOUBLE:         return (double) *_buffer_DOUBLE;
        case WT_FLOAT:          return (double) *_buffer_FLOAT;
        case WT_RGBA:
        case WT_UNSIGNED_CHAR:
          return (double) *_buffer_UNSIGNED_CHAR;
        case WT_UNSIGNED_SHORT: return (double) *_buffer_UNSIGNED_SHORT;
        case WT_SIGNED_SHORT:   return (double) *_buffer_SIGNED_SHORT;
        case WT_UNSIGNED_INT:   return (double) *_buffer_UNSIGNED_INT;
        case WT_SIGNED_INT:     return (double) *_buffer_SIGNED_INT;
        case WT_RGB:   return
      (double) (_buffer_RGB[0]+_buffer_RGB[1]+_buffer_RGB[2])/3.0;
        case WT_FLOAT_VECTOR:   return
      (double) _buffer_FLOAT_VECTOR[0];

        Defaut: printf("InrImage::ValeurBuffer()\t format non gere...\n");

      } // end switch

      return 0;

    } // ValeurBuffer()


    //
    double ValeurBuffer( long inc)
    //                   ------------
    // Renvoie la Valeur du buffer+inc
    {

      switch ( (WORDTYPE) _format ) {

        case WT_DOUBLE:         return (double) *(_buffer_DOUBLE         + inc);
        case WT_FLOAT:          return (double) *(_buffer_FLOAT          + inc);
        case WT_UNSIGNED_CHAR:  return (double) *(_buffer_UNSIGNED_CHAR  + inc);
        case WT_UNSIGNED_SHORT: return (double) *(_buffer_UNSIGNED_SHORT + inc);
        case WT_SIGNED_SHORT:   return (double) *(_buffer_SIGNED_SHORT   + inc);
        case WT_UNSIGNED_INT:     return (double) *(_buffer_UNSIGNED_INT     + inc);
        case WT_SIGNED_INT:     return (double) *(_buffer_SIGNED_INT     + inc);
        case WT_FLOAT_VECTOR:   return
      (double) _buffer_FLOAT_VECTOR[_vdim*inc+0];
        Defaut: printf("InrImage::InterpLinIntensite()\t format non gere...\n");

      } // end switch

      return 0;

    } // ValeurBuffer()

    /**
      Renvoie la valeur du buffer pour la coordonnee i (0:x, 1:y, 2:z)
    */
    double VectValeurBuffer( int i )
    //                   ----------------
    {

      switch ( (WORDTYPE) _format ) {
        case WT_RGB:   return (double) _buffer_RGB[i];
        case WT_FLOAT_VECTOR:   return (double) _buffer_FLOAT_VECTOR[i];
        case WT_FLOAT:          return  _buffer_FLOAT[i];
        case WT_DOUBLE:         return  _buffer_DOUBLE[i];

        case WT_RGBA:
        case WT_UNSIGNED_CHAR:
          return  _buffer_UNSIGNED_CHAR[i];

        case WT_SIGNED_SHORT:   return  _buffer_SIGNED_SHORT[i];
        case WT_SIGNED_INT:     return  _buffer_SIGNED_INT[i];
        case WT_UNSIGNED_SHORT: return  _buffer_UNSIGNED_SHORT[i];
        case WT_UNSIGNED_INT:   return  _buffer_UNSIGNED_INT[i];
        Defaut: printf("InrImage::VectValeurBuffer()\t format non gere...\n");
      } // end switch

      return 0;

    } // VectValeurBuffer()


    /**
      Renvoie la Valeur du buffer pour la coordonnee i
    */
    /*
    Vect3D<float> VectValeurBuffer( )
    //           ----------------
    {

      switch ( (WORDTYPE) _format ) {

        case WT_RGB:   return
                          Vect3D<float>( (float) _buffer_RGB[0],
                    (float) _buffer_RGB[1],
                    (float) _buffer_RGB[2]);
        case WT_FLOAT_VECTOR:
                         return
                          Vect3D<float>( (float) _buffer_FLOAT_VECTOR[0],
                    (float) _buffer_FLOAT_VECTOR[1],
                    (float) _buffer_FLOAT_VECTOR[2]);

        Defaut: printf("InrImage::VectValeurBuffer()\t format non gere...\n");

      } // end switch

      return Vect3D<float>(0.0,0.0,0.0);

    } // VectValeurBuffer()
    */


    void FixeValeur( double val)
    //             ----------
    // Fixe la valeur de l'image au point courant du buffer
    {

      switch ( (WORDTYPE) _format ) {

        case WT_DOUBLE:
          *_buffer_DOUBLE         = (FORMAT_DOUBLE)         val;
        break;

        case WT_FLOAT:
          *_buffer_FLOAT          = (FORMAT_FLOAT)          val;
        break;

        case WT_RGBA:
        case WT_UNSIGNED_CHAR:
          *_buffer_UNSIGNED_CHAR  = (FORMAT_UNSIGNED_CHAR)  (val+0.05);
        break;

        case WT_UNSIGNED_SHORT:
          *_buffer_UNSIGNED_SHORT = (FORMAT_UNSIGNED_SHORT) (val+0.05);
        break;

        case WT_SIGNED_SHORT:
          *_buffer_SIGNED_SHORT   = (FORMAT_SIGNED_SHORT)   (round(val));
        break;

        case WT_UNSIGNED_INT:
          *_buffer_UNSIGNED_INT     = (FORMAT_UNSIGNED_INT)     (val+0.05);
        break;

        case WT_SIGNED_INT:
          *_buffer_SIGNED_INT     = (FORMAT_SIGNED_INT)     (round(val));
        break;

        case WT_RGB:
          _buffer_RGB[0]   = (FORMAT_UNSIGNED_CHAR)    (val+0.05);
          _buffer_RGB[1]   = (FORMAT_UNSIGNED_CHAR)    (val+0.05);
          _buffer_RGB[2]   = (FORMAT_UNSIGNED_CHAR)    (val+0.05);
        break;

        case WT_FLOAT_VECTOR:
      for(int i=0;i<_vdim;i++)
            _buffer_FLOAT_VECTOR[i]   = (FORMAT_FLOAT)    val;
        break;

        Defaut: printf("InrImage::FixeValeur()\t format non gere...\n");

      } // end switch

    } // FixeValeur()

    //
    void VectFixeValeurs( double valx, double valy, double valz)
    //   ---------------
    // Fixe la valeur de l'image au point courant du buffer
    {

      switch ( (WORDTYPE) _format ) {

        case WT_RGB:
          _buffer_RGB[0]   = (FORMAT_UNSIGNED_CHAR)    (valx+0.05);
          _buffer_RGB[1]   = (FORMAT_UNSIGNED_CHAR)    (valy+0.05);
          _buffer_RGB[2]   = (FORMAT_UNSIGNED_CHAR)    (valz+0.05);
        break;

        case WT_FLOAT_VECTOR:
          _buffer_FLOAT_VECTOR[0]   = (FORMAT_FLOAT)    valx;
          _buffer_FLOAT_VECTOR[1]   = (FORMAT_FLOAT)    valy;
          _buffer_FLOAT_VECTOR[2]   = (FORMAT_FLOAT)    valz;
        break;

        case WT_FLOAT:
          if (_vdim==3) {
            _buffer_FLOAT[0]   = (FORMAT_FLOAT)    valx;
            _buffer_FLOAT[1]   = (FORMAT_FLOAT)    valy;
            _buffer_FLOAT[2]   = (FORMAT_FLOAT)    valz;
          } else printf("VectFixeValeurs() _vdim!=3 \n");
        break;

        case WT_DOUBLE:
          if (_vdim==3) {
            _buffer_DOUBLE[0]   = (FORMAT_DOUBLE)    valx;
            _buffer_DOUBLE[1]   = (FORMAT_DOUBLE)    valy;
            _buffer_DOUBLE[2]   = (FORMAT_DOUBLE)    valz;
          } else printf("VectFixeValeurs() _vdim!=3 \n");
        break;


        Defaut: printf("InrImage::VectFixeValeur()\t format non gere...\n");

      } // end switch

    } // VectFixeValeurs()

    //
    void VectFixeValeur( unsigned char coord, double val)
    //   --------------
    // Fixe la valeur de l'image au point courant du buffer
    {

      switch ( (WORDTYPE) _format ) {

       case WT_DOUBLE:
          _buffer_DOUBLE[coord]   = (FORMAT_DOUBLE)    val;
       break;

       case WT_FLOAT:
          _buffer_FLOAT[coord]   = (FORMAT_FLOAT)    val;
       break;

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

        case WT_FLOAT_VECTOR:
          _buffer_FLOAT_VECTOR[coord]   = (FORMAT_FLOAT)    val;
        break;

        Defaut: printf("InrImage::VectFixeValeur()\t format non gere...\n");

      } // end switch

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
    double operator()( int x, int y, int z) throw (DepassementLimites)
    //         --------
    {

#ifdef _debug_
      Si x<0 Ou x>=_tx Ou y<0 Ou y>=_ty Ou z<0 Ou z>=_tz Alors
        char message[100];
        sprintf(message, " image %s ( %d %d %d )", (char*) _nom, x, y, z);
        throw DepassementLimites( message);
      FinSi
#endif

      switch ( (WORDTYPE) _format ) {

        case WT_DOUBLE:
          return (double)(_positions_DOUBLE[z][y][x]);

        case WT_FLOAT:
          return (double)(_positions_FLOAT [z][y][x]);

        case WT_RGB:
        case WT_UNSIGNED_CHAR:
           return (double)(_positions_UNSIGNED_CHAR   [z][y][x]);

        case WT_UNSIGNED_SHORT:
           return (double)(_positions_UNSIGNED_SHORT   [z][y][x]);

        case WT_SIGNED_SHORT:
           return (double)(_positions_SIGNED_SHORT  [z][y][x]);

        case WT_UNSIGNED_INT:
           return (double)(_positions_UNSIGNED_INT  [z][y][x]);

        case WT_SIGNED_INT:
           return (double)(_positions_SIGNED_INT  [z][y][x]);


        Defaut: printf("InrImage::operator()\t format non gere...\n");

      } // end switch

      return 0;

    }


    //  {\bf Operator(x,y,z) }
    double operator()( int x, int y) throw (DepassementLimites)
    //         --------
    {

#ifdef _debug_
      Si x<0 Ou x>=_tx Ou y<0 Ou y>=_ty  Alors
        char message[100];
        sprintf(message, " image %s ( %d %d  )", (char*) _nom, x, y);
        throw DepassementLimites( message);
      FinSi
#endif

      switch ( (WORDTYPE) _format ) {

        case WT_DOUBLE:
          return (double)(_positions_DOUBLE[0][y][x]);

        case WT_FLOAT:
          return (double)(_positions_FLOAT [0][y][x]);

        case WT_UNSIGNED_CHAR:
           return (double)(_positions_UNSIGNED_CHAR   [0][y][x]);

        case WT_UNSIGNED_SHORT:
           return (double)(_positions_UNSIGNED_SHORT   [0][y][x]);

        case WT_SIGNED_SHORT:
           return (double)(_positions_SIGNED_SHORT  [0][y][x]);

        case WT_UNSIGNED_INT:
           return (double)(_positions_UNSIGNED_INT  [0][y][x]);

        case WT_SIGNED_INT:
           return (double)(_positions_SIGNED_INT  [0][y][x]);

        Defaut: printf("InrImage::operator()\t format non gere...\n");

      } // end switch

      return 0;

    }


    //  {\em Operator(x,y,z,coord) }
    double GetValue( int x, int y, int z, int coord)
    //         --------
    {

      switch ( (WORDTYPE) _format ) {

        case WT_RGB:
          return (double)(_positions_RGB [z][y][3*x+coord]);

        case WT_FLOAT:
          return (double)(_positions_FLOAT[z][y][_vdim*x+coord]);
        case WT_DOUBLE:
          return (double)(_positions_DOUBLE[z][y][_vdim*x+coord]);

        case WT_FLOAT_VECTOR:
          return (double)(_positions_FLOAT_VECTOR [z][y][_vdim*x+coord]);

        case WT_RGBA:
        case WT_UNSIGNED_CHAR:
          return (double)(_positions_UNSIGNED_CHAR [z][y][_vdim*x+coord]);

        case WT_SIGNED_SHORT:
          return (double)(_positions_SIGNED_SHORT[z][y][_vdim*x+coord]);

        case WT_UNSIGNED_SHORT:
          return (double)(_positions_UNSIGNED_SHORT[z][y][_vdim*x+coord]);

        case WT_SIGNED_INT:
          return (double)(_positions_SIGNED_INT[z][y][_vdim*x+coord]);

        case WT_UNSIGNED_INT:
          return (double)(_positions_UNSIGNED_INT[z][y][_vdim*x+coord]);

        Defaut: printf("InrImage::operator(x,y,z,coord)\t format non gere...\n");

      } // end switch

      return 0;

    }

    //  {\em Operator(x,y,z,coord) }
    double operator()( int x, int y, int z, int coord)
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


  // Interpolation Lin�ire de l'intensit�au point (x,y,z)
  double InterpLinIntensite2( double dx1, double dx2, int tx1, int tx2)
  //   -------------------
  {


      register double coeff00,coeff01,coeff10,coeff11;
      register int     tx12;
      register double res = 0;

    coeff00 = 1.0 - dx1;
    coeff10 = dx1;

    coeff01 = coeff00 * dx2;
    coeff11 = coeff10 * dx2;

    coeff00 -= coeff01;
    coeff10 -= coeff11;

    tx12 = tx1+tx2;

#define MACRO_case_buffer(Format,Buf) \
\
      case Format: \
        Buf += _coord_vecteur; \
        res  =  coeff00* *(Buf)       + \
                coeff10* *(Buf+_vdim*tx1); \
        res +=  coeff01* *(Buf+_vdim*tx2) + \
                coeff11* *(Buf+_vdim*tx12); \
      break;


    switch ( (WORDTYPE) _format ) {

      MACRO_case_buffer(WT_DOUBLE,          _buffer_DOUBLE)
      MACRO_case_buffer(WT_FLOAT,           _buffer_FLOAT)
      MACRO_case_buffer(WT_UNSIGNED_CHAR,   _buffer_UNSIGNED_CHAR )
      MACRO_case_buffer(WT_UNSIGNED_SHORT,  _buffer_UNSIGNED_SHORT)
      MACRO_case_buffer(WT_SIGNED_SHORT,    _buffer_SIGNED_SHORT)
      MACRO_case_buffer(WT_UNSIGNED_INT,    _buffer_UNSIGNED_INT)
      MACRO_case_buffer(WT_SIGNED_INT,      _buffer_SIGNED_INT)
      MACRO_case_buffer(WT_RGB,             _buffer_RGB)
      MACRO_case_buffer(WT_FLOAT_VECTOR,    _buffer_FLOAT_VECTOR)

      Defaut: printf("InrImage::InterpLinIntensite2()\t format non gere...\n");

    } // end switch

#undef MACRO_case_buffer

    return res;

  } // InterpLinIntensite2()


  /** Interpolation Lineaire de l'intensite au point (x,y) avec z = 0
   en coordonnees reelles
   Prendre en compte la taille des voxels ???
   Pour une image 2D ...
  */
  double InterpLinIntensite( float x, float y)
  //         ------------------
  {

    Si (x < 0) Ou ( x >= _tx-1) Ou
       (y < 0) Ou ( y >= _ty-1)
    Alors
      int x1=(int)(x+0.5),y1=(int)(y+0.5);
      if (x<0)      x1 = 0;
      if (x>=_tx-1) x1 = _tx-1;
      if (y<0)      y1=0;
      if (y>=_ty-1) y1 = _ty-1;
      if (this->ScalarFormat())
        return (*this)(x1,y1);
      else
        return (*this)(x1,y1,0,_coord_vecteur);
    FinSi

    BufferPos( (int) x, (int) y, 0);
    return InterpLinIntensite2( (x-(int)x),
                  (y-(int)y),
                  1,_tx);

  } // InterpLinIntensite(x,y)


  /** Interpolation Lin�ire de l'intensit�au point (x,y,z)
   en coordonn�s r�lles
   Prendre en compte la taille des voxels ???
   Pour une image 3D ...
  */
  double InterpLinIntensite( float x, float y, float z)
  //         ------------------
  {

      register int     xi,yi,zi;
      register double dx,dy,dz;
      register double res = 0;
      register double coeff000,coeff010,coeff100,coeff110;
      register double coeff001,coeff011,coeff101,coeff111;

    Si _tz == 1 AlorsRetourne InterpLinIntensite(x,y);

    Si (x < 0)      AlorsFait x= (float) 0.0;
    Si (y < 0)      AlorsFait y= (float) 0.0;
    Si (z < 0)      AlorsFait z= (float) 0.0;
    Si ( x > _tx-1) AlorsFait x= (float) _tx-1;
    Si ( y > _ty-1) AlorsFait y= (float) _ty-1;
    Si ( z > _tz-1) AlorsFait z= (float) _tz-1;

    xi = (int) x;
    yi = (int) y;
    zi = (int) z;

    dx = x - (double)xi;
    dy = y - (double)yi;
    dz = z - (double)zi;

    Si xi == _tx-1 Alors      xi = _tx-2;      dx = 1.0;    FinSi
    Si yi == _ty-1 Alors      yi = _ty-2;      dy = 1.0;    FinSi
    Si zi == _tz-1 Alors      zi = _tz-2;      dz = 1.0;    FinSi

    Si dx < 1E-10 Alors
      BufferPos(xi,yi,zi);
      return  InterpLinIntensite2(dy,dz,_tx,_txy);
    FinSi

    Si dy < 1E-10 Alors
      BufferPos(xi,yi,zi);
      return InterpLinIntensite2(dx,dz,1,_txy);
    FinSi

    Si dz < 1E-10 Alors
      BufferPos(xi,yi,zi);
      return InterpLinIntensite2(dx,dy,1,_tx);
    FinSi

    /*--- calcul des poids associ� �chaque point ---*/
    // 16 multiplication, 12 additions, 8 affectations
    // coeff000 = (1.0 - dx) * (1.0 - dy) * (1.0 - dz);
    // coeff100 = dx         * (1.0 - dy) * (1.0 - dz);
    // coeff010 = (1.0 - dx) * dy         * (1.0 - dz);
    // coeff110 = dx         * dy         * (1.0 - dz);
    // coeff001= (1.0 - dx) * (1.0 - dy)  * dz;
    // coeff101 = dx         * (1.0 - dy) * dz;
    // coeff011 = (1.0 - dx) * dy         * dz;
    // coeff111 = dx         * dy         * dz;


    // 6 multiplication, 7 additions, 14 affectations
    coeff000 = 1.0 - dx;
    coeff100 = dx;

    coeff010 = coeff000 * dy;
    coeff110 = coeff100 * dy;

    coeff000 -= coeff010;
    coeff100 -= coeff110;

    coeff001 = coeff000*dz;
    coeff101 = coeff100*dz;
    coeff011 = coeff010*dz;
    coeff111 = coeff110*dz;

    coeff000 -= coeff001;
    coeff100 -= coeff101;
    coeff010 -= coeff011;
    coeff110 -= coeff111;

// BufferPos(xi,yi,zi);
// res  = coeff000*ValeurBuffer()       + coeff100*ValeurBuffer(1);
// res += coeff010*ValeurBuffer(tx)     + coeff110*ValeurBuffer(tx+1);
// res += coeff001*ValeurBuffer(txy)    + coeff101*ValeurBuffer(txy+1);
// res += coeff011*ValeurBuffer(txy+tx) + coeff111*ValeurBuffer(txy+tx+1);

#define MACRO_case_buffer(Format,Pos,Buf) \
\
    case Format: \
      Buf = (  Pos[zi][yi] + _vdim*xi + _coord_vecteur); \
      res  =  coeff000* *(Buf) + \
              coeff100* *(Buf +_vdim); \
      res +=  coeff010* *(Buf +_vdim*_tx) + \
              coeff110* *(Buf +_vdim*(_tx+1)); \
      res +=  coeff001* *(Buf +_vdim*_txy ) + \
              coeff101* *(Buf +_vdim*(_txy+1)); \
      res +=  coeff011* *(Buf +_vdim*(_txy+_tx)) + \
              coeff111* *(Buf +_vdim*(_txy+_tx+1)); \
    break;


    //--- Calcul de l'intensit�
    switch ( (WORDTYPE) _format ) {

      MACRO_case_buffer(WT_DOUBLE,        _positions_DOUBLE,        _buffer_DOUBLE)
      MACRO_case_buffer(WT_FLOAT,         _positions_FLOAT,         _buffer_FLOAT)
      MACRO_case_buffer(WT_UNSIGNED_CHAR, _positions_UNSIGNED_CHAR, _buffer_UNSIGNED_CHAR)
      MACRO_case_buffer(WT_SIGNED_SHORT,  _positions_SIGNED_SHORT,  _buffer_SIGNED_SHORT)
      MACRO_case_buffer(WT_UNSIGNED_SHORT,_positions_UNSIGNED_SHORT,_buffer_UNSIGNED_SHORT)
      MACRO_case_buffer(WT_SIGNED_INT,    _positions_SIGNED_INT,    _buffer_SIGNED_INT)
      MACRO_case_buffer(WT_UNSIGNED_INT,  _positions_UNSIGNED_INT,  _buffer_UNSIGNED_INT)
      MACRO_case_buffer(WT_RGB,           _positions_RGB,           _buffer_RGB)
      MACRO_case_buffer(WT_FLOAT_VECTOR,  _positions_FLOAT_VECTOR,  _buffer_FLOAT_VECTOR)

      Defaut: printf("InrImage::InterpLinIntensite()\t format non gere...\n");

    } // end switch

#undef MACRO_case_buffer

    return res;

  } // InterpLinIntensite()


  /** Interpolation Lineaire de l'intensite au point (x,y,z)
   en coordonnees reelles
   Prendre en compte la taille des voxels ???
   Pour une image 3D ...
  */
  double InterpLinIntensite( float x, float y, float z, int coord)
  //         ------------------
  {
    this->FixeVecteurCoord(coord);
    return this->InterpLinIntensite(x,y,z);
  }

  //
  void VoisinageYZ( int x, int y, int z, float** vois)
  //   -----------
  {

    switch ( (WORDTYPE) _format ) {

      case WT_DOUBLE:
        vois[0][0] = (float)_positions_DOUBLE[z]  [y]  [x];
        vois[0][1] = (float)_positions_DOUBLE[z+1][y]  [x];
        vois[1][0] = (float)_positions_DOUBLE[z]  [y+1][x];
        vois[1][1] = (float)_positions_DOUBLE[z+1][y+1][x];
      break;

      case WT_FLOAT:
        vois[0][0] = (float)_positions_FLOAT[z]  [y]  [x];
        vois[0][1] = (float)_positions_FLOAT[z+1][y]  [x];
        vois[1][0] = (float)_positions_FLOAT[z]  [y+1][x];
        vois[1][1] = (float)_positions_FLOAT[z+1][y+1][x];
      break;

      case WT_UNSIGNED_CHAR:
        vois[0][0] = (float)_positions_UNSIGNED_CHAR[z]  [y]  [x];
        vois[0][1] = (float)_positions_UNSIGNED_CHAR[z+1][y]  [x];
        vois[1][0] = (float)_positions_UNSIGNED_CHAR[z]  [y+1][x];
        vois[1][1] = (float)_positions_UNSIGNED_CHAR[z+1][y+1][x];
      break;

      case WT_SIGNED_SHORT:
        vois[0][0] = (float)_positions_SIGNED_SHORT[z]  [y]  [x];
        vois[0][1] = (float)_positions_SIGNED_SHORT[z+1][y]  [x];
        vois[1][0] = (float)_positions_SIGNED_SHORT[z]  [y+1][x];
        vois[1][1] = (float)_positions_SIGNED_SHORT[z+1][y+1][x];
      break;

      case WT_UNSIGNED_SHORT:
        vois[0][0] = (float)_positions_UNSIGNED_SHORT[z]  [y]  [x];
        vois[0][1] = (float)_positions_UNSIGNED_SHORT[z+1][y]  [x];
        vois[1][0] = (float)_positions_UNSIGNED_SHORT[z]  [y+1][x];
        vois[1][1] = (float)_positions_UNSIGNED_SHORT[z+1][y+1][x];
      break;

      case WT_SIGNED_INT:
        vois[0][0] = (float)_positions_SIGNED_INT[z]  [y]  [x];
        vois[0][1] = (float)_positions_SIGNED_INT[z+1][y]  [x];
        vois[1][0] = (float)_positions_SIGNED_INT[z]  [y+1][x];
        vois[1][1] = (float)_positions_SIGNED_INT[z+1][y+1][x];
      break;

      Defaut: printf("InrImage::VoisinageYZ()\t format non gere...\n");

    } // end switch

  } // VoisinageYZ()

  float** create_float_positions_2D(int order=0);
  void    free_float_positions_2D(float** pos, int order=0);

  template <class T>  T*** create_positions_3D();

  template <class T>  void free_positions_3D(T*** pos);

  //@}

}; // InrImage


InrImage* operator-(  InrImage& i1,  InrImage& i2);
//

InrImage* operator-(  InrImage& i, double r );
//

InrImage* operator+(  InrImage& i1,  InrImage& i2);
//


InrImage* operator*(  InrImage& i1,  InrImage& i2);
//

InrImage* operator/(  InrImage& i1,  InrImage& i2);
//

// Vectorial product
InrImage* operator^(  InrImage& i1,  InrImage& i2);
//

// Norm (for vectorial images) or absolute value for scalars
InrImage* Norm(  InrImage& i1);

//
//
//

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

  switch ( (WORDTYPE) _format ) {

    case WT_DOUBLE:
      register FORMAT_DOUBLE*         buf_DOUBLE;

      buf_DOUBLE = (FORMAT_DOUBLE*) this->GetData();
      *min = *max = (float) (*buf_DOUBLE);
      DebutBoucle n=0 ItererTantQue n < size Pas n++ Faire
        Si *buf_DOUBLE < *min AlorsFait *min =(float)  *buf_DOUBLE;
        Si *buf_DOUBLE > *max AlorsFait *max =(float)  *buf_DOUBLE;
        buf_DOUBLE++;
      FinBoucle // n

    break;

    case WT_FLOAT:
      register  FORMAT_FLOAT*          buf_FLOAT;
      buf_FLOAT = (FORMAT_FLOAT*) this->GetData();
      *min = *max = *buf_FLOAT;
      DebutBoucle n=0 ItererTantQue n < size Pas n++ Faire
        Si *buf_FLOAT < *min AlorsFait *min = *buf_FLOAT;
        Si *buf_FLOAT > *max AlorsFait *max = *buf_FLOAT;
        buf_FLOAT++;
      FinBoucle // n

    break;

    case WT_UNSIGNED_CHAR:
      register FORMAT_UNSIGNED_CHAR*  buf_UNSIGNED_CHAR;

      buf_UNSIGNED_CHAR = (FORMAT_UNSIGNED_CHAR*) this->GetData();
      *min = *max = (float) *buf_UNSIGNED_CHAR;
      DebutBoucle n=0 ItererTantQue n < size Pas n++ Faire
        Si *buf_UNSIGNED_CHAR < *min AlorsFait *min = (float) *buf_UNSIGNED_CHAR;
        Si *buf_UNSIGNED_CHAR > *max AlorsFait *max = (float) *buf_UNSIGNED_CHAR;
        buf_UNSIGNED_CHAR++;
      FinBoucle // n

    break;

    case WT_UNSIGNED_SHORT:
      register FORMAT_UNSIGNED_SHORT* buf_UNSIGNED_SHORT;

      buf_UNSIGNED_SHORT = (FORMAT_UNSIGNED_SHORT*) this->GetData();
      *min = *max = (float) *buf_UNSIGNED_SHORT;
      DebutBoucle n=0 ItererTantQue n < size Pas n++ Faire
        Si *buf_UNSIGNED_SHORT < *min AlorsFait *min = (float) *buf_UNSIGNED_SHORT;
        Si *buf_UNSIGNED_SHORT > *max AlorsFait *max = (float) *buf_UNSIGNED_SHORT;
        buf_UNSIGNED_SHORT++;
      FinBoucle // n

    break;

    case WT_SIGNED_SHORT:
      register FORMAT_SIGNED_SHORT*   buf_SIGNED_SHORT;

      buf_SIGNED_SHORT = (FORMAT_SIGNED_SHORT*) this->GetData();
      *min = *max = (float) *buf_SIGNED_SHORT;
      DebutBoucle n=0 ItererTantQue n < size Pas n++ Faire
        Si *buf_SIGNED_SHORT < *min AlorsFait *min = (float) *buf_SIGNED_SHORT;
        Si *buf_SIGNED_SHORT > *max AlorsFait *max = (float) *buf_SIGNED_SHORT;
        buf_SIGNED_SHORT++;
      FinBoucle // n

    break;

    case WT_UNSIGNED_INT:
      register FORMAT_UNSIGNED_INT*   buf_UNSIGNED_INT;

      buf_UNSIGNED_INT = (FORMAT_UNSIGNED_INT*) this->GetData();
      *min = *max = (float) *buf_UNSIGNED_INT;
      DebutBoucle n=0 ItererTantQue n < size Pas n++ Faire
        Si *buf_UNSIGNED_INT < *min AlorsFait *min = (float) *buf_UNSIGNED_INT;
        Si *buf_UNSIGNED_INT > *max AlorsFait *max = (float) *buf_UNSIGNED_INT;
        buf_UNSIGNED_INT++;
      FinBoucle // n

    break;

    case WT_SIGNED_INT:
      register FORMAT_SIGNED_INT*   buf_SIGNED_INT;

      buf_SIGNED_INT = (FORMAT_SIGNED_INT*) this->GetData();
      *min = *max = (float) (*buf_SIGNED_INT);
      DebutBoucle n=0 ItererTantQue n < size Pas n++ Faire
        Si *buf_SIGNED_INT < *min AlorsFait *min = (float) (*buf_SIGNED_INT);
        Si *buf_SIGNED_INT > *max AlorsFait *max = (float) (*buf_SIGNED_INT);
        buf_SIGNED_INT++;
      FinBoucle // n

    break;

    case WT_RGB:
    case WT_RGBA:

      *min = 0;
      *max = 255;

    break;

    Defaut: printf("InrImage::MinMax()\t format non gere..\n");

  } // end switch

  return;

} // MinMax()

#endif // _INRIMAGE_HPP
