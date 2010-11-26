/**
 * C++ Interface: wrap_wxKeyEvent
 *
 * Description: wrapping wxKeyEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxKeyEvent_h_
#define _wrap_wxKeyEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"



AMI_DECLARE_TYPE(wxKeyEvent);

// TODO: check for inheritence ...
class WrapClass_wxKeyEvent : public WrapClass<wxKeyEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxKeyEvent);

  protected:
    typedef WrapClass<wxKeyEvent>::ptr _parentclass_ptr;
    typedef wxKeyEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxKeyEvent>& GetObj() const { return WrapClass<wxKeyEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxKeyEvent(boost::shared_ptr<wxKeyEvent > si): 
    WrapClass<wxKeyEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxKeyEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxKeyEvent_1,"Constructor wxKeyEvent::wxKeyEvent(wxEventType keyType = wxEVT_NULL) (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#wxkeyevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxKeyEvent,"Constructor wxKeyEvent::wxKeyEvent() (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#wxkeyevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxKeyEvent_2,"Constructor wxKeyEvent::wxKeyEvent(wxKeyEvent const & evt) (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#wxkeyevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxKeyEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetModifiers,"int wxKeyEvent::GetModifiers()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getmodifiers)")
    ADD_CLASS_METHOD(ControlDown,"bool wxKeyEvent::ControlDown()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#controldown)")
    ADD_CLASS_METHOD(ShiftDown,"bool wxKeyEvent::ShiftDown()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#shiftdown)")
    ADD_CLASS_METHOD(MetaDown,"bool wxKeyEvent::MetaDown()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#metadown)")
    ADD_CLASS_METHOD(AltDown,"bool wxKeyEvent::AltDown()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#altdown)")
    ADD_CLASS_METHOD(CmdDown,"bool wxKeyEvent::CmdDown()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#cmddown)")
    ADD_CLASS_METHOD(HasModifiers,"bool wxKeyEvent::HasModifiers()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#hasmodifiers)")
    ADD_CLASS_METHOD(GetKeyCode,"int wxKeyEvent::GetKeyCode()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getkeycode)")
    ADD_CLASS_METHOD(GetUnicodeKey,"wxChar wxKeyEvent::GetUnicodeKey()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getunicodekey)")
    ADD_CLASS_METHOD(GetRawKeyCode,"wxUint32 wxKeyEvent::GetRawKeyCode()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getrawkeycode)")
    ADD_CLASS_METHOD(GetRawKeyFlags,"wxUint32 wxKeyEvent::GetRawKeyFlags()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getrawkeyflags)")
    ADD_CLASS_METHOD(GetPosition_1,"void wxKeyEvent::GetPosition(wxCoord * xpos, wxCoord * ypos)  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getposition)")
    ADD_CLASS_METHOD(GetPosition,"wxKeyEvent::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_2,"void wxKeyEvent::GetPosition(long int * xpos, long int * ypos)  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_3,"wxPoint wxKeyEvent::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getposition)")
    ADD_CLASS_METHOD(GetX,"wxCoord wxKeyEvent::GetX()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getx)")
    ADD_CLASS_METHOD(GetY,"wxCoord wxKeyEvent::GetY()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#gety)")
    ADD_CLASS_METHOD(KeyCode,"long int wxKeyEvent::KeyCode()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#keycode)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxKeyEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxKeyEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxKeyEvent & wxKeyEvent::operator =(wxKeyEvent const & evt) (http://docs.wxwidgets.org/stable/wx_wxkeyevent.html#__assign__)")




    void AddMethods(WrapClass<wxKeyEvent>::ptr this_ptr );

};


#endif // _wrap_wxKeyEvent_h
