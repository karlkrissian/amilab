#ifndef _TIFF_
#define	_TIFF_
/*
 * Tag Image File Format (TIFF)
 *
 * Based on Rev 6.0
 */

//#include "ami.h"


/* Create a tiff file with:
   - 8 or 16 bits
   - No compression
   - 0 = black
   - Order MSB2LSB
   - Planar config contig
   - RETURN 0 IF FINISH PROPERLY -1 OTHERWISE
*/
int write_tiff (
		const char name[200],   /* Name of the file */
		float *image,     /* We use a float vector to keep the image */
		int width,        /* Width of the image */
		int length,       /* Length of the image */
		int charOrShort   /* The tiff file will be of 8 bpp if charOrShort = 0 or 16 bpp if charOrShort = 1. */
		);


/* Read a tiff file with:
   - 8 or 16 bits -> float
   - No compression
   - 0 = black or 0 = white
   - Order MSB2LSB
   - Planar config contig
   - RETURN 0 IF FINISH PROPERLY -1 OTHERWISE
*/
int read_tiff (
	       const char name[200],   /* Name of the file */
	       float **image,    /* We use a float vector to keep the image */
	       int *width,       /* Width of the readed image */
	       int *length,      /* Length of the readed image */
	       int *charOrShort  /* The tiff file has 8 bpp if charOrShort = 0 or 16 bpp if charOrShort = 1. */
	       );






#endif /* _TIFF_ */
