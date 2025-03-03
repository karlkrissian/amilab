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
#include "vtkSmartPointer.h"

#include "DefineClass.hpp"
#include "amilab_messages.h"


template<class T>
class vtk_deleter
{
  DEFINE_SIMPLE_CLASS(vtk_deleter)

  public: 
  virtual ~vtk_deleter() {}
    void operator()(T * p) 
    { 
      CLASS_MESSAGE(p->GetClassName())
      p->Delete(); 
    }  
};


template<class T>
class vtk_new
{
  DEFINE_SIMPLE_CLASS(vtk_new)

  public: 
  virtual ~vtk_new() {}
    boost::shared_ptr<T> operator() ()
    { 
      CLASS_MESSAGE("");
      boost::shared_ptr<T> res =  boost::shared_ptr<T>(
        (T*)T::New(),
        vtk_deleter<T>() ); 
      CLASS_MESSAGE(res->GetClassName());
      return res;
    }  

    boost::shared_ptr<T> operator()(T* pointer) 
    { 
      if (pointer==NULL) {
        CLASS_ERROR("Null pointer");
      }
      boost::shared_ptr<T> res(pointer,vtk_deleter<T>()); 
      return res;
    }  
};

typedef boost::shared_ptr<vtkImageData>  vtkImageData_ptr;

#endif // _vtk_common_
