/**
 * C++ Interface: wrap_wxColourBase
 *
 * Description: wrapping wxColourBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxColourBase_h_
#define _wrap_wxColourBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxGDIObject.h"



AMI_DECLARE_TYPE(wxColourBase);

// TODO: check for inheritence ...
class WrapClass_wxColourBase : public WrapClass<wxColourBase>
    , public   WrapClass_wxGDIObject
{
  DEFINE_CLASS(WrapClass_wxColourBase);

  protected:
    typedef WrapClass<wxColourBase>::ptr _parentclass_ptr;
    typedef wxColourBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxColourBase>& GetObj() const { return WrapClass<wxColourBase>::GetObj(); }

    /// Constructor
    WrapClass_wxColourBase(boost::shared_ptr<wxColourBase > si): 
    WrapClass<wxColourBase>(si)
    , WrapClass_wxGDIObject(si)
    {}

    /// Destructor
    ~WrapClass_wxColourBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxColourBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Set_1,"void wxColourBase::Set(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = wxALPHA_OPAQUE)  (http://docs.wxwidgets.org/stable/wx_wxcolourbase.html#set)")
    ADD_CLASS_METHOD(Set,"wxColourBase::Set()  (http://docs.wxwidgets.org/stable/wx_wxcolourbase.html#set)")
    ADD_CLASS_METHOD(Set_2,"bool wxColourBase::Set(wxChar const * str)  (http://docs.wxwidgets.org/stable/wx_wxcolourbase.html#set)")
    ADD_CLASS_METHOD(Set_3,"bool wxColourBase::Set(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxcolourbase.html#set)")
    ADD_CLASS_METHOD(Set_4,"void wxColourBase::Set(long unsigned int colRGB)  (http://docs.wxwidgets.org/stable/wx_wxcolourbase.html#set)")
    ADD_CLASS_METHOD(Ok,"bool wxColourBase::Ok()  (http://docs.wxwidgets.org/stable/wx_wxcolourbase.html#ok)")
    ADD_CLASS_METHOD(Alpha,"unsigned char wxColourBase::Alpha()  (http://docs.wxwidgets.org/stable/wx_wxcolourbase.html#alpha)")
    ADD_CLASS_METHOD(GetAsString,"wxString wxColourBase::GetAsString(long int flags = 3)  (http://docs.wxwidgets.org/stable/wx_wxcolourbase.html#getasstring)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxColourBase & wxColourBase::operator =(wxColourBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxcolourbase.html#__assign__)")




    void AddMethods(WrapClass<wxColourBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxColourBase_h
