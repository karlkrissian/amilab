/**
 * C++ Interface: wrap_wxwxSizerItemListNode
 *
 * Description: wrapping wxwxSizerItemListNode
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
#include "wrap_wxListBase.h"
#include "wrap_wxwxSizerItemListNode.h"
#include "wrap_wxSizerItem.h"
#include "wrap_wxListKey.h"


#include "wrap_wxwxSizerItemListNode.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxwxSizerItemListNode>::CreateVar( ParamList* p)
{
  WrapClass_wxwxSizerItemListNode::wrap_wxwxSizerItemListNode construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxwxSizerItemListNode);
AMI_DEFINE_VARFROMSMTPTR(wxwxSizerItemListNode);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxwxSizerItemListNode>::CreateVar( wxwxSizerItemListNode* val, bool nodeleter)
{ 
  boost::shared_ptr<wxwxSizerItemListNode> obj_ptr(val,smartpointer_nodeleter<wxwxSizerItemListNode>());
  return AMILabType<wxwxSizerItemListNode>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxwxSizerItemListNode
//
Variable<AMIObject>::ptr WrapClass_wxwxSizerItemListNode::CreateVar( wxwxSizerItemListNode* sp)
{
  boost::shared_ptr<wxwxSizerItemListNode> di_ptr(
    sp,
    wxwindow_nodeleter<wxwxSizerItemListNode>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxwxSizerItemListNode>::CreateVar(
      new WrapClass_wxwxSizerItemListNode(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxwxSizerItemListNode::AddMethods(WrapClass<wxwxSizerItemListNode>::ptr this_ptr )
{
  
      // Add members from wxNodeBase
      WrapClass_wxNodeBase::ptr parent_wxNodeBase(        boost::dynamic_pointer_cast<WrapClass_wxNodeBase >(this_ptr));
      parent_wxNodeBase->AddMethods(parent_wxNodeBase);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_GetNext( this_ptr);
      AddVar_GetPrevious( this_ptr);
      AddVar_GetData( this_ptr);
      AddVar_SetData( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxwxSizerItemListNode::wxwxSizerItemListNode(wxListBase * list = 0u, wxwxSizerItemListNode * previous = 0u, wxwxSizerItemListNode * next = 0u, wxSizerItem * data = 0u, wxListKey const & key = wxDefaultListKey)
//---------------------------------------------------
void WrapClass_wxwxSizerItemListNode::
    wrap_wxwxSizerItemListNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListBase, "parameter named 'list' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxwxSizerItemListNode, "parameter named 'previous' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxwxSizerItemListNode, "parameter named 'next' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'data' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'key' (def:wxDefaultListKey)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxSizerItemListNode::
    wrap_wxwxSizerItemListNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxListBase > list_smtptr;
  if (!get_val_smtptr_param<wxListBase >(list_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxListBase* list = list_smtptr.get();

  boost::shared_ptr<wxwxSizerItemListNode > previous_smtptr;
  if (!get_val_smtptr_param<wxwxSizerItemListNode >(previous_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  wxwxSizerItemListNode* previous = previous_smtptr.get();

  boost::shared_ptr<wxwxSizerItemListNode > next_smtptr;
  if (!get_val_smtptr_param<wxwxSizerItemListNode >(next_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  wxwxSizerItemListNode* next = next_smtptr.get();

  boost::shared_ptr<wxSizerItem > data_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizerItem* data = data_smtptr.get();

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxListKey const & key = ( key_smtptr.get() ? (*key_smtptr) : wxListKey(wxDefaultListKey) );

  wxwxSizerItemListNode* _newobj = new wxwxSizerItemListNode(list, previous, next, data, key);
  BasicVariable::ptr res = WrapClass_wxwxSizerItemListNode::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxwxSizerItemListNode::GetNext()
//---------------------------------------------------
void WrapClass_wxwxSizerItemListNode::
    wrap_GetNext::SetParametersComments()
{
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxSizerItemListNode::
    wrap_GetNext::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->GetNext();
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxSizerItemListNode * wxwxSizerItemListNode::GetPrevious()
//---------------------------------------------------
void WrapClass_wxwxSizerItemListNode::
    wrap_GetPrevious::SetParametersComments()
{
  return_comments="returning a variable of type wxwxSizerItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxSizerItemListNode::
    wrap_GetPrevious::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxwxSizerItemListNode * res =   this->_objectptr->GetObj()->GetPrevious();
  BasicVariable::ptr res_var = WrapClass_wxwxSizerItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxSizerItem * wxwxSizerItemListNode::GetData()
//---------------------------------------------------
void WrapClass_wxwxSizerItemListNode::
    wrap_GetData::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxSizerItemListNode::
    wrap_GetData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerItem * res =   this->_objectptr->GetObj()->GetData();
  BasicVariable::ptr res_var = WrapClass_wxSizerItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxwxSizerItemListNode::SetData(wxSizerItem * data)
//---------------------------------------------------
void WrapClass_wxwxSizerItemListNode::
    wrap_SetData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerItem, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxSizerItemListNode::
    wrap_SetData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizerItem > data_smtptr;
  if (!get_val_smtptr_param<wxSizerItem >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizerItem* data = data_smtptr.get();

  this->_objectptr->GetObj()->SetData(data);
  return BasicVariable::ptr();
}

