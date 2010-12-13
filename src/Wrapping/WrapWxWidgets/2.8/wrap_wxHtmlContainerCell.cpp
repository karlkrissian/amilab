/**
 * C++ Interface: wrap_wxHtmlContainerCell
 *
 * Description: wrapping wxHtmlContainerCell
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

#include "wrap_wxHtmlContainerCell.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxHtmlContainerCell_declared
  #define wxHtmlContainerCell_declared
  AMI_DECLARE_TYPE(wxHtmlContainerCell)
#endif
#ifndef wxDC_declared
  #define wxDC_declared
  AMI_DECLARE_TYPE(wxDC)
#endif
#ifndef wxHtmlRenderingInfo_declared
  #define wxHtmlRenderingInfo_declared
  AMI_DECLARE_TYPE(wxHtmlRenderingInfo)
#endif
#ifndef wxArrayInt_declared
  #define wxArrayInt_declared
  AMI_DECLARE_TYPE(wxArrayInt)
#endif
#ifndef wxHtmlCell_declared
  #define wxHtmlCell_declared
  AMI_DECLARE_TYPE(wxHtmlCell)
#endif
#ifndef wxHtmlTag_declared
  #define wxHtmlTag_declared
  AMI_DECLARE_TYPE(wxHtmlTag)
#endif
#ifndef wxColour_declared
  #define wxColour_declared
  AMI_DECLARE_TYPE(wxColour)
#endif
#ifndef wxHtmlLinkInfo_declared
  #define wxHtmlLinkInfo_declared
  AMI_DECLARE_TYPE(wxHtmlLinkInfo)
#endif
#ifndef wxHtmlWindowInterface_declared
  #define wxHtmlWindowInterface_declared
  AMI_DECLARE_TYPE(wxHtmlWindowInterface)
#endif
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxMouseEvent_declared
  #define wxMouseEvent_declared
  AMI_DECLARE_TYPE(wxMouseEvent)
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
BasicVariable::ptr WrapClass<wxHtmlContainerCell>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlContainerCell::wrap_wxHtmlContainerCell construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxHtmlContainerCell);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlContainerCell);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxHtmlContainerCell>::CreateVar( wxHtmlContainerCell* val, bool nodeleter)
{ 
  boost::shared_ptr<wxHtmlContainerCell> obj_ptr(val,smartpointer_nodeleter<wxHtmlContainerCell>());
  return AMILabType<wxHtmlContainerCell>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlContainerCell
//
Variable<AMIObject>::ptr WrapClass_wxHtmlContainerCell::CreateVar( wxHtmlContainerCell* sp)
{
  boost::shared_ptr<wxHtmlContainerCell> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlContainerCell>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlContainerCell>::CreateVar(
      new WrapClass_wxHtmlContainerCell(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlContainerCell::AddMethods(WrapClass<wxHtmlContainerCell>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Layout( this_ptr);
  AddVar_Draw( this_ptr);
  AddVar_DrawInvisible( this_ptr);
  AddVar_AdjustPagebreak( this_ptr);
  AddVar_InsertCell( this_ptr);
  AddVar_SetAlignHor( this_ptr);
  AddVar_GetAlignHor( this_ptr);
  AddVar_SetAlignVer( this_ptr);
  AddVar_GetAlignVer( this_ptr);
  AddVar_SetIndent( this_ptr);
  AddVar_GetIndent( this_ptr);
  AddVar_GetIndentUnits( this_ptr);
  AddVar_SetAlign( this_ptr);
  AddVar_SetWidthFloat_1( this_ptr);
  AddVar_SetWidthFloat( this_ptr);
  AddVar_SetWidthFloat_2( this_ptr);
  AddVar_SetMinHeight( this_ptr);
  AddVar_SetBackgroundColour( this_ptr);
  AddVar_GetBackgroundColour( this_ptr);
  AddVar_SetBorder( this_ptr);
  AddVar_GetLink( this_ptr);
/* The following types are missing: void
  AddVar_Find( this_ptr);
*/
  AddVar_ProcessMouseClick( this_ptr);
  AddVar_GetFirstChild( this_ptr);
  AddVar_GetLastChild( this_ptr);
  AddVar_IsTerminalCell( this_ptr);
  AddVar_FindCellByPos( this_ptr);
  AddVar_GetFirstTerminal( this_ptr);
  AddVar_GetLastTerminal( this_ptr);
  AddVar_RemoveExtraSpacing( this_ptr);
  AddVar_GetMaxTotalWidth( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxHtmlCell
  boost::shared_ptr<wxHtmlCell > parent_wxHtmlCell(  boost::dynamic_pointer_cast<wxHtmlCell >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxHtmlCell = AMILabType<wxHtmlCell >::CreateVarFromSmtPtr(parent_wxHtmlCell);
  context->AddVar("wxHtmlCell",var_wxHtmlCell);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxHtmlCell = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxHtmlCell);
  context->AddDefault(obj_wxHtmlCell->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlContainerCell_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlContainerCell");
    WrapClass_wxHtmlContainerCell::AddVar_wxHtmlContainerCell(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlContainerCell::wxHtmlContainerCell(wxHtmlContainerCell * parent)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_wxHtmlContainerCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlContainerCell, "parameter named 'parent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_wxHtmlContainerCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlContainerCell* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxHtmlContainerCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlContainerCell > parent_smtptr;
    if (!get_val_smtptr_param<wxHtmlContainerCell >(parent_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
    parent = parent_smtptr.get();
  }

  wxHtmlContainerCell* _newobj = new wxHtmlContainerCell(parent);
  BasicVariable::ptr res = WrapClass_wxHtmlContainerCell::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::Layout(int w)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_Layout::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_Layout::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int w;
  if (!get_val_param<int >(w,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Layout(w);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::Draw(wxDC & dc, int x, int y, int view_y1, int view_y2, wxHtmlRenderingInfo & info)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_Draw::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'dc'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'view_y1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'view_y2'")
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingInfo, "parameter named 'info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_Draw::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > dc_smtptr;
  if (!get_val_smtptr_param<wxDC >(dc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC & dc = *dc_smtptr;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  int view_y1;
  if (!get_val_param<int >(view_y1,_p,_n,true,false)) ClassHelpAndReturn;

  int view_y2;
  if (!get_val_param<int >(view_y2,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxHtmlRenderingInfo > info_smtptr;
  if (!get_val_smtptr_param<wxHtmlRenderingInfo >(info_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlRenderingInfo & info = *info_smtptr;

  this->_objectptr->GetObj()->Draw(dc, x, y, view_y1, view_y2, info);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::DrawInvisible(wxDC & dc, int x, int y, wxHtmlRenderingInfo & info)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_DrawInvisible::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'dc'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingInfo, "parameter named 'info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_DrawInvisible::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > dc_smtptr;
  if (!get_val_smtptr_param<wxDC >(dc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC & dc = *dc_smtptr;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxHtmlRenderingInfo > info_smtptr;
  if (!get_val_smtptr_param<wxHtmlRenderingInfo >(info_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlRenderingInfo & info = *info_smtptr;

  this->_objectptr->GetObj()->DrawInvisible(dc, x, y, info);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlContainerCell::AdjustPagebreak(int * pagebreak, wxArrayInt & known_pagebreaks)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_AdjustPagebreak::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pagebreak'")
  ADDPARAMCOMMENT_TYPE( wxArrayInt, "parameter named 'known_pagebreaks'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_AdjustPagebreak::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int* pagebreak;
  if (CheckNullVar(_p,_n))  {
    pagebreak=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > pagebreak_smtptr;
    if (!get_val_smtptr_param<int >(pagebreak_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    pagebreak = pagebreak_smtptr.get();
  }

  boost::shared_ptr<wxArrayInt > known_pagebreaks_smtptr;
  if (!get_val_smtptr_param<wxArrayInt >(known_pagebreaks_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxArrayInt & known_pagebreaks = *known_pagebreaks_smtptr;

  bool res =   this->_objectptr->GetObj()->AdjustPagebreak(pagebreak, known_pagebreaks);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::InsertCell(wxHtmlCell * cell)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_InsertCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'cell'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_InsertCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlCell* cell;
  if (CheckNullVar(_p,_n))  {
    cell=(wxHtmlCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlCell > cell_smtptr;
    if (!get_val_smtptr_param<wxHtmlCell >(cell_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    cell = cell_smtptr.get();
  }

  this->_objectptr->GetObj()->InsertCell(cell);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::SetAlignHor(int al)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetAlignHor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'al'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetAlignHor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int al;
  if (!get_val_param<int >(al,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAlignHor(al);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxHtmlContainerCell::GetAlignHor()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetAlignHor::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetAlignHor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAlignHor();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::SetAlignVer(int al)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetAlignVer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'al'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetAlignVer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int al;
  if (!get_val_param<int >(al,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAlignVer(al);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxHtmlContainerCell::GetAlignVer()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetAlignVer::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetAlignVer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAlignVer();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::SetIndent(int i, int what, int units = 1)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetIndent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'what'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'units' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetIndent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  int what;
  if (!get_val_param<int >(what,_p,_n,true,false)) ClassHelpAndReturn;

  int units = 1;
  if (!get_val_param<int >(units,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetIndent(i, what, units);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxHtmlContainerCell::GetIndent(int ind)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetIndent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ind'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetIndent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int ind;
  if (!get_val_param<int >(ind,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIndent(ind);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlContainerCell::GetIndentUnits(int ind)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetIndentUnits::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ind'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetIndentUnits::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int ind;
  if (!get_val_param<int >(ind,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIndentUnits(ind);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::SetAlign(wxHtmlTag const & tag)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetAlign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlTag, "parameter named 'tag'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetAlign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlTag > tag_smtptr;
  if (!get_val_smtptr_param<wxHtmlTag >(tag_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlTag const & tag = *tag_smtptr;

  this->_objectptr->GetObj()->SetAlign(tag);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::SetWidthFloat(int w, int units)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetWidthFloat_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'units'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetWidthFloat_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int w;
  if (!get_val_param<int >(w,_p,_n,true,true)) ClassReturnEmptyVar;

  int units;
  if (!get_val_param<int >(units,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetWidthFloat(w, units);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxHtmlContainerCell::SetWidthFloat(...)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetWidthFloat::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetWidthFloat::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHtmlContainerCell::wrap_SetWidthFloat_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHtmlContainerCell::wrap_SetWidthFloat_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::SetWidthFloat(wxHtmlTag const & tag, double pixel_scale = 1.0e+0)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetWidthFloat_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlTag, "parameter named 'tag'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'pixel_scale' (def:1.0e+0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetWidthFloat_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxHtmlTag > tag_smtptr;
  if (!get_val_smtptr_param<wxHtmlTag >(tag_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxHtmlTag const & tag = *tag_smtptr;

  double pixel_scale = 1.0e+0;
  if (!get_val_param<double >(pixel_scale,_p,_n,false,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetWidthFloat(tag, pixel_scale);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::SetMinHeight(int h, int align = 4)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetMinHeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'h'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'align' (def:4)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetMinHeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int h;
  if (!get_val_param<int >(h,_p,_n,true,false)) ClassHelpAndReturn;

  int align = 4;
  if (!get_val_param<int >(align,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMinHeight(h, align);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::SetBackgroundColour(wxColour const & clr)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetBackgroundColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'clr'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetBackgroundColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > clr_smtptr;
  if (!get_val_smtptr_param<wxColour >(clr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & clr = *clr_smtptr;

  this->_objectptr->GetObj()->SetBackgroundColour(clr);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxColour wxHtmlContainerCell::GetBackgroundColour()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetBackgroundColour::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetBackgroundColour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour res =   this->_objectptr->GetObj()->GetBackgroundColour();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::SetBorder(wxColour const & clr1, wxColour const & clr2)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_SetBorder::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'clr1'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'clr2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_SetBorder::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > clr1_smtptr;
  if (!get_val_smtptr_param<wxColour >(clr1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & clr1 = *clr1_smtptr;

  boost::shared_ptr<wxColour > clr2_smtptr;
  if (!get_val_smtptr_param<wxColour >(clr2_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & clr2 = *clr2_smtptr;

  this->_objectptr->GetObj()->SetBorder(clr1, clr2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlLinkInfo * wxHtmlContainerCell::GetLink(int x = 0, int y = 0)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetLink::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y' (def:0)")
  return_comments="returning a variable of type wxHtmlLinkInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetLink::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x = 0;
  if (!get_val_param<int >(x,_p,_n,false,false)) ClassHelpAndReturn;

  int y = 0;
  if (!get_val_param<int >(y,_p,_n,false,false)) ClassHelpAndReturn;

  wxHtmlLinkInfo * res =   this->_objectptr->GetObj()->GetLink(x, y);
  BasicVariable::ptr res_var = AMILabType<wxHtmlLinkInfo >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxHtmlCell const * wxHtmlContainerCell::Find(int condition, void const * param)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_Find::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'condition'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'param'")
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_Find::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int condition;
  if (!get_val_param<int >(condition,_p,_n,true,false)) ClassHelpAndReturn;

  void* param;
  if (CheckNullVar(_p,_n))  {
    param=(void*)NULL;
    _n++;
  } else {
    boost::shared_ptr<void > param_smtptr;
    if (!get_val_smtptr_param<void >(param_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param = param_smtptr.get();
  }

  wxHtmlCell const * res =   this->_objectptr->GetObj()->Find(condition, param);
  BasicVariable::ptr res_var = AMILabType<wxHtmlCell >::CreateVar(const_cast<wxHtmlCell *>(res),true);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of bool wxHtmlContainerCell::ProcessMouseClick(wxHtmlWindowInterface * window, wxPoint const & pos, wxMouseEvent const & event)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_ProcessMouseClick::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlWindowInterface, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_ProcessMouseClick::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  wxHtmlWindowInterface* window;
  if (CheckNullVar(_p,_n))  {
    window=(wxHtmlWindowInterface*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlWindowInterface > window_smtptr;
    if (!get_val_smtptr_param<wxHtmlWindowInterface >(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    window = window_smtptr.get();
  }

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent const & event = *event_smtptr;

  bool res =   this->_objectptr->GetObj()->ProcessMouseClick(window, pos, event);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlContainerCell::GetFirstChild()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetFirstChild::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetFirstChild::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell * res =   this->_objectptr->GetObj()->GetFirstChild();
  BasicVariable::ptr res_var = AMILabType<wxHtmlCell >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlContainerCell::GetLastChild()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetLastChild::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetLastChild::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell * res =   this->_objectptr->GetObj()->GetLastChild();
  BasicVariable::ptr res_var = AMILabType<wxHtmlCell >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlContainerCell::IsTerminalCell()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_IsTerminalCell::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_IsTerminalCell::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsTerminalCell();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlContainerCell::FindCellByPos(wxCoord x, wxCoord y, unsigned int flags = wxHTML_FIND_EXACT)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_FindCellByPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags' (def:wxHTML_FIND_EXACT)")
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_FindCellByPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  long flags_long = boost::numeric_cast<long >((unsigned int)wxHTML_FIND_EXACT);;
  if (!get_val_param<long >(flags_long,_p,_n,false,false)) ClassHelpAndReturn;
  unsigned int flags = boost::numeric_cast<unsigned int >(flags_long);

  wxHtmlCell * res =   this->_objectptr->GetObj()->FindCellByPos(x, y, flags);
  BasicVariable::ptr res_var = AMILabType<wxHtmlCell >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlContainerCell::GetFirstTerminal()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetFirstTerminal::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetFirstTerminal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell * res =   this->_objectptr->GetObj()->GetFirstTerminal();
  BasicVariable::ptr res_var = AMILabType<wxHtmlCell >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlContainerCell::GetLastTerminal()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetLastTerminal::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetLastTerminal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell * res =   this->_objectptr->GetObj()->GetLastTerminal();
  BasicVariable::ptr res_var = AMILabType<wxHtmlCell >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlContainerCell::RemoveExtraSpacing(bool top, bool bottom)
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_RemoveExtraSpacing::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'top'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bottom'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_RemoveExtraSpacing::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  bool top;
  if (!get_val_param<bool >(top,_p,_n,true,false)) ClassHelpAndReturn;

  bool bottom;
  if (!get_val_param<bool >(bottom,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveExtraSpacing(top, bottom);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxHtmlContainerCell::GetMaxTotalWidth()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetMaxTotalWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetMaxTotalWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaxTotalWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlContainerCell::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlContainerCell::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlContainerCell::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

