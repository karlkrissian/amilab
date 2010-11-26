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
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCharBuffer_1,"Constructor wxCharBuffer::wxCharBuffer(char const * str = 0l) (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#wxcharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCharBuffer,"Constructor wxCharBuffer::wxCharBuffer() (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#wxcharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCharBuffer_2,"Constructor wxCharBuffer::wxCharBuffer(size_t len) (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#wxcharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCharBuffer_3,"Constructor wxCharBuffer::wxCharBuffer(wxCharBuffer const & src) (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#wxcharbuffer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxCharBuffer*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(release,"char * wxCharBuffer::release()  (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#release)")
    ADD_CLASS_METHOD(reset,"void wxCharBuffer::reset()  (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#reset)")
    ADD_CLASS_METHOD(extend,"bool wxCharBuffer::extend(size_t len)  (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#extend)")
    ADD_CLASS_METHOD(data_1,"char * wxCharBuffer::data()  (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#data)")
    ADD_CLASS_METHOD(data,"wxCharBuffer::data()  (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#data)")
    ADD_CLASS_METHOD(data_2,"char const * wxCharBuffer::data()  (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#data)")

    // Operators:
    ADD_CLASS_METHOD(__assign___1,            "wxCharBuffer & wxCharBuffer::operator =(char const * str) (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#__assign__)")
    ADD_CLASS_METHOD(__assign__,            "wxCharBuffer::operator =() (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#__assign__)")
    ADD_CLASS_METHOD(__assign___2,            "wxCharBuffer & wxCharBuffer::operator =(wxCharBuffer const & src) (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "char wxCharBuffer::operator [](size_t n) (http://docs.wxwidgets.org/stable/wx_wxcharbuffer.html#__at__)")




    void AddMethods(WrapClass<wxCharBuffer>::ptr this_ptr );

};


#endif // _wrap_wxCharBuffer_h
