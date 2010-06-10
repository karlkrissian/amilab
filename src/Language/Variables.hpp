
#ifndef _AMI_VARIABLES_H
#define _AMI_VARIABLES_H

// TODO: change and use STL ... !!!
//#define MAX_VARS     500

#include <list>
#include "BasicVariable.h"
#include "Variable.hpp"
#include "DefineClass.hpp"

class wxString;
class wxArrayString;

#include "Variable.hpp"

#include <boost/shared_ptr.hpp>


/**
 * Variables for each context.
 **/
class Variables{

  DEFINE_CLASS(Variables);

protected:
  // TODO: avoid pointers here !!!
  std::list<BasicVariable::ptr>  _vars;
  string                    _context_name;
  bool                      _global_new;

 public:

  Variables() {
    _context_name = "global context";
    _global_new = false;
  }

  virtual ~Variables();

//  Variable* operator [](int i) {  return _vars[i];  }

  std::string GetName() const { return _context_name; }
  void SetName( const string& name ) { _context_name = name; }

  bool GetGlobalNew() const { return _global_new; }
  void SetGlobalNew( const bool& gn ) { _global_new = gn; }

  std::string CheckVarName(const char* name);

  /**
   *  Add a new variable based on its type, name, pointer to the object information, and context.
   * @param name 
   * @param val 
   * @param context 
   * @return a smart pointer to the new variable (base class)
   */
  BasicVariable::ptr AddVar( const std::string& name, BasicVariable::ptr& val, boost::shared_ptr<Variables> context = boost::shared_ptr<Variables>() );

  /**
   *  Add a new variable based on its type, name, pointer to the object information, and context.
   * @param type 
   * @param name 
   * @param val 
   * @param context 
   * @return a smart pointer to the new variable (base class)
   */
  template <class T>
  boost::shared_ptr<Variable<T> > AddVar(
        const std::string& name,
        boost::shared_ptr<Variable<T> >& val,
        boost::shared_ptr<Variables> context = boost::shared_ptr<Variables>() )
{
  CLASS_MESSAGE(boost::format(" %1%, in %2% ") % name % GetName());

  string resname = this->CheckVarName(name.c_str());
  boost::shared_ptr<Variable<T> > newvar(new Variable<T>(name,val->Pointer()));
  //std::cout << "  **  newvar =  " << newvar << endl;

  newvar->Rename(resname.c_str());
  newvar->SetContext(context);
  _vars.push_front(newvar);

  return newvar;
}

  template <class T>
  /**
   * Adds a variable of type T to the context, based on its name, a smart pointer to its value, and an optional context.
   * @param name 
   * @param val 
   * @param context 
   * @return smart pointer to the new variable.
   */
  boost::shared_ptr<Variable<T> > AddVar(
        const std::string& name,
        boost::shared_ptr<T >& val,
        boost::shared_ptr<Variables> context = boost::shared_ptr<Variables>() )
  {
    CLASS_MESSAGE(boost::format(" %1%, in %2% ") % name % GetName());
  
    string resname = this->CheckVarName(name.c_str());
    boost::shared_ptr<Variable<T> > newvar(new Variable<T>(name,val));
    //std::cout << "  **  newvar =  " << newvar << endl;
  
    newvar->Rename(resname.c_str());
    newvar->SetContext(context);
    _vars.push_front(newvar);
  
    return newvar;
  }

  BasicVariable::ptr AddVar(BasicVariable::ptr& var, Variables::ptr context = Variables::ptr());

  /**
   *  Adds a new variable to the context based on a smart pointer to a variable
   * @param var 
   * @param context 
   * @return 
   */
  BasicVariable::ptr AddVar(const BasicVariable::ptr& var, Variables::ptr context = Variables::ptr());

  bool ExistVar(const char* varname);

  bool ExistVar(BasicVariable::ptr& var);

  bool ExistVar(BasicVariable* var);

  void SearchCompletions( const wxString& varname, 
                          boost::shared_ptr<wxArrayString>& completions);

  /**
   *  Search all variable of a given type within the object,
   *  and preprend the given string to the result.
   * @param type 
   * @param varlist 
   * @param preprend
   */
  void SearchVariables( const vartype& type,
                          boost::shared_ptr<wxArrayString>& varlist,
                        const std::string& preprend = "");

  /**
   * Find a variable based on its name.
   * @param varname variable name
   * @return a smart pointer to the variable if found or an empty smart pointer otherwise
   */
  BasicVariable::ptr GetVar(const char* varname);

//  unsigned char GetVar(const char* varname, int* i);

  bool deleteVar(const char* varname);

  int deleteVars(const std::string& varmatch);

//  unsigned char deleteVar(int i);

  void EmptyVariables();

  void display();

};



/*
#include "Variable.hpp"
template <class T>
boost::shared_ptr<Variable<T> > Variables::AddVar(
      const std::string& name,
      boost::shared_ptr<Variable<T> >& val,
      boost::shared_ptr<Variables> context )
{
  CLASS_MESSAGE(boost::format(" %1%, in %2% ") % name % GetName());

  string resname = this->CheckVarName(name.c_str());
  boost::shared_ptr<Variable<T> > newvar(new Variable<T>(name,val->Pointer()));
  //std::cout << "  **  newvar =  " << newvar << endl;

  newvar->Rename(resname.c_str());
  newvar->SetContext(context);
  _vars.push_front(newvar);

  return newvar;
}
*/

#endif
