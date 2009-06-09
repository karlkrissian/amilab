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

#include "amimage.hpp"
#include <string.h>
#include <stdio.h>
#include <locale.h>

#include <xmmintrin.h>

#include <boost/iostreams/copy.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/regex.hpp>
#include <boost/format.hpp>

#define BOOST_IOSTREAMS_NO_LIB
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filter/bzip2.hpp>
#include <boost/iostreams/device/file.hpp>

namespace bf = boost::filesystem;

#include <fstream>
#include <iostream>
using namespace boost::iostreams;
using namespace boost;

using namespace std;

/*// compile time endianness
#if (defined (_ALPHA_) || defined (_LINUX_)|| defined (_LITTLE_ENDIANNESS_))
#define ARCHITECTURE_ENDIANNESS LITTLE_END
#else
#define ARCHITECTURE_ENDIANNESS BIG_END
#endif
*/

// for reading genesis headers
#define OFFSET_HEADER                0
#define OFFSET_WIDTH                 8
#define OFFSET_HEIGHT               12
#define OFFSET_IMAGE_HEADER        148

// Image Header information
#define OFFSET_IH_DIM_X             42
#define OFFSET_IH_DIM_Y             46
#define OFFSET_IH_PIXEL_SIZE_X      50
#define OFFSET_IH_PIXEL_SIZE_Y      54
#define OFFSET_IH_SLICE_THICKNESS   26

#define OFFSET_IH_TOP_LEFT         154
#define OFFSET_IH_TOP_RIGHT        166
#define OFFSET_IH_BOT_RIGHT        178


extern unsigned char GB_debug;
extern unsigned char GB_verbose;

#include "amilab_messages.h"

#define NEW(mess,ptr,type,size) \
    ptr = (type*) _mm_malloc (sizeof(type)*size,16); \
    CLASS_MESSAGE( boost::format("%1%, allocation of %2% Mb") \
        % mess % (1.0*size*sizeof(type)/1000000.0));

#define DELETE(ptr) \
  { \
    CLASS_MESSAGE( " calling _mm_free() "); \
   _mm_free(ptr); ptr = NULL; } \


#define NUM_REPRES 12


static string repres_datafile[2] =
{ "INTERN",
  "EXTERN"
};

// Creating a std::vector from the strings
std::vector<string> repres_datafile_v(repres_datafile, repres_datafile+2);

static string repres_string[NUM_REPRES] =
{ "UNKNOWN",
  "BIN",            // Binary 1 bit
  "UCHAR",  // Unsigned 8 bits
  "SCHAR",    // Signed 8 bits
  "USHORT", // Unsigned 16 bits
  "SSHORT",   // Signed 16 bits
  "UINT",   // Unsigned 32 bits
  "SINT",     // Signed 32 bits
  "ULONG",  // Unsigned 64 bits
  "SLONG",    // Signed 64 bits
  "FLOAT",          // Float 32 bits
  "DOUBLE"          // Float 64 bits
};

// Creating a std::vector from the strings
std::vector<string> repres_string_v(repres_string, repres_string+12);


static unsigned char repres_size[NUM_REPRES] =
{
  0,
  1, // A voir: traitement a part ...
  sizeof(unsigned char),
  sizeof(signed char),
  sizeof(unsigned short ),
  sizeof(signed short ),
  sizeof(unsigned int),
  sizeof(signed int),
  sizeof(unsigned long),
  sizeof(signed long),
  sizeof(float),
  sizeof(double)
};

static string type_string[8] = {
  "SCALAR",    // scalar image
  "2DVECTOR",  // 2D vector
  "3DVECTOR",  // 3D vector
  "VECTOR",    // generic vector
  "RGB",       // RGB
  "2DSYMMAT",  // 2D SYMETRIC MATRIX
  "3DSYMMAT",  // 3D SYMETRIC MATRIX
  "COMPLEX"    // complex
};

// Creating a std::vector from the strings
std::vector<string> type_string_v(type_string, type_string+8);

// Get rid off type_size in the future ??
static unsigned char type_size[8] = {
  1,    // scalar image
  1,    // vector 2d: using vdim
  1,    // vector 3d: using vdim
  1,    // vector: using vdim
  1,    // RGB
  3,    // 2D SYMETRIC MATRIX
  6,    // 3D SYMETRIC MATRIX
  2    // complex
};

static string end_string[3] = {
  "UNKNOWN",
  "BIG",
  "LITTLE"
};

// Creating a std::vector from the strings
std::vector<string> end_string_v(end_string, end_string+3);

static string so_string[6] = {
  "LR", // SAGITTAL Left Right
  "RL",
  "SI", // AXIAL Superior Inferior
  "IS",
  "AP", // CORONAL Anterior Posterior
  "PA"
};

