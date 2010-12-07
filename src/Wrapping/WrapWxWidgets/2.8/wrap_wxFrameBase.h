/**
 * C++ Interface: wrap_wxFrameBase
 *
 * Description: wrapping wxFrameBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFrameBase_h_
#define _wrap_wxFrameBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxTopLevelWindow.h"



AMI_DECLARE_TYPE(wxFrameBase);

// TODO: check for inheritence ...
class WrapClass_wxFrameBase : public WrapClass<wxFrameBase>
    , public   WrapClass_wxTopLevelWindow
{
  DEFINE_CLASS(WrapClass_wxFrameBase);

  protected:
    typedef WrapClass<wxFrameBase>::ptr _parentclass_ptr;
    typedef wxFrameBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFrameBase>& GetObj() const { return WrapClass<wxFrameBase>::GetObj(); }

    /// Constructor
    WrapClass_wxFrameBase(boost::shared_ptr<wxFrameBase > si): 
    WrapClass<wxFrameBase>(si)
    , WrapClass_wxTopLevelWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxFrameBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrameBase,"Constructor wxFrameBase::wxFrameBase() (http://docs.wxwidgets.org/stable/wx_wxframebase.html#wxframebase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFrameBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(New,"wxFrame * wxFrameBase::New(wxWindow * parent, wxWindowID winid, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#new)")
    ADD_CLASS_METHOD(GetClientAreaOrigin,"wxPoint wxFrameBase::GetClientAreaOrigin()  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#getclientareaorigin)")
    ADD_CLASS_METHOD(SendSizeEvent,"void wxFrameBase::SendSizeEvent()  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#sendsizeevent)")
    ADD_CLASS_METHOD(SetMenuBar,"void wxFrameBase::SetMenuBar(wxMenuBar * menubar)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#setmenubar)")
    ADD_CLASS_METHOD(GetMenuBar,"wxMenuBar * wxFrameBase::GetMenuBar()  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#getmenubar)")
    ADD_CLASS_METHOD(ProcessCommand,"bool wxFrameBase::ProcessCommand(int winid)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#processcommand)")
    ADD_CLASS_METHOD(CreateStatusBar,"wxStatusBar * wxFrameBase::CreateStatusBar(int number = 1, long int style = 65552, wxWindowID winid = 0, wxString const & name = wxStatusLineNameStr)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#createstatusbar)")
    ADD_CLASS_METHOD(OnCreateStatusBar,"wxStatusBar * wxFrameBase::OnCreateStatusBar(int number, long int style, wxWindowID winid, wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#oncreatestatusbar)")
    ADD_CLASS_METHOD(GetStatusBar,"wxStatusBar * wxFrameBase::GetStatusBar()  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#getstatusbar)")
    ADD_CLASS_METHOD(SetStatusBar,"void wxFrameBase::SetStatusBar(wxStatusBar * statBar)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#setstatusbar)")
    ADD_CLASS_METHOD(SetStatusText,"void wxFrameBase::SetStatusText(wxString const & text, int number = 0)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#setstatustext)")
    ADD_CLASS_METHOD(SetStatusWidths,"void wxFrameBase::SetStatusWidths(int n, int const * widths_field)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#setstatuswidths)")
    ADD_CLASS_METHOD(PushStatusText,"void wxFrameBase::PushStatusText(wxString const & text, int number = 0)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#pushstatustext)")
    ADD_CLASS_METHOD(PopStatusText,"void wxFrameBase::PopStatusText(int number = 0)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#popstatustext)")
    ADD_CLASS_METHOD(SetStatusBarPane,"void wxFrameBase::SetStatusBarPane(int n)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#setstatusbarpane)")
    ADD_CLASS_METHOD(GetStatusBarPane,"int wxFrameBase::GetStatusBarPane()  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#getstatusbarpane)")
    ADD_CLASS_METHOD(CreateToolBar,"wxToolBar * wxFrameBase::CreateToolBar(long int style = -0x00000000000000001, wxWindowID winid = wxID_ANY, wxString const & name = wxToolBarNameStr)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#createtoolbar)")
    ADD_CLASS_METHOD(OnCreateToolBar,"wxToolBar * wxFrameBase::OnCreateToolBar(long int style, wxWindowID winid, wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#oncreatetoolbar)")
    ADD_CLASS_METHOD(GetToolBar,"wxToolBar * wxFrameBase::GetToolBar()  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#gettoolbar)")
    ADD_CLASS_METHOD(SetToolBar,"void wxFrameBase::SetToolBar(wxToolBar * toolbar)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#settoolbar)")
    ADD_CLASS_METHOD(OnMenuOpen,"void wxFrameBase::OnMenuOpen(wxMenuEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#onmenuopen)")
    ADD_CLASS_METHOD(OnMenuClose,"void wxFrameBase::OnMenuClose(wxMenuEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#onmenuclose)")
    ADD_CLASS_METHOD(OnMenuHighlight,"void wxFrameBase::OnMenuHighlight(wxMenuEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#onmenuhighlight)")
    ADD_CLASS_METHOD(DoMenuUpdates,"void wxFrameBase::DoMenuUpdates(wxMenu * menu = 0l)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#domenuupdates)")
    ADD_CLASS_METHOD(UpdateWindowUI,"void wxFrameBase::UpdateWindowUI(long int flags = wxUPDATE_UI_NONE)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#updatewindowui)")
    ADD_CLASS_METHOD(OnInternalIdle,"void wxFrameBase::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#oninternalidle)")
    ADD_CLASS_METHOD(DoGiveHelp,"void wxFrameBase::DoGiveHelp(wxString const & text, bool show)  (http://docs.wxwidgets.org/stable/wx_wxframebase.html#dogivehelp)")





    void AddMethods(WrapClass<wxFrameBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxFrameBase_h
