/**
 * C++ Interface: wrap_wxAcceleratorTable
 *
 * Description: wrapping wxAcceleratorTable
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAcceleratorTable_h_
#define _wrap_wxAcceleratorTable_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


#ifndef wxAcceleratorTable_declared
  #define wxAcceleratorTable_declared
  AMI_DECLARE_TYPE(wxAcceleratorTable);
#endif

// TODO: check for inheritence ...
class WrapClass_wxAcceleratorTable : public WrapClass<wxAcceleratorTable>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxAcceleratorTable);

  protected:
    typedef WrapClass<wxAcceleratorTable>::ptr _parentclass_ptr;
    typedef wxAcceleratorTable ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAcceleratorTable>& GetObj() const { return WrapClass<wxAcceleratorTable>::GetObj(); }

    /// Constructor
    WrapClass_wxAcceleratorTable(boost::shared_ptr<wxAcceleratorTable > si): 
    WrapClass<wxAcceleratorTable>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxAcceleratorTable()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAcceleratorTable_1,"Constructor wxAcceleratorTable::wxAcceleratorTable(wxAcceleratorTable const & param0) (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#wxacceleratortable).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAcceleratorTable,"Constructor wxAcceleratorTable::wxAcceleratorTable() (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#wxacceleratortable).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAcceleratorTable_2,"Constructor wxAcceleratorTable::wxAcceleratorTable() (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#wxacceleratortable).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAcceleratorTable_3,"Constructor wxAcceleratorTable::wxAcceleratorTable(int n, wxAcceleratorEntry const * entries) (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#wxacceleratortable).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAcceleratorTable*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxAcceleratorTable::Ok()  (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxAcceleratorTable::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#isok)")
    ADD_CLASS_METHOD(Add,"void wxAcceleratorTable::Add(wxAcceleratorEntry const & entry)  (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#add)")
    ADD_CLASS_METHOD(Remove,"void wxAcceleratorTable::Remove(wxAcceleratorEntry const & entry)  (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#remove)")
    ADD_CLASS_METHOD(GetMenuItem,"wxMenuItem * wxAcceleratorTable::GetMenuItem(wxKeyEvent const & event)  (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#getmenuitem)")
    ADD_CLASS_METHOD(GetCommand,"int wxAcceleratorTable::GetCommand(wxKeyEvent const & event)  (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#getcommand)")
    ADD_CLASS_METHOD(GetEntry,"wxAcceleratorEntry const * wxAcceleratorTable::GetEntry(wxKeyEvent const & event)  (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#getentry)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxAcceleratorTable::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxAcceleratorTable & wxAcceleratorTable::operator =(wxAcceleratorTable const & param0) (http://docs.wxwidgets.org/stable/wx_wxacceleratortable.html#__assign__)")




    void AddMethods(WrapClass<wxAcceleratorTable>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAcceleratorTable_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxAcceleratorTable_h
