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
  mess = (boost::format("\n %s ( listofparameters )\n\n ")% functionname).str();
  mess = mess + (boost::format("Description:\n %s \n") % description).str(); 
  mess = mess + (boost::format("Parameters:\n  %s \n") % parameters).str(); 
  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString::FromAscii(mess.c_str()),
      wxString::FromAscii("Info"),wxOK | wxICON_INFORMATION  );
  msg->ShowModal();
}

