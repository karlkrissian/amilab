/**
 * C++ Interface: wrap_wxDynamicLibraryDetailsArray
 *
 * Description: wrapping wxDynamicLibraryDetailsArray
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxDynamicLibraryDetailsArray.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxDynamicLibraryDetailsArray_declared
  #define wxDynamicLibraryDetailsArray_declared
  AMI_DECLARE_TYPE(wxDynamicLibraryDetailsArray)
#endif
#ifndef wxDynamicLibraryDetails_declared
  #define wxDynamicLibraryDetails_declared
  AMI_DECLARE_TYPE(wxDynamicLibraryDetails)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxDynamicLibraryDetailsArray>::CreateVar( ParamList* p)
{
  WrapClass_wxDynamicLibraryDetailsArray::wrap_wxDynamicLibraryDetailsArray construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxDynamicLibraryDetailsArray);
AMI_DEFINE_VARFROMSMTPTR(wxDynamicLibraryDetailsArray);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDynamicLibraryDetailsArray
//
Variable<AMIObject>::ptr WrapClass_wxDynamicLibraryDetailsArray::CreateVar( wxDynamicLibraryDetailsArray* sp)
{
  boost::shared_ptr<wxDynamicLibraryDetailsArray> di_ptr(
    sp,
    wxwindow_nodeleter<wxDynamicLibraryDetailsArray>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDynamicLibraryDetailsArray>::CreateVar(
      new WrapClass_wxDynamicLibraryDetailsArray(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::AddMethods(WrapClass<wxDynamicLibraryDetailsArray>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Alloc( this_ptr);
  AddVar_GetCount( this_ptr);
  AddVar_size( this_ptr);
  AddVar_IsEmpty( this_ptr);
  AddVar_empty( this_ptr);
  AddVar_Count( this_ptr);
  AddVar_Shrink( this_ptr);
  AddVar_Item( this_ptr);
  AddVar_Last( this_ptr);
  AddVar_Index( this_ptr);
  AddVar_Add_1( this_ptr);
  AddVar_Add( this_ptr);
  AddVar_Add_2( this_ptr);
  AddVar_push_back_1( this_ptr);
  AddVar_push_back( this_ptr);
  AddVar_push_back_2( this_ptr);
  AddVar_Insert_1( this_ptr);
  AddVar_Insert( this_ptr);
  AddVar_Insert_2( this_ptr);
  AddVar_Empty( this_ptr);
  AddVar_Clear( this_ptr);
  AddVar_Detach( this_ptr);
  AddVar_RemoveAt( this_ptr);
/* The following types are missing: _11355
  AddVar_Sort( this_ptr);
*/

  // Adding operators
  AddVar___assign__( this_ptr);
  AddVar___at__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDynamicLibraryDetailsArray_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxDynamicLibraryDetailsArray");
    WrapClass_wxDynamicLibraryDetailsArray::AddVar_wxDynamicLibraryDetailsArray_1(amiobject->GetContext());
  WrapClass_wxDynamicLibraryDetailsArray::AddVar_wxDynamicLibraryDetailsArray(amiobject->GetContext());
  WrapClass_wxDynamicLibraryDetailsArray::AddVar_wxDynamicLibraryDetailsArray_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxDynamicLibraryDetailsArray::wxDynamicLibraryDetailsArray()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_wxDynamicLibraryDetailsArray_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_wxDynamicLibraryDetailsArray_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxDynamicLibraryDetailsArray* _newobj = new wxDynamicLibraryDetailsArray();
  BasicVariable::ptr res = WrapClass_wxDynamicLibraryDetailsArray::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxDynamicLibraryDetailsArray::wxDynamicLibraryDetailsArray(...)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_wxDynamicLibraryDetailsArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_wxDynamicLibraryDetailsArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDynamicLibraryDetailsArray::wrap_wxDynamicLibraryDetailsArray_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDynamicLibraryDetailsArray::wrap_wxDynamicLibraryDetailsArray_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDynamicLibraryDetailsArray::wxDynamicLibraryDetailsArray(wxDynamicLibraryDetailsArray const & src)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_wxDynamicLibraryDetailsArray_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetailsArray, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_wxDynamicLibraryDetailsArray_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDynamicLibraryDetailsArray > src_smtptr;
  if (!get_val_smtptr_param<wxDynamicLibraryDetailsArray >(src_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxDynamicLibraryDetailsArray const & src = *src_smtptr;

  wxDynamicLibraryDetailsArray* _newobj = new wxDynamicLibraryDetailsArray(src);
  BasicVariable::ptr res = WrapClass_wxDynamicLibraryDetailsArray::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxDynamicLibraryDetailsArray.
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxDynamicLibraryDetailsArray object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxDynamicLibraryDetailsArray >::CreateVar( new wxDynamicLibraryDetailsArray(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::Alloc(size_t count)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Alloc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Alloc::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long count_long;
  if (!get_val_param<long >(count_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  this->_objectptr->GetObj()->Alloc(count);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxDynamicLibraryDetailsArray::GetCount()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_GetCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_GetCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxDynamicLibraryDetailsArray::size()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxDynamicLibraryDetailsArray::IsEmpty()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDynamicLibraryDetailsArray::empty()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxDynamicLibraryDetailsArray::Count()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Count::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Count::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->Count();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::Shrink()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Shrink::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Shrink::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Shrink();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxDynamicLibraryDetailsArray & wxDynamicLibraryDetailsArray::Item(size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Item::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxDynamicLibraryDetails";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Item::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxObjArraywxDynamicLibraryDetailsArray & res =   this->_objectptr->GetObj()->Item(uiIndex);
  return AMILabType<wxDynamicLibraryDetails >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxDynamicLibraryDetailsArray & wxDynamicLibraryDetailsArray::Last()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Last::SetParametersComments()
{
  return_comments="returning a variable of type wxDynamicLibraryDetails";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Last::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  _wxObjArraywxDynamicLibraryDetailsArray & res =   this->_objectptr->GetObj()->Last();
  return AMILabType<wxDynamicLibraryDetails >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDynamicLibraryDetailsArray::Index(_wxObjArraywxDynamicLibraryDetailsArray const & lItem, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Index::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetails, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bFromEnd' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Index::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDynamicLibraryDetails > lItem_smtptr;
  if (!get_val_smtptr_param<wxDynamicLibraryDetails >(lItem_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  _wxObjArraywxDynamicLibraryDetailsArray const & lItem = *lItem_smtptr;

  bool bFromEnd = false;
  if (!get_val_param<bool >(bFromEnd,_p,_n,false,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->Index(lItem, bFromEnd);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::Add(_wxObjArraywxDynamicLibraryDetailsArray const & lItem, size_t nInsert = 1)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Add_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetails, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nInsert' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Add_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDynamicLibraryDetails > lItem_smtptr;
  if (!get_val_smtptr_param<wxDynamicLibraryDetails >(lItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxObjArraywxDynamicLibraryDetailsArray const & lItem = *lItem_smtptr;

  long nInsert_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(nInsert_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long unsigned int nInsert = boost::numeric_cast<long unsigned int >(nInsert_long);

  this->_objectptr->GetObj()->Add(lItem, nInsert);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDynamicLibraryDetailsArray::Add(...)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Add::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Add::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDynamicLibraryDetailsArray::wrap_Add_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDynamicLibraryDetailsArray::wrap_Add_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::Add(_wxObjArraywxDynamicLibraryDetailsArray const * pItem)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Add_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetails, "parameter named 'pItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Add_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxDynamicLibraryDetails* pItem;
  if (CheckNullVar(_p,_n))  {
    pItem=(wxDynamicLibraryDetails*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDynamicLibraryDetails > pItem_smtptr;
    if (!get_val_smtptr_param<wxDynamicLibraryDetails >(pItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    pItem = pItem_smtptr.get();
  }

  this->_objectptr->GetObj()->Add(pItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::push_back(_wxObjArraywxDynamicLibraryDetailsArray const * pItem)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_push_back_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetails, "parameter named 'pItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_push_back_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxDynamicLibraryDetails* pItem;
  if (CheckNullVar(_p,_n))  {
    pItem=(wxDynamicLibraryDetails*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDynamicLibraryDetails > pItem_smtptr;
    if (!get_val_smtptr_param<wxDynamicLibraryDetails >(pItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    pItem = pItem_smtptr.get();
  }

  this->_objectptr->GetObj()->push_back(pItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDynamicLibraryDetailsArray::push_back(...)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_push_back::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_push_back::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDynamicLibraryDetailsArray::wrap_push_back_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDynamicLibraryDetailsArray::wrap_push_back_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::push_back(_wxObjArraywxDynamicLibraryDetailsArray const & lItem)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_push_back_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetails, "parameter named 'lItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_push_back_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDynamicLibraryDetails > lItem_smtptr;
  if (!get_val_smtptr_param<wxDynamicLibraryDetails >(lItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxObjArraywxDynamicLibraryDetailsArray const & lItem = *lItem_smtptr;

  this->_objectptr->GetObj()->push_back(lItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::Insert(_wxObjArraywxDynamicLibraryDetailsArray const & lItem, size_t uiIndex, size_t nInsert = 1)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetails, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nInsert' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDynamicLibraryDetails > lItem_smtptr;
  if (!get_val_smtptr_param<wxDynamicLibraryDetails >(lItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxObjArraywxDynamicLibraryDetailsArray const & lItem = *lItem_smtptr;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  long nInsert_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(nInsert_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long unsigned int nInsert = boost::numeric_cast<long unsigned int >(nInsert_long);

  this->_objectptr->GetObj()->Insert(lItem, uiIndex, nInsert);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxDynamicLibraryDetailsArray::Insert(...)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDynamicLibraryDetailsArray::wrap_Insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDynamicLibraryDetailsArray::wrap_Insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::Insert(_wxObjArraywxDynamicLibraryDetailsArray const * pItem, size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetails, "parameter named 'pItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxDynamicLibraryDetails* pItem;
  if (CheckNullVar(_p,_n))  {
    pItem=(wxDynamicLibraryDetails*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDynamicLibraryDetails > pItem_smtptr;
    if (!get_val_smtptr_param<wxDynamicLibraryDetails >(pItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    pItem = pItem_smtptr.get();
  }

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  this->_objectptr->GetObj()->Insert(pItem, uiIndex);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::Empty()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Empty::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Empty();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::Clear()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxDynamicLibraryDetailsArray * wxDynamicLibraryDetailsArray::Detach(size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Detach::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxDynamicLibraryDetails";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Detach::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxObjArraywxDynamicLibraryDetailsArray * res =   this->_objectptr->GetObj()->Detach(uiIndex);
  BasicVariable::ptr res_var = AMILabType<wxDynamicLibraryDetails >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::RemoveAt(size_t uiIndex, size_t nRemove = 1)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_RemoveAt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRemove' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_RemoveAt::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  long nRemove_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(nRemove_long,_p,_n,false,false)) ClassHelpAndReturn;
  long unsigned int nRemove = boost::numeric_cast<long unsigned int >(nRemove_long);

  this->_objectptr->GetObj()->RemoveAt(uiIndex, nRemove);
  return BasicVariable::ptr();
}
/* The following types are missing: _11355

//---------------------------------------------------
//  Wrapping of void wxDynamicLibraryDetailsArray::Sort(CMPFUNC_wxObjArraywxDynamicLibraryDetailsArray fCmp)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Sort::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _11355, "parameter named 'fCmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap_Sort::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _11355 fCmp;
  if (!get_val_param<_11355 >(fCmp,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Sort(fCmp);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxDynamicLibraryDetailsArray & wxDynamicLibraryDetailsArray::operator =(wxDynamicLibraryDetailsArray const & src)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetailsArray, "parameter named 'src'")
  return_comments="returning a variable of type wxDynamicLibraryDetailsArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDynamicLibraryDetailsArray > src_smtptr;
  if (!get_val_smtptr_param<wxDynamicLibraryDetailsArray >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDynamicLibraryDetailsArray const & src = *src_smtptr;

  wxDynamicLibraryDetailsArray & res =   (*this->_objectptr->GetObj()) = (src);
  return AMILabType<wxDynamicLibraryDetailsArray >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxDynamicLibraryDetailsArray & wxDynamicLibraryDetailsArray::operator [](size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetailsArray::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxDynamicLibraryDetails";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetailsArray::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxObjArraywxDynamicLibraryDetailsArray & res =   (*this->_objectptr->GetObj()) [ (uiIndex)];
  return AMILabType<wxDynamicLibraryDetails >::CreateVar(res);
}

