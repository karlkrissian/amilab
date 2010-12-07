/**
 * C++ Interface: wrap_wxToolBarBase
 *
 * Description: wrapping wxToolBarBase
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
#include "wrap_wxToolBarToolBase.h"
#include "wrap_wxString.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxObject.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxControl.h"
#include "wrap_wxSize.h"


#include "wrap_wxToolBarBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxToolBarBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxToolBarBase);
AMI_DEFINE_VARFROMSMTPTR(wxToolBarBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxToolBarBase>::CreateVar( wxToolBarBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxToolBarBase> obj_ptr(val,smartpointer_nodeleter<wxToolBarBase>());
  return AMILabType<wxToolBarBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxToolBarBase
//
Variable<AMIObject>::ptr WrapClass_wxToolBarBase::CreateVar( wxToolBarBase* sp)
{
  boost::shared_ptr<wxToolBarBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxToolBarBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxToolBarBase>::CreateVar(
      new WrapClass_wxToolBarBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxToolBarBase::AddMethods(WrapClass<wxToolBarBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_AddTool_1( this_ptr);
      AddVar_AddTool( this_ptr);
      AddVar_AddTool_2( this_ptr);
      AddVar_AddCheckTool( this_ptr);
      AddVar_AddRadioTool( this_ptr);
      AddVar_InsertTool_1( this_ptr);
      AddVar_AddTool_3( this_ptr);
      AddVar_InsertTool( this_ptr);
      AddVar_InsertTool_2( this_ptr);
      AddVar_AddControl( this_ptr);
      AddVar_InsertControl( this_ptr);
      AddVar_FindControl( this_ptr);
      AddVar_AddSeparator( this_ptr);
      AddVar_InsertSeparator( this_ptr);
      AddVar_RemoveTool( this_ptr);
      AddVar_DeleteToolByPos( this_ptr);
      AddVar_DeleteTool( this_ptr);
      AddVar_ClearTools( this_ptr);
      AddVar_Realize( this_ptr);
      AddVar_EnableTool( this_ptr);
      AddVar_ToggleTool( this_ptr);
      AddVar_SetToggle( this_ptr);
      AddVar_GetToolClientData( this_ptr);
      AddVar_SetToolClientData( this_ptr);
      AddVar_GetToolPos( this_ptr);
      AddVar_GetToolState( this_ptr);
      AddVar_GetToolEnabled( this_ptr);
      AddVar_SetToolShortHelp( this_ptr);
      AddVar_GetToolShortHelp( this_ptr);
      AddVar_SetToolLongHelp( this_ptr);
      AddVar_GetToolLongHelp( this_ptr);
      AddVar_SetMargins_1( this_ptr);
      AddVar_SetMargins( this_ptr);
      AddVar_SetMargins_2( this_ptr);
      AddVar_SetToolPacking( this_ptr);
      AddVar_SetToolSeparation( this_ptr);
      AddVar_GetToolMargins( this_ptr);
      AddVar_GetToolPacking( this_ptr);
      AddVar_GetToolSeparation( this_ptr);
      AddVar_SetRows( this_ptr);
      AddVar_SetMaxRowsCols( this_ptr);
      AddVar_GetMaxRows( this_ptr);
      AddVar_GetMaxCols( this_ptr);
      AddVar_SetToolBitmapSize( this_ptr);
      AddVar_GetToolBitmapSize( this_ptr);
      AddVar_GetToolSize( this_ptr);
      AddVar_FindById( this_ptr);
      AddVar_IsVertical( this_ptr);
      AddVar_AddTool_4( this_ptr);
      AddVar_AddTool_5( this_ptr);
      AddVar_AddTool_6( this_ptr);
      AddVar_InsertTool_3( this_ptr);
      AddVar_OnLeftClick( this_ptr);
      AddVar_OnRightClick( this_ptr);
      AddVar_OnMouseEnter( this_ptr);
      AddVar_GetMargins( this_ptr);
      AddVar_GetToolsCount( this_ptr);
      AddVar_UpdateWindowUI( this_ptr);
      AddVar_AcceptsFocus( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxControl
  boost::shared_ptr<wxControl > parent_wxControl(  boost::dynamic_pointer_cast<wxControl >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxControl = AMILabType<wxControl >::CreateVarFromSmtPtr(parent_wxControl);
  context->AddVar("wxControl",var_wxControl);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxControl = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxControl);
  context->AddDefault(obj_wxControl->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxToolBarBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxToolBarBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxString const & label, wxBitmap const & bitmap, wxBitmap const & bmpDisabled, wxItemKind kind = wxITEM_NORMAL, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString, wxObject * data = 0l)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddTool_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpDisabled'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'kind' (def:wxITEM_NORMAL)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'longHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'data' (def:0l)")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddTool_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>8) ClassReturnEmptyVar;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxBitmap > bmpDisabled_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpDisabled_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bmpDisabled = *bmpDisabled_smtptr;

  int kind_int = (int) wxITEM_NORMAL;;
  if (!get_val_param<int >(kind_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxItemKind kind = (wxItemKind) kind_int;

  boost::shared_ptr<wxString > shortHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(shortHelp_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & shortHelp = ( shortHelp_smtptr.get() ? (*shortHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > longHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(longHelp_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & longHelp = ( longHelp_smtptr.get() ? (*longHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxObject > data_smtptr;
  if (!get_val_smtptr_param<wxObject >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxObject* data = data_smtptr.get();

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddTool(toolid, label, bitmap, bmpDisabled, kind, shortHelp, longHelp, data);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxToolBarBase::AddTool(...)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddTool::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddTool::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxToolBarBase::wrap_AddTool_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxToolBarBase::wrap_AddTool_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxToolBarBase::wrap_AddTool_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxToolBarBase::wrap_AddTool_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxToolBarBase::wrap_AddTool_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxToolBarBase::wrap_AddTool_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxString const & label, wxBitmap const & bitmap, wxString const & shortHelp = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddTool_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'kind' (def:wxITEM_NORMAL)")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddTool_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxString > shortHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(shortHelp_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & shortHelp = ( shortHelp_smtptr.get() ? (*shortHelp_smtptr) : wxString(wxEmptyString) );

  int kind_int = (int) wxITEM_NORMAL;;
  if (!get_val_param<int >(kind_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxItemKind kind = (wxItemKind) kind_int;

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddTool(toolid, label, bitmap, shortHelp, kind);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddCheckTool(int toolid, wxString const & label, wxBitmap const & bitmap, wxBitmap const & bmpDisabled = wxNullBitmap, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString, wxObject * data = 0l)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddCheckTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpDisabled' (def:wxNullBitmap)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'longHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'data' (def:0l)")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddCheckTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxBitmap > bmpDisabled_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpDisabled_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxBitmap const & bmpDisabled = ( bmpDisabled_smtptr.get() ? (*bmpDisabled_smtptr) : wxNullBitmap );

  boost::shared_ptr<wxString > shortHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(shortHelp_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & shortHelp = ( shortHelp_smtptr.get() ? (*shortHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > longHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(longHelp_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & longHelp = ( longHelp_smtptr.get() ? (*longHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxObject > data_smtptr;
  if (!get_val_smtptr_param<wxObject >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxObject* data = data_smtptr.get();

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddCheckTool(toolid, label, bitmap, bmpDisabled, shortHelp, longHelp, data);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddRadioTool(int toolid, wxString const & label, wxBitmap const & bitmap, wxBitmap const & bmpDisabled = wxNullBitmap, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString, wxObject * data = 0l)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddRadioTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpDisabled' (def:wxNullBitmap)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'longHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'data' (def:0l)")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddRadioTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxBitmap > bmpDisabled_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpDisabled_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxBitmap const & bmpDisabled = ( bmpDisabled_smtptr.get() ? (*bmpDisabled_smtptr) : wxNullBitmap );

  boost::shared_ptr<wxString > shortHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(shortHelp_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & shortHelp = ( shortHelp_smtptr.get() ? (*shortHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > longHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(longHelp_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & longHelp = ( longHelp_smtptr.get() ? (*longHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxObject > data_smtptr;
  if (!get_val_smtptr_param<wxObject >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxObject* data = data_smtptr.get();

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddRadioTool(toolid, label, bitmap, bmpDisabled, shortHelp, longHelp, data);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::InsertTool(size_t pos, int toolid, wxString const & label, wxBitmap const & bitmap, wxBitmap const & bmpDisabled = wxNullBitmap, wxItemKind kind = wxITEM_NORMAL, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString, wxObject * clientData = 0l)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_InsertTool_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpDisabled' (def:wxNullBitmap)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'kind' (def:wxITEM_NORMAL)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'longHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'clientData' (def:0l)")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_InsertTool_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>9) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxBitmap > bmpDisabled_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpDisabled_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxBitmap const & bmpDisabled = ( bmpDisabled_smtptr.get() ? (*bmpDisabled_smtptr) : wxNullBitmap );

  int kind_int = (int) wxITEM_NORMAL;;
  if (!get_val_param<int >(kind_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxItemKind kind = (wxItemKind) kind_int;

  boost::shared_ptr<wxString > shortHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(shortHelp_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & shortHelp = ( shortHelp_smtptr.get() ? (*shortHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > longHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(longHelp_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & longHelp = ( longHelp_smtptr.get() ? (*longHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxObject > clientData_smtptr;
  if (!get_val_smtptr_param<wxObject >(clientData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxObject* clientData = clientData_smtptr.get();

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->InsertTool(pos, toolid, label, bitmap, bmpDisabled, kind, shortHelp, longHelp, clientData);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddTool(wxToolBarToolBase * tool)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddTool_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxToolBarToolBase, "parameter named 'tool'")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddTool_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxToolBarToolBase > tool_smtptr;
  if (!get_val_smtptr_param<wxToolBarToolBase >(tool_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxToolBarToolBase* tool = tool_smtptr.get();

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddTool(tool);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxToolBarBase::InsertTool(...)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_InsertTool::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_InsertTool::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxToolBarBase::wrap_InsertTool_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxToolBarBase::wrap_InsertTool_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxToolBarBase::wrap_InsertTool_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::InsertTool(size_t pos, wxToolBarToolBase * tool)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_InsertTool_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxToolBarToolBase, "parameter named 'tool'")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_InsertTool_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxToolBarToolBase > tool_smtptr;
  if (!get_val_smtptr_param<wxToolBarToolBase >(tool_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxToolBarToolBase* tool = tool_smtptr.get();

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->InsertTool(pos, tool);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddControl(wxControl * control)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddControl::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxControl, "parameter named 'control'")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddControl::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxControl > control_smtptr;
  if (!get_val_smtptr_param<wxControl >(control_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxControl* control = control_smtptr.get();

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddControl(control);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::InsertControl(size_t pos, wxControl * control)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_InsertControl::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxControl, "parameter named 'control'")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_InsertControl::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  boost::shared_ptr<wxControl > control_smtptr;
  if (!get_val_smtptr_param<wxControl >(control_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxControl* control = control_smtptr.get();

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->InsertControl(pos, control);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxControl * wxToolBarBase::FindControl(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_FindControl::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  return_comments="returning a variable of type wxControl";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_FindControl::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  wxControl * res =   this->_objectptr->GetObj()->FindControl(toolid);
  BasicVariable::ptr res_var = WrapClass_wxControl::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddSeparator()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddSeparator::SetParametersComments()
{
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddSeparator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddSeparator();
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::InsertSeparator(size_t pos)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_InsertSeparator::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_InsertSeparator::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->InsertSeparator(pos);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::RemoveTool(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_RemoveTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_RemoveTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->RemoveTool(toolid);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarBase::DeleteToolByPos(size_t pos)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_DeleteToolByPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_DeleteToolByPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  bool res =   this->_objectptr->GetObj()->DeleteToolByPos(pos);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarBase::DeleteTool(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_DeleteTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_DeleteTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->DeleteTool(toolid);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::ClearTools()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_ClearTools::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_ClearTools::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClearTools();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarBase::Realize()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_Realize::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_Realize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Realize();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::EnableTool(int toolid, bool enable)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_EnableTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'enable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_EnableTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  bool enable;
  if (!get_val_param<bool >(enable,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EnableTool(toolid, enable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::ToggleTool(int toolid, bool toggle)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_ToggleTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'toggle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_ToggleTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  bool toggle;
  if (!get_val_param<bool >(toggle,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ToggleTool(toolid, toggle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetToggle(int toolid, bool toggle)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetToggle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'toggle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetToggle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  bool toggle;
  if (!get_val_param<bool >(toggle,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetToggle(toolid, toggle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxObject * wxToolBarBase::GetToolClientData(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolClientData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolClientData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  wxObject * res =   this->_objectptr->GetObj()->GetToolClientData(toolid);
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetToolClientData(int toolid, wxObject * clientData)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetToolClientData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'clientData'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetToolClientData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxObject > clientData_smtptr;
  if (!get_val_smtptr_param<wxObject >(clientData_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxObject* clientData = clientData_smtptr.get();

  this->_objectptr->GetObj()->SetToolClientData(toolid, clientData);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxToolBarBase::GetToolPos(int id)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolPos(id);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarBase::GetToolState(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolState::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolState::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetToolState(toolid);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarBase::GetToolEnabled(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetToolEnabled(toolid);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetToolShortHelp(int toolid, wxString const & helpString)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetToolShortHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'helpString'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetToolShortHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > helpString_smtptr;
  if (!get_val_smtptr_param<wxString >(helpString_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & helpString = *helpString_smtptr;

  this->_objectptr->GetObj()->SetToolShortHelp(toolid, helpString);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxToolBarBase::GetToolShortHelp(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolShortHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolShortHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetToolShortHelp(toolid);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetToolLongHelp(int toolid, wxString const & helpString)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetToolLongHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'helpString'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetToolLongHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > helpString_smtptr;
  if (!get_val_smtptr_param<wxString >(helpString_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & helpString = *helpString_smtptr;

  this->_objectptr->GetObj()->SetToolLongHelp(toolid, helpString);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxToolBarBase::GetToolLongHelp(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolLongHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolLongHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetToolLongHelp(toolid);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetMargins(int x, int y)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetMargins_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetMargins_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetMargins(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxToolBarBase::SetMargins(...)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetMargins::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetMargins::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxToolBarBase::wrap_SetMargins_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxToolBarBase::wrap_SetMargins_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetMargins(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetMargins_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetMargins_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetMargins(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetToolPacking(int packing)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetToolPacking::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'packing'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetToolPacking::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int packing;
  if (!get_val_param<int >(packing,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetToolPacking(packing);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetToolSeparation(int separation)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetToolSeparation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'separation'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetToolSeparation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int separation;
  if (!get_val_param<int >(separation,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetToolSeparation(separation);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxToolBarBase::GetToolMargins()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolMargins::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolMargins::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetToolMargins();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxToolBarBase::GetToolPacking()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolPacking::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolPacking::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolPacking();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxToolBarBase::GetToolSeparation()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolSeparation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolSeparation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolSeparation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetRows(int nRows)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetRows::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'nRows'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetRows::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int nRows;
  if (!get_val_param<int >(nRows,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRows(nRows);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetMaxRowsCols(int rows, int cols)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetMaxRowsCols::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'rows'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cols'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetMaxRowsCols::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int rows;
  if (!get_val_param<int >(rows,_p,_n,true,false)) ClassHelpAndReturn;

  int cols;
  if (!get_val_param<int >(cols,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMaxRowsCols(rows, cols);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxToolBarBase::GetMaxRows()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetMaxRows::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetMaxRows::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaxRows();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxToolBarBase::GetMaxCols()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetMaxCols::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetMaxCols::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaxCols();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::SetToolBitmapSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_SetToolBitmapSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_SetToolBitmapSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetToolBitmapSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxToolBarBase::GetToolBitmapSize()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolBitmapSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolBitmapSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetToolBitmapSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSize wxToolBarBase::GetToolSize()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetToolSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::FindById(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_FindById::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_FindById::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->FindById(toolid);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarBase::IsVertical()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_IsVertical::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_IsVertical::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsVertical();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxBitmap const & bitmap, wxBitmap const & bmpDisabled, bool toggle = false, wxObject * clientData = 0l, wxString const & shortHelpString = wxEmptyString, wxString const & longHelpString = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddTool_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpDisabled'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'toggle' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'clientData' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelpString' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'longHelpString' (def:wxEmptyString)")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddTool_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxBitmap > bmpDisabled_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpDisabled_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bmpDisabled = *bmpDisabled_smtptr;

  bool toggle = false;
  if (!get_val_param<bool >(toggle,_p,_n,false,true)) ClassReturnEmptyVar;

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

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddTool(toolid, bitmap, bmpDisabled, toggle, clientData, shortHelpString, longHelpString);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxBitmap const & bitmap, wxString const & shortHelpString = wxEmptyString, wxString const & longHelpString = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddTool_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelpString' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'longHelpString' (def:wxEmptyString)")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddTool_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxString > shortHelpString_smtptr;
  if (!get_val_smtptr_param<wxString >(shortHelpString_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & shortHelpString = ( shortHelpString_smtptr.get() ? (*shortHelpString_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > longHelpString_smtptr;
  if (!get_val_smtptr_param<wxString >(longHelpString_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & longHelpString = ( longHelpString_smtptr.get() ? (*longHelpString_smtptr) : wxString(wxEmptyString) );

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddTool(toolid, bitmap, shortHelpString, longHelpString);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxBitmap const & bitmap, wxBitmap const & bmpDisabled, bool toggle, wxCoord xPos, wxCoord yPos = wxDefaultCoord, wxObject * clientData = 0l, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AddTool_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpDisabled'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'toggle'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xPos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yPos' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'clientData' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'longHelp' (def:wxEmptyString)")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AddTool_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>9) ClassReturnEmptyVar;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxBitmap > bmpDisabled_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpDisabled_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bmpDisabled = *bmpDisabled_smtptr;

  bool toggle;
  if (!get_val_param<bool >(toggle,_p,_n,true,true)) ClassReturnEmptyVar;

  int xPos;
  if (!get_val_param<int >(xPos,_p,_n,true,true)) ClassReturnEmptyVar;

  int yPos = wxDefaultCoord;
  if (!get_val_param<int >(yPos,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > clientData_smtptr;
  if (!get_val_smtptr_param<wxObject >(clientData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxObject* clientData = clientData_smtptr.get();

  boost::shared_ptr<wxString > shortHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(shortHelp_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & shortHelp = ( shortHelp_smtptr.get() ? (*shortHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > longHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(longHelp_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & longHelp = ( longHelp_smtptr.get() ? (*longHelp_smtptr) : wxString(wxEmptyString) );

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->AddTool(toolid, bitmap, bmpDisabled, toggle, xPos, yPos, clientData, shortHelp, longHelp);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBarBase::InsertTool(size_t pos, int toolid, wxBitmap const & bitmap, wxBitmap const & bmpDisabled = wxNullBitmap, bool toggle = false, wxObject * clientData = 0l, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_InsertTool_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpDisabled' (def:wxNullBitmap)")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'toggle' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'clientData' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'shortHelp' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'longHelp' (def:wxEmptyString)")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_InsertTool_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>8) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxBitmap > bmpDisabled_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpDisabled_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxBitmap const & bmpDisabled = ( bmpDisabled_smtptr.get() ? (*bmpDisabled_smtptr) : wxNullBitmap );

  bool toggle = false;
  if (!get_val_param<bool >(toggle,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxObject > clientData_smtptr;
  if (!get_val_smtptr_param<wxObject >(clientData_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxObject* clientData = clientData_smtptr.get();

  boost::shared_ptr<wxString > shortHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(shortHelp_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & shortHelp = ( shortHelp_smtptr.get() ? (*shortHelp_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > longHelp_smtptr;
  if (!get_val_smtptr_param<wxString >(longHelp_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & longHelp = ( longHelp_smtptr.get() ? (*longHelp_smtptr) : wxString(wxEmptyString) );

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->InsertTool(pos, toolid, bitmap, bmpDisabled, toggle, clientData, shortHelp, longHelp);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarBase::OnLeftClick(int toolid, bool toggleDown)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_OnLeftClick::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'toggleDown'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_OnLeftClick::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  bool toggleDown;
  if (!get_val_param<bool >(toggleDown,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->OnLeftClick(toolid, toggleDown);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::OnRightClick(int toolid, long int x, long int y)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_OnRightClick::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_OnRightClick::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  long x_long;
  if (!get_val_param<long >(x_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int x = x_long;

  long y_long;
  if (!get_val_param<long >(y_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int y = y_long;

  this->_objectptr->GetObj()->OnRightClick(toolid, x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::OnMouseEnter(int toolid)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_OnMouseEnter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'toolid'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_OnMouseEnter::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int toolid;
  if (!get_val_param<int >(toolid,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnMouseEnter(toolid);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxToolBarBase::GetMargins()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetMargins::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetMargins::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetMargins();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxToolBarBase::GetToolsCount()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_GetToolsCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_GetToolsCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetToolsCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxToolBarBase::UpdateWindowUI(long int flags = wxUPDATE_UI_NONE)
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_UpdateWindowUI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags' (def:wxUPDATE_UI_NONE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_UpdateWindowUI::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flags_long = wxUPDATE_UI_NONE;;
  if (!get_val_param<long >(flags_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int flags = flags_long;

  this->_objectptr->GetObj()->UpdateWindowUI(flags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxToolBarBase::AcceptsFocus()
//---------------------------------------------------
void WrapClass_wxToolBarBase::
    wrap_AcceptsFocus::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBarBase::
    wrap_AcceptsFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AcceptsFocus();
  return AMILabType<bool >::CreateVar(res);
}

