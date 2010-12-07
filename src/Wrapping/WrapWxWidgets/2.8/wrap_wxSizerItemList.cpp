/**
 * C++ Interface: wrap_wxSizerItemList
 *
 * Description: wrapping wxSizerItemList
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
#include "wrap_wxSizerItemList.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxSizerItem.h"
#include "wrap_wxwxSizerItemListNode.h"
#include "stdlib.h"
#include "wrap_wxListKey.h"


#include "wrap_wxSizerItemList.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxSizerItemList>::CreateVar( ParamList* p)
{
  WrapClass_wxSizerItemList::wrap_wxSizerItemList construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxSizerItemList);
AMI_DEFINE_VARFROMSMTPTR(wxSizerItemList);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxSizerItemList
//
Variable<AMIObject>::ptr WrapClass_wxSizerItemList::CreateVar( wxSizerItemList* sp)
{
  boost::shared_ptr<wxSizerItemList> di_ptr(
    sp,
    wxwindow_nodeleter<wxSizerItemList>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxSizerItemList>::CreateVar(
      new WrapClass_wxSizerItemList(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxSizerItemList::AddMethods(WrapClass<wxSizerItemList>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_GetFirst( this_ptr);
      AddVar_GetLast( this_ptr);
      AddVar_Item( this_ptr);
      AddVar_Append_1( this_ptr);
      AddVar_Insert_1( this_ptr);
      AddVar_Insert( this_ptr);
      AddVar_Insert_2( this_ptr);
      AddVar_Insert_3( this_ptr);
      AddVar_Append( this_ptr);
/* The following types are missing: void
      AddVar_Append_2( this_ptr);
*/
/* The following types are missing: void
      AddVar_Append_3( this_ptr);
*/
      AddVar_DetachNode( this_ptr);
      AddVar_DeleteNode( this_ptr);
      AddVar_DeleteObject( this_ptr);
      AddVar_Erase( this_ptr);
      AddVar_Find_1( this_ptr);
      AddVar_Find( this_ptr);
      AddVar_Find_2( this_ptr);
      AddVar_IndexOf( this_ptr);
/* The following types are missing: _9904
      AddVar_Sort_1( this_ptr);
*/
      AddVar_Sort( this_ptr);
/* The following types are missing: _9172
      AddVar_Sort_2( this_ptr);
*/
/* The following types are missing: iterator
      AddVar_begin_1( this_ptr);
*/
      AddVar_begin( this_ptr);
/* The following types are missing: const_iterator
      AddVar_begin_2( this_ptr);
*/
/* The following types are missing: iterator
      AddVar_end_1( this_ptr);
*/
      AddVar_end( this_ptr);
/* The following types are missing: const_iterator
      AddVar_end_2( this_ptr);
*/
/* The following types are missing: reverse_iterator
      AddVar_rbegin_1( this_ptr);
*/
      AddVar_rbegin( this_ptr);
/* The following types are missing: const_reverse_iterator
      AddVar_rbegin_2( this_ptr);
*/
/* The following types are missing: reverse_iterator
      AddVar_rend_1( this_ptr);
*/
      AddVar_rend( this_ptr);
/* The following types are missing: const_reverse_iterator
      AddVar_rend_2( this_ptr);
*/
      AddVar_resize( this_ptr);
      AddVar_size( this_ptr);
      AddVar_max_size( this_ptr);
      AddVar_empty( this_ptr);
      AddVar_front_1( this_ptr);
      AddVar_front( this_ptr);
      AddVar_front_2( this_ptr);
      AddVar_back_1( this_ptr);
      AddVar_back( this_ptr);
      AddVar_back_2( this_ptr);
      AddVar_push_front( this_ptr);
      AddVar_pop_front( this_ptr);
      AddVar_push_back( this_ptr);
      AddVar_pop_back( this_ptr);
/* The following types are missing: const_iterator, const_iterator
      AddVar_assign_1( this_ptr);
*/
      AddVar_assign( this_ptr);
      AddVar_assign_2( this_ptr);
