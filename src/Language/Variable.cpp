
#include "DefineClass.hpp"
#include "Variable.hpp"

//#include "ParamBox.hpp"
#include "ParamPanel.hpp"
#include "DessinImage.hpp"
#include "Viewer3D.hpp"
#include "ami_function.h"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_cpp_object.h"
#include "FloatMatrix.hpp"
#include "wrapfunction_class.h"
#include "amilab_messages.h"
#include "VarArray.h"

#include <string>

using namespace std;

extern unsigned char       GB_debug;

using namespace std;

#define VARTYPE_PROP(type,name,isnum) \
  template<> vartype GetVarType<type>()  { return name;     } \
  template<> bool IsNumerical  <type>()  { return isnum; }


VARTYPE_PROP( InrImage,             type_image,           false)
VARTYPE_PROP( float,                type_float,           true)
VARTYPE_PROP( int,                  type_int,             true)
VARTYPE_PROP( unsigned char,        type_uchar,           true)
VARTYPE_PROP( std::string,          type_string,          false)
VARTYPE_PROP( DessinImage,          type_imagedraw,       false)
VARTYPE_PROP( SurfacePoly,          type_surface,         false)
VARTYPE_PROP( Viewer3D,             type_surfdraw,        false)
VARTYPE_PROP( FILE,                 type_file,            false)
VARTYPE_PROP( C_wrap_procedure,     type_c_procedure,     false)
VARTYPE_PROP( WrapClassMember,      type_class_member,    false)
VARTYPE_PROP( C_wrap_imagefunction, type_c_image_function,false)
VARTYPE_PROP( C_wrap_varfunction,   type_c_function,      false)
VARTYPE_PROP( AMIFunction,          type_ami_function,    false)
VARTYPE_PROP( AMIClass,             type_ami_class,       false)
VARTYPE_PROP( AMIObject,            type_ami_object,      false)
VARTYPE_PROP( AMICPPObject,         type_ami_cpp_object,  false)
VARTYPE_PROP( FloatMatrix,          type_matrix,          false)
VARTYPE_PROP( GLTransfMatrix,       type_gltransform,     false)
VARTYPE_PROP( VarArray,             type_array,           false)

#undef VARTYPE_PROP

//------------------------------------------------------
//------- Variable<float>
//------------------------------------------------------

//------------------------------------------------
template <>
std::string Variable<float>::GetValueAsString() const
{
  return (boost::format("%1%")%(*this->Pointer())).str();
}

template <>
double Variable<float>::GetValueAsDouble() const
{
  return (double) Value();
}

#include "Variable_float.cpp"

//------------------------------------------------------
//------- Variable<unsigned char>
//------------------------------------------------------

//------------------------------------------------
template <>
std::string Variable<unsigned char>::GetValueAsString() const
{
 //  CLASS_MESSAGE("...");
 return (boost::format("%1%")%((int)Value())).str();
}

template <>
double Variable<unsigned char>::GetValueAsDouble() const
{
  return (double) Value();
}

//------------------------------------------------------
//------- Variable<int>
//------------------------------------------------------

//------------------------------------------------
template <>
std::string Variable<int>::GetValueAsString() const
{
  //CLASS_MESSAGE("...");
  return (boost::format("%1%")%(Value())).str();
}

template <>
double Variable<int>::GetValueAsDouble() const
{
  return (double) Value();
}

//------------------------------------------------------
//------- Variable<string>
//------------------------------------------------------


//------------------------------------------------
template <>
std::string Variable<string>::GetValueAsString() const
{
  return (boost::format("%1%")%(*this->Pointer())).str();
}

// instantiate + operator
/*
template<>
BasicVariable::ptr operator +(const boost::shared_ptr<Variable<float> >& a, 
                              const boost::shared_ptr<Variable<float> >& b);
*/