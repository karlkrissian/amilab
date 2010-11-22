/**
 * C++ Interface: wrap_wxColour
 *
 * Description: wrapping wxColour
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
#include "wrap_wxColour.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxString.h"
#include "stdlib.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxColour.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxColour>::CreateVar( ParamList* p)
{
  WrapClass_wxColour::wrap_wxColour construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxColour);
AMI_DEFINE_VARFROMSMTPTR(wxColour);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxColour
//
Variable<AMIObject>::ptr WrapClass_wxColour::CreateVar( wxColour* sp)
{
  boost::shared_ptr<wxColour> di_ptr(
    sp,
    wxwindow_nodeleter<wxColour>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxColour>::CreateVar(
      new WrapClass_wxColour(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxColour::AddMethods(WrapClass<wxColour>::ptr this_ptr )
{
  
      // Add members from wxColourBase
      WrapClass_wxColourBase::ptr parent_wxColourBase(        boost::dynamic_pointer_cast<WrapClass_wxColourBase >(this_ptr));
      parent_wxColourBase->AddMethods(parent_wxColourBase);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Ok( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_Red( this_ptr);
      AddVar_Green( this_ptr);
      AddVar_Blue( this_ptr);
      AddVar_Alpha( this_ptr);
/* The following types are missing: _GdkColormap
      AddVar_CalcPixel( this_ptr);
*/
      AddVar_GetPixel( this_ptr);
/* The following types are missing: _GdkColor
      AddVar_GetColor( this_ptr);
*/
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___equal__( this_ptr);
      AddVar___not_equal__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxColour::wxColour(wxColour const & param0)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_wxColour_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_wxColour_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxColour > param0_smtptr;
  if (!get_val_smtptr_param<wxColour >(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxColour const & param0 = *param0_smtptr;

  wxColour* _newobj = new wxColour(param0);
  BasicVariable::ptr res = WrapClass_wxColour::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxColour::wxColour(...)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_wxColour::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_wxColour::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxColour::wrap_wxColour_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxColour::wrap_wxColour_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxColour::wrap_wxColour_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxColour::wrap_wxColour_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxColour::wrap_wxColour_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxColour::wrap_wxColour_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxColour::wxColour()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_wxColour_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_wxColour_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxColour* _newobj = new wxColour();
  BasicVariable::ptr res = WrapClass_wxColour::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxColour::wxColour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = wxALPHA_OPAQUE)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_wxColour_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'red'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'green'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'blue'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'alpha' (def:wxALPHA_OPAQUE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_wxColour_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  unsigned char red;
  if (!get_val_param<unsigned char >(red,_p,_n)) ClassReturnEmptyVar;

  unsigned char green;
  if (!get_val_param<unsigned char >(green,_p,_n)) ClassReturnEmptyVar;

  unsigned char blue;
  if (!get_val_param<unsigned char >(blue,_p,_n)) ClassReturnEmptyVar;

  unsigned char alpha = wxALPHA_OPAQUE;
  if (!get_val_param<unsigned char >(alpha,_p,_n)) ClassReturnEmptyVar;

  wxColour* _newobj = new wxColour(red, green, blue, alpha);
  BasicVariable::ptr res = WrapClass_wxColour::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxColour::wxColour(long unsigned int colRGB)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_wxColour_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'colRGB'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_wxColour_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long colRGB_long;
  if (!get_val_param<long >(colRGB_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int colRGB = boost::numeric_cast<long unsigned int >(colRGB_long);

  wxColour* _newobj = new wxColour(colRGB);
  BasicVariable::ptr res = WrapClass_wxColour::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxColour::wxColour(wxString const & colourName)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_wxColour_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'colourName'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_wxColour_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > colourName_smtptr;
  if (!get_val_smtptr_param<wxString >(colourName_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & colourName = *colourName_smtptr;

  wxColour* _newobj = new wxColour(colourName);
  BasicVariable::ptr res = WrapClass_wxColour::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxColour::wxColour(wxChar const * colourName)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_wxColour_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'colourName'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_wxColour_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > colourName_string;
  if (!get_val_smtptr_param<std::string >(colourName_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t colourName[colourName_string->size()+1];
mbstowcs(colourName,colourName_string->c_str(),colourName_string->size()+1);

  wxColour* _newobj = new wxColour(colourName);
  BasicVariable::ptr res = WrapClass_wxColour::CreateVar(_newobj);
  return res;
}
/* The following types are missing: _GdkColor

//---------------------------------------------------
//  Wrapping of Constructor wxColour::wxColour(GdkColor const & gdkColor)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_wxColour_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GdkColor, "parameter named 'gdkColor'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_wxColour_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<_GdkColor > gdkColor_smtptr;
  if (!get_val_smtptr_param<_GdkColor >(gdkColor_smtptr,_p,_n)) ClassReturnEmptyVar;
  GdkColor const & gdkColor = *gdkColor_smtptr;

  wxColour* _newobj = new wxColour(gdkColor);
  BasicVariable::ptr res = WrapClass_wxColour::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxColour.
//---------------------------------------------------
void WrapClass_wxColour::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxColour object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxColour >::CreateVar( new wxColour(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxColour::Ok()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxColour::IsOk()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxColour::Red()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_Red::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_Red::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->Red();
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxColour::Green()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_Green::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_Green::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->Green();
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxColour::Blue()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_Blue::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_Blue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->Blue();
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxColour::Alpha()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_Alpha::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_Alpha::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->Alpha();
  return AMILabType<unsigned char >::CreateVar(res);
}
/* The following types are missing: _GdkColormap

//---------------------------------------------------
//  Wrapping of void wxColour::CalcPixel(GdkColormap * cmap)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_CalcPixel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GdkColormap, "parameter named 'cmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_CalcPixel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<_GdkColormap > cmap_smtptr;
  if (!get_val_smtptr_param<_GdkColormap >(cmap_smtptr,_p,_n)) ClassHelpAndReturn;
  _GdkColormap* cmap = cmap_smtptr.get();

  this->_objectptr->GetObj()->CalcPixel(cmap);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of int wxColour::GetPixel()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_GetPixel::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_GetPixel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPixel();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: _GdkColor

//---------------------------------------------------
//  Wrapping of GdkColor const * wxColour::GetColor()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_GetColor::SetParametersComments()
{
  return_comments="returning a variable of type _GdkColor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_GetColor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GdkColor const * res =   this->_objectptr->GetObj()->GetColor();
  return AMILabType<_GdkColor >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxColour::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxColour::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxColour & wxColour::operator =(wxColour const & param0)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'param0'")
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > param0_smtptr;
  if (!get_val_smtptr_param<wxColour >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxColour const & param0 = *param0_smtptr;

  wxColour & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxColour::operator ==(wxColour const & col)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'col'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > col_smtptr;
  if (!get_val_smtptr_param<wxColour >(col_smtptr,_p,_n)) ClassHelpAndReturn;
  wxColour const & col = *col_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (col);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxColour::operator !=(wxColour const & col)
//---------------------------------------------------
void WrapClass_wxColour::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'col'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > col_smtptr;
  if (!get_val_smtptr_param<wxColour >(col_smtptr,_p,_n)) ClassHelpAndReturn;
  wxColour const & col = *col_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (col);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

