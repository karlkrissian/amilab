/**
 * C++ Interface: wrap_wxSysColourChangedEvent
 *
 * Description: wrapping wxSysColourChangedEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxSysColourChangedEvent_h_
#define _wrap_wxSysColourChangedEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"



AMI_DECLARE_TYPE(wxSysColourChangedEvent);

// TODO: check for inheritence ...
class WrapClass_wxSysColourChangedEvent : public WrapClass<wxSysColourChangedEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxSysColourChangedEvent);

  protected:
    typedef WrapClass<wxSysColourChangedEvent>::ptr _parentclass_ptr;
    typedef wxSysColourChangedEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxSysColourChangedEvent>& GetObj() const { return WrapClass<wxSysColourChangedEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxSysColourChangedEvent(boost::shared_ptr<wxSysColourChangedEvent > si): 
    WrapClass<wxSysColourChangedEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxSysColourChangedEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSysColourChangedEvent_1,"Constructor wxSysColourChangedEvent::wxSysColourChangedEvent(wxSysColourChangedEvent const & param0) (http://docs.wxwidgets.org/stable/wx_wxsyscolourchangedevent.html#wxsyscolourchangedevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSysColourChangedEvent,"Constructor wxSysColourChangedEvent::wxSysColourChangedEvent() (http://docs.wxwidgets.org/stable/wx_wxsyscolourchangedevent.html#wxsyscolourchangedevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSysColourChangedEvent_2,"Constructor wxSysColourChangedEvent::wxSysColourChangedEvent() (http://docs.wxwidgets.org/stable/wx_wxsyscolourchangedevent.html#wxsyscolourchangedevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSysColourChangedEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Clone,"wxEvent * wxSysColourChangedEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxsyscolourchangedevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxSysColourChangedEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxsyscolourchangedevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxSysColourChangedEvent>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxSysColourChangedEvent_h
