/***************************************************************************
 * $Author: karl $
 * $Revision: 1.1.1.1 $
 * $Log: ImageIO.h,v $
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:11:43  karl
 * Sources code
 *
 * Revision 1.3  1998/09/24 20:40:11  jmontagn
 * Added typedef for (de)allocation routines
 *
 * Revision 1.2  1998/09/15 15:23:46  jmontagn
 * Suppressed any malloc/free from C++ code
 *
 * Revision 1.1  1998/09/14 09:08:47  jmontagn
 * Moved ImageIO routines to CVS base
 *
 * Revision 1.8  1998/07/29  08:34:48  jmontagn
 * Added imageType() function
 *
 * Revision 1.7  1998/07/28  11:43:58  aguimond
 * Added analyze image format.
 * Added _openWriteImage().
 * Renamed _openImage() to _openReadImage().
 *
 * Revision 1.6  1998/07/27 09:01:57  jmontagn
 * Added RCS header keywords
 *
 *
 * $Id: ImageIO.h,v 1.1.1.1 2004/02/02 20:47:09 karl Exp $
 ***************************************************************************/

#ifndef IMAGEIO_H
#define IMAGEIO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "AMILabConfig.h"

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifdef _SGI_
  extern FILE     *popen(const char *, const char *);
  /* popen prototype is not defined on SGI */
#endif


#if (defined _ALPHA_ || (defined _SGI_ && (defined _64_ || defined _64_M4_ || defined _64_M3_)))
#define LONG long int
/* 64 bits integer on 64 bits processor */
#else
#define LONG long long int
/* 64 bits integer on 32 bits processor */
#endif



#define PACK_MAGIC     "\037\036"
/* Magic header for packed files */

#define GZIP_MAGIC     "\037\213"
/* Magic header for gzip files, 1F 8B */

#define OLD_GZIP_MAGIC "\037\236"
/* Magic header for gzip 0.5 = freeze 1.x */

#define LZH_MAGIC      "\037\240"
/* Magic header for SCO LZH Compress files*/

#define PKZIP_MAGIC    "\120\113\003\004"
/* Magic header for pkzip files */

#define LZW_MAGIC      "\037\235"
/* Magic header for lzw files, 1F 9D */

#define INR_MAGIC "#INR"
/* Magic header for inrimages */

#define GIF_MAGIC "GIF8"
/* Magic header for GIF files */

#define IRIS_MAGIC 0732
/* Magic header for RGB files */

#define ANALYZE_LE_MAGIC "\000\000\001\134"
/* Magic header for ANALYZE files written in little endian format */

#define ANALYZE_BE_MAGIC "\134\001\000\000"
/* Magic header for ANALYZE files written in big endian format */


typedef enum {
  OM_CLOSE,       /* no file open */
  OM_STDIN,       /* file is stdin or stdout */
  OM_PIPE,        /* file is a pipe */
  OM_FILE         /* file is standard */
} OPEN_MODE;
/* file open mode */


typedef enum {
  WK_FIXED,       /* fixed type */
  WK_FLOAT,       /* floating point */
  WK_UNKNOWN      /* unknown (uninitialized) */
} WORD_KIND;
/* kind of image word */


typedef enum {
  SGN_SIGNED,     /* signed */
  SGN_UNSIGNED,   /* unsigned */
  SGN_UNKNOWN     /* unknown (uninitialized or floating point words) */
} SIGN;
/* image word sign */


typedef enum {
  END_LITTLE,        /* Little endian processor */
  END_BIG,           /* Big endian processor */
  END_UNKNOWN        /* Unknown endianness (unopenned file) */
} ENDIANNESS;
/* endianness */


typedef enum {
  VM_INTERLACED,
  VM_NON_INTERLACED,
  VM_SCALAR
} VECTORIAL_MODE;


typedef enum {
  IF_UNKNOWN,
  IF_INR,			/* inrimage format */
  IF_INR_GZ,			/* gzipped inrimage format */
  IF_GIF,			/* gif format */
  IF_IRIS,			/* iris format */
  IF_ANALYZE			/* ANALYZE format order */
} IMAGE_FORMAT;
/* the file format to use */


typedef struct {
  unsigned int xdim;       /* Image x dimension (number of columns) */
  unsigned int ydim;       /* Image y dimension (number of rows) */
  unsigned int zdim;       /* Image z dimension (number of planes) */
  unsigned int vdim;       /* Image vectorial dimension */

  float vx;                /* Image voxel size in x dimension */
  float vy;                /* Image voxel size in y dimension */
  float vz;                /* Image voxel size in z dimension */

  void *data;              /* Image data buffer */

  unsigned int wdim;       /* Image word size (in bytes) */
  IMAGE_FORMAT imageFormat;  /* Image format to use for I/0. Should not be set by user. */
  VECTORIAL_MODE vectMode; /* Data buffer vectors are interlaced or
			      non interlaced */
  WORD_KIND wordKind;      /* Image word kind */
  SIGN sign;               /* Image word sign */

  char **user;            /* User defined strings array.<br>
			     The user can use any internal purpose string.<br>
			     Each string is written at then end of header<br>
			     after a '#' character. */
  unsigned int nuser;     /* Number of user strings */

  FILE *fd;               /* Image file descriptor */
  OPEN_MODE openMode;     /* Kind of image file descriptor */
  ENDIANNESS endianness;  /* Written words endianness */
} _image;
/* Image descriptor */



