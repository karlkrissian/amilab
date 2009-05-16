/***************************************************************************
 * $Author: karl $
 * $Revision: 1.1.1.1 $
 * $Log: ImageIO.c,v $
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:11:42  karl
 * Sources code
 *
 * Revision 1.5  1998/09/24 20:39:39  jmontagn
 * Added typedef for (de)allocation routines
 *
 * Revision 1.4  1998/09/21 14:32:08  jmontagn
 * Improved exception management.
 *
 * Revision 1.3  1998/09/15 15:23:42  jmontagn
 * Suppressed any malloc/free from C++ code
 *
 * Revision 1.2  1998/09/14 09:08:41  jmontagn
 * Moved ImageIO routines to CVS base
 *
 * Revision 1.1.1.1  1998/07/31 20:09:12  jmontagn
 * Initialized libInrimage module
 *
 * Revision 1.6  1998/07/29  08:34:48  jmontagn
 * Added imageType() function
 *
 * Revision 1.5  1998/07/28  11:43:58  aguimond
 * Added analyze image format.
 * Added _openWriteImage().
 * Renamed _openImage() to _openReadImage().
 *
 * Revision 1.4  1998/07/27 09:00:31  jmontagn
 * fixed return value for _writeInrimageData when writting non-interlaced vectorial images
 *
 *
 * $Id: ImageIO.c,v 1.1.1.1 2004/02/02 20:47:09 karl Exp $
 ***************************************************************************/

#include <ImageIO.h>
//#include "gif.h"
//#include "iris.h"
//#include "analyze.h"



#if (defined (_ALPHA_) || defined (_LINUX_))
#define ARCHITECTURE_ENDIANNESS END_LITTLE
#else
#define ARCHITECTURE_ENDIANNESS END_BIG
#endif
/* compile time endianness */


#define INR4_MAGIC "#INRIMAGE-4#{"
/* Magic header for inrimages v4 */

#ifdef _MSC_VER
  #define popen  _popen
  #define pclose _pclose
#endif

typedef struct stringListElementStruct {
  char *string;
  struct stringListElementStruct *next;
} stringListElement;
/* list element with a pointer on a string */

typedef struct {
  stringListElement *begin, *end;
} stringListHead;
/* string list descriptor */

static void addStringElement(stringListHead *strhead,
			     const char *str);
/* add a string element at the tail of given list */

static void concatStringElement(const stringListHead *strhead,
				const char *str);
/* concat given string at the last element of given list */

static char *fgetns(char *str, int n, FILE *f);
/* get a string from a file and discard the ending newline character
   if any */


/* default allocation routine */
static void *(*allocRoutine)(size_t) = malloc;
/* default deallocation routine */
static void (*deleteRoutine)(void *) = free;

/* set allocation and deallocation routines */
void setImageIOAllocationRoutines(ALLOCATION_FUNCTION alloc,
				  DEALLOCATION_FUNTION del) {
  if(alloc != NULL) allocRoutine = alloc;
  if(del != NULL) deleteRoutine = del;
}


/* Allocates and initializes an image descriptor */
_image *_initImage() {
  _image *im;

  im = (_image *) (*allocRoutine)(sizeof(_image));

  /* default image size is 1*1*1 */
  im->xdim = im->ydim = im->zdim = im->vdim = 1;
  /* default image voxel size is 1.0*1.0*1.0 */
  im->vx = im->vy = im->vz = 1.0;

  /* no data yet */
  im->data = NULL;

  /* no file associated to image */
  im->fd = NULL;
  im->openMode = OM_CLOSE;
  im->endianness = END_UNKNOWN;

  /* no user string */
  im->user = NULL;
  im->nuser = 0;

  /* unknown word kind */
  im->wdim = 0;
  im->wordKind = WK_UNKNOWN;
  im->vectMode = VM_SCALAR;
  im->sign = SGN_UNKNOWN;
  im->imageFormat = IF_UNKNOWN;

  /* return image descriptor */
  return im;
}



/* Free an image descriptor */
void _freeImage(_image *im) {
  int i;

  /* close image if opened */
  if(im->openMode != OM_CLOSE) _closeImage(im);

  /* free data if any */
  if(im->data) (*deleteRoutine)(im->data);

  /* free user string array if any */
  if(im->nuser > 0) {
    for(i = 0; i < im->nuser; i++)
      (*deleteRoutine)(im->user[i]);
    (*deleteRoutine)(im->user);
  }

  /* free given descriptor */
  (*deleteRoutine)(im);
}




