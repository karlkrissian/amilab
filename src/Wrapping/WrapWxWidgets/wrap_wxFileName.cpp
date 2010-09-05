//
// C++ Implementation: wrap_wxFileName
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_wxFileName.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_object.h"
#include "wrapfunction_class.h"


#define SIZE_BUFFER 2040

#include <wx/string.h>
#include "driver.h"
#include "MainFrame.h"

extern yyip::Driver GB_driver;
extern MainFrame* GB_main_wxFrame;
extern wxApp* GB_wxApp;


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxFileName>::CreateVar( ParamList* p)
{
  WrapClass_wxFileName::wrap_wxFileName construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxFileName);
AMI_DEFINE_VARFROMSMTPTR(wxFileName);

/*//
// static member for creating a variable from a pointer to wxColour
//
Variable<AMIObject>::ptr WrapClass_wxFileName::CreateVar( wxFileName* sp)
{
  boost::shared_ptr<wxFileName> _obj_ptr(sp);
  return WrapClass<wxFileName>::CreateVar( new WrapClass_wxFileName(_obj_ptr));
}
*/

//---------------------------------------------------
// Method that adds wrapping of wxFileName
//---------------------------------------------------

void WrapClass_wxFileName::
      wrap_wxFileName::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A full file name (MODE 1) or A directory name (MODE 2) or A directory name (MODE 3) or A volume name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file name (MODE 2) or A file name (MODE 3) or A directory name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file extension (MODE 3) or A file name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file extension (MODE 4).");
  return_comments = "A wrapped wxFileName object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_wxFileName::CallMember( ParamList* p)
{
  wxFileName* owxFileName = NULL;
  int n=0;

  if (!p) ClassHelpAndReturn;

  switch (p->GetNumParam())
  {
    case 0: { //Mode 0
      owxFileName = new wxFileName();
      break;
    }
    case 1: { //Mode 1
      GET_PARAM(string,sFullpath,"");

      owxFileName = new wxFileName(wxString(sFullpath.c_str(), wxConvUTF8));
      break;
    }
    case 2: { //Mode 2
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");

      owxFileName = new wxFileName(wxString(sPath.c_str(), wxConvUTF8),
                                   wxString(sName.c_str(), wxConvUTF8));
      break;
    }
    case 3: { //Mode 3
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");
      GET_PARAM(string,sExt,"");

      owxFileName = new wxFileName(wxString(sPath.c_str(), wxConvUTF8),
                                   wxString(sName.c_str(), wxConvUTF8),
                                   wxString(sExt.c_str(),  wxConvUTF8));
      break;
    }
    case 4: { //Mode 4
      GET_PARAM(string,sVolume,"");
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");
      GET_PARAM(string,sExt,"");

      owxFileName = new wxFileName(wxString(sVolume.c_str(), wxConvUTF8),
                                   wxString(sPath.c_str(), wxConvUTF8),
                                   wxString(sName.c_str(), wxConvUTF8),
                                   wxString(sExt.c_str(), wxConvUTF8));
      break;
    }
  }

  // Create smart pointer with own deleter
  if (owxFileName) {
    boost::shared_ptr<wxFileName> pt_ptr(owxFileName);
    return WrapClass<wxFileName>::CreateVar(new WrapClass_wxFileName(pt_ptr));
  } 
  else
    return BasicVariable::ptr();

}

