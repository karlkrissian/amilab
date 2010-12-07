/**
 * C++ Interface: wrap_wxThread
 *
 * Description: wrapping wxThread
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxThread_h_
#define _wrap_wxThread_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxThread);

// TODO: check for inheritence ...
class WrapClass_wxThread : public WrapClass<wxThread>
    
{
  DEFINE_CLASS(WrapClass_wxThread);

  protected:
    typedef WrapClass<wxThread>::ptr _parentclass_ptr;
    typedef wxThread ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxThread>& GetObj() const { return WrapClass<wxThread>::GetObj(); }

    /// Constructor
    WrapClass_wxThread(boost::shared_ptr<wxThread > si): 
    WrapClass<wxThread>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxThread()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxThread*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(This,"wxThread * wxThread::This() (http://docs.wxwidgets.org/stable/wx_wxthread.html#this).");
    ADD_CLASS_STATICMETHOD(IsMain,"bool wxThread::IsMain() (http://docs.wxwidgets.org/stable/wx_wxthread.html#ismain).");
    ADD_CLASS_STATICMETHOD(Yield,"void wxThread::Yield() (http://docs.wxwidgets.org/stable/wx_wxthread.html#yield).");
    ADD_CLASS_STATICMETHOD(Sleep,"void wxThread::Sleep(long unsigned int milliseconds) (http://docs.wxwidgets.org/stable/wx_wxthread.html#sleep).");
    ADD_CLASS_STATICMETHOD(GetCPUCount,"int wxThread::GetCPUCount() (http://docs.wxwidgets.org/stable/wx_wxthread.html#getcpucount).");
    ADD_CLASS_STATICMETHOD(GetCurrentId,"wxThreadIdType wxThread::GetCurrentId() (http://docs.wxwidgets.org/stable/wx_wxthread.html#getcurrentid).");
    ADD_CLASS_STATICMETHOD(SetConcurrency,"bool wxThread::SetConcurrency(size_t level) (http://docs.wxwidgets.org/stable/wx_wxthread.html#setconcurrency).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"wxThreadError wxThread::Create(unsigned int stackSize = 0)  (http://docs.wxwidgets.org/stable/wx_wxthread.html#create)")
    ADD_CLASS_METHOD(Run,"wxThreadError wxThread::Run()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#run)")
/* The following types are missing: void * *
    ADD_CLASS_METHOD(Delete,"wxThreadError wxThread::Delete(void * * rc = 0u)  (http://docs.wxwidgets.org/stable/wx_wxthread.html#delete)")
*/
    ADD_CLASS_METHOD(Wait,"void * wxThread::Wait()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#wait)")
    ADD_CLASS_METHOD(Kill,"wxThreadError wxThread::Kill()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#kill)")
    ADD_CLASS_METHOD(Pause,"wxThreadError wxThread::Pause()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#pause)")
    ADD_CLASS_METHOD(Resume,"wxThreadError wxThread::Resume()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#resume)")
    ADD_CLASS_METHOD(SetPriority,"void wxThread::SetPriority(unsigned int prio)  (http://docs.wxwidgets.org/stable/wx_wxthread.html#setpriority)")
    ADD_CLASS_METHOD(GetPriority,"unsigned int wxThread::GetPriority()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#getpriority)")
    ADD_CLASS_METHOD(IsAlive,"bool wxThread::IsAlive()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#isalive)")
    ADD_CLASS_METHOD(IsRunning,"bool wxThread::IsRunning()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#isrunning)")
    ADD_CLASS_METHOD(IsPaused,"bool wxThread::IsPaused()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#ispaused)")
    ADD_CLASS_METHOD(IsDetached,"bool wxThread::IsDetached()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#isdetached)")
    ADD_CLASS_METHOD(GetId,"wxThreadIdType wxThread::GetId()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#getid)")
    ADD_CLASS_METHOD(OnExit,"void wxThread::OnExit()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#onexit)")
    ADD_CLASS_METHOD(TestDestroy,"bool wxThread::TestDestroy()  (http://docs.wxwidgets.org/stable/wx_wxthread.html#testdestroy)")





    void AddMethods(WrapClass<wxThread>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxThread_h