/* creates an image descriptor from the given header information */
_image *_createImage(int x, int y, int z, int v,
		     float vx, float vy, float vz,
		     int w, WORD_KIND wk, SIGN sgn) {
  _image *im;

  im = (_image *) (*allocRoutine)(sizeof(_image));

  /* image size */
  im->xdim = x;
  im->ydim = y;
  im->zdim = z;
  im->vdim = v;
  /* image voxel size */
  im->vx = vx;
  im->vy = vy;
  im->vz = vz;

  /* no file associated to image */
  im->fd = NULL;
  im->openMode = OM_CLOSE;
  im->endianness = END_UNKNOWN;
  im->imageFormat = IF_INR;

  /* no user string */
  im->user = NULL;
  im->nuser = 0;

  /* unknown word kind */
  im->wdim = w;
  im->wordKind = wk;
  im->sign = sgn;

  /* default vectors setting: interlaced */
  if(im->vdim == 1)
    im->vectMode = VM_SCALAR;
  else
    im->vectMode = VM_INTERLACED;

  /* no data yet */
  im->data = (*allocRoutine)(x * y * z * v * w);
#ifndef WIN32
  bzero((char *) im->data, x * y * z * v * w);
#else
  memset((char *) im->data,0, x * y * z * v * w);
#endif

  /* return image descriptor */
  return im;
}







/* Reads an image from a file and returns an image descriptor or NULL if
   reading failed.
   Reads from stdin if image name is NULL. */
_image* _readImage(const char *name) {
  _image *im;

  /* read header */
  im = _readImageHeader(name);

  if(im && im->openMode != OM_CLOSE) {
    /* read body */
    if(_readImageData(im) < 0) {
      fprintf(stderr, "_readImage: error: invalid data encountered in \'%s\'\n",
	      name);
      _freeImage(im);
      return NULL;
    }
    _closeImage(im);
  }

  return im;
}


/* Reads an image from a file and returns an image descriptor or NULL if<br>
   reading failed.<br>
   Reads from stdin if image name is NULL.
   If the image is vectorial, it is uninterlaced. */
_image* _readNonInterlacedImage(const char *name) {
  _image *im;

  /* read header */
  im = _readImageHeader(name);

  if(im && im->openMode != OM_CLOSE) {
    /* read scalar image body */
    if(im->vdim == 1) {
      if(_readImageData(im) < 0) {
	fprintf(stderr, "_readImage: error: invalid data encountered in \'%s\'\n",
		name);
	_freeImage(im);
	return NULL;
      }
    }
    /* read vectorial image body */
    else {
      im->vectMode = VM_NON_INTERLACED;
      if(_readNonInterlacedImageData(im) < 0) {
	fprintf(stderr, "_readImage: error: invalid data encountered in \'%s\'\n",
		name);
	_freeImage(im);
	return NULL;
      }
    }
    _closeImage(im);
   }

  return im;
}


/* Write inrimage given in inr in file name. If file name's suffix is
   .gz, the image is gziped. If file name's suffix is .hdr, the image
   is written in ANALYZE format. If file name is NULL, image is written
   on stdout */
int _writeImage ( _image *im, const char *name )
{
  int r = 1;

  /* open file descriptor */
  _openWriteImage ( im, name ) ;

  if ( !im->fd )
  {
    fprintf ( stderr, "_writeImage: error: open failed\n" );
    return -1;
  }

  printf ( "_writeImage() \t %s \n",name );


  switch ( im->imageFormat )
  {

    case IF_INR:
    case IF_INR_GZ:
    case IF_GIF:
    case IF_IRIS:
    default:
      /* write header */
      if ( _writeInrimageHeader ( im ) < 0 )
      {
        fprintf ( stderr, "_writeImage: error: unable to write header of \'%s\'\n",
                  name );
        r = -1;
      }

      /* write body */
      else if ( _writeInrimageData ( im ) < 0 )
      {
        fprintf ( stderr, "_writeImage: error: unable to write data of \'%s\'\n",
                  name );
        r = -1;
      }
      break ;
  }


  /* close file descriptor */
  switch ( im->openMode )
  {
    case OM_STDIN:
    case OM_CLOSE:
      break;
    case OM_PIPE:
      fflush ( im->fd );
      pclose ( im->fd );
      break;
    case OM_FILE:
      fclose ( im->fd );
      break;
  }

  im->fd = NULL;
  im->openMode = OM_CLOSE;

  return r;
}



