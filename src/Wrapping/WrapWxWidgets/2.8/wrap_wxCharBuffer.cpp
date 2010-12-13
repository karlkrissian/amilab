/**
 * C++ Interface: wrap_wxCharBuffer
 *
 * Description: wrapping wxCharBuffer
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

#include "wrap_wxCharBuffer.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxCharBuffer_declared
  #define wxCharBuffer_declared
  AMI_DECLARE_TYPE(wxCharBuffer)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxCharBuffer>::CreateVar( ParamList* p)
{
  WrapClass_wxCharBuffer::wrap_wxCharBuffer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxCharBuffer);
AMI_DEFINE_VARFROMSMTPTR(wxCharBuffer);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxCharBuffer
//
Variable<AMIObject>::ptr WrapClass_wxCharBuffer::CreateVar( wxCharBuffer* sp)
{
  boost::shared_ptr<wxCharBuffer> di_ptr(
    sp,
    wxwindow_nodeleter<wxCharBuffer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxCharBuffer>::CreateVar(
      new WrapClass_wxCharBuffer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxCharBuffer::AddMethods(WrapClass<wxCharBuffer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_release( this_ptr);
  AddVar_reset( this_ptr);
  AddVar_extend( this_ptr);
  AddVar_data_1( this_ptr);
  AddVar_data( this_ptr);
  AddVar_data_2( this_ptr);

  // Adding operators
  AddVar___assign___1( this_ptr);
  AddVar___assign__( this_ptr);
  AddVar___assign___2( this_ptr);
  AddVar___at__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxCharBuffer_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxCharBuffer");
    WrapClass_wxCharBuffer::AddVar_wxCharBuffer_1(amiobject->GetContext());
  WrapClass_wxCharBuffer::AddVar_wxCharBuffer(amiobject->GetContext());
  WrapClass_wxCharBuffer::AddVar_wxCharBuffer_2(amiobject->GetContext());
  WrapClass_wxCharBuffer::AddVar_wxCharBuffer_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxCharBuffer::wxCharBuffer(char const * str = 0l)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_wxCharBuffer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_wxCharBuffer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > str_string;
  if (!get_val_smtptr_param<std::string >(str_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * str = str_string->c_str();

  wxCharBuffer* _newobj = new wxCharBuffer(str);
  BasicVariable::ptr res = WrapClass_wxCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxCharBuffer::wxCharBuffer(...)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_wxCharBuffer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_wxCharBuffer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxCharBuffer::wrap_wxCharBuffer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxCharBuffer::wrap_wxCharBuffer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxCharBuffer::wrap_wxCharBuffer_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCharBuffer::wxCharBuffer(size_t len)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_wxCharBuffer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_wxCharBuffer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long len_long;
  if (!get_val_param<long >(len_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int >(len_long);

  wxCharBuffer* _newobj = new wxCharBuffer(len);
  BasicVariable::ptr res = WrapClass_wxCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCharBuffer::wxCharBuffer(wxCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_wxCharBuffer_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCharBuffer, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_wxCharBuffer_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCharBuffer > src_smtptr;
  if (!get_val_smtptr_param<wxCharBuffer >(src_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxCharBuffer const & src = *src_smtptr;

  wxCharBuffer* _newobj = new wxCharBuffer(src);
  BasicVariable::ptr res = WrapClass_wxCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxCharBuffer.
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxCharBuffer object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxCharBuffer >::CreateVar( new wxCharBuffer(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of char * wxCharBuffer::release()
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_release::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_release::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char * res =   this->_objectptr->GetObj()->release();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void wxCharBuffer::reset()
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_reset::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_reset::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->reset();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxCharBuffer::extend(size_t len)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_extend::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_extend::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long len_long;
  if (!get_val_param<long >(len_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int len = boost::numeric_cast<long unsigned int >(len_long);

  bool res =   this->_objectptr->GetObj()->extend(len);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of char * wxCharBuffer::data()
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_data_1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_data_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  char * res =   this->_objectptr->GetObj()->data();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxCharBuffer::data(...)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_data::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_data::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxCharBuffer::wrap_data_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxCharBuffer::wrap_data_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of char const * wxCharBuffer::data()
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_data_2::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_data_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  char const * res =   this->_objectptr->GetObj()->data();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer & wxCharBuffer::operator =(char const * str)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap___assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str'")
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap___assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > str_string;
  if (!get_val_smtptr_param<std::string >(str_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * str = str_string->c_str();

  wxCharBuffer & res =   (*this->_objectptr->GetObj()) = (str);
  return AMILabType<wxCharBuffer >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxCharBuffer::=(...)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap___assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap___assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxCharBuffer::wrap___assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxCharBuffer::wrap___assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer & wxCharBuffer::operator =(wxCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap___assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCharBuffer, "parameter named 'src'")
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap___assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCharBuffer > src_smtptr;
  if (!get_val_smtptr_param<wxCharBuffer >(src_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxCharBuffer const & src = *src_smtptr;

  wxCharBuffer & res =   (*this->_objectptr->GetObj()) = (src);
  return AMILabType<wxCharBuffer >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of char wxCharBuffer::operator [](size_t n)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  char res =   (*this->_objectptr->GetObj()) [ (n)];
  std::string res_string = std::string(1,res);
  return AMILabType<std::string >::CreateVar(res_string);
}

