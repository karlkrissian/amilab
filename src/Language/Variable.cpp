
#include "DefineClass.hpp"
#include "Variable.hpp"

#include "ParamBox.hpp"
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

#include <string>

using namespace std;

extern unsigned char       GB_debug;

using namespace std;

template<> vartype GetVarType<InrImage>      ()    
{ return type_image;     }

template<> vartype GetVarType<float>         ()    
{ return type_float;     }

template<> vartype GetVarType<int>           ()    
{ return type_int;       }

template<> vartype GetVarType<unsigned char> ()    
{ return type_uchar;     }

template<> vartype GetVarType<string>        ()    
{ return type_string;    }

template<> vartype GetVarType<DessinImage>   ()    
{ return type_imagedraw; }

template<> vartype GetVarType<SurfacePoly>   ()    
{ return type_surface;   }

template<> vartype GetVarType<Viewer3D>   ()
{ return type_surfdraw;   }

template<> vartype GetVarType<FILE>   ()
{ return type_file;   }

template<> vartype GetVarType<C_wrap_procedure>   ()
{ return type_c_procedure;   }

template<> vartype GetVarType<WrapClassMember>   ()
{ return type_class_member;   }

template<> vartype GetVarType<C_wrap_imagefunction>   ()
{ return type_c_image_function;   }

template<> vartype GetVarType<C_wrap_varfunction>   ()
{ return type_c_function;   }

template<> vartype GetVarType<AMIFunction>   ()
{ return type_ami_function;   }

template<> vartype GetVarType<AMIClass>      ()
{ return type_ami_class;   }

template<> vartype GetVarType<AMIObject>     ()
{ return type_ami_object;   }

template<> vartype GetVarType<AMICPPObject>  ()
{ return type_ami_cpp_object;   }



// TODO : make a base non-template class 
// and a template class !!

// TODO: deal with pointers to FILE ...

//----------------------------------------------------------------------
//  Variable
//----------------------------------------------------------------------

template<class T>
Variable<T>::Variable()
{
  _type         = type_void;
}


//------------------------------------------------
template<class T>
void Variable<T>::operator = (const Variable<T>& v)
{
    _comments     = v._comments;
    // new copy or new reference ???
}


//------------------------------------------------
template<class T>
void Variable<T>::Init(vartype type, const char* name, boost::shared_ptr<T>& p)
{
  _type    = type;
  _name    = name;
  _pointer = boost::shared_ptr<_typename>(p);
}


/*
void  Variable::SetString(string_ptr st) 
{
  // Not good, or OK?
  // in this case, need to free the pointer
  if (_type==type_string) {
    *((string_ptr*)_pointer)=st;
  }
}
*/

template<class T>
void  Variable<T>::SetString(const char* st) 
{
  // replace the value inside the string
  if (_type==type_string) {
    *(*((string_ptr*)_pointer))=st;
  }
}



template<class T>
void Variable<T>::Delete() 
{
  if ((_pointer==NULL)||(!_allocated_memory)) return;
  if (!FreeMemory()) 
  {
    CLASS_MESSAGE(boost::format("Could not completely delete variable %s") % _name);
  }
  _pointer=NULL;
  _type = type_void;
}

template<class T>
int Variable<T>::HasName(const char* name) 
{
  //printf("Variable::HasName( %s) \n",name);
  if (_type==type_void) return 0;
  return (strcmp(_name.c_str(), name)==0);
}


//---------------------------------------------
const string Variable::GetTypeName()
//               -----------
{
  if (_type==type_void) { return string("deleted"); }
  switch(_type) {
    //      case type_void     : printf("void";     
    case type_image           : return string( "image"); 
    case type_float           : return string( "float"); 
    case type_int             : return string( "int"); 
    case type_uchar           : return string( "uchar"); 
    case type_string          : return string( "string"); 
    case type_imagedraw       : return string( "imagedraw"); 
    case type_surface         : return string( "surface"); 
    case type_surfdraw        : return string( "surfdraw"); 
    case type_file            : return string( "file"); 
  //  case type_c_function      : return string( "C function ");
    case type_c_procedure     : return string( "C procedure"); 
    case type_class_member : return string( "C++ procedure member"); 
    case type_c_image_function: return string( "C image function");
    case type_c_function      : return string( "C function");
    case type_ami_function    : return string( "AMI function");
    case type_ami_class       : return string( "AMI Class");
    case type_ami_object      : return string( "AMI Object");
    case type_paramwin        : return string( "Parameters Window");
    case type_matrix          : return string( "matrix");
    case type_gltransform     : return string( "gltransform");
    case type_array           : 
    {
      VarArray::ptr array =  *((VarArray::ptr*) Pointer());
      return str( format("array \t %d \n") % array->Size());
    }
    default                : 
      return string( "unknown type");
  }

  return string();
} // PrintType


//---------------------------------------------------
ostream& operator<<(ostream& o, const Variable& v)
//       -----------
{
  if (v._type==type_void) { o << "deleted"; return o;}
  o << format("%s\t") % v._name;
  switch(v._type) {
    //      case type_void     : printf("void";     break;
    case type_image           : o << "image    "; break;
    case type_float           : o << "float    "; break;
    case type_int             : o << "int      "; break;
    case type_uchar           : o << "uchar    "; break;
    case type_string          : o << "string   "; break;
    case type_imagedraw       : o << "imagedraw"; break;
    case type_surface         : o << "surface  "; break;
    case type_surfdraw        : o << "surfdraw "; break;
    case type_file            : o << "file     "; break;
  //  case type_c_function      : o << ("C function ";       break;
    case type_c_procedure     : o << "C procedure ";       break;
    case type_class_member : o << "C++ procedure member";       break;
    case type_c_image_function: o << "C image function ";  break;
    case type_c_function      : o << "C function ";        break;
    case type_ami_function    : o << "AMI function ";      break;
    case type_ami_class       : o << "AMI class ";         break;
    case type_ami_object      : o << "AMI Object ";         break;
    case type_paramwin        : o << "Parameters Window";  break;
    case type_matrix          : o << "matrix";             break;
    case type_gltransform     : o << "gltransform";        break;
    case type_array           : 
    {
      VarArray::ptr array =  *((VarArray::ptr*) v.Pointer());
      o << format("array \t %d \n") % array->Size();
      o << *array;
      break;
    }
    default                : o << "unknown type ";     break;
  }
  //      o << ("\n");
  return o;
} // operator << Variable


//--------------------------------------------------------------
void Variable::display() 
//             -------
{
  cout << *this;
}

template<> BasicVariable::ptr Variable<FILE>::NewCopy()
{
  // don't copy a file, keep a reference ...
  CLASS_MESSAGE(boost::format("Don't copy a file, keep a reference to it ... for variable %1% ")
                      % Name());
  return NewRef();
}
