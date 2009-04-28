//
// C++ Interface: vtk_common
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _vtk_common_
#define _vtk_common_

#include <boost/shared_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_array.hpp>
#include "vtkImageData.h"


using namespace boost;

template<class T>
class vtk_deleter
{
  public: 
    void operator()(T * p) 
    { 
      p->Delete(); 
    }  
};


template<class T>
class vtk_new
{
  public: 
    shared_ptr<T> operator() ()
    { 
      shared_ptr<T> res =  shared_ptr<T>(
        (T*)T::New(),
        vtk_deleter<T>() ); 
      return res;
    }  

    shared_ptr<T> operator()(T* pointer) 
    { 
      shared_ptr<T> res(pointer,vtk_deleter<T>()); 
      return res;
    }  
};

typedef shared_ptr<vtkImageData>  vtkImageData_ptr;

#endif // _vtk_common_
