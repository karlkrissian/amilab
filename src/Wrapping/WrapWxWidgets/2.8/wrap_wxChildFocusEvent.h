/**
 * C++ Interface: wrap_wxChildFocusEvent
 *
 * Description: wrapping wxChildFocusEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxChildFocusEvent_h_
#define _wrap_wxChildFocusEvent_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxCommandEvent.h"


#ifndef wxChildFocusEvent_declared
  #define wxChildFocusEvent_declared
  AMI_DECLARE_TYPE(wxChildFocusEvent);
#endif

// TODO: check for inheritence ...
class WrapClass_wxChildFocusEvent : public WrapClass<wxChildFocusEvent>
    , public   WrapClass_wxCommandEvent
{
  DEFINE_CLASS(WrapClass_wxChildFocusEvent);

  protected:
    typedef WrapClass<wxChildFocusEvent>::ptr _parentclass_ptr;
    typedef wxChildFocusEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxChildFocusEvent>& GetObj() const { return WrapClass<wxChildFocusEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxChildFocusEvent(boost::shared_ptr<wxChildFocusEvent > si): 
    WrapClass<wxChildFocusEvent>(si)
    , WrapClass_wxCommandEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxChildFocusEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxChildFocusEvent_1,"Constructor wxChildFocusEvent::wxChildFocusEvent(wxChildFocusEvent const & param0) (http://docs.wxwidgets.org/stable/wx_wxchildfocusevent.html#wxchildfocusevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxChildFocusEvent,"Constructor wxChildFocusEvent::wxChildFocusEvent() (http://docs.wxwidgets.org/stable/wx_wxchildfocusevent.html#wxchildfocusevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxChildFocusEvent_2,"Constructor wxChildFocusEvent::wxChildFocusEvent(wxWindow * win = 0l) (http://docs.wxwidgets.org/stable/wx_wxchildfocusevent.html#wxchildfocusevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxChildFocusEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetWindow,"wxWindow * wxChildFocusEvent::GetWindow()  (http://docs.wxwidgets.org/stable/wx_wxchildfocusevent.html#getwindow)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxChildFocusEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxchildfocusevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxChildFocusEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxchildfocusevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxChildFocusEvent>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxChildFocusEvent_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxChildFocusEvent_h
