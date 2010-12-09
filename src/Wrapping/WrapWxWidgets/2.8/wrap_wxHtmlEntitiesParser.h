/**
 * C++ Interface: wrap_wxHtmlEntitiesParser
 *
 * Description: wrapping wxHtmlEntitiesParser
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlEntitiesParser_h_
#define _wrap_wxHtmlEntitiesParser_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxHtmlEntitiesParser);

// TODO: check for inheritence ...
class WrapClass_wxHtmlEntitiesParser : public WrapClass<wxHtmlEntitiesParser>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxHtmlEntitiesParser);

  protected:
    typedef WrapClass<wxHtmlEntitiesParser>::ptr _parentclass_ptr;
    typedef wxHtmlEntitiesParser ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlEntitiesParser>& GetObj() const { return WrapClass<wxHtmlEntitiesParser>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlEntitiesParser(boost::shared_ptr<wxHtmlEntitiesParser > si): 
    WrapClass<wxHtmlEntitiesParser>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlEntitiesParser()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlEntitiesParser,"Constructor wxHtmlEntitiesParser::wxHtmlEntitiesParser() (http://docs.wxwidgets.org/stable/wx_wxhtmlentitiesparser.html#wxhtmlentitiesparser).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlEntitiesParser*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlEntitiesParser::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmlentitiesparser.html#getclassinfo)")
    ADD_CLASS_METHOD(SetEncoding,"void wxHtmlEntitiesParser::SetEncoding(wxFontEncoding encoding)  (http://docs.wxwidgets.org/stable/wx_wxhtmlentitiesparser.html#setencoding)")
    ADD_CLASS_METHOD(Parse,"wxString wxHtmlEntitiesParser::Parse(wxString const & input)  (http://docs.wxwidgets.org/stable/wx_wxhtmlentitiesparser.html#parse)")
    ADD_CLASS_METHOD(GetEntityChar,"wxChar wxHtmlEntitiesParser::GetEntityChar(wxString const & entity)  (http://docs.wxwidgets.org/stable/wx_wxhtmlentitiesparser.html#getentitychar)")
    ADD_CLASS_METHOD(GetCharForCode,"wxChar wxHtmlEntitiesParser::GetCharForCode(unsigned int code)  (http://docs.wxwidgets.org/stable/wx_wxhtmlentitiesparser.html#getcharforcode)")





    void AddMethods(WrapClass<wxHtmlEntitiesParser>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxHtmlEntitiesParser_h
