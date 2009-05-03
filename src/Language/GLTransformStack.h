//
// C++ Interface: GLTransformStack
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _GLTransformStack_h_
#define _GLTransformStack_h_

#include <stack>
#include "GLparam.hpp"

//----------------------------------------------------------------------
// GLTransformStack Stack: Allows operations on matrices
//
class GLTransformStack{
//    ----------
  std::stack<GLTransfMatrix*> _matrices;

 public:

  GLTransformStack() {}

  ~GLTransformStack() {}

  void AddMatrix( GLTransfMatrix* m)
  {
    _matrices.push(m);
  }

  GLTransfMatrix* GetLastMatrix()
  {
    GLTransfMatrix* tmp;
    tmp=_matrices.top();
    _matrices.pop();
    return tmp;
  }
}; // GLTransformStack


#endif // _GLTransformStack_h_
