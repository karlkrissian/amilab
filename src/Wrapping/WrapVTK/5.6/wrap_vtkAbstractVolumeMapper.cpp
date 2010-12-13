/**
 * C++ Interface: wrap_vtkAbstractVolumeMapper
 *
 * Description: wrapping vtkAbstractVolumeMapper
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

#include "wrap_vtkAbstractVolumeMapper.h"

// get all the required includes
// #include "..."
#ifndef vtkAbstractVolumeMapper_declared
  #define vtkAbstractVolumeMapper_declared
  AMI_DECLARE_TYPE(vtkAbstractVolumeMapper)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkDataSet_declared
  #define vtkDataSet_declared
  AMI_DECLARE_TYPE(vtkDataSet)
#endif
#ifndef vtkDataObject_declared
  #define vtkDataObject_declared
  AMI_DECLARE_TYPE(vtkDataObject)
#endif
#ifndef vtkWindow_declared
  #define vtkWindow_declared
  AMI_DECLARE_TYPE(vtkWindow)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkAbstractVolumeMapper>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkAbstractVolumeMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkAbstractVolumeMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkAbstractVolumeMapper>::CreateVar( vtkAbstractVolumeMapper* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkAbstractVolumeMapper> obj_ptr(val,smartpointer_nodeleter<vtkAbstractVolumeMapper>());
  return AMILabType<vtkAbstractVolumeMapper>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkAbstractVolumeMapper
//
Variable<AMIObject>::ptr WrapClass_vtkAbstractVolumeMapper::CreateVar( vtkAbstractVolumeMapper* sp)
{
  boost::shared_ptr<vtkAbstractVolumeMapper> di_ptr(
    sp,
    wxwindow_nodeleter<vtkAbstractVolumeMapper>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkAbstractVolumeMapper>::CreateVar(
      new WrapClass_vtkAbstractVolumeMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::AddMethods(WrapClass<vtkAbstractVolumeMapper>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_SetInput( this_ptr);
  AddVar_GetDataSetInput( this_ptr);
  AddVar_GetDataObjectInput( this_ptr);
  AddVar_GetBounds_1( this_ptr);
  AddVar_GetBounds( this_ptr);
  AddVar_GetBounds_2( this_ptr);
  AddVar_SetScalarMode( this_ptr);
  AddVar_GetScalarMode( this_ptr);
  AddVar_SetScalarModeToDefault( this_ptr);
  AddVar_SetScalarModeToUsePointData( this_ptr);
  AddVar_SetScalarModeToUseCellData( this_ptr);
  AddVar_SetScalarModeToUsePointFieldData( this_ptr);
  AddVar_SetScalarModeToUseCellFieldData( this_ptr);
  AddVar_SelectScalarArray_1( this_ptr);
  AddVar_SelectScalarArray( this_ptr);
  AddVar_SelectScalarArray_2( this_ptr);
  AddVar_GetArrayName( this_ptr);
  AddVar_GetArrayId( this_ptr);
  AddVar_GetArrayAccessMode( this_ptr);
  AddVar_GetScalarModeAsString( this_ptr);
  AddVar_GetGradientMagnitudeScale_1( this_ptr);
  AddVar_GetGradientMagnitudeBias_1( this_ptr);
  AddVar_GetGradientMagnitudeScale( this_ptr);
  AddVar_GetGradientMagnitudeScale_2( this_ptr);
  AddVar_GetGradientMagnitudeBias( this_ptr);
  AddVar_GetGradientMagnitudeBias_2( this_ptr);
  AddVar_ReleaseGraphicsResources( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkAbstractMapper3D
  boost::shared_ptr<vtkAbstractMapper3D > parent_vtkAbstractMapper3D(  boost::dynamic_pointer_cast<vtkAbstractMapper3D >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkAbstractMapper3D = AMILabType<vtkAbstractMapper3D >::CreateVarFromSmtPtr(parent_vtkAbstractMapper3D);
  context->AddVar("vtkAbstractMapper3D",var_vtkAbstractMapper3D);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkAbstractMapper3D = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkAbstractMapper3D);
  context->AddDefault(obj_vtkAbstractMapper3D->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkAbstractVolumeMapper_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkAbstractVolumeMapper");
  
  // Static methods 
  WrapClass_vtkAbstractVolumeMapper::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkAbstractVolumeMapper::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkAbstractVolumeMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkAbstractVolumeMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAbstractVolumeMapper * vtkAbstractVolumeMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkAbstractVolumeMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
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

  vtkAbstractVolumeMapper * res =   vtkAbstractVolumeMapper::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkAbstractVolumeMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractVolumeMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
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
//  Wrapping of vtkAbstractVolumeMapper * vtkAbstractVolumeMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractVolumeMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractVolumeMapper * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkAbstractVolumeMapper >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
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
//  Wrapping of void vtkAbstractVolumeMapper::SetInput(vtkDataSet * param0)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SetInput::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataSet, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SetInput::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataSet* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkDataSet*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataSet > param0_smtptr;
    if (!get_val_smtptr_param<vtkDataSet >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInput(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkDataSet * vtkAbstractVolumeMapper::GetDataSetInput()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetDataSetInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetDataSetInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataSet * res =   this->_objectptr->GetObj()->GetDataSetInput();
  BasicVariable::ptr res_var = AMILabType<vtkDataSet >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkDataObject * vtkAbstractVolumeMapper::GetDataObjectInput()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetDataObjectInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetDataObjectInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataObject * res =   this->_objectptr->GetObj()->GetDataObjectInput();
  BasicVariable::ptr res_var = AMILabType<vtkDataObject >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractVolumeMapper::GetBounds()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetBounds_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetBounds_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetBounds();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractVolumeMapper::GetBounds(...)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetBounds::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractVolumeMapper::wrap_GetBounds_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractVolumeMapper::wrap_GetBounds_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::GetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetBounds_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetBounds_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* bounds;
  if (CheckNullVar(_p,_n))  {
    bounds=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > bounds_smtptr;
    if (!get_val_smtptr_param<double >(bounds_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    bounds = bounds_smtptr.get();
  }

  this->_objectptr->GetObj()->GetBounds(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::SetScalarMode(int _arg)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarMode(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractVolumeMapper::GetScalarMode()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetScalarMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetScalarMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScalarMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::SetScalarModeToDefault()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToDefault::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToDefault();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::SetScalarModeToUsePointData()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToUsePointData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToUsePointData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToUsePointData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::SetScalarModeToUseCellData()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToUseCellData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToUseCellData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToUseCellData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::SetScalarModeToUsePointFieldData()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToUsePointFieldData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToUsePointFieldData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToUsePointFieldData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::SetScalarModeToUseCellFieldData()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToUseCellFieldData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SetScalarModeToUseCellFieldData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToUseCellFieldData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::SelectScalarArray(int arrayNum)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SelectScalarArray_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'arrayNum'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SelectScalarArray_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int arrayNum;
  if (!get_val_param<int >(arrayNum,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SelectScalarArray(arrayNum);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractVolumeMapper::SelectScalarArray(...)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SelectScalarArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SelectScalarArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractVolumeMapper::wrap_SelectScalarArray_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractVolumeMapper::wrap_SelectScalarArray_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::SelectScalarArray(char const * arrayName)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_SelectScalarArray_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'arrayName'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_SelectScalarArray_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > arrayName_string;
  if (!get_val_smtptr_param<std::string >(arrayName_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * arrayName = arrayName_string->c_str();

  this->_objectptr->GetObj()->SelectScalarArray(arrayName);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char * vtkAbstractVolumeMapper::GetArrayName()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetArrayName::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetArrayName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char * res =   this->_objectptr->GetObj()->GetArrayName();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractVolumeMapper::GetArrayId()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetArrayId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetArrayId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetArrayId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractVolumeMapper::GetArrayAccessMode()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetArrayAccessMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetArrayAccessMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetArrayAccessMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of char const * vtkAbstractVolumeMapper::GetScalarModeAsString()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetScalarModeAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetScalarModeAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetScalarModeAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of float vtkAbstractVolumeMapper::GetGradientMagnitudeScale()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeScale_1::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeScale_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientMagnitudeScale();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAbstractVolumeMapper::GetGradientMagnitudeBias()
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeBias_1::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeBias_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientMagnitudeBias();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractVolumeMapper::GetGradientMagnitudeScale(...)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeScale::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeScale::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractVolumeMapper::wrap_GetGradientMagnitudeScale_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractVolumeMapper::wrap_GetGradientMagnitudeScale_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float vtkAbstractVolumeMapper::GetGradientMagnitudeScale(int param0)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeScale_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeScale_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientMagnitudeScale(param0);
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractVolumeMapper::GetGradientMagnitudeBias(...)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeBias::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeBias::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractVolumeMapper::wrap_GetGradientMagnitudeBias_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractVolumeMapper::wrap_GetGradientMagnitudeBias_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float vtkAbstractVolumeMapper::GetGradientMagnitudeBias(int param0)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeBias_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_GetGradientMagnitudeBias_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientMagnitudeBias(param0);
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractVolumeMapper::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkAbstractVolumeMapper::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractVolumeMapper::
    wrap_ReleaseGraphicsResources::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkWindow* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkWindow > param0_smtptr;
    if (!get_val_smtptr_param<vtkWindow >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->ReleaseGraphicsResources(param0);
  return BasicVariable::ptr();
}

