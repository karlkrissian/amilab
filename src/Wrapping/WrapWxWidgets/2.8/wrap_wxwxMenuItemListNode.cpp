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

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxwxMenuItemListNode.h"

// get all the required includes
// #include "..."
#ifndef wxListBase_declared
  #define wxListBase_declared
  AMI_DECLARE_TYPE(wxListBase)
#endif
#ifndef wxwxMenuItemListNode_declared
  #define wxwxMenuItemListNode_declared
  AMI_DECLARE_TYPE(wxwxMenuItemListNode)
#endif
#ifndef wxMenuItem_declared
  #define wxMenuItem_declared
  AMI_DECLARE_TYPE(wxMenuItem)
#endif
#ifndef wxListKey_declared
  #define wxListKey_declared
  AMI_DECLARE_TYPE(wxListKey)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

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
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetNext( this_ptr);
  AddVar_GetPrevious( this_ptr);
  AddVar_GetData( this_ptr);
  AddVar_SetData( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxNodeBase
  boost::shared_ptr<wxNodeBase > parent_wxNodeBase(  boost::dynamic_pointer_cast<wxNodeBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxNodeBase = AMILabType<wxNodeBase >::CreateVarFromSmtPtr(parent_wxNodeBase);
  context->AddVar("wxNodeBase",var_wxNodeBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxNodeBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxNodeBase);
  context->AddDefault(obj_wxNodeBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxwxMenuItemListNode_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxwxMenuItemListNode");
    WrapClass_wxwxMenuItemListNode::AddVar_wxwxMenuItemListNode(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

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

  wxListBase* list = 0u;
  if (CheckNullVar(_p,_n))  {
    list=(wxListBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxListBase > list_smtptr;
    if (!get_val_smtptr_param<wxListBase >(list_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    list = list_smtptr.get();
  }

  wxwxMenuItemListNode* previous = 0u;
  if (CheckNullVar(_p,_n))  {
    previous=(wxwxMenuItemListNode*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxwxMenuItemListNode > previous_smtptr;
    if (!get_val_smtptr_param<wxwxMenuItemListNode >(previous_smtptr,_p,_n,false,true,false)) ClassHelpAndReturn;
    previous = previous_smtptr.get();
  }

  wxwxMenuItemListNode* next = 0u;
  if (CheckNullVar(_p,_n))  {
    next=(wxwxMenuItemListNode*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxwxMenuItemListNode > next_smtptr;
    if (!get_val_smtptr_param<wxwxMenuItemListNode >(next_smtptr,_p,_n,false,true,false)) ClassHelpAndReturn;
    next = next_smtptr.get();
  }

  wxMenuItem* data = 0u;
  if (CheckNullVar(_p,_n))  {
    data=(wxMenuItem*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenuItem > data_smtptr;
    if (!get_val_smtptr_param<wxMenuItem >(data_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

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
  BasicVariable::ptr res_var = AMILabType<wxwxMenuItemListNode >::CreateVar(res,true);
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
  BasicVariable::ptr res_var = AMILabType<wxwxMenuItemListNode >::CreateVar(res,true);
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
  BasicVariable::ptr res_var = AMILabType<wxMenuItem >::CreateVar(res,true);
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

  wxMenuItem* data;
  if (CheckNullVar(_p,_n))  {
    data=(wxMenuItem*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenuItem > data_smtptr;
    if (!get_val_smtptr_param<wxMenuItem >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->SetData(data);
  return BasicVariable::ptr();
}

