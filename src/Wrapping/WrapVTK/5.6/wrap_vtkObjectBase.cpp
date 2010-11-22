/**
 * C++ Interface: wrap_vtkObjectBase
 *
 * Description: wrapping vtkObjectBase
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
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"


#include "wrap_vtkObjectBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkObjectBase>::CreateVar( ParamList* p)
{
  WrapClass_vtkObjectBase::wrap_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkObjectBase);
AMI_DEFINE_VARFROMSMTPTR(vtkObjectBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkObjectBase>::CreateVar( vtkObjectBase* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkObjectBase> obj_ptr(val,smartpointer_nodeleter<vtkObjectBase>());
  return AMILabType<vtkObjectBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkObjectBase
//
Variable<AMIObject>::ptr WrapClass_vtkObjectBase::CreateVar( vtkObjectBase* sp)
{
  boost::shared_ptr<vtkObjectBase> di_ptr(
    sp,
    wxwindow_nodeleter<vtkObjectBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkObjectBase>::CreateVar(
      new WrapClass_vtkObjectBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkObjectBase::AddMethods(WrapClass<vtkObjectBase>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_GetClassName( this_ptr);
      AddVar_IsA( this_ptr);
      AddVar_Delete( this_ptr);
      AddVar_FastDelete( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_Print( this_ptr);
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintHeader( this_ptr);
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintTrailer( this_ptr);
*/
      AddVar_Register( this_ptr);
      AddVar_UnRegister( this_ptr);
      AddVar_GetReferenceCount( this_ptr);
      AddVar_SetReferenceCount( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintRevisions( this_ptr);
*/



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkObjectBase::IsTypeOf(char const * name)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n)) ClassHelpAndReturn;
  char const * name = name_string->c_str();

  int res =   vtkObjectBase::IsTypeOf(name);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkObjectBase * vtkObjectBase::New()
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkObjectBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkObjectBase * res =   vtkObjectBase::New();
  BasicVariable::ptr res_var = WrapClass_vtkObjectBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of char const * vtkObjectBase::GetClassName()
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_GetClassName::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_GetClassName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetClassName();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of int vtkObjectBase::IsA(char const * name)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > name_string;
  if (!get_val_smtptr_param<std::string >(name_string,_p,_n)) ClassHelpAndReturn;
  char const * name = name_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(name);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::Delete()
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_Delete::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_Delete::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Delete();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::FastDelete()
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_FastDelete::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_FastDelete::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FastDelete();
  return BasicVariable::ptr();
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::Print(ostream & os)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_Print::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_Print::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  this->_objectptr->GetObj()->Print(os);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::PrintHeader(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_PrintHeader::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_PrintHeader::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintHeader(os, indent);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::PrintTrailer(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_PrintTrailer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_PrintTrailer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintTrailer(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::Register(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_Register::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_Register::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  this->_objectptr->GetObj()->Register(o);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::UnRegister(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_UnRegister::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_UnRegister::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  this->_objectptr->GetObj()->UnRegister(o);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkObjectBase::GetReferenceCount()
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_GetReferenceCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_GetReferenceCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetReferenceCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::SetReferenceCount(int param0)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_SetReferenceCount::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_SetReferenceCount::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetReferenceCount(param0);
  return BasicVariable::ptr();
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkObjectBase::PrintRevisions(ostream & os)
//---------------------------------------------------
void WrapClass_vtkObjectBase::
    wrap_PrintRevisions::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkObjectBase::
    wrap_PrintRevisions::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  this->_objectptr->GetObj()->PrintRevisions(os);
  return BasicVariable::ptr();
}
*/

