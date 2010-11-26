/**
 * C++ Interface: wrap_wxWindow
 *
 * Description: wrapping wxWindow
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxWindow_h_
#define _wrap_wxWindow_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWindowBase.h"



AMI_DECLARE_TYPE(wxWindow);

// TODO: check for inheritence ...
class WrapClass_wxWindow : public WrapClass<wxWindow>
    , public   WrapClass_wxWindowBase
{
  DEFINE_CLASS(WrapClass_wxWindow);

  protected:
    typedef WrapClass<wxWindow>::ptr _parentclass_ptr;
    typedef wxWindow ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxWindow>& GetObj() const { return WrapClass<wxWindow>::GetObj(); }

    /// Constructor
    WrapClass_wxWindow(boost::shared_ptr<wxWindow > si): 
    WrapClass<wxWindow>(si)
    , WrapClass_wxWindowBase(si)
    {}

    /// Destructor
    ~WrapClass_wxWindow()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindow_1,"Constructor wxWindow::wxWindow() (http://docs.wxwidgets.org/stable/wx_wxwindow.html#wxwindow).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindow,"Constructor wxWindow::wxWindow() (http://docs.wxwidgets.org/stable/wx_wxwindow.html#wxwindow).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindow_2,"Constructor wxWindow::wxWindow(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxPanelNameStr) (http://docs.wxwidgets.org/stable/wx_wxwindow.html#wxwindow).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxWindow*);

    // Static methods
    
    /* The following types are missing: wxLayoutDirection, _GtkWidget
    ADD_CLASS_STATICMETHOD(GTKGetLayout,"wxLayoutDirection wxWindow::GTKGetLayout(GtkWidget * widget) (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtkgetlayout).");
    */
    /* The following types are missing: _GtkWidget, wxLayoutDirection
    ADD_CLASS_STATICMETHOD(GTKSetLayout,"void wxWindow::GTKSetLayout(GtkWidget * widget, wxLayoutDirection dir) (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtksetlayout).");
    */



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxWindow::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxPanelNameStr)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#create)")
    ADD_CLASS_METHOD(SetLabel,"void wxWindow::SetLabel(wxString const & param0)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setlabel)")
    ADD_CLASS_METHOD(GetLabel,"wxString wxWindow::GetLabel()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getlabel)")
    ADD_CLASS_METHOD(Destroy,"bool wxWindow::Destroy()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#destroy)")
    ADD_CLASS_METHOD(Raise,"void wxWindow::Raise()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#raise)")
    ADD_CLASS_METHOD(Lower,"void wxWindow::Lower()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#lower)")
    ADD_CLASS_METHOD(Show,"bool wxWindow::Show(bool show = true)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#show)")
    ADD_CLASS_METHOD(Enable,"bool wxWindow::Enable(bool enable = true)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#enable)")
    ADD_CLASS_METHOD(SetWindowStyleFlag,"void wxWindow::SetWindowStyleFlag(long int style)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setwindowstyleflag)")
    ADD_CLASS_METHOD(IsRetained,"bool wxWindow::IsRetained()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#isretained)")
    ADD_CLASS_METHOD(SetFocus,"void wxWindow::SetFocus()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setfocus)")
    ADD_CLASS_METHOD(AcceptsFocus,"bool wxWindow::AcceptsFocus()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#acceptsfocus)")
    ADD_CLASS_METHOD(Reparent,"bool wxWindow::Reparent(wxWindowBase * newParent)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#reparent)")
    ADD_CLASS_METHOD(WarpPointer,"void wxWindow::WarpPointer(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#warppointer)")
    ADD_CLASS_METHOD(Refresh,"void wxWindow::Refresh(bool eraseBackground = true, wxRect const * rect = 0u)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#refresh)")
    ADD_CLASS_METHOD(Update,"void wxWindow::Update()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#update)")
    ADD_CLASS_METHOD(ClearBackground,"void wxWindow::ClearBackground()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#clearbackground)")
    ADD_CLASS_METHOD(SetBackgroundColour,"bool wxWindow::SetBackgroundColour(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setbackgroundcolour)")
    ADD_CLASS_METHOD(SetForegroundColour,"bool wxWindow::SetForegroundColour(wxColour const & colour)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setforegroundcolour)")
    ADD_CLASS_METHOD(SetCursor,"bool wxWindow::SetCursor(wxCursor const & cursor)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setcursor)")
    ADD_CLASS_METHOD(SetFont,"bool wxWindow::SetFont(wxFont const & font)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setfont)")
