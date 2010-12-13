/**
 * C++ Interface: wrap_wxInputStream
 *
 * Description: wrapping wxInputStream
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

#include "wrap_wxInputStream.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxInputStream_declared
  #define wxInputStream_declared
  AMI_DECLARE_TYPE(wxInputStream)
#endif
#ifndef wxOutputStream_declared
  #define wxOutputStream_declared
  AMI_DECLARE_TYPE(wxOutputStream)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxInputStream>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxInputStream);
AMI_DEFINE_VARFROMSMTPTR(wxInputStream);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxInputStream>::CreateVar( wxInputStream* val, bool nodeleter)
{ 
  boost::shared_ptr<wxInputStream> obj_ptr(val,smartpointer_nodeleter<wxInputStream>());
  return AMILabType<wxInputStream>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxInputStream
//
Variable<AMIObject>::ptr WrapClass_wxInputStream::CreateVar( wxInputStream* sp)
{
  boost::shared_ptr<wxInputStream> di_ptr(
    sp,
    wxwindow_nodeleter<wxInputStream>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxInputStream>::CreateVar(
      new WrapClass_wxInputStream(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxInputStream::AddMethods(WrapClass<wxInputStream>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Peek( this_ptr);
  AddVar_GetC( this_ptr);
/* The following types are missing: void
  AddVar_Read_1( this_ptr);
*/
  AddVar_Read( this_ptr);
  AddVar_Read_2( this_ptr);
  AddVar_LastRead( this_ptr);
  AddVar_CanRead( this_ptr);
  AddVar_Eof( this_ptr);
/* The following types are missing: void
  AddVar_Ungetch_1( this_ptr);
*/
  AddVar_Ungetch( this_ptr);
  AddVar_Ungetch_2( this_ptr);
  AddVar_SeekI( this_ptr);
  AddVar_TellI( this_ptr);

  // Adding operators
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
/* The following types are missing: _6152
  // AddVar_operator not available( this_ptr);
*/



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

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
void WrapClasswxInputStream_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxInputStream");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of char wxInputStream::Peek()
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_Peek::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_Peek::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char res =   this->_objectptr->GetObj()->Peek();
  std::string res_string = std::string(1,res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of int wxInputStream::GetC()
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_GetC::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_GetC::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetC();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxInputStream & wxInputStream::Read(void * buffer, size_t size)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_Read_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'buffer'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'size'")
  return_comments="returning a variable of type wxInputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_Read_1::CallMember( ParamList* _p)
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

  wxInputStream & res =   this->_objectptr->GetObj()->Read(buffer, size);
  return AMILabType<wxInputStream >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxInputStream::Read(...)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_Read::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_Read::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxInputStream::wrap_Read_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxInputStream & wxInputStream::Read(wxOutputStream & streamOut)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_Read_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxOutputStream, "parameter named 'streamOut'")
  return_comments="returning a variable of type wxInputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_Read_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxOutputStream > streamOut_smtptr;
  if (!get_val_smtptr_param<wxOutputStream >(streamOut_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxOutputStream & streamOut = *streamOut_smtptr;

  wxInputStream & res =   this->_objectptr->GetObj()->Read(streamOut);
  return AMILabType<wxInputStream >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxInputStream::LastRead()
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_LastRead::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_LastRead::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->LastRead();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxInputStream::CanRead()
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_CanRead::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_CanRead::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->CanRead();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxInputStream::Eof()
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_Eof::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_Eof::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Eof();
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of size_t wxInputStream::Ungetch(void const * buffer, size_t size)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_Ungetch_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'buffer'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'size'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_Ungetch_1::CallMember( ParamList* _p)
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

  size_t res =   this->_objectptr->GetObj()->Ungetch(buffer, size);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxInputStream::Ungetch(...)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_Ungetch::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_Ungetch::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxInputStream::wrap_Ungetch_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxInputStream::Ungetch(char c)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_Ungetch_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_Ungetch_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string c_string;
  if (!get_val_param<std::string >(c_string,_p,_n,true,true)) ClassReturnEmptyVar;
  char c = ' ';
if (c_string.size()>0) c = c_string[0];

  bool res =   this->_objectptr->GetObj()->Ungetch(c);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxFileOffset wxInputStream::SeekI(wxFileOffset pos, wxSeekMode mode = wxFromStart)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_SeekI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mode' (def:wxFromStart)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_SeekI::CallMember( ParamList* _p)
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

  wxFileOffset res =   this->_objectptr->GetObj()->SeekI(pos, mode);
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxFileOffset wxInputStream::TellI()
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_TellI::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_TellI::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFileOffset res =   this->_objectptr->GetObj()->TellI();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxInputStream & wxInputStream::>>(wxOutputStream & out)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxOutputStream, "parameter named 'out'")
  return_comments="returning a variable of type wxInputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxOutputStream > out_smtptr;
  if (!get_val_smtptr_param<wxOutputStream >(out_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxOutputStream & out = *out_smtptr;

  wxInputStream & res =   this->_objectptr->GetObj()->>>(out);
  return AMILabType<wxInputStream >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxInputStream::>>(...)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * The following types are missing: _6152
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxInputStream & wxInputStream::>>(__wxInputManip func)
//---------------------------------------------------
void WrapClass_wxInputStream::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _6152, "parameter named 'func'")
  return_comments="returning a variable of type wxInputStream";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxInputStream::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  _6152 func;
  if (!get_val_param<_6152 >(func,_p,_n,true,true)) ClassReturnEmptyVar;

  wxInputStream & res =   this->_objectptr->GetObj()->>>(func);
  return AMILabType<wxInputStream >::CreateVar(res);
}
*/

