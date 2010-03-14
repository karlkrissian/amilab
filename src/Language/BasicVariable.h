
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

  virtual bool operator == (const BasicVariable::ptr& v)  = 0;

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

  const std::string GetTypeName();

  //
  virtual void display()
  {
    //cout << *this;
  }


  // allow access to private members of Variable class
//  friend class VarArray;

}; // class BasicVariable




#endif
