//
// C++ Interface: wrapAMIFluid
//
// Description:
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrapfunctions.hpp"
#include "DefineClass.hpp"
#include "amilab_messages.h"
#include "DessinImage.hpp"
#include "ami_function.h"

#include <string>
using namespace std;


template<> vartype GetVarType<float>       ()    { return type_float;     }
template<> vartype GetVarType<string>      ()    { return type_string;    }
template<> vartype GetVarType<int>         ()    { return type_int;       }
template<> vartype GetVarType<InrImage>    ()    { return type_image;     }
template<> vartype GetVarType<SurfacePoly> ()    { return type_surface;   }
template<> vartype GetVarType<DessinImage> ()    { return type_imagedraw; }
template<> vartype GetVarType<AMIFunction> ()    { return type_ami_function; }


/**
 * Function returns the number of parameters of the parameters list
 * if the pointer is NULL, returns -1 to allow display the documentation
 */
int get_num_param(ParamList* p)
{
  if (!p) return -1;
  return p->GetNumParam();
}


/**
 * Function used to parse an integer in a list of parameters
 */
bool get_int_param(int& arg, ParamList*p, int& num)
{
  // Get an integer param from a float value ...
  // copy to start with default value
  float val = arg;
  if (get_val_param<float>(val,p,num)) {
    arg = round(val);
    return true;
  }
  else 
  {
    FILE_ERROR("Could not get an integer parameter from a floating point value");
    return false;
  }
}



/**
 * Function used to parse a vectorial image in a list of parameters
 */
bool get_vectimage_param(InrImage*& arg, ParamList*p, int& num)
{
  if (get_val_ptr_param<InrImage>(arg,p,num))
  {
    if (!arg->VectorialFormat()) {
      FILE_ERROR(boost::format("Param %d must be a vectorial image.") %num);
      return false;
    }
    else return true;
  } 
  else return false;
}


