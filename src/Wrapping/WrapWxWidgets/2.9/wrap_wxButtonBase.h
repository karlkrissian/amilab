/**
 * C++ Interface: wrap_wxButtonBase
 *
 * Description: wrapping wxButtonBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxButtonBase_h_
#define _wrap_wxButtonBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxControl.h"


AMI_DECLARE_TYPE(wxButtonBase);

// TODO: check for inheritence ...
class WrapClass_wxButtonBase : public WrapClass<wxButtonBase>
    , public   WrapClass_wxControl
{
  DEFINE_CLASS(WrapClass_wxButtonBase);

  protected:
    typedef WrapClass<wxButtonBase>::ptr _parentclass_ptr;
    typedef wxButtonBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxButtonBase>& GetObj() const { return WrapClass<wxButtonBase>::GetObj(); }

    /// Constructor
    WrapClass_wxButtonBase(boost::shared_ptr<wxButtonBase > si): 
    WrapClass<wxButtonBase>(si)
    , WrapClass_wxControl(si)
    {}

    /// Destructor
    ~WrapClass_wxButtonBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxButtonBase,"Constructor wxButtonBase::wxButtonBase() (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#wxbuttonbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxButtonBase*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetAuthNeeded,"void wxButtonBase::SetAuthNeeded(bool show = true)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setauthneeded)")
    ADD_CLASS_METHOD(GetAuthNeeded,"bool wxButtonBase::GetAuthNeeded()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getauthneeded)")
    ADD_CLASS_METHOD(SetBitmap,"void wxButtonBase::SetBitmap(wxBitmap const & bitmap, wxDirection dir = wxLEFT)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmap)")
    ADD_CLASS_METHOD(GetBitmap,"wxBitmap wxButtonBase::GetBitmap()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getbitmap)")
    ADD_CLASS_METHOD(SetBitmapLabel,"void wxButtonBase::SetBitmapLabel(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmaplabel)")
    ADD_CLASS_METHOD(SetBitmapPressed,"void wxButtonBase::SetBitmapPressed(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmappressed)")
    ADD_CLASS_METHOD(SetBitmapDisabled,"void wxButtonBase::SetBitmapDisabled(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmapdisabled)")
    ADD_CLASS_METHOD(SetBitmapCurrent,"void wxButtonBase::SetBitmapCurrent(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmapcurrent)")
    ADD_CLASS_METHOD(SetBitmapFocus,"void wxButtonBase::SetBitmapFocus(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmapfocus)")
    ADD_CLASS_METHOD(GetBitmapLabel,"wxBitmap wxButtonBase::GetBitmapLabel()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getbitmaplabel)")
    ADD_CLASS_METHOD(GetBitmapPressed,"wxBitmap wxButtonBase::GetBitmapPressed()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getbitmappressed)")
    ADD_CLASS_METHOD(GetBitmapDisabled,"wxBitmap wxButtonBase::GetBitmapDisabled()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getbitmapdisabled)")
    ADD_CLASS_METHOD(GetBitmapCurrent,"wxBitmap wxButtonBase::GetBitmapCurrent()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getbitmapcurrent)")
    ADD_CLASS_METHOD(GetBitmapFocus,"wxBitmap wxButtonBase::GetBitmapFocus()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getbitmapfocus)")
    ADD_CLASS_METHOD(SetBitmapMargins_1,"void wxButtonBase::SetBitmapMargins(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmapmargins)")
    ADD_CLASS_METHOD(SetBitmapMargins,"wxButtonBase::SetBitmapMargins()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmapmargins)")
    ADD_CLASS_METHOD(SetBitmapMargins_2,"void wxButtonBase::SetBitmapMargins(wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmapmargins)")
    ADD_CLASS_METHOD(GetBitmapMargins,"wxSize wxButtonBase::GetBitmapMargins()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getbitmapmargins)")
    ADD_CLASS_METHOD(SetBitmapPosition,"void wxButtonBase::SetBitmapPosition(wxDirection dir)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmapposition)")
    ADD_CLASS_METHOD(SetDefault,"wxWindow * wxButtonBase::SetDefault()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setdefault)")
    ADD_CLASS_METHOD(ShouldInheritColours,"bool wxButtonBase::ShouldInheritColours()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#shouldinheritcolours)")
    ADD_CLASS_METHOD(GetDefaultSize,"wxSize wxButtonBase::GetDefaultSize()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getdefaultsize)")
    ADD_CLASS_METHOD(SetImageLabel,"void wxButtonBase::SetImageLabel(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setimagelabel)")
    ADD_CLASS_METHOD(SetImageMargins,"void wxButtonBase::SetImageMargins(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setimagemargins)")
    ADD_CLASS_METHOD(GetBitmapSelected,"wxBitmap wxButtonBase::GetBitmapSelected()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getbitmapselected)")
    ADD_CLASS_METHOD(GetBitmapHover,"wxBitmap wxButtonBase::GetBitmapHover()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getbitmaphover)")
    ADD_CLASS_METHOD(SetBitmapSelected,"void wxButtonBase::SetBitmapSelected(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmapselected)")
    ADD_CLASS_METHOD(SetBitmapHover,"void wxButtonBase::SetBitmapHover(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setbitmaphover)")
    ADD_CLASS_METHOD(DontShowLabel,"bool wxButtonBase::DontShowLabel()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#dontshowlabel)")
    ADD_CLASS_METHOD(ShowsLabel,"bool wxButtonBase::ShowsLabel()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#showslabel)")





    void AddMethods(WrapClass<wxButtonBase>::ptr this_ptr );

};


#endif // _wrap_wxButtonBase_h
