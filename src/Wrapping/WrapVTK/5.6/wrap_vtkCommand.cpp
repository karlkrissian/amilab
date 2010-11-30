/**
 * C++ Interface: wrap_vtkCommand
 *
 * Description: wrapping vtkCommand
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkObjectBase.h"


#include "wrap_vtkCommand.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkCommand>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkCommand);
AMI_DEFINE_VARFROMSMTPTR(vtkCommand);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkCommand>::CreateVar( vtkCommand* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkCommand> obj_ptr(val,smartpointer_nodeleter<vtkCommand>());
  return AMILabType<vtkCommand>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkCommand
//
Variable<AMIObject>::ptr WrapClass_vtkCommand::CreateVar( vtkCommand* sp)
{
  boost::shared_ptr<vtkCommand> di_ptr(
    sp,
    wxwindow_nodeleter<vtkCommand>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkCommand>::CreateVar(
      new WrapClass_vtkCommand(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkCommand::AddMethods(WrapClass<vtkCommand>::ptr this_ptr )
{
  
      // Add members from vtkObjectBase
      WrapClass_vtkObjectBase::ptr parent_vtkObjectBase(        boost::dynamic_pointer_cast<WrapClass_vtkObjectBase >(this_ptr));
      parent_vtkObjectBase->AddMethods(parent_vtkObjectBase);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_UnRegister_1( this_ptr);
      AddVar_UnRegister( this_ptr);
      AddVar_UnRegister_2( this_ptr);
      AddVar_SetAbortFlag( this_ptr);
      AddVar_GetAbortFlag( this_ptr);
      AddVar_AbortFlagOn( this_ptr);
      AddVar_AbortFlagOff( this_ptr);
      AddVar_SetPassiveObserver( this_ptr);
      AddVar_GetPassiveObserver( this_ptr);
      AddVar_PassiveObserverOn( this_ptr);
      AddVar_PassiveObserverOff( this_ptr);



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkCommand::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkCommand");
  
  // Static methods 
  WrapClass_vtkCommand::AddVar_GetStringFromEventId(amiobject->GetContext());
  WrapClass_vtkCommand::AddVar_GetEventIdFromString(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of char const * vtkCommand::GetStringFromEventId(long unsigned int event)
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_static_GetStringFromEventId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'event'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_static_GetStringFromEventId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long event_long;
  if (!get_val_param<long >(event_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int event = boost::numeric_cast<long unsigned int >(event_long);

  char const * res =   vtkCommand::GetStringFromEventId(event);
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkCommand::GetEventIdFromString(char const * event)
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_static_GetEventIdFromString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'event'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_static_GetEventIdFromString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > event_string;
  if (!get_val_smtptr_param<std::string >(event_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * event = event_string->c_str();

  long unsigned int res =   vtkCommand::GetEventIdFromString(event);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkCommand::UnRegister()
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_UnRegister_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_UnRegister_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->UnRegister();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCommand::UnRegister(...)
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_UnRegister::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_UnRegister::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCommand::wrap_UnRegister_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCommand::wrap_UnRegister_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCommand::UnRegister(vtkObjectBase * param0)
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_UnRegister_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_UnRegister_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > param0_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkObjectBase* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->UnRegister(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCommand::SetAbortFlag(int f)
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_SetAbortFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_SetAbortFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int f;
  if (!get_val_param<int >(f,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAbortFlag(f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkCommand::GetAbortFlag()
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_GetAbortFlag::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_GetAbortFlag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAbortFlag();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCommand::AbortFlagOn()
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_AbortFlagOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_AbortFlagOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AbortFlagOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCommand::AbortFlagOff()
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_AbortFlagOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_AbortFlagOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AbortFlagOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCommand::SetPassiveObserver(int f)
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_SetPassiveObserver::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'f'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_SetPassiveObserver::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int f;
  if (!get_val_param<int >(f,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPassiveObserver(f);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkCommand::GetPassiveObserver()
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_GetPassiveObserver::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_GetPassiveObserver::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPassiveObserver();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCommand::PassiveObserverOn()
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_PassiveObserverOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_PassiveObserverOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PassiveObserverOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCommand::PassiveObserverOff()
//---------------------------------------------------
void WrapClass_vtkCommand::
    wrap_PassiveObserverOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCommand::
    wrap_PassiveObserverOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PassiveObserverOff();
  return BasicVariable::ptr();
}

