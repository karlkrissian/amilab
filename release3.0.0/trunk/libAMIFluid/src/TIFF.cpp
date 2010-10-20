
#include "TIFF.h"
#include "ami.h"

/*
********************************************************************************
********************************************************************************
*/




#define	TIFF_VERSION	        42
#define TIFF_BIGTIFF_VERSION    43

#define	TIFF_BIGENDIAN		0x4d
#define	TIFF_LITTLEENDIAN	0x49


/*
 * Tag data type information.
 *
 * Note: RATIONALs are the ratio of two 32-bit integer values.
 */
#define TIFF_BYTE           1	/* 8-bit unsigned integer */
#define TIFF_ASCII          2	/* 8-bit bytes w/ last byte null */
#define TIFF_SHORT          3	/* 16-bit unsigned integer */
#define TIFF_LONG           4	/* 32-bit unsigned integer */
#define TIFF_RATIONAL       5	/* 64-bit unsigned fraction */
#define TIFF_SBYTE          6	/* !8-bit signed integer */
#define TIFF_UNDEFINED      7	/* !8-bit untyped data */
#define TIFF_SSHORT         8	/* !16-bit signed integer */
#define TIFF_SLONG          9	/* !32-bit signed integer */
#define TIFF_SRATIONAL      10	/* !64-bit signed fraction */
#define TIFF_FLOAT          11	/* !32-bit IEEE floating point */
#define TIFF_DOUBLE         12	/* !64-bit IEEE floating point */


/*
 * TIFF Tag Definitions.
 */
