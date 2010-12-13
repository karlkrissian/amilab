/**
 * C++ Interface: wrap_wxHtmlRenderingInfo
 *
 * Description: wrapping wxHtmlRenderingInfo
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

#include "wrap_wxHtmlRenderingInfo.h"

// get all the required includes
// #include "..."
#ifndef wxHtmlRenderingInfo_declared
  #define wxHtmlRenderingInfo_declared
  AMI_DECLARE_TYPE(wxHtmlRenderingInfo)
#endif
#ifndef wxHtmlSelection_declared
  #define wxHtmlSelection_declared
  AMI_DECLARE_TYPE(wxHtmlSelection)
#endif
#ifndef wxHtmlRenderingStyle_declared
  #define wxHtmlRenderingStyle_declared
  AMI_DECLARE_TYPE(wxHtmlRenderingStyle)
#endif
#ifndef wxHtmlRenderingState_declared
  #define wxHtmlRenderingState_declared
  AMI_DECLARE_TYPE(wxHtmlRenderingState)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlRenderingInfo>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlRenderingInfo::wrap_wxHtmlRenderingInfo construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxHtmlRenderingInfo);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlRenderingInfo);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlRenderingInfo
//
Variable<AMIObject>::ptr WrapClass_wxHtmlRenderingInfo::CreateVar( wxHtmlRenderingInfo* sp)
{
  boost::shared_ptr<wxHtmlRenderingInfo> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlRenderingInfo>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlRenderingInfo>::CreateVar(
      new WrapClass_wxHtmlRenderingInfo(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::AddMethods(WrapClass<wxHtmlRenderingInfo>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_SetSelection( this_ptr);
  AddVar_GetSelection( this_ptr);
  AddVar_SetStyle( this_ptr);
  AddVar_GetStyle( this_ptr);
  AddVar_GetState( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlRenderingInfo_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlRenderingInfo");
    WrapClass_wxHtmlRenderingInfo::AddVar_wxHtmlRenderingInfo_1(amiobject->GetContext());
  WrapClass_wxHtmlRenderingInfo::AddVar_wxHtmlRenderingInfo(amiobject->GetContext());
  WrapClass_wxHtmlRenderingInfo::AddVar_wxHtmlRenderingInfo_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlRenderingInfo::wxHtmlRenderingInfo(wxHtmlRenderingInfo const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap_wxHtmlRenderingInfo_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingInfo, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap_wxHtmlRenderingInfo_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxHtmlRenderingInfo > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlRenderingInfo >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxHtmlRenderingInfo const & param0 = *param0_smtptr;

  wxHtmlRenderingInfo* _newobj = new wxHtmlRenderingInfo(param0);
  BasicVariable::ptr res = WrapClass_wxHtmlRenderingInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxHtmlRenderingInfo::wxHtmlRenderingInfo(...)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap_wxHtmlRenderingInfo::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap_wxHtmlRenderingInfo::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHtmlRenderingInfo::wrap_wxHtmlRenderingInfo_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHtmlRenderingInfo::wrap_wxHtmlRenderingInfo_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxHtmlRenderingInfo::wxHtmlRenderingInfo()
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap_wxHtmlRenderingInfo_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap_wxHtmlRenderingInfo_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxHtmlRenderingInfo* _newobj = new wxHtmlRenderingInfo();
  BasicVariable::ptr res = WrapClass_wxHtmlRenderingInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxHtmlRenderingInfo.
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxHtmlRenderingInfo object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxHtmlRenderingInfo >::CreateVar( new wxHtmlRenderingInfo(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxHtmlRenderingInfo::SetSelection(wxHtmlSelection * s)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap_SetSelection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlSelection, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap_SetSelection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlSelection* s;
  if (CheckNullVar(_p,_n))  {
    s=(wxHtmlSelection*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlSelection > s_smtptr;
    if (!get_val_smtptr_param<wxHtmlSelection >(s_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    s = s_smtptr.get();
  }

  this->_objectptr->GetObj()->SetSelection(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlSelection * wxHtmlRenderingInfo::GetSelection()
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap_GetSelection::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlSelection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap_GetSelection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlSelection * res =   this->_objectptr->GetObj()->GetSelection();
  BasicVariable::ptr res_var = AMILabType<wxHtmlSelection >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlRenderingInfo::SetStyle(wxHtmlRenderingStyle * style)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap_SetStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingStyle, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap_SetStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlRenderingStyle* style;
  if (CheckNullVar(_p,_n))  {
    style=(wxHtmlRenderingStyle*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlRenderingStyle > style_smtptr;
    if (!get_val_smtptr_param<wxHtmlRenderingStyle >(style_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    style = style_smtptr.get();
  }

  this->_objectptr->GetObj()->SetStyle(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlRenderingStyle & wxHtmlRenderingInfo::GetStyle()
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap_GetStyle::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlRenderingStyle";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap_GetStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlRenderingStyle & res =   this->_objectptr->GetObj()->GetStyle();
  return AMILabType<wxHtmlRenderingStyle >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlRenderingState & wxHtmlRenderingInfo::GetState()
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap_GetState::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlRenderingState";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap_GetState::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlRenderingState & res =   this->_objectptr->GetObj()->GetState();
  return AMILabType<wxHtmlRenderingState >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlRenderingInfo & wxHtmlRenderingInfo::operator =(wxHtmlRenderingInfo const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingInfo::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingInfo, "parameter named 'param0'")
  return_comments="returning a variable of type wxHtmlRenderingInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingInfo::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlRenderingInfo > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlRenderingInfo >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlRenderingInfo const & param0 = *param0_smtptr;

  wxHtmlRenderingInfo & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxHtmlRenderingInfo >::CreateVar(res);
}

