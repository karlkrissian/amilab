/**
 * C++ Interface: wrap_wxHtmlLinkInfo
 *
 * Description: wrapping wxHtmlLinkInfo
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

#include "wrap_wxHtmlLinkInfo.h"

// get all the required includes
// #include "..."
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxHtmlLinkInfo_declared
  #define wxHtmlLinkInfo_declared
  AMI_DECLARE_TYPE(wxHtmlLinkInfo)
#endif
#ifndef wxMouseEvent_declared
  #define wxMouseEvent_declared
  AMI_DECLARE_TYPE(wxMouseEvent)
#endif
#ifndef wxHtmlCell_declared
  #define wxHtmlCell_declared
  AMI_DECLARE_TYPE(wxHtmlCell)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlLinkInfo>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlLinkInfo::wrap_wxHtmlLinkInfo construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxHtmlLinkInfo);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlLinkInfo);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlLinkInfo
//
Variable<AMIObject>::ptr WrapClass_wxHtmlLinkInfo::CreateVar( wxHtmlLinkInfo* sp)
{
  boost::shared_ptr<wxHtmlLinkInfo> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlLinkInfo>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlLinkInfo>::CreateVar(
      new WrapClass_wxHtmlLinkInfo(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlLinkInfo::AddMethods(WrapClass<wxHtmlLinkInfo>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_SetEvent( this_ptr);
  AddVar_SetHtmlCell( this_ptr);
  AddVar_GetHref( this_ptr);
  AddVar_GetTarget( this_ptr);
  AddVar_GetEvent( this_ptr);
  AddVar_GetHtmlCell( this_ptr);

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
void WrapClasswxHtmlLinkInfo_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlLinkInfo");
    WrapClass_wxHtmlLinkInfo::AddVar_wxHtmlLinkInfo_1(amiobject->GetContext());
  WrapClass_wxHtmlLinkInfo::AddVar_wxHtmlLinkInfo(amiobject->GetContext());
  WrapClass_wxHtmlLinkInfo::AddVar_wxHtmlLinkInfo_2(amiobject->GetContext());
  WrapClass_wxHtmlLinkInfo::AddVar_wxHtmlLinkInfo_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlLinkInfo::wxHtmlLinkInfo()
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_wxHtmlLinkInfo_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_wxHtmlLinkInfo_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxHtmlLinkInfo* _newobj = new wxHtmlLinkInfo();
  BasicVariable::ptr res = WrapClass_wxHtmlLinkInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxHtmlLinkInfo::wxHtmlLinkInfo(...)
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_wxHtmlLinkInfo::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_wxHtmlLinkInfo::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHtmlLinkInfo::wrap_wxHtmlLinkInfo_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHtmlLinkInfo::wrap_wxHtmlLinkInfo_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxHtmlLinkInfo::wrap_wxHtmlLinkInfo_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxHtmlLinkInfo::wxHtmlLinkInfo(wxString const & href, wxString const & target = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_wxHtmlLinkInfo_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'href'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'target' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_wxHtmlLinkInfo_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > href_smtptr;
  if (!get_val_smtptr_param<wxString >(href_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & href = *href_smtptr;

  boost::shared_ptr<wxString > target_smtptr;
  if (!get_val_smtptr_param<wxString >(target_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & target = ( target_smtptr.get() ? (*target_smtptr) : wxString(wxEmptyString) );

  wxHtmlLinkInfo* _newobj = new wxHtmlLinkInfo(href, target);
  BasicVariable::ptr res = WrapClass_wxHtmlLinkInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxHtmlLinkInfo::wxHtmlLinkInfo(wxHtmlLinkInfo const & l)
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_wxHtmlLinkInfo_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlLinkInfo, "parameter named 'l'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_wxHtmlLinkInfo_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxHtmlLinkInfo > l_smtptr;
  if (!get_val_smtptr_param<wxHtmlLinkInfo >(l_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxHtmlLinkInfo const & l = *l_smtptr;

  wxHtmlLinkInfo* _newobj = new wxHtmlLinkInfo(l);
  BasicVariable::ptr res = WrapClass_wxHtmlLinkInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxHtmlLinkInfo.
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxHtmlLinkInfo object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxHtmlLinkInfo >::CreateVar( new wxHtmlLinkInfo(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxHtmlLinkInfo::SetEvent(wxMouseEvent const * e)
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_SetEvent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'e'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_SetEvent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxMouseEvent* e;
  if (CheckNullVar(_p,_n))  {
    e=(wxMouseEvent*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMouseEvent > e_smtptr;
    if (!get_val_smtptr_param<wxMouseEvent >(e_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    e = e_smtptr.get();
  }

  this->_objectptr->GetObj()->SetEvent(e);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlLinkInfo::SetHtmlCell(wxHtmlCell const * e)
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_SetHtmlCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'e'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_SetHtmlCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlCell* e;
  if (CheckNullVar(_p,_n))  {
    e=(wxHtmlCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlCell > e_smtptr;
    if (!get_val_smtptr_param<wxHtmlCell >(e_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    e = e_smtptr.get();
  }

  this->_objectptr->GetObj()->SetHtmlCell(e);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlLinkInfo::GetHref()
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_GetHref::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_GetHref::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetHref();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlLinkInfo::GetTarget()
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_GetTarget::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_GetTarget::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetTarget();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMouseEvent const * wxHtmlLinkInfo::GetEvent()
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_GetEvent::SetParametersComments()
{
  return_comments="returning a variable of type wxMouseEvent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_GetEvent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMouseEvent const * res =   this->_objectptr->GetObj()->GetEvent();
  BasicVariable::ptr res_var = AMILabType<wxMouseEvent >::CreateVar(const_cast<wxMouseEvent *>(res),true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell const * wxHtmlLinkInfo::GetHtmlCell()
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap_GetHtmlCell::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap_GetHtmlCell::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell const * res =   this->_objectptr->GetObj()->GetHtmlCell();
  BasicVariable::ptr res_var = AMILabType<wxHtmlCell >::CreateVar(const_cast<wxHtmlCell *>(res),true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlLinkInfo & wxHtmlLinkInfo::operator =(wxHtmlLinkInfo const & l)
//---------------------------------------------------
void WrapClass_wxHtmlLinkInfo::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlLinkInfo, "parameter named 'l'")
  return_comments="returning a variable of type wxHtmlLinkInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlLinkInfo::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlLinkInfo > l_smtptr;
  if (!get_val_smtptr_param<wxHtmlLinkInfo >(l_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlLinkInfo const & l = *l_smtptr;

  wxHtmlLinkInfo & res =   (*this->_objectptr->GetObj()) = (l);
  return AMILabType<wxHtmlLinkInfo >::CreateVar(res);
}

