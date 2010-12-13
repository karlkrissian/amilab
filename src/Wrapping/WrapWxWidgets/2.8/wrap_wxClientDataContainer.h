/**
 * C++ Interface: wrap_wxClientDataContainer
 *
 * Description: wrapping wxClientDataContainer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxClientDataContainer_h_
#define _wrap_wxClientDataContainer_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxClientDataContainer_declared
  #define wxClientDataContainer_declared
  AMI_DECLARE_TYPE(wxClientDataContainer);
#endif

// TODO: check for inheritence ...
class WrapClass_wxClientDataContainer : public WrapClass<wxClientDataContainer>
    
{
  DEFINE_CLASS(WrapClass_wxClientDataContainer);

  protected:
    typedef WrapClass<wxClientDataContainer>::ptr _parentclass_ptr;
    typedef wxClientDataContainer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxClientDataContainer>& GetObj() const { return WrapClass<wxClientDataContainer>::GetObj(); }

    /// Constructor
    WrapClass_wxClientDataContainer(boost::shared_ptr<wxClientDataContainer > si): 
    WrapClass<wxClientDataContainer>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxClientDataContainer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxClientDataContainer_1,"Constructor wxClientDataContainer::wxClientDataContainer(wxClientDataContainer const & param0) (http://docs.wxwidgets.org/stable/wx_wxclientdatacontainer.html#wxclientdatacontainer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxClientDataContainer,"Constructor wxClientDataContainer::wxClientDataContainer() (http://docs.wxwidgets.org/stable/wx_wxclientdatacontainer.html#wxclientdatacontainer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxClientDataContainer_2,"Constructor wxClientDataContainer::wxClientDataContainer() (http://docs.wxwidgets.org/stable/wx_wxclientdatacontainer.html#wxclientdatacontainer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxClientDataContainer*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SetClientObject,"void wxClientDataContainer::SetClientObject(wxClientData * data)  (http://docs.wxwidgets.org/stable/wx_wxclientdatacontainer.html#setclientobject)")
    ADD_CLASS_METHOD(GetClientObject,"wxClientData * wxClientDataContainer::GetClientObject()  (http://docs.wxwidgets.org/stable/wx_wxclientdatacontainer.html#getclientobject)")
/* The following types are missing: void
    ADD_CLASS_METHOD(SetClientData,"void wxClientDataContainer::SetClientData(void * data)  (http://docs.wxwidgets.org/stable/wx_wxclientdatacontainer.html#setclientdata)")
*/
    ADD_CLASS_METHOD(GetClientData,"void * wxClientDataContainer::GetClientData()  (http://docs.wxwidgets.org/stable/wx_wxclientdatacontainer.html#getclientdata)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxClientDataContainer & wxClientDataContainer::operator =(wxClientDataContainer const & param0) (http://docs.wxwidgets.org/stable/wx_wxclientdatacontainer.html#__assign__)")




    void AddMethods(WrapClass<wxClientDataContainer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxClientDataContainer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxClientDataContainer_h
