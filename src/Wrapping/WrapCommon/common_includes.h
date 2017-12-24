
#ifdef __GCCXML__
//#define __nullptr NULL
//#define _NOEXCEPT
//#define constexpr const
#endif


#include "amiImageExtent.h"

#include <vector>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <complex>


#ifdef __GCCXML__
  template class ami::ImageExtent<float>;
 
  //----------------------------------------------------------------------------
  // std::vector of basic types
  template class std::vector<double>;
  template class std::vector<float>;
  template class std::vector<int>;
  template class std::vector<long>;
  template class std::vector<unsigned long>;
  template class std::vector<std::string>;

  // short names
  typedef std::vector<double>         vector_double;
  typedef std::vector<float>          vector_float;
  typedef std::vector<int>            vector_int;
  typedef std::vector<long>           vector_long;
  typedef std::vector<unsigned long>  vector_ulong;
  typedef std::vector<std::string>    vector_string;
  
  typedef vector_double::iterator vector_double_it;
  typedef vector_float::iterator  vector_float_it;
  typedef vector_int::iterator    vector_int_it;
  typedef vector_long::iterator   vector_long_it;
  typedef vector_ulong::iterator  vector_ulong_it;
  typedef vector_string::iterator vector_string_it;
    
  // instanciate iterators
  vector_double::iterator vdi;
  vector_float ::iterator vfi;
  vector_int   ::iterator vii;
  vector_long  ::iterator vli;
  vector_ulong ::iterator vuli;
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
  
  template class std::complex<float>;
#endif // __GCCXML__

// // trying iostream maybe should be moved from Algorithms to here ...
// #include <iostream>
// #include <sstream>
// #include <string>

