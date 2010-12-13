/**
 * C++ Interface: wrap_wxAuiManagerEvent
 *
 * Description: wrapping wxAuiManagerEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiManagerEvent_h_
#define _wrap_wxAuiManagerEvent_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"


#ifndef wxAuiManagerEvent_declared
  #define wxAuiManagerEvent_declared
  AMI_DECLARE_TYPE(wxAuiManagerEvent);
#endif

// TODO: check for inheritence ...
class WrapClass_wxAuiManagerEvent : public WrapClass<wxAuiManagerEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxAuiManagerEvent);

  protected:
    typedef WrapClass<wxAuiManagerEvent>::ptr _parentclass_ptr;
    typedef wxAuiManagerEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiManagerEvent>& GetObj() const { return WrapClass<wxAuiManagerEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiManagerEvent(boost::shared_ptr<wxAuiManagerEvent > si): 
    WrapClass<wxAuiManagerEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxAuiManagerEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiManagerEvent_1,"Constructor wxAuiManagerEvent::wxAuiManagerEvent(wxEventType type = wxEVT_NULL) (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#wxauimanagerevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiManagerEvent,"Constructor wxAuiManagerEvent::wxAuiManagerEvent() (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#wxauimanagerevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiManagerEvent_2,"Constructor wxAuiManagerEvent::wxAuiManagerEvent(wxAuiManagerEvent const & c) (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#wxauimanagerevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiManagerEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Clone,"wxEvent * wxAuiManagerEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#clone)")
    ADD_CLASS_METHOD(SetManager,"void wxAuiManagerEvent::SetManager(wxAuiManager * mgr)  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#setmanager)")
    ADD_CLASS_METHOD(SetPane,"void wxAuiManagerEvent::SetPane(wxAuiPaneInfo * p)  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#setpane)")
    ADD_CLASS_METHOD(SetButton,"void wxAuiManagerEvent::SetButton(int b)  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#setbutton)")
    ADD_CLASS_METHOD(SetDC,"void wxAuiManagerEvent::SetDC(wxDC * pdc)  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#setdc)")
    ADD_CLASS_METHOD(GetManager,"wxAuiManager * wxAuiManagerEvent::GetManager()  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#getmanager)")
    ADD_CLASS_METHOD(GetPane,"wxAuiPaneInfo * wxAuiManagerEvent::GetPane()  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#getpane)")
    ADD_CLASS_METHOD(GetButton,"int wxAuiManagerEvent::GetButton()  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#getbutton)")
    ADD_CLASS_METHOD(GetDC,"wxDC * wxAuiManagerEvent::GetDC()  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#getdc)")
    ADD_CLASS_METHOD(Veto,"void wxAuiManagerEvent::Veto(bool veto = true)  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#veto)")
    ADD_CLASS_METHOD(GetVeto,"bool wxAuiManagerEvent::GetVeto()  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#getveto)")
    ADD_CLASS_METHOD(SetCanVeto,"void wxAuiManagerEvent::SetCanVeto(bool can_veto)  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#setcanveto)")
    ADD_CLASS_METHOD(CanVeto,"bool wxAuiManagerEvent::CanVeto()  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#canveto)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxAuiManagerEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxauimanagerevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxAuiManagerEvent>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAuiManagerEvent_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxAuiManagerEvent_h
