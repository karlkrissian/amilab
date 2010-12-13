/**
 * C++ Interface: wrap_wxTimerBase
 *
 * Description: wrapping wxTimerBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxTimerBase_h_
#define _wrap_wxTimerBase_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvtHandler.h"


#ifndef wxTimerBase_declared
  #define wxTimerBase_declared
  AMI_DECLARE_TYPE(wxTimerBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxTimerBase : public WrapClass<wxTimerBase>
    , public   WrapClass_wxEvtHandler
{
  DEFINE_CLASS(WrapClass_wxTimerBase);

  protected:
    typedef WrapClass<wxTimerBase>::ptr _parentclass_ptr;
    typedef wxTimerBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxTimerBase>& GetObj() const { return WrapClass<wxTimerBase>::GetObj(); }

    /// Constructor
    WrapClass_wxTimerBase(boost::shared_ptr<wxTimerBase > si): 
    WrapClass<wxTimerBase>(si)
    , WrapClass_wxEvtHandler(si)
    {}

    /// Destructor
    ~WrapClass_wxTimerBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxTimerBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetOwner,"void wxTimerBase::SetOwner(wxEvtHandler * owner, int timerid = wxID_ANY)  (http://docs.wxwidgets.org/stable/wx_wxtimerbase.html#setowner)")
    ADD_CLASS_METHOD(GetOwner,"wxEvtHandler * wxTimerBase::GetOwner()  (http://docs.wxwidgets.org/stable/wx_wxtimerbase.html#getowner)")
    ADD_CLASS_METHOD(Start,"bool wxTimerBase::Start(int milliseconds = -0x00000000000000001, bool oneShot = false)  (http://docs.wxwidgets.org/stable/wx_wxtimerbase.html#start)")
    ADD_CLASS_METHOD(Notify,"void wxTimerBase::Notify()  (http://docs.wxwidgets.org/stable/wx_wxtimerbase.html#notify)")
    ADD_CLASS_METHOD(GetId,"int wxTimerBase::GetId()  (http://docs.wxwidgets.org/stable/wx_wxtimerbase.html#getid)")
    ADD_CLASS_METHOD(GetInterval,"int wxTimerBase::GetInterval()  (http://docs.wxwidgets.org/stable/wx_wxtimerbase.html#getinterval)")
    ADD_CLASS_METHOD(IsOneShot,"bool wxTimerBase::IsOneShot()  (http://docs.wxwidgets.org/stable/wx_wxtimerbase.html#isoneshot)")





    void AddMethods(WrapClass<wxTimerBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxTimerBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxTimerBase_h
