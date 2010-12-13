/**
 * C++ Interface: wrap_vtkWindowToImageFilter
 *
 * Description: wrapping vtkWindowToImageFilter
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

#include "wrap_vtkWindowToImageFilter.h"

// get all the required includes
// #include "..."
#ifndef vtkWindowToImageFilter_declared
  #define vtkWindowToImageFilter_declared
  AMI_DECLARE_TYPE(vtkWindowToImageFilter)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkWindow_declared
  #define vtkWindow_declared
  AMI_DECLARE_TYPE(vtkWindow)
#endif
#ifndef vtkImageData_declared
  #define vtkImageData_declared
  AMI_DECLARE_TYPE(vtkImageData)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkWindowToImageFilter>::CreateVar( ParamList* p)
{
  WrapClass_vtkWindowToImageFilter::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkWindowToImageFilter);
AMI_DEFINE_VARFROMSMTPTR(vtkWindowToImageFilter);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkWindowToImageFilter>::CreateVar( vtkWindowToImageFilter* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkWindowToImageFilter> obj_ptr(val,smartpointer_nodeleter<vtkWindowToImageFilter>());
  return AMILabType<vtkWindowToImageFilter>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkWindowToImageFilter
//
Variable<AMIObject>::ptr WrapClass_vtkWindowToImageFilter::CreateVar( vtkWindowToImageFilter* sp)
{
  boost::shared_ptr<vtkWindowToImageFilter> di_ptr(
    sp,
    wxwindow_nodeleter<vtkWindowToImageFilter>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkWindowToImageFilter>::CreateVar(
      new WrapClass_vtkWindowToImageFilter(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkWindowToImageFilter::AddMethods(WrapClass<vtkWindowToImageFilter>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_SetInput( this_ptr);
  AddVar_GetInput( this_ptr);
  AddVar_SetMagnification( this_ptr);
  AddVar_GetMagnificationMinValue( this_ptr);
  AddVar_GetMagnificationMaxValue( this_ptr);
  AddVar_GetMagnification( this_ptr);
  AddVar_ReadFrontBufferOn( this_ptr);
  AddVar_ReadFrontBufferOff( this_ptr);
  AddVar_GetReadFrontBuffer( this_ptr);
  AddVar_SetReadFrontBuffer( this_ptr);
  AddVar_ShouldRerenderOn( this_ptr);
  AddVar_ShouldRerenderOff( this_ptr);
  AddVar_SetShouldRerender( this_ptr);
  AddVar_GetShouldRerender( this_ptr);
  AddVar_SetViewport_1( this_ptr);
  AddVar_SetViewport( this_ptr);
  AddVar_SetViewport_2( this_ptr);
  AddVar_GetViewport_1( this_ptr);
  AddVar_GetViewport( this_ptr);
  AddVar_GetViewport_2( this_ptr);
  AddVar_SetInputBufferType( this_ptr);
  AddVar_GetInputBufferType( this_ptr);
  AddVar_SetInputBufferTypeToRGB( this_ptr);
  AddVar_SetInputBufferTypeToRGBA( this_ptr);
  AddVar_SetInputBufferTypeToZBuffer( this_ptr);
  AddVar_GetOutput( this_ptr);
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector
  AddVar_ProcessRequest( this_ptr);
*/



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
void WrapClassvtkWindowToImageFilter_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkWindowToImageFilter");
  
  // Static methods 
  WrapClass_vtkWindowToImageFilter::AddVar_New(amiobject->GetContext());
  WrapClass_vtkWindowToImageFilter::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkWindowToImageFilter::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkWindowToImageFilter * vtkWindowToImageFilter::New()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkWindowToImageFilter";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkWindowToImageFilter * res =   vtkWindowToImageFilter::New();
  BasicVariable::ptr res_var = AMILabType<vtkWindowToImageFilter >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkWindowToImageFilter::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkWindowToImageFilter::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkWindowToImageFilter * vtkWindowToImageFilter::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkWindowToImageFilter";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
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

  vtkWindowToImageFilter * res =   vtkWindowToImageFilter::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkWindowToImageFilter >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkWindowToImageFilter::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
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
//  Wrapping of vtkWindowToImageFilter * vtkWindowToImageFilter::NewInstance()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkWindowToImageFilter";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkWindowToImageFilter * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkWindowToImageFilter >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
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
//  Wrapping of void vtkWindowToImageFilter::SetInput(vtkWindow * input)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetInput::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'input'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetInput::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkWindow* input;
  if (CheckNullVar(_p,_n))  {
    input=(vtkWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkWindow > input_smtptr;
    if (!get_val_smtptr_param<vtkWindow >(input_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    input = input_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInput(input);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkWindow * vtkWindowToImageFilter::GetInput()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkWindow * res =   this->_objectptr->GetObj()->GetInput();
  BasicVariable::ptr res_var = AMILabType<vtkWindow >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::SetMagnification(int _arg)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetMagnification::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetMagnification::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMagnification(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindowToImageFilter::GetMagnificationMinValue()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetMagnificationMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetMagnificationMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMagnificationMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkWindowToImageFilter::GetMagnificationMaxValue()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetMagnificationMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetMagnificationMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMagnificationMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkWindowToImageFilter::GetMagnification()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetMagnification::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetMagnification::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMagnification();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::ReadFrontBufferOn()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_ReadFrontBufferOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_ReadFrontBufferOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReadFrontBufferOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::ReadFrontBufferOff()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_ReadFrontBufferOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_ReadFrontBufferOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReadFrontBufferOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindowToImageFilter::GetReadFrontBuffer()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetReadFrontBuffer::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetReadFrontBuffer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetReadFrontBuffer();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::SetReadFrontBuffer(int _arg)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetReadFrontBuffer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetReadFrontBuffer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetReadFrontBuffer(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::ShouldRerenderOn()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_ShouldRerenderOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_ShouldRerenderOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ShouldRerenderOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::ShouldRerenderOff()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_ShouldRerenderOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_ShouldRerenderOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ShouldRerenderOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::SetShouldRerender(int _arg)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetShouldRerender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetShouldRerender::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetShouldRerender(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindowToImageFilter::GetShouldRerender()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetShouldRerender::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetShouldRerender::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetShouldRerender();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::SetViewport(double _arg1, double _arg2, double _arg3, double _arg4)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetViewport_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg4'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetViewport_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg3;
  if (!get_val_param<double >(_arg3,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg4;
  if (!get_val_param<double >(_arg4,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetViewport(_arg1, _arg2, _arg3, _arg4);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkWindowToImageFilter::SetViewport(...)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetViewport::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetViewport::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkWindowToImageFilter::wrap_SetViewport_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkWindowToImageFilter::wrap_SetViewport_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::SetViewport(double * _arg)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetViewport_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetViewport_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* _arg;
  if (CheckNullVar(_p,_n))  {
    _arg=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > _arg_smtptr;
    if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    _arg = _arg_smtptr.get();
  }

  this->_objectptr->GetObj()->SetViewport(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkWindowToImageFilter::GetViewport()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetViewport_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetViewport_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetViewport();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkWindowToImageFilter::GetViewport(...)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetViewport::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetViewport::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkWindowToImageFilter::wrap_GetViewport_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkWindowToImageFilter::wrap_GetViewport_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::GetViewport(double * data)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetViewport_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetViewport_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* data;
  if (CheckNullVar(_p,_n))  {
    data=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > data_smtptr;
    if (!get_val_smtptr_param<double >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->GetViewport(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::SetInputBufferType(int _arg)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetInputBufferType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetInputBufferType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInputBufferType(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindowToImageFilter::GetInputBufferType()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetInputBufferType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetInputBufferType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInputBufferType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::SetInputBufferTypeToRGB()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetInputBufferTypeToRGB::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetInputBufferTypeToRGB::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInputBufferTypeToRGB();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::SetInputBufferTypeToRGBA()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetInputBufferTypeToRGBA::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetInputBufferTypeToRGBA::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInputBufferTypeToRGBA();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindowToImageFilter::SetInputBufferTypeToZBuffer()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_SetInputBufferTypeToZBuffer::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_SetInputBufferTypeToZBuffer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInputBufferTypeToZBuffer();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkWindowToImageFilter::GetOutput()
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_GetOutput::SetParametersComments()
{
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
    wrap_GetOutput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkImageData * res =   this->_objectptr->GetObj()->GetOutput();
  BasicVariable::ptr res_var = AMILabType<vtkImageData >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector

//---------------------------------------------------
//  Wrapping of int vtkWindowToImageFilter::ProcessRequest(vtkInformation * param0, vtkInformationVector * * param1, vtkInformationVector * param2)
//---------------------------------------------------
void WrapClass_vtkWindowToImageFilter::
    wrap_ProcessRequest::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'param2'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindowToImageFilter::
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

