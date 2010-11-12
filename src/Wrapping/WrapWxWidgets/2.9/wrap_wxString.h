/**
 * C++ Interface: wrap_wxString
 *
 * Description: wrapping wxString
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxString_h_
#define _wrap_wxString_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxString);

// TODO: check for inheritence ...
class WrapClass_wxString : public WrapClass<wxString>
    
{
  DEFINE_CLASS(WrapClass_wxString);

  protected:
    typedef WrapClass<wxString>::ptr _parentclass_ptr;
    typedef wxString ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxString>& GetObj() const { return WrapClass<wxString>::GetObj(); }

    /// Constructor
    WrapClass_wxString(boost::shared_ptr<wxString > si): 
    WrapClass<wxString>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxString()
    {
      std::cout << "~WrapClass_wxString()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_1,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_2,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: wxUniChar
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_3,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /* The following types are missing: wxUniChar
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_4,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /* The following types are missing: wxUniCharRef
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_5,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /* The following types are missing: wxUniCharRef
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_6,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_7,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_8,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_9,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_10,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_11,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: wxMBConv
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_12,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_13,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: wxMBConv
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_14,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_15,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: wxMBConv
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_16,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_17,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: wxMBConv
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_18,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_19,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: wxMBConv
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_20,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_21,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: wxMBConv
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_22,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /* The following types are missing: wxScopedCharTypeBuffer<char>
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_23,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_24,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /* The following types are missing: wxCStrData
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_25,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /* The following types are missing: wxCStrData
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_26,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_27,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_28,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_29,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_30,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: const_iterator, const_iterator
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_31,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_32,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_33,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: wxCStrData, wxCStrData
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_34,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxString*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
/* The following types are missing: iterator
    ADD_CLASS_METHOD(IterToImplPos,"http://docs.wxwidgets.org/stable/wx_wxstring.html#itertoimplpos")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(GetIterForNthChar_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getiterfornthchar")
*/
    ADD_CLASS_METHOD(GetIterForNthChar,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getiterfornthchar")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(GetIterForNthChar_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getiterfornthchar")
*/
/* The following types are missing: basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >
    ADD_CLASS_METHOD(ToStdWstring,"http://docs.wxwidgets.org/stable/wx_wxstring.html#tostdwstring")
*/
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >
    ADD_CLASS_METHOD(ToStdString,"http://docs.wxwidgets.org/stable/wx_wxstring.html#tostdstring")
