/**
 * C++ Interface: wrap_vtkVolumeMapper
 *
 * Description: wrapping vtkVolumeMapper
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
#include "wrap_vtkVolumeMapper.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkImageData.h"
#include "wrap_vtkDataSet.h"
#include "wrap_vtkWindow.h"


#include "wrap_vtkVolumeMapper.h"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVolumeMapper>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkVolumeMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkVolumeMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkVolumeMapper>::CreateVar( vtkVolumeMapper* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkVolumeMapper> obj_ptr(val,smartpointer_nodeleter<vtkVolumeMapper>());
  return AMILabType<vtkVolumeMapper>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolumeMapper
//
Variable<AMIObject>::ptr WrapClass_vtkVolumeMapper::CreateVar( vtkVolumeMapper* sp)
{
  boost::shared_ptr<vtkVolumeMapper> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolumeMapper>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolumeMapper>::CreateVar(
      new WrapClass_vtkVolumeMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolumeMapper::AddMethods(WrapClass<vtkVolumeMapper>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_SetInput_1( this_ptr);
  AddVar_SetInput( this_ptr);
  AddVar_SetInput_2( this_ptr);
  AddVar_GetInput( this_ptr);
  AddVar_SetBlendMode( this_ptr);
  AddVar_SetBlendModeToComposite( this_ptr);
  AddVar_SetBlendModeToMaximumIntensity( this_ptr);
  AddVar_SetBlendModeToMinimumIntensity( this_ptr);
  AddVar_GetBlendMode( this_ptr);
  AddVar_SetCropping( this_ptr);
  AddVar_GetCroppingMinValue( this_ptr);
  AddVar_GetCroppingMaxValue( this_ptr);
  AddVar_GetCropping( this_ptr);
  AddVar_CroppingOn( this_ptr);
  AddVar_CroppingOff( this_ptr);
  AddVar_SetCroppingRegionPlanes_1( this_ptr);
  AddVar_SetCroppingRegionPlanes( this_ptr);
  AddVar_SetCroppingRegionPlanes_2( this_ptr);
  AddVar_GetCroppingRegionPlanes_1( this_ptr);
  AddVar_GetCroppingRegionPlanes( this_ptr);
  AddVar_GetCroppingRegionPlanes_2( this_ptr);
  AddVar_GetVoxelCroppingRegionPlanes_1( this_ptr);
  AddVar_GetVoxelCroppingRegionPlanes( this_ptr);
  AddVar_GetVoxelCroppingRegionPlanes_2( this_ptr);
  AddVar_SetCroppingRegionFlags( this_ptr);
  AddVar_GetCroppingRegionFlagsMinValue( this_ptr);
  AddVar_GetCroppingRegionFlagsMaxValue( this_ptr);
  AddVar_GetCroppingRegionFlags( this_ptr);
  AddVar_SetCroppingRegionFlagsToSubVolume( this_ptr);
  AddVar_SetCroppingRegionFlagsToFence( this_ptr);
  AddVar_SetCroppingRegionFlagsToInvertedFence( this_ptr);
  AddVar_SetCroppingRegionFlagsToCross( this_ptr);
  AddVar_SetCroppingRegionFlagsToInvertedCross( this_ptr);
  AddVar_ReleaseGraphicsResources( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  
  AMIObject::ptr obj_enum_86(new AMIObject);
  obj_enum_86->SetName("enum_86");

  BasicVariable::ptr var_COMPOSITE_BLEND = AMILabType<int >::CreateVar(0);
  if (var_COMPOSITE_BLEND.get()) {
    var_COMPOSITE_BLEND->Rename("COMPOSITE_BLEND");
    obj_enum_86->GetContext()->AddVar(var_COMPOSITE_BLEND,obj_enum_86->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_enum_86->GetName().c_str(),obj_enum_86,context);


  // Adding Bases

  // Add base parent vtkAbstractVolumeMapper
  boost::shared_ptr<vtkAbstractVolumeMapper > parent_vtkAbstractVolumeMapper(  boost::dynamic_pointer_cast<vtkAbstractVolumeMapper >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkAbstractVolumeMapper = AMILabType<vtkAbstractVolumeMapper >::CreateVarFromSmtPtr(parent_vtkAbstractVolumeMapper);
  context->AddVar("vtkAbstractVolumeMapper",var_vtkAbstractVolumeMapper);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkAbstractVolumeMapper = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkAbstractVolumeMapper);
  context->AddDefault(obj_vtkAbstractVolumeMapper->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkVolumeMapper::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolumeMapper");
  
  // Static methods 
  WrapClass_vtkVolumeMapper::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkVolumeMapper::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkVolumeMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkVolumeMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkVolumeMapper * vtkVolumeMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkVolumeMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
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

  vtkVolumeMapper * res =   vtkVolumeMapper::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkVolumeMapper::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
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
//  Wrapping of vtkVolumeMapper * vtkVolumeMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeMapper * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkVolumeMapper::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
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
//  Wrapping of void vtkVolumeMapper::SetInput(vtkImageData * param0)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetInput_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkImageData, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetInput_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkImageData* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkImageData*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkImageData > param0_smtptr;
    if (!get_val_smtptr_param<vtkImageData >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInput(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeMapper::SetInput(...)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetInput::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetInput::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeMapper::wrap_SetInput_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeMapper::wrap_SetInput_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetInput(vtkDataSet * param0)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetInput_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataSet, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetInput_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkDataSet* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkDataSet*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataSet > param0_smtptr;
    if (!get_val_smtptr_param<vtkDataSet >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInput(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkVolumeMapper::GetInput()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkImageData * res =   this->_objectptr->GetObj()->GetInput();
  BasicVariable::ptr res_var = WrapClass_vtkImageData::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetBlendMode(int _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetBlendMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetBlendMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBlendMode(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetBlendModeToComposite()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetBlendModeToComposite::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetBlendModeToComposite::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBlendModeToComposite();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetBlendModeToMaximumIntensity()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetBlendModeToMaximumIntensity::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetBlendModeToMaximumIntensity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBlendModeToMaximumIntensity();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetBlendModeToMinimumIntensity()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetBlendModeToMinimumIntensity::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetBlendModeToMinimumIntensity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBlendModeToMinimumIntensity();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeMapper::GetBlendMode()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetBlendMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetBlendMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBlendMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetCropping(int _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCropping::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCropping::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCropping(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeMapper::GetCroppingMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetCroppingMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetCroppingMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCroppingMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeMapper::GetCroppingMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetCroppingMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetCroppingMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCroppingMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeMapper::GetCropping()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetCropping::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetCropping::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCropping();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::CroppingOn()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_CroppingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_CroppingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CroppingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::CroppingOff()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_CroppingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_CroppingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CroppingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetCroppingRegionPlanes(double _arg1, double _arg2, double _arg3, double _arg4, double _arg5, double _arg6)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionPlanes_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg4'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg5'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg6'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionPlanes_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg3;
  if (!get_val_param<double >(_arg3,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg4;
  if (!get_val_param<double >(_arg4,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg5;
  if (!get_val_param<double >(_arg5,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg6;
  if (!get_val_param<double >(_arg6,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetCroppingRegionPlanes(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeMapper::SetCroppingRegionPlanes(...)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionPlanes::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionPlanes::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeMapper::wrap_SetCroppingRegionPlanes_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeMapper::wrap_SetCroppingRegionPlanes_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetCroppingRegionPlanes(double * _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionPlanes_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionPlanes_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetCroppingRegionPlanes(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkVolumeMapper::GetCroppingRegionPlanes()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionPlanes_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionPlanes_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetCroppingRegionPlanes();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeMapper::GetCroppingRegionPlanes(...)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionPlanes::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionPlanes::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeMapper::wrap_GetCroppingRegionPlanes_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeMapper::wrap_GetCroppingRegionPlanes_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::GetCroppingRegionPlanes(double * data)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionPlanes_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionPlanes_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetCroppingRegionPlanes(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkVolumeMapper::GetVoxelCroppingRegionPlanes()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetVoxelCroppingRegionPlanes_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetVoxelCroppingRegionPlanes_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetVoxelCroppingRegionPlanes();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeMapper::GetVoxelCroppingRegionPlanes(...)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetVoxelCroppingRegionPlanes::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetVoxelCroppingRegionPlanes::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeMapper::wrap_GetVoxelCroppingRegionPlanes_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeMapper::wrap_GetVoxelCroppingRegionPlanes_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::GetVoxelCroppingRegionPlanes(double * data)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetVoxelCroppingRegionPlanes_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetVoxelCroppingRegionPlanes_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetVoxelCroppingRegionPlanes(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetCroppingRegionFlags(int _arg)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlags::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlags::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCroppingRegionFlags(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeMapper::GetCroppingRegionFlagsMinValue()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionFlagsMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionFlagsMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCroppingRegionFlagsMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeMapper::GetCroppingRegionFlagsMaxValue()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionFlagsMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionFlagsMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCroppingRegionFlagsMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeMapper::GetCroppingRegionFlags()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionFlags::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_GetCroppingRegionFlags::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCroppingRegionFlags();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetCroppingRegionFlagsToSubVolume()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToSubVolume::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToSubVolume::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCroppingRegionFlagsToSubVolume();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetCroppingRegionFlagsToFence()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToFence::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToFence::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCroppingRegionFlagsToFence();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetCroppingRegionFlagsToInvertedFence()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToInvertedFence::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToInvertedFence::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCroppingRegionFlagsToInvertedFence();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetCroppingRegionFlagsToCross()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToCross::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToCross::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCroppingRegionFlagsToCross();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::SetCroppingRegionFlagsToInvertedCross()
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToInvertedCross::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
    wrap_SetCroppingRegionFlagsToInvertedCross::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCroppingRegionFlagsToInvertedCross();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolumeMapper::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkVolumeMapper::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeMapper::
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