//---------------------------------------------------
//  Assign
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Assign::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A full file name (MODE 1) or A directory name (MODE 2) or A directory name (MODE 3) or A volume name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file name (MODE 2) or A file name (MODE 3) or A directory name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file extension (MODE 3) or A file name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file extension (MODE 4).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Assign::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  int n=0;

  if (!p) ClassHelpAndReturn;

  switch (p->GetNumParam())
  {
    case 1: { //Mode 1
      GET_PARAM(string,sFullpath,"");

      owxFileName->Assign(wxString(sFullpath.c_str(), wxConvUTF8));
      break;
    }
    case 2: { //Mode 2
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");

      owxFileName->Assign(wxString(sPath.c_str(), wxConvUTF8),
                          wxString(sName.c_str(), wxConvUTF8));
      break;
    }
    case 3: { //Mode 3
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");
      GET_PARAM(string,sExt,"");

      owxFileName->Assign(wxString(sPath.c_str(), wxConvUTF8),
                          wxString(sName.c_str(), wxConvUTF8),
                          wxString(sExt.c_str(),  wxConvUTF8));
      break;
    }
    case 4: { //Mode 4
      GET_PARAM(string,sVolume,"");
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");
      GET_PARAM(string,sExt,"");

      owxFileName->Assign(wxString(sVolume.c_str(), wxConvUTF8),
                          wxString(sPath.c_str(), wxConvUTF8),
                          wxString(sName.c_str(), wxConvUTF8),
                          wxString(sExt.c_str(),  wxConvUTF8));
      break;
    }
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  AssignCwd
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_AssignCwd::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A volume name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_AssignCwd::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  int n=0;

  if (!p) ClassHelpAndReturn;
  GET_PARAM(string,sVolume,"");

  owxFileName->AssignCwd(wxString(sVolume.c_str(), wxConvUTF8));

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  AssignDir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_AssignDir::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A directory name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_AssignDir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  int n=0;

  if (!p) ClassHelpAndReturn;
  GET_PARAM(string,sDir,"");

  if (sDir != "")
    owxFileName->AssignDir(wxString(sDir.c_str(), wxConvUTF8));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  AssignHomeDir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_AssignHomeDir::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_AssignHomeDir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  owxFileName->AssignHomeDir();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetHomeDir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetHomeDir::SetParametersComments() 
{
  return_comments="The home directory.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetHomeDir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  char buffer[SIZE_BUFFER];
  strcpy( buffer, (const char*)owxFileName->GetHomeDir().mb_str(wxConvUTF8) );
  string sVal = buffer;

//  string sVal = owxFileName->GetHomeDir().mb_str(wxConvUTF8);

  RETURN_VAR(string,sVal);
}

//---------------------------------------------------
//  AppendDir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_AppendDir::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A directory name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_AppendDir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sDir,"");

  if(sDir != "")
    owxFileName->AppendDir(wxString(sDir.c_str(), wxConvUTF8));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetVolume
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetVolume::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A volume name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetVolume::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sVolume,"");

  if(sVolume != "")
    owxFileName->SetVolume(wxString(sVolume.c_str(), wxConvUTF8));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetName::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A name without extension.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sName,"");

  if(sName != "")
    owxFileName->SetName(wxString(sName.c_str(), wxConvUTF8));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetExt
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetExt::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The extension of the file name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetExt::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sExtension,"");

  if(sExtension != "")
    owxFileName->SetExt(wxString(sExtension.c_str(), wxConvUTF8));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetEmptyExt
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetEmptyExt::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetEmptyExt::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  owxFileName->SetEmptyExt();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetFullName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetFullName::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A full name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetFullName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sFullName,"");

  if(sFullName != "")
    owxFileName->SetFullName(wxString(sFullName.c_str(), wxConvUTF8));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCwd
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetCwd::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A working directory.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetCwd::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sDir,"");

  if(sDir != "")
    owxFileName->SetCwd(wxString(sDir.c_str(), wxConvUTF8));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetVolume
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetVolume::SetParametersComments() 
{
  return_comments="The string containing the volume for this file name.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetVolume::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  char buffer[SIZE_BUFFER];
  strcpy( buffer, (const char*)owxFileName->GetVolume().mb_str(wxConvUTF8) );
  string sVal = buffer;

  //string sVal = owxFileName->GetVolume().c_str();

  RETURN_VAR(string,sVal);
}

//---------------------------------------------------
//  GetName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetName::SetParametersComments() 
{
  return_comments="The name part of the filename.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  char buffer[SIZE_BUFFER];
  strcpy( buffer, (const char*)owxFileName->GetName().mb_str(wxConvUTF8) );
  string sVal = buffer;

//  string sVal = owxFileName->GetName().c_str();

  RETURN_VAR(string,sVal);
}

//---------------------------------------------------
//  GetExt
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetExt::SetParametersComments() 
{
  return_comments="The file name extension.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetExt::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  char buffer[SIZE_BUFFER];
  strcpy( buffer, (const char*)owxFileName->GetExt().mb_str(wxConvUTF8) );
  string sVal = buffer;

//  string sVal = owxFileName->GetExt().c_str();

  RETURN_VAR(string,sVal);
}

//---------------------------------------------------
//  GetPath
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetPath::SetParametersComments() 
{
  return_comments="The path part of the filename.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetPath::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  char buffer[SIZE_BUFFER];
  strcpy( buffer, (const char*)owxFileName->GetPath().mb_str(wxConvUTF8) );
  string sVal = buffer;
//  string sVal = owxFileName->GetPath().c_str();

  RETURN_VAR(string,sVal);
}

