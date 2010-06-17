//
// C++ Interface: wrapfunction_class
//
// Description: Prototype for wrapping functions
// based on http://www.parashift.com/c++-faq-lite/pointers-to-members.html#faq-33.1
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrapfunction_class.h"

#include <wx/msgdlg.h>

void WrapClassMember::ShowHelp() 
{
  std::string mess; 
  std::string paramlist_str;
  int nb_param = parameters_comments.size();
  

  for(int n=0;n<nb_param;n++) {
    //if ()
    paramlist_str += (boost::format("%1% p%2%") % paramtypes[n] %n).str(); 
    
    if (n<nb_param-1) paramlist_str += ", ";
  }

  mess += "\n";
  if (return_comments!="") 
    mess += "Variable ";
  mess += (boost::format("%1%(%2%)\n")% functionname % paramlist_str).str();
  mess += "\n"; 
  if (nb_param>0) {
    //mess +=  "\n  Parameters:\n"; 
    for(int n=0;n<nb_param;n++) {
      mess +=  (boost::format("    - p%1%: %2% \n") % n % parameters_comments[n]).str(); 
    }
  }
  mess += "\n"; 
  mess +=  (boost::format("    %s\n") % description).str(); 

  if (return_comments!="") {
    mess += "\n";
    mess += "  Returns: ";
    mess += return_comments;
    mess += "\n";
  }

  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),
      wxString::FromAscii("Info"),wxOK | wxICON_INFORMATION  );
  msg->ShowModal();
  msg->Destroy();
}

