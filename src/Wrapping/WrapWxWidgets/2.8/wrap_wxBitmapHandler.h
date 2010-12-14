/**
 * C++ Interface: wrap_wxBitmapHandler
 *
 * Description: wrapping wxBitmapHandler
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBitmapHandler_h_
#define _wrap_wxBitmapHandler_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxBitmapHandlerBase.h"


#ifndef wxBitmapHandler_declared
  #define wxBitmapHandler_declared
  AMI_DECLARE_TYPE(wxBitmapHandler);
#endif

// TODO: check for inheritence ...
class WrapClass_wxBitmapHandler : public WrapClass<wxBitmapHandler>
    , public   WrapClass_wxBitmapHandlerBase
{
  DEFINE_CLASS(WrapClass_wxBitmapHandler);

  protected:
    typedef WrapClass<wxBitmapHandler>::ptr _parentclass_ptr;
    typedef wxBitmapHandler ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBitmapHandler>& GetObj() const { return WrapClass<wxBitmapHandler>::GetObj(); }

    /// Constructor
    WrapClass_wxBitmapHandler(boost::shared_ptr<wxBitmapHandler > si): 
    WrapClass<wxBitmapHandler>(si)
    , WrapClass_wxBitmapHandlerBase(si)
    {}

    /// Destructor
    ~WrapClass_wxBitmapHandler()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapHandler_1,"Constructor wxBitmapHandler::wxBitmapHandler(wxBitmapHandler const & param0) (http://docs.wxwidgets.org/stable/wx_wxbitmaphandler.html#wxbitmaphandler).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapHandler,"Constructor wxBitmapHandler::wxBitmapHandler() (http://docs.wxwidgets.org/stable/wx_wxbitmaphandler.html#wxbitmaphandler).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapHandler_2,"Constructor wxBitmapHandler::wxBitmapHandler() (http://docs.wxwidgets.org/stable/wx_wxbitmaphandler.html#wxbitmaphandler).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBitmapHandler*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxBitmapHandler::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxbitmaphandler.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxBitmapHandler & wxBitmapHandler::operator =(wxBitmapHandler const & param0) (http://docs.wxwidgets.org/stable/wx_wxbitmaphandler.html#__assign__)")




    void AddMethods(WrapClass<wxBitmapHandler>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxBitmapHandler_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxBitmapHandler_h
