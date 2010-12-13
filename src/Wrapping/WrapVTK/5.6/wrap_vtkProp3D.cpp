/**
 * C++ Interface: wrap_vtkProp3D
 *
 * Description: wrapping vtkProp3D
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

#include "wrap_vtkProp3D.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkProp3D_declared
  #define vtkProp3D_declared
  AMI_DECLARE_TYPE(vtkProp3D)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkProp_declared
  #define vtkProp_declared
  AMI_DECLARE_TYPE(vtkProp)
#endif
#ifndef vtkLinearTransform_declared
  #define vtkLinearTransform_declared
  AMI_DECLARE_TYPE(vtkLinearTransform)
#endif
#ifndef vtkMatrix4x4_declared
  #define vtkMatrix4x4_declared
  AMI_DECLARE_TYPE(vtkMatrix4x4)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkProp3D>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkProp3D);
AMI_DEFINE_VARFROMSMTPTR(vtkProp3D);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkProp3D>::CreateVar( vtkProp3D* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkProp3D> obj_ptr(val,smartpointer_nodeleter<vtkProp3D>());
  return AMILabType<vtkProp3D>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkProp3D
//
Variable<AMIObject>::ptr WrapClass_vtkProp3D::CreateVar( vtkProp3D* sp)
{
  boost::shared_ptr<vtkProp3D> di_ptr(
    sp,
    wxwindow_nodeleter<vtkProp3D>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkProp3D>::CreateVar(
      new WrapClass_vtkProp3D(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkProp3D::AddMethods(WrapClass<vtkProp3D>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_ShallowCopy( this_ptr);
  AddVar_SetPosition_1( this_ptr);
  AddVar_SetPosition( this_ptr);
  AddVar_SetPosition_2( this_ptr);
  AddVar_GetPosition_1( this_ptr);
  AddVar_GetPosition( this_ptr);
  AddVar_GetPosition_2( this_ptr);
  AddVar_AddPosition_1( this_ptr);
  AddVar_AddPosition( this_ptr);
  AddVar_AddPosition_2( this_ptr);
  AddVar_SetOrigin_1( this_ptr);
  AddVar_SetOrigin( this_ptr);
  AddVar_SetOrigin_2( this_ptr);
  AddVar_GetOrigin_1( this_ptr);
  AddVar_GetOrigin( this_ptr);
  AddVar_GetOrigin_2( this_ptr);
  AddVar_SetScale_1( this_ptr);
  AddVar_SetScale( this_ptr);
  AddVar_SetScale_2( this_ptr);
  AddVar_GetScale_1( this_ptr);
  AddVar_GetScale( this_ptr);
  AddVar_GetScale_2( this_ptr);
  AddVar_SetScale_3( this_ptr);
  AddVar_SetUserTransform( this_ptr);
  AddVar_GetUserTransform( this_ptr);
  AddVar_SetUserMatrix( this_ptr);
  AddVar_GetUserMatrix( this_ptr);
  AddVar_GetMatrix_1( this_ptr);
  AddVar_GetMatrix( this_ptr);
  AddVar_GetMatrix_2( this_ptr);
  AddVar_GetBounds( this_ptr);
  AddVar_GetCenter( this_ptr);
  AddVar_GetXRange( this_ptr);
  AddVar_GetYRange( this_ptr);
  AddVar_GetZRange( this_ptr);
  AddVar_GetLength( this_ptr);
  AddVar_RotateX( this_ptr);
  AddVar_RotateY( this_ptr);
  AddVar_RotateZ( this_ptr);
  AddVar_RotateWXYZ( this_ptr);
  AddVar_SetOrientation_1( this_ptr);
  AddVar_SetOrientation( this_ptr);
  AddVar_SetOrientation_2( this_ptr);
  AddVar_GetOrientation_1( this_ptr);
  AddVar_GetOrientation( this_ptr);
  AddVar_GetOrientation_2( this_ptr);
  AddVar_GetOrientationWXYZ( this_ptr);
  AddVar_AddOrientation_1( this_ptr);
  AddVar_AddOrientation( this_ptr);
  AddVar_AddOrientation_2( this_ptr);
  AddVar_PokeMatrix( this_ptr);
  AddVar_InitPathTraversal( this_ptr);
  AddVar_GetMTime( this_ptr);
  AddVar_GetUserTransformMatrixMTime( this_ptr);
  AddVar_ComputeMatrix( this_ptr);
  AddVar_GetMatrix_3( this_ptr);
  AddVar_GetIsIdentity( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent vtkProp
  boost::shared_ptr<vtkProp > parent_vtkProp(  boost::dynamic_pointer_cast<vtkProp >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkProp = AMILabType<vtkProp >::CreateVarFromSmtPtr(parent_vtkProp);
  context->AddVar("vtkProp",var_vtkProp);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkProp = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkProp);
  context->AddDefault(obj_vtkProp->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkProp3D_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkProp3D");
  
  // Static methods 
  WrapClass_vtkProp3D::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkProp3D::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkProp3D::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkProp3D::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkProp3D * vtkProp3D::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkProp3D";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
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

  vtkProp3D * res =   vtkProp3D::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkProp3D >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkProp3D::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
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
//  Wrapping of vtkProp3D * vtkProp3D::NewInstance()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkProp3D";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProp3D * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkProp3D >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkProp3D::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
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
//  Wrapping of void vtkProp3D::ShallowCopy(vtkProp * prop)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'prop'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkProp* prop;
  if (CheckNullVar(_p,_n))  {
    prop=(vtkProp*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkProp > prop_smtptr;
    if (!get_val_smtptr_param<vtkProp >(prop_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    prop = prop_smtptr.get();
  }

  this->_objectptr->GetObj()->ShallowCopy(prop);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetPosition(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg3;
  if (!get_val_param<double >(_arg3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetPosition(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::SetPosition(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_SetPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_SetPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetPosition(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetPosition_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetPosition(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProp3D::GetPosition()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetPosition_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetPosition_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetPosition();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::GetPosition(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_GetPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_GetPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::GetPosition(double * data)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetPosition_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetPosition(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::AddPosition(double * deltaPosition)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_AddPosition_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'deltaPosition'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_AddPosition_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* deltaPosition;
  if (CheckNullVar(_p,_n))  {
    deltaPosition=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > deltaPosition_smtptr;
    if (!get_val_smtptr_param<double >(deltaPosition_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    deltaPosition = deltaPosition_smtptr.get();
  }

  this->_objectptr->GetObj()->AddPosition(deltaPosition);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::AddPosition(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_AddPosition::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_AddPosition::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_AddPosition_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_AddPosition_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::AddPosition(double deltaX, double deltaY, double deltaZ)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_AddPosition_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'deltaX'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'deltaY'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'deltaZ'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_AddPosition_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double deltaX;
  if (!get_val_param<double >(deltaX,_p,_n,true,true)) ClassReturnEmptyVar;

  double deltaY;
  if (!get_val_param<double >(deltaY,_p,_n,true,true)) ClassReturnEmptyVar;

  double deltaZ;
  if (!get_val_param<double >(deltaZ,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddPosition(deltaX, deltaY, deltaZ);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetOrigin(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetOrigin_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetOrigin_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg3;
  if (!get_val_param<double >(_arg3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetOrigin(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::SetOrigin(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetOrigin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetOrigin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_SetOrigin_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_SetOrigin_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetOrigin(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetOrigin_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetOrigin_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetOrigin(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProp3D::GetOrigin()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetOrigin_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetOrigin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetOrigin();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::GetOrigin(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetOrigin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetOrigin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_GetOrigin_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_GetOrigin_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::GetOrigin(double * data)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetOrigin_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetOrigin_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetOrigin(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetScale(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetScale_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetScale_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg3;
  if (!get_val_param<double >(_arg3,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetScale(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::SetScale(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetScale::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetScale::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_SetScale_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_SetScale_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_SetScale_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetScale(double * _arg)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetScale_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetScale_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetScale(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProp3D::GetScale()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetScale_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetScale_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetScale();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::GetScale(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetScale::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetScale::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_GetScale_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_GetScale_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::GetScale(double * data)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetScale_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetScale_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetScale(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetScale(double s)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetScale_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetScale_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double s;
  if (!get_val_param<double >(s,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetScale(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetUserTransform(vtkLinearTransform * transform)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetUserTransform::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkLinearTransform, "parameter named 'transform'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetUserTransform::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkLinearTransform* transform;
  if (CheckNullVar(_p,_n))  {
    transform=(vtkLinearTransform*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkLinearTransform > transform_smtptr;
    if (!get_val_smtptr_param<vtkLinearTransform >(transform_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    transform = transform_smtptr.get();
  }

  this->_objectptr->GetObj()->SetUserTransform(transform);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkLinearTransform * vtkProp3D::GetUserTransform()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetUserTransform::SetParametersComments()
{
  return_comments="returning a variable of type vtkLinearTransform";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetUserTransform::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkLinearTransform * res =   this->_objectptr->GetObj()->GetUserTransform();
  BasicVariable::ptr res_var = AMILabType<vtkLinearTransform >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetUserMatrix(vtkMatrix4x4 * matrix)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetUserMatrix::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'matrix'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetUserMatrix::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkMatrix4x4* matrix;
  if (CheckNullVar(_p,_n))  {
    matrix=(vtkMatrix4x4*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkMatrix4x4 > matrix_smtptr;
    if (!get_val_smtptr_param<vtkMatrix4x4 >(matrix_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    matrix = matrix_smtptr.get();
  }

  this->_objectptr->GetObj()->SetUserMatrix(matrix);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkProp3D::GetUserMatrix()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetUserMatrix::SetParametersComments()
{
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetUserMatrix::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetUserMatrix();
  BasicVariable::ptr res_var = AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::GetMatrix(vtkMatrix4x4 * m)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetMatrix_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'm'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetMatrix_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkMatrix4x4* m;
  if (CheckNullVar(_p,_n))  {
    m=(vtkMatrix4x4*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkMatrix4x4 > m_smtptr;
    if (!get_val_smtptr_param<vtkMatrix4x4 >(m_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    m = m_smtptr.get();
  }

  this->_objectptr->GetObj()->GetMatrix(m);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::GetMatrix(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetMatrix::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetMatrix::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_GetMatrix_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_GetMatrix_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_GetMatrix_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::GetMatrix(double * m)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetMatrix_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'm'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetMatrix_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* m;
  if (CheckNullVar(_p,_n))  {
    m=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > m_smtptr;
    if (!get_val_smtptr_param<double >(m_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    m = m_smtptr.get();
  }

  this->_objectptr->GetObj()->GetMatrix(m);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::GetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetBounds::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double* bounds;
  if (CheckNullVar(_p,_n))  {
    bounds=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > bounds_smtptr;
    if (!get_val_smtptr_param<double >(bounds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    bounds = bounds_smtptr.get();
  }

  this->_objectptr->GetObj()->GetBounds(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProp3D::GetCenter()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetCenter::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetCenter::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetCenter();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkProp3D::GetXRange()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetXRange::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetXRange::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetXRange();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkProp3D::GetYRange()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetYRange::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetYRange::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetYRange();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double * vtkProp3D::GetZRange()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetZRange::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetZRange::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetZRange();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of double vtkProp3D::GetLength()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetLength::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetLength::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetLength();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::RotateX(double param0)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_RotateX::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_RotateX::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotateX(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::RotateY(double param0)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_RotateY::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_RotateY::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotateY(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::RotateZ(double param0)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_RotateZ::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_RotateZ::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotateZ(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::RotateWXYZ(double param0, double param1, double param2, double param3)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_RotateWXYZ::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_RotateWXYZ::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  double param1;
  if (!get_val_param<double >(param1,_p,_n,true,false)) ClassHelpAndReturn;

  double param2;
  if (!get_val_param<double >(param2,_p,_n,true,false)) ClassHelpAndReturn;

  double param3;
  if (!get_val_param<double >(param3,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotateWXYZ(param0, param1, param2, param3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetOrientation(double param0, double param1, double param2)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetOrientation_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetOrientation_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  double param1;
  if (!get_val_param<double >(param1,_p,_n,true,true)) ClassReturnEmptyVar;

  double param2;
  if (!get_val_param<double >(param2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetOrientation(param0, param1, param2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::SetOrientation(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetOrientation::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetOrientation::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_SetOrientation_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_SetOrientation_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::SetOrientation(double * a)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_SetOrientation_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_SetOrientation_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* a;
  if (CheckNullVar(_p,_n))  {
    a=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > a_smtptr;
    if (!get_val_smtptr_param<double >(a_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    a = a_smtptr.get();
  }

  this->_objectptr->GetObj()->SetOrientation(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProp3D::GetOrientation()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetOrientation_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetOrientation_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetOrientation();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::GetOrientation(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetOrientation::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetOrientation::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_GetOrientation_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_GetOrientation_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::GetOrientation(double * o)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetOrientation_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetOrientation_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* o;
  if (CheckNullVar(_p,_n))  {
    o=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > o_smtptr;
    if (!get_val_smtptr_param<double >(o_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    o = o_smtptr.get();
  }

  this->_objectptr->GetObj()->GetOrientation(o);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProp3D::GetOrientationWXYZ()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetOrientationWXYZ::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetOrientationWXYZ::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetOrientationWXYZ();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::AddOrientation(double param0, double param1, double param2)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_AddOrientation_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_AddOrientation_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  double param1;
  if (!get_val_param<double >(param1,_p,_n,true,true)) ClassReturnEmptyVar;

  double param2;
  if (!get_val_param<double >(param2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->AddOrientation(param0, param1, param2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp3D::AddOrientation(...)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_AddOrientation::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_AddOrientation::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp3D::wrap_AddOrientation_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp3D::wrap_AddOrientation_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::AddOrientation(double * a)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_AddOrientation_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_AddOrientation_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* a;
  if (CheckNullVar(_p,_n))  {
    a=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > a_smtptr;
    if (!get_val_smtptr_param<double >(a_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    a = a_smtptr.get();
  }

  this->_objectptr->GetObj()->AddOrientation(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::PokeMatrix(vtkMatrix4x4 * matrix)
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_PokeMatrix::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'matrix'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_PokeMatrix::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkMatrix4x4* matrix;
  if (CheckNullVar(_p,_n))  {
    matrix=(vtkMatrix4x4*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkMatrix4x4 > matrix_smtptr;
    if (!get_val_smtptr_param<vtkMatrix4x4 >(matrix_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    matrix = matrix_smtptr.get();
  }

  this->_objectptr->GetObj()->PokeMatrix(matrix);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::InitPathTraversal()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_InitPathTraversal::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_InitPathTraversal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InitPathTraversal();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkProp3D::GetMTime()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkProp3D::GetUserTransformMatrixMTime()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetUserTransformMatrixMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetUserTransformMatrixMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetUserTransformMatrixMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkProp3D::ComputeMatrix()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_ComputeMatrix::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_ComputeMatrix::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeMatrix();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkProp3D::GetMatrix()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetMatrix_3::SetParametersComments()
{
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetMatrix_3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetMatrix();
  BasicVariable::ptr res_var = AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkProp3D::GetIsIdentity()
//---------------------------------------------------
void WrapClass_vtkProp3D::
    wrap_GetIsIdentity::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp3D::
    wrap_GetIsIdentity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIsIdentity();
  return AMILabType<int >::CreateVar(res);
}

