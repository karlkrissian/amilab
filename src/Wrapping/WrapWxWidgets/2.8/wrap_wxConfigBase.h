/**
 * C++ Interface: wrap_wxConfigBase
 *
 * Description: wrapping wxConfigBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxConfigBase_h_
#define _wrap_wxConfigBase_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxConfigBase_declared
  #define wxConfigBase_declared
  AMI_DECLARE_TYPE(wxConfigBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxConfigBase : public WrapClass<wxConfigBase>
    
{
  DEFINE_CLASS(WrapClass_wxConfigBase);

  protected:
    typedef WrapClass<wxConfigBase>::ptr _parentclass_ptr;
    typedef wxConfigBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxConfigBase>& GetObj() const { return WrapClass<wxConfigBase>::GetObj(); }

    /// Constructor
    WrapClass_wxConfigBase(boost::shared_ptr<wxConfigBase > si): 
    WrapClass<wxConfigBase>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxConfigBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxConfigBase*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(Set,"wxConfigBase * wxConfigBase::Set(wxConfigBase * pConfig) (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#set).");
    ADD_CLASS_STATICMETHOD(Get,"wxConfigBase * wxConfigBase::Get(bool createOnDemand = true) (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#get).");
    ADD_CLASS_STATICMETHOD(Create,"wxConfigBase * wxConfigBase::Create() (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#create).");
    ADD_CLASS_STATICMETHOD(DontCreateOnDemand,"void wxConfigBase::DontCreateOnDemand() (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#dontcreateondemand).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Exists,"bool wxConfigBase::Exists(wxString const & strName)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#exists)")
    ADD_CLASS_METHOD(GetEntryType,"wxConfigBase::EntryType wxConfigBase::GetEntryType(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#getentrytype)")
    ADD_CLASS_METHOD(Read_1,"bool wxConfigBase::Read(wxString const & key, wxString * pStr)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read,"wxConfigBase::Read()  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_2,"bool wxConfigBase::Read(wxString const & key, wxString * pStr, wxString const & defVal)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_3,"bool wxConfigBase::Read(wxString const & key, long int * pl)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_4,"bool wxConfigBase::Read(wxString const & key, long int * pl, long int defVal)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_5,"bool wxConfigBase::Read(wxString const & key, int * pi)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_6,"bool wxConfigBase::Read(wxString const & key, int * pi, int defVal)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_7,"bool wxConfigBase::Read(wxString const & key, double * val)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_8,"bool wxConfigBase::Read(wxString const & key, double * val, double defVal)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_9,"bool wxConfigBase::Read(wxString const & key, bool * val)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_10,"bool wxConfigBase::Read(wxString const & key, bool * val, bool defVal)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_11,"wxString wxConfigBase::Read(wxString const & key, wxString const & defVal = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Read_12,"long int wxConfigBase::Read(wxString const & key, long int defVal)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#read)")
    ADD_CLASS_METHOD(Write_1,"bool wxConfigBase::Write(wxString const & key, wxString const & value)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#write)")
    ADD_CLASS_METHOD(Write,"wxConfigBase::Write()  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#write)")
    ADD_CLASS_METHOD(Write_2,"bool wxConfigBase::Write(wxString const & key, long int value)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#write)")
    ADD_CLASS_METHOD(Write_3,"bool wxConfigBase::Write(wxString const & key, int value)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#write)")
    ADD_CLASS_METHOD(Write_4,"bool wxConfigBase::Write(wxString const & key, double value)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#write)")
    ADD_CLASS_METHOD(Write_5,"bool wxConfigBase::Write(wxString const & key, bool value)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#write)")
    ADD_CLASS_METHOD(Write_6,"bool wxConfigBase::Write(wxString const & key, wxChar const * value)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#write)")
    ADD_CLASS_METHOD(IsExpandingEnvVars,"bool wxConfigBase::IsExpandingEnvVars()  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#isexpandingenvvars)")
    ADD_CLASS_METHOD(SetExpandEnvVars,"void wxConfigBase::SetExpandEnvVars(bool bDoIt = true)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#setexpandenvvars)")
    ADD_CLASS_METHOD(SetRecordDefaults,"void wxConfigBase::SetRecordDefaults(bool bDoIt = true)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#setrecorddefaults)")
    ADD_CLASS_METHOD(IsRecordingDefaults,"bool wxConfigBase::IsRecordingDefaults()  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#isrecordingdefaults)")
    ADD_CLASS_METHOD(ExpandEnvVars,"wxString wxConfigBase::ExpandEnvVars(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#expandenvvars)")
    ADD_CLASS_METHOD(GetAppName,"wxString wxConfigBase::GetAppName()  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#getappname)")
    ADD_CLASS_METHOD(GetVendorName,"wxString wxConfigBase::GetVendorName()  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#getvendorname)")
    ADD_CLASS_METHOD(SetAppName,"void wxConfigBase::SetAppName(wxString const & appName)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#setappname)")
    ADD_CLASS_METHOD(SetVendorName,"void wxConfigBase::SetVendorName(wxString const & vendorName)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#setvendorname)")
    ADD_CLASS_METHOD(SetStyle,"void wxConfigBase::SetStyle(long int style)  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#setstyle)")
    ADD_CLASS_METHOD(GetStyle,"long int wxConfigBase::GetStyle()  (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#getstyle)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxConfigBase & wxConfigBase::operator =(wxConfigBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxconfigbase.html#__assign__)")




    void AddMethods(WrapClass<wxConfigBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxConfigBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxConfigBase_h
