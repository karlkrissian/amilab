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

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxwxSizerItemListNode.h"

// get all the required includes
// #include "..."
#ifndef wxListBase_declared
  #define wxListBase_declared
  AMI_DECLARE_TYPE(wxListBase)
#endif
#ifndef wxwxSizerItemListNode_declared
  #define wxwxSizerItemListNode_declared
  AMI_DECLARE_TYPE(wxwxSizerItemListNode)
#endif
#ifndef wxSizerItem_declared
  #define wxSizerItem_declared
  AMI_DECLARE_TYPE(wxSizerItem)
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
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetNext( this_ptr);
  AddVar_GetPrevious( this_ptr);
  AddVar_GetData( this_ptr);
  AddVar_SetData( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

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
void WrapClasswxwxSizerItemListNode_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxwxSizerItemListNode");
    WrapClass_wxwxSizerItemListNode::AddVar_wxwxSizerItemListNode(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

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

  wxListBase* list = 0u;
  if (CheckNullVar(_p,_n))  {
    list=(wxListBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxListBase > list_smtptr;
    if (!get_val_smtptr_param<wxListBase >(list_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    list = list_smtptr.get();
  }

  wxwxSizerItemListNode* previous = 0u;
  if (CheckNullVar(_p,_n))  {
    previous=(wxwxSizerItemListNode*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxwxSizerItemListNode > previous_smtptr;
    if (!get_val_smtptr_param<wxwxSizerItemListNode >(previous_smtptr,_p,_n,false,true,false)) ClassHelpAndReturn;
    previous = previous_smtptr.get();
  }

  wxwxSizerItemListNode* next = 0u;
  if (CheckNullVar(_p,_n))  {
    next=(wxwxSizerItemListNode*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxwxSizerItemListNode > next_smtptr;
    if (!get_val_smtptr_param<wxwxSizerItemListNode >(next_smtptr,_p,_n,false,true,false)) ClassHelpAndReturn;
    next = next_smtptr.get();
  }

  wxSizerItem* data = 0u;
  if (CheckNullVar(_p,_n))  {
    data=(wxSizerItem*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxSizerItem > data_smtptr;
    if (!get_val_smtptr_param<wxSizerItem >(data_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxListKey const & key = ( key_smtptr.get() ? (*key_smtptr) : wxDefaultListKey );

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
  BasicVariable::ptr res_var = AMILabType<wxwxSizerItemListNode >::CreateVar(res,true);
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
  BasicVariable::ptr res_var = AMILabType<wxwxSizerItemListNode >::CreateVar(res,true);
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
  BasicVariable::ptr res_var = AMILabType<wxSizerItem >::CreateVar(res,true);
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

  wxSizerItem* data;
  if (CheckNullVar(_p,_n))  {
    data=(wxSizerItem*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxSizerItem > data_smtptr;
    if (!get_val_smtptr_param<wxSizerItem >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->SetData(data);
  return BasicVariable::ptr();
}

