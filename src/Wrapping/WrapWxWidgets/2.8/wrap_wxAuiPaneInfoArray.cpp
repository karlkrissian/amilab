/**
 * C++ Interface: wrap_wxAuiPaneInfoArray
 *
 * Description: wrapping wxAuiPaneInfoArray
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
#include "wrap_wxAuiPaneInfoArray.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxAuiPaneInfo.h"


#include "wrap_wxAuiPaneInfoArray.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiPaneInfoArray>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiPaneInfoArray::wrap_wxAuiPaneInfoArray construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxAuiPaneInfoArray);
AMI_DEFINE_VARFROMSMTPTR(wxAuiPaneInfoArray);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiPaneInfoArray
//
Variable<AMIObject>::ptr WrapClass_wxAuiPaneInfoArray::CreateVar( wxAuiPaneInfoArray* sp)
{
  boost::shared_ptr<wxAuiPaneInfoArray> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiPaneInfoArray>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiPaneInfoArray>::CreateVar(
      new WrapClass_wxAuiPaneInfoArray(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::AddMethods(WrapClass<wxAuiPaneInfoArray>::ptr this_ptr )
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
/* The following types are missing: _15468
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
void WrapClass_wxAuiPaneInfoArray::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAuiPaneInfoArray");
    WrapClass_wxAuiPaneInfoArray::AddVar_wxAuiPaneInfoArray_1(amiobject->GetContext());
  WrapClass_wxAuiPaneInfoArray::AddVar_wxAuiPaneInfoArray(amiobject->GetContext());
  WrapClass_wxAuiPaneInfoArray::AddVar_wxAuiPaneInfoArray_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAuiPaneInfoArray::wxAuiPaneInfoArray()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_wxAuiPaneInfoArray_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_wxAuiPaneInfoArray_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxAuiPaneInfoArray* _newobj = new wxAuiPaneInfoArray();
  BasicVariable::ptr res = WrapClass_wxAuiPaneInfoArray::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxAuiPaneInfoArray::wxAuiPaneInfoArray(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_wxAuiPaneInfoArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_wxAuiPaneInfoArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfoArray::wrap_wxAuiPaneInfoArray_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfoArray::wrap_wxAuiPaneInfoArray_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAuiPaneInfoArray::wxAuiPaneInfoArray(wxAuiPaneInfoArray const & src)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_wxAuiPaneInfoArray_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfoArray, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_wxAuiPaneInfoArray_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfoArray > src_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfoArray >(src_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxAuiPaneInfoArray const & src = *src_smtptr;

  wxAuiPaneInfoArray* _newobj = new wxAuiPaneInfoArray(src);
  BasicVariable::ptr res = WrapClass_wxAuiPaneInfoArray::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxAuiPaneInfoArray.
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxAuiPaneInfoArray object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxAuiPaneInfoArray >::CreateVar( new wxAuiPaneInfoArray(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::Alloc(size_t count)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Alloc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
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
//  Wrapping of size_t wxAuiPaneInfoArray::GetCount()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_GetCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_GetCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxAuiPaneInfoArray::size()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfoArray::IsEmpty()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiPaneInfoArray::empty()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxAuiPaneInfoArray::Count()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Count::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Count::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->Count();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::Shrink()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Shrink::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Shrink::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Shrink();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxAuiPaneInfoArray & wxAuiPaneInfoArray::Item(size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Item::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Item::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxObjArraywxAuiPaneInfoArray & res =   this->_objectptr->GetObj()->Item(uiIndex);
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxAuiPaneInfoArray & wxAuiPaneInfoArray::Last()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Last::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Last::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  _wxObjArraywxAuiPaneInfoArray & res =   this->_objectptr->GetObj()->Last();
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxAuiPaneInfoArray::Index(_wxObjArraywxAuiPaneInfoArray const & lItem, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Index::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bFromEnd' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Index::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > lItem_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(lItem_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  _wxObjArraywxAuiPaneInfoArray const & lItem = *lItem_smtptr;

  bool bFromEnd = false;
  if (!get_val_param<bool >(bFromEnd,_p,_n,false,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->Index(lItem, bFromEnd);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::Add(_wxObjArraywxAuiPaneInfoArray const & lItem, size_t nInsert = 1)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Add_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nInsert' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Add_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > lItem_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(lItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxObjArraywxAuiPaneInfoArray const & lItem = *lItem_smtptr;

  long nInsert_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(nInsert_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long unsigned int nInsert = boost::numeric_cast<long unsigned int >(nInsert_long);

  this->_objectptr->GetObj()->Add(lItem, nInsert);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiPaneInfoArray::Add(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Add::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Add::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfoArray::wrap_Add_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfoArray::wrap_Add_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::Add(_wxObjArraywxAuiPaneInfoArray const * pItem)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Add_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Add_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > pItem_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxAuiPaneInfo* pItem = pItem_smtptr.get();

  this->_objectptr->GetObj()->Add(pItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::push_back(_wxObjArraywxAuiPaneInfoArray const * pItem)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_push_back_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_push_back_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > pItem_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxAuiPaneInfo* pItem = pItem_smtptr.get();

  this->_objectptr->GetObj()->push_back(pItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiPaneInfoArray::push_back(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_push_back::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_push_back::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfoArray::wrap_push_back_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfoArray::wrap_push_back_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::push_back(_wxObjArraywxAuiPaneInfoArray const & lItem)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_push_back_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'lItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_push_back_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > lItem_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(lItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxObjArraywxAuiPaneInfoArray const & lItem = *lItem_smtptr;

  this->_objectptr->GetObj()->push_back(lItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::Insert(_wxObjArraywxAuiPaneInfoArray const & lItem, size_t uiIndex, size_t nInsert = 1)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nInsert' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > lItem_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(lItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxObjArraywxAuiPaneInfoArray const & lItem = *lItem_smtptr;

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
//  Wrapping of multipled defined method:... wxAuiPaneInfoArray::Insert(...)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiPaneInfoArray::wrap_Insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiPaneInfoArray::wrap_Insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::Insert(_wxObjArraywxAuiPaneInfoArray const * pItem, size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfo, "parameter named 'pItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfo > pItem_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfo >(pItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxAuiPaneInfo* pItem = pItem_smtptr.get();

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  this->_objectptr->GetObj()->Insert(pItem, uiIndex);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::Empty()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Empty::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Empty();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::Clear()
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxAuiPaneInfoArray * wxAuiPaneInfoArray::Detach(size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Detach::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Detach::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxObjArraywxAuiPaneInfoArray * res =   this->_objectptr->GetObj()->Detach(uiIndex);
  BasicVariable::ptr res_var = WrapClass_wxAuiPaneInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::RemoveAt(size_t uiIndex, size_t nRemove = 1)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_RemoveAt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRemove' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
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
/* The following types are missing: _15468

//---------------------------------------------------
//  Wrapping of void wxAuiPaneInfoArray::Sort(CMPFUNC_wxObjArraywxAuiPaneInfoArray fCmp)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap_Sort::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _15468, "parameter named 'fCmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap_Sort::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _15468 fCmp;
  if (!get_val_param<_15468 >(fCmp,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Sort(fCmp);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxAuiPaneInfoArray & wxAuiPaneInfoArray::operator =(wxAuiPaneInfoArray const & src)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiPaneInfoArray, "parameter named 'src'")
  return_comments="returning a variable of type wxAuiPaneInfoArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiPaneInfoArray > src_smtptr;
  if (!get_val_smtptr_param<wxAuiPaneInfoArray >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiPaneInfoArray const & src = *src_smtptr;

  wxAuiPaneInfoArray & res =   (*this->_objectptr->GetObj()) = (src);
  return AMILabType<wxAuiPaneInfoArray >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxAuiPaneInfoArray & wxAuiPaneInfoArray::operator [](size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiPaneInfoArray::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxAuiPaneInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiPaneInfoArray::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxObjArraywxAuiPaneInfoArray & res =   (*this->_objectptr->GetObj()) [ (uiIndex)];
  return AMILabType<wxAuiPaneInfo >::CreateVar(res);
}

