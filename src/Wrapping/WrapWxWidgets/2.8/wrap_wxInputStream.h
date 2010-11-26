/**
 * C++ Interface: wrap_wxInputStream
 *
 * Description: wrapping wxInputStream
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxInputStream_h_
#define _wrap_wxInputStream_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxStreamBase.h"



AMI_DECLARE_TYPE(wxInputStream);

// TODO: check for inheritence ...
class WrapClass_wxInputStream : public WrapClass<wxInputStream>
    , public   WrapClass_wxStreamBase
{
  DEFINE_CLASS(WrapClass_wxInputStream);

  protected:
    typedef WrapClass<wxInputStream>::ptr _parentclass_ptr;
    typedef wxInputStream ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxInputStream>& GetObj() const { return WrapClass<wxInputStream>::GetObj(); }

    /// Constructor
    WrapClass_wxInputStream(boost::shared_ptr<wxInputStream > si): 
    WrapClass<wxInputStream>(si)
    , WrapClass_wxStreamBase(si)
    {}

    /// Destructor
    ~WrapClass_wxInputStream()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxInputStream*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Peek,"char wxInputStream::Peek()  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#peek)")
    ADD_CLASS_METHOD(GetC,"int wxInputStream::GetC()  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#getc)")
/* The following types are missing: void
    ADD_CLASS_METHOD(Read_1,"wxInputStream & wxInputStream::Read(void * buffer, size_t size)  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#read)")
*/
    ADD_CLASS_METHOD(Read,"wxInputStream::Read()  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#read)")
    ADD_CLASS_METHOD(Read_2,"wxInputStream & wxInputStream::Read(wxOutputStream & streamOut)  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#read)")
    ADD_CLASS_METHOD(LastRead,"size_t wxInputStream::LastRead()  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#lastread)")
    ADD_CLASS_METHOD(CanRead,"bool wxInputStream::CanRead()  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#canread)")
    ADD_CLASS_METHOD(Eof,"bool wxInputStream::Eof()  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#eof)")
/* The following types are missing: void
    ADD_CLASS_METHOD(Ungetch_1,"size_t wxInputStream::Ungetch(void const * buffer, size_t size)  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#ungetch)")
*/
    ADD_CLASS_METHOD(Ungetch,"wxInputStream::Ungetch()  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#ungetch)")
    ADD_CLASS_METHOD(Ungetch_2,"bool wxInputStream::Ungetch(char c)  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#ungetch)")
/* The following types are missing: wxSeekMode
    ADD_CLASS_METHOD(SeekI,"wxFileOffset wxInputStream::SeekI(wxFileOffset pos, wxSeekMode mode = wxFromStart)  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#seeki)")
*/
    ADD_CLASS_METHOD(TellI,"wxFileOffset wxInputStream::TellI()  (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#telli)")

    // Operators:
    // ADD_CLASS_METHOD(operator not available,"wxInputStream & wxInputStream::>>(wxOutputStream & out) (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#>>)")
    // ADD_CLASS_METHOD(operator not available,"wxInputStream::>>() (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#>>)")
/* The following types are missing: _12813
    // ADD_CLASS_METHOD(operator not available,"wxInputStream & wxInputStream::>>(__wxInputManip func) (http://docs.wxwidgets.org/stable/wx_wxinputstream.html#>>)")
*/




    void AddMethods(WrapClass<wxInputStream>::ptr this_ptr );

};


#endif // _wrap_wxInputStream_h
