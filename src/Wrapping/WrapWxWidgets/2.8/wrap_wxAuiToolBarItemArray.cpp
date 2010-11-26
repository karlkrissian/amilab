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

#include "wrap_wxAuiToolBarItemArray.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxAuiToolBarItemArray.h"
#include "wrap_wxAuiToolBarItem.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiToolBarItemArray>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiToolBarItemArray::wrap_wxAuiToolBarItemArray construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAuiToolBarItemArray);

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



//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBarItemArray::wxAuiToolBarItemArray()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray::CallMember( ParamList* _p)
{
  wxAuiToolBarItemArray* _newobj = new wxAuiToolBarItemArray();
  BasicVariable::ptr res = WrapClass_wxAuiToolBarItemArray::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBarItemArray::wxAuiToolBarItemArray(wxAuiToolBarItemArray & src)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItemArray, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_wxAuiToolBarItemArray1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItemArray* src_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItemArray>(src_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItemArray& src = *src_ptr;
  wxAuiToolBarItemArray* _newobj = new wxAuiToolBarItemArray(src);
  BasicVariable::ptr res = WrapClass_wxAuiToolBarItemArray::CreateVar(_newobj);
  return res;
}
/* The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Alloc(size_t count)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Alloc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'count'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Alloc::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  long unsigned int count;
  if (!get_val_param<long unsigned int>(count,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->Alloc(count);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of size_t wxAuiToolBarItemArray::GetCount()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_GetCount::SetParametersComments()
{
  return_comments="returning a variable of type long unsigned int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_GetCount::CallMember( ParamList* _p)
{
  size_t res =   this->_objectptr->GetObj()->GetCount();
  return AMILabType<long unsigned int>::CreateVar(res);
}
*/
/* The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of size_t wxAuiToolBarItemArray::size()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long unsigned int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_size::CallMember( ParamList* _p)
{
  size_t res =   this->_objectptr->GetObj()->size();
  return AMILabType<long unsigned int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItemArray::IsEmpty()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->IsEmpty();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBarItemArray::empty()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_empty::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->empty();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of size_t wxAuiToolBarItemArray::Count()
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Count::SetParametersComments()
{
  return_comments="returning a variable of type long unsigned int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Count::CallMember( ParamList* _p)
{
  size_t res =   this->_objectptr->GetObj()->Count();
  return AMILabType<long unsigned int>::CreateVar(res);
}
*/

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
  this->_objectptr->GetObj()->Shrink();
  return BasicVariable::ptr();
}
/* The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem & wxAuiToolBarItemArray::Item(size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Item::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Item::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  long unsigned int uiIndex;
  if (!get_val_param<long unsigned int>(uiIndex,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem & res =   this->_objectptr->GetObj()->Item(uiIndex);
  return AMILabType<wxAuiToolBarItem>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem & wxAuiToolBarItemArray::Last()
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
  wxAuiToolBarItem & res =   this->_objectptr->GetObj()->Last();
  return AMILabType<wxAuiToolBarItem>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBarItemArray::Index(wxAuiToolBarItem & lItem, bool bFromEnd)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Index::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bFromEnd'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Index::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* lItem_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItem>(lItem_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem& lItem = *lItem_ptr;
  int bFromEnd_int;
  if (!get_val_param<int>(bFromEnd_int,_p,_n)) ClassHelpAndReturn;
  bool bFromEnd = (bool) (bFromEnd_int>0.5);
  int res =   this->_objectptr->GetObj()->Index(lItem, bFromEnd);
  return AMILabType<int>::CreateVar(res);
}
/* The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Add(wxAuiToolBarItem & lItem, size_t nInsert)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Add::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'nInsert'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Add::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* lItem_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItem>(lItem_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem& lItem = *lItem_ptr;
  long unsigned int nInsert;
  if (!get_val_param<long unsigned int>(nInsert,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->Add(lItem, nInsert);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Add(wxAuiToolBarItem * pItem)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Add1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'pItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Add1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* pItem;
  if (!get_val_ptr_param<wxAuiToolBarItem>(pItem,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->Add(pItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::push_back(wxAuiToolBarItem * pItem)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_push_back::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'pItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_push_back::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* pItem;
  if (!get_val_ptr_param<wxAuiToolBarItem>(pItem,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->push_back(pItem);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::push_back(wxAuiToolBarItem & lItem)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_push_back1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'lItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_push_back1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* lItem_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItem>(lItem_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem& lItem = *lItem_ptr;
  this->_objectptr->GetObj()->push_back(lItem);
  return BasicVariable::ptr();
}
/* The following types are missing: long unsigned int, long unsigned int

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Insert(wxAuiToolBarItem & lItem, size_t uiIndex, size_t nInsert)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Insert::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'nInsert'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Insert::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* lItem_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItem>(lItem_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem& lItem = *lItem_ptr;
  long unsigned int uiIndex;
  if (!get_val_param<long unsigned int>(uiIndex,_p,_n)) ClassHelpAndReturn;
  long unsigned int nInsert;
  if (!get_val_param<long unsigned int>(nInsert,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->Insert(lItem, uiIndex, nInsert);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Insert(wxAuiToolBarItem * pItem, size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Insert1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItem, "parameter named 'pItem'")
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'uiIndex'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Insert1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItem* pItem;
  if (!get_val_ptr_param<wxAuiToolBarItem>(pItem,_p,_n)) ClassHelpAndReturn;
  long unsigned int uiIndex;
  if (!get_val_param<long unsigned int>(uiIndex,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->Insert(pItem, uiIndex);
  return BasicVariable::ptr();
}
*/

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
  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}
