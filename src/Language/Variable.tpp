
#include "DefineClass.hpp"
#include "Variable.hpp"


#include <string>
#include <ostream>

//------------------------------------------------------------//  Variable
//------------------------------------------------------------
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
    this->Init(v._type,v._name.c_str(), v._pointer);

}


//------------------------------------------------
template<class T>
void Variable<T>::Init(const std::string& name, boost::shared_ptr<T>& p)
{
  _type         = GetVarType<T>();
  _name         = name;
  _pointer      = boost::shared_ptr<T>(p); 

}


template<class T>
void Variable<T>::Delete() 
{
  if (!FreeMemory()) 
  {
    CLASS_MESSAGE(boost::format("Could not completely delete variable %s") % _name);
  }
  _type = type_void;
}



//---------------------------------------------------
template<class T>
std::ostream& operator<<(std::ostream& o, const Variable<T>& v)
//       -----------
{
  if (v.Type()==type_void) { o << "deleted"; return o;}
  o << format("%s\t") % v.Name();
// TODO: take care of this functionality

  switch(v.Type()) {
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
    case type_matrix          : o << "matrix";             break;
    case type_gltransform     : o << "gltransform";        break;
    case type_array           : 
    {
/* TODO ...
      VarArray::ptr array =  *((VarArray::ptr*) v.Pointer());
      o << format("array \t %d \n") % array->Size();
      o << *array;
*/
      break;
    }
    default                : o << "unknown type ";     break;
  }

  //      o << ("\n");
  return o;
} // operator << Variable

template <class T>
void Variable<T>::display()
{
  std::cout << (*this);
}


// Specializations
class DessinImage;
class Viewer3D;

/*
template<> BasicVariable::ptr Variable<FILE>::NewCopy()
{
  // don't copy a file, keep a reference ...
  CLASS_MESSAGE(boost::format("Don't copy a file, keep a reference to it ... for variable %1% ")
                      % Name());
  return NewReference();
}

template<> BasicVariable::ptr Variable<DessinImage>::NewCopy()
{
  // don't copy a file, keep a reference ...
  CLASS_MESSAGE(boost::format("Don't copy object, keep a reference to it ... for variable %1% ")
                      % Name());
  return NewReference();
}

template<> BasicVariable::ptr Variable<Viewer3D>::NewCopy()
{
  // don't copy a file, keep a reference ...
  CLASS_MESSAGE(boost::format("Don't copy object, keep a reference to it ... for variable %1% ")
                      % Name());
  return NewReference();
}
*/