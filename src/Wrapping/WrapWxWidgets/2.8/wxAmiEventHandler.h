
#ifndef _wxAmiEventHandler_h_
#define _wxAmiEventHandler_h_

#include "wx/wx.h"
#include "ami_function.h"

void CB_ParamWin( void* cd );

/* Karl*/
class wxAmiEventHandler: public wxEvtHandler
{
  wxString text;
  wxObjectEventFunction* eventfunc;

  AMIFunction* callback_function;

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
    }
    
    void OnTest(wxCommandEvent& event)
    {
      if (callback_function!=NULL)
      {
        // give the event in parameter (would be nice ...)!!!
        CB_ParamWin((void*)callback_function);
      }
      else
        wxLogMessage(wxT("Callback function not available"));

      // if we don't skip the event, the other event handlers won't get it:
      // try commenting out this line and see what changes
      event.Skip();
    }
    
    wxObjectEventFunction* GetEventFunction() {
      // TODO: deletec the new allocation
      eventfunc = new wxObjectEventFunction(wxCommandEventHandler(wxAmiEventHandler::OnTest));
      return eventfunc;
    }

};
/*--*/

#endif // _wxAmiEventHandler_h_
