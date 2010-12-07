/**
 * C++ Interface: wrap_wxListKey
 *
 * Description: wrapping wxListKey
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxListKey_h_
#define _wrap_wxListKey_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxListKey);

// TODO: check for inheritence ...
class WrapClass_wxListKey : public WrapClass<wxListKey>
    
{
  DEFINE_CLASS(WrapClass_wxListKey);

  protected:
    typedef WrapClass<wxListKey>::ptr _parentclass_ptr;
    typedef wxListKey ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxListKey>& GetObj() const { return WrapClass<wxListKey>::GetObj(); }

    /// Constructor
    WrapClass_wxListKey(boost::shared_ptr<wxListKey > si): 
    WrapClass<wxListKey>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxListKey()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxListKey_1,"Constructor wxListKey::wxListKey(wxListKey const & param0) (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#wxlistkey).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxListKey,"Constructor wxListKey::wxListKey() (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#wxlistkey).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxListKey_2,"Constructor wxListKey::wxListKey() (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#wxlistkey).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxListKey_3,"Constructor wxListKey::wxListKey(long int i) (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#wxlistkey).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxListKey_4,"Constructor wxListKey::wxListKey(wxChar const * s) (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#wxlistkey).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxListKey_5,"Constructor wxListKey::wxListKey(wxString const & s) (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#wxlistkey).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxListKey*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetKeyType,"wxKeyType wxListKey::GetKeyType()  (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#getkeytype)")
    ADD_CLASS_METHOD(GetString,"wxChar const * wxListKey::GetString()  (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#getstring)")
    ADD_CLASS_METHOD(GetNumber,"long int wxListKey::GetNumber()  (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#getnumber)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxListKey & wxListKey::operator =(wxListKey const & param0) (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#__assign__)")
/* The following types are missing: wxListKeyValue
    ADD_CLASS_METHOD(__equal__,            "bool wxListKey::operator ==(wxListKeyValue value) (http://docs.wxwidgets.org/stable/wx_wxlistkey.html#__equal__)")
*/




    void AddMethods(WrapClass<wxListKey>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxListKey_h
