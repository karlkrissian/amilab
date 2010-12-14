/**
 * C++ Interface: wrap_wxOutputStream
 *
 * Description: wrapping wxOutputStream
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxOutputStream_h_
#define _wrap_wxOutputStream_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxStreamBase.h"


#ifndef wxOutputStream_declared
  #define wxOutputStream_declared
  AMI_DECLARE_TYPE(wxOutputStream);
#endif

// TODO: check for inheritence ...
class WrapClass_wxOutputStream : public WrapClass<wxOutputStream>
    , public   WrapClass_wxStreamBase
{
  DEFINE_CLASS(WrapClass_wxOutputStream);

  protected:
    typedef WrapClass<wxOutputStream>::ptr _parentclass_ptr;
    typedef wxOutputStream ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxOutputStream>& GetObj() const { return WrapClass<wxOutputStream>::GetObj(); }

    /// Constructor
    WrapClass_wxOutputStream(boost::shared_ptr<wxOutputStream > si): 
    WrapClass<wxOutputStream>(si)
    , WrapClass_wxStreamBase(si)
    {}

    /// Destructor
    ~WrapClass_wxOutputStream()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxOutputStream,"Constructor wxOutputStream::wxOutputStream() (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#wxoutputstream).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxOutputStream*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(PutC,"void wxOutputStream::PutC(char c)  (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#putc)")
/* The following types are missing: void
    ADD_CLASS_METHOD(Write_1,"wxOutputStream & wxOutputStream::Write(void const * buffer, size_t size)  (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#write)")
*/
    ADD_CLASS_METHOD(Write,"wxOutputStream::Write()  (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#write)")
    ADD_CLASS_METHOD(Write_2,"wxOutputStream & wxOutputStream::Write(wxInputStream & stream_in)  (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#write)")
    ADD_CLASS_METHOD(SeekO,"wxFileOffset wxOutputStream::SeekO(wxFileOffset pos, wxSeekMode mode = wxFromStart)  (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#seeko)")
    ADD_CLASS_METHOD(TellO,"wxFileOffset wxOutputStream::TellO()  (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#tello)")
    ADD_CLASS_METHOD(LastWrite,"size_t wxOutputStream::LastWrite()  (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#lastwrite)")
    ADD_CLASS_METHOD(Sync,"void wxOutputStream::Sync()  (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#sync)")
    ADD_CLASS_METHOD(Close,"bool wxOutputStream::Close()  (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#close)")

    // Operators:
    // ADD_CLASS_METHOD(operator not available,"wxOutputStream & wxOutputStream::<<(wxInputStream & out) (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxOutputStream::<<() (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#<<)")
/* The following types are missing: _6623
    // ADD_CLASS_METHOD(operator not available,"wxOutputStream & wxOutputStream::<<(__wxOutputManip func) (http://docs.wxwidgets.org/stable/wx_wxoutputstream.html#<<)")
*/




    void AddMethods(WrapClass<wxOutputStream>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxOutputStream_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxOutputStream_h
