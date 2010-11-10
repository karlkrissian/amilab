/**
 * C++ Interface: wrap_wxControl
 *
 * Description: wrapping wxControl
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxControl_h_
#define _wrap_wxControl_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

//#include "wrap_wxControlBase.h"


AMI_DECLARE_TYPE(wxControl);

// TODO: check for inheritence ...
class WrapClass_wxControl : public WrapClass<wxControl>
    //, public virtual WrapClass_wxControlBase
{
  DEFINE_CLASS(WrapClass_wxControl);

  protected:
    typedef WrapClass<wxControl>::ptr _parentclass_ptr;
    typedef wxControl ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxControl>& GetObj() const { return WrapClass<wxControl>::GetObj(); }

    /// Constructor
    WrapClass_wxControl(boost::shared_ptr<wxControl > si): 
    WrapClass<wxControl>(si)
    //, WrapClass_wxControlBase(si)
    {}

    /// Destructor
    ~WrapClass_wxControl()
    {
      std::cout << "~WrapClass_wxControl()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxControl,"Wrapping of wxControl.");
    /* The following types are missing: wxValidator
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxControl1,"Wrapping of wxControl.");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxControl*);

    // here add each method
    
/* The following types are missing: wxValidator
    ADD_CLASS_METHOD(Create,"")
*/
    ADD_CLASS_METHOD(SetLabel,"")
    ADD_CLASS_METHOD(GetLabel,"")
/* The following types are missing: wxVisualAttributes
    ADD_CLASS_METHOD(GetDefaultAttributes,"")
*/
    ADD_CLASS_METHOD(OnInternalIdle,"")
/* The following types are missing: wxClassInfo
    ADD_CLASS_METHOD(GetClassInfo,"")
*/
    ADD_CLASS_METHOD(wxCreateObject,"")

    // Operators:




    void AddMethods(WrapClass<wxControl>::ptr this_ptr )
    {
      // here inheritence
      /*
      // Add members from wxControlBase
      WrapClass_wxControlBase::ptr parent_wxControlBase(        boost::dynamic_pointer_cast<WrapClass_wxControlBase>(this_ptr));
      parent_wxControlBase->AddMethods(parent_wxControlBase);
      */


      // check that the method name is not a token
      
/* The following types are missing: wxValidator
      AddVar_Create( this_ptr);
*/
      AddVar_SetLabel( this_ptr);
      AddVar_GetLabel( this_ptr);
/* The following types are missing: wxVisualAttributes
      AddVar_GetDefaultAttributes( this_ptr);
*/
      AddVar_OnInternalIdle( this_ptr);
/* The following types are missing: wxClassInfo
      AddVar_GetClassInfo( this_ptr);
*/
      AddVar_wxCreateObject( this_ptr);

      // Operators:


    };
};


#endif // _wrap_wxControl_h
