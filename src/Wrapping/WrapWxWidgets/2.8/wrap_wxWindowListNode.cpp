/**
 * C++ Interface: wrap_wxWindowListNode
 *
 * Description: wrapping wxWindowListNode
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
#include "wrap_wxWindowListNode.h"
#include "wrap_wxWindow.h"
#include "wrap_wxListKey.h"


#include "wrap_wxWindowListNode.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxWindowListNode>::CreateVar( ParamList* p)
{
  WrapClass_wxWindowListNode::wrap_wxWindowListNode construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxWindowListNode);
AMI_DEFINE_VARFROMSMTPTR(wxWindowListNode);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxWindowListNode>::CreateVar( wxWindowListNode* val, bool nodeleter)
{ 
  boost::shared_ptr<wxWindowListNode> obj_ptr(val,smartpointer_nodeleter<wxWindowListNode>());
  return AMILabType<wxWindowListNode>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxWindowListNode
//
Variable<AMIObject>::ptr WrapClass_wxWindowListNode::CreateVar( wxWindowListNode* sp)
{
  boost::shared_ptr<wxWindowListNode> di_ptr(
    sp,
    wxwindow_nodeleter<wxWindowListNode>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxWindowListNode>::CreateVar(
      new WrapClass_wxWindowListNode(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxWindowListNode::AddMethods(WrapClass<wxWindowListNode>::ptr this_ptr )
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
//  Wrapping of Constructor wxWindowListNode::wxWindowListNode(wxListBase * list = 0u, wxWindowListNode * previous = 0u, wxWindowListNode * next = 0u, wxWindow * data = 0u, wxListKey const & key = wxDefaultListKey)
//---------------------------------------------------
void WrapClass_wxWindowListNode::
    wrap_wxWindowListNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListBase, "parameter named 'list' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxWindowListNode, "parameter named 'previous' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxWindowListNode, "parameter named 'next' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'data' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'key' (def:wxDefaultListKey)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowListNode::
    wrap_wxWindowListNode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxListBase > list_smtptr;
  if (!get_val_smtptr_param<wxListBase >(list_smtptr,_p,_n)) ClassHelpAndReturn;
  wxListBase* list = list_smtptr.get();

  boost::shared_ptr<wxWindowListNode > previous_smtptr;
  if (!get_val_smtptr_param<wxWindowListNode >(previous_smtptr,_p,_n,true,true)) ClassHelpAndReturn;
  wxWindowListNode* previous = previous_smtptr.get();

  boost::shared_ptr<wxWindowListNode > next_smtptr;
  if (!get_val_smtptr_param<wxWindowListNode >(next_smtptr,_p,_n,true,true)) ClassHelpAndReturn;
  wxWindowListNode* next = next_smtptr.get();

  boost::shared_ptr<wxWindow > data_smtptr;
  if (!get_val_smtptr_param<wxWindow >(data_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* data = data_smtptr.get();

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxListKey const & key = ( key_smtptr.get() ? (*key_smtptr) : (wxDefaultListKey) );

  wxWindowListNode* _newobj = new wxWindowListNode(list, previous, next, data, key);
  BasicVariable::ptr res = WrapClass_wxWindowListNode::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowListNode::GetNext()
//---------------------------------------------------
void WrapClass_wxWindowListNode::
    wrap_GetNext::SetParametersComments()
{
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowListNode::
    wrap_GetNext::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindowListNode * res =   this->_objectptr->GetObj()->GetNext();
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindowListNode * wxWindowListNode::GetPrevious()
//---------------------------------------------------
void WrapClass_wxWindowListNode::
    wrap_GetPrevious::SetParametersComments()
{
  return_comments="returning a variable of type wxWindowListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowListNode::
    wrap_GetPrevious::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindowListNode * res =   this->_objectptr->GetObj()->GetPrevious();
  BasicVariable::ptr res_var = WrapClass_wxWindowListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxWindowListNode::GetData()
//---------------------------------------------------
void WrapClass_wxWindowListNode::
    wrap_GetData::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowListNode::
    wrap_GetData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetData();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxWindowListNode::SetData(wxWindow * data)
//---------------------------------------------------
void WrapClass_wxWindowListNode::
    wrap_SetData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWindowListNode::
    wrap_SetData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > data_smtptr;
  if (!get_val_smtptr_param<wxWindow >(data_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* data = data_smtptr.get();

  this->_objectptr->GetObj()->SetData(data);
  return BasicVariable::ptr();
}

