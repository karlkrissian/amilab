/**
 * C++ Interface: wrap_wxBitmapButton
 *
 * Description: wrapping wxBitmapButton
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
#include "wrap_wxBitmap.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxValidator.h"
#include "wrap_wxString.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxBitmapButton.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBitmapButton>::CreateVar( ParamList* p)
{
  WrapClass_wxBitmapButton::wrap_wxBitmapButton construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxBitmapButton);
AMI_DEFINE_VARFROMSMTPTR(wxBitmapButton);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxBitmapButton>::CreateVar( wxBitmapButton* val, bool nodeleter)
{ 
  boost::shared_ptr<wxBitmapButton> obj_ptr(val,smartpointer_nodeleter<wxBitmapButton>());
  return AMILabType<wxBitmapButton>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBitmapButton
//
Variable<AMIObject>::ptr WrapClass_wxBitmapButton::CreateVar( wxBitmapButton* sp)
{
  boost::shared_ptr<wxBitmapButton> di_ptr(
    sp,
    wxwindow_nodeleter<wxBitmapButton>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBitmapButton>::CreateVar(
      new WrapClass_wxBitmapButton(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBitmapButton::AddMethods(WrapClass<wxBitmapButton>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_Create( this_ptr);
      AddVar_SetLabel_1( this_ptr);
      AddVar_SetLabel( this_ptr);
      AddVar_SetLabel_2( this_ptr);
      AddVar_SetDefault( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_HasFocus( this_ptr);
      AddVar_NotFocus( this_ptr);
      AddVar_StartSelect( this_ptr);
      AddVar_EndSelect( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* Can't get address of a bit field
      // Adding public member m_hasFocus
      boost::shared_ptr<bool > var_m_hasFocus_ptr(&GetObj()->m_hasFocus, smartpointer_nodeleter<bool >());
      if (var_m_hasFocus_ptr.get()) {
        BasicVariable::ptr var_m_hasFocus = AMILabType<bool >::CreateVarFromSmtPtr(var_m_hasFocus_ptr);
        if (var_m_hasFocus.get()) {
          var_m_hasFocus->Rename("m_hasFocus");
          context->AddVar(var_m_hasFocus,context);
        }
      }
      */
      
      /* Can't get address of a bit field
      // Adding public member m_isSelected
      boost::shared_ptr<bool > var_m_isSelected_ptr(&GetObj()->m_isSelected, smartpointer_nodeleter<bool >());
      if (var_m_isSelected_ptr.get()) {
        BasicVariable::ptr var_m_isSelected = AMILabType<bool >::CreateVarFromSmtPtr(var_m_isSelected_ptr);
        if (var_m_isSelected.get()) {
          var_m_isSelected->Rename("m_isSelected");
          context->AddVar(var_m_isSelected,context);
        }
      }
      */


  // Adding Bases

  // Add base parent wxBitmapButtonBase
  boost::shared_ptr<wxBitmapButtonBase > parent_wxBitmapButtonBase(  boost::dynamic_pointer_cast<wxBitmapButtonBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxBitmapButtonBase = AMILabType<wxBitmapButtonBase >::CreateVarFromSmtPtr(parent_wxBitmapButtonBase);
  context->AddVar("wxBitmapButtonBase",var_wxBitmapButtonBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxBitmapButtonBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxBitmapButtonBase);
  context->AddDefault(obj_wxBitmapButtonBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxBitmapButton::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxBitmapButton");
    WrapClass_wxBitmapButton::AddVar_wxBitmapButton_1(amiobject->GetContext());
  WrapClass_wxBitmapButton::AddVar_wxBitmapButton(amiobject->GetContext());
  WrapClass_wxBitmapButton::AddVar_wxBitmapButton_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxBitmapButton::wxBitmapButton()
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_wxBitmapButton_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_wxBitmapButton_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmapButton* _newobj = new wxBitmapButton();
  BasicVariable::ptr res = WrapClass_wxBitmapButton::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxBitmapButton::wxBitmapButton(...)
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_wxBitmapButton::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_wxBitmapButton::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapButton::wrap_wxBitmapButton_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapButton::wrap_wxBitmapButton_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBitmapButton::wxBitmapButton(wxWindow * parent, wxWindowID id, wxBitmap const & bitmap, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 4, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr)
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_wxBitmapButton_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:4)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxButtonNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_wxBitmapButton_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>8) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 4;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxValidator const & validator = ( validator_smtptr.get() ? (*validator_smtptr) : wxDefaultValidator );

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxButtonNameStr) );

  wxBitmapButton* _newobj = new wxBitmapButton(parent, id, bitmap, pos, size, style, validator, name);
  BasicVariable::ptr res = WrapClass_wxBitmapButton::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxBitmapButton::Create(wxWindow * parent, wxWindowID id, wxBitmap const & bitmap, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 4, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr)
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:4)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxButtonNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>8) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 4;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxValidator const & validator = ( validator_smtptr.get() ? (*validator_smtptr) : wxDefaultValidator );

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxButtonNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, bitmap, pos, size, style, validator, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButton::SetLabel(wxString const & label)
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_SetLabel_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_SetLabel_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetLabel(label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxBitmapButton::SetLabel(...)
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_SetLabel::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapButton::wrap_SetLabel_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapButton::wrap_SetLabel_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButton::SetLabel(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_SetLabel_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_SetLabel_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetLabel(bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButton::SetDefault()
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_SetDefault::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_SetDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDefault();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxBitmapButton::Enable(bool enable = 1)
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'enable' (def:1)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool enable = 1;
  if (!get_val_param<bool >(enable,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Enable(enable);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButton::HasFocus()
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_HasFocus::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_HasFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HasFocus();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButton::NotFocus()
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_NotFocus::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_NotFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->NotFocus();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButton::StartSelect()
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_StartSelect::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_StartSelect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartSelect();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapButton::EndSelect()
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_EndSelect::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_EndSelect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndSelect();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxBitmapButton::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

