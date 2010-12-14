/**
 * C++ Interface: wrap_wxUpdateUIEvent
 *
 * Description: wrapping wxUpdateUIEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxUpdateUIEvent_h_
#define _wrap_wxUpdateUIEvent_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxCommandEvent.h"


#ifndef wxUpdateUIEvent_declared
  #define wxUpdateUIEvent_declared
  AMI_DECLARE_TYPE(wxUpdateUIEvent);
#endif

// TODO: check for inheritence ...
class WrapClass_wxUpdateUIEvent : public WrapClass<wxUpdateUIEvent>
    , public   WrapClass_wxCommandEvent
{
  DEFINE_CLASS(WrapClass_wxUpdateUIEvent);

  protected:
    typedef WrapClass<wxUpdateUIEvent>::ptr _parentclass_ptr;
    typedef wxUpdateUIEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxUpdateUIEvent>& GetObj() const { return WrapClass<wxUpdateUIEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxUpdateUIEvent(boost::shared_ptr<wxUpdateUIEvent > si): 
    WrapClass<wxUpdateUIEvent>(si)
    , WrapClass_wxCommandEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxUpdateUIEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxUpdateUIEvent_1,"Constructor wxUpdateUIEvent::wxUpdateUIEvent(wxWindowID commandId = 0) (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#wxupdateuievent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxUpdateUIEvent,"Constructor wxUpdateUIEvent::wxUpdateUIEvent() (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#wxupdateuievent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxUpdateUIEvent_2,"Constructor wxUpdateUIEvent::wxUpdateUIEvent(wxUpdateUIEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#wxupdateuievent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxUpdateUIEvent*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(SetUpdateInterval,"void wxUpdateUIEvent::SetUpdateInterval(long int updateInterval) (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#setupdateinterval).");
    ADD_CLASS_STATICMETHOD(GetUpdateInterval,"long int wxUpdateUIEvent::GetUpdateInterval() (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getupdateinterval).");
    ADD_CLASS_STATICMETHOD(CanUpdate,"bool wxUpdateUIEvent::CanUpdate(wxWindowBase * win) (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#canupdate).");
    ADD_CLASS_STATICMETHOD(ResetUpdateTime,"void wxUpdateUIEvent::ResetUpdateTime() (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#resetupdatetime).");
    ADD_CLASS_STATICMETHOD(SetMode,"void wxUpdateUIEvent::SetMode(wxUpdateUIMode mode) (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#setmode).");
    ADD_CLASS_STATICMETHOD(GetMode,"wxUpdateUIMode wxUpdateUIEvent::GetMode() (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getmode).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetChecked,"bool wxUpdateUIEvent::GetChecked()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getchecked)")
    ADD_CLASS_METHOD(GetEnabled,"bool wxUpdateUIEvent::GetEnabled()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getenabled)")
    ADD_CLASS_METHOD(GetShown,"bool wxUpdateUIEvent::GetShown()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getshown)")
    ADD_CLASS_METHOD(GetText,"wxString wxUpdateUIEvent::GetText()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#gettext)")
    ADD_CLASS_METHOD(GetSetText,"bool wxUpdateUIEvent::GetSetText()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getsettext)")
    ADD_CLASS_METHOD(GetSetChecked,"bool wxUpdateUIEvent::GetSetChecked()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getsetchecked)")
    ADD_CLASS_METHOD(GetSetEnabled,"bool wxUpdateUIEvent::GetSetEnabled()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getsetenabled)")
    ADD_CLASS_METHOD(GetSetShown,"bool wxUpdateUIEvent::GetSetShown()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getsetshown)")
    ADD_CLASS_METHOD(Check,"void wxUpdateUIEvent::Check(bool check)  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#check)")
    ADD_CLASS_METHOD(Enable,"void wxUpdateUIEvent::Enable(bool enable)  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#enable)")
    ADD_CLASS_METHOD(Show,"void wxUpdateUIEvent::Show(bool show)  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#show)")
    ADD_CLASS_METHOD(SetText,"void wxUpdateUIEvent::SetText(wxString const & text)  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#settext)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxUpdateUIEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxUpdateUIEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxupdateuievent.html#getclassinfo)")





    void AddMethods(WrapClass<wxUpdateUIEvent>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxUpdateUIEvent_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxUpdateUIEvent_h
