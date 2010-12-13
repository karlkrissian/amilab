/**
 * C++ Interface: wrap_vtkCommand
 *
 * Description: wrapping vtkCommand
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkCommand_h_
#define _wrap_vtkCommand_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkCommand.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObjectBase.h"


#ifndef vtkCommand_declared
  #define vtkCommand_declared
  AMI_DECLARE_TYPE(vtkCommand);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkCommand : public WrapClass<vtkCommand>
    , public   WrapClass_vtkObjectBase
{
  DEFINE_CLASS(WrapClass_vtkCommand);

  protected:
    typedef WrapClass<vtkCommand>::ptr _parentclass_ptr;
    typedef vtkCommand ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkCommand>& GetObj() const { return WrapClass<vtkCommand>::GetObj(); }

    /// Constructor
    WrapClass_vtkCommand(boost::shared_ptr<vtkCommand > si): 
    WrapClass<vtkCommand>(si)
    , WrapClass_vtkObjectBase(si)
    {}

    /// Destructor
    ~WrapClass_vtkCommand()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkCommand*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(GetStringFromEventId,"char const * vtkCommand::GetStringFromEventId(long unsigned int event) (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#getstringfromeventid).");
    ADD_CLASS_STATICMETHOD(GetEventIdFromString,"long unsigned int vtkCommand::GetEventIdFromString(char const * event) (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#geteventidfromstring).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(UnRegister_1,"void vtkCommand::UnRegister()  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#unregister)")
    ADD_CLASS_METHOD(UnRegister,"vtkCommand::UnRegister()  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#unregister)")
    ADD_CLASS_METHOD(UnRegister_2,"void vtkCommand::UnRegister(vtkObjectBase * param0)  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#unregister)")
    ADD_CLASS_METHOD(SetAbortFlag,"void vtkCommand::SetAbortFlag(int f)  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#setabortflag)")
    ADD_CLASS_METHOD(GetAbortFlag,"int vtkCommand::GetAbortFlag()  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#getabortflag)")
    ADD_CLASS_METHOD(AbortFlagOn,"void vtkCommand::AbortFlagOn()  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#abortflagon)")
    ADD_CLASS_METHOD(AbortFlagOff,"void vtkCommand::AbortFlagOff()  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#abortflagoff)")
    ADD_CLASS_METHOD(SetPassiveObserver,"void vtkCommand::SetPassiveObserver(int f)  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#setpassiveobserver)")
    ADD_CLASS_METHOD(GetPassiveObserver,"int vtkCommand::GetPassiveObserver()  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#getpassiveobserver)")
    ADD_CLASS_METHOD(PassiveObserverOn,"void vtkCommand::PassiveObserverOn()  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#passiveobserveron)")
    ADD_CLASS_METHOD(PassiveObserverOff,"void vtkCommand::PassiveObserverOff()  (http://docs.wxwidgets.org/stable/wx_vtkcommand.html#passiveobserveroff)")





    void AddMethods(WrapClass<vtkCommand>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkCommand_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkCommand_h
