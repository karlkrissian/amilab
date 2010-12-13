/**
 * C++ Interface: wrap_wxAuiNotebook
 *
 * Description: wrapping wxAuiNotebook
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

#include "wrap_wxAuiNotebook.h"

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
#ifndef wxAuiTabArt_declared
  #define wxAuiTabArt_declared
  AMI_DECLARE_TYPE(wxAuiTabArt)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxBitmap_declared
  #define wxBitmap_declared
  AMI_DECLARE_TYPE(wxBitmap)
#endif
#ifndef wxAuiManager_declared
  #define wxAuiManager_declared
  AMI_DECLARE_TYPE(wxAuiManager)
#endif
#ifndef wxFont_declared
  #define wxFont_declared
  AMI_DECLARE_TYPE(wxFont)
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
BasicVariable::ptr WrapClass<wxAuiNotebook>::CreateVar( ParamList* p)
{
  WrapClass_wxAuiNotebook::wrap_wxAuiNotebook construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAuiNotebook);
AMI_DEFINE_VARFROMSMTPTR(wxAuiNotebook);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxAuiNotebook>::CreateVar( wxAuiNotebook* val, bool nodeleter)
{ 
  boost::shared_ptr<wxAuiNotebook> obj_ptr(val,smartpointer_nodeleter<wxAuiNotebook>());
  return AMILabType<wxAuiNotebook>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiNotebook
//
Variable<AMIObject>::ptr WrapClass_wxAuiNotebook::CreateVar( wxAuiNotebook* sp)
{
  boost::shared_ptr<wxAuiNotebook> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiNotebook>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiNotebook>::CreateVar(
      new WrapClass_wxAuiNotebook(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiNotebook::AddMethods(WrapClass<wxAuiNotebook>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Create( this_ptr);
  AddVar_SetWindowStyleFlag( this_ptr);
  AddVar_SetArtProvider( this_ptr);
  AddVar_GetArtProvider( this_ptr);
  AddVar_SetUniformBitmapSize( this_ptr);
  AddVar_SetTabCtrlHeight( this_ptr);
  AddVar_AddPage( this_ptr);
  AddVar_InsertPage( this_ptr);
  AddVar_DeletePage( this_ptr);
  AddVar_RemovePage( this_ptr);
  AddVar_GetPageCount( this_ptr);
  AddVar_GetPage( this_ptr);
  AddVar_GetPageIndex( this_ptr);
  AddVar_SetPageText( this_ptr);
  AddVar_GetPageText( this_ptr);
  AddVar_SetPageBitmap( this_ptr);
  AddVar_GetPageBitmap( this_ptr);
  AddVar_SetSelection( this_ptr);
  AddVar_GetSelection( this_ptr);
  AddVar_Split( this_ptr);
  AddVar_GetAuiManager( this_ptr);
  AddVar_SetNormalFont( this_ptr);
  AddVar_SetSelectedFont( this_ptr);
  AddVar_SetMeasuringFont( this_ptr);
  AddVar_SetFont( this_ptr);
  AddVar_GetTabCtrlHeight( this_ptr);
  AddVar_GetHeightForPageHeight( this_ptr);
  AddVar_AdvanceSelection( this_ptr);
  AddVar_ShowWindowMenu( this_ptr);
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
void WrapClasswxAuiNotebook_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAuiNotebook");
    WrapClass_wxAuiNotebook::AddVar_wxAuiNotebook_1(amiobject->GetContext());
  WrapClass_wxAuiNotebook::AddVar_wxAuiNotebook(amiobject->GetContext());
  WrapClass_wxAuiNotebook::AddVar_wxAuiNotebook_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAuiNotebook::wxAuiNotebook()
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_wxAuiNotebook_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_wxAuiNotebook_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxAuiNotebook* _newobj = new wxAuiNotebook();
  BasicVariable::ptr res = WrapClass_wxAuiNotebook::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxAuiNotebook::wxAuiNotebook(...)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_wxAuiNotebook::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_wxAuiNotebook::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAuiNotebook::wrap_wxAuiNotebook_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAuiNotebook::wrap_wxAuiNotebook_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAuiNotebook::wxAuiNotebook(wxWindow * parent, wxWindowID id = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = wxAUI_NB_DEFAULT_STYLE)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_wxAuiNotebook_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:wxAUI_NB_DEFAULT_STYLE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_wxAuiNotebook_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    parent = parent_smtptr.get();
  }

  int id = wxID_ANY;
  if (!get_val_param<int >(id,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = wxAUI_NB_DEFAULT_STYLE;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  wxAuiNotebook* _newobj = new wxAuiNotebook(parent, id, pos, size, style);
  BasicVariable::ptr res = WrapClass_wxAuiNotebook::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxAuiNotebook::Create(wxWindow * parent, wxWindowID id = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_Create::CallMember( ParamList* _p)
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

  int id = wxID_ANY;
  if (!get_val_param<int >(id,_p,_n,false,false)) ClassHelpAndReturn;

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

  bool res =   this->_objectptr->GetObj()->Create(parent, id, pos, size, style);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiNotebook::SetWindowStyleFlag(long int style)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetWindowStyleFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
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
//  Wrapping of void wxAuiNotebook::SetArtProvider(wxAuiTabArt * art)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetArtProvider::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiTabArt, "parameter named 'art'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_SetArtProvider::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxAuiTabArt* art;
  if (CheckNullVar(_p,_n))  {
    art=(wxAuiTabArt*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxAuiTabArt > art_smtptr;
    if (!get_val_smtptr_param<wxAuiTabArt >(art_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    art = art_smtptr.get();
  }

  this->_objectptr->GetObj()->SetArtProvider(art);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxAuiTabArt * wxAuiNotebook::GetArtProvider()
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetArtProvider::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiTabArt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetArtProvider::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiTabArt * res =   this->_objectptr->GetObj()->GetArtProvider();
  BasicVariable::ptr res_var = AMILabType<wxAuiTabArt >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxAuiNotebook::SetUniformBitmapSize(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetUniformBitmapSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_SetUniformBitmapSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  this->_objectptr->GetObj()->SetUniformBitmapSize(size);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiNotebook::SetTabCtrlHeight(int height)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetTabCtrlHeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_SetTabCtrlHeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetTabCtrlHeight(height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiNotebook::AddPage(wxWindow * page, wxString const & caption, bool select = false, wxBitmap const & bitmap = wxNullBitmap)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_AddPage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'page'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'caption'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'select' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap' (def:wxNullBitmap)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_AddPage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  wxWindow* page;
  if (CheckNullVar(_p,_n))  {
    page=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > page_smtptr;
    if (!get_val_smtptr_param<wxWindow >(page_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    page = page_smtptr.get();
  }

  boost::shared_ptr<wxString > caption_smtptr;
  if (!get_val_smtptr_param<wxString >(caption_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & caption = *caption_smtptr;

  bool select = false;
  if (!get_val_param<bool >(select,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxBitmap const & bitmap = ( bitmap_smtptr.get() ? (*bitmap_smtptr) : wxNullBitmap );

  bool res =   this->_objectptr->GetObj()->AddPage(page, caption, select, bitmap);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiNotebook::InsertPage(size_t page_idx, wxWindow * page, wxString const & caption, bool select = false, wxBitmap const & bitmap = wxNullBitmap)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_InsertPage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'page_idx'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'page'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'caption'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'select' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap' (def:wxNullBitmap)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_InsertPage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  long page_idx_long;
  if (!get_val_param<long >(page_idx_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int page_idx = boost::numeric_cast<long unsigned int >(page_idx_long);

  wxWindow* page;
  if (CheckNullVar(_p,_n))  {
    page=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > page_smtptr;
    if (!get_val_smtptr_param<wxWindow >(page_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    page = page_smtptr.get();
  }

  boost::shared_ptr<wxString > caption_smtptr;
  if (!get_val_smtptr_param<wxString >(caption_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & caption = *caption_smtptr;

  bool select = false;
  if (!get_val_param<bool >(select,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxBitmap const & bitmap = ( bitmap_smtptr.get() ? (*bitmap_smtptr) : wxNullBitmap );

  bool res =   this->_objectptr->GetObj()->InsertPage(page_idx, page, caption, select, bitmap);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiNotebook::DeletePage(size_t page)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_DeletePage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'page'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_DeletePage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long page_long;
  if (!get_val_param<long >(page_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int page = boost::numeric_cast<long unsigned int >(page_long);

  bool res =   this->_objectptr->GetObj()->DeletePage(page);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiNotebook::RemovePage(size_t page)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_RemovePage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'page'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_RemovePage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long page_long;
  if (!get_val_param<long >(page_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int page = boost::numeric_cast<long unsigned int >(page_long);

  bool res =   this->_objectptr->GetObj()->RemovePage(page);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxAuiNotebook::GetPageCount()
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetPageCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetPageCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetPageCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxAuiNotebook::GetPage(size_t page_idx)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetPage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'page_idx'")
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetPage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long page_idx_long;
  if (!get_val_param<long >(page_idx_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int page_idx = boost::numeric_cast<long unsigned int >(page_idx_long);

  wxWindow * res =   this->_objectptr->GetObj()->GetPage(page_idx);
  BasicVariable::ptr res_var = AMILabType<wxWindow >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxAuiNotebook::GetPageIndex(wxWindow * page_wnd)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetPageIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'page_wnd'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetPageIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindow* page_wnd;
  if (CheckNullVar(_p,_n))  {
    page_wnd=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > page_wnd_smtptr;
    if (!get_val_smtptr_param<wxWindow >(page_wnd_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    page_wnd = page_wnd_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->GetPageIndex(page_wnd);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiNotebook::SetPageText(size_t page, wxString const & text)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetPageText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'page'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_SetPageText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long page_long;
  if (!get_val_param<long >(page_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int page = boost::numeric_cast<long unsigned int >(page_long);

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  bool res =   this->_objectptr->GetObj()->SetPageText(page, text);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxAuiNotebook::GetPageText(size_t page_idx)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetPageText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'page_idx'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetPageText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long page_idx_long;
  if (!get_val_param<long >(page_idx_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int page_idx = boost::numeric_cast<long unsigned int >(page_idx_long);

  wxString res =   this->_objectptr->GetObj()->GetPageText(page_idx);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAuiNotebook::SetPageBitmap(size_t page, wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetPageBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'page'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_SetPageBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long page_long;
  if (!get_val_param<long >(page_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int page = boost::numeric_cast<long unsigned int >(page_long);

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  bool res =   this->_objectptr->GetObj()->SetPageBitmap(page, bitmap);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxAuiNotebook::GetPageBitmap(size_t page_idx)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetPageBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'page_idx'")
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetPageBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long page_idx_long;
  if (!get_val_param<long >(page_idx_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int page_idx = boost::numeric_cast<long unsigned int >(page_idx_long);

  wxBitmap res =   this->_objectptr->GetObj()->GetPageBitmap(page_idx);
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxAuiNotebook::SetSelection(size_t new_page)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetSelection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'new_page'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_SetSelection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long new_page_long;
  if (!get_val_param<long >(new_page_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int new_page = boost::numeric_cast<long unsigned int >(new_page_long);

  size_t res =   this->_objectptr->GetObj()->SetSelection(new_page);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of int wxAuiNotebook::GetSelection()
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetSelection::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetSelection::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetSelection();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiNotebook::Split(size_t page, int direction)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_Split::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'page'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'direction'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_Split::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long page_long;
  if (!get_val_param<long >(page_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int page = boost::numeric_cast<long unsigned int >(page_long);

  int direction;
  if (!get_val_param<int >(direction,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Split(page, direction);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxAuiManager const & wxAuiNotebook::GetAuiManager()
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetAuiManager::SetParametersComments()
{
  return_comments="returning a variable of type wxAuiManager";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetAuiManager::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxAuiManager const & res =   this->_objectptr->GetObj()->GetAuiManager();
  return AMILabType<wxAuiManager >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiNotebook::SetNormalFont(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetNormalFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_SetNormalFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  this->_objectptr->GetObj()->SetNormalFont(font);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiNotebook::SetSelectedFont(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetSelectedFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_SetSelectedFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  this->_objectptr->GetObj()->SetSelectedFont(font);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAuiNotebook::SetMeasuringFont(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetMeasuringFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_SetMeasuringFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  this->_objectptr->GetObj()->SetMeasuringFont(font);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiNotebook::SetFont(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_SetFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
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
//  Wrapping of int wxAuiNotebook::GetTabCtrlHeight()
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetTabCtrlHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetTabCtrlHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetTabCtrlHeight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxAuiNotebook::GetHeightForPageHeight(int pageHeight)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetHeightForPageHeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pageHeight'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetHeightForPageHeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int pageHeight;
  if (!get_val_param<int >(pageHeight,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetHeightForPageHeight(pageHeight);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiNotebook::AdvanceSelection(bool forward = true)
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_AdvanceSelection::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'forward' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_AdvanceSelection::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool forward = true;
  if (!get_val_param<bool >(forward,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AdvanceSelection(forward);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxAuiNotebook::ShowWindowMenu()
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_ShowWindowMenu::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_ShowWindowMenu::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShowWindowMenu();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxAuiNotebook::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxAuiNotebook::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiNotebook::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

