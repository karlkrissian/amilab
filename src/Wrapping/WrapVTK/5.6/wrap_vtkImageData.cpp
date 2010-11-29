/**
 * C++ Interface: wrap_vtkImageData
 *
 * Description: wrapping vtkImageData
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
#include "wrap_vtkImageData.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkDataSet.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkDataArray.h"
#include "wrap_vtkDataObject.h"


#include "wrap_vtkImageData.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkImageData>::CreateVar( ParamList* p)
{
  WrapClass_vtkImageData::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkImageData);
AMI_DEFINE_VARFROMSMTPTR(vtkImageData);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkImageData>::CreateVar( vtkImageData* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkImageData> obj_ptr(val,smartpointer_nodeleter<vtkImageData>());
  return AMILabType<vtkImageData>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkImageData
//
Variable<AMIObject>::ptr WrapClass_vtkImageData::CreateVar( vtkImageData* sp)
{
  boost::shared_ptr<vtkImageData> di_ptr(
    sp,
    wxwindow_nodeleter<vtkImageData>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkImageData>::CreateVar(
      new WrapClass_vtkImageData(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkImageData::AddMethods(WrapClass<vtkImageData>::ptr this_ptr )
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
      AddVar_CopyStructure( this_ptr);
      AddVar_GetDataObjectType( this_ptr);
      AddVar_GetNumberOfCells( this_ptr);
      AddVar_GetNumberOfPoints( this_ptr);
      AddVar_GetPoint_1( this_ptr);
      AddVar_GetPoint( this_ptr);
      AddVar_GetPoint_2( this_ptr);
/* The following types are missing: vtkCell
      AddVar_GetCell_1( this_ptr);
*/
      AddVar_GetCell( this_ptr);
/* The following types are missing: vtkGenericCell
      AddVar_GetCell_2( this_ptr);
*/
      AddVar_GetCellBounds( this_ptr);
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
/* The following types are missing: vtkCell, vtkCell
      AddVar_FindAndGetCell( this_ptr);
*/
      AddVar_GetCellType( this_ptr);
