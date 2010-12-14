/**
 * C++ Interface: wrap_wxNodeBase
 *
 * Description: wrapping wxNodeBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxNodeBase_h_
#define _wrap_wxNodeBase_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxNodeBase_declared
  #define wxNodeBase_declared
  AMI_DECLARE_TYPE(wxNodeBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxNodeBase : public WrapClass<wxNodeBase>
    
{
  DEFINE_CLASS(WrapClass_wxNodeBase);

  protected:
    typedef WrapClass<wxNodeBase>::ptr _parentclass_ptr;
    typedef wxNodeBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxNodeBase>& GetObj() const { return WrapClass<wxNodeBase>::GetObj(); }

    /// Constructor
    WrapClass_wxNodeBase(boost::shared_ptr<wxNodeBase > si): 
    WrapClass<wxNodeBase>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxNodeBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /* The following types are missing: void
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxNodeBase,"Constructor wxNodeBase::wxNodeBase(wxListBase * list = 0u, wxNodeBase * previous = 0u, wxNodeBase * next = 0u, void * data = 0l, wxListKey const & key = wxDefaultListKey) (http://docs.wxwidgets.org/stable/wx_wxnodebase.html#wxnodebase).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxNodeBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetKeyString,"wxChar const * wxNodeBase::GetKeyString()  (http://docs.wxwidgets.org/stable/wx_wxnodebase.html#getkeystring)")
    ADD_CLASS_METHOD(GetKeyInteger,"long int wxNodeBase::GetKeyInteger()  (http://docs.wxwidgets.org/stable/wx_wxnodebase.html#getkeyinteger)")
    ADD_CLASS_METHOD(SetKeyString,"void wxNodeBase::SetKeyString(wxChar * s)  (http://docs.wxwidgets.org/stable/wx_wxnodebase.html#setkeystring)")
    ADD_CLASS_METHOD(SetKeyInteger,"void wxNodeBase::SetKeyInteger(long int i)  (http://docs.wxwidgets.org/stable/wx_wxnodebase.html#setkeyinteger)")
    ADD_CLASS_METHOD(GetDataPtr,"void * * wxNodeBase::GetDataPtr()  (http://docs.wxwidgets.org/stable/wx_wxnodebase.html#getdataptr)")





    void AddMethods(WrapClass<wxNodeBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxNodeBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxNodeBase_h
