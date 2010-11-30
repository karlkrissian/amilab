/**
 * C++ Interface: wrap_vtkWindow
 *
 * Description: wrapping vtkWindow
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
#include "wrap_vtkWindow.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"


#include "wrap_vtkWindow.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkWindow>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkWindow);
AMI_DEFINE_VARFROMSMTPTR(vtkWindow);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkWindow>::CreateVar( vtkWindow* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkWindow> obj_ptr(val,smartpointer_nodeleter<vtkWindow>());
  return AMILabType<vtkWindow>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkWindow
//
Variable<AMIObject>::ptr WrapClass_vtkWindow::CreateVar( vtkWindow* sp)
{
  boost::shared_ptr<vtkWindow> di_ptr(
    sp,
    wxwindow_nodeleter<vtkWindow>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkWindow>::CreateVar(
      new WrapClass_vtkWindow(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkWindow::AddMethods(WrapClass<vtkWindow>::ptr this_ptr )
{
  
      // Add members from vtkObject
      WrapClass_vtkObject::ptr parent_vtkObject(        boost::dynamic_pointer_cast<WrapClass_vtkObject >(this_ptr));
      parent_vtkObject->AddMethods(parent_vtkObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_GetPosition( this_ptr);
      AddVar_SetPosition_1( this_ptr);
      AddVar_SetPosition( this_ptr);
      AddVar_SetPosition_2( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_SetSize_1( this_ptr);
      AddVar_SetSize( this_ptr);
      AddVar_SetSize_2( this_ptr);
      AddVar_GetActualSize( this_ptr);
      AddVar_SetMapped( this_ptr);
      AddVar_GetMapped( this_ptr);
      AddVar_MappedOn( this_ptr);
      AddVar_MappedOff( this_ptr);
      AddVar_SetErase( this_ptr);
      AddVar_GetErase( this_ptr);
      AddVar_EraseOn( this_ptr);
      AddVar_EraseOff( this_ptr);
      AddVar_SetDoubleBuffer( this_ptr);
      AddVar_GetDoubleBuffer( this_ptr);
      AddVar_DoubleBufferOn( this_ptr);
      AddVar_DoubleBufferOff( this_ptr);
      AddVar_GetWindowName( this_ptr);
      AddVar_SetWindowName( this_ptr);
      AddVar_GetDPI( this_ptr);
      AddVar_SetDPI( this_ptr);
      AddVar_GetDPIMinValue( this_ptr);
      AddVar_GetDPIMaxValue( this_ptr);
      AddVar_SetOffScreenRendering( this_ptr);
      AddVar_GetOffScreenRendering( this_ptr);
      AddVar_OffScreenRenderingOn( this_ptr);
      AddVar_OffScreenRenderingOff( this_ptr);
      AddVar_MakeCurrent( this_ptr);
      AddVar_SetTileScale_1( this_ptr);
      AddVar_SetTileScale( this_ptr);
      AddVar_SetTileScale_2( this_ptr);
      AddVar_GetTileScale_1( this_ptr);
      AddVar_GetTileScale( this_ptr);
      AddVar_GetTileScale_2( this_ptr);
      AddVar_GetTileScale_3( this_ptr);
      AddVar_SetTileScale_3( this_ptr);
      AddVar_SetTileViewport_1( this_ptr);
      AddVar_SetTileViewport( this_ptr);
      AddVar_SetTileViewport_2( this_ptr);
      AddVar_GetTileViewport_1( this_ptr);
      AddVar_GetTileViewport( this_ptr);
      AddVar_GetTileViewport_2( this_ptr);
      AddVar_GetTileViewport_3( this_ptr);



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkWindow::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkWindow");
  
  // Static methods 
  WrapClass_vtkWindow::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkWindow::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkWindow::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkWindow::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkWindow * vtkWindow::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkWindow * res =   vtkWindow::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkWindow::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
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
//  Wrapping of vtkWindow * vtkWindow::NewInstance()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkWindow * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkWindow::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkWindow::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
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
//  Wrapping of int * vtkWindow::GetPosition()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetPosition::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int * res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetPosition(int param0, int param1)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  int param1;
  if (!get_val_param<int >(param1,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetPosition(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkWindow::SetPosition(...)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkWindow::wrap_SetPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkWindow::wrap_SetPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetPosition(int * a)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > a_smtptr;
  if (!get_val_smtptr_param<int >(a_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* a = a_smtptr.get();

  this->_objectptr->GetObj()->SetPosition(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkWindow::GetSize()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int * res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetSize(int param0, int param1)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetSize_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetSize_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  int param1;
  if (!get_val_param<int >(param1,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetSize(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkWindow::SetSize(...)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetSize::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetSize::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkWindow::wrap_SetSize_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkWindow::wrap_SetSize_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetSize(int * a)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetSize_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetSize_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > a_smtptr;
  if (!get_val_smtptr_param<int >(a_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* a = a_smtptr.get();

  this->_objectptr->GetObj()->SetSize(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkWindow::GetActualSize()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetActualSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetActualSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int * res =   this->_objectptr->GetObj()->GetActualSize();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetMapped(int _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetMapped::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetMapped::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMapped(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindow::GetMapped()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetMapped::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetMapped::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMapped();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::MappedOn()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_MappedOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_MappedOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MappedOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::MappedOff()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_MappedOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_MappedOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MappedOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetErase(int _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetErase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetErase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetErase(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindow::GetErase()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetErase::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetErase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetErase();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::EraseOn()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_EraseOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_EraseOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EraseOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::EraseOff()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_EraseOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_EraseOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EraseOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetDoubleBuffer(int _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetDoubleBuffer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetDoubleBuffer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDoubleBuffer(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindow::GetDoubleBuffer()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetDoubleBuffer::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetDoubleBuffer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDoubleBuffer();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::DoubleBufferOn()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_DoubleBufferOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_DoubleBufferOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoubleBufferOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::DoubleBufferOff()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_DoubleBufferOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_DoubleBufferOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoubleBufferOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char * vtkWindow::GetWindowName()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetWindowName::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetWindowName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char * res =   this->_objectptr->GetObj()->GetWindowName();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetWindowName(char const * _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetWindowName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetWindowName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > _arg_string;
  if (!get_val_smtptr_param<std::string >(_arg_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * _arg = _arg_string->c_str();

  this->_objectptr->GetObj()->SetWindowName(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindow::GetDPI()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetDPI::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetDPI::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDPI();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetDPI(int _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetDPI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetDPI::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDPI(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindow::GetDPIMinValue()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetDPIMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetDPIMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDPIMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkWindow::GetDPIMaxValue()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetDPIMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetDPIMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDPIMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetOffScreenRendering(int _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetOffScreenRendering::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetOffScreenRendering::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetOffScreenRendering(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkWindow::GetOffScreenRendering()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetOffScreenRendering::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetOffScreenRendering::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetOffScreenRendering();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::OffScreenRenderingOn()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_OffScreenRenderingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_OffScreenRenderingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OffScreenRenderingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::OffScreenRenderingOff()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_OffScreenRenderingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_OffScreenRenderingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OffScreenRenderingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::MakeCurrent()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_MakeCurrent::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_MakeCurrent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MakeCurrent();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetTileScale(int _arg1, int _arg2)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetTileScale_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetTileScale_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int _arg1;
  if (!get_val_param<int >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  int _arg2;
  if (!get_val_param<int >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetTileScale(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkWindow::SetTileScale(...)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetTileScale::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetTileScale::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkWindow::wrap_SetTileScale_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkWindow::wrap_SetTileScale_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkWindow::wrap_SetTileScale_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetTileScale(int * _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetTileScale_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetTileScale_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetTileScale(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkWindow::GetTileScale()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetTileScale_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetTileScale_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetTileScale();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkWindow::GetTileScale(...)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetTileScale::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetTileScale::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkWindow::wrap_GetTileScale_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkWindow::wrap_GetTileScale_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkWindow::wrap_GetTileScale_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::GetTileScale(int & _arg1, int & _arg2)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetTileScale_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetTileScale_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg1_smtptr;
  if (!get_val_smtptr_param<int >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<int > _arg2_smtptr;
  if (!get_val_smtptr_param<int >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & _arg2 = *_arg2_smtptr;

  this->_objectptr->GetObj()->GetTileScale(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::GetTileScale(int * _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetTileScale_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetTileScale_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetTileScale(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetTileScale(int s)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetTileScale_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetTileScale_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int s;
  if (!get_val_param<int >(s,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetTileScale(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetTileViewport(double _arg1, double _arg2, double _arg3, double _arg4)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetTileViewport_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg4'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetTileViewport_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetTileViewport(_arg1, _arg2, _arg3, _arg4);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkWindow::SetTileViewport(...)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetTileViewport::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetTileViewport::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkWindow::wrap_SetTileViewport_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkWindow::wrap_SetTileViewport_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::SetTileViewport(double * _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_SetTileViewport_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_SetTileViewport_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetTileViewport(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkWindow::GetTileViewport()
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetTileViewport_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetTileViewport_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetTileViewport();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkWindow::GetTileViewport(...)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetTileViewport::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetTileViewport::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkWindow::wrap_GetTileViewport_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkWindow::wrap_GetTileViewport_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkWindow::wrap_GetTileViewport_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::GetTileViewport(double & _arg1, double & _arg2, double & _arg3, double & _arg4)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetTileViewport_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg4'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetTileViewport_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  boost::shared_ptr<double > _arg4_smtptr;
  if (!get_val_smtptr_param<double >(_arg4_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg4 = *_arg4_smtptr;

  this->_objectptr->GetObj()->GetTileViewport(_arg1, _arg2, _arg3, _arg4);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkWindow::GetTileViewport(double * _arg)
//---------------------------------------------------
void WrapClass_vtkWindow::
    wrap_GetTileViewport_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkWindow::
    wrap_GetTileViewport_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetTileViewport(_arg);
  return BasicVariable::ptr();
}