/* The following types are missing: wxBackgroundStyle
    ADD_CLASS_METHOD(SetBackgroundStyle,"bool wxWindow::SetBackgroundStyle(wxBackgroundStyle style)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setbackgroundstyle)")
*/
    ADD_CLASS_METHOD(GetCharHeight,"int wxWindow::GetCharHeight()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getcharheight)")
    ADD_CLASS_METHOD(GetCharWidth,"int wxWindow::GetCharWidth()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getcharwidth)")
    ADD_CLASS_METHOD(GetTextExtent,"void wxWindow::GetTextExtent(wxString const & string, int * x, int * y, int * descent = 0u, int * externalLeading = 0u, wxFont const * theFont = 0u)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gettextextent)")
    ADD_CLASS_METHOD(SetScrollbar,"void wxWindow::SetScrollbar(int orient, int pos, int thumbVisible, int range, bool refresh = true)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setscrollbar)")
    ADD_CLASS_METHOD(SetScrollPos,"void wxWindow::SetScrollPos(int orient, int pos, bool refresh = true)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setscrollpos)")
    ADD_CLASS_METHOD(GetScrollPos,"int wxWindow::GetScrollPos(int orient)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getscrollpos)")
    ADD_CLASS_METHOD(GetScrollThumb,"int wxWindow::GetScrollThumb(int orient)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getscrollthumb)")
    ADD_CLASS_METHOD(GetScrollRange,"int wxWindow::GetScrollRange(int orient)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getscrollrange)")
    ADD_CLASS_METHOD(ScrollWindow,"void wxWindow::ScrollWindow(int dx, int dy, wxRect const * rect = 0u)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#scrollwindow)")
    ADD_CLASS_METHOD(ScrollLines,"bool wxWindow::ScrollLines(int lines)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#scrolllines)")
    ADD_CLASS_METHOD(ScrollPages,"bool wxWindow::ScrollPages(int pages)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#scrollpages)")
/* The following types are missing: wxDropTarget
    ADD_CLASS_METHOD(SetDropTarget,"void wxWindow::SetDropTarget(wxDropTarget * dropTarget)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setdroptarget)")
*/
    ADD_CLASS_METHOD(AddChild,"void wxWindow::AddChild(wxWindowBase * child)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#addchild)")
    ADD_CLASS_METHOD(RemoveChild,"void wxWindow::RemoveChild(wxWindowBase * child)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#removechild)")
