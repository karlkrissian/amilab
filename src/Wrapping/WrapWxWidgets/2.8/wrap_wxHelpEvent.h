/**
 * C++ Interface: wrap_wxHelpEvent
 *
 * Description: wrapping wxHelpEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHelpEvent_h_
#define _wrap_wxHelpEvent_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxCommandEvent.h"



AMI_DECLARE_TYPE(wxHelpEvent);

// TODO: check for inheritence ...
class WrapClass_wxHelpEvent : public WrapClass<wxHelpEvent>
    , public   WrapClass_wxCommandEvent
{
  DEFINE_CLASS(WrapClass_wxHelpEvent);

  protected:
    typedef WrapClass<wxHelpEvent>::ptr _parentclass_ptr;
    typedef wxHelpEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHelpEvent>& GetObj() const { return WrapClass<wxHelpEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxHelpEvent(boost::shared_ptr<wxHelpEvent > si): 
    WrapClass<wxHelpEvent>(si)
    , WrapClass_wxCommandEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxHelpEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHelpEvent_1,"Constructor wxHelpEvent::wxHelpEvent(wxEventType type = wxEVT_NULL, wxWindowID winid = 0, wxPoint const & pt = wxDefaultPosition, wxHelpEvent::Origin origin = Origin_Unknown) (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#wxhelpevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHelpEvent,"Constructor wxHelpEvent::wxHelpEvent() (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#wxhelpevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHelpEvent_2,"Constructor wxHelpEvent::wxHelpEvent(wxHelpEvent const & event) (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#wxhelpevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHelpEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetPosition,"wxPoint const & wxHelpEvent::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#getposition)")
    ADD_CLASS_METHOD(SetPosition,"void wxHelpEvent::SetPosition(wxPoint const & pos)  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#setposition)")
    ADD_CLASS_METHOD(GetLink,"wxString const & wxHelpEvent::GetLink()  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#getlink)")
    ADD_CLASS_METHOD(SetLink,"void wxHelpEvent::SetLink(wxString const & link)  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#setlink)")
    ADD_CLASS_METHOD(GetTarget,"wxString const & wxHelpEvent::GetTarget()  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#gettarget)")
    ADD_CLASS_METHOD(SetTarget,"void wxHelpEvent::SetTarget(wxString const & target)  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#settarget)")
    ADD_CLASS_METHOD(Clone,"wxEvent * wxHelpEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#clone)")
    ADD_CLASS_METHOD(GetOrigin,"wxHelpEvent::Origin wxHelpEvent::GetOrigin()  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#getorigin)")
    ADD_CLASS_METHOD(SetOrigin,"void wxHelpEvent::SetOrigin(wxHelpEvent::Origin origin)  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#setorigin)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHelpEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhelpevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxHelpEvent>::ptr this_ptr );

};


#endif // _wrap_wxHelpEvent_h