/* read header from an image file */
_image *_readImageHeader ( const char *name )
{
  _image *im;
  char magic[5];
  int res;

  /* open image file */
  im = _initImage();
  _openReadImage ( im, name );

  if ( !im->fd )
  {
    fprintf ( stderr, "_readImageHeader: error: unable to open file \'%s\'\n", name );
    _freeImage ( im );
    return NULL;
  }

  else
  {

    /* read magic number */
    fread ( ( void * ) magic, 4, 1, im->fd );
    magic[4] = '\0';

    /* unread magic bytes */
    switch ( im->openMode )
    {
        /* unread from a file */
      case OM_FILE:
        fseek ( im->fd, 0L, SEEK_SET );
        break;

        /* unread from stdin or a pipe */
      case OM_STDIN:
      case OM_PIPE:
        ungetc ( magic[3], im->fd );
        ungetc ( magic[2], im->fd );
        ungetc ( magic[1], im->fd );
        ungetc ( magic[0], im->fd );
        break;

        /* cannot happen */
      case OM_CLOSE:
        break;
    }

    /* openned image is an inrimage */
    if ( !strcmp ( magic, INR_MAGIC ) )
    {
      if ( readInrimageHeader ( im ) < 0 )
      {
        fprintf ( stderr, "_readImageHeader: error: invalid inrimage header encountered in \'%s\'\n", name );
        _freeImage ( im );
        return NULL;
      }
      im->imageFormat = IF_INR;
    }
        else
        {

      /*  fprintf(stderr,
        "_readImageHeader: error: unknown image type \'%s\'\n", name);
      */
      _freeImage ( im );
      return NULL;

    /* close image file and return */
    if ( res > 0 )
    {
      _closeImage ( im );
      im->fd = NULL;
      im->openMode = OM_CLOSE;
    }
    else
    {
      _freeImage ( im );
      fprintf ( stderr,
                "_readImageHeader: error: invalid file \'%s\' encountered\n", name );
      return NULL;
    }

  }

}

return im;
}



/* Read data of an inrimage.
   If im->data is not NULL, assume that the buffer was previously allocated
   Swap bytes depending on the endianness and the current architecture  */
int _readImageData(_image *im) {
  unsigned LONG size, nread, length;
  unsigned char *ptr1, *ptr2, b[8];

  if(im->openMode != OM_CLOSE) {
    size = im->xdim * im->ydim * im->zdim * im->vdim * im->wdim;

    if(!im->data) {
      im->data = (unsigned char *) (*allocRoutine)(size);
      if(!im->data) return -2;
    }

    nread = fread(im->data, 1, size, im->fd);
    if(nread != size) return -1;

  
    /* architecture is big endian and data little endian */
    if(ARCHITECTURE_ENDIANNESS != im->endianness) {
      
      length = size / im->wdim;
      ptr1 = ptr2 = (unsigned char *) im->data;
	
      /* 2 bytes swap */
      if(im->wdim == 2) {
	while(length--) {
	  b[0] = *ptr1++;
	  b[1] = *ptr1++;
	  *ptr2++ = b[1];
	  *ptr2++ = b[0];
	}
      }
      
      /* 4 bytes swap */
      else if(im->wdim == 4) {
	while(length--) {
	  b[0] = *ptr1++;
	  b[1] = *ptr1++;
	  b[2] = *ptr1++;
	  b[3] = *ptr1++;
	  *ptr2++ = b[3];
	  *ptr2++ = b[2];
	  *ptr2++ = b[1];
	  *ptr2++ = b[0];
	}
      }
      
      /* 8 bytes swap */
      else if(im->wdim == 8) {
	while(length--) {
	  b[0] = *ptr1++;
	  b[1] = *ptr1++;
	  b[2] = *ptr1++;
	  b[3] = *ptr1++;
	  b[4] = *ptr1++;
	  b[5] = *ptr1++;
	  b[6] = *ptr1++;
	  b[7] = *ptr1++;
	  *ptr2++ = b[7];
	  *ptr2++ = b[6];
	  *ptr2++ = b[5];
	  *ptr2++ = b[4];
	  *ptr2++ = b[3];
	  *ptr2++ = b[2];
	  *ptr2++ = b[1];
	  *ptr2++ = b[0];
	}
      }
    }

    /* reorder lines */
    if( im->imageFormat == IF_ANALYZE ) {
       int lineSize = im->wdim * im->xdim * im->vdim ;
       char* buf1 = (char*) im->data ;
       char* buf2 = buf1 + lineSize * im->ydim * im->zdim - lineSize ;
       char* swapped = (char*) (*allocRoutine)(lineSize) ;
       
       while( buf1 < buf2 )
       {
	  memcpy( swapped, buf1, lineSize ) ;
	  memcpy( buf1, buf2, lineSize ) ;
	  memcpy( buf2, swapped, lineSize ) ;
	  buf1 += lineSize ;
	  buf2 -= lineSize ;
       }

       (*deleteRoutine)( swapped ) ;
    }
  }

  return 1;
}



