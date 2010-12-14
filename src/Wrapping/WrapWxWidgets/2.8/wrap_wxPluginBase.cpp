/**
 * C++ Interface: wrap_wxPluginBase
 *
 * Description: wrapping wxPluginBase
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

#include "wrap_wxPluginBase.h"

// get all the required includes
// #include "..."
#ifndef wxPluginBase_declared
  #define wxPluginBase_declared
  AMI_DECLARE_TYPE(wxPluginBase)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPluginBase>::CreateVar( ParamList* p)
{
  WrapClass_wxPluginBase::wrap_wxPluginBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxPluginBase);
AMI_DEFINE_VARFROMSMTPTR(wxPluginBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPluginBase
//
Variable<AMIObject>::ptr WrapClass_wxPluginBase::CreateVar( wxPluginBase* sp)
{
  boost::shared_ptr<wxPluginBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxPluginBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPluginBase>::CreateVar(
      new WrapClass_wxPluginBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPluginBase::AddMethods(WrapClass<wxPluginBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetName( this_ptr);
  AddVar_GetDescription( this_ptr);
  AddVar_GetVersion( this_ptr);
  AddVar_GetAuthor( this_ptr);
  AddVar_SetName( this_ptr);
  AddVar_SetDescription( this_ptr);
  AddVar_SetVersion( this_ptr);
  AddVar_SetAuthor( this_ptr);
  AddVar_GetwxWindow( this_ptr);
  AddVar_SetwxWindow( this_ptr);
  AddVar_SetConsoleMode( this_ptr);
  AddVar_SetGraphicMode( this_ptr);
  AddVar_IsConsoleMode( this_ptr);
  AddVar_IsGraphicMode( this_ptr);
  AddVar_Execute( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxPluginInterface
  boost::shared_ptr<wxPluginInterface > parent_wxPluginInterface(  boost::dynamic_pointer_cast<wxPluginInterface >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxPluginInterface = AMILabType<wxPluginInterface >::CreateVarFromSmtPtr(parent_wxPluginInterface);
  context->AddVar("wxPluginInterface",var_wxPluginInterface);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxPluginInterface = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxPluginInterface);
  context->AddDefault(obj_wxPluginInterface->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPluginBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxPluginBase");
    WrapClass_wxPluginBase::AddVar_wxPluginBase_1(amiobject->GetContext());
  WrapClass_wxPluginBase::AddVar_wxPluginBase(amiobject->GetContext());
  WrapClass_wxPluginBase::AddVar_wxPluginBase_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxPluginBase::wxPluginBase(wxPluginBase const & param0)
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_wxPluginBase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPluginBase, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_wxPluginBase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPluginBase > param0_smtptr;
  if (!get_val_smtptr_param<wxPluginBase >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxPluginBase const & param0 = *param0_smtptr;

  wxPluginBase* _newobj = new wxPluginBase(param0);
  BasicVariable::ptr res = WrapClass_wxPluginBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxPluginBase::wxPluginBase(...)
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_wxPluginBase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_wxPluginBase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPluginBase::wrap_wxPluginBase_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPluginBase::wrap_wxPluginBase_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPluginBase::wxPluginBase()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_wxPluginBase_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_wxPluginBase_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPluginBase* _newobj = new wxPluginBase();
  BasicVariable::ptr res = WrapClass_wxPluginBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxPluginBase.
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxPluginBase object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxPluginBase >::CreateVar( new wxPluginBase(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxString wxPluginBase::GetName()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_GetName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_GetName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxPluginBase::GetDescription()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_GetDescription::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_GetDescription::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetDescription();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxPluginBase::GetVersion()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_GetVersion::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_GetVersion::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetVersion();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxPluginBase::GetAuthor()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_GetAuthor::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_GetAuthor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetAuthor();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxPluginBase::SetName(wxString const & Name)
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_SetName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'Name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_SetName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > Name_smtptr;
  if (!get_val_smtptr_param<wxString >(Name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & Name = *Name_smtptr;

  this->_objectptr->GetObj()->SetName(Name);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPluginBase::SetDescription(wxString const & Description)
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_SetDescription::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'Description'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_SetDescription::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > Description_smtptr;
  if (!get_val_smtptr_param<wxString >(Description_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & Description = *Description_smtptr;

  this->_objectptr->GetObj()->SetDescription(Description);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPluginBase::SetVersion(wxString const & Version)
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_SetVersion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'Version'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_SetVersion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > Version_smtptr;
  if (!get_val_smtptr_param<wxString >(Version_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & Version = *Version_smtptr;

  this->_objectptr->GetObj()->SetVersion(Version);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPluginBase::SetAuthor(wxString const & Author)
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_SetAuthor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'Author'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_SetAuthor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > Author_smtptr;
  if (!get_val_smtptr_param<wxString >(Author_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & Author = *Author_smtptr;

  this->_objectptr->GetObj()->SetAuthor(Author);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxPluginBase::GetwxWindow()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_GetwxWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_GetwxWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetwxWindow();
  BasicVariable::ptr res_var = AMILabType<wxWindow >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxPluginBase::SetwxWindow(wxWindow * Parent)
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_SetwxWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'Parent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_SetwxWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindow* Parent;
  if (CheckNullVar(_p,_n))  {
    Parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > Parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(Parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    Parent = Parent_smtptr.get();
  }

  this->_objectptr->GetObj()->SetwxWindow(Parent);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPluginBase::SetConsoleMode()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_SetConsoleMode::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_SetConsoleMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetConsoleMode();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPluginBase::SetGraphicMode()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_SetGraphicMode::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_SetGraphicMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetGraphicMode();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxPluginBase::IsConsoleMode()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_IsConsoleMode::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_IsConsoleMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsConsoleMode();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPluginBase::IsGraphicMode()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_IsGraphicMode::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_IsGraphicMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsGraphicMode();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPluginBase::Execute()
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap_Execute::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap_Execute::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Execute();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPluginBase & wxPluginBase::operator =(wxPluginBase const & param0)
//---------------------------------------------------
void WrapClass_wxPluginBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPluginBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxPluginBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPluginBase > param0_smtptr;
  if (!get_val_smtptr_param<wxPluginBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPluginBase const & param0 = *param0_smtptr;

  wxPluginBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxPluginBase >::CreateVar(res);
}

