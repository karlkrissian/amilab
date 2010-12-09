/**
 * C++ Interface: wrap_wxHtmlRenderingInfo
 *
 * Description: wrapping wxHtmlRenderingInfo
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlRenderingInfo_h_
#define _wrap_wxHtmlRenderingInfo_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxHtmlRenderingInfo);

// TODO: check for inheritence ...
class WrapClass_wxHtmlRenderingInfo : public WrapClass<wxHtmlRenderingInfo>
    
{
  DEFINE_CLASS(WrapClass_wxHtmlRenderingInfo);

  protected:
    typedef WrapClass<wxHtmlRenderingInfo>::ptr _parentclass_ptr;
    typedef wxHtmlRenderingInfo ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlRenderingInfo>& GetObj() const { return WrapClass<wxHtmlRenderingInfo>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlRenderingInfo(boost::shared_ptr<wxHtmlRenderingInfo > si): 
    WrapClass<wxHtmlRenderingInfo>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxHtmlRenderingInfo()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlRenderingInfo_1,"Constructor wxHtmlRenderingInfo::wxHtmlRenderingInfo(wxHtmlRenderingInfo const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderinginfo.html#wxhtmlrenderinginfo).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlRenderingInfo,"Constructor wxHtmlRenderingInfo::wxHtmlRenderingInfo() (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderinginfo.html#wxhtmlrenderinginfo).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlRenderingInfo_2,"Constructor wxHtmlRenderingInfo::wxHtmlRenderingInfo() (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderinginfo.html#wxhtmlrenderinginfo).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlRenderingInfo*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SetSelection,"void wxHtmlRenderingInfo::SetSelection(wxHtmlSelection * s)  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderinginfo.html#setselection)")
    ADD_CLASS_METHOD(GetSelection,"wxHtmlSelection * wxHtmlRenderingInfo::GetSelection()  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderinginfo.html#getselection)")
    ADD_CLASS_METHOD(SetStyle,"void wxHtmlRenderingInfo::SetStyle(wxHtmlRenderingStyle * style)  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderinginfo.html#setstyle)")
    ADD_CLASS_METHOD(GetStyle,"wxHtmlRenderingStyle & wxHtmlRenderingInfo::GetStyle()  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderinginfo.html#getstyle)")
    ADD_CLASS_METHOD(GetState,"wxHtmlRenderingState & wxHtmlRenderingInfo::GetState()  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderinginfo.html#getstate)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxHtmlRenderingInfo & wxHtmlRenderingInfo::operator =(wxHtmlRenderingInfo const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderinginfo.html#__assign__)")




    void AddMethods(WrapClass<wxHtmlRenderingInfo>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxHtmlRenderingInfo_h
