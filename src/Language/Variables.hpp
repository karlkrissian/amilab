
#ifndef _AMI_VARIABLES_H
#define _AMI_VARIABLES_H

// TODO: change and use STL ... !!!
//#define MAX_VARS     500

#include <list>
#include "Variable.hpp"
#include "DefineClass.hpp"

class wxString;
class wxArrayString;

#include <boost/shared_ptr.hpp>


/**
 * Variables for each context.
 **/
class Variables{

  DEFINE_CLASS(Variables);

protected:
  // TODO: avoid pointers here !!!
  std::list<Variable*>  _vars;
  string                _context_name;
  bool                  _global_new;

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
   * @param type 
   * @param name 
   * @param val 
   * @param context 
   * @return 
   */
  Variable* AddVar(vartype type, const char* name, void* val, boost::shared_ptr<Variables> context = boost::shared_ptr<Variables>() );

  /**
   *  Add a new variable based on its type, name, pointer to a smart pointer of the object information, and context.
   * @param type 
   * @param name 
   * @param val 
   * @param context 
   * @return 
   */
  Variable* AddVarPtr(vartype type, const char* name, void* val, boost::shared_ptr<Variables> context = boost::shared_ptr<Variables>());

  Variable* AddVar(Variable* var, Variables::ptr context = Variables::ptr());

  /**
   *  Add a new variable based on a smart pointer to a variable
   * @param var 
   * @param context 
   * @return 
   */
  Variable* AddVarSmtPtr(const Variable::ptr& var, Variables::ptr context = Variables::ptr());

  bool ExistVar(const char* varname);

  bool ExistVar(Variable* var);

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
   * @param var resulting pointer to the variable
   * @return 
   */
  bool GetVar(const char* varname, Variable** var);

//  unsigned char GetVar(const char* varname, int* i);

  bool deleteVar(const char* varname);

  int deleteVars(const std::string& varmatch);

//  unsigned char deleteVar(int i);

  void EmptyVariables();

  void display();

};

#endif
