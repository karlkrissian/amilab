/**
 * C++ Interface: wrap_wxFSFile
 *
 * Description: wrapping wxFSFile
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

#include "wrap_wxFSFile.h"

// get all the required includes
// #include "..."
#ifndef wxInputStream_declared
  #define wxInputStream_declared
  AMI_DECLARE_TYPE(wxInputStream)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxDateTime_declared
  #define wxDateTime_declared
  AMI_DECLARE_TYPE(wxDateTime)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxFSFile>::CreateVar( ParamList* p)
{
  WrapClass_wxFSFile::wrap_wxFSFile construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxFSFile);
AMI_DEFINE_VARFROMSMTPTR(wxFSFile);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxFSFile>::CreateVar( wxFSFile* val, bool nodeleter)
{ 
  boost::shared_ptr<wxFSFile> obj_ptr(val,smartpointer_nodeleter<wxFSFile>());
  return AMILabType<wxFSFile>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxFSFile
//
Variable<AMIObject>::ptr WrapClass_wxFSFile::CreateVar( wxFSFile* sp)
{
  boost::shared_ptr<wxFSFile> di_ptr(
    sp,
    wxwindow_nodeleter<wxFSFile>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFSFile>::CreateVar(
      new WrapClass_wxFSFile(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxFSFile::AddMethods(WrapClass<wxFSFile>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetStream( this_ptr);
  AddVar_DetachStream( this_ptr);
  AddVar_SetStream( this_ptr);
  AddVar_GetMimeType( this_ptr);
  AddVar_GetLocation( this_ptr);
  AddVar_GetAnchor( this_ptr);
  AddVar_GetModificationTime( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

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
void WrapClasswxFSFile_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxFSFile");
    WrapClass_wxFSFile::AddVar_wxFSFile(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxFSFile::wxFSFile(wxInputStream * stream, wxString const & loc, wxString const & mimetype, wxString const & anchor, wxDateTime modif)
//---------------------------------------------------
void WrapClass_wxFSFile::
    wrap_wxFSFile::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'loc'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'mimetype'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'anchor'")
  ADDPARAMCOMMENT_TYPE( wxDateTime, "parameter named 'modif'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFSFile::
    wrap_wxFSFile::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  wxInputStream* stream;
  if (CheckNullVar(_p,_n))  {
    stream=(wxInputStream*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxInputStream > stream_smtptr;
    if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    stream = stream_smtptr.get();
  }

  boost::shared_ptr<wxString > loc_smtptr;
  if (!get_val_smtptr_param<wxString >(loc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & loc = *loc_smtptr;

  boost::shared_ptr<wxString > mimetype_smtptr;
  if (!get_val_smtptr_param<wxString >(mimetype_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & mimetype = *mimetype_smtptr;

  boost::shared_ptr<wxString > anchor_smtptr;
  if (!get_val_smtptr_param<wxString >(anchor_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & anchor = *anchor_smtptr;

  wxDateTime modif;
  if (!get_val_param<wxDateTime >(modif,_p,_n,true,false)) ClassHelpAndReturn;

  wxFSFile* _newobj = new wxFSFile(stream, loc, mimetype, anchor, modif);
  BasicVariable::ptr res = WrapClass_wxFSFile::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxInputStream * wxFSFile::GetStream()
//---------------------------------------------------
void WrapClass_wxFSFile::
    wrap_GetStream::SetParametersComments()
{
  return_comments="returning a variable of type wxInputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFSFile::
    wrap_GetStream::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxInputStream * res =   this->_objectptr->GetObj()->GetStream();
  BasicVariable::ptr res_var = AMILabType<wxInputStream >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxInputStream * wxFSFile::DetachStream()
//---------------------------------------------------
void WrapClass_wxFSFile::
    wrap_DetachStream::SetParametersComments()
{
  return_comments="returning a variable of type wxInputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFSFile::
    wrap_DetachStream::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxInputStream * res =   this->_objectptr->GetObj()->DetachStream();
  BasicVariable::ptr res_var = AMILabType<wxInputStream >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxFSFile::SetStream(wxInputStream * stream)
//---------------------------------------------------
void WrapClass_wxFSFile::
    wrap_SetStream::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFSFile::
    wrap_SetStream::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxInputStream* stream;
  if (CheckNullVar(_p,_n))  {
    stream=(wxInputStream*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxInputStream > stream_smtptr;
    if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    stream = stream_smtptr.get();
  }

  this->_objectptr->GetObj()->SetStream(stream);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxFSFile::GetMimeType()
//---------------------------------------------------
void WrapClass_wxFSFile::
    wrap_GetMimeType::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFSFile::
    wrap_GetMimeType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetMimeType();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxFSFile::GetLocation()
//---------------------------------------------------
void WrapClass_wxFSFile::
    wrap_GetLocation::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFSFile::
    wrap_GetLocation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetLocation();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxFSFile::GetAnchor()
//---------------------------------------------------
void WrapClass_wxFSFile::
    wrap_GetAnchor::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFSFile::
    wrap_GetAnchor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetAnchor();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDateTime wxFSFile::GetModificationTime()
//---------------------------------------------------
void WrapClass_wxFSFile::
    wrap_GetModificationTime::SetParametersComments()
{
  return_comments="returning a variable of type wxDateTime";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFSFile::
    wrap_GetModificationTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDateTime res =   this->_objectptr->GetObj()->GetModificationTime();
  return AMILabType<wxDateTime >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxFSFile::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxFSFile::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFSFile::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