/* The following types are missing: vtkIdList
      AddVar_GetCellPoints( this_ptr);
*/
/* The following types are missing: vtkIdList
      AddVar_GetPointCells( this_ptr);
*/
      AddVar_ComputeBounds( this_ptr);
      AddVar_GetMaxCellSize( this_ptr);
      AddVar_Initialize( this_ptr);
      AddVar_SetDimensions_1( this_ptr);
      AddVar_SetDimensions( this_ptr);
      AddVar_SetDimensions_2( this_ptr);
      AddVar_GetDimensions_1( this_ptr);
      AddVar_GetDimensions( this_ptr);
      AddVar_GetDimensions_2( this_ptr);
      AddVar_ComputeStructuredCoordinates( this_ptr);
      AddVar_GetVoxelGradient( this_ptr);
      AddVar_GetPointGradient( this_ptr);
      AddVar_GetDataDimension( this_ptr);
      AddVar_ComputePointId( this_ptr);
      AddVar_ComputeCellId( this_ptr);
      AddVar_SetAxisUpdateExtent( this_ptr);
      AddVar_GetAxisUpdateExtent( this_ptr);
      AddVar_UpdateInformation( this_ptr);
      AddVar_SetExtent_1( this_ptr);
      AddVar_SetExtent( this_ptr);
      AddVar_SetExtent_2( this_ptr);
      AddVar_GetExtent_1( this_ptr);
      AddVar_GetExtent( this_ptr);
      AddVar_GetExtent_2( this_ptr);
      AddVar_GetExtent_3( this_ptr);
      AddVar_GetEstimatedMemorySize( this_ptr);
      AddVar_GetScalarTypeMin( this_ptr);
      AddVar_GetScalarTypeMax( this_ptr);
      AddVar_GetScalarSize( this_ptr);
      AddVar_GetIncrements_1( this_ptr);
      AddVar_GetIncrements( this_ptr);
      AddVar_GetIncrements_2( this_ptr);
      AddVar_GetIncrements_3( this_ptr);
      AddVar_GetContinuousIncrements( this_ptr);
      AddVar_GetScalarPointerForExtent( this_ptr);
      AddVar_GetScalarPointer_1( this_ptr);
      AddVar_GetScalarPointer( this_ptr);
      AddVar_GetScalarPointer_2( this_ptr);
      AddVar_GetScalarPointer_3( this_ptr);
      AddVar_GetScalarComponentAsFloat( this_ptr);
      AddVar_SetScalarComponentFromFloat( this_ptr);
      AddVar_GetScalarComponentAsDouble( this_ptr);
      AddVar_SetScalarComponentFromDouble( this_ptr);
      AddVar_AllocateScalars( this_ptr);
      AddVar_CopyAndCastFrom_1( this_ptr);
      AddVar_CopyAndCastFrom( this_ptr);
      AddVar_CopyAndCastFrom_2( this_ptr);
      AddVar_Crop( this_ptr);
      AddVar_GetActualMemorySize( this_ptr);
      AddVar_SetSpacing_1( this_ptr);
      AddVar_SetSpacing( this_ptr);
      AddVar_SetSpacing_2( this_ptr);
      AddVar_GetSpacing_1( this_ptr);
      AddVar_GetSpacing( this_ptr);
      AddVar_GetSpacing_2( this_ptr);
      AddVar_GetSpacing_3( this_ptr);
      AddVar_SetOrigin_1( this_ptr);
      AddVar_SetOrigin( this_ptr);
      AddVar_SetOrigin_2( this_ptr);
      AddVar_GetOrigin_1( this_ptr);
      AddVar_GetOrigin( this_ptr);
      AddVar_GetOrigin_2( this_ptr);
      AddVar_GetOrigin_3( this_ptr);
      AddVar_SetScalarTypeToFloat( this_ptr);
      AddVar_SetScalarTypeToDouble( this_ptr);
      AddVar_SetScalarTypeToInt( this_ptr);
      AddVar_SetScalarTypeToUnsignedInt( this_ptr);
      AddVar_SetScalarTypeToLong( this_ptr);
      AddVar_SetScalarTypeToUnsignedLong( this_ptr);
      AddVar_SetScalarTypeToShort( this_ptr);
      AddVar_SetScalarTypeToUnsignedShort( this_ptr);
      AddVar_SetScalarTypeToUnsignedChar( this_ptr);
      AddVar_SetScalarTypeToSignedChar( this_ptr);
      AddVar_SetScalarTypeToChar( this_ptr);
      AddVar_SetScalarType( this_ptr);
      AddVar_GetScalarType( this_ptr);
      AddVar_GetScalarTypeAsString( this_ptr);
      AddVar_SetNumberOfScalarComponents( this_ptr);
      AddVar_GetNumberOfScalarComponents( this_ptr);
      AddVar_CopyTypeSpecificInformation( this_ptr);
