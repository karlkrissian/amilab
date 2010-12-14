/**
 * C++ Interface: wrap_wxImageHandler
 *
 * Description: wrapping wxImageHandler
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

#include "wrap_wxImageHandler.h"

// get all the required includes
// #include "..."
#ifndef wxImage_declared
  #define wxImage_declared
  AMI_DECLARE_TYPE(wxImage)
#endif
#ifndef wxInputStream_declared
  #define wxInputStream_declared
  AMI_DECLARE_TYPE(wxInputStream)
#endif
#ifndef wxOutputStream_declared
  #define wxOutputStream_declared
  AMI_DECLARE_TYPE(wxOutputStream)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif
#ifndef wxImageHandler_declared
  #define wxImageHandler_declared
  AMI_DECLARE_TYPE(wxImageHandler)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxImageHandler>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxImageHandler);
AMI_DEFINE_VARFROMSMTPTR(wxImageHandler);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxImageHandler
//
Variable<AMIObject>::ptr WrapClass_wxImageHandler::CreateVar( wxImageHandler* sp)
{
  boost::shared_ptr<wxImageHandler> di_ptr(
    sp,
    wxwindow_nodeleter<wxImageHandler>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxImageHandler>::CreateVar(
      new WrapClass_wxImageHandler(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxImageHandler::AddMethods(WrapClass<wxImageHandler>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_LoadFile( this_ptr);
  AddVar_SaveFile( this_ptr);
  AddVar_GetImageCount( this_ptr);
  AddVar_CanRead_1( this_ptr);
  AddVar_CanRead( this_ptr);
  AddVar_CanRead_2( this_ptr);
  AddVar_SetName( this_ptr);
  AddVar_SetExtension( this_ptr);
  AddVar_SetType( this_ptr);
  AddVar_SetMimeType( this_ptr);
  AddVar_GetName( this_ptr);
  AddVar_GetExtension( this_ptr);
  AddVar_GetType( this_ptr);
  AddVar_GetMimeType( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



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
void WrapClasswxImageHandler_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxImageHandler");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of bool wxImageHandler::LoadFile(wxImage * image, wxInputStream & stream, bool verbose = true, int index = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_LoadFile::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImage, "parameter named 'image'")
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'verbose' (def:true)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index' (def:-0x00000000000000001)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_LoadFile::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  wxImage* image;
  if (CheckNullVar(_p,_n))  {
    image=(wxImage*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxImage > image_smtptr;
    if (!get_val_smtptr_param<wxImage >(image_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    image = image_smtptr.get();
  }

  boost::shared_ptr<wxInputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxInputStream & stream = *stream_smtptr;

  bool verbose = true;
  if (!get_val_param<bool >(verbose,_p,_n,false,false)) ClassHelpAndReturn;

  int index = -0x00000000000000001;
  if (!get_val_param<int >(index,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->LoadFile(image, stream, verbose, index);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxImageHandler::SaveFile(wxImage * image, wxOutputStream & stream, bool verbose = true)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_SaveFile::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImage, "parameter named 'image'")
  ADDPARAMCOMMENT_TYPE( wxOutputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'verbose' (def:true)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_SaveFile::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  wxImage* image;
  if (CheckNullVar(_p,_n))  {
    image=(wxImage*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxImage > image_smtptr;
    if (!get_val_smtptr_param<wxImage >(image_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    image = image_smtptr.get();
  }

  boost::shared_ptr<wxOutputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxOutputStream >(stream_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxOutputStream & stream = *stream_smtptr;

  bool verbose = true;
  if (!get_val_param<bool >(verbose,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->SaveFile(image, stream, verbose);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxImageHandler::GetImageCount(wxInputStream & stream)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_GetImageCount::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_GetImageCount::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxInputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxInputStream & stream = *stream_smtptr;

  int res =   this->_objectptr->GetObj()->GetImageCount(stream);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxImageHandler::CanRead(wxInputStream & stream)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_CanRead_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_CanRead_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxInputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxInputStream & stream = *stream_smtptr;

  bool res =   this->_objectptr->GetObj()->CanRead(stream);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImageHandler::CanRead(...)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_CanRead::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_CanRead::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImageHandler::wrap_CanRead_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImageHandler::wrap_CanRead_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxImageHandler::CanRead(wxString const & name)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_CanRead_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_CanRead_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  bool res =   this->_objectptr->GetObj()->CanRead(name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImageHandler::SetName(wxString const & name)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_SetName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_SetName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  this->_objectptr->GetObj()->SetName(name);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxImageHandler::SetExtension(wxString const & ext)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_SetExtension::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_SetExtension::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > ext_smtptr;
  if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & ext = *ext_smtptr;

  this->_objectptr->GetObj()->SetExtension(ext);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxImageHandler::SetType(long int type)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_SetType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'type'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_SetType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long type_long;
  if (!get_val_param<long >(type_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int type = type_long;

  this->_objectptr->GetObj()->SetType(type);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxImageHandler::SetMimeType(wxString const & type)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_SetMimeType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'type'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_SetMimeType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > type_smtptr;
  if (!get_val_smtptr_param<wxString >(type_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & type = *type_smtptr;

  this->_objectptr->GetObj()->SetMimeType(type);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxImageHandler::GetName()
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_GetName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_GetName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxImageHandler::GetExtension()
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_GetExtension::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_GetExtension::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetExtension();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long int wxImageHandler::GetType()
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_GetType::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_GetType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetType();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxImageHandler::GetMimeType()
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_GetMimeType::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_GetMimeType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetMimeType();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxImageHandler::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxImageHandler & wxImageHandler::operator =(wxImageHandler const & param0)
//---------------------------------------------------
void WrapClass_wxImageHandler::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHandler, "parameter named 'param0'")
  return_comments="returning a variable of type wxImageHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHandler::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHandler > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHandler >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxImageHandler const & param0 = *param0_smtptr;

  wxImageHandler & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxImageHandler >::CreateVar(res);
}

