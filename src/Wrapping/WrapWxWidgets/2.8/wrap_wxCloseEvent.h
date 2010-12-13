/**
 * C++ Interface: wrap_wxCloseEvent
 *
 * Description: wrapping wxCloseEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxCloseEvent_h_
#define _wrap_wxCloseEvent_h_

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


#ifndef wxCloseEvent_declared
  #define wxCloseEvent_declared
  AMI_DECLARE_TYPE(wxCloseEvent);
#endif

// TODO: check for inheritence ...
class WrapClass_wxCloseEvent : public WrapClass<wxCloseEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxCloseEvent);

  protected:
    typedef WrapClass<wxCloseEvent>::ptr _parentclass_ptr;
    typedef wxCloseEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxCloseEvent>& GetObj() const { return WrapClass<wxCloseEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxCloseEvent(boost::shared_ptr<wxCloseEvent > si): 
    WrapClass<wxCloseEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxCloseEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCloseEvent_1,"Constructor wxCloseEvent::wxCloseEvent(wxEventType type = wxEVT_NULL, int winid = 0) (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#wxcloseevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCloseEvent,"Constructor wxCloseEvent::wxCloseEvent() (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#wxcloseevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCloseEvent_2,"Constructor wxCloseEvent::wxCloseEvent(wxCloseEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#wxcloseevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxCloseEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SetLoggingOff,"void wxCloseEvent::SetLoggingOff(bool logOff)  (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#setloggingoff)")
    ADD_CLASS_METHOD(GetLoggingOff,"bool wxCloseEvent::GetLoggingOff()  (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#getloggingoff)")
    ADD_CLASS_METHOD(Veto,"void wxCloseEvent::Veto(bool veto = true)  (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#veto)")
    ADD_CLASS_METHOD(SetCanVeto,"void wxCloseEvent::SetCanVeto(bool canVeto)  (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#setcanveto)")
    ADD_CLASS_METHOD(CanVeto,"bool wxCloseEvent::CanVeto()  (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#canveto)")
    ADD_CLASS_METHOD(GetVeto,"bool wxCloseEvent::GetVeto()  (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#getveto)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxCloseEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxCloseEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxcloseevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxCloseEvent>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxCloseEvent_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxCloseEvent_h
