


#include "amiImageExtent.h"

#include <vector>

#ifdef __GCCXML__
  template class ami::ImageExtent<float>;
  template class std::vector<double>;
  
  typedef std::vector<double> vector_double;
#endif // __GCCXML__

// // trying iostream maybe should be moved from Algorithms to here ...
// #include <iostream>
// #include <sstream>
// #include <string>

