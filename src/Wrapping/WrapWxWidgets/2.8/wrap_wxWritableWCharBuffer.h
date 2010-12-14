/**
 * C++ Interface: wrap_wxWritableWCharBuffer
 *
 * Description: wrapping wxWritableWCharBuffer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxWritableWCharBuffer_h_
#define _wrap_wxWritableWCharBuffer_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWCharBuffer.h"


#ifndef wxWritableWCharBuffer_declared
  #define wxWritableWCharBuffer_declared
  AMI_DECLARE_TYPE(wxWritableWCharBuffer);
#endif

// TODO: check for inheritence ...
class WrapClass_wxWritableWCharBuffer : public WrapClass<wxWritableWCharBuffer>
    , public   WrapClass_wxWCharBuffer
{
  DEFINE_CLASS(WrapClass_wxWritableWCharBuffer);

  protected:
    typedef WrapClass<wxWritableWCharBuffer>::ptr _parentclass_ptr;
    typedef wxWritableWCharBuffer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxWritableWCharBuffer>& GetObj() const { return WrapClass<wxWritableWCharBuffer>::GetObj(); }

    /// Constructor
    WrapClass_wxWritableWCharBuffer(boost::shared_ptr<wxWritableWCharBuffer > si): 
    WrapClass<wxWritableWCharBuffer>(si)
    , WrapClass_wxWCharBuffer(si)
    {}

    /// Destructor
    ~WrapClass_wxWritableWCharBuffer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWritableWCharBuffer_1,"Constructor wxWritableWCharBuffer::wxWritableWCharBuffer(wxWritableWCharBuffer const & param0) (http://docs.wxwidgets.org/stable/wx_wxwritablewcharbuffer.html#wxwritablewcharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWritableWCharBuffer,"Constructor wxWritableWCharBuffer::wxWritableWCharBuffer() (http://docs.wxwidgets.org/stable/wx_wxwritablewcharbuffer.html#wxwritablewcharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWritableWCharBuffer_2,"Constructor wxWritableWCharBuffer::wxWritableWCharBuffer(wxWCharBuffer const & src) (http://docs.wxwidgets.org/stable/wx_wxwritablewcharbuffer.html#wxwritablewcharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWritableWCharBuffer_3,"Constructor wxWritableWCharBuffer::wxWritableWCharBuffer(wchar_t const * str = 0l) (http://docs.wxwidgets.org/stable/wx_wxwritablewcharbuffer.html#wxwritablewcharbuffer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxWritableWCharBuffer*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxWritableWCharBuffer & wxWritableWCharBuffer::operator =(wxWritableWCharBuffer const & param0) (http://docs.wxwidgets.org/stable/wx_wxwritablewcharbuffer.html#__assign__)")




    void AddMethods(WrapClass<wxWritableWCharBuffer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxWritableWCharBuffer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxWritableWCharBuffer_h
