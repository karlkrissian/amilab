/**
 * C++ Interface: wrap_vtkInteractorStyleImage
 *
 * Description: wrapping vtkInteractorStyleImage
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

#include "wrap_vtkInteractorStyleImage.h"

// get all the required includes
// #include "..."
#ifndef vtkInteractorStyleImage_declared
  #define vtkInteractorStyleImage_declared
  AMI_DECLARE_TYPE(vtkInteractorStyleImage)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkInteractorStyleImage>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkInteractorStyleImage);
AMI_DEFINE_VARFROMSMTPTR(vtkInteractorStyleImage);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkInteractorStyleImage>::CreateVar( vtkInteractorStyleImage* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkInteractorStyleImage> obj_ptr(val,smartpointer_nodeleter<vtkInteractorStyleImage>());
  return AMILabType<vtkInteractorStyleImage>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkInteractorStyleImage
//
Variable<AMIObject>::ptr WrapClass_vtkInteractorStyleImage::CreateVar( vtkInteractorStyleImage* sp)
{
  boost::shared_ptr<vtkInteractorStyleImage> di_ptr(
    sp,
    wxwindow_nodeleter<vtkInteractorStyleImage>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkInteractorStyleImage>::CreateVar(
      new WrapClass_vtkInteractorStyleImage(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkInteractorStyleImage::AddMethods(WrapClass<vtkInteractorStyleImage>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_GetWindowLevelStartPosition_1( this_ptr);
  AddVar_GetWindowLevelStartPosition( this_ptr);
  AddVar_GetWindowLevelStartPosition_2( this_ptr);
  AddVar_GetWindowLevelStartPosition_3( this_ptr);
  AddVar_GetWindowLevelCurrentPosition_1( this_ptr);
  AddVar_GetWindowLevelCurrentPosition( this_ptr);
  AddVar_GetWindowLevelCurrentPosition_2( this_ptr);
  AddVar_GetWindowLevelCurrentPosition_3( this_ptr);
  AddVar_OnMouseMove( this_ptr);
  AddVar_OnLeftButtonDown( this_ptr);
  AddVar_OnLeftButtonUp( this_ptr);
  AddVar_OnRightButtonDown( this_ptr);
  AddVar_OnRightButtonUp( this_ptr);
  AddVar_OnChar( this_ptr);
  AddVar_WindowLevel( this_ptr);
  AddVar_Pick( this_ptr);
  AddVar_StartWindowLevel( this_ptr);
  AddVar_EndWindowLevel( this_ptr);
  AddVar_StartPick( this_ptr);
  AddVar_EndPick( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkInteractorStyleTrackballCamera
  boost::shared_ptr<vtkInteractorStyleTrackballCamera > parent_vtkInteractorStyleTrackballCamera(  boost::dynamic_pointer_cast<vtkInteractorStyleTrackballCamera >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkInteractorStyleTrackballCamera = AMILabType<vtkInteractorStyleTrackballCamera >::CreateVarFromSmtPtr(parent_vtkInteractorStyleTrackballCamera);
  context->AddVar("vtkInteractorStyleTrackballCamera",var_vtkInteractorStyleTrackballCamera);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkInteractorStyleTrackballCamera = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkInteractorStyleTrackballCamera);
  context->AddDefault(obj_vtkInteractorStyleTrackballCamera->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkInteractorStyleImage_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkInteractorStyleImage");
  
  // Static methods 
  WrapClass_vtkInteractorStyleImage::AddVar_New(amiobject->GetContext());
  WrapClass_vtkInteractorStyleImage::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkInteractorStyleImage::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkInteractorStyleImage * vtkInteractorStyleImage::New()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyleImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyleImage * res =   vtkInteractorStyleImage::New();
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyleImage >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyleImage::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkInteractorStyleImage::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkInteractorStyleImage * vtkInteractorStyleImage::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkInteractorStyleImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
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

  vtkInteractorStyleImage * res =   vtkInteractorStyleImage::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyleImage >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyleImage::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
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
//  Wrapping of vtkInteractorStyleImage * vtkInteractorStyleImage::NewInstance()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyleImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyleImage * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyleImage >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
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
//  Wrapping of int * vtkInteractorStyleImage::GetWindowLevelStartPosition()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelStartPosition_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelStartPosition_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetWindowLevelStartPosition();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInteractorStyleImage::GetWindowLevelStartPosition(...)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelStartPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelStartPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkInteractorStyleImage::wrap_GetWindowLevelStartPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkInteractorStyleImage::wrap_GetWindowLevelStartPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkInteractorStyleImage::wrap_GetWindowLevelStartPosition_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::GetWindowLevelStartPosition(int & _arg1, int & _arg2)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelStartPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelStartPosition_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetWindowLevelStartPosition(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::GetWindowLevelStartPosition(int * _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelStartPosition_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelStartPosition_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int* _arg;
  if (CheckNullVar(_p,_n))  {
    _arg=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > _arg_smtptr;
    if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    _arg = _arg_smtptr.get();
  }

  this->_objectptr->GetObj()->GetWindowLevelStartPosition(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkInteractorStyleImage::GetWindowLevelCurrentPosition()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelCurrentPosition_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelCurrentPosition_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetWindowLevelCurrentPosition();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkInteractorStyleImage::GetWindowLevelCurrentPosition(...)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelCurrentPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelCurrentPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkInteractorStyleImage::wrap_GetWindowLevelCurrentPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkInteractorStyleImage::wrap_GetWindowLevelCurrentPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkInteractorStyleImage::wrap_GetWindowLevelCurrentPosition_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::GetWindowLevelCurrentPosition(int & _arg1, int & _arg2)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelCurrentPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelCurrentPosition_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetWindowLevelCurrentPosition(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::GetWindowLevelCurrentPosition(int * _arg)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelCurrentPosition_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_GetWindowLevelCurrentPosition_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int* _arg;
  if (CheckNullVar(_p,_n))  {
    _arg=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > _arg_smtptr;
    if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    _arg = _arg_smtptr.get();
  }

  this->_objectptr->GetObj()->GetWindowLevelCurrentPosition(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::OnMouseMove()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_OnMouseMove::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_OnMouseMove::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMouseMove();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::OnLeftButtonDown()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_OnLeftButtonDown::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_OnLeftButtonDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnLeftButtonDown();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::OnLeftButtonUp()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_OnLeftButtonUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_OnLeftButtonUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnLeftButtonUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::OnRightButtonDown()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_OnRightButtonDown::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_OnRightButtonDown::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnRightButtonDown();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::OnRightButtonUp()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_OnRightButtonUp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_OnRightButtonUp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnRightButtonUp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::OnChar()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_OnChar::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_OnChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnChar();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::WindowLevel()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_WindowLevel::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_WindowLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->WindowLevel();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::Pick()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_Pick::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_Pick::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Pick();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::StartWindowLevel()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_StartWindowLevel::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_StartWindowLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartWindowLevel();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::EndWindowLevel()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_EndWindowLevel::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_EndWindowLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndWindowLevel();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::StartPick()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_StartPick::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_StartPick::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartPick();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleImage::EndPick()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleImage::
    wrap_EndPick::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleImage::
    wrap_EndPick::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndPick();
  return BasicVariable::ptr();
}

