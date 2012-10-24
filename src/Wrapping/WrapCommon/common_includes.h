


#include "amiImageExtent.h"

#include <vector>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>

#ifdef __GCCXML__
  template class ami::ImageExtent<float>;
 
  //----------------------------------------------------------------------------
  // std::vector of basic types
  template class std::vector<double>;
  template class std::vector<float>;
  template class std::vector<int>;
  template class std::vector<std::string>;

  // short names
  typedef std::vector<double>       vector_double;
  typedef std::vector<float>        vector_float;
  typedef std::vector<int>          vector_int;
  typedef std::vector<std::string>  vector_string;
  
  // instanciate iterators
  vector_double::iterator vdi;
  vector_float ::iterator vfi;
  vector_int   ::iterator vii;
  vector_string::iterator vsi;

  //----------------------------------------------------------------------------
  // std::set of basic types
  template class std::set<std::string>;
  template class std::set<int>;

  // short names
  // todo: improve all this ...
  typedef std::set<std::string>                             set_string;
  typedef std::set<std::string>::iterator                   set_string_iterator;
  typedef std::pair<std::set<std::string>::iterator, bool>  set_string_pair_iterator_bool;

  typedef std::set<int>          set_int;
  
  // instanciate iterators
  set_string_iterator           ssi;
  set_string_pair_iterator_bool sspib;
  
  std::set<int>        ::iterator sii;
  
  //----------------------------------------------------------------------------
  //std::ostream std_ostream_obj;
  std::stringstream string_stream_obj;
//  std::iostream io_stream_obj;
#endif // __GCCXML__

// // trying iostream maybe should be moved from Algorithms to here ...
// #include <iostream>
// #include <sstream>
// #include <string>

