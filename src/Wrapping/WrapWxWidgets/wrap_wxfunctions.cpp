//
// C++ Implementation: wrap_wxfunctions
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_object.h"

#include "wrap_wxfunctions.h"

#include <wx/utils.h>


AMIObject::ptr AddWrap_wxfunctions()
{
  // Create new instance of the class
  AMIObject::ptr amiobject (new AMIObject);
  amiobject->SetName("wxfunctions");

  ADDLOCAL_OBJECTVAR_NAME(amiobject,C_wrap_varfunction,
                          "LaunchDefaultBrowser",
                          wrap_LaunchDefaultBrowser);

  return amiobject;
}

BasicVariable::ptr wrap_wxfunctions( ParamList* p)
{
    char functionname[] = "wx";
    char description[]=" \n\
      Adds wrapping for the wxwidgets samples and functions. \n\
            ";
    char parameters[] =" \n\
            ";

  AMIObject::ptr amiobject (AddWrap_wxfunctions());

  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>(amiobject));

  return varres;

}


/**
 * Launch the default browser with the given web page.
 * @param p 
 */
BasicVariable::ptr wrap_LaunchDefaultBrowser( ParamList* p)
{
    char functionname[] = "LaunchDefaultBrowser";
    char description[]=" \n\
      Launch the default browser with the given web page. \n\
            ";
    char parameters[] =" \n\
            - string: webpage.";

  int n=0;
  std::string* webpage = NULL;
  
  if (!get_val_ptr_param<string>( webpage,    p, n)) HelpAndReturnVarPtr;

  int res = wxLaunchDefaultBrowser(wxString::FromAscii(webpage->c_str()));

  RETURN_VAR(int, res);
}


