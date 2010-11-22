/**
 * C++ Interface: wrap_wxFrame
 *
 * Description: wrapping wxFrame
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
#include "wrap_wxStatusBar.h"
#include "wrap_wxToolBar.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxFrame.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxFrame>::CreateVar( ParamList* p)
{
  WrapClass_wxFrame::wrap_wxFrame construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxFrame);
AMI_DEFINE_VARFROMSMTPTR(wxFrame);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxFrame>::CreateVar( wxFrame* val, bool nodeleter)
{ 
  boost::shared_ptr<wxFrame> obj_ptr(val,smartpointer_nodeleter<wxFrame>());
  return AMILabType<wxFrame>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxFrame
//
Variable<AMIObject>::ptr WrapClass_wxFrame::CreateVar( wxFrame* sp)
{
  boost::shared_ptr<wxFrame> di_ptr(
    sp,
    wxwindow_nodeleter<wxFrame>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFrame>::CreateVar(
      new WrapClass_wxFrame(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxFrame::AddMethods(WrapClass<wxFrame>::ptr this_ptr )
{
  
      // Add members from wxFrameBase
      WrapClass_wxFrameBase::ptr parent_wxFrameBase(        boost::dynamic_pointer_cast<WrapClass_wxFrameBase >(this_ptr));
      parent_wxFrameBase->AddMethods(parent_wxFrameBase);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_Create( this_ptr);
      AddVar_CreateStatusBar( this_ptr);
      AddVar_SetStatusBar( this_ptr);
      AddVar_CreateToolBar( this_ptr);
      AddVar_SetToolBar( this_ptr);
      AddVar_GetClientAreaOrigin( this_ptr);
      AddVar_GtkOnSize( this_ptr);
      AddVar_OnInternalIdle( this_ptr);
      AddVar_UpdateMenuBarSize( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* type not available
      // Adding public member m_menuBarDetached
      boost::shared_ptr<bool > var_m_menuBarDetached_ptr(&GetObj()->m_menuBarDetached, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_menuBarDetached = AMILabType<bool >::CreateVarFromSmtPtr(var_m_menuBarDetached_ptr);
      if (var_m_menuBarDetached.get()) {
        var_m_menuBarDetached->Rename("m_menuBarDetached");
        context->AddVar(var_m_menuBarDetached,context);
      }
      */
      
      // Adding public member m_menuBarHeight
      boost::shared_ptr<int > var_m_menuBarHeight_ptr(&GetObj()->m_menuBarHeight, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_menuBarHeight = AMILabType<int >::CreateVarFromSmtPtr(var_m_menuBarHeight_ptr);
      if (var_m_menuBarHeight.get()) {
        var_m_menuBarHeight->Rename("m_menuBarHeight");
        context->AddVar(var_m_menuBarHeight,context);
      }
      
      /* type not available
      // Adding public member m_toolBarDetached
      boost::shared_ptr<bool > var_m_toolBarDetached_ptr(&GetObj()->m_toolBarDetached, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_toolBarDetached = AMILabType<bool >::CreateVarFromSmtPtr(var_m_toolBarDetached_ptr);
      if (var_m_toolBarDetached.get()) {
        var_m_toolBarDetached->Rename("m_toolBarDetached");
        context->AddVar(var_m_toolBarDetached,context);
      }
      */

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxFrame::wxFrame()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_wxFrame_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_wxFrame_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxFrame* _newobj = new wxFrame();
  BasicVariable::ptr res = WrapClass_wxFrame::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxFrame::wxFrame(...)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_wxFrame::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_wxFrame::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFrame::wrap_wxFrame_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFrame::wrap_wxFrame_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFrame::wxFrame(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_wxFrame_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:541072960)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxFrameNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_wxFrame_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : (wxDefaultPosition) );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : (wxDefaultSize) );

  long style_long = 541072960;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : (wxFrameNameStr) );

  wxFrame* _newobj = new wxFrame(parent, id, title, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxFrame::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxFrame::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:541072960)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxFrameNameStr)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
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

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : (wxDefaultPosition) );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : (wxDefaultSize) );

  long style_long = 541072960;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : (wxFrameNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, title, pos, size, style, name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxStatusBar * wxFrame::CreateStatusBar(int number = 1, long int style = 65552, wxWindowID id = 0, wxString const & name = wxStatusLineNameStr)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_CreateStatusBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:1)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:65552)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxStatusLineNameStr)")
  return_comments="returning a variable of type wxStatusBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_CreateStatusBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int number = 1;
  if (!get_val_param<int >(number,_p,_n)) ClassHelpAndReturn;

  long style_long = 65552;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  int id = 0;
  if (!get_val_param<int >(id,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : (wxStatusLineNameStr) );

  wxStatusBar * res =   this->_objectptr->GetObj()->CreateStatusBar(number, style, id, name);
  BasicVariable::ptr res_var = WrapClass_wxStatusBar::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxFrame::SetStatusBar(wxStatusBar * statbar)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_SetStatusBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStatusBar, "parameter named 'statbar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_SetStatusBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxStatusBar > statbar_smtptr;
  if (!get_val_smtptr_param<wxStatusBar >(statbar_smtptr,_p,_n)) ClassHelpAndReturn;
  wxStatusBar* statbar = statbar_smtptr.get();

  this->_objectptr->GetObj()->SetStatusBar(statbar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxToolBar * wxFrame::CreateToolBar(long int style = -0x00000000000000001, wxWindowID id = -0x00000000000000001, wxString const & name = wxToolBarNameStr)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_CreateToolBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxToolBarNameStr)")
  return_comments="returning a variable of type wxToolBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_CreateToolBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long style_long = -0x00000000000000001;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  int id = -0x00000000000000001;
  if (!get_val_param<int >(id,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : (wxToolBarNameStr) );

  wxToolBar * res =   this->_objectptr->GetObj()->CreateToolBar(style, id, name);
  BasicVariable::ptr res_var = WrapClass_wxToolBar::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxFrame::SetToolBar(wxToolBar * toolbar)
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_SetToolBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxToolBar, "parameter named 'toolbar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_SetToolBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxToolBar > toolbar_smtptr;
  if (!get_val_smtptr_param<wxToolBar >(toolbar_smtptr,_p,_n)) ClassHelpAndReturn;
  wxToolBar* toolbar = toolbar_smtptr.get();

  this->_objectptr->GetObj()->SetToolBar(toolbar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPoint wxFrame::GetClientAreaOrigin()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_GetClientAreaOrigin::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_GetClientAreaOrigin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetClientAreaOrigin();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFrame::GtkOnSize()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_GtkOnSize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_GtkOnSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GtkOnSize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrame::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrame::UpdateMenuBarSize()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_UpdateMenuBarSize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_UpdateMenuBarSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateMenuBarSize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxFrame::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxFrame::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrame::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

