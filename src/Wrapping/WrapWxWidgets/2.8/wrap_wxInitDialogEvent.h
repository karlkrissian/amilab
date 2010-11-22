/**
 * C++ Interface: wrap_wxInitDialogEvent
 *
 * Description: wrapping wxInitDialogEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxInitDialogEvent_h_
#define _wrap_wxInitDialogEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"


AMI_DECLARE_TYPE(wxInitDialogEvent);

// TODO: check for inheritence ...
class WrapClass_wxInitDialogEvent : public WrapClass<wxInitDialogEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxInitDialogEvent);

  protected:
    typedef WrapClass<wxInitDialogEvent>::ptr _parentclass_ptr;
    typedef wxInitDialogEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxInitDialogEvent>& GetObj() const { return WrapClass<wxInitDialogEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxInitDialogEvent(boost::shared_ptr<wxInitDialogEvent > si): 
    WrapClass<wxInitDialogEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxInitDialogEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxInitDialogEvent_1,"Constructor wxInitDialogEvent::wxInitDialogEvent(wxInitDialogEvent const & param0) (http://docs.wxwidgets.org/stable/wx_wxinitdialogevent.html#wxinitdialogevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxInitDialogEvent,"Constructor wxInitDialogEvent::wxInitDialogEvent() (http://docs.wxwidgets.org/stable/wx_wxinitdialogevent.html#wxinitdialogevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxInitDialogEvent_2,"Constructor wxInitDialogEvent::wxInitDialogEvent(int Id = 0) (http://docs.wxwidgets.org/stable/wx_wxinitdialogevent.html#wxinitdialogevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxInitDialogEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Clone,"wxEvent * wxInitDialogEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxinitdialogevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxInitDialogEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxinitdialogevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxInitDialogEvent>::ptr this_ptr );

};


#endif // _wrap_wxInitDialogEvent_h
