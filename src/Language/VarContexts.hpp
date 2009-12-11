/** 
 * \file VarContexts.hpp
 * \author Karl Krissian
 * Create several contexts for variables: 
 * allow local variables in functions for example
 * later will be used for object oriented programming
 */

 
#ifndef _AMI_VARCONTEXTS_HPP
#define _AMI_VARCONTEXTS_HPP

#include <stack>
#include "Variables.hpp"
#include "IdentifierInfo.h"

#include "DefineClass.hpp"

#define NEWVAR_CONTEXT -1
#define OBJECT_CONTEXT_NUMBER -10

/** VarContexts
 *  is a stack of contexts, 
 *  where each context contains a set of variables
 **/
class VarContexts {

  DEFINE_CLASS(VarContexts)

private:
  /// _current_context is the number of contexts used
  int        _current_context;
 
  /// A context is an array of variables
  std::vector<Variables::ptr> _context;

  /// points to the current object context
  Variables::ptr _object_context;

public:

  /// Constructor
  VarContexts();

  /// Destructor
  virtual ~VarContexts();

  /// Remove all the variables
  void EmptyVariables();

  /// Creates a new context of variables
  int GetNewVarContext();

  /// Sets the current object context
  void SetObjectContext(const Variables::ptr& ocontext)
  {
    _object_context = ocontext;
  }

  /**
   * @return a reference to the current object context
   */
  Variables::ptr& GetObjectContext() 
  { 
    return _object_context;
  }

  /**
   * Activate/Desactivate the creation of new variables as global
   * @param gn 
   */
  void SetGlobalNew(bool gn)  {  _context[_current_context]->SetGlobalNew(gn);}

  /**
   * @return the current context number
   */
  int GetCurrentContextNumber() {
    return _current_context;
  }
  
  /**
   * 
   */
  void SetGlobalContext();
  void SetLastContext();

  Variables::ptr GetCurrentContext() {
    return _context[_current_context];
  }

  /**
   * Creates a new context
   * @param name of the new context
   * @return true/false for success/failure
   */
  bool NewContext(const char* name);

  bool DeleteLastContext();

  void display();

  bool ExistVar(const char* varname);

  boost::shared_ptr<wxArrayString> SearchCompletions(const wxString& varname);

  boost::shared_ptr<wxArrayString> SearchVariables(const vartype& type);

/**
 * 
 * @param type variable type
 * @param name variable name
 * @param val is a pointer to the variable type
 * @param context NEWVAR_CONTEXT (-1) means the current context | OBJECT_CONTEXT_NUMBER (-10) 
 * @return 
 */
  Variable* AddVar(vartype type, const char* name, void* val,
                    int context=NEWVAR_CONTEXT);

  /// IndentifierInfo contains the name and the context
  Variable* AddVar(vartype type, const IdentifierInfo::ptr& info, void* val);

  // here void* val is a pointer to 
  // a smart pointer of the variable type
  Variable* AddVarPtr(vartype type, const char* name, void* val);

  Variable* AddVar(Variable* var, int context=NEWVAR_CONTEXT);

  Variable* AddVar(Variable::ptr var, int context=NEWVAR_CONTEXT);

  bool GetVar( const char* varname, Variable** var,
                        int context=NEWVAR_CONTEXT);

  bool deleteVar(const char* varname);

  int deleteVars(const std::string& varmatch);

  int GetContext(Variable* var);
  bool deleteVar(Variable* var);

};


#endif //_AMI_VARCONTEXTS_HPP
