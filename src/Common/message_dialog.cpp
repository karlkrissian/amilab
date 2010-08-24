
#include "message_dialog.h"

#include "AMILabConfig.h"
#include <wx/msgdlg.h>

void MessageDialog(std::string mess)
{
  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),
    wxString::FromAscii("Info"),wxOK | wxICON_INFORMATION  );
  msg->ShowModal();
  msg->Destroy();
}
