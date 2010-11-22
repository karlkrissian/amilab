/**
 * C++ Interface: wrap_wxWindowList
 *
 * Description: wrapping wxWindowList
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
#include "wrap_wxWindowList.h"
#include "wrap_wxWindow.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxWindowListNode.h"
#include "wrap_wxWindowBase.h"
#include "stdlib.h"
#include "wrap_wxListKey.h"


#include "wrap_wxWindowList.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxWindowList>::CreateVar( ParamList* p)
{
  WrapClass_wxWindowList::wrap_wxWindowList construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxWindowList);
AMI_DEFINE_VARFROMSMTPTR(wxWindowList);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxWindowList
//
Variable<AMIObject>::ptr WrapClass_wxWindowList::CreateVar( wxWindowList* sp)
{
  boost::shared_ptr<wxWindowList> di_ptr(
    sp,
    wxwindow_nodeleter<wxWindowList>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxWindowList>::CreateVar(
      new WrapClass_wxWindowList(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxWindowList::AddMethods(WrapClass<wxWindowList>::ptr this_ptr )
{
  
      // Add members from wxListBase
      WrapClass_wxListBase::ptr parent_wxListBase(        boost::dynamic_pointer_cast<WrapClass_wxListBase >(this_ptr));
      parent_wxListBase->AddMethods(parent_wxListBase);


  // check that the method name is not a token
  
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
/* The following types are missing: _9505
      AddVar_Sort_1( this_ptr);
*/
      AddVar_Sort( this_ptr);
