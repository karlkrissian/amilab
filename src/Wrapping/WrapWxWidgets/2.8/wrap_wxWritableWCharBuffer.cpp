/**
 * C++ Interface: wrap_wxWritableWCharBuffer
 *
 * Description: wrapping wxWritableWCharBuffer
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
#include "wrap_wxWritableWCharBuffer.h"
#include "wrap_wxWCharBuffer.h"
#include "stdlib.h"


#include "wrap_wxWritableWCharBuffer.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxWritableWCharBuffer>::CreateVar( ParamList* p)
{
  WrapClass_wxWritableWCharBuffer::wrap_wxWritableWCharBuffer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxWritableWCharBuffer);
AMI_DEFINE_VARFROMSMTPTR(wxWritableWCharBuffer);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxWritableWCharBuffer
//
Variable<AMIObject>::ptr WrapClass_wxWritableWCharBuffer::CreateVar( wxWritableWCharBuffer* sp)
{
  boost::shared_ptr<wxWritableWCharBuffer> di_ptr(
    sp,
    wxwindow_nodeleter<wxWritableWCharBuffer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxWritableWCharBuffer>::CreateVar(
      new WrapClass_wxWritableWCharBuffer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxWritableWCharBuffer::AddMethods(WrapClass<wxWritableWCharBuffer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 

      // Adding operators
      AddVar___assign__( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxWCharBuffer
  boost::shared_ptr<wxWCharBuffer > parent_wxWCharBuffer(  boost::dynamic_pointer_cast<wxWCharBuffer >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxWCharBuffer = AMILabType<wxWCharBuffer >::CreateVarFromSmtPtr(parent_wxWCharBuffer);
  context->AddVar("wxWCharBuffer",var_wxWCharBuffer);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxWCharBuffer = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxWCharBuffer);
  context->AddDefault(obj_wxWCharBuffer->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxWritableWCharBuffer::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxWritableWCharBuffer");
    WrapClass_wxWritableWCharBuffer::AddVar_wxWritableWCharBuffer_1(amiobject->GetContext());
  WrapClass_wxWritableWCharBuffer::AddVar_wxWritableWCharBuffer(amiobject->GetContext());
  WrapClass_wxWritableWCharBuffer::AddVar_wxWritableWCharBuffer_2(amiobject->GetContext());
  WrapClass_wxWritableWCharBuffer::AddVar_wxWritableWCharBuffer_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxWritableWCharBuffer::wxWritableWCharBuffer(wxWritableWCharBuffer const & param0)
//---------------------------------------------------
void WrapClass_wxWritableWCharBuffer::
    wrap_wxWritableWCharBuffer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWritableWCharBuffer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableWCharBuffer::
    wrap_wxWritableWCharBuffer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWritableWCharBuffer > param0_smtptr;
  if (!get_val_smtptr_param<wxWritableWCharBuffer >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxWritableWCharBuffer const & param0 = *param0_smtptr;

  wxWritableWCharBuffer* _newobj = new wxWritableWCharBuffer(param0);
  BasicVariable::ptr res = WrapClass_wxWritableWCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxWritableWCharBuffer::wxWritableWCharBuffer(...)
//---------------------------------------------------
void WrapClass_wxWritableWCharBuffer::
    wrap_wxWritableWCharBuffer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableWCharBuffer::
    wrap_wxWritableWCharBuffer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWritableWCharBuffer::wrap_wxWritableWCharBuffer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWritableWCharBuffer::wrap_wxWritableWCharBuffer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxWritableWCharBuffer::wrap_wxWritableWCharBuffer_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWritableWCharBuffer::wxWritableWCharBuffer(wxWCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxWritableWCharBuffer::
    wrap_wxWritableWCharBuffer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWCharBuffer, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableWCharBuffer::
    wrap_wxWritableWCharBuffer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWCharBuffer > src_smtptr;
  if (!get_val_smtptr_param<wxWCharBuffer >(src_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWCharBuffer const & src = *src_smtptr;

  wxWritableWCharBuffer* _newobj = new wxWritableWCharBuffer(src);
  BasicVariable::ptr res = WrapClass_wxWritableWCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWritableWCharBuffer::wxWritableWCharBuffer(wchar_t const * str = 0l)
//---------------------------------------------------
void WrapClass_wxWritableWCharBuffer::
    wrap_wxWritableWCharBuffer_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableWCharBuffer::
    wrap_wxWritableWCharBuffer_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > str_string;
  if (!get_val_smtptr_param<std::string >(str_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wchar_t str[str_string->size()+1];
mbstowcs(str,str_string->c_str(),str_string->size()+1);

  wxWritableWCharBuffer* _newobj = new wxWritableWCharBuffer(str);
  BasicVariable::ptr res = WrapClass_wxWritableWCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxWritableWCharBuffer.
//---------------------------------------------------
void WrapClass_wxWritableWCharBuffer::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxWritableWCharBuffer object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableWCharBuffer::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxWritableWCharBuffer >::CreateVar( new wxWritableWCharBuffer(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxWritableWCharBuffer & wxWritableWCharBuffer::operator =(wxWritableWCharBuffer const & param0)
//---------------------------------------------------
void WrapClass_wxWritableWCharBuffer::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWritableWCharBuffer, "parameter named 'param0'")
  return_comments="returning a variable of type wxWritableWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableWCharBuffer::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWritableWCharBuffer > param0_smtptr;
  if (!get_val_smtptr_param<wxWritableWCharBuffer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWritableWCharBuffer const & param0 = *param0_smtptr;

  wxWritableWCharBuffer & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxWritableWCharBuffer >::CreateVar(res);
}

