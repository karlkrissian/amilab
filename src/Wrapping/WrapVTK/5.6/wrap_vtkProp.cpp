/**
 * C++ Interface: wrap_vtkProp
 *
 * Description: wrapping vtkProp
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
#include "wrap_vtkProp.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkPropCollection.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkViewport.h"
#include "wrap_vtkWindow.h"
#include "wrap_vtkObject.h"


#include "wrap_vtkProp.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkProp>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkProp);
AMI_DEFINE_VARFROMSMTPTR(vtkProp);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkProp>::CreateVar( vtkProp* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkProp> obj_ptr(val,smartpointer_nodeleter<vtkProp>());
  return AMILabType<vtkProp>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkProp
//
Variable<AMIObject>::ptr WrapClass_vtkProp::CreateVar( vtkProp* sp)
{
  boost::shared_ptr<vtkProp> di_ptr(
    sp,
    wxwindow_nodeleter<vtkProp>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkProp>::CreateVar(
      new WrapClass_vtkProp(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkProp::AddMethods(WrapClass<vtkProp>::ptr this_ptr )
{
  
      // Add members from vtkObject
      WrapClass_vtkObject::ptr parent_vtkObject(        boost::dynamic_pointer_cast<WrapClass_vtkObject >(this_ptr));
      parent_vtkObject->AddMethods(parent_vtkObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_GetActors( this_ptr);
      AddVar_GetActors2D( this_ptr);
      AddVar_GetVolumes( this_ptr);
      AddVar_SetVisibility( this_ptr);
      AddVar_GetVisibility( this_ptr);
      AddVar_VisibilityOn( this_ptr);
      AddVar_VisibilityOff( this_ptr);
      AddVar_SetPickable( this_ptr);
      AddVar_GetPickable( this_ptr);
      AddVar_PickableOn( this_ptr);
      AddVar_PickableOff( this_ptr);
      AddVar_Pick( this_ptr);
      AddVar_SetDragable( this_ptr);
      AddVar_GetDragable( this_ptr);
      AddVar_DragableOn( this_ptr);
      AddVar_DragableOff( this_ptr);
      AddVar_GetRedrawMTime( this_ptr);
      AddVar_SetUseBounds( this_ptr);
      AddVar_GetUseBounds( this_ptr);
      AddVar_UseBoundsOn( this_ptr);
      AddVar_UseBoundsOff( this_ptr);
      AddVar_GetBounds( this_ptr);
      AddVar_ShallowCopy( this_ptr);
      AddVar_InitPathTraversal( this_ptr);
/* The following types are missing: vtkAssemblyPath
      AddVar_GetNextPath( this_ptr);
*/
      AddVar_GetNumberOfPaths( this_ptr);
/* The following types are missing: vtkMatrix4x4
      AddVar_PokeMatrix( this_ptr);
*/
/* The following types are missing: vtkMatrix4x4
      AddVar_GetMatrix( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_GetPropertyKeys( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_SetPropertyKeys( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_HasKeys( this_ptr);
*/
      AddVar_RenderOpaqueGeometry( this_ptr);
      AddVar_RenderTranslucentPolygonalGeometry( this_ptr);
      AddVar_RenderVolumetricGeometry( this_ptr);
      AddVar_RenderOverlay( this_ptr);
/* The following types are missing: vtkInformation
      AddVar_RenderFilteredOpaqueGeometry( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_RenderFilteredTranslucentPolygonalGeometry( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_RenderFilteredVolumetricGeometry( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_RenderFilteredOverlay( this_ptr);
*/
      AddVar_HasTranslucentPolygonalGeometry( this_ptr);
      AddVar_ReleaseGraphicsResources( this_ptr);
      AddVar_GetEstimatedRenderTime_1( this_ptr);
      AddVar_GetEstimatedRenderTime( this_ptr);
      AddVar_GetEstimatedRenderTime_2( this_ptr);
      AddVar_SetEstimatedRenderTime( this_ptr);
      AddVar_RestoreEstimatedRenderTime( this_ptr);
      AddVar_AddEstimatedRenderTime( this_ptr);
      AddVar_SetAllocatedRenderTime( this_ptr);
      AddVar_GetAllocatedRenderTime( this_ptr);
      AddVar_SetRenderTimeMultiplier( this_ptr);
      AddVar_GetRenderTimeMultiplier( this_ptr);
