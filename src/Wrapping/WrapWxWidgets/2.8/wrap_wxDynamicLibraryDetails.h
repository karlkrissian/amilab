/**
 * C++ Interface: wrap_wxDynamicLibraryDetails
 *
 * Description: wrapping wxDynamicLibraryDetails
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDynamicLibraryDetails_h_
#define _wrap_wxDynamicLibraryDetails_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxDynamicLibraryDetails_declared
  #define wxDynamicLibraryDetails_declared
  AMI_DECLARE_TYPE(wxDynamicLibraryDetails);
#endif

// TODO: check for inheritence ...
class WrapClass_wxDynamicLibraryDetails : public WrapClass<wxDynamicLibraryDetails>
    
{
  DEFINE_CLASS(WrapClass_wxDynamicLibraryDetails);

  protected:
    typedef WrapClass<wxDynamicLibraryDetails>::ptr _parentclass_ptr;
    typedef wxDynamicLibraryDetails ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDynamicLibraryDetails>& GetObj() const { return WrapClass<wxDynamicLibraryDetails>::GetObj(); }

    /// Constructor
    WrapClass_wxDynamicLibraryDetails(boost::shared_ptr<wxDynamicLibraryDetails > si): 
    WrapClass<wxDynamicLibraryDetails>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxDynamicLibraryDetails()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDynamicLibraryDetails_1,"Constructor wxDynamicLibraryDetails::wxDynamicLibraryDetails(wxDynamicLibraryDetails const & param0) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetails.html#wxdynamiclibrarydetails).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDynamicLibraryDetails,"Constructor wxDynamicLibraryDetails::wxDynamicLibraryDetails() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetails.html#wxdynamiclibrarydetails).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDynamicLibraryDetails_2,"Constructor wxDynamicLibraryDetails::wxDynamicLibraryDetails() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetails.html#wxdynamiclibrarydetails).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDynamicLibraryDetails*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetName,"wxString wxDynamicLibraryDetails::GetName()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetails.html#getname)")
    ADD_CLASS_METHOD(GetPath,"wxString wxDynamicLibraryDetails::GetPath()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetails.html#getpath)")
/* The following types are missing: void
    ADD_CLASS_METHOD(GetAddress,"bool wxDynamicLibraryDetails::GetAddress(void * * addr, size_t * len)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetails.html#getaddress)")
*/
    ADD_CLASS_METHOD(GetVersion,"wxString wxDynamicLibraryDetails::GetVersion()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetails.html#getversion)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxDynamicLibraryDetails & wxDynamicLibraryDetails::operator =(wxDynamicLibraryDetails const & param0) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrarydetails.html#__assign__)")




    void AddMethods(WrapClass<wxDynamicLibraryDetails>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDynamicLibraryDetails_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxDynamicLibraryDetails_h
