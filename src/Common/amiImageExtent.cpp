
#include "amiImageExtent.h"

namespace ami {
  
  template<> AMI_DLLEXPORT ImageExtent<int>::ImageExtent(InrImage* im)
  {
    //printf("ImageExtent<int>(InrImage* im)\n");
    extent[0][0] = 0;
    extent[1][0] = 0;
    extent[2][0] = 0;
    extent[0][1] = im->DimX()-1;
    extent[1][1] = im->DimY()-1;
    extent[2][1] = im->DimZ()-1;
    mode = Absolute;
  }
  
}
