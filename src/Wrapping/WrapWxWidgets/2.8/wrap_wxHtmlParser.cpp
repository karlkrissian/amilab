/**
 * C++ Interface: wrap_wxHtmlParser
 *
 * Description: wrapping wxHtmlParser
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
#include "wrap_wxString.h"
#include "wrap_wxClassInfo.h"
#include "wrap_wxFileSystem.h"
#include "wrap_wxFSFile.h"
#include "wrap_wxObject.h"
#include "wrap_wxHtmlTag.h"
#include "wrap_wxHtmlTagHandler.h"
#include "wrap_wxHtmlEntitiesParser.h"


#include "wrap_wxHtmlParser.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlParser>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxHtmlParser);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlParser);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxHtmlParser>::CreateVar( wxHtmlParser* val, bool nodeleter)
{ 
  boost::shared_ptr<wxHtmlParser> obj_ptr(val,smartpointer_nodeleter<wxHtmlParser>());
  return AMILabType<wxHtmlParser>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlParser
//
Variable<AMIObject>::ptr WrapClass_wxHtmlParser::CreateVar( wxHtmlParser* sp)
{
  boost::shared_ptr<wxHtmlParser> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlParser>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlParser>::CreateVar(
      new WrapClass_wxHtmlParser(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlParser::AddMethods(WrapClass<wxHtmlParser>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);
  AddVar_SetFS( this_ptr);
  AddVar_GetFS( this_ptr);
  AddVar_OpenURL( this_ptr);
  AddVar_Parse( this_ptr);
  AddVar_InitParser( this_ptr);
  AddVar_DoneParser( this_ptr);
  AddVar_StopParsing( this_ptr);
  AddVar_DoParsing_1( this_ptr);
  AddVar_DoParsing( this_ptr);
  AddVar_DoParsing_2( this_ptr);
  AddVar_GetCurrentTag( this_ptr);
  AddVar_AddTagHandler( this_ptr);
  AddVar_PushTagHandler( this_ptr);
  AddVar_PopTagHandler( this_ptr);
  AddVar_GetSource( this_ptr);
  AddVar_SetSource( this_ptr);
  AddVar_SetSourceAndSaveState( this_ptr);
  AddVar_RestoreState( this_ptr);
  AddVar_GetInnerSource( this_ptr);
  AddVar_GetEntitiesParser( this_ptr);



  

  


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
void WrapClass_wxHtmlParser::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlParser");
  
  // Static methods 
  WrapClass_wxHtmlParser::AddVar_ExtractCharsetInformation(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxString wxHtmlParser::ExtractCharsetInformation(wxString const & markup)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_static_ExtractCharsetInformation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'markup'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_static_ExtractCharsetInformation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > markup_smtptr;
  if (!get_val_smtptr_param<wxString >(markup_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & markup = *markup_smtptr;

  wxString res =   wxHtmlParser::ExtractCharsetInformation(markup);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlParser::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::SetFS(wxFileSystem * fs)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_SetFS::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileSystem, "parameter named 'fs'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_SetFS::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFileSystem > fs_smtptr;
  if (!get_val_smtptr_param<wxFileSystem >(fs_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFileSystem* fs = fs_smtptr.get();

  this->_objectptr->GetObj()->SetFS(fs);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxFileSystem * wxHtmlParser::GetFS()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_GetFS::SetParametersComments()
{
  return_comments="returning a variable of type wxFileSystem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_GetFS::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFileSystem * res =   this->_objectptr->GetObj()->GetFS();
  BasicVariable::ptr res_var = WrapClass_wxFileSystem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxFSFile * wxHtmlParser::OpenURL(wxHtmlURLType type, wxString const & url)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_OpenURL::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'url'")
  return_comments="returning a variable of type wxFSFile";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_OpenURL::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int type_int;
  if (!get_val_param<int >(type_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlURLType type = (wxHtmlURLType) type_int;

  boost::shared_ptr<wxString > url_smtptr;
  if (!get_val_smtptr_param<wxString >(url_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & url = *url_smtptr;

  wxFSFile * res =   this->_objectptr->GetObj()->OpenURL(type, url);
  BasicVariable::ptr res_var = WrapClass_wxFSFile::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObject * wxHtmlParser::Parse(wxString const & source)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_Parse::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'source'")
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_Parse::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > source_smtptr;
  if (!get_val_smtptr_param<wxString >(source_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & source = *source_smtptr;

  wxObject * res =   this->_objectptr->GetObj()->Parse(source);
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::InitParser(wxString const & source)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_InitParser::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'source'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_InitParser::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > source_smtptr;
  if (!get_val_smtptr_param<wxString >(source_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & source = *source_smtptr;

  this->_objectptr->GetObj()->InitParser(source);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::DoneParser()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_DoneParser::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_DoneParser::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoneParser();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::StopParsing()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_StopParsing::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_StopParsing::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StopParsing();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::DoParsing(int begin_pos, int end_pos)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_DoParsing_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'begin_pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'end_pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_DoParsing_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int begin_pos;
  if (!get_val_param<int >(begin_pos,_p,_n,true,true)) ClassReturnEmptyVar;

  int end_pos;
  if (!get_val_param<int >(end_pos,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DoParsing(begin_pos, end_pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxHtmlParser::DoParsing(...)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_DoParsing::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_DoParsing::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHtmlParser::wrap_DoParsing_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHtmlParser::wrap_DoParsing_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::DoParsing()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_DoParsing_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_DoParsing_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->DoParsing();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlTag * wxHtmlParser::GetCurrentTag()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_GetCurrentTag::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlTag";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_GetCurrentTag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlTag * res =   this->_objectptr->GetObj()->GetCurrentTag();
  BasicVariable::ptr res_var = WrapClass_wxHtmlTag::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::AddTagHandler(wxHtmlTagHandler * handler)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_AddTagHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlTagHandler, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_AddTagHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlTagHandler > handler_smtptr;
  if (!get_val_smtptr_param<wxHtmlTagHandler >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlTagHandler* handler = handler_smtptr.get();

  this->_objectptr->GetObj()->AddTagHandler(handler);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::PushTagHandler(wxHtmlTagHandler * handler, wxString const & tags)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_PushTagHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlTagHandler, "parameter named 'handler'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'tags'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_PushTagHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlTagHandler > handler_smtptr;
  if (!get_val_smtptr_param<wxHtmlTagHandler >(handler_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlTagHandler* handler = handler_smtptr.get();

  boost::shared_ptr<wxString > tags_smtptr;
  if (!get_val_smtptr_param<wxString >(tags_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & tags = *tags_smtptr;

  this->_objectptr->GetObj()->PushTagHandler(handler, tags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::PopTagHandler()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_PopTagHandler::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_PopTagHandler::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PopTagHandler();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString * wxHtmlParser::GetSource()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_GetSource::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_GetSource::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString * res =   this->_objectptr->GetObj()->GetSource();
  BasicVariable::ptr res_var = WrapClass_wxString::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::SetSource(wxString const & src)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_SetSource::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_SetSource::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > src_smtptr;
  if (!get_val_smtptr_param<wxString >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & src = *src_smtptr;

  this->_objectptr->GetObj()->SetSource(src);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlParser::SetSourceAndSaveState(wxString const & src)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_SetSourceAndSaveState::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_SetSourceAndSaveState::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > src_smtptr;
  if (!get_val_smtptr_param<wxString >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & src = *src_smtptr;

  this->_objectptr->GetObj()->SetSourceAndSaveState(src);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlParser::RestoreState()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_RestoreState::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_RestoreState::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->RestoreState();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlParser::GetInnerSource(wxHtmlTag const & tag)
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_GetInnerSource::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlTag, "parameter named 'tag'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_GetInnerSource::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlTag > tag_smtptr;
  if (!get_val_smtptr_param<wxHtmlTag >(tag_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlTag const & tag = *tag_smtptr;

  wxString res =   this->_objectptr->GetObj()->GetInnerSource(tag);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlEntitiesParser * wxHtmlParser::GetEntitiesParser()
//---------------------------------------------------
void WrapClass_wxHtmlParser::
    wrap_GetEntitiesParser::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlEntitiesParser";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlParser::
    wrap_GetEntitiesParser::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlEntitiesParser * res =   this->_objectptr->GetObj()->GetEntitiesParser();
  BasicVariable::ptr res_var = WrapClass_wxHtmlEntitiesParser::CreateVar(res);
  return res_var;
}

