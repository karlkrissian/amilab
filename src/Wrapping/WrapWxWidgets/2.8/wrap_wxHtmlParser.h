/**
 * C++ Interface: wrap_wxHtmlParser
 *
 * Description: wrapping wxHtmlParser
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlParser_h_
#define _wrap_wxHtmlParser_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


#ifndef wxHtmlParser_declared
  #define wxHtmlParser_declared
  AMI_DECLARE_TYPE(wxHtmlParser);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlParser : public WrapClass<wxHtmlParser>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxHtmlParser);

  protected:
    typedef WrapClass<wxHtmlParser>::ptr _parentclass_ptr;
    typedef wxHtmlParser ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlParser>& GetObj() const { return WrapClass<wxHtmlParser>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlParser(boost::shared_ptr<wxHtmlParser > si): 
    WrapClass<wxHtmlParser>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlParser()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlParser*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(ExtractCharsetInformation,"wxString wxHtmlParser::ExtractCharsetInformation(wxString const & markup) (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#extractcharsetinformation).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlParser::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#getclassinfo)")
    ADD_CLASS_METHOD(SetFS,"void wxHtmlParser::SetFS(wxFileSystem * fs)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#setfs)")
    ADD_CLASS_METHOD(GetFS,"wxFileSystem * wxHtmlParser::GetFS()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#getfs)")
    ADD_CLASS_METHOD(OpenURL,"wxFSFile * wxHtmlParser::OpenURL(wxHtmlURLType type, wxString const & url)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#openurl)")
    ADD_CLASS_METHOD(Parse,"wxObject * wxHtmlParser::Parse(wxString const & source)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#parse)")
    ADD_CLASS_METHOD(InitParser,"void wxHtmlParser::InitParser(wxString const & source)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#initparser)")
    ADD_CLASS_METHOD(DoneParser,"void wxHtmlParser::DoneParser()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#doneparser)")
    ADD_CLASS_METHOD(StopParsing,"void wxHtmlParser::StopParsing()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#stopparsing)")
    ADD_CLASS_METHOD(DoParsing_1,"void wxHtmlParser::DoParsing(int begin_pos, int end_pos)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#doparsing)")
    ADD_CLASS_METHOD(DoParsing,"wxHtmlParser::DoParsing()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#doparsing)")
    ADD_CLASS_METHOD(DoParsing_2,"void wxHtmlParser::DoParsing()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#doparsing)")
    ADD_CLASS_METHOD(GetCurrentTag,"wxHtmlTag * wxHtmlParser::GetCurrentTag()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#getcurrenttag)")
    ADD_CLASS_METHOD(AddTagHandler,"void wxHtmlParser::AddTagHandler(wxHtmlTagHandler * handler)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#addtaghandler)")
    ADD_CLASS_METHOD(PushTagHandler,"void wxHtmlParser::PushTagHandler(wxHtmlTagHandler * handler, wxString const & tags)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#pushtaghandler)")
    ADD_CLASS_METHOD(PopTagHandler,"void wxHtmlParser::PopTagHandler()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#poptaghandler)")
    ADD_CLASS_METHOD(GetSource,"wxString * wxHtmlParser::GetSource()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#getsource)")
    ADD_CLASS_METHOD(SetSource,"void wxHtmlParser::SetSource(wxString const & src)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#setsource)")
    ADD_CLASS_METHOD(SetSourceAndSaveState,"void wxHtmlParser::SetSourceAndSaveState(wxString const & src)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#setsourceandsavestate)")
    ADD_CLASS_METHOD(RestoreState,"bool wxHtmlParser::RestoreState()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#restorestate)")
    ADD_CLASS_METHOD(GetInnerSource,"wxString wxHtmlParser::GetInnerSource(wxHtmlTag const & tag)  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#getinnersource)")
    ADD_CLASS_METHOD(GetEntitiesParser,"wxHtmlEntitiesParser * wxHtmlParser::GetEntitiesParser()  (http://docs.wxwidgets.org/stable/wx_wxhtmlparser.html#getentitiesparser)")





    void AddMethods(WrapClass<wxHtmlParser>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlParser_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlParser_h
