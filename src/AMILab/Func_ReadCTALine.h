//
// C++ Interface: Func_ReadCTALine
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Func_ReadCTALine_h
#define _Func_ReadCTALine_h

#include "surface.hpp"
using namespace amilab;

#include <string>

SurfacePoly* Func_ReadCTALine( std::string filename, int mode=0);

InrImage* Func_ReadCTALineRadii(  SurfacePoly* line,
                                  std::string filename);

void Func_WriteCTALine( SurfacePoly* surf, std::string filename);

#endif
