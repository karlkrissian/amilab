/**
 * C++ Interface: wrap_wxMouseEvent
 *
 * Description: wrapping wxMouseEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMouseEvent_h_
#define _wrap_wxMouseEvent_h_

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


#ifndef wxMouseEvent_declared
  #define wxMouseEvent_declared
  AMI_DECLARE_TYPE(wxMouseEvent);
#endif

// TODO: check for inheritence ...
class WrapClass_wxMouseEvent : public WrapClass<wxMouseEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxMouseEvent);

  protected:
    typedef WrapClass<wxMouseEvent>::ptr _parentclass_ptr;
    typedef wxMouseEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMouseEvent>& GetObj() const { return WrapClass<wxMouseEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxMouseEvent(boost::shared_ptr<wxMouseEvent > si): 
    WrapClass<wxMouseEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxMouseEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMouseEvent_1,"Constructor wxMouseEvent::wxMouseEvent(wxEventType mouseType = wxEVT_NULL) (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#wxmouseevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMouseEvent,"Constructor wxMouseEvent::wxMouseEvent() (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#wxmouseevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMouseEvent_2,"Constructor wxMouseEvent::wxMouseEvent(wxMouseEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#wxmouseevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMouseEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(IsButton,"bool wxMouseEvent::IsButton()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#isbutton)")
    ADD_CLASS_METHOD(ButtonDown,"bool wxMouseEvent::ButtonDown(int but = wxMOUSE_BTN_ANY)  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#buttondown)")
    ADD_CLASS_METHOD(ButtonDClick,"bool wxMouseEvent::ButtonDClick(int but = wxMOUSE_BTN_ANY)  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#buttondclick)")
    ADD_CLASS_METHOD(ButtonUp,"bool wxMouseEvent::ButtonUp(int but = wxMOUSE_BTN_ANY)  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#buttonup)")
    ADD_CLASS_METHOD(Button,"bool wxMouseEvent::Button(int but)  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#button)")
    ADD_CLASS_METHOD(ButtonIsDown,"bool wxMouseEvent::ButtonIsDown(int but)  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#buttonisdown)")
    ADD_CLASS_METHOD(GetButton,"int wxMouseEvent::GetButton()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getbutton)")
    ADD_CLASS_METHOD(ControlDown,"bool wxMouseEvent::ControlDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#controldown)")
    ADD_CLASS_METHOD(MetaDown,"bool wxMouseEvent::MetaDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#metadown)")
    ADD_CLASS_METHOD(AltDown,"bool wxMouseEvent::AltDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#altdown)")
    ADD_CLASS_METHOD(ShiftDown,"bool wxMouseEvent::ShiftDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#shiftdown)")
    ADD_CLASS_METHOD(CmdDown,"bool wxMouseEvent::CmdDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#cmddown)")
    ADD_CLASS_METHOD(LeftDown,"bool wxMouseEvent::LeftDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#leftdown)")
    ADD_CLASS_METHOD(MiddleDown,"bool wxMouseEvent::MiddleDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#middledown)")
    ADD_CLASS_METHOD(RightDown,"bool wxMouseEvent::RightDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#rightdown)")
    ADD_CLASS_METHOD(LeftUp,"bool wxMouseEvent::LeftUp()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#leftup)")
    ADD_CLASS_METHOD(MiddleUp,"bool wxMouseEvent::MiddleUp()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#middleup)")
    ADD_CLASS_METHOD(RightUp,"bool wxMouseEvent::RightUp()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#rightup)")
    ADD_CLASS_METHOD(LeftDClick,"bool wxMouseEvent::LeftDClick()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#leftdclick)")
    ADD_CLASS_METHOD(MiddleDClick,"bool wxMouseEvent::MiddleDClick()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#middledclick)")
    ADD_CLASS_METHOD(RightDClick,"bool wxMouseEvent::RightDClick()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#rightdclick)")
    ADD_CLASS_METHOD(LeftIsDown,"bool wxMouseEvent::LeftIsDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#leftisdown)")
    ADD_CLASS_METHOD(MiddleIsDown,"bool wxMouseEvent::MiddleIsDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#middleisdown)")
    ADD_CLASS_METHOD(RightIsDown,"bool wxMouseEvent::RightIsDown()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#rightisdown)")
    ADD_CLASS_METHOD(Dragging,"bool wxMouseEvent::Dragging()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#dragging)")
    ADD_CLASS_METHOD(Moving,"bool wxMouseEvent::Moving()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#moving)")
    ADD_CLASS_METHOD(Entering,"bool wxMouseEvent::Entering()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#entering)")
    ADD_CLASS_METHOD(Leaving,"bool wxMouseEvent::Leaving()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#leaving)")
    ADD_CLASS_METHOD(GetPosition_1,"void wxMouseEvent::GetPosition(wxCoord * xpos, wxCoord * ypos)  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getposition)")
    ADD_CLASS_METHOD(GetPosition,"wxMouseEvent::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_2,"void wxMouseEvent::GetPosition(long int * xpos, long int * ypos)  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getposition)")
    ADD_CLASS_METHOD(GetPosition_3,"wxPoint wxMouseEvent::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getposition)")
    ADD_CLASS_METHOD(GetLogicalPosition,"wxPoint wxMouseEvent::GetLogicalPosition(wxDC const & dc)  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getlogicalposition)")
    ADD_CLASS_METHOD(GetX,"wxCoord wxMouseEvent::GetX()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getx)")
    ADD_CLASS_METHOD(GetY,"wxCoord wxMouseEvent::GetY()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#gety)")
    ADD_CLASS_METHOD(GetWheelRotation,"int wxMouseEvent::GetWheelRotation()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getwheelrotation)")
    ADD_CLASS_METHOD(GetWheelDelta,"int wxMouseEvent::GetWheelDelta()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getwheeldelta)")
    ADD_CLASS_METHOD(GetLinesPerAction,"int wxMouseEvent::GetLinesPerAction()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getlinesperaction)")
    ADD_CLASS_METHOD(IsPageScroll,"bool wxMouseEvent::IsPageScroll()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#ispagescroll)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxMouseEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxMouseEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxMouseEvent & wxMouseEvent::operator =(wxMouseEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxmouseevent.html#__assign__)")




    void AddMethods(WrapClass<wxMouseEvent>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxMouseEvent_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxMouseEvent_h
