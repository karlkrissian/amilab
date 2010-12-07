/**
 * C++ Interface: wrap_wxMenuItemList
 *
 * Description: wrapping wxMenuItemList
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
#include "wrap_wxMenuItemList.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxMenuItem.h"
#include "wrap_wxwxMenuItemListNode.h"
#include "stdlib.h"
#include "wrap_wxListKey.h"


#include "wrap_wxMenuItemList.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMenuItemList>::CreateVar( ParamList* p)
{
  WrapClass_wxMenuItemList::wrap_wxMenuItemList construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxMenuItemList);
AMI_DEFINE_VARFROMSMTPTR(wxMenuItemList);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMenuItemList
//
Variable<AMIObject>::ptr WrapClass_wxMenuItemList::CreateVar( wxMenuItemList* sp)
{
  boost::shared_ptr<wxMenuItemList> di_ptr(
    sp,
    wxwindow_nodeleter<wxMenuItemList>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMenuItemList>::CreateVar(
      new WrapClass_wxMenuItemList(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMenuItemList::AddMethods(WrapClass<wxMenuItemList>::ptr this_ptr )
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
/* The following types are missing: _8388
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
void WrapClass_wxMenuItemList::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxMenuItemList");
    WrapClass_wxMenuItemList::AddVar_wxMenuItemList_1(amiobject->GetContext());
  WrapClass_wxMenuItemList::AddVar_wxMenuItemList(amiobject->GetContext());
  WrapClass_wxMenuItemList::AddVar_wxMenuItemList_2(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxMenuItemList::AddVar_wxMenuItemList_3(amiobject->GetContext());
  */
  WrapClass_wxMenuItemList::AddVar_wxMenuItemList_4(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxMenuItemList::AddVar_wxMenuItemList_5(amiobject->GetContext());
  */


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMenuItemList::wxMenuItemList(wxKeyType keyType = wxKEY_NONE)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'keyType' (def:wxKEY_NONE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int keyType_int = (int) wxKEY_NONE;;
  if (!get_val_param<int >(keyType_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxKeyType keyType = (wxKeyType) keyType_int;

  wxMenuItemList* _newobj = new wxMenuItemList(keyType);
  BasicVariable::ptr res = WrapClass_wxMenuItemList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMenuItemList::wxMenuItemList(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_wxMenuItemList::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_wxMenuItemList::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuItemList::wrap_wxMenuItemList_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuItemList::wrap_wxMenuItemList_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxMenuItemList::wrap_wxMenuItemList_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMenuItemList::wxMenuItemList(wxMenuItemList const & list)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItemList, "parameter named 'list'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuItemList > list_smtptr;
  if (!get_val_smtptr_param<wxMenuItemList >(list_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxMenuItemList const & list = *list_smtptr;

  wxMenuItemList* _newobj = new wxMenuItemList(list);
  BasicVariable::ptr res = WrapClass_wxMenuItemList::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxMenuItem * *

//---------------------------------------------------
//  Wrapping of Constructor wxMenuItemList::wxMenuItemList(size_t count, wxMenuItem * * elements)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long count_long;
  if (!get_val_param<long >(count_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  boost::shared_ptr<wxMenuItem > elements_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(elements_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* elements = elements_smtptr.get();

  wxMenuItemList* _newobj = new wxMenuItemList(count, elements);
  BasicVariable::ptr res = WrapClass_wxMenuItemList::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxMenuItemList::wxMenuItemList(size_t n, wxMenuItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxMenuItem > v_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(v_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxMenuItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  wxMenuItemList* _newobj = new wxMenuItemList(n, v);
  BasicVariable::ptr res = WrapClass_wxMenuItemList::CreateVar(_newobj);
  return res;
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of Constructor wxMenuItemList::wxMenuItemList(const_iterator const & first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_wxMenuItemList_5::CallMember( ParamList* _p)
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

  wxMenuItemList* _newobj = new wxMenuItemList(first, last);
  BasicVariable::ptr res = WrapClass_wxMenuItemList::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxMenuItemList.
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxMenuItemList object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxMenuItemList >::CreateVar( new wxMenuItemList(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::GetFirst()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_GetFirst::SetParametersComments()
{
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_GetFirst::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->GetFirst();
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::GetLast()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_GetLast::SetParametersComments()
{
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_GetLast::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->GetLast();
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::Item(size_t index)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Item::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Item::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->Item(index);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::Append(wxMenuItem * object)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Append_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Append_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuItem > object_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* object = object_smtptr.get();

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->Append(object);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::Insert(wxMenuItem * object)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuItem > object_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* object = object_smtptr.get();

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->Insert(object);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::Insert(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuItemList::wrap_Insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuItemList::wrap_Insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxMenuItemList::wrap_Insert_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::Insert(size_t pos, wxMenuItem * object)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxMenuItem > object_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* object = object_smtptr.get();

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->Insert(pos, object);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::Insert(wxwxMenuItemListNode * prev, wxMenuItem * object)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxwxMenuItemListNode, "parameter named 'prev'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxwxMenuItemListNode > prev_smtptr;
  if (!get_val_smtptr_param<wxwxMenuItemListNode >(prev_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxwxMenuItemListNode* prev = prev_smtptr.get();

  boost::shared_ptr<wxMenuItem > object_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* object = object_smtptr.get();

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->Insert(prev, object);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::Append(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuItemList::wrap_Append_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::Append(long int key, void * object)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Append_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'object'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
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

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->Append(key, object);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}
*/
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::Append(wxChar const * key, void * object)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'object'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
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

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->Append(key, object);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::DetachNode(wxwxMenuItemListNode * node)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_DetachNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxwxMenuItemListNode, "parameter named 'node'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_DetachNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxwxMenuItemListNode > node_smtptr;
  if (!get_val_smtptr_param<wxwxMenuItemListNode >(node_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxwxMenuItemListNode* node = node_smtptr.get();

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->DetachNode(node);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxMenuItemList::DeleteNode(wxwxMenuItemListNode * node)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_DeleteNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxwxMenuItemListNode, "parameter named 'node'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_DeleteNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxwxMenuItemListNode > node_smtptr;
  if (!get_val_smtptr_param<wxwxMenuItemListNode >(node_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxwxMenuItemListNode* node = node_smtptr.get();

  bool res =   this->_objectptr->GetObj()->DeleteNode(node);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuItemList::DeleteObject(wxMenuItem * object)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_DeleteObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'object'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_DeleteObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuItem > object_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(object_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuItem* object = object_smtptr.get();

  bool res =   this->_objectptr->GetObj()->DeleteObject(object);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::Erase(wxwxMenuItemListNode * it)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Erase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxwxMenuItemListNode, "parameter named 'it'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Erase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxwxMenuItemListNode > it_smtptr;
  if (!get_val_smtptr_param<wxwxMenuItemListNode >(it_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxwxMenuItemListNode* it = it_smtptr.get();

  this->_objectptr->GetObj()->Erase(it);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::Find(wxMenuItem const * object)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Find_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'object'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Find_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMenuItem > object_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(object_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* object = object_smtptr.get();

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->Find(object);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::Find(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Find::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Find::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuItemList::wrap_Find_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuItemList::wrap_Find_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxMenuItemList::Find(wxListKey const & key)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Find_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'key'")
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Find_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxListKey const & key = *key_smtptr;

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->Find(key);
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxMenuItemList::IndexOf(wxMenuItem * object)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_IndexOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'object'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_IndexOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuItem > object_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(object_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuItem* object = object_smtptr.get();

  int res =   this->_objectptr->GetObj()->IndexOf(object);
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: _9904

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::Sort(wxSortCompareFunction func)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Sort_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _9904, "parameter named 'func'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
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
//  Wrapping of multipled defined method:... wxMenuItemList::Sort(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Sort::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Sort::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: _8388

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::Sort(wxSortFuncFor_wxMenuItemList func)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_Sort_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _8388, "parameter named 'func'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_Sort_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  _8388 func;
  if (!get_val_param<_8388 >(func,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Sort(func);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxMenuItemList::begin()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_begin_1::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_begin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::begin(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_begin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_begin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxMenuItemList::begin()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_begin_2::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_begin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxMenuItemList::end()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_end_1::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_end_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::end(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_end::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_end::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxMenuItemList::end()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_end_2::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_end_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxMenuItemList::rbegin()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_rbegin_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_rbegin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::rbegin(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_rbegin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_rbegin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxMenuItemList::rbegin()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_rbegin_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_rbegin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxMenuItemList::rend()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_rend_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_rend_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::rend(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_rend::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_rend::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxMenuItemList::rend()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_rend_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_rend_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::resize(size_t n, wxMenuItem * v = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_resize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_resize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxMenuItem > v_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuItem* v = v_smtptr.get();

  this->_objectptr->GetObj()->resize(n, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxMenuItemList::size()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxMenuItemList::max_size()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_max_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_max_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->max_size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxMenuItemList::empty()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * & wxMenuItemList::front()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_front_1::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_front_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMenuItem * & res =   this->_objectptr->GetObj()->front();
  return AMILabType<wxMenuItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::front(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_front::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_front::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuItemList::wrap_front_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuItemList::wrap_front_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * const & wxMenuItemList::front()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_front_2::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_front_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMenuItem * const & res =   this->_objectptr->GetObj()->front();
  return AMILabType<wxMenuItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * & wxMenuItemList::back()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_back_1::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_back_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMenuItem * & res =   this->_objectptr->GetObj()->back();
  return AMILabType<wxMenuItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::back(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_back::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_back::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuItemList::wrap_back_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMenuItemList::wrap_back_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * const & wxMenuItemList::back()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_back_2::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_back_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMenuItem * const & res =   this->_objectptr->GetObj()->back();
  return AMILabType<wxMenuItem >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::push_front(wxMenuItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_push_front::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_push_front::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuItem > v_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(v_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxMenuItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->push_front(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::pop_front()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_pop_front::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_pop_front::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->pop_front();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::push_back(wxMenuItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_push_back::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_push_back::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuItem > v_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(v_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxMenuItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->push_back(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::pop_back()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_pop_back::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_pop_back::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->pop_back();
  return BasicVariable::ptr();
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::assign(const_iterator first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_assign_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
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
//  Wrapping of multipled defined method:... wxMenuItemList::assign(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMenuItemList::wrap_assign_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::assign(size_t n, wxMenuItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_assign_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_assign_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxMenuItem > v_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(v_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxMenuItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->assign(n, v);
  return BasicVariable::ptr();
}
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxMenuItemList::insert(iterator const & it, wxMenuItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'v' (def:0u)")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxMenuItem > v_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(v_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxMenuItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  iterator res =   this->_objectptr->GetObj()->insert(it, v);
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMenuItemList::insert(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::insert(iterator const & it, size_t n, wxMenuItem * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
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

  boost::shared_ptr<wxMenuItem > v_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(v_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxMenuItem * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->insert(it, n, v);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::insert(iterator const & it, const_iterator first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
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
//  Wrapping of iterator wxMenuItemList::erase(iterator const & it)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_erase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
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
//  Wrapping of multipled defined method:... wxMenuItemList::erase(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_erase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_erase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator, iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxMenuItemList::erase(iterator const & first, iterator const & last)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_erase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
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
//  Wrapping of void wxMenuItemList::clear()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->clear();
  return BasicVariable::ptr();
}
/* The following types are missing: iterator, iterator, iterator

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::splice(iterator const & it, wxMenuItemList & l, iterator const & first, iterator const & last)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_splice_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxMenuItemList, "parameter named 'l'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_splice_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxMenuItemList > l_smtptr;
  if (!get_val_smtptr_param<wxMenuItemList >(l_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItemList & l = *l_smtptr;

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
//  Wrapping of multipled defined method:... wxMenuItemList::splice(...)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_splice::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_splice::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::splice(iterator const & it, wxMenuItemList & l)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_splice_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxMenuItemList, "parameter named 'l'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_splice_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxMenuItemList > l_smtptr;
  if (!get_val_smtptr_param<wxMenuItemList >(l_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItemList & l = *l_smtptr;

  this->_objectptr->GetObj()->splice(it, l);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::splice(iterator const & it, wxMenuItemList & l, iterator const & first)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_splice_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxMenuItemList, "parameter named 'l'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_splice_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxMenuItemList > l_smtptr;
  if (!get_val_smtptr_param<wxMenuItemList >(l_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItemList & l = *l_smtptr;

  boost::shared_ptr<iterator > first_smtptr;
  if (!get_val_smtptr_param<iterator >(first_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & first = *first_smtptr;

  this->_objectptr->GetObj()->splice(it, l, first);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::remove(wxMenuItem * const & v)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_remove::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_remove::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuItem > v_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuItem * const & v = v_smtptr.get();

  this->_objectptr->GetObj()->remove(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxMenuItemList::reverse()
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap_reverse::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap_reverse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->reverse();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxMenuItemList & wxMenuItemList::operator =(wxMenuItemList const & list)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItemList, "parameter named 'list'")
  return_comments="returning a variable of type wxMenuItemList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuItemList > list_smtptr;
  if (!get_val_smtptr_param<wxMenuItemList >(list_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuItemList const & list = *list_smtptr;

  wxMenuItemList & res =   (*this->_objectptr->GetObj()) = (list);
  return AMILabType<wxMenuItemList >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxMenuItemList::operator [](size_t index)
//---------------------------------------------------
void WrapClass_wxMenuItemList::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMenuItemList::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  wxMenuItem * res =   (*this->_objectptr->GetObj()) [ (index)];
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

