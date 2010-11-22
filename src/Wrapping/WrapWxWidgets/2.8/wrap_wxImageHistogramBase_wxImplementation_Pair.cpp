/**
 * C++ Interface: wrap_wxImageHistogramBase_wxImplementation_Pair
 *
 * Description: wrapping wxImageHistogramBase_wxImplementation_Pair
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
#include "wrap_wxImageHistogramBase_wxImplementation_Pair.h"
#include "wrap_wxImageHistogramEntry.h"


#include "wrap_wxImageHistogramBase_wxImplementation_Pair.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxImageHistogramBase_wxImplementation_Pair>::CreateVar( ParamList* p)
{
  WrapClass_wxImageHistogramBase_wxImplementation_Pair::wrap_wxImageHistogramBase_wxImplementation_Pair construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxImageHistogramBase_wxImplementation_Pair);
AMI_DEFINE_VARFROMSMTPTR(wxImageHistogramBase_wxImplementation_Pair);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxImageHistogramBase_wxImplementation_Pair
//
Variable<AMIObject>::ptr WrapClass_wxImageHistogramBase_wxImplementation_Pair::CreateVar( wxImageHistogramBase_wxImplementation_Pair* sp)
{
  boost::shared_ptr<wxImageHistogramBase_wxImplementation_Pair> di_ptr(
    sp,
    wxwindow_nodeleter<wxImageHistogramBase_wxImplementation_Pair>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxImageHistogramBase_wxImplementation_Pair>::CreateVar(
      new WrapClass_wxImageHistogramBase_wxImplementation_Pair(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_Pair::AddMethods(WrapClass<wxImageHistogramBase_wxImplementation_Pair>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 

      // Adding operators
      AddVar___assign__( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* type not available
      // Adding public member first
      boost::shared_ptr<long unsigned int > var_first_ptr(&GetObj()->first, smartpointer_nodeleter<long unsigned int >());
      BasicVariable::ptr var_first = AMILabType<long unsigned int >::CreateVarFromSmtPtr(var_first_ptr);
      if (var_first.get()) {
        var_first->Rename("first");
        context->AddVar(var_first,context);
      }
      */
      
      // Adding public member second
      boost::shared_ptr<wxImageHistogramEntry > var_second_ptr(&GetObj()->second, smartpointer_nodeleter<wxImageHistogramEntry >());
      BasicVariable::ptr var_second = AMILabType<wxImageHistogramEntry >::CreateVarFromSmtPtr(var_second_ptr);
      if (var_second.get()) {
        var_second->Rename("second");
        context->AddVar(var_second,context);
      }

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramBase_wxImplementation_Pair::wxImageHistogramBase_wxImplementation_Pair(wxImageHistogramBase_wxImplementation_Pair const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap_wxImageHistogramBase_wxImplementation_Pair_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase_wxImplementation_Pair, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap_wxImageHistogramBase_wxImplementation_Pair_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase_wxImplementation_Pair > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase_wxImplementation_Pair >(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxImageHistogramBase_wxImplementation_Pair const & param0 = *param0_smtptr;

  wxImageHistogramBase_wxImplementation_Pair* _newobj = new wxImageHistogramBase_wxImplementation_Pair(param0);
  BasicVariable::ptr res = WrapClass_wxImageHistogramBase_wxImplementation_Pair::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxImageHistogramBase_wxImplementation_Pair::wxImageHistogramBase_wxImplementation_Pair(...)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap_wxImageHistogramBase_wxImplementation_Pair::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap_wxImageHistogramBase_wxImplementation_Pair::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImageHistogramBase_wxImplementation_Pair::wrap_wxImageHistogramBase_wxImplementation_Pair_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImageHistogramBase_wxImplementation_Pair::wrap_wxImageHistogramBase_wxImplementation_Pair_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramBase_wxImplementation_Pair::wxImageHistogramBase_wxImplementation_Pair(long unsigned int const & f, wxImageHistogramEntry const & s)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap_wxImageHistogramBase_wxImplementation_Pair_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'f'")
  ADDPARAMCOMMENT_TYPE( wxImageHistogramEntry, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap_wxImageHistogramBase_wxImplementation_Pair_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long unsigned int > f_smtptr;
  if (!get_val_smtptr_param<long unsigned int >(f_smtptr,_p,_n)) ClassReturnEmptyVar;
  long unsigned int const & f = *f_smtptr;

  boost::shared_ptr<wxImageHistogramEntry > s_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramEntry >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxImageHistogramEntry const & s = *s_smtptr;

  wxImageHistogramBase_wxImplementation_Pair* _newobj = new wxImageHistogramBase_wxImplementation_Pair(f, s);
  BasicVariable::ptr res = WrapClass_wxImageHistogramBase_wxImplementation_Pair::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxImageHistogramBase_wxImplementation_Pair.
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxImageHistogramBase_wxImplementation_Pair object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxImageHistogramBase_wxImplementation_Pair >::CreateVar( new wxImageHistogramBase_wxImplementation_Pair(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxImageHistogramBase_wxImplementation_Pair & wxImageHistogramBase_wxImplementation_Pair::operator =(wxImageHistogramBase_wxImplementation_Pair const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase_wxImplementation_Pair, "parameter named 'param0'")
  return_comments="returning a variable of type wxImageHistogramBase_wxImplementation_Pair";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_Pair::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase_wxImplementation_Pair > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase_wxImplementation_Pair >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxImageHistogramBase_wxImplementation_Pair const & param0 = *param0_smtptr;

  wxImageHistogramBase_wxImplementation_Pair & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxImageHistogramBase_wxImplementation_Pair >::CreateVar(res);
}

