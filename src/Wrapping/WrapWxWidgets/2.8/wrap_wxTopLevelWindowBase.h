/**
 * C++ Interface: wrap_wxTopLevelWindowBase
 *
 * Description: wrapping wxTopLevelWindowBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxTopLevelWindowBase_h_
#define _wrap_wxTopLevelWindowBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWindow.h"



AMI_DECLARE_TYPE(wxTopLevelWindowBase);

// TODO: check for inheritence ...
class WrapClass_wxTopLevelWindowBase : public WrapClass<wxTopLevelWindowBase>
    , public   WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxTopLevelWindowBase);

  protected:
    typedef WrapClass<wxTopLevelWindowBase>::ptr _parentclass_ptr;
    typedef wxTopLevelWindowBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxTopLevelWindowBase>& GetObj() const { return WrapClass<wxTopLevelWindowBase>::GetObj(); }

    /// Constructor
    WrapClass_wxTopLevelWindowBase(boost::shared_ptr<wxTopLevelWindowBase > si): 
    WrapClass<wxTopLevelWindowBase>(si)
    , WrapClass_wxWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxTopLevelWindowBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxTopLevelWindowBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsAlwaysMaximized,"bool wxTopLevelWindowBase::IsAlwaysMaximized()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#isalwaysmaximized)")
    ADD_CLASS_METHOD(GetIcon,"wxIcon const & wxTopLevelWindowBase::GetIcon()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#geticon)")
    ADD_CLASS_METHOD(GetIcons,"wxIconBundle const & wxTopLevelWindowBase::GetIcons()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#geticons)")
    ADD_CLASS_METHOD(SetIcon,"void wxTopLevelWindowBase::SetIcon(wxIcon const & icon)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#seticon)")
    ADD_CLASS_METHOD(SetIcons,"void wxTopLevelWindowBase::SetIcons(wxIconBundle const & icons)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#seticons)")
    ADD_CLASS_METHOD(EnableCloseButton,"bool wxTopLevelWindowBase::EnableCloseButton(bool param0)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#enableclosebutton)")
    ADD_CLASS_METHOD(SetShape,"bool wxTopLevelWindowBase::SetShape(wxRegion const & param0)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#setshape)")
    ADD_CLASS_METHOD(RequestUserAttention,"void wxTopLevelWindowBase::RequestUserAttention(int flags = wxUSER_ATTENTION_INFO)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#requestuserattention)")
    ADD_CLASS_METHOD(IsActive,"bool wxTopLevelWindowBase::IsActive()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#isactive)")
    ADD_CLASS_METHOD(ShouldPreventAppExit,"bool wxTopLevelWindowBase::ShouldPreventAppExit()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#shouldpreventappexit)")
    ADD_CLASS_METHOD(CentreOnScreen,"void wxTopLevelWindowBase::CentreOnScreen(int dir = wxBOTH)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#centreonscreen)")
    ADD_CLASS_METHOD(CenterOnScreen,"void wxTopLevelWindowBase::CenterOnScreen(int dir = wxBOTH)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#centeronscreen)")
    ADD_CLASS_METHOD(RemoveChild,"void wxTopLevelWindowBase::RemoveChild(wxWindowBase * child)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#removechild)")
    ADD_CLASS_METHOD(GetDefaultItem,"wxWindow * wxTopLevelWindowBase::GetDefaultItem()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#getdefaultitem)")
    ADD_CLASS_METHOD(SetDefaultItem,"wxWindow * wxTopLevelWindowBase::SetDefaultItem(wxWindow * win)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#setdefaultitem)")
    ADD_CLASS_METHOD(GetTmpDefaultItem,"wxWindow * wxTopLevelWindowBase::GetTmpDefaultItem()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#gettmpdefaultitem)")
    ADD_CLASS_METHOD(SetTmpDefaultItem,"wxWindow * wxTopLevelWindowBase::SetTmpDefaultItem(wxWindow * win)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#settmpdefaultitem)")
    ADD_CLASS_METHOD(Destroy,"bool wxTopLevelWindowBase::Destroy()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#destroy)")
    ADD_CLASS_METHOD(IsTopLevel,"bool wxTopLevelWindowBase::IsTopLevel()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#istoplevel)")
    ADD_CLASS_METHOD(IsVisible,"bool wxTopLevelWindowBase::IsVisible()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#isvisible)")
    ADD_CLASS_METHOD(OnCloseWindow,"void wxTopLevelWindowBase::OnCloseWindow(wxCloseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#onclosewindow)")
    ADD_CLASS_METHOD(OnSize,"void wxTopLevelWindowBase::OnSize(wxSizeEvent & param0)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#onsize)")
    ADD_CLASS_METHOD(GetRectForTopLevelChildren,"void wxTopLevelWindowBase::GetRectForTopLevelChildren(int * x, int * y, int * w, int * h)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#getrectfortoplevelchildren)")
    ADD_CLASS_METHOD(OnActivate,"void wxTopLevelWindowBase::OnActivate(wxActivateEvent & param0)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#onactivate)")
    ADD_CLASS_METHOD(DoUpdateWindowUI,"void wxTopLevelWindowBase::DoUpdateWindowUI(wxUpdateUIEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#doupdatewindowui)")
    ADD_CLASS_METHOD(SetMinSize,"void wxTopLevelWindowBase::SetMinSize(wxSize const & minSize)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#setminsize)")
    ADD_CLASS_METHOD(SetMaxSize,"void wxTopLevelWindowBase::SetMaxSize(wxSize const & maxSize)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#setmaxsize)")
    ADD_CLASS_METHOD(DoSetSizeHints,"void wxTopLevelWindowBase::DoSetSizeHints(int minW, int minH, int maxW = wxDefaultCoord, int maxH = wxDefaultCoord, int incW = wxDefaultCoord, int incH = wxDefaultCoord)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#dosetsizehints)")





    void AddMethods(WrapClass<wxTopLevelWindowBase>::ptr this_ptr );

};


#endif // _wrap_wxTopLevelWindowBase_h
