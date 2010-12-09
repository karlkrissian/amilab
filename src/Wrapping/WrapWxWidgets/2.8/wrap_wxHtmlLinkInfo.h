/**
 * C++ Interface: wrap_wxHtmlLinkInfo
 *
 * Description: wrapping wxHtmlLinkInfo
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlLinkInfo_h_
#define _wrap_wxHtmlLinkInfo_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxHtmlLinkInfo);

// TODO: check for inheritence ...
class WrapClass_wxHtmlLinkInfo : public WrapClass<wxHtmlLinkInfo>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxHtmlLinkInfo);

  protected:
    typedef WrapClass<wxHtmlLinkInfo>::ptr _parentclass_ptr;
    typedef wxHtmlLinkInfo ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlLinkInfo>& GetObj() const { return WrapClass<wxHtmlLinkInfo>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlLinkInfo(boost::shared_ptr<wxHtmlLinkInfo > si): 
    WrapClass<wxHtmlLinkInfo>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlLinkInfo()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlLinkInfo_1,"Constructor wxHtmlLinkInfo::wxHtmlLinkInfo() (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#wxhtmllinkinfo).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlLinkInfo,"Constructor wxHtmlLinkInfo::wxHtmlLinkInfo() (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#wxhtmllinkinfo).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlLinkInfo_2,"Constructor wxHtmlLinkInfo::wxHtmlLinkInfo(wxString const & href, wxString const & target = wxEmptyString) (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#wxhtmllinkinfo).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlLinkInfo_3,"Constructor wxHtmlLinkInfo::wxHtmlLinkInfo(wxHtmlLinkInfo const & l) (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#wxhtmllinkinfo).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlLinkInfo*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SetEvent,"void wxHtmlLinkInfo::SetEvent(wxMouseEvent const * e)  (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#setevent)")
    ADD_CLASS_METHOD(SetHtmlCell,"void wxHtmlLinkInfo::SetHtmlCell(wxHtmlCell const * e)  (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#sethtmlcell)")
    ADD_CLASS_METHOD(GetHref,"wxString wxHtmlLinkInfo::GetHref()  (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#gethref)")
    ADD_CLASS_METHOD(GetTarget,"wxString wxHtmlLinkInfo::GetTarget()  (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#gettarget)")
    ADD_CLASS_METHOD(GetEvent,"wxMouseEvent const * wxHtmlLinkInfo::GetEvent()  (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#getevent)")
    ADD_CLASS_METHOD(GetHtmlCell,"wxHtmlCell const * wxHtmlLinkInfo::GetHtmlCell()  (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#gethtmlcell)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxHtmlLinkInfo & wxHtmlLinkInfo::operator =(wxHtmlLinkInfo const & l) (http://docs.wxwidgets.org/stable/wx_wxhtmllinkinfo.html#__assign__)")




    void AddMethods(WrapClass<wxHtmlLinkInfo>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxHtmlLinkInfo_h
