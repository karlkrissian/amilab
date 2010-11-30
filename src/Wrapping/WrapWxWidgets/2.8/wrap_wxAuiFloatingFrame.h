/**
 * C++ Interface: wrap_wxAuiFloatingFrame
 *
 * Description: wrapping wxAuiFloatingFrame
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiFloatingFrame_h_
#define _wrap_wxAuiFloatingFrame_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/aui/aui.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxMiniFrame.h"



AMI_DECLARE_TYPE(wxAuiFloatingFrame);

// TODO: check for inheritence ...
class WrapClass_wxAuiFloatingFrame : public WrapClass<wxAuiFloatingFrame>
    , public   WrapClass_wxMiniFrame
{
  DEFINE_CLASS(WrapClass_wxAuiFloatingFrame);

  protected:
    typedef WrapClass<wxAuiFloatingFrame>::ptr _parentclass_ptr;
    typedef wxAuiFloatingFrame ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiFloatingFrame>& GetObj() const { return WrapClass<wxAuiFloatingFrame>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiFloatingFrame(boost::shared_ptr<wxAuiFloatingFrame > si): 
    WrapClass<wxAuiFloatingFrame>(si)
    , WrapClass_wxMiniFrame(si)
    {}

    /// Destructor
    ~WrapClass_wxAuiFloatingFrame()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiFloatingFrame,"Constructor wxAuiFloatingFrame::wxAuiFloatingFrame(wxWindow * parent, wxAuiManager * owner_mgr, wxAuiPaneInfo const & pane, wxWindowID id = wxID_ANY, long int style = 541067338) (http://docs.wxwidgets.org/stable/wx_wxauifloatingframe.html#wxauifloatingframe).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiFloatingFrame*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetPaneWindow,"void wxAuiFloatingFrame::SetPaneWindow(wxAuiPaneInfo const & pane)  (http://docs.wxwidgets.org/stable/wx_wxauifloatingframe.html#setpanewindow)")
    ADD_CLASS_METHOD(GetOwnerManager,"wxAuiManager * wxAuiFloatingFrame::GetOwnerManager()  (http://docs.wxwidgets.org/stable/wx_wxauifloatingframe.html#getownermanager)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxAuiFloatingFrame::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxauifloatingframe.html#getclassinfo)")





    void AddMethods(WrapClass<wxAuiFloatingFrame>::ptr this_ptr );

};


#endif // _wrap_wxAuiFloatingFrame_h
