
#ifndef _AMI_VARIABLES_H
#define _AMI_VARIABLES_H

#define MAX_VARS     500

#include "Variable.hpp"

class wxString;
class wxArrayString;

#include <boost/shared_ptr.hpp>


//----------------------------------------------------------------------
// Variables for each context
//
class Variables{

  //  static 
  Variable* _vars[MAX_VARS];
  // number of variables used?
  int       _num;

  // table of free positions (< _num) for put a new variable
  int _free_pos[MAX_VARS];
  // number of free positions available
  int _num_free;
  
 private:

  void AddFreePosition( int i);

  int GetFreePosition();

  int SearchFreePosition();


 public:

  Variables();

  ~Variables();

  Variable* operator [](int i) {  return _vars[i];  }

  int AddVar(vartype type, const char* name, void* val);

  int AddVarPtr(vartype type, const char* name, void* val);

  int AddVar(Variable* var);

  int AddVar(const Variable::ptr& var);

  int AddImage(char* name, void* val);

  unsigned char ExistVar(const char* varname, int& varnum);

  unsigned char ExistVar(Variable* var, int& varnum);

  void SearchCompletions(const wxString& varname, wxArrayString* completions);

  bool GetVar(const char* varname, Variable** var);

  unsigned char GetVar(const char* varname, int* i);

  unsigned char deleteVar(const char* varname);

  unsigned char deleteVar(int i);

  void EmptyVariables();

  void display();

};

#endif
