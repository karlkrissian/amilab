


#include "amiImageExtent.h"

#include <vector>

#ifdef __GCCXML__
  template class ami::ImageExtent<float>;
  template class std::vector<double>;
  template class std::vector<float>;
  template class std::vector<int>;
  
  typedef std::vector<double> vector_double;
  typedef std::vector<float>  vector_float;
  typedef std::vector<int>    vector_int;
#endif // __GCCXML__

// // trying iostream maybe should be moved from Algorithms to here ...
// #include <iostream>
// #include <sstream>
// #include <string>

