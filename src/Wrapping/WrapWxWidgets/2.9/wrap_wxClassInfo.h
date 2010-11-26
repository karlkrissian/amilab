/**
 * C++ Interface: wrap_wxClassInfo
 *
 * Description: wrapping wxClassInfo
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxClassInfo_h_
#define _wrap_wxClassInfo_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxClassInfo);

// TODO: check for inheritence ...
class WrapClass_wxClassInfo : public WrapClass<wxClassInfo>
    
{
  DEFINE_CLASS(WrapClass_wxClassInfo);

  protected:
    typedef WrapClass<wxClassInfo>::ptr _parentclass_ptr;
    typedef wxClassInfo ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxClassInfo>& GetObj() const { return WrapClass<wxClassInfo>::GetObj(); }

    /// Constructor
    WrapClass_wxClassInfo(boost::shared_ptr<wxClassInfo > si): 
    WrapClass<wxClassInfo>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxClassInfo()
    {
      std::cout << "~WrapClass_wxClassInfo()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /* The following types are missing: wchar_t, _8995
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxClassInfo,"Wrapping of wxClassInfo.");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar(   wxClassInfo*);

    // here add each method
    
    ADD_CLASS_METHOD(CreateObject,"")
    ADD_CLASS_METHOD(IsDynamic,"")
/* The following types are missing: wchar_t
    ADD_CLASS_METHOD(GetClassName,"")
*/
/* The following types are missing: wchar_t
    ADD_CLASS_METHOD(GetBaseClassName1,"")
*/
/* The following types are missing: wchar_t
    ADD_CLASS_METHOD(GetBaseClassName2,"")
*/
    ADD_CLASS_METHOD(GetBaseClass1,"")
    ADD_CLASS_METHOD(GetBaseClass2,"")
    ADD_CLASS_METHOD(GetSize,"")
/* The following types are missing: _8995
    ADD_CLASS_METHOD(GetConstructor,"")
*/
    ADD_CLASS_METHOD(GetFirst,"")
    ADD_CLASS_METHOD(GetNext,"")
/* The following types are missing: wchar_t
    ADD_CLASS_METHOD(FindClass,"")
*/
    ADD_CLASS_METHOD(IsKindOf,"")
    ADD_CLASS_METHOD(InitializeClasses,"")
    ADD_CLASS_METHOD(CleanUpClasses,"")





    void AddMethods(WrapClass<wxClassInfo>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      
      AddVar_CreateObject( this_ptr);
      AddVar_IsDynamic( this_ptr);
/* The following types are missing: wchar_t
      AddVar_GetClassName( this_ptr);
*/
/* The following types are missing: wchar_t
      AddVar_GetBaseClassName1( this_ptr);
*/
/* The following types are missing: wchar_t
      AddVar_GetBaseClassName2( this_ptr);
*/
      AddVar_GetBaseClass1( this_ptr);
      AddVar_GetBaseClass2( this_ptr);
      AddVar_GetSize( this_ptr);
/* The following types are missing: _8995
      AddVar_GetConstructor( this_ptr);
*/
      AddVar_GetFirst( this_ptr);
      AddVar_GetNext( this_ptr);
/* The following types are missing: wchar_t
      AddVar_FindClass( this_ptr);
*/
      AddVar_IsKindOf( this_ptr);
      AddVar_InitializeClasses( this_ptr);
      AddVar_CleanUpClasses( this_ptr);



    };
};


#endif // _wrap_wxClassInfo_h
