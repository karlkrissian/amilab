/**
 * C++ Interface: wrap_wxCommandEvent
 *
 * Description: wrapping wxCommandEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxCommandEvent_h_
#define _wrap_wxCommandEvent_h_

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


#ifndef wxCommandEvent_declared
  #define wxCommandEvent_declared
  AMI_DECLARE_TYPE(wxCommandEvent);
#endif

// TODO: check for inheritence ...
class WrapClass_wxCommandEvent : public WrapClass<wxCommandEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxCommandEvent);

  protected:
    typedef WrapClass<wxCommandEvent>::ptr _parentclass_ptr;
    typedef wxCommandEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxCommandEvent>& GetObj() const { return WrapClass<wxCommandEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxCommandEvent(boost::shared_ptr<wxCommandEvent > si): 
    WrapClass<wxCommandEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxCommandEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCommandEvent_1,"Constructor wxCommandEvent::wxCommandEvent(wxEventType commandType = wxEVT_NULL, int winid = 0) (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#wxcommandevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCommandEvent,"Constructor wxCommandEvent::wxCommandEvent() (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#wxcommandevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxCommandEvent_2,"Constructor wxCommandEvent::wxCommandEvent(wxCommandEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#wxcommandevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxCommandEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
/* The following types are missing: void
    ADD_CLASS_METHOD(SetClientData,"void wxCommandEvent::SetClientData(void * clientData)  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#setclientdata)")
*/
    ADD_CLASS_METHOD(GetClientData,"void * wxCommandEvent::GetClientData()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#getclientdata)")
    ADD_CLASS_METHOD(SetClientObject,"void wxCommandEvent::SetClientObject(wxClientData * clientObject)  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#setclientobject)")
    ADD_CLASS_METHOD(GetClientObject,"wxClientData * wxCommandEvent::GetClientObject()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#getclientobject)")
    ADD_CLASS_METHOD(GetSelection,"int wxCommandEvent::GetSelection()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#getselection)")
    ADD_CLASS_METHOD(SetString,"void wxCommandEvent::SetString(wxString const & s)  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#setstring)")
    ADD_CLASS_METHOD(GetString,"wxString wxCommandEvent::GetString()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#getstring)")
    ADD_CLASS_METHOD(IsChecked,"bool wxCommandEvent::IsChecked()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#ischecked)")
    ADD_CLASS_METHOD(IsSelection,"bool wxCommandEvent::IsSelection()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#isselection)")
    ADD_CLASS_METHOD(SetExtraLong,"void wxCommandEvent::SetExtraLong(long int extraLong)  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#setextralong)")
    ADD_CLASS_METHOD(GetExtraLong,"long int wxCommandEvent::GetExtraLong()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#getextralong)")
    ADD_CLASS_METHOD(SetInt,"void wxCommandEvent::SetInt(int i)  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#setint)")
    ADD_CLASS_METHOD(GetInt,"int wxCommandEvent::GetInt()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#getint)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxCommandEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxCommandEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxcommandevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxCommandEvent>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxCommandEvent_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxCommandEvent_h
