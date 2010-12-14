/**
 * C++ Interface: wrap_wxModule
 *
 * Description: wrapping wxModule
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxModule_h_
#define _wrap_wxModule_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


#ifndef wxModule_declared
  #define wxModule_declared
  AMI_DECLARE_TYPE(wxModule);
#endif

// TODO: check for inheritence ...
class WrapClass_wxModule : public WrapClass<wxModule>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxModule);

  protected:
    typedef WrapClass<wxModule>::ptr _parentclass_ptr;
    typedef wxModule ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxModule>& GetObj() const { return WrapClass<wxModule>::GetObj(); }

    /// Constructor
    WrapClass_wxModule(boost::shared_ptr<wxModule > si): 
    WrapClass<wxModule>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxModule()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxModule*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(RegisterModule,"void wxModule::RegisterModule(wxModule * module) (http://docs.wxwidgets.org/stable/wx_wxmodule.html#registermodule).");
    ADD_CLASS_STATICMETHOD(RegisterModules,"void wxModule::RegisterModules() (http://docs.wxwidgets.org/stable/wx_wxmodule.html#registermodules).");
    ADD_CLASS_STATICMETHOD(InitializeModules,"bool wxModule::InitializeModules() (http://docs.wxwidgets.org/stable/wx_wxmodule.html#initializemodules).");
    ADD_CLASS_STATICMETHOD(CleanUpModules,"void wxModule::CleanUpModules() (http://docs.wxwidgets.org/stable/wx_wxmodule.html#cleanupmodules).");
    ADD_CLASS_STATICMETHOD(UnregisterModule,"void wxModule::UnregisterModule(wxModule * module) (http://docs.wxwidgets.org/stable/wx_wxmodule.html#unregistermodule).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Init,"bool wxModule::Init()  (http://docs.wxwidgets.org/stable/wx_wxmodule.html#init)")
    ADD_CLASS_METHOD(Exit,"void wxModule::Exit()  (http://docs.wxwidgets.org/stable/wx_wxmodule.html#exit)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxModule::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxmodule.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxModule & wxModule::operator =(wxModule const & param0) (http://docs.wxwidgets.org/stable/wx_wxmodule.html#__assign__)")




    void AddMethods(WrapClass<wxModule>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxModule_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxModule_h
