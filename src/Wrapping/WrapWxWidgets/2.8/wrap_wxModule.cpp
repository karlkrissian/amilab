/**
 * C++ Interface: wrap_wxModule
 *
 * Description: wrapping wxModule
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

#include "wrap_wxModule.h"

// get all the required includes
// #include "..."
#ifndef wxModule_declared
  #define wxModule_declared
  AMI_DECLARE_TYPE(wxModule)
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
BasicVariable::ptr WrapClass<wxModule>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxModule);
AMI_DEFINE_VARFROMSMTPTR(wxModule);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxModule
//
Variable<AMIObject>::ptr WrapClass_wxModule::CreateVar( wxModule* sp)
{
  boost::shared_ptr<wxModule> di_ptr(
    sp,
    wxwindow_nodeleter<wxModule>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxModule>::CreateVar(
      new WrapClass_wxModule(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxModule::AddMethods(WrapClass<wxModule>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Init( this_ptr);
  AddVar_Exit( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

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
void WrapClasswxModule_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxModule");
  
  // Static methods 
  WrapClass_wxModule::AddVar_RegisterModule(amiobject->GetContext());
  WrapClass_wxModule::AddVar_RegisterModules(amiobject->GetContext());
  WrapClass_wxModule::AddVar_InitializeModules(amiobject->GetContext());
  WrapClass_wxModule::AddVar_CleanUpModules(amiobject->GetContext());
  WrapClass_wxModule::AddVar_UnregisterModule(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxModule::RegisterModule(wxModule * module)
//---------------------------------------------------
void WrapClass_wxModule::
    wrap_static_RegisterModule::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxModule, "parameter named 'module'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxModule::
    wrap_static_RegisterModule::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxModule* module;
  if (CheckNullVar(_p,_n))  {
    module=(wxModule*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxModule > module_smtptr;
    if (!get_val_smtptr_param<wxModule >(module_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    module = module_smtptr.get();
  }

  wxModule::RegisterModule(module);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxModule::RegisterModules()
//---------------------------------------------------
void WrapClass_wxModule::
    wrap_static_RegisterModules::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxModule::
    wrap_static_RegisterModules::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxModule::RegisterModules();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxModule::InitializeModules()
//---------------------------------------------------
void WrapClass_wxModule::
    wrap_static_InitializeModules::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxModule::
    wrap_static_InitializeModules::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   wxModule::InitializeModules();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxModule::CleanUpModules()
//---------------------------------------------------
void WrapClass_wxModule::
    wrap_static_CleanUpModules::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxModule::
    wrap_static_CleanUpModules::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxModule::CleanUpModules();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxModule::UnregisterModule(wxModule * module)
//---------------------------------------------------
void WrapClass_wxModule::
    wrap_static_UnregisterModule::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxModule, "parameter named 'module'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxModule::
    wrap_static_UnregisterModule::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxModule* module;
  if (CheckNullVar(_p,_n))  {
    module=(wxModule*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxModule > module_smtptr;
    if (!get_val_smtptr_param<wxModule >(module_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    module = module_smtptr.get();
  }

  wxModule::UnregisterModule(module);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxModule::Init()
//---------------------------------------------------
void WrapClass_wxModule::
    wrap_Init::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxModule::
    wrap_Init::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Init();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxModule::Exit()
//---------------------------------------------------
void WrapClass_wxModule::
    wrap_Exit::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxModule::
    wrap_Exit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Exit();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxModule::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxModule::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxModule::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxModule & wxModule::operator =(wxModule const & param0)
//---------------------------------------------------
void WrapClass_wxModule::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxModule, "parameter named 'param0'")
  return_comments="returning a variable of type wxModule";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxModule::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxModule > param0_smtptr;
  if (!get_val_smtptr_param<wxModule >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxModule const & param0 = *param0_smtptr;

  wxModule & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxModule >::CreateVar(res);
}

