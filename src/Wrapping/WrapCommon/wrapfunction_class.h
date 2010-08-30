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

// new includes needed for WrapClass<T>
#include "ami_object.h"
#include "Variable.hpp"

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

/** Macro for adding the class constructor with a static function
  to create the variable
  */
#define ADD_CLASS_CONSTRUCTOR(methodname,description_str) \
/**\
 * description_str\
 **/\
class wrap_##methodname : public WrapClassMember { \
  public: \
    wrap_##methodname() { \
      functionname = #methodname; \
      description=description_str; \
      SetParametersComments(); \
    } \
    void SetParametersComments(); \
    BasicVariable::ptr CallMember(ParamList* p); \
}; \
\
static void AddVar_##methodname(  Variables::ptr& _context, const std::string& newname = #methodname) {\
  boost::shared_ptr<WrapClassMember> tmp( new wrap_##methodname());\
  _context->AddVar<WrapClassMember>(newname, tmp, _context); \
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

/*! \def GET_PARAM
    \brief Extracts the value of the next parameter from the list.
*/
#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

/*! \def GET_PARAM
    \brief Extracts a smart pointer of the next parameter from the list.
*/
#define GET_SMTPTR_PARAM(type,varname) \
  boost::shared_ptr<type> varname; \
  if (!get_val_smtptr_param<type>( varname, p, n)) \
    ClassHelpAndReturn;


class AMIObject;

/**
 Base class for class wrapping
 **/
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

// is it useful to add this intermediate class?
/**
 Base Template class for class wrapping.
 Allows including some static member for the construction and the management of the wrapped class.
 **/
template<class T>
class WrapClass: public WrapClassBase
{

  protected:  
    // for nested classes
    typedef boost::shared_ptr<WrapClass<T> > _parentclass_ptr;

  public:
    typedef boost::shared_ptr<WrapClass<T> > ptr;


    /// Stores a pointer to an object of type File.
    boost::shared_ptr<T> _obj;
    const boost::shared_ptr<T>& GetObj() const { return _obj; }

    /// Constructor
    WrapClass<T>(boost::shared_ptr<T> si):  _obj(si)
    {}

    // Will call the constructor based on a ParamList
    static BasicVariable::ptr CreateVar(ParamList*);
    
    //
    virtual void AddMethods(WrapClass<T>::ptr this_ptr ) = 0;
    
    /**
    * Create a Wrapped object
    * @param objectptr input smart pointer to a WrapClass<T>
    * @return smart pointer to an AMIObject class
    */
    static AMIObject::ptr AddWrap( WrapClass<T>::ptr& objectptr)
    {
      // Create new instance of the class
      AMIObject::ptr amiobject( new AMIObject);
      amiobject->SetName(to_string<T>::value());
      amiobject->SetWrappedObject(objectptr);
      objectptr->SetAMIObject(amiobject);
      objectptr->AddMethods( objectptr);
      return amiobject;
    }
  
    /**
    * Create a Wrapped object
    * @param si_ptr input smart pointer to the template class T
    * @return smart pointer to an AMIObject class
    */
    static Variable<AMIObject>::ptr CreateVar( WrapClass<T>* _objp)
    {
      WrapClass<T>::ptr obj_smtptr(_objp);
      AMIObject::ptr amiobject(AddWrap(obj_smtptr));
      boost::shared_ptr<Variable<AMIObject> > varres(
          new Variable<AMIObject>( amiobject));
      return varres;
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
