
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
#include "VarArray.h"

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

template<> vartype GetVarType<FloatMatrix>  ()
{ return type_matrix;   }

template<> vartype GetVarType<GLTransfMatrix>  ()
{ return type_gltransform;   }

template<> vartype GetVarType<VarArray>  ()
{ return type_array;   }





//----------------------------------------------------------//  Variable
//----------------------------------------------------------


