/**
 * C++ Interface: wrap_vtkAMILabGPUMultiVolumeRayCastMapper
 *
 * Description: wrapping vtkAMILabGPUMultiVolumeRayCastMapper
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

#include "wrap_vtkAMILabGPUMultiVolumeRayCastMapper.h"

// get all the required includes
// #include "..."
#include "/home/karl/projects/Sourceforge/amilab/trunk/Modules/vtkAmiVolRen/src/vtkAMILabGPUMultiVolumeRayCastMapper.h"
#include "/usr/local/include/vtk-5.8/vtkObjectBase.h"
#include "/usr/local/include/vtk-5.8/vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"

#ifndef vtkAMILabGPUMultiVolumeRayCastMapper_declared
  #define vtkAMILabGPUMultiVolumeRayCastMapper_declared
  AMI_DECLARE_TYPE(vtkAMILabGPUMultiVolumeRayCastMapper)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkRenderWindow_declared
  #define vtkRenderWindow_declared
  AMI_DECLARE_TYPE(vtkRenderWindow)
#endif
#ifndef vtkVolumeProperty_declared
  #define vtkVolumeProperty_declared
  AMI_DECLARE_TYPE(vtkVolumeProperty)
#endif
#ifndef vtkRenderer_declared
  #define vtkRenderer_declared
  AMI_DECLARE_TYPE(vtkRenderer)
#endif
#ifndef vtkVolume_declared
  #define vtkVolume_declared
  AMI_DECLARE_TYPE(vtkVolume)
#endif
#ifndef vtkImageData_declared
  #define vtkImageData_declared
  AMI_DECLARE_TYPE(vtkImageData)
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
BasicVariable::ptr WrapClass<vtkAMILabGPUMultiVolumeRayCastMapper>::CreateVar( ParamList* p, bool quiet)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkAMILabGPUMultiVolumeRayCastMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkAMILabGPUMultiVolumeRayCastMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkAMILabGPUMultiVolumeRayCastMapper >::CreateVar( vtkAMILabGPUMultiVolumeRayCastMapper* val, bool nodeleter)
{ 
    boost::shared_ptr<vtkAMILabGPUMultiVolumeRayCastMapper > obj_ptr;
  if (nodeleter)
    obj_ptr = boost::shared_ptr<vtkAMILabGPUMultiVolumeRayCastMapper >(val, smartpointer_nodeleter<vtkAMILabGPUMultiVolumeRayCastMapper >());
  else
    obj_ptr = boost::shared_ptr<vtkAMILabGPUMultiVolumeRayCastMapper >(val , smartpointer_nodeleter<vtkAMILabGPUMultiVolumeRayCastMapper >());
  return AMILabType<vtkAMILabGPUMultiVolumeRayCastMapper >::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkAMILabGPUMultiVolumeRayCastMapper
//
Variable<AMIObject>::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::CreateVar( vtkAMILabGPUMultiVolumeRayCastMapper* sp)
{
  boost::shared_ptr<vtkAMILabGPUMultiVolumeRayCastMapper> di_ptr(
    sp  
    , smartpointer_nodeleter<vtkAMILabGPUMultiVolumeRayCastMapper >() ); 
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkAMILabGPUMultiVolumeRayCastMapper>::CreateVar(
      new WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::AddMethods(WrapClass<vtkAMILabGPUMultiVolumeRayCastMapper>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: std::ostream
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_SetAutoAdjustSampleDistances( this_ptr);
  AddVar_GetAutoAdjustSampleDistancesMinValue( this_ptr);
  AddVar_GetAutoAdjustSampleDistancesMaxValue( this_ptr);
  AddVar_GetAutoAdjustSampleDistances( this_ptr);
  AddVar_AutoAdjustSampleDistancesOn( this_ptr);
  AddVar_AutoAdjustSampleDistancesOff( this_ptr);
  AddVar_SetSampleDistance( this_ptr);
  AddVar_GetSampleDistance( this_ptr);
  AddVar_SetImageSampleDistance( this_ptr);
  AddVar_GetImageSampleDistanceMinValue( this_ptr);
  AddVar_GetImageSampleDistanceMaxValue( this_ptr);
  AddVar_GetImageSampleDistance( this_ptr);
  AddVar_SetMinimumImageSampleDistance( this_ptr);
  AddVar_GetMinimumImageSampleDistanceMinValue( this_ptr);
  AddVar_GetMinimumImageSampleDistanceMaxValue( this_ptr);
  AddVar_GetMinimumImageSampleDistance( this_ptr);
  AddVar_SetMaximumImageSampleDistance( this_ptr);
  AddVar_GetMaximumImageSampleDistanceMinValue( this_ptr);
  AddVar_GetMaximumImageSampleDistanceMaxValue( this_ptr);
  AddVar_GetMaximumImageSampleDistance( this_ptr);
  AddVar_SetFinalColorWindow( this_ptr);
  AddVar_GetFinalColorWindow( this_ptr);
  AddVar_SetFinalColorLevel( this_ptr);
  AddVar_GetFinalColorLevel( this_ptr);
  AddVar_SetMaxMemoryInBytes( this_ptr);
  AddVar_GetMaxMemoryInBytes( this_ptr);
  AddVar_SetMaxMemoryFraction( this_ptr);
  AddVar_GetMaxMemoryFractionMinValue( this_ptr);
  AddVar_GetMaxMemoryFractionMaxValue( this_ptr);
  AddVar_GetMaxMemoryFraction( this_ptr);
  AddVar_SetReportProgress( this_ptr);
  AddVar_GetReportProgress( this_ptr);
  AddVar_IsRenderSupported( this_ptr);
  AddVar_CreateCanonicalView( this_ptr);
  AddVar_SetMaskInput( this_ptr);
  AddVar_GetMaskInput( this_ptr);
  AddVar_SetMaskType( this_ptr);
  AddVar_GetMaskType( this_ptr);
  AddVar_SetMaskTypeToBinary( this_ptr);
  AddVar_SetMaskTypeToLabelMap( this_ptr);
  AddVar_SetMaskBlendFactor( this_ptr);
  AddVar_GetMaskBlendFactorMinValue( this_ptr);
  AddVar_GetMaskBlendFactorMaxValue( this_ptr);
  AddVar_GetMaskBlendFactor( this_ptr);
  AddVar_Render( this_ptr);
  AddVar_GPURender( this_ptr);
  AddVar_ReleaseGraphicsResources( this_ptr);
  AddVar_GetReductionRatio( this_ptr);



  // Add public fields 
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  // Adding Bases

  // Add base parent vtkVolumeMapper
  boost::shared_ptr<vtkVolumeMapper > parent_vtkVolumeMapper(  boost::dynamic_pointer_cast<vtkVolumeMapper >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkVolumeMapper = AMILabType<vtkVolumeMapper >::CreateVarFromSmtPtr(parent_vtkVolumeMapper);
  context->AddVar("vtkVolumeMapper",var_vtkVolumeMapper);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkVolumeMapper = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkVolumeMapper);
  context->AddDefault(obj_vtkVolumeMapper->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkAMILabGPUMultiVolumeRayCastMapper_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkAMILabGPUMultiVolumeRayCastMapper");
  
  // Static methods 
  WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::AddVar_New(amiobject->GetContext());
  WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::AddVar_SafeDownCast(amiobject->GetContext());

  
// Add public enumerations 
  AMIObject::ptr obj_enum_85(new AMIObject);
  obj_enum_85->SetName("enum_85");

  BasicVariable::ptr var_LabelMapMaskType = AMILabType<int >::CreateVar(1);
  if (var_LabelMapMaskType.get()) {
    var_LabelMapMaskType->Rename("LabelMapMaskType");
    obj_enum_85->GetContext()->AddVar(var_LabelMapMaskType,obj_enum_85->GetContext());
  }
  BasicVariable::ptr var_BinaryMaskType = AMILabType<int >::CreateVar(0);
  if (var_BinaryMaskType.get()) {
    var_BinaryMaskType->Rename("BinaryMaskType");
    obj_enum_85->GetContext()->AddVar(var_BinaryMaskType,obj_enum_85->GetContext());
  }

  // Add enum to context
  amiobject->GetContext()->AddVar<AMIObject>(obj_enum_85->GetName().c_str(),obj_enum_85,context);
  // Add as default context
  amiobject->GetContext()->AddDefault(obj_enum_85->GetContext());

  // Adding public typedefs 
  BasicVariable::ptr type_0 = AMILabType<std::string>::CreateVar(new std::string("vtkVolumeMapper  --  vtkVolumeMapper"));
  type_0->Rename("Superclass");
  amiobject->GetContext()->AddVar(type_0->Name(),type_0,context);


  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkAMILabGPUMultiVolumeRayCastMapper * vtkAMILabGPUMultiVolumeRayCastMapper::New()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkAMILabGPUMultiVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  vtkAMILabGPUMultiVolumeRayCastMapper * res = vtkAMILabGPUMultiVolumeRayCastMapper::New();
  if (res==NULL) return nullvar;
  BasicVariable::ptr res_var = AMILabType<vtkAMILabGPUMultiVolumeRayCastMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAMILabGPUMultiVolumeRayCastMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!AMILabType<std::string >::get_val_smtptr_param(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();
  // -------- Calling the class method with all parameter(s)
  int res = vtkAMILabGPUMultiVolumeRayCastMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAMILabGPUMultiVolumeRayCastMapper * vtkAMILabGPUMultiVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkAMILabGPUMultiVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
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
    if (!AMILabType<vtkObjectBase >::get_val_smtptr_param(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    o = o_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  vtkAMILabGPUMultiVolumeRayCastMapper * res = vtkAMILabGPUMultiVolumeRayCastMapper::SafeDownCast(o);
  if (res==NULL) return nullvar;
  BasicVariable::ptr res_var = AMILabType<vtkAMILabGPUMultiVolumeRayCastMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAMILabGPUMultiVolumeRayCastMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!AMILabType<std::string >::get_val_smtptr_param(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  int res = this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAMILabGPUMultiVolumeRayCastMapper * vtkAMILabGPUMultiVolumeRayCastMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkAMILabGPUMultiVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  vtkAMILabGPUMultiVolumeRayCastMapper * res = this->_objectptr->GetObj()->NewInstance();
  if (res==NULL) return nullvar;
  BasicVariable::ptr res_var = AMILabType<vtkAMILabGPUMultiVolumeRayCastMapper >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: std::ostream

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::PrintSelf(std::ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::ostream, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::ostream > os_smtptr;
  if (!AMILabType<std::ostream >::get_val_smtptr_param(os_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  std::ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!AMILabType<vtkIndent >::get_val_param(indent,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetAutoAdjustSampleDistances(int _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetAutoAdjustSampleDistances::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetAutoAdjustSampleDistances::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!AMILabType<int >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetAutoAdjustSampleDistances(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAMILabGPUMultiVolumeRayCastMapper::GetAutoAdjustSampleDistancesMinValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  int res = this->_objectptr->GetObj()->GetAutoAdjustSampleDistancesMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAMILabGPUMultiVolumeRayCastMapper::GetAutoAdjustSampleDistancesMaxValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistancesMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  int res = this->_objectptr->GetObj()->GetAutoAdjustSampleDistancesMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAMILabGPUMultiVolumeRayCastMapper::GetAutoAdjustSampleDistances()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistances::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetAutoAdjustSampleDistances::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  int res = this->_objectptr->GetObj()->GetAutoAdjustSampleDistances();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::AutoAdjustSampleDistancesOn()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->AutoAdjustSampleDistancesOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::AutoAdjustSampleDistancesOff()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_AutoAdjustSampleDistancesOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->AutoAdjustSampleDistancesOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetSampleDistance(float _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!AMILabType<float >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetSampleDistance()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetSampleDistance();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetImageSampleDistance(float _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetImageSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetImageSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!AMILabType<float >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetImageSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetImageSampleDistanceMinValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetImageSampleDistanceMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetImageSampleDistanceMaxValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetImageSampleDistanceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetImageSampleDistanceMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetImageSampleDistance()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetImageSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetImageSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetImageSampleDistance();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetMinimumImageSampleDistance(float _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMinimumImageSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMinimumImageSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!AMILabType<float >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetMinimumImageSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMinimumImageSampleDistanceMinValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMinimumImageSampleDistanceMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMinimumImageSampleDistanceMaxValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistanceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMinimumImageSampleDistanceMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMinimumImageSampleDistance()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMinimumImageSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMinimumImageSampleDistance();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaximumImageSampleDistance(float _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaximumImageSampleDistance::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaximumImageSampleDistance::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!AMILabType<float >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetMaximumImageSampleDistance(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaximumImageSampleDistanceMinValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMaximumImageSampleDistanceMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaximumImageSampleDistanceMaxValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistanceMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMaximumImageSampleDistanceMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaximumImageSampleDistance()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistance::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaximumImageSampleDistance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMaximumImageSampleDistance();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetFinalColorWindow(float _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetFinalColorWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetFinalColorWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!AMILabType<float >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetFinalColorWindow(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetFinalColorWindow()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetFinalColorWindow::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetFinalColorWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetFinalColorWindow();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetFinalColorLevel(float _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetFinalColorLevel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetFinalColorLevel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!AMILabType<float >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetFinalColorLevel(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetFinalColorLevel()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetFinalColorLevel::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetFinalColorLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetFinalColorLevel();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaxMemoryInBytes(long long int _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaxMemoryInBytes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaxMemoryInBytes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long _arg_long;
  if (!AMILabType<long >::get_val_param(_arg_long,_p,_n,true,false,false)) ClassHelpAndReturn;
  long long int _arg = boost::numeric_cast<long long int >(_arg_long);
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetMaxMemoryInBytes(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long long int vtkAMILabGPUMultiVolumeRayCastMapper::GetMaxMemoryInBytes()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaxMemoryInBytes::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaxMemoryInBytes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  long long int res = this->_objectptr->GetObj()->GetMaxMemoryInBytes();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaxMemoryFraction(float _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaxMemoryFraction::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaxMemoryFraction::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!AMILabType<float >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetMaxMemoryFraction(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaxMemoryFractionMinValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaxMemoryFractionMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaxMemoryFractionMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMaxMemoryFractionMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaxMemoryFractionMaxValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaxMemoryFractionMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaxMemoryFractionMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMaxMemoryFractionMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaxMemoryFraction()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaxMemoryFraction::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaxMemoryFraction::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMaxMemoryFraction();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetReportProgress(bool _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetReportProgress::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetReportProgress::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool _arg;
  if (!AMILabType<bool >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetReportProgress(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool vtkAMILabGPUMultiVolumeRayCastMapper::GetReportProgress()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetReportProgress::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetReportProgress::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  bool res = this->_objectptr->GetObj()->GetReportProgress();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAMILabGPUMultiVolumeRayCastMapper::IsRenderSupported(vtkRenderWindow * param0, vtkVolumeProperty * param1)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_IsRenderSupported::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindow, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkVolumeProperty, "parameter named 'param1'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_IsRenderSupported::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkRenderWindow* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkRenderWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderWindow > param0_smtptr;
    if (!AMILabType<vtkRenderWindow >::get_val_smtptr_param(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  vtkVolumeProperty* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkVolumeProperty*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolumeProperty > param1_smtptr;
    if (!AMILabType<vtkVolumeProperty >::get_val_smtptr_param(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param1 = param1_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  int res = this->_objectptr->GetObj()->IsRenderSupported(param0, param1);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::CreateCanonicalView(vtkRenderer * ren, vtkVolume * volume, vtkImageData * image, int blend_mode, double * viewDirection, double * viewUp)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_CreateCanonicalView::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'volume'")
  ADDPARAMCOMMENT_TYPE( vtkImageData, "parameter named 'image'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'blend_mode'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'viewDirection'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'viewUp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_CreateCanonicalView::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* ren;
  if (CheckNullVar(_p,_n))  {
    ren=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > ren_smtptr;
    if (!AMILabType<vtkRenderer >::get_val_smtptr_param(ren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ren = ren_smtptr.get();
  }

  vtkVolume* volume;
  if (CheckNullVar(_p,_n))  {
    volume=(vtkVolume*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolume > volume_smtptr;
    if (!AMILabType<vtkVolume >::get_val_smtptr_param(volume_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    volume = volume_smtptr.get();
  }

  vtkImageData* image;
  if (CheckNullVar(_p,_n))  {
    image=(vtkImageData*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkImageData > image_smtptr;
    if (!AMILabType<vtkImageData >::get_val_smtptr_param(image_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    image = image_smtptr.get();
  }

  int blend_mode;
  if (!AMILabType<int >::get_val_param(blend_mode,_p,_n,true,false,false)) ClassHelpAndReturn;

  double* viewDirection;
  if (CheckNullVar(_p,_n))  {
    viewDirection=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > viewDirection_smtptr;
    if (!AMILabType<double >::get_val_smtptr_param(viewDirection_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    viewDirection = viewDirection_smtptr.get();
  }

  double* viewUp;
  if (CheckNullVar(_p,_n))  {
    viewUp=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > viewUp_smtptr;
    if (!AMILabType<double >::get_val_smtptr_param(viewUp_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    viewUp = viewUp_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->CreateCanonicalView(ren, volume, image, blend_mode, viewDirection, viewUp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskInput(vtkImageData * mask)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskInput::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkImageData, "parameter named 'mask'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskInput::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkImageData* mask;
  if (CheckNullVar(_p,_n))  {
    mask=(vtkImageData*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkImageData > mask_smtptr;
    if (!AMILabType<vtkImageData >::get_val_smtptr_param(mask_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    mask = mask_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetMaskInput(mask);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskInput()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  vtkImageData * res = this->_objectptr->GetObj()->GetMaskInput();
  if (res==NULL) return nullvar;
  BasicVariable::ptr res_var = AMILabType<vtkImageData >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskType(int _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!AMILabType<int >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetMaskType(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskType()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  int res = this->_objectptr->GetObj()->GetMaskType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskTypeToBinary()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskTypeToBinary::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskTypeToBinary::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetMaskTypeToBinary();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskTypeToLabelMap()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskTypeToLabelMap::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskTypeToLabelMap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetMaskTypeToLabelMap();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::SetMaskBlendFactor(float _arg)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskBlendFactor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_SetMaskBlendFactor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!AMILabType<float >::get_val_param(_arg,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->SetMaskBlendFactor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskBlendFactorMinValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskBlendFactorMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskBlendFactorMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMaskBlendFactorMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskBlendFactorMaxValue()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskBlendFactorMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskBlendFactorMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMaskBlendFactorMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkAMILabGPUMultiVolumeRayCastMapper::GetMaskBlendFactor()
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskBlendFactor::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetMaskBlendFactor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  float res = this->_objectptr->GetObj()->GetMaskBlendFactor();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::Render(vtkRenderer * param0, vtkVolume * param1)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_Render::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_Render::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > param0_smtptr;
    if (!AMILabType<vtkRenderer >::get_val_smtptr_param(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  vtkVolume* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkVolume*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolume > param1_smtptr;
    if (!AMILabType<vtkVolume >::get_val_smtptr_param(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param1 = param1_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->Render(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::GPURender(vtkRenderer * param0, vtkVolume * param1)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GPURender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GPURender::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > param0_smtptr;
    if (!AMILabType<vtkRenderer >::get_val_smtptr_param(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  vtkVolume* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkVolume*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolume > param1_smtptr;
    if (!AMILabType<vtkVolume >::get_val_smtptr_param(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param1 = param1_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->GPURender(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
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
    if (!AMILabType<vtkWindow >::get_val_smtptr_param(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->ReleaseGraphicsResources(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabGPUMultiVolumeRayCastMapper::GetReductionRatio(double * ratio)
//---------------------------------------------------
void WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetReductionRatio::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ratio'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabGPUMultiVolumeRayCastMapper::
    wrap_GetReductionRatio::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double* ratio;
  if (CheckNullVar(_p,_n))  {
    ratio=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > ratio_smtptr;
    if (!AMILabType<double >::get_val_smtptr_param(ratio_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ratio = ratio_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->GetReductionRatio(ratio);
  return BasicVariable::ptr();
}

