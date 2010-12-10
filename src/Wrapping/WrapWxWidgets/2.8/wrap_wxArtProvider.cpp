/**
 * C++ Interface: wrap_wxArtProvider
 *
 * Description: wrapping wxArtProvider
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
#include "wrap_wxArtProvider.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxString.h"
#include "wrap_wxSize.h"
#include "wrap_wxIcon.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxArtProvider.h"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxArtProvider>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxArtProvider);
AMI_DEFINE_VARFROMSMTPTR(wxArtProvider);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxArtProvider
//
Variable<AMIObject>::ptr WrapClass_wxArtProvider::CreateVar( wxArtProvider* sp)
{
  boost::shared_ptr<wxArtProvider> di_ptr(
    sp,
    wxwindow_nodeleter<wxArtProvider>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxArtProvider>::CreateVar(
      new WrapClass_wxArtProvider(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxArtProvider::AddMethods(WrapClass<wxArtProvider>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxObject
  boost::shared_ptr<wxObject > parent_wxObject(  boost::dynamic_pointer_cast<wxObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxObject = AMILabType<wxObject >::CreateVarFromSmtPtr(parent_wxObject);
  context->AddVar("wxObject",var_wxObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxObject);
  context->AddDefault(obj_wxObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxArtProvider::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxArtProvider");
  
  // Static methods 
  WrapClass_wxArtProvider::AddVar_Push(amiobject->GetContext());
  WrapClass_wxArtProvider::AddVar_PushBack(amiobject->GetContext());
  WrapClass_wxArtProvider::AddVar_Insert(amiobject->GetContext());
  WrapClass_wxArtProvider::AddVar_Pop(amiobject->GetContext());
  WrapClass_wxArtProvider::AddVar_Remove(amiobject->GetContext());
  WrapClass_wxArtProvider::AddVar_Delete(amiobject->GetContext());
  WrapClass_wxArtProvider::AddVar_GetBitmap(amiobject->GetContext());
  WrapClass_wxArtProvider::AddVar_GetIcon(amiobject->GetContext());
  WrapClass_wxArtProvider::AddVar_GetSizeHint(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxArtProvider::Push(wxArtProvider * provider)
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_static_Push::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxArtProvider, "parameter named 'provider'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_static_Push::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxArtProvider* provider;
  if (CheckNullVar(_p,_n))  {
    provider=(wxArtProvider*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxArtProvider > provider_smtptr;
    if (!get_val_smtptr_param<wxArtProvider >(provider_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    provider = provider_smtptr.get();
  }

  wxArtProvider::Push(provider);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxArtProvider::PushBack(wxArtProvider * provider)
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_static_PushBack::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxArtProvider, "parameter named 'provider'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_static_PushBack::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxArtProvider* provider;
  if (CheckNullVar(_p,_n))  {
    provider=(wxArtProvider*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxArtProvider > provider_smtptr;
    if (!get_val_smtptr_param<wxArtProvider >(provider_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    provider = provider_smtptr.get();
  }

  wxArtProvider::PushBack(provider);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxArtProvider::Insert(wxArtProvider * provider)
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_static_Insert::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxArtProvider, "parameter named 'provider'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_static_Insert::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxArtProvider* provider;
  if (CheckNullVar(_p,_n))  {
    provider=(wxArtProvider*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxArtProvider > provider_smtptr;
    if (!get_val_smtptr_param<wxArtProvider >(provider_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    provider = provider_smtptr.get();
  }

  wxArtProvider::Insert(provider);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxArtProvider::Pop()
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_static_Pop::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_static_Pop::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   wxArtProvider::Pop();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxArtProvider::Remove(wxArtProvider * provider)
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_static_Remove::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxArtProvider, "parameter named 'provider'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_static_Remove::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxArtProvider* provider;
  if (CheckNullVar(_p,_n))  {
    provider=(wxArtProvider*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxArtProvider > provider_smtptr;
    if (!get_val_smtptr_param<wxArtProvider >(provider_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    provider = provider_smtptr.get();
  }

  bool res =   wxArtProvider::Remove(provider);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxArtProvider::Delete(wxArtProvider * provider)
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_static_Delete::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxArtProvider, "parameter named 'provider'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_static_Delete::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxArtProvider* provider;
  if (CheckNullVar(_p,_n))  {
    provider=(wxArtProvider*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxArtProvider > provider_smtptr;
    if (!get_val_smtptr_param<wxArtProvider >(provider_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    provider = provider_smtptr.get();
  }

  bool res =   wxArtProvider::Delete(provider);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxArtProvider::GetBitmap(wxArtID const & id, wxArtClient const & client = 'wxART_OTHER_C', wxSize const & size = wxDefaultSize)
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_static_GetBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'client' (def:'wxART_OTHER_C')")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_static_GetBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > id_smtptr;
  if (!get_val_smtptr_param<wxString >(id_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxArtID const & id = *id_smtptr;

  boost::shared_ptr<wxString > client_smtptr;
  if (!get_val_smtptr_param<wxString >(client_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxArtClient const & client = ( client_smtptr.get() ? (*client_smtptr) : wxString(L"wxART_OTHER_C") );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  wxBitmap res =   wxArtProvider::GetBitmap(id, client, size);
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxIcon wxArtProvider::GetIcon(wxArtID const & id, wxArtClient const & client = 'wxART_OTHER_C', wxSize const & size = wxDefaultSize)
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_static_GetIcon::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'client' (def:'wxART_OTHER_C')")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  return_comments="returning a variable of type wxIcon";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_static_GetIcon::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > id_smtptr;
  if (!get_val_smtptr_param<wxString >(id_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxArtID const & id = *id_smtptr;

  boost::shared_ptr<wxString > client_smtptr;
  if (!get_val_smtptr_param<wxString >(client_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxArtClient const & client = ( client_smtptr.get() ? (*client_smtptr) : wxString(L"wxART_OTHER_C") );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  wxIcon res =   wxArtProvider::GetIcon(id, client, size);
  return AMILabType<wxIcon >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxArtProvider::GetSizeHint(wxArtClient const & client, bool platform_dependent = false)
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_static_GetSizeHint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'client'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'platform_dependent' (def:false)")
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_static_GetSizeHint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > client_smtptr;
  if (!get_val_smtptr_param<wxString >(client_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxArtClient const & client = *client_smtptr;

  bool platform_dependent = false;
  if (!get_val_param<bool >(platform_dependent,_p,_n,false,false)) ClassHelpAndReturn;

  wxSize res =   wxArtProvider::GetSizeHint(client, platform_dependent);
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxArtProvider::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxArtProvider & wxArtProvider::operator =(wxArtProvider const & param0)
//---------------------------------------------------
void WrapClass_wxArtProvider::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxArtProvider, "parameter named 'param0'")
  return_comments="returning a variable of type wxArtProvider";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArtProvider::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxArtProvider > param0_smtptr;
  if (!get_val_smtptr_param<wxArtProvider >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxArtProvider const & param0 = *param0_smtptr;

  wxArtProvider & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxArtProvider >::CreateVar(res);
}

