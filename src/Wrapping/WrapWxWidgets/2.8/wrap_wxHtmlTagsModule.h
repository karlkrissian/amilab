/**
 * C++ Interface: wrap_wxHtmlTagsModule
 *
 * Description: wrapping wxHtmlTagsModule
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlTagsModule_h_
#define _wrap_wxHtmlTagsModule_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxModule.h"


#ifndef wxHtmlTagsModule_declared
  #define wxHtmlTagsModule_declared
  AMI_DECLARE_TYPE(wxHtmlTagsModule);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlTagsModule : public WrapClass<wxHtmlTagsModule>
    , public   WrapClass_wxModule
{
  DEFINE_CLASS(WrapClass_wxHtmlTagsModule);

  protected:
    typedef WrapClass<wxHtmlTagsModule>::ptr _parentclass_ptr;
    typedef wxHtmlTagsModule ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlTagsModule>& GetObj() const { return WrapClass<wxHtmlTagsModule>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlTagsModule(boost::shared_ptr<wxHtmlTagsModule > si): 
    WrapClass<wxHtmlTagsModule>(si)
    , WrapClass_wxModule(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlTagsModule()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlTagsModule_1,"Constructor wxHtmlTagsModule::wxHtmlTagsModule(wxHtmlTagsModule const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmltagsmodule.html#wxhtmltagsmodule).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlTagsModule,"Constructor wxHtmlTagsModule::wxHtmlTagsModule() (http://docs.wxwidgets.org/stable/wx_wxhtmltagsmodule.html#wxhtmltagsmodule).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlTagsModule_2,"Constructor wxHtmlTagsModule::wxHtmlTagsModule() (http://docs.wxwidgets.org/stable/wx_wxhtmltagsmodule.html#wxhtmltagsmodule).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlTagsModule*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlTagsModule::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmltagsmodule.html#getclassinfo)")
    ADD_CLASS_METHOD(OnInit,"bool wxHtmlTagsModule::OnInit()  (http://docs.wxwidgets.org/stable/wx_wxhtmltagsmodule.html#oninit)")
    ADD_CLASS_METHOD(OnExit,"void wxHtmlTagsModule::OnExit()  (http://docs.wxwidgets.org/stable/wx_wxhtmltagsmodule.html#onexit)")
    ADD_CLASS_METHOD(FillHandlersTable,"void wxHtmlTagsModule::FillHandlersTable(wxHtmlWinParser * param0)  (http://docs.wxwidgets.org/stable/wx_wxhtmltagsmodule.html#fillhandlerstable)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxHtmlTagsModule & wxHtmlTagsModule::operator =(wxHtmlTagsModule const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmltagsmodule.html#__assign__)")




    void AddMethods(WrapClass<wxHtmlTagsModule>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlTagsModule_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlTagsModule_h
