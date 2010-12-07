/**
 * C++ Interface: wrap_wxControl
 *
 * Description: wrapping wxControl
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
#include "wrap_wxWindow.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxValidator.h"
#include "wrap_wxString.h"
#include "wrap_wxVisualAttributes.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxControl.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxControl>::CreateVar( ParamList* p)
{
  WrapClass_wxControl::wrap_wxControl construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxControl);
AMI_DEFINE_VARFROMSMTPTR(wxControl);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxControl>::CreateVar( wxControl* val, bool nodeleter)
{ 
  boost::shared_ptr<wxControl> obj_ptr(val,smartpointer_nodeleter<wxControl>());
  return AMILabType<wxControl>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxControl
//
Variable<AMIObject>::ptr WrapClass_wxControl::CreateVar( wxControl* sp)
{
  boost::shared_ptr<wxControl> di_ptr(
    sp,
    wxwindow_nodeleter<wxControl>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxControl>::CreateVar(
      new WrapClass_wxControl(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxControl::AddMethods(WrapClass<wxControl>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_Create( this_ptr);
      AddVar_SetLabel( this_ptr);
      AddVar_GetLabel( this_ptr);
      AddVar_GetDefaultAttributes( this_ptr);
      AddVar_OnInternalIdle( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxControlBase
  boost::shared_ptr<wxControlBase > parent_wxControlBase(  boost::dynamic_pointer_cast<wxControlBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxControlBase = AMILabType<wxControlBase >::CreateVarFromSmtPtr(parent_wxControlBase);
  context->AddVar("wxControlBase",var_wxControlBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxControlBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxControlBase);
  context->AddDefault(obj_wxControlBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxControl::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxControl");
    WrapClass_wxControl::AddVar_wxControl_1(amiobject->GetContext());
  WrapClass_wxControl::AddVar_wxControl(amiobject->GetContext());
  WrapClass_wxControl::AddVar_wxControl_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxControl::wxControl()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_wxControl_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_wxControl_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxControl* _newobj = new wxControl();
  BasicVariable::ptr res = WrapClass_wxControl::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxControl::wxControl(...)
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_wxControl::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_wxControl::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxControl::wrap_wxControl_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxControl::wrap_wxControl_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxControl::wxControl(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxControlNameStr)
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_wxControl_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxControlNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_wxControl_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxValidator const & validator = ( validator_smtptr.get() ? (*validator_smtptr) : wxDefaultValidator );

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxControlNameStr) );

  wxControl* _newobj = new wxControl(parent, id, pos, size, style, validator, name);
  BasicVariable::ptr res = WrapClass_wxControl::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxControl::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxControlNameStr)
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxControlNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxValidator const & validator = ( validator_smtptr.get() ? (*validator_smtptr) : wxDefaultValidator );

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxControlNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, pos, size, style, validator, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxControl::SetLabel(wxString const & label)
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
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
//  Wrapping of wxString wxControl::GetLabel()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_GetLabel::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_GetLabel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetLabel();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxVisualAttributes wxControl::GetDefaultAttributes()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_GetDefaultAttributes::SetParametersComments()
{
  return_comments="returning a variable of type wxVisualAttributes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_GetDefaultAttributes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxVisualAttributes res =   this->_objectptr->GetObj()->GetDefaultAttributes();
  return AMILabType<wxVisualAttributes >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxControl::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxControl::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

