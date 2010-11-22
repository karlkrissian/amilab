/**
 * C++ Interface: wrap_wxListBase
 *
 * Description: wrapping wxListBase
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
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxObjectListNode.h"
#include "wrap_wxListBase.h"


#include "wrap_wxListBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxListBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxListBase);
AMI_DEFINE_VARFROMSMTPTR(wxListBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxListBase
//
Variable<AMIObject>::ptr WrapClass_wxListBase::CreateVar( wxListBase* sp)
{
  boost::shared_ptr<wxListBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxListBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxListBase>::CreateVar(
      new WrapClass_wxListBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxListBase::AddMethods(WrapClass<wxListBase>::ptr this_ptr )
{
  
      // Add members from wxObject
      WrapClass_wxObject::ptr parent_wxObject(        boost::dynamic_pointer_cast<WrapClass_wxObject >(this_ptr));
      parent_wxObject->AddMethods(parent_wxObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_GetCount( this_ptr);
      AddVar_IsEmpty( this_ptr);
      AddVar_Clear( this_ptr);
      AddVar_DeleteContents( this_ptr);
      AddVar_GetDeleteContents( this_ptr);
      AddVar_GetKeyType( this_ptr);
      AddVar_SetKeyType( this_ptr);
      AddVar_Number( this_ptr);
      AddVar_First( this_ptr);
      AddVar_Last( this_ptr);
      AddVar_Nth( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of size_t wxListBase::GetCount()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_GetCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_GetCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxListBase::IsEmpty()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxListBase::Clear()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxListBase::DeleteContents(bool destroy)
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_DeleteContents::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'destroy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_DeleteContents::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int destroy_int;
  if (!get_val_param<int >(destroy_int,_p,_n)) ClassHelpAndReturn;
  bool destroy = (bool) (destroy_int>0.5);

  this->_objectptr->GetObj()->DeleteContents(destroy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxListBase::GetDeleteContents()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_GetDeleteContents::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_GetDeleteContents::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetDeleteContents();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxKeyType wxListBase::GetKeyType()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_GetKeyType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_GetKeyType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxKeyType res =   this->_objectptr->GetObj()->GetKeyType();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxListBase::SetKeyType(wxKeyType keyType)
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_SetKeyType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'keyType'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_SetKeyType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int keyType_int;
  if (!get_val_param<int >(keyType_int,_p,_n)) ClassHelpAndReturn;
  wxKeyType keyType = (wxKeyType) keyType_int;

  this->_objectptr->GetObj()->SetKeyType(keyType);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxListBase::Number()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_Number::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_Number::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->Number();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxNode * wxListBase::First()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_First::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_First::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxNode * res =   this->_objectptr->GetObj()->First();
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxNode * wxListBase::Last()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_Last::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_Last::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxNode * res =   this->_objectptr->GetObj()->Last();
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxNode * wxListBase::Nth(size_t n)
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_Nth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_Nth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxNode * res =   this->_objectptr->GetObj()->Nth(n);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxListBase & wxListBase::operator =(wxListBase const & param0)
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxListBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxListBase > param0_smtptr;
  if (!get_val_smtptr_param<wxListBase >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxListBase const & param0 = *param0_smtptr;

  wxListBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxListBase >::CreateVar(res);
}

