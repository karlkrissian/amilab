
#ifndef _AMI_VARIABLE_HPP
#define _AMI_VARIABLE_HPP

//#include "ParamBox.hpp"
//#include "DessinImage.hpp"
//#include "Viewer3D.hpp"
//#include "paramlist.h"
#include <string>
#include <iostream>

#include "DefineClass.hpp"

#include "amilab_messages.h"
#include "vartype.h"


// forward definition of Variables
class Variables;
class VarArray;

/* TODO: Change SetString */

//----------------------------------------------------------------------
/**
 * Define one variable, which contains a generic pointer (void*) to a smart pointer
 * of the contained object.
 **/
class Variable {

  DEFINE_CLASS(Variable);

private:
  vartype       _type;
  std::string   _name;
  std::string   _comments;
  void*         _pointer; // TODO remove all pointers!!!
  bool          _allocated_memory;
  boost::shared_ptr<Variables>   _context; // points to the context
    // that the variable belong to, if any

private:

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
          _allocated_memory = true;
        break;
      }
  }

  template <class T>
  bool FreeMemory()
  {
    //std::cout << "FreeMemory()" << std::endl;
    if (_pointer==NULL) {
        CLASS_ERROR("pointer is NULL !");
        return false;
    }
    boost::shared_ptr<T>* ptr = (boost::shared_ptr<T>*) _pointer;
    if ((ptr->use_count()>1)&&(GB_debug)) {
      CLASS_ERROR( format("variable %1% is referenced %2% times")  % _name % ptr->use_count() );
    }
    delete (boost::shared_ptr<T>*) _pointer;
    //std::cout << "  **  delete " << ptr << endl;
    _allocated_memory = false;
    _pointer = NULL;
    return true;
  }

public:

  Variable();
  virtual ~Variable(){ this->Delete(); }

  /**
   * Copy of variables
   * @param v 
   */
  void operator = (const Variable& v);
/*
  {
      _type         = v._type;
      _name         = v._name;
      _comments     = v._comments;
      // Problem: unsafe to copy pointers here
      _pointer      = v._pointer;
  }
*/

  /**
   * Copy of variables
   * @param v 
   */
  void operator = (const Variable::ptr& v) {
     (*this) = (*v);
      /*
      _type         = v->_type;
      _name         = v->_name;
      _comments     = v->_comments;
      // Problem: unsafe to copy pointers here
      _pointer      = v->_pointer;
    */
  }

  bool operator == (const Variable& v) {
      return ((_type     == v._type) &&
              (_name     == v._name) &&
              (_comments == v._comments) &&
              (_pointer  == v._pointer));
  }

  /**
  * Get the pointer of the variable value, points to a smart pointer.
  * @return Pointer of the variable, points to a smart pointer
  */
  void* Pointer() const { return _pointer;}

  void SetContext(const boost::shared_ptr<Variables>& val) 
  {
    _context = val;
  }

  /**
   * Create a new shared pointer reference to the object.
   * @return variable's context
   */
  boost::shared_ptr<Variables> GetContext() const
  {
    return _context;
  }


  void Init(vartype type, const char* name, void* p);

  /**
   * Create a new shared pointer reference to the object.
   * void* p is a pointer to a smart pointer.
   * @param type  variable type
   * @param name  variable name
   * @param p     pointer to a smart pointer depending on the variable type
   */
  void InitPtr(vartype type, const char* name, void* p);

  vartype Type() const { return _type; }

//  void  SetString(string_ptr st);
  void  SetString(const char* st);

  /**
   * Rename variable.
   * @param newname 
   */
  void Rename(const char* newname) 
  {  
    _name=newname;
  }

  std::string Name() const { return _name;}

  void SetComments(const std::string& comments) { _comments = comments;}
  std::string GetComments() const { return _comments; }

  bool FreeMemory();

  void Delete();

  int HasName(const char* name);

  const string GetTypeName();

  //
  friend std::ostream& operator<<(std::ostream& o, const Variable& v);

  friend std::ostream& PrintType(std::ostream& o, const Variable& v);

  //
  void display();

  // allow access to private members of Variable class
  friend class VarArray;

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
  friend std::ostream& operator<<(std::ostream& o, const VarArray& v);

}; // VarArray




#endif
