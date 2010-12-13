/**
 * C++ Interface: wrap_wxAuiToolBar
 *
 * Description: wrapping wxAuiToolBar
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

#include "wrap_wxAuiToolBar.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
#endif
#ifndef wxAuiToolBarArt_declared
  #define wxAuiToolBarArt_declared
  AMI_DECLARE_TYPE(wxAuiToolBarArt)
#endif
#ifndef wxFont_declared
  #define wxFont_declared
  AMI_DECLARE_TYPE(wxFont)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxBitmap_declared
  #define wxBitmap_declared
  AMI_DECLARE_TYPE(wxBitmap)
#endif
#ifndef wxObject_declared
  #define wxObject_declared
  AMI_DECLARE_TYPE(wxObject)
#endif
#ifndef wxControl_declared
  #define wxControl_declared
  AMI_DECLARE_TYPE(wxControl)
#endif
#ifndef wxAuiToolBarItem_declared
  #define wxAuiToolBarItem_declared
  AMI_DECLARE_TYPE(wxAuiToolBarItem)
#endif
#ifndef wxRect_declared
  #define wxRect_declared
  AMI_DECLARE_TYPE(wxRect)
#endif
#ifndef wxAuiToolBarItemArray_declared
  #define wxAuiToolBarItemArray_declared
  AMI_DECLARE_TYPE(wxAuiToolBarItemArray)
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
BasicVariable::ptr WrapClass<wxAuiToolBar>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiToolBar::wrap_wxAuiToolBar construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAuiToolBar);
AMI_DEFINE_VARFROMSMTPTR(wxAuiToolBar);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxAuiToolBar>::CreateVar( wxAuiToolBar* val, bool nodeleter)
{ 
  boost::shared_ptr<wxAuiToolBar> obj_ptr(val,smartpointer_nodeleter<wxAuiToolBar>());
  return AMILabType<wxAuiToolBar>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiToolBar
//
Variable<AMIObject>::ptr WrapClass_wxAuiToolBar::CreateVar( wxAuiToolBar* sp)
{
  boost::shared_ptr<wxAuiToolBar> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiToolBar>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiToolBar>::CreateVar(
      new WrapClass_wxAuiToolBar(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiToolBar::AddMethods(WrapClass<wxAuiToolBar>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_SetWindowStyleFlag( this_ptr);
  AddVar_GetWindowStyleFlag( this_ptr);
  AddVar_SetArtProvider( this_ptr);
  AddVar_GetArtProvider( this_ptr);
  AddVar_SetFont( this_ptr);
  AddVar_AddTool_1( this_ptr);
  AddVar_AddTool( this_ptr);
  AddVar_AddTool_2( this_ptr);
  AddVar_AddTool_3( this_ptr);
  AddVar_AddLabel( this_ptr);
  AddVar_AddControl( this_ptr);
  AddVar_AddSeparator( this_ptr);
  AddVar_AddSpacer( this_ptr);
  AddVar_AddStretchSpacer( this_ptr);
  AddVar_Realize( this_ptr);
  AddVar_FindControl( this_ptr);
  AddVar_FindToolByPosition( this_ptr);
  AddVar_FindToolByIndex( this_ptr);
  AddVar_FindTool( this_ptr);
  AddVar_ClearTools( this_ptr);
  AddVar_Clear( this_ptr);
  AddVar_DeleteTool( this_ptr);
  AddVar_DeleteByIndex( this_ptr);
  AddVar_GetToolCount( this_ptr);
  AddVar_GetToolPos( this_ptr);
  AddVar_GetToolIndex( this_ptr);
  AddVar_GetToolFits( this_ptr);
  AddVar_GetToolRect( this_ptr);
  AddVar_GetToolFitsByIndex( this_ptr);
  AddVar_GetToolBarFits( this_ptr);
  AddVar_SetMargins_1( this_ptr);
  AddVar_SetMargins( this_ptr);
  AddVar_SetMargins_2( this_ptr);
  AddVar_SetMargins_3( this_ptr);
  AddVar_SetToolBitmapSize( this_ptr);
  AddVar_GetToolBitmapSize( this_ptr);
  AddVar_GetOverflowVisible( this_ptr);
  AddVar_SetOverflowVisible( this_ptr);
  AddVar_GetGripperVisible( this_ptr);
  AddVar_SetGripperVisible( this_ptr);
  AddVar_ToggleTool( this_ptr);
  AddVar_GetToolToggled( this_ptr);
  AddVar_EnableTool( this_ptr);
  AddVar_GetToolEnabled( this_ptr);
  AddVar_SetToolDropDown( this_ptr);
  AddVar_GetToolDropDown( this_ptr);
  AddVar_SetToolBorderPadding( this_ptr);
  AddVar_GetToolBorderPadding( this_ptr);
  AddVar_SetToolTextOrientation( this_ptr);
  AddVar_GetToolTextOrientation( this_ptr);
  AddVar_SetToolPacking( this_ptr);
  AddVar_GetToolPacking( this_ptr);
  AddVar_SetToolProportion( this_ptr);
  AddVar_GetToolProportion( this_ptr);
  AddVar_SetToolSeparation( this_ptr);
  AddVar_GetToolSeparation( this_ptr);
  AddVar_SetToolSticky( this_ptr);
  AddVar_GetToolSticky( this_ptr);
  AddVar_GetToolLabel( this_ptr);
  AddVar_SetToolLabel( this_ptr);
  AddVar_GetToolBitmap( this_ptr);
  AddVar_SetToolBitmap( this_ptr);
  AddVar_GetToolShortHelp( this_ptr);
  AddVar_SetToolShortHelp( this_ptr);
  AddVar_GetToolLongHelp( this_ptr);
  AddVar_SetToolLongHelp( this_ptr);
  AddVar_SetCustomOverflowItems( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


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
void WrapClasswxAuiToolBar_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAuiToolBar");
    WrapClass_wxAuiToolBar::AddVar_wxAuiToolBar(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAuiToolBar::wxAuiToolBar(wxWindow * parent, wxWindowID id = -0x00000000000000001, wxPoint const & position = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = wxAUI_TB_DEFAULT_STYLE)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_wxAuiToolBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'position' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:wxAUI_TB_DEFAULT_STYLE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_wxAuiToolBar::CallMember( ParamList* _p)
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

  int id = -0x00000000000000001;
  if (!get_val_param<int >(id,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > position_smtptr;
  if (!get_val_smtptr_param<wxPoint >(position_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & position = ( position_smtptr.get() ? (*position_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = wxAUI_TB_DEFAULT_STYLE;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  wxAuiToolBar* _newobj = new wxAuiToolBar(parent, id, position, size, style);
  BasicVariable::ptr res = WrapClass_wxAuiToolBar::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetWindowStyleFlag(long int style)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetWindowStyleFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetWindowStyleFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int style = style_long;

  this->_objectptr->GetObj()->SetWindowStyleFlag(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxAuiToolBar::GetWindowStyleFlag()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetWindowStyleFlag::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetWindowStyleFlag::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetWindowStyleFlag();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetArtProvider(wxAuiToolBarArt * art)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetArtProvider::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarArt, "parameter named 'art'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetArtProvider::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxAuiToolBarArt* art;
  if (CheckNullVar(_p,_n))  {
    art=(wxAuiToolBarArt*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxAuiToolBarArt > art_smtptr;
    if (!get_val_smtptr_param<wxAuiToolBarArt >(art_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    art = art_smtptr.get();
  }

  this->_objectptr->GetObj()->SetArtProvider(art);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarArt * wxAuiToolBar::GetArtProvider()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetArtProvider::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiToolBarArt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetArtProvider::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiToolBarArt * res =   this->_objectptr->GetObj()->GetArtProvider();
  BasicVariable::ptr res_var = AMILabType<wxAuiToolBarArt >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::SetFont(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  bool res =   this->_objectptr->GetObj()->SetFont(font);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddTool(int tool_id, wxString const & label, wxBitmap const & bitmap, wxString const & short_help_string = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddTool_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'short_help_string' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'kind' (def:wxITEM_NORMAL)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddTool_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxString > short_help_string_smtptr;
  if (!get_val_smtptr_param<wxString >(short_help_string_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & short_help_string = ( short_help_string_smtptr.get() ? (*short_help_string_smtptr) : wxString(wxEmptyString) );

  int kind_int = (int) wxITEM_NORMAL;;
  if (!get_val_param<int >(kind_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxItemKind kind = (wxItemKind) kind_int;

  this->_objectptr->GetObj()->AddTool(tool_id, label, bitmap, short_help_string, kind);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxAuiToolBar::AddTool(...)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddTool::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddTool::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiToolBar::wrap_AddTool_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiToolBar::wrap_AddTool_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxAuiToolBar::wrap_AddTool_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddTool(int tool_id, wxString const & label, wxBitmap const & bitmap, wxBitmap const & disabled_bitmap, wxItemKind kind, wxString const & short_help_string, wxString const & long_help_string, wxObject * client_data)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddTool_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'disabled_bitmap'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'kind'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'short_help_string'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'long_help_string'")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'client_data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddTool_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>8) ClassReturnEmptyVar;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxBitmap > disabled_bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(disabled_bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & disabled_bitmap = *disabled_bitmap_smtptr;

  int kind_int;
  if (!get_val_param<int >(kind_int,_p,_n,true,true)) ClassReturnEmptyVar;
  wxItemKind kind = (wxItemKind) kind_int;

  boost::shared_ptr<wxString > short_help_string_smtptr;
  if (!get_val_smtptr_param<wxString >(short_help_string_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & short_help_string = *short_help_string_smtptr;

  boost::shared_ptr<wxString > long_help_string_smtptr;
  if (!get_val_smtptr_param<wxString >(long_help_string_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & long_help_string = *long_help_string_smtptr;

  wxObject* client_data;
  if (CheckNullVar(_p,_n))  {
    client_data=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > client_data_smtptr;
    if (!get_val_smtptr_param<wxObject >(client_data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    client_data = client_data_smtptr.get();
  }

  this->_objectptr->GetObj()->AddTool(tool_id, label, bitmap, disabled_bitmap, kind, short_help_string, long_help_string, client_data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddTool(int tool_id, wxBitmap const & bitmap, wxBitmap const & disabled_bitmap, bool toggle = false, wxObject * client_data = 0l, wxString const & short_help_string = wxEmptyString, wxString const & long_help_string = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddTool_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'disabled_bitmap'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'toggle' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'client_data' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'short_help_string' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'long_help_string' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddTool_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxBitmap > disabled_bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(disabled_bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & disabled_bitmap = *disabled_bitmap_smtptr;

  bool toggle = false;
  if (!get_val_param<bool >(toggle,_p,_n,false,true)) ClassReturnEmptyVar;

  wxObject* client_data = 0l;
  if (CheckNullVar(_p,_n))  {
    client_data=(wxObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObject > client_data_smtptr;
    if (!get_val_smtptr_param<wxObject >(client_data_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
    client_data = client_data_smtptr.get();
  }

  boost::shared_ptr<wxString > short_help_string_smtptr;
  if (!get_val_smtptr_param<wxString >(short_help_string_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & short_help_string = ( short_help_string_smtptr.get() ? (*short_help_string_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > long_help_string_smtptr;
  if (!get_val_smtptr_param<wxString >(long_help_string_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & long_help_string = ( long_help_string_smtptr.get() ? (*long_help_string_smtptr) : wxString(wxEmptyString) );

  this->_objectptr->GetObj()->AddTool(tool_id, bitmap, disabled_bitmap, toggle, client_data, short_help_string, long_help_string);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddLabel(int tool_id, wxString const & label = wxEmptyString, int const width = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & label = ( label_smtptr.get() ? (*label_smtptr) : wxString(wxEmptyString) );

  int width = -0x00000000000000001;
  if (!get_val_param<int >(width,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddLabel(tool_id, label, width);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddControl(wxControl * control, wxString const & label = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddControl::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxControl, "parameter named 'control'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddControl::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  wxControl* control;
  if (CheckNullVar(_p,_n))  {
    control=(wxControl*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxControl > control_smtptr;
    if (!get_val_smtptr_param<wxControl >(control_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    control = control_smtptr.get();
  }

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & label = ( label_smtptr.get() ? (*label_smtptr) : wxString(wxEmptyString) );

  this->_objectptr->GetObj()->AddControl(control, label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddSeparator()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddSeparator::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddSeparator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddSeparator();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddSpacer(int pixels)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pixels'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int pixels;
  if (!get_val_param<int >(pixels,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddSpacer(pixels);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::AddStretchSpacer(int proportion = 1)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_AddStretchSpacer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_AddStretchSpacer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int proportion = 1;
  if (!get_val_param<int >(proportion,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddStretchSpacer(proportion);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::Realize()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_Realize::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_Realize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Realize();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxControl * wxAuiToolBar::FindControl(int window_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_FindControl::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'window_id'")
  return_comments="returning a variable of type wxControl";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_FindControl::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int window_id;
  if (!get_val_param<int >(window_id,_p,_n,true,false)) ClassHelpAndReturn;

  wxControl * res =   this->_objectptr->GetObj()->FindControl(window_id);
  BasicVariable::ptr res_var = AMILabType<wxControl >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem * wxAuiToolBar::FindToolByPosition(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_FindToolByPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_FindToolByPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  wxAuiToolBarItem * res =   this->_objectptr->GetObj()->FindToolByPosition(x, y);
  BasicVariable::ptr res_var = AMILabType<wxAuiToolBarItem >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem * wxAuiToolBar::FindToolByIndex(int idx)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_FindToolByIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'idx'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_FindToolByIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int idx;
  if (!get_val_param<int >(idx,_p,_n,true,false)) ClassHelpAndReturn;

  wxAuiToolBarItem * res =   this->_objectptr->GetObj()->FindToolByIndex(idx);
  BasicVariable::ptr res_var = AMILabType<wxAuiToolBarItem >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxAuiToolBarItem * wxAuiToolBar::FindTool(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_FindTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxAuiToolBarItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_FindTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  wxAuiToolBarItem * res =   this->_objectptr->GetObj()->FindTool(tool_id);
  BasicVariable::ptr res_var = AMILabType<wxAuiToolBarItem >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::ClearTools()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_ClearTools::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_ClearTools::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClearTools();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::Clear()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::DeleteTool(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_DeleteTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_DeleteTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->DeleteTool(tool_id);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::DeleteByIndex(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_DeleteByIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_DeleteByIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->DeleteByIndex(tool_id);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxAuiToolBar::GetToolCount()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetToolCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolPos(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolPos(tool_id);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolIndex(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolIndex(tool_id);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolFits(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolFits::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolFits::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetToolFits(tool_id);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxRect wxAuiToolBar::GetToolRect(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolRect::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxRect";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolRect::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  wxRect res =   this->_objectptr->GetObj()->GetToolRect(tool_id);
  return AMILabType<wxRect >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolFitsByIndex(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolFitsByIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolFitsByIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetToolFitsByIndex(tool_id);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolBarFits()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolBarFits::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolBarFits::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetToolBarFits();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetMargins(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetMargins_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetMargins_1::CallMember( ParamList* _p)
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
//  Wrapping of multipled defined method:... wxAuiToolBar::SetMargins(...)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetMargins::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetMargins::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiToolBar::wrap_SetMargins_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiToolBar::wrap_SetMargins_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxAuiToolBar::wrap_SetMargins_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetMargins(int x, int y)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetMargins_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetMargins_2::CallMember( ParamList* _p)
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
//  Wrapping of void wxAuiToolBar::SetMargins(int left, int right, int top, int bottom)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetMargins_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'left'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'right'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'top'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bottom'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetMargins_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int left;
  if (!get_val_param<int >(left,_p,_n,true,true)) ClassReturnEmptyVar;

  int right;
  if (!get_val_param<int >(right,_p,_n,true,true)) ClassReturnEmptyVar;

  int top;
  if (!get_val_param<int >(top,_p,_n,true,true)) ClassReturnEmptyVar;

  int bottom;
  if (!get_val_param<int >(bottom,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetMargins(left, right, top, bottom);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolBitmapSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolBitmapSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
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
//  Wrapping of wxSize wxAuiToolBar::GetToolBitmapSize()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolBitmapSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolBitmapSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetToolBitmapSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetOverflowVisible()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetOverflowVisible::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetOverflowVisible::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetOverflowVisible();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetOverflowVisible(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetOverflowVisible::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'visible'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetOverflowVisible::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool visible;
  if (!get_val_param<bool >(visible,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetOverflowVisible(visible);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetGripperVisible()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetGripperVisible::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetGripperVisible::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetGripperVisible();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetGripperVisible(bool visible)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetGripperVisible::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'visible'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetGripperVisible::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool visible;
  if (!get_val_param<bool >(visible,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetGripperVisible(visible);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::ToggleTool(int tool_id, bool state)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_ToggleTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'state'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_ToggleTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool state;
  if (!get_val_param<bool >(state,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ToggleTool(tool_id, state);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolToggled(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolToggled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolToggled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetToolToggled(tool_id);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::EnableTool(int tool_id, bool state)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_EnableTool::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'state'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_EnableTool::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool state;
  if (!get_val_param<bool >(state,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EnableTool(tool_id, state);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolEnabled(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolEnabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolEnabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetToolEnabled(tool_id);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolDropDown(int tool_id, bool dropdown)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolDropDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'dropdown'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolDropDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool dropdown;
  if (!get_val_param<bool >(dropdown,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetToolDropDown(tool_id, dropdown);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolDropDown(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolDropDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolDropDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetToolDropDown(tool_id);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolBorderPadding(int padding)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolBorderPadding::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'padding'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolBorderPadding::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int padding;
  if (!get_val_param<int >(padding,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetToolBorderPadding(padding);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolBorderPadding()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolBorderPadding::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolBorderPadding::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolBorderPadding();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolTextOrientation(int orientation)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolTextOrientation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orientation'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolTextOrientation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int orientation;
  if (!get_val_param<int >(orientation,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetToolTextOrientation(orientation);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolTextOrientation()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolTextOrientation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolTextOrientation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolTextOrientation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolPacking(int packing)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolPacking::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'packing'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
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
//  Wrapping of int wxAuiToolBar::GetToolPacking()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolPacking::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolPacking::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolPacking();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolProportion(int tool_id, int proportion)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolProportion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolProportion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  int proportion;
  if (!get_val_param<int >(proportion,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetToolProportion(tool_id, proportion);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAuiToolBar::GetToolProportion(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolProportion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolProportion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolProportion(tool_id);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolSeparation(int separation)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolSeparation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'separation'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
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
//  Wrapping of int wxAuiToolBar::GetToolSeparation()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolSeparation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolSeparation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetToolSeparation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolSticky(int tool_id, bool sticky)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolSticky::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'sticky'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolSticky::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool sticky;
  if (!get_val_param<bool >(sticky,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetToolSticky(tool_id, sticky);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiToolBar::GetToolSticky(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolSticky::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolSticky::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetToolSticky(tool_id);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxAuiToolBar::GetToolLabel(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetToolLabel(tool_id);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolLabel(int tool_id, wxString const & label)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetToolLabel(tool_id, label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxAuiToolBar::GetToolBitmap(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetToolBitmap(tool_id);
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolBitmap(int tool_id, wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetToolBitmap(tool_id, bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxAuiToolBar::GetToolShortHelp(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolShortHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolShortHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetToolShortHelp(tool_id);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolShortHelp(int tool_id, wxString const & help_string)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolShortHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help_string'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolShortHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > help_string_smtptr;
  if (!get_val_smtptr_param<wxString >(help_string_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & help_string = *help_string_smtptr;

  this->_objectptr->GetObj()->SetToolShortHelp(tool_id, help_string);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxAuiToolBar::GetToolLongHelp(int tool_id)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetToolLongHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetToolLongHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetToolLongHelp(tool_id);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetToolLongHelp(int tool_id, wxString const & help_string)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetToolLongHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'tool_id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'help_string'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetToolLongHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int tool_id;
  if (!get_val_param<int >(tool_id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > help_string_smtptr;
  if (!get_val_smtptr_param<wxString >(help_string_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & help_string = *help_string_smtptr;

  this->_objectptr->GetObj()->SetToolLongHelp(tool_id, help_string);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiToolBar::SetCustomOverflowItems(wxAuiToolBarItemArray const & prepend, wxAuiToolBarItemArray const & append)
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_SetCustomOverflowItems::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItemArray, "parameter named 'prepend'")
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarItemArray, "parameter named 'append'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_SetCustomOverflowItems::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarItemArray > prepend_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItemArray >(prepend_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiToolBarItemArray const & prepend = *prepend_smtptr;

  boost::shared_ptr<wxAuiToolBarItemArray > append_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarItemArray >(append_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiToolBarItemArray const & append = *append_smtptr;

  this->_objectptr->GetObj()->SetCustomOverflowItems(prepend, append);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxAuiToolBar::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxAuiToolBar::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBar::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

