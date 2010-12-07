/**
 * C++ Interface: wrap_wxAuiToolBarItem
 *
 * Description: wrapping wxAuiToolBarItem
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiToolBarItem_h_
#define _wrap_wxAuiToolBarItem_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxAuiToolBarItem);

// TODO: check for inheritence ...
class WrapClass_wxAuiToolBarItem : public WrapClass<wxAuiToolBarItem>
    
{
  DEFINE_CLASS(WrapClass_wxAuiToolBarItem);

  protected:
    typedef WrapClass<wxAuiToolBarItem>::ptr _parentclass_ptr;
    typedef wxAuiToolBarItem ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiToolBarItem>& GetObj() const { return WrapClass<wxAuiToolBarItem>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiToolBarItem(boost::shared_ptr<wxAuiToolBarItem > si): 
    WrapClass<wxAuiToolBarItem>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAuiToolBarItem()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItem_1,"Constructor wxAuiToolBarItem::wxAuiToolBarItem() (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#wxauitoolbaritem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItem,"Constructor wxAuiToolBarItem::wxAuiToolBarItem() (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#wxauitoolbaritem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItem_2,"Constructor wxAuiToolBarItem::wxAuiToolBarItem(wxAuiToolBarItem const & c) (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#wxauitoolbaritem).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiToolBarItem*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Assign,"void wxAuiToolBarItem::Assign(wxAuiToolBarItem const & c)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#assign)")
    ADD_CLASS_METHOD(SetWindow,"void wxAuiToolBarItem::SetWindow(wxWindow * w)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setwindow)")
    ADD_CLASS_METHOD(GetWindow,"wxWindow * wxAuiToolBarItem::GetWindow()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getwindow)")
    ADD_CLASS_METHOD(SetId,"void wxAuiToolBarItem::SetId(int new_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setid)")
    ADD_CLASS_METHOD(GetId,"int wxAuiToolBarItem::GetId()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getid)")
    ADD_CLASS_METHOD(SetKind,"void wxAuiToolBarItem::SetKind(int new_kind)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setkind)")
    ADD_CLASS_METHOD(GetKind,"int wxAuiToolBarItem::GetKind()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getkind)")
    ADD_CLASS_METHOD(SetState,"void wxAuiToolBarItem::SetState(int new_state)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setstate)")
    ADD_CLASS_METHOD(GetState,"int wxAuiToolBarItem::GetState()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getstate)")
    ADD_CLASS_METHOD(SetSizerItem,"void wxAuiToolBarItem::SetSizerItem(wxSizerItem * s)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setsizeritem)")
    ADD_CLASS_METHOD(GetSizerItem,"wxSizerItem * wxAuiToolBarItem::GetSizerItem()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getsizeritem)")
    ADD_CLASS_METHOD(SetLabel,"void wxAuiToolBarItem::SetLabel(wxString const & s)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setlabel)")
    ADD_CLASS_METHOD(GetLabel,"wxString const & wxAuiToolBarItem::GetLabel()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getlabel)")
    ADD_CLASS_METHOD(SetBitmap,"void wxAuiToolBarItem::SetBitmap(wxBitmap const & bmp)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setbitmap)")
    ADD_CLASS_METHOD(GetBitmap,"wxBitmap const & wxAuiToolBarItem::GetBitmap()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getbitmap)")
    ADD_CLASS_METHOD(SetDisabledBitmap,"void wxAuiToolBarItem::SetDisabledBitmap(wxBitmap const & bmp)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setdisabledbitmap)")
    ADD_CLASS_METHOD(GetDisabledBitmap,"wxBitmap const & wxAuiToolBarItem::GetDisabledBitmap()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getdisabledbitmap)")
    ADD_CLASS_METHOD(SetHoverBitmap,"void wxAuiToolBarItem::SetHoverBitmap(wxBitmap const & bmp)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#sethoverbitmap)")
    ADD_CLASS_METHOD(GetHoverBitmap,"wxBitmap const & wxAuiToolBarItem::GetHoverBitmap()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#gethoverbitmap)")
    ADD_CLASS_METHOD(SetShortHelp,"void wxAuiToolBarItem::SetShortHelp(wxString const & s)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setshorthelp)")
    ADD_CLASS_METHOD(GetShortHelp,"wxString const & wxAuiToolBarItem::GetShortHelp()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getshorthelp)")
    ADD_CLASS_METHOD(SetLongHelp,"void wxAuiToolBarItem::SetLongHelp(wxString const & s)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setlonghelp)")
    ADD_CLASS_METHOD(GetLongHelp,"wxString const & wxAuiToolBarItem::GetLongHelp()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getlonghelp)")
    ADD_CLASS_METHOD(SetMinSize,"void wxAuiToolBarItem::SetMinSize(wxSize const & s)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setminsize)")
    ADD_CLASS_METHOD(GetMinSize,"wxSize const & wxAuiToolBarItem::GetMinSize()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getminsize)")
    ADD_CLASS_METHOD(SetSpacerPixels,"void wxAuiToolBarItem::SetSpacerPixels(int s)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setspacerpixels)")
    ADD_CLASS_METHOD(GetSpacerPixels,"int wxAuiToolBarItem::GetSpacerPixels()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getspacerpixels)")
    ADD_CLASS_METHOD(SetProportion,"void wxAuiToolBarItem::SetProportion(int p)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setproportion)")
    ADD_CLASS_METHOD(GetProportion,"int wxAuiToolBarItem::GetProportion()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getproportion)")
    ADD_CLASS_METHOD(SetActive,"void wxAuiToolBarItem::SetActive(bool b)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setactive)")
    ADD_CLASS_METHOD(IsActive,"bool wxAuiToolBarItem::IsActive()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#isactive)")
    ADD_CLASS_METHOD(SetHasDropDown,"void wxAuiToolBarItem::SetHasDropDown(bool b)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#sethasdropdown)")
    ADD_CLASS_METHOD(HasDropDown,"bool wxAuiToolBarItem::HasDropDown()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#hasdropdown)")
    ADD_CLASS_METHOD(SetSticky,"void wxAuiToolBarItem::SetSticky(bool b)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setsticky)")
    ADD_CLASS_METHOD(IsSticky,"bool wxAuiToolBarItem::IsSticky()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#issticky)")
    ADD_CLASS_METHOD(SetUserData,"void wxAuiToolBarItem::SetUserData(long int l)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#setuserdata)")
    ADD_CLASS_METHOD(GetUserData,"long int wxAuiToolBarItem::GetUserData()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#getuserdata)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxAuiToolBarItem & wxAuiToolBarItem::operator =(wxAuiToolBarItem const & c) (http://docs.wxwidgets.org/stable/wx_wxauitoolbaritem.html#__assign__)")




    void AddMethods(WrapClass<wxAuiToolBarItem>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxAuiToolBarItem_h
