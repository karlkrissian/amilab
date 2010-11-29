/**
 * C++ Interface: wrap_vtkVariant
 *
 * Description: wrapping vtkVariant
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
#include "wrap_vtkVariant.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_vtkStdString.h"
#include "wrap_vtkUnicodeString.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkAbstractArray.h"


#include "wrap_vtkVariant.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVariant>::CreateVar( ParamList* p)
{
  WrapClass_vtkVariant::wrap_vtkVariant construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(vtkVariant);
AMI_DEFINE_VARFROMSMTPTR(vtkVariant);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVariant
//
Variable<AMIObject>::ptr WrapClass_vtkVariant::CreateVar( vtkVariant* sp)
{
  boost::shared_ptr<vtkVariant> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVariant>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVariant>::CreateVar(
      new WrapClass_vtkVariant(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVariant::AddMethods(WrapClass<vtkVariant>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_IsValid( this_ptr);
      AddVar_IsString( this_ptr);
      AddVar_IsUnicodeString( this_ptr);
      AddVar_IsNumeric( this_ptr);
      AddVar_IsFloat( this_ptr);
      AddVar_IsDouble( this_ptr);
      AddVar_IsChar( this_ptr);
      AddVar_IsUnsignedChar( this_ptr);
      AddVar_IsSignedChar( this_ptr);
      AddVar_IsShort( this_ptr);
      AddVar_IsUnsignedShort( this_ptr);
      AddVar_IsInt( this_ptr);
      AddVar_IsUnsignedInt( this_ptr);
      AddVar_IsLong( this_ptr);
      AddVar_IsUnsignedLong( this_ptr);
      AddVar_Is__Int64( this_ptr);
      AddVar_IsUnsigned__Int64( this_ptr);
      AddVar_IsLongLong( this_ptr);
      AddVar_IsUnsignedLongLong( this_ptr);
      AddVar_IsVTKObject( this_ptr);
      AddVar_IsArray( this_ptr);
      AddVar_GetType( this_ptr);
      AddVar_GetTypeAsString( this_ptr);
      AddVar_ToString( this_ptr);
      AddVar_ToUnicodeString( this_ptr);
      AddVar_ToFloat( this_ptr);
      AddVar_ToDouble( this_ptr);
      AddVar_ToChar( this_ptr);
      AddVar_ToUnsignedChar( this_ptr);
/* The following types are missing: signed char
      AddVar_ToSignedChar( this_ptr);
*/
/* The following types are missing: short int
      AddVar_ToShort( this_ptr);
*/
      AddVar_ToUnsignedShort( this_ptr);
      AddVar_ToInt( this_ptr);
      AddVar_ToUnsignedInt( this_ptr);
      AddVar_ToLong( this_ptr);
      AddVar_ToUnsignedLong( this_ptr);
      AddVar_ToLongLong( this_ptr);
/* The following types are missing: long long unsigned int
      AddVar_ToUnsignedLongLong( this_ptr);
*/
      AddVar_ToTypeInt64( this_ptr);
