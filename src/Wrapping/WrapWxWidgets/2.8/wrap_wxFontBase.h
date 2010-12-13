/**
 * C++ Interface: wrap_wxFontBase
 *
 * Description: wrapping wxFontBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFontBase_h_
#define _wrap_wxFontBase_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxGDIObject.h"


#ifndef wxFontBase_declared
  #define wxFontBase_declared
  AMI_DECLARE_TYPE(wxFontBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxFontBase : public WrapClass<wxFontBase>
    , public   WrapClass_wxGDIObject
{
  DEFINE_CLASS(WrapClass_wxFontBase);

  protected:
    typedef WrapClass<wxFontBase>::ptr _parentclass_ptr;
    typedef wxFontBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFontBase>& GetObj() const { return WrapClass<wxFontBase>::GetObj(); }

    /// Constructor
    WrapClass_wxFontBase(boost::shared_ptr<wxFontBase > si): 
    WrapClass<wxFontBase>(si)
    , WrapClass_wxGDIObject(si)
    {}

    /// Destructor
    ~WrapClass_wxFontBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFontBase*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New_1,"wxFont * wxFontBase::New(int pointSize, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new).");
    ADD_CLASS_STATICMETHOD(New,"wxFontBase::New() (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new).");
    ADD_CLASS_STATICMETHOD(New_2,"wxFont * wxFontBase::New(int pointSize, wxFontFamily family, int flags = wxFONTFLAG_DEFAULT, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new).");
    ADD_CLASS_STATICMETHOD(New_3,"wxFont * wxFontBase::New(wxSize const & pixelSize, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new).");
    ADD_CLASS_STATICMETHOD(New_4,"wxFont * wxFontBase::New(wxSize const & pixelSize, wxFontFamily family, int flags = wxFONTFLAG_DEFAULT, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new).");
    /* The following types are missing: wxNativeFontInfo
    ADD_CLASS_STATICMETHOD(New_5,"wxFont * wxFontBase::New(wxNativeFontInfo const & nativeFontDesc) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new).");
    */
    ADD_CLASS_STATICMETHOD(New_6,"wxFont * wxFontBase::New(wxString const & strNativeFontDesc) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new).");
    ADD_CLASS_STATICMETHOD(GetDefaultEncoding,"wxFontEncoding wxFontBase::GetDefaultEncoding() (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#getdefaultencoding).");
    ADD_CLASS_STATICMETHOD(SetDefaultEncoding,"void wxFontBase::SetDefaultEncoding(wxFontEncoding encoding) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#setdefaultencoding).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxFontBase::Ok()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxFontBase::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#isok)")
    ADD_CLASS_METHOD(GetPixelSize,"wxSize wxFontBase::GetPixelSize()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#getpixelsize)")
    ADD_CLASS_METHOD(IsUsingSizeInPixels,"bool wxFontBase::IsUsingSizeInPixels()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#isusingsizeinpixels)")
    ADD_CLASS_METHOD(IsFixedWidth,"bool wxFontBase::IsFixedWidth()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#isfixedwidth)")
    ADD_CLASS_METHOD(GetNativeFontInfoDesc,"wxString wxFontBase::GetNativeFontInfoDesc()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#getnativefontinfodesc)")
    ADD_CLASS_METHOD(GetNativeFontInfoUserDesc,"wxString wxFontBase::GetNativeFontInfoUserDesc()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#getnativefontinfouserdesc)")
    ADD_CLASS_METHOD(SetPixelSize,"void wxFontBase::SetPixelSize(wxSize const & pixelSize)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#setpixelsize)")
    ADD_CLASS_METHOD(SetFaceName,"bool wxFontBase::SetFaceName(wxString const & faceName)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#setfacename)")
/* The following types are missing: wxNativeFontInfo
    ADD_CLASS_METHOD(SetNativeFontInfo_1,"void wxFontBase::SetNativeFontInfo(wxNativeFontInfo const & info)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#setnativefontinfo)")
*/
    ADD_CLASS_METHOD(SetNativeFontInfo,"wxFontBase::SetNativeFontInfo()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#setnativefontinfo)")
    ADD_CLASS_METHOD(SetNativeFontInfo_2,"bool wxFontBase::SetNativeFontInfo(wxString const & info)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#setnativefontinfo)")
    ADD_CLASS_METHOD(SetNativeFontInfoUserDesc,"bool wxFontBase::SetNativeFontInfoUserDesc(wxString const & info)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#setnativefontinfouserdesc)")
    ADD_CLASS_METHOD(GetFamilyString,"wxString wxFontBase::GetFamilyString()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#getfamilystring)")
    ADD_CLASS_METHOD(GetStyleString,"wxString wxFontBase::GetStyleString()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#getstylestring)")
    ADD_CLASS_METHOD(GetWeightString,"wxString wxFontBase::GetWeightString()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#getweightstring)")
    ADD_CLASS_METHOD(SetNoAntiAliasing,"void wxFontBase::SetNoAntiAliasing(bool param0 = true)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#setnoantialiasing)")
    ADD_CLASS_METHOD(GetNoAntiAliasing,"bool wxFontBase::GetNoAntiAliasing()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#getnoantialiasing)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxFontBase & wxFontBase::operator =(wxFontBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxFontBase::operator ==(wxFont const & font) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxFontBase::operator !=(wxFont const & font) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#__not_equal__)")




    void AddMethods(WrapClass<wxFontBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxFontBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxFontBase_h
