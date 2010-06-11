
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

#include <vector>
#include <list>
#include <boost/pointer_cast.hpp>

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


/*! \def GET_WRAPPED_OBJECT
    \brief gets the smart pointer to the object wrapped, from a smart pointer to a basic variable
*/
#define GET_WRAPPED_OBJECT(type,var,objname) \
    DYNAMIC_CAST_VARIABLE(AMIObject, var, varobj) \
    boost::shared_ptr<type> objname; \
    if (varobj.get()) { \
      WrapClassBase::ptr wrapped_base(varobj->Pointer()->GetWrappedObject()); \
      WrapClass_##type::ptr wrapped_obj( \
        boost::dynamic_pointer_cast<WrapClass_##type>(wrapped_base)); \
      if (wrapped_obj.get()) \
        objname = wrapped_obj->_obj; \
    }

// TODO: improve this way of wrapping template objects ...
/*! \def GET_WRAPPED_TEMPLATE_OBJECT
    \brief gets the smart pointer to the object wrapped, from a smart pointer to a basic variable where the object comes from a template class
*/
#define GET_WRAPPED_TEMPLATE_OBJECT(type, templ, var,objname) \
    DYNAMIC_CAST_VARIABLE(AMIObject, var, varobj) \
    boost::shared_ptr<type<templ> > objname; \
    if (varobj.get()) { \
      WrapClassBase::ptr wrapped_base(varobj->Pointer()->GetWrappedObject()); \
      WrapClass_##type::ptr wrapped_obj( \
        boost::dynamic_pointer_cast<WrapClass_##type >(wrapped_base)); \
      if (wrapped_obj.get()) \
        objname = wrapped_obj->_obj; \
    }

template<typename> 
struct to_string {
    // optionally, add other information, like the size
    // of the string.
    static char const* value() { return "unknown"; }
};

