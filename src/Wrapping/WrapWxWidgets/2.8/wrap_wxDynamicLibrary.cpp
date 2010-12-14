/**
 * C++ Interface: wrap_wxDynamicLibrary
 *
 * Description: wrapping wxDynamicLibrary
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

#include "wrap_wxDynamicLibrary.h"

// get all the required includes
// #include "..."
#include "stdlib.h"
#include "wchar.h"
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxDynamicLibraryDetailsArray_declared
  #define wxDynamicLibraryDetailsArray_declared
  AMI_DECLARE_TYPE(wxDynamicLibraryDetailsArray)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxDynamicLibrary>::CreateVar( ParamList* p)
{
  WrapClass_wxDynamicLibrary::wrap_wxDynamicLibrary construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxDynamicLibrary);
AMI_DEFINE_VARFROMSMTPTR(wxDynamicLibrary);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxDynamicLibrary>::CreateVar( wxDynamicLibrary* val, bool nodeleter)
{ 
  boost::shared_ptr<wxDynamicLibrary> obj_ptr(val,smartpointer_nodeleter<wxDynamicLibrary>());
  return AMILabType<wxDynamicLibrary>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDynamicLibrary
//
Variable<AMIObject>::ptr WrapClass_wxDynamicLibrary::CreateVar( wxDynamicLibrary* sp)
{
  boost::shared_ptr<wxDynamicLibrary> di_ptr(
    sp,
    wxwindow_nodeleter<wxDynamicLibrary>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDynamicLibrary>::CreateVar(
      new WrapClass_wxDynamicLibrary(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDynamicLibrary::AddMethods(WrapClass<wxDynamicLibrary>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsLoaded( this_ptr);
  AddVar_Load( this_ptr);
  AddVar_Detach( this_ptr);
  AddVar_Unload( this_ptr);
  AddVar_GetLibHandle( this_ptr);
  AddVar_HasSymbol( this_ptr);
  AddVar_GetSymbol( this_ptr);
  AddVar_RawGetSymbol( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDynamicLibrary_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxDynamicLibrary");
    WrapClass_wxDynamicLibrary::AddVar_wxDynamicLibrary_1(amiobject->GetContext());
  WrapClass_wxDynamicLibrary::AddVar_wxDynamicLibrary(amiobject->GetContext());
  WrapClass_wxDynamicLibrary::AddVar_wxDynamicLibrary_2(amiobject->GetContext());


  // Static methods 
  WrapClass_wxDynamicLibrary::AddVar_GetProgramHandle(amiobject->GetContext());
  WrapClass_wxDynamicLibrary::AddVar_GetDllExt(amiobject->GetContext());
  WrapClass_wxDynamicLibrary::AddVar_RawLoad(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxDynamicLibrary::AddVar_Unload(amiobject->GetContext());
  */
  /* Types are missing
  WrapClass_wxDynamicLibrary::AddVar_RawGetSymbol(amiobject->GetContext());
  */
  WrapClass_wxDynamicLibrary::AddVar_ListLoaded(amiobject->GetContext());
  WrapClass_wxDynamicLibrary::AddVar_CanonicalizeName(amiobject->GetContext());
  WrapClass_wxDynamicLibrary::AddVar_CanonicalizePluginName(amiobject->GetContext());
  WrapClass_wxDynamicLibrary::AddVar_GetPluginsDirectory(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxDynamicLibrary::wxDynamicLibrary()
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_wxDynamicLibrary_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_wxDynamicLibrary_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxDynamicLibrary* _newobj = new wxDynamicLibrary();
  BasicVariable::ptr res = WrapClass_wxDynamicLibrary::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxDynamicLibrary::wxDynamicLibrary(...)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_wxDynamicLibrary::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_wxDynamicLibrary::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDynamicLibrary::wrap_wxDynamicLibrary_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDynamicLibrary::wrap_wxDynamicLibrary_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDynamicLibrary::wxDynamicLibrary(wxString const & libname, int flags = wxDL_NOW)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_wxDynamicLibrary_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'libname'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxDL_NOW)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_wxDynamicLibrary_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > libname_smtptr;
  if (!get_val_smtptr_param<wxString >(libname_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & libname = *libname_smtptr;

  int flags = wxDL_NOW;
  if (!get_val_param<int >(flags,_p,_n,false,true)) ClassReturnEmptyVar;

  wxDynamicLibrary* _newobj = new wxDynamicLibrary(libname, flags);
  BasicVariable::ptr res = WrapClass_wxDynamicLibrary::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxDllType wxDynamicLibrary::GetProgramHandle()
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_static_GetProgramHandle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_static_GetProgramHandle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDynamicLibrary::GetProgramHandle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxDynamicLibrary::GetDllExt()
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_static_GetDllExt::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_static_GetDllExt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar const * res =   wxDynamicLibrary::GetDllExt();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxDllType wxDynamicLibrary::RawLoad(wxString const & libname, int flags = wxDL_NOW)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_static_RawLoad::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'libname'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxDL_NOW)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_static_RawLoad::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > libname_smtptr;
  if (!get_val_smtptr_param<wxString >(libname_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & libname = *libname_smtptr;

  int flags = wxDL_NOW;
  if (!get_val_param<int >(flags,_p,_n,false,false)) ClassHelpAndReturn;

  wxDynamicLibrary::RawLoad(libname, flags);
  return BasicVariable::ptr();
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of void wxDynamicLibrary::Unload(wxDllType handle)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_static_Unload::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'handle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_static_Unload::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  void handle;
  if (!get_val_param<void >(handle,_p,_n,true,false)) ClassHelpAndReturn;

  wxDynamicLibrary::Unload(handle);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of void * wxDynamicLibrary::RawGetSymbol(wxDllType handle, wxString const & name)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_static_RawGetSymbol::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'handle'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_static_RawGetSymbol::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  void handle;
  if (!get_val_param<void >(handle,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  wxDynamicLibrary::RawGetSymbol(handle, name);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxDynamicLibraryDetailsArray wxDynamicLibrary::ListLoaded()
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_static_ListLoaded::SetParametersComments()
{
  return_comments="returning a variable of type wxDynamicLibraryDetailsArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_static_ListLoaded::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDynamicLibraryDetailsArray res =   wxDynamicLibrary::ListLoaded();
  return AMILabType<wxDynamicLibraryDetailsArray >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxDynamicLibrary::CanonicalizeName(wxString const & name, wxDynamicLibraryCategory cat = wxDL_LIBRARY)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_static_CanonicalizeName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cat' (def:wxDL_LIBRARY)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_static_CanonicalizeName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  int cat_int = (int) wxDL_LIBRARY;;
  if (!get_val_param<int >(cat_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxDynamicLibraryCategory cat = (wxDynamicLibraryCategory) cat_int;

  wxString res =   wxDynamicLibrary::CanonicalizeName(name, cat);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxDynamicLibrary::CanonicalizePluginName(wxString const & name, wxPluginCategory cat = wxDL_PLUGIN_GUI)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_static_CanonicalizePluginName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cat' (def:wxDL_PLUGIN_GUI)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_static_CanonicalizePluginName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  int cat_int = (int) wxDL_PLUGIN_GUI;;
  if (!get_val_param<int >(cat_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxPluginCategory cat = (wxPluginCategory) cat_int;

  wxString res =   wxDynamicLibrary::CanonicalizePluginName(name, cat);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxDynamicLibrary::GetPluginsDirectory()
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_static_GetPluginsDirectory::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_static_GetPluginsDirectory::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   wxDynamicLibrary::GetPluginsDirectory();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDynamicLibrary::IsLoaded()
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_IsLoaded::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_IsLoaded::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsLoaded();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDynamicLibrary::Load(wxString const & libname, int flags = wxDL_NOW)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_Load::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'libname'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxDL_NOW)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_Load::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > libname_smtptr;
  if (!get_val_smtptr_param<wxString >(libname_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & libname = *libname_smtptr;

  int flags = wxDL_NOW;
  if (!get_val_param<int >(flags,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Load(libname, flags);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDllType wxDynamicLibrary::Detach()
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_Detach::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_Detach::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Detach();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibrary::Unload()
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_Unload::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_Unload::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Unload();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxDllType wxDynamicLibrary::GetLibHandle()
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_GetLibHandle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_GetLibHandle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GetLibHandle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxDynamicLibrary::HasSymbol(wxString const & name)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_HasSymbol::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_HasSymbol::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  bool res =   this->_objectptr->GetObj()->HasSymbol(name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void * wxDynamicLibrary::GetSymbol(wxString const & name, bool * success = 0l)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_GetSymbol::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'success' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_GetSymbol::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  bool* success = 0l;
  if (CheckNullVar(_p,_n))  {
    success=(bool*)NULL;
    _n++;
  } else {
    boost::shared_ptr<bool > success_smtptr;
    if (!get_val_smtptr_param<bool >(success_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    success = success_smtptr.get();
  }

  this->_objectptr->GetObj()->GetSymbol(name, success);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void * wxDynamicLibrary::RawGetSymbol(wxString const & name)
//---------------------------------------------------
void WrapClass_wxDynamicLibrary::
    wrap_RawGetSymbol::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibrary::
    wrap_RawGetSymbol::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  this->_objectptr->GetObj()->RawGetSymbol(name);
  return BasicVariable::ptr();
}

