/**
 * C++ Interface: wrap_vtkPolyData
 *
 * Description: wrapping vtkPolyData
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

#include "wrap_vtkPolyData.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkPolyData_declared
  #define vtkPolyData_declared
  AMI_DECLARE_TYPE(vtkPolyData)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkDataSet_declared
  #define vtkDataSet_declared
  AMI_DECLARE_TYPE(vtkDataSet)
#endif
#ifndef vtkDataObject_declared
  #define vtkDataObject_declared
  AMI_DECLARE_TYPE(vtkDataObject)
#endif
#ifndef vtkDataArray_declared
  #define vtkDataArray_declared
  AMI_DECLARE_TYPE(vtkDataArray)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkPolyData>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkPolyData);
AMI_DEFINE_VARFROMSMTPTR(vtkPolyData);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkPolyData>::CreateVar( vtkPolyData* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkPolyData> obj_ptr(val,smartpointer_nodeleter<vtkPolyData>());
  return AMILabType<vtkPolyData>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkPolyData
//
Variable<AMIObject>::ptr WrapClass_vtkPolyData::CreateVar( vtkPolyData* sp)
{
  boost::shared_ptr<vtkPolyData> di_ptr(
    sp,
    wxwindow_nodeleter<vtkPolyData>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkPolyData>::CreateVar(
      new WrapClass_vtkPolyData(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkPolyData::AddMethods(WrapClass<vtkPolyData>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_GetDataObjectType( this_ptr);
  AddVar_CopyStructure( this_ptr);
  AddVar_GetNumberOfCells( this_ptr);
/* The following types are missing: vtkCell
  AddVar_GetCell_1( this_ptr);
*/
  AddVar_GetCell( this_ptr);
/* The following types are missing: vtkGenericCell
  AddVar_GetCell_2( this_ptr);
*/
  AddVar_GetCellType( this_ptr);
  AddVar_GetCellBounds( this_ptr);
/* The following types are missing: vtkIdList, vtkIdList
  AddVar_GetCellNeighbors( this_ptr);
*/
/* The following types are missing: vtkIdList, vtkPointLocator
  AddVar_CopyCells( this_ptr);
*/
  AddVar_ComputeBounds( this_ptr);
  AddVar_Squeeze( this_ptr);
  AddVar_GetMaxCellSize( this_ptr);
/* The following types are missing: vtkCellArray
  AddVar_SetVerts( this_ptr);
*/
/* The following types are missing: vtkCellArray
  AddVar_GetVerts( this_ptr);
*/
/* The following types are missing: vtkCellArray
  AddVar_SetLines( this_ptr);
*/
/* The following types are missing: vtkCellArray
  AddVar_GetLines( this_ptr);
*/
/* The following types are missing: vtkCellArray
  AddVar_SetPolys( this_ptr);
*/
/* The following types are missing: vtkCellArray
  AddVar_GetPolys( this_ptr);
*/
/* The following types are missing: vtkCellArray
  AddVar_SetStrips( this_ptr);
*/
/* The following types are missing: vtkCellArray
  AddVar_GetStrips( this_ptr);
*/
  AddVar_GetNumberOfVerts( this_ptr);
  AddVar_GetNumberOfLines( this_ptr);
  AddVar_GetNumberOfPolys( this_ptr);
  AddVar_GetNumberOfStrips( this_ptr);
  AddVar_Allocate_1( this_ptr);
  AddVar_Allocate( this_ptr);
  AddVar_Allocate_2( this_ptr);
  AddVar_InsertNextCell_1( this_ptr);
  AddVar_InsertNextCell( this_ptr);
/* The following types are missing: vtkIdList
  AddVar_InsertNextCell_2( this_ptr);
*/
  AddVar_Reset( this_ptr);
  AddVar_BuildCells( this_ptr);
  AddVar_BuildLinks( this_ptr);
  AddVar_DeleteCells( this_ptr);
  AddVar_DeleteLinks( this_ptr);
