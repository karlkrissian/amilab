/**
 * C++ Interface: wrap_vtkActor
 *
 * Description: wrapping vtkActor
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
#include "wrap_vtkActor.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkPropCollection.h"
#include "wrap_vtkViewport.h"
#include "wrap_vtkRenderer.h"
#include "wrap_vtkProp.h"
#include "wrap_vtkWindow.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkActor.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkActor>::CreateVar( ParamList* p)
{
  WrapClass_vtkActor::wrap_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkActor);
AMI_DEFINE_VARFROMSMTPTR(vtkActor);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkActor>::CreateVar( vtkActor* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkActor> obj_ptr(val,smartpointer_nodeleter<vtkActor>());
  return AMILabType<vtkActor>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkActor
//
Variable<AMIObject>::ptr WrapClass_vtkActor::CreateVar( vtkActor* sp)
{
  boost::shared_ptr<vtkActor> di_ptr(
    sp,
    wxwindow_nodeleter<vtkActor>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkActor>::CreateVar(
      new WrapClass_vtkActor(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkActor::AddMethods(WrapClass<vtkActor>::ptr this_ptr )
{
  
      // Add members from vtkProp3D
      WrapClass_vtkProp3D::ptr parent_vtkProp3D(        boost::dynamic_pointer_cast<WrapClass_vtkProp3D >(this_ptr));
      parent_vtkProp3D->AddMethods(parent_vtkProp3D);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_GetActors( this_ptr);
      AddVar_RenderOpaqueGeometry( this_ptr);
      AddVar_RenderTranslucentPolygonalGeometry( this_ptr);
      AddVar_HasTranslucentPolygonalGeometry( this_ptr);
/* The following types are missing: vtkMapper
      AddVar_Render( this_ptr);
*/
      AddVar_ShallowCopy( this_ptr);
      AddVar_ReleaseGraphicsResources( this_ptr);
