/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
//
//  Author: Karl Krissian
//
//

#ifndef _LINKCLASS_HPP
#define _LINKCLASS_HPP

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <list>
#include <vector>

#define DEFINE_CLASS(class) \
public:\
  virtual char const* get_name() const { return #class; } \
  typedef boost::shared_ptr<class>    ptr;              \
  typedef boost::weak_ptr<class>      wptr;             \
  typedef std::vector<class::ptr>     ptr_vector;       \
  typedef std::vector<class::wptr>    wptr_vector;      \
  typedef std::list<class::ptr>       ptr_list;         \
  typedef std::list<class::wptr>      wptr_list;


template<class T>
class wxwindow_deleter 
  { 
  public: 
    void operator()(T * p) 
    { 
      if (p!=NULL) p->Destroy();
    }  
  };

template<class T>
class wxwindow_nodeleter 
  { 
  public: 
    void operator()(T * p)  {  }  
  };

template<class T>
class smartpointer_nodeleter 
  { 
  public: 
    void operator()(T * p)  {  }  
  };

#define new_wxWindow_ptr(_class,_parent) \
  _class::ptr(new _class(_parent),wxwindow_nodeleter<_class>())

#define new_wxWindow_ptr_deleter(_class,_parent) \
  _class::ptr(new _class(_parent),wxwindow_deleter<_class>())

// no special type added
#define DEFINE_SIMPLE_CLASS(class) \
public:\
  virtual char const* get_name() const { return #class; } 

//--- string formatting using boost
#include <iostream>
#include <iomanip>
#include <cassert>
#include "boost/format.hpp"


typedef boost::shared_ptr<float>           float_ptr;
typedef boost::shared_ptr<int>             int_ptr;
typedef boost::shared_ptr<unsigned char>   uchar_ptr;
typedef boost::shared_ptr<std::string>     string_ptr;
typedef boost::shared_ptr<FILE>            FILE_ptr;


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


namespace MyNS_ForOutput {
  using std::cout; using std::cerr;
  using std::string;
  using std::endl; using std::flush;

  using boost::format;
  using boost::io::group;
}
using namespace MyNS_ForOutput;



#endif // _LINKCLASS_HPP