_image *_initImage();
/* Allocates and initializes an image descriptor */

void _freeImage(_image *im /* image descriptor */);
/* Free an image descriptor */

_image *_createImage(int x /* image x dimension (number of columns) */,
		     int y /* image y dimension (number of rows) */,
		     int z /* image z dimension (number of planes) */,
		     int v /* image vectorial dimension */,
		     float vx /* image voxel size in x dimension */,
		     float vy /* image voxel size in y dimension */,
		     float vz /* image voxel size in z dimension */,
		     int w /* image word size in bytes */,
		     WORD_KIND wk /* image word kind */,
		     SIGN sgn /* image word sign */);
/* creates an image descriptor from the given header information */


_image* _readImage(const char *name /* image file name or NULL */);
/* Reads an image from a file and returns an image descriptor or NULL if<br>
   reading failed.<br>
   Reads from stdin if image name is NULL.
   The image data field points to a xdim * ydim * zdim * vdim buffer
   containing voxels in order:<pre>
     (Z1, Y1, X1, V1) (Z1, Y1, X1, V2), ... , (Z1, Y1, X1, Vt),
     (Z1, Y1, X2, V1) ...         ...       , (Z1, Y1, X2, Vt),
     ...
     (Z1, Y2, X1, V1) ...         ...       , (Z1, Y2, X1, Vt),
     ...
     (Z2, Y1, X1, V1) ...         ...       , (Z2, Y1, X1, Vt),
     ...
                      ...         ...       , (Zl, Ym, Xn, Vt)</pre>*/

_image* _readNonInterlacedImage(const char *name /* image file name or NULL */);
/* Reads an image from a file and returns an image descriptor or NULL if<br>
   reading failed.<br>
   Reads from stdin if image name is NULL.
   If the image is vectorial, it is uninterlaced, i.e. the image data
   field points to a xdim * ydim * zdim * vdim buffer containing voxels
   in order:<pre>
     (V1, Z1, Y1, X1) (V1, Z1, Y1, X2), ... , (V1, Z1, Y1, Xn),
     (V1, Z1, Y2, X1) ...         ...       , (V1, Z1, Y2, Xn),
     ...
     (V1, Z2, Y1, X1) ...         ...       , (V1, Z2, Y1, Xn),
     ...
     (V2, Z1, Y1, X1) ...         ...       , (V2, Z1, Y1, Xn),
     ...
                      ...         ...       , (Vt, Zl, Ym, Xn)</pre>*/

int _writeImage(_image *im /* image descriptor */,
		const char *name /* file name to store image or NULL */);
/* Writes given image in file 'name'.<br>
   If name ends with '.gz', file is gzipped.<br>
   If name is NULL, image is sent to stdout.*/

void _getNextSlice(_image *im /* image descriptor */);
/* Read one slice of given image whose header has already been read.<br>
   File descriptor is let at the beginning of next slice and closed<br>
   when end of file is encountered.<br>
   If data buffer is NULL, it is allocated for one slice only.<br>
   This funtion is dedicated to read huge inrimages.*/



_image* _readImageHeader(const char *name /* image file name or NULL*/);
/* Reads header from an image file<br>
   If file is an inrimage, only header is read. Otherwise, whole image<br>
   is read and image file descriptor is closed.<br>
   If name is NULL, header is read from STDIN */

int _readImageData(_image *im /* image descriptor */);
/* Reads body from an inrmage whose header has been read by _readImageHeader */

int _readNonInterlacedImageData(_image *im /* image descriptor */);
/* Reads body from a vectorial inrimage whose header has been read by
   _readImageHeader. The image is uninterlaced
   (see _readNonInterlacedImage for details). */

int _writeInrimageHeader(const _image *im /* image descriptor */);
/* Writes the given inrimage header in an already opened file.*/

int _writeInrimageData(const _image *im /* image descriptor */);
/* Writes the given image body in an already opened file.*/



void _openWriteImage(_image* im /* initialized image descriptor */,
		     const char *name /* image file name */ ) ;
/* given an initialized file descriptor and a file name, open file
   from stdout (if name == NULL), a gziped pipe (if file is gziped)
   or a standard file otherwise. */

void _openReadImage(_image *im /* initialized image descriptor */,
		const char *name /* image file name */);
/* open an image file from stdin (if name == NULL), from a pipe
   (piped with gzip if image was compressed) or from a standard file */

void _closeImage(_image *im /* opened image descriptor */);
/* close an image file descriptor that was opened using _openImage */

int readInrimageHeader(_image *im /* opened inrmage descriptor */);
/* read header from an opened inrimage file */


IMAGE_FORMAT imageType(const char *fileName /* image file name */);
/* return image type in given file */


typedef void *(*ALLOCATION_FUNCTION)(size_t);
/* function prototype to allocate memory */

typedef void (*DEALLOCATION_FUNTION)(void *);
/* function prototype to free memory */


void setImageIOAllocationRoutines(ALLOCATION_FUNCTION alloc /* new allocation routine */,
				  DEALLOCATION_FUNTION del   /* new deallocation routine*/);
/* set allocation and deallocation routines */

#ifdef __cplusplus
}
#endif

#endif
