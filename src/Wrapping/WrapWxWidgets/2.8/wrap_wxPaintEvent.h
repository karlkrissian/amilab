/**
 * C++ Interface: wrap_wxPaintEvent
 *
 * Description: wrapping wxPaintEvent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPaintEvent_h_
#define _wrap_wxPaintEvent_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvent.h"


#ifndef wxPaintEvent_declared
  #define wxPaintEvent_declared
  AMI_DECLARE_TYPE(wxPaintEvent);
#endif

// TODO: check for inheritence ...
class WrapClass_wxPaintEvent : public WrapClass<wxPaintEvent>
    , public   WrapClass_wxEvent
{
  DEFINE_CLASS(WrapClass_wxPaintEvent);

  protected:
    typedef WrapClass<wxPaintEvent>::ptr _parentclass_ptr;
    typedef wxPaintEvent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPaintEvent>& GetObj() const { return WrapClass<wxPaintEvent>::GetObj(); }

    /// Constructor
    WrapClass_wxPaintEvent(boost::shared_ptr<wxPaintEvent > si): 
    WrapClass<wxPaintEvent>(si)
    , WrapClass_wxEvent(si)
    {}

    /// Destructor
    ~WrapClass_wxPaintEvent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPaintEvent_1,"Constructor wxPaintEvent::wxPaintEvent(wxPaintEvent const & param0) (http://docs.wxwidgets.org/stable/wx_wxpaintevent.html#wxpaintevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPaintEvent,"Constructor wxPaintEvent::wxPaintEvent() (http://docs.wxwidgets.org/stable/wx_wxpaintevent.html#wxpaintevent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPaintEvent_2,"Constructor wxPaintEvent::wxPaintEvent(int Id = 0) (http://docs.wxwidgets.org/stable/wx_wxpaintevent.html#wxpaintevent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPaintEvent*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Clone,"wxEvent * wxPaintEvent::Clone()  (http://docs.wxwidgets.org/stable/wx_wxpaintevent.html#clone)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxPaintEvent::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxpaintevent.html#getclassinfo)")





    void AddMethods(WrapClass<wxPaintEvent>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPaintEvent_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxPaintEvent_h
