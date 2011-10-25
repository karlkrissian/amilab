/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@ctm.ulpgc.es

    OSRAD is a noise reducing filter program
    ==================================================
    Copyright (C) 2008  Karl Krissian

    OSRAD is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    OSRAD is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ==================================================
   The full GNU Lesser General Public License file is in LesserGPL_license.txt
*/

/*
   image format:  amimage

   Karl Krissian

   Universidad de Las Palmas de Gran Canaria

   07/05/01


*/


#ifndef _AMIMAGE_H_
#define _AMIMAGE_H_

#include <sstream>
#include <boost/scoped_ptr.hpp>

// gccxml compilation pb
#ifndef __GCCXML__
  #include <boost/iostreams/filtering_stream.hpp>
  #include <boost/iostreams/filtering_streambuf.hpp>
#endif

#include "CommonConfigure.h"

/*
#include <fstream>
#include <iostream>

//using namespace boost::iostreams;
//using namespace boost;

//using -- namespace std;
*/

#include <stdio.h>
#include "DefineClass.hpp"

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

/*
#if (defined (_ALPHA_) || defined (_LINUX_)|| defined (_LITTLE_ENDIANNESS_))
#define ARCHITECTURE_ENDIANNESS LITTLE_END
#else
#define ARCHITECTURE_ENDIANNESS BIG_END
#endif
*/

#define AMI_MAGIC "AMIM"
/* Magic header for amimages */

#define INR_MAGIC "#INR"
/* Magic header for inrimages */

#define ANALYZE_LE_MAGIC "\000\000\001\134"
/* Magic header for ANALYZE files written in little endian format */

#define ANALYZE_BE_MAGIC "\134\001\000\000"
/* Magic header for ANALYZE files written in big endian format */

/*
#ifndef false
  #define false 0
#endif
#ifndef true
  #define true  1
#endif
*/

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
  AMI_VECTOR,    // vector of dimension n
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


/*//----------------------------------------------------------------------
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
*/

//----------------------------------------------------------------------
class COMMON_EXPORT amimage
{

  DEFINE_CLASS(amimage)

protected:

  void initialize();

  bool open_file( const char* filename);

  void close_file();

public:
  int xdim;
  int ydim;
  int zdim;

  int vdim; // vector size for vector field

  AMI_REPRES   repres; // representation of a scalar (int, float, ..)
  AMI_TYPE     type;   // type: vector, scalar, RGB, etc ...


  AMI_DATAFILE   datafile;
  std::string         file_prefix;
  std::string         file_format;
  unsigned short first_slice;
  unsigned short last_slice;

  void* data;
  long data_size;

  float voxsize_x;
  float voxsize_y;
  float voxsize_z;

  // Translation in space coord of the voxel (0,0,0)
  float transl_x;
  float transl_y;
  float transl_z;

  AMIENDIANNESS endianness;
  AMIENDIANNESS ARCHITECTURE_ENDIANNESS;
  SCANORDER     scanorder;

  boost::scoped_ptr<std::stringstream> file_str;
  //istream*  file_str;

  // still keep it until everything is changed
 // FILE*         file;
 // FILE_MODE     open_mode;

  unsigned char header_read;

  unsigned char data_allocated;

  // Will have to be an independent object class
  float         TransfMatrix[4][4];

  amimage();

  virtual ~amimage();

  void SetRepres(AMI_REPRES r) { repres = r; }

  AMI_REPRES GetRepres() { return repres; }

  void SetType(  AMI_TYPE   t) { type   = t; }

  AMI_TYPE GetType() { return type; }

  void SetDim( int tx, int ty, int tz, int tv=1)
  {
    xdim = tx;
    ydim = ty;
    zdim = tz;
    vdim = tv;
  }

  void SetVDim(int tv) { vdim= tv; }

  int GetXDim() {return xdim; }
  int GetYDim() {return ydim; }
  int GetZDim() {return zdim; }
  int GetVDim() {return vdim; }

  void ComputeDataSize();

  unsigned long  GetDataSize() {return data_size; }
  void*          GetData() { return data; }
  void const*    GetConstData() const { return data; }
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

  /**
    used to force the endianness before writing the file
  **/
  void SetEndianness( AMIENDIANNESS end)
  {
    endianness=end;
  }

  AMIENDIANNESS GetEndianness( )
  {
    return this->endianness;
  }

  AMIENDIANNESS GetMachineEndianness( )
  {
    int x = 1;
    if(*(char *)&x == 1)
        return LITTLE_END;
    else
        return BIG_END;
  }

  float GetTX() {return transl_x; }
  float GetTY() {return transl_y; }
  float GetTZ() {return transl_z; }

  void SetTX(float tx) { transl_x=tx; }
  void SetTY(float ty) { transl_y=ty; }
  void SetTZ(float tz) { transl_z=tz; }

  /**
   * Allocate the memory for the image.
   * @return true is success, false otherwise.
   */
  bool allocate();

  template <class T>
  T GetValue(char* buf,int offset)
  {
    if (this->ARCHITECTURE_ENDIANNESS != this->endianness) {
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

  unsigned char readdata3D_ext();

  unsigned char readdata();

#ifndef __GCCXML__

  unsigned char writeheader(const char* filename,
      boost::iostreams::filtering_ostream& out,
      bool include_header=true);

  unsigned char writedata(boost::iostreams::filtering_ostream& out);
#endif
  
  unsigned char read(const char* filename);

  unsigned char write(const char* filename, bool include_header=true);

  void swap_bytes();

  void displayinfo();

  void CopyDataField( int n, void* d);
};



#endif // _AMIMAGE_H