// Creating a std::vector from the strings
std::vector<string> so_string_v(so_string, so_string+6);

//-------------------------------------------------------------
template<class T>
bool check_value( const string& line,
                  const string& st,
                  const string& format,
                  T& val,
                  bool& found)
{
  if (found) return false;
  boost::smatch what;
  boost::regex lower_case("\\l");
  bool result;

  // get rid of lower cases on the left side of '='
  //cout << "**" << line2 << "**" << endl;
  //cout << st + string(" = ")+format << endl;
  try {
    boost::regex e(string("(\\w+)\\s*=\\s*")+format);
    result = boost::regex_search(line, what, e);
    // get first part
    string first_part;
    stringstream ssout(what[1]);
    ssout>>first_part;
    // remove lower cases from it
    string line2= regex_replace(first_part, lower_case, "",
                                boost::match_default | boost::format_sed);
    if (line2.compare(st)!=0) {
      //cout << "no match for " << st << endl;
      return false;
    }
  } catch (boost::regex_error& e)
  {
      cout << " not a valid regular expression: \""
          << e.what() << "\"" << endl;
  }

  if (result) {
    stringstream ssout(what[2]);
    ssout>>val;
    cout << st << " = " << val << endl;
    found = true;
    return true;
  }
  cout << "no match for " << st << endl;
  return false;
}



//-------------------------------------------------------------
template<class T>
bool check_enum( const string&   line,
                 const string&   st,
                 const string&   format,
                 const vector<string>& enum_strings,
                 T& val,
                 bool& found)
{
  if (found) return false;
  boost::smatch what;
  boost::regex lower_case("\\l");
  bool result;

  try {
    boost::regex e(string("(\\w+)\\s*=\\s*")+format);
    result = boost::regex_search(line, what, e);
    // get first part
    string first_part;
    stringstream ssout(what[1]);
    ssout>>first_part;
    // remove lower cases from it
    string line2= regex_replace(first_part, lower_case, "",
                                boost::match_default | boost::format_sed);
    if (line2.compare(st)!=0) {
      //cout << "no match for " << st << endl;
      return false;
    }
  } catch (boost::regex_error& e)
  {
      cout << " not a valid regular expression: \""
          << e.what() << "\"" << endl;
  }

  if (result) {
    // find the corresponding string
    vector<string>::const_iterator i;
    for(i=enum_strings.begin(); i!=enum_strings.end(); ++i) {
      if ((*i).compare(what[2])==0) {
        int val_int = i-enum_strings.begin();
        val = T(val_int);
        cout << st << " = " << enum_strings[val] << endl;
        found = true;
        return true;
      }
    }
  }
  cout << "no match for " << st << endl;
  return false;
}


// Check if the upper characters of the first string
// correspond to the second string
unsigned char CompareString( char* st1, char* st2)
{
  int i1,i2;
  i1=i2=0;

  if (strlen(st2)==0) return 0;

  while (st1[i1]!='\0') {
    if ((st1[i1]>='A') && (st1[i1]<='Z')) {
      if (st1[i1] == st2[i2])
    i2++;
      else
    return 0;
    }
    i1++;
  }
  return (st2[i2]=='\0');
}


/*
//----------------------------------------------------------------------
unsigned char WriteAMI(const char* name,
               AMI_REPRES repres,
               AMI_TYPE type,
               void* r,
               void* g,
               void* b,
               int tx,
               int ty,
               int tz
               )
//
{

  amimage im;

  im.SetDim(tx,ty,tz);
  im.SetRepres(repres);
  im.SetType(type);

  im.allocate();

  switch (type) {
    case AMI_SCALAR:
      im.CopyDataField(0,r);
      break;

    case AMI_RGB:
      im.CopyDataField(0,r);
      im.CopyDataField(1,g);
      im.CopyDataField(2,b);
      break;

    case AMI_VECTOR:
      if (im.GetVDim()==3) {
        im.CopyDataField(0,r);
        im.CopyDataField(1,g);
        im.CopyDataField(2,b);
      } else
    fprintf(stderr,"amimage::WriteAMI()\n vectors must be of size 3 \n");
      break;

    default:
      fprintf(stderr,"WriteAMI() \t type not available \n");
  }

  return im.write(name);

} // WriteAMI()
*/

//----------------------------------------------------------------------
void amimage::ComputeDataSize()
{
    data_size = xdim*ydim*zdim*vdim*
                repres_size[repres]*type_size[type];
}


