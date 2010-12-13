/**
 * C++ Interface: wrap_wxFileName
 *
 * Description: wrapping wxFileName
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxFileName.h"

// get all the required includes
// #include "..."
#include "stdlib.h"
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxFileName_declared
  #define wxFileName_declared
  AMI_DECLARE_TYPE(wxFileName)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxULongLongNative_declared
  #define wxULongLongNative_declared
  AMI_DECLARE_TYPE(wxULongLongNative)
#endif
#ifndef wxDateTime_declared
  #define wxDateTime_declared
  AMI_DECLARE_TYPE(wxDateTime)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
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


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxFileName
//
Variable<AMIObject>::ptr WrapClass_wxFileName::CreateVar( wxFileName* sp)
{
  boost::shared_ptr<wxFileName> di_ptr(
    sp,
    wxwindow_nodeleter<wxFileName>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFileName>::CreateVar(
      new WrapClass_wxFileName(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxFileName::AddMethods(WrapClass<wxFileName>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Assign_1( this_ptr);
  AddVar_Assign( this_ptr);
  AddVar_Assign_2( this_ptr);
  AddVar_Assign_3( this_ptr);
  AddVar_Assign_4( this_ptr);
  AddVar_Assign_5( this_ptr);
  AddVar_Assign_6( this_ptr);
  AddVar_AssignDir( this_ptr);
  AddVar_Clear( this_ptr);
  AddVar_IsOk( this_ptr);
  AddVar_FileExists( this_ptr);
  AddVar_DirExists( this_ptr);
  AddVar_IsDirWritable( this_ptr);
  AddVar_IsDirReadable( this_ptr);
  AddVar_IsFileWritable( this_ptr);
  AddVar_IsFileReadable( this_ptr);
  AddVar_IsFileExecutable( this_ptr);
  AddVar_SetTimes( this_ptr);
  AddVar_Touch( this_ptr);
  AddVar_GetTimes( this_ptr);
  AddVar_GetModificationTime( this_ptr);
  AddVar_AssignCwd( this_ptr);
  AddVar_SetCwd( this_ptr);
  AddVar_AssignHomeDir( this_ptr);
  AddVar_AssignTempFileName_1( this_ptr);
  AddVar_AssignTempFileName( this_ptr);
/* The following types are missing: wxFile
  AddVar_AssignTempFileName_2( this_ptr);
*/
/* The following types are missing: wxFFile
  AddVar_AssignTempFileName_3( this_ptr);
*/
  AddVar_Mkdir( this_ptr);
  AddVar_Rmdir( this_ptr);
  AddVar_Normalize( this_ptr);
  AddVar_MakeRelativeTo( this_ptr);
  AddVar_MakeAbsolute( this_ptr);
  AddVar_SameAs( this_ptr);
  AddVar_IsAbsolute( this_ptr);
  AddVar_IsRelative( this_ptr);
  AddVar_GetDirCount( this_ptr);
  AddVar_AppendDir( this_ptr);
  AddVar_PrependDir( this_ptr);
  AddVar_InsertDir( this_ptr);
  AddVar_RemoveDir( this_ptr);
  AddVar_RemoveLastDir( this_ptr);
  AddVar_SetExt( this_ptr);
  AddVar_ClearExt( this_ptr);
  AddVar_SetEmptyExt( this_ptr);
  AddVar_GetExt( this_ptr);
  AddVar_HasExt( this_ptr);
  AddVar_SetName( this_ptr);
  AddVar_GetName( this_ptr);
  AddVar_HasName( this_ptr);
  AddVar_SetVolume( this_ptr);
  AddVar_GetVolume( this_ptr);
  AddVar_HasVolume( this_ptr);
  AddVar_SetFullName( this_ptr);
  AddVar_GetFullName( this_ptr);
