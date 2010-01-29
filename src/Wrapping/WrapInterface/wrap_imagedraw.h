//
// C++ Interface: wrap_image_draw
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_imagedraw_h_
#define _wrap_imagedraw_h_

#include "wrapfunction_class.h"
#include "paramlist.h"
#include "DessinImage.hpp"

/** function that add wrapping of the Image Drawing window
 */
void wrap_ImageDraw( ParamList* p);

///
class wrap_ImageDrawSetLineColor : public WrapClassMember {
    DessinImage::ptr _imdraw;
  public:
    wrap_ImageDrawSetLineColor(const DessinImage::ptr& imdraw) : _imdraw(imdraw) {}
    void CallProc(ParamList*);
};

///
class wrap_ImageDrawDrawLine : public WrapClassMember {
    DessinImage::ptr _imdraw;
  public:
    wrap_ImageDrawDrawLine(const DessinImage::ptr& imdraw) : _imdraw(imdraw) {}
    void CallProc(ParamList*);
};

///
class wrap_ImageDrawLineParam : public WrapClassMember {
    DessinImage::ptr _imdraw;
  public:
    wrap_ImageDrawLineParam(const DessinImage::ptr& imdraw) : _imdraw(imdraw) {}
    void CallProc(ParamList*);
};

///
class wrap_ImageDrawDisplayDA : public WrapClassMember {
    DessinImage::ptr _imdraw;
  public:
    wrap_ImageDrawDisplayDA(const DessinImage::ptr& imdraw) : _imdraw(imdraw) {}
    void CallProc(ParamList*);
};


#endif //  _wrap_mainframe_h_
