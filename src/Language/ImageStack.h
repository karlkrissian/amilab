//
// C++ Interface: ImageStack
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ImageStack_h_
#define _ImageStack_h_

#include <stack>
#include "inrimage.hpp"
#include <wx/filename.h>
#include "ami_class.h"
#include "amilab_messages.h"


//----------------------------------------------------------------------
// Image Stack: Allows operations on images
//
class ImageStack{
//    ----------

  DEFINE_CLASS(ImageStack);

  std::stack<InrImage::ptr> _images;

 public:

  ImageStack() {}

  ~ImageStack()    { }

  void AddFileImage( const char* name);

  void AddImagePointer(  InrImage* im)
  {
    _images.push(InrImage::ptr(im));
  }

  void AddImage( const InrImage::ptr& im)
  {
    _images.push(im);
  }

  InrImage::ptr GetLastImage()
  {
    if (_images.empty()) return InrImage::ptr();
    InrImage::ptr tmp;
    tmp=_images.top();
    _images.pop();
    return tmp;
  }
}; // ImageStack

#endif // _ImageStack_h_
