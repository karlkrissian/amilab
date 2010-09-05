
#include "DefineClass.hpp"
#include "Variable.hpp"

#include "FloatMatrix.hpp"

//#include "ParamBox.hpp"
/*
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
*/

#include <string>

using namespace std;

extern unsigned char       GB_debug;

using namespace std;

// forward class declarations
class InrImage;
class DessinImage;


class Viewer3D;
//class C_wrap_procedure;
class WrapClassMember;
//class C_wrap_imagefunction;
//class C_wrap_varfunction;
class AMIFunction;
class AMIClass;
class AMIObject;
class FloatMatrix;
class GLTransfMatrix;
class VarArray;

#include "VarArray.h"


#define VARTYPE_PROP(type,name,isnum) \
  template<> AMI_DLLEXPORT vartype GetVarType<type>()  { return name;     } \
  template<> AMI_DLLEXPORT bool IsNumerical  <type>()  { return isnum;    }


VARTYPE_PROP( InrImage,             type_image,           false);
VARTYPE_PROP( float,                type_float,           true);
VARTYPE_PROP( double,               type_double,          true); /// New (added: 24/05/2010)
VARTYPE_PROP( long,                 type_long,            true); /// New (added: 27/05/2010)
VARTYPE_PROP( int,                  type_int,             true);
VARTYPE_PROP( unsigned char,        type_uchar,           true)
VARTYPE_PROP( std::string,          type_string,          false)
//VARTYPE_PROP( Viewer3D,             type_surfdraw,        false)
VARTYPE_PROP( FILE,                 type_file,            false)
VARTYPE_PROP( C_wrap_procedure,     type_c_procedure,     false)
VARTYPE_PROP( WrapClassMember,      type_class_member,    false)
VARTYPE_PROP( C_wrap_imagefunction, type_c_image_function,false)
VARTYPE_PROP( C_wrap_varfunction,   type_c_function,      false)
VARTYPE_PROP( AMIFunction,          type_ami_function,    false)
VARTYPE_PROP( AMIClass,             type_ami_class,       false)
VARTYPE_PROP( AMIObject,            type_ami_object,      false)
//VARTYPE_PROP( ,         type_ami_cpp_object,  false)
VARTYPE_PROP( FloatMatrix,          type_matrix,          false)
//VARTYPE_PROP( GLTransfMatrix,       type_gltransform,     false)
VARTYPE_PROP( VarArray,             type_array,           false)

#undef VARTYPE_PROP


#define VARTYPE_STRING_DOUBLE(type,val1,val2) \
  template <> std::string Variable<type>::GetValueAsString() const { return (boost::format("%1%")%(val1)).str();} \
  template <> double Variable<type>::GetValueAsDouble() const { return (double) (val2); } 

