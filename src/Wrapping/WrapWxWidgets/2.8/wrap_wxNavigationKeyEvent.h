/**
 * C++ Interface: wrap_wxNavigationKeyEvent
 *
 * Description: wrapping wxNavigationKeyEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxNavigationKeyEvent_h_
#define _wrap_wxNavigationKeyEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"



AMI_DECLARE_TYPE(wxNavigationKeyEvent);

// TODO: check for inheritence ...
class WrapClass_wxNavigationKeyEvent : public WrapClass<wxNavigationKeyEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxNavigationKeyEvent);

  protected:
    typedef WrapClass<wxNavigationKeyEvent>::ptr _parentclass_ptr;
    typedef wxNavigationKeyEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxNavigationKeyEvent>& GetObj() const { return WrapClass<wxNavigationKeyEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxNavigationKeyEvent(boost::shared_ptr<wxNavigationKeyEvent > si): 
    WrapClass<wxNavigationKeyEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxNavigationKeyEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxNavigationKeyEvent_1,"Constructor wxNavigationKeyEvent::wxNavigationKeyEvent() (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#wxnavigationkeyevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxNavigationKeyEvent,"Constructor wxNavigationKeyEvent::wxNavigationKeyEvent() (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#wxnavigationkeyevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxNavigationKeyEvent_2,"Constructor wxNavigationKeyEvent::wxNavigationKeyEvent(wxNavigationKeyEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#wxnavigationkeyevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxNavigationKeyEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetDirection,"bool wxNavigationKeyEvent::GetDirection()  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#getdirection)")
    ADD_CLASS_METHOD(SetDirection,"void wxNavigationKeyEvent::SetDirection(bool bForward)  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#setdirection)")
    ADD_CLASS_METHOD(IsWindowChange,"bool wxNavigationKeyEvent::IsWindowChange()  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#iswindowchange)")
    ADD_CLASS_METHOD(SetWindowChange,"void wxNavigationKeyEvent::SetWindowChange(bool bIs)  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#setwindowchange)")
    ADD_CLASS_METHOD(IsFromTab,"bool wxNavigationKeyEvent::IsFromTab()  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#isfromtab)")
    ADD_CLASS_METHOD(SetFromTab,"void wxNavigationKeyEvent::SetFromTab(bool bIs)  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#setfromtab)")
    ADD_CLASS_METHOD(GetCurrentFocus,"wxWindow * wxNavigationKeyEvent::GetCurrentFocus()  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#getcurrentfocus)")
    ADD_CLASS_METHOD(SetCurrentFocus,"void wxNavigationKeyEvent::SetCurrentFocus(wxWindow * win)  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#setcurrentfocus)")
    ADD_CLASS_METHOD(SetFlags,"void wxNavigationKeyEvent::SetFlags(long int flags)  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#setflags)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxNavigationKeyEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxNavigationKeyEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxnavigationkeyevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxNavigationKeyEvent>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxNavigationKeyEvent_h