//----------------------------------------------------------------------
void amimage::initialize()
//            ----------
{
  int i,j;

  xdim   = ydim = zdim = 0;
  vdim   = 1;
  repres = AMI_UNSIGNED_CHAR;
  type   = AMI_SCALAR;
  data   = NULL;

  voxsize_x  =
  voxsize_y  =
  voxsize_z  = 1.0;

  transl_x =
  transl_y =
  transl_z = 0.0;

  ARCHITECTURE_ENDIANNESS = GetMachineEndianness();
  endianness = ARCHITECTURE_ENDIANNESS;

  scanorder = SAG_LR;

  header_read    = false;
  data_allocated = false;

  datafile     = AMI_DATAINT;
  file_prefix = "";
  file_format = "";
  first_slice  = 0;
  last_slice   = 0;

  // Identity Matrix for the transformation
  for(i=0;i<4;i++)
  for(j=0;j<4;j++)
    TransfMatrix[i][j] = 0;
  for(i=0;i<3;i++) TransfMatrix[i][i] = 1;

}


//----------------------------------------------------------------------
bool amimage::open_file( const char* filename)
//
{
  // don´ t use stdin
  // 1. check existence of the file
  bf::path p(filename);
  if( !bf::exists(p) )  {
    std::cerr <<p.leaf()<<" does not exist.\n";
    return false;
  }
  if( bf::is_directory(p) ) {
    std::cerr<<p.leaf()<<" is a directory.\n";
    return false;
  }

  bool file_read=false;
  filtering_stream<input> filter_str;


  // Trying gzip
  if (!file_read) {
    try {
      if (GB_verbose)
        std::cout << "trying gzip" << std::endl;
      file_read = true;
      ifstream file(filename, ios_base::in | ios_base::binary);
      filter_str.reset();
      filter_str.push(gzip_decompressor());
      filter_str.push(file);
      boost::iostreams::copy(filter_str, *file_str.get());
    } catch (boost::iostreams::gzip_error) {
      if (GB_verbose)
        std::cout << "gzip failed" << std::endl;
      file_read=false;
    }
  }

#ifndef WIN32 // don´t know why windows doesn´t catch the exception for bzip2 and zlib ...
  // Trying bzip2
  if (!file_read) {
    try {
      if (GB_verbose)
        std::cout << "trying bzip2" << std::endl;
      file_read = true;
      ifstream file(filename, ios_base::in | ios_base::binary);
      filter_str.reset();
      filter_str.push(bzip2_decompressor());
      filter_str.push(file);
      boost::iostreams::copy(filter_str, *file_str.get());
    } catch (boost::iostreams::bzip2_error) {
      if (GB_verbose)
        std::cout << "bzip2 failed" << std::endl;
      file_read=false;
    }
  }

  // Trying zlib
  if (!file_read) {
    try {
      if (GB_verbose)
        std::cout << "trying zlib" << std::endl;
      file_read = true;
      ifstream file(filename, ios_base::in | ios_base::binary);
      filter_str.reset();
      filter_str.push(zlib_decompressor());
      filter_str.push(file);
      boost::iostreams::copy(filter_str, *file_str.get());
    } catch (boost::iostreams::zlib_error) {
      if (GB_verbose)
        std::cout << "zlib failed" << std::endl;
      file_read=false;
    }
  }
#endif // not WIN32

  // Normal read
  if (!file_read) {
    if (GB_verbose)
      std::cout << "trying standard file" << std::endl;
    file_read = true;
    ifstream file(filename, ios_base::in | ios_base::binary);
    filter_str.reset();
    filter_str.push(file);
    boost::iostreams::copy(filter_str, *file_str.get());
  }

  return file_read;

} // open_file()


//----------------------------------------------------------------------
void amimage::close_file(  )
//
{

  file_str.reset(new stringstream);


} // close_file()


//----------------------------------------------------------------------
void amimage::displayinfo()
{

  printf("Image \n");
  printf(" Dimensions = ( %d %d %d) x %d \n", xdim,ydim,zdim,vdim);
  printf(" Voxel dimensions = ( %f %f %f )\n",
     voxsize_x, voxsize_y, voxsize_z);
  printf(" Translation = ( %f %f %f )\n",
     transl_x, transl_y, transl_z);

  cout << boost::format(" representation = %s\n")% repres_string[repres];
  cout << boost::format(" type = %s\n") % type_string[type];

}


//----------------------------------------------------------------------
amimage::amimage() : file_str(new stringstream)
//       -------
{
  initialize();
}


//----------------------------------------------------------------------
amimage::~amimage()
//        -------
{
  if (data_allocated) {
    DELETE(data);
  }
}


//----------------------------------------------------------------------
unsigned char amimage::allocate()
//                     --------
{

  if (data_allocated) {
    DELETE(data);
  }

  this->ComputeDataSize();
  NEW("amimage::allocate", data,  unsigned char, data_size);

  if (data)
    data_allocated = true;
  else
    data_allocated = false;

  return data_allocated;

} // allocate()



