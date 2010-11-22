/**
 * C++ Interface: wrap_wxEventTable
 *
 * Description: wrapping wxEventTable
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxEventTable_h_
#define _wrap_wxEventTable_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxEventTable);

// TODO: check for inheritence ...
class WrapClass_wxEventTable : public WrapClass<wxEventTable>
    
{
  DEFINE_CLASS(WrapClass_wxEventTable);

  protected:
    typedef WrapClass<wxEventTable>::ptr _parentclass_ptr;
    typedef wxEventTable ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxEventTable>& GetObj() const { return WrapClass<wxEventTable>::GetObj(); }

    /// Constructor
    WrapClass_wxEventTable(boost::shared_ptr<wxEventTable > si): 
    WrapClass<wxEventTable>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxEventTable()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxEventTable_1,"Constructor wxEventTable::wxEventTable(wxEventTable const & param0) (http://docs.wxwidgets.org/stable/wx_wxeventtable.html#wxeventtable).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxEventTable,"Constructor wxEventTable::wxEventTable() (http://docs.wxwidgets.org/stable/wx_wxeventtable.html#wxeventtable).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxEventTable_2,"Constructor wxEventTable::wxEventTable() (http://docs.wxwidgets.org/stable/wx_wxeventtable.html#wxeventtable).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxEventTable*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxEventTable & wxEventTable::operator =(wxEventTable const & param0) (http://docs.wxwidgets.org/stable/wx_wxeventtable.html#__assign__)")




    void AddMethods(WrapClass<wxEventTable>::ptr this_ptr );

};


#endif // _wrap_wxEventTable_h
