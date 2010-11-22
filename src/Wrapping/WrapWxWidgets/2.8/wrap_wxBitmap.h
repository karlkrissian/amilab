/**
 * C++ Interface: wrap_wxBitmap
 *
 * Description: wrapping wxBitmap
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBitmap_h_
#define _wrap_wxBitmap_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxBitmapBase.h"



AMI_DECLARE_TYPE(wxBitmap);

// TODO: check for inheritence ...
class WrapClass_wxBitmap : public WrapClass<wxBitmap>
    , public   WrapClass_wxBitmapBase
{
  DEFINE_CLASS(WrapClass_wxBitmap);

  protected:
    typedef WrapClass<wxBitmap>::ptr _parentclass_ptr;
    typedef wxBitmap ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBitmap>& GetObj() const { return WrapClass<wxBitmap>::GetObj(); }

    /// Constructor
    WrapClass_wxBitmap(boost::shared_ptr<wxBitmap > si): 
    WrapClass<wxBitmap>(si)
    , WrapClass_wxBitmapBase(si)
    {}

    /// Destructor
    ~WrapClass_wxBitmap()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmap_1,"Constructor wxBitmap::wxBitmap(wxBitmap const & param0) (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#wxbitmap).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmap,"Constructor wxBitmap::wxBitmap() (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#wxbitmap).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmap_2,"Constructor wxBitmap::wxBitmap() (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#wxbitmap).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmap_3,"Constructor wxBitmap::wxBitmap(int width, int height, int depth = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#wxbitmap).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmap_4,"Constructor wxBitmap::wxBitmap(char const * bits, int width, int height, int depth = 1) (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#wxbitmap).");
    /* The following types are missing: char const * const *
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmap_5,"Constructor wxBitmap::wxBitmap(char const * const * bits) (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#wxbitmap).");
    */
    /* The following types are missing: wxBitmapType
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmap_6,"Constructor wxBitmap::wxBitmap(wxString const & filename, wxBitmapType type = wxBITMAP_TYPE_XPM) (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#wxbitmap).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmap_7,"Constructor wxBitmap::wxBitmap(wxImage const & image, int depth = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#wxbitmap).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBitmap*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(InitStandardHandlers,"void wxBitmap::InitStandardHandlers() (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#initstandardhandlers).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxBitmap::Ok()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxBitmap::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#isok)")
    ADD_CLASS_METHOD(Create,"bool wxBitmap::Create(int width, int height, int depth = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#create)")
    ADD_CLASS_METHOD(GetHeight,"int wxBitmap::GetHeight()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getheight)")
    ADD_CLASS_METHOD(GetWidth,"int wxBitmap::GetWidth()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getwidth)")
    ADD_CLASS_METHOD(GetDepth,"int wxBitmap::GetDepth()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getdepth)")
    ADD_CLASS_METHOD(ConvertToImage,"wxImage wxBitmap::ConvertToImage()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#converttoimage)")
    ADD_CLASS_METHOD(CopyFromIcon,"bool wxBitmap::CopyFromIcon(wxIcon const & icon)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#copyfromicon)")
    ADD_CLASS_METHOD(GetMask,"wxMask * wxBitmap::GetMask()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getmask)")
    ADD_CLASS_METHOD(SetMask,"void wxBitmap::SetMask(wxMask * mask)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#setmask)")
    ADD_CLASS_METHOD(GetSubBitmap,"wxBitmap wxBitmap::GetSubBitmap(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getsubbitmap)")
/* The following types are missing: wxBitmapType
    ADD_CLASS_METHOD(SaveFile,"bool wxBitmap::SaveFile(wxString const & name, wxBitmapType type, wxPalette const * palette = 0u)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#savefile)")
*/
/* The following types are missing: wxBitmapType
    ADD_CLASS_METHOD(LoadFile,"bool wxBitmap::LoadFile(wxString const & name, wxBitmapType type = wxBITMAP_TYPE_XPM)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#loadfile)")
*/
    ADD_CLASS_METHOD(GetPalette,"wxPalette * wxBitmap::GetPalette()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getpalette)")
    ADD_CLASS_METHOD(SetPalette,"void wxBitmap::SetPalette(wxPalette const & palette)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#setpalette)")
    ADD_CLASS_METHOD(GetColourMap,"wxPalette * wxBitmap::GetColourMap()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getcolourmap)")
    ADD_CLASS_METHOD(SetHeight,"void wxBitmap::SetHeight(int height)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#setheight)")
    ADD_CLASS_METHOD(SetWidth,"void wxBitmap::SetWidth(int width)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#setwidth)")
    ADD_CLASS_METHOD(SetDepth,"void wxBitmap::SetDepth(int depth)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#setdepth)")
/* The following types are missing: _GdkDrawable
    ADD_CLASS_METHOD(SetPixmap,"void wxBitmap::SetPixmap(GdkPixmap * pixmap)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#setpixmap)")
*/
/* The following types are missing: _GdkPixbuf
    ADD_CLASS_METHOD(SetPixbuf,"void wxBitmap::SetPixbuf(GdkPixbuf * pixbuf, int depth = 0)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#setpixbuf)")
*/
/* The following types are missing: _GdkDrawable
    ADD_CLASS_METHOD(GetPixmap,"GdkPixmap * wxBitmap::GetPixmap()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getpixmap)")
*/
    ADD_CLASS_METHOD(HasPixmap,"bool wxBitmap::HasPixmap()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#haspixmap)")
    ADD_CLASS_METHOD(HasPixbuf,"bool wxBitmap::HasPixbuf()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#haspixbuf)")
/* The following types are missing: _GdkPixbuf
    ADD_CLASS_METHOD(GetPixbuf,"GdkPixbuf * wxBitmap::GetPixbuf()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getpixbuf)")
*/
    ADD_CLASS_METHOD(Rescale,"wxBitmap wxBitmap::Rescale(int clipx, int clipy, int clipwidth, int clipheight, int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#rescale)")
/* The following types are missing: wxPixelDataBase
    ADD_CLASS_METHOD(GetRawData,"void * wxBitmap::GetRawData(wxPixelDataBase & data, int bpp)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getrawdata)")
*/
/* The following types are missing: wxPixelDataBase
    ADD_CLASS_METHOD(UngetRawData,"void wxBitmap::UngetRawData(wxPixelDataBase & data)  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#ungetrawdata)")
*/
    ADD_CLASS_METHOD(HasAlpha,"bool wxBitmap::HasAlpha()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#hasalpha)")
    ADD_CLASS_METHOD(UseAlpha,"void wxBitmap::UseAlpha()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#usealpha)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxBitmap::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxBitmap & wxBitmap::operator =(wxBitmap const & param0) (http://docs.wxwidgets.org/stable/wx_wxbitmap.html#__assign__)")




    void AddMethods(WrapClass<wxBitmap>::ptr this_ptr );

};


#endif // _wrap_wxBitmap_h
