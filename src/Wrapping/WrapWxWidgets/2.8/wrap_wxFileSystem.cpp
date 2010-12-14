/**
 * C++ Interface: wrap_wxFileSystem
 *
 * Description: wrapping wxFileSystem
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

#include "wrap_wxFileSystem.h"

// get all the required includes
// #include "..."
#include "stdlib.h"
#ifndef wxFileSystemHandler_declared
  #define wxFileSystemHandler_declared
  AMI_DECLARE_TYPE(wxFileSystemHandler)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxFileName_declared
  #define wxFileName_declared
  AMI_DECLARE_TYPE(wxFileName)
#endif
#ifndef wxFSFile_declared
  #define wxFSFile_declared
  AMI_DECLARE_TYPE(wxFSFile)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxFileSystem>::CreateVar( ParamList* p)
{
  WrapClass_wxFileSystem::wrap_wxFileSystem construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxFileSystem);
AMI_DEFINE_VARFROMSMTPTR(wxFileSystem);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxFileSystem>::CreateVar( wxFileSystem* val, bool nodeleter)
{ 
  boost::shared_ptr<wxFileSystem> obj_ptr(val,smartpointer_nodeleter<wxFileSystem>());
  return AMILabType<wxFileSystem>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxFileSystem
//
Variable<AMIObject>::ptr WrapClass_wxFileSystem::CreateVar( wxFileSystem* sp)
{
  boost::shared_ptr<wxFileSystem> di_ptr(
    sp,
    wxwindow_nodeleter<wxFileSystem>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFileSystem>::CreateVar(
      new WrapClass_wxFileSystem(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxFileSystem::AddMethods(WrapClass<wxFileSystem>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_ChangePathTo( this_ptr);
  AddVar_GetPath( this_ptr);
  AddVar_OpenFile( this_ptr);
  AddVar_FindFirst( this_ptr);
  AddVar_FindNext( this_ptr);
  AddVar_FindFileInPath( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxObject
  boost::shared_ptr<wxObject > parent_wxObject(  boost::dynamic_pointer_cast<wxObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxObject = AMILabType<wxObject >::CreateVarFromSmtPtr(parent_wxObject);
  context->AddVar("wxObject",var_wxObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxObject);
  context->AddDefault(obj_wxObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxFileSystem_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxFileSystem");
    WrapClass_wxFileSystem::AddVar_wxFileSystem(amiobject->GetContext());


  // Static methods 
  WrapClass_wxFileSystem::AddVar_AddHandler(amiobject->GetContext());
  WrapClass_wxFileSystem::AddVar_RemoveHandler(amiobject->GetContext());
  WrapClass_wxFileSystem::AddVar_HasHandlerForPath(amiobject->GetContext());
  WrapClass_wxFileSystem::AddVar_CleanUpHandlers(amiobject->GetContext());
  WrapClass_wxFileSystem::AddVar_URLToFileName(amiobject->GetContext());
  WrapClass_wxFileSystem::AddVar_FileNameToURL(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxFileSystem::wxFileSystem()
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_wxFileSystem::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_wxFileSystem::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFileSystem* _newobj = new wxFileSystem();
  BasicVariable::ptr res = WrapClass_wxFileSystem::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxFileSystem::AddHandler(wxFileSystemHandler * handler)
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_static_AddHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileSystemHandler, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_static_AddHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxFileSystemHandler* handler;
  if (CheckNullVar(_p,_n))  {
    handler=(wxFileSystemHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxFileSystemHandler > handler_smtptr;
    if (!get_val_smtptr_param<wxFileSystemHandler >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    handler = handler_smtptr.get();
  }

  wxFileSystem::AddHandler(handler);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxFileSystemHandler * wxFileSystem::RemoveHandler(wxFileSystemHandler * handler)
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_static_RemoveHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileSystemHandler, "parameter named 'handler'")
  return_comments="returning a variable of type wxFileSystemHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_static_RemoveHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxFileSystemHandler* handler;
  if (CheckNullVar(_p,_n))  {
    handler=(wxFileSystemHandler*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxFileSystemHandler > handler_smtptr;
    if (!get_val_smtptr_param<wxFileSystemHandler >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    handler = handler_smtptr.get();
  }

  wxFileSystemHandler * res =   wxFileSystem::RemoveHandler(handler);
  BasicVariable::ptr res_var = AMILabType<wxFileSystemHandler >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxFileSystem::HasHandlerForPath(wxString const & location)
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_static_HasHandlerForPath::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'location'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_static_HasHandlerForPath::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > location_smtptr;
  if (!get_val_smtptr_param<wxString >(location_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & location = *location_smtptr;

  bool res =   wxFileSystem::HasHandlerForPath(location);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFileSystem::CleanUpHandlers()
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_static_CleanUpHandlers::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_static_CleanUpHandlers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFileSystem::CleanUpHandlers();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxFileName wxFileSystem::URLToFileName(wxString const & url)
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_static_URLToFileName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'url'")
  return_comments="returning a variable of type wxFileName";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_static_URLToFileName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > url_smtptr;
  if (!get_val_smtptr_param<wxString >(url_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & url = *url_smtptr;

  wxFileName res =   wxFileSystem::URLToFileName(url);
  return AMILabType<wxFileName >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileSystem::FileNameToURL(wxFileName const & filename)
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_static_FileNameToURL::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileName, "parameter named 'filename'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_static_FileNameToURL::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFileName > filename_smtptr;
  if (!get_val_smtptr_param<wxFileName >(filename_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFileName const & filename = *filename_smtptr;

  wxString res =   wxFileSystem::FileNameToURL(filename);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFileSystem::ChangePathTo(wxString const & location, bool is_dir = false)
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_ChangePathTo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'location'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'is_dir' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_ChangePathTo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > location_smtptr;
  if (!get_val_smtptr_param<wxString >(location_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & location = *location_smtptr;

  bool is_dir = false;
  if (!get_val_param<bool >(is_dir,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ChangePathTo(location, is_dir);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxFileSystem::GetPath()
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_GetPath::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_GetPath::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetPath();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxFSFile * wxFileSystem::OpenFile(wxString const & location, int flags = wxFS_READ)
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_OpenFile::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'location'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxFS_READ)")
  return_comments="returning a variable of type wxFSFile";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_OpenFile::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > location_smtptr;
  if (!get_val_smtptr_param<wxString >(location_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & location = *location_smtptr;

  int flags = wxFS_READ;
  if (!get_val_param<int >(flags,_p,_n,false,false)) ClassHelpAndReturn;

  wxFSFile * res =   this->_objectptr->GetObj()->OpenFile(location, flags);
  BasicVariable::ptr res_var = AMILabType<wxFSFile >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxString wxFileSystem::FindFirst(wxString const & spec, int flags = 0)
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_FindFirst::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'spec'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:0)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_FindFirst::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > spec_smtptr;
  if (!get_val_smtptr_param<wxString >(spec_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & spec = *spec_smtptr;

  int flags = 0;
  if (!get_val_param<int >(flags,_p,_n,false,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FindFirst(spec, flags);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileSystem::FindNext()
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_FindNext::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_FindNext::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FindNext();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFileSystem::FindFileInPath(wxString * pStr, wxChar const * path, wxChar const * file)
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_FindFileInPath::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'pStr'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'path'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'file'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_FindFileInPath::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  wxString* pStr;
  if (CheckNullVar(_p,_n))  {
    pStr=(wxString*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxString > pStr_smtptr;
    if (!get_val_smtptr_param<wxString >(pStr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    pStr = pStr_smtptr.get();
  }

  boost::shared_ptr<std::string > path_string;
  if (!get_val_smtptr_param<std::string >(path_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t path[path_string->size()+1];
mbstowcs(path,path_string->c_str(),path_string->size()+1);

  boost::shared_ptr<std::string > file_string;
  if (!get_val_smtptr_param<std::string >(file_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t file[file_string->size()+1];
mbstowcs(file,file_string->c_str(),file_string->size()+1);

  bool res =   this->_objectptr->GetObj()->FindFileInPath(pStr, path, file);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxFileSystem::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxFileSystem::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystem::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