/* Read data of a vectorial inrimage, making the resulting buffer non-
   inerlaced.
   If im->data is not NULL, assume that the buffer was previously allocated
   Swap bytes depending on the endianness and the current architecture. */
int _readNonInterlacedImageData(_image *im) {
  unsigned LONG size, nread, length;
  unsigned char *ptr1, *ptr2, b[8], **vp, *buf;
  unsigned int i, j, k, v, w;

  if(im->vdim == 1) return _readImageData(im);

  if(im->openMode != OM_CLOSE) {
    size = im->xdim * im->ydim * im->zdim * im->vdim * im->wdim;

    if(!im->data) {
      im->data = (unsigned char *) (*allocRoutine)(size);
      if(!im->data) return -2;
    }

    vp = (unsigned char **) (*allocRoutine)(im->vdim * sizeof(unsigned char *));
    buf = (unsigned char *) (*allocRoutine)(im->vdim * im->wdim);
    size = im->xdim * im->ydim * im->zdim * im->wdim;
    for(v = 0; v < im->vdim; v++)
      vp[v] = (unsigned char *) im->data + v * size;

    for(k = 0; k < im->zdim; k++) {
      for(j = 0; j < im->ydim; j++) {
	for(i = 0; i < im->xdim; i++) {
	  nread = fread(buf, 1, im->vdim * im->wdim, im->fd);
	  if(nread != im->vdim * im->wdim) return -1;
	  for(v = 0; v < im->vdim; v++)
	    for(w = 0; w < im->wdim; w++)
	      *vp[v]++ = *buf++;
	  buf -= im->vdim * im->wdim;
	}
      }
    }

    (*deleteRoutine)(buf);
    (*deleteRoutine)(vp);

    /* architecture is big endian and data little endian */
    if(ARCHITECTURE_ENDIANNESS != im->endianness) {
      
      length = size / im->wdim;
      ptr1 = ptr2 = (unsigned char *) im->data;
	
      /* 2 bytes swap */
      if(im->wdim == 2) {
	while(length--) {
	  b[0] = *ptr1++;
	  b[1] = *ptr1++;
	  *ptr2++ = b[1];
	  *ptr2++ = b[0];
	}
      }
      
      /* 4 bytes swap */
      else if(im->wdim == 4) {
	while(length--) {
	  b[0] = *ptr1++;
	  b[1] = *ptr1++;
	  b[2] = *ptr1++;
	  b[3] = *ptr1++;
	  *ptr2++ = b[3];
	  *ptr2++ = b[2];
	  *ptr2++ = b[1];
	  *ptr2++ = b[0];
	}
      }
      
      /* 8 bytes swap */
      else if(im->wdim == 8) {
	while(length--) {
	  b[0] = *ptr1++;
	  b[1] = *ptr1++;
	  b[2] = *ptr1++;
	  b[3] = *ptr1++;
	  b[4] = *ptr1++;
	  b[5] = *ptr1++;
	  b[6] = *ptr1++;
	  b[7] = *ptr1++;
	  *ptr2++ = b[7];
	  *ptr2++ = b[6];
	  *ptr2++ = b[5];
	  *ptr2++ = b[4];
	  *ptr2++ = b[3];
	  *ptr2++ = b[2];
	  *ptr2++ = b[1];
	  *ptr2++ = b[0];
	}
      }
    }
    
    /* reorder lines */
    /* no non-interlaced data for ANALYZE. But if ever... */
/*     if( im->imageFormat == IF_ANALYZE ) { */
/*        int v ; */
/*        int vdim = im->vdim ; */
/*        int lineSize = im->wdim * im->xdim ; */
/*        int vsize = lineSize * im->ydim * im->zdim ; */
/*        char* swapped = (*allocRoutine)(lineSize) ; */
/*        for( v = 0 ; v < vdim ; ++v ) */
/*        { */
/* 	  char* buf1 = (char*)im->data + v*vsize ; */
/* 	  char* buf2 = buf1 + vsize - lineSize ; */
	  
/* 	  while( buf1 < buf2 ) */
/* 	  { */
/* 	     memcpy( swapped, buf1, lineSize ) ; */
/* 	     memcpy( buf1, buf2, lineSize ) ; */
/* 	     memcpy( buf2, swapped, lineSize ) ; */
/* 	     buf1 += lineSize ; */
/* 	     buf2 -= lineSize ; */
/* 	  } */

/* 	  (*deleteRoutine)( swapped ) ; */
/*        } */
/*     } */
  }

  return 1;
}



