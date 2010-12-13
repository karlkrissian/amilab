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

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxWCharBuffer_declared
  #define wxWCharBuffer_declared
  AMI_DECLARE_TYPE(wxWCharBuffer);
#endif

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
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWCharBuffer_1,"Constructor wxWCharBuffer::wxWCharBuffer(wchar_t const * str = 0l) (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#wxwcharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWCharBuffer,"Constructor wxWCharBuffer::wxWCharBuffer() (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#wxwcharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWCharBuffer_2,"Constructor wxWCharBuffer::wxWCharBuffer(size_t len) (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#wxwcharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWCharBuffer_3,"Constructor wxWCharBuffer::wxWCharBuffer(wxWCharBuffer const & src) (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#wxwcharbuffer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxWCharBuffer*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(release,"wchar_t * wxWCharBuffer::release()  (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#release)")
    ADD_CLASS_METHOD(reset,"void wxWCharBuffer::reset()  (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#reset)")
    ADD_CLASS_METHOD(extend,"bool wxWCharBuffer::extend(size_t len)  (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#extend)")
    ADD_CLASS_METHOD(data_1,"wchar_t * wxWCharBuffer::data()  (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#data)")
    ADD_CLASS_METHOD(data,"wxWCharBuffer::data()  (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#data)")
    ADD_CLASS_METHOD(data_2,"wchar_t const * wxWCharBuffer::data()  (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#data)")

    // Operators:
    ADD_CLASS_METHOD(__assign___1,            "wxWCharBuffer & wxWCharBuffer::operator =(wchar_t const * str) (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#__assign__)")
    ADD_CLASS_METHOD(__assign__,            "wxWCharBuffer::operator =() (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#__assign__)")
    ADD_CLASS_METHOD(__assign___2,            "wxWCharBuffer & wxWCharBuffer::operator =(wxWCharBuffer const & src) (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "wchar_t wxWCharBuffer::operator [](size_t n) (http://docs.wxwidgets.org/stable/wx_wxwcharbuffer.html#__at__)")




    void AddMethods(WrapClass<wxWCharBuffer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxWCharBuffer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxWCharBuffer_h
