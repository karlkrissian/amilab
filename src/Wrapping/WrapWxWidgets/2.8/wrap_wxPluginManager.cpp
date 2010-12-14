/**
 * C++ Interface: wrap_wxPluginManager
 *
 * Description: wrapping wxPluginManager
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

#include "wrap_wxPluginManager.h"

// get all the required includes
// #include "..."
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxPluginBase_declared
  #define wxPluginBase_declared
  AMI_DECLARE_TYPE(wxPluginBase)
#endif
#ifndef wxDynamicLibrary_declared
  #define wxDynamicLibrary_declared
  AMI_DECLARE_TYPE(wxDynamicLibrary)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPluginManager>::CreateVar( ParamList* p)
{
  WrapClass_wxPluginManager::wrap_wxPluginManager construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxPluginManager);
AMI_DEFINE_VARFROMSMTPTR(wxPluginManager);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxPluginManager>::CreateVar( wxPluginManager* val, bool nodeleter)
{ 
  boost::shared_ptr<wxPluginManager> obj_ptr(val,smartpointer_nodeleter<wxPluginManager>());
  return AMILabType<wxPluginManager>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPluginManager
//
Variable<AMIObject>::ptr WrapClass_wxPluginManager::CreateVar( wxPluginManager* sp)
{
  boost::shared_ptr<wxPluginManager> di_ptr(
    sp,
    wxwindow_nodeleter<wxPluginManager>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPluginManager>::CreateVar(
      new WrapClass_wxPluginManager(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPluginManager::AddMethods(WrapClass<wxPluginManager>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_get_name( this_ptr);
  AddVar_Load( this_ptr);
  AddVar_Detach( this_ptr);
  AddVar_Unload( this_ptr);
  AddVar_Getplugin( this_ptr);
  AddVar_Getdll( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPluginManager_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxPluginManager");
    WrapClass_wxPluginManager::AddVar_wxPluginManager(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxPluginManager::wxPluginManager()
//---------------------------------------------------
void WrapClass_wxPluginManager::
    wrap_wxPluginManager::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginManager::
    wrap_wxPluginManager::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPluginManager* _newobj = new wxPluginManager();
  BasicVariable::ptr res = WrapClass_wxPluginManager::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of char const * wxPluginManager::get_name()
//---------------------------------------------------
void WrapClass_wxPluginManager::
    wrap_get_name::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginManager::
    wrap_get_name::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->get_name();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of bool wxPluginManager::Load(wxString const & LibName)
//---------------------------------------------------
void WrapClass_wxPluginManager::
    wrap_Load::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'LibName'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginManager::
    wrap_Load::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > LibName_smtptr;
  if (!get_val_smtptr_param<wxString >(LibName_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & LibName = *LibName_smtptr;

  bool res =   this->_objectptr->GetObj()->Load(LibName);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxPluginManager::Detach()
//---------------------------------------------------
void WrapClass_wxPluginManager::
    wrap_Detach::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginManager::
    wrap_Detach::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Detach();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPluginManager::Unload()
//---------------------------------------------------
void WrapClass_wxPluginManager::
    wrap_Unload::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginManager::
    wrap_Unload::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Unload();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPluginBase * wxPluginManager::Getplugin()
//---------------------------------------------------
void WrapClass_wxPluginManager::
    wrap_Getplugin::SetParametersComments()
{
  return_comments="returning a variable of type wxPluginBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginManager::
    wrap_Getplugin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPluginBase * res =   this->_objectptr->GetObj()->Getplugin();
  BasicVariable::ptr res_var = AMILabType<wxPluginBase >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxDynamicLibrary & wxPluginManager::Getdll()
//---------------------------------------------------
void WrapClass_wxPluginManager::
    wrap_Getdll::SetParametersComments()
{
  return_comments="returning a variable of type wxDynamicLibrary";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginManager::
    wrap_Getdll::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDynamicLibrary & res =   this->_objectptr->GetObj()->Getdll();
  return AMILabType<wxDynamicLibrary >::CreateVar(res);
}

