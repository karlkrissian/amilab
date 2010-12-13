/**
 * C++ Interface: wrap_wxStreamBase
 *
 * Description: wrapping wxStreamBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxStreamBase_h_
#define _wrap_wxStreamBase_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxStreamBase_declared
  #define wxStreamBase_declared
  AMI_DECLARE_TYPE(wxStreamBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxStreamBase : public WrapClass<wxStreamBase>
    
{
  DEFINE_CLASS(WrapClass_wxStreamBase);

  protected:
    typedef WrapClass<wxStreamBase>::ptr _parentclass_ptr;
    typedef wxStreamBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxStreamBase>& GetObj() const { return WrapClass<wxStreamBase>::GetObj(); }

    /// Constructor
    WrapClass_wxStreamBase(boost::shared_ptr<wxStreamBase > si): 
    WrapClass<wxStreamBase>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxStreamBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStreamBase,"Constructor wxStreamBase::wxStreamBase() (http://docs.wxwidgets.org/stable/wx_wxstreambase.html#wxstreambase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStreamBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetLastError,"wxStreamError wxStreamBase::GetLastError()  (http://docs.wxwidgets.org/stable/wx_wxstreambase.html#getlasterror)")
    ADD_CLASS_METHOD(IsOk,"bool wxStreamBase::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxstreambase.html#isok)")
    ADD_CLASS_METHOD(Reset,"void wxStreamBase::Reset()  (http://docs.wxwidgets.org/stable/wx_wxstreambase.html#reset)")
    ADD_CLASS_METHOD(GetSize,"size_t wxStreamBase::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxstreambase.html#getsize)")
    ADD_CLASS_METHOD(GetLength,"wxFileOffset wxStreamBase::GetLength()  (http://docs.wxwidgets.org/stable/wx_wxstreambase.html#getlength)")
    ADD_CLASS_METHOD(IsSeekable,"bool wxStreamBase::IsSeekable()  (http://docs.wxwidgets.org/stable/wx_wxstreambase.html#isseekable)")

    // Operators:
    // ADD_CLASS_METHOD(operator not available,"bool wxStreamBase::!() (http://docs.wxwidgets.org/stable/wx_wxstreambase.html#!)")




    void AddMethods(WrapClass<wxStreamBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxStreamBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxStreamBase_h
