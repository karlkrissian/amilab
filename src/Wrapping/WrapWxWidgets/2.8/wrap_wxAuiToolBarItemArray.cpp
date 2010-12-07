/**
 * C++ Interface: wrap_wxAuiToolBarItemArray
 *
 * Description: wrapping wxAuiToolBarItemArray
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
#include "wrap_wxAuiToolBarItemArray.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxAuiToolBarItem.h"


#include "wrap_wxAuiToolBarItemArray.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiToolBarItemArray>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiToolBarItemArray::wrap_wxAuiToolBarItemArray construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxAuiToolBarItemArray);
AMI_DEFINE_VARFROMSMTPTR(wxAuiToolBarItemArray);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiToolBarItemArray
//
Variable<AMIObject>::ptr WrapClass_wxAuiToolBarItemArray::CreateVar( wxAuiToolBarItemArray* sp)
{
  boost::shared_ptr<wxAuiToolBarItemArray> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiToolBarItemArray>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiToolBarItemArray>::CreateVar(
      new WrapClass_wxAuiToolBarItemArray(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::AddMethods(WrapClass<wxAuiToolBarItemArray>::ptr this_ptr )
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
/* The following types are missing: _13436
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
void WrapClass_wxAuiToolBarItemArray::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAuiToolBarItemArray");
    WrapClass_wxAuiToolBarItemArray::AddVar_wxAuiToolBarItemArray_1(amiobject->GetContext());
  WrapClass_wxAuiToolBarItemArray::AddVar_wxAuiToolBarItemArray(amiobject->GetContext());
  WrapClass_wxAuiToolBarItemArray::AddVar_wxAuiToolBarItemArray_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBarItemArray::wxAuiToolBarItemArray()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxAuiToolBarItemArray* _newobj = new wxAuiToolBarItemArray();
  BasicVariable::ptr res = WrapClass_wxAuiToolBarItemArray::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxAuiToolBarItemArray::wxAuiToolBarItemArray(...)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiToolBarItemArray::wrap_wxAuiToolBarItemArray_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiToolBarItemArray::wrap_wxAuiToolBarItemArray_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBarItemArray::wxAuiToolBarItemArray(wxAuiToolBarItemArray const & src)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItemArray, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItemArray > src_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItemArray >(src_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxAuiToolBarItemArray const & src = *src_smtptr;

  wxAuiToolBarItemArray* _newobj = new wxAuiToolBarItemArray(src);
  BasicVariable::ptr res = WrapClass_wxAuiToolBarItemArray::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxAuiToolBarItemArray.
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxAuiToolBarItemArray object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxAuiToolBarItemArray >::CreateVar( new wxAuiToolBarItemArray(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Alloc(size_t count)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Alloc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
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
//  Wrapping of size_t wxAuiToolBarItemArray::GetCount()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_GetCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_GetCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxAuiToolBarItemArray::size()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItemArray::IsEmpty()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItemArray::empty()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxAuiToolBarItemArray::Count()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Count::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Count::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->Count();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Shrink()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Shrink::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Shrink::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Shrink();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxAuiToolBarItemArray & wxAuiToolBarItemArray::Item(size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Item::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Item::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxObjArraywxAuiToolBarItemArray & res =   this->_objectptr->GetObj()->Item(uiIndex);
  return AMILabType<wxAuiToolBarItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxAuiToolBarItemArray & wxAuiToolBarItemArray::Last()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Last::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Last::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  _wxObjArraywxAuiToolBarItemArray & res =   this->_objectptr->GetObj()->Last();
  return AMILabType<wxAuiToolBarItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBarItemArray::Index(_wxObjArraywxAuiToolBarItemArray const & lItem, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Index::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bFromEnd' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Index::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > lItem_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(lItem_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  _wxObjArraywxAuiToolBarItemArray const & lItem = *lItem_smtptr;

  bool bFromEnd = false;
  if (!get_val_param<bool >(bFromEnd,_p,_n,false,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->Index(lItem, bFromEnd);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Add(_wxObjArraywxAuiToolBarItemArray const & lItem, size_t nInsert = 1)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Add_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nInsert' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Add_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > lItem_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(lItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxObjArraywxAuiToolBarItemArray const & lItem = *lItem_smtptr;

  long nInsert_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(nInsert_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long unsigned int nInsert = boost::numeric_cast<long unsigned int >(nInsert_long);

  this->_objectptr->GetObj()->Add(lItem, nInsert);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiToolBarItemArray::Add(...)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Add::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Add::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiToolBarItemArray::wrap_Add_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiToolBarItemArray::wrap_Add_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Add(_wxObjArraywxAuiToolBarItemArray const * pItem)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Add_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'pItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Add_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > pItem_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(pItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxAuiToolBarItem* pItem = pItem_smtptr.get();

  this->_objectptr->GetObj()->Add(pItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::push_back(_wxObjArraywxAuiToolBarItemArray const * pItem)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_push_back_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'pItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_push_back_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > pItem_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(pItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxAuiToolBarItem* pItem = pItem_smtptr.get();

  this->_objectptr->GetObj()->push_back(pItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiToolBarItemArray::push_back(...)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_push_back::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_push_back::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiToolBarItemArray::wrap_push_back_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiToolBarItemArray::wrap_push_back_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::push_back(_wxObjArraywxAuiToolBarItemArray const & lItem)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_push_back_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'lItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_push_back_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > lItem_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(lItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxObjArraywxAuiToolBarItemArray const & lItem = *lItem_smtptr;

  this->_objectptr->GetObj()->push_back(lItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Insert(_wxObjArraywxAuiToolBarItemArray const & lItem, size_t uiIndex, size_t nInsert = 1)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nInsert' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > lItem_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(lItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxObjArraywxAuiToolBarItemArray const & lItem = *lItem_smtptr;

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
//  Wrapping of multipled defined method:... wxAuiToolBarItemArray::Insert(...)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiToolBarItemArray::wrap_Insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiToolBarItemArray::wrap_Insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Insert(_wxObjArraywxAuiToolBarItemArray const * pItem, size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'pItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItem > pItem_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItem >(pItem_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxAuiToolBarItem* pItem = pItem_smtptr.get();

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  this->_objectptr->GetObj()->Insert(pItem, uiIndex);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Empty()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Empty::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Empty();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Clear()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxAuiToolBarItemArray * wxAuiToolBarItemArray::Detach(size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Detach::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Detach::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxObjArraywxAuiToolBarItemArray * res =   this->_objectptr->GetObj()->Detach(uiIndex);
  BasicVariable::ptr res_var = WrapClass_wxAuiToolBarItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::RemoveAt(size_t uiIndex, size_t nRemove = 1)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_RemoveAt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRemove' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
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
/* The following types are missing: _13436

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Sort(CMPFUNC_wxObjArraywxAuiToolBarItemArray fCmp)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Sort::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _13436, "parameter named 'fCmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Sort::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _13436 fCmp;
  if (!get_val_param<_13436 >(fCmp,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Sort(fCmp);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItemArray & wxAuiToolBarItemArray::operator =(wxAuiToolBarItemArray const & src)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItemArray, "parameter named 'src'")
  return_comments="returning a variable of type wxAuiToolBarItemArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItemArray > src_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItemArray >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiToolBarItemArray const & src = *src_smtptr;

  wxAuiToolBarItemArray & res =   (*this->_objectptr->GetObj()) = (src);
  return AMILabType<wxAuiToolBarItemArray >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of _wxObjArraywxAuiToolBarItemArray & wxAuiToolBarItemArray::operator [](size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxObjArraywxAuiToolBarItemArray & res =   (*this->_objectptr->GetObj()) [ (uiIndex)];
  return AMILabType<wxAuiToolBarItem >::CreateVar(res);
}