/* Writes the given inrimage header in an already opened file.*/
int _writeInrimageHeader(const _image *im) {
  int pos, i;
  char type[30], endianness[5], buf[257], scale[20];

  if(im->openMode != OM_CLOSE) {
    /* fix word kind */
    switch(im->wordKind) {

    case WK_FLOAT:
      sprintf(type, "float");
      scale[0] = '\0';
      break;

    case WK_FIXED:
      switch(im->sign) {
      case SGN_SIGNED:
	sprintf(type, "signed fixed");
	break;
      case SGN_UNSIGNED:
	sprintf(type, "unsigned fixed");
	break;
      default:
	return -1;
      }
      sprintf(scale, "SCALE=2**0\n");
      break;
      
    default:
      return -1;
    }
    
    /* fix architecture endianness */
    if(ARCHITECTURE_ENDIANNESS == END_LITTLE)
      sprintf(endianness, "decm");
    else
      sprintf(endianness, "sun");
  
    /* write header information */
    sprintf(buf, "%s\nXDIM=%i\nYDIM=%i\nZDIM=%i\nVDIM=%d\nTYPE=%s\nPIXSIZE=%i bits\n%sCPU=%s\nVX=%f\nVY=%f\nVZ=%f\n",
	    INR4_MAGIC, im->xdim, im->ydim, im->zdim, im->vdim,
	    type, im->wdim*8, scale, endianness, im->vx, im->vy, im->vz);
    pos = strlen(buf);  
    if(fprintf(im->fd, "%s", buf) == EOF) return -1;
    
    
    /* write user strings */
    for(i = 0; i < im->nuser; i++) {
      pos += strlen(im->user[i]) + 2;
      if(fprintf(im->fd, "#%s\n", im->user[i]) == EOF) return -1;
    }

    /* write end of header */
    pos = pos % 256;
    if(pos > 252) {
      for(i = pos; i < 256; i++)
	if(fwrite("\n", 1, 1, im->fd) != 1) return -1;
      pos = 0;
    }
    buf[0] = '\0';
    for(i = pos; i < 252; i++) strcat(buf, "\n");
    strcat(buf, "##}\n");
    
    if(fprintf(im->fd, "%s", buf) == EOF) return -1;
    else return 1;
  }

  else return -1;
}