//---------------------------------------------------
//  GetFullName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetFullName::SetParametersComments() 
{
  return_comments="The full name.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetFullName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  char buffer[SIZE_BUFFER];
  strcpy( buffer, (const char*)owxFileName->GetFullName().mb_str(wxConvUTF8) );
  string sVal = buffer;
//  string sVal = owxFileName->GetFullName().c_str();

  RETURN_VAR(string,sVal);
}

//---------------------------------------------------
//  GetFullPath
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetFullPath::SetParametersComments() 
{
  return_comments="The full path with name and extension.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetFullPath::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  char buffer[SIZE_BUFFER];
  strcpy( buffer, (const char*)owxFileName->GetFullPath().mb_str(wxConvUTF8) );
  string sVal = buffer;
//  string sVal = owxFileName->GetFullPath().c_str();

  RETURN_VAR(string,sVal);
}

//---------------------------------------------------
//  GetCwd
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetCwd::SetParametersComments() 
{
  return_comments="The value of the current working directory.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetCwd::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  char buffer[SIZE_BUFFER];
  strcpy( buffer, (const char*)owxFileName->GetCwd().mb_str(wxConvUTF8) );
  string sVal = buffer;
//  string sVal = owxFileName->GetCwd().c_str();

  RETURN_VAR(string,sVal);
}

