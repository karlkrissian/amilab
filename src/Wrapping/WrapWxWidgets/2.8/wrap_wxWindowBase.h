/**
 * C++ Interface: wrap_wxWindowBase
 *
 * Description: wrapping wxWindowBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxWindowBase_h_
#define _wrap_wxWindowBase_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvtHandler.h"


#ifndef wxWindowBase_declared
  #define wxWindowBase_declared
  AMI_DECLARE_TYPE(wxWindowBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxWindowBase : public WrapClass<wxWindowBase>
    , public   WrapClass_wxEvtHandler
{
  DEFINE_CLASS(WrapClass_wxWindowBase);

  protected:
    typedef WrapClass<wxWindowBase>::ptr _parentclass_ptr;
    typedef wxWindowBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxWindowBase>& GetObj() const { return WrapClass<wxWindowBase>::GetObj(); }

    /// Constructor
    WrapClass_wxWindowBase(boost::shared_ptr<wxWindowBase > si): 
    WrapClass<wxWindowBase>(si)
    , WrapClass_wxEvtHandler(si)
    {}

    /// Destructor
    ~WrapClass_wxWindowBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxWindowBase*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(NewControlId,"int wxWindowBase::NewControlId() (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#newcontrolid).");
    ADD_CLASS_STATICMETHOD(NextControlId,"int wxWindowBase::NextControlId(int winid) (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#nextcontrolid).");
    ADD_CLASS_STATICMETHOD(PrevControlId,"int wxWindowBase::PrevControlId(int winid) (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#prevcontrolid).");
    ADD_CLASS_STATICMETHOD(FindFocus,"wxWindow * wxWindowBase::FindFocus() (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#findfocus).");
    ADD_CLASS_STATICMETHOD(DoFindFocus,"wxWindow * wxWindowBase::DoFindFocus() (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#dofindfocus).");
    ADD_CLASS_STATICMETHOD(FindWindowById,"wxWindow * wxWindowBase::FindWindowById(long int winid, wxWindow const * parent = 0l) (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#findwindowbyid).");
    ADD_CLASS_STATICMETHOD(FindWindowByName,"wxWindow * wxWindowBase::FindWindowByName(wxString const & name, wxWindow const * parent = 0l) (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#findwindowbyname).");
    ADD_CLASS_STATICMETHOD(FindWindowByLabel,"wxWindow * wxWindowBase::FindWindowByLabel(wxString const & label, wxWindow const * parent = 0l) (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#findwindowbylabel).");
    ADD_CLASS_STATICMETHOD(GetCapture,"wxWindow * wxWindowBase::GetCapture() (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getcapture).");
    ADD_CLASS_STATICMETHOD(GetClassDefaultAttributes,"wxVisualAttributes wxWindowBase::GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL) (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getclassdefaultattributes).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(CreateBase,"bool wxWindowBase::CreateBase(wxWindowBase * parent, wxWindowID winid, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxPanelNameStr)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#createbase)")
    ADD_CLASS_METHOD(Close,"bool wxWindowBase::Close(bool force = false)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#close)")
    ADD_CLASS_METHOD(Destroy,"bool wxWindowBase::Destroy()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#destroy)")
    ADD_CLASS_METHOD(DestroyChildren,"bool wxWindowBase::DestroyChildren()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#destroychildren)")
    ADD_CLASS_METHOD(IsBeingDeleted,"bool wxWindowBase::IsBeingDeleted()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isbeingdeleted)")
    ADD_CLASS_METHOD(SetName,"void wxWindowBase::SetName(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setname)")
    ADD_CLASS_METHOD(GetName,"wxString wxWindowBase::GetName()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getname)")
    ADD_CLASS_METHOD(SetWindowVariant,"void wxWindowBase::SetWindowVariant(wxWindowVariant variant)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setwindowvariant)")
    ADD_CLASS_METHOD(GetWindowVariant,"wxWindowVariant wxWindowBase::GetWindowVariant()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getwindowvariant)")
    ADD_CLASS_METHOD(SetId,"void wxWindowBase::SetId(wxWindowID winid)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setid)")
    ADD_CLASS_METHOD(GetId,"wxWindowID wxWindowBase::GetId()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getid)")
    ADD_CLASS_METHOD(GetLayoutDirection,"wxLayoutDirection wxWindowBase::GetLayoutDirection()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getlayoutdirection)")
    ADD_CLASS_METHOD(SetLayoutDirection,"void wxWindowBase::SetLayoutDirection(wxLayoutDirection param0)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setlayoutdirection)")
    ADD_CLASS_METHOD(AdjustForLayoutDirection,"wxCoord wxWindowBase::AdjustForLayoutDirection(wxCoord x, wxCoord width, wxCoord widthTotal)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#adjustforlayoutdirection)")
    ADD_CLASS_METHOD(SetSize_1,"void wxWindowBase::SetSize(int x, int y, int width, int height, int sizeFlags = 3)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsize)")
    ADD_CLASS_METHOD(SetSize,"wxWindowBase::SetSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsize)")
    ADD_CLASS_METHOD(SetSize_2,"void wxWindowBase::SetSize(int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsize)")
    ADD_CLASS_METHOD(SetSize_3,"void wxWindowBase::SetSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsize)")
    ADD_CLASS_METHOD(SetSize_4,"void wxWindowBase::SetSize(wxRect const & rect, int sizeFlags = 3)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsize)")
    ADD_CLASS_METHOD(Move_1,"void wxWindowBase::Move(int x, int y, int flags = 0)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#move)")
    ADD_CLASS_METHOD(Move,"wxWindowBase::Move()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#move)")
    ADD_CLASS_METHOD(Move_2,"void wxWindowBase::Move(wxPoint const & pt, int flags = 0)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#move)")
    ADD_CLASS_METHOD(SetPosition,"void wxWindowBase::SetPosition(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setposition)")
    ADD_CLASS_METHOD(SetClientSize_1,"void wxWindowBase::SetClientSize(int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setclientsize)")
    ADD_CLASS_METHOD(SetClientSize,"wxWindowBase::SetClientSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setclientsize)")
    ADD_CLASS_METHOD(SetClientSize_2,"void wxWindowBase::SetClientSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setclientsize)")
    ADD_CLASS_METHOD(SetClientSize_3,"void wxWindowBase::SetClientSize(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setclientsize)")
    ADD_CLASS_METHOD(GetPosition_1,"void wxWindowBase::GetPosition(int * x, int * y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getposition)")
    ADD_CLASS_METHOD(GetPosition,"wxWindowBase::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_2,"wxPoint wxWindowBase::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getposition)")
    ADD_CLASS_METHOD(GetScreenPosition_1,"void wxWindowBase::GetScreenPosition(int * x, int * y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getscreenposition)")
    ADD_CLASS_METHOD(GetScreenPosition,"wxWindowBase::GetScreenPosition()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getscreenposition)")
    ADD_CLASS_METHOD(GetScreenPosition_2,"wxPoint wxWindowBase::GetScreenPosition()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getscreenposition)")
    ADD_CLASS_METHOD(GetSize_1,"void wxWindowBase::GetSize(int * w, int * h)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getsize)")
    ADD_CLASS_METHOD(GetSize,"wxWindowBase::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getsize)")
    ADD_CLASS_METHOD(GetSize_2,"wxSize wxWindowBase::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getsize)")
    ADD_CLASS_METHOD(GetClientSize_1,"void wxWindowBase::GetClientSize(int * w, int * h)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getclientsize)")
    ADD_CLASS_METHOD(GetClientSize,"wxWindowBase::GetClientSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getclientsize)")
    ADD_CLASS_METHOD(GetClientSize_2,"wxSize wxWindowBase::GetClientSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getclientsize)")
    ADD_CLASS_METHOD(GetRect,"wxRect wxWindowBase::GetRect()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getrect)")
    ADD_CLASS_METHOD(GetScreenRect,"wxRect wxWindowBase::GetScreenRect()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getscreenrect)")
    ADD_CLASS_METHOD(GetClientAreaOrigin,"wxPoint wxWindowBase::GetClientAreaOrigin()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getclientareaorigin)")
    ADD_CLASS_METHOD(GetClientRect,"wxRect wxWindowBase::GetClientRect()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getclientrect)")
    ADD_CLASS_METHOD(ClientToWindowSize,"wxSize wxWindowBase::ClientToWindowSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#clienttowindowsize)")
    ADD_CLASS_METHOD(WindowToClientSize,"wxSize wxWindowBase::WindowToClientSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#windowtoclientsize)")
    ADD_CLASS_METHOD(GetBestSize_1,"wxSize wxWindowBase::GetBestSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getbestsize)")
    ADD_CLASS_METHOD(GetBestSize,"wxWindowBase::GetBestSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getbestsize)")
    ADD_CLASS_METHOD(GetBestSize_2,"void wxWindowBase::GetBestSize(int * w, int * h)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getbestsize)")
    ADD_CLASS_METHOD(SetScrollHelper,"void wxWindowBase::SetScrollHelper(wxScrollHelper * sh)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setscrollhelper)")
    ADD_CLASS_METHOD(GetScrollHelper,"wxScrollHelper * wxWindowBase::GetScrollHelper()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getscrollhelper)")
    ADD_CLASS_METHOD(InvalidateBestSize,"void wxWindowBase::InvalidateBestSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#invalidatebestsize)")
    ADD_CLASS_METHOD(CacheBestSize,"void wxWindowBase::CacheBestSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#cachebestsize)")
    ADD_CLASS_METHOD(GetEffectiveMinSize,"wxSize wxWindowBase::GetEffectiveMinSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#geteffectiveminsize)")
    ADD_CLASS_METHOD(SetInitialSize,"void wxWindowBase::SetInitialSize(wxSize const & size = wxDefaultSize)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setinitialsize)")
    ADD_CLASS_METHOD(Centre,"void wxWindowBase::Centre(int dir = wxBOTH)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#centre)")
    ADD_CLASS_METHOD(Center,"void wxWindowBase::Center(int dir = wxBOTH)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#center)")
    ADD_CLASS_METHOD(CentreOnParent,"void wxWindowBase::CentreOnParent(int dir = wxBOTH)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#centreonparent)")
    ADD_CLASS_METHOD(CenterOnParent,"void wxWindowBase::CenterOnParent(int dir = wxBOTH)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#centeronparent)")
    ADD_CLASS_METHOD(Fit,"void wxWindowBase::Fit()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#fit)")
    ADD_CLASS_METHOD(FitInside,"void wxWindowBase::FitInside()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#fitinside)")
    ADD_CLASS_METHOD(SetSizeHints_1,"void wxWindowBase::SetSizeHints(int minW, int minH, int maxW = wxDefaultCoord, int maxH = wxDefaultCoord, int incW = wxDefaultCoord, int incH = wxDefaultCoord)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsizehints)")
    ADD_CLASS_METHOD(SetSizeHints,"wxWindowBase::SetSizeHints()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsizehints)")
    ADD_CLASS_METHOD(SetSizeHints_2,"void wxWindowBase::SetSizeHints(wxSize const & minSize, wxSize const & maxSize = wxDefaultSize, wxSize const & incSize = wxDefaultSize)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsizehints)")
    ADD_CLASS_METHOD(DoSetSizeHints,"void wxWindowBase::DoSetSizeHints(int minW, int minH, int maxW, int maxH, int incW, int incH)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#dosetsizehints)")
    ADD_CLASS_METHOD(SetVirtualSizeHints_1,"void wxWindowBase::SetVirtualSizeHints(int minW, int minH, int maxW = wxDefaultCoord, int maxH = wxDefaultCoord)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setvirtualsizehints)")
    ADD_CLASS_METHOD(SetVirtualSizeHints,"wxWindowBase::SetVirtualSizeHints()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setvirtualsizehints)")
    ADD_CLASS_METHOD(SetVirtualSizeHints_2,"void wxWindowBase::SetVirtualSizeHints(wxSize const & minSize, wxSize const & maxSize = wxDefaultSize)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setvirtualsizehints)")
    ADD_CLASS_METHOD(SetMinSize,"void wxWindowBase::SetMinSize(wxSize const & minSize)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setminsize)")
    ADD_CLASS_METHOD(SetMaxSize,"void wxWindowBase::SetMaxSize(wxSize const & maxSize)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setmaxsize)")
    ADD_CLASS_METHOD(GetMinSize,"wxSize wxWindowBase::GetMinSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getminsize)")
    ADD_CLASS_METHOD(GetMaxSize,"wxSize wxWindowBase::GetMaxSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getmaxsize)")
    ADD_CLASS_METHOD(GetMinWidth,"int wxWindowBase::GetMinWidth()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getminwidth)")
    ADD_CLASS_METHOD(GetMinHeight,"int wxWindowBase::GetMinHeight()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getminheight)")
    ADD_CLASS_METHOD(GetMaxWidth,"int wxWindowBase::GetMaxWidth()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getmaxwidth)")
    ADD_CLASS_METHOD(GetMaxHeight,"int wxWindowBase::GetMaxHeight()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getmaxheight)")
    ADD_CLASS_METHOD(SetVirtualSize_1,"void wxWindowBase::SetVirtualSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setvirtualsize)")
    ADD_CLASS_METHOD(SetVirtualSize,"wxWindowBase::SetVirtualSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setvirtualsize)")
    ADD_CLASS_METHOD(SetVirtualSize_2,"void wxWindowBase::SetVirtualSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setvirtualsize)")
    ADD_CLASS_METHOD(GetVirtualSize_1,"wxSize wxWindowBase::GetVirtualSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getvirtualsize)")
    ADD_CLASS_METHOD(GetVirtualSize,"wxWindowBase::GetVirtualSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getvirtualsize)")
    ADD_CLASS_METHOD(GetVirtualSize_2,"void wxWindowBase::GetVirtualSize(int * x, int * y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getvirtualsize)")
    ADD_CLASS_METHOD(DoSetVirtualSize,"void wxWindowBase::DoSetVirtualSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#dosetvirtualsize)")
    ADD_CLASS_METHOD(DoGetVirtualSize,"wxSize wxWindowBase::DoGetVirtualSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#dogetvirtualsize)")
    ADD_CLASS_METHOD(GetBestVirtualSize,"wxSize wxWindowBase::GetBestVirtualSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getbestvirtualsize)")
    ADD_CLASS_METHOD(GetWindowBorderSize,"wxSize wxWindowBase::GetWindowBorderSize()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getwindowbordersize)")
    ADD_CLASS_METHOD(Show,"bool wxWindowBase::Show(bool show = true)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#show)")
    ADD_CLASS_METHOD(Hide,"bool wxWindowBase::Hide()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hide)")
    ADD_CLASS_METHOD(Enable,"bool wxWindowBase::Enable(bool enable = true)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#enable)")
    ADD_CLASS_METHOD(Disable,"bool wxWindowBase::Disable()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#disable)")
    ADD_CLASS_METHOD(IsShown,"bool wxWindowBase::IsShown()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isshown)")
    ADD_CLASS_METHOD(IsEnabled,"bool wxWindowBase::IsEnabled()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isenabled)")
    ADD_CLASS_METHOD(IsShownOnScreen,"bool wxWindowBase::IsShownOnScreen()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isshownonscreen)")
    ADD_CLASS_METHOD(SetWindowStyleFlag,"void wxWindowBase::SetWindowStyleFlag(long int style)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setwindowstyleflag)")
    ADD_CLASS_METHOD(GetWindowStyleFlag,"long int wxWindowBase::GetWindowStyleFlag()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getwindowstyleflag)")
    ADD_CLASS_METHOD(SetWindowStyle,"void wxWindowBase::SetWindowStyle(long int style)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setwindowstyle)")
    ADD_CLASS_METHOD(GetWindowStyle,"long int wxWindowBase::GetWindowStyle()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getwindowstyle)")
    ADD_CLASS_METHOD(HasFlag,"bool wxWindowBase::HasFlag(int flag)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hasflag)")
    ADD_CLASS_METHOD(IsRetained,"bool wxWindowBase::IsRetained()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isretained)")
    ADD_CLASS_METHOD(ToggleWindowStyle,"bool wxWindowBase::ToggleWindowStyle(int flag)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#togglewindowstyle)")
    ADD_CLASS_METHOD(SetExtraStyle,"void wxWindowBase::SetExtraStyle(long int exStyle)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setextrastyle)")
    ADD_CLASS_METHOD(GetExtraStyle,"long int wxWindowBase::GetExtraStyle()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getextrastyle)")
    ADD_CLASS_METHOD(MakeModal,"void wxWindowBase::MakeModal(bool modal = true)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#makemodal)")
    ADD_CLASS_METHOD(SetThemeEnabled,"void wxWindowBase::SetThemeEnabled(bool enableTheme)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setthemeenabled)")
    ADD_CLASS_METHOD(GetThemeEnabled,"bool wxWindowBase::GetThemeEnabled()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getthemeenabled)")
    ADD_CLASS_METHOD(SetFocusFromKbd,"void wxWindowBase::SetFocusFromKbd()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setfocusfromkbd)")
    ADD_CLASS_METHOD(AcceptsFocus,"bool wxWindowBase::AcceptsFocus()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#acceptsfocus)")
    ADD_CLASS_METHOD(AcceptsFocusFromKeyboard,"bool wxWindowBase::AcceptsFocusFromKeyboard()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#acceptsfocusfromkeyboard)")
    ADD_CLASS_METHOD(MoveBeforeInTabOrder,"void wxWindowBase::MoveBeforeInTabOrder(wxWindow * win)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#movebeforeintaborder)")
    ADD_CLASS_METHOD(MoveAfterInTabOrder,"void wxWindowBase::MoveAfterInTabOrder(wxWindow * win)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#moveafterintaborder)")
    ADD_CLASS_METHOD(GetChildren_1,"wxWindowList const & wxWindowBase::GetChildren()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getchildren)")
    ADD_CLASS_METHOD(GetChildren,"wxWindowBase::GetChildren()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getchildren)")
    ADD_CLASS_METHOD(GetChildren_2,"wxWindowList & wxWindowBase::GetChildren()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getchildren)")
    ADD_CLASS_METHOD(GetWindowChildren,"wxWindowList const & wxWindowBase::GetWindowChildren()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getwindowchildren)")
    ADD_CLASS_METHOD(GetPrevSibling,"wxWindow * wxWindowBase::GetPrevSibling()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getprevsibling)")
    ADD_CLASS_METHOD(GetNextSibling,"wxWindow * wxWindowBase::GetNextSibling()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getnextsibling)")
    ADD_CLASS_METHOD(GetParent,"wxWindow * wxWindowBase::GetParent()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getparent)")
    ADD_CLASS_METHOD(GetGrandParent,"wxWindow * wxWindowBase::GetGrandParent()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getgrandparent)")
    ADD_CLASS_METHOD(IsTopLevel,"bool wxWindowBase::IsTopLevel()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#istoplevel)")
    ADD_CLASS_METHOD(SetParent,"void wxWindowBase::SetParent(wxWindowBase * parent)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setparent)")
    ADD_CLASS_METHOD(Reparent,"bool wxWindowBase::Reparent(wxWindowBase * newParent)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#reparent)")
    ADD_CLASS_METHOD(AddChild,"void wxWindowBase::AddChild(wxWindowBase * child)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#addchild)")
    ADD_CLASS_METHOD(RemoveChild,"void wxWindowBase::RemoveChild(wxWindowBase * child)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#removechild)")
    ADD_CLASS_METHOD(FindWindow_1,"wxWindow * wxWindowBase::FindWindow(long int winid)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#findwindow)")
    ADD_CLASS_METHOD(FindWindow,"wxWindowBase::FindWindow()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#findwindow)")
    ADD_CLASS_METHOD(FindWindow_2,"wxWindow * wxWindowBase::FindWindow(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#findwindow)")
    ADD_CLASS_METHOD(GetEventHandler,"wxEvtHandler * wxWindowBase::GetEventHandler()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#geteventhandler)")
    ADD_CLASS_METHOD(SetEventHandler,"void wxWindowBase::SetEventHandler(wxEvtHandler * handler)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#seteventhandler)")
    ADD_CLASS_METHOD(PushEventHandler,"void wxWindowBase::PushEventHandler(wxEvtHandler * handler)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#pusheventhandler)")
    ADD_CLASS_METHOD(PopEventHandler,"wxEvtHandler * wxWindowBase::PopEventHandler(bool deleteHandler = false)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#popeventhandler)")
    ADD_CLASS_METHOD(RemoveEventHandler,"bool wxWindowBase::RemoveEventHandler(wxEvtHandler * handler)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#removeeventhandler)")
    ADD_CLASS_METHOD(SetValidator,"void wxWindowBase::SetValidator(wxValidator const & validator)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setvalidator)")
    ADD_CLASS_METHOD(GetValidator,"wxValidator * wxWindowBase::GetValidator()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getvalidator)")
    ADD_CLASS_METHOD(Validate,"bool wxWindowBase::Validate()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#validate)")
    ADD_CLASS_METHOD(TransferDataToWindow,"bool wxWindowBase::TransferDataToWindow()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#transferdatatowindow)")
    ADD_CLASS_METHOD(TransferDataFromWindow,"bool wxWindowBase::TransferDataFromWindow()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#transferdatafromwindow)")
    ADD_CLASS_METHOD(InitDialog,"void wxWindowBase::InitDialog()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#initdialog)")
    ADD_CLASS_METHOD(SetAcceleratorTable,"void wxWindowBase::SetAcceleratorTable(wxAcceleratorTable const & accel)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setacceleratortable)")
    ADD_CLASS_METHOD(GetAcceleratorTable,"wxAcceleratorTable * wxWindowBase::GetAcceleratorTable()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getacceleratortable)")
    ADD_CLASS_METHOD(ConvertPixelsToDialog_1,"wxPoint wxWindowBase::ConvertPixelsToDialog(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#convertpixelstodialog)")
    ADD_CLASS_METHOD(ConvertDialogToPixels_1,"wxPoint wxWindowBase::ConvertDialogToPixels(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#convertdialogtopixels)")
    ADD_CLASS_METHOD(ConvertPixelsToDialog,"wxWindowBase::ConvertPixelsToDialog()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#convertpixelstodialog)")
    ADD_CLASS_METHOD(ConvertPixelsToDialog_2,"wxSize wxWindowBase::ConvertPixelsToDialog(wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#convertpixelstodialog)")
    ADD_CLASS_METHOD(ConvertDialogToPixels,"wxWindowBase::ConvertDialogToPixels()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#convertdialogtopixels)")
    ADD_CLASS_METHOD(ConvertDialogToPixels_2,"wxSize wxWindowBase::ConvertDialogToPixels(wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#convertdialogtopixels)")
    ADD_CLASS_METHOD(CaptureMouse,"void wxWindowBase::CaptureMouse()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#capturemouse)")
    ADD_CLASS_METHOD(ReleaseMouse,"void wxWindowBase::ReleaseMouse()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#releasemouse)")
    ADD_CLASS_METHOD(HasCapture,"bool wxWindowBase::HasCapture()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hascapture)")
    ADD_CLASS_METHOD(RefreshRect,"void wxWindowBase::RefreshRect(wxRect const & rect, bool eraseBackground = true)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#refreshrect)")
    ADD_CLASS_METHOD(Update,"void wxWindowBase::Update()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#update)")
    ADD_CLASS_METHOD(ClearBackground,"void wxWindowBase::ClearBackground()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#clearbackground)")
    ADD_CLASS_METHOD(Freeze,"void wxWindowBase::Freeze()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#freeze)")
    ADD_CLASS_METHOD(Thaw,"void wxWindowBase::Thaw()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#thaw)")
    ADD_CLASS_METHOD(IsFrozen,"bool wxWindowBase::IsFrozen()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isfrozen)")
    ADD_CLASS_METHOD(PrepareDC,"void wxWindowBase::PrepareDC(wxDC & param0)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#preparedc)")
    ADD_CLASS_METHOD(IsDoubleBuffered,"bool wxWindowBase::IsDoubleBuffered()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isdoublebuffered)")
    ADD_CLASS_METHOD(GetUpdateRegion_1,"wxRegion const & wxWindowBase::GetUpdateRegion()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getupdateregion)")
    ADD_CLASS_METHOD(GetUpdateRegion,"wxWindowBase::GetUpdateRegion()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getupdateregion)")
    ADD_CLASS_METHOD(GetUpdateRegion_2,"wxRegion & wxWindowBase::GetUpdateRegion()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getupdateregion)")
    ADD_CLASS_METHOD(GetUpdateClientRect,"wxRect wxWindowBase::GetUpdateClientRect()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getupdateclientrect)")
    ADD_CLASS_METHOD(DoIsExposed_1,"bool wxWindowBase::DoIsExposed(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#doisexposed)")
    ADD_CLASS_METHOD(DoIsExposed,"wxWindowBase::DoIsExposed()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#doisexposed)")
    ADD_CLASS_METHOD(DoIsExposed_2,"bool wxWindowBase::DoIsExposed(int x, int y, int w, int h)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#doisexposed)")
    ADD_CLASS_METHOD(IsExposed_1,"bool wxWindowBase::IsExposed(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isexposed)")
    ADD_CLASS_METHOD(IsExposed,"wxWindowBase::IsExposed()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isexposed)")
    ADD_CLASS_METHOD(IsExposed_2,"bool wxWindowBase::IsExposed(int x, int y, int w, int h)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isexposed)")
    ADD_CLASS_METHOD(IsExposed_3,"bool wxWindowBase::IsExposed(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isexposed)")
    ADD_CLASS_METHOD(IsExposed_4,"bool wxWindowBase::IsExposed(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#isexposed)")
    ADD_CLASS_METHOD(GetDefaultAttributes,"wxVisualAttributes wxWindowBase::GetDefaultAttributes()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getdefaultattributes)")
    ADD_CLASS_METHOD(SetBackgroundColour,"bool wxWindowBase::SetBackgroundColour(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setbackgroundcolour)")
    ADD_CLASS_METHOD(SetOwnBackgroundColour,"void wxWindowBase::SetOwnBackgroundColour(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setownbackgroundcolour)")
    ADD_CLASS_METHOD(GetBackgroundColour,"wxColour wxWindowBase::GetBackgroundColour()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getbackgroundcolour)")
    ADD_CLASS_METHOD(InheritsBackgroundColour,"bool wxWindowBase::InheritsBackgroundColour()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#inheritsbackgroundcolour)")
    ADD_CLASS_METHOD(UseBgCol,"bool wxWindowBase::UseBgCol()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#usebgcol)")
    ADD_CLASS_METHOD(SetForegroundColour,"bool wxWindowBase::SetForegroundColour(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setforegroundcolour)")
    ADD_CLASS_METHOD(SetOwnForegroundColour,"void wxWindowBase::SetOwnForegroundColour(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setownforegroundcolour)")
    ADD_CLASS_METHOD(GetForegroundColour,"wxColour wxWindowBase::GetForegroundColour()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getforegroundcolour)")
    ADD_CLASS_METHOD(SetBackgroundStyle,"bool wxWindowBase::SetBackgroundStyle(wxBackgroundStyle style)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setbackgroundstyle)")
    ADD_CLASS_METHOD(GetBackgroundStyle,"wxBackgroundStyle wxWindowBase::GetBackgroundStyle()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getbackgroundstyle)")
    ADD_CLASS_METHOD(HasTransparentBackground,"bool wxWindowBase::HasTransparentBackground()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hastransparentbackground)")
    ADD_CLASS_METHOD(SetOwnFont,"void wxWindowBase::SetOwnFont(wxFont const & font)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setownfont)")
    ADD_CLASS_METHOD(GetFont,"wxFont wxWindowBase::GetFont()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getfont)")
    ADD_CLASS_METHOD(SetCursor,"bool wxWindowBase::SetCursor(wxCursor const & cursor)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setcursor)")
    ADD_CLASS_METHOD(GetCursor,"wxCursor const & wxWindowBase::GetCursor()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getcursor)")
/* The following types are missing: wxCaret
    ADD_CLASS_METHOD(SetCaret,"void wxWindowBase::SetCaret(wxCaret * caret)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setcaret)")
*/
/* The following types are missing: wxCaret
    ADD_CLASS_METHOD(GetCaret,"wxCaret * wxWindowBase::GetCaret()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getcaret)")
*/
    ADD_CLASS_METHOD(ClientToScreen_1,"void wxWindowBase::ClientToScreen(int * x, int * y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#clienttoscreen)")
    ADD_CLASS_METHOD(ScreenToClient_1,"void wxWindowBase::ScreenToClient(int * x, int * y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#screentoclient)")
    ADD_CLASS_METHOD(ClientToScreen,"wxWindowBase::ClientToScreen()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#clienttoscreen)")
    ADD_CLASS_METHOD(ClientToScreen_2,"wxPoint wxWindowBase::ClientToScreen(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#clienttoscreen)")
    ADD_CLASS_METHOD(ScreenToClient,"wxWindowBase::ScreenToClient()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#screentoclient)")
    ADD_CLASS_METHOD(ScreenToClient_2,"wxPoint wxWindowBase::ScreenToClient(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#screentoclient)")
    ADD_CLASS_METHOD(HitTest_1,"wxHitTest wxWindowBase::HitTest(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hittest)")
    ADD_CLASS_METHOD(HitTest,"wxWindowBase::HitTest()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hittest)")
    ADD_CLASS_METHOD(HitTest_2,"wxHitTest wxWindowBase::HitTest(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hittest)")
    ADD_CLASS_METHOD(GetBorder_1,"wxBorder wxWindowBase::GetBorder(long int flags)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getborder)")
    ADD_CLASS_METHOD(GetBorder,"wxWindowBase::GetBorder()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getborder)")
    ADD_CLASS_METHOD(GetBorder_2,"wxBorder wxWindowBase::GetBorder()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getborder)")
    ADD_CLASS_METHOD(UpdateWindowUI,"void wxWindowBase::UpdateWindowUI(long int flags = wxUPDATE_UI_NONE)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#updatewindowui)")
    ADD_CLASS_METHOD(DoUpdateWindowUI,"void wxWindowBase::DoUpdateWindowUI(wxUpdateUIEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#doupdatewindowui)")
    ADD_CLASS_METHOD(PopupMenu_1,"bool wxWindowBase::PopupMenu(wxMenu * menu, wxPoint const & pos = wxDefaultPosition)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#popupmenu)")
    ADD_CLASS_METHOD(PopupMenu,"wxWindowBase::PopupMenu()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#popupmenu)")
    ADD_CLASS_METHOD(PopupMenu_2,"bool wxWindowBase::PopupMenu(wxMenu * menu, int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#popupmenu)")
    ADD_CLASS_METHOD(HasMultiplePages,"bool wxWindowBase::HasMultiplePages()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hasmultiplepages)")
    ADD_CLASS_METHOD(HasScrollbar,"bool wxWindowBase::HasScrollbar(int orient)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hasscrollbar)")
    ADD_CLASS_METHOD(ScrollLines,"bool wxWindowBase::ScrollLines(int param0)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#scrolllines)")
    ADD_CLASS_METHOD(ScrollPages,"bool wxWindowBase::ScrollPages(int param0)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#scrollpages)")
    ADD_CLASS_METHOD(LineUp,"bool wxWindowBase::LineUp()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#lineup)")
    ADD_CLASS_METHOD(LineDown,"bool wxWindowBase::LineDown()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#linedown)")
    ADD_CLASS_METHOD(PageUp,"bool wxWindowBase::PageUp()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#pageup)")
    ADD_CLASS_METHOD(PageDown,"bool wxWindowBase::PageDown()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#pagedown)")
    ADD_CLASS_METHOD(SetHelpText,"void wxWindowBase::SetHelpText(wxString const & text)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#sethelptext)")
    ADD_CLASS_METHOD(SetHelpTextForId,"void wxWindowBase::SetHelpTextForId(wxString const & text)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#sethelptextforid)")
    ADD_CLASS_METHOD(GetHelpText,"wxString wxWindowBase::GetHelpText()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#gethelptext)")
    ADD_CLASS_METHOD(SetToolTip_1,"void wxWindowBase::SetToolTip(wxString const & tip)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#settooltip)")
    ADD_CLASS_METHOD(SetToolTip,"wxWindowBase::SetToolTip()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#settooltip)")
