/**
 * C++ Interface: wrap_wxWritableCharBuffer
 *
 * Description: wrapping wxWritableCharBuffer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxWritableCharBuffer_h_
#define _wrap_wxWritableCharBuffer_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxCharBuffer.h"


#ifndef wxWritableCharBuffer_declared
  #define wxWritableCharBuffer_declared
  AMI_DECLARE_TYPE(wxWritableCharBuffer);
#endif

// TODO: check for inheritence ...
class WrapClass_wxWritableCharBuffer : public WrapClass<wxWritableCharBuffer>
    , public   WrapClass_wxCharBuffer
{
  DEFINE_CLASS(WrapClass_wxWritableCharBuffer);

  protected:
    typedef WrapClass<wxWritableCharBuffer>::ptr _parentclass_ptr;
    typedef wxWritableCharBuffer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxWritableCharBuffer>& GetObj() const { return WrapClass<wxWritableCharBuffer>::GetObj(); }

    /// Constructor
    WrapClass_wxWritableCharBuffer(boost::shared_ptr<wxWritableCharBuffer > si): 
    WrapClass<wxWritableCharBuffer>(si)
    , WrapClass_wxCharBuffer(si)
    {}

    /// Destructor
    ~WrapClass_wxWritableCharBuffer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWritableCharBuffer_1,"Constructor wxWritableCharBuffer::wxWritableCharBuffer(wxWritableCharBuffer const & param0) (http://docs.wxwidgets.org/stable/wx_wxwritablecharbuffer.html#wxwritablecharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWritableCharBuffer,"Constructor wxWritableCharBuffer::wxWritableCharBuffer() (http://docs.wxwidgets.org/stable/wx_wxwritablecharbuffer.html#wxwritablecharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWritableCharBuffer_2,"Constructor wxWritableCharBuffer::wxWritableCharBuffer(wxCharBuffer const & src) (http://docs.wxwidgets.org/stable/wx_wxwritablecharbuffer.html#wxwritablecharbuffer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWritableCharBuffer_3,"Constructor wxWritableCharBuffer::wxWritableCharBuffer(char const * str = 0l) (http://docs.wxwidgets.org/stable/wx_wxwritablecharbuffer.html#wxwritablecharbuffer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxWritableCharBuffer*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxWritableCharBuffer & wxWritableCharBuffer::operator =(wxWritableCharBuffer const & param0) (http://docs.wxwidgets.org/stable/wx_wxwritablecharbuffer.html#__assign__)")




    void AddMethods(WrapClass<wxWritableCharBuffer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxWritableCharBuffer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxWritableCharBuffer_h
