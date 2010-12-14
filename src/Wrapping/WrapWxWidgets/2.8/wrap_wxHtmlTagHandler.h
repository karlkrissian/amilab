/**
 * C++ Interface: wrap_wxHtmlTagHandler
 *
 * Description: wrapping wxHtmlTagHandler
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlTagHandler_h_
#define _wrap_wxHtmlTagHandler_h_

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


#ifndef wxHtmlTagHandler_declared
  #define wxHtmlTagHandler_declared
  AMI_DECLARE_TYPE(wxHtmlTagHandler);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlTagHandler : public WrapClass<wxHtmlTagHandler>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxHtmlTagHandler);

  protected:
    typedef WrapClass<wxHtmlTagHandler>::ptr _parentclass_ptr;
    typedef wxHtmlTagHandler ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlTagHandler>& GetObj() const { return WrapClass<wxHtmlTagHandler>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlTagHandler(boost::shared_ptr<wxHtmlTagHandler > si): 
    WrapClass<wxHtmlTagHandler>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlTagHandler()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlTagHandler*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlTagHandler::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmltaghandler.html#getclassinfo)")
    ADD_CLASS_METHOD(SetParser,"void wxHtmlTagHandler::SetParser(wxHtmlParser * parser)  (http://docs.wxwidgets.org/stable/wx_wxhtmltaghandler.html#setparser)")





    void AddMethods(WrapClass<wxHtmlTagHandler>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlTagHandler_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlTagHandler_h
