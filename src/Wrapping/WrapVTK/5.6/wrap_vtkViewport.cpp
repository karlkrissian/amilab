/**
 * C++ Interface: wrap_vtkViewport
 *
 * Description: wrapping vtkViewport
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
#include "wrap_vtkViewport.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkProp.h"
#include "wrap_vtkPropCollection.h"


#include "wrap_vtkViewport.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkViewport>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkViewport);
AMI_DEFINE_VARFROMSMTPTR(vtkViewport);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkViewport>::CreateVar( vtkViewport* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkViewport> obj_ptr(val,smartpointer_nodeleter<vtkViewport>());
  return AMILabType<vtkViewport>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkViewport
//
Variable<AMIObject>::ptr WrapClass_vtkViewport::CreateVar( vtkViewport* sp)
{
  boost::shared_ptr<vtkViewport> di_ptr(
    sp,
    wxwindow_nodeleter<vtkViewport>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkViewport>::CreateVar(
      new WrapClass_vtkViewport(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkViewport::AddMethods(WrapClass<vtkViewport>::ptr this_ptr )
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
      AddVar_AddViewProp( this_ptr);
      AddVar_GetViewProps( this_ptr);
      AddVar_HasViewProp( this_ptr);
      AddVar_RemoveViewProp( this_ptr);
      AddVar_RemoveAllViewProps( this_ptr);
      AddVar_AddActor2D( this_ptr);
      AddVar_RemoveActor2D( this_ptr);
/* The following types are missing: vtkActor2DCollection
      AddVar_GetActors2D( this_ptr);
*/
      AddVar_SetBackground_1( this_ptr);
      AddVar_SetBackground( this_ptr);
      AddVar_SetBackground_2( this_ptr);
      AddVar_GetBackground_1( this_ptr);
      AddVar_GetBackground( this_ptr);
      AddVar_GetBackground_2( this_ptr);
      AddVar_GetBackground_3( this_ptr);
      AddVar_SetBackground2_1( this_ptr);
      AddVar_SetBackground2( this_ptr);
      AddVar_SetBackground2_2( this_ptr);
      AddVar_GetBackground2_1( this_ptr);
      AddVar_GetBackground2( this_ptr);
      AddVar_GetBackground2_2( this_ptr);
      AddVar_GetBackground2_3( this_ptr);
      AddVar_SetGradientBackground( this_ptr);
      AddVar_GetGradientBackground( this_ptr);
      AddVar_GradientBackgroundOn( this_ptr);
      AddVar_GradientBackgroundOff( this_ptr);
      AddVar_SetAspect_1( this_ptr);
      AddVar_SetAspect( this_ptr);
      AddVar_SetAspect_2( this_ptr);
      AddVar_GetAspect_1( this_ptr);
      AddVar_GetAspect( this_ptr);
      AddVar_GetAspect_2( this_ptr);
      AddVar_ComputeAspect( this_ptr);
      AddVar_SetPixelAspect_1( this_ptr);
      AddVar_SetPixelAspect( this_ptr);
      AddVar_SetPixelAspect_2( this_ptr);
      AddVar_GetPixelAspect_1( this_ptr);
      AddVar_GetPixelAspect( this_ptr);
      AddVar_GetPixelAspect_2( this_ptr);
      AddVar_SetViewport_1( this_ptr);
      AddVar_SetViewport( this_ptr);
      AddVar_SetViewport_2( this_ptr);
      AddVar_GetViewport_1( this_ptr);
      AddVar_GetViewport( this_ptr);
      AddVar_GetViewport_2( this_ptr);
      AddVar_SetDisplayPoint_1( this_ptr);
      AddVar_SetDisplayPoint( this_ptr);
      AddVar_SetDisplayPoint_2( this_ptr);
      AddVar_GetDisplayPoint_1( this_ptr);
      AddVar_GetDisplayPoint( this_ptr);
      AddVar_GetDisplayPoint_2( this_ptr);
      AddVar_SetViewPoint_1( this_ptr);
      AddVar_SetViewPoint( this_ptr);
      AddVar_SetViewPoint_2( this_ptr);
      AddVar_GetViewPoint_1( this_ptr);
      AddVar_GetViewPoint( this_ptr);
      AddVar_GetViewPoint_2( this_ptr);
      AddVar_SetWorldPoint_1( this_ptr);
      AddVar_SetWorldPoint( this_ptr);
      AddVar_SetWorldPoint_2( this_ptr);
      AddVar_GetWorldPoint_1( this_ptr);
      AddVar_GetWorldPoint( this_ptr);
      AddVar_GetWorldPoint_2( this_ptr);
      AddVar_GetCenter( this_ptr);
      AddVar_IsInViewport( this_ptr);
      AddVar_DisplayToView( this_ptr);
      AddVar_ViewToDisplay( this_ptr);
      AddVar_WorldToView_1( this_ptr);
      AddVar_ViewToWorld_1( this_ptr);
      AddVar_DisplayToWorld( this_ptr);
      AddVar_WorldToDisplay( this_ptr);
      AddVar_LocalDisplayToDisplay( this_ptr);
      AddVar_DisplayToNormalizedDisplay( this_ptr);
      AddVar_NormalizedDisplayToViewport( this_ptr);
      AddVar_ViewportToNormalizedViewport( this_ptr);
      AddVar_NormalizedViewportToView( this_ptr);
      AddVar_ViewToWorld( this_ptr);
      AddVar_ViewToWorld_2( this_ptr);
      AddVar_DisplayToLocalDisplay( this_ptr);
      AddVar_NormalizedDisplayToDisplay( this_ptr);
      AddVar_ViewportToNormalizedDisplay( this_ptr);
      AddVar_NormalizedViewportToViewport( this_ptr);
      AddVar_ViewToNormalizedViewport( this_ptr);
      AddVar_WorldToView( this_ptr);
      AddVar_WorldToView_2( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_GetOrigin( this_ptr);
      AddVar_GetTiledSize( this_ptr);
      AddVar_GetTiledSizeAndOrigin( this_ptr);
/* The following types are missing: vtkAssemblyPath
      AddVar_PickPropFrom( this_ptr);
*/
      AddVar_GetPickX( this_ptr);
      AddVar_GetPickY( this_ptr);
      AddVar_GetPickWidth( this_ptr);
      AddVar_GetPickHeight( this_ptr);
      AddVar_GetPickX1( this_ptr);
      AddVar_GetPickY1( this_ptr);
      AddVar_GetPickX2( this_ptr);
      AddVar_GetPickY2( this_ptr);
      AddVar_GetIsPicking( this_ptr);
      AddVar_GetPickResultProps( this_ptr);
      AddVar_RemoveProp( this_ptr);
      AddVar_AddProp( this_ptr);
      AddVar_GetProps( this_ptr);
      AddVar_HasProp( this_ptr);
      AddVar_RemoveAllProps( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkViewport::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkViewport::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkViewport * vtkViewport::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkViewport";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkViewport * res =   vtkViewport::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkViewport::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkViewport::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
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
//  Wrapping of vtkViewport * vtkViewport::NewInstance()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkViewport";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkViewport * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkViewport::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkViewport::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
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
//  Wrapping of void vtkViewport::AddViewProp(vtkProp * param0)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_AddViewProp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_AddViewProp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > param0_smtptr;
  if (!get_val_smtptr_param<vtkProp >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->AddViewProp(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkPropCollection * vtkViewport::GetViewProps()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetViewProps::SetParametersComments()
{
  return_comments="returning a variable of type vtkPropCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetViewProps::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPropCollection * res =   this->_objectptr->GetObj()->GetViewProps();
  BasicVariable::ptr res_var = WrapClass_vtkPropCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkViewport::HasViewProp(vtkProp * param0)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_HasViewProp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_HasViewProp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > param0_smtptr;
  if (!get_val_smtptr_param<vtkProp >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp* param0 = param0_smtptr.get();

  int res =   this->_objectptr->GetObj()->HasViewProp(param0);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::RemoveViewProp(vtkProp * param0)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_RemoveViewProp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_RemoveViewProp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > param0_smtptr;
  if (!get_val_smtptr_param<vtkProp >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->RemoveViewProp(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::RemoveAllViewProps()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_RemoveAllViewProps::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_RemoveAllViewProps::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllViewProps();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::AddActor2D(vtkProp * p)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_AddActor2D::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_AddActor2D::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > p_smtptr;
  if (!get_val_smtptr_param<vtkProp >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp* p = p_smtptr.get();

  this->_objectptr->GetObj()->AddActor2D(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::RemoveActor2D(vtkProp * p)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_RemoveActor2D::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_RemoveActor2D::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > p_smtptr;
  if (!get_val_smtptr_param<vtkProp >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp* p = p_smtptr.get();

  this->_objectptr->GetObj()->RemoveActor2D(p);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkActor2DCollection

//---------------------------------------------------
//  Wrapping of vtkActor2DCollection * vtkViewport::GetActors2D()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetActors2D::SetParametersComments()
{
  return_comments="returning a variable of type vtkActor2DCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetActors2D::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActor2DCollection * res =   this->_objectptr->GetObj()->GetActors2D();
  return AMILabType<vtkActor2DCollection >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetBackground(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetBackground_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetBackground_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetBackground(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::SetBackground(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetBackground::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetBackground::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_SetBackground_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_SetBackground_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetBackground(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetBackground_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetBackground_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetBackground(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkViewport::GetBackground()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetBackground_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetBackground_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetBackground();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::GetBackground(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetBackground::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetBackground::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_GetBackground_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetBackground_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetBackground_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetBackground(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetBackground_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetBackground_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetBackground(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetBackground(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetBackground_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetBackground_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetBackground(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetBackground2(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetBackground2_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetBackground2_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetBackground2(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::SetBackground2(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetBackground2::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetBackground2::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_SetBackground2_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_SetBackground2_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetBackground2(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetBackground2_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetBackground2_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetBackground2(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkViewport::GetBackground2()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetBackground2_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetBackground2_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetBackground2();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::GetBackground2(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetBackground2::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetBackground2::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_GetBackground2_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetBackground2_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetBackground2_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetBackground2(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetBackground2_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetBackground2_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg1_smtptr;
  if (!get_val_smtptr_param<double >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<double > _arg2_smtptr;
  if (!get_val_smtptr_param<double >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<double > _arg3_smtptr;
  if (!get_val_smtptr_param<double >(_arg3_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & _arg3 = *_arg3_smtptr;

  this->_objectptr->GetObj()->GetBackground2(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetBackground2(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetBackground2_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetBackground2_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetBackground2(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetGradientBackground(bool _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetGradientBackground::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetGradientBackground::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg_int;
  if (!get_val_param<int >(_arg_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool _arg = (bool) (_arg_int>0.5);

  this->_objectptr->GetObj()->SetGradientBackground(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool vtkViewport::GetGradientBackground()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetGradientBackground::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetGradientBackground::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetGradientBackground();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GradientBackgroundOn()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GradientBackgroundOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GradientBackgroundOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GradientBackgroundOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GradientBackgroundOff()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GradientBackgroundOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GradientBackgroundOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GradientBackgroundOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetAspect(double _arg1, double _arg2)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetAspect_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetAspect_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetAspect(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::SetAspect(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetAspect::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetAspect::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_SetAspect_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_SetAspect_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetAspect(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetAspect_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetAspect_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetAspect(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkViewport::GetAspect()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetAspect_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetAspect_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetAspect();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::GetAspect(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetAspect::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetAspect::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_GetAspect_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetAspect_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetAspect(double * data)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetAspect_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetAspect_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > data_smtptr;
  if (!get_val_smtptr_param<double >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* data = data_smtptr.get();

  this->_objectptr->GetObj()->GetAspect(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::ComputeAspect()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_ComputeAspect::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_ComputeAspect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeAspect();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetPixelAspect(double _arg1, double _arg2)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetPixelAspect_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetPixelAspect_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetPixelAspect(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::SetPixelAspect(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetPixelAspect::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetPixelAspect::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_SetPixelAspect_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_SetPixelAspect_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetPixelAspect(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetPixelAspect_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetPixelAspect_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetPixelAspect(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkViewport::GetPixelAspect()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPixelAspect_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPixelAspect_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetPixelAspect();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::GetPixelAspect(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPixelAspect::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPixelAspect::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_GetPixelAspect_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetPixelAspect_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetPixelAspect(double * data)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPixelAspect_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPixelAspect_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > data_smtptr;
  if (!get_val_smtptr_param<double >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* data = data_smtptr.get();

  this->_objectptr->GetObj()->GetPixelAspect(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetViewport(double _arg1, double _arg2, double _arg3, double _arg4)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetViewport_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg4'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetViewport_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg3;
  if (!get_val_param<double >(_arg3,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg4;
  if (!get_val_param<double >(_arg4,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetViewport(_arg1, _arg2, _arg3, _arg4);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::SetViewport(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetViewport::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetViewport::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_SetViewport_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_SetViewport_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetViewport(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetViewport_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetViewport_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetViewport(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkViewport::GetViewport()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetViewport_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetViewport_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetViewport();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::GetViewport(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetViewport::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetViewport::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_GetViewport_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetViewport_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetViewport(double * data)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetViewport_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetViewport_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > data_smtptr;
  if (!get_val_smtptr_param<double >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* data = data_smtptr.get();

  this->_objectptr->GetObj()->GetViewport(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetDisplayPoint(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetDisplayPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetDisplayPoint_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetDisplayPoint(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::SetDisplayPoint(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetDisplayPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetDisplayPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_SetDisplayPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_SetDisplayPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetDisplayPoint(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetDisplayPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetDisplayPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetDisplayPoint(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkViewport::GetDisplayPoint()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetDisplayPoint_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetDisplayPoint_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetDisplayPoint();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::GetDisplayPoint(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetDisplayPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetDisplayPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_GetDisplayPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetDisplayPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetDisplayPoint(double * data)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetDisplayPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetDisplayPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > data_smtptr;
  if (!get_val_smtptr_param<double >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* data = data_smtptr.get();

  this->_objectptr->GetObj()->GetDisplayPoint(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetViewPoint(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetViewPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetViewPoint_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetViewPoint(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::SetViewPoint(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetViewPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetViewPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_SetViewPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_SetViewPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetViewPoint(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetViewPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetViewPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetViewPoint(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkViewport::GetViewPoint()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetViewPoint_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetViewPoint_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetViewPoint();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::GetViewPoint(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetViewPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetViewPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_GetViewPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetViewPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetViewPoint(double * data)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetViewPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetViewPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > data_smtptr;
  if (!get_val_smtptr_param<double >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* data = data_smtptr.get();

  this->_objectptr->GetObj()->GetViewPoint(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetWorldPoint(double _arg1, double _arg2, double _arg3, double _arg4)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetWorldPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg4'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetWorldPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  double _arg1;
  if (!get_val_param<double >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg2;
  if (!get_val_param<double >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg3;
  if (!get_val_param<double >(_arg3,_p,_n,true,true)) ClassReturnEmptyVar;

  double _arg4;
  if (!get_val_param<double >(_arg4,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetWorldPoint(_arg1, _arg2, _arg3, _arg4);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::SetWorldPoint(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetWorldPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetWorldPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_SetWorldPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_SetWorldPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::SetWorldPoint(double * _arg)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_SetWorldPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_SetWorldPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetWorldPoint(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkViewport::GetWorldPoint()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetWorldPoint_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetWorldPoint_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetWorldPoint();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::GetWorldPoint(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetWorldPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetWorldPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_GetWorldPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_GetWorldPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetWorldPoint(double * data)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetWorldPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetWorldPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > data_smtptr;
  if (!get_val_smtptr_param<double >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* data = data_smtptr.get();

  this->_objectptr->GetObj()->GetWorldPoint(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkViewport::GetCenter()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetCenter::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetCenter::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double * res =   this->_objectptr->GetObj()->GetCenter();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of int vtkViewport::IsInViewport(int x, int y)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_IsInViewport::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_IsInViewport::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsInViewport(x, y);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::DisplayToView()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_DisplayToView::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_DisplayToView::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DisplayToView();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::ViewToDisplay()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_ViewToDisplay::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_ViewToDisplay::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ViewToDisplay();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::WorldToView()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_WorldToView_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_WorldToView_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->WorldToView();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::ViewToWorld()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_ViewToWorld_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_ViewToWorld_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->ViewToWorld();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::DisplayToWorld()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_DisplayToWorld::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_DisplayToWorld::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DisplayToWorld();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::WorldToDisplay()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_WorldToDisplay::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_WorldToDisplay::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->WorldToDisplay();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::LocalDisplayToDisplay(double & x, double & y)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_LocalDisplayToDisplay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_LocalDisplayToDisplay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & x = *x_smtptr;

  boost::shared_ptr<double > y_smtptr;
  if (!get_val_smtptr_param<double >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & y = *y_smtptr;

  this->_objectptr->GetObj()->LocalDisplayToDisplay(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::DisplayToNormalizedDisplay(double & u, double & v)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_DisplayToNormalizedDisplay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'u'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_DisplayToNormalizedDisplay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > u_smtptr;
  if (!get_val_smtptr_param<double >(u_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & u = *u_smtptr;

  boost::shared_ptr<double > v_smtptr;
  if (!get_val_smtptr_param<double >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & v = *v_smtptr;

  this->_objectptr->GetObj()->DisplayToNormalizedDisplay(u, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::NormalizedDisplayToViewport(double & x, double & y)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_NormalizedDisplayToViewport::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_NormalizedDisplayToViewport::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & x = *x_smtptr;

  boost::shared_ptr<double > y_smtptr;
  if (!get_val_smtptr_param<double >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & y = *y_smtptr;

  this->_objectptr->GetObj()->NormalizedDisplayToViewport(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::ViewportToNormalizedViewport(double & u, double & v)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_ViewportToNormalizedViewport::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'u'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_ViewportToNormalizedViewport::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > u_smtptr;
  if (!get_val_smtptr_param<double >(u_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & u = *u_smtptr;

  boost::shared_ptr<double > v_smtptr;
  if (!get_val_smtptr_param<double >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & v = *v_smtptr;

  this->_objectptr->GetObj()->ViewportToNormalizedViewport(u, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::NormalizedViewportToView(double & x, double & y, double & z)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_NormalizedViewportToView::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_NormalizedViewportToView::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & x = *x_smtptr;

  boost::shared_ptr<double > y_smtptr;
  if (!get_val_smtptr_param<double >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & y = *y_smtptr;

  boost::shared_ptr<double > z_smtptr;
  if (!get_val_smtptr_param<double >(z_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & z = *z_smtptr;

  this->_objectptr->GetObj()->NormalizedViewportToView(x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::ViewToWorld(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_ViewToWorld::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_ViewToWorld::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_ViewToWorld_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_ViewToWorld_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::ViewToWorld(double & param0, double & param1, double & param2)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_ViewToWorld_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_ViewToWorld_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > param0_smtptr;
  if (!get_val_smtptr_param<double >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & param0 = *param0_smtptr;

  boost::shared_ptr<double > param1_smtptr;
  if (!get_val_smtptr_param<double >(param1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & param1 = *param1_smtptr;

  boost::shared_ptr<double > param2_smtptr;
  if (!get_val_smtptr_param<double >(param2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & param2 = *param2_smtptr;

  this->_objectptr->GetObj()->ViewToWorld(param0, param1, param2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::DisplayToLocalDisplay(double & x, double & y)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_DisplayToLocalDisplay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_DisplayToLocalDisplay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & x = *x_smtptr;

  boost::shared_ptr<double > y_smtptr;
  if (!get_val_smtptr_param<double >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & y = *y_smtptr;

  this->_objectptr->GetObj()->DisplayToLocalDisplay(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::NormalizedDisplayToDisplay(double & u, double & v)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_NormalizedDisplayToDisplay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'u'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_NormalizedDisplayToDisplay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > u_smtptr;
  if (!get_val_smtptr_param<double >(u_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & u = *u_smtptr;

  boost::shared_ptr<double > v_smtptr;
  if (!get_val_smtptr_param<double >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & v = *v_smtptr;

  this->_objectptr->GetObj()->NormalizedDisplayToDisplay(u, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::ViewportToNormalizedDisplay(double & x, double & y)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_ViewportToNormalizedDisplay::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_ViewportToNormalizedDisplay::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & x = *x_smtptr;

  boost::shared_ptr<double > y_smtptr;
  if (!get_val_smtptr_param<double >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & y = *y_smtptr;

  this->_objectptr->GetObj()->ViewportToNormalizedDisplay(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::NormalizedViewportToViewport(double & u, double & v)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_NormalizedViewportToViewport::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'u'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_NormalizedViewportToViewport::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > u_smtptr;
  if (!get_val_smtptr_param<double >(u_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & u = *u_smtptr;

  boost::shared_ptr<double > v_smtptr;
  if (!get_val_smtptr_param<double >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & v = *v_smtptr;

  this->_objectptr->GetObj()->NormalizedViewportToViewport(u, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::ViewToNormalizedViewport(double & x, double & y, double & z)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_ViewToNormalizedViewport::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_ViewToNormalizedViewport::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & x = *x_smtptr;

  boost::shared_ptr<double > y_smtptr;
  if (!get_val_smtptr_param<double >(y_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & y = *y_smtptr;

  boost::shared_ptr<double > z_smtptr;
  if (!get_val_smtptr_param<double >(z_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double & z = *z_smtptr;

  this->_objectptr->GetObj()->ViewToNormalizedViewport(x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkViewport::WorldToView(...)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_WorldToView::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_WorldToView::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkViewport::wrap_WorldToView_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkViewport::wrap_WorldToView_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::WorldToView(double & param0, double & param1, double & param2)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_WorldToView_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_WorldToView_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > param0_smtptr;
  if (!get_val_smtptr_param<double >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & param0 = *param0_smtptr;

  boost::shared_ptr<double > param1_smtptr;
  if (!get_val_smtptr_param<double >(param1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & param1 = *param1_smtptr;

  boost::shared_ptr<double > param2_smtptr;
  if (!get_val_smtptr_param<double >(param2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double & param2 = *param2_smtptr;

  this->_objectptr->GetObj()->WorldToView(param0, param1, param2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkViewport::GetSize()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int * res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of int * vtkViewport::GetOrigin()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetOrigin::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetOrigin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int * res =   this->_objectptr->GetObj()->GetOrigin();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetTiledSize(int * width, int * height)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetTiledSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetTiledSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > width_smtptr;
  if (!get_val_smtptr_param<int >(width_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* width = width_smtptr.get();

  boost::shared_ptr<int > height_smtptr;
  if (!get_val_smtptr_param<int >(height_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* height = height_smtptr.get();

  this->_objectptr->GetObj()->GetTiledSize(width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::GetTiledSizeAndOrigin(int * width, int * height, int * lowerLeftX, int * lowerLeftY)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetTiledSizeAndOrigin::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'lowerLeftX'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'lowerLeftY'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetTiledSizeAndOrigin::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > width_smtptr;
  if (!get_val_smtptr_param<int >(width_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* width = width_smtptr.get();

  boost::shared_ptr<int > height_smtptr;
  if (!get_val_smtptr_param<int >(height_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* height = height_smtptr.get();

  boost::shared_ptr<int > lowerLeftX_smtptr;
  if (!get_val_smtptr_param<int >(lowerLeftX_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* lowerLeftX = lowerLeftX_smtptr.get();

  boost::shared_ptr<int > lowerLeftY_smtptr;
  if (!get_val_smtptr_param<int >(lowerLeftY_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* lowerLeftY = lowerLeftY_smtptr.get();

  this->_objectptr->GetObj()->GetTiledSizeAndOrigin(width, height, lowerLeftX, lowerLeftY);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkAssemblyPath

//---------------------------------------------------
//  Wrapping of vtkAssemblyPath * vtkViewport::PickPropFrom(double selectionX, double selectionY, vtkPropCollection * param2)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_PickPropFrom::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'selectionX'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'selectionY'")
  ADDPARAMCOMMENT_TYPE( vtkPropCollection, "parameter named 'param2'")
  return_comments="returning a variable of type vtkAssemblyPath";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_PickPropFrom::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double selectionX;
  if (!get_val_param<double >(selectionX,_p,_n,true,false)) ClassHelpAndReturn;

  double selectionY;
  if (!get_val_param<double >(selectionY,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<vtkPropCollection > param2_smtptr;
  if (!get_val_smtptr_param<vtkPropCollection >(param2_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkPropCollection* param2 = param2_smtptr.get();

  vtkAssemblyPath * res =   this->_objectptr->GetObj()->PickPropFrom(selectionX, selectionY, param2);
  return AMILabType<vtkAssemblyPath >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of double vtkViewport::GetPickX()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPickX::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPickX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPickX();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkViewport::GetPickY()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPickY::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPickY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPickY();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkViewport::GetPickWidth()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPickWidth::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPickWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPickWidth();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkViewport::GetPickHeight()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPickHeight::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPickHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPickHeight();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkViewport::GetPickX1()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPickX1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPickX1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPickX1();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkViewport::GetPickY1()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPickY1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPickY1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPickY1();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkViewport::GetPickX2()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPickX2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPickX2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPickX2();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkViewport::GetPickY2()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPickY2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPickY2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPickY2();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkViewport::GetIsPicking()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetIsPicking::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetIsPicking::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIsPicking();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPropCollection * vtkViewport::GetPickResultProps()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetPickResultProps::SetParametersComments()
{
  return_comments="returning a variable of type vtkPropCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetPickResultProps::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPropCollection * res =   this->_objectptr->GetObj()->GetPickResultProps();
  BasicVariable::ptr res_var = WrapClass_vtkPropCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::RemoveProp(vtkProp * param0)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_RemoveProp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_RemoveProp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > param0_smtptr;
  if (!get_val_smtptr_param<vtkProp >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->RemoveProp(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::AddProp(vtkProp * param0)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_AddProp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_AddProp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > param0_smtptr;
  if (!get_val_smtptr_param<vtkProp >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->AddProp(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkPropCollection * vtkViewport::GetProps()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_GetProps::SetParametersComments()
{
  return_comments="returning a variable of type vtkPropCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_GetProps::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPropCollection * res =   this->_objectptr->GetObj()->GetProps();
  BasicVariable::ptr res_var = WrapClass_vtkPropCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkViewport::HasProp(vtkProp * param0)
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_HasProp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_HasProp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp > param0_smtptr;
  if (!get_val_smtptr_param<vtkProp >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp* param0 = param0_smtptr.get();

  int res =   this->_objectptr->GetObj()->HasProp(param0);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkViewport::RemoveAllProps()
//---------------------------------------------------
void WrapClass_vtkViewport::
    wrap_RemoveAllProps::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkViewport::
    wrap_RemoveAllProps::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllProps();
  return BasicVariable::ptr();
}

