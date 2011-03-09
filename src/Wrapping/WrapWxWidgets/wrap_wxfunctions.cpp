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

#include "wrap_wxString.h"

#include "AMILabConfig.h"

#ifdef AMI_USE_PRECOM_HEADERS
  #include "WrapWxWidgets_header.h"
#endif

#include "paramlist.h"
#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_object.h"

#include "wrap_wxfunctions.h"
#include<iostream>
#include <wx/utils.h>
#include <wx/string.h>

extern VarContexts  Vars;


AMIObject::ptr AddWrap_wxfunctions()
{
  // Create new instance of the class
  AMIObject::ptr amiobject (new AMIObject);
  amiobject->SetName("wxfunctions");

  ADDLOCAL_OBJECTVAR_NAME(amiobject,C_wrap_varfunction,
                          "LaunchDefaultBrowser",
                          wrap_LaunchDefaultBrowser);

//   ADDLOCAL_OBJECTVAR_NAME(amiobject,C_wrap_varfunction,
//                           "FromWxString",
//                           wrap_FromWxString);
    
  ADDVAR_NAME( C_wrap_varfunction, "FromWxString", wrap_FromWxString);

  return amiobject;
}

BasicVariable::ptr wrap_wxfunctions( ParamList* p)
{
/*
    char functionname[] = "wx";
    char description[]=" \n\
      Adds wrapping for the wxwidgets samples and functions. \n\
            ";
    char parameters[] =" \n\
            ";
*/

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
  
  if (!get_val_ptr_param<std::string>( webpage,    p, n)) HelpAndReturnVarPtr;

  int res = wxLaunchDefaultBrowser(wxString(webpage->c_str(),wxConvUTF8));

  RETURN_VAR(int, res);
}

/**
 * Convert wxString to AMILab string.
 * @param p
 */
BasicVariable::ptr wrap_FromWxString( ParamList* p)
{
  char functionname[] = "FromWxString";
  char description[]=" \n\
                    Convert wxString to AMILab string\n\
                    ";
    char parameters[] =" \n\
                       Parameters:\n\
                       wxString variable\n\
                       Return:\n\
                       Returns a variable of type std::string\n\
                       ";

  int n=0;
  boost::shared_ptr<wxString > input_smtptr;

  if (!get_val_smtptr_param<wxString>( input_smtptr, p, n)) HelpAndReturnVarPtr;
  if (input_smtptr.get()) {
    std::cout << "Data: " << (*input_smtptr).ToAscii()<< " - " << input_smtptr->ToAscii().data() << std::endl;
    return AMILabType< std::string >::CreateVar( new std::string( (*input_smtptr).ToAscii() ) );
  }
  else
    return BasicVariable::ptr();
}

