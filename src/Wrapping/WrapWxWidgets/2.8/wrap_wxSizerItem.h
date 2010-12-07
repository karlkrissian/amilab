/**
 * C++ Interface: wrap_wxSizerItem
 *
 * Description: wrapping wxSizerItem
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxSizerItem_h_
#define _wrap_wxSizerItem_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxSizerItem);

// TODO: check for inheritence ...
class WrapClass_wxSizerItem : public WrapClass<wxSizerItem>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxSizerItem);

  protected:
    typedef WrapClass<wxSizerItem>::ptr _parentclass_ptr;
    typedef wxSizerItem ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxSizerItem>& GetObj() const { return WrapClass<wxSizerItem>::GetObj(); }

    /// Constructor
    WrapClass_wxSizerItem(boost::shared_ptr<wxSizerItem > si): 
    WrapClass<wxSizerItem>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxSizerItem()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItem_1,"Constructor wxSizerItem::wxSizerItem(wxWindow * window, int proportion, int flag, int border, wxObject * userData) (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#wxsizeritem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItem,"Constructor wxSizerItem::wxSizerItem() (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#wxsizeritem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItem_2,"Constructor wxSizerItem::wxSizerItem(wxWindow * window, wxSizerFlags const & flags) (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#wxsizeritem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItem_3,"Constructor wxSizerItem::wxSizerItem(wxSizer * sizer, int proportion, int flag, int border, wxObject * userData) (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#wxsizeritem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItem_4,"Constructor wxSizerItem::wxSizerItem(wxSizer * sizer, wxSizerFlags const & flags) (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#wxsizeritem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItem_5,"Constructor wxSizerItem::wxSizerItem(int width, int height, int proportion, int flag, int border, wxObject * userData) (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#wxsizeritem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItem_6,"Constructor wxSizerItem::wxSizerItem(int width, int height, wxSizerFlags const & flags) (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#wxsizeritem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItem_7,"Constructor wxSizerItem::wxSizerItem() (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#wxsizeritem).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSizerItem*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(DeleteWindows,"void wxSizerItem::DeleteWindows()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#deletewindows)")
    ADD_CLASS_METHOD(DetachSizer,"void wxSizerItem::DetachSizer()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#detachsizer)")
    ADD_CLASS_METHOD(GetSize,"wxSize wxSizerItem::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getsize)")
    ADD_CLASS_METHOD(CalcMin,"wxSize wxSizerItem::CalcMin()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#calcmin)")
    ADD_CLASS_METHOD(SetDimension,"void wxSizerItem::SetDimension(wxPoint const & pos, wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setdimension)")
    ADD_CLASS_METHOD(GetMinSize,"wxSize wxSizerItem::GetMinSize()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getminsize)")
    ADD_CLASS_METHOD(GetMinSizeWithBorder,"wxSize wxSizerItem::GetMinSizeWithBorder()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getminsizewithborder)")
    ADD_CLASS_METHOD(SetMinSize_1,"void wxSizerItem::SetMinSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setminsize)")
    ADD_CLASS_METHOD(SetMinSize,"wxSizerItem::SetMinSize()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setminsize)")
    ADD_CLASS_METHOD(SetMinSize_2,"void wxSizerItem::SetMinSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setminsize)")
    ADD_CLASS_METHOD(SetInitSize,"void wxSizerItem::SetInitSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setinitsize)")
    ADD_CLASS_METHOD(SetRatio_1,"void wxSizerItem::SetRatio(int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setratio)")
    ADD_CLASS_METHOD(SetRatio,"wxSizerItem::SetRatio()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setratio)")
    ADD_CLASS_METHOD(SetRatio_2,"void wxSizerItem::SetRatio(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setratio)")
    ADD_CLASS_METHOD(SetRatio_3,"void wxSizerItem::SetRatio(float ratio)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setratio)")
    ADD_CLASS_METHOD(GetRatio,"float wxSizerItem::GetRatio()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getratio)")
    ADD_CLASS_METHOD(GetRect,"wxRect wxSizerItem::GetRect()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getrect)")
    ADD_CLASS_METHOD(IsWindow,"bool wxSizerItem::IsWindow()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#iswindow)")
    ADD_CLASS_METHOD(IsSizer,"bool wxSizerItem::IsSizer()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#issizer)")
    ADD_CLASS_METHOD(IsSpacer,"bool wxSizerItem::IsSpacer()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#isspacer)")
    ADD_CLASS_METHOD(SetProportion,"void wxSizerItem::SetProportion(int proportion)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setproportion)")
    ADD_CLASS_METHOD(GetProportion,"int wxSizerItem::GetProportion()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getproportion)")
    ADD_CLASS_METHOD(SetFlag,"void wxSizerItem::SetFlag(int flag)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setflag)")
    ADD_CLASS_METHOD(GetFlag,"int wxSizerItem::GetFlag()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getflag)")
    ADD_CLASS_METHOD(SetBorder,"void wxSizerItem::SetBorder(int border)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setborder)")
    ADD_CLASS_METHOD(GetBorder,"int wxSizerItem::GetBorder()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getborder)")
    ADD_CLASS_METHOD(GetWindow,"wxWindow * wxSizerItem::GetWindow()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getwindow)")
    ADD_CLASS_METHOD(GetSizer,"wxSizer * wxSizerItem::GetSizer()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getsizer)")
    ADD_CLASS_METHOD(GetSpacer,"wxSize wxSizerItem::GetSpacer()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getspacer)")
    ADD_CLASS_METHOD(IsShown,"bool wxSizerItem::IsShown()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#isshown)")
    ADD_CLASS_METHOD(Show,"void wxSizerItem::Show(bool show)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#show)")
    ADD_CLASS_METHOD(SetUserData,"void wxSizerItem::SetUserData(wxObject * userData)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setuserdata)")
    ADD_CLASS_METHOD(GetUserData,"wxObject * wxSizerItem::GetUserData()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getuserdata)")
    ADD_CLASS_METHOD(GetPosition,"wxPoint wxSizerItem::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getposition)")
    ADD_CLASS_METHOD(SetWindow,"void wxSizerItem::SetWindow(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setwindow)")
    ADD_CLASS_METHOD(SetSizer,"void wxSizerItem::SetSizer(wxSizer * sizer)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setsizer)")
    ADD_CLASS_METHOD(SetSpacer_1,"void wxSizerItem::SetSpacer(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setspacer)")
    ADD_CLASS_METHOD(SetSpacer,"wxSizerItem::SetSpacer()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setspacer)")
    ADD_CLASS_METHOD(SetSpacer_2,"void wxSizerItem::SetSpacer(int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#setspacer)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxSizerItem::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxsizeritem.html#getclassinfo)")





    void AddMethods(WrapClass<wxSizerItem>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxSizerItem_h
