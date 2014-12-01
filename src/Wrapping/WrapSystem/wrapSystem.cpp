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


#include "AMILabConfig.h"

//#include "fonctions.h"
#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapSystem.h"
#include "driver.h"
#include "message_dialog.h"

#include <wx/filename.h>

extern yyip::Driver GB_driver;

#include <wx/utils.h>
//#include <improcess_bison.ypp>

#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT VarContexts  Vars;

extern wxString  GB_scripts_dir;

using namespace std;



//---------------------------------------------------------
void AddWrapSystem( AMIObject::ptr& obj)
{
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
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetCurrentFilename",  wrap_GetCurrentFilename);

  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetGlobalScriptDir",  wrap_GetGlobalScriptDir);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"SetGlobalScriptDir",  wrap_SetGlobalScriptDir);

  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetCMakeBuildType", wrap_GetCMakeBuildType);
  ADDOBJECTVAR_NAME(C_wrap_varfunction,"GetAMILabVersion",  wrap_GetAMILabVersion);

// Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  // 3. add the variables to this instance
  obj->GetContext()->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject,obj->GetContext());

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
 std::cout << (boost::format("Free Memory = %1%") % val).str() << std::endl;

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
  HomeDir.Replace(wxT("\\"),wxT("/"),true);
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
  UserHome.Replace(wxT("\\"),wxT("/"),true);

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
  //std::cout << "GB_driver.GetCurrentFilename()=" << GB_driver.GetCurrentFilename() << std::endl;
  wxFileName filename(wxString(GB_driver.GetCurrentFilename().c_str(), wxConvUTF8));
  filename.MakeAbsolute();
  wxString wxvalue = filename.GetPath();
  // unix-like separation of directories to avoid escape characters and their problems
  wxvalue.Replace(wxT("\\"),wxT("/"),true);
  string_ptr value ( new string(wxvalue.mb_str()));

  Variable<string>::ptr varres(
    new Variable<string>("CurrentScriptDir",value));

  return varres;
}

//--------------------------------------------------------------------
BasicVariable::ptr wrap_GetCurrentFilename(ParamList* p)
{
    char functionname[] = "GetCurrentFilename";
    char description[]=" \n\
        Returns the filename of the current script\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              the filename of the current script\n\
            ";

  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  wxFileName filename(wxString(GB_driver.GetCurrentFilename().c_str(), wxConvUTF8));
  filename.MakeAbsolute();
  // unix-like separation of directories to avoid escape characters and their problems
  wxString wxvalue = filename.GetFullPath();
  wxvalue.Replace(wxT("\\"),wxT("/"),true);
  string_ptr value ( new string(wxvalue.mb_str()));

  Variable<string>::ptr varres(
    new Variable<string>("CurrentFilename",value));

  return varres;
}


//--------------------------------------------------------------------
BasicVariable::ptr wrap_GetGlobalScriptDir(ParamList* p)
{
    char functionname[] = "GetGlobalScriptDir";
    char description[]=" \n\
        Returns the global amilab scripts directory\n\
            ";
    char parameters[] =" \n\
          Return:\n\
              the directory of the amilab scripts\n\
            ";
  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  wxString wxvalue(GB_scripts_dir);
  wxvalue.Replace(wxT("\\"),wxT("/"),true);
  std::string val(wxvalue.mb_str());
  RETURN_VAR(string,val);
}

//------------------------------------------------------------------------------
BasicVariable::ptr wrap_SetGlobalScriptDir(ParamList* p)
{
    char functionname[] = "SetGlobalScriptDir";
    char description[]=" \n\
        Sets the global amilab scripts directory\n\
            ";
    char parameters[] =" \n\
          Parameters:\n\
              - string: the new directory of the amilab scripts\n\
            ";
  if (get_num_param(p)==0)  HelpAndReturnVarPtr;
  int n=0;
  std::string scripts_dir;
  if (!get_val_param<string>( scripts_dir, p, n)) HelpAndReturnVarPtr

  wxString newdir(scripts_dir.c_str(), wxConvUTF8);

  if (wxFileName::DirExists(newdir))
    GB_scripts_dir = newdir;
  else
    GB_driver.err_print("Directory does not exists.");
    
  return BasicVariable::ptr();
}


//------------------------------------------------------------------------------
BasicVariable::ptr wrap_GetCMakeBuildType( ParamList* p)
{
    char functionname[] = "GetCMakeBuildType";
    char description[]=" \n\
        Return the cmake build type:\n\
        Release, Debug,  RelWithDebInfo or MinSizeRel, \n\
        or an empty string otherwise\n\
            ";
    char parameters[] =" \n\
          Parameters: no parameter.\n\
            ";
  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  std::string res;
  #ifdef _CMAKEBUILDTYPE_RELEASE_
    res="Release";
  #endif
  #ifdef _CMAKEBUILDTYPE_DEBUG_
    res="Debug";
  #endif
  #ifdef _CMAKEBUILDTYPE_RELWITHDEBINFO_
    res="RelWithDebInfo";
  #endif
  #ifdef _CMAKEBUILDTYPE_MINSIZEREL_
    res="MinSizeRel";
  #endif
    
  return AMILabType<std::string>::CreateVar(res);
}


//------------------------------------------------------------------------------
BasicVariable::ptr wrap_GetAMILabVersion( ParamList* p)
{
    char functionname[] = "GetAMILabVersion";
    char description[]=" \n\
        Return the current version number of AMILab\n\
            ";
    char parameters[] =" \n\
          Parameters: no parameter.\n\
            ";
  if (get_num_param(p)!=0)  HelpAndReturnVarPtr;
  std::string res = AMILAB_VERSION;
    
  return AMILabType<std::string>::CreateVar(res);
}
