/**
 * C++ Interface: wrap_wxOutputStream
 *
 * Description: wrapping wxOutputStream
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

#include "wrap_wxOutputStream.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxOutputStream_declared
  #define wxOutputStream_declared
  AMI_DECLARE_TYPE(wxOutputStream)
#endif
#ifndef wxInputStream_declared
  #define wxInputStream_declared
  AMI_DECLARE_TYPE(wxInputStream)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxOutputStream>::CreateVar( ParamList* p)
{
  WrapClass_wxOutputStream::wrap_wxOutputStream construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxOutputStream);
AMI_DEFINE_VARFROMSMTPTR(wxOutputStream);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxOutputStream>::CreateVar( wxOutputStream* val, bool nodeleter)
{ 
  boost::shared_ptr<wxOutputStream> obj_ptr(val,smartpointer_nodeleter<wxOutputStream>());
  return AMILabType<wxOutputStream>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxOutputStream
//
Variable<AMIObject>::ptr WrapClass_wxOutputStream::CreateVar( wxOutputStream* sp)
{
  boost::shared_ptr<wxOutputStream> di_ptr(
    sp,
    wxwindow_nodeleter<wxOutputStream>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxOutputStream>::CreateVar(
      new WrapClass_wxOutputStream(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxOutputStream::AddMethods(WrapClass<wxOutputStream>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_PutC( this_ptr);
/* The following types are missing: void
  AddVar_Write_1( this_ptr);
*/
  AddVar_Write( this_ptr);
  AddVar_Write_2( this_ptr);
  AddVar_SeekO( this_ptr);
  AddVar_TellO( this_ptr);
  AddVar_LastWrite( this_ptr);
  AddVar_Sync( this_ptr);
  AddVar_Close( this_ptr);

  // Adding operators
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
/* The following types are missing: _6623
  // AddVar_operator not available( this_ptr);
*/



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxStreamBase
  boost::shared_ptr<wxStreamBase > parent_wxStreamBase(  boost::dynamic_pointer_cast<wxStreamBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxStreamBase = AMILabType<wxStreamBase >::CreateVarFromSmtPtr(parent_wxStreamBase);
  context->AddVar("wxStreamBase",var_wxStreamBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxStreamBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxStreamBase);
  context->AddDefault(obj_wxStreamBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxOutputStream_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxOutputStream");
    WrapClass_wxOutputStream::AddVar_wxOutputStream(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxOutputStream::wxOutputStream()
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_wxOutputStream::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_wxOutputStream::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxOutputStream* _newobj = new wxOutputStream();
  BasicVariable::ptr res = WrapClass_wxOutputStream::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxOutputStream::PutC(char c)
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_PutC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_PutC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string c_string;
  if (!get_val_param<std::string >(c_string,_p,_n,true,false)) ClassHelpAndReturn;
  char c = ' ';
if (c_string.size()>0) c = c_string[0];

  this->_objectptr->GetObj()->PutC(c);
  return BasicVariable::ptr();
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxOutputStream & wxOutputStream::Write(void const * buffer, size_t size)
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_Write_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'buffer'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'size'")
  return_comments="returning a variable of type wxOutputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_Write_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  void* buffer;
  if (CheckNullVar(_p,_n))  {
    buffer=(void*)NULL;
    _n++;
  } else {
    boost::shared_ptr<void > buffer_smtptr;
    if (!get_val_smtptr_param<void >(buffer_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    buffer = buffer_smtptr.get();
  }

  long size_long;
  if (!get_val_param<long >(size_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int size = boost::numeric_cast<long unsigned int >(size_long);

  wxOutputStream & res =   this->_objectptr->GetObj()->Write(buffer, size);
  return AMILabType<wxOutputStream >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxOutputStream::Write(...)
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_Write::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_Write::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxOutputStream::wrap_Write_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxOutputStream & wxOutputStream::Write(wxInputStream & stream_in)
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_Write_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream_in'")
  return_comments="returning a variable of type wxOutputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_Write_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxInputStream > stream_in_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_in_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxInputStream & stream_in = *stream_in_smtptr;

  wxOutputStream & res =   this->_objectptr->GetObj()->Write(stream_in);
  return AMILabType<wxOutputStream >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxFileOffset wxOutputStream::SeekO(wxFileOffset pos, wxSeekMode mode = wxFromStart)
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_SeekO::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mode' (def:wxFromStart)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_SeekO::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int pos = pos_long;

  int mode_int = (int) wxFromStart;;
  if (!get_val_param<int >(mode_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxSeekMode mode = (wxSeekMode) mode_int;

  wxFileOffset res =   this->_objectptr->GetObj()->SeekO(pos, mode);
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxFileOffset wxOutputStream::TellO()
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_TellO::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_TellO::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFileOffset res =   this->_objectptr->GetObj()->TellO();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxOutputStream::LastWrite()
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_LastWrite::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_LastWrite::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->LastWrite();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxOutputStream::Sync()
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_Sync::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_Sync::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Sync();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxOutputStream::Close()
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_Close::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_Close::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Close();
  return AMILabType<bool >::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxOutputStream & wxOutputStream::<<(wxInputStream & out)
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'out'")
  return_comments="returning a variable of type wxOutputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxInputStream > out_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxInputStream & out = *out_smtptr;

  wxOutputStream & res =   this->_objectptr->GetObj()-><<(out);
  return AMILabType<wxOutputStream >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxOutputStream::<<(...)
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * The following types are missing: _6623
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxOutputStream & wxOutputStream::<<(__wxOutputManip func)
//---------------------------------------------------
void WrapClass_wxOutputStream::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _6623, "parameter named 'func'")
  return_comments="returning a variable of type wxOutputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxOutputStream::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  _6623 func;
  if (!get_val_param<_6623 >(func,_p,_n,true,true)) ClassReturnEmptyVar;

  wxOutputStream & res =   this->_objectptr->GetObj()-><<(func);
  return AMILabType<wxOutputStream >::CreateVar(res);
}
*/