#define	TIFFTAG_SUBFILETYPE		    254	/* subfile data descriptor */
#define	    FILETYPE_REDUCEDIMAGE	        0x1	/* reduced resolution version */
#define	    FILETYPE_PAGE		        0x2	/* one page of many */
#define	    FILETYPE_MASK		        0x4	/* transparency mask */
#define	TIFFTAG_OSUBFILETYPE	            255	/* +kind of data in subfile */
#define	    OFILETYPE_IMAGE		        1	/* full resolution image data */
#define	    OFILETYPE_REDUCEDIMAGE	        2	/* reduced size image data */
#define	    OFILETYPE_PAGE		        3	/* one page of many */
#define	TIFFTAG_IMAGEWIDTH		    256	/* image width in pixels */
#define	TIFFTAG_IMAGELENGTH		    257	/* image height in pixels */
#define	TIFFTAG_BITSPERSAMPLE	            258	/* bits per channel (sample) */
#define	TIFFTAG_COMPRESSION		    259	/* data compression technique */
#define	    COMPRESSION_NONE		        1	/* dump mode */
#define	    COMPRESSION_CCITTRLE	        2	/* CCITT modified Huffman RLE */
#define	    COMPRESSION_CCITTFAX3	        3	/* CCITT Group 3 fax encoding */
#define	    COMPRESSION_CCITTFAX4	        4	/* CCITT Group 4 fax encoding */
#define	    COMPRESSION_LZW		        5       /* Lempel-Ziv  & Welch */
#define	    COMPRESSION_OJPEG		        6	/* !6.0 JPEG */
#define	    COMPRESSION_PACKBITS	        32773	/* Macintosh RLE */
#define	TIFFTAG_PHOTOMETRIC		    262	/* photometric interpretation */
#define	    PHOTOMETRIC_MINISWHITE	        0	/* min value is white */
#define	    PHOTOMETRIC_MINISBLACK	        1	/* min value is black */
#define	    PHOTOMETRIC_RGB		        2	/* RGB color model */
#define	    PHOTOMETRIC_PALETTE		        3	/* color map indexed */
#define	    PHOTOMETRIC_MASK		        4	/* $holdout mask */
#define	    PHOTOMETRIC_SEPARATED	        5	/* !color separations */
#define	    PHOTOMETRIC_YCBCR		        6	/* !CCIR 601 */
#define	    PHOTOMETRIC_CIELAB		        8	/* !1976 CIE L*a*b* */
#define	TIFFTAG_THRESHHOLDING	            263	/* +thresholding used on data */
#define	    THRESHHOLD_BILEVEL		        1	/* b&w art scan */
#define	    THRESHHOLD_HALFTONE		        2	/* or dithered scan */
#define	    THRESHHOLD_ERRORDIFFUSE	        3	/* usually floyd-steinberg */
#define	TIFFTAG_CELLWIDTH		    264	/* +dithering matrix width */
#define	TIFFTAG_CELLLENGTH		    265	/* +dithering matrix height */
#define	TIFFTAG_FILLORDER		    266	/* data order within a byte */
#define	    FILLORDER_MSB2LSB		        1	/* most significant -> least */
#define	    FILLORDER_LSB2MSB		        2	/* least significant -> most */
#define	TIFFTAG_DOCUMENTNAME	            269	/* name of doc. image is from */
#define	TIFFTAG_IMAGEDESCRIPTION            270	/* info about image */
#define	TIFFTAG_MAKE			    271	/* scanner manufacturer name */
#define	TIFFTAG_MODEL			    272	/* scanner model name/number */
#define	TIFFTAG_STRIPOFFSETS	            273	/* offsets to data strips */
#define	TIFFTAG_ORIENTATION		    274	/* +image orientation */
#define	    ORIENTATION_TOPLEFT		        1	/* row 0 top, col 0 lhs */
#define	    ORIENTATION_TOPRIGHT	        2	/* row 0 top, col 0 rhs */
#define	    ORIENTATION_BOTRIGHT	        3	/* row 0 bottom, col 0 rhs */
#define	    ORIENTATION_BOTLEFT		        4	/* row 0 bottom, col 0 lhs */
#define	    ORIENTATION_LEFTTOP		        5	/* row 0 lhs, col 0 top */
#define	    ORIENTATION_RIGHTTOP	        6	/* row 0 rhs, col 0 top */
#define	    ORIENTATION_RIGHTBOT	        7	/* row 0 rhs, col 0 bottom */
#define	    ORIENTATION_LEFTBOT		        8	/* row 0 lhs, col 0 bottom */
#define	TIFFTAG_SAMPLESPERPIXEL             277	/* samples per pixel */
#define	TIFFTAG_ROWSPERSTRIP	            278	/* rows per strip of data */
#define	TIFFTAG_STRIPBYTECOUNTS	            279	/* bytes counts for strips */
#define	TIFFTAG_MINSAMPLEVALUE	            280	/* +minimum sample value */
#define	TIFFTAG_MAXSAMPLEVALUE	            281	/* +maximum sample value */
#define	TIFFTAG_XRESOLUTION		    282	/* pixels/resolution in x */
#define	TIFFTAG_YRESOLUTION		    283	/* pixels/resolution in y */
#define	TIFFTAG_PLANARCONFIG	            284	/* storage organization */
#define	    PLANARCONFIG_CONTIG		        1	/* single image plane */
#define	    PLANARCONFIG_SEPARATE	        2	/* separate planes of data */
#define	TIFFTAG_PAGENAME		    285	/* page name image is from */
#define	TIFFTAG_XPOSITION		    286	/* x page offset of image lhs */
#define	TIFFTAG_YPOSITION		    287	/* y page offset of image lhs */
#define	TIFFTAG_FREEOFFSETS		    288	/* +byte offset to free block */
#define	TIFFTAG_FREEBYTECOUNTS	            289	/* +sizes of free blocks */
#define	TIFFTAG_GRAYRESPONSEUNIT            290	/* $gray scale curve accuracy */
#define	    GRAYRESPONSEUNIT_10S	        1	/* tenths of a unit */
#define	    GRAYRESPONSEUNIT_100S	        2	/* hundredths of a unit */
#define	    GRAYRESPONSEUNIT_1000S	        3	/* thousandths of a unit */
#define	    GRAYRESPONSEUNIT_10000S	        4	/* ten-thousandths of a unit */
#define	    GRAYRESPONSEUNIT_100000S	        5	/* hundred-thousandths */
#define	TIFFTAG_GRAYRESPONSECURVE	    291	/* $gray scale response curve */
#define	TIFFTAG_GROUP3OPTIONS		    292	/* 32 flag bits */
#define	TIFFTAG_T4OPTIONS		    292	/* TIFF 6.0 proper name alias */
#define	    GROUP3OPT_2DENCODING	        0x1	/* 2-dimensional coding */
#define	    GROUP3OPT_UNCOMPRESSED	        0x2	/* data not compressed */
#define	    GROUP3OPT_FILLBITS		        0x4	/* fill to byte boundary */
#define TIFFTAG_T6OPTIONS                   293 /* TIFF 6.0 proper name */
#define	    GROUP4OPT_UNCOMPRESSED	        0x2	/* data not compressed */
#define	TIFFTAG_RESOLUTIONUNIT		    296	/* units of resolutions */
#define	    RESUNIT_NONE		        1	/* no meaningful units */
#define	    RESUNIT_INCH		        2	/* english */
#define	    RESUNIT_CENTIMETER		        3	/* metric */
#define	TIFFTAG_PAGENUMBER		    297	/* page numbers of multi-page */
#define	TIFFTAG_COLORRESPONSEUNIT	    300	/* $color curve accuracy */
#define	    COLORRESPONSEUNIT_10S	        1	/* tenths of a unit */
#define	    COLORRESPONSEUNIT_100S	        2	/* hundredths of a unit */
#define	    COLORRESPONSEUNIT_1000S	        3	/* thousandths of a unit */
#define	    COLORRESPONSEUNIT_10000S	        4	/* ten-thousandths of a unit */
#define	    COLORRESPONSEUNIT_100000S	        5	/* hundred-thousandths */
#define	TIFFTAG_TRANSFERFUNCTION	    301	/* !colorimetry info */
#define	TIFFTAG_SOFTWARE		    305	/* name & release */
#define	TIFFTAG_DATETIME		    306	/* creation date and time */
#define	TIFFTAG_ARTIST			    315	/* creator of image */
#define	TIFFTAG_HOSTCOMPUTER		    316	/* machine where created */
#define	TIFFTAG_PREDICTOR		    317	/* prediction scheme w/ LZW */
#define	TIFFTAG_WHITEPOINT		    318	/* image white point */
#define	TIFFTAG_PRIMARYCHROMATICITIES	    319	/* !primary chromaticities */
#define	TIFFTAG_COLORMAP		    320	/* RGB map for pallette image */
#define	TIFFTAG_HALFTONEHINTS		    321	/* !highlight+shadow info */
#define	TIFFTAG_TILEWIDTH		    322	/* !rows/data tile */
#define	TIFFTAG_TILELENGTH		    323	/* !cols/data tile */
#define TIFFTAG_TILEOFFSETS		    324	/* !offsets to data tiles */
#define TIFFTAG_TILEBYTECOUNTS		    325	/* !byte counts for tiles */
#define	TIFFTAG_INKSET			    332	/* !inks in separated image */
#define	    INKSET_CMYK			        1	/* !cyan-magenta-yellow-black color */
#define	    INKSET_MULTIINK		        2	/* !multi-ink or hi-fi color */
#define	TIFFTAG_INKNAMES		    333	/* !ascii names of inks */
#define	TIFFTAG_NUMBEROFINKS		    334	/* !number of inks */
#define	TIFFTAG_DOTRANGE		    336	/* !0% and 100% dot codes */
#define	TIFFTAG_TARGETPRINTER		    337	/* !separation target */
#define	TIFFTAG_EXTRASAMPLES		    338	/* !info about extra samples */
#define	    EXTRASAMPLE_UNSPECIFIED	        0	/* !unspecified data */
#define	    EXTRASAMPLE_ASSOCALPHA	        1	/* !associated alpha data */
#define	    EXTRASAMPLE_UNASSALPHA	        2	/* !unassociated alpha data */
#define	TIFFTAG_SAMPLEFORMAT		    339	/* !data sample format */
#define	    SAMPLEFORMAT_UINT		        1	/* !unsigned integer data */
#define	    SAMPLEFORMAT_INT		        2	/* !signed integer data */
#define	    SAMPLEFORMAT_IEEEFP		        3	/* !IEEE floating point data */
#define	    SAMPLEFORMAT_VOID		        4	/* !untyped data */
#define	    SAMPLEFORMAT_COMPLEXINT	        5	/* !complex signed int */
#define	    SAMPLEFORMAT_COMPLEXIEEEFP	        6	/* !complex ieee floating */
#define	TIFFTAG_SMINSAMPLEVALUE		    340	/* !variable MinSampleValue */
#define	TIFFTAG_SMAXSAMPLEVALUE		    341	/* !variable MaxSampleValue */