/* The following types are missing: vtkIdList
  AddVar_GetCellEdgeNeighbors( this_ptr);
*/
  AddVar_IsTriangle( this_ptr);
  AddVar_IsEdge( this_ptr);
  AddVar_IsPointUsedByCell( this_ptr);
  AddVar_ReplaceCell( this_ptr);
  AddVar_ReplaceCellPoint( this_ptr);
  AddVar_ReverseCell( this_ptr);
  AddVar_DeletePoint( this_ptr);
  AddVar_DeleteCell( this_ptr);
  AddVar_RemoveDeletedCells( this_ptr);
  AddVar_InsertNextLinkedPoint_1( this_ptr);
  AddVar_InsertNextLinkedPoint( this_ptr);
  AddVar_InsertNextLinkedPoint_2( this_ptr);
  AddVar_InsertNextLinkedCell( this_ptr);
  AddVar_ReplaceLinkedCell( this_ptr);
  AddVar_RemoveCellReference( this_ptr);
  AddVar_AddCellReference( this_ptr);
  AddVar_RemoveReferenceToCell( this_ptr);
  AddVar_AddReferenceToCell( this_ptr);
  AddVar_ResizeCellList( this_ptr);
  AddVar_Initialize( this_ptr);
  AddVar_GetUpdateExtent_1( this_ptr);
  AddVar_GetUpdateExtent( this_ptr);
  AddVar_GetUpdateExtent_2( this_ptr);
  AddVar_GetUpdateExtent_3( this_ptr);
  AddVar_GetUpdateExtent_4( this_ptr);
  AddVar_GetPiece( this_ptr);
  AddVar_GetNumberOfPieces( this_ptr);
  AddVar_GetGhostLevel( this_ptr);
  AddVar_GetActualMemorySize( this_ptr);
  AddVar_ShallowCopy( this_ptr);
  AddVar_DeepCopy( this_ptr);
  AddVar_RemoveGhostCells( this_ptr);
  AddVar_GetScalarFieldCriticalIndex_1( this_ptr);
  AddVar_GetScalarFieldCriticalIndex( this_ptr);
  AddVar_GetScalarFieldCriticalIndex_2( this_ptr);
  AddVar_GetScalarFieldCriticalIndex_3( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  
  AMIObject::ptr obj_enum_94(new AMIObject);
  obj_enum_94->SetName("enum_94");

  BasicVariable::ptr var_ERR_NO_SUCH_FIELD = AMILabType<int >::CreateVar(-4);
  if (var_ERR_NO_SUCH_FIELD.get()) {
    var_ERR_NO_SUCH_FIELD->Rename("ERR_NO_SUCH_FIELD");
    obj_enum_94->GetContext()->AddVar(var_ERR_NO_SUCH_FIELD,obj_enum_94->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_enum_94->GetName().c_str(),obj_enum_94,context);


  // Adding Bases

  // Add base parent vtkPointSet
  boost::shared_ptr<vtkPointSet > parent_vtkPointSet(  boost::dynamic_pointer_cast<vtkPointSet >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkPointSet = AMILabType<vtkPointSet >::CreateVarFromSmtPtr(parent_vtkPointSet);
  context->AddVar("vtkPointSet",var_vtkPointSet);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkPointSet = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkPointSet);
  context->AddDefault(obj_vtkPointSet->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkPolyData_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkPolyData");
  
  // Static methods 
  WrapClass_vtkPolyData::AddVar_New(amiobject->GetContext());
  WrapClass_vtkPolyData::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkPolyData::AddVar_SafeDownCast(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkPolyData::AddVar_GetData_1(amiobject->GetContext());
  */
  WrapClass_vtkPolyData::AddVar_GetData(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkPolyData::AddVar_GetData_2(amiobject->GetContext());
  */

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkPolyData * vtkPolyData::New()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkPolyData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPolyData * res =   vtkPolyData::New();
  BasicVariable::ptr res_var = AMILabType<vtkPolyData >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkPolyData::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPolyData * vtkPolyData::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkPolyData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
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

  vtkPolyData * res =   vtkPolyData::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkPolyData >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: vtkInformation

//---------------------------------------------------
//  Wrapping of vtkPolyData * vtkPolyData::GetData(vtkInformation * info)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_static_GetData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformation, "parameter named 'info'")
  return_comments="returning a variable of type vtkPolyData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_static_GetData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkInformation* info;
  if (CheckNullVar(_p,_n))  {
    info=(vtkInformation*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformation > info_smtptr;
    if (!get_val_smtptr_param<vtkInformation >(info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    info = info_smtptr.get();
  }

  vtkPolyData * res =   vtkPolyData::GetData(info);
  BasicVariable::ptr res_var = AMILabType<vtkPolyData >::CreateVar(res,true);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkPolyData::GetData(...)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_static_GetData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_static_GetData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkInformationVector

//---------------------------------------------------
//  Wrapping of vtkPolyData * vtkPolyData::GetData(vtkInformationVector * v, int i = 0)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_static_GetData_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkInformationVector, "parameter named 'v'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i' (def:0)")
  return_comments="returning a variable of type vtkPolyData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_static_GetData_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  vtkInformationVector* v;
  if (CheckNullVar(_p,_n))  {
    v=(vtkInformationVector*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkInformationVector > v_smtptr;
    if (!get_val_smtptr_param<vtkInformationVector >(v_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    v = v_smtptr.get();
  }

  int i = 0;
  if (!get_val_param<int >(i,_p,_n,false,true)) ClassReturnEmptyVar;

  vtkPolyData * res =   vtkPolyData::GetData(v, i);
  BasicVariable::ptr res_var = AMILabType<vtkPolyData >::CreateVar(res,true);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of int vtkPolyData::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
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
//  Wrapping of vtkPolyData * vtkPolyData::NewInstance()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkPolyData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPolyData * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkPolyData >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkPolyData::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
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
//  Wrapping of int vtkPolyData::GetDataObjectType()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetDataObjectType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetDataObjectType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDataObjectType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::CopyStructure(vtkDataSet * ds)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_CopyStructure::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataSet, "parameter named 'ds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_CopyStructure::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataSet* ds;
  if (CheckNullVar(_p,_n))  {
    ds=(vtkDataSet*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataSet > ds_smtptr;
    if (!get_val_smtptr_param<vtkDataSet >(ds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ds = ds_smtptr.get();
  }

  this->_objectptr->GetObj()->CopyStructure(ds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPolyData::GetNumberOfCells()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetNumberOfCells::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetNumberOfCells::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfCells();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: vtkCell

//---------------------------------------------------
//  Wrapping of vtkCell * vtkPolyData::GetCell(vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetCell_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  return_comments="returning a variable of type vtkCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
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
//  Wrapping of multipled defined method:... vtkPolyData::GetCell(...)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetCell::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetCell::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkGenericCell

//---------------------------------------------------
//  Wrapping of void vtkPolyData::GetCell(vtkIdType cellId, vtkGenericCell * cell)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetCell_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( vtkGenericCell, "parameter named 'cell'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetCell_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  vtkGenericCell* cell;
  if (CheckNullVar(_p,_n))  {
    cell=(vtkGenericCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkGenericCell > cell_smtptr;
    if (!get_val_smtptr_param<vtkGenericCell >(cell_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    cell = cell_smtptr.get();
  }

  this->_objectptr->GetObj()->GetCell(cellId, cell);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of int vtkPolyData::GetCellType(vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetCellType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
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

//---------------------------------------------------
//  Wrapping of void vtkPolyData::GetCellBounds(vtkIdType cellId, double * bounds)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetCellBounds::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetCellBounds::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  double* bounds;
  if (CheckNullVar(_p,_n))  {
    bounds=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > bounds_smtptr;
    if (!get_val_smtptr_param<double >(bounds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    bounds = bounds_smtptr.get();
  }

  this->_objectptr->GetObj()->GetCellBounds(cellId, bounds);
  return BasicVariable::ptr();
}
/* The following types are missing: vtkIdList, vtkIdList

//---------------------------------------------------
//  Wrapping of void vtkPolyData::GetCellNeighbors(vtkIdType cellId, vtkIdList * ptIds, vtkIdList * cellIds)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetCellNeighbors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'ptIds'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'cellIds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetCellNeighbors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  vtkIdList* ptIds;
  if (CheckNullVar(_p,_n))  {
    ptIds=(vtkIdList*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkIdList > ptIds_smtptr;
    if (!get_val_smtptr_param<vtkIdList >(ptIds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ptIds = ptIds_smtptr.get();
  }

  vtkIdList* cellIds;
  if (CheckNullVar(_p,_n))  {
    cellIds=(vtkIdList*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkIdList > cellIds_smtptr;
    if (!get_val_smtptr_param<vtkIdList >(cellIds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    cellIds = cellIds_smtptr.get();
  }

  this->_objectptr->GetObj()->GetCellNeighbors(cellId, ptIds, cellIds);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkIdList, vtkPointLocator

//---------------------------------------------------
//  Wrapping of void vtkPolyData::CopyCells(vtkPolyData * pd, vtkIdList * idList, vtkPointLocator * locator = 0l)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_CopyCells::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPolyData, "parameter named 'pd'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'idList'")
  ADDPARAMCOMMENT_TYPE( vtkPointLocator, "parameter named 'locator' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_CopyCells::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
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

  vtkIdList* idList;
  if (CheckNullVar(_p,_n))  {
    idList=(vtkIdList*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkIdList > idList_smtptr;
    if (!get_val_smtptr_param<vtkIdList >(idList_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    idList = idList_smtptr.get();
  }

  vtkPointLocator* locator = 0l;
  if (CheckNullVar(_p,_n))  {
    locator=(vtkPointLocator*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPointLocator > locator_smtptr;
    if (!get_val_smtptr_param<vtkPointLocator >(locator_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    locator = locator_smtptr.get();
  }

  this->_objectptr->GetObj()->CopyCells(pd, idList, locator);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkPolyData::ComputeBounds()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_ComputeBounds::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_ComputeBounds::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeBounds();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::Squeeze()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_Squeeze::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_Squeeze::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Squeeze();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::GetMaxCellSize()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetMaxCellSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetMaxCellSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaxCellSize();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkCellArray

//---------------------------------------------------
//  Wrapping of void vtkPolyData::SetVerts(vtkCellArray * v)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_SetVerts::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCellArray, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_SetVerts::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkCellArray* v;
  if (CheckNullVar(_p,_n))  {
    v=(vtkCellArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkCellArray > v_smtptr;
    if (!get_val_smtptr_param<vtkCellArray >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    v = v_smtptr.get();
  }

  this->_objectptr->GetObj()->SetVerts(v);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkCellArray

//---------------------------------------------------
//  Wrapping of vtkCellArray * vtkPolyData::GetVerts()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetVerts::SetParametersComments()
{
  return_comments="returning a variable of type vtkCellArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetVerts::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCellArray * res =   this->_objectptr->GetObj()->GetVerts();
  return AMILabType<vtkCellArray >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkCellArray

//---------------------------------------------------
//  Wrapping of void vtkPolyData::SetLines(vtkCellArray * l)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_SetLines::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCellArray, "parameter named 'l'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_SetLines::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkCellArray* l;
  if (CheckNullVar(_p,_n))  {
    l=(vtkCellArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkCellArray > l_smtptr;
    if (!get_val_smtptr_param<vtkCellArray >(l_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    l = l_smtptr.get();
  }

  this->_objectptr->GetObj()->SetLines(l);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkCellArray

//---------------------------------------------------
//  Wrapping of vtkCellArray * vtkPolyData::GetLines()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetLines::SetParametersComments()
{
  return_comments="returning a variable of type vtkCellArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetLines::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCellArray * res =   this->_objectptr->GetObj()->GetLines();
  return AMILabType<vtkCellArray >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkCellArray

//---------------------------------------------------
//  Wrapping of void vtkPolyData::SetPolys(vtkCellArray * p)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_SetPolys::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCellArray, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_SetPolys::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkCellArray* p;
  if (CheckNullVar(_p,_n))  {
    p=(vtkCellArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkCellArray > p_smtptr;
    if (!get_val_smtptr_param<vtkCellArray >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    p = p_smtptr.get();
  }

  this->_objectptr->GetObj()->SetPolys(p);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkCellArray

//---------------------------------------------------
//  Wrapping of vtkCellArray * vtkPolyData::GetPolys()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetPolys::SetParametersComments()
{
  return_comments="returning a variable of type vtkCellArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetPolys::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCellArray * res =   this->_objectptr->GetObj()->GetPolys();
  return AMILabType<vtkCellArray >::CreateVar(res,true);
}
*/
/* The following types are missing: vtkCellArray

//---------------------------------------------------
//  Wrapping of void vtkPolyData::SetStrips(vtkCellArray * s)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_SetStrips::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkCellArray, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_SetStrips::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkCellArray* s;
  if (CheckNullVar(_p,_n))  {
    s=(vtkCellArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkCellArray > s_smtptr;
    if (!get_val_smtptr_param<vtkCellArray >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    s = s_smtptr.get();
  }

  this->_objectptr->GetObj()->SetStrips(s);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vtkCellArray

//---------------------------------------------------
//  Wrapping of vtkCellArray * vtkPolyData::GetStrips()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetStrips::SetParametersComments()
{
  return_comments="returning a variable of type vtkCellArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetStrips::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCellArray * res =   this->_objectptr->GetObj()->GetStrips();
  return AMILabType<vtkCellArray >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPolyData::GetNumberOfVerts()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetNumberOfVerts::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetNumberOfVerts::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfVerts();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPolyData::GetNumberOfLines()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetNumberOfLines::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetNumberOfLines::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfLines();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPolyData::GetNumberOfPolys()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetNumberOfPolys::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetNumberOfPolys::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfPolys();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkIdType vtkPolyData::GetNumberOfStrips()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetNumberOfStrips::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetNumberOfStrips::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIdType res =   this->_objectptr->GetObj()->GetNumberOfStrips();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::Allocate(vtkIdType numCells = 1000, int extSize = 1000)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_Allocate_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'numCells' (def:1000)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extSize' (def:1000)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_Allocate_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long numCells_long = boost::numeric_cast<long >((unsigned int)1000);;
  if (!get_val_param<long >(numCells_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long long int numCells = boost::numeric_cast<long long int >(numCells_long);

  int extSize = 1000;
  if (!get_val_param<int >(extSize,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Allocate(numCells, extSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPolyData::Allocate(...)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_Allocate::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_Allocate::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPolyData::wrap_Allocate_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPolyData::wrap_Allocate_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::Allocate(vtkPolyData * inPolyData, vtkIdType numCells = 1000, int extSize = 1000)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_Allocate_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPolyData, "parameter named 'inPolyData'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'numCells' (def:1000)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extSize' (def:1000)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_Allocate_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  vtkPolyData* inPolyData;
  if (CheckNullVar(_p,_n))  {
    inPolyData=(vtkPolyData*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPolyData > inPolyData_smtptr;
    if (!get_val_smtptr_param<vtkPolyData >(inPolyData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    inPolyData = inPolyData_smtptr.get();
  }

  long numCells_long = boost::numeric_cast<long >((unsigned int)1000);;
  if (!get_val_param<long >(numCells_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long long int numCells = boost::numeric_cast<long long int >(numCells_long);

  int extSize = 1000;
  if (!get_val_param<int >(extSize,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Allocate(inPolyData, numCells, extSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::InsertNextCell(int type, int npts, vtkIdType * pts)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_InsertNextCell_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'npts'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pts'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_InsertNextCell_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,true)) ClassReturnEmptyVar;

  int npts;
  if (!get_val_param<int >(npts,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<long > pts_long;
  if (!get_val_smtptr_param<long >(pts_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long long int pts_val = boost::numeric_cast<long long int >(*pts_long);
  long long int* pts = &pts_val;

  int res =   this->_objectptr->GetObj()->InsertNextCell(type, npts, pts);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPolyData::InsertNextCell(...)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_InsertNextCell::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_InsertNextCell::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPolyData::wrap_InsertNextCell_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: vtkIdList

//---------------------------------------------------
//  Wrapping of int vtkPolyData::InsertNextCell(int type, vtkIdList * pts)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_InsertNextCell_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'pts'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_InsertNextCell_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkIdList* pts;
  if (CheckNullVar(_p,_n))  {
    pts=(vtkIdList*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkIdList > pts_smtptr;
    if (!get_val_smtptr_param<vtkIdList >(pts_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    pts = pts_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->InsertNextCell(type, pts);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkPolyData::Reset()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_Reset::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_Reset::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Reset();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::BuildCells()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_BuildCells::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_BuildCells::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BuildCells();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::BuildLinks(int initialSize = 0)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_BuildLinks::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'initialSize' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_BuildLinks::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int initialSize = 0;
  if (!get_val_param<int >(initialSize,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BuildLinks(initialSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::DeleteCells()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_DeleteCells::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_DeleteCells::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DeleteCells();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::DeleteLinks()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_DeleteLinks::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_DeleteLinks::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DeleteLinks();
  return BasicVariable::ptr();
}
/* The following types are missing: vtkIdList

//---------------------------------------------------
//  Wrapping of void vtkPolyData::GetCellEdgeNeighbors(vtkIdType cellId, vtkIdType p1, vtkIdType p2, vtkIdList * cellIds)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetCellEdgeNeighbors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'p1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'p2'")
  ADDPARAMCOMMENT_TYPE( vtkIdList, "parameter named 'cellIds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetCellEdgeNeighbors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  long p1_long;
  if (!get_val_param<long >(p1_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int p1 = boost::numeric_cast<long long int >(p1_long);

  long p2_long;
  if (!get_val_param<long >(p2_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int p2 = boost::numeric_cast<long long int >(p2_long);

  vtkIdList* cellIds;
  if (CheckNullVar(_p,_n))  {
    cellIds=(vtkIdList*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkIdList > cellIds_smtptr;
    if (!get_val_smtptr_param<vtkIdList >(cellIds_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    cellIds = cellIds_smtptr.get();
  }

  this->_objectptr->GetObj()->GetCellEdgeNeighbors(cellId, p1, p2, cellIds);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of int vtkPolyData::IsTriangle(int v1, int v2, int v3)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_IsTriangle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v3'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_IsTriangle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int v1;
  if (!get_val_param<int >(v1,_p,_n,true,false)) ClassHelpAndReturn;

  int v2;
  if (!get_val_param<int >(v2,_p,_n,true,false)) ClassHelpAndReturn;

  int v3;
  if (!get_val_param<int >(v3,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsTriangle(v1, v2, v3);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::IsEdge(vtkIdType p1, vtkIdType p2)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_IsEdge::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'p1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'p2'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_IsEdge::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long p1_long;
  if (!get_val_param<long >(p1_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int p1 = boost::numeric_cast<long long int >(p1_long);

  long p2_long;
  if (!get_val_param<long >(p2_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int p2 = boost::numeric_cast<long long int >(p2_long);

  int res =   this->_objectptr->GetObj()->IsEdge(p1, p2);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::IsPointUsedByCell(vtkIdType ptId, vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_IsPointUsedByCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ptId'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_IsPointUsedByCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long ptId_long;
  if (!get_val_param<long >(ptId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int ptId = boost::numeric_cast<long long int >(ptId_long);

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  int res =   this->_objectptr->GetObj()->IsPointUsedByCell(ptId, cellId);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::ReplaceCell(vtkIdType cellId, int npts, vtkIdType * pts)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_ReplaceCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'npts'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pts'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_ReplaceCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  int npts;
  if (!get_val_param<int >(npts,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<long > pts_long;
  if (!get_val_smtptr_param<long >(pts_long,_p,_n,true,false,false)) ClassHelpAndReturn;
  long long int pts_val = boost::numeric_cast<long long int >(*pts_long);
  long long int* pts = &pts_val;

  this->_objectptr->GetObj()->ReplaceCell(cellId, npts, pts);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::ReplaceCellPoint(vtkIdType cellId, vtkIdType oldPtId, vtkIdType newPtId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_ReplaceCellPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'oldPtId'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'newPtId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_ReplaceCellPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  long oldPtId_long;
  if (!get_val_param<long >(oldPtId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int oldPtId = boost::numeric_cast<long long int >(oldPtId_long);

  long newPtId_long;
  if (!get_val_param<long >(newPtId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int newPtId = boost::numeric_cast<long long int >(newPtId_long);

  this->_objectptr->GetObj()->ReplaceCellPoint(cellId, oldPtId, newPtId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::ReverseCell(vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_ReverseCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_ReverseCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  this->_objectptr->GetObj()->ReverseCell(cellId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::DeletePoint(vtkIdType ptId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_DeletePoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ptId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_DeletePoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long ptId_long;
  if (!get_val_param<long >(ptId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int ptId = boost::numeric_cast<long long int >(ptId_long);

  this->_objectptr->GetObj()->DeletePoint(ptId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::DeleteCell(vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_DeleteCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_DeleteCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  this->_objectptr->GetObj()->DeleteCell(cellId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::RemoveDeletedCells()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_RemoveDeletedCells::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_RemoveDeletedCells::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveDeletedCells();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::InsertNextLinkedPoint(int numLinks)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_InsertNextLinkedPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numLinks'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_InsertNextLinkedPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int numLinks;
  if (!get_val_param<int >(numLinks,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->InsertNextLinkedPoint(numLinks);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPolyData::InsertNextLinkedPoint(...)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_InsertNextLinkedPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_InsertNextLinkedPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPolyData::wrap_InsertNextLinkedPoint_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPolyData::wrap_InsertNextLinkedPoint_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::InsertNextLinkedPoint(double * x, int numLinks)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_InsertNextLinkedPoint_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numLinks'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_InsertNextLinkedPoint_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  double* x;
  if (CheckNullVar(_p,_n))  {
    x=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > x_smtptr;
    if (!get_val_smtptr_param<double >(x_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    x = x_smtptr.get();
  }

  int numLinks;
  if (!get_val_param<int >(numLinks,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->InsertNextLinkedPoint(x, numLinks);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::InsertNextLinkedCell(int type, int npts, vtkIdType * pts)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_InsertNextLinkedCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'npts'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pts'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_InsertNextLinkedCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,false)) ClassHelpAndReturn;

  int npts;
  if (!get_val_param<int >(npts,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<long > pts_long;
  if (!get_val_smtptr_param<long >(pts_long,_p,_n,true,false,false)) ClassHelpAndReturn;
  long long int pts_val = boost::numeric_cast<long long int >(*pts_long);
  long long int* pts = &pts_val;

  int res =   this->_objectptr->GetObj()->InsertNextLinkedCell(type, npts, pts);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::ReplaceLinkedCell(vtkIdType cellId, int npts, vtkIdType * pts)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_ReplaceLinkedCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'npts'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pts'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_ReplaceLinkedCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  int npts;
  if (!get_val_param<int >(npts,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<long > pts_long;
  if (!get_val_smtptr_param<long >(pts_long,_p,_n,true,false,false)) ClassHelpAndReturn;
  long long int pts_val = boost::numeric_cast<long long int >(*pts_long);
  long long int* pts = &pts_val;

  this->_objectptr->GetObj()->ReplaceLinkedCell(cellId, npts, pts);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::RemoveCellReference(vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_RemoveCellReference::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_RemoveCellReference::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  this->_objectptr->GetObj()->RemoveCellReference(cellId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::AddCellReference(vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_AddCellReference::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_AddCellReference::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  this->_objectptr->GetObj()->AddCellReference(cellId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::RemoveReferenceToCell(vtkIdType ptId, vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_RemoveReferenceToCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ptId'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_RemoveReferenceToCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long ptId_long;
  if (!get_val_param<long >(ptId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int ptId = boost::numeric_cast<long long int >(ptId_long);

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  this->_objectptr->GetObj()->RemoveReferenceToCell(ptId, cellId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::AddReferenceToCell(vtkIdType ptId, vtkIdType cellId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_AddReferenceToCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ptId'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'cellId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_AddReferenceToCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long ptId_long;
  if (!get_val_param<long >(ptId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int ptId = boost::numeric_cast<long long int >(ptId_long);

  long cellId_long;
  if (!get_val_param<long >(cellId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int cellId = boost::numeric_cast<long long int >(cellId_long);

  this->_objectptr->GetObj()->AddReferenceToCell(ptId, cellId);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::ResizeCellList(vtkIdType ptId, int size)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_ResizeCellList::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ptId'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_ResizeCellList::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long ptId_long;
  if (!get_val_param<long >(ptId_long,_p,_n,true,false)) ClassHelpAndReturn;
  long long int ptId = boost::numeric_cast<long long int >(ptId_long);

  int size;
  if (!get_val_param<int >(size,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ResizeCellList(ptId, size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::Initialize()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_Initialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_Initialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Initialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::GetUpdateExtent(int & piece, int & numPieces, int & ghostLevel)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetUpdateExtent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'piece'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'numPieces'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ghostLevel'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetUpdateExtent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > piece_smtptr;
  if (!get_val_smtptr_param<int >(piece_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & piece = *piece_smtptr;

  boost::shared_ptr<int > numPieces_smtptr;
  if (!get_val_smtptr_param<int >(numPieces_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & numPieces = *numPieces_smtptr;

  boost::shared_ptr<int > ghostLevel_smtptr;
  if (!get_val_smtptr_param<int >(ghostLevel_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & ghostLevel = *ghostLevel_smtptr;

  this->_objectptr->GetObj()->GetUpdateExtent(piece, numPieces, ghostLevel);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPolyData::GetUpdateExtent(...)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetUpdateExtent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetUpdateExtent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPolyData::wrap_GetUpdateExtent_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPolyData::wrap_GetUpdateExtent_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkPolyData::wrap_GetUpdateExtent_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkPolyData::wrap_GetUpdateExtent_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int * vtkPolyData::GetUpdateExtent()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetUpdateExtent_2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetUpdateExtent_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetUpdateExtent();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::GetUpdateExtent(int & x0, int & x1, int & y0, int & y1, int & z0, int & z1)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetUpdateExtent_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'z1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetUpdateExtent_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > x0_smtptr;
  if (!get_val_smtptr_param<int >(x0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & x0 = *x0_smtptr;

  boost::shared_ptr<int > x1_smtptr;
  if (!get_val_smtptr_param<int >(x1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & x1 = *x1_smtptr;

  boost::shared_ptr<int > y0_smtptr;
  if (!get_val_smtptr_param<int >(y0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & y0 = *y0_smtptr;

  boost::shared_ptr<int > y1_smtptr;
  if (!get_val_smtptr_param<int >(y1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & y1 = *y1_smtptr;

  boost::shared_ptr<int > z0_smtptr;
  if (!get_val_smtptr_param<int >(z0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & z0 = *z0_smtptr;

  boost::shared_ptr<int > z1_smtptr;
  if (!get_val_smtptr_param<int >(z1_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int & z1 = *z1_smtptr;

  this->_objectptr->GetObj()->GetUpdateExtent(x0, x1, y0, y1, z0, z1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::GetUpdateExtent(int * extent)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetUpdateExtent_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'extent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetUpdateExtent_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int* extent;
  if (CheckNullVar(_p,_n))  {
    extent=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > extent_smtptr;
    if (!get_val_smtptr_param<int >(extent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    extent = extent_smtptr.get();
  }

  this->_objectptr->GetObj()->GetUpdateExtent(extent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::GetPiece()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetPiece::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetPiece::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPiece();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::GetNumberOfPieces()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetNumberOfPieces::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetNumberOfPieces::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfPieces();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::GetGhostLevel()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetGhostLevel::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetGhostLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetGhostLevel();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkPolyData::GetActualMemorySize()
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetActualMemorySize::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetActualMemorySize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetActualMemorySize();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::ShallowCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataObject* src;
  if (CheckNullVar(_p,_n))  {
    src=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > src_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    src = src_smtptr.get();
  }

  this->_objectptr->GetObj()->ShallowCopy(src);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::DeepCopy(vtkDataObject * src)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_DeepCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkDataObject, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_DeepCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkDataObject* src;
  if (CheckNullVar(_p,_n))  {
    src=(vtkDataObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataObject > src_smtptr;
    if (!get_val_smtptr_param<vtkDataObject >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    src = src_smtptr.get();
  }

  this->_objectptr->GetObj()->DeepCopy(src);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyData::RemoveGhostCells(int level)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_RemoveGhostCells::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'level'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_RemoveGhostCells::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int level;
  if (!get_val_param<int >(level,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveGhostCells(level);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::GetScalarFieldCriticalIndex(vtkIdType pointId, vtkDataArray * scalarField)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetScalarFieldCriticalIndex_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pointId'")
  ADDPARAMCOMMENT_TYPE( vtkDataArray, "parameter named 'scalarField'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetScalarFieldCriticalIndex_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pointId_long;
  if (!get_val_param<long >(pointId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int pointId = boost::numeric_cast<long long int >(pointId_long);

  vtkDataArray* scalarField;
  if (CheckNullVar(_p,_n))  {
    scalarField=(vtkDataArray*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkDataArray > scalarField_smtptr;
    if (!get_val_smtptr_param<vtkDataArray >(scalarField_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    scalarField = scalarField_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->GetScalarFieldCriticalIndex(pointId, scalarField);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPolyData::GetScalarFieldCriticalIndex(...)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetScalarFieldCriticalIndex::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetScalarFieldCriticalIndex::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPolyData::wrap_GetScalarFieldCriticalIndex_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPolyData::wrap_GetScalarFieldCriticalIndex_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkPolyData::wrap_GetScalarFieldCriticalIndex_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::GetScalarFieldCriticalIndex(vtkIdType pointId, int fieldId)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetScalarFieldCriticalIndex_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pointId'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldId'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetScalarFieldCriticalIndex_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pointId_long;
  if (!get_val_param<long >(pointId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int pointId = boost::numeric_cast<long long int >(pointId_long);

  int fieldId;
  if (!get_val_param<int >(fieldId,_p,_n,true,true)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->GetScalarFieldCriticalIndex(pointId, fieldId);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkPolyData::GetScalarFieldCriticalIndex(vtkIdType pointId, char const * fieldName)
//---------------------------------------------------
void WrapClass_vtkPolyData::
    wrap_GetScalarFieldCriticalIndex_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pointId'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'fieldName'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyData::
    wrap_GetScalarFieldCriticalIndex_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pointId_long;
  if (!get_val_param<long >(pointId_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int pointId = boost::numeric_cast<long long int >(pointId_long);

  boost::shared_ptr<std::string > fieldName_string;
  if (!get_val_smtptr_param<std::string >(fieldName_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * fieldName = fieldName_string->c_str();

  int res =   this->_objectptr->GetObj()->GetScalarFieldCriticalIndex(pointId, fieldName);
  return AMILabType<int >::CreateVar(res);
}

