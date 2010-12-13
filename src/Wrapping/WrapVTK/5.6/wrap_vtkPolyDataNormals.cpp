/**
 * C++ Interface: wrap_vtkPolyDataNormals
 *
 * Description: wrapping vtkPolyDataNormals
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

#include "wrap_vtkPolyDataNormals.h"

// get all the required includes
// #include "..."
#ifndef vtkPolyDataNormals_declared
  #define vtkPolyDataNormals_declared
  AMI_DECLARE_TYPE(vtkPolyDataNormals)
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
BasicVariable::ptr WrapClass<vtkPolyDataNormals>::CreateVar( ParamList* p)
{
  WrapClass_vtkPolyDataNormals::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkPolyDataNormals);
AMI_DEFINE_VARFROMSMTPTR(vtkPolyDataNormals);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkPolyDataNormals>::CreateVar( vtkPolyDataNormals* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkPolyDataNormals> obj_ptr(val,smartpointer_nodeleter<vtkPolyDataNormals>());
  return AMILabType<vtkPolyDataNormals>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkPolyDataNormals
//
Variable<AMIObject>::ptr WrapClass_vtkPolyDataNormals::CreateVar( vtkPolyDataNormals* sp)
{
  boost::shared_ptr<vtkPolyDataNormals> di_ptr(
    sp,
    wxwindow_nodeleter<vtkPolyDataNormals>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkPolyDataNormals>::CreateVar(
      new WrapClass_vtkPolyDataNormals(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkPolyDataNormals::AddMethods(WrapClass<vtkPolyDataNormals>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_SetFeatureAngle( this_ptr);
  AddVar_GetFeatureAngleMinValue( this_ptr);
  AddVar_GetFeatureAngleMaxValue( this_ptr);
  AddVar_GetFeatureAngle( this_ptr);
  AddVar_SetSplitting( this_ptr);
  AddVar_GetSplitting( this_ptr);
  AddVar_SplittingOn( this_ptr);
  AddVar_SplittingOff( this_ptr);
  AddVar_SetConsistency( this_ptr);
  AddVar_GetConsistency( this_ptr);
  AddVar_ConsistencyOn( this_ptr);
  AddVar_ConsistencyOff( this_ptr);
  AddVar_SetAutoOrientNormals( this_ptr);
  AddVar_GetAutoOrientNormals( this_ptr);
  AddVar_AutoOrientNormalsOn( this_ptr);
  AddVar_AutoOrientNormalsOff( this_ptr);
  AddVar_SetComputePointNormals( this_ptr);
  AddVar_GetComputePointNormals( this_ptr);
  AddVar_ComputePointNormalsOn( this_ptr);
  AddVar_ComputePointNormalsOff( this_ptr);
  AddVar_SetComputeCellNormals( this_ptr);
  AddVar_GetComputeCellNormals( this_ptr);
  AddVar_ComputeCellNormalsOn( this_ptr);
  AddVar_ComputeCellNormalsOff( this_ptr);
  AddVar_SetFlipNormals( this_ptr);
  AddVar_GetFlipNormals( this_ptr);
  AddVar_FlipNormalsOn( this_ptr);
  AddVar_FlipNormalsOff( this_ptr);
  AddVar_SetNonManifoldTraversal( this_ptr);
  AddVar_GetNonManifoldTraversal( this_ptr);
  AddVar_NonManifoldTraversalOn( this_ptr);
  AddVar_NonManifoldTraversalOff( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent vtkPolyDataAlgorithm
  boost::shared_ptr<vtkPolyDataAlgorithm > parent_vtkPolyDataAlgorithm(  boost::dynamic_pointer_cast<vtkPolyDataAlgorithm >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkPolyDataAlgorithm = AMILabType<vtkPolyDataAlgorithm >::CreateVarFromSmtPtr(parent_vtkPolyDataAlgorithm);
  context->AddVar("vtkPolyDataAlgorithm",var_vtkPolyDataAlgorithm);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkPolyDataAlgorithm = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkPolyDataAlgorithm);
  context->AddDefault(obj_vtkPolyDataAlgorithm->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkPolyDataNormals_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkPolyDataNormals");
  
  // Static methods 
  WrapClass_vtkPolyDataNormals::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkPolyDataNormals::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkPolyDataNormals::AddVar_New(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkPolyDataNormals::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkPolyDataNormals::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPolyDataNormals * vtkPolyDataNormals::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkPolyDataNormals";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
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

  vtkPolyDataNormals * res =   vtkPolyDataNormals::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkPolyDataNormals >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkPolyDataNormals * vtkPolyDataNormals::New()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkPolyDataNormals";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPolyDataNormals * res =   vtkPolyDataNormals::New();
  BasicVariable::ptr res_var = AMILabType<vtkPolyDataNormals >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataNormals::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
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
//  Wrapping of vtkPolyDataNormals * vtkPolyDataNormals::NewInstance()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkPolyDataNormals";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPolyDataNormals * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkPolyDataNormals >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
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
//  Wrapping of void vtkPolyDataNormals::SetFeatureAngle(double _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SetFeatureAngle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SetFeatureAngle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFeatureAngle(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkPolyDataNormals::GetFeatureAngleMinValue()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetFeatureAngleMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetFeatureAngleMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetFeatureAngleMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkPolyDataNormals::GetFeatureAngleMaxValue()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetFeatureAngleMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetFeatureAngleMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetFeatureAngleMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkPolyDataNormals::GetFeatureAngle()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetFeatureAngle::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetFeatureAngle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetFeatureAngle();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::SetSplitting(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SetSplitting::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SetSplitting::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetSplitting(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataNormals::GetSplitting()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetSplitting::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetSplitting::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetSplitting();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::SplittingOn()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SplittingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SplittingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SplittingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::SplittingOff()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SplittingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SplittingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SplittingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::SetConsistency(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SetConsistency::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SetConsistency::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetConsistency(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataNormals::GetConsistency()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetConsistency::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetConsistency::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetConsistency();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::ConsistencyOn()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_ConsistencyOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_ConsistencyOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ConsistencyOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::ConsistencyOff()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_ConsistencyOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_ConsistencyOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ConsistencyOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::SetAutoOrientNormals(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SetAutoOrientNormals::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SetAutoOrientNormals::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAutoOrientNormals(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataNormals::GetAutoOrientNormals()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetAutoOrientNormals::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetAutoOrientNormals::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAutoOrientNormals();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::AutoOrientNormalsOn()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_AutoOrientNormalsOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_AutoOrientNormalsOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutoOrientNormalsOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::AutoOrientNormalsOff()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_AutoOrientNormalsOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_AutoOrientNormalsOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AutoOrientNormalsOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::SetComputePointNormals(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SetComputePointNormals::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SetComputePointNormals::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetComputePointNormals(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataNormals::GetComputePointNormals()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetComputePointNormals::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetComputePointNormals::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetComputePointNormals();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::ComputePointNormalsOn()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_ComputePointNormalsOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_ComputePointNormalsOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputePointNormalsOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::ComputePointNormalsOff()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_ComputePointNormalsOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_ComputePointNormalsOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputePointNormalsOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::SetComputeCellNormals(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SetComputeCellNormals::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SetComputeCellNormals::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetComputeCellNormals(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataNormals::GetComputeCellNormals()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetComputeCellNormals::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetComputeCellNormals::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetComputeCellNormals();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::ComputeCellNormalsOn()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_ComputeCellNormalsOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_ComputeCellNormalsOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeCellNormalsOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::ComputeCellNormalsOff()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_ComputeCellNormalsOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_ComputeCellNormalsOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeCellNormalsOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::SetFlipNormals(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SetFlipNormals::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SetFlipNormals::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFlipNormals(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataNormals::GetFlipNormals()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetFlipNormals::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetFlipNormals::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFlipNormals();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::FlipNormalsOn()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_FlipNormalsOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_FlipNormalsOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FlipNormalsOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::FlipNormalsOff()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_FlipNormalsOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_FlipNormalsOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FlipNormalsOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::SetNonManifoldTraversal(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_SetNonManifoldTraversal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_SetNonManifoldTraversal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNonManifoldTraversal(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataNormals::GetNonManifoldTraversal()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_GetNonManifoldTraversal::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_GetNonManifoldTraversal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNonManifoldTraversal();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::NonManifoldTraversalOn()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_NonManifoldTraversalOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_NonManifoldTraversalOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->NonManifoldTraversalOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataNormals::NonManifoldTraversalOff()
//---------------------------------------------------
void WrapClass_vtkPolyDataNormals::
    wrap_NonManifoldTraversalOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataNormals::
    wrap_NonManifoldTraversalOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->NonManifoldTraversalOff();
  return BasicVariable::ptr();
}