//----------------------------------------------------------------------
void  amimage::SetData( void* d)
//             -------
{
  this->ComputeDataSize();
  if (data_allocated)
    fprintf(stderr,"amimage::SetData() \t data already allocated \n");
  else
    data = d;

} // SetData()


//----------------------------------------------------------------------
unsigned char  amimage::readheader( const char* filename)
//                      ----------
{
  int          resscan;
  unsigned int v_uint;
  float        v_float;
  char         v_string[256];
  char         attrib[100];
  char        line[200];
  int version;
  int release;
  int c;

  //  fprintf(stderr,"amimage::readheader() 1 \n");
  setlocale(LC_NUMERIC,"C");
  // Initialization of the structure
  initialize();

  //  fprintf(stderr,"amimage::readheader() 2 \n");

  // 1. Open the file
  if (open_file(filename)) {


    // 2. Read the parameters
    // read magic number
    boost::smatch what;
    boost::regex lower_case("\\l");

    file_str->seekg(0);
    file_str->getline(line,255);
    //string line_str(line);
    boost::regex e("AMIMAGE (\\d)+.(\\d)+");
    string sline(line);
    if (boost::regex_search(sline, what, e)) {
      stringstream ssout1(what[1]);
      ssout1 >> version;
      stringstream ssout2(what[2]);
      ssout2 >> release;
    } else {
      CLASS_ERROR("not in ami format");
      return false;
    }

    // skip '('
    bool result;
    do {
      file_str->getline(line,255);
      boost::regex e("\\(");
      result = boost::regex_search(string(line), what, e);
    } while (!result);

    string uint_expr  ="(\\d+)";
    string float_expr ="([-+]?\\d*\\.?\\d+)"; // no exponential here?
    string enum_expr  ="(\\w*)";
    string fileprefix_expr="([\\w\\d\\s\\\\:/_.]+)";
    string fileformat_expr="([\\w\\d\\s\\\\:/_.%]+)";

    bool end_header=false;
    bool XD_found=false,YD_found=false,ZD_found=false;
    bool VD_found=false;
    bool VSX_found=false,VSY_found=false,VSZ_found=false;
    bool TX_found=false, TY_found=false, TZ_found=false;
    bool T_found=false,R_found=false,E_found=false;
    bool SO_found = false;
    bool DF_found = false;
    bool FS_found = false,LS_found = false;
    bool FP_found = false,FF_found = false;
    while (!end_header) {
      file_str->getline(line,255);

      // read parameters
      // read image size
      if (!check_value<int>(string(line),"XD",uint_expr,xdim,XD_found))
      if (!check_value<int>(string(line),"YD",uint_expr,ydim,YD_found))
      if (!check_value<int>(string(line),"ZD",uint_expr,zdim,ZD_found))
      if (!check_value<int>(string(line),"VD",uint_expr,vdim,VD_found))

      // read voxel size
      if (!check_value<float>(string(line),"VSX",float_expr,voxsize_x,
          VSX_found))
      if (!check_value<float>(string(line),"VSY",float_expr,voxsize_y,
          VSY_found))
      if (!check_value<float>(string(line),"VSZ",float_expr,voxsize_z,
          VSZ_found))

      // read translation
      if (!check_value<float>(string(line),"TX",float_expr,transl_x,
          TX_found))
      if (!check_value<float>(string(line),"TY",float_expr,transl_y,
          TY_found))
      if (!check_value<float>(string(line),"TZ",float_expr,transl_z,
          TZ_found))

      // read representation
      if (!check_enum<AMI_REPRES>( string(line),"R",enum_expr,
                              repres_string_v,repres,R_found))

      // read image type
      if (!check_enum<AMI_TYPE>( string(line),"T",enum_expr,
                            type_string_v,type,T_found))

      // read image endianness
      if (!check_enum<AMIENDIANNESS>(  string(line),"E",enum_expr,
                                  end_string_v,endianness,E_found))

      // read scan order
      if (!check_enum<SCANORDER>(  string(line),"SO",enum_expr,
                              so_string_v,scanorder, SO_found))

      // read scan order
      if (!check_enum<AMI_DATAFILE>( string(line),"DF",enum_expr,
                                repres_datafile_v,datafile, DF_found))

      // file prefix is kept for compatibility
      if (!check_value<string>( string(line),"FP",fileprefix_expr,
                                file_prefix, FP_found))
      if (!check_value<string>( string(line),"FF",fileformat_expr,
                                file_format, FP_found))

      if (!check_value<unsigned short>(string(line),"FS",
                                        uint_expr,first_slice, FS_found))
      if (!check_value<unsigned short>(string(line),"LS",
                                        uint_expr,last_slice, LS_found))
      {
        boost::regex e("\\)");
        end_header = boost::regex_search(string(line), what, e);
        if (!end_header)
          cerr << "amimage::readheader() line not recognized \n" << endl;
      }

    } // end_header

    // convert older representation to new format
    switch (type) {
      case AMI_2DVECTOR:
        type = AMI_VECTOR;
        vdim = 2;
        break;
      case AMI_3DVECTOR:
        type = AMI_VECTOR;
        vdim = 3;
        break;
      case AMI_RGB:
        type = AMI_VECTOR;
        repres = AMI_UNSIGNED_CHAR;
        vdim = 3;
    } // end switch type

  }
  else // could not open file
  {
    //fprintf(stderr,"amimage::readheader()\tnot in ami format \n");
    return false;
  }

  header_read = true;
  return true;

} // readheader()



