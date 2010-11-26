/**
 * C++ Interface: wrap_wxTopLevelWindow
 *
 * Description: wrapping wxTopLevelWindow
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
#include "wrap_wxString.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxTopLevelWindow.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxTopLevelWindow>::CreateVar( ParamList* p)
{
  WrapClass_wxTopLevelWindow::wrap_wxTopLevelWindow construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxTopLevelWindow);
AMI_DEFINE_VARFROMSMTPTR(wxTopLevelWindow);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxTopLevelWindow>::CreateVar( wxTopLevelWindow* val, bool nodeleter)
{ 
  boost::shared_ptr<wxTopLevelWindow> obj_ptr(val,smartpointer_nodeleter<wxTopLevelWindow>());
  return AMILabType<wxTopLevelWindow>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxTopLevelWindow
//
Variable<AMIObject>::ptr WrapClass_wxTopLevelWindow::CreateVar( wxTopLevelWindow* sp)
{
  boost::shared_ptr<wxTopLevelWindow> di_ptr(
    sp,
    wxwindow_nodeleter<wxTopLevelWindow>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxTopLevelWindow>::CreateVar(
      new WrapClass_wxTopLevelWindow(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxTopLevelWindow::AddMethods(WrapClass<wxTopLevelWindow>::ptr this_ptr )
{
  
      // Add members from wxTopLevelWindowGTK
      WrapClass_wxTopLevelWindowGTK::ptr parent_wxTopLevelWindowGTK(        boost::dynamic_pointer_cast<WrapClass_wxTopLevelWindowGTK >(this_ptr));
      parent_wxTopLevelWindowGTK->AddMethods(parent_wxTopLevelWindowGTK);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_GetClassInfo( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxTopLevelWindow::wxTopLevelWindow()
//---------------------------------------------------
void WrapClass_wxTopLevelWindow::
    wrap_wxTopLevelWindow_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindow::
    wrap_wxTopLevelWindow_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxTopLevelWindow* _newobj = new wxTopLevelWindow();
  BasicVariable::ptr res = WrapClass_wxTopLevelWindow::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxTopLevelWindow::wxTopLevelWindow(...)
//---------------------------------------------------
void WrapClass_wxTopLevelWindow::
    wrap_wxTopLevelWindow::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindow::
    wrap_wxTopLevelWindow::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxTopLevelWindow::wrap_wxTopLevelWindow_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxTopLevelWindow::wrap_wxTopLevelWindow_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxTopLevelWindow::wxTopLevelWindow(wxWindow * parent, wxWindowID winid, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)
//---------------------------------------------------
void WrapClass_wxTopLevelWindow::
    wrap_wxTopLevelWindow_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:541072960)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxFrameNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindow::
    wrap_wxTopLevelWindow_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxPoint(wxDefaultPosition) );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxSize(wxDefaultSize) );

  long style_long = 541072960;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxFrameNameStr) );

  wxTopLevelWindow* _newobj = new wxTopLevelWindow(parent, winid, title, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxTopLevelWindow::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxTopLevelWindow::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxTopLevelWindow::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindow::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

