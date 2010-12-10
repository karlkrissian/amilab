/**
 * C++ Interface: wrap_vtkInteractorStyleTrackballCamera
 *
 * Description: wrapping vtkInteractorStyleTrackballCamera
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
#include "wrap_vtkInteractorStyleTrackballCamera.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"


#include "wrap_vtkInteractorStyleTrackballCamera.h"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkInteractorStyleTrackballCamera>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkInteractorStyleTrackballCamera);
AMI_DEFINE_VARFROMSMTPTR(vtkInteractorStyleTrackballCamera);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkInteractorStyleTrackballCamera>::CreateVar( vtkInteractorStyleTrackballCamera* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkInteractorStyleTrackballCamera> obj_ptr(val,smartpointer_nodeleter<vtkInteractorStyleTrackballCamera>());
  return AMILabType<vtkInteractorStyleTrackballCamera>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkInteractorStyleTrackballCamera
//
Variable<AMIObject>::ptr WrapClass_vtkInteractorStyleTrackballCamera::CreateVar( vtkInteractorStyleTrackballCamera* sp)
{
  boost::shared_ptr<vtkInteractorStyleTrackballCamera> di_ptr(
    sp,
    wxwindow_nodeleter<vtkInteractorStyleTrackballCamera>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkInteractorStyleTrackballCamera>::CreateVar(
      new WrapClass_vtkInteractorStyleTrackballCamera(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::AddMethods(WrapClass<vtkInteractorStyleTrackballCamera>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_OnMouseMove( this_ptr);
  AddVar_OnLeftButtonDown( this_ptr);
  AddVar_OnLeftButtonUp( this_ptr);
  AddVar_OnMiddleButtonDown( this_ptr);
  AddVar_OnMiddleButtonUp( this_ptr);
  AddVar_OnRightButtonDown( this_ptr);
  AddVar_OnRightButtonUp( this_ptr);
  AddVar_OnMouseWheelForward( this_ptr);
  AddVar_OnMouseWheelBackward( this_ptr);
  AddVar_Rotate( this_ptr);
  AddVar_Spin( this_ptr);
  AddVar_Pan( this_ptr);
  AddVar_Dolly( this_ptr);
  AddVar_SetMotionFactor( this_ptr);
  AddVar_GetMotionFactor( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkInteractorStyle
  boost::shared_ptr<vtkInteractorStyle > parent_vtkInteractorStyle(  boost::dynamic_pointer_cast<vtkInteractorStyle >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkInteractorStyle = AMILabType<vtkInteractorStyle >::CreateVarFromSmtPtr(parent_vtkInteractorStyle);
  context->AddVar("vtkInteractorStyle",var_vtkInteractorStyle);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkInteractorStyle = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkInteractorStyle);
  context->AddDefault(obj_vtkInteractorStyle->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkInteractorStyleTrackballCamera::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkInteractorStyleTrackballCamera");
  
  // Static methods 
  WrapClass_vtkInteractorStyleTrackballCamera::AddVar_New(amiobject->GetContext());
  WrapClass_vtkInteractorStyleTrackballCamera::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkInteractorStyleTrackballCamera::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkInteractorStyleTrackballCamera * vtkInteractorStyleTrackballCamera::New()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyleTrackballCamera";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyleTrackballCamera * res =   vtkInteractorStyleTrackballCamera::New();
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyleTrackballCamera::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyleTrackballCamera::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkInteractorStyleTrackballCamera::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkInteractorStyleTrackballCamera * vtkInteractorStyleTrackballCamera::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkInteractorStyleTrackballCamera";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
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

  vtkInteractorStyleTrackballCamera * res =   vtkInteractorStyleTrackballCamera::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyleTrackballCamera::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyleTrackballCamera::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
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
//  Wrapping of vtkInteractorStyleTrackballCamera * vtkInteractorStyleTrackballCamera::NewInstance()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyleTrackballCamera";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyleTrackballCamera * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkInteractorStyleTrackballCamera::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
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
//  Wrapping of void vtkInteractorStyleTrackballCamera::OnMouseMove()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMouseMove::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMouseMove::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMouseMove();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::OnLeftButtonDown()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnLeftButtonDown::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnLeftButtonDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnLeftButtonDown();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::OnLeftButtonUp()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnLeftButtonUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnLeftButtonUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnLeftButtonUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::OnMiddleButtonDown()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMiddleButtonDown::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMiddleButtonDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMiddleButtonDown();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::OnMiddleButtonUp()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMiddleButtonUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMiddleButtonUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMiddleButtonUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::OnRightButtonDown()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnRightButtonDown::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnRightButtonDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnRightButtonDown();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::OnRightButtonUp()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnRightButtonUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnRightButtonUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnRightButtonUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::OnMouseWheelForward()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMouseWheelForward::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMouseWheelForward::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMouseWheelForward();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::OnMouseWheelBackward()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMouseWheelBackward::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_OnMouseWheelBackward::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMouseWheelBackward();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::Rotate()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_Rotate::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_Rotate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Rotate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::Spin()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_Spin::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_Spin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Spin();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::Pan()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_Pan::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_Pan::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Pan();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::Dolly()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_Dolly::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_Dolly::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Dolly();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackballCamera::SetMotionFactor(double _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_SetMotionFactor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_SetMotionFactor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMotionFactor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkInteractorStyleTrackballCamera::GetMotionFactor()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_GetMotionFactor::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackballCamera::
    wrap_GetMotionFactor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMotionFactor();
  return AMILabType<double >::CreateVar(res);
}

