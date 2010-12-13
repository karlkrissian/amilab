/**
 * C++ Interface: wrap_wxObjectListNode
 *
 * Description: wrapping wxObjectListNode
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

#include "wrap_wxObjectListNode.h"

// get all the required includes
// #include "..."
#ifndef wxListBase_declared
  #define wxListBase_declared
  AMI_DECLARE_TYPE(wxListBase)
#endif
#ifndef wxObjectListNode_declared
  #define wxObjectListNode_declared
  AMI_DECLARE_TYPE(wxObjectListNode)
#endif
#ifndef wxObject_declared
  #define wxObject_declared
  AMI_DECLARE_TYPE(wxObject)
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
BasicVariable::ptr WrapClass<wxObjectListNode>::CreateVar( ParamList* p)
{
  WrapClass_wxObjectListNode::wrap_wxObjectListNode construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxObjectListNode);
AMI_DEFINE_VARFROMSMTPTR(wxObjectListNode);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxObjectListNode>::CreateVar( wxObjectListNode* val, bool nodeleter)
{ 
  boost::shared_ptr<wxObjectListNode> obj_ptr(val,smartpointer_nodeleter<wxObjectListNode>());
  return AMILabType<wxObjectListNode>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxObjectListNode
//
Variable<AMIObject>::ptr WrapClass_wxObjectListNode::CreateVar( wxObjectListNode* sp)
{
  boost::shared_ptr<wxObjectListNode> di_ptr(
    sp,
    wxwindow_nodeleter<wxObjectListNode>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxObjectListNode>::CreateVar(
      new WrapClass_wxObjectListNode(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxObjectListNode::AddMethods(WrapClass<wxObjectListNode>::ptr this_ptr )
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
void WrapClasswxObjectListNode_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxObjectListNode");
    WrapClass_wxObjectListNode::AddVar_wxObjectListNode(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxObjectListNode::wxObjectListNode(wxListBase * list = 0u, wxObjectListNode * previous = 0u, wxObjectListNode * next = 0u, wxObject * data = 0u, wxListKey const & key = wxDefaultListKey)
//---------------------------------------------------
void WrapClass_wxObjectListNode::
    wrap_wxObjectListNode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListBase, "parameter named 'list' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxObjectListNode, "parameter named 'previous' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxObjectListNode, "parameter named 'next' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'data' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'key' (def:wxDefaultListKey)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectListNode::
    wrap_wxObjectListNode::CallMember( ParamList* _p)
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

  wxObjectListNode* previous = 0u;
  if (CheckNullVar(_p,_n))  {
    previous=(wxObjectListNode*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObjectListNode > previous_smtptr;
    if (!get_val_smtptr_param<wxObjectListNode >(previous_smtptr,_p,_n,false,true,false)) ClassHelpAndReturn;
    previous = previous_smtptr.get();
  }

  wxObjectListNode* next = 0u;
  if (CheckNullVar(_p,_n))  {
    next=(wxObjectListNode*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObjectListNode > next_smtptr;
    if (!get_val_smtptr_param<wxObjectListNode >(next_smtptr,_p,_n,false,true,false)) ClassHelpAndReturn;
    next = next_smtptr.get();
  }

  wxObject* data = 0u;
  if (CheckNullVar(_p,_n))  {
    data=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > data_smtptr;
    if (!get_val_smtptr_param<wxObject >(data_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxListKey const & key = ( key_smtptr.get() ? (*key_smtptr) : wxDefaultListKey );

  wxObjectListNode* _newobj = new wxObjectListNode(list, previous, next, data, key);
  BasicVariable::ptr res = WrapClass_wxObjectListNode::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectListNode::GetNext()
//---------------------------------------------------
void WrapClass_wxObjectListNode::
    wrap_GetNext::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectListNode::
    wrap_GetNext::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObjectListNode * res =   this->_objectptr->GetObj()->GetNext();
  BasicVariable::ptr res_var = AMILabType<wxObjectListNode >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObjectListNode * wxObjectListNode::GetPrevious()
//---------------------------------------------------
void WrapClass_wxObjectListNode::
    wrap_GetPrevious::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectListNode::
    wrap_GetPrevious::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObjectListNode * res =   this->_objectptr->GetObj()->GetPrevious();
  BasicVariable::ptr res_var = AMILabType<wxObjectListNode >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObject * wxObjectListNode::GetData()
//---------------------------------------------------
void WrapClass_wxObjectListNode::
    wrap_GetData::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectListNode::
    wrap_GetData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObject * res =   this->_objectptr->GetObj()->GetData();
  BasicVariable::ptr res_var = AMILabType<wxObject >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxObjectListNode::SetData(wxObject * data)
//---------------------------------------------------
void WrapClass_wxObjectListNode::
    wrap_SetData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObjectListNode::
    wrap_SetData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxObject* data;
  if (CheckNullVar(_p,_n))  {
    data=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > data_smtptr;
    if (!get_val_smtptr_param<wxObject >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->SetData(data);
  return BasicVariable::ptr();
}

