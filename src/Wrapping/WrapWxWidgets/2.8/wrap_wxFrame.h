/**
 * C++ Interface: wrap_wxFrame
 *
 * Description: wrapping wxFrame
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFrame_h_
#define _wrap_wxFrame_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxFrameBase.h"


AMI_DECLARE_TYPE(wxFrame);

// TODO: check for inheritence ...
class WrapClass_wxFrame : public WrapClass<wxFrame>
    , public   WrapClass_wxFrameBase
{
  DEFINE_CLASS(WrapClass_wxFrame);

  protected:
    typedef WrapClass<wxFrame>::ptr _parentclass_ptr;
    typedef wxFrame ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFrame>& GetObj() const { return WrapClass<wxFrame>::GetObj(); }

    /// Constructor
    WrapClass_wxFrame(boost::shared_ptr<wxFrame > si): 
    WrapClass<wxFrame>(si)
    , WrapClass_wxFrameBase(si)
    {}

    /// Destructor
    ~WrapClass_wxFrame()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrame_1,"Constructor wxFrame::wxFrame() (http://docs.wxwidgets.org/stable/wx_wxframe.html#wxframe).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrame,"Constructor wxFrame::wxFrame() (http://docs.wxwidgets.org/stable/wx_wxframe.html#wxframe).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrame_2,"Constructor wxFrame::wxFrame(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr) (http://docs.wxwidgets.org/stable/wx_wxframe.html#wxframe).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFrame*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxFrame::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#create)")
    ADD_CLASS_METHOD(CreateStatusBar,"wxStatusBar * wxFrame::CreateStatusBar(int number = 1, long int style = 65552, wxWindowID id = 0, wxString const & name = wxStatusLineNameStr)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#createstatusbar)")
    ADD_CLASS_METHOD(SetStatusBar,"void wxFrame::SetStatusBar(wxStatusBar * statbar)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#setstatusbar)")
    ADD_CLASS_METHOD(CreateToolBar,"wxToolBar * wxFrame::CreateToolBar(long int style = -0x00000000000000001, wxWindowID id = -0x00000000000000001, wxString const & name = wxToolBarNameStr)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#createtoolbar)")
    ADD_CLASS_METHOD(SetToolBar,"void wxFrame::SetToolBar(wxToolBar * toolbar)  (http://docs.wxwidgets.org/stable/wx_wxframe.html#settoolbar)")
    ADD_CLASS_METHOD(GetClientAreaOrigin,"wxPoint wxFrame::GetClientAreaOrigin()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#getclientareaorigin)")
    ADD_CLASS_METHOD(GtkOnSize,"void wxFrame::GtkOnSize()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#gtkonsize)")
    ADD_CLASS_METHOD(OnInternalIdle,"void wxFrame::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#oninternalidle)")
    ADD_CLASS_METHOD(UpdateMenuBarSize,"void wxFrame::UpdateMenuBarSize()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#updatemenubarsize)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxFrame::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxframe.html#getclassinfo)")





    void AddMethods(WrapClass<wxFrame>::ptr this_ptr );

};


#endif // _wrap_wxFrame_h
