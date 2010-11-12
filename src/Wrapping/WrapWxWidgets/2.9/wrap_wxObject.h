/**
 * C++ Interface: wrap_wxObject
 *
 * Description: wrapping wxObject
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxObject_h_
#define _wrap_wxObject_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxObject);

// TODO: check for inheritence ...
class WrapClass_wxObject : public WrapClass<wxObject>
    
{
  DEFINE_CLASS(WrapClass_wxObject);

  protected:
    typedef WrapClass<wxObject>::ptr _parentclass_ptr;
    typedef wxObject ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxObject>& GetObj() const { return WrapClass<wxObject>::GetObj(); }

    /// Constructor
    WrapClass_wxObject(boost::shared_ptr<wxObject > si): 
    WrapClass<wxObject>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxObject()
    {
      std::cout << "~WrapClass_wxObject()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObject,"Wrapping of wxObject.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObject1,"Wrapping of wxObject.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxObject*);

    // here add each method
    
    ADD_CLASS_METHOD(GetClassInfo,"")
    ADD_CLASS_METHOD(IsKindOf,"")
/* The following types are missing: wxObjectRefData
    ADD_CLASS_METHOD(GetRefData,"")
*/
/* The following types are missing: wxObjectRefData
    ADD_CLASS_METHOD(SetRefData,"")
*/
    ADD_CLASS_METHOD(Ref,"")
    ADD_CLASS_METHOD(UnRef,"")
    ADD_CLASS_METHOD(UnShare,"")
    ADD_CLASS_METHOD(IsSameAs,"")

    // Operators:
    ADD_CLASS_METHOD(assign,"")




    void AddMethods(WrapClass<wxObject>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      
      AddVar_GetClassInfo( this_ptr);
      AddVar_IsKindOf( this_ptr);
/* The following types are missing: wxObjectRefData
      AddVar_GetRefData( this_ptr);
*/
/* The following types are missing: wxObjectRefData
      AddVar_SetRefData( this_ptr);
*/
      AddVar_Ref( this_ptr);
      AddVar_UnRef( this_ptr);
      AddVar_UnShare( this_ptr);
      AddVar_IsSameAs( this_ptr);

      // Operators:
      AddVar_assign( this_ptr);


    };
};


#endif // _wrap_wxObject_h
