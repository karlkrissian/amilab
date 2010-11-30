/**
 * C++ Interface: wrap_wxImageHistogramEntry
 *
 * Description: wrapping wxImageHistogramEntry
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
#include "wrap_wxImageHistogramEntry.h"


#include "wrap_wxImageHistogramEntry.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxImageHistogramEntry>::CreateVar( ParamList* p)
{
  WrapClass_wxImageHistogramEntry::wrap_wxImageHistogramEntry construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxImageHistogramEntry);
AMI_DEFINE_VARFROMSMTPTR(wxImageHistogramEntry);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxImageHistogramEntry
//
Variable<AMIObject>::ptr WrapClass_wxImageHistogramEntry::CreateVar( wxImageHistogramEntry* sp)
{
  boost::shared_ptr<wxImageHistogramEntry> di_ptr(
    sp,
    wxwindow_nodeleter<wxImageHistogramEntry>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxImageHistogramEntry>::CreateVar(
      new WrapClass_wxImageHistogramEntry(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxImageHistogramEntry::AddMethods(WrapClass<wxImageHistogramEntry>::ptr this_ptr )
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
      // Adding public member index
      boost::shared_ptr<long unsigned int > var_index_ptr(&GetObj()->index, smartpointer_nodeleter<long unsigned int >());
      BasicVariable::ptr var_index = AMILabType<long unsigned int >::CreateVarFromSmtPtr(var_index_ptr);
      if (var_index.get()) {
        var_index->Rename("index");
        context->AddVar(var_index,context);
      }
      */
      
      /* type not available
      // Adding public member value
      boost::shared_ptr<long unsigned int > var_value_ptr(&GetObj()->value, smartpointer_nodeleter<long unsigned int >());
      BasicVariable::ptr var_value = AMILabType<long unsigned int >::CreateVarFromSmtPtr(var_value_ptr);
      if (var_value.get()) {
        var_value->Rename("value");
        context->AddVar(var_value,context);
      }
      */

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramEntry::wxImageHistogramEntry(wxImageHistogramEntry const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogramEntry::
    wrap_wxImageHistogramEntry_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramEntry, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramEntry::
    wrap_wxImageHistogramEntry_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxImageHistogramEntry > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramEntry >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxImageHistogramEntry const & param0 = *param0_smtptr;

  wxImageHistogramEntry* _newobj = new wxImageHistogramEntry(param0);
  BasicVariable::ptr res = WrapClass_wxImageHistogramEntry::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxImageHistogramEntry::wxImageHistogramEntry(...)
//---------------------------------------------------
void WrapClass_wxImageHistogramEntry::
    wrap_wxImageHistogramEntry::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramEntry::
    wrap_wxImageHistogramEntry::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImageHistogramEntry::wrap_wxImageHistogramEntry_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImageHistogramEntry::wrap_wxImageHistogramEntry_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramEntry::wxImageHistogramEntry()
//---------------------------------------------------
void WrapClass_wxImageHistogramEntry::
    wrap_wxImageHistogramEntry_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramEntry::
    wrap_wxImageHistogramEntry_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxImageHistogramEntry* _newobj = new wxImageHistogramEntry();
  BasicVariable::ptr res = WrapClass_wxImageHistogramEntry::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxImageHistogramEntry.
//---------------------------------------------------
void WrapClass_wxImageHistogramEntry::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxImageHistogramEntry object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramEntry::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxImageHistogramEntry >::CreateVar( new wxImageHistogramEntry(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxImageHistogramEntry & wxImageHistogramEntry::operator =(wxImageHistogramEntry const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogramEntry::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramEntry, "parameter named 'param0'")
  return_comments="returning a variable of type wxImageHistogramEntry";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramEntry::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHistogramEntry > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramEntry >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxImageHistogramEntry const & param0 = *param0_smtptr;

  wxImageHistogramEntry & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxImageHistogramEntry >::CreateVar(res);
}

