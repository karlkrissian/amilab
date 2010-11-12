/**
 * C++ Interface: wrap_wxWCharBuffer
 *
 * Description: wrapping wxWCharBuffer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxWCharBuffer_h_
#define _wrap_wxWCharBuffer_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxWCharBuffer);

// TODO: check for inheritence ...
class WrapClass_wxWCharBuffer : public WrapClass<wxWCharBuffer>
    
{
  DEFINE_CLASS(WrapClass_wxWCharBuffer);

  protected:
    typedef WrapClass<wxWCharBuffer>::ptr _parentclass_ptr;
    typedef wxWCharBuffer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxWCharBuffer>& GetObj() const { return WrapClass<wxWCharBuffer>::GetObj(); }

    /// Constructor
    WrapClass_wxWCharBuffer(boost::shared_ptr<wxWCharBuffer > si): 
    WrapClass<wxWCharBuffer>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxWCharBuffer()
    {
      std::cout << "~WrapClass_wxWCharBuffer()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWCharBuffer1,"Wrapping of wxWCharBuffer, http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#wxwcharbuffer.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWCharBuffer,"Wrapping of wxWCharBuffer, http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#wxwcharbuffer.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWCharBuffer2,"Wrapping of wxWCharBuffer, http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#wxwcharbuffer.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWCharBuffer3,"Wrapping of wxWCharBuffer, http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#wxwcharbuffer.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxWCharBuffer*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(copy,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(release,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#release")
    ADD_CLASS_METHOD(reset,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#reset")
    ADD_CLASS_METHOD(extend,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#extend")
    ADD_CLASS_METHOD(data1,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#data")
    ADD_CLASS_METHOD(data,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#data")
    ADD_CLASS_METHOD(data2,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#data")

    // Operators:
    ADD_CLASS_METHOD(assign1,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#assign")
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#assign")
    ADD_CLASS_METHOD(assign2,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#assign")
    ADD_CLASS_METHOD(at,"http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#at")




    void AddMethods(WrapClass<wxWCharBuffer>::ptr this_ptr )
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


#endif // _wrap_wxWCharBuffer_h