//---------------------------------------------------
//  Clear
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Clear::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Clear::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  owxFileName->Clear();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  ClearExt
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_ClearExt::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_ClearExt::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  owxFileName->ClearExt();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Touch
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Touch::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Touch::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  owxFileName->Touch();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Mkdir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Mkdir::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The directory name (optional).");
  ADDPARAMCOMMENT_TYPE(int,"The permissions for the newly created directory (optional, by default 0777).");
  return_comments="Returns true if the directory was successfully created, false otherwise (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Mkdir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  unsigned char res;

  switch (p->GetNumParam())
  {
    case 0: {
      res = (unsigned char) owxFileName->Mkdir();
      break;
    }
    case 1: {
      int n=0;
      GET_PARAM(int,iPerm,0777);

      res = (unsigned char) owxFileName->Mkdir(iPerm);
      break;
    }
    case 2: {
      int n=0;
      GET_PARAM(string,sName,"");
      GET_PARAM(int,iPerm,0777);
      if (sName != "")
        res = (unsigned char) owxFileName->Mkdir(wxString(sName.c_str(), wxConvUTF8), iPerm);
      else
        ClassHelpAndReturn;
    }
  }

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  Rmdir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Rmdir::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The directory from the file system (optional).");
  return_comments="Returns true if the directory was successfully deleted, false otherwise (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Rmdir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  unsigned char res;

  if (p->GetNumParam() == 0)
    res = (unsigned char) owxFileName->Rmdir();
  else
  {
    int n=0;
    GET_PARAM(string,sDir,"");

    if(sDir != "")
      res = (unsigned char) owxFileName->Rmdir(wxString(sDir.c_str(), wxConvUTF8));
    else
      ClassHelpAndReturn;
  }

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  MakeAbsolute
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_MakeAbsolute::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_MakeAbsolute::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  owxFileName->MakeAbsolute();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  MakeRelativeTo
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_MakeRelativeTo::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_MakeRelativeTo::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  owxFileName->MakeRelativeTo();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsAbsolute
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsAbsolute::SetParametersComments() 
{
  return_comments="True if this filename is absolute (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsAbsolute::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->IsAbsolute();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsRelative
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsRelative::SetParametersComments() 
{
  return_comments="True if this filename is not absolute (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsRelative::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->IsRelative();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsCaseSensitive
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsCaseSensitive::SetParametersComments() 
{
  return_comments="True if the file names of this type are case-sensitive (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsCaseSensitive::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->IsCaseSensitive();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  HasExt
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_HasExt::SetParametersComments() 
{
  return_comments="True if an extension is present (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_HasExt::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->HasExt();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  HasName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_HasName::SetParametersComments() 
{
  return_comments="True if a name is present (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_HasName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->HasName();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  HasVolume
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_HasVolume::SetParametersComments() 
{
  return_comments="True if a volume specifier is present (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_HasVolume::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->HasVolume();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  DirExists
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_DirExists::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The directory from the file system (optional).");
  return_comments="True if the directory with this name exists (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_DirExists::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  unsigned char res;

  if (p->GetNumParam() == 0)
    res = (unsigned char) owxFileName->DirExists();
  else
  {
    int n=0;
    GET_PARAM(string,sDir,"");

    if(sDir != "")
      res = (unsigned char) owxFileName->DirExists(wxString(sDir.c_str(), wxConvUTF8));
    else
      ClassHelpAndReturn;
  }

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  FileExists
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_FileExists::SetParametersComments() 
{
  return_comments="True if the file with this name exists (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_FileExists::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->FileExists();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsDir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsDir::SetParametersComments() 
{
  return_comments="True if this object represents a directory (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsDir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->IsDir();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsDirReadable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsDirReadable::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The directory from the file system (optional).");
  return_comments="True if the directory of this instance is an existing directory and this process has read permissions on it (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsDirReadable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  unsigned char res;

  if (p->GetNumParam() == 0)
    res = (unsigned char) owxFileName->IsDirReadable();
  else
  {
    int n=0;
    GET_PARAM(string,sDir,"");

    if(sDir != "")
      res = (unsigned char) owxFileName->IsDirReadable(wxString(sDir.c_str(), wxConvUTF8));
    else
      ClassHelpAndReturn;
  }

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsDirWritable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsDirWritable::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The directory from the file system (optional).");
  return_comments="True if the directory of this instance is an existing directory and this process has read permissions on it (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsDirWritable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  unsigned char res;

  if (p->GetNumParam() == 0)
    res = (unsigned char) owxFileName->IsDirWritable();
  else
  {
    int n=0;
    GET_PARAM(string,sDir,"");

    if(sDir != "")
      res = (unsigned char) owxFileName->IsDirWritable(wxString(sDir.c_str(), wxConvUTF8));
    else
      ClassHelpAndReturn;
  }

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsFileExecutable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsFileExecutable::SetParametersComments() 
{
  return_comments="True if a file with this name exists and if this process has execute permissions on it (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsFileExecutable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->IsFileExecutable();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsFileReadable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsFileReadable::SetParametersComments() 
{
  return_comments="True if a file with this name exists and if this process has read permissions on it (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsFileReadable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->IsFileReadable();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsFileWritable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsFileWritable::SetParametersComments() 
{
  return_comments="True if a file with this name exists and if this process has write permissions on it (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsFileWritable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->IsFileWritable();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsOk
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsOk::SetParametersComments() 
{
  return_comments="True if the filename is valid, false if it is not initialized yet (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsOk::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxFileName->IsOk();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  SameAs
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SameAs::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxFileName,"A wrapped wxFileName object.");
  return_comments="True if the filename is equal (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SameAs::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;

  CLASS_GET_OBJECT_PARAM(wxFileName,varFileName,oFileName);
  if (!oFileName.get()) ClassHelpAndReturn;

  if (oFileName.get())
  {
    unsigned char res = (unsigned char) owxFileName->SameAs((*oFileName.get()));
    RETURN_VAR(unsigned char,res);
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_copy::SetParametersComments() 
{
  return_comments="A copy of the wxFileName.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_copy::CallMember( ParamList* p)
{
  return AMILabType<wxFileName>::CreateVar( new wxFileName(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  assign_operator
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_assign_operator::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxFileName,"A wrapped wxFileName object.");
  return_comments="A copy of the wxFileName.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_assign_operator::CallMember( ParamList* p)
{
  return AMILabType<wxFileName>::CreateVar( new wxFileName(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  equal
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_equal::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxFileName,"A wrapped FileName object.");
  return_comments = "True if the filename is equal (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_equal::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;

  CLASS_GET_OBJECT_PARAM(wxFileName,varFileName,oFileName);
  if (!oFileName.get()) ClassHelpAndReturn;

  if (oFileName.get())
  {
    unsigned char res = (unsigned char) owxFileName->SameAs((*oFileName.get()));
    RETURN_VAR(unsigned char,res);
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  not_equal
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_not_equal::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxFileName,"A wrapped wxFileName object.");
  return_comments = "True if the filename is not equal (unsigned char).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_not_equal::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  string sVal;
  int n=0;

  CLASS_GET_OBJECT_PARAM(wxFileName,varFileName,oFileName);
  if (!oFileName.get()) ClassHelpAndReturn;

  if (oFileName.get())
  {
    unsigned char res = (unsigned char) owxFileName->SameAs((*oFileName.get()));

    if (res==1)
      res=0;
    else
      res=1;

    RETURN_VAR(unsigned char,res);
  }

  return BasicVariable::ptr();
}
