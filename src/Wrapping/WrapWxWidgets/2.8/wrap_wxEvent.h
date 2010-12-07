/**
 * C++ Interface: wrap_wxEvent
 *
 * Description: wrapping wxEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxEvent_h_
#define _wrap_wxEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxEvent);

// TODO: check for inheritence ...
class WrapClass_wxEvent : public WrapClass<wxEvent>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxEvent);

  protected:
    typedef WrapClass<wxEvent>::ptr _parentclass_ptr;
    typedef wxEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxEvent>& GetObj() const { return WrapClass<wxEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxEvent(boost::shared_ptr<wxEvent > si): 
    WrapClass<wxEvent>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetEventType,"void wxEvent::SetEventType(wxEventType typ)  (http://docs.wxwidgets.org/stable/wx_wxevent.html#seteventtype)")
    ADD_CLASS_METHOD(GetEventType,"wxEventType wxEvent::GetEventType()  (http://docs.wxwidgets.org/stable/wx_wxevent.html#geteventtype)")
    ADD_CLASS_METHOD(GetEventObject,"wxObject * wxEvent::GetEventObject()  (http://docs.wxwidgets.org/stable/wx_wxevent.html#geteventobject)")
    ADD_CLASS_METHOD(SetEventObject,"void wxEvent::SetEventObject(wxObject * obj)  (http://docs.wxwidgets.org/stable/wx_wxevent.html#seteventobject)")
    ADD_CLASS_METHOD(GetTimestamp,"long int wxEvent::GetTimestamp()  (http://docs.wxwidgets.org/stable/wx_wxevent.html#gettimestamp)")
    ADD_CLASS_METHOD(SetTimestamp,"void wxEvent::SetTimestamp(long int ts = 0)  (http://docs.wxwidgets.org/stable/wx_wxevent.html#settimestamp)")
    ADD_CLASS_METHOD(GetId,"int wxEvent::GetId()  (http://docs.wxwidgets.org/stable/wx_wxevent.html#getid)")
    ADD_CLASS_METHOD(SetId,"void wxEvent::SetId(int Id)  (http://docs.wxwidgets.org/stable/wx_wxevent.html#setid)")
    ADD_CLASS_METHOD(Skip,"void wxEvent::Skip(bool skip = true)  (http://docs.wxwidgets.org/stable/wx_wxevent.html#skip)")
    ADD_CLASS_METHOD(GetSkipped,"bool wxEvent::GetSkipped()  (http://docs.wxwidgets.org/stable/wx_wxevent.html#getskipped)")
    ADD_CLASS_METHOD(IsCommandEvent,"bool wxEvent::IsCommandEvent()  (http://docs.wxwidgets.org/stable/wx_wxevent.html#iscommandevent)")
    ADD_CLASS_METHOD(ShouldPropagate,"bool wxEvent::ShouldPropagate()  (http://docs.wxwidgets.org/stable/wx_wxevent.html#shouldpropagate)")
    ADD_CLASS_METHOD(StopPropagation,"int wxEvent::StopPropagation()  (http://docs.wxwidgets.org/stable/wx_wxevent.html#stoppropagation)")
    ADD_CLASS_METHOD(ResumePropagation,"void wxEvent::ResumePropagation(int propagationLevel)  (http://docs.wxwidgets.org/stable/wx_wxevent.html#resumepropagation)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxEvent>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxEvent_h
