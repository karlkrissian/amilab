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
/*
   image format:  amimage

   Karl Krissian

   Universidad de Las Palmas de Gran Canaria 

   07/05/01


*/


#ifndef _AMIMAGE_H_
#define _AMIMAGE_H_

#include <stdio.h>


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

#if (defined (_ALPHA_) || defined (_LINUX_))
#define ARCHITECTURE_ENDIANNESS LITTLE_END
#else
#define ARCHITECTURE_ENDIANNESS BIG_END
#endif

#define AMI_MAGIC "AMIM"
/* Magic header for amimages */

#define INR_MAGIC "#INR"
/* Magic header for inrimages */

#define ANALYZE_LE_MAGIC "\000\000\001\134"
/* Magic header for ANALYZE files written in little endian format */

#define ANALYZE_BE_MAGIC "\134\001\000\000"
/* Magic header for ANALYZE files written in big endian format */

#define FALSE 0
#define TRUE  1


typedef enum {
  AMI_DATAINT,      // data are in the same file as the header
  AMI_DATAEXT      // data are on separate files
} AMI_DATAFILE;

typedef enum {
  AMI_UNKNOWN,
  AMI_BIN,            // Binary 1 bit 
  AMI_UNSIGNED_CHAR,  // Unsigned 8 bits 
  AMI_SIGNED_CHAR,    // Signed 8 bits 
  AMI_UNSIGNED_SHORT, // Unsigned 16 bits 
  AMI_SIGNED_SHORT,   // Signed 16 bits 
  AMI_UNSIGNED_INT,   // Unsigned 32 bits 
  AMI_SIGNED_INT,     // Signed 32 bits 
  AMI_UNSIGNED_LONG,  // Unsigned 64 bits 
  AMI_SIGNED_LONG,    // Signed 64 bits 
  AMI_FLOAT,          // Float 32 bits 
  AMI_DOUBLE          // Float 64 bits 
} AMI_REPRES;


typedef enum {
  AMI_SCALAR,    // scalar image
  AMI_2DVECTOR,  // 2D vector
  AMI_3DVECTOR,  // 3D vector
  AMI_RGB,       // RGB
  AMI_2DSYMMAT,  // 2D SYMETRIC MATRIX
  AMI_3DSYMMAT,  // 3D SYMETRIC MATRIX
  AMI_COMPLEX    // complex
} AMI_TYPE;

typedef enum {
  UNKNOWN_END,
  BIG_END,
  LITTLE_END
} AMIENDIANNESS;


typedef enum {
  SAG_LR,
  SAG_RL,
  AX_SI,
  AX_IS,
  COR_AP,
  COR_PA
} SCANORDER;

// file open mode 
typedef enum {
  FILE_CLOSE,       // no file open 
  FILE_STDIO,       // file is stdin or stdout 
  FILE_PIPE,        // file is a pipe 
  FILE_STD          // file is standard 
} FILE_MODE;


//----------------------------------------------------------------------
// Write an image in amimage format
// if type is AMI_SCALAR uses only the 'r' information
// if type is AMI_RGB uses r,g,b components
unsigned char WriteAMI(const char* name,
		       AMI_REPRES repres,
		       AMI_TYPE type,
		       void* r,
		       void* g,
		       void* b,
		       int tx,
		       int ty,
		       int tz
		       );

//----------------------------------------------------------------------
class amimage
{

protected:

  void initialize();

  void open_file( const char* filename);

  void close_file();

public:
  int xdim;
  int ydim;
  int zdim;

  AMI_REPRES   repres; // representation of a scalar (int, float, ..)
  AMI_TYPE     type;   // type: vector, scalar, RGB, etc ...


  AMI_DATAFILE   datafile;
  char           file_prefix[256];
  char           file_format[256];
  unsigned short first_slice;
  unsigned short last_slice;

  void* data;
  unsigned long data_size;

  float voxsize_x;  
  float voxsize_y;  
  float voxsize_z;  

  // Translation in space coord of the voxel (0,0,0)
  float transl_x;  
  float transl_y;  
  float transl_z;  

  AMIENDIANNESS endianness;
  SCANORDER     scanorder;

  FILE*         file;
  FILE_MODE     open_mode;
  unsigned char header_read;

  unsigned char data_allocated;

  // Will have to be an independent object class
  float         TransfMatrix[4][4];

  amimage();

  ~amimage();

  void SetRepres(AMI_REPRES r) { repres = r; }

  AMI_REPRES GetRepres() { return repres; }

  void SetType(  AMI_TYPE   t) { type   = t; }

  AMI_TYPE GetType() { return type; }

  void SetDim( int tx, int ty, int tz)
  {
    xdim = tx;
    ydim = ty;
    zdim = tz;
  }

  int GetXDim() {return xdim; }
  int GetYDim() {return ydim; }
  int GetZDim() {return zdim; }

  unsigned long  GetDataSize() {return data_size; }
  void*          GetData() { return data; }
  void           SetData( void* d);

  void SetVoxelSize( float vx, float vy, float vz)
  {
    voxsize_x = vx;
    voxsize_y = vy;
    voxsize_z = vz;
  }

  float GetVX() {return voxsize_x; }
  float GetVY() {return voxsize_y; }
  float GetVZ() {return voxsize_z; }

  void SetVX(float vx) { voxsize_x=vx; }
  void SetVY(float vy) { voxsize_y=vy; }
  void SetVZ(float vz) { voxsize_z=vz; }

  void SetTranslation( float tx, float ty, float tz)
  {
    transl_x = tx;
    transl_y = ty;
    transl_z = tz;
  }

  float GetTX() {return transl_x; }
  float GetTY() {return transl_y; }
  float GetTZ() {return transl_z; }

  void SetTX(float tx) { transl_x=tx; }
  void SetTY(float ty) { transl_y=ty; }
  void SetTZ(float tz) { transl_z=tz; }

  unsigned char allocate();

  template <class T>
  T GetValue(char* buf,int offset) 
  { 
    if (ARCHITECTURE_ENDIANNESS != endianness) {
      int size,b;
      char* ptr;
      T res;
  
      size = sizeof(T);
      ptr = new char[size];
      for(b=0;b<size;b++) 
	ptr[size-1-b] = buf[offset+b];
      res = *(T*) ptr;
      delete [] ptr;
      return res;
    }
    else
      return *(T*)(buf+offset); 
  }

  unsigned char CheckGenesisHeader(char* ptr, int slice, float corner[4][3]);

  void          GetTransfMatrix(float m[4][4]) 
  { 
    for(int i=0;i<4;i++) 
      for(int j=0;j<4;j++) 
	m[i][j] = TransfMatrix[i][j]; 
  }

  unsigned char readheader(const char* filename);

  unsigned char readdata_ext();

  unsigned char readdata();

  unsigned char writeheader(const char* filename);

  unsigned char writedata();

  unsigned char read(const char* filename);

  unsigned char write(const char* filename);

  void swap_bytes();

  void displayinfo();

  void CopyDataField( int n, void* d);
};



#endif // _AMIMAGE_H
