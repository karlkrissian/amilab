/**
 * C++ Interface: wrap_wxHtmlTag
 *
 * Description: wrapping wxHtmlTag
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlTag_h_
#define _wrap_wxHtmlTag_h_

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


#ifndef wxHtmlTag_declared
  #define wxHtmlTag_declared
  AMI_DECLARE_TYPE(wxHtmlTag);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlTag : public WrapClass<wxHtmlTag>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxHtmlTag);

  protected:
    typedef WrapClass<wxHtmlTag>::ptr _parentclass_ptr;
    typedef wxHtmlTag ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlTag>& GetObj() const { return WrapClass<wxHtmlTag>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlTag(boost::shared_ptr<wxHtmlTag > si): 
    WrapClass<wxHtmlTag>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlTag()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlTag*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlTag::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getclassinfo)")
    ADD_CLASS_METHOD(GetParent,"wxHtmlTag * wxHtmlTag::GetParent()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getparent)")
    ADD_CLASS_METHOD(GetFirstSibling,"wxHtmlTag * wxHtmlTag::GetFirstSibling()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getfirstsibling)")
    ADD_CLASS_METHOD(GetLastSibling,"wxHtmlTag * wxHtmlTag::GetLastSibling()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getlastsibling)")
    ADD_CLASS_METHOD(GetChildren,"wxHtmlTag * wxHtmlTag::GetChildren()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getchildren)")
    ADD_CLASS_METHOD(GetPreviousSibling,"wxHtmlTag * wxHtmlTag::GetPreviousSibling()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getprevioussibling)")
    ADD_CLASS_METHOD(GetNextSibling,"wxHtmlTag * wxHtmlTag::GetNextSibling()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getnextsibling)")
    ADD_CLASS_METHOD(GetNextTag,"wxHtmlTag * wxHtmlTag::GetNextTag()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getnexttag)")
    ADD_CLASS_METHOD(GetName,"wxString wxHtmlTag::GetName()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getname)")
    ADD_CLASS_METHOD(HasParam,"bool wxHtmlTag::HasParam(wxString const & par)  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#hasparam)")
    ADD_CLASS_METHOD(GetParam,"wxString wxHtmlTag::GetParam(wxString const & par, bool with_commas = false)  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getparam)")
    ADD_CLASS_METHOD(GetParamAsColour,"bool wxHtmlTag::GetParamAsColour(wxString const & par, wxColour * clr)  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getparamascolour)")
    ADD_CLASS_METHOD(GetParamAsInt,"bool wxHtmlTag::GetParamAsInt(wxString const & par, int * clr)  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getparamasint)")
/* The following types are missing: void
    ADD_CLASS_METHOD(ScanParam,"int wxHtmlTag::ScanParam(wxString const & par, wxChar const * format, void * param)  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#scanparam)")
*/
    ADD_CLASS_METHOD(GetAllParams,"wxString wxHtmlTag::GetAllParams()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getallparams)")
    ADD_CLASS_METHOD(HasEnding,"bool wxHtmlTag::HasEnding()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#hasending)")
    ADD_CLASS_METHOD(GetBeginPos,"int wxHtmlTag::GetBeginPos()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getbeginpos)")
    ADD_CLASS_METHOD(GetEndPos1,"int wxHtmlTag::GetEndPos1()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getendpos1)")
    ADD_CLASS_METHOD(GetEndPos2,"int wxHtmlTag::GetEndPos2()  (http://docs.wxwidgets.org/stable/wx_wxhtmltag.html#getendpos2)")





    void AddMethods(WrapClass<wxHtmlTag>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlTag_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlTag_h
