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

#define STATIC_HELP \
    const std::string GetDescription()  { return StaticDescription();  }\
    const std::string GetFunctionName() { return StaticFunctionName(); }\

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
      SetParametersComments(); \
    } \
    void SetParametersComments(); \
    BasicVariable::ptr CallMember(ParamList*); \
    static const std::string StaticDescription()  { return description_str; }\
    static const std::string StaticFunctionName() \
    { return std::string(#classname)+"::"+#methodname; }\
    STATIC_HELP\
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
      SetParametersComments(); \
    } \
    void SetParametersComments(); \
    BasicVariable::ptr CallMember(ParamList*); \
    static const std::string StaticDescription()  { return description_str; }\
    static const std::string StaticFunctionName() \
    { std::string classname(AMILabType<ObjectType>::name_as_string());\
      return classname+"::"+#methodname; }\
    STATIC_HELP\
}; \
\
void AddVar_##methodname(  _parentclass_ptr& pc, const std::string& newname = #methodname) {\
  boost::shared_ptr<WrapClassMember> tmp( new wrap_##methodname(pc));\
  AMIObject::ptr tmpobj(amiobject.lock()); \
  tmpobj->GetContext()->AddVar<WrapClassMember>(newname, tmp,tmpobj->GetContext()); \
}

//    const boost::shared_ptr<ObjectType>& GetObj() const { return _objectptr->GetObj(); }  


/**
  Macro to wrap Set/Get methods
  */
#define ADD_CLASS_SETGET(type,varname,description_str) \
/**\
 * Sets the variable varname, description_str\
 **/\
class wrap_Set##varname : public WrapClassMember { \
  protected:\
    _parentclass_ptr _objectptr; \
  public: \
    wrap_Set##varname(_parentclass_ptr& pp) : \
     _objectptr(pp) { \
      ADDPARAMCOMMENT_TYPE(type,description_str); \
    } \
    BasicVariable::ptr CallMember(ParamList* p) { \
      int n=0;\
      type val; \
      if (!get_val_param<type>( val, p, n)) ClassHelpAndReturn; \
      _objectptr->GetObj()->Set##varname(val); \
      return BasicVariable::ptr(); \
    } \
    static const std::string StaticDescription()  \
    { return std::string("Sets ")+description_str; }\
    static const std::string StaticFunctionName() \
    { std::string classname(AMILabType<ObjectType>::name_as_string());\
      return classname+"::Set"+#varname; }\
    STATIC_HELP\
}; \
\
/**\
 * Gets the variable varname, description_str\
 **/\
class wrap_Get##varname : public WrapClassMember { \
  protected:\
    _parentclass_ptr _objectptr; \
  public: \
    wrap_Get##varname(_parentclass_ptr& pp) : \
     _objectptr(pp) { \
      return_comments = (boost::format("Returns a variable of type %1%.") % AMILabType<type>::name_as_string().c_str()).str(); \
    } \
    BasicVariable::ptr CallMember(ParamList*) { \
      type val = this->_objectptr->GetObj()->Get##varname(); \
      RETURN_VAR(type,val); \
    } \
    static const std::string StaticDescription()  \
    { return std::string("Gets ")+description_str; }\
    static const std::string StaticFunctionName() \
    { std::string classname(AMILabType<ObjectType>::name_as_string());\
      return classname+"::Get"+#varname; }\
    STATIC_HELP\
}; \
\
void AddVar_SetGet##varname(  _parentclass_ptr& pc) {\
  boost::shared_ptr<WrapClassMember> tmp; \
  AMIObject::ptr tmpobj(amiobject.lock()); \
  tmp = boost::shared_ptr<WrapClassMember>( new wrap_Set##varname(pc));\
  tmpobj->GetContext()->AddVar<WrapClassMember>(\
    std::string("Set")+#varname, tmp,tmpobj->GetContext()); \
  tmp = boost::shared_ptr<WrapClassMember>( new wrap_Get##varname(pc));\
  tmpobj->GetContext()->AddVar<WrapClassMember>(\
    std::string("Get")+#varname, tmp,tmpobj->GetContext()); \
} \

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
      SetParametersComments(); \
    } \
    void SetParametersComments(); \
    BasicVariable::ptr CallMember(ParamList* p); \
    static const std::string StaticDescription()  { return description_str; }\
    static const std::string StaticFunctionName() \
    { std::string classname(AMILabType<ObjectType>::name_as_string());\
      return classname+"::"+#methodname; }\
    STATIC_HELP\
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

// simple return with empty variable for a class member
#define ClassReturnEmptyVar  \
    return BasicVariable::ptr();

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
   this->paramtypes.push_back(AMILabType<type>::name_as_string());

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

    // import to declare virtual destructor here !!!
    virtual ~WrapClassBase() {}

    /// use weak pointer here to prevent blocking the object from being deleted
    boost::weak_ptr<AMIObject> amiobject;

    void SetAMIObject(boost::shared_ptr<AMIObject> obj) 
    {
      amiobject = boost::weak_ptr<AMIObject>(obj);
    }

    virtual int GetObjCounter() { return 0; }

};

// is it useful to add this intermediate class?
/**
 Base Template class for class wrapping.
 Allows including some static member for the construction and the management of the wrapped class.
 **/
template<class T>
class WrapClass: public virtual WrapClassBase
{

  protected:  
    // for nested classes
    typedef boost::shared_ptr<WrapClass<T> > _parentclass_ptr;
    typedef T ObjectType;

  public:
    //typedef T objtype;
    //typedef boost::shared_ptr<T> objtype_ptr;
    typedef boost::shared_ptr<WrapClass<T> > ptr;


    /// Stores a pointer to an object of type File.
    boost::shared_ptr<T> _obj;
    const boost::shared_ptr<T>& GetObj() const { return _obj; }

    virtual int GetObjCounter() const
    {
      return _obj.use_count();
    }

    /// Constructor
    WrapClass<T>(boost::shared_ptr<T> si):  _obj(si)
    {}

    // import to declare virtual destructor here !!!
    virtual ~WrapClass<T>()
    {
//      std::cout << "~WrapClass<" << AMILabType<T>::name_as_string() << ">" << std::endl;
//      std::cout << "_obj.use_count() = " << _obj.use_count() << std::endl;
    }

    /// Constructor without parameters to deal with inheritance
    /// and avoid multiple smart pointers inside

    // Will call the constructor based on a ParamList
    static BasicVariable::ptr CreateVar(ParamList*);
    
    //
    virtual void AddMethods(boost::shared_ptr<WrapClass<T> > this_ptr ) = 0;
    
    /**
    * Create a Wrapped object
    * @param objectptr input smart pointer to a WrapClass<T>
    * @return smart pointer to an AMIObject class
    */
    static AMIObject::ptr AddWrap( boost::shared_ptr<WrapClass<T> >& objectptr)
    {
      // Create new instance of the class
      AMIObject::ptr amiobject( new AMIObject);
      amiobject->SetName(AMILabType<T>::name_as_string());
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
      boost::shared_ptr<WrapClass<T> > obj_smtptr(_objp);
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
//    std::string functionname; 
//    std::string description; 
    std::vector<std::string> parameters_comments;
    std::vector<std::string> paramtypes;
    std::string return_comments;
    std::string return_type;

  public:
    virtual ~WrapClassMember() = 0;
    virtual void SetParametersComments()          {};
    virtual BasicVariable::ptr CallMember(ParamList*)  
    { return BasicVariable::ptr(); };

    /**
     * Display the function help in an information dialog.
     */
    void ShowHelp();
    virtual const std::string GetDescription() = 0;
    virtual const std::string GetFunctionName() = 0;
};
 
inline WrapClassMember::~WrapClassMember() { }  // defined even though it's pure virtual; it's faster this way; 


#endif 
// _wrapfunction_class_h_
