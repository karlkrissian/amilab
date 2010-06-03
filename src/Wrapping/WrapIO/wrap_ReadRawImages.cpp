//
// C++ Implementation: wrap_ReadRawImages
//
// Description: function to read raw images
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_ReadRawImages.h"

#include <string>
using namespace std;

#include "wrapfunction_class.h"
#include "amimage.hpp"
#include "inrimage.hpp"

//---------------------------------------------------
//  ReadRawImages2D 
//---------------------------------------------------
void  wrap_ReadRawImages2D::SetParametersComments() 
{
   ADDPARAMCOMMENT("dimension in X");
   ADDPARAMCOMMENT("dimension in Y");
   ADDPARAMCOMMENT("image type, one of: CHAR, UCHAR, SHORT,\n\
                                 USHORT, FLOAT, DOUBLE, RGB,\n\
                                  FLOAT_VECTOR.");
   ADDPARAMCOMMENT("endianess: 0 for little, 1 for big.");
   ADDPARAMCOMMENT("filename or file format");
   ADDPARAMCOMMENT("first slice number (def:0)");
   ADDPARAMCOMMENT("last slice number (def:0)");
}
//---------------------------------------------------
BasicVariable::ptr wrap_ReadRawImages2D::CallMember( ParamList* p)
{
  int dimx = 1;
  int dimy = 1 ;
  int image_format = 0;
  int endianness;
  std::string fileformat;
  int firstslice = 0;
  int lastslice = 0;
  int n = 0;

  if (!get_int_param( dimx,         p, n)) ClassHelpAndReturn;
  if (!get_int_param( dimy,         p, n)) ClassHelpAndReturn;
  if (!get_int_param( image_format, p, n)) ClassHelpAndReturn;
  if (!get_int_param( endianness,   p, n)) ClassHelpAndReturn;
  if (!get_val_param<string>( fileformat, p, n)) 
      ClassHelpAndReturn;
  get_int_param( firstslice, p, n,false);
  get_int_param( lastslice, p, n,false);

  InrImage::ptr im (new InrImage());
  boost::shared_ptr<amimage> amim(new amimage());

  amim->SetDim(dimx,dimy,1);
  if (endianness)
    amim->endianness = BIG_END;
  else
    amim->endianness = LITTLE_END;

  im->AMIFromWT(1, (WORDTYPE) image_format, amim);
  amim->datafile    = AMI_DATAEXT;
  amim->file_format = fileformat;
  amim->first_slice = firstslice;
  amim->last_slice  = lastslice;

  if (amim->readdata_ext()) {
    im->SetAMImage(amim);
    Variable<InrImage>::ptr varres( new Variable<InrImage>(im));
    return varres; 
  } else {
    // Error message
    CLASS_ERROR("ReadRawImages() failed ... \n");
    return BasicVariable::ptr();
  }

}


