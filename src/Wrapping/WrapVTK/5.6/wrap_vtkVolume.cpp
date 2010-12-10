/**
 * C++ Interface: wrap_vtkVolume
 *
 * Description: wrapping vtkVolume
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
#include "wrap_vtkVolume.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkAbstractVolumeMapper.h"
#include "wrap_vtkVolumeProperty.h"
#include "wrap_vtkPropCollection.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkProp.h"
#include "wrap_vtkViewport.h"
#include "wrap_vtkWindow.h"
#include "wrap_vtkRenderer.h"


#include "wrap_vtkVolume.h"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVolume>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkVolume);
AMI_DEFINE_VARFROMSMTPTR(vtkVolume);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkVolume>::CreateVar( vtkVolume* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkVolume> obj_ptr(val,smartpointer_nodeleter<vtkVolume>());
  return AMILabType<vtkVolume>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolume
//
Variable<AMIObject>::ptr WrapClass_vtkVolume::CreateVar( vtkVolume* sp)
{
  boost::shared_ptr<vtkVolume> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolume>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolume>::CreateVar(
      new WrapClass_vtkVolume(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolume::AddMethods(WrapClass<vtkVolume>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_SetMapper( this_ptr);
  AddVar_GetMapper( this_ptr);
  AddVar_SetProperty( this_ptr);
  AddVar_GetProperty( this_ptr);
  AddVar_GetVolumes( this_ptr);
  AddVar_Update( this_ptr);
  AddVar_GetBounds_1( this_ptr);
  AddVar_GetBounds( this_ptr);
  AddVar_GetBounds_2( this_ptr);
  AddVar_GetMinXBound( this_ptr);
  AddVar_GetMaxXBound( this_ptr);
  AddVar_GetMinYBound( this_ptr);
  AddVar_GetMaxYBound( this_ptr);
  AddVar_GetMinZBound( this_ptr);
  AddVar_GetMaxZBound( this_ptr);
  AddVar_GetMTime( this_ptr);
  AddVar_GetRedrawMTime( this_ptr);
  AddVar_ShallowCopy( this_ptr);
  AddVar_RenderVolumetricGeometry( this_ptr);
  AddVar_ReleaseGraphicsResources( this_ptr);
  AddVar_GetCorrectedScalarOpacityArray_1( this_ptr);
  AddVar_GetCorrectedScalarOpacityArray( this_ptr);
  AddVar_GetCorrectedScalarOpacityArray_2( this_ptr);
  AddVar_GetScalarOpacityArray_1( this_ptr);
  AddVar_GetScalarOpacityArray( this_ptr);
  AddVar_GetScalarOpacityArray_2( this_ptr);
  AddVar_GetGradientOpacityArray_1( this_ptr);
  AddVar_GetGradientOpacityArray( this_ptr);
  AddVar_GetGradientOpacityArray_2( this_ptr);
  AddVar_GetGrayArray_1( this_ptr);
  AddVar_GetGrayArray( this_ptr);
  AddVar_GetGrayArray_2( this_ptr);
  AddVar_GetRGBArray_1( this_ptr);
  AddVar_GetRGBArray( this_ptr);
  AddVar_GetRGBArray_2( this_ptr);
  AddVar_GetGradientOpacityConstant_1( this_ptr);
  AddVar_GetGradientOpacityConstant( this_ptr);
  AddVar_GetGradientOpacityConstant_2( this_ptr);
  AddVar_GetArraySize( this_ptr);
  AddVar_UpdateTransferFunctions( this_ptr);
  AddVar_UpdateScalarOpacityforSampleSize( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkProp3D
  boost::shared_ptr<vtkProp3D > parent_vtkProp3D(  boost::dynamic_pointer_cast<vtkProp3D >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkProp3D = AMILabType<vtkProp3D >::CreateVarFromSmtPtr(parent_vtkProp3D);
  context->AddVar("vtkProp3D",var_vtkProp3D);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkProp3D = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkProp3D);
  context->AddDefault(obj_vtkProp3D->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkVolume::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolume");
  
  // Static methods 
  WrapClass_vtkVolume::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkVolume::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkVolume::AddVar_New(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkVolume::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkVolume::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkVolume * vtkVolume::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkVolume";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
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

  vtkVolume * res =   vtkVolume::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkVolume::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkVolume * vtkVolume::New()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolume";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolume * res =   vtkVolume::New();
  BasicVariable::ptr res_var = WrapClass_vtkVolume::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolume::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
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
//  Wrapping of vtkVolume * vtkVolume::NewInstance()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolume";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolume * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkVolume::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkVolume::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
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
//  Wrapping of void vtkVolume::SetMapper(vtkAbstractVolumeMapper * mapper)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_SetMapper::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractVolumeMapper, "parameter named 'mapper'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_SetMapper::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkAbstractVolumeMapper* mapper;
  if (CheckNullVar(_p,_n))  {
    mapper=(vtkAbstractVolumeMapper*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractVolumeMapper > mapper_smtptr;
    if (!get_val_smtptr_param<vtkAbstractVolumeMapper >(mapper_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    mapper = mapper_smtptr.get();
  }

  this->_objectptr->GetObj()->SetMapper(mapper);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkAbstractVolumeMapper * vtkVolume::GetMapper()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetMapper::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractVolumeMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetMapper::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractVolumeMapper * res =   this->_objectptr->GetObj()->GetMapper();
  BasicVariable::ptr res_var = WrapClass_vtkAbstractVolumeMapper::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkVolume::SetProperty(vtkVolumeProperty * property)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_SetProperty::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeProperty, "parameter named 'property'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_SetProperty::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkVolumeProperty* property;
  if (CheckNullVar(_p,_n))  {
    property=(vtkVolumeProperty*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolumeProperty > property_smtptr;
    if (!get_val_smtptr_param<vtkVolumeProperty >(property_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    property = property_smtptr.get();
  }

  this->_objectptr->GetObj()->SetProperty(property);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkVolumeProperty * vtkVolume::GetProperty()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeProperty * res =   this->_objectptr->GetObj()->GetProperty();
  BasicVariable::ptr res_var = WrapClass_vtkVolumeProperty::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkVolume::GetVolumes(vtkPropCollection * vc)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetVolumes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPropCollection, "parameter named 'vc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetVolumes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkPropCollection* vc;
  if (CheckNullVar(_p,_n))  {
    vc=(vtkPropCollection*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPropCollection > vc_smtptr;
    if (!get_val_smtptr_param<vtkPropCollection >(vc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    vc = vc_smtptr.get();
  }

  this->_objectptr->GetObj()->GetVolumes(vc);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolume::Update()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_Update::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_Update::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Update();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkVolume::GetBounds()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetBounds_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetBounds_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetBounds();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolume::GetBounds(...)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetBounds::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolume::wrap_GetBounds_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolume::wrap_GetBounds_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkVolume::GetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetBounds_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
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
//  Wrapping of double vtkVolume::GetMinXBound()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetMinXBound::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetMinXBound::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMinXBound();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolume::GetMaxXBound()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetMaxXBound::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetMaxXBound::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMaxXBound();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolume::GetMinYBound()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetMinYBound::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetMinYBound::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMinYBound();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolume::GetMaxYBound()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetMaxYBound::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetMaxYBound::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMaxYBound();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolume::GetMinZBound()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetMinZBound::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetMinZBound::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMinZBound();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVolume::GetMaxZBound()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetMaxZBound::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetMaxZBound::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetMaxZBound();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkVolume::GetMTime()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkVolume::GetRedrawMTime()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetRedrawMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetRedrawMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetRedrawMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkVolume::ShallowCopy(vtkProp * prop)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'prop'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
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
//  Wrapping of int vtkVolume::RenderVolumetricGeometry(vtkViewport * viewport)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_RenderVolumetricGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'viewport'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_RenderVolumetricGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkViewport* viewport;
  if (CheckNullVar(_p,_n))  {
    viewport=(vtkViewport*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkViewport > viewport_smtptr;
    if (!get_val_smtptr_param<vtkViewport >(viewport_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    viewport = viewport_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->RenderVolumetricGeometry(viewport);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolume::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
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
//  Wrapping of float * vtkVolume::GetCorrectedScalarOpacityArray(int param0)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetCorrectedScalarOpacityArray_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetCorrectedScalarOpacityArray_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetCorrectedScalarOpacityArray(param0);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolume::GetCorrectedScalarOpacityArray(...)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetCorrectedScalarOpacityArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetCorrectedScalarOpacityArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolume::wrap_GetCorrectedScalarOpacityArray_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolume::wrap_GetCorrectedScalarOpacityArray_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float * vtkVolume::GetCorrectedScalarOpacityArray()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetCorrectedScalarOpacityArray_2::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetCorrectedScalarOpacityArray_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetCorrectedScalarOpacityArray();
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float * vtkVolume::GetScalarOpacityArray(int param0)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetScalarOpacityArray_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetScalarOpacityArray_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetScalarOpacityArray(param0);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolume::GetScalarOpacityArray(...)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetScalarOpacityArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetScalarOpacityArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolume::wrap_GetScalarOpacityArray_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolume::wrap_GetScalarOpacityArray_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float * vtkVolume::GetScalarOpacityArray()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetScalarOpacityArray_2::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetScalarOpacityArray_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetScalarOpacityArray();
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float * vtkVolume::GetGradientOpacityArray(int param0)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetGradientOpacityArray_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetGradientOpacityArray_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetGradientOpacityArray(param0);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolume::GetGradientOpacityArray(...)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetGradientOpacityArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetGradientOpacityArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolume::wrap_GetGradientOpacityArray_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolume::wrap_GetGradientOpacityArray_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float * vtkVolume::GetGradientOpacityArray()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetGradientOpacityArray_2::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetGradientOpacityArray_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetGradientOpacityArray();
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float * vtkVolume::GetGrayArray(int param0)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetGrayArray_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetGrayArray_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetGrayArray(param0);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolume::GetGrayArray(...)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetGrayArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetGrayArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolume::wrap_GetGrayArray_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolume::wrap_GetGrayArray_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float * vtkVolume::GetGrayArray()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetGrayArray_2::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetGrayArray_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetGrayArray();
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float * vtkVolume::GetRGBArray(int param0)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetRGBArray_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetRGBArray_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetRGBArray(param0);
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolume::GetRGBArray(...)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetRGBArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetRGBArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolume::wrap_GetRGBArray_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolume::wrap_GetRGBArray_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float * vtkVolume::GetRGBArray()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetRGBArray_2::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetRGBArray_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float * res =   this->_objectptr->GetObj()->GetRGBArray();
  return AMILabType<float >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of float vtkVolume::GetGradientOpacityConstant(int param0)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetGradientOpacityConstant_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetGradientOpacityConstant_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientOpacityConstant(param0);
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolume::GetGradientOpacityConstant(...)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetGradientOpacityConstant::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetGradientOpacityConstant::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolume::wrap_GetGradientOpacityConstant_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolume::wrap_GetGradientOpacityConstant_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of float vtkVolume::GetGradientOpacityConstant()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetGradientOpacityConstant_2::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetGradientOpacityConstant_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  float res =   this->_objectptr->GetObj()->GetGradientOpacityConstant();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkVolume::GetArraySize()
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_GetArraySize::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_GetArraySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetArraySize();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkVolume::UpdateTransferFunctions(vtkRenderer * ren)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_UpdateTransferFunctions::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_UpdateTransferFunctions::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* ren;
  if (CheckNullVar(_p,_n))  {
    ren=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > ren_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ren = ren_smtptr.get();
  }

  this->_objectptr->GetObj()->UpdateTransferFunctions(ren);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkVolume::UpdateScalarOpacityforSampleSize(vtkRenderer * ren, float sample_distance)
//---------------------------------------------------
void WrapClass_vtkVolume::
    wrap_UpdateScalarOpacityforSampleSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'sample_distance'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolume::
    wrap_UpdateScalarOpacityforSampleSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* ren;
  if (CheckNullVar(_p,_n))  {
    ren=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > ren_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ren = ren_smtptr.get();
  }

  float sample_distance;
  if (!get_val_param<float >(sample_distance,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateScalarOpacityforSampleSize(ren, sample_distance);
  return BasicVariable::ptr();
}

