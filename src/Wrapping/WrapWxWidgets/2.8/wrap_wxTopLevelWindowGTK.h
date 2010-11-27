/**
 * C++ Interface: wrap_wxTopLevelWindowGTK
 *
 * Description: wrapping wxTopLevelWindowGTK
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxTopLevelWindowGTK_h_
#define _wrap_wxTopLevelWindowGTK_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxTopLevelWindowBase.h"



AMI_DECLARE_TYPE(wxTopLevelWindowGTK);

// TODO: check for inheritence ...
class WrapClass_wxTopLevelWindowGTK : public WrapClass<wxTopLevelWindowGTK>
    , public   WrapClass_wxTopLevelWindowBase
{
  DEFINE_CLASS(WrapClass_wxTopLevelWindowGTK);

  protected:
    typedef WrapClass<wxTopLevelWindowGTK>::ptr _parentclass_ptr;
    typedef wxTopLevelWindowGTK ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxTopLevelWindowGTK>& GetObj() const { return WrapClass<wxTopLevelWindowGTK>::GetObj(); }

    /// Constructor
    WrapClass_wxTopLevelWindowGTK(boost::shared_ptr<wxTopLevelWindowGTK > si): 
    WrapClass<wxTopLevelWindowGTK>(si)
    , WrapClass_wxTopLevelWindowBase(si)
    {}

    /// Destructor
    ~WrapClass_wxTopLevelWindowGTK()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTopLevelWindowGTK_1,"Constructor wxTopLevelWindowGTK::wxTopLevelWindowGTK() (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#wxtoplevelwindowgtk).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTopLevelWindowGTK,"Constructor wxTopLevelWindowGTK::wxTopLevelWindowGTK() (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#wxtoplevelwindowgtk).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTopLevelWindowGTK_2,"Constructor wxTopLevelWindowGTK::wxTopLevelWindowGTK(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr) (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#wxtoplevelwindowgtk).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxTopLevelWindowGTK*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxTopLevelWindowGTK::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#create)")
    ADD_CLASS_METHOD(Maximize,"void wxTopLevelWindowGTK::Maximize(bool maximize = true)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#maximize)")
    ADD_CLASS_METHOD(IsMaximized,"bool wxTopLevelWindowGTK::IsMaximized()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#ismaximized)")
    ADD_CLASS_METHOD(Iconize,"void wxTopLevelWindowGTK::Iconize(bool iconize = true)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#iconize)")
    ADD_CLASS_METHOD(IsIconized,"bool wxTopLevelWindowGTK::IsIconized()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#isiconized)")
    ADD_CLASS_METHOD(SetIcon,"void wxTopLevelWindowGTK::SetIcon(wxIcon const & icon)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#seticon)")
    ADD_CLASS_METHOD(SetIcons,"void wxTopLevelWindowGTK::SetIcons(wxIconBundle const & icons)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#seticons)")
    ADD_CLASS_METHOD(Restore,"void wxTopLevelWindowGTK::Restore()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#restore)")
    ADD_CLASS_METHOD(EnableCloseButton,"bool wxTopLevelWindowGTK::EnableCloseButton(bool enable = true)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#enableclosebutton)")
    ADD_CLASS_METHOD(ShowFullScreen,"bool wxTopLevelWindowGTK::ShowFullScreen(bool show, long int style = wxFULLSCREEN_ALL)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#showfullscreen)")
    ADD_CLASS_METHOD(IsFullScreen,"bool wxTopLevelWindowGTK::IsFullScreen()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#isfullscreen)")
    ADD_CLASS_METHOD(SetShape,"bool wxTopLevelWindowGTK::SetShape(wxRegion const & region)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#setshape)")
    ADD_CLASS_METHOD(RequestUserAttention,"void wxTopLevelWindowGTK::RequestUserAttention(int flags = wxUSER_ATTENTION_INFO)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#requestuserattention)")
    ADD_CLASS_METHOD(SetWindowStyleFlag,"void wxTopLevelWindowGTK::SetWindowStyleFlag(long int style)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#setwindowstyleflag)")
    ADD_CLASS_METHOD(Show,"bool wxTopLevelWindowGTK::Show(bool show = true)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#show)")
    ADD_CLASS_METHOD(Raise,"void wxTopLevelWindowGTK::Raise()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#raise)")
    ADD_CLASS_METHOD(IsActive,"bool wxTopLevelWindowGTK::IsActive()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#isactive)")
    ADD_CLASS_METHOD(SetTitle,"void wxTopLevelWindowGTK::SetTitle(wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#settitle)")
    ADD_CLASS_METHOD(GetTitle,"wxString wxTopLevelWindowGTK::GetTitle()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#gettitle)")
    ADD_CLASS_METHOD(SetTransparent,"bool wxTopLevelWindowGTK::SetTransparent(wxByte alpha)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#settransparent)")
    ADD_CLASS_METHOD(CanSetTransparent,"bool wxTopLevelWindowGTK::CanSetTransparent()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#cansettransparent)")
    ADD_CLASS_METHOD(AddGrab,"void wxTopLevelWindowGTK::AddGrab()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#addgrab)")
    ADD_CLASS_METHOD(RemoveGrab,"void wxTopLevelWindowGTK::RemoveGrab()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#removegrab)")
    ADD_CLASS_METHOD(IsGrabbed,"bool wxTopLevelWindowGTK::IsGrabbed()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#isgrabbed)")
    ADD_CLASS_METHOD(GtkOnSize,"void wxTopLevelWindowGTK::GtkOnSize()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#gtkonsize)")
    ADD_CLASS_METHOD(OnInternalIdle,"void wxTopLevelWindowGTK::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#oninternalidle)")
    ADD_CLASS_METHOD(SetIconizeState,"void wxTopLevelWindowGTK::SetIconizeState(bool iconic)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#seticonizestate)")
    ADD_CLASS_METHOD(DoSetSizeHints,"void wxTopLevelWindowGTK::DoSetSizeHints(int minW, int minH, int maxW = wxDefaultCoord, int maxH = wxDefaultCoord, int incW = wxDefaultCoord, int incH = wxDefaultCoord)  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowgtk.html#dosetsizehints)")





    void AddMethods(WrapClass<wxTopLevelWindowGTK>::ptr this_ptr );

};


#endif // _wrap_wxTopLevelWindowGTK_h
