/**
  This class exists only because of the operation image[image_draw] that is implemented in the library LanguageBase and should not depend on wrap_Interface ...
  Shoulw be removed once InrImage moves to a wrapped object.
*/


#pragma once
#ifndef _ImageViewerBase_h_
#define _ImageViewerBase_h_

#include "DefineClass.hpp"

class ImageViewerBase
{
  DEFINE_CLASS(ImageViewerBase);

public:
  /// This only method we need here ...
  virtual void GetZoom( int& xmin, int& ymin, int& zmin,
                        int& xmax, int& ymax, int& zmax)
  {
      xmin=ymin=zmin=0;
      xmax=ymax=zmax=0;
  }

};

#endif // _ImageViewerBase_h_
