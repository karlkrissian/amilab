
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
//#include "paramlist.h"
#include "BasicVariable.h"
#include <limits>

// forward definition of Variables
//class Variables;
//class VarArray;


/*! \def DYNAMIC_CAST_VARIABLE
    \brief helper for dynamic cast from BasicVariable to Variable<newtype>
*/
#define DYNAMIC_CAST_VARIABLE(newtype,initvar,resvar) \
    Variable<newtype>::ptr resvar( \
          boost::dynamic_pointer_cast<Variable<newtype> >(initvar)); \
    if (!resvar.get()) std::cerr << "DYNAMIC_CAST_VARIABLE(" << #newtype << "," << #initvar << "," << # resvar << ") failed ..." << std::endl;


/*
template<class T> 
std::ostream& PrintType(std::ostream& o, const Variable<T>& v);
*/

// forward declaration of ParamList;
class ParamList;

// forward declaration of InrImage;
class InrImage;

/// Getting variable type 
template<class T> vartype GetVarType();

/// Check numerical type
template<class T> bool IsNumerical();

/// type: pointer to a C wrapping procedure
typedef void      (C_wrap_procedure)(ParamList*);

/// type: pointer to a C wrapping image function
typedef InrImage* (C_wrap_imagefunction)(ParamList*);

/// type: pointer to a C wrapping variable function
typedef BasicVariable::ptr (C_wrap_varfunction)(ParamList*);



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

  Variable(const boost::shared_ptr<T>& p)
  {
    _type    = GetVarType<T>();
    _name    = "tmpvar";
    _pointer = boost::shared_ptr<T>(p);
  }

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
    // don't copy a file, keep a reference ...
    CLASS_MESSAGE(boost::format("No default copy of variable contents, need to be specialized for this type of variable ... for variable %1% ")
                        % Name());
    return NewReference();

/*    std::string resname = _name+"_copy";
    boost::shared_ptr<T> copy(new T(*_pointer));
    Variable<T>::ptr res(new Variable<T>(resname,copy));
    return res;
*/
  }

  /**
    * Virtual Method that creates a new smart pointer to a basic variable coming from the same type
    * with a reference to the same value
    */
  BasicVariable::ptr NewReference()
  {
    std::string resname = _name+"_ref";
    Variable<T>::ptr res(new Variable<T>(resname,_pointer));
    // copy the comments
    res->SetComments(_comments);
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

  bool operator == ( BasicVariable* v) 
  {
    if (_type == v->Type()) {
      // convert pointer
      Variable<T>* newvar = dynamic_cast<Variable<T>*>(v);
      return ((_name     == newvar->_name) &&
              (_comments == newvar->_comments) &&
              (_pointer.get()  == newvar->_pointer.get()));

    }
    else return false;
  }

  bool operator == (const BasicVariable::ptr& v) 
  {
    if (_type == v->Type()) {
      // convert pointer
      Variable<T>::ptr newvar (boost::dynamic_pointer_cast<Variable<T> >(v));
      return ((_name     == newvar->_name) &&
              (_comments == newvar->_comments) &&
              (_pointer.get()  == newvar->_pointer.get()));

    }
    else return false;
  }

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
  boost::shared_ptr<T> Pointer() const { return _pointer;}

  const T& Value() const { return *_pointer; }

  T& RefValue() { return *_pointer; }

  void Init(const std::string& name, 
            boost::shared_ptr<T>& p);

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

  double GetValueAsDouble() const {
      CLASS_ERROR("Variable type is not numeric");
      return 0.0;
  }
  
  /**
   * 
   * @return A string containing the value of the variable.
   */
  std::string GetValueAsString() const;

  // allow access to private members of Variable class
//  friend class VarArray;


#define VAR_UNARYOP(op) \
  BasicVariable::ptr operator op() \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

/*
#define VAR_OP_VAR(op) \
  BasicVariable::ptr operator op(const Variable<T>& b) \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }
*/

#define VAR_OP_BASICVAR(op) \
  BasicVariable::ptr operator op(const BasicVariable& b) \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

/*
#define VAR_OP_VAR2(op) \
  BasicVariable::ptr operator op(const Variable<T>& b);
*/

//#define VAR_OP_VAR2(op) 
//  template<class U> 
//  BasicVariable::ptr operator op(const Variable<U>& b); 

#define VAR_COMP_OP_BASICVAR(op) \
  BasicVariable::ptr operator op(const BasicVariable& b) \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

#define VAR_LOGIC_OP(op) \
  BasicVariable::ptr operator op() \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

#define VAR_LOGIC_OP_VAR(op) \
  BasicVariable::ptr operator op(const BasicVariable& b) \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

  /** @name ArithmeticOperators
   *  Variable Arithmetic Operators.
   */
  //@{
  // -------- Operators ---

  /// +T
  VAR_UNARYOP(+)
  /// prefix ++ operator ++T 
  VAR_UNARYOP(++)
  /// postfix ++ operator T++ 
  BasicVariable::ptr operator ++(int)
  {
     std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl;
     return this->NewReference(); 
  }

  /// -T
  VAR_UNARYOP(-)
  /// prefix -- operator --T 
  VAR_UNARYOP(--)
  /// postfix -- operator T-- 
  BasicVariable::ptr operator --(int)
  {
     std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl;
     return this->NewReference(); 
  }

  /// a+b
  // can I keep the const here, no because we return a reference ... ???
  // question, should we create a new variable ????
  // in this case yes, and the rule should take care of choosing a+b or a+=b to avoid 
  // a new allocation
  VAR_OP_BASICVAR(+);
  VAR_OP_BASICVAR(+=);
  VAR_OP_BASICVAR(-);
  VAR_OP_BASICVAR(-=);
  VAR_OP_BASICVAR(*);
  VAR_OP_BASICVAR(*=);
  VAR_OP_BASICVAR(/);
  VAR_OP_BASICVAR(/=);
  VAR_OP_BASICVAR(%);
  VAR_OP_BASICVAR(%=);

  //@}

  /** @name ComparisonOperators
   *  Variable Comparison operators/Relational operators.
   */
  //@{
    VAR_COMP_OP_BASICVAR(<);
    VAR_COMP_OP_BASICVAR(<=);
    VAR_COMP_OP_BASICVAR(>);
    VAR_COMP_OP_BASICVAR(>=);
    VAR_COMP_OP_BASICVAR(!=);
    VAR_COMP_OP_BASICVAR(==);
  //@}

  /** @name LogicalOperators
   *  Variable Logical operators.
   */
  //@{
    VAR_LOGIC_OP(!);
    VAR_LOGIC_OP_VAR(&&);
    VAR_LOGIC_OP_VAR(||);
  //@}

  /** @name BitwiseOperators
   *  Variable Bitwise operators.
   */
  //@{
  //@}

  /** @name OtherOperators
   *  Variable Other operators.
   */
  //@{
  //@}

}; // class Variable

template<class T>  
std::ostream& operator<<(std::ostream& o, const Variable<T>& v);



#include "Variable.tpp"

#endif
