
#ifndef _wxAmiEventHandler_h_
#define _wxAmiEventHandler_h_

#include "wx/wx.h"
#include "ami_function.h"
#include <wx/listctrl.h>
#include <wx/html/htmlwin.h>
#include <wx/dataview.h>

#ifndef wxCommandEvent_declared
  #define wxCommandEvent_declared
  AMI_DECLARE_TYPE(wxCommandEvent)
#endif

#ifndef wxChildFocusEvent_declared
  #define wxChildFocusEvent_declared
  AMI_DECLARE_TYPE(wxChildFocusEvent)
#endif    
  
#ifndef wxEraseEvent_declared
  #define wxEraseEvent_declared
  AMI_DECLARE_TYPE(wxEraseEvent)
#endif  

#ifndef wxFocusEvent_declared
  #define wxFocusEvent_declared
  AMI_DECLARE_TYPE(wxFocusEvent)
#endif  
  
#ifndef wxMouseEvent_declared
  #define wxMouseEvent_declared
  AMI_DECLARE_TYPE(wxMouseEvent)
#endif

#ifndef wxKeyEvent_declared
  #define wxKeyEvent_declared
  AMI_DECLARE_TYPE(wxKeyEvent)
#endif

#ifndef wxListEvent_declared
  #define wxListEvent_declared
  AMI_DECLARE_TYPE(wxListEvent)
#endif

#ifndef wxHtmlCellEvent_declared
  #define wxHtmlCellEvent_declared
  AMI_DECLARE_TYPE(wxHtmlCellEvent)
#endif

#ifndef wxHtmlLinkEvent_declared
  #define wxHtmlLinkEvent_declared
  AMI_DECLARE_TYPE(wxHtmlLinkEvent)
#endif

#ifndef wxCloseEvent_declared
  #define wxCloseEvent_declared
  AMI_DECLARE_TYPE(wxCloseEvent)
#endif

#ifndef wxSizeEvent_declared
  #define wxSizeEvent_declared
  AMI_DECLARE_TYPE(wxSizeEvent)
#endif

#ifndef wxPaintEvent_declared
  #define wxPaintEvent_declared
  AMI_DECLARE_TYPE(wxPaintEvent)
#endif

#ifndef wxMenuEvent_declared
  #define wxMenuEvent_declared
  AMI_DECLARE_TYPE(wxMenuEvent)
#endif

#ifndef wxDataViewEvent_declared
  #define wxDataViewEvent_declared
  AMI_DECLARE_TYPE(wxDataViewEvent)
#endif

void CB_ParamWin( void* cd );
void CallAmiFunction(AMIFunction* f, const ParamList::ptr& p);

/* Karl*/
class wxAmiEventHandler: public wxEvtHandler
{
  wxString text;
  wxObjectEventFunction* eventfunc;

  AMIFunction* callback_function;

  bool SendListEvent;
  bool SendCommandEvent;

//   Variable<AMIFunction>::ptr var;
//   int  n = 0;
// 
//   if (!get_var_param<AMIFunction>(var, p, n))     ClassHelpAndReturn;
// 
//   int nbp = this->_objectptr->GetObj()->NbParameters();
// 
//   this->_objectptr->GetObj()->ChangedValueCallback(nbp-1,
//               (void*) CB_ParamWin,
//               (void*) var->Pointer().get() );



  public:
    wxAmiEventHandler(AMIFunction* f=NULL) 
    {
      callback_function = f;
      SendListEvent=false;
      SendCommandEvent=false;
    }
    
    void SetSendListEvent(bool v) { SendListEvent = v; }
    bool GetSendListEvent() { return SendListEvent;}

    void SetSendCommandEvent(bool v) { SendCommandEvent = v; }
    bool GetSendCommandEvent()       { return SendCommandEvent;}

