
#ifndef _AMI_VARIABLE_HPP
#define _AMI_VARIABLE_HPP

//#include "ParamBox.hpp"
//#include "DessinImage.hpp"
//#include "Viewer3D.hpp"
#include "paramlist.h"
#include "chaine.hpp"
#include "ami_function.h"
#include "FloatMatrix.hpp"



#include "DefineClass.hpp"




/* TODO: Change SetString */

//----------------------------------------------------------------------
class Variable {

  DEFINE_CLASS(Variable)

private:
  vartype       _type;
  Chaine        _name;
  void*         _pointer; // TODO remove all pointers!!!

 public:

  Variable();
  virtual ~Variable(){}

  void operator = (const Variable& v) {
      _type         = v._type;
      _name         = v._name;
      _pointer      = v._pointer;
  }

  void operator = (const Variable::ptr& v) {
      _type         = v->_type;
      _name         = v->_name;
      _pointer      = v->_pointer;
  }

  bool operator == (const Variable& v) {
      return ((_type == v._type) &&
              (_name == v._name) &&
              (_pointer == v._pointer));
  }

  void* Pointer() const { return _pointer;}

  // create a new shared pointer reference to the object
  void Init(vartype type, const char* name, void* p);

  // create a new shared pointer reference to the object
  // void* p is a pointer to a smart pointer
  void InitPtr(vartype type, const char* name, void* p);

  // keep the shared pointer reference
  // TODO we should avoid using pointers to shared pointers!
  template <class T>
  void Init(vartype type, const char* name, 
            const boost::shared_ptr<T>& p)
  {
      _type         = type;
      _name         = name;
      switch(_type) {
        case type_void:   _pointer = NULL;    break;
        default:
          // keep the reference to avoid deleting the object
          _pointer = (void*) new boost::shared_ptr<T>(p);
        break;
      }
  }

  vartype Type() const { return _type; }

  void  SetString(string_ptr st);

  void Rename(const char* newname) {  _name=newname;}
  char* Name() const { return (char*) _name;}

  bool FreeMemory();

  template <class T>
  bool FreeMemory()
  {
    if (_pointer==NULL) {
        cerr << "Variable::FreeMemory<T>\t";
        cerr << "pointer is NULL !\n";
        return false;
    }
    boost::shared_ptr<T>* ptr = (boost::shared_ptr<T>*) _pointer;
    if ((ptr->use_count()>1)&&(GB_debug)) {
      cerr << "Variable::FreeMemory<T>\t";
      cerr << format("variable %1% is referenced %2% times")  % _name % ptr->use_count() << endl;
    }
    delete (boost::shared_ptr<T>*) _pointer;
    _pointer = NULL;
    return true;
  }

  void Delete();

  int HasName(const char* name);

  const string GetTypeName();

  //
  friend ostream& operator<<(ostream& o, const Variable& v);

  friend ostream& PrintType(ostream& o, const Variable& v);

  //
  void display();

}; // class Variable




//----------------------------------------------------------------------
class VarArray {

  DEFINE_CLASS(VarArray)

private:
  int           _size;
  int           _allocated_size;
  vartype       _type;
  Variable*     _vars;
  void Resize( int new_size);

 public:

  VarArray();
  virtual ~VarArray();
  int Size() {return _size;}
  void Init( vartype type, int initsize=10);
  void InitElement( int i, void* p,const char* name);

  template <class T>
  void InitElement( int i, 
                    const boost::shared_ptr<T>& p,
                    const char* name)
  {
    if (i>=_allocated_size) this->Resize(i+1);
    if ((i>=0)&&(i<_allocated_size)) {
      _vars[i].Init<T>(_type,name,p);
    }
  }

  Variable& GetVar(int i); 
  vartype Type() { return _type; }
  void FreeMemory();

  //
  void display();

  //
  friend ostream& operator<<(ostream& o, const VarArray& v);

}; // VarArray




#endif
