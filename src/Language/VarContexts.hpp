// Create several contexts for variables: 
// allow local variables in functions for example
// later will be used for object oriented programming

 
#ifndef _AMI_VARCONTEXTS_HPP
#define _AMI_VARCONTEXTS_HPP

#include <stack>
#include "Variables.hpp"
#include "IdentifierInfo.h"

#include "DefineClass.hpp"

// VarContexts is a stack of contexts, 
// where each context contains a set of variables
class VarContexts {

  DEFINE_CLASS(VarContexts)

private:
  // _current_context is the number of contexts used
  int        _current_context;
 
  // A context is a set of variables
  std::vector<Variables*> _context;


public:

  VarContexts();

  ~VarContexts();

  void EmptyVariables();

  int GetNewVarContext();

  void SetGlobalNew(bool gn)  {  _context[_current_context]->SetGlobalNew(gn);}

  int GetCurrentContextNumber() {
    return _current_context;
  }
  
  void SetGlobalContext();
  void SetLastContext();

  Variables* GetCurrentContext() {
    return _context[_current_context];
  }

  bool NewContext(const char* name);

  bool DeleteLastContext();

  void display();

  bool ExistVar(const char* varname);

  boost::shared_ptr<wxArrayString> SearchCompletions(const wxString& varname);

  /// here void* val is a pointer to the variable type
  /// context is the context where to add the variable
  /// -1 means the current context
  Variable* AddVar(vartype type, const char* name, void* val,
                    int context=-1);

  /// IndentifierInfo contains the name and the context
  Variable* AddVar(vartype type, const IdentifierInfo::ptr& info, void* val);

  // here void* val is a pointer to 
  // a smart pointer of the variable type
  Variable* AddVarPtr(vartype type, const char* name, void* val);

  Variable* AddVar(Variable* var, int context=-1);

  Variable* AddVar(Variable::ptr var, int context=-1);

  bool GetVar( const char* varname, Variable** var,
                        int context=-1);

  bool deleteVar(const char* varname);

  int GetContext(Variable* var);
  bool deleteVar(Variable* var);

};


#endif //_AMI_VARCONTEXTS_HPP
