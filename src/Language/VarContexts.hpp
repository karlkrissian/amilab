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

  DEFINE_CLASS(VarContexts);

private:
  /// _current_context is the number of contexts used
  int        _current_context;
 
  /// A context is an array of variables
  std::vector<Variables::ptr> _context;

  /// built-in context for variable accessible everywhere
  Variables::ptr _builtin_context;

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
   * @return The builtin context
   */
  Variables::ptr& GetBuiltinContext() 
  { 
    return _builtin_context;
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
   * Sets the current context number
   * @param  
   */
  void SetCurrentContextNumber( int context) {
    if ((context>=0)&&(context<_context.size()))
      _current_context = context;
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
  template <class T>
  boost::shared_ptr<Variable<T> > AddVar(const char* name, boost::shared_ptr<Variable<T> >& val, int context=NEWVAR_CONTEXT)
  {
      if (context==OBJECT_CONTEXT_NUMBER) {
        if (_object_context.get()) {
          CLASS_MESSAGE(boost::format("adding object of type %1%, name %2% into object context ")
                          % val->GetTypeName() 
                          % name);
          return _object_context->AddVar<T>(name,val, _object_context);
      }
      else {
        CLASS_ERROR("Calling object variable without any object context");
        return boost::shared_ptr<Variable<T> >();
      }
    }
  
    if (context==NEWVAR_CONTEXT) context = GetNewVarContext();
    return _context[context]->AddVar<T>(name,val);
  }

  ///
  template <class T>
  boost::shared_ptr<Variable<T> > AddVar(const std::string& name, boost::shared_ptr<T>& val, int context=NEWVAR_CONTEXT)
  {
      if (context==OBJECT_CONTEXT_NUMBER) {
        if (_object_context.get()) {
          CLASS_MESSAGE(boost::format("adding object name %1% into object context ")
                          % name);
          boost::shared_ptr<Variable<T> > newvar ( 
            new Variable<T>(name,val));
          return _object_context->AddVar<T>(name,newvar, _object_context);
      }
      else {
        CLASS_ERROR("Calling object variable without any object context");
        return boost::shared_ptr<Variable<T> >();
      }
    }
  
    if (context==NEWVAR_CONTEXT) context = GetNewVarContext();
    //boost::shared_ptr<Variable<T> > newvar( new Variable<T>(name,val));
    return _context[context]->AddVar<T>(name,val);
  }



  BasicVariable::ptr AddVar(const char* name, BasicVariable::ptr& val, int context=NEWVAR_CONTEXT)
  {
      if (context==OBJECT_CONTEXT_NUMBER) {
        if (_object_context.get()) {
          CLASS_MESSAGE(boost::format("adding object of type %1%, name %2% into object context ")
                          % val->GetTypeName() 
                          % name);
          return _object_context->AddVar(name,val, _object_context);
      }
      else {
        CLASS_ERROR("Calling object variable without any object context");
        return BasicVariable::ptr();
      }
    }
  
    if (context==NEWVAR_CONTEXT) context = GetNewVarContext();
    return _context[context]->AddVar(name,val);
  }

  /**
   * Adds a new variable based on a smart pointer to a variable and a context id.
   * @param var 
   * @param context 
   * @return smart pointer to the resulting variable
   */
  BasicVariable::ptr AddVar(BasicVariable::ptr var, int context=NEWVAR_CONTEXT);

  template <class T>
  boost::shared_ptr<Variable<T> > AddVar(  
                const IdentifierInfo::ptr& info, 
                boost::shared_ptr<Variable<T> >& val);

  template <class T>
  boost::shared_ptr<Variable<T> > AddVar(  
                const IdentifierInfo::ptr& info, 
                boost::shared_ptr<T >& val);

  BasicVariable::ptr AddVar(  
              const IdentifierInfo::ptr& info, 
              BasicVariable::ptr& val);

  /**
   * Find a variable based on its name, if context is -1, look for variable in the local context
   * @param varname name of the variable
   * @param context possible values: -1, 0--contexts, OBJECT_CONTEXT_NUMBER
   * @return resulting smart pointer to the variable if any
   */
  BasicVariable::ptr GetVar( const char* varname, int context=NEWVAR_CONTEXT);

  bool deleteVar(const char* varname);

  int deleteVars(const std::string& varmatch);

  int GetContext(BasicVariable::ptr var);

//  template <class T>
//  int GetContext(boost::shared_ptr<Variable<T> >& var);

  bool deleteVar(BasicVariable::ptr var);
  bool deleteVar(BasicVariable* var);

  template <class T>
  bool deleteVar(boost::shared_ptr<Variable<T> >& var);
};

#include "VarContexts.tpp"

#endif //_AMI_VARCONTEXTS_HPP
