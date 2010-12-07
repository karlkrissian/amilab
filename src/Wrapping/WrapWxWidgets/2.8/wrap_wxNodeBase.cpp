/**
 * C++ Interface: wrap_wxNodeBase
 *
 * Description: wrapping wxNodeBase
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
#include "wrap_wxNodeBase.h"
#include "wrap_wxListKey.h"
#include "stdlib.h"
#include "wchar.h"


#include "wrap_wxNodeBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxNodeBase>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxNodeBase);
AMI_DEFINE_VARFROMSMTPTR(wxNodeBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxNodeBase>::CreateVar( wxNodeBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxNodeBase> obj_ptr(val,smartpointer_nodeleter<wxNodeBase>());
  return AMILabType<wxNodeBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxNodeBase
//
Variable<AMIObject>::ptr WrapClass_wxNodeBase::CreateVar( wxNodeBase* sp)
{
  boost::shared_ptr<wxNodeBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxNodeBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxNodeBase>::CreateVar(
      new WrapClass_wxNodeBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxNodeBase::AddMethods(WrapClass<wxNodeBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_GetKeyString( this_ptr);
      AddVar_GetKeyInteger( this_ptr);
      AddVar_SetKeyString( this_ptr);
      AddVar_SetKeyInteger( this_ptr);
      AddVar_GetDataPtr( this_ptr);



  

  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxNodeBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxNodeBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------

/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of Constructor wxNodeBase::wxNodeBase(wxListBase * list = 0u, wxNodeBase * previous = 0u, wxNodeBase * next = 0u, void * data = 0l, wxListKey const & key = wxDefaultListKey)
//---------------------------------------------------
void WrapClass_wxNodeBase::
    wrap_wxNodeBase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListBase, "parameter named 'list' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxNodeBase, "parameter named 'previous' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxNodeBase, "parameter named 'next' (def:0u)")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'data' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'key' (def:wxDefaultListKey)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNodeBase::
    wrap_wxNodeBase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxListBase > list_smtptr;
  if (!get_val_smtptr_param<wxListBase >(list_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxListBase* list = list_smtptr.get();

  boost::shared_ptr<wxNodeBase > previous_smtptr;
  if (!get_val_smtptr_param<wxNodeBase >(previous_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  wxNodeBase* previous = previous_smtptr.get();

  boost::shared_ptr<wxNodeBase > next_smtptr;
  if (!get_val_smtptr_param<wxNodeBase >(next_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  wxNodeBase* next = next_smtptr.get();

  boost::shared_ptr<void > data_smtptr;
  if (!get_val_smtptr_param<void >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  void* data = data_smtptr.get();

  boost::shared_ptr<wxListKey > key_smtptr;
  if (!get_val_smtptr_param<wxListKey >(key_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxListKey const & key = ( key_smtptr.get() ? (*key_smtptr) : wxDefaultListKey );

  wxNodeBase* _newobj = new wxNodeBase(list, previous, next, data, key);
  BasicVariable::ptr res = WrapClass_wxNodeBase::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of wxChar const * wxNodeBase::GetKeyString()
//---------------------------------------------------
void WrapClass_wxNodeBase::
    wrap_GetKeyString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNodeBase::
    wrap_GetKeyString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar const * res =   this->_objectptr->GetObj()->GetKeyString();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of long int wxNodeBase::GetKeyInteger()
//---------------------------------------------------
void WrapClass_wxNodeBase::
    wrap_GetKeyInteger::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNodeBase::
    wrap_GetKeyInteger::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetKeyInteger();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxNodeBase::SetKeyString(wxChar * s)
//---------------------------------------------------
void WrapClass_wxNodeBase::
    wrap_SetKeyString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNodeBase::
    wrap_SetKeyString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > s_string;
  if (!get_val_smtptr_param<std::string >(s_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t s[s_string->size()+1];
mbstowcs(s,s_string->c_str(),s_string->size()+1);

  this->_objectptr->GetObj()->SetKeyString(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxNodeBase::SetKeyInteger(long int i)
//---------------------------------------------------
void WrapClass_wxNodeBase::
    wrap_SetKeyInteger::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNodeBase::
    wrap_SetKeyInteger::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int i = i_long;

  this->_objectptr->GetObj()->SetKeyInteger(i);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void * * wxNodeBase::GetDataPtr()
//---------------------------------------------------
void WrapClass_wxNodeBase::
    wrap_GetDataPtr::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxNodeBase::
    wrap_GetDataPtr::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GetDataPtr();
  return BasicVariable::ptr();
}

