/**
 * C++ Interface: wrap_vtkBoxWidget
 *
 * Description: wrapping vtkBoxWidget
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

#include "wrap_vtkBoxWidget.h"

// get all the required includes
// #include "..."
#ifndef vtkBoxWidget_declared
  #define vtkBoxWidget_declared
  AMI_DECLARE_TYPE(vtkBoxWidget)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkPlanes_declared
  #define vtkPlanes_declared
  AMI_DECLARE_TYPE(vtkPlanes)
#endif
#ifndef vtkTransform_declared
  #define vtkTransform_declared
  AMI_DECLARE_TYPE(vtkTransform)
#endif
#ifndef vtkPolyData_declared
  #define vtkPolyData_declared
  AMI_DECLARE_TYPE(vtkPolyData)
#endif
#ifndef vtkProperty_declared
  #define vtkProperty_declared
  AMI_DECLARE_TYPE(vtkProperty)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkBoxWidget>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkBoxWidget);
AMI_DEFINE_VARFROMSMTPTR(vtkBoxWidget);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkBoxWidget>::CreateVar( vtkBoxWidget* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkBoxWidget> obj_ptr(val,smartpointer_nodeleter<vtkBoxWidget>());
  return AMILabType<vtkBoxWidget>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkBoxWidget
//
Variable<AMIObject>::ptr WrapClass_vtkBoxWidget::CreateVar( vtkBoxWidget* sp)
{
  boost::shared_ptr<vtkBoxWidget> di_ptr(
    sp,
    wxwindow_nodeleter<vtkBoxWidget>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkBoxWidget>::CreateVar(
      new WrapClass_vtkBoxWidget(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkBoxWidget::AddMethods(WrapClass<vtkBoxWidget>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_SetEnabled( this_ptr);
  AddVar_PlaceWidget_1( this_ptr);
  AddVar_PlaceWidget( this_ptr);
  AddVar_PlaceWidget_2( this_ptr);
  AddVar_PlaceWidget_3( this_ptr);
  AddVar_GetPlanes( this_ptr);
  AddVar_SetInsideOut( this_ptr);
  AddVar_GetInsideOut( this_ptr);
  AddVar_InsideOutOn( this_ptr);
  AddVar_InsideOutOff( this_ptr);
  AddVar_GetTransform( this_ptr);
  AddVar_SetTransform( this_ptr);
  AddVar_GetPolyData( this_ptr);
  AddVar_GetHandleProperty( this_ptr);
  AddVar_GetSelectedHandleProperty( this_ptr);
  AddVar_HandlesOn( this_ptr);
  AddVar_HandlesOff( this_ptr);
  AddVar_GetFaceProperty( this_ptr);
  AddVar_GetSelectedFaceProperty( this_ptr);
  AddVar_GetOutlineProperty( this_ptr);
  AddVar_GetSelectedOutlineProperty( this_ptr);
  AddVar_SetOutlineFaceWires( this_ptr);
  AddVar_GetOutlineFaceWires( this_ptr);
  AddVar_OutlineFaceWiresOn( this_ptr);
  AddVar_OutlineFaceWiresOff( this_ptr);
  AddVar_SetOutlineCursorWires( this_ptr);
  AddVar_GetOutlineCursorWires( this_ptr);
  AddVar_OutlineCursorWiresOn( this_ptr);
  AddVar_OutlineCursorWiresOff( this_ptr);
  AddVar_SetTranslationEnabled( this_ptr);
  AddVar_GetTranslationEnabled( this_ptr);
  AddVar_TranslationEnabledOn( this_ptr);
  AddVar_TranslationEnabledOff( this_ptr);
  AddVar_SetScalingEnabled( this_ptr);
  AddVar_GetScalingEnabled( this_ptr);
  AddVar_ScalingEnabledOn( this_ptr);
  AddVar_ScalingEnabledOff( this_ptr);
  AddVar_SetRotationEnabled( this_ptr);
  AddVar_GetRotationEnabled( this_ptr);
  AddVar_RotationEnabledOn( this_ptr);
  AddVar_RotationEnabledOff( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtk3DWidget
  boost::shared_ptr<vtk3DWidget > parent_vtk3DWidget(  boost::dynamic_pointer_cast<vtk3DWidget >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtk3DWidget = AMILabType<vtk3DWidget >::CreateVarFromSmtPtr(parent_vtk3DWidget);
  context->AddVar("vtk3DWidget",var_vtk3DWidget);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtk3DWidget = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtk3DWidget);
  context->AddDefault(obj_vtk3DWidget->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkBoxWidget_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkBoxWidget");
  
  // Static methods 
  WrapClass_vtkBoxWidget::AddVar_New(amiobject->GetContext());
  WrapClass_vtkBoxWidget::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkBoxWidget::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkBoxWidget * vtkBoxWidget::New()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkBoxWidget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkBoxWidget * res =   vtkBoxWidget::New();
  BasicVariable::ptr res_var = AMILabType<vtkBoxWidget >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkBoxWidget::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkBoxWidget::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkBoxWidget * vtkBoxWidget::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkBoxWidget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
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

  vtkBoxWidget * res =   vtkBoxWidget::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkBoxWidget >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkBoxWidget::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
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
//  Wrapping of vtkBoxWidget * vtkBoxWidget::NewInstance()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkBoxWidget";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkBoxWidget * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkBoxWidget >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
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
//  Wrapping of void vtkBoxWidget::SetEnabled(int param0)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_SetEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_SetEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetEnabled(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::PlaceWidget(double * bounds)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_PlaceWidget_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_PlaceWidget_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->PlaceWidget(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkBoxWidget::PlaceWidget(...)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_PlaceWidget::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_PlaceWidget::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkBoxWidget::wrap_PlaceWidget_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkBoxWidget::wrap_PlaceWidget_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkBoxWidget::wrap_PlaceWidget_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::PlaceWidget()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_PlaceWidget_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_PlaceWidget_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->PlaceWidget();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::PlaceWidget(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_PlaceWidget_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'xmax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'ymax'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmin'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'zmax'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_PlaceWidget_3::CallMember( ParamList* _p)
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
//  Wrapping of void vtkBoxWidget::GetPlanes(vtkPlanes * planes)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetPlanes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPlanes, "parameter named 'planes'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetPlanes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkPlanes* planes;
  if (CheckNullVar(_p,_n))  {
    planes=(vtkPlanes*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPlanes > planes_smtptr;
    if (!get_val_smtptr_param<vtkPlanes >(planes_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    planes = planes_smtptr.get();
  }

  this->_objectptr->GetObj()->GetPlanes(planes);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::SetInsideOut(int _arg)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_SetInsideOut::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_SetInsideOut::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInsideOut(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkBoxWidget::GetInsideOut()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetInsideOut::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetInsideOut::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInsideOut();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::InsideOutOn()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_InsideOutOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_InsideOutOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsideOutOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::InsideOutOff()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_InsideOutOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_InsideOutOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InsideOutOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::GetTransform(vtkTransform * t)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetTransform::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTransform, "parameter named 't'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetTransform::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkTransform* t;
  if (CheckNullVar(_p,_n))  {
    t=(vtkTransform*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkTransform > t_smtptr;
    if (!get_val_smtptr_param<vtkTransform >(t_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    t = t_smtptr.get();
  }

  this->_objectptr->GetObj()->GetTransform(t);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::SetTransform(vtkTransform * t)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_SetTransform::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTransform, "parameter named 't'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_SetTransform::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkTransform* t;
  if (CheckNullVar(_p,_n))  {
    t=(vtkTransform*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkTransform > t_smtptr;
    if (!get_val_smtptr_param<vtkTransform >(t_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    t = t_smtptr.get();
  }

  this->_objectptr->GetObj()->SetTransform(t);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::GetPolyData(vtkPolyData * pd)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetPolyData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPolyData, "parameter named 'pd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetPolyData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkPolyData* pd;
  if (CheckNullVar(_p,_n))  {
    pd=(vtkPolyData*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPolyData > pd_smtptr;
    if (!get_val_smtptr_param<vtkPolyData >(pd_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    pd = pd_smtptr.get();
  }

  this->_objectptr->GetObj()->GetPolyData(pd);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkBoxWidget::GetHandleProperty()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetHandleProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetHandleProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->GetHandleProperty();
  BasicVariable::ptr res_var = AMILabType<vtkProperty >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkBoxWidget::GetSelectedHandleProperty()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetSelectedHandleProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetSelectedHandleProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->GetSelectedHandleProperty();
  BasicVariable::ptr res_var = AMILabType<vtkProperty >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::HandlesOn()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_HandlesOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_HandlesOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HandlesOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::HandlesOff()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_HandlesOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_HandlesOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HandlesOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkBoxWidget::GetFaceProperty()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetFaceProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetFaceProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->GetFaceProperty();
  BasicVariable::ptr res_var = AMILabType<vtkProperty >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkBoxWidget::GetSelectedFaceProperty()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetSelectedFaceProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetSelectedFaceProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->GetSelectedFaceProperty();
  BasicVariable::ptr res_var = AMILabType<vtkProperty >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkBoxWidget::GetOutlineProperty()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetOutlineProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetOutlineProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->GetOutlineProperty();
  BasicVariable::ptr res_var = AMILabType<vtkProperty >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkProperty * vtkBoxWidget::GetSelectedOutlineProperty()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetSelectedOutlineProperty::SetParametersComments()
{
  return_comments="returning a variable of type vtkProperty";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetSelectedOutlineProperty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProperty * res =   this->_objectptr->GetObj()->GetSelectedOutlineProperty();
  BasicVariable::ptr res_var = AMILabType<vtkProperty >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::SetOutlineFaceWires(int param0)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_SetOutlineFaceWires::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_SetOutlineFaceWires::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetOutlineFaceWires(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkBoxWidget::GetOutlineFaceWires()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetOutlineFaceWires::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetOutlineFaceWires::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetOutlineFaceWires();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::OutlineFaceWiresOn()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_OutlineFaceWiresOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_OutlineFaceWiresOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OutlineFaceWiresOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::OutlineFaceWiresOff()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_OutlineFaceWiresOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_OutlineFaceWiresOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OutlineFaceWiresOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::SetOutlineCursorWires(int param0)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_SetOutlineCursorWires::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_SetOutlineCursorWires::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetOutlineCursorWires(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkBoxWidget::GetOutlineCursorWires()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetOutlineCursorWires::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetOutlineCursorWires::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetOutlineCursorWires();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::OutlineCursorWiresOn()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_OutlineCursorWiresOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_OutlineCursorWiresOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OutlineCursorWiresOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::OutlineCursorWiresOff()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_OutlineCursorWiresOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_OutlineCursorWiresOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OutlineCursorWiresOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::SetTranslationEnabled(int _arg)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_SetTranslationEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_SetTranslationEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTranslationEnabled(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkBoxWidget::GetTranslationEnabled()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetTranslationEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetTranslationEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTranslationEnabled();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::TranslationEnabledOn()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_TranslationEnabledOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_TranslationEnabledOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->TranslationEnabledOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::TranslationEnabledOff()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_TranslationEnabledOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_TranslationEnabledOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->TranslationEnabledOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::SetScalingEnabled(int _arg)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_SetScalingEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_SetScalingEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalingEnabled(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkBoxWidget::GetScalingEnabled()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetScalingEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetScalingEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScalingEnabled();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::ScalingEnabledOn()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_ScalingEnabledOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_ScalingEnabledOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ScalingEnabledOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::ScalingEnabledOff()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_ScalingEnabledOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_ScalingEnabledOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ScalingEnabledOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::SetRotationEnabled(int _arg)
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_SetRotationEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_SetRotationEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRotationEnabled(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkBoxWidget::GetRotationEnabled()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_GetRotationEnabled::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_GetRotationEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetRotationEnabled();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::RotationEnabledOn()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_RotationEnabledOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_RotationEnabledOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotationEnabledOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkBoxWidget::RotationEnabledOff()
//---------------------------------------------------
void WrapClass_vtkBoxWidget::
    wrap_RotationEnabledOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkBoxWidget::
    wrap_RotationEnabledOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotationEnabledOff();
  return BasicVariable::ptr();
}

