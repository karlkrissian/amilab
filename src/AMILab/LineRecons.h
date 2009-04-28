//
// C++ Interface: LineRecons
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _LineRecons_h_
#define _LineRecons_h_

#include "surface.hpp"
#include "inrimage.hpp"

InrImage* LineRecons( SurfacePoly* surf, InrImage* ref,
                      InrImage* radii);

#endif // _LineRecons_h_
