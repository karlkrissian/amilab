//
// C++ Interface: wrapfunction_class
//
// Description: Prototype for wrapping functions
// based on http://www.parashift.com/c++-faq-lite/pointers-to-members.html#faq-33.1
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrapfunction_class_h_
#define _wrapfunction_class_h_

#include "paramlist.h"
#include "DefineClass.hpp"

/** Macro for adding a class that wraps a method.
  */
#define ADD_METHOD(classname,methodname,description_str) \
/**\
 * description_str\
 **/\
class wrap_##classname##methodname : public WrapClassMember { \
  protected:\
    classname::ptr _objectptr; \
  public: \
    wrap_##classname##methodname(const classname::ptr& pp) : \
     _objectptr(pp) { \
      functionname = #classname;\
      functionname += "::";\
      functionname += #methodname; \
      description=description_str; \
      SetParametersComments(); \
    } \
    void SetParametersComments(); \
    BasicVariable::ptr CallMember(ParamList*); \
};

/**
    Macro for adding the members to a class.
 */
#define ADDMEMBER(str_name,classname,proc_name) \
  {\
    boost::shared_ptr<WrapClassMember> tmp( new wrap_##classname##proc_name(objectptr));\
    Vars.AddVar<WrapClassMember>(str_name,  \
                tmp, \
                OBJECT_CONTEXT_NUMBER); \
  }

/** Shows help and returns 
*/
// TODO:mettre un message plus explicite avec le numero et le nom du paramete ...
#define ClassHelpAndReturn { \
    this->ShowHelp();\
    return BasicVariable::ptr();\
  }

/**
 * Add the comments for the next parameter for a wrapped class member.
 **/
#define ADDPARAMCOMMENT(c)  this->parameters_comments.push_back(c)


/**
 * Basic class for wrapping class function members.
 **/
class WrapClassMember {

  DEFINE_CLASS(WrapClassMember);

  protected:
    std::string functionname;
    std::string description;
    std::vector<std::string> parameters_comments;
    std::string return_comments;

  public:
    virtual ~WrapClassMember() = 0;
    virtual void SetParametersComments()          {};
    virtual BasicVariable::ptr CallMember(ParamList*)  
    { return BasicVariable::ptr(); };

    /**
     * Display the function help in an information dialog.
     */
    void ShowHelp();

};
 
inline WrapClassMember::~WrapClassMember() { }  // defined even though it's pure virtual; it's faster this way; 


#endif 
// _wrapfunction_class_h_
