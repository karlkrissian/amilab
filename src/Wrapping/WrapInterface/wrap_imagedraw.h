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

#include "paramlist.h"


/** function that add wrapping of the Image Drawing window
 */
void AddWrapImageDraw();

void wrap_ImageDrawSetLineColor( ParamList* p);
void wrap_ImageDrawDrawLine(     ParamList* p);
void wrap_ImageDrawLineParam(    ParamList* p);
void wrap_ImageDrawDisplayDA(    ParamList* p);

#endif //  _wrap_mainframe_h_
