/**
 * C++ Interface: wrap_wxScrollWinEvent
 *
 * Description: wrapping wxScrollWinEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxScrollWinEvent_h_
#define _wrap_wxScrollWinEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"



AMI_DECLARE_TYPE(wxScrollWinEvent);

// TODO: check for inheritence ...
class WrapClass_wxScrollWinEvent : public WrapClass<wxScrollWinEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxScrollWinEvent);

  protected:
    typedef WrapClass<wxScrollWinEvent>::ptr _parentclass_ptr;
    typedef wxScrollWinEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxScrollWinEvent>& GetObj() const { return WrapClass<wxScrollWinEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxScrollWinEvent(boost::shared_ptr<wxScrollWinEvent > si): 
    WrapClass<wxScrollWinEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxScrollWinEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxScrollWinEvent_1,"Constructor wxScrollWinEvent::wxScrollWinEvent(wxEventType commandType = wxEVT_NULL, int pos = 0, int orient = 0) (http://docs.wxwidgets.org/stable/wx_wxscrollwinevent.html#wxscrollwinevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxScrollWinEvent,"Constructor wxScrollWinEvent::wxScrollWinEvent() (http://docs.wxwidgets.org/stable/wx_wxscrollwinevent.html#wxscrollwinevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxScrollWinEvent_2,"Constructor wxScrollWinEvent::wxScrollWinEvent(wxScrollWinEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxscrollwinevent.html#wxscrollwinevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxScrollWinEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetOrientation,"int wxScrollWinEvent::GetOrientation()  (http://docs.wxwidgets.org/stable/wx_wxscrollwinevent.html#getorientation)")
    ADD_CLASS_METHOD(GetPosition,"int wxScrollWinEvent::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxscrollwinevent.html#getposition)")
    ADD_CLASS_METHOD(SetOrientation,"void wxScrollWinEvent::SetOrientation(int orient)  (http://docs.wxwidgets.org/stable/wx_wxscrollwinevent.html#setorientation)")
    ADD_CLASS_METHOD(SetPosition,"void wxScrollWinEvent::SetPosition(int pos)  (http://docs.wxwidgets.org/stable/wx_wxscrollwinevent.html#setposition)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxScrollWinEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxscrollwinevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxScrollWinEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxscrollwinevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxScrollWinEvent>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxScrollWinEvent_h
