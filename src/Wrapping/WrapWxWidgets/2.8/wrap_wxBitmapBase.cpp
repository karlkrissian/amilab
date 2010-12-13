/**
 * C++ Interface: wrap_wxBitmapBase
 *
 * Description: wrapping wxBitmapBase
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

#include "wrap_wxBitmapBase.h"

// get all the required includes
// #include "..."
#ifndef wxList_declared
  #define wxList_declared
  AMI_DECLARE_TYPE(wxList)
#endif
#ifndef wxBitmapHandlerBase_declared
  #define wxBitmapHandlerBase_declared
  AMI_DECLARE_TYPE(wxBitmapHandlerBase)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxBitmapHandler_declared
  #define wxBitmapHandler_declared
  AMI_DECLARE_TYPE(wxBitmapHandler)
#endif
#ifndef wxColour_declared
  #define wxColour_declared
  AMI_DECLARE_TYPE(wxColour)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif
#ifndef wxBitmapBase_declared
  #define wxBitmapBase_declared
  AMI_DECLARE_TYPE(wxBitmapBase)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBitmapBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxBitmapBase);
AMI_DEFINE_VARFROMSMTPTR(wxBitmapBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBitmapBase
//
Variable<AMIObject>::ptr WrapClass_wxBitmapBase::CreateVar( wxBitmapBase* sp)
{
  boost::shared_ptr<wxBitmapBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxBitmapBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBitmapBase>::CreateVar(
      new WrapClass_wxBitmapBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBitmapBase::AddMethods(WrapClass<wxBitmapBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Ok( this_ptr);
  AddVar_QuantizeColour( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxGDIObject
  boost::shared_ptr<wxGDIObject > parent_wxGDIObject(  boost::dynamic_pointer_cast<wxGDIObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxGDIObject = AMILabType<wxGDIObject >::CreateVarFromSmtPtr(parent_wxGDIObject);
  context->AddVar("wxGDIObject",var_wxGDIObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxGDIObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxGDIObject);
  context->AddDefault(obj_wxGDIObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxBitmapBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxBitmapBase");
  
  // Static methods 
  WrapClass_wxBitmapBase::AddVar_GetHandlers(amiobject->GetContext());
  WrapClass_wxBitmapBase::AddVar_AddHandler(amiobject->GetContext());
  WrapClass_wxBitmapBase::AddVar_InsertHandler(amiobject->GetContext());
  WrapClass_wxBitmapBase::AddVar_RemoveHandler(amiobject->GetContext());
  WrapClass_wxBitmapBase::AddVar_FindHandler_1(amiobject->GetContext());
  WrapClass_wxBitmapBase::AddVar_FindHandler(amiobject->GetContext());
  WrapClass_wxBitmapBase::AddVar_FindHandler_2(amiobject->GetContext());
  WrapClass_wxBitmapBase::AddVar_FindHandler_3(amiobject->GetContext());
  WrapClass_wxBitmapBase::AddVar_CleanUpHandlers(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxList & wxBitmapBase::GetHandlers()
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_static_GetHandlers::SetParametersComments()
{
  return_comments="returning a variable of type wxList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_static_GetHandlers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxList & res =   wxBitmapBase::GetHandlers();
  return AMILabType<wxList >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxBitmapBase::AddHandler(wxBitmapHandlerBase * handler)
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_static_AddHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmapHandlerBase, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_static_AddHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxBitmapHandlerBase* handler;
  if (CheckNullVar(_p,_n))  {
    handler=(wxBitmapHandlerBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxBitmapHandlerBase > handler_smtptr;
    if (!get_val_smtptr_param<wxBitmapHandlerBase >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    handler = handler_smtptr.get();
  }

  wxBitmapBase::AddHandler(handler);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapBase::InsertHandler(wxBitmapHandlerBase * handler)
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_static_InsertHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmapHandlerBase, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_static_InsertHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxBitmapHandlerBase* handler;
  if (CheckNullVar(_p,_n))  {
    handler=(wxBitmapHandlerBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxBitmapHandlerBase > handler_smtptr;
    if (!get_val_smtptr_param<wxBitmapHandlerBase >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    handler = handler_smtptr.get();
  }

  wxBitmapBase::InsertHandler(handler);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxBitmapBase::RemoveHandler(wxString const & name)
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_static_RemoveHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_static_RemoveHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  bool res =   wxBitmapBase::RemoveHandler(name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmapHandler * wxBitmapBase::FindHandler(wxString const & name)
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_static_FindHandler_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxBitmapHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_static_FindHandler_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  wxBitmapHandler * res =   wxBitmapBase::FindHandler(name);
  BasicVariable::ptr res_var = AMILabType<wxBitmapHandler >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static wxBitmapBase::FindHandler(...)
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_static_FindHandler::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_static_FindHandler::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapBase::wrap_static_FindHandler_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapBase::wrap_static_FindHandler_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxBitmapBase::wrap_static_FindHandler_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxBitmapHandler * wxBitmapBase::FindHandler(wxString const & extension, wxBitmapType bitmapType)
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_static_FindHandler_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'extension'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bitmapType'")
  return_comments="returning a variable of type wxBitmapHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_static_FindHandler_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > extension_smtptr;
  if (!get_val_smtptr_param<wxString >(extension_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & extension = *extension_smtptr;

  int bitmapType_int;
  if (!get_val_param<int >(bitmapType_int,_p,_n,true,true)) ClassReturnEmptyVar;
  wxBitmapType bitmapType = (wxBitmapType) bitmapType_int;

  wxBitmapHandler * res =   wxBitmapBase::FindHandler(extension, bitmapType);
  BasicVariable::ptr res_var = AMILabType<wxBitmapHandler >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxBitmapHandler * wxBitmapBase::FindHandler(wxBitmapType bitmapType)
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_static_FindHandler_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bitmapType'")
  return_comments="returning a variable of type wxBitmapHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_static_FindHandler_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int bitmapType_int;
  if (!get_val_param<int >(bitmapType_int,_p,_n,true,true)) ClassReturnEmptyVar;
  wxBitmapType bitmapType = (wxBitmapType) bitmapType_int;

  wxBitmapHandler * res =   wxBitmapBase::FindHandler(bitmapType);
  BasicVariable::ptr res_var = AMILabType<wxBitmapHandler >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxBitmapBase::CleanUpHandlers()
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_static_CleanUpHandlers::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_static_CleanUpHandlers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmapBase::CleanUpHandlers();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxBitmapBase::Ok()
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxColour wxBitmapBase::QuantizeColour(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_QuantizeColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_QuantizeColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & colour = *colour_smtptr;

  wxColour res =   this->_objectptr->GetObj()->QuantizeColour(colour);
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxBitmapBase::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxBitmapBase & wxBitmapBase::operator =(wxBitmapBase const & param0)
//---------------------------------------------------
void WrapClass_wxBitmapBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmapBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxBitmapBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmapBase > param0_smtptr;
  if (!get_val_smtptr_param<wxBitmapBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmapBase const & param0 = *param0_smtptr;

  wxBitmapBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxBitmapBase >::CreateVar(res);
}

