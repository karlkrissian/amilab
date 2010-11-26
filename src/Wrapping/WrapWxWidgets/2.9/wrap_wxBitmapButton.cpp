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
BasicVariable::ptr AMILabType<wxBitmapButton>::CreateVar( wxBitmapButton* val)
{ 
  boost::shared_ptr<wxBitmapButton> obj_ptr(val,wxwindow_nodeleter<wxBitmapButton>());
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
  
      // Add members from wxBitmapButtonBase
      WrapClass_wxBitmapButtonBase::ptr parent_wxBitmapButtonBase(        boost::dynamic_pointer_cast<WrapClass_wxBitmapButtonBase >(this_ptr));
      parent_wxBitmapButtonBase->AddMethods(parent_wxBitmapButtonBase);


  // check that the method name is not a token
  
      // Adding standard methods 
/* The following types are missing: wxValidator
      AddVar_Create( this_ptr);
*/
      AddVar_GetClassInfo( this_ptr);



  
};

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
  ClassHelpAndReturn;
}
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of Constructor wxBitmapButton::wxBitmapButton(wxWindow * parent, wxWindowID id, wxBitmap const & bitmap, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr)
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_wxBitmapButton_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
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
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : (wxDefaultPosition) );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : (wxDefaultSize) );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxValidator const & validator = ( validator_smtptr.get() ? (*validator_smtptr) : (wxDefaultValidator) );

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : (wxButtonNameStr) );

  wxBitmapButton* _newobj = new wxBitmapButton(parent, id, bitmap, pos, size, style, validator, name);
  BasicVariable::ptr res = WrapClass_wxBitmapButton::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of bool wxBitmapButton::Create(wxWindow * parent, wxWindowID id, wxBitmap const & bitmap, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr)
//---------------------------------------------------
void WrapClass_wxBitmapButton::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxButtonNameStr)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapButton::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>8) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : (wxDefaultPosition) );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : (wxDefaultSize) );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxValidator const & validator = ( validator_smtptr.get() ? (*validator_smtptr) : (wxDefaultValidator) );

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : (wxButtonNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, bitmap, pos, size, style, validator, name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

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

