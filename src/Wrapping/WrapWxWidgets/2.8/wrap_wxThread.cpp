/**
 * C++ Interface: wrap_wxThread
 *
 * Description: wrapping wxThread
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

#include "wrap_wxThread.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxThread_declared
  #define wxThread_declared
  AMI_DECLARE_TYPE(wxThread)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxThread>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxThread);
AMI_DEFINE_VARFROMSMTPTR(wxThread);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxThread>::CreateVar( wxThread* val, bool nodeleter)
{ 
  boost::shared_ptr<wxThread> obj_ptr(val,smartpointer_nodeleter<wxThread>());
  return AMILabType<wxThread>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxThread
//
Variable<AMIObject>::ptr WrapClass_wxThread::CreateVar( wxThread* sp)
{
  boost::shared_ptr<wxThread> di_ptr(
    sp,
    wxwindow_nodeleter<wxThread>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxThread>::CreateVar(
      new WrapClass_wxThread(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxThread::AddMethods(WrapClass<wxThread>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Create( this_ptr);
  AddVar_Run( this_ptr);
/* The following types are missing: void
  AddVar_Delete( this_ptr);
*/
  AddVar_Wait( this_ptr);
  AddVar_Kill( this_ptr);
  AddVar_Pause( this_ptr);
  AddVar_Resume( this_ptr);
  AddVar_SetPriority( this_ptr);
  AddVar_GetPriority( this_ptr);
  AddVar_IsAlive( this_ptr);
  AddVar_IsRunning( this_ptr);
  AddVar_IsPaused( this_ptr);
  AddVar_IsDetached( this_ptr);
  AddVar_GetId( this_ptr);
  AddVar_OnExit( this_ptr);
  AddVar_TestDestroy( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxThread_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxThread");
  
  // Static methods 
  WrapClass_wxThread::AddVar_This(amiobject->GetContext());
  WrapClass_wxThread::AddVar_IsMain(amiobject->GetContext());
  WrapClass_wxThread::AddVar_Yield(amiobject->GetContext());
  WrapClass_wxThread::AddVar_Sleep(amiobject->GetContext());
  WrapClass_wxThread::AddVar_GetCPUCount(amiobject->GetContext());
  WrapClass_wxThread::AddVar_GetCurrentId(amiobject->GetContext());
  WrapClass_wxThread::AddVar_SetConcurrency(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxThread * wxThread::This()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_static_This::SetParametersComments()
{
  return_comments="returning a variable of type wxThread";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_static_This::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxThread * res =   wxThread::This();
  BasicVariable::ptr res_var = AMILabType<wxThread >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxThread::IsMain()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_static_IsMain::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_static_IsMain::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   wxThread::IsMain();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxThread::Yield()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_static_Yield::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_static_Yield::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxThread::Yield();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxThread::Sleep(long unsigned int milliseconds)
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_static_Sleep::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'milliseconds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_static_Sleep::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long milliseconds_long;
  if (!get_val_param<long >(milliseconds_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int milliseconds = boost::numeric_cast<long unsigned int >(milliseconds_long);

  wxThread::Sleep(milliseconds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxThread::GetCPUCount()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_static_GetCPUCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_static_GetCPUCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   wxThread::GetCPUCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxThreadIdType wxThread::GetCurrentId()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_static_GetCurrentId::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_static_GetCurrentId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxThreadIdType res =   wxThread::GetCurrentId();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxThread::SetConcurrency(size_t level)
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_static_SetConcurrency::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'level'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_static_SetConcurrency::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long level_long;
  if (!get_val_param<long >(level_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int level = boost::numeric_cast<long unsigned int >(level_long);

  bool res =   wxThread::SetConcurrency(level);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxThreadError wxThread::Create(unsigned int stackSize = 0)
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'stackSize' (def:0)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long stackSize_long = boost::numeric_cast<long >((unsigned int)0);;
  if (!get_val_param<long >(stackSize_long,_p,_n,false,false)) ClassHelpAndReturn;
  unsigned int stackSize = boost::numeric_cast<unsigned int >(stackSize_long);

  wxThreadError res =   this->_objectptr->GetObj()->Create(stackSize);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxThreadError wxThread::Run()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_Run::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_Run::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxThreadError res =   this->_objectptr->GetObj()->Run();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxThreadError wxThread::Delete(void * * rc = 0u)
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_Delete::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'rc' (def:0u)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_Delete::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  void* local_rc = NULL;
  void** rc = 0u;
  if (CheckNullVar(_p,_n))  {
    rc=(void**)NULL;
    _n++;
  } else {
    boost::shared_ptr<void > rc_smtptr;
    if (!get_val_smtptr_param<void >(rc_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    local_rc = rc_smtptr.get();
    rc = &local_rc;
  }

  wxThreadError res =   this->_objectptr->GetObj()->Delete(rc);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of void * wxThread::Wait()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_Wait::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_Wait::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Wait();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxThreadError wxThread::Kill()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_Kill::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_Kill::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxThreadError res =   this->_objectptr->GetObj()->Kill();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxThreadError wxThread::Pause()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_Pause::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_Pause::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxThreadError res =   this->_objectptr->GetObj()->Pause();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxThreadError wxThread::Resume()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_Resume::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_Resume::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxThreadError res =   this->_objectptr->GetObj()->Resume();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxThread::SetPriority(unsigned int prio)
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_SetPriority::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'prio'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_SetPriority::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long prio_long;
  if (!get_val_param<long >(prio_long,_p,_n,true,false)) ClassHelpAndReturn;
  unsigned int prio = boost::numeric_cast<unsigned int >(prio_long);

  this->_objectptr->GetObj()->SetPriority(prio);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of unsigned int wxThread::GetPriority()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_GetPriority::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_GetPriority::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned int res =   this->_objectptr->GetObj()->GetPriority();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxThread::IsAlive()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_IsAlive::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_IsAlive::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsAlive();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxThread::IsRunning()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_IsRunning::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_IsRunning::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsRunning();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxThread::IsPaused()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_IsPaused::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_IsPaused::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsPaused();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxThread::IsDetached()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_IsDetached::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_IsDetached::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDetached();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxThreadIdType wxThread::GetId()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_GetId::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_GetId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxThreadIdType res =   this->_objectptr->GetObj()->GetId();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxThread::OnExit()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_OnExit::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_OnExit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnExit();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxThread::TestDestroy()
//---------------------------------------------------
void WrapClass_wxThread::
    wrap_TestDestroy::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxThread::
    wrap_TestDestroy::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->TestDestroy();
  return AMILabType<bool >::CreateVar(res);
}

