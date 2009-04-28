// Create several contexts for variables: 
// allow local variables in functions for example
// later will be used for object oriented programming

 
#ifndef _AMI_VARCONTEXTS_HPP
#define _AMI_VARCONTEXTS_HPP

#include "Variables.hpp"
#define MAX_CONTEXTS 500


// VarContexts is a stack of contexts, 
// where each context contains a set of variables
class VarContexts {

  // _current_context is the number of contexts used
  int        _current_context;
  int        _context_depth;
  int        _num_contexts_allocated;

  // force the next variable to in a given context number
  // if -1, just use the current context
  int        _next_variable_context;
 
  // A context is a set of variables
  Variables* _context;
  Chaine*    _context_name;
  
  // set global context for creation of new variables of a given context
  unsigned char* _global_new; 

  unsigned char DoubleContexts() {
    fprintf(stderr,"VarContexts::DoubleContexts() \t not yet implemented \n");
    return 0;
  }


public:

  VarContexts();

  ~VarContexts();

  void SetNextVarContext(int n) {
    _next_variable_context = n;
  }

  int GetNewVarContext();

  void SetGlobalNew(unsigned char gn)  {  _global_new[_current_context] = gn;}

  int GetCurrentContextNumber() {
    return _current_context;
  }
  
  void SetCurrentContext(int n);
  void SetLastContext();

  Variables* GetCurrentContext() {
    return &_context[_current_context];
  }

  int NewContext(const char* name);

  int DeleteLastContext();

  void display();

  unsigned char ExistVar(const char* varname);

  wxArrayString* SearchCompletions(const wxString& varname);

  // here void* val is a pointer to the variable type
  int AddVar(vartype type, const char* name, void* val);

  // here void* val is a pointer to 
  // a smart pointer of the variable type
  int AddVarPtr(vartype type, const char* name, void* val);

  int AddVar(Variable* var);

  int AddVar(Variable::ptr var);

  unsigned char GetVar( const char* varname, Variable** var,
                        int context=-1);

  unsigned char deleteVar(const char* varname);

  int GetContext(Variable* var);
  unsigned char deleteVar(Variable* var);

};


#endif //_AMI_VARCONTEXTS_HPP
