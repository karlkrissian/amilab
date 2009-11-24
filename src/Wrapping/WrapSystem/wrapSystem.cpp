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

//---------------------------------------------------------
void AddWrapSystem(){

//  Vars.AddVar(type_c_function, "GetFreeMemory",    (void*) wrap_GetFreeMemory );
  Vars.AddVar(type_c_function, "GetFullHostName",     (void*) wrap_GetFullHostName );
  Vars.AddVar(type_c_function, "GetHomeDir",          (void*) wrap_GetHomeDir );
  Vars.AddVar(type_c_function, "GetHostName",         (void*) wrap_GetHostName );
  Vars.AddVar(type_c_function, "GetUserHome",         (void*) wrap_GetUserHome );
  Vars.AddVar(type_c_function, "GetUserId",           (void*) wrap_GetUserId );
  Vars.AddVar(type_c_function, "GetUserName",         (void*) wrap_GetUserName );
  Vars.AddVar(type_c_function, "GetCurrentScriptDir", (void*) wrap_GetCurrentScriptDir );

}

/*
//--------------------------------------------------------------------
Variable::ptr wrap_GetFreeMemory(ParamList* p)
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

  Variable::ptr varres(new Variable());
  varres->Init(type_string,"FreeMemory",value);

  return varres;
}
*/

//--------------------------------------------------------------------
Variable::ptr wrap_GetFullHostName(ParamList* p)
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
  string* value = new string(FullHostName.mb_str());

  Variable::ptr varres(new Variable());
  varres->Init(type_string,"FullHostName",value);

  return varres;
}

//--------------------------------------------------------------------
Variable::ptr wrap_GetHomeDir(ParamList* p) {
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
  string* value = new string(HomeDir.mb_str());

  Variable::ptr varres(new Variable());
  varres->Init(type_string,"HomeDir",value);

  return varres;
}

//--------------------------------------------------------------------
Variable::ptr wrap_GetUserHome(ParamList* p)
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
  string* value = new string(UserHome.mb_str());

  Variable::ptr varres(new Variable());
  varres->Init(type_string,"UserHome",value);

  return varres;
}

//--------------------------------------------------------------------
Variable::ptr wrap_GetUserId(ParamList* p)
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
  string* value = new string(UserId.mb_str());

  Variable::ptr varres(new Variable());
  varres->Init(type_string,"UserId",value);

  return varres;
}

//--------------------------------------------------------------------
Variable::ptr wrap_GetUserName(ParamList* p)
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
  string* value = new string(UserName.mb_str());

  Variable::ptr varres(new Variable());
  varres->Init(type_string,"UserName",value);

  return varres;
}

//--------------------------------------------------------------------

Variable::ptr wrap_GetHostName(ParamList* p)
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
  string* value = new string(hostname.mb_str());

  Variable::ptr varres(new Variable());
  varres->Init(type_string,"hostname",value);

  return varres;
}


//--------------------------------------------------------------------
Variable::ptr wrap_GetCurrentScriptDir(ParamList* p)
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
  
  wxString wxvalue = wxFileName(wxString(GB_driver.GetCurrentFilename().c_str(), wxConvUTF8)).GetPath();
  string* value = new string(wxvalue.mb_str());

  Variable::ptr varres(new Variable());
  varres->Init(type_string,"hostname",value);

  return varres;
}
