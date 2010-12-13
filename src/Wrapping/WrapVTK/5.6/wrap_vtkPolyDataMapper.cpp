/**
 * C++ Interface: wrap_vtkPolyDataMapper
 *
 * Description: wrapping vtkPolyDataMapper
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

#include "wrap_vtkPolyDataMapper.h"

// get all the required includes
// #include "..."
#ifndef vtkPolyDataMapper_declared
  #define vtkPolyDataMapper_declared
  AMI_DECLARE_TYPE(vtkPolyDataMapper)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkRenderer_declared
  #define vtkRenderer_declared
  AMI_DECLARE_TYPE(vtkRenderer)
#endif
#ifndef vtkActor_declared
  #define vtkActor_declared
  AMI_DECLARE_TYPE(vtkActor)
#endif
#ifndef vtkPolyData_declared
  #define vtkPolyData_declared
  AMI_DECLARE_TYPE(vtkPolyData)
#endif
#ifndef vtkAbstractMapper_declared
  #define vtkAbstractMapper_declared
  AMI_DECLARE_TYPE(vtkAbstractMapper)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkPolyDataMapper>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkPolyDataMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkPolyDataMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkPolyDataMapper>::CreateVar( vtkPolyDataMapper* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkPolyDataMapper> obj_ptr(val,smartpointer_nodeleter<vtkPolyDataMapper>());
  return AMILabType<vtkPolyDataMapper>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkPolyDataMapper
//
Variable<AMIObject>::ptr WrapClass_vtkPolyDataMapper::CreateVar( vtkPolyDataMapper* sp)
{
  boost::shared_ptr<vtkPolyDataMapper> di_ptr(
    sp,
    wxwindow_nodeleter<vtkPolyDataMapper>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkPolyDataMapper>::CreateVar(
      new WrapClass_vtkPolyDataMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkPolyDataMapper::AddMethods(WrapClass<vtkPolyDataMapper>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_Render( this_ptr);
  AddVar_SetInput( this_ptr);
  AddVar_GetInput( this_ptr);
  AddVar_Update( this_ptr);
  AddVar_SetPiece( this_ptr);
  AddVar_GetPiece( this_ptr);
  AddVar_SetNumberOfPieces( this_ptr);
  AddVar_GetNumberOfPieces( this_ptr);
  AddVar_SetNumberOfSubPieces( this_ptr);
  AddVar_GetNumberOfSubPieces( this_ptr);
  AddVar_SetGhostLevel( this_ptr);
  AddVar_GetGhostLevel( this_ptr);
  AddVar_GetBounds_1( this_ptr);
  AddVar_GetBounds( this_ptr);
  AddVar_GetBounds_2( this_ptr);
  AddVar_ShallowCopy( this_ptr);
  AddVar_MapDataArrayToVertexAttribute( this_ptr);
  AddVar_MapDataArrayToMultiTextureAttribute( this_ptr);
  AddVar_RemoveVertexAttributeMapping( this_ptr);
  AddVar_RemoveAllVertexAttributeMappings( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent vtkMapper
  boost::shared_ptr<vtkMapper > parent_vtkMapper(  boost::dynamic_pointer_cast<vtkMapper >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkMapper = AMILabType<vtkMapper >::CreateVarFromSmtPtr(parent_vtkMapper);
  context->AddVar("vtkMapper",var_vtkMapper);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkMapper = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkMapper);
  context->AddDefault(obj_vtkMapper->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkPolyDataMapper_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkPolyDataMapper");
  
  // Static methods 
  WrapClass_vtkPolyDataMapper::AddVar_New(amiobject->GetContext());
  WrapClass_vtkPolyDataMapper::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkPolyDataMapper::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkPolyDataMapper * vtkPolyDataMapper::New()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkPolyDataMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPolyDataMapper * res =   vtkPolyDataMapper::New();
  BasicVariable::ptr res_var = AMILabType<vtkPolyDataMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkPolyDataMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPolyDataMapper * vtkPolyDataMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkPolyDataMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkObjectBase* o;
  if (CheckNullVar(_p,_n))  {
    o=(vtkObjectBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObjectBase > o_smtptr;
    if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    o = o_smtptr.get();
  }

  vtkPolyDataMapper * res =   vtkPolyDataMapper::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkPolyDataMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
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
//  Wrapping of vtkPolyDataMapper * vtkPolyDataMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkPolyDataMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPolyDataMapper * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkPolyDataMapper >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
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
//  Wrapping of void vtkPolyDataMapper::Render(vtkRenderer * ren, vtkActor * act)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_Render::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( vtkActor, "parameter named 'act'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_Render::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* ren;
  if (CheckNullVar(_p,_n))  {
    ren=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > ren_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ren = ren_smtptr.get();
  }

  vtkActor* act;
  if (CheckNullVar(_p,_n))  {
    act=(vtkActor*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkActor > act_smtptr;
    if (!get_val_smtptr_param<vtkActor >(act_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    act = act_smtptr.get();
  }

  this->_objectptr->GetObj()->Render(ren, act);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::SetInput(vtkPolyData * in)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_SetInput::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkPolyData, "parameter named 'in'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_SetInput::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkPolyData* in;
  if (CheckNullVar(_p,_n))  {
    in=(vtkPolyData*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkPolyData > in_smtptr;
    if (!get_val_smtptr_param<vtkPolyData >(in_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    in = in_smtptr.get();
  }

  this->_objectptr->GetObj()->SetInput(in);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkPolyData * vtkPolyDataMapper::GetInput()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_GetInput::SetParametersComments()
{
  return_comments="returning a variable of type vtkPolyData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_GetInput::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPolyData * res =   this->_objectptr->GetObj()->GetInput();
  BasicVariable::ptr res_var = AMILabType<vtkPolyData >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::Update()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_Update::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_Update::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Update();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::SetPiece(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_SetPiece::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_SetPiece::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPiece(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataMapper::GetPiece()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_GetPiece::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_GetPiece::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPiece();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::SetNumberOfPieces(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_SetNumberOfPieces::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_SetNumberOfPieces::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNumberOfPieces(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataMapper::GetNumberOfPieces()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_GetNumberOfPieces::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_GetNumberOfPieces::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfPieces();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::SetNumberOfSubPieces(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_SetNumberOfSubPieces::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_SetNumberOfSubPieces::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNumberOfSubPieces(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataMapper::GetNumberOfSubPieces()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_GetNumberOfSubPieces::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_GetNumberOfSubPieces::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfSubPieces();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::SetGhostLevel(int _arg)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_SetGhostLevel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_SetGhostLevel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetGhostLevel(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkPolyDataMapper::GetGhostLevel()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_GetGhostLevel::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_GetGhostLevel::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetGhostLevel();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double * vtkPolyDataMapper::GetBounds()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_GetBounds_1::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_GetBounds_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  double * res =   this->_objectptr->GetObj()->GetBounds();
  return AMILabType<double >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPolyDataMapper::GetBounds(...)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_GetBounds::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_GetBounds::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPolyDataMapper::wrap_GetBounds_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkPolyDataMapper::wrap_GetBounds_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::GetBounds(double * bounds)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_GetBounds_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'bounds'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_GetBounds_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double* bounds;
  if (CheckNullVar(_p,_n))  {
    bounds=(double*)NULL;
    _n++;
  } else {
    boost::shared_ptr<double > bounds_smtptr;
    if (!get_val_smtptr_param<double >(bounds_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    bounds = bounds_smtptr.get();
  }

  this->_objectptr->GetObj()->GetBounds(bounds);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::ShallowCopy(vtkAbstractMapper * m)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_ShallowCopy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAbstractMapper, "parameter named 'm'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_ShallowCopy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkAbstractMapper* m;
  if (CheckNullVar(_p,_n))  {
    m=(vtkAbstractMapper*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAbstractMapper > m_smtptr;
    if (!get_val_smtptr_param<vtkAbstractMapper >(m_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    m = m_smtptr.get();
  }

  this->_objectptr->GetObj()->ShallowCopy(m);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::MapDataArrayToVertexAttribute(char const * vertexAttributeName, char const * dataArrayName, int fieldAssociation, int componentno = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_MapDataArrayToVertexAttribute::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'vertexAttributeName'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'dataArrayName'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'componentno' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_MapDataArrayToVertexAttribute::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > vertexAttributeName_string;
  if (!get_val_smtptr_param<std::string >(vertexAttributeName_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * vertexAttributeName = vertexAttributeName_string->c_str();

  boost::shared_ptr<std::string > dataArrayName_string;
  if (!get_val_smtptr_param<std::string >(dataArrayName_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * dataArrayName = dataArrayName_string->c_str();

  int fieldAssociation;
  if (!get_val_param<int >(fieldAssociation,_p,_n,true,false)) ClassHelpAndReturn;

  int componentno = -0x00000000000000001;
  if (!get_val_param<int >(componentno,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MapDataArrayToVertexAttribute(vertexAttributeName, dataArrayName, fieldAssociation, componentno);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::MapDataArrayToMultiTextureAttribute(int unit, char const * dataArrayName, int fieldAssociation, int componentno = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_MapDataArrayToMultiTextureAttribute::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'unit'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'dataArrayName'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'fieldAssociation'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'componentno' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_MapDataArrayToMultiTextureAttribute::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int unit;
  if (!get_val_param<int >(unit,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<std::string > dataArrayName_string;
  if (!get_val_smtptr_param<std::string >(dataArrayName_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * dataArrayName = dataArrayName_string->c_str();

  int fieldAssociation;
  if (!get_val_param<int >(fieldAssociation,_p,_n,true,false)) ClassHelpAndReturn;

  int componentno = -0x00000000000000001;
  if (!get_val_param<int >(componentno,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MapDataArrayToMultiTextureAttribute(unit, dataArrayName, fieldAssociation, componentno);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::RemoveVertexAttributeMapping(char const * vertexAttributeName)
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_RemoveVertexAttributeMapping::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'vertexAttributeName'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_RemoveVertexAttributeMapping::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > vertexAttributeName_string;
  if (!get_val_smtptr_param<std::string >(vertexAttributeName_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * vertexAttributeName = vertexAttributeName_string->c_str();

  this->_objectptr->GetObj()->RemoveVertexAttributeMapping(vertexAttributeName);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkPolyDataMapper::RemoveAllVertexAttributeMappings()
//---------------------------------------------------
void WrapClass_vtkPolyDataMapper::
    wrap_RemoveAllVertexAttributeMappings::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPolyDataMapper::
    wrap_RemoveAllVertexAttributeMappings::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllVertexAttributeMappings();
  return BasicVariable::ptr();
}

