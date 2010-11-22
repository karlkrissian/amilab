/**
 * C++ Interface: wrap_wxBaseArrayInt
 *
 * Description: wrapping wxBaseArrayInt
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBaseArrayInt_h_
#define _wrap_wxBaseArrayInt_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxBaseArrayInt);

// TODO: check for inheritence ...
class WrapClass_wxBaseArrayInt : public WrapClass<wxBaseArrayInt>
    
{
  DEFINE_CLASS(WrapClass_wxBaseArrayInt);

  protected:
    typedef WrapClass<wxBaseArrayInt>::ptr _parentclass_ptr;
    typedef wxBaseArrayInt ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBaseArrayInt>& GetObj() const { return WrapClass<wxBaseArrayInt>::GetObj(); }

    /// Constructor
    WrapClass_wxBaseArrayInt(boost::shared_ptr<wxBaseArrayInt > si): 
    WrapClass<wxBaseArrayInt>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxBaseArrayInt()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBaseArrayInt_1,"Constructor wxBaseArrayInt::wxBaseArrayInt() (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#wxbasearrayint).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBaseArrayInt,"Constructor wxBaseArrayInt::wxBaseArrayInt() (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#wxbasearrayint).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBaseArrayInt_2,"Constructor wxBaseArrayInt::wxBaseArrayInt(wxBaseArrayInt const & array) (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#wxbasearrayint).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBaseArrayInt*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Empty,"void wxBaseArrayInt::Empty()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#empty)")
    ADD_CLASS_METHOD(Clear,"void wxBaseArrayInt::Clear()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#clear)")
    ADD_CLASS_METHOD(Alloc,"void wxBaseArrayInt::Alloc(size_t n)  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#alloc)")
    ADD_CLASS_METHOD(Shrink,"void wxBaseArrayInt::Shrink()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#shrink)")
    ADD_CLASS_METHOD(GetCount,"size_t wxBaseArrayInt::GetCount()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#getcount)")
    ADD_CLASS_METHOD(SetCount,"void wxBaseArrayInt::SetCount(size_t n, _wxArraywxBaseArrayInt defval = 0)  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#setcount)")
    ADD_CLASS_METHOD(IsEmpty,"bool wxBaseArrayInt::IsEmpty()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#isempty)")
    ADD_CLASS_METHOD(Count,"size_t wxBaseArrayInt::Count()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#count)")
    ADD_CLASS_METHOD(clear,"void wxBaseArrayInt::clear()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#clear)")
    ADD_CLASS_METHOD(empty,"bool wxBaseArrayInt::empty()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#empty)")
    ADD_CLASS_METHOD(max_size,"size_t wxBaseArrayInt::max_size()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#max_size)")
    ADD_CLASS_METHOD(size,"size_t wxBaseArrayInt::size()  (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#size)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxBaseArrayInt & wxBaseArrayInt::operator =(wxBaseArrayInt const & src) (http://docs.wxwidgets.org/stable/wx_wxbasearrayint.html#__assign__)")




    void AddMethods(WrapClass<wxBaseArrayInt>::ptr this_ptr );

};


#endif // _wrap_wxBaseArrayInt_h