/* Rational: offset, num & den */
struct TIFF_rational {
  long num;
  long den;
  long offset;
};


/* Offset or byte counts */
struct TIFF_stripData {
  long begin;
  int shortOrLong;  /* 0 short, 1 long */
  short *TIFF_short;
  long *TIFF_long;
};


/* Image vector: unsigned char (8b) or unsigned short (16b) */
struct TIFF_image {
  int charOrShort; /* 0 char, 1 short  */
  unsigned char *TIFF_char;
  unsigned short *TIFF_short;
};


/* Information of tiff file */
struct TIFF_struct {
  int IIorMM;  /* byte order */
  int magicNumber; /* number of tiff file */
  long offsetNextIFD; /* offset of the next IFD of the tiff file */
  int numberDirectoryEntries; /* number of directory entries of the actual IFD */
  int width;
  int length; /* width and lenght of the image */
  int bitPerSample; /* bits per channel: 8 or 16 */
  int samplesPerPixel; /* number of channels per pixel: only valid 1 channel */
  int compresion; /* used compresion : only valid "no compresion" */
  int photometric; /* basseline tiff. Only valid bilevel or greyscale images */
  int fillOrder;   /* The logical order of bits within a byte. Only valid MSB2LSB */
  int numberStrips; /* number of strips of the image */
  int rowsPerStrip; /* number of rows per strip */
  int planarConfiguration; /* How the components of each pixel are stored. Only valid 1chumky format (RGB) */
  int resolutionUnit; /* The unit of measurement for XResolution and YResolution. */
  struct TIFF_rational xResolution;  /* The number of pixels per ResolutionUnit in the ImageWidth direction. */
  struct TIFF_rational yResolution;  /* The number of pixels per ResolutionUnit in the ImageLength direction. */
  struct TIFF_image image;  /* image */
};


/*
********************************************************************************
********************************************************************************
*/

/* SHORT to HEX in byte order II or MM */
void hexadecimal2 (int source, unsigned char *dest, int IIorMM);


/* LONG to HEX in byte order II or MM */
void hexadecimal4 (int source, unsigned char *dest, int IIorMM);

/* Write a directory entry */
void writeDirectoryEntry (long tag, long type, long count, long value, unsigned char *data, int IIorMM);


/* HEX to SHORT in byte order II or MM */
short integer2(unsigned char A0, unsigned char A1, int IIorMM);

/* HEX to LONG in byte order II or MM */
long integer4(unsigned char A0, unsigned char A1, unsigned char A2, unsigned char A3, int IIorMM);


/* Create and write a file tiff called "name" given by myTiff */
int write_tiff_TIFF_struct  ( const char name[200], struct TIFF_struct *myTiff);


/* Create the tiff with:
   - 8 or 16 bits
   - No compression
   - 0 = black
   - Order MSB2LSB
   - Planar config
*/
int write_tiff ( const char name[200], float *image, int width, int length, int charOrShort);


/* Read a tiff file called "name" and fill myTiff with the information */
int read_tiff_TIFF_struct (const char name[200], struct TIFF_struct *myTiff);


/* Read a tiff file with:
   - 8 or 16 bits -> float
   - No compression
   - 0 = black or 0 = white
   - Order MSB2LSB
   - Planar config
*/
int read_tiff (const char name[200], float **image, int *width, int *length, int *charOrShort);


/* SHORT to HEX in byte order II or MM */
void hexadecimal2 (int source, unsigned char *dest, int IIorMM)
{
  short A0 = 0, A1 = 0;
  
  if (IIorMM)  {
    A0 = source & 0xFF00;
    A0 >>= 8;

    A1 = source & 0x00FF;
  }
  else {
    A1 = source & 0xFF00;
    A1 >>= 8;
    A0 = source & 0x00FF;
  }
  
  dest[0] = A0;
  dest[1] = A1;
}


