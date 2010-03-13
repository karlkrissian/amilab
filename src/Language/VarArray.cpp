
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

#include "VarArray.h"

#include <string>

using namespace std;

extern unsigned char       GB_debug;


//----------------------------------------------------------------------
//  VarArray
//----------------------------------------------------------------------

void VarArray::Resize( int new_size)
  {
    _vars.resize(new_size);
    _allocated_size = new_size;
    // for the moment, set the size to the allocated size ...
    _size = _allocated_size;
  }


VarArray::VarArray()
{
  _type           = type_void;
  _vars.clear();
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
  _vars.resize(initsize);
}

void VarArray::InitElement( int i, void* p,const char* name) 
{
  if (i>=_allocated_size) this->Resize(i+1);
  if ((i>=0)&&(i<_allocated_size)) {
    if (!_vars[i].get()) _vars[i] = Variable::ptr(new Variable());
    _vars[i]->Init(_type,name,p);
  }
}

void VarArray::InitElementPtr( vartype _type, int i, void* p,const char* name) 
{
  if (i>=_allocated_size) this->Resize(i+1);
  if ((i>=0)&&(i<_allocated_size)) {
    if (!_vars[i].get()) _vars[i] = Variable::ptr(new Variable());
    _vars[i]->InitPtr(_type,name,p);
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

BasicVariable::ptr VarArray::GetVar(int i) {
  if ((i>=0)&&(i<_allocated_size)) {
    return _vars[i];
  }    
  else {
    CLASS_ERROR(boost::format("Wrong index %1%") % i);
    return BasicVariable::ptr();
  }
}


//---------------------------------------------------
ostream& operator<<(ostream& o, const VarArray& v)
//       -----------
{
  int i;
  for (i=0;i<v._size;i++) 
    if (v._vars[i].get())
      if (v._vars[i]->Pointer()!=NULL) 
        o  << format("\t\t [%1%]\t %2%") % i  % (*v._vars[i])  << endl;
  return o;
} // operator <<


//---------------------------------------------------
void VarArray::display() 
{
  cout << *this;
}

void VarArray::FreeMemory()
{
  _vars.clear();
  _size = 0;
}
