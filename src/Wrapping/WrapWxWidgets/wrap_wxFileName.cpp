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

#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define GET_SMTPTR_PARAM(type,varname) \
  boost::shared_ptr<type> varname; \
  if (!get_val_smtptr_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#include <wx/string.h>
#include "driver.h"
#include "MainFrame.h"

extern yyip::Driver GB_driver;
extern MainFrame* GB_main_wxFrame;
extern wxApp* GB_wxApp;


//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxFileName(  WrapClass_wxFileName::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("wxFileName");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxFileName( wxFileName* si)
{
  // Create smart pointer with own deleter
  boost::shared_ptr<wxFileName> si_ptr( 
    si,
    wxwindow_nodeleter<wxFileName>() // deletion will be done by wxwidgets
  );

  WrapClass_wxFileName::ptr sip(new WrapClass_wxFileName(si_ptr));
  AMIObject::ptr amiobject(AddWrap_wxFileName(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
// Method that adds wrapping of wxFileName
//---------------------------------------------------

void  wrap_wxFileName::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A full file name (MODE 1).");
  ADDPARAMCOMMENT_TYPE(string,"A directory name (MODE 2).");
  ADDPARAMCOMMENT_TYPE(string,"A file name (MODE 2).");
  ADDPARAMCOMMENT_TYPE(string,"A directory name (MODE 3).");
  ADDPARAMCOMMENT_TYPE(string,"A file name (MODE 3).");
  ADDPARAMCOMMENT_TYPE(string,"A file extension (MODE 3).");
  ADDPARAMCOMMENT_TYPE(string,"A volume name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A directory name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file extension (MODE 4).");
  return_comments = "A wrapped wxFileName object.";
}

//---------------------------------------------------
BasicVariable::ptr wrap_wxFileName::CallMember( ParamList* p)
{
  wxFileName* owxFileName;
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

      if (sFullpath != "")
        owxFileName = new wxFileName(wxString(sFullpath.c_str(),wxConvUTF8));
      else
        ClassHelpAndReturn;
      break;
    }
    case 2: { //Mode 2
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");

      if ((sPath != "") && (sName != ""))
        owxFileName = new wxFileName(wxString(sPath.c_str(),wxConvUTF8),
                                     wxString(sName.c_str(),wxConvUTF8));
      else
        ClassHelpAndReturn;
      break;
    }
    case 3: { //Mode 3
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");
      GET_PARAM(string,sExt,"");

      if ((sPath != "") && (sName != "") &&
          (sExt != ""))
        owxFileName = new wxFileName(wxString(sPath.c_str(),wxConvUTF8),
                                     wxString(sName.c_str(),wxConvUTF8),
                                     wxString(sExt.c_str(),wxConvUTF8));
      else
        ClassHelpAndReturn;
      break;
    }
    case 4: { //Mode 4
      GET_PARAM(string,sVolume,"");
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");
      GET_PARAM(string,sExt,"");

      if ((sVolume != "") && (sPath != "") &&
          (sName != "") && (sExt != ""))
        owxFileName = new wxFileName(wxString(sVolume.c_str(),wxConvUTF8),
                                     wxString(sPath.c_str(),wxConvUTF8),
                                     wxString(sName.c_str(),wxConvUTF8),
                                     wxString(sExt.c_str(),wxConvUTF8));
      else
        ClassHelpAndReturn;
      break;
    }
  }

  BasicVariable::ptr res = CreateVar_wxFileName(owxFileName);

  return res;
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
  return CreateVar_wxFileName( new wxFileName(*(this->_objectptr->_obj)));
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
  return CreateVar_wxFileName( new wxFileName(*(this->_objectptr->_obj)));
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
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sDir,"");

  if(sDir != "")
    owxFileName->AppendDir(wxString(sDir.c_str(),wxConvUTF8));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Assign
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Assign::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A full file name (MODE 1).");
  ADDPARAMCOMMENT_TYPE(string,"A directory name (MODE 2).");
  ADDPARAMCOMMENT_TYPE(string,"A file name (MODE 2).");
  ADDPARAMCOMMENT_TYPE(string,"A directory name (MODE 3).");
  ADDPARAMCOMMENT_TYPE(string,"A file name (MODE 3).");
  ADDPARAMCOMMENT_TYPE(string,"A file extension (MODE 3).");
  ADDPARAMCOMMENT_TYPE(string,"A volume name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A directory name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file name (MODE 4).");
  ADDPARAMCOMMENT_TYPE(string,"A file extension (MODE 4).");

}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Assign::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;

  switch (p->GetNumParam())
  {
    case 1: { //Mode 1
      GET_PARAM(string,sFullpath,"");

      if (sFullpath != "")
        owxFileName->Assign(wxString(sFullpath.c_str(),wxConvUTF8));
      else
        ClassHelpAndReturn;
      break;
    }
    case 2: { //Mode 2
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");

      if ((sPath != "") && (sName != ""))
        owxFileName->Assign(wxString(sPath.c_str(),wxConvUTF8),
                             wxString(sName.c_str(),wxConvUTF8));
      else
        ClassHelpAndReturn;
      break;
    }
    case 3: { //Mode 3
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");
      GET_PARAM(string,sExt,"");

      if ((sPath != "") && (sName != "") &&
          (sExt != ""))
        owxFileName->Assign(wxString(sPath.c_str(),wxConvUTF8),
                            wxString(sName.c_str(),wxConvUTF8),
                            wxString(sExt.c_str(),wxConvUTF8));
      else
        ClassHelpAndReturn;
      break;
    }
    case 4: { //Mode 4
      GET_PARAM(string,sVolume,"");
      GET_PARAM(string,sPath,"");
      GET_PARAM(string,sName,"");
      GET_PARAM(string,sExt,"");

      if ((sVolume != "") && (sPath != "") &&
          (sName != "") && (sExt != ""))
        owxFileName->Assign(wxString(sVolume.c_str(),wxConvUTF8),
                            wxString(sPath.c_str(),wxConvUTF8),
                            wxString(sName.c_str(),wxConvUTF8),
                            wxString(sExt.c_str(),wxConvUTF8));
      else
        ClassHelpAndReturn;
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
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;
  GET_PARAM(string,sVolume,wxEmptyString);

  owxFileName->AssignCwd(wxString(sVolume.c_str(),wxConvUTF8));

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
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;
  GET_PARAM(string,sDir,"");

  if (sDir != "")
    owxFileName->AssignDir(wxString(sDir.c_str(),wxConvUTF8));
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
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  owxFileName->AssignHomeDir();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  AssignTempFileName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_AssignTempFileName::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A prefix name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_AssignTempFileName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  int n=0;

  if (!p) ClassHelpAndReturn;
  GET_PARAM(string,sPrefix,"");

  if (sPrefix != "")
    owxFileName->AssignTempFileName(wxString(sPrefix.c_str(),wxConvUTF8));
  else
    ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetHomeDir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetHomeDir::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetHomeDir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetTempDir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetTempDir::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetTempDir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetEmptyExt
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetEmptyExt::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetEmptyExt::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetExt
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetExt::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetExt::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetFullName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetFullName::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetFullName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetName::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetPath
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetPath::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetPath::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetVolume
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetVolume::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetVolume::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetCwd
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_SetCwd::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_SetCwd::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetExt
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetExt::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetExt::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetFullName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetFullName::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetFullName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetFullPath
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetFullPath::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetFullPath::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetCwd
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetCwd::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetCwd::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetName::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetPath
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetPath::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetPath::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetShortPath
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetShortPath::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetShortPath::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetVolume
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetVolume::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetVolume::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetPathSeparator
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetPathSeparator::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetPathSeparator::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetPathSeparators
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetPathSeparators::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetPathSeparators::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetPathTerminators
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetPathTerminators::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetPathTerminators::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetVolumeSeparator
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_GetVolumeSeparator::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_GetVolumeSeparator::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  ReplaceHomeDir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_ReplaceHomeDir::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_ReplaceHomeDir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Clear
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Clear::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Clear::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  ClearExt
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_ClearExt::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_ClearExt::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  HasName
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_HasName::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_HasName::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  HasVolume
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_HasVolume::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_HasVolume::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  DirExists
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_DirExists::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_DirExists::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  FileExists
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_FileExists::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_FileExists::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsAbsolute
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsAbsolute::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsAbsolute::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsDir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsDir::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsDir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsDirReadable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsDirReadable::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsDirReadable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsDirWritable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsDirWritable::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsDirWritable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsFileExecutable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsFileExecutable::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsFileExecutable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsFileReadable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsFileReadable::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsFileReadable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsFileWritable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsFileWritable::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsFileWritable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsOk
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsOk::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsOk::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsRelative
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsRelative::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsRelative::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  IsCaseSensitive
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_IsCaseSensitive::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_IsCaseSensitive::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Touch
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Touch::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Touch::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  ReplaceEnvVariable
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_ReplaceEnvVariable::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_ReplaceEnvVariable::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  MakeAbsolute
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_MakeAbsolute::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_MakeAbsolute::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  MakeRelativeTo
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_MakeRelativeTo::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_MakeRelativeTo::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Mkdir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Mkdir::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Mkdir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Rmdir
//---------------------------------------------------
void WrapClass_wxFileName::
      wrap_Rmdir::SetParametersComments() 
{
  //TODO
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
      wrap_Rmdir::CallMember( ParamList* p)
{
  boost::shared_ptr<wxFileName> owxFileName(this->_objectptr->_obj);

  //TODO

  return BasicVariable::ptr();
}