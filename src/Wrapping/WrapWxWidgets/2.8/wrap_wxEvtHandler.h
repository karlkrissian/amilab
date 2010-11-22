/**
 * C++ Interface: wrap_wxEvtHandler
 *
 * Description: wrapping wxEvtHandler
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxEvtHandler_h_
#define _wrap_wxEvtHandler_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


AMI_DECLARE_TYPE(wxEvtHandler);

// TODO: check for inheritence ...
class WrapClass_wxEvtHandler : public WrapClass<wxEvtHandler>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxEvtHandler);

  protected:
    typedef WrapClass<wxEvtHandler>::ptr _parentclass_ptr;
    typedef wxEvtHandler ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxEvtHandler>& GetObj() const { return WrapClass<wxEvtHandler>::GetObj(); }

    /// Constructor
    WrapClass_wxEvtHandler(boost::shared_ptr<wxEvtHandler > si): 
    WrapClass<wxEvtHandler>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxEvtHandler()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxEvtHandler,"Constructor wxEvtHandler::wxEvtHandler() (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#wxevthandler).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxEvtHandler*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(ProcessEventIfMatches,"bool wxEvtHandler::ProcessEventIfMatches(wxEventTableEntryBase const & tableEntry, wxEvtHandler * handler, wxEvent & event) (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#processeventifmatches).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetNextHandler,"wxEvtHandler * wxEvtHandler::GetNextHandler()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#getnexthandler)")
    ADD_CLASS_METHOD(GetPreviousHandler,"wxEvtHandler * wxEvtHandler::GetPreviousHandler()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#getprevioushandler)")
    ADD_CLASS_METHOD(SetNextHandler,"void wxEvtHandler::SetNextHandler(wxEvtHandler * handler)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#setnexthandler)")
    ADD_CLASS_METHOD(SetPreviousHandler,"void wxEvtHandler::SetPreviousHandler(wxEvtHandler * handler)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#setprevioushandler)")
    ADD_CLASS_METHOD(SetEvtHandlerEnabled,"void wxEvtHandler::SetEvtHandlerEnabled(bool enabled)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#setevthandlerenabled)")
    ADD_CLASS_METHOD(GetEvtHandlerEnabled,"bool wxEvtHandler::GetEvtHandlerEnabled()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#getevthandlerenabled)")
    ADD_CLASS_METHOD(ProcessEvent,"bool wxEvtHandler::ProcessEvent(wxEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#processevent)")
    ADD_CLASS_METHOD(AddPendingEvent,"void wxEvtHandler::AddPendingEvent(wxEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#addpendingevent)")
    ADD_CLASS_METHOD(ProcessPendingEvents,"void wxEvtHandler::ProcessPendingEvents()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#processpendingevents)")
    ADD_CLASS_METHOD(ProcessThreadEvent,"bool wxEvtHandler::ProcessThreadEvent(wxEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#processthreadevent)")
/* The following types are missing: _13558
    ADD_CLASS_METHOD(Connect_1,"void wxEvtHandler::Connect(int winid, int lastId, int eventType, wxObjectEventFunction func, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#connect)")
*/
    ADD_CLASS_METHOD(Connect,"wxEvtHandler::Connect()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#connect)")
/* The following types are missing: _13558
    ADD_CLASS_METHOD(Connect_2,"void wxEvtHandler::Connect(int winid, int eventType, wxObjectEventFunction func, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#connect)")
*/
/* The following types are missing: _13558
    ADD_CLASS_METHOD(Connect_3,"void wxEvtHandler::Connect(int eventType, wxObjectEventFunction func, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#connect)")
*/
/* The following types are missing: _13558
    ADD_CLASS_METHOD(Disconnect_1,"bool wxEvtHandler::Disconnect(int winid, int lastId, wxEventType eventType, wxObjectEventFunction func = 0l, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#disconnect)")
*/
    ADD_CLASS_METHOD(Disconnect,"wxEvtHandler::Disconnect()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#disconnect)")
/* The following types are missing: _13558
    ADD_CLASS_METHOD(Disconnect_2,"bool wxEvtHandler::Disconnect(int winid = wxID_ANY, wxEventType eventType = wxEVT_NULL, wxObjectEventFunction func = 0l, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#disconnect)")
*/
/* The following types are missing: _13558
    ADD_CLASS_METHOD(Disconnect_3,"bool wxEvtHandler::Disconnect(wxEventType eventType, wxObjectEventFunction func, wxObject * userData = 0u, wxEvtHandler * eventSink = 0u)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#disconnect)")
*/
    ADD_CLASS_METHOD(GetDynamicEventTable,"wxList * wxEvtHandler::GetDynamicEventTable()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#getdynamiceventtable)")
    ADD_CLASS_METHOD(SetClientObject,"void wxEvtHandler::SetClientObject(wxClientData * data)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#setclientobject)")
    ADD_CLASS_METHOD(GetClientObject,"wxClientData * wxEvtHandler::GetClientObject()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#getclientobject)")
/* The following types are missing: void
    ADD_CLASS_METHOD(SetClientData,"void wxEvtHandler::SetClientData(void * data)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#setclientdata)")
*/
    ADD_CLASS_METHOD(GetClientData,"void * wxEvtHandler::GetClientData()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#getclientdata)")
    ADD_CLASS_METHOD(SearchEventTable,"bool wxEvtHandler::SearchEventTable(wxEventTable & table, wxEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#searcheventtable)")
    ADD_CLASS_METHOD(SearchDynamicEventTable,"bool wxEvtHandler::SearchDynamicEventTable(wxEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#searchdynamiceventtable)")
    ADD_CLASS_METHOD(ClearEventLocker,"void wxEvtHandler::ClearEventLocker()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#cleareventlocker)")
    ADD_CLASS_METHOD(ClearEventHashTable,"void wxEvtHandler::ClearEventHashTable()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#cleareventhashtable)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxEvtHandler::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxevthandler.html#getclassinfo)")





    void AddMethods(WrapClass<wxEvtHandler>::ptr this_ptr );

};


#endif // _wrap_wxEvtHandler_h
