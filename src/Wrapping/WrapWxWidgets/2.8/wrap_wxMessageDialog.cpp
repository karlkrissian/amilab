/**
 * C++ Interface: wrap_wxMessageDialog
 *
 * Description: wrapping wxMessageDialog
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

#include "wrap_wxMessageDialog.h"

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
BasicVariable::ptr WrapClass<wxMessageDialog>::CreateVar( ParamList* p)
{
  WrapClass_wxMessageDialog::wrap_wxMessageDialog construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxMessageDialog);
AMI_DEFINE_VARFROMSMTPTR(wxMessageDialog);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxMessageDialog>::CreateVar( wxMessageDialog* val, bool nodeleter)
{ 
  boost::shared_ptr<wxMessageDialog> obj_ptr(val,smartpointer_nodeleter<wxMessageDialog>());
  return AMILabType<wxMessageDialog>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMessageDialog
//
Variable<AMIObject>::ptr WrapClass_wxMessageDialog::CreateVar( wxMessageDialog* sp)
{
  boost::shared_ptr<wxMessageDialog> di_ptr(
    sp,
    wxwindow_nodeleter<wxMessageDialog>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMessageDialog>::CreateVar(
      new WrapClass_wxMessageDialog(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMessageDialog::AddMethods(WrapClass<wxMessageDialog>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_ShowModal( this_ptr);
  AddVar_Show( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxDialog
  boost::shared_ptr<wxDialog > parent_wxDialog(  boost::dynamic_pointer_cast<wxDialog >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxDialog = AMILabType<wxDialog >::CreateVarFromSmtPtr(parent_wxDialog);
  context->AddVar("wxDialog",var_wxDialog);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxDialog = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxDialog);
  context->AddDefault(obj_wxDialog->Pointer()->GetContext());

  // Add base parent wxMessageDialogBase
  boost::shared_ptr<wxMessageDialogBase > parent_wxMessageDialogBase(  boost::dynamic_pointer_cast<wxMessageDialogBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxMessageDialogBase = AMILabType<wxMessageDialogBase >::CreateVarFromSmtPtr(parent_wxMessageDialogBase);
  context->AddVar("wxMessageDialogBase",var_wxMessageDialogBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxMessageDialogBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxMessageDialogBase);
  context->AddDefault(obj_wxMessageDialogBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxMessageDialog_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxMessageDialog");
    WrapClass_wxMessageDialog::AddVar_wxMessageDialog(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMessageDialog::wxMessageDialog(wxWindow * parent, wxString const & message, wxString const & caption = wxMessageBoxCaptionStr, long int style = 5, wxPoint const & pos = wxDefaultPosition)
//---------------------------------------------------
void WrapClass_wxMessageDialog::
    wrap_wxMessageDialog::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'message'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'caption' (def:wxMessageBoxCaptionStr)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:5)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMessageDialog::
    wrap_wxMessageDialog::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
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

  boost::shared_ptr<wxString > message_smtptr;
  if (!get_val_smtptr_param<wxString >(message_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & message = *message_smtptr;

  boost::shared_ptr<wxString > caption_smtptr;
  if (!get_val_smtptr_param<wxString >(caption_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & caption = ( caption_smtptr.get() ? (*caption_smtptr) : wxString(wxMessageBoxCaptionStr) );

  long style_long = 5;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  wxMessageDialog* _newobj = new wxMessageDialog(parent, message, caption, style, pos);
  BasicVariable::ptr res = WrapClass_wxMessageDialog::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of int wxMessageDialog::ShowModal()
//---------------------------------------------------
void WrapClass_wxMessageDialog::
    wrap_ShowModal::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMessageDialog::
    wrap_ShowModal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->ShowModal();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMessageDialog::Show(bool param0 = true)
//---------------------------------------------------
void WrapClass_wxMessageDialog::
    wrap_Show::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'param0' (def:true)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMessageDialog::
    wrap_Show::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool param0 = true;
  if (!get_val_param<bool >(param0,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Show(param0);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxMessageDialog::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxMessageDialog::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMessageDialog::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

