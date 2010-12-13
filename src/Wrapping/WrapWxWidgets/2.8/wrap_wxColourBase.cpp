/**
 * C++ Interface: wrap_wxColourBase
 *
 * Description: wrapping wxColourBase
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

#include "wrap_wxColourBase.h"

// get all the required includes
// #include "..."
#include "stdlib.h"
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxColourBase_declared
  #define wxColourBase_declared
  AMI_DECLARE_TYPE(wxColourBase)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxColourBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxColourBase);
AMI_DEFINE_VARFROMSMTPTR(wxColourBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxColourBase
//
Variable<AMIObject>::ptr WrapClass_wxColourBase::CreateVar( wxColourBase* sp)
{
  boost::shared_ptr<wxColourBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxColourBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxColourBase>::CreateVar(
      new WrapClass_wxColourBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxColourBase::AddMethods(WrapClass<wxColourBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Set_1( this_ptr);
  AddVar_Set( this_ptr);
  AddVar_Set_2( this_ptr);
  AddVar_Set_3( this_ptr);
  AddVar_Set_4( this_ptr);
  AddVar_Ok( this_ptr);
  AddVar_Alpha( this_ptr);
  AddVar_GetAsString( this_ptr);

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
void WrapClasswxColourBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxColourBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxColourBase::Set(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = wxALPHA_OPAQUE)
//---------------------------------------------------
void WrapClass_wxColourBase::
    wrap_Set_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'red'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'green'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'blue'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'alpha' (def:wxALPHA_OPAQUE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColourBase::
    wrap_Set_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  unsigned char red;
  if (!get_val_param<unsigned char >(red,_p,_n,true,true)) ClassReturnEmptyVar;

  unsigned char green;
  if (!get_val_param<unsigned char >(green,_p,_n,true,true)) ClassReturnEmptyVar;

  unsigned char blue;
  if (!get_val_param<unsigned char >(blue,_p,_n,true,true)) ClassReturnEmptyVar;

  unsigned char alpha = wxALPHA_OPAQUE;
  if (!get_val_param<unsigned char >(alpha,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Set(red, green, blue, alpha);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxColourBase::Set(...)
//---------------------------------------------------
void WrapClass_wxColourBase::
    wrap_Set::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColourBase::
    wrap_Set::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxColourBase::wrap_Set_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxColourBase::wrap_Set_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxColourBase::wrap_Set_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxColourBase::wrap_Set_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxColourBase::Set(wxChar const * str)
//---------------------------------------------------
void WrapClass_wxColourBase::
    wrap_Set_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColourBase::
    wrap_Set_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > str_string;
  if (!get_val_smtptr_param<std::string >(str_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wchar_t str[str_string->size()+1];
mbstowcs(str,str_string->c_str(),str_string->size()+1);

  bool res =   this->_objectptr->GetObj()->Set(str);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxColourBase::Set(wxString const & str)
//---------------------------------------------------
void WrapClass_wxColourBase::
    wrap_Set_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColourBase::
    wrap_Set_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  bool res =   this->_objectptr->GetObj()->Set(str);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxColourBase::Set(long unsigned int colRGB)
//---------------------------------------------------
void WrapClass_wxColourBase::
    wrap_Set_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'colRGB'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColourBase::
    wrap_Set_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long colRGB_long;
  if (!get_val_param<long >(colRGB_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int colRGB = boost::numeric_cast<long unsigned int >(colRGB_long);

  this->_objectptr->GetObj()->Set(colRGB);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxColourBase::Ok()
//---------------------------------------------------
void WrapClass_wxColourBase::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColourBase::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxColourBase::Alpha()
//---------------------------------------------------
void WrapClass_wxColourBase::
    wrap_Alpha::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColourBase::
    wrap_Alpha::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->Alpha();
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxColourBase::GetAsString(long int flags = 3)
//---------------------------------------------------
void WrapClass_wxColourBase::
    wrap_GetAsString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags' (def:3)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColourBase::
    wrap_GetAsString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flags_long = 3;;
  if (!get_val_param<long >(flags_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int flags = flags_long;

  wxString res =   this->_objectptr->GetObj()->GetAsString(flags);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxColourBase & wxColourBase::operator =(wxColourBase const & param0)
//---------------------------------------------------
void WrapClass_wxColourBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColourBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxColourBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColourBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColourBase > param0_smtptr;
  if (!get_val_smtptr_param<wxColourBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColourBase const & param0 = *param0_smtptr;

  wxColourBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxColourBase >::CreateVar(res);
}