/* Writes the given image body in an already opened file.*/
int _writeInrimageData(const _image *im) {
  unsigned LONG size, nwrt, i;
  unsigned int v;
  unsigned char **vp;
  
  if(im->openMode != OM_CLOSE) {

    /* scalar or interlaced vectors */
    if(im->vectMode != VM_NON_INTERLACED) {
      size = im->xdim * im->ydim * im->zdim * im->vdim * im->wdim;
      nwrt = fwrite(im->data, 1, size, im->fd);
      if(nwrt != size) return -1;
      else return 1;
    }

    /* non interlaced vectors: interlace for saving */
    else {
      size = im->xdim * im->ydim * im->zdim * im->wdim;
      vp = (unsigned char **) (*allocRoutine)(im->vdim * sizeof(unsigned char *));
      for(v = 0; v < im->vdim; v++)
	vp[v] = (unsigned char *) im->data + v * size;
      for(i = 0; i < size; i++)
	for(v = 0; v < im->vdim; v++) {
	  if(fwrite((const void *) vp[v], 1, im->wdim, im->fd) != im->wdim)
	    return -1;
	  vp[v] += im->wdim;
	}
      (*deleteRoutine)(vp);
      return 1;
    }
  }
  else return -1;
}



/* Read one slice of given image whose header has already been read.
   File descriptor is let at the beginning of next slice and closed
   when end of file is encountered.
   If data buffer is NULL, it is allocated for one slice only.
   This funtion is dedicated to read huge inrimages. */
void _getNextSlice(_image *im) {
  unsigned LONG size, nread;
  int i;

  if(im->openMode != OM_CLOSE) {

    size = im->xdim * im->ydim * im->vdim * im->wdim;

    if(!im->data)
      im->data = (*allocRoutine)(size);

    /* read a plane */
    nread = fread(im->data, 1, size, im->fd);

    if(nread != size) {
      fprintf(stderr, "_getNextSlice: error: truncated file\n");
      _closeImage(im);
    }
    else {
      /* test end of file */
      i = fgetc(im->fd);
      if(i == EOF) _closeImage(im);
      else ungetc(i, im->fd);
    }
    
    /* reorder lines */
    if( im->imageFormat == IF_ANALYZE ) {
       int lineSize = im->wdim * im->xdim * im->vdim ;
       char* buf1 = (char*) im->data ;
       char* buf2 = buf1 + lineSize * im->ydim - lineSize ;
       char* swapped = (char*) (*allocRoutine)(lineSize) ;
       
       while( buf1 < buf2 )
       {
	  memcpy( swapped, buf1, lineSize ) ;
	  memcpy( buf1, buf2, lineSize ) ;
	  memcpy( buf2, swapped, lineSize ) ;
	  buf1 += lineSize ;
	  buf2 -= lineSize ;
       }

       (*deleteRoutine)( swapped ) ;
    }
  }
}



