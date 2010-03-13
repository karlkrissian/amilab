//
// C++ Interface: amilab_boost
//
// Description: utility for boost
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _amilab_boost_h_
#define _amilab_boost_h_

#include "paramlist.h"
#include <boost/shared_ptr.hpp>
#include <stdio.h>

/// Generic class with operator for creating smart pointers
template<class T>
class CreateSmartPointer
{
  public:
  boost::shared_ptr<T> operator() (T* p) 
  {
    return boost::shared_ptr<T>(p);
  }
};


/// FILE deleter
class file_deleter
{
  public:
    void operator()(FILE * p)
    {
      if (p!=NULL)
        if (p!=stdout)
          fclose(p);
    }
};

/// Specialization for FILE
template<>
class CreateSmartPointer<FILE>
{
  public:
  boost::shared_ptr<FILE> operator() (FILE* p) 
  {
    return boost::shared_ptr<FILE>(p,file_deleter());
  }
};

/// smart pointer without deleter
template<class T>
class smartpointer_nodeleter
  {
  public:
    void operator()(T * p)  {  }
  };

/// Specialization for C_wrap_varfunction
template<>
class CreateSmartPointer<C_wrap_varfunction>
{
  public:
  boost::shared_ptr<C_wrap_varfunction> operator() (C_wrap_varfunction* p) 
  {
    return boost::shared_ptr<C_wrap_varfunction>(p,smartpointer_nodeleter());
  }
};

/// Specialization for C_wrap_procedure
template<>
class CreateSmartPointer<C_wrap_procedure>
{
  public:
  boost::shared_ptr<C_wrap_procedure> operator() (C_wrap_procedure* p) 
  {
    return boost::shared_ptr<C_wrap_procedure>(p,smartpointer_nodeleter());
  }
};

/// Specialization for C_wrap_imagefunction
template<>
class CreateSmartPointer<C_wrap_imagefunction>
{
  public:
  boost::shared_ptr<C_wrap_imagefunction> operator() (C_wrap_imagefunction* p) 
  {
    return boost::shared_ptr<C_wrap_imagefunction>(p,smartpointer_nodeleter());
  }
};

#endif
// _amilab_boost_h_
