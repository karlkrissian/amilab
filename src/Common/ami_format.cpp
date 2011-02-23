
#include "ami_format.h"
#include <boost/format.hpp>

namespace ami {
  //----------------------------------
  format::format(const char* st)
  {
    _boost_format = (void*) new boost::format(st);
  }

  //----------------------------------
  format::~format()
  {
    delete static_cast<boost::format*>(_boost_format);
  }

  //----------------------------------
  format& format::operator%(const char* st)
  {
    boost::format* f = (boost::format*)(_boost_format);

    *f = *f % st;
    return *this;
  }

  //----------------------------------
  format& format::operator%(const int& val)
  {
    boost::format* f = static_cast<boost::format*>(_boost_format);
    (*f) = (*f) % val;
    return *this;
  }

  //----------------------------------
  format& format::operator%(const float& val)
  {
    boost::format* f = static_cast<boost::format*>(_boost_format);
    (*f) = (*f) % val;
    return *this;
  }

  //----------------------------------
  format& format::operator%(const double& val)
  {
    boost::format* f = static_cast<boost::format*>(_boost_format);
    (*f) = (*f) % val;
    return *this;
  }

  //----------------------------------
  const char* format::GetString() const
  {
    boost::format* f = static_cast<boost::format*>(_boost_format);
    return (*f).str().c_str();
  }
}
