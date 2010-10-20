
#include "inrimage.hpp"

InrImage*    Func_Chamfer(InrImage* im, float a, float b, float c);

InrImage*    Func_Chamfer2(InrImage* im, float a, float b, float c, float dmax=10000);

InrImage*    Func_Chamfer2Signed(InrImage* im, float a, float b, float c, float dmax=10000);

InrImage*    Func_Chamfer2_2D(InrImage* im, float a, float b, float dmax=10000);

InrImage*    Func_Chamfer2Signed_2D(InrImage* im, float a, float b, float dmax=10000);