/* read header of an opened inrimage */
int readInrimageHeader(_image *im) {
  char str[257];
  int n, nusr;
  stringListHead strl = { NULL, NULL };
  stringListElement *oel, *el;

  if(im->openMode != OM_CLOSE) {
    /* read image magic number */
    if(!fgetns(str, 257, im->fd)) return -1;
    if(strcmp(str, INR4_MAGIC)) return -1;

    /* while read line does not begin with '#' or '\n', read line
       and decode field */
    if(!fgetns(str, 257, im->fd)) return -1;
    while(str[0] != '#' && str[0] != '\0') {
      if(!strncmp(str, "XDIM=", 5)) {
	if(sscanf(str+5, "%i", &im->xdim) != 1) return -1;
      }
      else if(!strncmp(str, "YDIM=", 5)) {
	if(sscanf(str+5, "%i", &im->ydim) != 1) return -1;
      }
      else if(!strncmp(str, "ZDIM=", 5)) {
	if(sscanf(str+5, "%i", &im->zdim) != 1) return -1;
      }
      else if(!strncmp(str, "VDIM=", 5)) {
	if(sscanf(str+5, "%i", &im->vdim) != 1) return -1;
	if(im->vdim == 1) im->vectMode = VM_SCALAR;
	else im->vectMode = VM_INTERLACED;
      }
      else if(!strncmp(str, "VX=", 3)) {
	if(sscanf(str+3, "%f", &im->vx) != 1) return -1;
      }
      else if(!strncmp(str, "VY=", 3)) {
	if(sscanf(str+3, "%f", &im->vy) != 1) return -1;
      }
      else if(!strncmp(str, "VZ=", 3)) {
	if(sscanf(str+3, "%f", &im->vz) != 1) return -1;
      }
      else if(!strncmp(str, "TYPE=", 5)) {
	if(!strncmp(str+5, "float", 5)) im->wordKind = WK_FLOAT;
	else {
	  if(!strncmp(str+5, "signed fixed", 12)) {
	    im->wordKind = WK_FIXED;
	    im->sign = SGN_SIGNED;
	  }
	  else if(!strncmp(str+5, "unsigned fixed", 14)) {
	    im->wordKind = WK_FIXED;
	    im->sign = SGN_UNSIGNED;
	  }
	  else return -1;
	}
      }
      else if(!strncmp(str, "PIXSIZE=", 8)) {
	if(sscanf(str+8, "%i %n", &im->wdim, &n) != 1) return -1;
	if(im->wdim != 8 && im->wdim != 16 && im->wdim != 32 &&
	   im->wdim != 64) return -1;
	im->wdim >>= 3;
	if(strncmp(str+8+n, "bits", 4)) return -1;
      }
      else if(!strncmp(str, "SCALE=", 6)) ;
      else if(!strncmp(str, "CPU=", 4)) {
	if(!strncmp(str+4, "decm", 4)) im->endianness = END_LITTLE;
	else if(!strncmp(str+4, "alpha", 5)) im->endianness = END_LITTLE;
	else if(!strncmp(str+4, "pc", 2)) im->endianness = END_LITTLE;
	else if(!strncmp(str+4, "sun", 3)) im->endianness = END_BIG;
	else if(!strncmp(str+4, "sgi", 3)) im->endianness = END_BIG;
	else return -1;
      }
      else return -1;

      if(!fgetns(str, 257, im->fd)) return -1;
    }

    /* parse user strings */
    im->nuser = nusr = 0;
    while(str[0] == '#' && strncmp(str, "##}", 3)) {
      addStringElement(&strl, str + 1);
      while(strlen(str) == 256) {
	if(!fgetns(str, 257, im->fd)) return -1;
	concatStringElement(&strl, str);
      }
      nusr++;
      if(!fgetns(str, 257, im->fd)) return -1;      
    }
    
    /* go to end of header */
    while(strncmp(str, "##}", 3)) {
      if(!fgetns(str, 257, im->fd)) return -1;
    }

    /* check header validity */
    if(im->xdim > 0 && im->ydim > 0 && im->zdim > 0 && im->vdim > 0 &&
       im->vx > 0.0 && im->vy > 0.0 && im->vz > 0.0 &&
       (im->wordKind == WK_FLOAT || (im->wordKind == WK_FIXED &&
				     im->sign != SGN_UNKNOWN)) &&
       im->endianness != END_UNKNOWN) {
      if(nusr > 0) {
	im->nuser = nusr;
	im->user = (char **) (*allocRoutine)(im->nuser * sizeof(char *));
	oel = NULL;
	for(el = strl.begin, n = 0; el != NULL; el = el->next, n++) {
	  if(oel) (*deleteRoutine)(oel);
	  im->user[n] = el->string;
	  oel = el;
	}
      }
      return 1;
    }
    else return -1;

  }
  else return -1;
}


/* given an initialized file descriptor and a file name, open file
   from stdin (if name == NULL), a gziped pipe (if file is gziped)
   or a standard file otherwise. */
void _openReadImage(_image* im, const char *name) {
  char *cmd, magic[5];

  if(im->openMode == OM_CLOSE) {

    /* open from stdin */
    if(name == NULL) {
      im->openMode = OM_STDIN;
      im->fd = stdin;
    }

    else {

      /* read magic number */
      im->fd = fopen(name, "r");
      if(im->fd) {
	fread((void *) magic, 4, 1, im->fd);
	magic[4] = '\0';

	/* open from a pipe */
	if(memcmp(magic, GZIP_MAGIC, 2) == 0
	    || memcmp(magic, OLD_GZIP_MAGIC, 2) == 0
	    || memcmp(magic, PKZIP_MAGIC, 4) == 0
	    || memcmp(magic, PACK_MAGIC, 2) == 0
	    || memcmp(magic, LZW_MAGIC, 2) == 0
	    || memcmp(magic, LZH_MAGIC, 2) == 0)  {
	  fclose(im->fd);
	  cmd = (char *) (*allocRoutine)((strlen(name) + 25) * sizeof(char)); 
	  sprintf(cmd, "gzip -dc %s 2> /dev/null", name);
	  im->fd = popen(cmd, "r");
	  (*deleteRoutine)(cmd);
	  if(!im->fd)
	    fprintf(stderr, "_openReadImage: error: popen failed for gzip image\n");
	  else im->openMode = OM_PIPE;
	}

	/* open from a file */
	else {
	  fseek(im->fd, 0L, SEEK_SET);
	  im->openMode = OM_FILE;
	}
      }
      
    }

  }
}


