/**
 * C++ Interface: wrap_vtkPointSet
 *
 * Description: wrapping vtkPointSet
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
#include "wrap_vtkPointSet.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkDataSet.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkPoints.h"
#include "wrap_vtkDataObject.h"


#include "wrap_vtkPointSet.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkPointSet>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkPointSet);
AMI_DEFINE_VARFROMSMTPTR(vtkPointSet);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkPointSet>::CreateVar( vtkPointSet* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkPointSet> obj_ptr(val,smartpointer_nodeleter<vtkPointSet>());
  return AMILabType<vtkPointSet>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkPointSet
//
Variable<AMIObject>::ptr WrapClass_vtkPointSet::CreateVar( vtkPointSet* sp)
{
  boost::shared_ptr<vtkPointSet> di_ptr(
    sp,
    wxwindow_nodeleter<vtkPointSet>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkPointSet>::CreateVar(
      new WrapClass_vtkPointSet(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkPointSet::AddMethods(WrapClass<vtkPointSet>::ptr this_ptr )
{
  
      // Add members from vtkDataSet
      WrapClass_vtkDataSet::ptr parent_vtkDataSet(        boost::dynamic_pointer_cast<WrapClass_vtkDataSet >(this_ptr));
      parent_vtkDataSet->AddMethods(parent_vtkDataSet);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_Initialize( this_ptr);
      AddVar_CopyStructure( this_ptr);
      AddVar_GetNumberOfPoints( this_ptr);
      AddVar_GetPoint_1( this_ptr);
      AddVar_GetPoint( this_ptr);
      AddVar_GetPoint_2( this_ptr);
      AddVar_FindPoint_1( this_ptr);
      AddVar_FindPoint( this_ptr);
      AddVar_FindPoint_2( this_ptr);
/* The following types are missing: vtkCell
      AddVar_FindCell_1( this_ptr);
*/
      AddVar_FindCell( this_ptr);
