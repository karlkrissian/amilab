//
// C++ Implementation: EigenDecomp_NRAD
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "amiEigenDecomp_NRAD.h"
#include "amiImageExtent.h"
#include "amilab_messages.h"
#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>
#include "Eigen.hpp"
#include "FloatMatrix.hpp"
#include <boost/scoped_array.hpp>

namespace ami {

//------------------------------------------------------------------------------
void EigenDecomp_NRAD::InitIncrements()
{
  InrImage::ptr   in = params.GetInput();
  in->GetBufferIncrements(inc_x,inc_y,inc_z);
}

  
//------------------------------------------------------------------------------
void EigenDecomp_NRAD::FillMatrix(FloatMatrix & matrix, float* in_ptr, int vdim)
{
  // fill the matrix
  int i,j;
  int n=0;
  for(i=0;i<3;i++)
  for(j=0;j<3;j++) 
  {
    if (vdim==6) {
      if (i<=j) {
        matrix[i][j] = in_ptr[n];
        if (half_displ==HALF_DISPL_X)
          matrix[i][j] += in_ptr[inc_x+n]; 
        else
        if (half_displ==HALF_DISPL_Y)
          matrix[i][j] += in_ptr[inc_y+n];
        else
        if (half_displ==HALF_DISPL_Z)
          matrix[i][j] += in_ptr[inc_z+n];
        n++;
      } else {
        matrix[i][j] = matrix[j][i];
      }
    }
    if (vdim==9) {
      matrix[i][j] = in_ptr[n];
      if (half_displ==HALF_DISPL_X)
        matrix[i][j] = in_ptr[inc_x+n]; 
      else
      if (half_displ==HALF_DISPL_Y)
        matrix[i][j] = in_ptr[inc_y+n];
      else
      if (half_displ==HALF_DISPL_Z)
        matrix[i][j] = in_ptr[inc_z+n];
      n++;
    }
  }
}


//------------------------------------------------------------------------------
void EigenDecomp_NRAD::Run() 
{
  // need to initialize the increments !!!
  InitIncrements();
  EigenDecomp::Run();
}


} // end namespace ami
