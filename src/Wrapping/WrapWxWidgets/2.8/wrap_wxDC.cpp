/**
 * C++ Interface: wrap_wxDC
 *
 * Description: wrapping wxDC
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
#include "wrap_wxPalette.h"
#include "wrap_wxSize.h"
#include "wrap_wxString.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxDC.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxDC>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxDC);
AMI_DEFINE_VARFROMSMTPTR(wxDC);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxDC>::CreateVar( wxDC* val, bool nodeleter)
{ 
  boost::shared_ptr<wxDC> obj_ptr(val,smartpointer_nodeleter<wxDC>());
  return AMILabType<wxDC>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDC
//
Variable<AMIObject>::ptr WrapClass_wxDC::CreateVar( wxDC* sp)
{
  boost::shared_ptr<wxDC> di_ptr(
    sp,
    wxwindow_nodeleter<wxDC>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDC>::CreateVar(
      new WrapClass_wxDC(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDC::AddMethods(WrapClass<wxDC>::ptr this_ptr )
{
  
      // Add members from wxDCBase
      WrapClass_wxDCBase::ptr parent_wxDCBase(        boost::dynamic_pointer_cast<WrapClass_wxDCBase >(this_ptr));
      parent_wxDCBase->AddMethods(parent_wxDCBase);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_SetColourMap( this_ptr);
      AddVar_GetPPI( this_ptr);
      AddVar_StartDoc( this_ptr);
      AddVar_EndDoc( this_ptr);
      AddVar_StartPage( this_ptr);
      AddVar_EndPage( this_ptr);
      AddVar_SetMapMode( this_ptr);
      AddVar_SetUserScale( this_ptr);
      AddVar_SetLogicalScale( this_ptr);
      AddVar_SetLogicalOrigin( this_ptr);
      AddVar_SetDeviceOrigin( this_ptr);
      AddVar_SetAxisOrientation( this_ptr);
      AddVar_ComputeScaleAndOrigin( this_ptr);
/* The following types are missing: _GdkDrawable
      AddVar_GetGDKWindow( this_ptr);
*/
      AddVar_GetSelectedBitmap( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member m_mm_to_pix_x
      boost::shared_ptr<double > var_m_mm_to_pix_x_ptr(&GetObj()->m_mm_to_pix_x, smartpointer_nodeleter<double >());
      BasicVariable::ptr var_m_mm_to_pix_x = AMILabType<double >::CreateVarFromSmtPtr(var_m_mm_to_pix_x_ptr);
      if (var_m_mm_to_pix_x.get()) {
        var_m_mm_to_pix_x->Rename("m_mm_to_pix_x");
        context->AddVar(var_m_mm_to_pix_x,context);
      }
      
      // Adding public member m_mm_to_pix_y
      boost::shared_ptr<double > var_m_mm_to_pix_y_ptr(&GetObj()->m_mm_to_pix_y, smartpointer_nodeleter<double >());
      BasicVariable::ptr var_m_mm_to_pix_y = AMILabType<double >::CreateVarFromSmtPtr(var_m_mm_to_pix_y_ptr);
      if (var_m_mm_to_pix_y.get()) {
        var_m_mm_to_pix_y->Rename("m_mm_to_pix_y");
        context->AddVar(var_m_mm_to_pix_y,context);
      }
      
      /* type not available
      // Adding public member m_needComputeScaleX
      boost::shared_ptr<bool > var_m_needComputeScaleX_ptr(&GetObj()->m_needComputeScaleX, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_needComputeScaleX = AMILabType<bool >::CreateVarFromSmtPtr(var_m_needComputeScaleX_ptr);
      if (var_m_needComputeScaleX.get()) {
        var_m_needComputeScaleX->Rename("m_needComputeScaleX");
        context->AddVar(var_m_needComputeScaleX,context);
      }
      */
      
      /* type not available
      // Adding public member m_needComputeScaleY
      boost::shared_ptr<bool > var_m_needComputeScaleY_ptr(&GetObj()->m_needComputeScaleY, smartpointer_nodeleter<bool >());
      BasicVariable::ptr var_m_needComputeScaleY = AMILabType<bool >::CreateVarFromSmtPtr(var_m_needComputeScaleY_ptr);
      if (var_m_needComputeScaleY.get()) {
        var_m_needComputeScaleY->Rename("m_needComputeScaleY");
        context->AddVar(var_m_needComputeScaleY,context);
      }
      */

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxDC::SetColourMap(wxPalette const & palette)
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_SetColourMap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPalette, "parameter named 'palette'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_SetColourMap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPalette > palette_smtptr;
  if (!get_val_smtptr_param<wxPalette >(palette_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPalette const & palette = *palette_smtptr;

  this->_objectptr->GetObj()->SetColourMap(palette);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxDC::GetPPI()
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_GetPPI::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_GetPPI::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetPPI();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxDC::StartDoc(wxString const & param0)
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_StartDoc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_StartDoc::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > param0_smtptr;
  if (!get_val_smtptr_param<wxString >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & param0 = *param0_smtptr;

  bool res =   this->_objectptr->GetObj()->StartDoc(param0);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxDC::EndDoc()
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_EndDoc::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_EndDoc::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndDoc();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDC::StartPage()
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_StartPage::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_StartPage::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StartPage();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDC::EndPage()
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_EndPage::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_EndPage::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->EndPage();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDC::SetMapMode(int mode)
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_SetMapMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mode'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_SetMapMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int mode;
  if (!get_val_param<int >(mode,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMapMode(mode);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDC::SetUserScale(double x, double y)
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_SetUserScale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_SetUserScale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUserScale(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDC::SetLogicalScale(double x, double y)
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_SetLogicalScale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_SetLogicalScale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  double x;
  if (!get_val_param<double >(x,_p,_n,true,false)) ClassHelpAndReturn;

  double y;
  if (!get_val_param<double >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLogicalScale(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDC::SetLogicalOrigin(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_SetLogicalOrigin::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_SetLogicalOrigin::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLogicalOrigin(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDC::SetDeviceOrigin(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_SetDeviceOrigin::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_SetDeviceOrigin::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDeviceOrigin(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDC::SetAxisOrientation(bool xLeftRight, bool yBottomUp)
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_SetAxisOrientation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xLeftRight'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yBottomUp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_SetAxisOrientation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int xLeftRight_int;
  if (!get_val_param<int >(xLeftRight_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool xLeftRight = (bool) (xLeftRight_int>0.5);

  int yBottomUp_int;
  if (!get_val_param<int >(yBottomUp_int,_p,_n,true,false)) ClassHelpAndReturn;
  bool yBottomUp = (bool) (yBottomUp_int>0.5);

  this->_objectptr->GetObj()->SetAxisOrientation(xLeftRight, yBottomUp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDC::ComputeScaleAndOrigin()
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_ComputeScaleAndOrigin::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_ComputeScaleAndOrigin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ComputeScaleAndOrigin();
  return BasicVariable::ptr();
}
/* The following types are missing: _GdkDrawable

//---------------------------------------------------
//  Wrapping of GdkWindow * wxDC::GetGDKWindow()
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_GetGDKWindow::SetParametersComments()
{
  return_comments="returning a variable of type _GdkDrawable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_GetGDKWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GdkWindow * res =   this->_objectptr->GetObj()->GetGDKWindow();
  return AMILabType<_GdkDrawable >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of wxBitmap wxDC::GetSelectedBitmap()
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_GetSelectedBitmap::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_GetSelectedBitmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->GetSelectedBitmap();
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxDC::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxDC::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDC::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