*/
    ADD_CLASS_METHOD(Clone,"http://docs.wxwidgets.org/stable/wx_wxstring.html#clone")
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(begin_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#begin")
*/
    ADD_CLASS_METHOD(begin,"http://docs.wxwidgets.org/stable/wx_wxstring.html#begin")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(begin_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#begin")
*/
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(end_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#end")
*/
    ADD_CLASS_METHOD(end,"http://docs.wxwidgets.org/stable/wx_wxstring.html#end")
/* The following types are missing: iterator
    ADD_CLASS_METHOD(end_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#end")
*/
/* The following types are missing: reverse_iterator_impl<wxString::const_iterator>
    ADD_CLASS_METHOD(rbegin_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rbegin")
*/
    ADD_CLASS_METHOD(rbegin,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rbegin")
/* The following types are missing: reverse_iterator_impl<wxString::iterator>
    ADD_CLASS_METHOD(rbegin_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rbegin")
*/
/* The following types are missing: reverse_iterator_impl<wxString::const_iterator>
    ADD_CLASS_METHOD(rend_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rend")
*/
    ADD_CLASS_METHOD(rend,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rend")
/* The following types are missing: reverse_iterator_impl<wxString::iterator>
    ADD_CLASS_METHOD(rend_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rend")
*/
    ADD_CLASS_METHOD(length,"http://docs.wxwidgets.org/stable/wx_wxstring.html#length")
    ADD_CLASS_METHOD(size,"http://docs.wxwidgets.org/stable/wx_wxstring.html#size")
    ADD_CLASS_METHOD(max_size,"http://docs.wxwidgets.org/stable/wx_wxstring.html#max_size")
    ADD_CLASS_METHOD(empty,"http://docs.wxwidgets.org/stable/wx_wxstring.html#empty")
    ADD_CLASS_METHOD(capacity,"http://docs.wxwidgets.org/stable/wx_wxstring.html#capacity")
    ADD_CLASS_METHOD(reserve,"http://docs.wxwidgets.org/stable/wx_wxstring.html#reserve")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(resize,"http://docs.wxwidgets.org/stable/wx_wxstring.html#resize")
*/
    ADD_CLASS_METHOD(substr,"http://docs.wxwidgets.org/stable/wx_wxstring.html#substr")
    ADD_CLASS_METHOD(Len,"http://docs.wxwidgets.org/stable/wx_wxstring.html#len")
    ADD_CLASS_METHOD(IsEmpty,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isempty")
    ADD_CLASS_METHOD(Truncate,"http://docs.wxwidgets.org/stable/wx_wxstring.html#truncate")
    ADD_CLASS_METHOD(Empty,"http://docs.wxwidgets.org/stable/wx_wxstring.html#empty")
    ADD_CLASS_METHOD(Clear,"http://docs.wxwidgets.org/stable/wx_wxstring.html#clear")
    ADD_CLASS_METHOD(IsAscii,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isascii")
    ADD_CLASS_METHOD(IsNumber,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isnumber")
    ADD_CLASS_METHOD(IsWord,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isword")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(at_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#at")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(GetChar,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getchar")
*/
    ADD_CLASS_METHOD(at,"http://docs.wxwidgets.org/stable/wx_wxstring.html#at")
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(at_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#at")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(GetWritableChar,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getwritablechar")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(SetChar,"http://docs.wxwidgets.org/stable/wx_wxstring.html#setchar")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(Last_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#last")
*/
    ADD_CLASS_METHOD(Last,"http://docs.wxwidgets.org/stable/wx_wxstring.html#last")
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(Last_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#last")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(c_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#c_str")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(data,"http://docs.wxwidgets.org/stable/wx_wxstring.html#data")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(GetData,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getdata")
*/
    ADD_CLASS_METHOD(wx_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wx_str")
/* The following types are missing: wxWritableCharTypeBuffer<char>, wxMBConv
    ADD_CLASS_METHOD(char_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#char_str")
*/
/* The following types are missing: wxWritableCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(wchar_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wchar_str")
*/
    ADD_CLASS_METHOD(FromAscii_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii")
    ADD_CLASS_METHOD(FromAscii,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii")
    ADD_CLASS_METHOD(FromAscii_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii")
    ADD_CLASS_METHOD(FromAscii_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii")
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(ToAscii,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toascii")
*/
    ADD_CLASS_METHOD(FromAscii_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii")
    ADD_CLASS_METHOD(FromAscii_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii")
    ADD_CLASS_METHOD(FromUTF8Unchecked_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8unchecked")
    ADD_CLASS_METHOD(FromUTF8Unchecked,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8unchecked")
    ADD_CLASS_METHOD(FromUTF8Unchecked_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8unchecked")
    ADD_CLASS_METHOD(FromUTF8_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8")
    ADD_CLASS_METHOD(FromUTF8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8")
    ADD_CLASS_METHOD(FromUTF8_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8")
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(utf8_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#utf8_str")
*/
    ADD_CLASS_METHOD(utf8_length,"http://docs.wxwidgets.org/stable/wx_wxstring.html#utf8_length")
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(ToUTF8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toutf8")
*/
    ADD_CLASS_METHOD(From8BitData_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#from8bitdata")
    ADD_CLASS_METHOD(From8BitData,"http://docs.wxwidgets.org/stable/wx_wxstring.html#from8bitdata")
    ADD_CLASS_METHOD(From8BitData_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#from8bitdata")
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(To8BitData,"http://docs.wxwidgets.org/stable/wx_wxstring.html#to8bitdata")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>, wxMBConv
    ADD_CLASS_METHOD(mb_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#mb_str")
*/
/* The following types are missing: wxCharBuffer
    ADD_CLASS_METHOD(mbc_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#mbc_str")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(wc_str_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wc_str")
*/
    ADD_CLASS_METHOD(wc_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wc_str")
/* The following types are missing: wxWCharBuffer, wxMBConv
    ADD_CLASS_METHOD(wc_str_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wc_str")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(fn_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fn_str")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(t_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#t_str")
*/
    ADD_CLASS_METHOD(Append_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(Append_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(Append_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(Append_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
    ADD_CLASS_METHOD(Append_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(Append_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(Append_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(Append_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(Append_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(Append_13,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
    ADD_CLASS_METHOD(Append_14,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append_15,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append_16,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Prepend,"http://docs.wxwidgets.org/stable/wx_wxstring.html#prepend")
    ADD_CLASS_METHOD(Cmp_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
    ADD_CLASS_METHOD(Cmp,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
    ADD_CLASS_METHOD(Cmp_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
    ADD_CLASS_METHOD(Cmp_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(Cmp_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(Cmp_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(Cmp_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
*/
    ADD_CLASS_METHOD(CmpNoCase,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmpnocase")
    ADD_CLASS_METHOD(IsSameAs_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(IsSameAs,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(IsSameAs_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(IsSameAs_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(IsSameAs_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(IsSameAs_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(IsSameAs_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(IsSameAs_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(IsSameAs_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
*/
    ADD_CLASS_METHOD(IsSameAs_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(IsSameAs_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(IsSameAs_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(IsSameAs_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(Mid,"http://docs.wxwidgets.org/stable/wx_wxstring.html#mid")
    ADD_CLASS_METHOD(StartsWith,"http://docs.wxwidgets.org/stable/wx_wxstring.html#startswith")
    ADD_CLASS_METHOD(EndsWith,"http://docs.wxwidgets.org/stable/wx_wxstring.html#endswith")
    ADD_CLASS_METHOD(Left,"http://docs.wxwidgets.org/stable/wx_wxstring.html#left")
    ADD_CLASS_METHOD(Right,"http://docs.wxwidgets.org/stable/wx_wxstring.html#right")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(BeforeFirst,"http://docs.wxwidgets.org/stable/wx_wxstring.html#beforefirst")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(BeforeLast,"http://docs.wxwidgets.org/stable/wx_wxstring.html#beforelast")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(AfterFirst,"http://docs.wxwidgets.org/stable/wx_wxstring.html#afterfirst")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(AfterLast,"http://docs.wxwidgets.org/stable/wx_wxstring.html#afterlast")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(Before,"http://docs.wxwidgets.org/stable/wx_wxstring.html#before")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(After,"http://docs.wxwidgets.org/stable/wx_wxstring.html#after")
*/
    ADD_CLASS_METHOD(MakeUpper,"http://docs.wxwidgets.org/stable/wx_wxstring.html#makeupper")
    ADD_CLASS_METHOD(Upper,"http://docs.wxwidgets.org/stable/wx_wxstring.html#upper")
    ADD_CLASS_METHOD(MakeLower,"http://docs.wxwidgets.org/stable/wx_wxstring.html#makelower")
    ADD_CLASS_METHOD(Lower,"http://docs.wxwidgets.org/stable/wx_wxstring.html#lower")
    ADD_CLASS_METHOD(MakeCapitalized,"http://docs.wxwidgets.org/stable/wx_wxstring.html#makecapitalized")
    ADD_CLASS_METHOD(Capitalize,"http://docs.wxwidgets.org/stable/wx_wxstring.html#capitalize")
    ADD_CLASS_METHOD(Trim,"http://docs.wxwidgets.org/stable/wx_wxstring.html#trim")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(Pad,"http://docs.wxwidgets.org/stable/wx_wxstring.html#pad")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(Find_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
    ADD_CLASS_METHOD(Find,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(Find_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
    ADD_CLASS_METHOD(Find_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(Find_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(Find_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(Find_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(Find_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(Find_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(Find_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(Find_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(Find_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
    ADD_CLASS_METHOD(Replace,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(Matches,"http://docs.wxwidgets.org/stable/wx_wxstring.html#matches")
    ADD_CLASS_METHOD(ToLong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#tolong")
    ADD_CLASS_METHOD(ToULong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toulong")
/* The following types are missing: long long int
    ADD_CLASS_METHOD(ToLongLong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#tolonglong")
*/
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(ToULongLong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toulonglong")
*/
    ADD_CLASS_METHOD(ToDouble,"http://docs.wxwidgets.org/stable/wx_wxstring.html#todouble")
    ADD_CLASS_METHOD(ToCLong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toclong")
    ADD_CLASS_METHOD(ToCULong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toculong")
    ADD_CLASS_METHOD(ToCDouble,"http://docs.wxwidgets.org/stable/wx_wxstring.html#tocdouble")
    ADD_CLASS_METHOD(FromDouble,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromdouble")
    ADD_CLASS_METHOD(FromCDouble,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromcdouble")
/* The following types are missing: wxFormatString
    ADD_CLASS_METHOD(Printf,"http://docs.wxwidgets.org/stable/wx_wxstring.html#printf")
*/
/* The following types are missing: __va_list_tag
    ADD_CLASS_METHOD(PrintfV,"http://docs.wxwidgets.org/stable/wx_wxstring.html#printfv")
*/
/* The following types are missing: wxFormatString
    ADD_CLASS_METHOD(Format_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
*/
    ADD_CLASS_METHOD(Format,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
/* The following types are missing: wxFormatString
    ADD_CLASS_METHOD(Format_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
*/
/* The following types are missing: wxFormatString
    ADD_CLASS_METHOD(Format_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
*/
/* The following types are missing: wxFormatString, long long unsigned int
    ADD_CLASS_METHOD(Format_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
*/
/* The following types are missing: wxFormatString, long long int
    ADD_CLASS_METHOD(Format_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
*/
/* The following types are missing: wxFormatString
    ADD_CLASS_METHOD(Format_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
*/
/* The following types are missing: wxFormatString
    ADD_CLASS_METHOD(Format_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
*/
/* The following types are missing: wxFormatString
    ADD_CLASS_METHOD(Format_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
*/
/* The following types are missing: wxFormatString
    ADD_CLASS_METHOD(Format_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
*/
/* The following types are missing: __va_list_tag
    ADD_CLASS_METHOD(FormatV,"http://docs.wxwidgets.org/stable/wx_wxstring.html#formatv")
*/
    ADD_CLASS_METHOD(Alloc,"http://docs.wxwidgets.org/stable/wx_wxstring.html#alloc")
    ADD_CLASS_METHOD(Shrink,"http://docs.wxwidgets.org/stable/wx_wxstring.html#shrink")
    ADD_CLASS_METHOD(SubString,"http://docs.wxwidgets.org/stable/wx_wxstring.html#substring")
/* The following types are missing: wxFormatString
    ADD_CLASS_METHOD(sprintf,"http://docs.wxwidgets.org/stable/wx_wxstring.html#sprintf")
*/
    ADD_CLASS_METHOD(Length,"http://docs.wxwidgets.org/stable/wx_wxstring.html#length")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(Freq,"http://docs.wxwidgets.org/stable/wx_wxstring.html#freq")
*/
    ADD_CLASS_METHOD(LowerCase,"http://docs.wxwidgets.org/stable/wx_wxstring.html#lowercase")
    ADD_CLASS_METHOD(UpperCase,"http://docs.wxwidgets.org/stable/wx_wxstring.html#uppercase")
    ADD_CLASS_METHOD(Index_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#index")
    ADD_CLASS_METHOD(Index,"http://docs.wxwidgets.org/stable/wx_wxstring.html#index")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(Index_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#index")
*/
    ADD_CLASS_METHOD(Remove_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#remove")
    ADD_CLASS_METHOD(RemoveLast,"http://docs.wxwidgets.org/stable/wx_wxstring.html#removelast")
    ADD_CLASS_METHOD(Remove,"http://docs.wxwidgets.org/stable/wx_wxstring.html#remove")
    ADD_CLASS_METHOD(Remove_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#remove")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(First_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
*/
    ADD_CLASS_METHOD(First,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(First_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
*/
    ADD_CLASS_METHOD(First_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
    ADD_CLASS_METHOD(First_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
    ADD_CLASS_METHOD(First_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
    ADD_CLASS_METHOD(First_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(Last_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#last")
*/
    ADD_CLASS_METHOD(Contains,"http://docs.wxwidgets.org/stable/wx_wxstring.html#contains")
    ADD_CLASS_METHOD(IsNull,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isnull")
    ADD_CLASS_METHOD(append_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(append_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(append_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(append_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(append_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(append_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(append_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(append_13,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(append_14,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
    ADD_CLASS_METHOD(append_15,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_16,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_17,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
/* The following types are missing: const_iterator, const_iterator
    ADD_CLASS_METHOD(append_18,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
    ADD_CLASS_METHOD(append_19,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_20,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
/* The following types are missing: wxCStrData, wxCStrData
    ADD_CLASS_METHOD(append_21,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
*/
    ADD_CLASS_METHOD(assign_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(assign_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(assign_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(assign_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(assign_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(assign_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(assign_13,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(assign_14,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(assign_15,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
    ADD_CLASS_METHOD(assign_16,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_17,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_18,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
/* The following types are missing: const_iterator, const_iterator
    ADD_CLASS_METHOD(assign_19,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
    ADD_CLASS_METHOD(assign_20,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_21,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
/* The following types are missing: wxCStrData, wxCStrData
    ADD_CLASS_METHOD(assign_22,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
*/
    ADD_CLASS_METHOD(compare_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
    ADD_CLASS_METHOD(compare,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
    ADD_CLASS_METHOD(compare_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
    ADD_CLASS_METHOD(compare_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(compare_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(compare_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(compare_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
*/
    ADD_CLASS_METHOD(compare_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
    ADD_CLASS_METHOD(compare_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
    ADD_CLASS_METHOD(compare_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
    ADD_CLASS_METHOD(compare_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#compare")
    ADD_CLASS_METHOD(insert_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(insert_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
*/
/* The following types are missing: iterator, iterator, wxUniChar
    ADD_CLASS_METHOD(insert_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
*/
/* The following types are missing: iterator, const_iterator, const_iterator
    ADD_CLASS_METHOD(insert_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(insert_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
*/
/* The following types are missing: iterator
    ADD_CLASS_METHOD(insert_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
*/
/* The following types are missing: iterator, wxCStrData, wxCStrData
    ADD_CLASS_METHOD(insert_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
*/
/* The following types are missing: iterator, wxUniChar
    ADD_CLASS_METHOD(insert_13,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
*/
    ADD_CLASS_METHOD(erase_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#erase")
    ADD_CLASS_METHOD(erase,"http://docs.wxwidgets.org/stable/wx_wxstring.html#erase")
/* The following types are missing: iterator, iterator, iterator
    ADD_CLASS_METHOD(erase_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#erase")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(erase_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#erase")
*/
    ADD_CLASS_METHOD(clear,"http://docs.wxwidgets.org/stable/wx_wxstring.html#clear")
    ADD_CLASS_METHOD(replace_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(replace_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
    ADD_CLASS_METHOD(replace_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(replace_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(replace_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(replace_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(replace_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(replace_13,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
/* The following types are missing: iterator, iterator, wxUniChar
    ADD_CLASS_METHOD(replace_14,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
/* The following types are missing: iterator, iterator, const_iterator, const_iterator
    ADD_CLASS_METHOD(replace_15,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(replace_16,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
/* The following types are missing: iterator, iterator
    ADD_CLASS_METHOD(replace_17,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
*/
    ADD_CLASS_METHOD(swap,"http://docs.wxwidgets.org/stable/wx_wxstring.html#swap")
    ADD_CLASS_METHOD(find_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(find,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(find_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(find_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(find_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(find_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(find_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(find_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(find_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
*/
    ADD_CLASS_METHOD(find_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(find_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(find_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(rfind_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
    ADD_CLASS_METHOD(rfind,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
    ADD_CLASS_METHOD(rfind_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
    ADD_CLASS_METHOD(rfind_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(rfind_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(rfind_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(rfind_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(rfind_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(rfind_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
*/
    ADD_CLASS_METHOD(rfind_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
    ADD_CLASS_METHOD(rfind_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
    ADD_CLASS_METHOD(rfind_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#rfind")
    ADD_CLASS_METHOD(find_first_of_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(find_first_of_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
*/
    ADD_CLASS_METHOD(find_last_of_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(find_last_of_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
*/
    ADD_CLASS_METHOD(find_first_not_of_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(find_first_not_of_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
*/
    ADD_CLASS_METHOD(find_last_not_of_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(find_last_not_of_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(find_first_of_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
*/
    ADD_CLASS_METHOD(find_first_of_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
    ADD_CLASS_METHOD(find_first_of_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(find_last_of_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
*/
    ADD_CLASS_METHOD(find_last_of_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
    ADD_CLASS_METHOD(find_last_of_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(find_first_not_of_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
*/
    ADD_CLASS_METHOD(find_first_not_of_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
    ADD_CLASS_METHOD(find_first_not_of_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(find_last_not_of_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
*/
    ADD_CLASS_METHOD(find_last_not_of_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
    ADD_CLASS_METHOD(find_last_not_of_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(find_first_of_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(find_first_of_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(find_first_of_13,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(find_first_of_14,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(find_first_of_15,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(find_first_of_16,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_of")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(find_last_of_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(find_last_of_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(find_last_of_13,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(find_last_of_14,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(find_last_of_15,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(find_last_of_16,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_of")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(find_first_not_of_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(find_first_not_of_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(find_first_not_of_13,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(find_first_not_of_14,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(find_first_not_of_15,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(find_first_not_of_16,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_first_not_of")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(find_last_not_of_11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(find_last_not_of_12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(find_last_not_of_13,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
*/
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(find_last_not_of_14,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(find_last_not_of_15,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(find_last_not_of_16,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find_last_not_of")
*/

    // Operators:
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#!")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(__at___1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
*/
    ADD_CLASS_METHOD(__at__,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(__at___2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(__at___3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(__at___4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(__at___5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(__at___6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(__at___7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(__at___8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
*/
    ADD_CLASS_METHOD(__assign___1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    ADD_CLASS_METHOD(__assign__,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(__assign___2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(__assign___3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(__assign___4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
*/
    ADD_CLASS_METHOD(__assign___5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    ADD_CLASS_METHOD(__assign___6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    ADD_CLASS_METHOD(__assign___7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    ADD_CLASS_METHOD(__assign___8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    ADD_CLASS_METHOD(__assign___9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    ADD_CLASS_METHOD(__assign___10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(__assign___11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(__assign___12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
*/
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
/* The following types are missing: wxCStrData
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
*/
/* The following types are missing: wxUniChar
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
*/
/* The following types are missing: wxUniCharRef
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
*/
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
*/
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
/* The following types are missing: long long int
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
*/
/* The following types are missing: long long unsigned int
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
*/
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#()")
    ADD_CLASS_METHOD(__add_assign___1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    ADD_CLASS_METHOD(__add_assign__,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    ADD_CLASS_METHOD(__add_assign___2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    ADD_CLASS_METHOD(__add_assign___3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
/* The following types are missing: wxCStrData
    ADD_CLASS_METHOD(__add_assign___4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
    ADD_CLASS_METHOD(__add_assign___5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
    ADD_CLASS_METHOD(__add_assign___6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
*/
/* The following types are missing: wxUniChar
    ADD_CLASS_METHOD(__add_assign___7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
*/
/* The following types are missing: wxUniCharRef
    ADD_CLASS_METHOD(__add_assign___8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
*/
    ADD_CLASS_METHOD(__add_assign___9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    ADD_CLASS_METHOD(__add_assign___10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    ADD_CLASS_METHOD(__add_assign___11,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    ADD_CLASS_METHOD(__add_assign___12,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")




    void AddMethods(WrapClass<wxString>::ptr this_ptr )
    {
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
/* The following types are missing: iterator
      AddVar_IterToImplPos( this_ptr);
*/
/* The following types are missing: iterator
      AddVar_GetIterForNthChar_1( this_ptr);
*/
      AddVar_GetIterForNthChar( this_ptr);
/* The following types are missing: const_iterator
      AddVar_GetIterForNthChar_2( this_ptr);
*/
/* The following types are missing: basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >
      AddVar_ToStdWstring( this_ptr);
*/
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >
      AddVar_ToStdString( this_ptr);
*/
      AddVar_Clone( this_ptr);
/* The following types are missing: const_iterator
      AddVar_begin_1( this_ptr);
*/
      AddVar_begin( this_ptr);
/* The following types are missing: iterator
      AddVar_begin_2( this_ptr);
*/
/* The following types are missing: const_iterator
      AddVar_end_1( this_ptr);
*/
      AddVar_end( this_ptr);
/* The following types are missing: iterator
      AddVar_end_2( this_ptr);
*/
/* The following types are missing: reverse_iterator_impl<wxString::const_iterator>
      AddVar_rbegin_1( this_ptr);
*/
      AddVar_rbegin( this_ptr);
/* The following types are missing: reverse_iterator_impl<wxString::iterator>
      AddVar_rbegin_2( this_ptr);
*/
/* The following types are missing: reverse_iterator_impl<wxString::const_iterator>
      AddVar_rend_1( this_ptr);
*/
      AddVar_rend( this_ptr);
/* The following types are missing: reverse_iterator_impl<wxString::iterator>
      AddVar_rend_2( this_ptr);
*/
      AddVar_length( this_ptr);
      AddVar_size( this_ptr);
      AddVar_max_size( this_ptr);
      AddVar_empty( this_ptr);
      AddVar_capacity( this_ptr);
      AddVar_reserve( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_resize( this_ptr);
*/
      AddVar_substr( this_ptr);
      AddVar_Len( this_ptr);
      AddVar_IsEmpty( this_ptr);
      AddVar_Truncate( this_ptr);
      AddVar_Empty( this_ptr);
      AddVar_Clear( this_ptr);
      AddVar_IsAscii( this_ptr);
      AddVar_IsNumber( this_ptr);
      AddVar_IsWord( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_at_1( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_GetChar( this_ptr);
*/
      AddVar_at( this_ptr);
/* The following types are missing: wxUniCharRef
      AddVar_at_2( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar_GetWritableChar( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_SetChar( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_Last_1( this_ptr);
*/
      AddVar_Last( this_ptr);
/* The following types are missing: wxUniCharRef
      AddVar_Last_2( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_c_str( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_data( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_GetData( this_ptr);
*/
      AddVar_wx_str( this_ptr);
/* The following types are missing: wxWritableCharTypeBuffer<char>, wxMBConv
      AddVar_char_str( this_ptr);
*/
/* The following types are missing: wxWritableCharTypeBuffer<wchar_t>
      AddVar_wchar_str( this_ptr);
*/
      AddVar_FromAscii_1( this_ptr);
      AddVar_FromAscii( this_ptr);
      AddVar_FromAscii_2( this_ptr);
      AddVar_FromAscii_3( this_ptr);
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_ToAscii( this_ptr);
*/
      AddVar_FromAscii_4( this_ptr);
      AddVar_FromAscii_5( this_ptr);
      AddVar_FromUTF8Unchecked_1( this_ptr);
      AddVar_FromUTF8Unchecked( this_ptr);
      AddVar_FromUTF8Unchecked_2( this_ptr);
      AddVar_FromUTF8_1( this_ptr);
      AddVar_FromUTF8( this_ptr);
      AddVar_FromUTF8_2( this_ptr);
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_utf8_str( this_ptr);
*/
      AddVar_utf8_length( this_ptr);
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_ToUTF8( this_ptr);
*/
      AddVar_From8BitData_1( this_ptr);
      AddVar_From8BitData( this_ptr);
      AddVar_From8BitData_2( this_ptr);
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_To8BitData( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>, wxMBConv
      AddVar_mb_str( this_ptr);
*/
/* The following types are missing: wxCharBuffer
      AddVar_mbc_str( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_wc_str_1( this_ptr);
*/
      AddVar_wc_str( this_ptr);
/* The following types are missing: wxWCharBuffer, wxMBConv
      AddVar_wc_str_2( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_fn_str( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_t_str( this_ptr);
*/
      AddVar_Append_1( this_ptr);
      AddVar_Append( this_ptr);
      AddVar_Append_2( this_ptr);
      AddVar_Append_3( this_ptr);
/* The following types are missing: wxCStrData
      AddVar_Append_4( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_Append_5( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_Append_6( this_ptr);
*/
      AddVar_Append_7( this_ptr);
      AddVar_Append_8( this_ptr);
/* The following types are missing: wxCStrData
      AddVar_Append_9( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_Append_10( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_Append_11( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_Append_12( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar_Append_13( this_ptr);
*/
      AddVar_Append_14( this_ptr);
      AddVar_Append_15( this_ptr);
      AddVar_Append_16( this_ptr);
      AddVar_Prepend( this_ptr);
      AddVar_Cmp_1( this_ptr);
      AddVar_Cmp( this_ptr);
      AddVar_Cmp_2( this_ptr);
      AddVar_Cmp_3( this_ptr);
/* The following types are missing: wxCStrData
      AddVar_Cmp_4( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_Cmp_5( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_Cmp_6( this_ptr);
*/
      AddVar_CmpNoCase( this_ptr);
      AddVar_IsSameAs_1( this_ptr);
      AddVar_IsSameAs( this_ptr);
      AddVar_IsSameAs_2( this_ptr);
      AddVar_IsSameAs_3( this_ptr);
/* The following types are missing: wxCStrData
      AddVar_IsSameAs_4( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_IsSameAs_5( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_IsSameAs_6( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_IsSameAs_7( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar_IsSameAs_8( this_ptr);
*/
      AddVar_IsSameAs_9( this_ptr);
      AddVar_IsSameAs_10( this_ptr);
      AddVar_IsSameAs_11( this_ptr);
      AddVar_IsSameAs_12( this_ptr);
      AddVar_Mid( this_ptr);
      AddVar_StartsWith( this_ptr);
      AddVar_EndsWith( this_ptr);
      AddVar_Left( this_ptr);
      AddVar_Right( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_BeforeFirst( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_BeforeLast( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_AfterFirst( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_AfterLast( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_Before( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_After( this_ptr);
*/
      AddVar_MakeUpper( this_ptr);
      AddVar_Upper( this_ptr);
      AddVar_MakeLower( this_ptr);
      AddVar_Lower( this_ptr);
      AddVar_MakeCapitalized( this_ptr);
      AddVar_Capitalize( this_ptr);
      AddVar_Trim( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_Pad( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_Find_1( this_ptr);
*/
      AddVar_Find( this_ptr);
/* The following types are missing: wxUniCharRef
      AddVar_Find_2( this_ptr);
*/
      AddVar_Find_3( this_ptr);
      AddVar_Find_4( this_ptr);
      AddVar_Find_5( this_ptr);
      AddVar_Find_6( this_ptr);
      AddVar_Find_7( this_ptr);
      AddVar_Find_8( this_ptr);
/* The following types are missing: wxCStrData
      AddVar_Find_9( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_Find_10( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_Find_11( this_ptr);
*/
      AddVar_Replace( this_ptr);
      AddVar_Matches( this_ptr);
      AddVar_ToLong( this_ptr);
      AddVar_ToULong( this_ptr);
/* The following types are missing: long long int
      AddVar_ToLongLong( this_ptr);
*/
/* The following types are missing: long long unsigned int
      AddVar_ToULongLong( this_ptr);
*/
      AddVar_ToDouble( this_ptr);
      AddVar_ToCLong( this_ptr);
      AddVar_ToCULong( this_ptr);
      AddVar_ToCDouble( this_ptr);
      AddVar_FromDouble( this_ptr);
      AddVar_FromCDouble( this_ptr);
/* The following types are missing: wxFormatString
      AddVar_Printf( this_ptr);
*/
/* The following types are missing: __va_list_tag
      AddVar_PrintfV( this_ptr);
*/
/* The following types are missing: wxFormatString
      AddVar_Format_1( this_ptr);
*/
      AddVar_Format( this_ptr);
/* The following types are missing: wxFormatString
      AddVar_Format_2( this_ptr);
*/
/* The following types are missing: wxFormatString
      AddVar_Format_3( this_ptr);
*/
/* The following types are missing: wxFormatString, long long unsigned int
      AddVar_Format_4( this_ptr);
*/
/* The following types are missing: wxFormatString, long long int
      AddVar_Format_5( this_ptr);
*/
/* The following types are missing: wxFormatString
      AddVar_Format_6( this_ptr);
*/
/* The following types are missing: wxFormatString
      AddVar_Format_7( this_ptr);
*/
/* The following types are missing: wxFormatString
      AddVar_Format_8( this_ptr);
*/
/* The following types are missing: wxFormatString
      AddVar_Format_9( this_ptr);
*/
/* The following types are missing: __va_list_tag
      AddVar_FormatV( this_ptr);
*/
      AddVar_Alloc( this_ptr);
      AddVar_Shrink( this_ptr);
      AddVar_SubString( this_ptr);
/* The following types are missing: wxFormatString
      AddVar_sprintf( this_ptr);
*/
      AddVar_Length( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_Freq( this_ptr);
*/
      AddVar_LowerCase( this_ptr);
      AddVar_UpperCase( this_ptr);
      AddVar_Index_1( this_ptr);
      AddVar_Index( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_Index_2( this_ptr);
*/
      AddVar_Remove_1( this_ptr);
      AddVar_RemoveLast( this_ptr);
      AddVar_Remove( this_ptr);
      AddVar_Remove_2( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_First_1( this_ptr);
*/
      AddVar_First( this_ptr);
/* The following types are missing: wxUniCharRef
      AddVar_First_2( this_ptr);
*/
      AddVar_First_3( this_ptr);
      AddVar_First_4( this_ptr);
      AddVar_First_5( this_ptr);
      AddVar_First_6( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_Last_3( this_ptr);
*/
      AddVar_Contains( this_ptr);
      AddVar_IsNull( this_ptr);
      AddVar_append_1( this_ptr);
      AddVar_append( this_ptr);
      AddVar_append_2( this_ptr);
      AddVar_append_3( this_ptr);
      AddVar_append_4( this_ptr);
      AddVar_append_5( this_ptr);
      AddVar_append_6( this_ptr);
/* The following types are missing: wxCStrData
      AddVar_append_7( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_append_8( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_append_9( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_append_10( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_append_11( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_append_12( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_append_13( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar_append_14( this_ptr);
*/
      AddVar_append_15( this_ptr);
      AddVar_append_16( this_ptr);
      AddVar_append_17( this_ptr);
/* The following types are missing: const_iterator, const_iterator
      AddVar_append_18( this_ptr);
*/
      AddVar_append_19( this_ptr);
      AddVar_append_20( this_ptr);
/* The following types are missing: wxCStrData, wxCStrData
      AddVar_append_21( this_ptr);
*/
      AddVar_assign_1( this_ptr);
      AddVar_assign( this_ptr);
      AddVar_assign_2( this_ptr);
      AddVar_assign_3( this_ptr);
      AddVar_assign_4( this_ptr);
      AddVar_assign_5( this_ptr);
      AddVar_assign_6( this_ptr);
      AddVar_assign_7( this_ptr);
/* The following types are missing: wxCStrData
      AddVar_assign_8( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_assign_9( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_assign_10( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_assign_11( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_assign_12( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_assign_13( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_assign_14( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar_assign_15( this_ptr);
*/
      AddVar_assign_16( this_ptr);
      AddVar_assign_17( this_ptr);
      AddVar_assign_18( this_ptr);
/* The following types are missing: const_iterator, const_iterator
      AddVar_assign_19( this_ptr);
*/
      AddVar_assign_20( this_ptr);
      AddVar_assign_21( this_ptr);
/* The following types are missing: wxCStrData, wxCStrData
      AddVar_assign_22( this_ptr);
*/
      AddVar_compare_1( this_ptr);
      AddVar_compare( this_ptr);
      AddVar_compare_2( this_ptr);
      AddVar_compare_3( this_ptr);
/* The following types are missing: wxCStrData
      AddVar_compare_4( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_compare_5( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_compare_6( this_ptr);
*/
      AddVar_compare_7( this_ptr);
      AddVar_compare_8( this_ptr);
      AddVar_compare_9( this_ptr);
      AddVar_compare_10( this_ptr);
      AddVar_insert_1( this_ptr);
      AddVar_insert( this_ptr);
      AddVar_insert_2( this_ptr);
      AddVar_insert_3( this_ptr);
      AddVar_insert_4( this_ptr);
      AddVar_insert_5( this_ptr);
      AddVar_insert_6( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_insert_7( this_ptr);
*/
/* The following types are missing: iterator, iterator, wxUniChar
      AddVar_insert_8( this_ptr);
*/
/* The following types are missing: iterator, const_iterator, const_iterator
      AddVar_insert_9( this_ptr);
*/
/* The following types are missing: iterator
      AddVar_insert_10( this_ptr);
*/
/* The following types are missing: iterator
      AddVar_insert_11( this_ptr);
*/
/* The following types are missing: iterator, wxCStrData, wxCStrData
      AddVar_insert_12( this_ptr);
*/
/* The following types are missing: iterator, wxUniChar
      AddVar_insert_13( this_ptr);
*/
      AddVar_erase_1( this_ptr);
      AddVar_erase( this_ptr);
/* The following types are missing: iterator, iterator, iterator
      AddVar_erase_2( this_ptr);
*/
/* The following types are missing: iterator, iterator
      AddVar_erase_3( this_ptr);
*/
      AddVar_clear( this_ptr);
      AddVar_replace_1( this_ptr);
      AddVar_replace( this_ptr);
      AddVar_replace_2( this_ptr);
      AddVar_replace_3( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_replace_4( this_ptr);
*/
      AddVar_replace_5( this_ptr);
      AddVar_replace_6( this_ptr);
      AddVar_replace_7( this_ptr);
      AddVar_replace_8( this_ptr);
/* The following types are missing: iterator, iterator
      AddVar_replace_9( this_ptr);
*/
/* The following types are missing: iterator, iterator
      AddVar_replace_10( this_ptr);
*/
/* The following types are missing: iterator, iterator
      AddVar_replace_11( this_ptr);
*/
/* The following types are missing: iterator, iterator
      AddVar_replace_12( this_ptr);
*/
/* The following types are missing: iterator, iterator
      AddVar_replace_13( this_ptr);
*/
/* The following types are missing: iterator, iterator, wxUniChar
      AddVar_replace_14( this_ptr);
*/
/* The following types are missing: iterator, iterator, const_iterator, const_iterator
      AddVar_replace_15( this_ptr);
*/
/* The following types are missing: iterator, iterator
      AddVar_replace_16( this_ptr);
*/
/* The following types are missing: iterator, iterator
      AddVar_replace_17( this_ptr);
*/
      AddVar_swap( this_ptr);
      AddVar_find_1( this_ptr);
      AddVar_find( this_ptr);
      AddVar_find_2( this_ptr);
      AddVar_find_3( this_ptr);
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_find_4( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_find_5( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_find_6( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_find_7( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar_find_8( this_ptr);
*/
      AddVar_find_9( this_ptr);
      AddVar_find_10( this_ptr);
      AddVar_find_11( this_ptr);
      AddVar_rfind_1( this_ptr);
      AddVar_rfind( this_ptr);
      AddVar_rfind_2( this_ptr);
      AddVar_rfind_3( this_ptr);
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_rfind_4( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_rfind_5( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_rfind_6( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar_rfind_7( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar_rfind_8( this_ptr);
*/
      AddVar_rfind_9( this_ptr);
      AddVar_rfind_10( this_ptr);
      AddVar_rfind_11( this_ptr);
      AddVar_find_first_of_1( this_ptr);
      AddVar_find_first_of( this_ptr);
      AddVar_find_first_of_2( this_ptr);
      AddVar_find_first_of_3( this_ptr);
      AddVar_find_first_of_4( this_ptr);
      AddVar_find_first_of_5( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_find_first_of_6( this_ptr);
*/
      AddVar_find_last_of_1( this_ptr);
      AddVar_find_last_of( this_ptr);
      AddVar_find_last_of_2( this_ptr);
      AddVar_find_last_of_3( this_ptr);
      AddVar_find_last_of_4( this_ptr);
      AddVar_find_last_of_5( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_find_last_of_6( this_ptr);
*/
      AddVar_find_first_not_of_1( this_ptr);
      AddVar_find_first_not_of( this_ptr);
      AddVar_find_first_not_of_2( this_ptr);
      AddVar_find_first_not_of_3( this_ptr);
      AddVar_find_first_not_of_4( this_ptr);
      AddVar_find_first_not_of_5( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_find_first_not_of_6( this_ptr);
*/
      AddVar_find_last_not_of_1( this_ptr);
      AddVar_find_last_not_of( this_ptr);
      AddVar_find_last_not_of_2( this_ptr);
      AddVar_find_last_not_of_3( this_ptr);
      AddVar_find_last_not_of_4( this_ptr);
      AddVar_find_last_not_of_5( this_ptr);
/* The following types are missing: wxUniChar
      AddVar_find_last_not_of_6( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar_find_first_of_7( this_ptr);
*/
      AddVar_find_first_of_8( this_ptr);
      AddVar_find_first_of_9( this_ptr);
      AddVar_find_first_of_10( this_ptr);
/* The following types are missing: wxUniCharRef
      AddVar_find_last_of_7( this_ptr);
*/
      AddVar_find_last_of_8( this_ptr);
      AddVar_find_last_of_9( this_ptr);
      AddVar_find_last_of_10( this_ptr);
/* The following types are missing: wxUniCharRef
      AddVar_find_first_not_of_7( this_ptr);
*/
      AddVar_find_first_not_of_8( this_ptr);
      AddVar_find_first_not_of_9( this_ptr);
      AddVar_find_first_not_of_10( this_ptr);
/* The following types are missing: wxUniCharRef
      AddVar_find_last_not_of_7( this_ptr);
*/
      AddVar_find_last_not_of_8( this_ptr);
      AddVar_find_last_not_of_9( this_ptr);
      AddVar_find_last_not_of_10( this_ptr);
/* The following types are missing: wxCStrData
      AddVar_find_first_of_11( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_find_first_of_12( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_find_first_of_13( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_find_first_of_14( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_find_first_of_15( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_find_first_of_16( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_find_last_of_11( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_find_last_of_12( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_find_last_of_13( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_find_last_of_14( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_find_last_of_15( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_find_last_of_16( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_find_first_not_of_11( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_find_first_not_of_12( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_find_first_not_of_13( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_find_first_not_of_14( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_find_first_not_of_15( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_find_first_not_of_16( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_find_last_not_of_11( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_find_last_not_of_12( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_find_last_not_of_13( this_ptr);
*/
/* The following types are missing: wxCStrData
      AddVar_find_last_not_of_14( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar_find_last_not_of_15( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar_find_last_not_of_16( this_ptr);
*/

      // Adding operators
      // AddVar_operator not available( this_ptr);
/* The following types are missing: wxUniChar
      AddVar___at___1( this_ptr);
*/
      AddVar___at__( this_ptr);
/* The following types are missing: wxUniChar
      AddVar___at___2( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar___at___3( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar___at___4( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar___at___5( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar___at___6( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar___at___7( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar___at___8( this_ptr);
*/
      AddVar___assign___1( this_ptr);
      AddVar___assign__( this_ptr);
/* The following types are missing: wxCStrData
      AddVar___assign___2( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar___assign___3( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar___assign___4( this_ptr);
*/
      AddVar___assign___5( this_ptr);
      AddVar___assign___6( this_ptr);
      AddVar___assign___7( this_ptr);
      AddVar___assign___8( this_ptr);
      AddVar___assign___9( this_ptr);
      AddVar___assign___10( this_ptr);
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar___assign___11( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar___assign___12( this_ptr);
*/
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
/* The following types are missing: wxCStrData
      // AddVar_operator not available( this_ptr);
*/
/* The following types are missing: wxUniChar
      // AddVar_operator not available( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      // AddVar_operator not available( this_ptr);
*/
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      // AddVar_operator not available( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      // AddVar_operator not available( this_ptr);
*/
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
/* The following types are missing: long long int
      // AddVar_operator not available( this_ptr);
*/
/* The following types are missing: long long unsigned int
      // AddVar_operator not available( this_ptr);
*/
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      AddVar___add_assign___1( this_ptr);
      AddVar___add_assign__( this_ptr);
      AddVar___add_assign___2( this_ptr);
      AddVar___add_assign___3( this_ptr);
/* The following types are missing: wxCStrData
      AddVar___add_assign___4( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>
      AddVar___add_assign___5( this_ptr);
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>
      AddVar___add_assign___6( this_ptr);
*/
/* The following types are missing: wxUniChar
      AddVar___add_assign___7( this_ptr);
*/
/* The following types are missing: wxUniCharRef
      AddVar___add_assign___8( this_ptr);
*/
      AddVar___add_assign___9( this_ptr);
      AddVar___add_assign___10( this_ptr);
      AddVar___add_assign___11( this_ptr);
      AddVar___add_assign___12( this_ptr);



      
    };
};


#endif // _wrap_wxString_h
