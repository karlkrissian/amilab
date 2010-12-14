/**
 * C++ Interface: wrap_wxHtmlFilter
 *
 * Description: wrapping wxHtmlFilter
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlFilter_h_
#define _wrap_wxHtmlFilter_h_

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


#ifndef wxHtmlFilter_declared
  #define wxHtmlFilter_declared
  AMI_DECLARE_TYPE(wxHtmlFilter);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlFilter : public WrapClass<wxHtmlFilter>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxHtmlFilter);

  protected:
    typedef WrapClass<wxHtmlFilter>::ptr _parentclass_ptr;
    typedef wxHtmlFilter ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlFilter>& GetObj() const { return WrapClass<wxHtmlFilter>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlFilter(boost::shared_ptr<wxHtmlFilter > si): 
    WrapClass<wxHtmlFilter>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlFilter()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlFilter*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlFilter::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmlfilter.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxHtmlFilter & wxHtmlFilter::operator =(wxHtmlFilter const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmlfilter.html#__assign__)")




    void AddMethods(WrapClass<wxHtmlFilter>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlFilter_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlFilter_h
