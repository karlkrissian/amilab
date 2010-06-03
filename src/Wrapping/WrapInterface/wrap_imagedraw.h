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

ADD_METHOD(DessinImage,SetLineColor,  "Sets the color of the line.");
ADD_METHOD(DessinImage,DrawLine,      "Draws a line on XY plane.");
ADD_METHOD(DessinImage,LineParam,     "Sets the parameters of the line.");
ADD_METHOD(DessinImage,DisplayDA,     "Updates the display of the Drawing Area.");

#endif //  _wrap_imagedraw_h_
