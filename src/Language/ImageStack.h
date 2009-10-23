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

  std::stack<InrImage*> _images;

 public:

  ImageStack() {}

  ~ImageStack()    { }

  void AddImage( char* name);

  void AddImage( InrImage* im)
  {
    _images.push(im);
  }

  InrImage* GetLastImage()
  {
    if (_images.empty()) return NULL;
    InrImage* tmp;
    tmp=_images.top();
    _images.pop();
    return tmp;
  }
}; // ImageStack

#endif // _ImageStack_h_
