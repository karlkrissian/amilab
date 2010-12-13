/**
 * C++ Interface: wrap_vtkImageAlgorithm
 *
 * Description: wrapping vtkImageAlgorithm
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

#include "wrap_vtkImageAlgorithm.h"

// get all the required includes
// #include "..."
#ifndef vtkImageAlgorithm_declared
  #define vtkImageAlgorithm_declared
  AMI_DECLARE_TYPE(vtkImageAlgorithm)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkImageData_declared
  #define vtkImageData_declared
  AMI_DECLARE_TYPE(vtkImageData)
#endif
#ifndef vtkDataObject_declared
  #define vtkDataObject_declared
  AMI_DECLARE_TYPE(vtkDataObject)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkImageAlgorithm>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkImageAlgorithm);
AMI_DEFINE_VARFROMSMTPTR(vtkImageAlgorithm);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkImageAlgorithm>::CreateVar( vtkImageAlgorithm* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkImageAlgorithm> obj_ptr(val,smartpointer_nodeleter<vtkImageAlgorithm>());
  return AMILabType<vtkImageAlgorithm>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkImageAlgorithm
//
Variable<AMIObject>::ptr WrapClass_vtkImageAlgorithm::CreateVar( vtkImageAlgorithm* sp)
{
  boost::shared_ptr<vtkImageAlgorithm> di_ptr(
    sp,
    wxwindow_nodeleter<vtkImageAlgorithm>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkImageAlgorithm>::CreateVar(
      new WrapClass_vtkImageAlgorithm(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkImageAlgorithm::AddMethods(WrapClass<vtkImageAlgorithm>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_GetOutput_1( this_ptr);
  AddVar_GetOutput( this_ptr);
  AddVar_GetOutput_2( this_ptr);
  AddVar_SetOutput( this_ptr);
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector
  AddVar_ProcessRequest( this_ptr);
*/
  AddVar_SetInput_1( this_ptr);
  AddVar_SetInput( this_ptr);
  AddVar_SetInput_2( this_ptr);
  AddVar_GetInput_1( this_ptr);
  AddVar_GetInput( this_ptr);
  AddVar_GetInput_2( this_ptr);
  AddVar_GetImageDataInput( this_ptr);
  AddVar_AddInput_1( this_ptr);
  AddVar_AddInput( this_ptr);
  AddVar_AddInput_2( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent vtkAlgorithm
  boost::shared_ptr<vtkAlgorithm > parent_vtkAlgorithm(  boost::dynamic_pointer_cast<vtkAlgorithm >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkAlgorithm = AMILabType<vtkAlgorithm >::CreateVarFromSmtPtr(parent_vtkAlgorithm);
  context->AddVar("vtkAlgorithm",var_vtkAlgorithm);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkAlgorithm = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkAlgorithm);
  context->AddDefault(obj_vtkAlgorithm->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkImageAlgorithm_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkImageAlgorithm");
  
  // Static methods 
  WrapClass_vtkImageAlgorithm::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkImageAlgorithm::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkImageAlgorithm::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkImageAlgorithm::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkImageAlgorithm * vtkImageAlgorithm::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkImageAlgorithm";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkObjectBase* o;
  if (CheckNullVar(_p,_n))  {
    o=(vtkObjectBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObjectBase > o_smtptr;
    if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    o = o_smtptr.get();
  }

  vtkImageAlgorithm * res =   vtkImageAlgorithm::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkImageAlgorithm >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkImageAlgorithm::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkImageAlgorithm * vtkImageAlgorithm::NewInstance()
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkImageAlgorithm";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkImageAlgorithm * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkImageAlgorithm >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkImageAlgorithm::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkImageAlgorithm::GetOutput()
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_GetOutput_1::SetParametersComments()
{
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_GetOutput_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkImageData * res =   this->_objectptr->GetObj()->GetOutput();
  BasicVariable::ptr res_var = AMILabType<vtkImageData >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageAlgorithm::GetOutput(...)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_GetOutput::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_GetOutput::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageAlgorithm::wrap_GetOutput_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageAlgorithm::wrap_GetOutput_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkImageAlgorithm::GetOutput(int param0)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_GetOutput_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_GetOutput_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkImageData * res =   this->_objectptr->GetObj()->GetOutput(param0);
  BasicVariable::ptr res_var = AMILabType<vtkImageData >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkImageAlgorithm::SetOutput(vtkDataObject * d)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_SetOutput::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_SetOutput::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataObject* d;
  if (CheckNullVar(_p,_n))  {
    d=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > d_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(d_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    d = d_smtptr.get();
  }

  this->_objectptr->GetObj()->SetOutput(d);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector

//---------------------------------------------------
//  Wrapping of int vtkImageAlgorithm::ProcessRequest(vtkInformation * param0, vtkInformationVector * * param1, vtkInformationVector * param2)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_ProcessRequest::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'param2'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_ProcessRequest::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  vtkInformation* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > param0_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  vtkInformationVector* local_param1 = NULL;
  vtkInformationVector** param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkInformationVector**)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationVector > param1_smtptr;
    if (!get_val_smtptr_param<vtkInformationVector >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    local_param1 = param1_smtptr.get();
    param1 = &local_param1;
  }

  vtkInformationVector* param2;
  if (CheckNullVar(_p,_n))  {
    param2=(vtkInformationVector*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationVector > param2_smtptr;
    if (!get_val_smtptr_param<vtkInformationVector >(param2_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param2 = param2_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->ProcessRequest(param0, param1, param2);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkImageAlgorithm::SetInput(vtkDataObject * param0)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_SetInput_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_SetInput_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkDataObject* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > param0_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInput(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageAlgorithm::SetInput(...)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_SetInput::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_SetInput::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageAlgorithm::wrap_SetInput_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageAlgorithm::wrap_SetInput_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageAlgorithm::SetInput(int param0, vtkDataObject * param1)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_SetInput_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_SetInput_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkDataObject* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > param1_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(param1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInput(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkImageAlgorithm::GetInput(int port)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_GetInput_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_GetInput_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkDataObject * res =   this->_objectptr->GetObj()->GetInput(port);
  BasicVariable::ptr res_var = AMILabType<vtkDataObject >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageAlgorithm::GetInput(...)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_GetInput::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_GetInput::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageAlgorithm::wrap_GetInput_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageAlgorithm::wrap_GetInput_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkImageAlgorithm::GetInput()
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_GetInput_2::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_GetInput_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkDataObject * res =   this->_objectptr->GetObj()->GetInput();
  BasicVariable::ptr res_var = AMILabType<vtkDataObject >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkImageAlgorithm::GetImageDataInput(int port)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_GetImageDataInput::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'port'")
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_GetImageDataInput::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int port;
  if (!get_val_param<int >(port,_p,_n,true,false)) ClassHelpAndReturn;

  vtkImageData * res =   this->_objectptr->GetObj()->GetImageDataInput(port);
  BasicVariable::ptr res_var = AMILabType<vtkImageData >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkImageAlgorithm::AddInput(vtkDataObject * param0)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_AddInput_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_AddInput_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkDataObject* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > param0_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->AddInput(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageAlgorithm::AddInput(...)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_AddInput::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_AddInput::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageAlgorithm::wrap_AddInput_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageAlgorithm::wrap_AddInput_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageAlgorithm::AddInput(int param0, vtkDataObject * param1)
//---------------------------------------------------
void WrapClass_vtkImageAlgorithm::
    wrap_AddInput_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageAlgorithm::
    wrap_AddInput_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkDataObject* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > param1_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(param1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->AddInput(param0, param1);
  return BasicVariable::ptr();
}

