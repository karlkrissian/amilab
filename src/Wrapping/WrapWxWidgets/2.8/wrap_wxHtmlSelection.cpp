/**
 * C++ Interface: wrap_wxHtmlSelection
 *
 * Description: wrapping wxHtmlSelection
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

#include "wrap_wxHtmlSelection.h"

// get all the required includes
// #include "..."
#ifndef wxHtmlSelection_declared
  #define wxHtmlSelection_declared
  AMI_DECLARE_TYPE(wxHtmlSelection)
#endif
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxHtmlCell_declared
  #define wxHtmlCell_declared
  AMI_DECLARE_TYPE(wxHtmlCell)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlSelection>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlSelection::wrap_wxHtmlSelection construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxHtmlSelection);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlSelection);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlSelection
//
Variable<AMIObject>::ptr WrapClass_wxHtmlSelection::CreateVar( wxHtmlSelection* sp)
{
  boost::shared_ptr<wxHtmlSelection> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlSelection>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlSelection>::CreateVar(
      new WrapClass_wxHtmlSelection(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlSelection::AddMethods(WrapClass<wxHtmlSelection>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Set_1( this_ptr);
  AddVar_Set( this_ptr);
  AddVar_Set_2( this_ptr);
  AddVar_GetFromCell( this_ptr);
  AddVar_GetToCell( this_ptr);
  AddVar_GetFromPos( this_ptr);
  AddVar_GetToPos( this_ptr);
  AddVar_GetFromPrivPos( this_ptr);
  AddVar_GetToPrivPos( this_ptr);
  AddVar_SetFromPrivPos( this_ptr);
  AddVar_SetToPrivPos( this_ptr);
  AddVar_ClearPrivPos( this_ptr);
  AddVar_IsEmpty( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlSelection_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlSelection");
    WrapClass_wxHtmlSelection::AddVar_wxHtmlSelection_1(amiobject->GetContext());
  WrapClass_wxHtmlSelection::AddVar_wxHtmlSelection(amiobject->GetContext());
  WrapClass_wxHtmlSelection::AddVar_wxHtmlSelection_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlSelection::wxHtmlSelection(wxHtmlSelection const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_wxHtmlSelection_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlSelection, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_wxHtmlSelection_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxHtmlSelection > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlSelection >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxHtmlSelection const & param0 = *param0_smtptr;

  wxHtmlSelection* _newobj = new wxHtmlSelection(param0);
  BasicVariable::ptr res = WrapClass_wxHtmlSelection::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxHtmlSelection::wxHtmlSelection(...)
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_wxHtmlSelection::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_wxHtmlSelection::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHtmlSelection::wrap_wxHtmlSelection_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHtmlSelection::wrap_wxHtmlSelection_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxHtmlSelection::wxHtmlSelection()
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_wxHtmlSelection_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_wxHtmlSelection_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxHtmlSelection* _newobj = new wxHtmlSelection();
  BasicVariable::ptr res = WrapClass_wxHtmlSelection::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxHtmlSelection.
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxHtmlSelection object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxHtmlSelection >::CreateVar( new wxHtmlSelection(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxHtmlSelection::Set(wxPoint const & fromPos, wxHtmlCell const * fromCell, wxPoint const & toPos, wxHtmlCell const * toCell)
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_Set_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'fromPos'")
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'fromCell'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'toPos'")
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'toCell'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_Set_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > fromPos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(fromPos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & fromPos = *fromPos_smtptr;

  wxHtmlCell* fromCell;
  if (CheckNullVar(_p,_n))  {
    fromCell=(wxHtmlCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlCell > fromCell_smtptr;
    if (!get_val_smtptr_param<wxHtmlCell >(fromCell_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    fromCell = fromCell_smtptr.get();
  }

  boost::shared_ptr<wxPoint > toPos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(toPos_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & toPos = *toPos_smtptr;

  wxHtmlCell* toCell;
  if (CheckNullVar(_p,_n))  {
    toCell=(wxHtmlCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlCell > toCell_smtptr;
    if (!get_val_smtptr_param<wxHtmlCell >(toCell_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    toCell = toCell_smtptr.get();
  }

  this->_objectptr->GetObj()->Set(fromPos, fromCell, toPos, toCell);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxHtmlSelection::Set(...)
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_Set::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_Set::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHtmlSelection::wrap_Set_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHtmlSelection::wrap_Set_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlSelection::Set(wxHtmlCell const * fromCell, wxHtmlCell const * toCell)
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_Set_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'fromCell'")
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'toCell'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_Set_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxHtmlCell* fromCell;
  if (CheckNullVar(_p,_n))  {
    fromCell=(wxHtmlCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlCell > fromCell_smtptr;
    if (!get_val_smtptr_param<wxHtmlCell >(fromCell_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    fromCell = fromCell_smtptr.get();
  }

  wxHtmlCell* toCell;
  if (CheckNullVar(_p,_n))  {
    toCell=(wxHtmlCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlCell > toCell_smtptr;
    if (!get_val_smtptr_param<wxHtmlCell >(toCell_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    toCell = toCell_smtptr.get();
  }

  this->_objectptr->GetObj()->Set(fromCell, toCell);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell const * wxHtmlSelection::GetFromCell()
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_GetFromCell::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_GetFromCell::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell const * res =   this->_objectptr->GetObj()->GetFromCell();
  BasicVariable::ptr res_var = AMILabType<wxHtmlCell >::CreateVar(const_cast<wxHtmlCell *>(res),true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell const * wxHtmlSelection::GetToCell()
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_GetToCell::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_GetToCell::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell const * res =   this->_objectptr->GetObj()->GetToCell();
  BasicVariable::ptr res_var = AMILabType<wxHtmlCell >::CreateVar(const_cast<wxHtmlCell *>(res),true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxPoint const & wxHtmlSelection::GetFromPos()
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_GetFromPos::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_GetFromPos::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint const & res =   this->_objectptr->GetObj()->GetFromPos();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint const & wxHtmlSelection::GetToPos()
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_GetToPos::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_GetToPos::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint const & res =   this->_objectptr->GetObj()->GetToPos();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint const & wxHtmlSelection::GetFromPrivPos()
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_GetFromPrivPos::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_GetFromPrivPos::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint const & res =   this->_objectptr->GetObj()->GetFromPrivPos();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint const & wxHtmlSelection::GetToPrivPos()
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_GetToPrivPos::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_GetToPrivPos::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint const & res =   this->_objectptr->GetObj()->GetToPrivPos();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlSelection::SetFromPrivPos(wxPoint const & pos)
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_SetFromPrivPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_SetFromPrivPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  this->_objectptr->GetObj()->SetFromPrivPos(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlSelection::SetToPrivPos(wxPoint const & pos)
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_SetToPrivPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_SetToPrivPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  this->_objectptr->GetObj()->SetToPrivPos(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlSelection::ClearPrivPos()
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_ClearPrivPos::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_ClearPrivPos::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClearPrivPos();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlSelection::IsEmpty()
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlSelection & wxHtmlSelection::operator =(wxHtmlSelection const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlSelection::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlSelection, "parameter named 'param0'")
  return_comments="returning a variable of type wxHtmlSelection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlSelection::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlSelection > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlSelection >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlSelection const & param0 = *param0_smtptr;

  wxHtmlSelection & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxHtmlSelection >::CreateVar(res);
}