/* The following types are missing: vtkAssemblyPaths, vtkAssemblyPath
      AddVar_BuildPaths( this_ptr);
*/
      AddVar_GetSupportsSelection( this_ptr);
      AddVar_GetNumberOfConsumers( this_ptr);
      AddVar_AddConsumer( this_ptr);
      AddVar_RemoveConsumer( this_ptr);
      AddVar_GetConsumer( this_ptr);
      AddVar_IsConsumer( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkProp::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkProp::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkProp * vtkProp::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkProp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkProp * res =   vtkProp::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkProp::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkProp::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
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
//  Wrapping of vtkProp * vtkProp::NewInstance()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkProp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProp * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkProp::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkProp::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
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
//  Wrapping of void vtkProp::GetActors(vtkPropCollection * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetActors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPropCollection, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
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
//  Wrapping of void vtkProp::GetActors2D(vtkPropCollection * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetActors2D::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPropCollection, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetActors2D::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkPropCollection > param0_smtptr;
  if (!get_val_smtptr_param<vtkPropCollection >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkPropCollection* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->GetActors2D(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::GetVolumes(vtkPropCollection * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetVolumes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPropCollection, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetVolumes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkPropCollection > param0_smtptr;
  if (!get_val_smtptr_param<vtkPropCollection >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkPropCollection* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->GetVolumes(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::SetVisibility(int _arg)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_SetVisibility::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_SetVisibility::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetVisibility(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProp::GetVisibility()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetVisibility::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetVisibility::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetVisibility();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::VisibilityOn()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_VisibilityOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_VisibilityOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->VisibilityOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::VisibilityOff()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_VisibilityOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_VisibilityOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->VisibilityOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::SetPickable(int _arg)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_SetPickable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_SetPickable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPickable(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProp::GetPickable()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetPickable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetPickable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPickable();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::PickableOn()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_PickableOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_PickableOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PickableOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::PickableOff()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_PickableOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_PickableOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PickableOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::Pick()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_Pick::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_Pick::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Pick();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::SetDragable(int _arg)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_SetDragable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_SetDragable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDragable(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkProp::GetDragable()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetDragable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetDragable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDragable();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::DragableOn()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_DragableOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_DragableOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DragableOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::DragableOff()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_DragableOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_DragableOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DragableOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkProp::GetRedrawMTime()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetRedrawMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetRedrawMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetRedrawMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::SetUseBounds(bool _arg)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_SetUseBounds::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_SetUseBounds::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg_int;
  if (!get_val_param<int >(_arg_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool _arg = (bool) (_arg_int>0.5);

  this->_objectptr->GetObj()->SetUseBounds(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool vtkProp::GetUseBounds()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetUseBounds::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetUseBounds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetUseBounds();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::UseBoundsOn()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_UseBoundsOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_UseBoundsOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseBoundsOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::UseBoundsOff()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_UseBoundsOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_UseBoundsOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseBoundsOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkProp::GetBounds()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetBounds::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetBounds();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::ShallowCopy(vtkProp * prop)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'prop'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
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
//  Wrapping of void vtkProp::InitPathTraversal()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_InitPathTraversal::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_InitPathTraversal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InitPathTraversal();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkAssemblyPath

//---------------------------------------------------
//  Wrapping of vtkAssemblyPath * vtkProp::GetNextPath()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetNextPath::SetParametersComments()
{
  return_comments="returning a variable of type vtkAssemblyPath";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetNextPath::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAssemblyPath * res =   this->_objectptr->GetObj()->GetNextPath();
  return AMILabType<vtkAssemblyPath >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkProp::GetNumberOfPaths()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetNumberOfPaths::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetNumberOfPaths::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfPaths();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of void vtkProp::PokeMatrix(vtkMatrix4x4 * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_PokeMatrix::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkMatrix4x4, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_PokeMatrix::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkMatrix4x4 > param0_smtptr;
  if (!get_val_smtptr_param<vtkMatrix4x4 >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkMatrix4x4* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->PokeMatrix(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkMatrix4x4

//---------------------------------------------------
//  Wrapping of vtkMatrix4x4 * vtkProp::GetMatrix()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetMatrix::SetParametersComments()
{
  return_comments="returning a variable of type vtkMatrix4x4";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetMatrix::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkMatrix4x4 * res =   this->_objectptr->GetObj()->GetMatrix();
  return AMILabType<vtkMatrix4x4 >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkInformation * vtkProp::GetPropertyKeys()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetPropertyKeys::SetParametersComments()
{
  return_comments="returning a variable of type vtkInformation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetPropertyKeys::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInformation * res =   this->_objectptr->GetObj()->GetPropertyKeys();
  return AMILabType<vtkInformation >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkProp::SetPropertyKeys(vtkInformation * keys)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_SetPropertyKeys::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'keys'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_SetPropertyKeys::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > keys_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(keys_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* keys = keys_smtptr.get();

  this->_objectptr->GetObj()->SetPropertyKeys(keys);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of bool vtkProp::HasKeys(vtkInformation * requiredKeys)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_HasKeys::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'requiredKeys'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_HasKeys::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > requiredKeys_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(requiredKeys_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* requiredKeys = requiredKeys_smtptr.get();

  bool res =   this->_objectptr->GetObj()->HasKeys(requiredKeys);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkProp::RenderOpaqueGeometry(vtkViewport * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RenderOpaqueGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RenderOpaqueGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > param0_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* param0 = param0_smtptr.get();

  int res =   this->_objectptr->GetObj()->RenderOpaqueGeometry(param0);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProp::RenderTranslucentPolygonalGeometry(vtkViewport * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RenderTranslucentPolygonalGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RenderTranslucentPolygonalGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > param0_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* param0 = param0_smtptr.get();

  int res =   this->_objectptr->GetObj()->RenderTranslucentPolygonalGeometry(param0);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProp::RenderVolumetricGeometry(vtkViewport * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RenderVolumetricGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RenderVolumetricGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > param0_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* param0 = param0_smtptr.get();

  int res =   this->_objectptr->GetObj()->RenderVolumetricGeometry(param0);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkProp::RenderOverlay(vtkViewport * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RenderOverlay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RenderOverlay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > param0_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* param0 = param0_smtptr.get();

  int res =   this->_objectptr->GetObj()->RenderOverlay(param0);
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of bool vtkProp::RenderFilteredOpaqueGeometry(vtkViewport * v, vtkInformation * requiredKeys)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RenderFilteredOpaqueGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'requiredKeys'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RenderFilteredOpaqueGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > v_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* v = v_smtptr.get();

  boost::shared_ptr<vtkInformation > requiredKeys_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(requiredKeys_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* requiredKeys = requiredKeys_smtptr.get();

  bool res =   this->_objectptr->GetObj()->RenderFilteredOpaqueGeometry(v, requiredKeys);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of bool vtkProp::RenderFilteredTranslucentPolygonalGeometry(vtkViewport * v, vtkInformation * requiredKeys)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RenderFilteredTranslucentPolygonalGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'requiredKeys'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RenderFilteredTranslucentPolygonalGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > v_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* v = v_smtptr.get();

  boost::shared_ptr<vtkInformation > requiredKeys_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(requiredKeys_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* requiredKeys = requiredKeys_smtptr.get();

  bool res =   this->_objectptr->GetObj()->RenderFilteredTranslucentPolygonalGeometry(v, requiredKeys);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of bool vtkProp::RenderFilteredVolumetricGeometry(vtkViewport * v, vtkInformation * requiredKeys)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RenderFilteredVolumetricGeometry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'requiredKeys'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RenderFilteredVolumetricGeometry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > v_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* v = v_smtptr.get();

  boost::shared_ptr<vtkInformation > requiredKeys_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(requiredKeys_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* requiredKeys = requiredKeys_smtptr.get();

  bool res =   this->_objectptr->GetObj()->RenderFilteredVolumetricGeometry(v, requiredKeys);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of bool vtkProp::RenderFilteredOverlay(vtkViewport * v, vtkInformation * requiredKeys)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RenderFilteredOverlay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'requiredKeys'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RenderFilteredOverlay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkViewport > v_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* v = v_smtptr.get();

  boost::shared_ptr<vtkInformation > requiredKeys_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(requiredKeys_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* requiredKeys = requiredKeys_smtptr.get();

  bool res =   this->_objectptr->GetObj()->RenderFilteredOverlay(v, requiredKeys);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkProp::HasTranslucentPolygonalGeometry()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_HasTranslucentPolygonalGeometry::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_HasTranslucentPolygonalGeometry::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->HasTranslucentPolygonalGeometry();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
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

//---------------------------------------------------
//  Wrapping of double vtkProp::GetEstimatedRenderTime(vtkViewport * param0)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetEstimatedRenderTime_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'param0'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetEstimatedRenderTime_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkViewport > param0_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkViewport* param0 = param0_smtptr.get();

  double res =   this->_objectptr->GetObj()->GetEstimatedRenderTime(param0);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkProp::GetEstimatedRenderTime(...)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetEstimatedRenderTime::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetEstimatedRenderTime::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkProp::wrap_GetEstimatedRenderTime_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkProp::wrap_GetEstimatedRenderTime_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double vtkProp::GetEstimatedRenderTime()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetEstimatedRenderTime_2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetEstimatedRenderTime_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double res =   this->_objectptr->GetObj()->GetEstimatedRenderTime();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::SetEstimatedRenderTime(double t)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_SetEstimatedRenderTime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 't'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_SetEstimatedRenderTime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double t;
  if (!get_val_param<double >(t,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEstimatedRenderTime(t);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::RestoreEstimatedRenderTime()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RestoreEstimatedRenderTime::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RestoreEstimatedRenderTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RestoreEstimatedRenderTime();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::AddEstimatedRenderTime(double t, vtkViewport * param1)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_AddEstimatedRenderTime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 't'")
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_AddEstimatedRenderTime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double t;
  if (!get_val_param<double >(t,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<vtkViewport > param1_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* param1 = param1_smtptr.get();

  this->_objectptr->GetObj()->AddEstimatedRenderTime(t, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::SetAllocatedRenderTime(double t, vtkViewport * param1)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_SetAllocatedRenderTime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 't'")
  ADDPARAMCOMMENT_TYPE( vtkViewport, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_SetAllocatedRenderTime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double t;
  if (!get_val_param<double >(t,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<vtkViewport > param1_smtptr;
  if (!get_val_smtptr_param<vtkViewport >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkViewport* param1 = param1_smtptr.get();

  this->_objectptr->GetObj()->SetAllocatedRenderTime(t, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkProp::GetAllocatedRenderTime()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetAllocatedRenderTime::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetAllocatedRenderTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetAllocatedRenderTime();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::SetRenderTimeMultiplier(double t)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_SetRenderTimeMultiplier::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 't'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_SetRenderTimeMultiplier::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double t;
  if (!get_val_param<double >(t,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRenderTimeMultiplier(t);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkProp::GetRenderTimeMultiplier()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetRenderTimeMultiplier::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetRenderTimeMultiplier::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetRenderTimeMultiplier();
  return AMILabType<double >::CreateVar(res);
}
/* The following types are missing: vtkAssemblyPaths, vtkAssemblyPath

//---------------------------------------------------
//  Wrapping of void vtkProp::BuildPaths(vtkAssemblyPaths * paths, vtkAssemblyPath * path)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_BuildPaths::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAssemblyPaths, "parameter named 'paths'")
  ADDPARAMCOMMENT_TYPE( vtkAssemblyPath, "parameter named 'path'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_BuildPaths::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkAssemblyPaths > paths_smtptr;
  if (!get_val_smtptr_param<vtkAssemblyPaths >(paths_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkAssemblyPaths* paths = paths_smtptr.get();

  boost::shared_ptr<vtkAssemblyPath > path_smtptr;
  if (!get_val_smtptr_param<vtkAssemblyPath >(path_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkAssemblyPath* path = path_smtptr.get();

  this->_objectptr->GetObj()->BuildPaths(paths, path);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of bool vtkProp::GetSupportsSelection()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetSupportsSelection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetSupportsSelection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetSupportsSelection();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int vtkProp::GetNumberOfConsumers()
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetNumberOfConsumers::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetNumberOfConsumers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfConsumers();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkProp::AddConsumer(vtkObject * c)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_AddConsumer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObject, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_AddConsumer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObject > c_smtptr;
  if (!get_val_smtptr_param<vtkObject >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObject* c = c_smtptr.get();

  this->_objectptr->GetObj()->AddConsumer(c);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkProp::RemoveConsumer(vtkObject * c)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_RemoveConsumer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObject, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_RemoveConsumer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObject > c_smtptr;
  if (!get_val_smtptr_param<vtkObject >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObject* c = c_smtptr.get();

  this->_objectptr->GetObj()->RemoveConsumer(c);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkObject * vtkProp::GetConsumer(int i)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_GetConsumer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  return_comments="returning a variable of type vtkObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_GetConsumer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  vtkObject * res =   this->_objectptr->GetObj()->GetConsumer(i);
  BasicVariable::ptr res_var = WrapClass_vtkObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkProp::IsConsumer(vtkObject * c)
//---------------------------------------------------
void WrapClass_vtkProp::
    wrap_IsConsumer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObject, "parameter named 'c'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkProp::
    wrap_IsConsumer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObject > c_smtptr;
  if (!get_val_smtptr_param<vtkObject >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObject* c = c_smtptr.get();

  int res =   this->_objectptr->GetObj()->IsConsumer(c);
  return AMILabType<int >::CreateVar(res);
}

