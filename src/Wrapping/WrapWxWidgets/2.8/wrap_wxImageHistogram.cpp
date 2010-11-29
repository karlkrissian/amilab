/**
 * C++ Interface: wrap_wxImageHistogram
 *
 * Description: wrapping wxImageHistogram
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
#include "wrap_wxImageHistogram.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_wxImageHistogram.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxImageHistogram>::CreateVar( ParamList* p)
{
  WrapClass_wxImageHistogram::wrap_wxImageHistogram construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxImageHistogram);
AMI_DEFINE_VARFROMSMTPTR(wxImageHistogram);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxImageHistogram
//
Variable<AMIObject>::ptr WrapClass_wxImageHistogram::CreateVar( wxImageHistogram* sp)
{
  boost::shared_ptr<wxImageHistogram> di_ptr(
    sp,
    wxwindow_nodeleter<wxImageHistogram>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxImageHistogram>::CreateVar(
      new WrapClass_wxImageHistogram(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxImageHistogram::AddMethods(WrapClass<wxImageHistogram>::ptr this_ptr )
{
  
      // Add members from wxImageHistogramBase
      WrapClass_wxImageHistogramBase::ptr parent_wxImageHistogramBase(        boost::dynamic_pointer_cast<WrapClass_wxImageHistogramBase >(this_ptr));
      parent_wxImageHistogramBase->AddMethods(parent_wxImageHistogramBase);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_FindFirstUnusedColour( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogram::wxImageHistogram(wxImageHistogram const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogram::
    wrap_wxImageHistogram_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogram, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogram::
    wrap_wxImageHistogram_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxImageHistogram > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogram >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxImageHistogram const & param0 = *param0_smtptr;

  wxImageHistogram* _newobj = new wxImageHistogram(param0);
  BasicVariable::ptr res = WrapClass_wxImageHistogram::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxImageHistogram::wxImageHistogram(...)
//---------------------------------------------------
void WrapClass_wxImageHistogram::
    wrap_wxImageHistogram::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogram::
    wrap_wxImageHistogram::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImageHistogram::wrap_wxImageHistogram_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImageHistogram::wrap_wxImageHistogram_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogram::wxImageHistogram()
//---------------------------------------------------
void WrapClass_wxImageHistogram::
    wrap_wxImageHistogram_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogram::
    wrap_wxImageHistogram_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxImageHistogram* _newobj = new wxImageHistogram();
  BasicVariable::ptr res = WrapClass_wxImageHistogram::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of long unsigned int wxImageHistogram::MakeKey(unsigned char r, unsigned char g, unsigned char b)
//---------------------------------------------------
void WrapClass_wxImageHistogram::
    wrap_static_MakeKey::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogram::
    wrap_static_MakeKey::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  unsigned char r;
  if (!get_val_param<unsigned char >(r,_p,_n,true,false)) ClassHelpAndReturn;

  unsigned char g;
  if (!get_val_param<unsigned char >(g,_p,_n,true,false)) ClassHelpAndReturn;

  unsigned char b;
  if (!get_val_param<unsigned char >(b,_p,_n,true,false)) ClassHelpAndReturn;

  long unsigned int res =   wxImageHistogram::MakeKey(r, g, b);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxImageHistogram.
//---------------------------------------------------
void WrapClass_wxImageHistogram::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxImageHistogram object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogram::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxImageHistogram >::CreateVar( new wxImageHistogram(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxImageHistogram::FindFirstUnusedColour(unsigned char * r, unsigned char * g, unsigned char * b, unsigned char startR = 1, unsigned char startG = 0, unsigned char startB = 0)
//---------------------------------------------------
void WrapClass_wxImageHistogram::
    wrap_FindFirstUnusedColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'startR' (def:1)")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'startG' (def:0)")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'startB' (def:0)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogram::
    wrap_FindFirstUnusedColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<unsigned char > r_smtptr;
  if (!get_val_smtptr_param<unsigned char >(r_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* r = r_smtptr.get();

  boost::shared_ptr<unsigned char > g_smtptr;
  if (!get_val_smtptr_param<unsigned char >(g_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* g = g_smtptr.get();

  boost::shared_ptr<unsigned char > b_smtptr;
  if (!get_val_smtptr_param<unsigned char >(b_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned char* b = b_smtptr.get();

  unsigned char startR = 1;
  if (!get_val_param<unsigned char >(startR,_p,_n,false,false)) ClassHelpAndReturn;

  unsigned char startG = 0;
  if (!get_val_param<unsigned char >(startG,_p,_n,false,false)) ClassHelpAndReturn;

  unsigned char startB = 0;
  if (!get_val_param<unsigned char >(startB,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->FindFirstUnusedColour(r, g, b, startR, startG, startB);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxImageHistogram & wxImageHistogram::operator =(wxImageHistogram const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogram::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogram, "parameter named 'param0'")
  return_comments="returning a variable of type wxImageHistogram";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogram::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHistogram > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogram >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxImageHistogram const & param0 = *param0_smtptr;

  wxImageHistogram & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxImageHistogram >::CreateVar(res);
}

