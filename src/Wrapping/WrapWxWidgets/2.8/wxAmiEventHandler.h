
#ifndef _wxAmiEventHandler_h_
#define _wxAmiEventHandler_h_

#include "wx/wx.h"
#include "ami_function.h"

#ifndef wxCommandEvent_declared
  #define wxCommandEvent_declared
  AMI_DECLARE_TYPE(wxCommandEvent)
#endif

#ifndef wxListEvent_declared
  #define wxListEvent_declared
  AMI_DECLARE_TYPE(wxListEvent)
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
    }
    
    void SetSendListEvent(bool v) { SendListEvent = v; }
    bool GetSendListEvent() { return SendListEvent;}

    void OnEvent(wxCommandEvent& event)
    {
      if (callback_function!=NULL)
      {
        if (!SendListEvent) {
          // give the event in parameter (would be nice ...)!!!
          CB_ParamWin((void*)callback_function);
        } else {
          ParamList::ptr p(new ParamList());
          // Add the event to the list
          BasicVariable::ptr v = AMILabType<wxListEvent>::CreateVar((wxListEvent*)&event,true);
          p->AddParam(v);

          CallAmiFunction(callback_function,p);
        }
      }
      else
        wxLogMessage(wxT("Callback function not available"));

      // if we don't skip the event, the other event handlers won't get it:
      // try commenting out this line and see what changes
      event.Skip();
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

/*    wxObjectEventFunction* GetListEventFunction() {
      // TODO: delete the new allocation
      eventfunc = new wxObjectEventFunction(wxListEventHandler(wxAmiEventHandler::OnListEvent));
      return eventfunc;
    }*/
};
/*--*/

#endif // _wxAmiEventHandler_h_
