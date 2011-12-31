//
// C++ Interface: CallbackBase
//
// Description: 
//
//
// Author:  <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _CallBackBase_h_
#define _CallBackBase_h_

//#include "DefineClass.hpp"

#include <boost/shared_ptr.hpp>

/**
  Base Class for dealing with callbacks in a clean way
**/
class CallBackBase
{
  public:
    virtual char const* get_name() const { return "CallBackBase"; } 
    typedef boost::shared_ptr<CallBackBase>    ptr;              
    typedef boost::weak_ptr<CallBackBase>      wptr;             

  public:
    /**
     * Call the callback function
     * @return True is success, false otherwise
     */
    virtual bool operator()() = 0;
};


#endif //  _CallBackBase_h_
