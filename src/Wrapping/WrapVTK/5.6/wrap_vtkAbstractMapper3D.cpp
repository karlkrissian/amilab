/**
 * C++ Interface: wrap_vtkAbstractMapper3D
 *
 * Description: wrapping vtkAbstractMapper3D
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
#include "wrap_vtkAbstractMapper3D.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"


#include "wrap_vtkAbstractMapper3D.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkAbstractMapper3D>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkAbstractMapper3D);
AMI_DEFINE_VARFROMSMTPTR(vtkAbstractMapper3D);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkAbstractMapper3D>::CreateVar( vtkAbstractMapper3D* val)
{ 
  boost::shared_ptr<vtkAbstractMapper3D> obj_ptr(val,wxwindow_nodeleter<vtkAbstractMapper3D>());
  return AMILabType<vtkAbstractMapper3D>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkAbstractMapper3D
//
Variable<AMIObject>::ptr WrapClass_vtkAbstractMapper3D::CreateVar( vtkAbstractMapper3D* sp)
{
  boost::shared_ptr<vtkAbstractMapper3D> di_ptr(
    sp,
    wxwindow_nodeleter<vtkAbstractMapper3D>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkAbstractMapper3D>::CreateVar(
      new WrapClass_vtkAbstractMapper3D(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkAbstractMapper3D::AddMethods(WrapClass<vtkAbstractMapper3D>::ptr this_ptr )
{
  
      // Add members from vtkAbstractMapper
      WrapClass_vtkAbstractMapper::ptr parent_vtkAbstractMapper(        boost::dynamic_pointer_cast<WrapClass_vtkAbstractMapper >(this_ptr));
      parent_vtkAbstractMapper->AddMethods(parent_vtkAbstractMapper);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_GetBounds( this_ptr);
      AddVar_GetCenter_1( this_ptr);
      AddVar_GetCenter( this_ptr);
      AddVar_GetCenter_2( this_ptr);
      AddVar_GetLength( this_ptr);
      AddVar_IsARayCastMapper( this_ptr);
      AddVar_IsARenderIntoImageMapper( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkAbstractMapper3D::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkAbstractMapper3D::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAbstractMapper3D * vtkAbstractMapper3D::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkAbstractMapper3D";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkAbstractMapper3D * res =   vtkAbstractMapper3D::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkAbstractMapper3D::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractMapper3D::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAbstractMapper3D * vtkAbstractMapper3D::NewInstance()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractMapper3D";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractMapper3D * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkAbstractMapper3D::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper3D::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper3D::GetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_GetBounds::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > bounds_smtptr;
  if (!get_val_smtptr_param<double >(bounds_smtptr,_p,_n)) ClassHelpAndReturn;
  double* bounds = bounds_smtptr.get();

  this->_objectptr->GetObj()->GetBounds(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkAbstractMapper3D::GetCenter()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_GetCenter_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_GetCenter_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetCenter();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractMapper3D::GetCenter(...)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_GetCenter::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_GetCenter::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractMapper3D::wrap_GetCenter_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkAbstractMapper3D::wrap_GetCenter_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper3D::GetCenter(double * center)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_GetCenter_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'center'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_GetCenter_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > center_smtptr;
  if (!get_val_smtptr_param<double >(center_smtptr,_p,_n)) ClassReturnEmptyVar;
  double* center = center_smtptr.get();

  this->_objectptr->GetObj()->GetCenter(center);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkAbstractMapper3D::GetLength()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_GetLength::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_GetLength::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetLength();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractMapper3D::IsARayCastMapper()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_IsARayCastMapper::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_IsARayCastMapper::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsARayCastMapper();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkAbstractMapper3D::IsARenderIntoImageMapper()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper3D::
    wrap_IsARenderIntoImageMapper::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper3D::
    wrap_IsARenderIntoImageMapper::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsARenderIntoImageMapper();
  return AMILabType<int >::CreateVar(res);
}