/* The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem * wxAuiToolBarItemArray::Detach(size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Detach::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Detach::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  long unsigned int uiIndex;
  if (!get_val_param<long unsigned int>(uiIndex,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem * res =   this->_objectptr->GetObj()->Detach(uiIndex);
  BasicVariable::ptr res_var = WrapClass_wxAuiToolBarItem::CreateVar(res);
  return res_var;
}
*/
/* The following types are missing: long unsigned int, long unsigned int

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::RemoveAt(size_t uiIndex, size_t nRemove)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_RemoveAt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'nRemove'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_RemoveAt::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  long unsigned int uiIndex;
  if (!get_val_param<long unsigned int>(uiIndex,_p,_n)) ClassHelpAndReturn;
  long unsigned int nRemove;
  if (!get_val_param<long unsigned int>(nRemove,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->RemoveAt(uiIndex, nRemove);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: _9596

//---------------------------------------------------
//  Wrapping of void wxAuiToolBarItemArray::Sort(CMPFUNC_wxObjArraywxAuiToolBarItemArray fCmp)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_Sort::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _9596, "parameter named 'fCmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_Sort::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  _9596 fCmp;
  if (!get_val_param<_9596>(fCmp,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->Sort(fCmp);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItemArray & wxAuiToolBarItemArray::=(wxAuiToolBarItemArray & src)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItemArray, "parameter named 'src'")
  return_comments="returning a variable of type wxAuiToolBarItemArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarItemArray* src_ptr;
  if (!get_val_ptr_param<wxAuiToolBarItemArray>(src_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItemArray& src = *src_ptr;
  wxAuiToolBarItemArray & res =   (*this->_objectptr->GetObj())=(src);
  return AMILabType<wxAuiToolBarItemArray>::CreateVar(res);
}
/*
 * The following types are missing: long unsigned int

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem & wxAuiToolBarItemArray::[](size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxAuiToolBarItemArray::
    wrap_at::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long unsigned int, "parameter named 'uiIndex'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarItemArray::
    wrap_at::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  long unsigned int uiIndex;
  if (!get_val_param<long unsigned int>(uiIndex,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarItem & res =   this->_objectptr->GetObj()->[](uiIndex);
  return AMILabType<wxAuiToolBarItem>::CreateVar(res);
}
*/