/* The following types are missing: vtkCell, vtkGenericCell
      AddVar_FindCell_2( this_ptr);
*/
      AddVar_GetMTime( this_ptr);
      AddVar_ComputeBounds( this_ptr);
      AddVar_Squeeze( this_ptr);
      AddVar_SetPoints( this_ptr);
      AddVar_GetPoints( this_ptr);
      AddVar_GetActualMemorySize( this_ptr);
      AddVar_ShallowCopy( this_ptr);
      AddVar_DeepCopy( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkPointSet::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkPointSet::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPointSet * vtkPointSet::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkPointSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkPointSet * res =   vtkPointSet::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkPointSet::CreateVar(res);
  return res_var;
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkPointSet * vtkPointSet::GetData(vtkInformation * info)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_static_GetData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  return_comments="returning a variable of type vtkPointSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_static_GetData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkInformation* info = info_smtptr.get();

  vtkPointSet * res =   vtkPointSet::GetData(info);
  BasicVariable::ptr res_var = WrapClass_vtkPointSet::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkPointSet::GetData(...)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_static_GetData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_static_GetData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationVector

//---------------------------------------------------
//  Wrapping of vtkPointSet * vtkPointSet::GetData(vtkInformationVector * v, int i = 0)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_static_GetData_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i' (def:0)")
  return_comments="returning a variable of type vtkPointSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
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

  vtkPointSet * res =   vtkPointSet::GetData(v, i);
  BasicVariable::ptr res_var = WrapClass_vtkPointSet::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of int vtkPointSet::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
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
//  Wrapping of vtkPointSet * vtkPointSet::NewInstance()
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkPointSet";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPointSet * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkPointSet::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkPointSet::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
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
//  Wrapping of void vtkPointSet::Initialize()
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_Initialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_Initialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Initialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPointSet::CopyStructure(vtkDataSet * pd)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_CopyStructure::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataSet, "parameter named 'pd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_CopyStructure::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataSet > pd_smtptr;
  if (!get_val_smtptr_param<vtkDataSet >(pd_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataSet* pd = pd_smtptr.get();

  this->_objectptr->GetObj()->CopyStructure(pd);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPointSet::GetNumberOfPoints()
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_GetNumberOfPoints::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_GetNumberOfPoints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfPoints();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of double * vtkPointSet::GetPoint(vtkIdType ptId)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_GetPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ptId'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_GetPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ptId_long;
  if (!get_val_param<long >(ptId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int ptId = boost::numeric_cast<long long int >(ptId_long);

  double * res =   this->_objectptr->GetObj()->GetPoint(ptId);
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPointSet::GetPoint(...)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_GetPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_GetPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPointSet::wrap_GetPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPointSet::wrap_GetPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPointSet::GetPoint(vtkIdType ptId, double * x)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_GetPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ptId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_GetPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long ptId_long;
  if (!get_val_param<long >(ptId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int ptId = boost::numeric_cast<long long int >(ptId_long);

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  this->_objectptr->GetObj()->GetPoint(ptId, x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPointSet::FindPoint(double * x)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_FindPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_FindPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  vtkIdType res =   this->_objectptr->GetObj()->FindPoint(x);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPointSet::FindPoint(...)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_FindPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_FindPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPointSet::wrap_FindPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPointSet::wrap_FindPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPointSet::FindPoint(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_FindPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_FindPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  double z;
  if (!get_val_param<double >(z,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkIdType res =   this->_objectptr->GetObj()->FindPoint(x, y, z);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: vtkCell

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPointSet::FindCell(double * x, vtkCell * cell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_FindCell_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( vtkCell, "parameter named 'cell'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'tol2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'subId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'pcoords'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'weights'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_FindCell_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  boost::shared_ptr<vtkCell > cell_smtptr;
  if (!get_val_smtptr_param<vtkCell >(cell_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkCell* cell = cell_smtptr.get();

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  double tol2;
  if (!get_val_param<double >(tol2,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<int > subId_smtptr;
  if (!get_val_smtptr_param<int >(subId_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & subId = *subId_smtptr;

  boost::shared_ptr<double > pcoords_smtptr;
  if (!get_val_smtptr_param<double >(pcoords_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* pcoords = pcoords_smtptr.get();

  boost::shared_ptr<double > weights_smtptr;
  if (!get_val_smtptr_param<double >(weights_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* weights = weights_smtptr.get();

  vtkIdType res =   this->_objectptr->GetObj()->FindCell(x, cell, cellId, tol2, subId, pcoords, weights);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPointSet::FindCell(...)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_FindCell::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_FindCell::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkCell, vtkGenericCell

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPointSet::FindCell(double * x, vtkCell * cell, vtkGenericCell * gencell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_FindCell_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( vtkCell, "parameter named 'cell'")
  ADDPARAMCOMMENT_TYPE( vtkGenericCell, "parameter named 'gencell'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'tol2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'subId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'pcoords'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'weights'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_FindCell_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>8) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  boost::shared_ptr<vtkCell > cell_smtptr;
  if (!get_val_smtptr_param<vtkCell >(cell_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkCell* cell = cell_smtptr.get();

  boost::shared_ptr<vtkGenericCell > gencell_smtptr;
  if (!get_val_smtptr_param<vtkGenericCell >(gencell_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkGenericCell* gencell = gencell_smtptr.get();

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  double tol2;
  if (!get_val_param<double >(tol2,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<int > subId_smtptr;
  if (!get_val_smtptr_param<int >(subId_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & subId = *subId_smtptr;

  boost::shared_ptr<double > pcoords_smtptr;
  if (!get_val_smtptr_param<double >(pcoords_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* pcoords = pcoords_smtptr.get();

  boost::shared_ptr<double > weights_smtptr;
  if (!get_val_smtptr_param<double >(weights_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* weights = weights_smtptr.get();

  vtkIdType res =   this->_objectptr->GetObj()->FindCell(x, cell, gencell, cellId, tol2, subId, pcoords, weights);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of long unsigned int vtkPointSet::GetMTime()
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkPointSet::ComputeBounds()
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_ComputeBounds::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_ComputeBounds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeBounds();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPointSet::Squeeze()
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_Squeeze::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_Squeeze::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Squeeze();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPointSet::SetPoints(vtkPoints * param0)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_SetPoints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPoints, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_SetPoints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkPoints > param0_smtptr;
  if (!get_val_smtptr_param<vtkPoints >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkPoints* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetPoints(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkPoints * vtkPointSet::GetPoints()
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_GetPoints::SetParametersComments()
{
  return_comments="returning a variable of type vtkPoints";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_GetPoints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPoints * res =   this->_objectptr->GetObj()->GetPoints();
  BasicVariable::ptr res_var = WrapClass_vtkPoints::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkPointSet::GetActualMemorySize()
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_GetActualMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
    wrap_GetActualMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetActualMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkPointSet::ShallowCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
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
//  Wrapping of void vtkPointSet::DeepCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkPointSet::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPointSet::
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

