/**
 * C++ Interface: wrap_wxHtmlRenderingStyle
 *
 * Description: wrapping wxHtmlRenderingStyle
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlRenderingStyle_h_
#define _wrap_wxHtmlRenderingStyle_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxHtmlRenderingStyle);

// TODO: check for inheritence ...
class WrapClass_wxHtmlRenderingStyle : public WrapClass<wxHtmlRenderingStyle>
    
{
  DEFINE_CLASS(WrapClass_wxHtmlRenderingStyle);

  protected:
    typedef WrapClass<wxHtmlRenderingStyle>::ptr _parentclass_ptr;
    typedef wxHtmlRenderingStyle ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlRenderingStyle>& GetObj() const { return WrapClass<wxHtmlRenderingStyle>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlRenderingStyle(boost::shared_ptr<wxHtmlRenderingStyle > si): 
    WrapClass<wxHtmlRenderingStyle>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxHtmlRenderingStyle()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlRenderingStyle*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxHtmlRenderingStyle & wxHtmlRenderingStyle::operator =(wxHtmlRenderingStyle const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstyle.html#__assign__)")




    void AddMethods(WrapClass<wxHtmlRenderingStyle>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxHtmlRenderingStyle_h
