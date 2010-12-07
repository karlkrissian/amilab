/**
 * C++ Interface: wrap_wxFocusEvent
 *
 * Description: wrapping wxFocusEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFocusEvent_h_
#define _wrap_wxFocusEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"



AMI_DECLARE_TYPE(wxFocusEvent);

// TODO: check for inheritence ...
class WrapClass_wxFocusEvent : public WrapClass<wxFocusEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxFocusEvent);

  protected:
    typedef WrapClass<wxFocusEvent>::ptr _parentclass_ptr;
    typedef wxFocusEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFocusEvent>& GetObj() const { return WrapClass<wxFocusEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxFocusEvent(boost::shared_ptr<wxFocusEvent > si): 
    WrapClass<wxFocusEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxFocusEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFocusEvent_1,"Constructor wxFocusEvent::wxFocusEvent(wxEventType type = wxEVT_NULL, int winid = 0) (http://docs.wxwidgets.org/stable/wx_wxfocusevent.html#wxfocusevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFocusEvent,"Constructor wxFocusEvent::wxFocusEvent() (http://docs.wxwidgets.org/stable/wx_wxfocusevent.html#wxfocusevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFocusEvent_2,"Constructor wxFocusEvent::wxFocusEvent(wxFocusEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxfocusevent.html#wxfocusevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFocusEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetWindow,"wxWindow * wxFocusEvent::GetWindow()  (http://docs.wxwidgets.org/stable/wx_wxfocusevent.html#getwindow)")
    ADD_CLASS_METHOD(SetWindow,"void wxFocusEvent::SetWindow(wxWindow * win)  (http://docs.wxwidgets.org/stable/wx_wxfocusevent.html#setwindow)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxFocusEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxfocusevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxFocusEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxfocusevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxFocusEvent>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxFocusEvent_h
