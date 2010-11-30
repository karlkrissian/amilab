/**
 * C++ Interface: wrap_wxwxMenuItemListNode
 *
 * Description: wrapping wxwxMenuItemListNode
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
#include "wrap_wxwxMenuItemListNode.h"
#include "wrap_wxMenuItem.h"
#include "wrap_wxListKey.h"


#include "wrap_wxwxMenuItemListNode.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxwxMenuItemListNode>::CreateVar( ParamList* p)
{
  WrapClass_wxwxMenuItemListNode::wrap_wxwxMenuItemListNode construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxwxMenuItemListNode);
AMI_DEFINE_VARFROMSMTPTR(wxwxMenuItemListNode);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxwxMenuItemListNode>::CreateVar( wxwxMenuItemListNode* val, bool nodeleter)
{ 
  boost::shared_ptr<wxwxMenuItemListNode> obj_ptr(val,smartpointer_nodeleter<wxwxMenuItemListNode>());
  return AMILabType<wxwxMenuItemListNode>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxwxMenuItemListNode
//
Variable<AMIObject>::ptr WrapClass_wxwxMenuItemListNode::CreateVar( wxwxMenuItemListNode* sp)
{
  boost::shared_ptr<wxwxMenuItemListNode> di_ptr(
    sp,
    wxwindow_nodeleter<wxwxMenuItemListNode>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxwxMenuItemListNode>::CreateVar(
      new WrapClass_wxwxMenuItemListNode(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxwxMenuItemListNode::AddMethods(WrapClass<wxwxMenuItemListNode>::ptr this_ptr )
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
//  Wrapping of Constructor wxwxMenuItemListNode::wxwxMenuItemListNode(wxListBase * list = 0u, wxwxMenuItemListNode * previous = 0u, wxwxMenuItemListNode * next = 0u, wxMenuItem * data = 0u, wxListKey const & key = wxDefaultListKey)
//---------------------------------------------------
void WrapClass_wxwxMenuItemListNode::
    wrap_wxwxMenuItemListNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListBase, "parameter named 'list' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxwxMenuItemListNode, "parameter named 'previous' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxwxMenuItemListNode, "parameter named 'next' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'data' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'key' (def:wxDefaultListKey)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxMenuItemListNode::
    wrap_wxwxMenuItemListNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxListBase > list_smtptr;
  if (!get_val_smtptr_param<wxListBase >(list_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxListBase* list = list_smtptr.get();

  boost::shared_ptr<wxwxMenuItemListNode > previous_smtptr;
  if (!get_val_smtptr_param<wxwxMenuItemListNode >(previous_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  wxwxMenuItemListNode* previous = previous_smtptr.get();

  boost::shared_ptr<wxwxMenuItemListNode > next_smtptr;
  if (!get_val_smtptr_param<wxwxMenuItemListNode >(next_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  wxwxMenuItemListNode* next = next_smtptr.get();

  boost::shared_ptr<wxMenuItem > data_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuItem* data = data_smtptr.get();

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxListKey const & key = ( key_smtptr.get() ? (*key_smtptr) : wxDefaultListKey );

  wxwxMenuItemListNode* _newobj = new wxwxMenuItemListNode(list, previous, next, data, key);
  BasicVariable::ptr res = WrapClass_wxwxMenuItemListNode::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxwxMenuItemListNode::GetNext()
//---------------------------------------------------
void WrapClass_wxwxMenuItemListNode::
    wrap_GetNext::SetParametersComments()
{
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxMenuItemListNode::
    wrap_GetNext::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->GetNext();
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxwxMenuItemListNode * wxwxMenuItemListNode::GetPrevious()
//---------------------------------------------------
void WrapClass_wxwxMenuItemListNode::
    wrap_GetPrevious::SetParametersComments()
{
  return_comments="returning a variable of type wxwxMenuItemListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxMenuItemListNode::
    wrap_GetPrevious::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxwxMenuItemListNode * res =   this->_objectptr->GetObj()->GetPrevious();
  BasicVariable::ptr res_var = WrapClass_wxwxMenuItemListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxwxMenuItemListNode::GetData()
//---------------------------------------------------
void WrapClass_wxwxMenuItemListNode::
    wrap_GetData::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxMenuItemListNode::
    wrap_GetData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenuItem * res =   this->_objectptr->GetObj()->GetData();
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxwxMenuItemListNode::SetData(wxMenuItem * data)
//---------------------------------------------------
void WrapClass_wxwxMenuItemListNode::
    wrap_SetData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxwxMenuItemListNode::
    wrap_SetData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuItem > data_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuItem* data = data_smtptr.get();

  this->_objectptr->GetObj()->SetData(data);
  return BasicVariable::ptr();
}

