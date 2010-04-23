
#ifndef _AMI_BASICVARIABLE_H
#define _AMI_BASICVARIABLE_H

//#include "ParamBox.hpp"
//#include "DessinImage.hpp"
//#include "Viewer3D.hpp"
//#include "paramlist.h"
#include <string>
#include <string.h>
#include <iostream>

#include "DefineClass.hpp"

#include "amilab_messages.h"
#include "vartype.h"
//#include "paramlist.h"

// forward definition of Variables
class Variables;
//class VarArray;


/*
template<class T>  
std::ostream& operator<<(std::ostream& o, const Variable<T>& v);

template<class T> 
std::ostream& PrintType(std::ostream& o, const Variable<T>& v);
*/


/// Getting variable type 
template<class T> vartype GetVarType();


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
  virtual ~BasicVariable() {};

  /**
    * Virtual Method that creates a new smart pointer to a basic variable with the same type
    */
  virtual BasicVariable::ptr NewCopy() = 0;

  /**
    * Virtual Method that creates a new smart pointer to a basic variable with the same type
    */
  virtual BasicVariable::ptr NewReference() = 0;

//  virtual void operator = (const BasicVariable& v) = 0;

//  void operator = (const BasicVariable::ptr& v) {
//     (*this) = (*v);
//  }

  virtual bool Equal(const BasicVariable::ptr& v)  = 0;

  virtual bool operator == (BasicVariable* v)  = 0;

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

  const std::string GetTypeName() const;

  //
  virtual void display()
  {
    //cout << *this;
  }

  virtual bool IsNumeric() const
  {
    return  (_type==type_float)||
            (_type==type_int)||
            (_type==type_uchar);
  }

  virtual double GetValueAsDouble() const = 0;

  /**
   * Virtual method to return the value of a variable.
   * @return a string containing the value of the variable.
   */
  virtual std::string GetValueAsString() const = 0;

  // allow access to private members of Variable class
//  friend class VarArray;



#define BASICVAR_UNARYOP(op) \
  virtual BasicVariable::ptr operator op() \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

#define BASICVAR_OP_VAR(op) \
  virtual BasicVariable::ptr operator op(const BasicVariable::ptr& b) \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }


#define BASICVAR_COMP_OP_VAR(op) \
  virtual BasicVariable::ptr operator op(const BasicVariable::ptr& b) \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

#define BASICVAR_LOGIC_OP(op) \
  virtual BasicVariable::ptr operator op() \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

#define BASICVAR_LOGIC_OP_VAR(op) \
  virtual BasicVariable::ptr operator op(const BasicVariable::ptr& b) \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

  /** @name ArithmeticOperators
   *  Variable Arithmetic Operators.
   */
  //@{
  // -------- Operators ---

  /// +T
  BASICVAR_UNARYOP(+)

  /// prefix ++ operator ++T 
  BASICVAR_UNARYOP(++)

  /// prefix ++ operator T-- 
  BasicVariable::ptr operator ++(int)
  { return this->NewReference(); }



  /// a+b
  // can I keep the const here, no because we return a reference ... ???
  // question, should we create a new variable ????
  // in this case yes, and the rule should take care of choosing a+b or a+=b to avoid 
  // a new allocation
  BASICVAR_OP_VAR(+);
  BASICVAR_OP_VAR(+=);

  /// -T
  BASICVAR_UNARYOP(-)

  /// a-b
  BASICVAR_OP_VAR(-);

  /// prefix -- operator --T 
  BASICVAR_UNARYOP(--)

  /// prefix -- operator T-- 
  BasicVariable::ptr operator --(int)
  { return this->NewReference(); }

  BASICVAR_OP_VAR(-=);
  BASICVAR_OP_VAR(*);
  BASICVAR_OP_VAR(*=);
  BASICVAR_OP_VAR(/);
  BASICVAR_OP_VAR(/=);
  BASICVAR_OP_VAR(%);
  BASICVAR_OP_VAR(%=);

  //@}

  /** @name ComparisonOperators
   *  Variable Comparison operators/Relational operators.
   */
  //@{
    BASICVAR_COMP_OP_VAR(<);
    BASICVAR_COMP_OP_VAR(<=);
    BASICVAR_COMP_OP_VAR(>);
    BASICVAR_COMP_OP_VAR(>=);
    BASICVAR_COMP_OP_VAR(!=);
    BASICVAR_COMP_OP_VAR(==);
  //@}

  /** @name LogicalOperators
   *  Variable Logical operators.
   */
  //@{
    BASICVAR_LOGIC_OP(!);
    BASICVAR_LOGIC_OP_VAR(&&);
    BASICVAR_LOGIC_OP_VAR(||);
  //@}

  /** @name BitwiseOperators
   *  Variable Bitwise operators.
   */
  //@{
    BASICVAR_LOGIC_OP_VAR(^);
  //@}

  /** @name OtherOperators
   *  Variable Other operators.
   */
  //@{
    /// basic assignment operator
    BASICVAR_OP_VAR(=);

    /// Transpose operator
    virtual BasicVariable::ptr Transpose()
    { return this->NewReference(); }

    /// PointWise multiplication, included for matrices
    virtual BasicVariable::ptr PointWiseMult(const BasicVariable::ptr& b) 
    {
      std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; 
      return this->NewReference(); 
    }
  //@}


#define BASICVAR_FUNC(func) \
  virtual BasicVariable::ptr m_##func() \
  { std::cout << get_name() << " " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

  /** @name Mathematical functions
   *  Mathematical functions.
   */
  //@{
    BASICVAR_FUNC(sin)
    BASICVAR_FUNC(cos)
    BASICVAR_FUNC(tan)
    BASICVAR_FUNC(asin)
    BASICVAR_FUNC(acos)
    BASICVAR_FUNC(atan)
    BASICVAR_FUNC(fabs)
    BASICVAR_FUNC(round)
    BASICVAR_FUNC(floor)
    BASICVAR_FUNC(exp)
    BASICVAR_FUNC(log)
    BASICVAR_FUNC(ln)
    BASICVAR_FUNC(sqrt)
    BASICVAR_FUNC(norm)
  //@}

  /**
   * Cast to standard predefined types
   * @param type of type WORDTYPE initially defined for image pixel types
   * @return the new variable after the cast
   */
  virtual BasicVariable::ptr BasicCast(const int& type) = 0;

  virtual BasicVariable::ptr operator[](const BasicVariable::ptr& v) = 0;

  virtual BasicVariable::ptr TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2) = 0;

}; // class BasicVariable



#endif
