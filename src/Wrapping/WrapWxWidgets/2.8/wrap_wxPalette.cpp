/**
 * C++ Interface: wrap_wxPalette
 *
 * Description: wrapping wxPalette
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
#include "wrap_wxClassInfo.h"


#include "wrap_wxPalette.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPalette>::CreateVar( ParamList* p)
{
  WrapClass_wxPalette::wrap_wxPalette construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxPalette);
AMI_DEFINE_VARFROMSMTPTR(wxPalette);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPalette
//
Variable<AMIObject>::ptr WrapClass_wxPalette::CreateVar( wxPalette* sp)
{
  boost::shared_ptr<wxPalette> di_ptr(
    sp,
    wxwindow_nodeleter<wxPalette>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPalette>::CreateVar(
      new WrapClass_wxPalette(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPalette::AddMethods(WrapClass<wxPalette>::ptr this_ptr )
{
  
      // Add members from wxPaletteBase
      WrapClass_wxPaletteBase::ptr parent_wxPaletteBase(        boost::dynamic_pointer_cast<WrapClass_wxPaletteBase >(this_ptr));
      parent_wxPaletteBase->AddMethods(parent_wxPaletteBase);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Ok( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_Create( this_ptr);
      AddVar_GetPixel( this_ptr);
      AddVar_GetRGB( this_ptr);
      AddVar_GetColoursCount( this_ptr);
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxPalette::wxPalette(wxPalette const & param0)
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_wxPalette_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPalette, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_wxPalette_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPalette > param0_smtptr;
  if (!get_val_smtptr_param<wxPalette >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxPalette const & param0 = *param0_smtptr;

  wxPalette* _newobj = new wxPalette(param0);
  BasicVariable::ptr res = WrapClass_wxPalette::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxPalette::wxPalette(...)
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_wxPalette::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_wxPalette::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPalette::wrap_wxPalette_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPalette::wrap_wxPalette_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxPalette::wrap_wxPalette_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPalette::wxPalette()
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_wxPalette_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_wxPalette_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPalette* _newobj = new wxPalette();
  BasicVariable::ptr res = WrapClass_wxPalette::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPalette::wxPalette(int n, unsigned char const * red, unsigned char const * green, unsigned char const * blue)
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_wxPalette_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'red'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'green'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'blue'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_wxPalette_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<unsigned char > red_smtptr;
  if (!get_val_smtptr_param<unsigned char >(red_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  unsigned char* red = red_smtptr.get();

  boost::shared_ptr<unsigned char > green_smtptr;
  if (!get_val_smtptr_param<unsigned char >(green_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  unsigned char* green = green_smtptr.get();

  boost::shared_ptr<unsigned char > blue_smtptr;
  if (!get_val_smtptr_param<unsigned char >(blue_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  unsigned char* blue = blue_smtptr.get();

  wxPalette* _newobj = new wxPalette(n, red, green, blue);
  BasicVariable::ptr res = WrapClass_wxPalette::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxPalette.
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxPalette object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxPalette >::CreateVar( new wxPalette(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxPalette::Ok()
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxPalette::IsOk()
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxPalette::Create(int n, unsigned char const * red, unsigned char const * green, unsigned char const * blue)
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'red'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'green'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'blue'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<unsigned char > red_smtptr;
  if (!get_val_smtptr_param<unsigned char >(red_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* red = red_smtptr.get();

  boost::shared_ptr<unsigned char > green_smtptr;
  if (!get_val_smtptr_param<unsigned char >(green_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* green = green_smtptr.get();

  boost::shared_ptr<unsigned char > blue_smtptr;
  if (!get_val_smtptr_param<unsigned char >(blue_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* blue = blue_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Create(n, red, green, blue);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxPalette::GetPixel(unsigned char red, unsigned char green, unsigned char blue)
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_GetPixel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'red'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'green'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'blue'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_GetPixel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  unsigned char red;
  if (!get_val_param<unsigned char >(red,_p,_n,true,false)) ClassHelpAndReturn;

  unsigned char green;
  if (!get_val_param<unsigned char >(green,_p,_n,true,false)) ClassHelpAndReturn;

  unsigned char blue;
  if (!get_val_param<unsigned char >(blue,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPixel(red, green, blue);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPalette::GetRGB(int pixel, unsigned char * red, unsigned char * green, unsigned char * blue)
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_GetRGB::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pixel'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'red'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'green'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'blue'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_GetRGB::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int pixel;
  if (!get_val_param<int >(pixel,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<unsigned char > red_smtptr;
  if (!get_val_smtptr_param<unsigned char >(red_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* red = red_smtptr.get();

  boost::shared_ptr<unsigned char > green_smtptr;
  if (!get_val_smtptr_param<unsigned char >(green_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* green = green_smtptr.get();

  boost::shared_ptr<unsigned char > blue_smtptr;
  if (!get_val_smtptr_param<unsigned char >(blue_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* blue = blue_smtptr.get();

  bool res =   this->_objectptr->GetObj()->GetRGB(pixel, red, green, blue);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxPalette::GetColoursCount()
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_GetColoursCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_GetColoursCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetColoursCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxPalette::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxPalette & wxPalette::operator =(wxPalette const & param0)
//---------------------------------------------------
void WrapClass_wxPalette::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPalette, "parameter named 'param0'")
  return_comments="returning a variable of type wxPalette";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPalette::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPalette > param0_smtptr;
  if (!get_val_smtptr_param<wxPalette >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPalette const & param0 = *param0_smtptr;

  wxPalette & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxPalette >::CreateVar(res);
}

