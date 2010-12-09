/**
 * C++ Interface: wrap_wxHtmlTag
 *
 * Description: wrapping wxHtmlTag
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
#include "wrap_wxClassInfo.h"
#include "wrap_wxHtmlTag.h"
#include "wrap_wxString.h"
#include "wrap_wxColour.h"
#include "stdlib.h"


#include "wrap_wxHtmlTag.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlTag>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxHtmlTag);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlTag);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxHtmlTag>::CreateVar( wxHtmlTag* val, bool nodeleter)
{ 
  boost::shared_ptr<wxHtmlTag> obj_ptr(val,smartpointer_nodeleter<wxHtmlTag>());
  return AMILabType<wxHtmlTag>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlTag
//
Variable<AMIObject>::ptr WrapClass_wxHtmlTag::CreateVar( wxHtmlTag* sp)
{
  boost::shared_ptr<wxHtmlTag> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlTag>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlTag>::CreateVar(
      new WrapClass_wxHtmlTag(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlTag::AddMethods(WrapClass<wxHtmlTag>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);
  AddVar_GetParent( this_ptr);
  AddVar_GetFirstSibling( this_ptr);
  AddVar_GetLastSibling( this_ptr);
  AddVar_GetChildren( this_ptr);
  AddVar_GetPreviousSibling( this_ptr);
  AddVar_GetNextSibling( this_ptr);
  AddVar_GetNextTag( this_ptr);
  AddVar_GetName( this_ptr);
  AddVar_HasParam( this_ptr);
  AddVar_GetParam( this_ptr);
  AddVar_GetParamAsColour( this_ptr);
  AddVar_GetParamAsInt( this_ptr);
/* The following types are missing: void
  AddVar_ScanParam( this_ptr);
*/
  AddVar_GetAllParams( this_ptr);
  AddVar_HasEnding( this_ptr);
  AddVar_GetBeginPos( this_ptr);
  AddVar_GetEndPos1( this_ptr);
  AddVar_GetEndPos2( this_ptr);



  

  


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
void WrapClass_wxHtmlTag::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlTag");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlTag::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlTag * wxHtmlTag::GetParent()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetParent::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlTag";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetParent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlTag * res =   this->_objectptr->GetObj()->GetParent();
  BasicVariable::ptr res_var = WrapClass_wxHtmlTag::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlTag * wxHtmlTag::GetFirstSibling()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetFirstSibling::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlTag";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetFirstSibling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlTag * res =   this->_objectptr->GetObj()->GetFirstSibling();
  BasicVariable::ptr res_var = WrapClass_wxHtmlTag::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlTag * wxHtmlTag::GetLastSibling()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetLastSibling::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlTag";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetLastSibling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlTag * res =   this->_objectptr->GetObj()->GetLastSibling();
  BasicVariable::ptr res_var = WrapClass_wxHtmlTag::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlTag * wxHtmlTag::GetChildren()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetChildren::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlTag";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetChildren::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlTag * res =   this->_objectptr->GetObj()->GetChildren();
  BasicVariable::ptr res_var = WrapClass_wxHtmlTag::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlTag * wxHtmlTag::GetPreviousSibling()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetPreviousSibling::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlTag";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetPreviousSibling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlTag * res =   this->_objectptr->GetObj()->GetPreviousSibling();
  BasicVariable::ptr res_var = WrapClass_wxHtmlTag::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlTag * wxHtmlTag::GetNextSibling()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetNextSibling::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlTag";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetNextSibling::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlTag * res =   this->_objectptr->GetObj()->GetNextSibling();
  BasicVariable::ptr res_var = WrapClass_wxHtmlTag::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlTag * wxHtmlTag::GetNextTag()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetNextTag::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlTag";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetNextTag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlTag * res =   this->_objectptr->GetObj()->GetNextTag();
  BasicVariable::ptr res_var = WrapClass_wxHtmlTag::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlTag::GetName()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlTag::HasParam(wxString const & par)
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_HasParam::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'par'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_HasParam::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > par_smtptr;
  if (!get_val_smtptr_param<wxString >(par_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & par = *par_smtptr;

  bool res =   this->_objectptr->GetObj()->HasParam(par);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlTag::GetParam(wxString const & par, bool with_commas = false)
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetParam::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'par'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'with_commas' (def:false)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetParam::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > par_smtptr;
  if (!get_val_smtptr_param<wxString >(par_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & par = *par_smtptr;

  bool with_commas = false;
  if (!get_val_param<bool >(with_commas,_p,_n,false,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetParam(par, with_commas);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlTag::GetParamAsColour(wxString const & par, wxColour * clr)
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetParamAsColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'par'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'clr'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetParamAsColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > par_smtptr;
  if (!get_val_smtptr_param<wxString >(par_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & par = *par_smtptr;

  boost::shared_ptr<wxColour > clr_smtptr;
  if (!get_val_smtptr_param<wxColour >(clr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour* clr = clr_smtptr.get();

  bool res =   this->_objectptr->GetObj()->GetParamAsColour(par, clr);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlTag::GetParamAsInt(wxString const & par, int * clr)
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetParamAsInt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'par'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'clr'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetParamAsInt::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > par_smtptr;
  if (!get_val_smtptr_param<wxString >(par_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & par = *par_smtptr;

  boost::shared_ptr<int > clr_smtptr;
  if (!get_val_smtptr_param<int >(clr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* clr = clr_smtptr.get();

  bool res =   this->_objectptr->GetObj()->GetParamAsInt(par, clr);
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of int wxHtmlTag::ScanParam(wxString const & par, wxChar const * format, void * param)
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_ScanParam::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'par'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'format'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'param'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_ScanParam::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > par_smtptr;
  if (!get_val_smtptr_param<wxString >(par_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & par = *par_smtptr;

  boost::shared_ptr<std::string > format_string;
  if (!get_val_smtptr_param<std::string >(format_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t format[format_string->size()+1];
mbstowcs(format,format_string->c_str(),format_string->size()+1);

  boost::shared_ptr<void > param_smtptr;
  if (!get_val_smtptr_param<void >(param_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  void* param = param_smtptr.get();

  int res =   this->_objectptr->GetObj()->ScanParam(par, format, param);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxHtmlTag::GetAllParams()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetAllParams::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetAllParams::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetAllParams();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlTag::HasEnding()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_HasEnding::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_HasEnding::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasEnding();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlTag::GetBeginPos()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetBeginPos::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetBeginPos::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBeginPos();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlTag::GetEndPos1()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetEndPos1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetEndPos1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetEndPos1();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlTag::GetEndPos2()
//---------------------------------------------------
void WrapClass_wxHtmlTag::
    wrap_GetEndPos2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTag::
    wrap_GetEndPos2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetEndPos2();
  return AMILabType<int >::CreateVar(res);
}

