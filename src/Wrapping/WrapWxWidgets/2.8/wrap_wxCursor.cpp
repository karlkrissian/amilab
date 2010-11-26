/**
 * C++ Interface: wrap_wxCursor
 *
 * Description: wrapping wxCursor
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
#include "wrap_wxCursor.h"
#include "wrap_wxImage.h"
#include "wrap_wxColour.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxCursor.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxCursor>::CreateVar( ParamList* p)
{
  WrapClass_wxCursor::wrap_wxCursor construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxCursor);
AMI_DEFINE_VARFROMSMTPTR(wxCursor);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxCursor
//
Variable<AMIObject>::ptr WrapClass_wxCursor::CreateVar( wxCursor* sp)
{
  boost::shared_ptr<wxCursor> di_ptr(
    sp,
    wxwindow_nodeleter<wxCursor>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxCursor>::CreateVar(
      new WrapClass_wxCursor(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxCursor::AddMethods(WrapClass<wxCursor>::ptr this_ptr )
{
  
      // Add members from wxObject
      WrapClass_wxObject::ptr parent_wxObject(        boost::dynamic_pointer_cast<WrapClass_wxObject >(this_ptr));
      parent_wxObject->AddMethods(parent_wxObject);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Ok( this_ptr);
      AddVar_IsOk( this_ptr);
/* The following types are missing: _GdkCursor
      AddVar_GetCursor( this_ptr);
*/
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxCursor::wxCursor(wxCursor const & param0)
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_wxCursor_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCursor, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_wxCursor_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCursor > param0_smtptr;
  if (!get_val_smtptr_param<wxCursor >(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxCursor const & param0 = *param0_smtptr;

  wxCursor* _newobj = new wxCursor(param0);
  BasicVariable::ptr res = WrapClass_wxCursor::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxCursor::wxCursor(...)
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_wxCursor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_wxCursor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxCursor::wrap_wxCursor_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxCursor::wrap_wxCursor_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxCursor::wrap_wxCursor_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxCursor::wrap_wxCursor_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxCursor::wrap_wxCursor_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCursor::wxCursor()
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_wxCursor_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_wxCursor_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxCursor* _newobj = new wxCursor();
  BasicVariable::ptr res = WrapClass_wxCursor::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCursor::wxCursor(int cursorId)
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_wxCursor_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cursorId'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_wxCursor_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int cursorId;
  if (!get_val_param<int >(cursorId,_p,_n)) ClassReturnEmptyVar;

  wxCursor* _newobj = new wxCursor(cursorId);
  BasicVariable::ptr res = WrapClass_wxCursor::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCursor::wxCursor(wxImage const & image)
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_wxCursor_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImage, "parameter named 'image'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_wxCursor_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxImage > image_smtptr;
  if (!get_val_smtptr_param<wxImage >(image_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxImage const & image = *image_smtptr;

  wxCursor* _newobj = new wxCursor(image);
  BasicVariable::ptr res = WrapClass_wxCursor::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCursor::wxCursor(char const * bits, int width, int height, int hotSpotX = -0x00000000000000001, int hotSpotY = -0x00000000000000001, char const * maskBits = 0l, wxColour const * fg = 0l, wxColour const * bg = 0l)
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_wxCursor_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'bits'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hotSpotX' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hotSpotY' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'maskBits' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'fg' (def:0l)")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'bg' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_wxCursor_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>8) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > bits_string;
  if (!get_val_smtptr_param<std::string >(bits_string,_p,_n)) ClassReturnEmptyVar;
  char const * bits = bits_string->c_str();

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  int hotSpotX = -0x00000000000000001;
  if (!get_val_param<int >(hotSpotX,_p,_n)) ClassReturnEmptyVar;

  int hotSpotY = -0x00000000000000001;
  if (!get_val_param<int >(hotSpotY,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string > maskBits_string;
  if (!get_val_smtptr_param<std::string >(maskBits_string,_p,_n)) ClassReturnEmptyVar;
  char const * maskBits = maskBits_string->c_str();

  boost::shared_ptr<wxColour > fg_smtptr;
  if (!get_val_smtptr_param<wxColour >(fg_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxColour* fg = fg_smtptr.get();

  boost::shared_ptr<wxColour > bg_smtptr;
  if (!get_val_smtptr_param<wxColour >(bg_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxColour* bg = bg_smtptr.get();

  wxCursor* _newobj = new wxCursor(bits, width, height, hotSpotX, hotSpotY, maskBits, fg, bg);
  BasicVariable::ptr res = WrapClass_wxCursor::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxCursor.
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxCursor object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxCursor >::CreateVar( new wxCursor(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxCursor::Ok()
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxCursor::IsOk()
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: _GdkCursor

//---------------------------------------------------
//  Wrapping of GdkCursor * wxCursor::GetCursor()
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_GetCursor::SetParametersComments()
{
  return_comments="returning a variable of type _GdkCursor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_GetCursor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GdkCursor * res =   this->_objectptr->GetObj()->GetCursor();
  return AMILabType<_GdkCursor >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxCursor::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxCursor & wxCursor::operator =(wxCursor const & param0)
//---------------------------------------------------
void WrapClass_wxCursor::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCursor, "parameter named 'param0'")
  return_comments="returning a variable of type wxCursor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCursor::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxCursor > param0_smtptr;
  if (!get_val_smtptr_param<wxCursor >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxCursor const & param0 = *param0_smtptr;

  wxCursor & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxCursor >::CreateVar(res);
}

