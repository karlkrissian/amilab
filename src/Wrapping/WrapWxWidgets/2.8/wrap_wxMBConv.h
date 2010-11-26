/**
 * C++ Interface: wrap_wxMBConv
 *
 * Description: wrapping wxMBConv
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMBConv_h_
#define _wrap_wxMBConv_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxMBConv);

// TODO: check for inheritence ...
class WrapClass_wxMBConv : public WrapClass<wxMBConv>
    
{
  DEFINE_CLASS(WrapClass_wxMBConv);

  protected:
    typedef WrapClass<wxMBConv>::ptr _parentclass_ptr;
    typedef wxMBConv ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMBConv>& GetObj() const { return WrapClass<wxMBConv>::GetObj(); }

    /// Constructor
    WrapClass_wxMBConv(boost::shared_ptr<wxMBConv > si): 
    WrapClass<wxMBConv>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxMBConv()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMBConv*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(GetMaxMBNulLen,"size_t wxMBConv::GetMaxMBNulLen() (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#getmaxmbnullen).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(ToWChar,"size_t wxMBConv::ToWChar(wchar_t * dst, size_t dstLen, char const * src, size_t srcLen = -1u)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#towchar)")
    ADD_CLASS_METHOD(FromWChar,"size_t wxMBConv::FromWChar(char * dst, size_t dstLen, wchar_t const * src, size_t srcLen = -1u)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#fromwchar)")
    ADD_CLASS_METHOD(cMB2WC_1,"wxWCharBuffer const wxMBConv::cMB2WC(char const * in)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cmb2wc)")
    ADD_CLASS_METHOD(cWC2MB_1,"wxCharBuffer const wxMBConv::cWC2MB(wchar_t const * in)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwc2mb)")
    ADD_CLASS_METHOD(cMB2WC,"wxMBConv::cMB2WC()  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cmb2wc)")
    ADD_CLASS_METHOD(cMB2WC_2,"wxWCharBuffer const wxMBConv::cMB2WC(char const * in, size_t inLen, size_t * outLen)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cmb2wc)")
    ADD_CLASS_METHOD(cWC2MB,"wxMBConv::cWC2MB()  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwc2mb)")
    ADD_CLASS_METHOD(cWC2MB_2,"wxCharBuffer const wxMBConv::cWC2MB(wchar_t const * in, size_t inLen, size_t * outLen)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwc2mb)")
    ADD_CLASS_METHOD(cMB2WX,"wxWCharBuffer const wxMBConv::cMB2WX(char const * psz)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cmb2wx)")
    ADD_CLASS_METHOD(cWX2MB,"wxCharBuffer const wxMBConv::cWX2MB(wchar_t const * psz)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwx2mb)")
    ADD_CLASS_METHOD(cWC2WX,"wchar_t const * wxMBConv::cWC2WX(wchar_t const * psz)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwc2wx)")
    ADD_CLASS_METHOD(cWX2WC,"wchar_t const * wxMBConv::cWX2WC(wchar_t const * psz)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwx2wc)")
    ADD_CLASS_METHOD(GetMBNulLen,"size_t wxMBConv::GetMBNulLen()  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#getmbnullen)")
    ADD_CLASS_METHOD(MB2WC,"size_t wxMBConv::MB2WC(wchar_t * out, char const * in, size_t outLen)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#mb2wc)")
    ADD_CLASS_METHOD(WC2MB,"size_t wxMBConv::WC2MB(char * out, wchar_t const * in, size_t outLen)  (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#wc2mb)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxMBConv & wxMBConv::operator =(wxMBConv const & param0) (http://docs.wxwidgets.org/stable/wx_wxmbconv.html#__assign__)")




    void AddMethods(WrapClass<wxMBConv>::ptr this_ptr );

};


#endif // _wrap_wxMBConv_h
