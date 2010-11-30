/**
 * C++ Interface: wrap_vtkDataSet
 *
 * Description: wrapping vtkDataSet
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
#include "wrap_vtkDataSet.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkCellTypes.h"
#include "wrap_vtkDataObject.h"


#include "wrap_vtkDataSet.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkDataSet>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkDataSet);
AMI_DEFINE_VARFROMSMTPTR(vtkDataSet);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkDataSet>::CreateVar( vtkDataSet* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkDataSet> obj_ptr(val,smartpointer_nodeleter<vtkDataSet>());
  return AMILabType<vtkDataSet>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkDataSet
//
Variable<AMIObject>::ptr WrapClass_vtkDataSet::CreateVar( vtkDataSet* sp)
{
  boost::shared_ptr<vtkDataSet> di_ptr(
    sp,
    wxwindow_nodeleter<vtkDataSet>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkDataSet>::CreateVar(
      new WrapClass_vtkDataSet(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkDataSet::AddMethods(WrapClass<vtkDataSet>::ptr this_ptr )
{
  
      // Add members from vtkDataObject
      WrapClass_vtkDataObject::ptr parent_vtkDataObject(        boost::dynamic_pointer_cast<WrapClass_vtkDataObject >(this_ptr));
      parent_vtkDataObject->AddMethods(parent_vtkDataObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_CopyAttributes( this_ptr);
      AddVar_GetPoint( this_ptr);
      AddVar_GetCellBounds( this_ptr);
      AddVar_GetCellTypes( this_ptr);
/* The following types are missing: vtkIdList, vtkIdList
      AddVar_GetCellNeighbors( this_ptr);
*/
      AddVar_FindPoint( this_ptr);
/* The following types are missing: vtkCell, vtkCell
      AddVar_FindAndGetCell( this_ptr);
*/
      AddVar_GetMTime( this_ptr);
/* The following types are missing: vtkCellData
      AddVar_GetCellData( this_ptr);
*/
/* The following types are missing: vtkPointData
      AddVar_GetPointData( this_ptr);
*/
      AddVar_Squeeze( this_ptr);
      AddVar_ComputeBounds( this_ptr);
      AddVar_GetBounds_1( this_ptr);
      AddVar_GetBounds( this_ptr);
      AddVar_GetBounds_2( this_ptr);
      AddVar_GetCenter_1( this_ptr);
      AddVar_GetCenter( this_ptr);
      AddVar_GetCenter_2( this_ptr);
      AddVar_GetLength( this_ptr);
      AddVar_Initialize( this_ptr);
      AddVar_GetScalarRange_1( this_ptr);
      AddVar_GetScalarRange( this_ptr);
      AddVar_GetScalarRange_2( this_ptr);
      AddVar_GetActualMemorySize( this_ptr);
      AddVar_GetDataObjectType( this_ptr);
      AddVar_ShallowCopy( this_ptr);
      AddVar_DeepCopy( this_ptr);
      AddVar_CheckAttributes( this_ptr);
      AddVar_GenerateGhostLevelArray( this_ptr);
