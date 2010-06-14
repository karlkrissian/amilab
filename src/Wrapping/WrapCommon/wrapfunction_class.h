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

/** Macro for adding a nested class that wraps a method.
  * requires that the type '_parentclass_ptr' be defined as a smart pointer to
  * the parent class
  * and that the parent class has a method get_name() returning 
  * the name of the class (it is provided by the macro DEFINE_CLASS).
  * and a AMIObject:ptr amiobject member pointing to the corresponding wrapped object class
  */
#define ADD_CLASS_METHOD(methodname,description_str) \
/**\
 * description_str\
 **/\
class wrap_##methodname : public WrapClassMember { \
  protected:\
    _parentclass_ptr _objectptr; \
  public: \
    wrap_##methodname(_parentclass_ptr& pp) : \
     _objectptr(pp) { \
      functionname = _objectptr->get_name();\
      functionname += "::";\
      functionname += #methodname; \
      description=description_str; \
      SetParametersComments(); \
    } \
    void SetParametersComments(); \
    BasicVariable::ptr CallMember(ParamList*); \
}; \
\
void AddVar_##methodname(  _parentclass_ptr& pc, const std::string& newname = #methodname) {\
  boost::shared_ptr<WrapClassMember> tmp( new wrap_##methodname(pc));\
  AMIObject::ptr tmpobj(amiobject.lock()); \
  tmpobj->GetContext()->AddVar<WrapClassMember>(newname, tmp,tmpobj->GetContext()); \
}


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
#define ADDPARAMCOMMENT(c) \
   this->parameters_comments.push_back(c); \
   this->paramtypes.push_back("var");

/**
 * Add the comments for the next parameter for a wrapped class member.
 **/
#define ADDPARAMCOMMENT_TYPE(type,c) \
   this->parameters_comments.push_back(c); \
   this->paramtypes.push_back(to_string<type>::value());


class AMIObject;

class  WrapClassBase
{
  DEFINE_CLASS(WrapClassBase);

  public:
    /// use weak pointer here to prevent blocking the object from being deleted
    boost::weak_ptr<AMIObject> amiobject;

    void SetAMIObject(boost::shared_ptr<AMIObject> obj) 
    {
      amiobject = boost::weak_ptr<AMIObject>(obj);
    }
};

/**
 * Basic class for wrapping class function members.
 **/
class WrapClassMember {

  DEFINE_CLASS(WrapClassMember);

  protected:
    std::string functionname;
    std::string description;
    std::vector<std::string> parameters_comments;
    std::vector<std::string> paramtypes;
    std::string return_comments;

  public:
    std::string GetDescription() { return description; }
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
