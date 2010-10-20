//
// C++ Interface: wrap_ReadRawImages
//
// Description: function to read raw images
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_ReadRawImages_h_
#define _wrap_ReadRawImages_h_

#include "wrapfunctions.hpp"
#include "wrapfunction_class.h"
#include "Variables.hpp"

ADD_CLASS_FUNCTION( ReadRawImages2D, 
    "Reads 2D raw data (or a sequence of 2D raw data) as an image. The program can read raw data compressed with gzip: if the file is not found, it looks for the same filename with a '.gz' extention. If it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program. \n\
\n\
       Example(s):\n\
          i = ReadRawImages(1024,1024,USHORT,0,\"AfGG.%d\",48,48)"
  );

ADD_CLASS_FUNCTION( ReadRawImage3D,
"         Read 3D raw data as an image.\n\
         The program can read raw data compressed with gzip:\n\
         if the file is not found, it looks for the same filename with a '.gz' extention. If\n\
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.\n\
\n\
       Example(s):\n\
          i = IO.ReadRawImage3D(256,256,256,USHORT,0,\"data.raw\")"  );


ADD_CLASS_FUNCTION( ReadRawVectImage3D,
"\n\
         Read 3D raw data as an image, allowing vectorial images.\n\
         The program can read raw data compressed with gzip:\n\
         if the file is not found, it looks for the same filename with a '.gz' extention. If\n\
         it can find it, it will open the file using the 'popen' (pipe open) command and the 'gunzip' program.\n\
\n\
       Example(s):\n\
          i = IO.ReadRawVectImage3D(256,256,256,FLOAT,3,0,\"3dvectorfielddata.raw\")\n\
"  );


#endif
// _wrap_ReadRawImages_h_
