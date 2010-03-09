
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

/**
  Basic Variable class without template
**/
class BasicVariable {

  DEFINE_CLASS(BasicVariable);

protected:
  vartype       _type;
  std::string   _name;
  std::string   _comments;
  boost::shared_ptr<Variables>   _context; // points to the context
    // that the variable belong to, if any

public:

  BasicVariable(): _type(type_void), _name(""), _comments("") {}
  virtual ~BasicVariable(){ this->Delete(); }

  /**
   * Copy of variables
   * @param v 
   */
  virtual void operator = (const BasicVariable& v) = 0;

  /**
   * Copy of variables
   * @param v 
   */
  void operator = (const VariableBasic::ptr& v) {
     (*this) = (*v);
  }

  virtual bool operator == (const BasicVariable& v)  = 0;

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


  vartype Type() const { return _type; }

//  void  SetString(string_ptr st);
  void  SetString(const char* st);

  /**
   * Rename variable.
   * @param newname 
   */
  void Rename(const char* newname) 
  {  
    CLASS_MESSAGE(boost::format("Renaming %1% to %2%")%_name % newname);
    _name=newname;
  }

  std::string Name() const { return _name;}

  void SetComments(const std::string& comments) { _comments = comments;}
  std::string GetComments() const { return _comments; }

  virtual bool FreeMemory() = 0;

  virtual void Delete() = 0;

  int HasName(const char* name)
  {
    if (_type==type_void) return 0;
    return (strcmp(_name.c_str(), name)==0);
  }

  const string GetTypeName();

  //
  virtual void display() = 0;

  // allow access to private members of Variable class
  friend class VarArray;

}; // class BasicVariable


//----------------------------------------------------------------------
/**
 * Define one variable, which contains a generic pointer (void*) to a smart pointer
 * of the contained object.
 **/
template<class T>
class Variable : public BasicVariable {

  DEFINE_TEMPLATE_CLASS1(Variable,T);

private:
  boost::shared_ptr<T>        _pointer; 

private:

  template <class T>
  bool FreeMemory()
  {
    if ((_pointer.use_count()>1)&&(GB_debug)) {
      CLASS_ERROR( format("variable %1% is referenced %2% times")  % _name % ptr.use_count() );
    }
    _pointer.reset();
    return true;
  }

public:

  Variable();
  virtual ~Variable(){ this->Delete(); }

  /**
   * Copy of variables
   * @param v 
   */
  void operator = (const Variable<T>& v);

  /**
   * Copy of variables
   * @param v 
   */
  void operator = (const Variable<T>::ptr& v) {
     (*this) = (*v);
      /*
      _type         = v->_type;
      _name         = v->_name;
      _comments     = v->_comments;
      // Problem: unsafe to copy pointers here
      _pointer      = v->_pointer;
    */
  }

  // TODO: copy from basic variable ???

  bool operator == (const Variable<T>& v) {
      return ((_type     == v._type) &&
              (_name     == v._name) &&
              (_comments == v._comments) &&
              (_pointer.get()  == v._pointer.get()));
  }

  /**
  * Get the pointer of the variable value, points to a smart pointer.
  * @return Pointer of the variable, points to a smart pointer
  */
  shared_ptr<T>& Pointer() const { return _pointer;}



  void Init(vartype type, const char* name, 
            const boost::shared_ptr<T>& p);

  bool FreeMemory();
  void Delete();

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
  std::vector<Variable::ptr>     _vars;
  void Resize( int new_size);

 public:

  VarArray();
  virtual ~VarArray();
  int Size() {return _size;}
  void Init( vartype type, int initsize=10);

  /**
   * Initialize an element of the array based on a pointer to its value. 
   **/
  void InitElement( int i, void* p,const char* name);

  /**
   * Initialize an element of the array based on a pointer to a smart pointer. 
   **/
  void InitElementPtr( vartype _type, int i, void* p,const char* name);

  template <class T>
  void InitElement( int i, 
                    const boost::shared_ptr<T>& p,
                    const char* name)
  {
    if (i>=_allocated_size) this->Resize(i+1);
    if ((i>=0)&&(i<_allocated_size)) {
      _vars[i]->Init<T>(_type,name,p);
    }
  }

  Variable::ptr& GetVar(int i); 
  vartype Type() { return _type; }
  void FreeMemory();

  //
  void display();

  //
  friend std::ostream& operator<<(std::ostream& o, const VarArray& v);

}; // VarArray




#endif
