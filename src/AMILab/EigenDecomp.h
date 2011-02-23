//
// C++ Interface: EigenDecomp
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _EigenDecomp_h_
#define _EigenDecomp_h_

#include "inrimage.hpp"
#include "DefineClass.hpp"

using namespace std;

#define GET_FIRST  1
#define GET_SECOND 2
#define GET_THIRD  4

#include <vector>

typedef std::vector<InrImage::ptr> InrImage_ptr_vector;

//--------------------------------------------------------------------
//  Return a vector of 6 pointers to images including
//  eigenvalues and eigenvectors or empty pointers depending on flags
// input should be a vectorial image of 3 (for symmetric matrices) 
// or 6 components
InrImage_ptr_vector EigenDecomp2D(InrImage* im, 
        int value_flag, 
        int vector_flag,
        InrImage* mask = NULL);

//--------------------------------------------------------------------
//  Return a vector of images including
//  eigenvalues and eigenvectors depending on flags
// input should be a vectorial image of 6 (for symmetric matrices) 
// or 9 components
InrImage_ptr_vector EigenDecomp3D(InrImage* im, 
        int value_flag, 
        int vector_flag,
        InrImage* mask = NULL);

//--------------------------------------------------------------------
//  Return a vector of images including
//  eigenvalues and eigenvectors depending on flags
//  use image dimensions to call the 2D or the 3D versions
InrImage_ptr_vector EigenDecomp(InrImage* im, 
        int value_flag, 
        int vector_flag,
        InrImage* mask = NULL);

#endif //  _EigenDecomp_h_
