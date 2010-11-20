/**
 * C++ Interface: wrap_vtkObject
 *
 * Description: wrapping vtkObject
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
#include "wrap_vtkObject.h"
#include "wrap_vtkObjectBase.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkIndent.h"
#include "wrap_vtkCommand.h"


#include "wrap_vtkObject.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkObject>::CreateVar( ParamList* p)
{
  WrapClass_vtkObject::wrap_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkObject);
AMI_DEFINE_VARFROMSMTPTR(vtkObject);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkObject>::CreateVar( vtkObject* val)
{ 
  boost::shared_ptr<vtkObject> obj_ptr(val,wxwindow_nodeleter<vtkObject>());
  return AMILabType<vtkObject>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkObject
//
Variable<AMIObject>::ptr WrapClass_vtkObject::CreateVar( vtkObject* sp)
{
  boost::shared_ptr<vtkObject> di_ptr(
    sp,
    wxwindow_nodeleter<vtkObject>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkObject>::CreateVar(
      new WrapClass_vtkObject(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkObject::AddMethods(WrapClass<vtkObject>::ptr this_ptr )
{
  
      // Add members from vtkObjectBase
      WrapClass_vtkObjectBase::ptr parent_vtkObjectBase(        boost::dynamic_pointer_cast<WrapClass_vtkObjectBase >(this_ptr));
      parent_vtkObjectBase->AddMethods(parent_vtkObjectBase);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
      AddVar_DebugOn( this_ptr);
      AddVar_DebugOff( this_ptr);
      AddVar_GetDebug( this_ptr);
      AddVar_SetDebug( this_ptr);
      AddVar_Modified( this_ptr);
      AddVar_GetMTime( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_AddObserver_1( this_ptr);
      AddVar_AddObserver( this_ptr);
      AddVar_AddObserver_2( this_ptr);
      AddVar_GetCommand( this_ptr);
      AddVar_RemoveObserver_1( this_ptr);
      AddVar_RemoveObservers_1( this_ptr);
      AddVar_RemoveObservers( this_ptr);
      AddVar_RemoveObservers_2( this_ptr);
      AddVar_HasObserver_1( this_ptr);
      AddVar_HasObserver( this_ptr);
      AddVar_HasObserver_2( this_ptr);
      AddVar_RemoveObserver( this_ptr);
      AddVar_RemoveObserver_2( this_ptr);
      AddVar_RemoveObservers_3( this_ptr);
      AddVar_RemoveObservers_4( this_ptr);
      AddVar_RemoveAllObservers( this_ptr);
      AddVar_HasObserver_3( this_ptr);
      AddVar_HasObserver_4( this_ptr);
/* The following types are missing: void
      AddVar_InvokeEvent_1( this_ptr);
*/
      AddVar_InvokeEvent( this_ptr);
