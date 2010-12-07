/**
 * C++ Interface: wrap_wxSizeEvent
 *
 * Description: wrapping wxSizeEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxSizeEvent_h_
#define _wrap_wxSizeEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"



AMI_DECLARE_TYPE(wxSizeEvent);

// TODO: check for inheritence ...
class WrapClass_wxSizeEvent : public WrapClass<wxSizeEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxSizeEvent);

  protected:
    typedef WrapClass<wxSizeEvent>::ptr _parentclass_ptr;
    typedef wxSizeEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxSizeEvent>& GetObj() const { return WrapClass<wxSizeEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxSizeEvent(boost::shared_ptr<wxSizeEvent > si): 
    WrapClass<wxSizeEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxSizeEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizeEvent_1,"Constructor wxSizeEvent::wxSizeEvent() (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#wxsizeevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizeEvent,"Constructor wxSizeEvent::wxSizeEvent() (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#wxsizeevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizeEvent_2,"Constructor wxSizeEvent::wxSizeEvent(wxSize const & sz, int winid = 0) (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#wxsizeevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizeEvent_3,"Constructor wxSizeEvent::wxSizeEvent(wxSizeEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#wxsizeevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizeEvent_4,"Constructor wxSizeEvent::wxSizeEvent(wxRect const & rect, int id = 0) (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#wxsizeevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSizeEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetSize,"wxSize wxSizeEvent::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#getsize)")
    ADD_CLASS_METHOD(GetRect,"wxRect wxSizeEvent::GetRect()  (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#getrect)")
    ADD_CLASS_METHOD(SetRect,"void wxSizeEvent::SetRect(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#setrect)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxSizeEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxSizeEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxsizeevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxSizeEvent>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxSizeEvent_h
