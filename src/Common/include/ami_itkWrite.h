//
// C++ Interface: ami_itkWrite
//
// Description: write InrImage in itk format
//
// Authors: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ami_itkWrite_h_
#define _ami_itkWrite_h_

#include "inrimage.hpp"

#include "CommonConfigure.h"

COMMON_EXPORT 
bool itkWrite(InrImage* input, const std::string& fname);

/*
std::vector<std::string> itkWriteGetExtensions( InrImage* input);
*/

#endif 
// _ami_itkWrite_h_