/* The following types are missing: wxArrayString
  AddVar_GetDirs( this_ptr);
*/
  AddVar_GetPath_1( this_ptr);
  AddVar_SetPath( this_ptr);
  AddVar_GetFullPath( this_ptr);
  AddVar_GetShortPath( this_ptr);
  AddVar_GetLongPath( this_ptr);
  AddVar_IsDir( this_ptr);
  AddVar_GetSize( this_ptr);
  AddVar_GetHumanReadableSize( this_ptr);
  AddVar_GetPath( this_ptr);
  AddVar_GetPath_2( this_ptr);
  AddVar_GetPathWithSep( this_ptr);

  // Adding operators
  AddVar___assign___1( this_ptr);
  AddVar___assign__( this_ptr);
  AddVar___assign___2( this_ptr);
  AddVar___equal___1( this_ptr);
  AddVar___not_equal___1( this_ptr);
  AddVar___equal__( this_ptr);
  AddVar___equal___2( this_ptr);
  AddVar___not_equal__( this_ptr);
  AddVar___not_equal___2( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxFileName_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxFileName");
    WrapClass_wxFileName::AddVar_wxFileName_1(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_wxFileName(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_wxFileName_2(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_wxFileName_3(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_wxFileName_4(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_wxFileName_5(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_wxFileName_6(amiobject->GetContext());


  // Static methods 
  WrapClass_wxFileName::AddVar_FileName(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_DirName(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_FileExists(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_DirExists(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_IsDirWritable(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_IsDirReadable(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_IsFileWritable(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_IsFileReadable(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_IsFileExecutable(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetCwd(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_SetCwd(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetHomeDir(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetTempDir(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_CreateTempFileName_1(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_CreateTempFileName(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxFileName::AddVar_CreateTempFileName_2(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_wxFileName::AddVar_CreateTempFileName_3(amiobject->GetContext());
  */
  WrapClass_wxFileName::AddVar_Mkdir(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_Rmdir(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_IsCaseSensitive(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetForbiddenChars(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetVolumeSeparator(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetPathSeparators(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetPathTerminators(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetPathSeparator(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_IsPathSeparator(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetFormat(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_SplitPath_1(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_SplitPath(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_SplitPath_2(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_SplitPath_3(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_SplitVolume(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_StripExtension(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetSize(amiobject->GetContext());
  WrapClass_wxFileName::AddVar_GetHumanReadableSize(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxFileName::wxFileName()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_wxFileName_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_wxFileName_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxFileName* _newobj = new wxFileName();
  BasicVariable::ptr res = WrapClass_wxFileName::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxFileName::wxFileName(...)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_wxFileName::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_wxFileName::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFileName::wrap_wxFileName_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_wxFileName_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_wxFileName_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_wxFileName_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_wxFileName_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_wxFileName_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFileName::wxFileName(wxFileName const & filepath)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_wxFileName_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileName, "parameter named 'filepath'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_wxFileName_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFileName > filepath_smtptr;
  if (!get_val_smtptr_param<wxFileName >(filepath_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxFileName const & filepath = *filepath_smtptr;

  wxFileName* _newobj = new wxFileName(filepath);
  BasicVariable::ptr res = WrapClass_wxFileName::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFileName::wxFileName(wxString const & fullpath, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_wxFileName_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fullpath'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_wxFileName_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > fullpath_smtptr;
  if (!get_val_smtptr_param<wxString >(fullpath_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & fullpath = *fullpath_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName* _newobj = new wxFileName(fullpath, format);
  BasicVariable::ptr res = WrapClass_wxFileName::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFileName::wxFileName(wxString const & path, wxString const & name, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_wxFileName_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_wxFileName_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & path = *path_smtptr;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName* _newobj = new wxFileName(path, name, format);
  BasicVariable::ptr res = WrapClass_wxFileName::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFileName::wxFileName(wxString const & volume, wxString const & path, wxString const & name, wxString const & ext, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_wxFileName_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'volume'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_wxFileName_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > volume_smtptr;
  if (!get_val_smtptr_param<wxString >(volume_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & volume = *volume_smtptr;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & path = *path_smtptr;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxString > ext_smtptr;
  if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & ext = *ext_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName* _newobj = new wxFileName(volume, path, name, ext, format);
  BasicVariable::ptr res = WrapClass_wxFileName::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFileName::wxFileName(wxString const & path, wxString const & name, wxString const & ext, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_wxFileName_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_wxFileName_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & path = *path_smtptr;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxString > ext_smtptr;
  if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & ext = *ext_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName* _newobj = new wxFileName(path, name, ext, format);
  BasicVariable::ptr res = WrapClass_wxFileName::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxFileName wxFileName::FileName(wxString const & file, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_FileName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'file'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxFileName";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_FileName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > file_smtptr;
  if (!get_val_smtptr_param<wxString >(file_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & file = *file_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName res =   wxFileName::FileName(file, format);
  return AMILabType<wxFileName >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxFileName wxFileName::DirName(wxString const & dir, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_DirName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'dir'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxFileName";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_DirName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > dir_smtptr;
  if (!get_val_smtptr_param<wxString >(dir_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & dir = *dir_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName res =   wxFileName::DirName(dir, format);
  return AMILabType<wxFileName >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::FileExists(wxString const & file)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_FileExists::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'file'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_FileExists::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > file_smtptr;
  if (!get_val_smtptr_param<wxString >(file_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & file = *file_smtptr;

  bool res =   wxFileName::FileExists(file);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::DirExists(wxString const & dir)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_DirExists::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'dir'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_DirExists::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > dir_smtptr;
  if (!get_val_smtptr_param<wxString >(dir_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & dir = *dir_smtptr;

  bool res =   wxFileName::DirExists(dir);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsDirWritable(wxString const & path)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_IsDirWritable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_IsDirWritable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & path = *path_smtptr;

  bool res =   wxFileName::IsDirWritable(path);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsDirReadable(wxString const & path)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_IsDirReadable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_IsDirReadable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & path = *path_smtptr;

  bool res =   wxFileName::IsDirReadable(path);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsFileWritable(wxString const & path)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_IsFileWritable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_IsFileWritable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & path = *path_smtptr;

  bool res =   wxFileName::IsFileWritable(path);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsFileReadable(wxString const & path)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_IsFileReadable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_IsFileReadable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & path = *path_smtptr;

  bool res =   wxFileName::IsFileReadable(path);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsFileExecutable(wxString const & path)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_IsFileExecutable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_IsFileExecutable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & path = *path_smtptr;

  bool res =   wxFileName::IsFileExecutable(path);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetCwd(wxString const & volume = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetCwd::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'volume' (def:wxEmptyString)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetCwd::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > volume_smtptr;
  if (!get_val_smtptr_param<wxString >(volume_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & volume = ( volume_smtptr.get() ? (*volume_smtptr) : wxString(wxEmptyString) );

  wxString res =   wxFileName::GetCwd(volume);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::SetCwd(wxString const & cwd)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_SetCwd::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'cwd'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_SetCwd::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > cwd_smtptr;
  if (!get_val_smtptr_param<wxString >(cwd_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & cwd = *cwd_smtptr;

  bool res =   wxFileName::SetCwd(cwd);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetHomeDir()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetHomeDir::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetHomeDir::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   wxFileName::GetHomeDir();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetTempDir()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetTempDir::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetTempDir::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   wxFileName::GetTempDir();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::CreateTempFileName(wxString const & prefix)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_CreateTempFileName_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'prefix'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_CreateTempFileName_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > prefix_smtptr;
  if (!get_val_smtptr_param<wxString >(prefix_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & prefix = *prefix_smtptr;

  wxString res =   wxFileName::CreateTempFileName(prefix);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static wxFileName::CreateTempFileName(...)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_CreateTempFileName::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_CreateTempFileName::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFileName::wrap_static_CreateTempFileName_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxFile

//---------------------------------------------------
//  Wrapping of wxString wxFileName::CreateTempFileName(wxString const & prefix, wxFile * fileTemp)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_CreateTempFileName_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'prefix'")
  ADDPARAMCOMMENT_TYPE( wxFile, "parameter named 'fileTemp'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_CreateTempFileName_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > prefix_smtptr;
  if (!get_val_smtptr_param<wxString >(prefix_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & prefix = *prefix_smtptr;

  wxFile* fileTemp;
  if (CheckNullVar(_p,_n))  {
    fileTemp=(wxFile*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxFile > fileTemp_smtptr;
    if (!get_val_smtptr_param<wxFile >(fileTemp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    fileTemp = fileTemp_smtptr.get();
  }

  wxString res =   wxFileName::CreateTempFileName(prefix, fileTemp);
  return AMILabType<wxString >::CreateVar(res);
}
*/
/* The following types are missing: wxFFile

//---------------------------------------------------
//  Wrapping of wxString wxFileName::CreateTempFileName(wxString const & prefix, wxFFile * fileTemp)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_CreateTempFileName_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'prefix'")
  ADDPARAMCOMMENT_TYPE( wxFFile, "parameter named 'fileTemp'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_CreateTempFileName_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > prefix_smtptr;
  if (!get_val_smtptr_param<wxString >(prefix_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & prefix = *prefix_smtptr;

  wxFFile* fileTemp;
  if (CheckNullVar(_p,_n))  {
    fileTemp=(wxFFile*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxFFile > fileTemp_smtptr;
    if (!get_val_smtptr_param<wxFFile >(fileTemp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    fileTemp = fileTemp_smtptr.get();
  }

  wxString res =   wxFileName::CreateTempFileName(prefix, fileTemp);
  return AMILabType<wxString >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxFileName::Mkdir(wxString const & dir, int perm = 511, int flags = 0)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_Mkdir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'dir'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'perm' (def:511)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:0)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_Mkdir::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > dir_smtptr;
  if (!get_val_smtptr_param<wxString >(dir_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & dir = *dir_smtptr;

  int perm = 511;
  if (!get_val_param<int >(perm,_p,_n,false,false)) ClassHelpAndReturn;

  int flags = 0;
  if (!get_val_param<int >(flags,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   wxFileName::Mkdir(dir, perm, flags);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::Rmdir(wxString const & dir)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_Rmdir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'dir'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_Rmdir::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > dir_smtptr;
  if (!get_val_smtptr_param<wxString >(dir_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & dir = *dir_smtptr;

  bool res =   wxFileName::Rmdir(dir);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsCaseSensitive(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_IsCaseSensitive::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_IsCaseSensitive::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  bool res =   wxFileName::IsCaseSensitive(format);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetForbiddenChars(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetForbiddenChars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetForbiddenChars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxString res =   wxFileName::GetForbiddenChars(format);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetVolumeSeparator(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetVolumeSeparator::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetVolumeSeparator::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxString res =   wxFileName::GetVolumeSeparator(format);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetPathSeparators(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetPathSeparators::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetPathSeparators::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxString res =   wxFileName::GetPathSeparators(format);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetPathTerminators(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetPathTerminators::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetPathTerminators::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxString res =   wxFileName::GetPathTerminators(format);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxChar wxFileName::GetPathSeparator(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetPathSeparator::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetPathSeparator::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxChar res =   wxFileName::GetPathSeparator(format);
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsPathSeparator(wxChar ch, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_IsPathSeparator::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_IsPathSeparator::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n,true,false)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  bool res =   wxFileName::IsPathSeparator(ch, format);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPathFormat wxFileName::GetFormat(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetFormat::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetFormat::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxPathFormat res =   wxFileName::GetFormat(format);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SplitPath(wxString const & fullpath, wxString * volume, wxString * path, wxString * name, wxString * ext, bool * hasExt = 0l, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_SplitPath_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fullpath'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'volume'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'hasExt' (def:0l)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_SplitPath_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > fullpath_smtptr;
  if (!get_val_smtptr_param<wxString >(fullpath_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & fullpath = *fullpath_smtptr;

  wxString* volume;
  if (CheckNullVar(_p,_n))  {
    volume=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > volume_smtptr;
    if (!get_val_smtptr_param<wxString >(volume_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    volume = volume_smtptr.get();
  }

  wxString* path;
  if (CheckNullVar(_p,_n))  {
    path=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > path_smtptr;
    if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    path = path_smtptr.get();
  }

  wxString* name;
  if (CheckNullVar(_p,_n))  {
    name=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > name_smtptr;
    if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    name = name_smtptr.get();
  }

  wxString* ext;
  if (CheckNullVar(_p,_n))  {
    ext=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > ext_smtptr;
    if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    ext = ext_smtptr.get();
  }

  bool* hasExt = 0l;
  if (CheckNullVar(_p,_n))  {
    hasExt=(bool*)NULL;
    _n++;
  } else {
    boost::shared_ptr<bool > hasExt_smtptr;
    if (!get_val_smtptr_param<bool >(hasExt_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    hasExt = hasExt_smtptr.get();
  }

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName::SplitPath(fullpath, volume, path, name, ext, hasExt, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static wxFileName::SplitPath(...)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_SplitPath::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_SplitPath::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFileName::wrap_static_SplitPath_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_static_SplitPath_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_static_SplitPath_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SplitPath(wxString const & fullpath, wxString * volume, wxString * path, wxString * name, wxString * ext, wxPathFormat format)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_SplitPath_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fullpath'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'volume'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_SplitPath_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > fullpath_smtptr;
  if (!get_val_smtptr_param<wxString >(fullpath_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & fullpath = *fullpath_smtptr;

  wxString* volume;
  if (CheckNullVar(_p,_n))  {
    volume=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > volume_smtptr;
    if (!get_val_smtptr_param<wxString >(volume_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    volume = volume_smtptr.get();
  }

  wxString* path;
  if (CheckNullVar(_p,_n))  {
    path=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > path_smtptr;
    if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    path = path_smtptr.get();
  }

  wxString* name;
  if (CheckNullVar(_p,_n))  {
    name=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > name_smtptr;
    if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    name = name_smtptr.get();
  }

  wxString* ext;
  if (CheckNullVar(_p,_n))  {
    ext=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > ext_smtptr;
    if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    ext = ext_smtptr.get();
  }

  int format_int;
  if (!get_val_param<int >(format_int,_p,_n,true,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName::SplitPath(fullpath, volume, path, name, ext, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SplitPath(wxString const & fullpath, wxString * path, wxString * name, wxString * ext, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_SplitPath_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fullpath'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_SplitPath_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > fullpath_smtptr;
  if (!get_val_smtptr_param<wxString >(fullpath_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & fullpath = *fullpath_smtptr;

  wxString* path;
  if (CheckNullVar(_p,_n))  {
    path=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > path_smtptr;
    if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    path = path_smtptr.get();
  }

  wxString* name;
  if (CheckNullVar(_p,_n))  {
    name=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > name_smtptr;
    if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    name = name_smtptr.get();
  }

  wxString* ext;
  if (CheckNullVar(_p,_n))  {
    ext=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > ext_smtptr;
    if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    ext = ext_smtptr.get();
  }

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName::SplitPath(fullpath, path, name, ext, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SplitVolume(wxString const & fullpathWithVolume, wxString * volume, wxString * path, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_SplitVolume::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fullpathWithVolume'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'volume'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_SplitVolume::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > fullpathWithVolume_smtptr;
  if (!get_val_smtptr_param<wxString >(fullpathWithVolume_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & fullpathWithVolume = *fullpathWithVolume_smtptr;

  wxString* volume;
  if (CheckNullVar(_p,_n))  {
    volume=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > volume_smtptr;
    if (!get_val_smtptr_param<wxString >(volume_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    volume = volume_smtptr.get();
  }

  wxString* path;
  if (CheckNullVar(_p,_n))  {
    path=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > path_smtptr;
    if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    path = path_smtptr.get();
  }

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxFileName::SplitVolume(fullpathWithVolume, volume, path, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::StripExtension(wxString const & fullpath)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_StripExtension::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fullpath'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_StripExtension::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > fullpath_smtptr;
  if (!get_val_smtptr_param<wxString >(fullpath_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & fullpath = *fullpath_smtptr;

  wxString res =   wxFileName::StripExtension(fullpath);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLong wxFileName::GetSize(wxString const & file)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'file'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > file_smtptr;
  if (!get_val_smtptr_param<wxString >(file_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & file = *file_smtptr;

  wxULongLong res =   wxFileName::GetSize(file);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetHumanReadableSize(wxULongLong const & sz, wxString const & nullsize = wxGetTranslation(((const wchar_t*)'Not available'), 0u), int precision = 1)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_static_GetHumanReadableSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'nullsize' (def:wxGetTranslation(((const wchar_t*)'Not available'), 0u))")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'precision' (def:1)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_static_GetHumanReadableSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > sz_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(sz_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxULongLong const & sz = *sz_smtptr;

  boost::shared_ptr<wxString > nullsize_smtptr;
  if (!get_val_smtptr_param<wxString >(nullsize_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & nullsize = ( nullsize_smtptr.get() ? (*nullsize_smtptr) : wxString(wxGetTranslation(((const wchar_t*)"N\000\000\000o\000\000\000t\000\000\000 \000\000\000a\000\000\000v\000\000\000a\000\000\000i\000\000\000l\000\000\000a\000\000\000b\000\000\000l\000\000\000e\000\000\000\000\000\000"), 0u)) );

  int precision = 1;
  if (!get_val_param<int >(precision,_p,_n,false,false)) ClassHelpAndReturn;

  wxString res =   wxFileName::GetHumanReadableSize(sz, nullsize, precision);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxFileName.
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxFileName object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxFileName >::CreateVar( new wxFileName(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxFileName::Assign(wxFileName const & filepath)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Assign_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileName, "parameter named 'filepath'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Assign_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFileName > filepath_smtptr;
  if (!get_val_smtptr_param<wxFileName >(filepath_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxFileName const & filepath = *filepath_smtptr;

  this->_objectptr->GetObj()->Assign(filepath);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxFileName::Assign(...)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFileName::wrap_Assign_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_Assign_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_Assign_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_Assign_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_Assign_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_Assign_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxFileName::Assign(wxString const & fullpath, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Assign_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fullpath'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Assign_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > fullpath_smtptr;
  if (!get_val_smtptr_param<wxString >(fullpath_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & fullpath = *fullpath_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  this->_objectptr->GetObj()->Assign(fullpath, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::Assign(wxString const & volume, wxString const & path, wxString const & name, wxString const & ext, bool hasExt, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Assign_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'volume'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'hasExt'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Assign_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > volume_smtptr;
  if (!get_val_smtptr_param<wxString >(volume_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & volume = *volume_smtptr;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & path = *path_smtptr;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxString > ext_smtptr;
  if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & ext = *ext_smtptr;

  bool hasExt;
  if (!get_val_param<bool >(hasExt,_p,_n,true,true)) ClassReturnEmptyVar;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  this->_objectptr->GetObj()->Assign(volume, path, name, ext, hasExt, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::Assign(wxString const & volume, wxString const & path, wxString const & name, wxString const & ext, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Assign_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'volume'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Assign_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > volume_smtptr;
  if (!get_val_smtptr_param<wxString >(volume_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & volume = *volume_smtptr;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & path = *path_smtptr;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxString > ext_smtptr;
  if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & ext = *ext_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  this->_objectptr->GetObj()->Assign(volume, path, name, ext, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::Assign(wxString const & path, wxString const & name, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Assign_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Assign_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & path = *path_smtptr;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  this->_objectptr->GetObj()->Assign(path, name, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::Assign(wxString const & path, wxString const & name, wxString const & ext, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Assign_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Assign_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & path = *path_smtptr;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxString > ext_smtptr;
  if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & ext = *ext_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  this->_objectptr->GetObj()->Assign(path, name, ext, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::AssignDir(wxString const & dir, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_AssignDir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'dir'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_AssignDir::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > dir_smtptr;
  if (!get_val_smtptr_param<wxString >(dir_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & dir = *dir_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  this->_objectptr->GetObj()->AssignDir(dir, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::Clear()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsOk()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::FileExists()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_FileExists::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_FileExists::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->FileExists();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::DirExists()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_DirExists::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_DirExists::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->DirExists();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsDirWritable()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_IsDirWritable::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_IsDirWritable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDirWritable();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsDirReadable()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_IsDirReadable::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_IsDirReadable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDirReadable();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsFileWritable()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_IsFileWritable::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_IsFileWritable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFileWritable();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsFileReadable()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_IsFileReadable::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_IsFileReadable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFileReadable();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsFileExecutable()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_IsFileExecutable::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_IsFileExecutable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFileExecutable();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::SetTimes(wxDateTime const * dtAccess, wxDateTime const * dtMod, wxDateTime const * dtCreate)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_SetTimes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dtAccess'")
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dtMod'")
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dtCreate'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_SetTimes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  wxDateTime* dtAccess;
  if (CheckNullVar(_p,_n))  {
    dtAccess=(wxDateTime*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDateTime > dtAccess_smtptr;
    if (!get_val_smtptr_param<wxDateTime >(dtAccess_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    dtAccess = dtAccess_smtptr.get();
  }

  wxDateTime* dtMod;
  if (CheckNullVar(_p,_n))  {
    dtMod=(wxDateTime*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDateTime > dtMod_smtptr;
    if (!get_val_smtptr_param<wxDateTime >(dtMod_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    dtMod = dtMod_smtptr.get();
  }

  wxDateTime* dtCreate;
  if (CheckNullVar(_p,_n))  {
    dtCreate=(wxDateTime*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDateTime > dtCreate_smtptr;
    if (!get_val_smtptr_param<wxDateTime >(dtCreate_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    dtCreate = dtCreate_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->SetTimes(dtAccess, dtMod, dtCreate);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::Touch()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Touch::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Touch::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Touch();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::GetTimes(wxDateTime * dtAccess, wxDateTime * dtMod, wxDateTime * dtCreate)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetTimes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dtAccess'")
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dtMod'")
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'dtCreate'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetTimes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  wxDateTime* dtAccess;
  if (CheckNullVar(_p,_n))  {
    dtAccess=(wxDateTime*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDateTime > dtAccess_smtptr;
    if (!get_val_smtptr_param<wxDateTime >(dtAccess_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    dtAccess = dtAccess_smtptr.get();
  }

  wxDateTime* dtMod;
  if (CheckNullVar(_p,_n))  {
    dtMod=(wxDateTime*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDateTime > dtMod_smtptr;
    if (!get_val_smtptr_param<wxDateTime >(dtMod_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    dtMod = dtMod_smtptr.get();
  }

  wxDateTime* dtCreate;
  if (CheckNullVar(_p,_n))  {
    dtCreate=(wxDateTime*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDateTime > dtCreate_smtptr;
    if (!get_val_smtptr_param<wxDateTime >(dtCreate_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    dtCreate = dtCreate_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->GetTimes(dtAccess, dtMod, dtCreate);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxFileName::GetModificationTime()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetModificationTime::SetParametersComments()
{
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetModificationTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->GetModificationTime();
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFileName::AssignCwd(wxString const & volume = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_AssignCwd::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'volume' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_AssignCwd::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > volume_smtptr;
  if (!get_val_smtptr_param<wxString >(volume_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & volume = ( volume_smtptr.get() ? (*volume_smtptr) : wxString(wxEmptyString) );

  this->_objectptr->GetObj()->AssignCwd(volume);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::SetCwd()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_SetCwd::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_SetCwd::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->SetCwd();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFileName::AssignHomeDir()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_AssignHomeDir::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_AssignHomeDir::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AssignHomeDir();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::AssignTempFileName(wxString const & prefix)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_AssignTempFileName_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'prefix'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_AssignTempFileName_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > prefix_smtptr;
  if (!get_val_smtptr_param<wxString >(prefix_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & prefix = *prefix_smtptr;

  this->_objectptr->GetObj()->AssignTempFileName(prefix);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxFileName::AssignTempFileName(...)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_AssignTempFileName::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_AssignTempFileName::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFileName::wrap_AssignTempFileName_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxFile

//---------------------------------------------------
//  Wrapping of void wxFileName::AssignTempFileName(wxString const & prefix, wxFile * fileTemp)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_AssignTempFileName_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'prefix'")
  ADDPARAMCOMMENT_TYPE( wxFile, "parameter named 'fileTemp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_AssignTempFileName_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > prefix_smtptr;
  if (!get_val_smtptr_param<wxString >(prefix_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & prefix = *prefix_smtptr;

  wxFile* fileTemp;
  if (CheckNullVar(_p,_n))  {
    fileTemp=(wxFile*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxFile > fileTemp_smtptr;
    if (!get_val_smtptr_param<wxFile >(fileTemp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    fileTemp = fileTemp_smtptr.get();
  }

  this->_objectptr->GetObj()->AssignTempFileName(prefix, fileTemp);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxFFile

//---------------------------------------------------
//  Wrapping of void wxFileName::AssignTempFileName(wxString const & prefix, wxFFile * fileTemp)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_AssignTempFileName_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'prefix'")
  ADDPARAMCOMMENT_TYPE( wxFFile, "parameter named 'fileTemp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_AssignTempFileName_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > prefix_smtptr;
  if (!get_val_smtptr_param<wxString >(prefix_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & prefix = *prefix_smtptr;

  wxFFile* fileTemp;
  if (CheckNullVar(_p,_n))  {
    fileTemp=(wxFFile*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxFFile > fileTemp_smtptr;
    if (!get_val_smtptr_param<wxFFile >(fileTemp_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    fileTemp = fileTemp_smtptr.get();
  }

  this->_objectptr->GetObj()->AssignTempFileName(prefix, fileTemp);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of bool wxFileName::Mkdir(int perm = 511, int flags = 0)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Mkdir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'perm' (def:511)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:0)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Mkdir::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int perm = 511;
  if (!get_val_param<int >(perm,_p,_n,false,false)) ClassHelpAndReturn;

  int flags = 0;
  if (!get_val_param<int >(flags,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Mkdir(perm, flags);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::Rmdir()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Rmdir::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Rmdir::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Rmdir();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::Normalize(int flags = wxPATH_NORM_ALL, wxString const & cwd = wxEmptyString, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_Normalize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxPATH_NORM_ALL)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'cwd' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_Normalize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int flags = wxPATH_NORM_ALL;
  if (!get_val_param<int >(flags,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > cwd_smtptr;
  if (!get_val_smtptr_param<wxString >(cwd_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & cwd = ( cwd_smtptr.get() ? (*cwd_smtptr) : wxString(wxEmptyString) );

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  bool res =   this->_objectptr->GetObj()->Normalize(flags, cwd, format);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::MakeRelativeTo(wxString const & pathBase = wxEmptyString, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_MakeRelativeTo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'pathBase' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_MakeRelativeTo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > pathBase_smtptr;
  if (!get_val_smtptr_param<wxString >(pathBase_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & pathBase = ( pathBase_smtptr.get() ? (*pathBase_smtptr) : wxString(wxEmptyString) );

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  bool res =   this->_objectptr->GetObj()->MakeRelativeTo(pathBase, format);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::MakeAbsolute(wxString const & cwd = wxEmptyString, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_MakeAbsolute::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'cwd' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_MakeAbsolute::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > cwd_smtptr;
  if (!get_val_smtptr_param<wxString >(cwd_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & cwd = ( cwd_smtptr.get() ? (*cwd_smtptr) : wxString(wxEmptyString) );

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  bool res =   this->_objectptr->GetObj()->MakeAbsolute(cwd, format);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::SameAs(wxFileName const & filepath, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_SameAs::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileName, "parameter named 'filepath'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_SameAs::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFileName > filepath_smtptr;
  if (!get_val_smtptr_param<wxFileName >(filepath_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFileName const & filepath = *filepath_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  bool res =   this->_objectptr->GetObj()->SameAs(filepath, format);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsAbsolute(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_IsAbsolute::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_IsAbsolute::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  bool res =   this->_objectptr->GetObj()->IsAbsolute(format);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsRelative(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_IsRelative::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_IsRelative::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  bool res =   this->_objectptr->GetObj()->IsRelative(format);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxFileName::GetDirCount()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetDirCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetDirCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetDirCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxFileName::AppendDir(wxString const & dir)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_AppendDir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'dir'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_AppendDir::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > dir_smtptr;
  if (!get_val_smtptr_param<wxString >(dir_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & dir = *dir_smtptr;

  this->_objectptr->GetObj()->AppendDir(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::PrependDir(wxString const & dir)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_PrependDir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'dir'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_PrependDir::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > dir_smtptr;
  if (!get_val_smtptr_param<wxString >(dir_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & dir = *dir_smtptr;

  this->_objectptr->GetObj()->PrependDir(dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::InsertDir(size_t before, wxString const & dir)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_InsertDir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'before'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'dir'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_InsertDir::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long before_long;
  if (!get_val_param<long >(before_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int before = boost::numeric_cast<long unsigned int >(before_long);

  boost::shared_ptr<wxString > dir_smtptr;
  if (!get_val_smtptr_param<wxString >(dir_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & dir = *dir_smtptr;

  this->_objectptr->GetObj()->InsertDir(before, dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::RemoveDir(size_t pos)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_RemoveDir::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_RemoveDir::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  this->_objectptr->GetObj()->RemoveDir(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::RemoveLastDir()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_RemoveLastDir::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_RemoveLastDir::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveLastDir();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SetExt(wxString const & ext)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_SetExt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_SetExt::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > ext_smtptr;
  if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & ext = *ext_smtptr;

  this->_objectptr->GetObj()->SetExt(ext);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::ClearExt()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_ClearExt::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_ClearExt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClearExt();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SetEmptyExt()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_SetEmptyExt::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_SetEmptyExt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEmptyExt();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetExt()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetExt::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetExt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetExt();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::HasExt()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_HasExt::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_HasExt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasExt();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SetName(wxString const & name)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_SetName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_SetName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  this->_objectptr->GetObj()->SetName(name);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetName()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::HasName()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_HasName::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_HasName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasName();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SetVolume(wxString const & volume)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_SetVolume::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'volume'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_SetVolume::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > volume_smtptr;
  if (!get_val_smtptr_param<wxString >(volume_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & volume = *volume_smtptr;

  this->_objectptr->GetObj()->SetVolume(volume);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetVolume()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetVolume::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetVolume::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetVolume();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::HasVolume()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_HasVolume::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_HasVolume::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasVolume();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SetFullName(wxString const & fullname)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_SetFullName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fullname'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_SetFullName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > fullname_smtptr;
  if (!get_val_smtptr_param<wxString >(fullname_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & fullname = *fullname_smtptr;

  this->_objectptr->GetObj()->SetFullName(fullname);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetFullName()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetFullName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetFullName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetFullName();
  return AMILabType<wxString >::CreateVar(res);
}
/* The following types are missing: wxArrayString

//---------------------------------------------------
//  Wrapping of wxArrayString const & wxFileName::GetDirs()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetDirs::SetParametersComments()
{
  return_comments="returning a variable of type wxArrayString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetDirs::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxArrayString const & res =   this->_objectptr->GetObj()->GetDirs();
  return AMILabType<wxArrayString >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetPath(int flags = wxPATH_GET_VOLUME, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetPath_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxPATH_GET_VOLUME)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetPath_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int flags = wxPATH_GET_VOLUME;
  if (!get_val_param<int >(flags,_p,_n,false,true)) ClassReturnEmptyVar;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  wxString res =   this->_objectptr->GetObj()->GetPath(flags, format);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFileName::SetPath(wxString const & path, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_SetPath::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_SetPath::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > path_smtptr;
  if (!get_val_smtptr_param<wxString >(path_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & path = *path_smtptr;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  this->_objectptr->GetObj()->SetPath(path, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetFullPath(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetFullPath::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetFullPath::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxString res =   this->_objectptr->GetObj()->GetFullPath(format);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetShortPath()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetShortPath::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetShortPath::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetShortPath();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetLongPath()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetLongPath::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetLongPath::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetLongPath();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::IsDir()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_IsDir::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_IsDir::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDir();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLong wxFileName::GetSize()
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxULongLong res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetHumanReadableSize(wxString const & nullsize = wxGetTranslation(((const wchar_t*)'Not available'), 0u), int precision = 1)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetHumanReadableSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'nullsize' (def:wxGetTranslation(((const wchar_t*)'Not available'), 0u))")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'precision' (def:1)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetHumanReadableSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > nullsize_smtptr;
  if (!get_val_smtptr_param<wxString >(nullsize_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & nullsize = ( nullsize_smtptr.get() ? (*nullsize_smtptr) : wxString(wxGetTranslation(((const wchar_t*)"N\000\000\000o\000\000\000t\000\000\000 \000\000\000a\000\000\000v\000\000\000a\000\000\000i\000\000\000l\000\000\000a\000\000\000b\000\000\000l\000\000\000e\000\000\000\000\000\000"), 0u)) );

  int precision = 1;
  if (!get_val_param<int >(precision,_p,_n,false,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetHumanReadableSize(nullsize, precision);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxFileName::GetPath(...)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetPath::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetPath::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFileName::wrap_GetPath_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap_GetPath_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetPath(bool withSep, wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetPath_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'withSep'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetPath_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  bool withSep;
  if (!get_val_param<bool >(withSep,_p,_n,true,true)) ClassReturnEmptyVar;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxPathFormat format = (wxPathFormat) format_int;

  wxString res =   this->_objectptr->GetObj()->GetPath(withSep, format);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileName::GetPathWithSep(wxPathFormat format = wxPATH_NATIVE)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap_GetPathWithSep::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'format' (def:wxPATH_NATIVE)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap_GetPathWithSep::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int format_int = (int) wxPATH_NATIVE;;
  if (!get_val_param<int >(format_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPathFormat format = (wxPathFormat) format_int;

  wxString res =   this->_objectptr->GetObj()->GetPathWithSep(format);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxFileName & wxFileName::operator =(wxFileName const & filename)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileName, "parameter named 'filename'")
  return_comments="returning a variable of type wxFileName";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFileName > filename_smtptr;
  if (!get_val_smtptr_param<wxFileName >(filename_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxFileName const & filename = *filename_smtptr;

  wxFileName & res =   (*this->_objectptr->GetObj()) = (filename);
  return AMILabType<wxFileName >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxFileName::=(...)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFileName::wrap___assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap___assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxFileName & wxFileName::operator =(wxString const & filename)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'filename'")
  return_comments="returning a variable of type wxFileName";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > filename_smtptr;
  if (!get_val_smtptr_param<wxString >(filename_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & filename = *filename_smtptr;

  wxFileName & res =   (*this->_objectptr->GetObj()) = (filename);
  return AMILabType<wxFileName >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::operator ==(wxFileName const & filename)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___equal___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileName, "parameter named 'filename'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___equal___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFileName > filename_smtptr;
  if (!get_val_smtptr_param<wxFileName >(filename_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxFileName const & filename = *filename_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (filename);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::operator !=(wxFileName const & filename)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___not_equal___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileName, "parameter named 'filename'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___not_equal___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFileName > filename_smtptr;
  if (!get_val_smtptr_param<wxFileName >(filename_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxFileName const & filename = *filename_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (filename);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxFileName::==(...)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___equal__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___equal__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFileName::wrap___equal___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap___equal___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::operator ==(wxString const & filename)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___equal___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'filename'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___equal___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > filename_smtptr;
  if (!get_val_smtptr_param<wxString >(filename_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & filename = *filename_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (filename);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxFileName::!=(...)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___not_equal__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFileName::wrap___not_equal___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFileName::wrap___not_equal___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxFileName::operator !=(wxString const & filename)
//---------------------------------------------------
void WrapClass_wxFileName::
    wrap___not_equal___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'filename'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileName::
    wrap___not_equal___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > filename_smtptr;
  if (!get_val_smtptr_param<wxString >(filename_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & filename = *filename_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (filename);
  return AMILabType<bool >::CreateVar(res);
}