//----------------------------------------------------------------------
unsigned char amimage::CheckGenesisHeader(char* ptr, int slice, float corner[4][3])
{
  char magic[5];
//  unsigned int width;
//  unsigned int height;
//  float vs[3];
//  char* imheaderbuf;
//  int   i;

  setlocale(LC_NUMERIC,"C");
  CLASS_MESSAGE("CheckGenesisHeader");

  // Return because of problems with byte swap .. (in linux)
  //    return 0;

  sprintf(magic,"%4s",ptr);
  if (strcmp(magic,"IMGF")!=0) {
    CLASS_MESSAGE("Not in Genesis Format");
    return 0;
  }
  else
    CLASS_MESSAGE("Image in Genesis Format");

  // pb to read Dicom ...
#ifdef _CHECK_GENESIS
  if (slice==0) {
    // check the dimensions and voxel size
    width  = GetValue<unsigned int>(ptr,OFFSET_WIDTH);
    height = GetValue<unsigned int>(ptr,OFFSET_HEIGHT);

    if (GB_debug)
      fprintf(stderr,"width %3.3f, height %3.3f \n",
         width,height);

    imheaderbuf = ptr+GetValue<unsigned int>(ptr,OFFSET_IMAGE_HEADER);
    vs[0] = GetValue<float>(imheaderbuf,OFFSET_IH_PIXEL_SIZE_X);
    vs[1] = GetValue<float>(imheaderbuf,OFFSET_IH_PIXEL_SIZE_Y);
    vs[2] = GetValue<float>(imheaderbuf,OFFSET_IH_SLICE_THICKNESS);

    if (width!=xdim) {
      fprintf(stderr,"amimage::CheckGenesisHeader() \t Error xdim != width \n");
      fprintf(stderr,"amimage::CheckGenesisHeader() \t xdim = %u width = %u \n",
          xdim, width);
    }

    if (height!=ydim) {
      fprintf(stderr,"amimage::CheckGenesisHeader() \t Error ydim != height \n");
      fprintf(stderr,"amimage::CheckGenesisHeader() \t ydim = %u height = %u \n",
          ydim, height);
    }

    if ((voxsize_x!=vs[0])||(voxsize_y!=vs[1])||(voxsize_z!=vs[2])) {
      fprintf(stderr,"amimage::CheckGenesisHeader() \t Error different voxel sizes \n");
      fprintf(stderr,"amimage::CheckGenesisHeader() \t amimage (%f,%f,%f) generis (%f,%f,%f) \n",
          voxsize_x,voxsize_y,voxsize_z,vs[0],vs[1],vs[2]);
    }

    // Get the three corners for the first slice
    // First Slice, Top, Left
    for (i=0;i<=2;i++) corner[0][i] = GetValue<float>(imheaderbuf,OFFSET_IH_TOP_LEFT +4*i);
    for (i=0;i<=2;i++) corner[1][i] = GetValue<float>(imheaderbuf,OFFSET_IH_TOP_RIGHT+4*i);
    for (i=0;i<=2;i++) corner[2][i] = GetValue<float>(imheaderbuf,OFFSET_IH_BOT_RIGHT+4*i);

    return 1;
  }

  if (slice==zdim-1) {
    imheaderbuf = ptr+GetValue<unsigned int>(ptr,OFFSET_IMAGE_HEADER);
    // Get the  corner for the last slice
    // First Slice, Top, Left
    for (i=0;i<=2;i++) corner[3][i] =  GetValue<float>(imheaderbuf,OFFSET_IH_TOP_LEFT+4*i);
    return 1;
  }
#endif
    return 1;

} // CheckGenesisHeader()


