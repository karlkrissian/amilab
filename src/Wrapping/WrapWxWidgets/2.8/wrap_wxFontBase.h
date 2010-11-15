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

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

//#include "wrap_wxGDIObject.h"


AMI_DECLARE_TYPE(wxFontBase);

// TODO: check for inheritence ...
class WrapClass_wxFontBase : public WrapClass<wxFontBase>
    //, public  WrapClass_wxGDIObject
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
    //, WrapClass_wxGDIObject(si)
    {}

    /// Destructor
    ~WrapClass_wxFontBase()
    {
      std::cout << "~WrapClass_wxFontBase()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFontBase*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(New_1,"wxFont * wxFontBase::New(int pointSize, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new)")
    ADD_CLASS_METHOD(New,"wxFontBase::New()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new)")
    ADD_CLASS_METHOD(New_2,"wxFont * wxFontBase::New(int pointSize, wxFontFamily family, int flags = wxFONTFLAG_DEFAULT, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new)")
    ADD_CLASS_METHOD(New_3,"wxFont * wxFontBase::New(wxSize const & pixelSize, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new)")
    ADD_CLASS_METHOD(New_4,"wxFont * wxFontBase::New(wxSize const & pixelSize, wxFontFamily family, int flags = wxFONTFLAG_DEFAULT, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new)")
/* The following types are missing: wxNativeFontInfo
    ADD_CLASS_METHOD(New_5,"wxFont * wxFontBase::New(wxNativeFontInfo const & nativeFontDesc)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new)")
*/
    ADD_CLASS_METHOD(New_6,"wxFont * wxFontBase::New(wxString const & strNativeFontDesc)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#new)")
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
    ADD_CLASS_METHOD(GetDefaultEncoding,"wxFontEncoding wxFontBase::GetDefaultEncoding()  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#getdefaultencoding)")
    ADD_CLASS_METHOD(SetDefaultEncoding,"void wxFontBase::SetDefaultEncoding(wxFontEncoding encoding)  (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#setdefaultencoding)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxFontBase & wxFontBase::=(wxFontBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxFontBase::==(wxFont const & font) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxFontBase::!=(wxFont const & font) (http://docs.wxwidgets.org/stable/wx_wxfontbase.html#__not_equal__)")




    void AddMethods(WrapClass<wxFontBase>::ptr this_ptr )
    {
      /*
      // Add members from wxGDIObject
      WrapClass_wxGDIObject::ptr parent_wxGDIObject(        boost::dynamic_pointer_cast<WrapClass_wxGDIObject >(this_ptr));
      parent_wxGDIObject->AddMethods(parent_wxGDIObject);
      */


      // check that the method name is not a token
      
      // Adding standard methods 
      AddVar_New_1( this_ptr);
      AddVar_New( this_ptr);
      AddVar_New_2( this_ptr);
      AddVar_New_3( this_ptr);
      AddVar_New_4( this_ptr);
/* The following types are missing: wxNativeFontInfo
      AddVar_New_5( this_ptr);
*/
      AddVar_New_6( this_ptr);
      AddVar_Ok( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_GetPixelSize( this_ptr);
      AddVar_IsUsingSizeInPixels( this_ptr);
      AddVar_IsFixedWidth( this_ptr);
      AddVar_GetNativeFontInfoDesc( this_ptr);
      AddVar_GetNativeFontInfoUserDesc( this_ptr);
      AddVar_SetPixelSize( this_ptr);
      AddVar_SetFaceName( this_ptr);
/* The following types are missing: wxNativeFontInfo
      AddVar_SetNativeFontInfo_1( this_ptr);
*/
      AddVar_SetNativeFontInfo( this_ptr);
      AddVar_SetNativeFontInfo_2( this_ptr);
      AddVar_SetNativeFontInfoUserDesc( this_ptr);
      AddVar_GetFamilyString( this_ptr);
      AddVar_GetStyleString( this_ptr);
      AddVar_GetWeightString( this_ptr);
      AddVar_SetNoAntiAliasing( this_ptr);
      AddVar_GetNoAntiAliasing( this_ptr);
      AddVar_GetDefaultEncoding( this_ptr);
      AddVar_SetDefaultEncoding( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___equal__( this_ptr);
      AddVar___not_equal__( this_ptr);



      
    };
};


#endif // _wrap_wxFontBase_h
