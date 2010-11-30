/**
 * C++ Interface: wrap_vtk3DWidget
 *
 * Description: wrapping vtk3DWidget
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
#include "wrap_vtk3DWidget.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkProp3D.h"
#include "wrap_vtkDataSet.h"


#include "wrap_vtk3DWidget.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtk3DWidget>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtk3DWidget);
AMI_DEFINE_VARFROMSMTPTR(vtk3DWidget);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtk3DWidget>::CreateVar( vtk3DWidget* val, bool nodeleter)
{ 
  boost::shared_ptr<vtk3DWidget> obj_ptr(val,smartpointer_nodeleter<vtk3DWidget>());
  return AMILabType<vtk3DWidget>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtk3DWidget
//
Variable<AMIObject>::ptr WrapClass_vtk3DWidget::CreateVar( vtk3DWidget* sp)
{
  boost::shared_ptr<vtk3DWidget> di_ptr(
    sp,
    wxwindow_nodeleter<vtk3DWidget>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtk3DWidget>::CreateVar(
      new WrapClass_vtk3DWidget(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtk3DWidget::AddMethods(WrapClass<vtk3DWidget>::ptr this_ptr )
{
  
      // Add members from vtkInteractorObserver
      WrapClass_vtkInteractorObserver::ptr parent_vtkInteractorObserver(        boost::dynamic_pointer_cast<WrapClass_vtkInteractorObserver >(this_ptr));
      parent_vtkInteractorObserver->AddMethods(parent_vtkInteractorObserver);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_PlaceWidget_1( this_ptr);
      AddVar_PlaceWidget( this_ptr);
      AddVar_PlaceWidget_2( this_ptr);
      AddVar_SetProp3D( this_ptr);
      AddVar_GetProp3D( this_ptr);
      AddVar_SetInput( this_ptr);
      AddVar_GetInput( this_ptr);
      AddVar_SetPlaceFactor( this_ptr);
      AddVar_GetPlaceFactorMinValue( this_ptr);
      AddVar_GetPlaceFactorMaxValue( this_ptr);
      AddVar_GetPlaceFactor( this_ptr);
      AddVar_SetHandleSize( this_ptr);
      AddVar_GetHandleSizeMinValue( this_ptr);
      AddVar_GetHandleSizeMaxValue( this_ptr);
      AddVar_GetHandleSize( this_ptr);



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtk3DWidget::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtk3DWidget");
  
  // Static methods 
  WrapClass_vtk3DWidget::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtk3DWidget::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtk3DWidget::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtk3DWidget::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtk3DWidget * vtk3DWidget::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtk3DWidget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtk3DWidget * res =   vtk3DWidget::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtk3DWidget::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtk3DWidget::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
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
//  Wrapping of vtk3DWidget * vtk3DWidget::NewInstance()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtk3DWidget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtk3DWidget * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtk3DWidget::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtk3DWidget::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
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
//  Wrapping of void vtk3DWidget::PlaceWidget()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_PlaceWidget_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_PlaceWidget_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->PlaceWidget();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtk3DWidget::PlaceWidget(...)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_PlaceWidget::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_PlaceWidget::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtk3DWidget::wrap_PlaceWidget_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtk3DWidget::wrap_PlaceWidget_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtk3DWidget::PlaceWidget(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_PlaceWidget_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmax'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_PlaceWidget_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  double xmin;
  if (!get_val_param<double >(xmin,_p,_n,true,true)) ClassReturnEmptyVar;

  double xmax;
  if (!get_val_param<double >(xmax,_p,_n,true,true)) ClassReturnEmptyVar;

  double ymin;
  if (!get_val_param<double >(ymin,_p,_n,true,true)) ClassReturnEmptyVar;

  double ymax;
  if (!get_val_param<double >(ymax,_p,_n,true,true)) ClassReturnEmptyVar;

  double zmin;
  if (!get_val_param<double >(zmin,_p,_n,true,true)) ClassReturnEmptyVar;

  double zmax;
  if (!get_val_param<double >(zmax,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->PlaceWidget(xmin, xmax, ymin, ymax, zmin, zmax);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtk3DWidget::SetProp3D(vtkProp3D * param0)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_SetProp3D::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp3D, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_SetProp3D::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProp3D > param0_smtptr;
  if (!get_val_smtptr_param<vtkProp3D >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProp3D* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetProp3D(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkProp3D * vtk3DWidget::GetProp3D()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_GetProp3D::SetParametersComments()
{
  return_comments="returning a variable of type vtkProp3D";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_GetProp3D::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProp3D * res =   this->_objectptr->GetObj()->GetProp3D();
  BasicVariable::ptr res_var = WrapClass_vtkProp3D::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtk3DWidget::SetInput(vtkDataSet * param0)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_SetInput::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataSet, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_SetInput::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataSet > param0_smtptr;
  if (!get_val_smtptr_param<vtkDataSet >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataSet* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetInput(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkDataSet * vtk3DWidget::GetInput()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_GetInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_GetInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataSet * res =   this->_objectptr->GetObj()->GetInput();
  BasicVariable::ptr res_var = WrapClass_vtkDataSet::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtk3DWidget::SetPlaceFactor(double _arg)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_SetPlaceFactor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_SetPlaceFactor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPlaceFactor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtk3DWidget::GetPlaceFactorMinValue()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_GetPlaceFactorMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_GetPlaceFactorMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPlaceFactorMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtk3DWidget::GetPlaceFactorMaxValue()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_GetPlaceFactorMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_GetPlaceFactorMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPlaceFactorMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtk3DWidget::GetPlaceFactor()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_GetPlaceFactor::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_GetPlaceFactor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPlaceFactor();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtk3DWidget::SetHandleSize(double _arg)
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_SetHandleSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_SetHandleSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double _arg;
  if (!get_val_param<double >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetHandleSize(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtk3DWidget::GetHandleSizeMinValue()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_GetHandleSizeMinValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_GetHandleSizeMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetHandleSizeMinValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtk3DWidget::GetHandleSizeMaxValue()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_GetHandleSizeMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_GetHandleSizeMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetHandleSizeMaxValue();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtk3DWidget::GetHandleSize()
//---------------------------------------------------
void WrapClass_vtk3DWidget::
    wrap_GetHandleSize::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtk3DWidget::
    wrap_GetHandleSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetHandleSize();
  return AMILabType<double >::CreateVar(res);
}

