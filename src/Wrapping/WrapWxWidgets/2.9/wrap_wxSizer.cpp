//
// C++ Implementation: wrap_wxSizer
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "AMILabConfig.h"

#ifdef _AMIPREC_
  #include "WrapWxWidgets_header.h"
#endif

#include "wrap_wxSizer.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

#include "wrap_wxWindow.h"

#include <wx/sizer.h>

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxSizer>::CreateVar( ParamList* p)
{
  WrapClass_wxSizer::wrap_wxSizer construct;
  return construct.CallMember(p);
}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxSizer);
AMI_DEFINE_VARFROMSMTPTR(wxSizer);


///
BasicVariable::ptr AMILabType<wxSizer>::CreateVar( wxSizer* val)  
{ 
  // deletion will be done by wxwidgets
  boost::shared_ptr<wxSizer> obj_ptr(val,wxwindow_nodeleter<wxSizer>());
  return AMILabType<wxSizer>::CreateVarFromSmtPtr(obj_ptr);
} 


//---------------------------------------------------
// Method that adds wrapping of wxSizer
//---------------------------------------------------

void WrapClass_wxSizer::
      wrap_wxSizer::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_wxSizer::CallMember( ParamList* p)
{
  return BasicVariable::ptr();
}



//---------------------------------------------------
//  Add1
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Add1::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxWindow,"Widget to add");
//  ADDPARAMCOMMENT_TYPE(wxSizerFlags, "Flags");
  return_comments="wxSizerItem variable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Add1::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();

/*  int n=0;
  CLASS_GET_OBJET_PARAM(wxWindow,var0,widget);
  if (!widget.get()) ClassHelpAndReturn;
  CLASS_GET_OBJET_PARAM(wxSizerFlags,var1,flags);
  if (!flags.get()) ClassHelpAndReturn;

  wxSizerItem* si = s->Add(widget.get(),*flags);
  RETURN_VAR(wxSizerItem,si);
*/
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Add2
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Add2::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxWindow,"wxWindow to add");
  ADDPARAMCOMMENT_TYPE(int, "Proportion");
  ADDPARAMCOMMENT_TYPE(int, "Flags");
  ADDPARAMCOMMENT_TYPE(int, "Border");
  // TODO: user data
  return_comments="wxSizerItem variable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Add2::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();

  int n=0;
  CLASS_GET_OBJECT_PARAM(wxWindow,var0,widget);
  if (!widget.get()) ClassHelpAndReturn;
  GET_PARAM(int,proportion,0)
  GET_PARAM(int,flags,0)
  GET_PARAM(int,border,0)

  wxSizerItem* si = s->Add(widget.get(),proportion,flags,border);
  RETURN_VAR(wxSizerItem,si);
}

//---------------------------------------------------
//  Add3
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Add3::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Add3::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Add4
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Add4::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Add4::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Add5
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Add5::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Add5::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Add
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Add::SetParametersComments() 
{
  ADDPARAMCOMMENT("First parameter can be either int, wxWindow or wxSizer");
  return_comments="wxSizerItem variable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Add::CallMember( ParamList* p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Add1 m1(this->_objectptr);
  res = m1.CallMember(p);
  if (res.get()) return res;

  WrapClass_wxSizer::wrap_Add2 m2(this->_objectptr);
  res = m2.CallMember(p);
  if (res.get()) return res;

  WrapClass_wxSizer::wrap_Add3 m3(this->_objectptr);
  res = m3.CallMember(p);
  if (res.get()) return res;

  WrapClass_wxSizer::wrap_Add4 m4(this->_objectptr);
  res = m4.CallMember(p);
  if (res.get()) return res;

  WrapClass_wxSizer::wrap_Add5 m5(this->_objectptr);
  res = m5.CallMember(p);
  if (res.get()) return res;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Detach1
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Detach1::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxWindow,"wxWindow to detach");
  return_comments="bool";
}

/*

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Add2::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();

  int n=0;
  CLASS_GET_OBJECT_PARAM(wxWindow,var0,widget);
  if (!widget.get()) ClassHelpAndReturn;
  GET_PARAM(int,proportion,0)
  GET_PARAM(int,flags,0)
  GET_PARAM(int,border,0)

  wxSizerItem* si = s->Add(widget.get(),proportion,flags,border);
  RETURN_VAR(wxSizerItem,si);
*/

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Detach1::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();

  int n=0;
  CLASS_GET_OBJECT_PARAM(wxWindow,var0,widget);

  bool res = s->Detach(widget.get());
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  Detach2
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Detach2::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Detach2::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Detach3
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Detach3::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Detach3::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Detach
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Detach::SetParametersComments() 
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Detach::CallMember( ParamList* p)
{

  BasicVariable::ptr res;
  WrapClass_wxSizer::wrap_Detach1 m1(this->_objectptr);
  res = m1.CallMember(p);
  if (res.get()) return res;

  WrapClass_wxSizer::wrap_Detach2 m2(this->_objectptr);
  res = m2.CallMember(p);
  if (res.get()) return res;

  WrapClass_wxSizer::wrap_Detach3 m3(this->_objectptr);
  res = m3.CallMember(p);
  if (res.get()) return res;

  RETURN_VAR(int,0);
}


//---------------------------------------------------
//  Layout
//---------------------------------------------------
void WrapClass_wxSizer::
      wrap_Layout::SetParametersComments() 
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizer::
      wrap_Layout::CallMember( ParamList* p)
{
  boost::shared_ptr<wxSizer> s = this->_objectptr->GetObj();
  s->Layout();
  return BasicVariable::ptr();
}