#define VARTYPE_DEFAULT(type) \
  template <> std::string Variable<type>::GetValueAsString() const { return (boost::format("%1%")%(#type)).str();} \
  template <> double Variable<type>::GetValueAsDouble() const { return 0.0; } 


VARTYPE_STRING_DOUBLE( float,                Value(),               Value())
VARTYPE_STRING_DOUBLE( double,               Value(),               Value())
VARTYPE_STRING_DOUBLE( long,                 Value(),               Value()) /// New (added: 27/05/2010)
VARTYPE_STRING_DOUBLE( int,                  Value(),               Value())
VARTYPE_STRING_DOUBLE( unsigned char,        (int)Value(),          Value())
VARTYPE_STRING_DOUBLE( std::string,          Value(),               0)

// FloatMatrix
template <> std::string Variable<FloatMatrix>::GetValueAsString() const 
{
   return Pointer()->PrintToString();
} 
template <> double Variable<FloatMatrix>::GetValueAsDouble() const { return 0.0; } 

VARTYPE_DEFAULT( InrImage)
//VARTYPE_DEFAULT( DessinImage)
//VARTYPE_DEFAULT( Viewer3D)
VARTYPE_DEFAULT( FILE)
VARTYPE_DEFAULT( C_wrap_procedure)
VARTYPE_DEFAULT( WrapClassMember)
VARTYPE_DEFAULT( C_wrap_imagefunction)
VARTYPE_DEFAULT( C_wrap_varfunction)
VARTYPE_DEFAULT( AMIFunction)
VARTYPE_DEFAULT( AMIClass)
VARTYPE_DEFAULT( AMIObject)
//VARTYPE_DEFAULT( GLTransfMatrix)
VARTYPE_DEFAULT( VarArray)

#undef VARTYPE_STRING_DOUBLE

//------------------------------------------------------
//------- Variable<WrapClassMember>
//------------------------------------------------------

#include "wrapfunction_class.h"
template<> AMI_DLLEXPORT std::string Variable<WrapClassMember>::TreeCtrlInfo() const
{
  // limit size of description here ???
  return Pointer()->GetDescription();
};

//------------------------------------------------------
//------- Variable<float>
//------------------------------------------------------


//#include "Variable_float.cpp"

//------------------------------------------------------
//------- Variable<unsigned char>
//------------------------------------------------------


//------------------------------------------------------
//------- Variable<string>
//------------------------------------------------------



// instantiate + operator
/*
template<> AMI_DLLEXPORT
BasicVariable::ptr operator +(const boost::shared_ptr<Variable<float> >& a, 
                              const boost::shared_ptr<Variable<float> >& b);
*/

/*
  template<> AMI_DLLEXPORT class AMILabType<float> { 
    
    static char const* name_as_string() { return "float"; } 
    
    static boost::shared_ptr<float> GetValue(BasicVariable::ptr var)  
    { 
      boost::shared_ptr<Variable<float> > tmp(      boost::dynamic_pointer_cast<Variable<float> >(var)); 
      if (tmp.get()) return tmp->Pointer(); 
      else return boost::shared_ptr<float>();
    } 
    
    static BasicVariable::ptr CreateVar(float& val)  
    { 
      boost::shared_ptr<float> valptr(new float(val));
      Variable<float>::ptr varres( new Variable<float>(valptr));
      return varres; 
    } 
    
  }; 
*/
#include "inrimage.hpp"
#include "wrapfunction_class.h"
#include "ami_function.h"

AMI_DEFINE_BASICTYPE(float);
AMI_DEFINE_BASICTYPE(double);
AMI_DEFINE_BASICTYPE(long);
AMI_DEFINE_BASICTYPE(int);
AMI_DEFINE_BASICTYPE(unsigned char);
AMI_DEFINE_BASICTYPE(InrImage);
AMI_DEFINE_BASICTYPE(std::string);
AMI_DEFINE_BASICTYPE(FloatMatrix);
AMI_DEFINE_BASICTYPE(AMIFunction);
AMI_DEFINE_BASICTYPE(AMIClass);
AMI_DEFINE_BASICTYPE(AMIObject);
AMI_DEFINE_BASICTYPE(VarArray);

#define AMI_DEFINE_BASICTYPE_NOCONSTRUCT(type) \
    AMI_DLLEXPORT \
    char const* AMILabType<type>::name_as_string() { return #type; } \
    \
    AMI_DLLEXPORT \
    boost::shared_ptr<type> AMILabType<type>::GetValue(BasicVariable::ptr var)  \
    { \
      if (!var.get()) \
      {\
        FILE_ERROR("Variable not found");\
        return boost::shared_ptr<type>();\
      }\
      boost::shared_ptr<Variable<type> > tmp( boost::dynamic_pointer_cast<Variable<type> >(var)); \
      if (tmp.get()) \
        return tmp->Pointer(); \
      else {\
        BasicVariable::ptr converted = var->TryCast(AMILabType<type>::name_as_string());\
        if (!converted.get()) {\
          FILE_ERROR(boost::format("Cannot not be converted to type %2%.") % AMILabType<type>::name_as_string());\
          return boost::shared_ptr<type>(); \
        } else { \
          boost::shared_ptr<Variable<type> > tmp( boost::dynamic_pointer_cast<Variable<type> >(converted)); \
          if (tmp.get()) \
            return tmp->Pointer(); \
          else \
            return boost::shared_ptr<type>(); \
        }\
      }\
    } \
    \
    AMI_DLLEXPORT \
    BasicVariable::ptr AMILabType<type>::CreateVar(const type& val)  \
    { \
      return BasicVariable::ptr(); \
    } 

AMI_DEFINE_BASICTYPE_NOCONSTRUCT(C_wrap_procedure);
AMI_DEFINE_BASICTYPE_NOCONSTRUCT(C_wrap_imagefunction);
AMI_DEFINE_BASICTYPE_NOCONSTRUCT(C_wrap_varfunction);


// abstract
AMI_DEFINE_BASICTYPE_NOCONSTRUCT(WrapClassMember);
