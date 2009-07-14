
#include "DefineClass.hpp"
#include "Variable.hpp"

#include "ParamBox.hpp"
#include "ParamPanel.hpp"
#include "DessinImage.hpp"
#include "Viewer3D.hpp"
#include "ami_function.h"
#include "ami_class.h"
#include "ami_object.h"
#include "FloatMatrix.hpp"

#include <string>


extern unsigned char       GB_debug;

using namespace std;


// TODO : make a base non-template class 
// and a template class !!

// TODO: deal with pointers to FILE ...

//----------------------------------------------------------------------
//  Variable
//----------------------------------------------------------------------

Variable::Variable()
{
  _type         = type_void;
  _pointer      = NULL;
}

void Variable::Init(vartype type, const char* name, void* p)
{
  _type         = type;
  _name         = name;

#define CREATE_CASE(_typeid,_typename) case _typeid: _pointer = new boost::shared_ptr<_typename>((_typename*)p);    break; 

#define CREATE_CASE_WXWINDOW(_typeid,_typename) case _typeid: _pointer = new boost::shared_ptr<_typename>((_typename*)p, \
      wxwindow_nodeleter<_typename>());    break; 

#define CREATE_CASE_WXWINDOW_DELETER(_typeid,_typename) case _typeid: _pointer = new boost::shared_ptr<_typename>((_typename*)p, \
      wxwindow_deleter<_typename>());    break; 

  switch(_type) {
    case type_void: 
      _pointer = NULL; //new boost::shared_ptr<void>((void*)p); 
    break; //CREATE_CASE(type_void,         void)
    CREATE_CASE(type_image,        InrImage)
    CREATE_CASE(type_float,        float)
    CREATE_CASE(type_int,          int)
    CREATE_CASE(type_uchar,        unsigned char)
    CREATE_CASE(type_string,       string)
    CREATE_CASE(type_surface,      SurfacePoly)
    CREATE_CASE(type_file,         FILE)
    CREATE_CASE(type_ami_function, AMIFunction)
    CREATE_CASE(type_ami_class,    AMIClass)
    CREATE_CASE(type_ami_object,   AMIObject)
    // don´t call the deleter for now because of a seg. fault
    // issue (29-06-09)
    CREATE_CASE_WXWINDOW(type_paramwin,     ParamBox)
    CREATE_CASE_WXWINDOW(type_parampanel,   ParamPanel)
    CREATE_CASE(type_matrix,       FloatMatrix)
    CREATE_CASE(type_gltransform,  GLTransfMatrix)
    CREATE_CASE(type_array,        VarArray)

    //CREATE_CASE(type_imagedraw,    DessinImage)
    //CREATE_CASE(type_surfdraw,     Viewer3D)

    case type_imagedraw:
       _pointer = new DessinImage::ptr(
            (DessinImage*)p,
            DessinImage::deleter());
    break; 

    case type_surfdraw:
       _pointer = new Viewer3D_ptr(
            (Viewer3D*)p,
            Viewer3D::deleter());
    break; 

    case type_c_procedure     : 
    case type_c_image_function:
    case type_c_function:
      _pointer = p; // no smart pointer here
    break;
    default       : 
      CLASS_ERROR(boost::format("unknown type %1%") % _type << endl); 
    break;
  }

#undef CREATE_CASE
}


//----------------------------------------------------------
void Variable::InitPtr( vartype type, 
                        const char* name, 
                        void* p // is reference a smart pointer to the type
                        )
{
  _type         = type;
  _name         = name;

using namespace boost;

#define CREATE_CASE(_typeid,_type) \
    case _typeid: \
      _pointer = new shared_ptr<_type>( \
                        *(shared_ptr<_type>*)p);\
    break; 

  switch(_type) {
    case type_void: 
      _pointer = NULL; //new boost::shared_ptr<void>((void*)p); 
    break; //CREATE_CASE(type_void,         void)
    CREATE_CASE(type_image,        InrImage)
    CREATE_CASE(type_float,        float)
    CREATE_CASE(type_int,          int)
    CREATE_CASE(type_uchar,        unsigned char)
    CREATE_CASE(type_string,       string)
    CREATE_CASE(type_surface,      SurfacePoly)
    CREATE_CASE(type_file,         FILE)
    CREATE_CASE(type_ami_function, AMIFunction)
    CREATE_CASE(type_ami_class,    AMIClass)
    CREATE_CASE(type_ami_object,   AMIObject)
    CREATE_CASE(type_paramwin,     ParamBox)
    CREATE_CASE(type_parampanel,   ParamPanel)
    CREATE_CASE(type_matrix,       FloatMatrix)
    CREATE_CASE(type_gltransform,  GLTransfMatrix)
    CREATE_CASE(type_array,        VarArray)
    CREATE_CASE(type_imagedraw,    DessinImage)
    CREATE_CASE(type_surfdraw,     Viewer3D)
    case type_c_procedure     : 
    case type_c_image_function:
    case type_c_function:
      _pointer = p; // no smart pointer here
    break;
    default       : 
      CLASS_ERROR(boost::format("unknown type %1%") % _type << endl); 
    break;
  }

#undef CREATE_CASE
} // InitPtr()

void  Variable::SetString(string_ptr st) 
{
  // Not good, or OK?
  if (_type==type_string) {
    *((string_ptr*)_pointer)=st;
  }
}


