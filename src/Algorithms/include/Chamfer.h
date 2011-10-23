
#include "inrimage.hpp"

/**
 * @brief Computes a Chamfer distance transform in a 3D image.
 *
 * @param im input image
 * @param a coefficient for X coordinates
 * @param b coefficient for Y coordinates
 * @param c coefficient for Z coordinates
 * @return Resulting image.
 **/
InrImage*    Func_Chamfer(InrImage* im, float a, float b, float c);

InrImage*    Func_Chamfer2(InrImage* im, float a, float b, float c, float dmax=10000);

InrImage*    Func_Chamfer2Signed(InrImage* im, float a, float b, float c, float dmax=10000);

InrImage*    Func_Chamfer2_2D(InrImage* im, float a, float b, float dmax=10000);

InrImage*    Func_Chamfer2Signed_2D(InrImage* im, float a, float b, float dmax=10000);