/* The following types are missing: vtkFieldData
      AddVar_GetAttributesAsFieldData( this_ptr);
*/
      AddVar_GetNumberOfElements( this_ptr);



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkDataSet::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkDataSet");
  
  // Static methods 
  WrapClass_vtkDataSet::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkDataSet::AddVar_SafeDownCast(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkDataSet::AddVar_GetData_1(amiobject->GetContext());
  */
  WrapClass_vtkDataSet::AddVar_GetData(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkDataSet::AddVar_GetData_2(amiobject->GetContext());
  */

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkDataSet::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkDataSet::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkDataSet * vtkDataSet::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkDataSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkDataSet * res =   vtkDataSet::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkDataSet::CreateVar(res);
  return res_var;
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkDataSet * vtkDataSet::GetData(vtkInformation * info)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_static_GetData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  return_comments="returning a variable of type vtkDataSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_static_GetData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkInformation* info = info_smtptr.get();

  vtkDataSet * res =   vtkDataSet::GetData(info);
  BasicVariable::ptr res_var = WrapClass_vtkDataSet::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkDataSet::GetData(...)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_static_GetData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_static_GetData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationVector

//---------------------------------------------------
//  Wrapping of vtkDataSet * vtkDataSet::GetData(vtkInformationVector * v, int i = 0)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_static_GetData_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i' (def:0)")
  return_comments="returning a variable of type vtkDataSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_static_GetData_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkInformationVector > v_smtptr;
  if (!get_val_smtptr_param<vtkInformationVector >(v_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkInformationVector* v = v_smtptr.get();

  int i = 0;
  if (!get_val_param<int >(i,_p,_n,false,true)) ClassReturnEmptyVar;

  vtkDataSet * res =   vtkDataSet::GetData(v, i);
  BasicVariable::ptr res_var = WrapClass_vtkDataSet::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of int vtkDataSet::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
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
//  Wrapping of vtkDataSet * vtkDataSet::NewInstance()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkDataSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkDataSet * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkDataSet::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkDataSet::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
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
//  Wrapping of void vtkDataSet::CopyAttributes(vtkDataSet * ds)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_CopyAttributes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataSet, "parameter named 'ds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_CopyAttributes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataSet > ds_smtptr;
  if (!get_val_smtptr_param<vtkDataSet >(ds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataSet* ds = ds_smtptr.get();

  this->_objectptr->GetObj()->CopyAttributes(ds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::GetPoint(vtkIdType id, double * x)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int id = boost::numeric_cast<long long int >(id_long);

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* x = x_smtptr.get();

  this->_objectptr->GetObj()->GetPoint(id, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::GetCellBounds(vtkIdType cellId, double * bounds)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetCellBounds::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetCellBounds::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  boost::shared_ptr<double > bounds_smtptr;
  if (!get_val_smtptr_param<double >(bounds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* bounds = bounds_smtptr.get();

  this->_objectptr->GetObj()->GetCellBounds(cellId, bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::GetCellTypes(vtkCellTypes * types)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetCellTypes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCellTypes, "parameter named 'types'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetCellTypes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkCellTypes > types_smtptr;
  if (!get_val_smtptr_param<vtkCellTypes >(types_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkCellTypes* types = types_smtptr.get();

  this->_objectptr->GetObj()->GetCellTypes(types);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkIdList, vtkIdList

//---------------------------------------------------
//  Wrapping of void vtkDataSet::GetCellNeighbors(vtkIdType cellId, vtkIdList * ptIds, vtkIdList * cellIds)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetCellNeighbors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'ptIds'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'cellIds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetCellNeighbors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  boost::shared_ptr<vtkIdList > ptIds_smtptr;
  if (!get_val_smtptr_param<vtkIdList >(ptIds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkIdList* ptIds = ptIds_smtptr.get();

  boost::shared_ptr<vtkIdList > cellIds_smtptr;
  if (!get_val_smtptr_param<vtkIdList >(cellIds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkIdList* cellIds = cellIds_smtptr.get();

  this->_objectptr->GetObj()->GetCellNeighbors(cellId, ptIds, cellIds);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of vtkIdType vtkDataSet::FindPoint(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_FindPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_FindPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,false)) ClassHelpAndReturn;

  double z;
  if (!get_val_param<double >(z,_p,_n,true,false)) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->FindPoint(x, y, z);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: vtkCell, vtkCell

//---------------------------------------------------
//  Wrapping of vtkCell * vtkDataSet::FindAndGetCell(double * x, vtkCell * cell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_FindAndGetCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( vtkCell, "parameter named 'cell'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'tol2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'subId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'pcoords'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'weights'")
  return_comments="returning a variable of type vtkCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_FindAndGetCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* x = x_smtptr.get();

  boost::shared_ptr<vtkCell > cell_smtptr;
  if (!get_val_smtptr_param<vtkCell >(cell_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkCell* cell = cell_smtptr.get();

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  double tol2;
  if (!get_val_param<double >(tol2,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<int > subId_smtptr;
  if (!get_val_smtptr_param<int >(subId_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int & subId = *subId_smtptr;

  boost::shared_ptr<double > pcoords_smtptr;
  if (!get_val_smtptr_param<double >(pcoords_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* pcoords = pcoords_smtptr.get();

  boost::shared_ptr<double > weights_smtptr;
  if (!get_val_smtptr_param<double >(weights_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* weights = weights_smtptr.get();

  vtkCell * res =   this->_objectptr->GetObj()->FindAndGetCell(x, cell, cellId, tol2, subId, pcoords, weights);
  return AMILabType<vtkCell >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of long unsigned int vtkDataSet::GetMTime()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: vtkCellData

//---------------------------------------------------
//  Wrapping of vtkCellData * vtkDataSet::GetCellData()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetCellData::SetParametersComments()
{
  return_comments="returning a variable of type vtkCellData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetCellData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCellData * res =   this->_objectptr->GetObj()->GetCellData();
  return AMILabType<vtkCellData >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkPointData

//---------------------------------------------------
//  Wrapping of vtkPointData * vtkDataSet::GetPointData()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetPointData::SetParametersComments()
{
  return_comments="returning a variable of type vtkPointData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetPointData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPointData * res =   this->_objectptr->GetObj()->GetPointData();
  return AMILabType<vtkPointData >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkDataSet::Squeeze()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_Squeeze::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_Squeeze::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Squeeze();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::ComputeBounds()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_ComputeBounds::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_ComputeBounds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeBounds();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkDataSet::GetBounds()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetBounds_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetBounds_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetBounds();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataSet::GetBounds(...)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetBounds::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataSet::wrap_GetBounds_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataSet::wrap_GetBounds_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::GetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetBounds_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetBounds_2::CallMember( ParamList* _p)
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
//  Wrapping of double * vtkDataSet::GetCenter()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetCenter_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetCenter_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetCenter();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataSet::GetCenter(...)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetCenter::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetCenter::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataSet::wrap_GetCenter_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataSet::wrap_GetCenter_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::GetCenter(double * center)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetCenter_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'center'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetCenter_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > center_smtptr;
  if (!get_val_smtptr_param<double >(center_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* center = center_smtptr.get();

  this->_objectptr->GetObj()->GetCenter(center);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkDataSet::GetLength()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetLength::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetLength::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetLength();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::Initialize()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_Initialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_Initialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Initialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::GetScalarRange(double * range)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetScalarRange_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'range'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetScalarRange_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > range_smtptr;
  if (!get_val_smtptr_param<double >(range_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* range = range_smtptr.get();

  this->_objectptr->GetObj()->GetScalarRange(range);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkDataSet::GetScalarRange(...)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetScalarRange::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetScalarRange::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkDataSet::wrap_GetScalarRange_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkDataSet::wrap_GetScalarRange_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of double * vtkDataSet::GetScalarRange()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetScalarRange_2::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetScalarRange_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetScalarRange();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkDataSet::GetActualMemorySize()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetActualMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetActualMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetActualMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of int vtkDataSet::GetDataObjectType()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetDataObjectType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetDataObjectType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataObjectType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::ShallowCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataObject > src_smtptr;
  if (!get_val_smtptr_param<vtkDataObject >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataObject* src = src_smtptr.get();

  this->_objectptr->GetObj()->ShallowCopy(src);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::DeepCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataObject > src_smtptr;
  if (!get_val_smtptr_param<vtkDataObject >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataObject* src = src_smtptr.get();

  this->_objectptr->GetObj()->DeepCopy(src);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkDataSet::CheckAttributes()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_CheckAttributes::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_CheckAttributes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->CheckAttributes();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkDataSet::GenerateGhostLevelArray()
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GenerateGhostLevelArray::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GenerateGhostLevelArray::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GenerateGhostLevelArray();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkFieldData

//---------------------------------------------------
//  Wrapping of vtkFieldData * vtkDataSet::GetAttributesAsFieldData(int type)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetAttributesAsFieldData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type vtkFieldData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetAttributesAsFieldData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,false)) ClassHelpAndReturn;

  vtkFieldData * res =   this->_objectptr->GetObj()->GetAttributesAsFieldData(type);
  return AMILabType<vtkFieldData >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of vtkIdType vtkDataSet::GetNumberOfElements(int type)
//---------------------------------------------------
void WrapClass_vtkDataSet::
    wrap_GetNumberOfElements::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkDataSet::
    wrap_GetNumberOfElements::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,false)) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfElements(type);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

