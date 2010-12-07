/**
 * C++ Interface: wrap_wxIdleEvent
 *
 * Description: wrapping wxIdleEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxIdleEvent_h_
#define _wrap_wxIdleEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"



AMI_DECLARE_TYPE(wxIdleEvent);

// TODO: check for inheritence ...
class WrapClass_wxIdleEvent : public WrapClass<wxIdleEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxIdleEvent);

  protected:
    typedef WrapClass<wxIdleEvent>::ptr _parentclass_ptr;
    typedef wxIdleEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxIdleEvent>& GetObj() const { return WrapClass<wxIdleEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxIdleEvent(boost::shared_ptr<wxIdleEvent > si): 
    WrapClass<wxIdleEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxIdleEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIdleEvent_1,"Constructor wxIdleEvent::wxIdleEvent() (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#wxidleevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIdleEvent,"Constructor wxIdleEvent::wxIdleEvent() (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#wxidleevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIdleEvent_2,"Constructor wxIdleEvent::wxIdleEvent(wxIdleEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#wxidleevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxIdleEvent*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(SetMode,"void wxIdleEvent::SetMode(wxIdleMode mode) (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#setmode).");
    ADD_CLASS_STATICMETHOD(GetMode,"wxIdleMode wxIdleEvent::GetMode() (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#getmode).");
    ADD_CLASS_STATICMETHOD(CanSend,"bool wxIdleEvent::CanSend(wxWindow * win) (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#cansend).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(RequestMore,"void wxIdleEvent::RequestMore(bool needMore = true)  (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#requestmore)")
    ADD_CLASS_METHOD(MoreRequested,"bool wxIdleEvent::MoreRequested()  (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#morerequested)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxIdleEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxIdleEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxidleevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxIdleEvent>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxIdleEvent_h