/* LONG to HEX in byte order II or MM */
void hexadecimal4 (int source, unsigned char *dest, int IIorMM)
{
  long A0 = 0, A1 = 0, A2 = 0, A3 = 0;
  
  if (IIorMM)  {
    A0 = source & 0xFF000000;
    A0 >>= 24;
    A1 = source & 0x00FF0000;
    A1 >>= 16;
    A2 = source & 0x0000FF00;
    A2 >>= 8;
    A3 = source & 0x000000FF;
  }
  else {
    A3 = source & 0xFF000000;
    A3 >>= 24;
    A2 = source & 0x00FF0000;
    A2 >>= 16;
    A1 = source & 0x0000FF00;
    A1 >>= 8;
    A0 = source & 0x000000FF;
  }
  
  dest[0] = A0;
  dest[1] = A1;
  dest[2] = A2;
  dest[3] = A3;
}


/* Write a directory entry */
void writeDirectoryEntry (long tag, long type, long count, long value, unsigned char *data, int IIorMM)
{
  hexadecimal2(tag,&data[0],IIorMM);
  hexadecimal2(type,&data[2],IIorMM);
  hexadecimal4(count,&data[4],IIorMM);
  hexadecimal4(value,&data[8],IIorMM);
}


/* HEX to SHORT in byte order II or MM */
short integer2(unsigned char A0, unsigned char A1, int IIorMM)
{
  int F0;
  if (IIorMM) {
    F0 = A0 << 8;
    return F0 | A1;
  }
  else {
    F0 = A1 << 8;
    return F0 | A0;
  }
}


/* HEX to LONG in byte order II or MM */
long integer4(unsigned char A0, unsigned char A1, unsigned char A2, unsigned char A3, int IIorMM)
{
  int F0, F1, F2;
  if (IIorMM) {
    F0 = A0 << 24;
    F1 = A1 << 16;
    F2 = A2 << 8;
    return F0 | F1 | F2 | A3;
  }
  else {
    F0 = A3 << 24;
    F1 = A2 << 16;
    F2 = A1 << 8;
    return F0 | F1 | F2 | A0;
  }
}