/* The following types are missing: void
      AddVar_InvokeEvent_2( this_ptr);
*/
      AddVar_InvokeEvent_3( this_ptr);
      AddVar_InvokeEvent_4( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkObject::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkObject::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkObject * vtkObject::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkObject * res =   vtkObject::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkObject * vtkObject::New()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkObject * res =   vtkObject::New();
  BasicVariable::ptr res_var = WrapClass_vtkObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkObject::BreakOnError()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_BreakOnError::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_BreakOnError::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkObject::BreakOnError();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObject::SetGlobalWarningDisplay(int val)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_SetGlobalWarningDisplay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'val'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_SetGlobalWarningDisplay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int val;
  if (!get_val_param<int >(val,_p,_n)) ClassHelpAndReturn;

  vtkObject::SetGlobalWarningDisplay(val);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObject::GlobalWarningDisplayOn()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_GlobalWarningDisplayOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_GlobalWarningDisplayOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkObject::GlobalWarningDisplayOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObject::GlobalWarningDisplayOff()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_GlobalWarningDisplayOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_GlobalWarningDisplayOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkObject::GlobalWarningDisplayOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkObject::GetGlobalWarningDisplay()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_GetGlobalWarningDisplay::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_GetGlobalWarningDisplay::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   vtkObject::GetGlobalWarningDisplay();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkObject::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkObject * vtkObject::NewInstance()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkObject * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkObject::DebugOn()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_DebugOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_DebugOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DebugOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObject::DebugOff()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_DebugOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_DebugOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DebugOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of unsigned char vtkObject::GetDebug()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_GetDebug::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_GetDebug::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->GetDebug();
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkObject::SetDebug(unsigned char debugFlag)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_SetDebug::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'debugFlag'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_SetDebug::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  unsigned char debugFlag;
  if (!get_val_param<unsigned char >(debugFlag,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDebug(debugFlag);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObject::Modified()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_Modified::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_Modified::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Modified();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkObject::GetMTime()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkObject::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of long unsigned int vtkObject::AddObserver(long unsigned int event, vtkCommand * param1, float priority = 0.0f)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_AddObserver_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'event'")
  ADDPARAMCOMMENT_TYPE( vtkCommand, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'priority' (def:0.0f)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_AddObserver_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long event_long;
  if (!get_val_param<long >(event_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int event = boost::numeric_cast<long unsigned int >(event_long);

  boost::shared_ptr<vtkCommand > param1_smtptr;
  if (!get_val_smtptr_param<vtkCommand >(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkCommand* param1 = param1_smtptr.get();

  float priority = 0.0f;
  if (!get_val_param<float >(priority,_p,_n)) ClassReturnEmptyVar;

  long unsigned int res =   this->_objectptr->GetObj()->AddObserver(event, param1, priority);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkObject::AddObserver(...)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_AddObserver::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_AddObserver::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkObject::wrap_AddObserver_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkObject::wrap_AddObserver_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkObject::AddObserver(char const * event, vtkCommand * param1, float priority = 0.0f)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_AddObserver_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'event'")
  ADDPARAMCOMMENT_TYPE( vtkCommand, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'priority' (def:0.0f)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_AddObserver_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > event_string;
  if (!get_val_smtptr_param<std::string >(event_string,_p,_n)) ClassReturnEmptyVar;
  char const * event = event_string->c_str();

  boost::shared_ptr<vtkCommand > param1_smtptr;
  if (!get_val_smtptr_param<vtkCommand >(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkCommand* param1 = param1_smtptr.get();

  float priority = 0.0f;
  if (!get_val_param<float >(priority,_p,_n)) ClassReturnEmptyVar;

  long unsigned int res =   this->_objectptr->GetObj()->AddObserver(event, param1, priority);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkCommand * vtkObject::GetCommand(long unsigned int tag)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_GetCommand::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'tag'")
  return_comments="returning a variable of type vtkCommand";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_GetCommand::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long tag_long;
  if (!get_val_param<long >(tag_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int tag = boost::numeric_cast<long unsigned int >(tag_long);

  vtkCommand * res =   this->_objectptr->GetObj()->GetCommand(tag);
  BasicVariable::ptr res_var = WrapClass_vtkCommand::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkObject::RemoveObserver(vtkCommand * param0)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_RemoveObserver_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCommand, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_RemoveObserver_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkCommand > param0_smtptr;
  if (!get_val_smtptr_param<vtkCommand >(param0_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkCommand* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->RemoveObserver(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObject::RemoveObservers(long unsigned int event, vtkCommand * param1)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_RemoveObservers_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'event'")
  ADDPARAMCOMMENT_TYPE( vtkCommand, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_RemoveObservers_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long event_long;
  if (!get_val_param<long >(event_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int event = boost::numeric_cast<long unsigned int >(event_long);

  boost::shared_ptr<vtkCommand > param1_smtptr;
  if (!get_val_smtptr_param<vtkCommand >(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkCommand* param1 = param1_smtptr.get();

  this->_objectptr->GetObj()->RemoveObservers(event, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkObject::RemoveObservers(...)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_RemoveObservers::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_RemoveObservers::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkObject::wrap_RemoveObservers_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkObject::wrap_RemoveObservers_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkObject::wrap_RemoveObservers_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkObject::wrap_RemoveObservers_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkObject::RemoveObservers(char const * event, vtkCommand * param1)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_RemoveObservers_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'event'")
  ADDPARAMCOMMENT_TYPE( vtkCommand, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_RemoveObservers_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > event_string;
  if (!get_val_smtptr_param<std::string >(event_string,_p,_n)) ClassReturnEmptyVar;
  char const * event = event_string->c_str();

  boost::shared_ptr<vtkCommand > param1_smtptr;
  if (!get_val_smtptr_param<vtkCommand >(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkCommand* param1 = param1_smtptr.get();

  this->_objectptr->GetObj()->RemoveObservers(event, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkObject::HasObserver(long unsigned int event, vtkCommand * param1)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_HasObserver_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'event'")
  ADDPARAMCOMMENT_TYPE( vtkCommand, "parameter named 'param1'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_HasObserver_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long event_long;
  if (!get_val_param<long >(event_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int event = boost::numeric_cast<long unsigned int >(event_long);

  boost::shared_ptr<vtkCommand > param1_smtptr;
  if (!get_val_smtptr_param<vtkCommand >(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkCommand* param1 = param1_smtptr.get();

  int res =   this->_objectptr->GetObj()->HasObserver(event, param1);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkObject::HasObserver(...)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_HasObserver::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_HasObserver::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkObject::wrap_HasObserver_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkObject::wrap_HasObserver_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkObject::wrap_HasObserver_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkObject::wrap_HasObserver_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkObject::HasObserver(char const * event, vtkCommand * param1)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_HasObserver_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'event'")
  ADDPARAMCOMMENT_TYPE( vtkCommand, "parameter named 'param1'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_HasObserver_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > event_string;
  if (!get_val_smtptr_param<std::string >(event_string,_p,_n)) ClassReturnEmptyVar;
  char const * event = event_string->c_str();

  boost::shared_ptr<vtkCommand > param1_smtptr;
  if (!get_val_smtptr_param<vtkCommand >(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkCommand* param1 = param1_smtptr.get();

  int res =   this->_objectptr->GetObj()->HasObserver(event, param1);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkObject::RemoveObserver(...)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_RemoveObserver::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_RemoveObserver::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkObject::wrap_RemoveObserver_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkObject::wrap_RemoveObserver_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkObject::RemoveObserver(long unsigned int tag)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_RemoveObserver_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'tag'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_RemoveObserver_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long tag_long;
  if (!get_val_param<long >(tag_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int tag = boost::numeric_cast<long unsigned int >(tag_long);

  this->_objectptr->GetObj()->RemoveObserver(tag);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObject::RemoveObservers(long unsigned int event)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_RemoveObservers_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_RemoveObservers_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long event_long;
  if (!get_val_param<long >(event_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int event = boost::numeric_cast<long unsigned int >(event_long);

  this->_objectptr->GetObj()->RemoveObservers(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObject::RemoveObservers(char const * event)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_RemoveObservers_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_RemoveObservers_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > event_string;
  if (!get_val_smtptr_param<std::string >(event_string,_p,_n)) ClassReturnEmptyVar;
  char const * event = event_string->c_str();

  this->_objectptr->GetObj()->RemoveObservers(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObject::RemoveAllObservers()
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_RemoveAllObservers::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_RemoveAllObservers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllObservers();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkObject::HasObserver(long unsigned int event)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_HasObserver_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'event'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_HasObserver_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long event_long;
  if (!get_val_param<long >(event_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int event = boost::numeric_cast<long unsigned int >(event_long);

  int res =   this->_objectptr->GetObj()->HasObserver(event);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkObject::HasObserver(char const * event)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_HasObserver_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'event'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_HasObserver_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > event_string;
  if (!get_val_smtptr_param<std::string >(event_string,_p,_n)) ClassReturnEmptyVar;
  char const * event = event_string->c_str();

  int res =   this->_objectptr->GetObj()->HasObserver(event);
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of int vtkObject::InvokeEvent(long unsigned int event, void * callData)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_InvokeEvent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'event'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'callData'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_InvokeEvent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long event_long;
  if (!get_val_param<long >(event_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int event = boost::numeric_cast<long unsigned int >(event_long);

  boost::shared_ptr<void > callData_smtptr;
  if (!get_val_smtptr_param<void >(callData_smtptr,_p,_n)) ClassReturnEmptyVar;
  void* callData = callData_smtptr.get();

  int res =   this->_objectptr->GetObj()->InvokeEvent(event, callData);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkObject::InvokeEvent(...)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_InvokeEvent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_InvokeEvent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkObject::wrap_InvokeEvent_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkObject::wrap_InvokeEvent_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of int vtkObject::InvokeEvent(char const * event, void * callData)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_InvokeEvent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'event'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'callData'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_InvokeEvent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > event_string;
  if (!get_val_smtptr_param<std::string >(event_string,_p,_n)) ClassReturnEmptyVar;
  char const * event = event_string->c_str();

  boost::shared_ptr<void > callData_smtptr;
  if (!get_val_smtptr_param<void >(callData_smtptr,_p,_n)) ClassReturnEmptyVar;
  void* callData = callData_smtptr.get();

  int res =   this->_objectptr->GetObj()->InvokeEvent(event, callData);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkObject::InvokeEvent(long unsigned int event)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_InvokeEvent_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'event'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_InvokeEvent_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long event_long;
  if (!get_val_param<long >(event_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int event = boost::numeric_cast<long unsigned int >(event_long);

  int res =   this->_objectptr->GetObj()->InvokeEvent(event);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkObject::InvokeEvent(char const * event)
//---------------------------------------------------
void WrapClass_vtkObject::
    wrap_InvokeEvent_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'event'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObject::
    wrap_InvokeEvent_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > event_string;
  if (!get_val_smtptr_param<std::string >(event_string,_p,_n)) ClassReturnEmptyVar;
  char const * event = event_string->c_str();

  int res =   this->_objectptr->GetObj()->InvokeEvent(event);
  return AMILabType<int >::CreateVar(res);
}

