//
// C++ Implementation: ImageStack
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "ImageStack.h"

#include "driver.h"

extern yyip::Driver GB_driver;


void ImageStack::AddImage( char* name)
{
  // look for the image 
  wxFileName inputname(name);
  wxFileName newname(name);

  if (!inputname.IsFileReadable()) 
  // add the current script path
  {
    newname.Assign(
            wxFileName(GB_driver.GetCurrentFilename().c_str()).GetPath() +
            inputname.GetPathSeparator()+
            inputname.GetPath(),
            inputname.GetFullName());
  }

  if (newname.IsFileReadable()) {
    InrImage* im_tmp;
    try {
      im_tmp=new InrImage(newname.GetFullPath().mb_str());
    }
    catch (InrImage::ErreurLecture)
      {
        fprintf(stderr,"Unable to read image %s\n",name);
        _images.push(NULL);
        return;
      }
    _images.push(im_tmp);
  } else {
    CLASS_ERROR(boost::format("Invalid image filename '%s'") % name);
    _images.push(NULL);
  }
}