/* Create and write a file tiff called "name" given by myTiff */
int write_tiff_TIFF_struct  ( const char name[200], struct TIFF_struct *myTiff)
{
  FILE *fptr;
  int i, retorno = 0;
  long size, temp;
  unsigned char *data;
  
  /* Allocate memory: maximun data is 4*sizeof(long) -> 2 RATIONAL */
  ami_malloc1d(data,unsigned char,4*sizeof(long));
  
  /* Create file */
  if ((fptr = fopen(name,"wb")) == NULL) {
    fprintf(stderr,"Unable to create tif file \"%s\"\n",name);
  }
  
  /* Write the head */
  /* Byte order */
  if (myTiff->IIorMM == 0) {
    data[0] = data[1] = TIFF_LITTLEENDIAN;
  }
  else {
    data[0] = data[1] = TIFF_BIGENDIAN;
  }
  
  /* Magic Number */
  hexadecimal2(myTiff->magicNumber,&data[2],myTiff->IIorMM);
  
  /* Offset of first IFD */
  hexadecimal4(myTiff->offsetNextIFD,&data[4],myTiff->IIorMM);
  fwrite(data,2*sizeof(short)+sizeof(long),1,fptr);
  
  /* Seek the cursor in the next IFD */
  fseek(fptr,myTiff->offsetNextIFD,SEEK_SET);
  
  /* Number of entries of the IFD */
  hexadecimal2(myTiff->numberDirectoryEntries,&data[0],myTiff->IIorMM);
  fwrite(data,sizeof(short),1,fptr);
  
  for (i = 0; i < myTiff->numberDirectoryEntries; i++) {
    /* Seek the pointer in the next entry */
    temp = myTiff->offsetNextIFD+sizeof(short)+(2*sizeof(short)+2*sizeof(long))*i;
    fseek(fptr,temp,SEEK_SET);
    
    switch (i) {
    case 0: /* The width */
      writeDirectoryEntry(TIFFTAG_IMAGEWIDTH,TIFF_LONG,1,myTiff->width,data,myTiff->IIorMM);
      break;
    case 1: /* The length */
      writeDirectoryEntry(TIFFTAG_IMAGELENGTH,TIFF_LONG,1,myTiff->length,data,myTiff->IIorMM);
      break;
    case 2: /* Bit per channel */
      if (myTiff->samplesPerPixel != 1) {
	fprintf(stderr,"The file \"%s\" not is a bilevel or grayscale image\n",name);
	retorno = -1;
	goto fin_write;
      }
      if ((myTiff->bitPerSample != 8) &&  (myTiff->bitPerSample != 16)) {
	fprintf(stderr,"The file \"%s\" uses a data type not available\n",name);
	retorno = -1;
	goto fin_write;
      }
      writeDirectoryEntry(TIFFTAG_BITSPERSAMPLE,TIFF_SHORT,myTiff->samplesPerPixel,myTiff->bitPerSample,data,myTiff->IIorMM);
      break;
    case 3: /* The compresion */
      if (myTiff->compresion != COMPRESSION_NONE) {
	fprintf(stderr,"The file \"%s\" uses a compresion method not available\n",name);
	retorno = -1;
	goto fin_write;
      }
      writeDirectoryEntry(TIFFTAG_COMPRESSION,TIFF_SHORT,1,myTiff->compresion,data,myTiff->IIorMM);
      break;
    case 4: /* Photometric Interpretation */
      if (myTiff->photometric != PHOTOMETRIC_MINISBLACK) {
	fprintf(stderr,"The file \"%s\" has a photometric interpretation not available\n",name);
	retorno = -1;
	goto fin_write;
      }
      writeDirectoryEntry(TIFFTAG_PHOTOMETRIC,TIFF_SHORT,1,myTiff->photometric,data,myTiff->IIorMM);
      break;
    case 5: /* The fill order */
      if (myTiff->fillOrder != FILLORDER_MSB2LSB) {
	fprintf(stderr,"The file \"%s\" has a fillorder not valid\n",name);
	retorno = -1;
	goto fin_write;
      }
      writeDirectoryEntry(TIFFTAG_FILLORDER,TIFF_SHORT,1,myTiff->fillOrder,data,myTiff->IIorMM);
      break;
    case 6: /* The offsets of the strips */
      if (myTiff->numberStrips != 1) {
	fprintf(stderr,"The file \"%s\" has a number os strips not valid\n",name);
	retorno = -1;
	goto fin_write;
      }
      temp = myTiff->offsetNextIFD+sizeof(short)+(2*sizeof(short)+2*sizeof(long))*myTiff->numberDirectoryEntries+5*sizeof(long);
      writeDirectoryEntry(TIFFTAG_STRIPOFFSETS,TIFF_LONG,myTiff->numberStrips,temp,data,myTiff->IIorMM);
      break;
    case 7: /* Channels per pixel */
      if (myTiff->samplesPerPixel != 1) {
	fprintf(stderr,"The file \"%s\" not is a bilevel or grayscale image.\n",name);
	retorno = -1;
	goto fin_write;
      }
      writeDirectoryEntry(TIFFTAG_SAMPLESPERPIXEL,TIFF_SHORT,1,myTiff->samplesPerPixel,data,myTiff->IIorMM);
      break;
    case 8: /* Rows per strip */
      if (myTiff->rowsPerStrip != myTiff->length) {
	fprintf(stderr,"The file \"%s\" has a number of rows per strip incorrect\n",name);
	retorno = -1;
	goto fin_write;
      }
      writeDirectoryEntry(TIFFTAG_ROWSPERSTRIP,TIFF_LONG,1,myTiff->rowsPerStrip,data,myTiff->IIorMM);
      break;
    case 9: /* Number of bytes of strips */
      if (myTiff->numberStrips != 1) {
	fprintf(stderr,"The file \"%s\" has a number os strips not valid\n",name);
	retorno = -1;
	goto fin_write;
      }
      size = myTiff->width*myTiff->length;
      if (myTiff->image.charOrShort == 0)
	size *= sizeof(unsigned char);
      else
	size *= sizeof(unsigned short);
      writeDirectoryEntry(TIFFTAG_STRIPBYTECOUNTS,TIFF_LONG,myTiff->numberStrips,size,data,myTiff->IIorMM);
      break;
    case 10:   /* X resolution */
      writeDirectoryEntry(TIFFTAG_XRESOLUTION,TIFF_RATIONAL,1,myTiff->xResolution.offset,data,myTiff->IIorMM);
      break;
    case 11:   /* Y resolution */
      writeDirectoryEntry(TIFFTAG_YRESOLUTION,TIFF_RATIONAL,1,myTiff->yResolution.offset,data,myTiff->IIorMM);
      break;
    case 12:   /* Planar config */
      if (myTiff->planarConfiguration != PLANARCONFIG_CONTIG) {
	fprintf(stderr,"The file \"%s\" uses a planar configuration not available\n",name);
	retorno = -1;
	goto fin_write;
      }
      writeDirectoryEntry(TIFFTAG_PLANARCONFIG,TIFF_SHORT,1,myTiff->planarConfiguration,data,myTiff->IIorMM);
      break;
    case 13:   /* Resolution unit */
      writeDirectoryEntry(TIFFTAG_RESOLUTIONUNIT,TIFF_SHORT,1,myTiff->resolutionUnit,data,myTiff->IIorMM);
      break;
    default:
      break;
    }
    
    /* And write the entry */
    fwrite(data,2*sizeof(short)+2*sizeof(long),1,fptr);
  }
  
  /* Seek the cursor in the end of the IFD */
  temp = myTiff->offsetNextIFD+sizeof(short)+(2*sizeof(short)+2*sizeof(long))*myTiff->numberDirectoryEntries;
  fseek(fptr,temp,SEEK_SET);
  
  /* Write the offset of the next IFD */
  hexadecimal4(0,&data[0],myTiff->IIorMM);
  fwrite(data,sizeof(long),1,fptr);
  
  /* Seek the cursor in the end of the file */
  temp = myTiff->offsetNextIFD+sizeof(short)+(2*sizeof(short)+2*sizeof(long))*myTiff->numberDirectoryEntries+sizeof(long);
  fseek(fptr,temp,SEEK_SET);
  
  /* Write the x and y resolution */
  hexadecimal4(myTiff->xResolution.num,&data[0],1);
  hexadecimal4(myTiff->xResolution.den,&data[4],1);
  hexadecimal4(myTiff->yResolution.num,&data[8],1);
  hexadecimal4(myTiff->yResolution.den,&data[12],1);
  fwrite(data,4*sizeof(long),1,fptr);
  
  /* Seek the cursor in the end of the file */
  temp = myTiff->offsetNextIFD+sizeof(short)+(2*sizeof(short)+2*sizeof(long))*myTiff->numberDirectoryEntries+5*sizeof(long);
  fseek(fptr,temp,SEEK_SET);
  
  /* Write the image */
  size = myTiff->length*myTiff->width;
  
  if (myTiff->image.charOrShort == 0)
    fwrite(myTiff->image.TIFF_char,size*sizeof(unsigned char),1,fptr);
  else
    fwrite(myTiff->image.TIFF_short,size*sizeof(unsigned short),1,fptr);
  
  
 fin_write:
  
  /* Close the file and free the memory */
  fclose(fptr);
  free(data);
  
  return retorno;
}


