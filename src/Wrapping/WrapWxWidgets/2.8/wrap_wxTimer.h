/**
 * C++ Interface: wrap_wxTimer
 *
 * Description: wrapping wxTimer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxTimer_h_
#define _wrap_wxTimer_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxTimerBase.h"


#ifndef wxTimer_declared
  #define wxTimer_declared
  AMI_DECLARE_TYPE(wxTimer);
#endif

// TODO: check for inheritence ...
class WrapClass_wxTimer : public WrapClass<wxTimer>
    , public   WrapClass_wxTimerBase
{
  DEFINE_CLASS(WrapClass_wxTimer);

  protected:
    typedef WrapClass<wxTimer>::ptr _parentclass_ptr;
    typedef wxTimer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxTimer>& GetObj() const { return WrapClass<wxTimer>::GetObj(); }

    /// Constructor
    WrapClass_wxTimer(boost::shared_ptr<wxTimer > si): 
    WrapClass<wxTimer>(si)
    , WrapClass_wxTimerBase(si)
    {}

    /// Destructor
    ~WrapClass_wxTimer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTimer_1,"Constructor wxTimer::wxTimer() (http://docs.wxwidgets.org/stable/wx_wxtimer.html#wxtimer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTimer,"Constructor wxTimer::wxTimer() (http://docs.wxwidgets.org/stable/wx_wxtimer.html#wxtimer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTimer_2,"Constructor wxTimer::wxTimer(wxEvtHandler * owner, int id = -0x00000000000000001) (http://docs.wxwidgets.org/stable/wx_wxtimer.html#wxtimer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxTimer*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Start,"bool wxTimer::Start(int millisecs = -0x00000000000000001, bool oneShot = 0)  (http://docs.wxwidgets.org/stable/wx_wxtimer.html#start)")
    ADD_CLASS_METHOD(Stop,"void wxTimer::Stop()  (http://docs.wxwidgets.org/stable/wx_wxtimer.html#stop)")
    ADD_CLASS_METHOD(IsRunning,"bool wxTimer::IsRunning()  (http://docs.wxwidgets.org/stable/wx_wxtimer.html#isrunning)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxTimer::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxtimer.html#getclassinfo)")





    void AddMethods(WrapClass<wxTimer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxTimer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxTimer_h
