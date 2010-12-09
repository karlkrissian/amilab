/**
 * C++ Interface: wrap_wxHtmlWindowInterface
 *
 * Description: wrapping wxHtmlWindowInterface
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlWindowInterface_h_
#define _wrap_wxHtmlWindowInterface_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxHtmlWindowInterface);

// TODO: check for inheritence ...
class WrapClass_wxHtmlWindowInterface : public WrapClass<wxHtmlWindowInterface>
    
{
  DEFINE_CLASS(WrapClass_wxHtmlWindowInterface);

  protected:
    typedef WrapClass<wxHtmlWindowInterface>::ptr _parentclass_ptr;
    typedef wxHtmlWindowInterface ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlWindowInterface>& GetObj() const { return WrapClass<wxHtmlWindowInterface>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlWindowInterface(boost::shared_ptr<wxHtmlWindowInterface > si): 
    WrapClass<wxHtmlWindowInterface>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxHtmlWindowInterface()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlWindowInterface*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxHtmlWindowInterface & wxHtmlWindowInterface::operator =(wxHtmlWindowInterface const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmlwindowinterface.html#__assign__)")




    void AddMethods(WrapClass<wxHtmlWindowInterface>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxHtmlWindowInterface_h
