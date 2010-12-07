/**
 * C++ Interface: wrap_wxIconLocation
 *
 * Description: wrapping wxIconLocation
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxIconLocation_h_
#define _wrap_wxIconLocation_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxIconLocationBase.h"



AMI_DECLARE_TYPE(wxIconLocation);

// TODO: check for inheritence ...
class WrapClass_wxIconLocation : public WrapClass<wxIconLocation>
    , public   WrapClass_wxIconLocationBase
{
  DEFINE_CLASS(WrapClass_wxIconLocation);

  protected:
    typedef WrapClass<wxIconLocation>::ptr _parentclass_ptr;
    typedef wxIconLocation ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxIconLocation>& GetObj() const { return WrapClass<wxIconLocation>::GetObj(); }

    /// Constructor
    WrapClass_wxIconLocation(boost::shared_ptr<wxIconLocation > si): 
    WrapClass<wxIconLocation>(si)
    , WrapClass_wxIconLocationBase(si)
    {}

    /// Destructor
    ~WrapClass_wxIconLocation()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconLocation_1,"Constructor wxIconLocation::wxIconLocation(wxIconLocation const & param0) (http://docs.wxwidgets.org/stable/wx_wxiconlocation.html#wxiconlocation).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconLocation,"Constructor wxIconLocation::wxIconLocation() (http://docs.wxwidgets.org/stable/wx_wxiconlocation.html#wxiconlocation).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconLocation_2,"Constructor wxIconLocation::wxIconLocation(wxString const & filename = wxEmptyString) (http://docs.wxwidgets.org/stable/wx_wxiconlocation.html#wxiconlocation).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxIconLocation*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxIconLocation & wxIconLocation::operator =(wxIconLocation const & param0) (http://docs.wxwidgets.org/stable/wx_wxiconlocation.html#__assign__)")




    void AddMethods(WrapClass<wxIconLocation>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxIconLocation_h
