/**
 * C++ Interface: wrap_wxFileSystemHandler
 *
 * Description: wrapping wxFileSystemHandler
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFileSystemHandler_h_
#define _wrap_wxFileSystemHandler_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"



AMI_DECLARE_TYPE(wxFileSystemHandler);

// TODO: check for inheritence ...
class WrapClass_wxFileSystemHandler : public WrapClass<wxFileSystemHandler>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxFileSystemHandler);

  protected:
    typedef WrapClass<wxFileSystemHandler>::ptr _parentclass_ptr;
    typedef wxFileSystemHandler ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFileSystemHandler>& GetObj() const { return WrapClass<wxFileSystemHandler>::GetObj(); }

    /// Constructor
    WrapClass_wxFileSystemHandler(boost::shared_ptr<wxFileSystemHandler > si): 
    WrapClass<wxFileSystemHandler>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxFileSystemHandler()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFileSystemHandler*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(FindFirst,"wxString wxFileSystemHandler::FindFirst(wxString const & spec, int flags = 0)  (http://docs.wxwidgets.org/stable/wx_wxfilesystemhandler.html#findfirst)")
    ADD_CLASS_METHOD(FindNext,"wxString wxFileSystemHandler::FindNext()  (http://docs.wxwidgets.org/stable/wx_wxfilesystemhandler.html#findnext)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxFileSystemHandler::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxfilesystemhandler.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxFileSystemHandler & wxFileSystemHandler::operator =(wxFileSystemHandler const & param0) (http://docs.wxwidgets.org/stable/wx_wxfilesystemhandler.html#__assign__)")




    void AddMethods(WrapClass<wxFileSystemHandler>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxFileSystemHandler_h
