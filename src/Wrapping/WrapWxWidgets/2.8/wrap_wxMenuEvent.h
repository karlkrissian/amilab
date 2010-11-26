/**
 * C++ Interface: wrap_wxMenuEvent
 *
 * Description: wrapping wxMenuEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMenuEvent_h_
#define _wrap_wxMenuEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"


AMI_DECLARE_TYPE(wxMenuEvent);

// TODO: check for inheritence ...
class WrapClass_wxMenuEvent : public WrapClass<wxMenuEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxMenuEvent);

  protected:
    typedef WrapClass<wxMenuEvent>::ptr _parentclass_ptr;
    typedef wxMenuEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMenuEvent>& GetObj() const { return WrapClass<wxMenuEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxMenuEvent(boost::shared_ptr<wxMenuEvent > si): 
    WrapClass<wxMenuEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxMenuEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuEvent_1,"Constructor wxMenuEvent::wxMenuEvent(wxEventType type = wxEVT_NULL, int winid = 0, wxMenu * menu = 0l) (http://docs.wxwidgets.org/stable/wx_wxmenuevent.html#wxmenuevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuEvent,"Constructor wxMenuEvent::wxMenuEvent() (http://docs.wxwidgets.org/stable/wx_wxmenuevent.html#wxmenuevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuEvent_2,"Constructor wxMenuEvent::wxMenuEvent(wxMenuEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxmenuevent.html#wxmenuevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMenuEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetMenuId,"int wxMenuEvent::GetMenuId()  (http://docs.wxwidgets.org/stable/wx_wxmenuevent.html#getmenuid)")
    ADD_CLASS_METHOD(IsPopup,"bool wxMenuEvent::IsPopup()  (http://docs.wxwidgets.org/stable/wx_wxmenuevent.html#ispopup)")
    ADD_CLASS_METHOD(GetMenu,"wxMenu * wxMenuEvent::GetMenu()  (http://docs.wxwidgets.org/stable/wx_wxmenuevent.html#getmenu)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxMenuEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxmenuevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxMenuEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxmenuevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxMenuEvent>::ptr this_ptr );

};


#endif // _wrap_wxMenuEvent_h
