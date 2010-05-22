//
// C++ Implementation: wrapAMIFluid
//
// Description:
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//



#include "fonctions.h"
#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapSystem.h"
#include "driver.h"

extern yyip::Driver GB_driver;

#include <wx/utils.h>

extern VarContexts  Vars;

using namespace std;

//---------------------------------------------------------
void AddWrapSystem(){
  // Create new instance of the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("op_system");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

//  Vars.AddVar(type_c_function, "GetFreeMemory",    (void*) wrap_GetFreeMemory , OBJECT_CONTEXT_NUMBER);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetFullHostName", wrap_GetFullHostName);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetHomeDir",      wrap_GetHomeDir);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetHostName",     wrap_GetHostName);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetUserHome",     wrap_GetUserHome);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetUserId",       wrap_GetUserId);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetUserName",     wrap_GetUserName);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetCurrentScriptDir", wrap_GetCurrentScriptDir);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  Vars.AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);

}


/**
 * Adds the System wrapping
 * @param p 
 */
void wrap_System(ParamList* p)
{
    char functionname[] = "System";
    char description[]=" \n\
      Adds wrapping for Operating System operations. \n\
            ";
    char parameters[] =" \n\
            ";

  AddWrapSystem();
}


/*
//--------------------------------------------------------------------
BasicVariable::ptr wrap_GetFreeMemory(ParamList* p)
{
    char functionname[] = "GetFreeMemory";
    char description[]=" \n\
        Wraps the wxWidgets function wxGetFreeMemory, \n\
        creates a new numerical variable containing the result\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              Returns a numerical variable with the result of wxGetFreeMemory\n\
            ";


  if (p->get_num_param()!=0)  HelpAndReturnVarPtr;
  long long val = ::wxGetFreeMemory();
  cout << (boost::format("Free Memory = %1%") % val).str() << endl;

  // cast not compiling, why ???
  //  float* value = new float(FreeMemory);
  string* value = new string( (boost::format("%1%") % val).str());

  BasicVariable::ptr varres(new Variable());
  varres->Init(type_string,"FreeMemory",value);

  return varres;
}
*/

//--------------------------------------------------------------------
BasicVariable::ptr wrap_GetFullHostName(ParamList* p)
{
    char functionname[] = "GetFullHostName";
    char description[]=" \n\
        Wraps the wxWidgets function wxGetFullHostName, \n\
        creates a new string variable containing the result\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              Returns a string variable with the result of wxGetFullHostName\n\
            ";

  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  wxString FullHostName = ::wxGetFullHostName();

  string_ptr value( new string(FullHostName.mb_str()));

  Variable<string>::ptr varres(
    new Variable<string>("FullHostName",value));

  return varres;
}

//--------------------------------------------------------------------
BasicVariable::ptr wrap_GetHomeDir(ParamList* p) {
    char functionname[] = "GetHomeDir";
    char description[]=" \n\
        Wraps the wxWidgets function wxGetHomeDir, \n\
        creates a new string variable containing the result\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              Returns a string variable with the result of wxGetHomeDir\n\
            ";

  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  wxString HomeDir = ::wxGetHomeDir();

  string_ptr value( new string(HomeDir.mb_str()));
  Variable<string>::ptr varres(
    new Variable<string>("HomeDir",value));

  return varres;
}

//--------------------------------------------------------------------
BasicVariable::ptr wrap_GetUserHome(ParamList* p)
{
    char functionname[] = "GetUserHome";
    char description[]=" \n\
        Wraps the wxWidgets function wxGetUserHome, \n\
        creates a new string variable containing the result\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              Returns a string variable with the result of wxGetUserHome\n\
            ";

  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  wxString UserHome = ::wxGetUserHome();

  string_ptr value( new string(UserHome.mb_str()));
  Variable<string>::ptr varres(
    new Variable<string>("UserHome",value));

  return varres;
}

//--------------------------------------------------------------------
BasicVariable::ptr wrap_GetUserId(ParamList* p)
{
    char functionname[] = "GetUserId";
    char description[]=" \n\
        Wraps the wxWidgets function wxGetUserId, \n\
        creates a new string variable containing the result\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              Returns a string variable with the result of wxGetUserId\n\
            ";

  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  wxString UserId = ::wxGetUserId();

  string_ptr value( new string(UserId.mb_str()));
  Variable<string>::ptr varres(
    new Variable<string>("UserId",value));

  return varres;
}

//--------------------------------------------------------------------
BasicVariable::ptr wrap_GetUserName(ParamList* p)
{
    char functionname[] = "GetUserName";
    char description[]=" \n\
        Wraps the wxWidgets function wxGetUserName, \n\
        creates a new string variable containing the result\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              Returns a string variable with the result of wxGetUserName\n\
            ";

  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  wxString UserName = ::wxGetUserName();

  string_ptr value( new string(UserName.mb_str()));
  Variable<string>::ptr varres(
    new Variable<string>("UserName",value));

  return varres;
}

//--------------------------------------------------------------------

BasicVariable::ptr wrap_GetHostName(ParamList* p)
{
    char functionname[] = "GetHostName";
    char description[]=" \n\
        Wraps the wxWidgets function wxGetHostName, \n\
        creates a new string variable containing the result\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              Returns a string variable with the result of wxGetHostName\n\
            ";

  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  wxString hostname = ::wxGetHostName();

  string_ptr value( new string(hostname.mb_str()));
  Variable<string>::ptr varres(
    new Variable<string>("hostname",value));

  return varres;
}


//--------------------------------------------------------------------
BasicVariable::ptr wrap_GetCurrentScriptDir(ParamList* p)
{
    char functionname[] = "GetCurrentScriptDir";
    char description[]=" \n\
        Returns the directory of the current script\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              the directory of the current script\n\
            ";

  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  cout << "GB_driver.GetCurrentFilename()=" << GB_driver.GetCurrentFilename() << endl;
  wxFileName filename(wxString(GB_driver.GetCurrentFilename().c_str(), wxConvUTF8));
  filename.MakeAbsolute();
  wxString wxvalue = filename.GetPath();
  string_ptr value ( new string(wxvalue.mb_str()));

  Variable<string>::ptr varres(
    new Variable<string>("CurrentScriptDir",value));

  return varres;
}