/* The following types are missing: vtkProperty
      AddVar_SetProperty( this_ptr);
*/
/* The following types are missing: vtkProperty
      AddVar_GetProperty( this_ptr);
*/
/* The following types are missing: vtkProperty
      AddVar_MakeProperty( this_ptr);
*/
/* The following types are missing: vtkProperty
      AddVar_SetBackfaceProperty( this_ptr);
*/
/* The following types are missing: vtkProperty
      AddVar_GetBackfaceProperty( this_ptr);
*/
/* The following types are missing: vtkTexture
      AddVar_SetTexture( this_ptr);
*/
/* The following types are missing: vtkTexture
      AddVar_GetTexture( this_ptr);
*/
/* The following types are missing: vtkMapper
      AddVar_SetMapper( this_ptr);
*/
/* The following types are missing: vtkMapper
      AddVar_GetMapper( this_ptr);
*/
      AddVar_GetBounds_1( this_ptr);
      AddVar_GetBounds( this_ptr);
      AddVar_GetBounds_2( this_ptr);
      AddVar_ApplyProperties( this_ptr);
      AddVar_GetMTime( this_ptr);
      AddVar_GetRedrawMTime( this_ptr);
      AddVar_InitPartTraversal( this_ptr);
      AddVar_GetNextPart( this_ptr);
      AddVar_GetNumberOfParts( this_ptr);
      AddVar_GetSupportsSelection( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkActor::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkActor::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkActor * vtkActor::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkActor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkActor * res =   vtkActor::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkActor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkActor * vtkActor::New()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkActor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActor * res =   vtkActor::New();
  BasicVariable::ptr res_var = WrapClass_vtkActor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkActor::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
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
//  Wrapping of vtkActor * vtkActor::NewInstance()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkActor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActor * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkActor::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkActor::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
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
//  Wrapping of void vtkActor::GetActors(vtkPropCollection * param0)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetActors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPropCollection, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetActors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkPropCollection > param0_smtptr;
  if (!get_val_smtptr_param<vtkPropCollection >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkPropCollection* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->GetActors(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkActor::RenderOpaqueGeometry(vtkViewport * viewport)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_RenderOpaqueGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'viewport'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_RenderOpaqueGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > viewport_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(viewport_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* viewport = viewport_smtptr.get();

  int res =   this->_objectptr->GetObj()->RenderOpaqueGeometry(viewport);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkActor::RenderTranslucentPolygonalGeometry(vtkViewport * viewport)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_RenderTranslucentPolygonalGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'viewport'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_RenderTranslucentPolygonalGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > viewport_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(viewport_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* viewport = viewport_smtptr.get();

  int res =   this->_objectptr->GetObj()->RenderTranslucentPolygonalGeometry(viewport);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkActor::HasTranslucentPolygonalGeometry()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_HasTranslucentPolygonalGeometry::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_HasTranslucentPolygonalGeometry::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->HasTranslucentPolygonalGeometry();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkMapper

//---------------------------------------------------
//  Wrapping of void vtkActor::Render(vtkRenderer * param0, vtkMapper * param1)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_Render::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( vtkMapper, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_Render::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  boost::shared_ptr<vtkMapper > param1_smtptr;
  if (!get_val_smtptr_param<vtkMapper >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkMapper* param1 = param1_smtptr.get();

  this->_objectptr->GetObj()->Render(param0, param1);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkActor::ShallowCopy(vtkProp * prop)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'prop'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > prop_smtptr;
  if (!get_val_smtptr_param<vtkProp >(prop_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp* prop = prop_smtptr.get();

  this->_objectptr->GetObj()->ShallowCopy(prop);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkActor::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_ReleaseGraphicsResources::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkWindow > param0_smtptr;
  if (!get_val_smtptr_param<vtkWindow >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkWindow* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->ReleaseGraphicsResources(param0);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkProperty

//---------------------------------------------------
//  Wrapping of void vtkActor::SetProperty(vtkProperty * lut)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_SetProperty::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProperty, "parameter named 'lut'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_SetProperty::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProperty > lut_smtptr;
  if (!get_val_smtptr_param<vtkProperty >(lut_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProperty* lut = lut_smtptr.get();

  this->_objectptr->GetObj()->SetProperty(lut);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkProperty

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkActor::GetProperty()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->GetProperty();
  return AMILabType<vtkProperty >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkProperty

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkActor::MakeProperty()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_MakeProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_MakeProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->MakeProperty();
  return AMILabType<vtkProperty >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkProperty

//---------------------------------------------------
//  Wrapping of void vtkActor::SetBackfaceProperty(vtkProperty * lut)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_SetBackfaceProperty::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProperty, "parameter named 'lut'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_SetBackfaceProperty::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProperty > lut_smtptr;
  if (!get_val_smtptr_param<vtkProperty >(lut_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProperty* lut = lut_smtptr.get();

  this->_objectptr->GetObj()->SetBackfaceProperty(lut);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkProperty

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkActor::GetBackfaceProperty()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetBackfaceProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetBackfaceProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->GetBackfaceProperty();
  return AMILabType<vtkProperty >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkTexture

//---------------------------------------------------
//  Wrapping of void vtkActor::SetTexture(vtkTexture * param0)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_SetTexture::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTexture, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_SetTexture::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkTexture > param0_smtptr;
  if (!get_val_smtptr_param<vtkTexture >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkTexture* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetTexture(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkTexture

//---------------------------------------------------
//  Wrapping of vtkTexture * vtkActor::GetTexture()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetTexture::SetParametersComments()
{
  return_comments="returning a variable of type vtkTexture";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetTexture::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTexture * res =   this->_objectptr->GetObj()->GetTexture();
  return AMILabType<vtkTexture >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkMapper

//---------------------------------------------------
//  Wrapping of void vtkActor::SetMapper(vtkMapper * param0)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_SetMapper::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMapper, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_SetMapper::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkMapper > param0_smtptr;
  if (!get_val_smtptr_param<vtkMapper >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkMapper* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetMapper(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkMapper

//---------------------------------------------------
//  Wrapping of vtkMapper * vtkActor::GetMapper()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetMapper::SetParametersComments()
{
  return_comments="returning a variable of type vtkMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetMapper::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMapper * res =   this->_objectptr->GetObj()->GetMapper();
  return AMILabType<vtkMapper >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkActor::GetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetBounds_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetBounds_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > bounds_smtptr;
  if (!get_val_smtptr_param<double >(bounds_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* bounds = bounds_smtptr.get();

  this->_objectptr->GetObj()->GetBounds(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkActor::GetBounds(...)
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetBounds::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkActor::wrap_GetBounds_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkActor::wrap_GetBounds_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double * vtkActor::GetBounds()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetBounds_2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetBounds_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetBounds();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkActor::ApplyProperties()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_ApplyProperties::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_ApplyProperties::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ApplyProperties();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkActor::GetMTime()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkActor::GetRedrawMTime()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetRedrawMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetRedrawMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetRedrawMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkActor::InitPartTraversal()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_InitPartTraversal::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_InitPartTraversal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InitPartTraversal();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkActor * vtkActor::GetNextPart()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetNextPart::SetParametersComments()
{
  return_comments="returning a variable of type vtkActor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetNextPart::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActor * res =   this->_objectptr->GetObj()->GetNextPart();
  BasicVariable::ptr res_var = WrapClass_vtkActor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkActor::GetNumberOfParts()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetNumberOfParts::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetNumberOfParts::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfParts();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool vtkActor::GetSupportsSelection()
//---------------------------------------------------
void WrapClass_vtkActor::
    wrap_GetSupportsSelection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActor::
    wrap_GetSupportsSelection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetSupportsSelection();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