/* The following types are missing: iterator, iterator
      AddVar_insert_1( this_ptr);
*/
      AddVar_insert( this_ptr);
/* The following types are missing: iterator
      AddVar_insert_2( this_ptr);
*/
/* The following types are missing: iterator, const_iterator, const_iterator
      AddVar_insert_3( this_ptr);
*/
/* The following types are missing: iterator, iterator
      AddVar_erase_1( this_ptr);
*/
      AddVar_erase( this_ptr);
/* The following types are missing: iterator, iterator, iterator
      AddVar_erase_2( this_ptr);
*/
      AddVar_clear( this_ptr);
/* The following types are missing: iterator, iterator, iterator
      AddVar_splice_1( this_ptr);
*/
      AddVar_splice( this_ptr);
/* The following types are missing: iterator
      AddVar_splice_2( this_ptr);
*/
/* The following types are missing: iterator, iterator
      AddVar_splice_3( this_ptr);
*/
      AddVar_remove( this_ptr);
      AddVar_reverse( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___at__( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxListBase
  boost::shared_ptr<wxListBase > parent_wxListBase(  boost::dynamic_pointer_cast<wxListBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxListBase = AMILabType<wxListBase >::CreateVarFromSmtPtr(parent_wxListBase);
  context->AddVar("wxListBase",var_wxListBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxListBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxListBase);
  context->AddDefault(obj_wxListBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxSizerItemList::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxSizerItemList");
    WrapClass_wxSizerItemList::AddVar_wxSizerItemList_1(amiobject->GetContext());
  WrapClass_wxSizerItemList::AddVar_wxSizerItemList(amiobject->GetContext());
  WrapClass_wxSizerItemList::AddVar_wxSizerItemList_2(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxSizerItemList::AddVar_wxSizerItemList_3(amiobject->GetContext());
  */
  WrapClass_wxSizerItemList::AddVar_wxSizerItemList_4(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxSizerItemList::AddVar_wxSizerItemList_5(amiobject->GetContext());
  */


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxSizerItemList::wxSizerItemList(wxKeyType keyType = wxKEY_NONE)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'keyType' (def:wxKEY_NONE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int keyType_int = (int) wxKEY_NONE;;
  if (!get_val_param<int >(keyType_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxKeyType keyType = (wxKeyType) keyType_int;

  wxSizerItemList* _newobj = new wxSizerItemList(keyType);
  BasicVariable::ptr res = WrapClass_wxSizerItemList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxSizerItemList::wxSizerItemList(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_wxSizerItemList::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_wxSizerItemList::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItemList::wrap_wxSizerItemList_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerItemList::wrap_wxSizerItemList_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizerItemList::wrap_wxSizerItemList_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItemList::wxSizerItemList(wxSizerItemList const & list)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItemList, "parameter named 'list'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizerItemList > list_smtptr;
  if (!get_val_smtptr_param<wxSizerItemList >(list_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxSizerItemList const & list = *list_smtptr;

  wxSizerItemList* _newobj = new wxSizerItemList(list);
  BasicVariable::ptr res = WrapClass_wxSizerItemList::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxSizerItem * *

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItemList::wxSizerItemList(size_t count, wxSizerItem * * elements)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long count_long;
  if (!get_val_param<long >(count_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  boost::shared_ptr<wxSizerItem > elements_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerItem* elements = elements_smtptr.get();

  wxSizerItemList* _newobj = new wxSizerItemList(count, elements);
  BasicVariable::ptr res = WrapClass_wxSizerItemList::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItemList::wxSizerItemList(size_t n, wxSizerItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxSizerItem > v_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(v_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSizerItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  wxSizerItemList* _newobj = new wxSizerItemList(n, v);
  BasicVariable::ptr res = WrapClass_wxSizerItemList::CreateVar(_newobj);
  return res;
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of Constructor wxSizerItemList::wxSizerItemList(const_iterator const & first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_wxSizerItemList_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<const_iterator > first_smtptr;
  if (!get_val_smtptr_param<const_iterator >(first_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  const_iterator const & first = *first_smtptr;

  boost::shared_ptr<const_iterator > last_smtptr;
  if (!get_val_smtptr_param<const_iterator >(last_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  const_iterator const & last = *last_smtptr;

  wxSizerItemList* _newobj = new wxSizerItemList(first, last);
  BasicVariable::ptr res = WrapClass_wxSizerItemList::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxSizerItemList.
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxSizerItemList object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxSizerItemList >::CreateVar( new wxSizerItemList(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::GetFirst()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_GetFirst::SetParametersComments()
{
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_GetFirst::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->GetFirst();
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::GetLast()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_GetLast::SetParametersComments()
{
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_GetLast::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->GetLast();
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::Item(size_t index)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Item::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Item::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->Item(index);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::Append(wxSizerItem * object)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Append_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Append_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizerItem > object_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerItem* object = object_smtptr.get();

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->Append(object);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::Insert(wxSizerItem * object)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizerItem > object_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerItem* object = object_smtptr.get();

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->Insert(object);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::Insert(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItemList::wrap_Insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerItemList::wrap_Insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxSizerItemList::wrap_Insert_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::Insert(size_t pos, wxSizerItem * object)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxSizerItem > object_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerItem* object = object_smtptr.get();

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->Insert(pos, object);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::Insert(wxwxSizerItemListNode * prev, wxSizerItem * object)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxwxSizerItemListNode, "parameter named 'prev'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxwxSizerItemListNode > prev_smtptr;
  if (!get_val_smtptr_param<wxwxSizerItemListNode >(prev_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxwxSizerItemListNode* prev = prev_smtptr.get();

  boost::shared_ptr<wxSizerItem > object_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerItem* object = object_smtptr.get();

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->Insert(prev, object);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::Append(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItemList::wrap_Append_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::Append(long int key, void * object)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Append_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'object'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Append_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long key_long;
  if (!get_val_param<long >(key_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int key = key_long;

  boost::shared_ptr<void > object_smtptr;
  if (!get_val_smtptr_param<void >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  void* object = object_smtptr.get();

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->Append(key, object);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}
*/
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::Append(wxChar const * key, void * object)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'object'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Append_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > key_string;
  if (!get_val_smtptr_param<std::string >(key_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wchar_t key[key_string->size()+1];
mbstowcs(key,key_string->c_str(),key_string->size()+1);

  boost::shared_ptr<void > object_smtptr;
  if (!get_val_smtptr_param<void >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  void* object = object_smtptr.get();

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->Append(key, object);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::DetachNode(wxwxSizerItemListNode * node)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_DetachNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxwxSizerItemListNode, "parameter named 'node'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_DetachNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxwxSizerItemListNode > node_smtptr;
  if (!get_val_smtptr_param<wxwxSizerItemListNode >(node_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxwxSizerItemListNode* node = node_smtptr.get();

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->DetachNode(node);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxSizerItemList::DeleteNode(wxwxSizerItemListNode * node)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_DeleteNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxwxSizerItemListNode, "parameter named 'node'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_DeleteNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxwxSizerItemListNode > node_smtptr;
  if (!get_val_smtptr_param<wxwxSizerItemListNode >(node_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxwxSizerItemListNode* node = node_smtptr.get();

  bool res =   this->_objectptr->GetObj()->DeleteNode(node);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxSizerItemList::DeleteObject(wxSizerItem * object)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_DeleteObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'object'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_DeleteObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizerItem > object_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(object_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizerItem* object = object_smtptr.get();

  bool res =   this->_objectptr->GetObj()->DeleteObject(object);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::Erase(wxwxSizerItemListNode * it)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Erase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxwxSizerItemListNode, "parameter named 'it'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Erase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxwxSizerItemListNode > it_smtptr;
  if (!get_val_smtptr_param<wxwxSizerItemListNode >(it_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxwxSizerItemListNode* it = it_smtptr.get();

  this->_objectptr->GetObj()->Erase(it);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::Find(wxSizerItem const * object)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Find_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Find_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizerItem > object_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerItem* object = object_smtptr.get();

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->Find(object);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::Find(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Find::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Find::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItemList::wrap_Find_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerItemList::wrap_Find_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxSizerItemList::Find(wxListKey const & key)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Find_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'key'")
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Find_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxListKey const & key = *key_smtptr;

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->Find(key);
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxSizerItemList::IndexOf(wxSizerItem * object)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_IndexOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'object'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_IndexOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizerItem > object_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(object_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizerItem* object = object_smtptr.get();

  int res =   this->_objectptr->GetObj()->IndexOf(object);
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: _9904

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::Sort(wxSortCompareFunction func)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Sort_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _9904, "parameter named 'func'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Sort_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  _9904 func;
  if (!get_val_param<_9904 >(func,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Sort(func);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::Sort(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Sort::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Sort::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: _9172

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::Sort(wxSortFuncFor_wxSizerItemList func)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_Sort_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _9172, "parameter named 'func'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_Sort_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  _9172 func;
  if (!get_val_param<_9172 >(func,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Sort(func);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxSizerItemList::begin()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_begin_1::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_begin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::begin(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_begin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_begin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxSizerItemList::begin()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_begin_2::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_begin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxSizerItemList::end()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_end_1::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_end_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::end(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_end::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_end::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxSizerItemList::end()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_end_2::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_end_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxSizerItemList::rbegin()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_rbegin_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_rbegin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::rbegin(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_rbegin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_rbegin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxSizerItemList::rbegin()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_rbegin_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_rbegin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxSizerItemList::rend()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_rend_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_rend_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::rend(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_rend::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_rend::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxSizerItemList::rend()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_rend_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_rend_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::resize(size_t n, wxSizerItem * v = 0u)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_resize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_resize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxSizerItem > v_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizerItem* v = v_smtptr.get();

  this->_objectptr->GetObj()->resize(n, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxSizerItemList::size()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxSizerItemList::max_size()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_max_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_max_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->max_size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxSizerItemList::empty()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * & wxSizerItemList::front()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_front_1::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_front_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSizerItem * & res =   this->_objectptr->GetObj()->front();
  return AMILabType<wxSizerItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::front(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_front::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_front::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItemList::wrap_front_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerItemList::wrap_front_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * const & wxSizerItemList::front()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_front_2::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_front_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSizerItem * const & res =   this->_objectptr->GetObj()->front();
  return AMILabType<wxSizerItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * & wxSizerItemList::back()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_back_1::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_back_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSizerItem * & res =   this->_objectptr->GetObj()->back();
  return AMILabType<wxSizerItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::back(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_back::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_back::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItemList::wrap_back_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerItemList::wrap_back_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * const & wxSizerItemList::back()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_back_2::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_back_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxSizerItem * const & res =   this->_objectptr->GetObj()->back();
  return AMILabType<wxSizerItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::push_front(wxSizerItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_push_front::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_push_front::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizerItem > v_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(v_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSizerItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->push_front(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::pop_front()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_pop_front::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_pop_front::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->pop_front();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::push_back(wxSizerItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_push_back::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_push_back::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizerItem > v_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(v_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSizerItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->push_back(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::pop_back()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_pop_back::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_pop_back::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->pop_back();
  return BasicVariable::ptr();
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::assign(const_iterator first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_assign_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_assign_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  const_iterator first;
  if (!get_val_param<const_iterator >(first,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<const_iterator > last_smtptr;
  if (!get_val_smtptr_param<const_iterator >(last_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  const_iterator const & last = *last_smtptr;

  this->_objectptr->GetObj()->assign(first, last);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::assign(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerItemList::wrap_assign_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::assign(size_t n, wxSizerItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_assign_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_assign_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxSizerItem > v_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(v_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSizerItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->assign(n, v);
  return BasicVariable::ptr();
}
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxSizerItemList::insert(iterator const & it, wxSizerItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'v' (def:0u)")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxSizerItem > v_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(v_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSizerItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  iterator res =   this->_objectptr->GetObj()->insert(it, v);
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::insert(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::insert(iterator const & it, size_t n, wxSizerItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxSizerItem > v_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(v_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSizerItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->insert(it, n, v);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::insert(iterator const & it, const_iterator first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  const_iterator first;
  if (!get_val_param<const_iterator >(first,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<const_iterator > last_smtptr;
  if (!get_val_smtptr_param<const_iterator >(last_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  const_iterator const & last = *last_smtptr;

  this->_objectptr->GetObj()->insert(it, first, last);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxSizerItemList::erase(iterator const & it)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_erase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_erase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  iterator res =   this->_objectptr->GetObj()->erase(it);
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::erase(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_erase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_erase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator, iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxSizerItemList::erase(iterator const & first, iterator const & last)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_erase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_erase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > first_smtptr;
  if (!get_val_smtptr_param<iterator >(first_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & first = *first_smtptr;

  boost::shared_ptr<iterator > last_smtptr;
  if (!get_val_smtptr_param<iterator >(last_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & last = *last_smtptr;

  iterator res =   this->_objectptr->GetObj()->erase(first, last);
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::clear()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->clear();
  return BasicVariable::ptr();
}
/* The following types are missing: iterator, iterator, iterator

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::splice(iterator const & it, wxSizerItemList & l, iterator const & first, iterator const & last)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_splice_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxSizerItemList, "parameter named 'l'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_splice_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxSizerItemList > l_smtptr;
  if (!get_val_smtptr_param<wxSizerItemList >(l_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerItemList & l = *l_smtptr;

  boost::shared_ptr<iterator > first_smtptr;
  if (!get_val_smtptr_param<iterator >(first_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & first = *first_smtptr;

  boost::shared_ptr<iterator > last_smtptr;
  if (!get_val_smtptr_param<iterator >(last_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & last = *last_smtptr;

  this->_objectptr->GetObj()->splice(it, l, first, last);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerItemList::splice(...)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_splice::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_splice::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::splice(iterator const & it, wxSizerItemList & l)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_splice_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxSizerItemList, "parameter named 'l'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_splice_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxSizerItemList > l_smtptr;
  if (!get_val_smtptr_param<wxSizerItemList >(l_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerItemList & l = *l_smtptr;

  this->_objectptr->GetObj()->splice(it, l);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::splice(iterator const & it, wxSizerItemList & l, iterator const & first)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_splice_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxSizerItemList, "parameter named 'l'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_splice_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxSizerItemList > l_smtptr;
  if (!get_val_smtptr_param<wxSizerItemList >(l_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizerItemList & l = *l_smtptr;

  boost::shared_ptr<iterator > first_smtptr;
  if (!get_val_smtptr_param<iterator >(first_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & first = *first_smtptr;

  this->_objectptr->GetObj()->splice(it, l, first);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::remove(wxSizerItem * const & v)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_remove::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_remove::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizerItem > v_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizerItem * const & v = v_smtptr.get();

  this->_objectptr->GetObj()->remove(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxSizerItemList::reverse()
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap_reverse::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap_reverse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->reverse();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSizerItemList & wxSizerItemList::operator =(wxSizerItemList const & list)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItemList, "parameter named 'list'")
  return_comments="returning a variable of type wxSizerItemList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizerItemList > list_smtptr;
  if (!get_val_smtptr_param<wxSizerItemList >(list_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizerItemList const & list = *list_smtptr;

  wxSizerItemList & res =   (*this->_objectptr->GetObj()) = (list);
  return AMILabType<wxSizerItemList >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxSizerItemList::operator [](size_t index)
//---------------------------------------------------
void WrapClass_wxSizerItemList::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItemList::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  wxSizerItem * res =   (*this->_objectptr->GetObj()) [ (index)];
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

