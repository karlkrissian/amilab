/**
 * C++ Interface: wrap_wxMessageDialogBase
 *
 * Description: wrapping wxMessageDialogBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMessageDialogBase_h_
#define _wrap_wxMessageDialogBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxMessageDialogBase);

// TODO: check for inheritence ...
class WrapClass_wxMessageDialogBase : public WrapClass<wxMessageDialogBase>
    
{
  DEFINE_CLASS(WrapClass_wxMessageDialogBase);

  protected:
    typedef WrapClass<wxMessageDialogBase>::ptr _parentclass_ptr;
    typedef wxMessageDialogBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMessageDialogBase>& GetObj() const { return WrapClass<wxMessageDialogBase>::GetObj(); }

    /// Constructor
    WrapClass_wxMessageDialogBase(boost::shared_ptr<wxMessageDialogBase > si): 
    WrapClass<wxMessageDialogBase>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxMessageDialogBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMessageDialogBase_1,"Constructor wxMessageDialogBase::wxMessageDialogBase(wxMessageDialogBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxmessagedialogbase.html#wxmessagedialogbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMessageDialogBase,"Constructor wxMessageDialogBase::wxMessageDialogBase() (http://docs.wxwidgets.org/stable/wx_wxmessagedialogbase.html#wxmessagedialogbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMessageDialogBase_2,"Constructor wxMessageDialogBase::wxMessageDialogBase() (http://docs.wxwidgets.org/stable/wx_wxmessagedialogbase.html#wxmessagedialogbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMessageDialogBase*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxMessageDialogBase & wxMessageDialogBase::operator =(wxMessageDialogBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxmessagedialogbase.html#__assign__)")




    void AddMethods(WrapClass<wxMessageDialogBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxMessageDialogBase_h
