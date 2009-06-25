
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


//----------------------------------------------------------------------
// Variables for each context
//
class Variables{

  DEFINE_CLASS(Variables)

protected:
  std::list<Variable*>  _vars;
  string                _context_name;
  bool                  _global_new;

 public:

  Variables() {
    _context_name = "global context";
    _global_new = false;
  }

  ~Variables();

//  Variable* operator [](int i) {  return _vars[i];  }

  string GetName() const { return _context_name; }
  void SetName( const string& name ) { _context_name = name; }

  bool GetGlobalNew() const { return _global_new; }
  void SetGlobalNew( const bool& gn ) { _global_new = gn; }

  std::string CheckVarName(const char* name);

  Variable* AddVar(vartype type, const char* name, void* val);

  Variable* AddVarPtr(vartype type, const char* name, void* val);

  Variable* AddVar(Variable* var);

  Variable* AddVar(const Variable::ptr& var);

  Variable* AddImage(char* name, void* val);

  bool ExistVar(const char* varname);

  bool ExistVar(Variable* var);

  void SearchCompletions( const wxString& varname, 
                          boost::shared_ptr<wxArrayString>& completions);

  void SearchVariables( const vartype& type,
                          boost::shared_ptr<wxArrayString>& varlist);

  bool GetVar(const char* varname, Variable** var);

//  unsigned char GetVar(const char* varname, int* i);

  bool deleteVar(const char* varname);

//  unsigned char deleteVar(int i);

  void EmptyVariables();

  void display();

};

#endif
