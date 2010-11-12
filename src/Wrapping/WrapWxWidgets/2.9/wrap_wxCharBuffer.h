/**
 * C++ Interface: wrap_wxCharBuffer
 *
 * Description: wrapping wxCharBuffer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxCharBuffer_h_
#define _wrap_wxCharBuffer_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxCharBuffer);

// TODO: check for inheritence ...
class WrapClass_wxCharBuffer : public WrapClass<wxCharBuffer>
    
{
  DEFINE_CLASS(WrapClass_wxCharBuffer);

  protected:
    typedef WrapClass<wxCharBuffer>::ptr _parentclass_ptr;
    typedef wxCharBuffer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxCharBuffer>& GetObj() const { return WrapClass<wxCharBuffer>::GetObj(); }

    /// Constructor
    WrapClass_wxCharBuffer(boost::shared_ptr<wxCharBuffer > si): 
    WrapClass<wxCharBuffer>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxCharBuffer()
    {
      std::cout << "~WrapClass_wxCharBuffer()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCharBuffer1,"Wrapping of wxCharBuffer, http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#wxcharbuffer.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCharBuffer,"Wrapping of wxCharBuffer, http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#wxcharbuffer.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCharBuffer2,"Wrapping of wxCharBuffer, http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#wxcharbuffer.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCharBuffer3,"Wrapping of wxCharBuffer, http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#wxcharbuffer.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxCharBuffer*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(copy,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(release,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#release")
    ADD_CLASS_METHOD(reset,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#reset")
    ADD_CLASS_METHOD(extend,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#extend")
    ADD_CLASS_METHOD(data1,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#data")
    ADD_CLASS_METHOD(data,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#data")
    ADD_CLASS_METHOD(data2,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#data")

    // Operators:
    ADD_CLASS_METHOD(assign1,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#assign")
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#assign")
    ADD_CLASS_METHOD(assign2,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#assign")
    ADD_CLASS_METHOD(at,"http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#at")




    void AddMethods(WrapClass<wxCharBuffer>::ptr this_ptr )
    {
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar_copy( this_ptr);
      // Adding standard methods 
      AddVar_release( this_ptr);
      AddVar_reset( this_ptr);
      AddVar_extend( this_ptr);
      AddVar_data1( this_ptr);
      AddVar_data( this_ptr);
      AddVar_data2( this_ptr);

      // Adding operators
      AddVar_assign1( this_ptr);
      AddVar_assign( this_ptr);
      AddVar_assign2( this_ptr);
      AddVar_at( this_ptr);



      
    };
};


#endif // _wrap_wxCharBuffer_h
