/**
 * C++ Interface: wrap_wxActivateEvent
 *
 * Description: wrapping wxActivateEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxActivateEvent_h_
#define _wrap_wxActivateEvent_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"


#ifndef wxActivateEvent_declared
  #define wxActivateEvent_declared
  AMI_DECLARE_TYPE(wxActivateEvent);
#endif

// TODO: check for inheritence ...
class WrapClass_wxActivateEvent : public WrapClass<wxActivateEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxActivateEvent);

  protected:
    typedef WrapClass<wxActivateEvent>::ptr _parentclass_ptr;
    typedef wxActivateEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxActivateEvent>& GetObj() const { return WrapClass<wxActivateEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxActivateEvent(boost::shared_ptr<wxActivateEvent > si): 
    WrapClass<wxActivateEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxActivateEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxActivateEvent_1,"Constructor wxActivateEvent::wxActivateEvent(wxEventType type = wxEVT_NULL, bool active = true, int Id = 0) (http://docs.wxwidgets.org/stable/wx_wxactivateevent.html#wxactivateevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxActivateEvent,"Constructor wxActivateEvent::wxActivateEvent() (http://docs.wxwidgets.org/stable/wx_wxactivateevent.html#wxactivateevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxActivateEvent_2,"Constructor wxActivateEvent::wxActivateEvent(wxActivateEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxactivateevent.html#wxactivateevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxActivateEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetActive,"bool wxActivateEvent::GetActive()  (http://docs.wxwidgets.org/stable/wx_wxactivateevent.html#getactive)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxActivateEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxactivateevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxActivateEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxactivateevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxActivateEvent>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxActivateEvent_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxActivateEvent_h
