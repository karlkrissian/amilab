/**
 * C++ Interface: wrap_vtkRendererCollection
 *
 * Description: wrapping vtkRendererCollection
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
#include "wrap_vtkRendererCollection.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkRenderer.h"


#include "wrap_vtkRendererCollection.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkRendererCollection>::CreateVar( ParamList* p)
{
  WrapClass_vtkRendererCollection::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkRendererCollection);
AMI_DEFINE_VARFROMSMTPTR(vtkRendererCollection);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkRendererCollection>::CreateVar( vtkRendererCollection* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkRendererCollection> obj_ptr(val,smartpointer_nodeleter<vtkRendererCollection>());
  return AMILabType<vtkRendererCollection>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkRendererCollection
//
Variable<AMIObject>::ptr WrapClass_vtkRendererCollection::CreateVar( vtkRendererCollection* sp)
{
  boost::shared_ptr<vtkRendererCollection> di_ptr(
    sp,
    wxwindow_nodeleter<vtkRendererCollection>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkRendererCollection>::CreateVar(
      new WrapClass_vtkRendererCollection(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkRendererCollection::AddMethods(WrapClass<vtkRendererCollection>::ptr this_ptr )
{
  
      // Add members from vtkCollection
      WrapClass_vtkCollection::ptr parent_vtkCollection(        boost::dynamic_pointer_cast<WrapClass_vtkCollection >(this_ptr));
      parent_vtkCollection->AddMethods(parent_vtkCollection);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_AddItem( this_ptr);
      AddVar_GetNextItem( this_ptr);
      AddVar_Render( this_ptr);
      AddVar_GetFirstRenderer( this_ptr);
/* The following types are missing: void
      AddVar_GetNextRenderer( this_ptr);
*/



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkRendererCollection::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkRendererCollection");
  
  // Static methods 
  WrapClass_vtkRendererCollection::AddVar_New(amiobject->GetContext());
  WrapClass_vtkRendererCollection::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkRendererCollection::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkRendererCollection * vtkRendererCollection::New()
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkRendererCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRendererCollection * res =   vtkRendererCollection::New();
  BasicVariable::ptr res_var = WrapClass_vtkRendererCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkRendererCollection::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkRendererCollection::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkRendererCollection * vtkRendererCollection::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkRendererCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkRendererCollection * res =   vtkRendererCollection::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkRendererCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkRendererCollection::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkRendererCollection * vtkRendererCollection::NewInstance()
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkRendererCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRendererCollection * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkRendererCollection::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkRendererCollection::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRendererCollection::AddItem(vtkRenderer * a)
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_AddItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_AddItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > a_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(a_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* a = a_smtptr.get();

  this->_objectptr->GetObj()->AddItem(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkRenderer * vtkRendererCollection::GetNextItem()
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_GetNextItem::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_GetNextItem::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderer * res =   this->_objectptr->GetObj()->GetNextItem();
  BasicVariable::ptr res_var = WrapClass_vtkRenderer::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkRendererCollection::Render()
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_Render::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_Render::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Render();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkRenderer * vtkRendererCollection::GetFirstRenderer()
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_GetFirstRenderer::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_GetFirstRenderer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderer * res =   this->_objectptr->GetObj()->GetFirstRenderer();
  BasicVariable::ptr res_var = WrapClass_vtkRenderer::CreateVar(res);
  return res_var;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of vtkRenderer * vtkRendererCollection::GetNextRenderer(vtkCollectionSimpleIterator & cookie)
//---------------------------------------------------
void WrapClass_vtkRendererCollection::
    wrap_GetNextRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'cookie'")
  return_comments="returning a variable of type vtkRenderer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRendererCollection::
    wrap_GetNextRenderer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<void > cookie_smtptr;
  if (!get_val_smtptr_param<void >(cookie_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkCollectionSimpleIterator & cookie = *cookie_smtptr;

  vtkRenderer * res =   this->_objectptr->GetObj()->GetNextRenderer(cookie);
  BasicVariable::ptr res_var = WrapClass_vtkRenderer::CreateVar(res);
  return res_var;
}
*/

