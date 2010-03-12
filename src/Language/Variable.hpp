
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
    * Virtual Method that creates a new smart pointer to a basic variable coming from the same type
    * generic copy of variable, can be specialized per variable type
    */
  BasicVariable::ptr NewCopy()
  {
    string resname = _name+"_copy";
    boost::shared_ptr<T> copy(new T(*_pointer));
    Variable<T>::ptr res(new Variable<T>(resname,copy));
    return res;
  }

  /**
    * Virtual Method that creates a new smart pointer to a basic variable coming from the same type
    * with a reference to the same value
    */
  BasicVariable::ptr NewReference()
  {
    string resname = _name+"_ref";
    Variable<T>::ptr res(new Variable<T>(resname,_pointer));
    return res;
  }

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


#endif