#define TO_STRING(type) \
  template<> struct to_string<type> { \
      static char const* value() { return #type; } \
  }; \

class FloatMatrix;
class InrImage;

TO_STRING(float);
TO_STRING(double);
TO_STRING(long);
TO_STRING(int);
TO_STRING(unsigned char);
TO_STRING(InrImage);
TO_STRING(std::string);
TO_STRING(FloatMatrix);
// TODO: the rest of convertions

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
	//  typedef typename Variable<T> VariableType;
  typedef typename boost::shared_ptr<Variable<T> >    ptr;
  typedef typename boost::weak_ptr<Variable<T> >      wptr;
  typedef typename std::vector<ptr>     ptr_vector;
  typedef typename std::vector<wptr>    wptr_vector;
  typedef typename std::list<ptr>       ptr_list;
  typedef typename std::list<wptr>      wptr_list;


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
 
  virtual ~Variable()
  { 
    this->Delete(); 
  }

  /**
    * Virtual Method that creates a new smart pointer to a basic variable coming from the same type
    * generic copy of variable, can be specialized per variable type
    */
  BasicVariable::ptr NewCopy() const
  {
    // don't copy a file, keep a reference ...
    CLASS_MESSAGE(boost::format("No default copy of variable contents, need to be specialized for this type of variable ... for variable %1% ")
                        % Name());
    return NewReference();

/*    std::string resname = _name+"_copy";
    boost::shared_ptr<T> copy(new T(*_pointer));
    ptr res(new Variable<T>(resname,copy));
    return res;
*/
  }

  /**
    * Virtual Method that creates a new smart pointer to a basic variable coming from the same type
    * with a reference to the same value
    */
  BasicVariable::ptr NewReference() const
  {
    std::string resname = _name+"_ref";
		ptr res(new Variable<T>(resname,_pointer));
    // copy the comments
    res->SetComments(_comments);
    return res;
  }


  int GetPtrCounter() const
  {
    return _pointer.use_count();
  }

  bool HasPointer() const
  {
    return (_pointer.get()!=NULL);
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
  void operator = (const ptr& v) {
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

  bool Equal(const BasicVariable::ptr& v) 
  {
    if (_type == v->Type()) {
      // convert pointer
      ptr newvar (boost::dynamic_pointer_cast<Variable<T> >(v));
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

  /**
   * Try to cast the variable to the type given as a string in parameter.
   * @param type_string : type as a string
   * @return smart pointer to a variable of the new type if success, empty smart pointer otherwise
   */
  virtual BasicVariable::ptr TryCast(const std::string& type_string) const;

  //
  void display() const;

  virtual double GetValueAsDouble() const;
  
  /*
   * 
   * @return A string containing the type of the variable.
   */
//  virtual std::string GetTypeAsString() const;

  /**
   * 
   * @return A string containing the value of the variable.
   */
  virtual std::string GetValueAsString() const;

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
  BasicVariable::ptr operator op(const BasicVariable::ptr& b) \
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
  BasicVariable::ptr operator op(const BasicVariable::ptr& b) \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

#define VAR_LOGIC_OP(op) \
  BasicVariable::ptr operator op() \
  { std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

#define VAR_LOGIC_OP_VAR(op) \
  BasicVariable::ptr operator op(const BasicVariable::ptr& b) \
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
    VAR_LOGIC_OP_VAR(^);
  //@}

  /** @name OtherOperators
   *  Variable Other operators.
   */
  //@{
    VAR_OP_BASICVAR(=);

    /**
    * left_assign is operator <<=, force assignation of new variable, even if a new pointer to the object needs to be created
    * @param b 
    * @return 
    */
    BasicVariable::ptr left_assign(const BasicVariable::ptr& b) 
    { 
      std::cout << get_name() << " " 
                << __func__ << " not defined." << std::endl; 
      return this->NewReference(); 
    }


    /// Transpose
    BasicVariable::ptr Transpose()
    {
       std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl;
      return this->NewReference();
    }

    /// Pointwise multiplication 
    BasicVariable::ptr PointWiseMult(const BasicVariable::ptr& b)
    {
       std::cout << get_name() << "::operator " << __func__ << " not defined." << std::endl;
      return this->NewReference();
    }
  //@}

#define VAR_FUNC(func) \
  BasicVariable::ptr m_##func() \
  { std::cout << get_name() << " " << __func__ << " not defined." << std::endl; \
    return this->NewReference(); }

  /** @name Mathematical functions
   *  Mathematical functions.
   */
  //@{
    VAR_FUNC(sin)
    VAR_FUNC(cos)
    VAR_FUNC(tan)
    VAR_FUNC(asin)
    VAR_FUNC(acos)
    VAR_FUNC(atan)
    VAR_FUNC(fabs)
    VAR_FUNC(round)
    VAR_FUNC(floor)
    VAR_FUNC(exp)
    VAR_FUNC(log)
    VAR_FUNC(ln)
    VAR_FUNC(norm)
    VAR_FUNC(sqrt)
  //@}


  BasicVariable::ptr BasicCast(const int& type) 
  {
    std::cout << get_name() << " " << __func__ << " not defined." << std::endl; 
    return this->NewReference(); 
  }

  BasicVariable::ptr operator[](const BasicVariable::ptr& v)
  {
    std::cout << get_name() << " " << __func__ << " not defined." << std::endl; 
    return BasicVariable::empty_variable; 
  }


  BasicVariable::ptr TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2) 
  {
    std::cout << get_name() << " " << __func__ << " not defined." << std::endl; 
    return this->NewReference(); 
  }

}; // class Variable

template<class T>  
std::ostream& operator<<(std::ostream& o, const Variable<T>& v);

/*
/// Variable Cast Operator Class

class CastVariableBase
{
  virtual BasicVariable::ptr operator()( const BasicVariable::ptr& varin) = 0;
};

template<class T, class U>
class CastVariable: public CastVariableBase
{
  BasicVariable::ptr operator()( const BasicVariable::ptr& varin)
  { 
    std::cout << "Cast operation not defined ... :(" << std::endl;
    return varin->NewReference(); 
  }
};
*/

#include "Variable.tpp"

//#include "Variable.cpp"

/*
class InrImage;
class DessinImage;


class Viewer3D;
//class C_wrap_procedure;
class WrapClassMember;
//class C_wrap_imagefunction;
//class C_wrap_varfunction;
class AMIFunction;
class AMIClass;
class AMIObject;
class AMICPPObject;
class FloatMatrix;
class GLTransfMatrix;
class VarArray;
*/


#include "Variable_float.h"
#include "Variable_double.h" /// New (added: 24/05/2010)
#include "Variable_long.h"   /// New (added: 27/05/2010)
#include "Variable_int.h"
#include "Variable_uchar.h"
#include "Variable_InrImage.h"
#include "Variable_string.h"
#include "Variable_FloatMatrix.h"
#include "Variable_AMIObject.h"



#endif