    void OnEvent(wxCommandEvent& event)
    {
      if (callback_function!=NULL)
      {
        if (SendCommandEvent){
          ParamList::ptr p(new ParamList());
          // Add the event to the list
          BasicVariable::ptr v = AMILabType<wxCommandEvent>::CreateVar((wxCommandEvent*)&event,true);
          p->AddParam(v);
          CallAmiFunction(callback_function,p);
        } else
        if (SendListEvent) {
          ParamList::ptr p(new ParamList());
          // Add the event to the list
          BasicVariable::ptr v = AMILabType<wxListEvent>::CreateVar((wxListEvent*)&event,true);
          p->AddParam(v);
          CallAmiFunction(callback_function,p);
        } else
          // give the event in parameter (would be nice ...)!!!
          CB_ParamWin((void*)callback_function);
      }
      else
        wxLogMessage(wxT("Callback function not available"));

      // if we don't skip the event, the other event handlers won't get it:
      // try commenting out this line and see what changes
      event.Skip();
    }
   
   
    void OnEraseEvent(wxEraseEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxEraseEvent>::CreateVar(
                                                  (wxEraseEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }
   
    void OnFocusEvent(wxFocusEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxFocusEvent>::CreateVar((wxFocusEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }
   
   
    void OnChildFocusEvent(wxChildFocusEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxChildFocusEvent>::CreateVar((wxChildFocusEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }
    

    void OnMouseEvent(wxMouseEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxMouseEvent>::CreateVar((wxMouseEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }
    
    
    void OnKeyEvent(wxKeyEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxKeyEvent>::CreateVar((wxKeyEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }

    void OnHtmlCellEvent(wxHtmlCellEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxHtmlCellEvent>::CreateVar((wxHtmlCellEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }

    void OnHtmlLinkEvent(wxHtmlLinkEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxHtmlLinkEvent>::CreateVar((wxHtmlLinkEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }

    void OnCloseEvent(wxCloseEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxCloseEvent>::CreateVar((wxCloseEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }

    void OnPaintEvent(wxPaintEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxPaintEvent>::CreateVar((wxPaintEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }

    void OnSizeEvent(wxSizeEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxSizeEvent>::CreateVar((wxSizeEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }

    void OnListEvent(wxListEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxListEvent>::CreateVar(
          (wxListEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }

    void OnMenuEvent(wxMenuEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxMenuEvent>::CreateVar(
          (wxMenuEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }

    void OnDataViewEvent(wxDataViewEvent& event)
    {
      if (callback_function!=NULL)
      {
        ParamList::ptr p(new ParamList());
        // Add the event to the list
        BasicVariable::ptr v = AMILabType<wxDataViewEvent>::CreateVar(
          (wxDataViewEvent*)&event,true);
        p->AddParam(v);
        CallAmiFunction(callback_function,p);
      }
      else
        wxLogMessage(wxT("Callback function not available"));
    }

//     void OnListEvent(wxListEvent& event)
//     {
//       if (callback_function!=NULL)
//       {
//         if (!SendListEvent) {
//           // give the event in parameter (would be nice ...)!!!
//           CB_ParamWin((void*)callback_function);
//         } else {
//           ParamList::ptr p(new ParamList());
//           // Add the event to the list
//           BasicVariable::ptr v = AMILabType<wxListEvent>::CreateVar((wxListEvent*)&event,true);
//           p->AddParam(v);
// 
//           CallAmiFunction(callback_function,p);
//         }
//       }
//       else
//         wxLogMessage(wxT("Callback function not available"));
// 
//       // if we don't skip the event, the other event handlers won't get it:
//       // try commenting out this line and see what changes
//       event.Skip();
//     }

    wxObjectEventFunction* GetEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxCommandEventHandler(wxAmiEventHandler::OnEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetEraseEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxEraseEventHandler(wxAmiEventHandler::OnEraseEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetFocusEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxFocusEventHandler(wxAmiEventHandler::OnFocusEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetChildFocusEventFunction() {
      // TODO: delete the new allocation wxChildFocusEvent
      eventfunc = new wxObjectEventFunction(wxChildFocusEventHandler(wxAmiEventHandler::OnChildFocusEvent));
      return eventfunc;
    }
    
    wxObjectEventFunction* GetMouseEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxMouseEventHandler(wxAmiEventHandler::OnMouseEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetKeyEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxCharEventHandler(wxAmiEventHandler::OnKeyEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetHtmlCellEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxHtmlCellEventHandler(wxAmiEventHandler::OnHtmlCellEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetHtmlLinkEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxHtmlLinkEventHandler(wxAmiEventHandler::OnHtmlLinkEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetCloseEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxCloseEventHandler(wxAmiEventHandler::OnCloseEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetPaintEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxPaintEventHandler(wxAmiEventHandler::OnPaintEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetSizeEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxSizeEventHandler(wxAmiEventHandler::OnSizeEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetListEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxListEventHandler(wxAmiEventHandler::OnListEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetMenuEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxMenuEventHandler(wxAmiEventHandler::OnMenuEvent));
      return eventfunc;
    }

    wxObjectEventFunction* GetDataViewEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxDataViewEventHandler(wxAmiEventHandler::OnDataViewEvent));
      return eventfunc;
    }
};
/*--*/

#endif // _wxAmiEventHandler_h_
