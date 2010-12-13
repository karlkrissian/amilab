/**
 * C++ Interface: wrap_wxDialog
 *
 * Description: wrapping wxDialog
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

#include "wrap_wxDialog.h"

// get all the required includes
// #include "..."
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
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
BasicVariable::ptr WrapClass<wxDialog>::CreateVar( ParamList* p)
{
  WrapClass_wxDialog::wrap_wxDialog construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxDialog);
AMI_DEFINE_VARFROMSMTPTR(wxDialog);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxDialog>::CreateVar( wxDialog* val, bool nodeleter)
{ 
  boost::shared_ptr<wxDialog> obj_ptr(val,smartpointer_nodeleter<wxDialog>());
  return AMILabType<wxDialog>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDialog
//
Variable<AMIObject>::ptr WrapClass_wxDialog::CreateVar( wxDialog* sp)
{
  boost::shared_ptr<wxDialog> di_ptr(
    sp,
    wxwindow_nodeleter<wxDialog>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDialog>::CreateVar(
      new WrapClass_wxDialog(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDialog::AddMethods(WrapClass<wxDialog>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Create( this_ptr);
  AddVar_Show( this_ptr);
  AddVar_ShowModal( this_ptr);
  AddVar_EndModal( this_ptr);
  AddVar_IsModal( this_ptr);
  AddVar_SetModal( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());
  
  // Adding public member m_modalShowing
  boost::shared_ptr<bool > var_m_modalShowing_ptr(&GetObj()->m_modalShowing, smartpointer_nodeleter<bool >());
  if (var_m_modalShowing_ptr.get()) {
    BasicVariable::ptr var_m_modalShowing = AMILabType<bool >::CreateVarFromSmtPtr(var_m_modalShowing_ptr);
    if (var_m_modalShowing.get()) {
      var_m_modalShowing->Rename("m_modalShowing");
      context->AddVar(var_m_modalShowing,context);
    }
  }


  


  // Adding Bases

  // Add base parent wxDialogBase
  boost::shared_ptr<wxDialogBase > parent_wxDialogBase(  boost::dynamic_pointer_cast<wxDialogBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxDialogBase = AMILabType<wxDialogBase >::CreateVarFromSmtPtr(parent_wxDialogBase);
  context->AddVar("wxDialogBase",var_wxDialogBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxDialogBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxDialogBase);
  context->AddDefault(obj_wxDialogBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDialog_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxDialog");
    WrapClass_wxDialog::AddVar_wxDialog_1(amiobject->GetContext());
  WrapClass_wxDialog::AddVar_wxDialog(amiobject->GetContext());
  WrapClass_wxDialog::AddVar_wxDialog_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxDialog::wxDialog()
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_wxDialog_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_wxDialog_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxDialog* _newobj = new wxDialog();
  BasicVariable::ptr res = WrapClass_wxDialog::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxDialog::wxDialog(...)
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_wxDialog::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_wxDialog::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDialog::wrap_wxDialog_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDialog::wrap_wxDialog_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDialog::wxDialog(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 536877056, wxString const & name = wxDialogNameStr)
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_wxDialog_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:536877056)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxDialogNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_wxDialog_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    parent = parent_smtptr.get();
  }

  int id;
  if (!get_val_param<int >(id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 536877056;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxDialogNameStr) );

  wxDialog* _newobj = new wxDialog(parent, id, title, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxDialog::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxDialog::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 536877056, wxString const & name = wxDialogNameStr)
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:536877056)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxDialogNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    parent = parent_smtptr.get();
  }

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 536877056;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxDialogNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, title, pos, size, style, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDialog::Show(bool show = 1)
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_Show::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'show' (def:1)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_Show::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool show = 1;
  if (!get_val_param<bool >(show,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Show(show);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxDialog::ShowModal()
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_ShowModal::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_ShowModal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->ShowModal();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDialog::EndModal(int retCode)
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_EndModal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'retCode'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_EndModal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int retCode;
  if (!get_val_param<int >(retCode,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndModal(retCode);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxDialog::IsModal()
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_IsModal::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_IsModal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsModal();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxDialog::SetModal(bool modal)
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_SetModal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'modal'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_SetModal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool modal;
  if (!get_val_param<bool >(modal,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetModal(modal);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxDialog::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxDialog::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDialog::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

