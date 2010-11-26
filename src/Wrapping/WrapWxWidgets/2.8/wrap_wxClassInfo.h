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
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /* The following types are missing: _8997
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxClassInfo,"Constructor wxClassInfo::wxClassInfo(wxChar const * className, wxClassInfo const * baseInfo1, wxClassInfo const * baseInfo2, int size, wxObjectConstructorFn ctor) (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#wxclassinfo).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxClassInfo*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(GetFirst,"wxClassInfo const * wxClassInfo::GetFirst() (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#getfirst).");
    ADD_CLASS_STATICMETHOD(FindClass,"wxClassInfo * wxClassInfo::FindClass(wxChar const * className) (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#findclass).");
    ADD_CLASS_STATICMETHOD(InitializeClasses,"void wxClassInfo::InitializeClasses() (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#initializeclasses).");
    ADD_CLASS_STATICMETHOD(CleanUpClasses,"void wxClassInfo::CleanUpClasses() (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#cleanupclasses).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(CreateObject,"wxObject * wxClassInfo::CreateObject()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#createobject)")
    ADD_CLASS_METHOD(IsDynamic,"bool wxClassInfo::IsDynamic()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#isdynamic)")
    ADD_CLASS_METHOD(GetClassName,"wxChar const * wxClassInfo::GetClassName()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#getclassname)")
    ADD_CLASS_METHOD(GetBaseClassName1,"wxChar const * wxClassInfo::GetBaseClassName1()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#getbaseclassname1)")
    ADD_CLASS_METHOD(GetBaseClassName2,"wxChar const * wxClassInfo::GetBaseClassName2()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#getbaseclassname2)")
    ADD_CLASS_METHOD(GetBaseClass1,"wxClassInfo const * wxClassInfo::GetBaseClass1()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#getbaseclass1)")
    ADD_CLASS_METHOD(GetBaseClass2,"wxClassInfo const * wxClassInfo::GetBaseClass2()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#getbaseclass2)")
    ADD_CLASS_METHOD(GetSize,"int wxClassInfo::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#getsize)")
/* The following types are missing: _8997
    ADD_CLASS_METHOD(GetConstructor,"wxObjectConstructorFn wxClassInfo::GetConstructor()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#getconstructor)")
*/
    ADD_CLASS_METHOD(GetNext,"wxClassInfo const * wxClassInfo::GetNext()  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#getnext)")
    ADD_CLASS_METHOD(IsKindOf,"bool wxClassInfo::IsKindOf(wxClassInfo const * info)  (http://docs.wxwidgets.org/stable/wx_wxclassinfo.html#iskindof)")





    void AddMethods(WrapClass<wxClassInfo>::ptr this_ptr );

};


#endif // _wrap_wxClassInfo_h
