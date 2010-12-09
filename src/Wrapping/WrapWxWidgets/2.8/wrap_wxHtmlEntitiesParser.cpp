/**
 * C++ Interface: wrap_wxHtmlEntitiesParser
 *
 * Description: wrapping wxHtmlEntitiesParser
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
#include "wrap_wxString.h"
#include "stdlib.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_wxHtmlEntitiesParser.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlEntitiesParser>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlEntitiesParser::wrap_wxHtmlEntitiesParser construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxHtmlEntitiesParser);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlEntitiesParser);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxHtmlEntitiesParser>::CreateVar( wxHtmlEntitiesParser* val, bool nodeleter)
{ 
  boost::shared_ptr<wxHtmlEntitiesParser> obj_ptr(val,smartpointer_nodeleter<wxHtmlEntitiesParser>());
  return AMILabType<wxHtmlEntitiesParser>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlEntitiesParser
//
Variable<AMIObject>::ptr WrapClass_wxHtmlEntitiesParser::CreateVar( wxHtmlEntitiesParser* sp)
{
  boost::shared_ptr<wxHtmlEntitiesParser> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlEntitiesParser>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlEntitiesParser>::CreateVar(
      new WrapClass_wxHtmlEntitiesParser(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlEntitiesParser::AddMethods(WrapClass<wxHtmlEntitiesParser>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);
  AddVar_SetEncoding( this_ptr);
  AddVar_Parse( this_ptr);
  AddVar_GetEntityChar( this_ptr);
  AddVar_GetCharForCode( this_ptr);



  

  


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
void WrapClass_wxHtmlEntitiesParser::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlEntitiesParser");
    WrapClass_wxHtmlEntitiesParser::AddVar_wxHtmlEntitiesParser(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlEntitiesParser::wxHtmlEntitiesParser()
//---------------------------------------------------
void WrapClass_wxHtmlEntitiesParser::
    wrap_wxHtmlEntitiesParser::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlEntitiesParser::
    wrap_wxHtmlEntitiesParser::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlEntitiesParser* _newobj = new wxHtmlEntitiesParser();
  BasicVariable::ptr res = WrapClass_wxHtmlEntitiesParser::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlEntitiesParser::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlEntitiesParser::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlEntitiesParser::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlEntitiesParser::SetEncoding(wxFontEncoding encoding)
//---------------------------------------------------
void WrapClass_wxHtmlEntitiesParser::
    wrap_SetEncoding::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'encoding'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlEntitiesParser::
    wrap_SetEncoding::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int encoding_int;
  if (!get_val_param<int >(encoding_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxFontEncoding encoding = (wxFontEncoding) encoding_int;

  this->_objectptr->GetObj()->SetEncoding(encoding);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlEntitiesParser::Parse(wxString const & input)
//---------------------------------------------------
void WrapClass_wxHtmlEntitiesParser::
    wrap_Parse::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'input'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlEntitiesParser::
    wrap_Parse::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > input_smtptr;
  if (!get_val_smtptr_param<wxString >(input_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & input = *input_smtptr;

  wxString res =   this->_objectptr->GetObj()->Parse(input);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxChar wxHtmlEntitiesParser::GetEntityChar(wxString const & entity)
//---------------------------------------------------
void WrapClass_wxHtmlEntitiesParser::
    wrap_GetEntityChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'entity'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlEntitiesParser::
    wrap_GetEntityChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > entity_smtptr;
  if (!get_val_smtptr_param<wxString >(entity_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & entity = *entity_smtptr;

  wxChar res =   this->_objectptr->GetObj()->GetEntityChar(entity);
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar wxHtmlEntitiesParser::GetCharForCode(unsigned int code)
//---------------------------------------------------
void WrapClass_wxHtmlEntitiesParser::
    wrap_GetCharForCode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'code'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlEntitiesParser::
    wrap_GetCharForCode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long code_long;
  if (!get_val_param<long >(code_long,_p,_n,true,false)) ClassHelpAndReturn;
  unsigned int code = boost::numeric_cast<unsigned int >(code_long);

  wxChar res =   this->_objectptr->GetObj()->GetCharForCode(code);
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