/* Create the tiff with:
   - 8 or 16 bits
   - No compression
   - 0 = black
   - Order MSB2LSB
   - Planar config
*/
int write_tiff ( const char name[200], float *image, int width, int length, int charOrShort)
{
  struct TIFF_struct myTiff;
  int size, i, retorno;
  
  /* Fill the TIFF_struct with the information */
  myTiff.IIorMM = 0;
  myTiff.magicNumber = TIFF_VERSION;
  myTiff.offsetNextIFD = 8;
  myTiff.numberDirectoryEntries = 14;
  myTiff.width = width;
  myTiff.length = length;
  myTiff.samplesPerPixel = 1;
  myTiff.compresion = COMPRESSION_NONE;
  myTiff.photometric = PHOTOMETRIC_MINISBLACK;
  myTiff.fillOrder = FILLORDER_MSB2LSB;
  myTiff.numberStrips = 1;
  myTiff.rowsPerStrip = length;
  myTiff.planarConfiguration = PLANARCONFIG_CONTIG;
  myTiff.resolutionUnit = RESUNIT_INCH;
  myTiff.xResolution.num= 72;
  myTiff.xResolution.den= 1;
  myTiff.yResolution.num= 72;
  myTiff.yResolution.den= 1;
  myTiff.xResolution.offset = myTiff.offsetNextIFD+sizeof(short)+(2*sizeof(short)+2*sizeof(long))*myTiff.numberDirectoryEntries+sizeof(long);
  myTiff.yResolution.offset = myTiff.offsetNextIFD+sizeof(short)+(2*sizeof(short)+2*sizeof(long))*myTiff.numberDirectoryEntries+3*sizeof(long);
  myTiff.image.charOrShort = charOrShort;
  
  size = length*width;
  
  /* 8 bits or 16 bits ?? */
  if (charOrShort == 0) {
    myTiff.image.TIFF_short = NULL;
    myTiff.bitPerSample = 8;
    ami_malloc1d(myTiff.image.TIFF_char,unsigned char,size);
    for (i = 0; i < size; i++) myTiff.image.TIFF_char[i] = (unsigned char)image[i];
  }
  else {
    myTiff.image.TIFF_char = NULL;
    myTiff.bitPerSample = 16;
    ami_malloc1d(myTiff.image.TIFF_short,unsigned short,size);
    for (i = 0; i < size; i++) myTiff.image.TIFF_short[i] = (short unsigned int)image[i];
  }
  
  /* Call the function write a tiff file */
  retorno = write_tiff_TIFF_struct(name,&myTiff);
  
  if (retorno == -1)
    fprintf(stderr,"Image write failed\n");
  
  /* Free the used memory */
  if (myTiff.image.TIFF_char != NULL) free(myTiff.image.TIFF_char);
  if (myTiff.image.TIFF_short != NULL) free(myTiff.image.TIFF_short);
  
  return retorno;
}