/* given an initialized file descriptor and a file name, open file
   from stdout (if name == NULL), a gziped pipe (if file is gziped)
   or a standard file otherwise. */
void _openWriteImage(_image* im, const char *name) {
   char *cmd;

   if(!name) {
      im->openMode = OM_STDIN;
      im->fd = stdout;
   }
   
   else {
      int i = strlen(name);
      if(!strncmp(name+i-3, ".gz", 3)) {
	 im->openMode = OM_PIPE;
	 cmd = (char *) (*allocRoutine)((i + 15) * sizeof(char));
	 sprintf(cmd, "gzip -c > %s", name);
	 im->fd = popen(cmd, "w");
	 (*deleteRoutine)(cmd);
      }
      else {
	 im->openMode = OM_FILE;
	 im->fd = fopen(name, "w");
      }
   }
}



/* close an image opened using _open{Read|Write}Image */
void _closeImage(_image *im) {
  switch(im->openMode) {
  case OM_CLOSE:
  case OM_STDIN:
    break;
  case OM_FILE:
    fclose(im->fd);
    break;
  case OM_PIPE:
    fflush(im->fd);
    pclose(im->fd);
    break;
  }

  im->fd = NULL;
  im->openMode = OM_CLOSE;
}





/* add a string element at the tail of given list */
static void addStringElement(stringListHead *strhead, const char *str) {
  stringListElement *el;

  el = (stringListElement *) (*allocRoutine)(sizeof(stringListElement));
  el->string = strdup(str);
  el->next = NULL;
  if(strhead->begin == NULL)
    strhead->begin = strhead->end = el;
  else {
    strhead->end->next = el;
    strhead->end = el;
  }
}

/* concat given string at the last element of given list */
static void concatStringElement(const stringListHead *strhead,
				const char *str) {
  stringListElement *el;

  el = strhead->end;
  el->string = (char *) realloc(el->string,
				strlen(el->string) + strlen(str) + 1);
  strcat(el->string, str);
}

/* get a string from a file and discard the ending newline character
   if any */
static char *fgetns(char *str, int n, FILE *f) {
  char *ret;
  int l;

  ret = fgets(str, n, f);
  if(!ret) return NULL;
  l = strlen(str);
  if(l > 0 && str[l-1] == '\n') str[l-1] = '\0';
  return ret;
}


/* check the type of image in fileName */
IMAGE_FORMAT imageType(const char *fileName) {
  FILE *f;
  char cmd[200], magic[5];

  f = fopen(fileName, "r");
  if(!f) return IF_UNKNOWN;

  fread((void *) magic, 4, 1, f);
  magic[4] = '\0';
  fclose(f);

  if(!strcmp(magic, INR_MAGIC)) return IF_INR;
  else if(!strcmp(magic, GIF_MAGIC)) return IF_GIF;
  else if((((unsigned char *)magic)[0]<<8) + ((unsigned char *)magic)[1]
	  == IRIS_MAGIC)
    return IF_IRIS;
  else if(memcmp(magic, GZIP_MAGIC, 2) == 0
	  || memcmp(magic, OLD_GZIP_MAGIC, 2) == 0
	  || memcmp(magic, PKZIP_MAGIC, 4) == 0
	  || memcmp(magic, PACK_MAGIC, 2) == 0
	  || memcmp(magic, LZW_MAGIC, 2) == 0
	  || memcmp(magic, LZH_MAGIC, 2) == 0) {
    sprintf(cmd, "gzip -dc %s 2> /dev/null", fileName);
    f = popen(cmd, "r");
    fread((void *) magic, 4, 1, f);
    magic[4] = '\0';
    fflush(f);
    pclose(f);
    if(!strcmp(magic, INR_MAGIC)) return IF_INR_GZ;
  }

  return IF_UNKNOWN;
}