/* The following types are missing: wxLayoutDirection
    ADD_CLASS_METHOD(SetLayoutDirection,"void wxWindow::SetLayoutDirection(wxLayoutDirection dir)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setlayoutdirection)")
*/
/* The following types are missing: wxLayoutDirection
    ADD_CLASS_METHOD(GetLayoutDirection,"wxLayoutDirection wxWindow::GetLayoutDirection()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getlayoutdirection)")
*/
    ADD_CLASS_METHOD(AdjustForLayoutDirection,"wxCoord wxWindow::AdjustForLayoutDirection(wxCoord x, wxCoord width, wxCoord widthTotal)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#adjustforlayoutdirection)")
    ADD_CLASS_METHOD(DoIsExposed_1,"bool wxWindow::DoIsExposed(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#doisexposed)")
    ADD_CLASS_METHOD(DoIsExposed,"wxWindow::DoIsExposed()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#doisexposed)")
    ADD_CLASS_METHOD(DoIsExposed_2,"bool wxWindow::DoIsExposed(int x, int y, int w, int h)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#doisexposed)")
    ADD_CLASS_METHOD(SetDoubleBuffered,"void wxWindow::SetDoubleBuffered(bool on)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#setdoublebuffered)")
    ADD_CLASS_METHOD(IsDoubleBuffered,"bool wxWindow::IsDoubleBuffered()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#isdoublebuffered)")
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(GetHandle,"WXWidget wxWindow::GetHandle()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gethandle)")
*/
    ADD_CLASS_METHOD(OnInternalIdle,"void wxWindow::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#oninternalidle)")
    ADD_CLASS_METHOD(GtkUpdate,"void wxWindow::GtkUpdate()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtkupdate)")
    ADD_CLASS_METHOD(OnIdle,"void wxWindow::OnIdle(wxIdleEvent & param0)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#onidle)")
    ADD_CLASS_METHOD(OnParentEnable,"void wxWindow::OnParentEnable(bool param0)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#onparentenable)")
    ADD_CLASS_METHOD(PreCreation,"bool wxWindow::PreCreation(wxWindow * parent, wxPoint const & pos, wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#precreation)")
    ADD_CLASS_METHOD(PostCreation,"void wxWindow::PostCreation()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#postcreation)")
    ADD_CLASS_METHOD(DoAddChild,"void wxWindow::DoAddChild(wxWindow * child)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#doaddchild)")
    ADD_CLASS_METHOD(GtkSendPaintEvents,"void wxWindow::GtkSendPaintEvents()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtksendpaintevents)")
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(GetConnectWidget,"GtkWidget * wxWindow::GetConnectWidget()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getconnectwidget)")
*/
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(ConnectWidget,"void wxWindow::ConnectWidget(GtkWidget * widget)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#connectwidget)")
*/
/* The following types are missing: _GdkEventAny
    ADD_CLASS_METHOD(GTKCallbackCommonPrologue,"int wxWindow::GTKCallbackCommonPrologue(_GdkEventAny * event)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtkcallbackcommonprologue)")
*/
    ADD_CLASS_METHOD(GTKProcessEvent,"bool wxWindow::GTKProcessEvent(wxEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtkprocessevent)")
/* The following types are missing: _PangoContext
    ADD_CLASS_METHOD(GtkGetPangoDefaultContext,"PangoContext * wxWindow::GtkGetPangoDefaultContext()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtkgetpangodefaultcontext)")
*/
/* The following types are missing: _GtkTooltips
    ADD_CLASS_METHOD(ApplyToolTip,"void wxWindow::ApplyToolTip(GtkTooltips * tips, wxChar const * tip)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#applytooltip)")
*/
    ADD_CLASS_METHOD(GtkUpdateSize,"void wxWindow::GtkUpdateSize()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtkupdatesize)")
    ADD_CLASS_METHOD(GtkShowOnIdle,"void wxWindow::GtkShowOnIdle()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtkshowonidle)")
    ADD_CLASS_METHOD(GtkShowFromOnIdle,"bool wxWindow::GtkShowFromOnIdle()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#gtkshowfromonidle)")
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(FixUpMouseEvent,"void wxWindow::FixUpMouseEvent(GtkWidget * param0, wxCoord & param1, wxCoord & param2)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#fixupmouseevent)")
*/
    ADD_CLASS_METHOD(IsTransparentForMouse,"bool wxWindow::IsTransparentForMouse()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#istransparentformouse)")
    ADD_CLASS_METHOD(IsRadioButton,"bool wxWindow::IsRadioButton()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#isradiobutton)")
/* The following types are missing: _GtkRange
    ADD_CLASS_METHOD(GetScrollEventType,"wxEventType wxWindow::GetScrollEventType(GtkRange * range)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getscrolleventtype)")
*/
    ADD_CLASS_METHOD(BlockScrollEvent,"void wxWindow::BlockScrollEvent()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#blockscrollevent)")
    ADD_CLASS_METHOD(UnblockScrollEvent,"void wxWindow::UnblockScrollEvent()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#unblockscrollevent)")
/* The following types are missing: _GtkRange
    ADD_CLASS_METHOD(ScrollDirFromRange,"wxWindow::ScrollDir wxWindow::ScrollDirFromRange(GtkRange * range)  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#scrolldirfromrange)")
*/
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxWindow::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxwindow.html#getclassinfo)")





    void AddMethods(WrapClass<wxWindow>::ptr this_ptr );

};


#endif // _wrap_wxWindow_h