/* The following types are missing: _10213
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



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxWindowList::wxWindowList(wxKeyType keyType = wxKEY_NONE)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_wxWindowList_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'keyType' (def:wxKEY_NONE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_wxWindowList_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int keyType_int = (int) wxKEY_NONE;;
  if (!get_val_param<int >(keyType_int,_p,_n)) ClassReturnEmptyVar;
  wxKeyType keyType = (wxKeyType) keyType_int;

  wxWindowList* _newobj = new wxWindowList(keyType);
  BasicVariable::ptr res = WrapClass_wxWindowList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxWindowList::wxWindowList(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_wxWindowList::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_wxWindowList::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowList::wrap_wxWindowList_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowList::wrap_wxWindowList_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxWindowList::wrap_wxWindowList_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxWindowList::wrap_wxWindowList_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWindowList::wxWindowList(wxWindowList const & list)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_wxWindowList_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowList, "parameter named 'list'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_wxWindowList_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindowList > list_smtptr;
  if (!get_val_smtptr_param<wxWindowList >(list_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxWindowList const & list = *list_smtptr;

  wxWindowList* _newobj = new wxWindowList(list);
  BasicVariable::ptr res = WrapClass_wxWindowList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWindowList::wxWindowList(size_t count, wxWindow * * elements)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_wxWindowList_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_wxWindowList_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long count_long;
  if (!get_val_param<long >(count_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  boost::shared_ptr<wxWindow > elements_smtptr;
  if (!get_val_smtptr_param<wxWindow >(elements_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* elements = elements_smtptr.get();

  wxWindowList* _newobj = new wxWindowList(count, elements);
  BasicVariable::ptr res = WrapClass_wxWindowList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWindowList::wxWindowList(size_t n, wxWindow * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_wxWindowList_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_wxWindowList_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxWindow > v_smtptr;
  if (!get_val_smtptr_param<wxWindow >(v_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxWindow * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  wxWindowList* _newobj = new wxWindowList(n, v);
  BasicVariable::ptr res = WrapClass_wxWindowList::CreateVar(_newobj);
  return res;
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of Constructor wxWindowList::wxWindowList(const_iterator const & first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_wxWindowList_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_wxWindowList_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<const_iterator > first_smtptr;
  if (!get_val_smtptr_param<const_iterator >(first_smtptr,_p,_n)) ClassReturnEmptyVar;
  const_iterator const & first = *first_smtptr;

  boost::shared_ptr<const_iterator > last_smtptr;
  if (!get_val_smtptr_param<const_iterator >(last_smtptr,_p,_n)) ClassReturnEmptyVar;
  const_iterator const & last = *last_smtptr;

  wxWindowList* _newobj = new wxWindowList(first, last);
  BasicVariable::ptr res = WrapClass_wxWindowList::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxWindowList.
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxWindowList object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxWindowList >::CreateVar( new wxWindowList(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::GetFirst()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_GetFirst::SetParametersComments()
{
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_GetFirst::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindowListNode * res =   this->_objectptr->GetObj()->GetFirst();
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::GetLast()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_GetLast::SetParametersComments()
{
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_GetLast::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindowListNode * res =   this->_objectptr->GetObj()->GetLast();
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::Item(size_t index)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Item::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Item::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  wxWindowListNode * res =   this->_objectptr->GetObj()->Item(index);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::Append(wxWindowBase * object)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Append_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'object'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Append_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindowBase > object_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindowBase* object = object_smtptr.get();

  wxWindowListNode * res =   this->_objectptr->GetObj()->Append(object);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::Insert(wxWindowBase * object)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'object'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindowBase > object_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindowBase* object = object_smtptr.get();

  wxWindowListNode * res =   this->_objectptr->GetObj()->Insert(object);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::Insert(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowList::wrap_Insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowList::wrap_Insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxWindowList::wrap_Insert_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::Insert(size_t pos, wxWindowBase * object)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'object'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxWindowBase > object_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindowBase* object = object_smtptr.get();

  wxWindowListNode * res =   this->_objectptr->GetObj()->Insert(pos, object);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::Insert(wxWindowListNode * prev, wxWindowBase * object)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowListNode, "parameter named 'prev'")
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'object'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindowListNode > prev_smtptr;
  if (!get_val_smtptr_param<wxWindowListNode >(prev_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindowListNode* prev = prev_smtptr.get();

  boost::shared_ptr<wxWindowBase > object_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindowBase* object = object_smtptr.get();

  wxWindowListNode * res =   this->_objectptr->GetObj()->Insert(prev, object);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::Append(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowList::wrap_Append_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::Append(long int key, void * object)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Append_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'object'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Append_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long key_long;
  if (!get_val_param<long >(key_long,_p,_n)) ClassReturnEmptyVar;
  long int key = key_long;

  boost::shared_ptr<void > object_smtptr;
  if (!get_val_smtptr_param<void >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  void* object = object_smtptr.get();

  wxWindowListNode * res =   this->_objectptr->GetObj()->Append(key, object);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}
*/
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::Append(wxChar const * key, void * object)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'object'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Append_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > key_string;
  if (!get_val_smtptr_param<std::string >(key_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t key[key_string->size()+1];
mbstowcs(key,key_string->c_str(),key_string->size()+1);

  boost::shared_ptr<void > object_smtptr;
  if (!get_val_smtptr_param<void >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  void* object = object_smtptr.get();

  wxWindowListNode * res =   this->_objectptr->GetObj()->Append(key, object);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::DetachNode(wxWindowListNode * node)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_DetachNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowListNode, "parameter named 'node'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_DetachNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowListNode > node_smtptr;
  if (!get_val_smtptr_param<wxWindowListNode >(node_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowListNode* node = node_smtptr.get();

  wxWindowListNode * res =   this->_objectptr->GetObj()->DetachNode(node);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxWindowList::DeleteNode(wxWindowListNode * node)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_DeleteNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowListNode, "parameter named 'node'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_DeleteNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowListNode > node_smtptr;
  if (!get_val_smtptr_param<wxWindowListNode >(node_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowListNode* node = node_smtptr.get();

  bool res =   this->_objectptr->GetObj()->DeleteNode(node);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowList::DeleteObject(wxWindowBase * object)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_DeleteObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'object'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_DeleteObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > object_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(object_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* object = object_smtptr.get();

  bool res =   this->_objectptr->GetObj()->DeleteObject(object);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxWindowList::Erase(wxWindowListNode * it)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Erase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowListNode, "parameter named 'it'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Erase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowListNode > it_smtptr;
  if (!get_val_smtptr_param<wxWindowListNode >(it_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowListNode* it = it_smtptr.get();

  this->_objectptr->GetObj()->Erase(it);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::Find(wxWindowBase const * object)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Find_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'object'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Find_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindowBase > object_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindowBase* object = object_smtptr.get();

  wxWindowListNode * res =   this->_objectptr->GetObj()->Find(object);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::Find(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Find::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Find::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowList::wrap_Find_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowList::wrap_Find_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowList::Find(wxListKey const & key)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Find_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'key'")
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Find_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxListKey const & key = *key_smtptr;

  wxWindowListNode * res =   this->_objectptr->GetObj()->Find(key);
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxWindowList::IndexOf(wxWindowBase * object)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_IndexOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'object'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_IndexOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > object_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(object_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* object = object_smtptr.get();

  int res =   this->_objectptr->GetObj()->IndexOf(object);
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: _9505

//---------------------------------------------------
//  Wrapping of void wxWindowList::Sort(wxSortCompareFunction func)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Sort_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _9505, "parameter named 'func'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Sort_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  _9505 func;
  if (!get_val_param<_9505 >(func,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Sort(func);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::Sort(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Sort::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Sort::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: _10213

//---------------------------------------------------
//  Wrapping of void wxWindowList::Sort(wxSortFuncFor_wxWindowList func)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_Sort_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _10213, "parameter named 'func'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_Sort_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  _10213 func;
  if (!get_val_param<_10213 >(func,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Sort(func);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxWindowList::begin()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_begin_1::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_begin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::begin(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_begin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_begin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxWindowList::begin()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_begin_2::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_begin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxWindowList::end()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_end_1::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_end_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::end(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_end::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_end::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxWindowList::end()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_end_2::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_end_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxWindowList::rbegin()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_rbegin_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_rbegin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::rbegin(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_rbegin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_rbegin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxWindowList::rbegin()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_rbegin_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_rbegin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxWindowList::rend()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_rend_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_rend_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::rend(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_rend::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_rend::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxWindowList::rend()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_rend_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_rend_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowList::resize(size_t n, wxWindow * v = 0u)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_resize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_resize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxWindow > v_smtptr;
  if (!get_val_smtptr_param<wxWindow >(v_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* v = v_smtptr.get();

  this->_objectptr->GetObj()->resize(n, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxWindowList::size()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxWindowList::max_size()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_max_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_max_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->max_size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxWindowList::empty()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxWindow * & wxWindowList::front()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_front_1::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_front_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxWindow * & res =   this->_objectptr->GetObj()->front();
  return AMILabType<wxWindow >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::front(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_front::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_front::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowList::wrap_front_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowList::wrap_front_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxWindow * const & wxWindowList::front()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_front_2::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_front_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxWindow * const & res =   this->_objectptr->GetObj()->front();
  return AMILabType<wxWindow >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxWindow * & wxWindowList::back()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_back_1::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_back_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxWindow * & res =   this->_objectptr->GetObj()->back();
  return AMILabType<wxWindow >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::back(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_back::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_back::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowList::wrap_back_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWindowList::wrap_back_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxWindow * const & wxWindowList::back()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_back_2::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_back_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxWindow * const & res =   this->_objectptr->GetObj()->back();
  return AMILabType<wxWindow >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxWindowList::push_front(wxWindow * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_push_front::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_push_front::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > v_smtptr;
  if (!get_val_smtptr_param<wxWindow >(v_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxWindow * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->push_front(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowList::pop_front()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_pop_front::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_pop_front::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->pop_front();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowList::push_back(wxWindow * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_push_back::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_push_back::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > v_smtptr;
  if (!get_val_smtptr_param<wxWindow >(v_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxWindow * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->push_back(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowList::pop_back()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_pop_back::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_pop_back::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->pop_back();
  return BasicVariable::ptr();
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void wxWindowList::assign(const_iterator first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_assign_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_assign_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  const_iterator first;
  if (!get_val_param<const_iterator >(first,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<const_iterator > last_smtptr;
  if (!get_val_smtptr_param<const_iterator >(last_smtptr,_p,_n)) ClassReturnEmptyVar;
  const_iterator const & last = *last_smtptr;

  this->_objectptr->GetObj()->assign(first, last);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::assign(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWindowList::wrap_assign_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxWindowList::assign(size_t n, wxWindow * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_assign_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_assign_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxWindow > v_smtptr;
  if (!get_val_smtptr_param<wxWindow >(v_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxWindow * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->assign(n, v);
  return BasicVariable::ptr();
}
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxWindowList::insert(iterator const & it, wxWindow * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'v' (def:0u)")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxWindow > v_smtptr;
  if (!get_val_smtptr_param<wxWindow >(v_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxWindow * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  iterator res =   this->_objectptr->GetObj()->insert(it, v);
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::insert(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxWindowList::insert(iterator const & it, size_t n, wxWindow * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxWindow > v_smtptr;
  if (!get_val_smtptr_param<wxWindow >(v_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxWindow * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->insert(it, n, v);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void wxWindowList::insert(iterator const & it, const_iterator first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  const_iterator first;
  if (!get_val_param<const_iterator >(first,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<const_iterator > last_smtptr;
  if (!get_val_smtptr_param<const_iterator >(last_smtptr,_p,_n)) ClassReturnEmptyVar;
  const_iterator const & last = *last_smtptr;

  this->_objectptr->GetObj()->insert(it, first, last);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxWindowList::erase(iterator const & it)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_erase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_erase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  iterator res =   this->_objectptr->GetObj()->erase(it);
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::erase(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_erase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_erase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator, iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxWindowList::erase(iterator const & first, iterator const & last)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_erase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_erase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > first_smtptr;
  if (!get_val_smtptr_param<iterator >(first_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & first = *first_smtptr;

  boost::shared_ptr<iterator > last_smtptr;
  if (!get_val_smtptr_param<iterator >(last_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & last = *last_smtptr;

  iterator res =   this->_objectptr->GetObj()->erase(first, last);
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowList::clear()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->clear();
  return BasicVariable::ptr();
}
/* The following types are missing: iterator, iterator, iterator

//---------------------------------------------------
//  Wrapping of void wxWindowList::splice(iterator const & it, wxWindowList & l, iterator const & first, iterator const & last)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_splice_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxWindowList, "parameter named 'l'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_splice_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxWindowList > l_smtptr;
  if (!get_val_smtptr_param<wxWindowList >(l_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindowList & l = *l_smtptr;

  boost::shared_ptr<iterator > first_smtptr;
  if (!get_val_smtptr_param<iterator >(first_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & first = *first_smtptr;

  boost::shared_ptr<iterator > last_smtptr;
  if (!get_val_smtptr_param<iterator >(last_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & last = *last_smtptr;

  this->_objectptr->GetObj()->splice(it, l, first, last);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWindowList::splice(...)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_splice::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_splice::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxWindowList::splice(iterator const & it, wxWindowList & l)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_splice_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxWindowList, "parameter named 'l'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_splice_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxWindowList > l_smtptr;
  if (!get_val_smtptr_param<wxWindowList >(l_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindowList & l = *l_smtptr;

  this->_objectptr->GetObj()->splice(it, l);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of void wxWindowList::splice(iterator const & it, wxWindowList & l, iterator const & first)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_splice_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxWindowList, "parameter named 'l'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_splice_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxWindowList > l_smtptr;
  if (!get_val_smtptr_param<wxWindowList >(l_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindowList & l = *l_smtptr;

  boost::shared_ptr<iterator > first_smtptr;
  if (!get_val_smtptr_param<iterator >(first_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & first = *first_smtptr;

  this->_objectptr->GetObj()->splice(it, l, first);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxWindowList::remove(wxWindow * const & v)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_remove::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_remove::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > v_smtptr;
  if (!get_val_smtptr_param<wxWindow >(v_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow * const & v = v_smtptr.get();

  this->_objectptr->GetObj()->remove(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxWindowList::reverse()
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap_reverse::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap_reverse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->reverse();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindowList & wxWindowList::operator =(wxWindowList const & list)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowList, "parameter named 'list'")
  return_comments="returning a variable of type wxWindowList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowList > list_smtptr;
  if (!get_val_smtptr_param<wxWindowList >(list_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowList const & list = *list_smtptr;

  wxWindowList & res =   (*this->_objectptr->GetObj()) = (list);
  return AMILabType<wxWindowList >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowList::operator [](size_t index)
//---------------------------------------------------
void WrapClass_wxWindowList::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowList::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  wxWindow * res =   (*this->_objectptr->GetObj()) [ (index)];
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

