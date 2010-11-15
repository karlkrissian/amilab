//
// C++ Implementation: BasicVariable
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "BasicVariable.h"
#include "Variables.hpp"

BasicVariable::ptr BasicVariable::empty_variable;

BasicVariable::BasicVariable() : _type(type_void), _name(""), _comments("") 
{
    _vars     = boost::shared_ptr<Variables>(new Variables);
    _vars->SetName("variable own context");
}

/*
//---------------------------------------------
const string BasicVariable::GetTypeName() const
//           -------------
{
  if (_type==type_void) { return string("deleted"); }
  switch(_type) {
    //      case type_void     : printf("void";     
    case type_image           : return string( "image"); 
    case type_float           : return string( "float"); 
    case type_double          : return string( "double"); /// New (added: 24/05/2010)
    case type_long            : return string( "long int");  /// New (added: 27/05/2010)
    case type_int             : return string( "int"); 
    case type_uchar           : return string( "uchar"); 
    case type_string          : return string( "string"); 
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
    case type_matrix          : return string( "matrix");
    case type_gltransform     : return string( "gltransform");
    case type_array           : 
    {
     // VarArray::ptr array =  *((VarArray::ptr*) Pointer());
     // return str( format("array \t %d \n") % array->Size());
    }
    default                : 
      return string( "unknown type");
  }

  return string();
} // PrintType
*/

void BasicVariable::Rename(const char* newname)
{  
  CLASS_MESSAGE(boost::format("Renaming %1% to %2%")%_name % newname);
  _name=newname;
  if (_vars.get())
    _vars->SetName(newname);
}