/* Read a tiff file called "name" and fill myTiff with the information */
int read_tiff_TIFF_struct (const char name[200], struct TIFF_struct *myTiff)
{
  unsigned char *data;
  FILE *fptr;
  int i, j, tag, type, retorno = 0;
  long size0 = 0, size1, byteCountsJ;
  struct TIFF_stripData stripByteCounts, stripOffset;
  
  stripByteCounts.TIFF_short = NULL;
  stripByteCounts.TIFF_long = NULL;
  stripOffset.TIFF_short = NULL;
  stripOffset.TIFF_long = NULL;
  myTiff->image.TIFF_char = NULL;
  myTiff->image.TIFF_short = NULL;
  
  /* Allocate memory maximun to a directory entry */
  ami_malloc1d(data,unsigned char,2*sizeof(short)+2*sizeof(long));
  
  /* Open file */
  if ((fptr = fopen(name,"rb")) == NULL) {
    fprintf(stderr,"Unable to open tif file \"%s\"\n",name);
  }
  
  /* Read the head */
  fread(data,2*sizeof(short)+sizeof(long),1,fptr);
  
  /* Byte order */
  if (data[0] == data[1]) {
    if (data[0] == TIFF_LITTLEENDIAN) myTiff->IIorMM = 0; /* II */
    else if (data[0] == TIFF_BIGENDIAN) myTiff->IIorMM = 1; /* MM */
    else {
      fprintf(stderr,"WARNING: This file is not a tiff image. It will treated like a 1024 x 1024 MSG IMAGE WITH 16 BITS DEPTH\n");
      myTiff->width = 1024;
      myTiff->length = 1024;
      size0 = 1024*1024;
      myTiff->image.charOrShort = 1;
      myTiff->image.TIFF_char = NULL;
      ami_malloc1d(myTiff->image.TIFF_short,unsigned short,size0);
      fseek(fptr,0,SEEK_SET);
      fread(myTiff->image.TIFF_short,size0*sizeof(unsigned short),1,fptr);
      goto fin_read;
    }
  }
  else {
    fprintf(stderr,"WARNING: This file is not a tiff image. It will treated like a 1024 x 1024 MSG IMAGE WITH 16 BITS DEPTH\n");
    myTiff->width = 1024;
    myTiff->length = 1024;
    size0 = 1024*1024;
    myTiff->image.charOrShort = 1;
    myTiff->image.TIFF_char = NULL;
    ami_malloc1d(myTiff->image.TIFF_short,unsigned short,size0);
    fseek(fptr,0,SEEK_SET);
    fread(myTiff->image.TIFF_short,size0*sizeof(unsigned short),1,fptr);
    goto fin_read;
  }
  
  /* Is a tiff image? */
  myTiff->magicNumber = integer2(data[2],data[3],myTiff->IIorMM);
  if ((myTiff->magicNumber != TIFF_VERSION) && (myTiff->magicNumber != TIFF_BIGTIFF_VERSION)) {
    fprintf(stderr,"The file \"%s\" is not a tiff file\n",name);
    retorno = -1;
    goto fin_read;
  }
  
  /* Offset of the first IFD */
  myTiff->offsetNextIFD = integer4(data[4],data[5],data[6],data[7],myTiff->IIorMM);
  
  do {
    /* Seek the pointer in the next IFD and read the number of directory entries */
    fseek(fptr,myTiff->offsetNextIFD,SEEK_SET);
    fread(data,sizeof(short),1,fptr);
    myTiff->numberDirectoryEntries = integer2(data[0],data[1],myTiff->IIorMM);
    
    for (i = 0; i < myTiff->numberDirectoryEntries; i++) {
      /* Read the next directory entry */
      fread(data,2*sizeof(short)+2*sizeof(long),1,fptr);
      tag = integer2(data[0],data[1],myTiff->IIorMM);
      switch (tag) {
      case TIFFTAG_IMAGEWIDTH:
	myTiff->width = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	break;
      case TIFFTAG_IMAGELENGTH:
	myTiff->length = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	break;
      case TIFFTAG_BITSPERSAMPLE:
	size0 = myTiff->width * myTiff->length;
	myTiff->bitPerSample = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	if (myTiff->bitPerSample == 8) {
	  myTiff->image.charOrShort = 0;
	  myTiff->image.TIFF_short = NULL;
	  ami_malloc1d(myTiff->image.TIFF_char,unsigned char,size0);
	}
	else if (myTiff->bitPerSample == 16) {
	  myTiff->image.charOrShort = 1;
	  myTiff->image.TIFF_char = NULL;
	  ami_malloc1d(myTiff->image.TIFF_short,unsigned short,size0);
	}
	else {
	  fprintf(stderr,"The file \"%s\" uses a data type not available: %d\n",name,myTiff->bitPerSample);
	  retorno = -1;
	  goto fin_read;
	}
	break;
      case TIFFTAG_COMPRESSION:
	myTiff->compresion = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	if (myTiff->compresion != COMPRESSION_NONE) {
	  fprintf(stderr,"The file \"%s\" uses a compresion method not available\n",name);
	  retorno = -1;
	  goto fin_read;
	}
	break;
      case TIFFTAG_PHOTOMETRIC:
	myTiff->photometric = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	if (myTiff->photometric > PHOTOMETRIC_MINISBLACK) {
	  fprintf(stderr,"The file \"%s\" has a photometric interpretation not available\n",name);
	  retorno = -1;
	  goto fin_read;
	}
	break;
      case TIFFTAG_FILLORDER:
	myTiff->fillOrder = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	if (myTiff->fillOrder != FILLORDER_MSB2LSB) {
	  fprintf(stderr,"The file \"%s\" has a fillorder not valid\n",name);
	  retorno = -1;
	  goto fin_read;
	}
	break;
      case TIFFTAG_STRIPOFFSETS:
	type = integer2(data[2],data[3],myTiff->IIorMM);
	myTiff->numberStrips = integer4(data[4],data[5],data[6],data[7],myTiff->IIorMM);
	stripOffset.begin = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	if (myTiff->numberStrips > 1) {
	  if (type == TIFF_SHORT) {
	    stripOffset.shortOrLong = 0;
	    stripOffset.TIFF_long = NULL;
	    ami_malloc1d(stripOffset.TIFF_short,short,myTiff->numberStrips);
	  }
	  else if (type == TIFF_LONG) {
	    stripOffset.shortOrLong = 1;
	    stripOffset.TIFF_short = NULL;
	    ami_malloc1d(stripOffset.TIFF_long,long,myTiff->numberStrips);
	  }
	  else {
	    fprintf(stderr,"There is an error with type definition.\n");
	    retorno = -1;
	    goto fin_read;
	  }
	}
	break;
      case TIFFTAG_SAMPLESPERPIXEL:
	myTiff->samplesPerPixel = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	if (myTiff->samplesPerPixel != 1) {
	  fprintf(stderr,"The file \"%s\" not is a bilevel or grayscale image.\n",name);
	  retorno = -1;
	  goto fin_read;
	}
	break;
      case TIFFTAG_ROWSPERSTRIP:
	myTiff->rowsPerStrip = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	break;
      case TIFFTAG_STRIPBYTECOUNTS:
	type = integer2(data[2],data[3],myTiff->IIorMM);
	myTiff->numberStrips = integer4(data[4],data[5],data[6],data[7],myTiff->IIorMM);
	stripByteCounts.begin = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	if (myTiff->numberStrips > 1) {
	  if (type == TIFF_SHORT) {
	    stripByteCounts.shortOrLong = 0;
	    stripByteCounts.TIFF_long = NULL;
	    ami_malloc1d(stripByteCounts.TIFF_short,short,myTiff->numberStrips);
	  }
	  else if (type == TIFF_LONG) {
	    stripByteCounts.shortOrLong = 1;
	    stripByteCounts.TIFF_short = NULL;
	    ami_malloc1d(stripByteCounts.TIFF_long,long,myTiff->numberStrips);
	  }
	  else {
	    fprintf(stderr,"There is an error with type definition.\n");
	    retorno = -1;
	    goto fin_read;
	  }
	}
	break;
      case TIFFTAG_XRESOLUTION:
	myTiff->xResolution.offset = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	break;
      case TIFFTAG_YRESOLUTION:
	myTiff->yResolution.offset = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	break;
      case TIFFTAG_PLANARCONFIG:
	myTiff->planarConfiguration = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	if (myTiff->planarConfiguration != PLANARCONFIG_CONTIG) {
	  fprintf(stderr,"The file \"%s\" uses a planar configuration not available\n",name);
	  retorno = -1;
	  goto fin_read;
	}
	break;
      case TIFFTAG_RESOLUTIONUNIT:
	myTiff->resolutionUnit = integer4(data[8],data[9],data[10],data[11],myTiff->IIorMM);
	break;
      default:
	break;
      }
    }
    
    /* Read the offset of the next IFD */
    fread(data,sizeof(long),1,fptr);
    myTiff->offsetNextIFD = integer4(data[0],data[1],data[2],data[3],myTiff->IIorMM);
    
    /* Read the image */
    if (myTiff->numberStrips == 1) {
      fseek(fptr,stripOffset.begin,SEEK_SET);
      if (myTiff->image.charOrShort == 0)
	fread(myTiff->image.TIFF_char,stripByteCounts.begin,1,fptr);
      else
	fread(myTiff->image.TIFF_short,stripByteCounts.begin,1,fptr);
    }
    else if (myTiff->numberStrips > 1) {
      /* Read the offsets of strips */
      fseek(fptr,stripOffset.begin,SEEK_SET);
      if (stripOffset.shortOrLong == 0)
	fread(stripOffset.TIFF_short,sizeof(short)*myTiff->numberStrips,1,fptr);
      else
	fread(stripOffset.TIFF_long,sizeof(long)*myTiff->numberStrips,1,fptr);
      
      /* Read the byte counts of strips */
      fseek(fptr,stripByteCounts.begin,SEEK_SET);
      if (stripByteCounts.shortOrLong == 0)
	fread(stripByteCounts.TIFF_short,sizeof(short)*myTiff->numberStrips,1,fptr);
      else
	fread(stripByteCounts.TIFF_long,sizeof(long)*myTiff->numberStrips,1,fptr);
      
      /* And now... read the image */
      size1 = 0;
      for (j = 0 ; j < myTiff->numberStrips; j++) {
	/* Where is the strip J? */
	if (stripOffset.shortOrLong == 0)
	  fseek(fptr,stripOffset.TIFF_short[j],SEEK_SET);
	else
	  fseek(fptr,stripOffset.TIFF_long[j],SEEK_SET);
	
	/* How many bytes per strip J ?*/
	byteCountsJ = (stripByteCounts.shortOrLong == 0) ? stripByteCounts.TIFF_short[j] : stripByteCounts.TIFF_long[j];
	
	/* Read the strip J */
	if (myTiff->image.charOrShort == 0)
	  fread(&myTiff->image.TIFF_char[size1],byteCountsJ,1,fptr);
	else
	  fread(&myTiff->image.TIFF_short[size1],byteCountsJ,1,fptr);
	
	size1 += byteCountsJ;
      }
      
      if (size0 != size1) {
	fprintf(stderr,"The file \"%s\" has a number of bytes not valid\n",name);
	retorno = -1;
	goto fin_read;
      }
    }
    else {
      fprintf(stderr,"The file \"%s\" has a number os strips not valid\n",name);
      retorno = -1;
      goto fin_read;
    }
    
    /* Read the x and y resolution */
    fseek(fptr,myTiff->xResolution.offset,SEEK_SET);
    fread(&myTiff->xResolution.num,sizeof(long),1,fptr);
    fread(&myTiff->xResolution.den,sizeof(long),1,fptr);
    
    fseek(fptr,myTiff->yResolution.offset,SEEK_SET);
    fread(&myTiff->yResolution.num,sizeof(long),1,fptr);
    fread(&myTiff->yResolution.den,sizeof(long),1,fptr);
    
  } while (myTiff->offsetNextIFD != 0);
  
 fin_read:
  
  /* Close the file and free the memory */
  fclose(fptr);
  if (data != NULL) free(data);
  if (stripByteCounts.TIFF_short != NULL) free(stripByteCounts.TIFF_short);
  if (stripByteCounts.TIFF_long != NULL) free(stripByteCounts.TIFF_long);
  if (stripOffset.TIFF_short != NULL) free(stripOffset.TIFF_short);
  if (stripOffset.TIFF_long != NULL) free(stripOffset.TIFF_long);
  
  return retorno;
}


/* Read a tiff file with:
   - 8 or 16 bits -> float
   - No compression
   - 0 = black or 0 = white
   - Order MSB2LSB
   - Planar config
*/
int read_tiff (const char name[200], float **image, int *width, int *length, int *charOrShort)
{
  struct TIFF_struct myTiff;
  int retorno, size, i;
  
  /* Call the read function */
    retorno = read_tiff_TIFF_struct (name,&myTiff);
    
    if (retorno != -1) {
      /* Valid data */
      *width = myTiff.width;
      *length = myTiff.length;
      size = myTiff.width*myTiff.length;
      ami_malloc1d(*image,float,size);
      *charOrShort = myTiff.image.charOrShort;
      for (i = 0; i < size; i++)
	image[0][i] = (myTiff.image.charOrShort == 0) ? myTiff.image.TIFF_char[i] : myTiff.image.TIFF_short[i];
    }
    else
      fprintf(stderr,"Image read failed\n");

    
    if (myTiff.image.charOrShort == 0) free(myTiff.image.TIFF_char);
    else free(myTiff.image.TIFF_short);
    
    return retorno;
}
