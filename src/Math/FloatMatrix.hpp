/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#ifndef _FLOATMATRIX_HPP
#define _FLOATMATRIX_HPP

#include "style.hpp"
#include <stdio.h>
#include "boost/shared_ptr.hpp"

//class FloatMatrix;

#include "DefineClass.hpp"

//==================================================
class FloatMatrix 
//
{

  DEFINE_CLASS(FloatMatrix)

protected:

  float** m;
  int     n1,n2;

public:
  FloatMatrix(int dim1, int dim2)
  {
    int     i;

    n1 = dim1;
    n2 = dim2;

    m = new float*[n1];
    Pour(i,0,n1-1)
      m[i] = new float[n2];
    FinPour

  }

  FloatMatrix(const FloatMatrix& m0)
  {
    int     i,j;

    n1 = m0.n1;
    n2 = m0.n2;

    m = new float*[n1];
    Pour(i,0,n1-1)
      m[i] = new float[n2];
      Pour(j,0,n2-1)
        m[i][j]=m0.m[i][j];
      FinPour
    FinPour

  }

  virtual ~FloatMatrix()
  {
    int     i;
    
    Pour(i,0,n1-1)
      delete [] m[i];
    FinPour
    delete [] m;
    
  }

  int Rows()    { return n1; }
  int Cols()    { return n2; }

  operator float**()
  {
    return m;
  }

  float* operator [] (int i)
  {
    return m[i];
  }


  float& operator()(int i,int j) {
    if ((i>=0)&&(i<n1)&&(j>=0)&&(j<n2))
      return this->m[i][j];
    else
      fprintf(stderr,"FloatMatrix::operator(%d,%d) error\n",i,j);
  return m[0][0];
  }

  FloatMatrix* Transpose();

  FloatMatrix& operator =(const float n);

  FloatMatrix& operator =(FloatMatrix* m);

  void PrintSelf();

  friend FloatMatrix* Multiply(FloatMatrix*, FloatMatrix*);


}; // end class FloatMatrix


#endif // _FLOATMATRIX_HPP