bool Variable::FreeMemory()
{
  if (_pointer==NULL) {
    fprintf(stderr,"Variable::FreeMemory()\t NULL pointer \n");
    return false;
  }

  if (GB_debug)
    cerr << "Variable::FreeMemory() " << _name << endl;
  switch(_type) {
    //      case type_void     : printf("void");     break;
  case type_image        : FreeMemory<InrImage>();       break;
  case type_float        : FreeMemory<float>();          break;
  case type_int          : FreeMemory<int>();            break;
  case type_uchar        : FreeMemory<unsigned char>();  break;
  case type_string       : FreeMemory<string>();         break;
  case type_imagedraw    : FreeMemory<DessinImage>();    break;
  case type_surface      : FreeMemory<SurfacePoly>();    break;
  case type_surfdraw     : FreeMemory<Viewer3D>();       break;
  case type_ami_function : FreeMemory<AMIFunction>();    break;
  case type_ami_class    : FreeMemory<AMIClass>();       break;
  case type_ami_object   : FreeMemory<AMIObject>();      break;
  case type_paramwin     : FreeMemory<ParamBox>();       break;
  case type_parampanel   : FreeMemory<ParamPanel>();     break;
  case type_matrix       : FreeMemory<FloatMatrix>();    break;
  case type_gltransform  : FreeMemory<GLTransfMatrix>(); break;
  case type_array        : FreeMemory<VarArray>();       break;
  case type_file     :
        // TODO: create a file class where the destructor closes the file 
        // for a cleaner implementation ...
        fclose( (*(boost::shared_ptr<FILE>*) _pointer).get()); 
    break;
    case type_c_procedure     : 
    case type_c_image_function:
    case type_c_function:
      // no specific memory free here, since no smart pointer is used
    break;
//  case type_c_function   : 
//    fprintf(stderr, "delete of C function not available \n");
//    break;
    default       : 
      CLASS_ERROR(boost::format("unknown type %1%") % _type << endl); 
    break;
  }
  _pointer = NULL;
  return true;
}


void Variable::Delete() 
{
  
  if (_pointer==NULL) return;
  if (!FreeMemory()) 
  {
    //if (GB_debug) fprintf(stderr,"Could not really delete variable %s \n", (char*) _name);
  }
  _pointer=NULL;
  _type = type_void;
}

int Variable::HasName(const char* name) 
{
  //printf("Variable::HasName( %s) \n",name);
  if (_type==type_void) return 0;
  return (strcmp(_name, name)==0);
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
    case type_c_image_function: return string( "C image function");
    case type_c_function      : return string( "C function");
    case type_ami_function    : return string( "AMI function");
    case type_ami_class       : return string( "AMI Class");
    case type_ami_object      : return string( "AMI Object");
    case type_paramwin        : return string( "Parameters Window");
    case type_parampanel      : return string( "Parameters Panel");
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
    case type_c_image_function: o << "C image function ";  break;
    case type_c_function      : o << "C function ";        break;
    case type_ami_function    : o << "AMI function ";      break;
    case type_ami_class       : o << "AMI class ";         break;
    case type_ami_object      : o << "AMI Object ";         break;
    case type_paramwin        : o << "Parameters Window";  break;
    case type_parampanel      : o << "Parameters Panel";  break;
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


//----------------------------------------------------------------------
//  VarArray
//----------------------------------------------------------------------

void VarArray::Resize( int new_size)
  {
    Variable* _tmp_vars;
    int i;
    if (new_size<2*_allocated_size) new_size = 2*_allocated_size;
    //printf("VarArray::Resize %d\n",new_size);

    _tmp_vars = new Variable[new_size];
    for (i=0;i<_allocated_size;i++)
      _tmp_vars[i] = _vars[i];
    delete []_vars;
    _vars = _tmp_vars;
    _allocated_size = new_size;
    // for the moment, set the size to the allocated size ...
    _size = _allocated_size;
  }


VarArray::VarArray()
{
  _type           = type_void;
  _vars           = NULL;
  _size           = 0;
  _allocated_size = 0;
}

VarArray::~VarArray()
{
  this->FreeMemory();
}

void VarArray::Init( vartype type, int initsize)
{
  _type           = type;
  _allocated_size = initsize;
  _size = _allocated_size;
  _vars           = new Variable[initsize];
}

void VarArray::InitElement( int i, void* p,const char* name) 
{
  if (i>=_allocated_size) this->Resize(i+1);
  if ((i>=0)&&(i<_allocated_size)) {
    _vars[i].Init(_type,name,p);
  }
}

/*
template <class T>
void VarArray::InitElement( int i, 
                            boost::shared_ptr<T>* p,
                            const char* name) 
{
  if (i>=_allocated_size) this->Resize(i+1);
  if ((i>=0)&&(i<_allocated_size)) {
    _vars[i].Init<T>(_type,name,p);
  }
}
*/

Variable& VarArray::GetVar(int i) {
  if ((i>=0)&&(i<_allocated_size)) {
    return _vars[i];
  }    
  else
    return _vars[0];
}


//---------------------------------------------------
ostream& operator<<(ostream& o, const VarArray& v)
//       -----------
{
  int i;
  for (i=0;i<v._size;i++) 
    if (v._vars[i].Pointer()!=NULL) 
      o  << format("\t\t [%1%]\t %2%") % i  % v._vars[i]  << endl;
  return o;
} // operator <<


//---------------------------------------------------
void VarArray::display() 
{
  cout << *this;
}

void VarArray::FreeMemory()
{
  int i;

  for (i=0;i<_size;i++)
    _vars[i].Delete();
  delete [] _vars;
  _vars = NULL;
  _size = 0;
}