//----------------------------------------------------------------------
unsigned char  amimage::readdata_ext( )
//                      ------------
{
  FILE*          f;
  int            z; //,error;
  string         fname;
  string         fname2;
  char           cmd[1024];
  unsigned char* ptr;
  char*          header_ptr = NULL;
  unsigned int   slice_size;
  int            openmode;
  int            header_size=0,read_size;

  unsigned char  genesis_format;
  float          corner[4][3];

  setlocale ( LC_NUMERIC,"C" );
//  fprintf(stderr,"amimage::readdata_ext() \t 1\n");
  if ( GB_debug ) fprintf ( stderr,"amimage::readdata_ext( ) begin\n" );

  genesis_format = 1;
  zdim = last_slice-first_slice+1;

  allocate();

  ptr        = ( unsigned char* ) data;
  slice_size = xdim*ydim*vdim*repres_size[repres]*type_size[type];

  for ( z=0; z < zdim; z++ )
  {

    if ( file_format.compare ( "" ) ==0 )
    {
      // Look for the filename
      // Use file prefix, kept for compatibility ...
      fname = (boost::format("%s.%03d")%file_prefix
                                %(first_slice+z)).str();
      // check for existence of the file
      if( !bf::exists(bf::path(fname)) )  {
        fname = fname+".gz";
        if (!bf::exists(bf::path(fname))) {
          fname = (boost::format("%s.%d")%file_prefix
                                  %(first_slice+z)).str();
          if( !bf::exists(bf::path(fname)) )  {
            fname = fname+".gz";
            if (!bf::exists(bf::path(fname))) {
              cerr  << " File with prefix " << file_prefix
                    << " number " << first_slice+z
                    << " not found ..." << endl;
              return 0;
            }
          }
        }
      }
    }
    else
    {
      // use file format ...
      fname = (boost::format(file_format) %(first_slice+z)).str();
      // check existence of the file
      if( !bf::exists(bf::path(fname)) ) {
        // try compressed file
        fname = fname + ".gz";
        if( !bf::exists(bf::path(fname)) ) {
          cerr  << " File with prefix " << file_format
                << " number " << first_slice+z
                << " not found ..." << endl;
          return 0;
        }
      }
    }

    if (!open_file(fname.c_str())) {
      cerr << " File " << fname << " could not be openned" << endl;
    }
    if ( z==0 )
    {
      // figure out the header size
      file_str->seekg (0, ios::end);
      header_size = (int)(file_str->tellg())-slice_size;
      cout << " stream pos  = " << file_str->tellg() << endl;
      cout << " header size = " << header_size << endl;
      cout << " slice_size  = " << slice_size << endl;
    }

    // read the header
    if ( header_ptr==NULL )
    {
      NEW ( fname.c_str(), header_ptr, char, header_size );
    }

    file_str->seekg (0, ios::beg); // Go back to the beginning
    file_str->read( (char*)header_ptr,header_size );
    // Get Information from the header
    //if ( header_size<4 )
    genesis_format = false;
    //  skip genesis format for the moment
    //if ( genesis_format ) genesis_format = CheckGenesisHeader ( header_ptr,z,corner );

    // Go back to the beginning of the data
    file_str->seekg (-((int)slice_size), ios::end);
    file_str->read ( (char*) ptr,slice_size );
    cout << " size read " << file_str->gcount() << endl;

    if ( GB_debug ) fprintf ( stderr,"amimage::readdata_ext( ) open STD finished\n" );
    close_file();

    ptr += slice_size;
  }

  if ( header_ptr!=NULL )
  {
    DELETE(header_ptr);
    header_ptr = NULL;
  }

// If all the corners have been extracted in the Genesis format,
// fill the transformation matrix
/*
  if ( genesis_format )
  {
    // Make the hypothesis that the basis is orthogonal
    // Map  ftl-->ftr  and (0,.,.)->(xdim,.,.)
    TransfMatrix[0][0] = ( corner[1][0]-corner[0][0] ) /xdim;
    TransfMatrix[1][0] = ( corner[1][1]-corner[0][1] ) /xdim;
    TransfMatrix[2][0] = ( corner[1][2]-corner[0][2] ) /xdim;
    // Map  ftr-->fbr  and (.,0,.)->(.,ydim,.)
    TransfMatrix[0][1] = ( corner[2][0]-corner[1][0] ) /ydim;
    TransfMatrix[1][1] = ( corner[2][1]-corner[1][1] ) /ydim;
    TransfMatrix[2][1] = ( corner[2][2]-corner[1][2] ) /ydim;
    // Map  ftl-->ltl  and (.,.,0.5)->(.,0,zdim-0.5)
    TransfMatrix[0][2] = ( corner[3][0]-corner[0][0] ) / ( zdim-1 );
    TransfMatrix[1][2] = ( corner[3][1]-corner[0][1] ) / ( zdim-1 );
    TransfMatrix[2][2] = ( corner[3][2]-corner[0][2] ) / ( zdim-1 );

    // translation because of Z mapping
    TransfMatrix[0][3] = corner[0][0]- ( corner[3][0]-corner[0][0] ) / ( zdim-1 ) *0.5;
    TransfMatrix[1][3] = corner[0][1]- ( corner[3][1]-corner[0][1] ) / ( zdim-1 ) *0.5;
    TransfMatrix[2][3] = corner[0][2]- ( corner[3][2]-corner[0][2] ) / ( zdim-1 ) *0.5;
  }
*/
  if ( ARCHITECTURE_ENDIANNESS != endianness )
  {
    swap_bytes();
  }

  return true;

} // readdata_ext