/* The following types are missing: long long unsigned int
      AddVar_ToTypeUInt64( this_ptr);
*/
      AddVar_ToVTKObject( this_ptr);
      AddVar_ToArray( this_ptr);
      AddVar_IsEqual( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___equal__( this_ptr);
      AddVar___not_equal__( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkVariant* _newobj = new vtkVariant();
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor vtkVariant::vtkVariant(...)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVariant::wrap_vtkVariant_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_8 m8;
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_9 m9;
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_10 m10;
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_11 m11;
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_12 m12;
  res = m12.CallMember(_p);
  if (!m12.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_13 m13;
  res = m13.CallMember(_p);
  if (!m13.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_15 m15;
  res = m15.CallMember(_p);
  if (!m15.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_16 m16;
  res = m16.CallMember(_p);
  if (!m16.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_17 m17;
  res = m17.CallMember(_p);
  if (!m17.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_18 m18;
  res = m18.CallMember(_p);
  if (!m18.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_19 m19;
  res = m19.CallMember(_p);
  if (!m19.Get_arg_failure()) return res;
  WrapClass_vtkVariant::wrap_vtkVariant_20 m20;
  res = m20.CallMember(_p);
  if (!m20.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(vtkVariant const & other)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVariant, "parameter named 'other'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkVariant > other_smtptr;
  if (!get_val_smtptr_param<vtkVariant >(other_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  vtkVariant const & other = *other_smtptr;

  vtkVariant* _newobj = new vtkVariant(other);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(bool value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int value_int;
  if (!get_val_param<int >(value_int,_p,_n,true,true)) ClassReturnEmptyVar;
  bool value = (bool) (value_int>0.5);

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(char value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string value_string;
  if (!get_val_param<std::string >(value_string,_p,_n,true,true)) ClassReturnEmptyVar;
  char value = ' ';
if (value_string.size()>0) value = value_string[0];

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(unsigned char value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  unsigned char value;
  if (!get_val_param<unsigned char >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}
/* The following types are missing: signed char

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(signed char value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( signed char, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  signed char value;
  if (!get_val_param<signed char >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: short int

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(short int value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( short int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  short int value;
  if (!get_val_param<short int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(short unsigned int value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int value_int;
  if (!get_val_param<int >(value_int,_p,_n,true,true)) ClassReturnEmptyVar;
  short unsigned int value = boost::numeric_cast<short unsigned int >(value_int);

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(int value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int value;
  if (!get_val_param<int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(unsigned int value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long value_long;
  if (!get_val_param<long >(value_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int value = boost::numeric_cast<unsigned int >(value_long);

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(long int value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long value_long;
  if (!get_val_param<long >(value_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int value = value_long;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(long unsigned int value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long value_long;
  if (!get_val_param<long >(value_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int value = boost::numeric_cast<long unsigned int >(value_long);

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(long long int value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long value_long;
  if (!get_val_param<long >(value_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int value = boost::numeric_cast<long long int >(value_long);

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}
/* The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(long long unsigned int value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int value;
  if (!get_val_param<long long unsigned int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(float value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  float value;
  if (!get_val_param<float >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(double value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(char const * value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_17::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_17::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > value_string;
  if (!get_val_smtptr_param<std::string >(value_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * value = value_string->c_str();

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(vtkStdString value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_18::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkStdString, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_18::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkStdString value;
  if (!get_val_param<vtkStdString >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(vtkUnicodeString const & value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_19::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkUnicodeString, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_19::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkUnicodeString > value_smtptr;
  if (!get_val_smtptr_param<vtkUnicodeString >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkUnicodeString const & value = *value_smtptr;

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVariant::vtkVariant(vtkObjectBase * value)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_vtkVariant_20::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_vtkVariant_20::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > value_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkObjectBase* value = value_smtptr.get();

  vtkVariant* _newobj = new vtkVariant(value);
  BasicVariable::ptr res = WrapClass_vtkVariant::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for vtkVariant.
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the vtkVariant object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<vtkVariant >::CreateVar( new vtkVariant(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsValid()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsValid::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsValid::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsValid();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsString()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsString::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsString();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsUnicodeString()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsUnicodeString::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsUnicodeString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsUnicodeString();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsNumeric()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsNumeric::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsNumeric::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsNumeric();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsFloat()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsFloat::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsFloat::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFloat();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsDouble()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsDouble::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsDouble::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDouble();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsChar()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsChar::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsChar();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsUnsignedChar()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsUnsignedChar::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsUnsignedChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsUnsignedChar();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsSignedChar()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsSignedChar::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsSignedChar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsSignedChar();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsShort()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsShort::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsShort::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsShort();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsUnsignedShort()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsUnsignedShort::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsUnsignedShort::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsUnsignedShort();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsInt()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsInt::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsInt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsInt();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsUnsignedInt()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsUnsignedInt::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsUnsignedInt::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsUnsignedInt();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsLong()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsLong::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsLong();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsUnsignedLong()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsUnsignedLong::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsUnsignedLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsUnsignedLong();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::Is__Int64()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_Is__Int64::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_Is__Int64::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Is__Int64();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsUnsigned__Int64()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsUnsigned__Int64::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsUnsigned__Int64::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsUnsigned__Int64();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsLongLong()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsLongLong::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsLongLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsLongLong();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsUnsignedLongLong()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsUnsignedLongLong::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsUnsignedLongLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsUnsignedLongLong();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsVTKObject()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsVTKObject::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsVTKObject::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsVTKObject();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsArray()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsArray::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsArray::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsArray();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of unsigned int vtkVariant::GetType()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_GetType::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_GetType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned int res =   this->_objectptr->GetObj()->GetType();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of char const * vtkVariant::GetTypeAsString()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_GetTypeAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_GetTypeAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetTypeAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of vtkStdString vtkVariant::ToString()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToString::SetParametersComments()
{
  return_comments="returning a variable of type vtkStdString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkStdString res =   this->_objectptr->GetObj()->ToString();
  return AMILabType<vtkStdString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkUnicodeString vtkVariant::ToUnicodeString()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToUnicodeString::SetParametersComments()
{
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToUnicodeString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkUnicodeString res =   this->_objectptr->GetObj()->ToUnicodeString();
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkVariant::ToFloat(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToFloat::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToFloat::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  float res =   this->_objectptr->GetObj()->ToFloat(valid);
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of double vtkVariant::ToDouble(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToDouble::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToDouble::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  double res =   this->_objectptr->GetObj()->ToDouble(valid);
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of char vtkVariant::ToChar(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  char res =   this->_objectptr->GetObj()->ToChar(valid);
  std::string res_string = std::string(1,res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of unsigned char vtkVariant::ToUnsignedChar(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToUnsignedChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToUnsignedChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  unsigned char res =   this->_objectptr->GetObj()->ToUnsignedChar(valid);
  return AMILabType<unsigned char >::CreateVar(res);
}
/* The following types are missing: signed char

//---------------------------------------------------
//  Wrapping of signed char vtkVariant::ToSignedChar(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToSignedChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type signed char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToSignedChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  signed char res =   this->_objectptr->GetObj()->ToSignedChar(valid);
  return AMILabType<signed char >::CreateVar(res);
}
*/
/* The following types are missing: short int

//---------------------------------------------------
//  Wrapping of short int vtkVariant::ToShort(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToShort::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type short int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToShort::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  short int res =   this->_objectptr->GetObj()->ToShort(valid);
  return AMILabType<short int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of short unsigned int vtkVariant::ToUnsignedShort(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToUnsignedShort::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToUnsignedShort::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  short unsigned int res =   this->_objectptr->GetObj()->ToUnsignedShort(valid);
  int res_int = boost::numeric_cast<int >((unsigned int)res);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int vtkVariant::ToInt(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToInt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToInt::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  int res =   this->_objectptr->GetObj()->ToInt(valid);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned int vtkVariant::ToUnsignedInt(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToUnsignedInt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToUnsignedInt::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  unsigned int res =   this->_objectptr->GetObj()->ToUnsignedInt(valid);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long int vtkVariant::ToLong(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToLong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToLong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  long int res =   this->_objectptr->GetObj()->ToLong(valid);
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkVariant::ToUnsignedLong(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToUnsignedLong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToUnsignedLong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  long unsigned int res =   this->_objectptr->GetObj()->ToUnsignedLong(valid);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long long int vtkVariant::ToLongLong(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToLongLong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToLongLong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  long long int res =   this->_objectptr->GetObj()->ToLongLong(valid);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of long long unsigned int vtkVariant::ToUnsignedLongLong(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToUnsignedLongLong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type long long unsigned int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToUnsignedLongLong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  long long unsigned int res =   this->_objectptr->GetObj()->ToUnsignedLongLong(valid);
  return AMILabType<long long unsigned int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of vtkTypeInt64 vtkVariant::ToTypeInt64(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToTypeInt64::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToTypeInt64::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  vtkTypeInt64 res =   this->_objectptr->GetObj()->ToTypeInt64(valid);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of vtkTypeUInt64 vtkVariant::ToTypeUInt64(bool * valid = 0)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToTypeUInt64::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'valid' (def:0)")
  return_comments="returning a variable of type long long unsigned int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToTypeUInt64::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > valid_int;
  if (!get_val_smtptr_param<int >(valid_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  bool valid_val = (bool) (*valid_int>0.5);
  bool* valid = &valid_val;

  vtkTypeUInt64 res =   this->_objectptr->GetObj()->ToTypeUInt64(valid);
  return AMILabType<long long unsigned int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of vtkObjectBase * vtkVariant::ToVTKObject()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToVTKObject::SetParametersComments()
{
  return_comments="returning a variable of type vtkObjectBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToVTKObject::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkObjectBase * res =   this->_objectptr->GetObj()->ToVTKObject();
  BasicVariable::ptr res_var = WrapClass_vtkObjectBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkAbstractArray * vtkVariant::ToArray()
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_ToArray::SetParametersComments()
{
  return_comments="returning a variable of type vtkAbstractArray";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_ToArray::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAbstractArray * res =   this->_objectptr->GetObj()->ToArray();
  BasicVariable::ptr res_var = WrapClass_vtkAbstractArray::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::IsEqual(vtkVariant const & other)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_IsEqual::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVariant, "parameter named 'other'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_IsEqual::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVariant > other_smtptr;
  if (!get_val_smtptr_param<vtkVariant >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVariant const & other = *other_smtptr;

  bool res =   this->_objectptr->GetObj()->IsEqual(other);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of vtkVariant const & vtkVariant::operator =(vtkVariant const & other)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVariant, "parameter named 'other'")
  return_comments="returning a variable of type vtkVariant";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVariant > other_smtptr;
  if (!get_val_smtptr_param<vtkVariant >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVariant const & other = *other_smtptr;

  vtkVariant const & res =   (*this->_objectptr->GetObj()) = (other);
  return AMILabType<vtkVariant >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::operator ==(vtkVariant const & other)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVariant, "parameter named 'other'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVariant > other_smtptr;
  if (!get_val_smtptr_param<vtkVariant >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVariant const & other = *other_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (other);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool vtkVariant::operator !=(vtkVariant const & other)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVariant, "parameter named 'other'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVariant > other_smtptr;
  if (!get_val_smtptr_param<vtkVariant >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVariant const & other = *other_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (other);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool vtkVariant::<(vtkVariant const & other)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVariant, "parameter named 'other'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVariant > other_smtptr;
  if (!get_val_smtptr_param<vtkVariant >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVariant const & other = *other_smtptr;

  bool res =   this->_objectptr->GetObj()-><(other);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool vtkVariant::>(vtkVariant const & other)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVariant, "parameter named 'other'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVariant > other_smtptr;
  if (!get_val_smtptr_param<vtkVariant >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVariant const & other = *other_smtptr;

  bool res =   this->_objectptr->GetObj()->>(other);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool vtkVariant::<=(vtkVariant const & other)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVariant, "parameter named 'other'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVariant > other_smtptr;
  if (!get_val_smtptr_param<vtkVariant >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVariant const & other = *other_smtptr;

  bool res =   this->_objectptr->GetObj()-><=(other);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool vtkVariant::>=(vtkVariant const & other)
//---------------------------------------------------
void WrapClass_vtkVariant::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVariant, "parameter named 'other'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVariant::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVariant > other_smtptr;
  if (!get_val_smtptr_param<vtkVariant >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVariant const & other = *other_smtptr;

  bool res =   this->_objectptr->GetObj()->>=(other);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

