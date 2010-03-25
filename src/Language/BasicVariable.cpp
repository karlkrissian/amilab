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

//---------------------------------------------
const string BasicVariable::GetTypeName()
//           -------------
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
    case type_matrix          : return string( "matrix");
    case type_gltransform     : return string( "gltransform");
    case type_array           : 
    {
/* TODO
      VarArray::ptr array =  *((VarArray::ptr*) Pointer());
      return str( format("array \t %d \n") % array->Size());
*/
    }
    default                : 
      return string( "unknown type");
  }

  return string();
} // PrintType

