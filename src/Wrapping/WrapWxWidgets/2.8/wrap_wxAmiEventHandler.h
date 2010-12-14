/**
 * C++ Interface: wrap_wxAmiEventHandler
 *
 * Description: wrapping wxAmiEventHandler
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAmiEventHandler_h_
#define _wrap_wxAmiEventHandler_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvtHandler.h"


#ifndef wxAmiEventHandler_declared
  #define wxAmiEventHandler_declared
  AMI_DECLARE_TYPE(wxAmiEventHandler);
#endif

// TODO: check for inheritence ...
class WrapClass_wxAmiEventHandler : public WrapClass<wxAmiEventHandler>
    , public   WrapClass_wxEvtHandler
{
  DEFINE_CLASS(WrapClass_wxAmiEventHandler);

  protected:
    typedef WrapClass<wxAmiEventHandler>::ptr _parentclass_ptr;
    typedef wxAmiEventHandler ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAmiEventHandler>& GetObj() const { return WrapClass<wxAmiEventHandler>::GetObj(); }

    /// Constructor
    WrapClass_wxAmiEventHandler(boost::shared_ptr<wxAmiEventHandler > si): 
    WrapClass<wxAmiEventHandler>(si)
    , WrapClass_wxEvtHandler(si)
    {}

    /// Destructor
    ~WrapClass_wxAmiEventHandler()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAmiEventHandler,"Constructor wxAmiEventHandler::wxAmiEventHandler(AMIFunction * f = 0l) (http://docs.wxwidgets.org/stable/wx_wxamieventhandler.html#wxamieventhandler).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAmiEventHandler*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(OnTest,"void wxAmiEventHandler::OnTest(wxCommandEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxamieventhandler.html#ontest)")
    ADD_CLASS_METHOD(GetEventFunction,"wxObjectEventFunction * wxAmiEventHandler::GetEventFunction()  (http://docs.wxwidgets.org/stable/wx_wxamieventhandler.html#geteventfunction)")





    void AddMethods(WrapClass<wxAmiEventHandler>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAmiEventHandler_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxAmiEventHandler_h
