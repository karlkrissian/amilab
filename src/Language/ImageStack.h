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

//----------------------------------------------------------------------
// Image Stack: Allows operations on images
//
class ImageStack{
//    ----------
  std::stack<InrImage*> _images;

 public:

  ImageStack() {}

  ~ImageStack()    { }

  void AddImage( char* name)
  {
    InrImage* im_tmp;
    try {
      im_tmp=new InrImage(name);
    }
    catch (InrImage::ErreurLecture)
      {
        fprintf(stderr,"Unable to read image %s\n",name);
        _images.push(NULL);
        return;
      }
    _images.push(im_tmp);
  }

  void AddImage( InrImage* im)
  {
    _images.push(im);
  }

  InrImage* GetLastImage()
  {
    InrImage* tmp;
    tmp=_images.top();
    _images.pop();
    return tmp;
  }
}; // ImageStack

#endif // _ImageStack_h_
