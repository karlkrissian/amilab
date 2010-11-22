/**
 * C++ Interface: wrap_vtkAbstractMapper
 *
 * Description: wrapping vtkAbstractMapper
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
#include "wrap_vtkAbstractMapper.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkDataSet.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkWindow.h"
#include "wrap_vtkPlanes.h"


#include "wrap_vtkAbstractMapper.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkAbstractMapper>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkAbstractMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkAbstractMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkAbstractMapper>::CreateVar( vtkAbstractMapper* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkAbstractMapper> obj_ptr(val,smartpointer_nodeleter<vtkAbstractMapper>());
  return AMILabType<vtkAbstractMapper>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkAbstractMapper
//
Variable<AMIObject>::ptr WrapClass_vtkAbstractMapper::CreateVar( vtkAbstractMapper* sp)
{
  boost::shared_ptr<vtkAbstractMapper> di_ptr(
    sp,
    wxwindow_nodeleter<vtkAbstractMapper>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkAbstractMapper>::CreateVar(
      new WrapClass_vtkAbstractMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkAbstractMapper::AddMethods(WrapClass<vtkAbstractMapper>::ptr this_ptr )
{
  
      // Add members from vtkAlgorithm
      WrapClass_vtkAlgorithm::ptr parent_vtkAlgorithm(        boost::dynamic_pointer_cast<WrapClass_vtkAlgorithm >(this_ptr));
      parent_vtkAlgorithm->AddMethods(parent_vtkAlgorithm);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_GetMTime( this_ptr);
      AddVar_ReleaseGraphicsResources( this_ptr);
      AddVar_GetTimeToDraw( this_ptr);
/* The following types are missing: vtkPlane
      AddVar_AddClippingPlane( this_ptr);
*/
/* The following types are missing: vtkPlane
      AddVar_RemoveClippingPlane( this_ptr);
*/
      AddVar_RemoveAllClippingPlanes( this_ptr);
/* The following types are missing: vtkPlaneCollection
      AddVar_SetClippingPlanes_1( this_ptr);
*/
/* The following types are missing: vtkPlaneCollection
      AddVar_GetClippingPlanes( this_ptr);
*/
      AddVar_SetClippingPlanes( this_ptr);
      AddVar_SetClippingPlanes_2( this_ptr);
      AddVar_ShallowCopy( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkAbstractMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkAbstractMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAbstractMapper * vtkAbstractMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkAbstractMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkAbstractMapper * res =   vtkAbstractMapper::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkAbstractMapper::CreateVar(res);
  return res_var;
}
/* The following types are missing: vtkDataArray

//---------------------------------------------------
//  Wrapping of vtkDataArray * vtkAbstractMapper::GetScalars(vtkDataSet * input, int scalarMode, int arrayAccessMode, int arrayId, char const * arrayName, int & cellFlag)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_GetScalars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataSet, "parameter named 'input'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'scalarMode'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'arrayAccessMode'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'arrayId'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'arrayName'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cellFlag'")
  return_comments="returning a variable of type vtkDataArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_GetScalars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataSet > input_smtptr;
  if (!get_val_smtptr_param<vtkDataSet >(input_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkDataSet* input = input_smtptr.get();

  int scalarMode;
  if (!get_val_param<int >(scalarMode,_p,_n)) ClassHelpAndReturn;

  int arrayAccessMode;
  if (!get_val_param<int >(arrayAccessMode,_p,_n)) ClassHelpAndReturn;

  int arrayId;
  if (!get_val_param<int >(arrayId,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<std::string > arrayName_string;
  if (!get_val_smtptr_param<std::string >(arrayName_string,_p,_n)) ClassHelpAndReturn;
  char const * arrayName = arrayName_string->c_str();

  boost::shared_ptr<int > cellFlag_smtptr;
  if (!get_val_smtptr_param<int >(cellFlag_smtptr,_p,_n)) ClassHelpAndReturn;
  int & cellFlag = *cellFlag_smtptr;

  vtkDataArray * res =   vtkAbstractMapper::GetScalars(input, scalarMode, arrayAccessMode, arrayId, arrayName, cellFlag);
  return AMILabType<vtkDataArray >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of int vtkAbstractMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
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
//  Wrapping of vtkAbstractMapper * vtkAbstractMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractMapper * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkAbstractMapper::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
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
//  Wrapping of long unsigned int vtkAbstractMapper::GetMTime()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper::ReleaseGraphicsResources(vtkWindow * param0)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_ReleaseGraphicsResources::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkWindow > param0_smtptr;
  if (!get_val_smtptr_param<vtkWindow >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkWindow* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->ReleaseGraphicsResources(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkAbstractMapper::GetTimeToDraw()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_GetTimeToDraw::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_GetTimeToDraw::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetTimeToDraw();
  return AMILabType<double >::CreateVar(res);
}
/* The following types are missing: vtkPlane

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper::AddClippingPlane(vtkPlane * plane)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_AddClippingPlane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPlane, "parameter named 'plane'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_AddClippingPlane::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkPlane > plane_smtptr;
  if (!get_val_smtptr_param<vtkPlane >(plane_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkPlane* plane = plane_smtptr.get();

  this->_objectptr->GetObj()->AddClippingPlane(plane);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkPlane

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper::RemoveClippingPlane(vtkPlane * plane)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_RemoveClippingPlane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPlane, "parameter named 'plane'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_RemoveClippingPlane::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkPlane > plane_smtptr;
  if (!get_val_smtptr_param<vtkPlane >(plane_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkPlane* plane = plane_smtptr.get();

  this->_objectptr->GetObj()->RemoveClippingPlane(plane);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper::RemoveAllClippingPlanes()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_RemoveAllClippingPlanes::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_RemoveAllClippingPlanes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllClippingPlanes();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkPlaneCollection

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper::SetClippingPlanes(vtkPlaneCollection * param0)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_SetClippingPlanes_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPlaneCollection, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_SetClippingPlanes_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkPlaneCollection > param0_smtptr;
  if (!get_val_smtptr_param<vtkPlaneCollection >(param0_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkPlaneCollection* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetClippingPlanes(param0);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkPlaneCollection

//---------------------------------------------------
//  Wrapping of vtkPlaneCollection * vtkAbstractMapper::GetClippingPlanes()
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_GetClippingPlanes::SetParametersComments()
{
  return_comments="returning a variable of type vtkPlaneCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_GetClippingPlanes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPlaneCollection * res =   this->_objectptr->GetObj()->GetClippingPlanes();
  return AMILabType<vtkPlaneCollection >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkAbstractMapper::SetClippingPlanes(...)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_SetClippingPlanes::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_SetClippingPlanes::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkAbstractMapper::wrap_SetClippingPlanes_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper::SetClippingPlanes(vtkPlanes * planes)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_SetClippingPlanes_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPlanes, "parameter named 'planes'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_SetClippingPlanes_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkPlanes > planes_smtptr;
  if (!get_val_smtptr_param<vtkPlanes >(planes_smtptr,_p,_n)) ClassReturnEmptyVar;
  vtkPlanes* planes = planes_smtptr.get();

  this->_objectptr->GetObj()->SetClippingPlanes(planes);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkAbstractMapper::ShallowCopy(vtkAbstractMapper * m)
//---------------------------------------------------
void WrapClass_vtkAbstractMapper::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractMapper, "parameter named 'm'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAbstractMapper::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkAbstractMapper > m_smtptr;
  if (!get_val_smtptr_param<vtkAbstractMapper >(m_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkAbstractMapper* m = m_smtptr.get();

  this->_objectptr->GetObj()->ShallowCopy(m);
  return BasicVariable::ptr();
}

