/**
 * C++ Interface: wrap_wxListBase
 *
 * Description: wrapping wxListBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxListBase_h_
#define _wrap_wxListBase_h_

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


#ifndef wxListBase_declared
  #define wxListBase_declared
  AMI_DECLARE_TYPE(wxListBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxListBase : public WrapClass<wxListBase>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxListBase);

  protected:
    typedef WrapClass<wxListBase>::ptr _parentclass_ptr;
    typedef wxListBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxListBase>& GetObj() const { return WrapClass<wxListBase>::GetObj(); }

    /// Constructor
    WrapClass_wxListBase(boost::shared_ptr<wxListBase > si): 
    WrapClass<wxListBase>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxListBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxListBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetCount,"size_t wxListBase::GetCount()  (http://docs.wxwidgets.org/stable/wx_wxlistbase.html#getcount)")
    ADD_CLASS_METHOD(IsEmpty,"bool wxListBase::IsEmpty()  (http://docs.wxwidgets.org/stable/wx_wxlistbase.html#isempty)")
    ADD_CLASS_METHOD(Clear,"void wxListBase::Clear()  (http://docs.wxwidgets.org/stable/wx_wxlistbase.html#clear)")
    ADD_CLASS_METHOD(DeleteContents,"void wxListBase::DeleteContents(bool destroy)  (http://docs.wxwidgets.org/stable/wx_wxlistbase.html#deletecontents)")
    ADD_CLASS_METHOD(GetDeleteContents,"bool wxListBase::GetDeleteContents()  (http://docs.wxwidgets.org/stable/wx_wxlistbase.html#getdeletecontents)")
    ADD_CLASS_METHOD(GetKeyType,"wxKeyType wxListBase::GetKeyType()  (http://docs.wxwidgets.org/stable/wx_wxlistbase.html#getkeytype)")
    ADD_CLASS_METHOD(SetKeyType,"void wxListBase::SetKeyType(wxKeyType keyType)  (http://docs.wxwidgets.org/stable/wx_wxlistbase.html#setkeytype)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxListBase & wxListBase::operator =(wxListBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxlistbase.html#__assign__)")




    void AddMethods(WrapClass<wxListBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxListBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxListBase_h
