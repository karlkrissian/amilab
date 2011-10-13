
#pragma once
#ifndef _HessianMatrix_h_
#define _HessianMatrix_h_

// TODO: dll_export ...

//
// Get first and second order derivatives:
// H1: 1st eigenvector or eigenvalue of the Hessian matrix
// H2: 2nd eigenvector or eigenvalue of the Hessian matrix
// H3: 3rd eigenvector or eigenvalue of the Hessian matrix
// G : gradient vector
// values: 0 do not save
//         1 save the eigenvector (or vector)
//         2 save the eigenvalue
//         3 save both
//
unsigned char      Func_Derivatives(  InrImage* image_initiale,
                                      const char* varname,
                                      float Sigma,
                                      float Gamma,
                                      InrImage* mask,
                                      int _H1,
                                      int _H2,int _H3,int _G);


unsigned char      Func_HessianMatrix(  InrImage* image_initiale, 
                                        const char* varname,
                                        float Sigma,
                                        float Gamma,
                                        InrImage* mask);

#endif // _HessianMatrix_h_
