/**
 * C++ Interface: wrap_vtkMapper
 *
 * Description: wrapping vtkMapper
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

#include "wrap_vtkMapper.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkMapper_declared
  #define vtkMapper_declared
  AMI_DECLARE_TYPE(vtkMapper)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkAbstractMapper_declared
  #define vtkAbstractMapper_declared
  AMI_DECLARE_TYPE(vtkAbstractMapper)
#endif
#ifndef vtkWindow_declared
  #define vtkWindow_declared
  AMI_DECLARE_TYPE(vtkWindow)
#endif
#ifndef vtkScalarsToColors_declared
  #define vtkScalarsToColors_declared
  AMI_DECLARE_TYPE(vtkScalarsToColors)
#endif
#ifndef vtkDataSet_declared
  #define vtkDataSet_declared
  AMI_DECLARE_TYPE(vtkDataSet)
#endif
#ifndef vtkUnsignedCharArray_declared
  #define vtkUnsignedCharArray_declared
  AMI_DECLARE_TYPE(vtkUnsignedCharArray)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkMapper>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkMapper>::CreateVar( vtkMapper* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkMapper> obj_ptr(val,smartpointer_nodeleter<vtkMapper>());
  return AMILabType<vtkMapper>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkMapper
//
Variable<AMIObject>::ptr WrapClass_vtkMapper::CreateVar( vtkMapper* sp)
{
  boost::shared_ptr<vtkMapper> di_ptr(
    sp,
    wxwindow_nodeleter<vtkMapper>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkMapper>::CreateVar(
      new WrapClass_vtkMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkMapper::AddMethods(WrapClass<vtkMapper>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_ShallowCopy( this_ptr);
  AddVar_GetMTime( this_ptr);
  AddVar_ReleaseGraphicsResources( this_ptr);
  AddVar_SetLookupTable( this_ptr);
  AddVar_GetLookupTable( this_ptr);
  AddVar_CreateDefaultLookupTable( this_ptr);
  AddVar_SetScalarVisibility( this_ptr);
  AddVar_GetScalarVisibility( this_ptr);
  AddVar_ScalarVisibilityOn( this_ptr);
  AddVar_ScalarVisibilityOff( this_ptr);
  AddVar_SetStatic( this_ptr);
  AddVar_GetStatic( this_ptr);
  AddVar_StaticOn( this_ptr);
  AddVar_StaticOff( this_ptr);
  AddVar_SetColorMode( this_ptr);
  AddVar_GetColorMode( this_ptr);
  AddVar_SetColorModeToDefault( this_ptr);
  AddVar_SetColorModeToMapScalars( this_ptr);
  AddVar_GetColorModeAsString( this_ptr);
  AddVar_SetInterpolateScalarsBeforeMapping( this_ptr);
  AddVar_GetInterpolateScalarsBeforeMapping( this_ptr);
  AddVar_InterpolateScalarsBeforeMappingOn( this_ptr);
  AddVar_InterpolateScalarsBeforeMappingOff( this_ptr);
  AddVar_SetUseLookupTableScalarRange( this_ptr);
  AddVar_GetUseLookupTableScalarRange( this_ptr);
  AddVar_UseLookupTableScalarRangeOn( this_ptr);
  AddVar_UseLookupTableScalarRangeOff( this_ptr);
  AddVar_SetScalarRange_1( this_ptr);
  AddVar_SetScalarRange( this_ptr);
  AddVar_SetScalarRange_2( this_ptr);
  AddVar_GetScalarRange_1( this_ptr);
  AddVar_GetScalarRange( this_ptr);
  AddVar_GetScalarRange_2( this_ptr);
  AddVar_SetImmediateModeRendering( this_ptr);
  AddVar_GetImmediateModeRendering( this_ptr);
  AddVar_ImmediateModeRenderingOn( this_ptr);
  AddVar_ImmediateModeRenderingOff( this_ptr);
  AddVar_GetForceCompileOnly( this_ptr);
  AddVar_SetForceCompileOnly( this_ptr);
  AddVar_SetScalarMode( this_ptr);
  AddVar_GetScalarMode( this_ptr);
  AddVar_SetScalarModeToDefault( this_ptr);
  AddVar_SetScalarModeToUsePointData( this_ptr);
  AddVar_SetScalarModeToUseCellData( this_ptr);
  AddVar_SetScalarModeToUsePointFieldData( this_ptr);
  AddVar_SetScalarModeToUseCellFieldData( this_ptr);
  AddVar_SetScalarModeToUseFieldData( this_ptr);
  AddVar_SelectColorArray_1( this_ptr);
  AddVar_SelectColorArray( this_ptr);
  AddVar_SelectColorArray_2( this_ptr);
  AddVar_ColorByArrayComponent_1( this_ptr);
  AddVar_ColorByArrayComponent( this_ptr);
  AddVar_ColorByArrayComponent_2( this_ptr);
  AddVar_GetArrayName( this_ptr);
  AddVar_GetArrayId( this_ptr);
  AddVar_GetArrayAccessMode( this_ptr);
  AddVar_GetArrayComponent( this_ptr);
  AddVar_GetScalarModeAsString( this_ptr);
  AddVar_GetBounds_1( this_ptr);
  AddVar_GetBounds( this_ptr);
  AddVar_GetBounds_2( this_ptr);
  AddVar_SetRenderTime( this_ptr);
  AddVar_GetRenderTime( this_ptr);
  AddVar_GetInput( this_ptr);
  AddVar_GetInputAsDataSet( this_ptr);
  AddVar_MapScalars( this_ptr);
  AddVar_SetScalarMaterialMode( this_ptr);
  AddVar_GetScalarMaterialMode( this_ptr);
  AddVar_SetScalarMaterialModeToDefault( this_ptr);
  AddVar_SetScalarMaterialModeToAmbient( this_ptr);
  AddVar_SetScalarMaterialModeToDiffuse( this_ptr);
  AddVar_SetScalarMaterialModeToAmbientAndDiffuse( this_ptr);
  AddVar_GetScalarMaterialModeAsString( this_ptr);
  AddVar_GetSupportsSelection( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

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
void WrapClassvtkMapper_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkMapper");
  
  // Static methods 
  WrapClass_vtkMapper::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SetGlobalImmediateModeRendering(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_GlobalImmediateModeRenderingOn(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_GlobalImmediateModeRenderingOff(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_GetGlobalImmediateModeRendering(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SetResolveCoincidentTopology(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_GetResolveCoincidentTopology(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SetResolveCoincidentTopologyToDefault(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SetResolveCoincidentTopologyToOff(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SetResolveCoincidentTopologyToPolygonOffset(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SetResolveCoincidentTopologyToShiftZBuffer(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SetResolveCoincidentTopologyPolygonOffsetParameters(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_GetResolveCoincidentTopologyPolygonOffsetParameters(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SetResolveCoincidentTopologyPolygonOffsetFaces(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_GetResolveCoincidentTopologyPolygonOffsetFaces(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_SetResolveCoincidentTopologyZShift(amiobject->GetContext());
  WrapClass_vtkMapper::AddVar_GetResolveCoincidentTopologyZShift(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkMapper * vtkMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
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

  vtkMapper * res =   vtkMapper::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetGlobalImmediateModeRendering(int val)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SetGlobalImmediateModeRendering::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'val'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_SetGlobalImmediateModeRendering::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int val;
  if (!get_val_param<int >(val,_p,_n,true,false)) ClassHelpAndReturn;

  vtkMapper::SetGlobalImmediateModeRendering(val);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::GlobalImmediateModeRenderingOn()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_GlobalImmediateModeRenderingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_GlobalImmediateModeRenderingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMapper::GlobalImmediateModeRenderingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::GlobalImmediateModeRenderingOff()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_GlobalImmediateModeRenderingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_GlobalImmediateModeRenderingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMapper::GlobalImmediateModeRenderingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetGlobalImmediateModeRendering()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_GetGlobalImmediateModeRendering::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_GetGlobalImmediateModeRendering::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   vtkMapper::GetGlobalImmediateModeRendering();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetResolveCoincidentTopology(int val)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopology::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'val'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopology::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int val;
  if (!get_val_param<int >(val,_p,_n,true,false)) ClassHelpAndReturn;

  vtkMapper::SetResolveCoincidentTopology(val);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetResolveCoincidentTopology()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_GetResolveCoincidentTopology::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_GetResolveCoincidentTopology::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   vtkMapper::GetResolveCoincidentTopology();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetResolveCoincidentTopologyToDefault()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyToDefault::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyToDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMapper::SetResolveCoincidentTopologyToDefault();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetResolveCoincidentTopologyToOff()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyToOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyToOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMapper::SetResolveCoincidentTopologyToOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetResolveCoincidentTopologyToPolygonOffset()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyToPolygonOffset::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyToPolygonOffset::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMapper::SetResolveCoincidentTopologyToPolygonOffset();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetResolveCoincidentTopologyToShiftZBuffer()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyToShiftZBuffer::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyToShiftZBuffer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMapper::SetResolveCoincidentTopologyToShiftZBuffer();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetResolveCoincidentTopologyPolygonOffsetParameters(double factor, double units)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyPolygonOffsetParameters::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'factor'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'units'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyPolygonOffsetParameters::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double factor;
  if (!get_val_param<double >(factor,_p,_n,true,false)) ClassHelpAndReturn;

  double units;
  if (!get_val_param<double >(units,_p,_n,true,false)) ClassHelpAndReturn;

  vtkMapper::SetResolveCoincidentTopologyPolygonOffsetParameters(factor, units);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::GetResolveCoincidentTopologyPolygonOffsetParameters(double & factor, double & units)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_GetResolveCoincidentTopologyPolygonOffsetParameters::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'factor'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'units'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_GetResolveCoincidentTopologyPolygonOffsetParameters::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > factor_smtptr;
  if (!get_val_smtptr_param<double >(factor_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & factor = *factor_smtptr;

  boost::shared_ptr<double > units_smtptr;
  if (!get_val_smtptr_param<double >(units_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & units = *units_smtptr;

  vtkMapper::GetResolveCoincidentTopologyPolygonOffsetParameters(factor, units);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetResolveCoincidentTopologyPolygonOffsetFaces(int faces)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyPolygonOffsetFaces::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'faces'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyPolygonOffsetFaces::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int faces;
  if (!get_val_param<int >(faces,_p,_n,true,false)) ClassHelpAndReturn;

  vtkMapper::SetResolveCoincidentTopologyPolygonOffsetFaces(faces);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetResolveCoincidentTopologyPolygonOffsetFaces()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_GetResolveCoincidentTopologyPolygonOffsetFaces::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_GetResolveCoincidentTopologyPolygonOffsetFaces::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   vtkMapper::GetResolveCoincidentTopologyPolygonOffsetFaces();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetResolveCoincidentTopologyZShift(double val)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyZShift::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_SetResolveCoincidentTopologyZShift::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double val;
  if (!get_val_param<double >(val,_p,_n,true,false)) ClassHelpAndReturn;

  vtkMapper::SetResolveCoincidentTopologyZShift(val);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkMapper::GetResolveCoincidentTopologyZShift()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_static_GetResolveCoincidentTopologyZShift::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_static_GetResolveCoincidentTopologyZShift::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   vtkMapper::GetResolveCoincidentTopologyZShift();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
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
//  Wrapping of vtkMapper * vtkMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMapper * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkMapper >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkMapper::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
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
//  Wrapping of void vtkMapper::ShallowCopy(vtkAbstractMapper * m)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractMapper, "parameter named 'm'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkAbstractMapper* m;
  if (CheckNullVar(_p,_n))  {
    m=(vtkAbstractMapper*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractMapper > m_smtptr;
    if (!get_val_smtptr_param<vtkAbstractMapper >(m_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    m = m_smtptr.get();
  }

  this->_objectptr->GetObj()->ShallowCopy(m);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkMapper::GetMTime()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
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

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetLookupTable(vtkScalarsToColors * lut)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetLookupTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkScalarsToColors, "parameter named 'lut'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetLookupTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkScalarsToColors* lut;
  if (CheckNullVar(_p,_n))  {
    lut=(vtkScalarsToColors*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkScalarsToColors > lut_smtptr;
    if (!get_val_smtptr_param<vtkScalarsToColors >(lut_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    lut = lut_smtptr.get();
  }

  this->_objectptr->GetObj()->SetLookupTable(lut);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkScalarsToColors * vtkMapper::GetLookupTable()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetLookupTable::SetParametersComments()
{
  return_comments="returning a variable of type vtkScalarsToColors";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetLookupTable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkScalarsToColors * res =   this->_objectptr->GetObj()->GetLookupTable();
  BasicVariable::ptr res_var = AMILabType<vtkScalarsToColors >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::CreateDefaultLookupTable()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_CreateDefaultLookupTable::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_CreateDefaultLookupTable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CreateDefaultLookupTable();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarVisibility(int _arg)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarVisibility::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarVisibility::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarVisibility(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetScalarVisibility()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetScalarVisibility::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetScalarVisibility::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScalarVisibility();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::ScalarVisibilityOn()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_ScalarVisibilityOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_ScalarVisibilityOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ScalarVisibilityOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::ScalarVisibilityOff()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_ScalarVisibilityOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_ScalarVisibilityOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ScalarVisibilityOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetStatic(int _arg)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetStatic::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetStatic::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStatic(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetStatic()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetStatic::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetStatic::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStatic();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::StaticOn()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_StaticOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_StaticOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StaticOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::StaticOff()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_StaticOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_StaticOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StaticOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetColorMode(int _arg)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetColorMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetColorMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetColorMode(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetColorMode()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetColorMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetColorMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetColorMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetColorModeToDefault()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetColorModeToDefault::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetColorModeToDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetColorModeToDefault();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetColorModeToMapScalars()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetColorModeToMapScalars::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetColorModeToMapScalars::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetColorModeToMapScalars();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char const * vtkMapper::GetColorModeAsString()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetColorModeAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetColorModeAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetColorModeAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetInterpolateScalarsBeforeMapping(int _arg)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetInterpolateScalarsBeforeMapping::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetInterpolateScalarsBeforeMapping::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInterpolateScalarsBeforeMapping(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetInterpolateScalarsBeforeMapping()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetInterpolateScalarsBeforeMapping::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetInterpolateScalarsBeforeMapping::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInterpolateScalarsBeforeMapping();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::InterpolateScalarsBeforeMappingOn()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_InterpolateScalarsBeforeMappingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_InterpolateScalarsBeforeMappingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InterpolateScalarsBeforeMappingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::InterpolateScalarsBeforeMappingOff()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_InterpolateScalarsBeforeMappingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_InterpolateScalarsBeforeMappingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InterpolateScalarsBeforeMappingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetUseLookupTableScalarRange(int _arg)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetUseLookupTableScalarRange::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetUseLookupTableScalarRange::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUseLookupTableScalarRange(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetUseLookupTableScalarRange()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetUseLookupTableScalarRange::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetUseLookupTableScalarRange::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetUseLookupTableScalarRange();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::UseLookupTableScalarRangeOn()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_UseLookupTableScalarRangeOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_UseLookupTableScalarRangeOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseLookupTableScalarRangeOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::UseLookupTableScalarRangeOff()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_UseLookupTableScalarRangeOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_UseLookupTableScalarRangeOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseLookupTableScalarRangeOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarRange(double _arg1, double _arg2)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarRange_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarRange_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetScalarRange(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMapper::SetScalarRange(...)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarRange::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarRange::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMapper::wrap_SetScalarRange_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMapper::wrap_SetScalarRange_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarRange(double * _arg)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarRange_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarRange_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetScalarRange(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkMapper::GetScalarRange()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetScalarRange_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetScalarRange_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetScalarRange();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMapper::GetScalarRange(...)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetScalarRange::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetScalarRange::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMapper::wrap_GetScalarRange_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMapper::wrap_GetScalarRange_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::GetScalarRange(double * data)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetScalarRange_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetScalarRange_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetScalarRange(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetImmediateModeRendering(int _arg)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetImmediateModeRendering::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetImmediateModeRendering::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetImmediateModeRendering(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetImmediateModeRendering()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetImmediateModeRendering::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetImmediateModeRendering::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetImmediateModeRendering();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::ImmediateModeRenderingOn()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_ImmediateModeRenderingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_ImmediateModeRenderingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ImmediateModeRenderingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::ImmediateModeRenderingOff()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_ImmediateModeRenderingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_ImmediateModeRenderingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ImmediateModeRenderingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetForceCompileOnly()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetForceCompileOnly::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetForceCompileOnly::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetForceCompileOnly();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetForceCompileOnly(int value)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetForceCompileOnly::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetForceCompileOnly::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int value;
  if (!get_val_param<int >(value,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetForceCompileOnly(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarMode(int _arg)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
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
//  Wrapping of int vtkMapper::GetScalarMode()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetScalarMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetScalarMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScalarMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarModeToDefault()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarModeToDefault::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarModeToDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToDefault();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarModeToUsePointData()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarModeToUsePointData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarModeToUsePointData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToUsePointData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarModeToUseCellData()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarModeToUseCellData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarModeToUseCellData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToUseCellData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarModeToUsePointFieldData()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarModeToUsePointFieldData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarModeToUsePointFieldData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToUsePointFieldData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarModeToUseCellFieldData()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarModeToUseCellFieldData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarModeToUseCellFieldData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToUseCellFieldData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarModeToUseFieldData()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarModeToUseFieldData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarModeToUseFieldData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarModeToUseFieldData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SelectColorArray(int arrayNum)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SelectColorArray_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'arrayNum'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SelectColorArray_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int arrayNum;
  if (!get_val_param<int >(arrayNum,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SelectColorArray(arrayNum);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMapper::SelectColorArray(...)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SelectColorArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SelectColorArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMapper::wrap_SelectColorArray_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMapper::wrap_SelectColorArray_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SelectColorArray(char const * arrayName)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SelectColorArray_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'arrayName'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SelectColorArray_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > arrayName_string;
  if (!get_val_smtptr_param<std::string >(arrayName_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * arrayName = arrayName_string->c_str();

  this->_objectptr->GetObj()->SelectColorArray(arrayName);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::ColorByArrayComponent(int arrayNum, int component)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_ColorByArrayComponent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'arrayNum'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'component'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_ColorByArrayComponent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int arrayNum;
  if (!get_val_param<int >(arrayNum,_p,_n,true,true)) ClassReturnEmptyVar;

  int component;
  if (!get_val_param<int >(component,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ColorByArrayComponent(arrayNum, component);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMapper::ColorByArrayComponent(...)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_ColorByArrayComponent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_ColorByArrayComponent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMapper::wrap_ColorByArrayComponent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMapper::wrap_ColorByArrayComponent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::ColorByArrayComponent(char const * arrayName, int component)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_ColorByArrayComponent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'arrayName'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'component'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_ColorByArrayComponent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > arrayName_string;
  if (!get_val_smtptr_param<std::string >(arrayName_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * arrayName = arrayName_string->c_str();

  int component;
  if (!get_val_param<int >(component,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ColorByArrayComponent(arrayName, component);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char * vtkMapper::GetArrayName()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetArrayName::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetArrayName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char * res =   this->_objectptr->GetObj()->GetArrayName();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetArrayId()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetArrayId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetArrayId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetArrayId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetArrayAccessMode()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetArrayAccessMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetArrayAccessMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetArrayAccessMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetArrayComponent()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetArrayComponent::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetArrayComponent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetArrayComponent();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of char const * vtkMapper::GetScalarModeAsString()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetScalarModeAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetScalarModeAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetScalarModeAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of double * vtkMapper::GetBounds()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetBounds_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetBounds_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetBounds();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkMapper::GetBounds(...)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetBounds::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkMapper::wrap_GetBounds_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkMapper::wrap_GetBounds_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::GetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetBounds_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
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
//  Wrapping of void vtkMapper::SetRenderTime(double time)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetRenderTime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'time'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetRenderTime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double time;
  if (!get_val_param<double >(time,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRenderTime(time);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkMapper::GetRenderTime()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetRenderTime::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetRenderTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetRenderTime();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkDataSet * vtkMapper::GetInput()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataSet * res =   this->_objectptr->GetObj()->GetInput();
  BasicVariable::ptr res_var = AMILabType<vtkDataSet >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkDataSet * vtkMapper::GetInputAsDataSet()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetInputAsDataSet::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetInputAsDataSet::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataSet * res =   this->_objectptr->GetObj()->GetInputAsDataSet();
  BasicVariable::ptr res_var = AMILabType<vtkDataSet >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkUnsignedCharArray * vtkMapper::MapScalars(double alpha)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_MapScalars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'alpha'")
  return_comments="returning a variable of type vtkUnsignedCharArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_MapScalars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double alpha;
  if (!get_val_param<double >(alpha,_p,_n,true,false)) ClassHelpAndReturn;

  vtkUnsignedCharArray * res =   this->_objectptr->GetObj()->MapScalars(alpha);
  BasicVariable::ptr res_var = AMILabType<vtkUnsignedCharArray >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarMaterialMode(int _arg)
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarMaterialMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarMaterialMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarMaterialMode(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkMapper::GetScalarMaterialMode()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetScalarMaterialMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetScalarMaterialMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScalarMaterialMode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarMaterialModeToDefault()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarMaterialModeToDefault::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarMaterialModeToDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarMaterialModeToDefault();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarMaterialModeToAmbient()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarMaterialModeToAmbient::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarMaterialModeToAmbient::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarMaterialModeToAmbient();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarMaterialModeToDiffuse()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarMaterialModeToDiffuse::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarMaterialModeToDiffuse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarMaterialModeToDiffuse();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkMapper::SetScalarMaterialModeToAmbientAndDiffuse()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_SetScalarMaterialModeToAmbientAndDiffuse::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_SetScalarMaterialModeToAmbientAndDiffuse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarMaterialModeToAmbientAndDiffuse();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char const * vtkMapper::GetScalarMaterialModeAsString()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetScalarMaterialModeAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetScalarMaterialModeAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetScalarMaterialModeAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of bool vtkMapper::GetSupportsSelection()
//---------------------------------------------------
void WrapClass_vtkMapper::
    wrap_GetSupportsSelection::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkMapper::
    wrap_GetSupportsSelection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetSupportsSelection();
  return AMILabType<bool >::CreateVar(res);
}

