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

#include "wrap_wxStringBase.h"



AMI_DECLARE_TYPE(wxString);

// TODO: check for inheritence ...
class WrapClass_wxString : public WrapClass<wxString>
    , public   WrapClass_wxStringBase
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
    , WrapClass_wxStringBase(si)
    {}

    /// Destructor
    ~WrapClass_wxString()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_1,"Constructor wxString::wxString() (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString,"Constructor wxString::wxString() (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_2,"Constructor wxString::wxString(wxStringBase const & stringSrc) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_3,"Constructor wxString::wxString(wxString const & stringSrc) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_4,"Constructor wxString::wxString(wxChar ch, size_t nRepeat = 1) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_5,"Constructor wxString::wxString(size_t nRepeat, wxChar ch) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_6,"Constructor wxString::wxString(wxChar const * psz) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_7,"Constructor wxString::wxString(wxChar const * psz, size_t nLength) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_8,"Constructor wxString::wxString(wxChar const * psz, wxMBConv const & param1, size_t nLength = wxStringBase::npos) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /* The following types are missing: basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_9,"Constructor wxString::wxString(wxStdString const & s) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_10,"Constructor wxString::wxString(char const * psz, wxMBConv const & conv, size_t nLength = wxStringBase::npos) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_11,"Constructor wxString::wxString(wxWCharBuffer const & psz) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_12,"Constructor wxString::wxString(wxString const & str, size_t nPos, size_t nLen) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    /* The following types are missing: void, void
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_13,"Constructor wxString::wxString(void const * pStart, void const * pEnd) (http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxString*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(FromAscii_1,"wxString wxString::FromAscii(char const * ascii) (http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii).");
    ADD_CLASS_STATICMETHOD(FromAscii,"wxString::FromAscii() (http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii).");
    ADD_CLASS_STATICMETHOD(FromAscii_2,"wxString wxString::FromAscii(char const ascii) (http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii).");
    ADD_CLASS_STATICMETHOD(FromUTF8_1,"wxString wxString::FromUTF8(char const * utf8) (http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8).");
    ADD_CLASS_STATICMETHOD(FromUTF8,"wxString::FromUTF8() (http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8).");
    ADD_CLASS_STATICMETHOD(FromUTF8_2,"wxString wxString::FromUTF8(char const * utf8, size_t len) (http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8).");
    ADD_CLASS_STATICMETHOD(From8BitData_1,"wxString wxString::From8BitData(char const * data, size_t len) (http://docs.wxwidgets.org/stable/wx_wxstring.html#from8bitdata).");
    ADD_CLASS_STATICMETHOD(From8BitData,"wxString::From8BitData() (http://docs.wxwidgets.org/stable/wx_wxstring.html#from8bitdata).");
    ADD_CLASS_STATICMETHOD(From8BitData_2,"wxString wxString::From8BitData(char const * data) (http://docs.wxwidgets.org/stable/wx_wxstring.html#from8bitdata).");
    ADD_CLASS_STATICMETHOD(Format,"wxString wxString::Format(wxChar const * pszFormat) (http://docs.wxwidgets.org/stable/wx_wxstring.html#format).");
    /* The following types are missing: __va_list_tag
    ADD_CLASS_STATICMETHOD(FormatV,"wxString wxString::FormatV(wxChar const * pszFormat, __va_list_tag * argptr) (http://docs.wxwidgets.org/stable/wx_wxstring.html#formatv).");
    */



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Len,"size_t wxString::Len()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#len)")
    ADD_CLASS_METHOD(IsEmpty,"bool wxString::IsEmpty()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#isempty)")
    ADD_CLASS_METHOD(Truncate,"wxString & wxString::Truncate(size_t uiLen)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#truncate)")
    ADD_CLASS_METHOD(Empty,"void wxString::Empty()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#empty)")
    ADD_CLASS_METHOD(Clear,"void wxString::Clear()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#clear)")
    ADD_CLASS_METHOD(IsAscii,"bool wxString::IsAscii()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#isascii)")
    ADD_CLASS_METHOD(IsNumber,"bool wxString::IsNumber()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#isnumber)")
    ADD_CLASS_METHOD(IsWord,"bool wxString::IsWord()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#isword)")
    ADD_CLASS_METHOD(GetChar,"wxChar wxString::GetChar(size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#getchar)")
    ADD_CLASS_METHOD(GetWritableChar,"wxChar & wxString::GetWritableChar(size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#getwritablechar)")
    ADD_CLASS_METHOD(SetChar,"void wxString::SetChar(size_t n, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#setchar)")
    ADD_CLASS_METHOD(Last_1,"wxChar wxString::Last()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#last)")
    ADD_CLASS_METHOD(Last,"wxString::Last()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#last)")
    ADD_CLASS_METHOD(Last_2,"wxChar & wxString::Last()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#last)")
    ADD_CLASS_METHOD(wx_str,"wxChar const * wxString::wx_str()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#wx_str)")
    ADD_CLASS_METHOD(GetData,"wxChar const * wxString::GetData()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#getdata)")
    ADD_CLASS_METHOD(char_str,"wxWritableCharBuffer wxString::char_str(wxMBConv const & conv = wxConvLibc)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#char_str)")
    ADD_CLASS_METHOD(wchar_str,"wxWritableWCharBuffer wxString::wchar_str()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#wchar_str)")
    ADD_CLASS_METHOD(ToAscii,"wxCharBuffer const wxString::ToAscii()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#toascii)")
    ADD_CLASS_METHOD(utf8_str,"wxCharBuffer const wxString::utf8_str()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#utf8_str)")
    ADD_CLASS_METHOD(ToUTF8,"wxCharBuffer const wxString::ToUTF8()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#toutf8)")
    ADD_CLASS_METHOD(To8BitData,"wxCharBuffer const wxString::To8BitData()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#to8bitdata)")
    ADD_CLASS_METHOD(mb_str,"wxCharBuffer const wxString::mb_str(wxMBConv const & conv = wxConvLibc)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#mb_str)")
    ADD_CLASS_METHOD(mbc_str,"wxCharBuffer const wxString::mbc_str()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#mbc_str)")
    ADD_CLASS_METHOD(wc_str_1,"wxChar const * wxString::wc_str()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#wc_str)")
    ADD_CLASS_METHOD(wc_str,"wxString::wc_str()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#wc_str)")
    ADD_CLASS_METHOD(wc_str_2,"wxChar const * wxString::wc_str(wxMBConv const & param0)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#wc_str)")
    ADD_CLASS_METHOD(fn_str,"wxCharBuffer const wxString::fn_str()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#fn_str)")
    ADD_CLASS_METHOD(Append_1,"wxString & wxString::Append(wxString const & s)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(Append,"wxString::Append()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(Append_2,"wxString & wxString::Append(wxChar const * psz)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(Append_3,"wxString & wxString::Append(wxChar ch, size_t count = 1u)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(Append_4,"wxString & wxString::Append(wxChar const * psz, size_t nLen)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(Prepend,"wxString & wxString::Prepend(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#prepend)")
    ADD_CLASS_METHOD(Cmp_1,"int wxString::Cmp(wxChar const * psz)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp)")
    ADD_CLASS_METHOD(Cmp,"wxString::Cmp()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp)")
    ADD_CLASS_METHOD(Cmp_2,"int wxString::Cmp(wxString const & s)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp)")
    ADD_CLASS_METHOD(CmpNoCase_1,"int wxString::CmpNoCase(wxChar const * psz)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#cmpnocase)")
    ADD_CLASS_METHOD(CmpNoCase,"wxString::CmpNoCase()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#cmpnocase)")
    ADD_CLASS_METHOD(CmpNoCase_2,"int wxString::CmpNoCase(wxString const & s)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#cmpnocase)")
    ADD_CLASS_METHOD(IsSameAs_1,"bool wxString::IsSameAs(wxChar const * psz, bool compareWithCase = true)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas)")
    ADD_CLASS_METHOD(IsSameAs,"wxString::IsSameAs()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas)")
    ADD_CLASS_METHOD(IsSameAs_2,"bool wxString::IsSameAs(wxChar c, bool compareWithCase = true)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas)")
    ADD_CLASS_METHOD(Mid,"wxString wxString::Mid(size_t nFirst, size_t nCount = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#mid)")
    ADD_CLASS_METHOD(StartsWith,"bool wxString::StartsWith(wxChar const * prefix, wxString * rest = 0l)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#startswith)")
    ADD_CLASS_METHOD(EndsWith,"bool wxString::EndsWith(wxChar const * suffix, wxString * rest = 0l)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#endswith)")
    ADD_CLASS_METHOD(Left,"wxString wxString::Left(size_t nCount)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#left)")
    ADD_CLASS_METHOD(Right,"wxString wxString::Right(size_t nCount)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#right)")
    ADD_CLASS_METHOD(BeforeFirst,"wxString wxString::BeforeFirst(wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#beforefirst)")
    ADD_CLASS_METHOD(BeforeLast,"wxString wxString::BeforeLast(wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#beforelast)")
    ADD_CLASS_METHOD(AfterFirst,"wxString wxString::AfterFirst(wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#afterfirst)")
    ADD_CLASS_METHOD(AfterLast,"wxString wxString::AfterLast(wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#afterlast)")
    ADD_CLASS_METHOD(Before,"wxString wxString::Before(wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#before)")
    ADD_CLASS_METHOD(After,"wxString wxString::After(wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#after)")
    ADD_CLASS_METHOD(MakeUpper,"wxString & wxString::MakeUpper()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#makeupper)")
    ADD_CLASS_METHOD(Upper,"wxString wxString::Upper()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#upper)")
    ADD_CLASS_METHOD(MakeLower,"wxString & wxString::MakeLower()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#makelower)")
    ADD_CLASS_METHOD(Lower,"wxString wxString::Lower()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#lower)")
    ADD_CLASS_METHOD(Trim,"wxString & wxString::Trim(bool bFromRight = true)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#trim)")
    ADD_CLASS_METHOD(Pad,"wxString & wxString::Pad(size_t nCount, wxChar chPad = 32, bool bFromRight = true)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#pad)")
    ADD_CLASS_METHOD(Find_1,"int wxString::Find(wxChar ch, bool bFromEnd = false)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#find)")
    ADD_CLASS_METHOD(Find,"wxString::Find()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#find)")
    ADD_CLASS_METHOD(Find_2,"int wxString::Find(wxChar const * pszSub)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#find)")
    ADD_CLASS_METHOD(Replace,"size_t wxString::Replace(wxChar const * szOld, wxChar const * szNew, bool bReplaceAll = true)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(Matches,"bool wxString::Matches(wxChar const * szMask)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#matches)")
    ADD_CLASS_METHOD(ToLong,"bool wxString::ToLong(long int * val, int base = 10)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#tolong)")
    ADD_CLASS_METHOD(ToULong,"bool wxString::ToULong(long unsigned int * val, int base = 10)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#toulong)")
    ADD_CLASS_METHOD(ToLongLong,"bool wxString::ToLongLong(long long int * val, int base = 10)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#tolonglong)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(ToULongLong,"bool wxString::ToULongLong(long long unsigned int * val, int base = 10)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#toulonglong)")
*/
    ADD_CLASS_METHOD(ToDouble,"bool wxString::ToDouble(double * val)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#todouble)")
    ADD_CLASS_METHOD(Printf,"int wxString::Printf(wxChar const * pszFormat)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#printf)")
/* The following types are missing: __va_list_tag
    ADD_CLASS_METHOD(PrintfV,"int wxString::PrintfV(wxChar const * pszFormat, __va_list_tag * argptr)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#printfv)")
*/
    ADD_CLASS_METHOD(Alloc,"bool wxString::Alloc(size_t nLen)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#alloc)")
    ADD_CLASS_METHOD(Shrink,"bool wxString::Shrink()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#shrink)")
    ADD_CLASS_METHOD(GetWriteBuf,"wxChar * wxString::GetWriteBuf(size_t nLen)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#getwritebuf)")
    ADD_CLASS_METHOD(UngetWriteBuf_1,"void wxString::UngetWriteBuf()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#ungetwritebuf)")
    ADD_CLASS_METHOD(UngetWriteBuf,"wxString::UngetWriteBuf()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#ungetwritebuf)")
    ADD_CLASS_METHOD(UngetWriteBuf_2,"void wxString::UngetWriteBuf(size_t nLen)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#ungetwritebuf)")
    ADD_CLASS_METHOD(SubString,"wxString wxString::SubString(size_t from, size_t to)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#substring)")
    ADD_CLASS_METHOD(sprintf,"int wxString::sprintf(wxChar const * pszFormat)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#sprintf)")
    ADD_CLASS_METHOD(Length,"size_t wxString::Length()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#length)")
    ADD_CLASS_METHOD(Freq,"int wxString::Freq(wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#freq)")
    ADD_CLASS_METHOD(LowerCase,"void wxString::LowerCase()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#lowercase)")
    ADD_CLASS_METHOD(UpperCase,"void wxString::UpperCase()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#uppercase)")
    ADD_CLASS_METHOD(Index_1,"size_t wxString::Index(wxChar const * psz)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#index)")
    ADD_CLASS_METHOD(Index,"wxString::Index()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#index)")
    ADD_CLASS_METHOD(Index_2,"size_t wxString::Index(wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#index)")
    ADD_CLASS_METHOD(Remove_1,"wxString & wxString::Remove(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#remove)")
    ADD_CLASS_METHOD(RemoveLast,"wxString & wxString::RemoveLast(size_t n = 1)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#removelast)")
    ADD_CLASS_METHOD(Remove,"wxString::Remove()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#remove)")
    ADD_CLASS_METHOD(Remove_2,"wxString & wxString::Remove(size_t nStart, size_t nLen)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#remove)")
    ADD_CLASS_METHOD(First_1,"int wxString::First(wxChar const ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#first)")
    ADD_CLASS_METHOD(First,"wxString::First()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#first)")
    ADD_CLASS_METHOD(First_2,"int wxString::First(wxChar const * psz)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#first)")
    ADD_CLASS_METHOD(First_3,"int wxString::First(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#first)")
    ADD_CLASS_METHOD(Last_3,"int wxString::Last(wxChar const ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#last)")
    ADD_CLASS_METHOD(Contains,"bool wxString::Contains(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#contains)")
    ADD_CLASS_METHOD(IsNull,"bool wxString::IsNull()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#isnull)")
    ADD_CLASS_METHOD(append_1,"wxString & wxString::append(wxString const & str, size_t pos, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(append,"wxString::append()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(append_2,"wxString & wxString::append(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(append_3,"wxString & wxString::append(wxChar const * sz)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(append_4,"wxString & wxString::append(wxChar const * sz, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(append_5,"wxString & wxString::append(size_t n, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(append_6,"wxString & wxString::append(wxChar const * first, wxChar const * last)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#append)")
    ADD_CLASS_METHOD(assign_1,"wxString & wxString::assign(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#assign)")
    ADD_CLASS_METHOD(assign,"wxString::assign()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#assign)")
    ADD_CLASS_METHOD(assign_2,"wxString & wxString::assign(wxString const & str, size_t pos, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#assign)")
    ADD_CLASS_METHOD(assign_3,"wxString & wxString::assign(wxChar const * sz)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#assign)")
    ADD_CLASS_METHOD(assign_4,"wxString & wxString::assign(wxChar const * sz, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#assign)")
    ADD_CLASS_METHOD(assign_5,"wxString & wxString::assign(size_t n, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#assign)")
    ADD_CLASS_METHOD(assign_6,"wxString & wxString::assign(wxChar const * first, wxChar const * last)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#assign)")
    ADD_CLASS_METHOD(insert_1,"wxString & wxString::insert(size_t nPos, wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#insert)")
    ADD_CLASS_METHOD(insert,"wxString::insert()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#insert)")
    ADD_CLASS_METHOD(insert_2,"wxString & wxString::insert(size_t nPos, wxString const & str, size_t nStart, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#insert)")
    ADD_CLASS_METHOD(insert_3,"wxString & wxString::insert(size_t nPos, wxChar const * sz)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#insert)")
    ADD_CLASS_METHOD(insert_4,"wxString & wxString::insert(size_t nPos, wxChar const * sz, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#insert)")
    ADD_CLASS_METHOD(insert_5,"wxString & wxString::insert(size_t nPos, size_t n, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#insert)")
    ADD_CLASS_METHOD(insert_6,"wxChar * wxString::insert(wxChar * it, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#insert)")
    ADD_CLASS_METHOD(insert_7,"void wxString::insert(wxChar * it, wxChar const * first, wxChar const * last)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#insert)")
    ADD_CLASS_METHOD(insert_8,"void wxString::insert(wxChar * it, size_t n, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#insert)")
    ADD_CLASS_METHOD(erase_1,"wxString & wxString::erase(size_t pos = 0, size_t n = wxStringBase::npos)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#erase)")
    ADD_CLASS_METHOD(erase,"wxString::erase()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#erase)")
    ADD_CLASS_METHOD(erase_2,"wxChar * wxString::erase(wxChar * first, wxChar * last)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#erase)")
    ADD_CLASS_METHOD(erase_3,"wxChar * wxString::erase(wxChar * first)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#erase)")
    ADD_CLASS_METHOD(replace_1,"wxString & wxString::replace(size_t nStart, size_t nLen, wxChar const * sz)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace,"wxString::replace()  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace_2,"wxString & wxString::replace(size_t nStart, size_t nLen, wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace_3,"wxString & wxString::replace(size_t nStart, size_t nLen, size_t nCount, wxChar ch)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace_4,"wxString & wxString::replace(size_t nStart, size_t nLen, wxString const & str, size_t nStart2, size_t nLen2)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace_5,"wxString & wxString::replace(size_t nStart, size_t nLen, wxChar const * sz, size_t nCount)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace_6,"wxString & wxString::replace(wxChar * first, wxChar * last, wxChar const * s)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace_7,"wxString & wxString::replace(wxChar * first, wxChar * last, wxChar const * s, size_t n)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace_8,"wxString & wxString::replace(wxChar * first, wxChar * last, wxString const & s)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace_9,"wxString & wxString::replace(wxChar * first, wxChar * last, size_t n, wxChar c)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")
    ADD_CLASS_METHOD(replace_10,"wxString & wxString::replace(wxChar * first, wxChar * last, wxChar const * first1, wxChar const * last1)  (http://docs.wxwidgets.org/stable/wx_wxstring.html#replace)")

    // Operators:
    ADD_CLASS_METHOD(__assign___1,            "wxString & wxString::operator =(wxString const & param0) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__)")
    // ADD_CLASS_METHOD(operator not available,"bool wxString::!() (http://docs.wxwidgets.org/stable/wx_wxstring.html#!)")
    ADD_CLASS_METHOD(__at___1,            "wxChar & wxString::operator [](int n) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__)")
    ADD_CLASS_METHOD(__at__,            "wxString::operator []() (http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__)")
    ADD_CLASS_METHOD(__at___2,            "wxChar & wxString::operator [](size_t n) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__)")
    ADD_CLASS_METHOD(__at___3,            "wxChar & wxString::operator [](unsigned int n) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__)")
    ADD_CLASS_METHOD(__assign__,            "wxString::operator =() (http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__)")
    ADD_CLASS_METHOD(__assign___2,            "wxString & wxString::operator =(wxStringBase const & stringSrc) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__)")
    ADD_CLASS_METHOD(__assign___3,            "wxString & wxString::operator =(wxChar ch) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__)")
    ADD_CLASS_METHOD(__assign___4,            "wxString & wxString::operator =(wxChar const * psz) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__)")
    ADD_CLASS_METHOD(__assign___5,            "wxString & wxString::operator =(wxWCharBuffer const & psz) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(wxString const & s) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString::<<() (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(wxChar const * psz) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(wxChar ch) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(wxWCharBuffer const & s) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    ADD_CLASS_METHOD(__add_assign___1,            "void wxString::operator +=(wxWCharBuffer const & s) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(int i) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(unsigned int ui) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(long int l) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(long unsigned int ul) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(long long int ll) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
/* The following types are missing: long long unsigned int
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(long long unsigned int ull) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
*/
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(float f) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString & wxString::<<(double d) (http://docs.wxwidgets.org/stable/wx_wxstring.html#<<)")
    // ADD_CLASS_METHOD(operator not available,"wxString wxString::()(size_t start, size_t len) (http://docs.wxwidgets.org/stable/wx_wxstring.html#())")
    ADD_CLASS_METHOD(__add_assign__,            "wxString::operator +=() (http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign___2,            "wxString & wxString::operator +=(wxString const & s) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign___3,            "wxString & wxString::operator +=(wxChar const * psz) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign___4,            "wxString & wxString::operator +=(wxChar ch) (http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__)")




    void AddMethods(WrapClass<wxString>::ptr this_ptr );

};


#endif // _wrap_wxString_h
