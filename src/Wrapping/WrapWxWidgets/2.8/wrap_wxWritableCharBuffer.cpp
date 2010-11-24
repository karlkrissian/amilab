/**
 * C++ Interface: wrap_wxWritableCharBuffer
 *
 * Description: wrapping wxWritableCharBuffer
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
#include "wrap_wxWritableCharBuffer.h"
#include "wrap_wxCharBuffer.h"


#include "wrap_wxWritableCharBuffer.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxWritableCharBuffer>::CreateVar( ParamList* p)
{
  WrapClass_wxWritableCharBuffer::wrap_wxWritableCharBuffer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxWritableCharBuffer);
AMI_DEFINE_VARFROMSMTPTR(wxWritableCharBuffer);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxWritableCharBuffer
//
Variable<AMIObject>::ptr WrapClass_wxWritableCharBuffer::CreateVar( wxWritableCharBuffer* sp)
{
  boost::shared_ptr<wxWritableCharBuffer> di_ptr(
    sp,
    wxwindow_nodeleter<wxWritableCharBuffer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxWritableCharBuffer>::CreateVar(
      new WrapClass_wxWritableCharBuffer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxWritableCharBuffer::AddMethods(WrapClass<wxWritableCharBuffer>::ptr this_ptr )
{
  
      // Add members from wxCharBuffer
      WrapClass_wxCharBuffer::ptr parent_wxCharBuffer(        boost::dynamic_pointer_cast<WrapClass_wxCharBuffer >(this_ptr));
      parent_wxCharBuffer->AddMethods(parent_wxCharBuffer);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxWritableCharBuffer::wxWritableCharBuffer(wxWritableCharBuffer const & param0)
//---------------------------------------------------
void WrapClass_wxWritableCharBuffer::
    wrap_wxWritableCharBuffer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWritableCharBuffer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableCharBuffer::
    wrap_wxWritableCharBuffer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWritableCharBuffer > param0_smtptr;
  if (!get_val_smtptr_param<wxWritableCharBuffer >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxWritableCharBuffer const & param0 = *param0_smtptr;

  wxWritableCharBuffer* _newobj = new wxWritableCharBuffer(param0);
  BasicVariable::ptr res = WrapClass_wxWritableCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxWritableCharBuffer::wxWritableCharBuffer(...)
//---------------------------------------------------
void WrapClass_wxWritableCharBuffer::
    wrap_wxWritableCharBuffer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableCharBuffer::
    wrap_wxWritableCharBuffer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWritableCharBuffer::wrap_wxWritableCharBuffer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWritableCharBuffer::wrap_wxWritableCharBuffer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxWritableCharBuffer::wrap_wxWritableCharBuffer_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWritableCharBuffer::wxWritableCharBuffer(wxCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxWritableCharBuffer::
    wrap_wxWritableCharBuffer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCharBuffer, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableCharBuffer::
    wrap_wxWritableCharBuffer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCharBuffer > src_smtptr;
  if (!get_val_smtptr_param<wxCharBuffer >(src_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxCharBuffer const & src = *src_smtptr;

  wxWritableCharBuffer* _newobj = new wxWritableCharBuffer(src);
  BasicVariable::ptr res = WrapClass_wxWritableCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWritableCharBuffer::wxWritableCharBuffer(char const * str = 0l)
//---------------------------------------------------
void WrapClass_wxWritableCharBuffer::
    wrap_wxWritableCharBuffer_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableCharBuffer::
    wrap_wxWritableCharBuffer_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > str_string;
  if (!get_val_smtptr_param<std::string >(str_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * str = str_string->c_str();

  wxWritableCharBuffer* _newobj = new wxWritableCharBuffer(str);
  BasicVariable::ptr res = WrapClass_wxWritableCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxWritableCharBuffer.
//---------------------------------------------------
void WrapClass_wxWritableCharBuffer::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxWritableCharBuffer object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableCharBuffer::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxWritableCharBuffer >::CreateVar( new wxWritableCharBuffer(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxWritableCharBuffer & wxWritableCharBuffer::operator =(wxWritableCharBuffer const & param0)
//---------------------------------------------------
void WrapClass_wxWritableCharBuffer::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWritableCharBuffer, "parameter named 'param0'")
  return_comments="returning a variable of type wxWritableCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWritableCharBuffer::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWritableCharBuffer > param0_smtptr;
  if (!get_val_smtptr_param<wxWritableCharBuffer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWritableCharBuffer const & param0 = *param0_smtptr;

  wxWritableCharBuffer & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxWritableCharBuffer >::CreateVar(res);
}

