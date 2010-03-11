
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
#include "paramlist.h"
#include "BasicVariable.h"

// forward definition of Variables
class Variables;
class VarArray;

/* TODO: Change SetString */

/*
template<class T>  
std::ostream& operator<<(std::ostream& o, const Variable<T>& v);

template<class T> 
std::ostream& PrintType(std::ostream& o, const Variable<T>& v);
*/


/// Getting variable type 
template<class T> vartype GetVarType();


/// type: pointer to a C wrapping procedure
typedef void      (*C_wrap_procedure)(ParamList*);

/// type: pointer to a C wrapping image function
typedef InrImage* (*C_wrap_imagefunction)(ParamList*);

/// type: pointer to a C wrapping variable function
typedef BasicVariable::ptr (*C_wrap_varfunction)(ParamList*);



//----------------------------------------------------------------------
/**
 * Define one variable, which contains a generic pointer (void*) to a smart pointer
 * of the contained object.
 **/
template<class T>
class Variable : public BasicVariable {

//  DEFINE_TEMPLATE_CLASS1(Variable,T);
public:
  virtual char const* get_name() const { return "Variable<T>"; } 
  typedef Variable<T> VariableType;
  typedef typename boost::shared_ptr<VariableType >    ptr;
  typedef typename boost::weak_ptr<VariableType >      wptr;
  typedef typename std::vector<VariableType::ptr>     ptr_vector;
  typedef std::vector<VariableType::wptr>    wptr_vector;
  typedef std::list<VariableType::ptr>       ptr_list;
  typedef std::list<VariableType::wptr>      wptr_list;


private:
  boost::shared_ptr<T>        _pointer; 

private:

  bool FreeMemory()
  {
    if ((_pointer.use_count()>1)&&(GB_debug)) {
      CLASS_ERROR( format("variable %1% is referenced %2% times")  % _name % _pointer.use_count() );
    }
    _pointer.reset();
    return true;
  }

public:

  Variable();

  Variable(const std::string& name, 
           const boost::shared_ptr<T>& p)
  {
    _type    = GetVarType<T>();
    _name    = name;
    _pointer = boost::shared_ptr<T>(p);
  }

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
  boost::shared_ptr<T>& Pointer() const { return _pointer;}



  void Init(const std::string& name, 
            const boost::shared_ptr<T>& p);

  void Delete();

  //
/*
  friend 
  std::ostream& operator<< <>(std::ostream& o, const Variable<T>& v);
*/

/*
  friend 
  std::ostream& PrintType <>(std::ostream& o, const Variable<T>& v);
*/

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
  std::vector<BasicVariable::ptr>     _vars;
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
      _vars[i] = BasicVariable::ptr(new Variable<T>(_type,name,p));
    }
  }

  BasicVariable::ptr GetVar(int i); 
  vartype Type() { return _type; }
  void FreeMemory();

  //
  void display();

  //
  friend std::ostream& operator<<(std::ostream& o, const VarArray& v);

}; // VarArray




#endif