/* The following types are missing: vtkInformation, vtkInformation, vtkInformation
      AddVar_CopyInformationToPipeline( this_ptr);
*/
/* The following types are missing: vtkInformation
      AddVar_CopyInformationFromPipeline( this_ptr);
*/
      AddVar_PrepareForNewData( this_ptr);
      AddVar_ShallowCopy( this_ptr);
      AddVar_DeepCopy( this_ptr);
      AddVar_GetArrayPointerForExtent( this_ptr);
      AddVar_GetArrayPointer( this_ptr);
      AddVar_GetArrayIncrements( this_ptr);
      AddVar_ComputeInternalExtent( this_ptr);
      AddVar_GetExtentType( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkImageData * vtkImageData::New()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkImageData * res =   vtkImageData::New();
  BasicVariable::ptr res_var = WrapClass_vtkImageData::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkImageData::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkImageData::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkImageData::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkImageData * res =   vtkImageData::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkImageData::CreateVar(res);
  return res_var;
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkImageData::GetData(vtkInformation * info)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_static_GetData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_static_GetData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkInformation > info_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkInformation* info = info_smtptr.get();

  vtkImageData * res =   vtkImageData::GetData(info);
  BasicVariable::ptr res_var = WrapClass_vtkImageData::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkImageData::GetData(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_static_GetData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_static_GetData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationVector

//---------------------------------------------------
//  Wrapping of vtkImageData * vtkImageData::GetData(vtkInformationVector * v, int i = 0)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_static_GetData_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i' (def:0)")
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
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

  vtkImageData * res =   vtkImageData::GetData(v, i);
  BasicVariable::ptr res_var = WrapClass_vtkImageData::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of int vtkImageData::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
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
//  Wrapping of vtkImageData * vtkImageData::NewInstance()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkImageData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkImageData * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkImageData::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkImageData::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
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
//  Wrapping of void vtkImageData::CopyStructure(vtkDataSet * ds)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_CopyStructure::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataSet, "parameter named 'ds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_CopyStructure::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataSet > ds_smtptr;
  if (!get_val_smtptr_param<vtkDataSet >(ds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataSet* ds = ds_smtptr.get();

  this->_objectptr->GetObj()->CopyStructure(ds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkImageData::GetDataObjectType()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetDataObjectType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetDataObjectType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataObjectType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkImageData::GetNumberOfCells()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetNumberOfCells::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetNumberOfCells::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfCells();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkImageData::GetNumberOfPoints()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetNumberOfPoints::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetNumberOfPoints::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfPoints();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of double * vtkImageData::GetPoint(vtkIdType ptId)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ptId'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
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
//  Wrapping of multipled defined method:... vtkImageData::GetPoint(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_GetPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetPoint(vtkIdType id, double * x)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long id_long;
  if (!get_val_param<long >(id_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int id = boost::numeric_cast<long long int >(id_long);

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* x = x_smtptr.get();

  this->_objectptr->GetObj()->GetPoint(id, x);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkCell

//---------------------------------------------------
//  Wrapping of vtkCell * vtkImageData::GetCell(vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetCell_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  return_comments="returning a variable of type vtkCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetCell_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  vtkCell * res =   this->_objectptr->GetObj()->GetCell(cellId);
  return AMILabType<vtkCell >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::GetCell(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetCell::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetCell::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkGenericCell

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetCell(vtkIdType cellId, vtkGenericCell * cell)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetCell_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( vtkGenericCell, "parameter named 'cell'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetCell_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  boost::shared_ptr<vtkGenericCell > cell_smtptr;
  if (!get_val_smtptr_param<vtkGenericCell >(cell_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkGenericCell* cell = cell_smtptr.get();

  this->_objectptr->GetObj()->GetCell(cellId, cell);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetCellBounds(vtkIdType cellId, double * bounds)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetCellBounds::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
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
//  Wrapping of vtkIdType vtkImageData::FindPoint(double x, double y, double z)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_FindPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'z'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_FindPoint_1::CallMember( ParamList* _p)
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

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::FindPoint(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_FindPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_FindPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_FindPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_FindPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkImageData::FindPoint(double * x)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_FindPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_FindPoint_2::CallMember( ParamList* _p)
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
/* The following types are missing: vtkCell

//---------------------------------------------------
//  Wrapping of vtkIdType vtkImageData::FindCell(double * x, vtkCell * cell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)
//---------------------------------------------------
void WrapClass_vtkImageData::
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
BasicVariable::ptr WrapClass_vtkImageData::
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
//  Wrapping of multipled defined method:... vtkImageData::FindCell(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_FindCell::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_FindCell::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkCell, vtkGenericCell

//---------------------------------------------------
//  Wrapping of vtkIdType vtkImageData::FindCell(double * x, vtkCell * cell, vtkGenericCell * gencell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)
//---------------------------------------------------
void WrapClass_vtkImageData::
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
BasicVariable::ptr WrapClass_vtkImageData::
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
/* The following types are missing: vtkCell, vtkCell

//---------------------------------------------------
//  Wrapping of vtkCell * vtkImageData::FindAndGetCell(double * x, vtkCell * cell, vtkIdType cellId, double tol2, int & subId, double * pcoords, double * weights)
//---------------------------------------------------
void WrapClass_vtkImageData::
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
BasicVariable::ptr WrapClass_vtkImageData::
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
//  Wrapping of int vtkImageData::GetCellType(vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetCellType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetCellType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  int res =   this->_objectptr->GetObj()->GetCellType(cellId);
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkIdList

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetCellPoints(vtkIdType cellId, vtkIdList * ptIds)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetCellPoints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'ptIds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetCellPoints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  boost::shared_ptr<vtkIdList > ptIds_smtptr;
  if (!get_val_smtptr_param<vtkIdList >(ptIds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkIdList* ptIds = ptIds_smtptr.get();

  this->_objectptr->GetObj()->GetCellPoints(cellId, ptIds);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkIdList

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetPointCells(vtkIdType ptId, vtkIdList * cellIds)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetPointCells::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ptId'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'cellIds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetPointCells::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long ptId_long;
  if (!get_val_param<long >(ptId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int ptId = boost::numeric_cast<long long int >(ptId_long);

  boost::shared_ptr<vtkIdList > cellIds_smtptr;
  if (!get_val_smtptr_param<vtkIdList >(cellIds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkIdList* cellIds = cellIds_smtptr.get();

  this->_objectptr->GetObj()->GetPointCells(ptId, cellIds);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkImageData::ComputeBounds()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_ComputeBounds::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_ComputeBounds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeBounds();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkImageData::GetMaxCellSize()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetMaxCellSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetMaxCellSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaxCellSize();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::Initialize()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_Initialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_Initialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Initialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetDimensions(int i, int j, int k)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetDimensions_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'k'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetDimensions_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,true)) ClassReturnEmptyVar;

  int j;
  if (!get_val_param<int >(j,_p,_n,true,true)) ClassReturnEmptyVar;

  int k;
  if (!get_val_param<int >(k,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetDimensions(i, j, k);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::SetDimensions(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetDimensions::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetDimensions::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_SetDimensions_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_SetDimensions_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetDimensions(int const * dims)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetDimensions_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dims'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetDimensions_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > dims_smtptr;
  if (!get_val_smtptr_param<int >(dims_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* dims = dims_smtptr.get();

  this->_objectptr->GetObj()->SetDimensions(dims);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkImageData::GetDimensions()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetDimensions_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetDimensions_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetDimensions();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::GetDimensions(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetDimensions::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetDimensions::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_GetDimensions_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetDimensions_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetDimensions(int * dims)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetDimensions_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'dims'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetDimensions_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > dims_smtptr;
  if (!get_val_smtptr_param<int >(dims_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* dims = dims_smtptr.get();

  this->_objectptr->GetObj()->GetDimensions(dims);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkImageData::ComputeStructuredCoordinates(double * x, int * ijk, double * pcoords)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_ComputeStructuredCoordinates::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ijk'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'pcoords'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_ComputeStructuredCoordinates::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double > x_smtptr;
  if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* x = x_smtptr.get();

  boost::shared_ptr<int > ijk_smtptr;
  if (!get_val_smtptr_param<int >(ijk_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* ijk = ijk_smtptr.get();

  boost::shared_ptr<double > pcoords_smtptr;
  if (!get_val_smtptr_param<double >(pcoords_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* pcoords = pcoords_smtptr.get();

  int res =   this->_objectptr->GetObj()->ComputeStructuredCoordinates(x, ijk, pcoords);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetVoxelGradient(int i, int j, int k, vtkDataArray * s, vtkDataArray * g)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetVoxelGradient::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'k'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'g'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetVoxelGradient::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  int j;
  if (!get_val_param<int >(j,_p,_n,true,false)) ClassHelpAndReturn;

  int k;
  if (!get_val_param<int >(k,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<vtkDataArray > s_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* s = s_smtptr.get();

  boost::shared_ptr<vtkDataArray > g_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(g_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* g = g_smtptr.get();

  this->_objectptr->GetObj()->GetVoxelGradient(i, j, k, s, g);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetPointGradient(int i, int j, int k, vtkDataArray * s, double * g)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetPointGradient::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'j'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'k'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'g'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetPointGradient::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  int j;
  if (!get_val_param<int >(j,_p,_n,true,false)) ClassHelpAndReturn;

  int k;
  if (!get_val_param<int >(k,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<vtkDataArray > s_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* s = s_smtptr.get();

  boost::shared_ptr<double > g_smtptr;
  if (!get_val_smtptr_param<double >(g_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  double* g = g_smtptr.get();

  this->_objectptr->GetObj()->GetPointGradient(i, j, k, s, g);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkImageData::GetDataDimension()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetDataDimension::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetDataDimension::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataDimension();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkImageData::ComputePointId(int * ijk)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_ComputePointId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ijk'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_ComputePointId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > ijk_smtptr;
  if (!get_val_smtptr_param<int >(ijk_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* ijk = ijk_smtptr.get();

  vtkIdType res =   this->_objectptr->GetObj()->ComputePointId(ijk);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkImageData::ComputeCellId(int * ijk)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_ComputeCellId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ijk'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_ComputeCellId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > ijk_smtptr;
  if (!get_val_smtptr_param<int >(ijk_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* ijk = ijk_smtptr.get();

  vtkIdType res =   this->_objectptr->GetObj()->ComputeCellId(ijk);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetAxisUpdateExtent(int axis, int min, int max)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetAxisUpdateExtent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'axis'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'min'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'max'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetAxisUpdateExtent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int axis;
  if (!get_val_param<int >(axis,_p,_n,true,false)) ClassHelpAndReturn;

  int min;
  if (!get_val_param<int >(min,_p,_n,true,false)) ClassHelpAndReturn;

  int max;
  if (!get_val_param<int >(max,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAxisUpdateExtent(axis, min, max);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetAxisUpdateExtent(int axis, int & min, int & max)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetAxisUpdateExtent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'axis'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'min'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'max'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetAxisUpdateExtent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int axis;
  if (!get_val_param<int >(axis,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<int > min_smtptr;
  if (!get_val_smtptr_param<int >(min_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int & min = *min_smtptr;

  boost::shared_ptr<int > max_smtptr;
  if (!get_val_smtptr_param<int >(max_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int & max = *max_smtptr;

  this->_objectptr->GetObj()->GetAxisUpdateExtent(axis, min, max);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::UpdateInformation()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_UpdateInformation::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_UpdateInformation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateInformation();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetExtent(int * extent)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetExtent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetExtent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > extent_smtptr;
  if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* extent = extent_smtptr.get();

  this->_objectptr->GetObj()->SetExtent(extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::SetExtent(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetExtent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetExtent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_SetExtent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_SetExtent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetExtent(int x1, int x2, int y1, int y2, int z1, int z2)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetExtent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetExtent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  int x1;
  if (!get_val_param<int >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  int x2;
  if (!get_val_param<int >(x2,_p,_n,true,true)) ClassReturnEmptyVar;

  int y1;
  if (!get_val_param<int >(y1,_p,_n,true,true)) ClassReturnEmptyVar;

  int y2;
  if (!get_val_param<int >(y2,_p,_n,true,true)) ClassReturnEmptyVar;

  int z1;
  if (!get_val_param<int >(z1,_p,_n,true,true)) ClassReturnEmptyVar;

  int z2;
  if (!get_val_param<int >(z2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetExtent(x1, x2, y1, y2, z1, z2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkImageData::GetExtent()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetExtent_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetExtent_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetExtent();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::GetExtent(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetExtent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetExtent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_GetExtent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetExtent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetExtent_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetExtent(int & _arg1, int & _arg2, int & _arg3, int & _arg4, int & _arg5, int & _arg6)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetExtent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg3'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg4'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg5'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg6'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetExtent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg1_smtptr;
  if (!get_val_smtptr_param<int >(_arg1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & _arg1 = *_arg1_smtptr;

  boost::shared_ptr<int > _arg2_smtptr;
  if (!get_val_smtptr_param<int >(_arg2_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & _arg2 = *_arg2_smtptr;

  boost::shared_ptr<int > _arg3_smtptr;
  if (!get_val_smtptr_param<int >(_arg3_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & _arg3 = *_arg3_smtptr;

  boost::shared_ptr<int > _arg4_smtptr;
  if (!get_val_smtptr_param<int >(_arg4_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & _arg4 = *_arg4_smtptr;

  boost::shared_ptr<int > _arg5_smtptr;
  if (!get_val_smtptr_param<int >(_arg5_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & _arg5 = *_arg5_smtptr;

  boost::shared_ptr<int > _arg6_smtptr;
  if (!get_val_smtptr_param<int >(_arg6_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & _arg6 = *_arg6_smtptr;

  this->_objectptr->GetObj()->GetExtent(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetExtent(int * _arg)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetExtent_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetExtent_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetExtent(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkImageData::GetEstimatedMemorySize()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetEstimatedMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetEstimatedMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetEstimatedMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of double vtkImageData::GetScalarTypeMin()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarTypeMin::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarTypeMin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetScalarTypeMin();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkImageData::GetScalarTypeMax()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarTypeMax::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarTypeMax::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetScalarTypeMax();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkImageData::GetScalarSize()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScalarSize();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkIdType * vtkImageData::GetIncrements()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetIncrements_1::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetIncrements_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkIdType * res =   this->_objectptr->GetObj()->GetIncrements();
  long res_long = boost::numeric_cast<long >((unsigned int)*res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::GetIncrements(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetIncrements::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetIncrements::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_GetIncrements_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetIncrements_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetIncrements_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetIncrements(vtkIdType & incX, vtkIdType & incY, vtkIdType & incZ)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetIncrements_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'incX'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'incY'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'incZ'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetIncrements_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long long int > incX_smtptr;
  if (!get_val_smtptr_param<long long int >(incX_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkIdType & incX = *incX_smtptr;

  boost::shared_ptr<long long int > incY_smtptr;
  if (!get_val_smtptr_param<long long int >(incY_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkIdType & incY = *incY_smtptr;

  boost::shared_ptr<long long int > incZ_smtptr;
  if (!get_val_smtptr_param<long long int >(incZ_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkIdType & incZ = *incZ_smtptr;

  this->_objectptr->GetObj()->GetIncrements(incX, incY, incZ);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetIncrements(vtkIdType * inc)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetIncrements_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'inc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetIncrements_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long > inc_long;
  if (!get_val_smtptr_param<long >(inc_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long long int inc_val = boost::numeric_cast<long long int >(*inc_long);
  long long int* inc = &inc_val;

  this->_objectptr->GetObj()->GetIncrements(inc);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetContinuousIncrements(int * extent, vtkIdType & incX, vtkIdType & incY, vtkIdType & incZ)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetContinuousIncrements::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'incX'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'incY'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'incZ'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetContinuousIncrements::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > extent_smtptr;
  if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* extent = extent_smtptr.get();

  boost::shared_ptr<long long int > incX_smtptr;
  if (!get_val_smtptr_param<long long int >(incX_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkIdType & incX = *incX_smtptr;

  boost::shared_ptr<long long int > incY_smtptr;
  if (!get_val_smtptr_param<long long int >(incY_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkIdType & incY = *incY_smtptr;

  boost::shared_ptr<long long int > incZ_smtptr;
  if (!get_val_smtptr_param<long long int >(incZ_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkIdType & incZ = *incZ_smtptr;

  this->_objectptr->GetObj()->GetContinuousIncrements(extent, incX, incY, incZ);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void * vtkImageData::GetScalarPointerForExtent(int * extent)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarPointerForExtent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarPointerForExtent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > extent_smtptr;
  if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* extent = extent_smtptr.get();

  this->_objectptr->GetObj()->GetScalarPointerForExtent(extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void * vtkImageData::GetScalarPointer(int * coordinates)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarPointer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'coordinates'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarPointer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > coordinates_smtptr;
  if (!get_val_smtptr_param<int >(coordinates_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* coordinates = coordinates_smtptr.get();

  this->_objectptr->GetObj()->GetScalarPointer(coordinates);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::GetScalarPointer(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarPointer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarPointer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_GetScalarPointer_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetScalarPointer_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetScalarPointer_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void * vtkImageData::GetScalarPointer(int x, int y, int z)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarPointer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarPointer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int z;
  if (!get_val_param<int >(z,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->GetScalarPointer(x, y, z);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void * vtkImageData::GetScalarPointer()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarPointer_3::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarPointer_3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->GetScalarPointer();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkImageData::GetScalarComponentAsFloat(int x, int y, int z, int component)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarComponentAsFloat::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'component'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarComponentAsFloat::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  int z;
  if (!get_val_param<int >(z,_p,_n,true,false)) ClassHelpAndReturn;

  int component;
  if (!get_val_param<int >(component,_p,_n,true,false)) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetScalarComponentAsFloat(x, y, z, component);
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarComponentFromFloat(int x, int y, int z, int component, float v)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarComponentFromFloat::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'component'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarComponentFromFloat::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  int z;
  if (!get_val_param<int >(z,_p,_n,true,false)) ClassHelpAndReturn;

  int component;
  if (!get_val_param<int >(component,_p,_n,true,false)) ClassHelpAndReturn;

  float v;
  if (!get_val_param<float >(v,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarComponentFromFloat(x, y, z, component, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkImageData::GetScalarComponentAsDouble(int x, int y, int z, int component)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarComponentAsDouble::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'component'")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarComponentAsDouble::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  int z;
  if (!get_val_param<int >(z,_p,_n,true,false)) ClassHelpAndReturn;

  int component;
  if (!get_val_param<int >(component,_p,_n,true,false)) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetScalarComponentAsDouble(x, y, z, component);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarComponentFromDouble(int x, int y, int z, int component, double v)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarComponentFromDouble::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'component'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarComponentFromDouble::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  int z;
  if (!get_val_param<int >(z,_p,_n,true,false)) ClassHelpAndReturn;

  int component;
  if (!get_val_param<int >(component,_p,_n,true,false)) ClassHelpAndReturn;

  double v;
  if (!get_val_param<double >(v,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarComponentFromDouble(x, y, z, component, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::AllocateScalars()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_AllocateScalars::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_AllocateScalars::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AllocateScalars();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::CopyAndCastFrom(vtkImageData * inData, int * extent)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_CopyAndCastFrom_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkImageData, "parameter named 'inData'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_CopyAndCastFrom_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkImageData > inData_smtptr;
  if (!get_val_smtptr_param<vtkImageData >(inData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkImageData* inData = inData_smtptr.get();

  boost::shared_ptr<int > extent_smtptr;
  if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* extent = extent_smtptr.get();

  this->_objectptr->GetObj()->CopyAndCastFrom(inData, extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::CopyAndCastFrom(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_CopyAndCastFrom::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_CopyAndCastFrom::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_CopyAndCastFrom_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_CopyAndCastFrom_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::CopyAndCastFrom(vtkImageData * inData, int x0, int x1, int y0, int y1, int z0, int z1)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_CopyAndCastFrom_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkImageData, "parameter named 'inData'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_CopyAndCastFrom_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkImageData > inData_smtptr;
  if (!get_val_smtptr_param<vtkImageData >(inData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkImageData* inData = inData_smtptr.get();

  int x0;
  if (!get_val_param<int >(x0,_p,_n,true,true)) ClassReturnEmptyVar;

  int x1;
  if (!get_val_param<int >(x1,_p,_n,true,true)) ClassReturnEmptyVar;

  int y0;
  if (!get_val_param<int >(y0,_p,_n,true,true)) ClassReturnEmptyVar;

  int y1;
  if (!get_val_param<int >(y1,_p,_n,true,true)) ClassReturnEmptyVar;

  int z0;
  if (!get_val_param<int >(z0,_p,_n,true,true)) ClassReturnEmptyVar;

  int z1;
  if (!get_val_param<int >(z1,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->CopyAndCastFrom(inData, x0, x1, y0, y1, z0, z1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::Crop()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_Crop::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_Crop::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Crop();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkImageData::GetActualMemorySize()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetActualMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetActualMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetActualMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetSpacing(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetSpacing_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetSpacing_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetSpacing(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::SetSpacing(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetSpacing::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetSpacing::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_SetSpacing_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_SetSpacing_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetSpacing(double * _arg)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetSpacing_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetSpacing_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetSpacing(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkImageData::GetSpacing()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetSpacing_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetSpacing_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetSpacing();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::GetSpacing(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetSpacing::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetSpacing::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_GetSpacing_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetSpacing_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetSpacing_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetSpacing(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetSpacing_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetSpacing_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetSpacing(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetSpacing(double * _arg)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetSpacing_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetSpacing_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetSpacing(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetOrigin(double _arg1, double _arg2, double _arg3)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetOrigin_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetOrigin_1::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->SetOrigin(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::SetOrigin(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetOrigin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetOrigin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_SetOrigin_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_SetOrigin_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetOrigin(double * _arg)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetOrigin_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetOrigin_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetOrigin(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double * vtkImageData::GetOrigin()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetOrigin_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetOrigin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetOrigin();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkImageData::GetOrigin(...)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetOrigin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetOrigin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkImageData::wrap_GetOrigin_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetOrigin_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkImageData::wrap_GetOrigin_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetOrigin(double & _arg1, double & _arg2, double & _arg3)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetOrigin_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg2'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetOrigin_2::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->GetOrigin(_arg1, _arg2, _arg3);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetOrigin(double * _arg)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetOrigin_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetOrigin_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<double > _arg_smtptr;
  if (!get_val_smtptr_param<double >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->GetOrigin(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToFloat()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToFloat::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToFloat::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToFloat();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToDouble()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToDouble::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToDouble::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToDouble();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToInt()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToInt::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToInt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToInt();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToUnsignedInt()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToUnsignedInt::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToUnsignedInt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToUnsignedInt();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToLong()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToLong::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToLong();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToUnsignedLong()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToUnsignedLong::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToUnsignedLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToUnsignedLong();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToShort()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToShort::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToShort::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToShort();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToUnsignedShort()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToUnsignedShort::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToUnsignedShort::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToUnsignedShort();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToUnsignedChar()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToUnsignedChar::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToUnsignedChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToUnsignedChar();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToSignedChar()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToSignedChar::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToSignedChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToSignedChar();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarTypeToChar()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarTypeToChar::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarTypeToChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarTypeToChar();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetScalarType(int param0)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetScalarType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetScalarType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScalarType(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkImageData::GetScalarType()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetScalarType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of char const * vtkImageData::GetScalarTypeAsString()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetScalarTypeAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetScalarTypeAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetScalarTypeAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::SetNumberOfScalarComponents(int n)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_SetNumberOfScalarComponents::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_SetNumberOfScalarComponents::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNumberOfScalarComponents(n);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkImageData::GetNumberOfScalarComponents()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetNumberOfScalarComponents::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetNumberOfScalarComponents::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfScalarComponents();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::CopyTypeSpecificInformation(vtkDataObject * image)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_CopyTypeSpecificInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'image'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_CopyTypeSpecificInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataObject > image_smtptr;
  if (!get_val_smtptr_param<vtkDataObject >(image_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataObject* image = image_smtptr.get();

  this->_objectptr->GetObj()->CopyTypeSpecificInformation(image);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkInformation, vtkInformation, vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkImageData::CopyInformationToPipeline(vtkInformation * request, vtkInformation * input, vtkInformation * output, int forceCopy)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_CopyInformationToPipeline::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'request'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'input'")
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'output'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'forceCopy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_CopyInformationToPipeline::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > request_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(request_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* request = request_smtptr.get();

  boost::shared_ptr<vtkInformation > input_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(input_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* input = input_smtptr.get();

  boost::shared_ptr<vtkInformation > output_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(output_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* output = output_smtptr.get();

  int forceCopy;
  if (!get_val_param<int >(forceCopy,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CopyInformationToPipeline(request, input, output, forceCopy);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of void vtkImageData::CopyInformationFromPipeline(vtkInformation * request)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_CopyInformationFromPipeline::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'request'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_CopyInformationFromPipeline::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkInformation > request_smtptr;
  if (!get_val_smtptr_param<vtkInformation >(request_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkInformation* request = request_smtptr.get();

  this->_objectptr->GetObj()->CopyInformationFromPipeline(request);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkImageData::PrepareForNewData()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_PrepareForNewData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_PrepareForNewData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrepareForNewData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::ShallowCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
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
//  Wrapping of void vtkImageData::DeepCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
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
//  Wrapping of void * vtkImageData::GetArrayPointerForExtent(vtkDataArray * array, int * extent)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetArrayPointerForExtent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'array'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetArrayPointerForExtent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataArray > array_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(array_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* array = array_smtptr.get();

  boost::shared_ptr<int > extent_smtptr;
  if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* extent = extent_smtptr.get();

  this->_objectptr->GetObj()->GetArrayPointerForExtent(array, extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void * vtkImageData::GetArrayPointer(vtkDataArray * array, int * coordinates)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetArrayPointer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'array'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'coordinates'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetArrayPointer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataArray > array_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(array_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* array = array_smtptr.get();

  boost::shared_ptr<int > coordinates_smtptr;
  if (!get_val_smtptr_param<int >(coordinates_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* coordinates = coordinates_smtptr.get();

  this->_objectptr->GetObj()->GetArrayPointer(array, coordinates);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::GetArrayIncrements(vtkDataArray * array, vtkIdType * increments)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetArrayIncrements::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'array'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'increments'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetArrayIncrements::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkDataArray > array_smtptr;
  if (!get_val_smtptr_param<vtkDataArray >(array_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkDataArray* array = array_smtptr.get();

  boost::shared_ptr<long > increments_long;
  if (!get_val_smtptr_param<long >(increments_long,_p,_n,true,false,false)) ClassHelpAndReturn;
  long long int increments_val = boost::numeric_cast<long long int >(*increments_long);
  long long int* increments = &increments_val;

  this->_objectptr->GetObj()->GetArrayIncrements(array, increments);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkImageData::ComputeInternalExtent(int * intExt, int * tgtExt, int * bnds)
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_ComputeInternalExtent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'intExt'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tgtExt'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bnds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_ComputeInternalExtent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > intExt_smtptr;
  if (!get_val_smtptr_param<int >(intExt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* intExt = intExt_smtptr.get();

  boost::shared_ptr<int > tgtExt_smtptr;
  if (!get_val_smtptr_param<int >(tgtExt_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* tgtExt = tgtExt_smtptr.get();

  boost::shared_ptr<int > bnds_smtptr;
  if (!get_val_smtptr_param<int >(bnds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* bnds = bnds_smtptr.get();

  this->_objectptr->GetObj()->ComputeInternalExtent(intExt, tgtExt, bnds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkImageData::GetExtentType()
//---------------------------------------------------
void WrapClass_vtkImageData::
    wrap_GetExtentType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkImageData::
    wrap_GetExtentType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetExtentType();
  return AMILabType<int >::CreateVar(res);
}

