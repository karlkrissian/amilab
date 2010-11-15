/**
 * C++ Interface: wrap_wxControlBase
 *
 * Description: wrapping wxControlBase
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
#include "wrap_wxString.h"
#include "wrap_wxFont.h"


#include "wrap_wxControlBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxControlBase>::CreateVar( ParamList* p)
{
  WrapClass_wxControlBase::wrap_wxControlBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxControlBase);
AMI_DEFINE_VARFROMSMTPTR(wxControlBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxControlBase>::CreateVar( wxControlBase* val)
{ 
  boost::shared_ptr<wxControlBase> obj_ptr(val,wxwindow_nodeleter<wxControlBase>());
  return AMILabType<wxControlBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxControlBase
//
Variable<AMIObject>::ptr WrapClass_wxControlBase::CreateVar( wxControlBase* sp)
{
  boost::shared_ptr<wxControlBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxControlBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxControlBase>::CreateVar(
      new WrapClass_wxControlBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxControlBase::AddMethods(WrapClass<wxControlBase>::ptr this_ptr )
{
  
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_wxWindow(        boost::dynamic_pointer_cast<WrapClass_wxWindow >(this_ptr));
      parent_wxWindow->AddMethods(parent_wxWindow);


  // check that the method name is not a token
  
      // Adding standard methods 
/* The following types are missing: wxValidator
      AddVar_Create( this_ptr);
*/
      AddVar_GetAlignment( this_ptr);
      AddVar_GetLabelText_1( this_ptr);
      AddVar_GetLabelText( this_ptr);
      AddVar_GetLabelText_2( this_ptr);
      AddVar_ShouldInheritColours( this_ptr);
/* The following types are missing: wxCommandEvent
      AddVar_Command( this_ptr);
*/
      AddVar_SetLabel( this_ptr);
      AddVar_SetFont( this_ptr);
/* The following types are missing: wxUpdateUIEvent
      AddVar_DoUpdateWindowUI( this_ptr);
*/



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxControlBase::wxControlBase()
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_wxControlBase::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_wxControlBase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxControlBase* _newobj = new wxControlBase();
  BasicVariable::ptr res = WrapClass_wxControlBase::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of bool wxControlBase::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxControlNameStr)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxControlNameStr)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = (pos_smtptr.get()?
    (wxPoint const &) (*pos_smtptr):
    (wxPoint const &) wxDefaultPosition);

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = (size_smtptr.get()?
    (wxSize const &) (*size_smtptr):
    (wxSize const &) wxDefaultSize);

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxValidator const & validator = (validator_smtptr.get()?
    (wxValidator const &) (*validator_smtptr):
    (wxValidator const &) wxDefaultValidator);

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = (name_smtptr.get()?
    (wxString const &) (*name_smtptr):
    (wxString const &) wxControlNameStr);

  bool res =   this->_objectptr->GetObj()->Create(parent, id, pos, size, style, validator, name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of int wxControlBase::GetAlignment()
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_GetAlignment::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_GetAlignment::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAlignment();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxControlBase::GetLabelText(wxString const & label)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_GetLabelText_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_GetLabelText_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  wxString res =   this->_objectptr->GetObj()->GetLabelText(label);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxControlBase::GetLabelText(...)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_GetLabelText::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_GetLabelText::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxControlBase::wrap_GetLabelText_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxControlBase::wrap_GetLabelText_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString wxControlBase::GetLabelText()
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_GetLabelText_2::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_GetLabelText_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxString res =   this->_objectptr->GetObj()->GetLabelText();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxControlBase::ShouldInheritColours()
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_ShouldInheritColours::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_ShouldInheritColours::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShouldInheritColours();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: wxCommandEvent

//---------------------------------------------------
//  Wrapping of void wxControlBase::Command(wxCommandEvent & event)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_Command::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCommandEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_Command::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxCommandEvent > event_smtptr;
  if (!get_val_smtptr_param<wxCommandEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxCommandEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->Command(event);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxControlBase::SetLabel(wxString const & label)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetLabel(label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxControlBase::SetFont(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_SetFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_SetFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  bool res =   this->_objectptr->GetObj()->SetFont(font);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: wxUpdateUIEvent

//---------------------------------------------------
//  Wrapping of void wxControlBase::DoUpdateWindowUI(wxUpdateUIEvent & event)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_DoUpdateWindowUI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUpdateUIEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_DoUpdateWindowUI::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxUpdateUIEvent > event_smtptr;
  if (!get_val_smtptr_param<wxUpdateUIEvent >(event_smtptr,_p,_n)) ClassHelpAndReturn;
  wxUpdateUIEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->DoUpdateWindowUI(event);
  return BasicVariable::ptr();
}
*/

