//
// C++ Interface: LineCC
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

// Compute Connected Components from the lines

#ifndef _LineCC_h_
#define _LineCC_h_

#include "surface.hpp"
//using namespace amilab;

// Get the connected component from a line number
amilab::SurfacePoly* GetConnectedComponent( int line_id);

#endif // _LineCC_h_
