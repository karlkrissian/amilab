
#ifndef _wxAmiEventHandler_h_
#define _wxAmiEventHandler_h_

#include "wx/wx.h"

/* Karl*/
class wxAmiEventHandler: public wxEvtHandler
{
  wxString text;

  public:
    wxAmiEventHandler(wxString t) : text(t) {}
    
    void OnTest(wxCommandEvent& event)
    {
        wxLogMessage(text);

        // if we don't skip the event, the other event handlers won't get it:
        // try commenting out this line and see what changes
        event.Skip();
    }
    
    wxObjectEventFunction GetEventFunction() {
      return wxCommandEventHandler(wxAmiEventHandler::OnTest);
    }

};
/*--*/

#endif // _wxAmiEventHandler_h_