/* The following types are missing: wxToolTip
    ADD_CLASS_METHOD(SetToolTip_2,"void wxWindowBase::SetToolTip(wxToolTip * tip)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#settooltip)")
*/
    ADD_CLASS_METHOD(UnsetToolTip,"void wxWindowBase::UnsetToolTip()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#unsettooltip)")
/* The following types are missing: wxToolTip
    ADD_CLASS_METHOD(GetToolTip,"wxToolTip * wxWindowBase::GetToolTip()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#gettooltip)")
*/
/* The following types are missing: wxDropTarget
    ADD_CLASS_METHOD(GetDropTarget,"wxDropTarget * wxWindowBase::GetDropTarget()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getdroptarget)")
*/
    ADD_CLASS_METHOD(DragAcceptFiles,"void wxWindowBase::DragAcceptFiles(bool accept)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#dragacceptfiles)")
    ADD_CLASS_METHOD(SetConstraints,"void wxWindowBase::SetConstraints(wxLayoutConstraints * constraints)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setconstraints)")
    ADD_CLASS_METHOD(GetConstraints,"wxLayoutConstraints * wxWindowBase::GetConstraints()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getconstraints)")
    ADD_CLASS_METHOD(UnsetConstraints,"void wxWindowBase::UnsetConstraints(wxLayoutConstraints * c)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#unsetconstraints)")
    ADD_CLASS_METHOD(GetConstraintsInvolvedIn,"wxWindowList * wxWindowBase::GetConstraintsInvolvedIn()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getconstraintsinvolvedin)")
    ADD_CLASS_METHOD(AddConstraintReference,"void wxWindowBase::AddConstraintReference(wxWindowBase * otherWin)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#addconstraintreference)")
    ADD_CLASS_METHOD(RemoveConstraintReference,"void wxWindowBase::RemoveConstraintReference(wxWindowBase * otherWin)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#removeconstraintreference)")
    ADD_CLASS_METHOD(DeleteRelatedConstraints,"void wxWindowBase::DeleteRelatedConstraints()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#deleterelatedconstraints)")
    ADD_CLASS_METHOD(ResetConstraints,"void wxWindowBase::ResetConstraints()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#resetconstraints)")
    ADD_CLASS_METHOD(SetConstraintSizes,"void wxWindowBase::SetConstraintSizes(bool recurse = true)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setconstraintsizes)")
    ADD_CLASS_METHOD(LayoutPhase1,"bool wxWindowBase::LayoutPhase1(int * noChanges)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#layoutphase1)")
    ADD_CLASS_METHOD(LayoutPhase2,"bool wxWindowBase::LayoutPhase2(int * noChanges)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#layoutphase2)")
    ADD_CLASS_METHOD(DoPhase,"bool wxWindowBase::DoPhase(int phase)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#dophase)")
    ADD_CLASS_METHOD(SetSizeConstraint,"void wxWindowBase::SetSizeConstraint(int x, int y, int w, int h)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsizeconstraint)")
    ADD_CLASS_METHOD(MoveConstraint,"void wxWindowBase::MoveConstraint(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#moveconstraint)")
    ADD_CLASS_METHOD(GetSizeConstraint,"void wxWindowBase::GetSizeConstraint(int * w, int * h)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getsizeconstraint)")
    ADD_CLASS_METHOD(GetClientSizeConstraint,"void wxWindowBase::GetClientSizeConstraint(int * w, int * h)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getclientsizeconstraint)")
    ADD_CLASS_METHOD(GetPositionConstraint,"void wxWindowBase::GetPositionConstraint(int * x, int * y)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getpositionconstraint)")
    ADD_CLASS_METHOD(SetAutoLayout,"void wxWindowBase::SetAutoLayout(bool autoLayout)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setautolayout)")
    ADD_CLASS_METHOD(GetAutoLayout,"bool wxWindowBase::GetAutoLayout()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getautolayout)")
    ADD_CLASS_METHOD(Layout,"bool wxWindowBase::Layout()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#layout)")
    ADD_CLASS_METHOD(SetSizer,"void wxWindowBase::SetSizer(wxSizer * sizer, bool deleteOld = true)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsizer)")
    ADD_CLASS_METHOD(SetSizerAndFit,"void wxWindowBase::SetSizerAndFit(wxSizer * sizer, bool deleteOld = true)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setsizerandfit)")
    ADD_CLASS_METHOD(GetSizer,"wxSizer * wxWindowBase::GetSizer()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getsizer)")
    ADD_CLASS_METHOD(SetContainingSizer,"void wxWindowBase::SetContainingSizer(wxSizer * sizer)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setcontainingsizer)")
    ADD_CLASS_METHOD(GetContainingSizer,"wxSizer * wxWindowBase::GetContainingSizer()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getcontainingsizer)")
    ADD_CLASS_METHOD(SetTransparent,"bool wxWindowBase::SetTransparent(wxByte param0)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#settransparent)")
    ADD_CLASS_METHOD(CanSetTransparent,"bool wxWindowBase::CanSetTransparent()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#cansettransparent)")
    ADD_CLASS_METHOD(OnSysColourChanged,"void wxWindowBase::OnSysColourChanged(wxSysColourChangedEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#onsyscolourchanged)")
    ADD_CLASS_METHOD(OnInitDialog,"void wxWindowBase::OnInitDialog(wxInitDialogEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#oninitdialog)")
    ADD_CLASS_METHOD(OnMiddleClick,"void wxWindowBase::OnMiddleClick(wxMouseEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#onmiddleclick)")
    ADD_CLASS_METHOD(OnHelp,"void wxWindowBase::OnHelp(wxHelpEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#onhelp)")
    ADD_CLASS_METHOD(OnInternalIdle,"void wxWindowBase::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#oninternalidle)")
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(AssociateHandle,"void wxWindowBase::AssociateHandle(WXWidget param0)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#associatehandle)")
*/
    ADD_CLASS_METHOD(DissociateHandle,"void wxWindowBase::DissociateHandle()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#dissociatehandle)")
    ADD_CLASS_METHOD(GetPalette,"wxPalette wxWindowBase::GetPalette()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getpalette)")
    ADD_CLASS_METHOD(SetPalette,"void wxWindowBase::SetPalette(wxPalette const & pal)  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#setpalette)")
    ADD_CLASS_METHOD(HasCustomPalette,"bool wxWindowBase::HasCustomPalette()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#hascustompalette)")
    ADD_CLASS_METHOD(GetAncestorWithCustomPalette,"wxWindow * wxWindowBase::GetAncestorWithCustomPalette()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getancestorwithcustompalette)")
    ADD_CLASS_METHOD(InheritAttributes,"void wxWindowBase::InheritAttributes()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#inheritattributes)")
    ADD_CLASS_METHOD(ShouldInheritColours,"bool wxWindowBase::ShouldInheritColours()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#shouldinheritcolours)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxWindowBase::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxwindowbase.html#getclassinfo)")





    void AddMethods(WrapClass<wxWindowBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxWindowBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxWindowBase_h
