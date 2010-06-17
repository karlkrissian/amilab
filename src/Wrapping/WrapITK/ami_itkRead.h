//
// C++ Interface: ami_itkRead
//
// Description: reads itk image as InrImage
//
// Authors: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _ami_itkRead_h_
#define _ami_itkRead_h_

#include "inrimage.hpp"

InrImage* itkRead(const std::string& fname);

#endif 
// _ami_itkRead_h_
