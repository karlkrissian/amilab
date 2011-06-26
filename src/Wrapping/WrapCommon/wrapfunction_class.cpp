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

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "paramlist.h"
#include "wrapfunction_class.h"

#include <wx/msgdlg.h>
#include <sstream>

std::string GetPointerAsString(void* p)
{
  std::string res;
  std::stringstream ss(res);
  ss << p;
  return res;
}


void WrapClassMember::ShowHelp() 
{
  std::string mess; 
  std::string paramlist_str;
  int nb_param = parameters_comments.size();
  
  // We consider that, when the help is displayed, the argument failure flag is set to true
  Set_arg_failure(true);

  for(int n=0;n<nb_param;n++) {
    //if ()
    paramlist_str += (boost::format("%1% p%2%") % paramtypes[n] %n).str(); 
    
    if (n<nb_param-1) paramlist_str += ", ";
  }

  mess += "\n";
  if (return_comments!="") 
    mess += "Variable ";
  mess += (boost::format("%1%(%2%)\n")% GetFunctionName() % paramlist_str).str();
  mess += "\n"; 
  if (nb_param>0) {
    //mess +=  "\n  Parameters:\n"; 
    for(int n=0;n<nb_param;n++) {
      mess +=  (boost::format("    - p%1%: %2% \n") % n % parameters_comments[n]).str(); 
    }
  }
  mess += "\n"; 
  mess +=  (boost::format("    %s\n") % GetDescription()).str(); 

  if (return_comments!="") {
    mess += "\n";
    mess += "  Returns: ";
    mess += return_comments;
    mess += "\n";
  }

  wxMessageDialog* msg = new wxMessageDialog(NULL,wxString(mess.c_str(),wxConvUTF8),
      wxString::FromAscii("Info"),wxOK | wxICON_INFORMATION  );
  msg->ShowModal();
  msg->Destroy();
}