//----------------------------------------------------------------------
unsigned char  amimage::readdata3D_ext( )
//                      ------------

{

  int            z; //,error;
  string         fname;
  unsigned char* ptr;
  char*          header_ptr = NULL;
  unsigned int   image_size;
  int            header_size=0,read_size;


  //  fprintf(stderr,"amimage::readdata_ext() \t 1\n");

  setlocale(LC_NUMERIC,"C");
  //  fprintf(stderr,"amimage::readdata_ext() \t 1\n");
  if (GB_debug) fprintf(stderr,"amimage::readdata_ext3D( ) begin\n");

  allocate();

  ptr        = (unsigned char*)data;
  image_size = xdim*ydim*zdim*vdim*repres_size[repres]*type_size[type];


  if (file_format.compare("")==0)
  {
    // Look for the filename
    // Use file prefix, kept for compatibility ...
    fname = (boost::format("%s")%file_prefix).str();
    // check for existence of the file
    if( !bf::exists(bf::path(fname)) )  {
      fname = fname+".gz";
      if (!bf::exists(bf::path(fname))) {
            cerr  << " File " << file_prefix
                  << " not found ..." << endl;
            return 0;
      }
    }
  }
  else
  {
    // Use file prefix, kept for compatibility ...
    fname = (boost::format("%s")%file_format).str();
    // check for existence of the file
    if( !bf::exists(bf::path(fname)) )  {
      fname = fname+".gz";
      if (!bf::exists(bf::path(fname))) {
            cerr  << " File " << file_format
                  << " not found ..." << endl;
            return 0;
      }
    }
  }


  if (!open_file(fname.c_str())) {
    cerr << " File " << fname << " could not be openned" << endl;
  }

  // figure out the header size
  file_str->seekg (0, ios::end);
  header_size = (int)(file_str->tellg())-(long)image_size;

  // don´ t read the header
  //if (header_ptr==NULL)
  //{
  //  NEW(fname, header_ptr, char, header_size);
  //}

  // don´t read the header
  //file_str->seekg (0, ios::beg); // Go back to the beginning
  //file_str->read( (char*)header_ptr,header_size );

  // Go back to the beginning of the data and read them
  file_str->seekg (-((long)image_size), ios::end);
  file_str->read ( (char*) ptr,image_size );

  if  (file_str->gcount() != image_size) {
    string error_msg;
    error_msg = (boost::format(
            "amimage::readdata3D_ext() Error reading file %s \n")
            % fname).str();
    perror( error_msg.c_str() );
    close_file();
    return 0;
  }
  close_file();


  if (ARCHITECTURE_ENDIANNESS != endianness)
    swap_bytes();

  if (GB_debug) fprintf(stderr,"amimage::readdata_ext3D( ) end\n");

  return true;

} // readdata3D_ext

//----------------------------------------------------------------------
unsigned char  amimage::readdata( )
//                      --------
{
  int  nread;
//  unsigned char  rsize; // size of the scalar representation
//  unsigned long  ssize; // number of scalars
//  unsigned char* ptr1;
//  unsigned char  b;

  //  fprintf(stderr,"amimage::readdata() \t 1\n");

  if (!header_read) {
    fprintf(stderr,"amimage::readdata() \t Error: header not read \n");
    return false;
  }

  allocate();

  cerr << "pos=" << file_str->tellg() << endl;
  streamoff offset = -streamoff(data_size);
  cerr << "off=" << offset << endl;
  file_str->seekg(offset, ios::end);
  cerr << "pos=" << file_str->tellg() << endl;
  file_str->read((char*) data, data_size);
  cerr << "pos=" << file_str->tellg() << endl;

  if(file_str->gcount() != (streamsize) data_size) {
    cerr << "amimage::readdata()\t Error reading data \n";
    cerr << "\t "<< file_str->gcount() << " characters have been read";
    cerr << "\t "<< data_size << " was expected.";
    return false;
  }

  if (ARCHITECTURE_ENDIANNESS != endianness)
    swap_bytes();

  return true;

} // readdata()


