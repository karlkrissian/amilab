


#include "amiImageExtent.h"

#include <vector>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>

#ifdef __GCCXML__
  template class ami::ImageExtent<float>;
  template class std::vector<double>;
  template class std::vector<float>;
  template class std::vector<int>;
  
  typedef std::vector<double> vector_double;
  typedef std::vector<float>  vector_float;
  typedef std::vector<int>    vector_int;
  
  // instanciate iterators
  vector_double::iterator vdi;
  vector_float::iterator  vfi;
  vector_int::iterator    vii;
  
  //std::ostream std_ostream_obj;
  std::stringstream string_stream_obj;
//  std::iostream io_stream_obj;
#endif // __GCCXML__

// // trying iostream maybe should be moved from Algorithms to here ...
// #include <iostream>
// #include <sstream>
// #include <string>

