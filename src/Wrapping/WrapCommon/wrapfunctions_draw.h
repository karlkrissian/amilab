//
// C++ Interface: wrapfunctions_draw
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrapfunctions_draw_h_
#define _wrapfunctions_draw_h_

#include "DessinImage.hpp"
#include "paramlist.h"

/**
 * Function used to parse an imagedraw in a list of parameters
 */
bool get_imagedraw_param(DessinImage::ptr& arg, ParamList*p, int& num);

#endif //  _wrapfunctions_draw_h_
