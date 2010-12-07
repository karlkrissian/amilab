/**
 * C++ Interface: wrap_wxFont
 *
 * Description: wrapping wxFont
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFont_h_
#define _wrap_wxFont_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxFontBase.h"



AMI_DECLARE_TYPE(wxFont);

// TODO: check for inheritence ...
class WrapClass_wxFont : public WrapClass<wxFont>
    , public   WrapClass_wxFontBase
{
  DEFINE_CLASS(WrapClass_wxFont);

  protected:
    typedef WrapClass<wxFont>::ptr _parentclass_ptr;
    typedef wxFont ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFont>& GetObj() const { return WrapClass<wxFont>::GetObj(); }

    /// Constructor
    WrapClass_wxFont(boost::shared_ptr<wxFont > si): 
    WrapClass<wxFont>(si)
    , WrapClass_wxFontBase(si)
    {}

    /// Destructor
    ~WrapClass_wxFont()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont_1,"Constructor wxFont::wxFont(wxFont const & param0) (http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont,"Constructor wxFont::wxFont() (http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont_2,"Constructor wxFont::wxFont() (http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont_3,"Constructor wxFont::wxFont(wxString const & fontname) (http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont).");
    /* The following types are missing: wxNativeFontInfo
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont_4,"Constructor wxFont::wxFont(wxNativeFontInfo const & info) (http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont_5,"Constructor wxFont::wxFont(int size, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT) (http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFont*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Create_1,"bool wxFont::Create(int size, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#create)")
    ADD_CLASS_METHOD(Create,"wxFont::Create()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#create)")
    ADD_CLASS_METHOD(Create_2,"bool wxFont::Create(wxString const & fontname)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#create)")
    ADD_CLASS_METHOD(GetPointSize,"int wxFont::GetPointSize()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getpointsize)")
    ADD_CLASS_METHOD(GetFamily,"int wxFont::GetFamily()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getfamily)")
    ADD_CLASS_METHOD(GetStyle,"int wxFont::GetStyle()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getstyle)")
    ADD_CLASS_METHOD(GetWeight,"int wxFont::GetWeight()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getweight)")
    ADD_CLASS_METHOD(GetFaceName,"wxString wxFont::GetFaceName()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getfacename)")
    ADD_CLASS_METHOD(GetUnderlined,"bool wxFont::GetUnderlined()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getunderlined)")
    ADD_CLASS_METHOD(GetEncoding,"wxFontEncoding wxFont::GetEncoding()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getencoding)")
/* The following types are missing: wxNativeFontInfo
    ADD_CLASS_METHOD(GetNativeFontInfo,"wxNativeFontInfo const * wxFont::GetNativeFontInfo()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getnativefontinfo)")
*/
    ADD_CLASS_METHOD(IsFixedWidth,"bool wxFont::IsFixedWidth()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#isfixedwidth)")
    ADD_CLASS_METHOD(SetPointSize,"void wxFont::SetPointSize(int pointSize)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#setpointsize)")
    ADD_CLASS_METHOD(SetFamily,"void wxFont::SetFamily(int family)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#setfamily)")
    ADD_CLASS_METHOD(SetStyle,"void wxFont::SetStyle(int style)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#setstyle)")
    ADD_CLASS_METHOD(SetWeight,"void wxFont::SetWeight(int weight)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#setweight)")
    ADD_CLASS_METHOD(SetFaceName,"bool wxFont::SetFaceName(wxString const & faceName)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#setfacename)")
    ADD_CLASS_METHOD(SetUnderlined,"void wxFont::SetUnderlined(bool underlined)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#setunderlined)")
    ADD_CLASS_METHOD(SetEncoding,"void wxFont::SetEncoding(wxFontEncoding encoding)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#setencoding)")
    ADD_CLASS_METHOD(SetNoAntiAliasing,"void wxFont::SetNoAntiAliasing(bool no = true)  (http://docs.wxwidgets.org/stable/wx_wxfont.html#setnoantialiasing)")
    ADD_CLASS_METHOD(GetNoAntiAliasing,"bool wxFont::GetNoAntiAliasing()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getnoantialiasing)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxFont::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxfont.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxFont & wxFont::operator =(wxFont const & param0) (http://docs.wxwidgets.org/stable/wx_wxfont.html#__assign__)")




    void AddMethods(WrapClass<wxFont>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxFont_h
