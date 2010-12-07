/**
 * C++ Interface: wrap_wxToolBarToolBase
 *
 * Description: wrapping wxToolBarToolBase
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
#include "wrap_wxToolBarBase.h"
#include "wrap_wxString.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxObject.h"
#include "wrap_wxControl.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxToolBarToolBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxToolBarToolBase>::CreateVar( ParamList* p)
{
  WrapClass_wxToolBarToolBase::wrap_wxToolBarToolBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxToolBarToolBase);
AMI_DEFINE_VARFROMSMTPTR(wxToolBarToolBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxToolBarToolBase>::CreateVar( wxToolBarToolBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxToolBarToolBase> obj_ptr(val,smartpointer_nodeleter<wxToolBarToolBase>());
  return AMILabType<wxToolBarToolBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxToolBarToolBase
//
Variable<AMIObject>::ptr WrapClass_wxToolBarToolBase::CreateVar( wxToolBarToolBase* sp)
{
  boost::shared_ptr<wxToolBarToolBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxToolBarToolBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxToolBarToolBase>::CreateVar(
      new WrapClass_wxToolBarToolBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxToolBarToolBase::AddMethods(WrapClass<wxToolBarToolBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_GetId( this_ptr);
      AddVar_GetControl( this_ptr);
      AddVar_GetToolBar( this_ptr);
      AddVar_IsButton( this_ptr);
      AddVar_IsControl( this_ptr);
      AddVar_IsSeparator( this_ptr);
      AddVar_GetStyle( this_ptr);
      AddVar_GetKind( this_ptr);
      AddVar_IsEnabled( this_ptr);
      AddVar_IsToggled( this_ptr);
      AddVar_CanBeToggled( this_ptr);
      AddVar_GetNormalBitmap( this_ptr);
      AddVar_GetDisabledBitmap( this_ptr);
      AddVar_GetBitmap( this_ptr);
      AddVar_GetLabel( this_ptr);
      AddVar_GetShortHelp( this_ptr);
      AddVar_GetLongHelp( this_ptr);
      AddVar_GetClientData( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_Toggle_1( this_ptr);
      AddVar_SetToggle( this_ptr);
      AddVar_SetShortHelp( this_ptr);
      AddVar_SetLongHelp( this_ptr);
      AddVar_Toggle( this_ptr);
      AddVar_Toggle_2( this_ptr);
      AddVar_SetNormalBitmap( this_ptr);
      AddVar_SetDisabledBitmap( this_ptr);
      AddVar_SetLabel( this_ptr);
      AddVar_SetClientData( this_ptr);
      AddVar_Detach( this_ptr);
      AddVar_Attach( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxObject
  boost::shared_ptr<wxObject > parent_wxObject(  boost::dynamic_pointer_cast<wxObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxObject = AMILabType<wxObject >::CreateVarFromSmtPtr(parent_wxObject);
  context->AddVar("wxObject",var_wxObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxObject);
  context->AddDefault(obj_wxObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxToolBarToolBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxToolBarToolBase");
    WrapClass_wxToolBarToolBase::AddVar_wxToolBarToolBase_1(amiobject->GetContext());
  WrapClass_wxToolBarToolBase::AddVar_wxToolBarToolBase(amiobject->GetContext());
  WrapClass_wxToolBarToolBase::AddVar_wxToolBarToolBase_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxToolBarToolBase::wxToolBarToolBase(wxToolBarBase * tbar = 0u, int toolid = wxID_SEPARATOR, wxString const & label = wxEmptyString, wxBitmap const & bmpNormal = wxNullBitmap, wxBitmap const & bmpDisabled = wxNullBitmap, wxItemKind kind = wxITEM_NORMAL, wxObject * clientData = 0u, wxString const & shortHelpString = wxEmptyString, wxString const & longHelpString = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_wxToolBarToolBase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxToolBarBase, "parameter named 'tbar' (def:0u)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid' (def:wxID_SEPARATOR)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpNormal' (def:wxNullBitmap)")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpDisabled' (def:wxNullBitmap)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'kind' (def:wxITEM_NORMAL)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'clientData' (def:0u)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelpString' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'longHelpString' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_wxToolBarToolBase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>9) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxToolBarBase > tbar_smtptr;
  if (!get_val_smtptr_param<wxToolBarBase >(tbar_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxToolBarBase* tbar = tbar_smtptr.get();

  int toolid = wxID_SEPARATOR;
  if (!get_val_param<int >(toolid,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & label = ( label_smtptr.get() ? (*label_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxBitmap > bmpNormal_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpNormal_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxBitmap const & bmpNormal = ( bmpNormal_smtptr.get() ? (*bmpNormal_smtptr) : wxNullBitmap );

  boost::shared_ptr<wxBitmap > bmpDisabled_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpDisabled_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxBitmap const & bmpDisabled = ( bmpDisabled_smtptr.get() ? (*bmpDisabled_smtptr) : wxNullBitmap );

  int kind_int = (int) wxITEM_NORMAL;;
  if (!get_val_param<int >(kind_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxItemKind kind = (wxItemKind) kind_int;

  boost::shared_ptr<wxObject > clientData_smtptr;
  if (!get_val_smtptr_param<wxObject >(clientData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxObject* clientData = clientData_smtptr.get();

  boost::shared_ptr<wxString > shortHelpString_smtptr;
  if (!get_val_smtptr_param<wxString >(shortHelpString_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & shortHelpString = ( shortHelpString_smtptr.get() ? (*shortHelpString_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > longHelpString_smtptr;
  if (!get_val_smtptr_param<wxString >(longHelpString_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & longHelpString = ( longHelpString_smtptr.get() ? (*longHelpString_smtptr) : wxString(wxEmptyString) );

  wxToolBarToolBase* _newobj = new wxToolBarToolBase(tbar, toolid, label, bmpNormal, bmpDisabled, kind, clientData, shortHelpString, longHelpString);
  BasicVariable::ptr res = WrapClass_wxToolBarToolBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxToolBarToolBase::wxToolBarToolBase(...)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_wxToolBarToolBase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_wxToolBarToolBase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxToolBarToolBase::wrap_wxToolBarToolBase_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxToolBarToolBase::wrap_wxToolBarToolBase_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxToolBarToolBase::wxToolBarToolBase(wxToolBarBase * tbar, wxControl * control)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_wxToolBarToolBase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxToolBarBase, "parameter named 'tbar'")
  ADDPARAMCOMMENT_TYPE( wxControl, "parameter named 'control'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_wxToolBarToolBase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxToolBarBase > tbar_smtptr;
  if (!get_val_smtptr_param<wxToolBarBase >(tbar_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxToolBarBase* tbar = tbar_smtptr.get();

  boost::shared_ptr<wxControl > control_smtptr;
  if (!get_val_smtptr_param<wxControl >(control_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxControl* control = control_smtptr.get();

  wxToolBarToolBase* _newobj = new wxToolBarToolBase(tbar, control);
  BasicVariable::ptr res = WrapClass_wxToolBarToolBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of int wxToolBarToolBase::GetId()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetId::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetId();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxControl * wxToolBarToolBase::GetControl()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetControl::SetParametersComments()
{
  return_comments="returning a variable of type wxControl";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetControl::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxControl * res =   this->_objectptr->GetObj()->GetControl();
  BasicVariable::ptr res_var = WrapClass_wxControl::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarBase * wxToolBarToolBase::GetToolBar()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetToolBar::SetParametersComments()
{
  return_comments="returning a variable of type wxToolBarBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetToolBar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxToolBarBase * res =   this->_objectptr->GetObj()->GetToolBar();
  BasicVariable::ptr res_var = WrapClass_wxToolBarBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::IsButton()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_IsButton::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_IsButton::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsButton();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::IsControl()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_IsControl::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_IsControl::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsControl();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::IsSeparator()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_IsSeparator::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_IsSeparator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSeparator();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxToolBarToolBase::GetStyle()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetStyle::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStyle();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxItemKind wxToolBarToolBase::GetKind()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetKind::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetKind::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxItemKind res =   this->_objectptr->GetObj()->GetKind();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::IsEnabled()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_IsEnabled::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_IsEnabled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEnabled();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::IsToggled()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_IsToggled::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_IsToggled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsToggled();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::CanBeToggled()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_CanBeToggled::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_CanBeToggled::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->CanBeToggled();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxToolBarToolBase::GetNormalBitmap()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetNormalBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetNormalBitmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetNormalBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxToolBarToolBase::GetDisabledBitmap()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetDisabledBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetDisabledBitmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetDisabledBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap const & wxToolBarToolBase::GetBitmap()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetBitmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap const & res =   this->_objectptr->GetObj()->GetBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxToolBarToolBase::GetLabel()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetLabel::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetLabel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetLabel();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxToolBarToolBase::GetShortHelp()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetShortHelp::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetShortHelp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetShortHelp();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxToolBarToolBase::GetLongHelp()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetLongHelp::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetLongHelp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetLongHelp();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxObject * wxToolBarToolBase::GetClientData()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetClientData::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetClientData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObject * res =   this->_objectptr->GetObj()->GetClientData();
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::Enable(bool enable)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'enable'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool enable;
  if (!get_val_param<bool >(enable,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Enable(enable);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::Toggle(bool toggle)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_Toggle_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'toggle'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_Toggle_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  bool toggle;
  if (!get_val_param<bool >(toggle,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Toggle(toggle);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::SetToggle(bool toggle)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_SetToggle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'toggle'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_SetToggle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool toggle;
  if (!get_val_param<bool >(toggle,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->SetToggle(toggle);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::SetShortHelp(wxString const & help)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_SetShortHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_SetShortHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & help = *help_smtptr;

  bool res =   this->_objectptr->GetObj()->SetShortHelp(help);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarToolBase::SetLongHelp(wxString const & help)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_SetLongHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_SetLongHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > help_smtptr;
  if (!get_val_smtptr_param<wxString >(help_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & help = *help_smtptr;

  bool res =   this->_objectptr->GetObj()->SetLongHelp(help);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxToolBarToolBase::Toggle(...)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_Toggle::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_Toggle::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxToolBarToolBase::wrap_Toggle_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxToolBarToolBase::wrap_Toggle_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxToolBarToolBase::Toggle()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_Toggle_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_Toggle_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Toggle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarToolBase::SetNormalBitmap(wxBitmap const & bmp)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_SetNormalBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_SetNormalBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bmp = *bmp_smtptr;

  this->_objectptr->GetObj()->SetNormalBitmap(bmp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarToolBase::SetDisabledBitmap(wxBitmap const & bmp)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_SetDisabledBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_SetDisabledBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bmp = *bmp_smtptr;

  this->_objectptr->GetObj()->SetDisabledBitmap(bmp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarToolBase::SetLabel(wxString const & label)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetLabel(label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarToolBase::SetClientData(wxObject * clientData)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_SetClientData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'clientData'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_SetClientData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > clientData_smtptr;
  if (!get_val_smtptr_param<wxObject >(clientData_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxObject* clientData = clientData_smtptr.get();

  this->_objectptr->GetObj()->SetClientData(clientData);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarToolBase::Detach()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_Detach::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_Detach::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Detach();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarToolBase::Attach(wxToolBarBase * tbar)
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_Attach::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxToolBarBase, "parameter named 'tbar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_Attach::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxToolBarBase > tbar_smtptr;
  if (!get_val_smtptr_param<wxToolBarBase >(tbar_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxToolBarBase* tbar = tbar_smtptr.get();

  this->_objectptr->GetObj()->Attach(tbar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxToolBarToolBase::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxToolBarToolBase::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarToolBase::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

