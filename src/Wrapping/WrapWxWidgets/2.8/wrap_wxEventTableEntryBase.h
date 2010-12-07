/**
 * C++ Interface: wrap_wxEventTableEntryBase
 *
 * Description: wrapping wxEventTableEntryBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxEventTableEntryBase_h_
#define _wrap_wxEventTableEntryBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxEventTableEntryBase);

// TODO: check for inheritence ...
class WrapClass_wxEventTableEntryBase : public WrapClass<wxEventTableEntryBase>
    
{
  DEFINE_CLASS(WrapClass_wxEventTableEntryBase);

  protected:
    typedef WrapClass<wxEventTableEntryBase>::ptr _parentclass_ptr;
    typedef wxEventTableEntryBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxEventTableEntryBase>& GetObj() const { return WrapClass<wxEventTableEntryBase>::GetObj(); }

    /// Constructor
    WrapClass_wxEventTableEntryBase(boost::shared_ptr<wxEventTableEntryBase > si): 
    WrapClass<wxEventTableEntryBase>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxEventTableEntryBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxEventTableEntryBase_1,"Constructor wxEventTableEntryBase::wxEventTableEntryBase(int winid, int idLast, wxObjectEventFunction fn, wxObject * data) (http://docs.wxwidgets.org/stable/wx_wxeventtableentrybase.html#wxeventtableentrybase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxEventTableEntryBase,"Constructor wxEventTableEntryBase::wxEventTableEntryBase() (http://docs.wxwidgets.org/stable/wx_wxeventtableentrybase.html#wxeventtableentrybase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxEventTableEntryBase_2,"Constructor wxEventTableEntryBase::wxEventTableEntryBase(wxEventTableEntryBase const & event) (http://docs.wxwidgets.org/stable/wx_wxeventtableentrybase.html#wxeventtableentrybase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxEventTableEntryBase*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods





    void AddMethods(WrapClass<wxEventTableEntryBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxEventTableEntryBase_h
