/**
 * C++ Interface: wrap_wxAcceleratorEntry
 *
 * Description: wrapping wxAcceleratorEntry
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAcceleratorEntry_h_
#define _wrap_wxAcceleratorEntry_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxAcceleratorEntry_declared
  #define wxAcceleratorEntry_declared
  AMI_DECLARE_TYPE(wxAcceleratorEntry);
#endif

// TODO: check for inheritence ...
class WrapClass_wxAcceleratorEntry : public WrapClass<wxAcceleratorEntry>
    
{
  DEFINE_CLASS(WrapClass_wxAcceleratorEntry);

  protected:
    typedef WrapClass<wxAcceleratorEntry>::ptr _parentclass_ptr;
    typedef wxAcceleratorEntry ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAcceleratorEntry>& GetObj() const { return WrapClass<wxAcceleratorEntry>::GetObj(); }

    /// Constructor
    WrapClass_wxAcceleratorEntry(boost::shared_ptr<wxAcceleratorEntry > si): 
    WrapClass<wxAcceleratorEntry>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAcceleratorEntry()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAcceleratorEntry_1,"Constructor wxAcceleratorEntry::wxAcceleratorEntry(int flags = 0, int keyCode = 0, int cmd = 0, wxMenuItem * item = 0l) (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#wxacceleratorentry).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAcceleratorEntry,"Constructor wxAcceleratorEntry::wxAcceleratorEntry() (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#wxacceleratorentry).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAcceleratorEntry_2,"Constructor wxAcceleratorEntry::wxAcceleratorEntry(wxAcceleratorEntry const & entry) (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#wxacceleratorentry).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAcceleratorEntry*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(Create,"wxAcceleratorEntry * wxAcceleratorEntry::Create(wxString const & str) (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#create).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Set,"void wxAcceleratorEntry::Set(int flags, int keyCode, int cmd, wxMenuItem * item = 0l)  (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#set)")
    ADD_CLASS_METHOD(SetMenuItem,"void wxAcceleratorEntry::SetMenuItem(wxMenuItem * item)  (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#setmenuitem)")
    ADD_CLASS_METHOD(GetFlags,"int wxAcceleratorEntry::GetFlags()  (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#getflags)")
    ADD_CLASS_METHOD(GetKeyCode,"int wxAcceleratorEntry::GetKeyCode()  (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#getkeycode)")
    ADD_CLASS_METHOD(GetCommand,"int wxAcceleratorEntry::GetCommand()  (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#getcommand)")
    ADD_CLASS_METHOD(GetMenuItem,"wxMenuItem * wxAcceleratorEntry::GetMenuItem()  (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#getmenuitem)")
    ADD_CLASS_METHOD(IsOk,"bool wxAcceleratorEntry::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#isok)")
    ADD_CLASS_METHOD(ToString,"wxString wxAcceleratorEntry::ToString()  (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#tostring)")
    ADD_CLASS_METHOD(FromString,"bool wxAcceleratorEntry::FromString(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#fromstring)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxAcceleratorEntry & wxAcceleratorEntry::operator =(wxAcceleratorEntry const & entry) (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxAcceleratorEntry::operator ==(wxAcceleratorEntry const & entry) (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxAcceleratorEntry::operator !=(wxAcceleratorEntry const & entry) (http://docs.wxwidgets.org/stable/wx_wxacceleratorentry.html#__not_equal__)")




    void AddMethods(WrapClass<wxAcceleratorEntry>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAcceleratorEntry_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxAcceleratorEntry_h
