

#ifndef  __INTERPOLATE_TRANSFORM_H_
#define __INTERPOLATE_TRANSFORM_H_

#include "GLparam.hpp"

void            Func_SaveTransform(GLTransfMatrix* glt1, char* name);
GLTransfMatrix* Func_ReadTransform(char* name);

GLTransfMatrix* Func_InterpolateTransform(GLTransfMatrix* glt1,GLTransfMatrix* glt2,float coeff);

#endif // __INTERPOLATE_TRANSFORM_H_
