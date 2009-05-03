//
// C++ Interface: MatrixStack
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _MatrixStack_h_
#define _MatrixStack_h_

#include <stack>
#include "FloatMatrix.hpp"

//----------------------------------------------------------------------
// Matrix Stack: Allows operations on matrices
//
class MatrixStack{
//    ----------
  std::stack<FloatMatrix*> _matrices;

 public:

  MatrixStack() {}

  ~MatrixStack() {}

  //  void AddMatrix( char* name);
  void AddMatrix( FloatMatrix* m)
  {
    _matrices.push(m);
  }

  FloatMatrix* GetLastMatrix()
  {
    FloatMatrix* tmp;
    tmp=_matrices.top();
    _matrices.pop();
    return tmp;
  }

}; // MatrixStack

#endif // _MatrixStack_h_
