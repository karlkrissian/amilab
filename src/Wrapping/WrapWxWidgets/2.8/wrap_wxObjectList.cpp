/**
 * C++ Interface: wrap_wxObjectList
 *
 * Description: wrapping wxObjectList
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
#include "wrap_wxObjectList.h"
#include "wrap_wxObject.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxObjectListNode.h"
#include "stdlib.h"
#include "wrap_wxListKey.h"


#include "wrap_wxObjectList.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxObjectList>::CreateVar( ParamList* p)
{
  WrapClass_wxObjectList::wrap_wxObjectList construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxObjectList);
AMI_DEFINE_VARFROMSMTPTR(wxObjectList);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxObjectList
//
Variable<AMIObject>::ptr WrapClass_wxObjectList::CreateVar( wxObjectList* sp)
{
  boost::shared_ptr<wxObjectList> di_ptr(
    sp,
    wxwindow_nodeleter<wxObjectList>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxObjectList>::CreateVar(
      new WrapClass_wxObjectList(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxObjectList::AddMethods(WrapClass<wxObjectList>::ptr this_ptr )
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
/* The following types are missing: _8294
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
//  Wrapping of Constructor wxObjectList::wxObjectList(wxKeyType keyType = wxKEY_NONE)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_wxObjectList_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'keyType' (def:wxKEY_NONE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_wxObjectList_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int keyType_int = (int) wxKEY_NONE;;
  if (!get_val_param<int >(keyType_int,_p,_n)) ClassReturnEmptyVar;
  wxKeyType keyType = (wxKeyType) keyType_int;

  wxObjectList* _newobj = new wxObjectList(keyType);
  BasicVariable::ptr res = WrapClass_wxObjectList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxObjectList::wxObjectList(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_wxObjectList::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_wxObjectList::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxObjectList::wrap_wxObjectList_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxObjectList::wrap_wxObjectList_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxObjectList::wrap_wxObjectList_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxObjectList::wrap_wxObjectList_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxObjectList::wxObjectList(wxObjectList const & list)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_wxObjectList_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectList, "parameter named 'list'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_wxObjectList_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxObjectList > list_smtptr;
  if (!get_val_smtptr_param<wxObjectList >(list_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxObjectList const & list = *list_smtptr;

  wxObjectList* _newobj = new wxObjectList(list);
  BasicVariable::ptr res = WrapClass_wxObjectList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxObjectList::wxObjectList(size_t count, wxObject * * elements)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_wxObjectList_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'elements'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_wxObjectList_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long count_long;
  if (!get_val_param<long >(count_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  boost::shared_ptr<wxObject > elements_smtptr;
  if (!get_val_smtptr_param<wxObject >(elements_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* elements = elements_smtptr.get();

  wxObjectList* _newobj = new wxObjectList(count, elements);
  BasicVariable::ptr res = WrapClass_wxObjectList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxObjectList::wxObjectList(size_t n, wxObject * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_wxObjectList_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_wxObjectList_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxObject > v_smtptr;
  if (!get_val_smtptr_param<wxObject >(v_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxObject * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  wxObjectList* _newobj = new wxObjectList(n, v);
  BasicVariable::ptr res = WrapClass_wxObjectList::CreateVar(_newobj);
  return res;
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of Constructor wxObjectList::wxObjectList(const_iterator const & first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_wxObjectList_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_wxObjectList_5::CallMember( ParamList* _p)
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

  wxObjectList* _newobj = new wxObjectList(first, last);
  BasicVariable::ptr res = WrapClass_wxObjectList::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxObjectList.
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxObjectList object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxObjectList >::CreateVar( new wxObjectList(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::GetFirst()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_GetFirst::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_GetFirst::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObjectListNode * res =   this->_objectptr->GetObj()->GetFirst();
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::GetLast()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_GetLast::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_GetLast::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObjectListNode * res =   this->_objectptr->GetObj()->GetLast();
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::Item(size_t index)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Item::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Item::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  wxObjectListNode * res =   this->_objectptr->GetObj()->Item(index);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::Append(wxObject * object)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Append_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'object'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Append_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxObject > object_smtptr;
  if (!get_val_smtptr_param<wxObject >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* object = object_smtptr.get();

  wxObjectListNode * res =   this->_objectptr->GetObj()->Append(object);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::Insert(wxObject * object)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'object'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxObject > object_smtptr;
  if (!get_val_smtptr_param<wxObject >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* object = object_smtptr.get();

  wxObjectListNode * res =   this->_objectptr->GetObj()->Insert(object);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::Insert(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxObjectList::wrap_Insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxObjectList::wrap_Insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxObjectList::wrap_Insert_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::Insert(size_t pos, wxObject * object)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'object'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxObject > object_smtptr;
  if (!get_val_smtptr_param<wxObject >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* object = object_smtptr.get();

  wxObjectListNode * res =   this->_objectptr->GetObj()->Insert(pos, object);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::Insert(wxObjectListNode * prev, wxObject * object)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectListNode, "parameter named 'prev'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'object'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxObjectListNode > prev_smtptr;
  if (!get_val_smtptr_param<wxObjectListNode >(prev_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObjectListNode* prev = prev_smtptr.get();

  boost::shared_ptr<wxObject > object_smtptr;
  if (!get_val_smtptr_param<wxObject >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* object = object_smtptr.get();

  wxObjectListNode * res =   this->_objectptr->GetObj()->Insert(prev, object);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::Append(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxObjectList::wrap_Append_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::Append(long int key, void * object)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Append_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'object'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
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

  wxObjectListNode * res =   this->_objectptr->GetObj()->Append(key, object);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}
*/
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::Append(wxChar const * key, void * object)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'object'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
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

  wxObjectListNode * res =   this->_objectptr->GetObj()->Append(key, object);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::DetachNode(wxObjectListNode * node)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_DetachNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectListNode, "parameter named 'node'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_DetachNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObjectListNode > node_smtptr;
  if (!get_val_smtptr_param<wxObjectListNode >(node_smtptr,_p,_n)) ClassHelpAndReturn;
  wxObjectListNode* node = node_smtptr.get();

  wxObjectListNode * res =   this->_objectptr->GetObj()->DetachNode(node);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxObjectList::DeleteNode(wxObjectListNode * node)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_DeleteNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectListNode, "parameter named 'node'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_DeleteNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObjectListNode > node_smtptr;
  if (!get_val_smtptr_param<wxObjectListNode >(node_smtptr,_p,_n)) ClassHelpAndReturn;
  wxObjectListNode* node = node_smtptr.get();

  bool res =   this->_objectptr->GetObj()->DeleteNode(node);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxObjectList::DeleteObject(wxObject * object)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_DeleteObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'object'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_DeleteObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > object_smtptr;
  if (!get_val_smtptr_param<wxObject >(object_smtptr,_p,_n)) ClassHelpAndReturn;
  wxObject* object = object_smtptr.get();

  bool res =   this->_objectptr->GetObj()->DeleteObject(object);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxObjectList::Erase(wxObjectListNode * it)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Erase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectListNode, "parameter named 'it'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Erase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObjectListNode > it_smtptr;
  if (!get_val_smtptr_param<wxObjectListNode >(it_smtptr,_p,_n)) ClassHelpAndReturn;
  wxObjectListNode* it = it_smtptr.get();

  this->_objectptr->GetObj()->Erase(it);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::Find(wxObject const * object)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Find_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'object'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Find_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxObject > object_smtptr;
  if (!get_val_smtptr_param<wxObject >(object_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObject* object = object_smtptr.get();

  wxObjectListNode * res =   this->_objectptr->GetObj()->Find(object);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::Find(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Find::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Find::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxObjectList::wrap_Find_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxObjectList::wrap_Find_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectList::Find(wxListKey const & key)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Find_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'key'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Find_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxListKey const & key = *key_smtptr;

  wxObjectListNode * res =   this->_objectptr->GetObj()->Find(key);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxObjectList::IndexOf(wxObject * object)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_IndexOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'object'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_IndexOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > object_smtptr;
  if (!get_val_smtptr_param<wxObject >(object_smtptr,_p,_n)) ClassHelpAndReturn;
  wxObject* object = object_smtptr.get();

  int res =   this->_objectptr->GetObj()->IndexOf(object);
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: _9505

//---------------------------------------------------
//  Wrapping of void wxObjectList::Sort(wxSortCompareFunction func)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Sort_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _9505, "parameter named 'func'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
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
//  Wrapping of multipled defined method:... wxObjectList::Sort(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Sort::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Sort::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: _8294

//---------------------------------------------------
//  Wrapping of void wxObjectList::Sort(wxSortFuncFor_wxObjectList func)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_Sort_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _8294, "parameter named 'func'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_Sort_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  _8294 func;
  if (!get_val_param<_8294 >(func,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Sort(func);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxObjectList::begin()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_begin_1::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_begin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::begin(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_begin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_begin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxObjectList::begin()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_begin_2::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_begin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxObjectList::end()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_end_1::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_end_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::end(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_end::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_end::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxObjectList::end()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_end_2::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_end_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxObjectList::rbegin()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_rbegin_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_rbegin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::rbegin(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_rbegin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_rbegin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxObjectList::rbegin()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_rbegin_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_rbegin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxObjectList::rend()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_rend_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_rend_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::rend(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_rend::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_rend::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxObjectList::rend()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_rend_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_rend_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxObjectList::resize(size_t n, wxObject * v = 0u)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_resize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_resize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxObject > v_smtptr;
  if (!get_val_smtptr_param<wxObject >(v_smtptr,_p,_n)) ClassHelpAndReturn;
  wxObject* v = v_smtptr.get();

  this->_objectptr->GetObj()->resize(n, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxObjectList::size()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxObjectList::max_size()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_max_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_max_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->max_size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxObjectList::empty()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxObject * & wxObjectList::front()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_front_1::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_front_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxObject * & res =   this->_objectptr->GetObj()->front();
  return AMILabType<wxObject >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::front(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_front::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_front::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxObjectList::wrap_front_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxObjectList::wrap_front_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxObject * const & wxObjectList::front()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_front_2::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_front_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxObject * const & res =   this->_objectptr->GetObj()->front();
  return AMILabType<wxObject >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxObject * & wxObjectList::back()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_back_1::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_back_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxObject * & res =   this->_objectptr->GetObj()->back();
  return AMILabType<wxObject >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::back(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_back::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_back::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxObjectList::wrap_back_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxObjectList::wrap_back_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxObject * const & wxObjectList::back()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_back_2::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_back_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxObject * const & res =   this->_objectptr->GetObj()->back();
  return AMILabType<wxObject >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxObjectList::push_front(wxObject * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_push_front::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_push_front::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > v_smtptr;
  if (!get_val_smtptr_param<wxObject >(v_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxObject * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->push_front(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxObjectList::pop_front()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_pop_front::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_pop_front::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->pop_front();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxObjectList::push_back(wxObject * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_push_back::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_push_back::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > v_smtptr;
  if (!get_val_smtptr_param<wxObject >(v_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxObject * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->push_back(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxObjectList::pop_back()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_pop_back::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_pop_back::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->pop_back();
  return BasicVariable::ptr();
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void wxObjectList::assign(const_iterator first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_assign_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
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
//  Wrapping of multipled defined method:... wxObjectList::assign(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxObjectList::wrap_assign_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxObjectList::assign(size_t n, wxObject * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_assign_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_assign_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<wxObject > v_smtptr;
  if (!get_val_smtptr_param<wxObject >(v_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxObject * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->assign(n, v);
  return BasicVariable::ptr();
}
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxObjectList::insert(iterator const & it, wxObject * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'v' (def:0u)")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxObject > v_smtptr;
  if (!get_val_smtptr_param<wxObject >(v_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxObject * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  iterator res =   this->_objectptr->GetObj()->insert(it, v);
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxObjectList::insert(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxObjectList::insert(iterator const & it, size_t n, wxObject * const & v = 0u)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'v' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
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

  boost::shared_ptr<wxObject > v_smtptr;
  if (!get_val_smtptr_param<wxObject >(v_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxObject * const & v = ( v_smtptr.get() ? v_smtptr.get() : (0u) );

  this->_objectptr->GetObj()->insert(it, n, v);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void wxObjectList::insert(iterator const & it, const_iterator first, const_iterator const & last)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
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
//  Wrapping of iterator wxObjectList::erase(iterator const & it)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_erase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
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
//  Wrapping of multipled defined method:... wxObjectList::erase(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_erase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_erase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator, iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxObjectList::erase(iterator const & first, iterator const & last)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_erase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
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
//  Wrapping of void wxObjectList::clear()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->clear();
  return BasicVariable::ptr();
}
/* The following types are missing: iterator, iterator, iterator

//---------------------------------------------------
//  Wrapping of void wxObjectList::splice(iterator const & it, wxObjectList & l, iterator const & first, iterator const & last)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_splice_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxObjectList, "parameter named 'l'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_splice_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxObjectList > l_smtptr;
  if (!get_val_smtptr_param<wxObjectList >(l_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObjectList & l = *l_smtptr;

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
//  Wrapping of multipled defined method:... wxObjectList::splice(...)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_splice::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_splice::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxObjectList::splice(iterator const & it, wxObjectList & l)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_splice_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxObjectList, "parameter named 'l'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_splice_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxObjectList > l_smtptr;
  if (!get_val_smtptr_param<wxObjectList >(l_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObjectList & l = *l_smtptr;

  this->_objectptr->GetObj()->splice(it, l);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of void wxObjectList::splice(iterator const & it, wxObjectList & l, iterator const & first)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_splice_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxObjectList, "parameter named 'l'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_splice_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  boost::shared_ptr<wxObjectList > l_smtptr;
  if (!get_val_smtptr_param<wxObjectList >(l_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxObjectList & l = *l_smtptr;

  boost::shared_ptr<iterator > first_smtptr;
  if (!get_val_smtptr_param<iterator >(first_smtptr,_p,_n)) ClassReturnEmptyVar;
  iterator const & first = *first_smtptr;

  this->_objectptr->GetObj()->splice(it, l, first);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxObjectList::remove(wxObject * const & v)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_remove::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_remove::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > v_smtptr;
  if (!get_val_smtptr_param<wxObject >(v_smtptr,_p,_n)) ClassHelpAndReturn;
  wxObject * const & v = v_smtptr.get();

  this->_objectptr->GetObj()->remove(v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxObjectList::reverse()
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap_reverse::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap_reverse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->reverse();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxObjectList & wxObjectList::operator =(wxObjectList const & list)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectList, "parameter named 'list'")
  return_comments="returning a variable of type wxObjectList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObjectList > list_smtptr;
  if (!get_val_smtptr_param<wxObjectList >(list_smtptr,_p,_n)) ClassHelpAndReturn;
  wxObjectList const & list = *list_smtptr;

  wxObjectList & res =   (*this->_objectptr->GetObj()) = (list);
  return AMILabType<wxObjectList >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxObject * wxObjectList::operator [](size_t index)
//---------------------------------------------------
void WrapClass_wxObjectList::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'index'")
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectList::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long index_long;
  if (!get_val_param<long >(index_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int index = boost::numeric_cast<long unsigned int >(index_long);

  wxObject * res =   (*this->_objectptr->GetObj()) [ (index)];
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