//----------------------------------------------------------------------
void  amimage::swap_bytes( )
//             ----------
{
  register unsigned char  rsize;  // size of the scalar representation
  register unsigned char  rsize2; // size of the scalar representation / 2
  register unsigned long  ssize;  // number of scalars
  register unsigned char* ptr;
  register unsigned char  tmp;
  register unsigned char  b;

  cout << "swapping bytes " << endl;

  if (!this->data_allocated) {
    fprintf(stderr,"amimage::swap_bytes() \t Error: data not allocated \n");
    return;
  }

  rsize = repres_size[repres];
  rsize2 = rsize/2;
  ssize = xdim*ydim*zdim*type_size[type];

  ptr = (unsigned char *) data;


  while(ssize--) {
    for(b=0;b<rsize2;b++) {
      tmp = ptr[b];
      ptr[b] = ptr[rsize-1-b];
      ptr[rsize-1-b] = tmp;
    }
    ptr += rsize;
  }


} // swap_bytes()



//----------------------------------------------------------------------
unsigned char  amimage::read( const char* filename)
//                      ----
{

  if (!readheader(filename)) return false;
  //  fprintf(stderr,"amimage::read() \t 1\n");


  switch (datafile) {
  case AMI_DATAINT:
      if (!readdata()) return false;
    break;
  case AMI_DATAEXT:
      if (!readdata_ext()) return false;
    break;
  }

  close_file();

  return true;

}


//----------------------------------------------------------------------
unsigned char  amimage::writeheader( const char* filename,
//                      -----------
          filtering_ostream& out, bool include_header)
{
  setlocale(LC_NUMERIC,"C");

  // Openning the file
  int i = strlen(filename);
  if(!strncmp(filename+i-3, ".gz", 3)) {
    out.push(gzip_compressor());
  }
  out.push(file_sink(filename));
  // write to out using std::ostream interface

  if (include_header) {
    // Writting the header
    out << "AMIMAGE 1.1\n";
    out << "(\n";

    out << format("XDim = %d\n")% xdim  ;
    out << format("YDim = %d\n")% ydim  ;
    out << format("ZDim = %d\n")% zdim  ;
    out << format("VDim = %d\n")% vdim  ;

    out << format("VoxSizeX = %f\n") % voxsize_x  ;
    out << format("VoxSizeY = %f\n") % voxsize_y  ;
    out << format("VoxSizeZ = %f\n") % voxsize_z  ;

    out << format("TranslX = %f\n")% transl_x  ;
    out << format("TranslY = %f\n")% transl_y  ;
    out << format("TranslZ = %f\n")% transl_z  ;

    out << format("Repres = %s\n")%  repres_string[repres];
    out << format("Type = %s\n")  %   type_string[type];


    out << format("Endianness = %s\n")% end_string[endianness].c_str();
    out << format("ScanOrder  = %s\n")% so_string[scanorder].c_str();
    out << ")\n";
  }

  return !out.bad();

} // writeheader()

//----------------------------------------------------------------------
unsigned char  amimage::writedata(filtering_ostream& out)
//                      ---------
{
  int res,written;

  ComputeDataSize();

  if (ARCHITECTURE_ENDIANNESS != endianness)
    swap_bytes();

  out.write((char*)data, data_size);

  if (out.bad()) {
    cerr << "amimage::writedata() \t error writting data !";
    //  << format("%d bytes written out of %d \n") % written %data_size);
  }

  if (ARCHITECTURE_ENDIANNESS != endianness)
    swap_bytes();

  return !out.bad();

} // writedata()


//----------------------------------------------------------------------
unsigned char  amimage::write( const char* filename, bool include_header)
//                      -----
{
  filtering_ostream out;

  if (!writeheader(filename,out,include_header))
  {
    return false;
  }
  if (!writedata(out))
  {
    return false;
  }

  return true;

} // write()


//----------------------------------------------------------------------
void  amimage::CopyDataField( int n, void* d)
//             -------------
{

  unsigned long size,i;
  int tsize = type_size[type]*this->vdim;

  if (n>vdim-1) {
    fprintf(stderr,"amimage::CopyDataField(), field number too high \n");
    return;
  }

  size = xdim*ydim*zdim;

  switch (repres) {
  case AMI_FLOAT:
    {
    float* imdata  = (float*) data;
    float* newdata = (float*) d;

    for(i=0;i<size;i++) {
      imdata[n] = *newdata;
      imdata  += tsize;
      newdata ++;
    }
    }
    break;

  case AMI_UNSIGNED_CHAR:
    {
    unsigned char* imdata  = (unsigned char*) data;
    unsigned char* newdata = (unsigned char*) d;

    for(i=0;i<size;i++) {
      imdata[n] = *newdata;
      imdata  += tsize;
      newdata ++;
    }
    }
    break;

  default:
    fprintf(stderr,"amimage::CopyDataField \t Error, repres still not available \n");
  }


} // CopyDataField()



