/**
 * C++ Interface: wrap_wxDynamicLibrary
 *
 * Description: wrapping wxDynamicLibrary
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDynamicLibrary_h_
#define _wrap_wxDynamicLibrary_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxDynamicLibrary_declared
  #define wxDynamicLibrary_declared
  AMI_DECLARE_TYPE(wxDynamicLibrary);
#endif

// TODO: check for inheritence ...
class WrapClass_wxDynamicLibrary : public WrapClass<wxDynamicLibrary>
    
{
  DEFINE_CLASS(WrapClass_wxDynamicLibrary);

  protected:
    typedef WrapClass<wxDynamicLibrary>::ptr _parentclass_ptr;
    typedef wxDynamicLibrary ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDynamicLibrary>& GetObj() const { return WrapClass<wxDynamicLibrary>::GetObj(); }

    /// Constructor
    WrapClass_wxDynamicLibrary(boost::shared_ptr<wxDynamicLibrary > si): 
    WrapClass<wxDynamicLibrary>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxDynamicLibrary()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDynamicLibrary_1,"Constructor wxDynamicLibrary::wxDynamicLibrary() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#wxdynamiclibrary).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDynamicLibrary,"Constructor wxDynamicLibrary::wxDynamicLibrary() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#wxdynamiclibrary).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDynamicLibrary_2,"Constructor wxDynamicLibrary::wxDynamicLibrary(wxString const & libname, int flags = wxDL_NOW) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#wxdynamiclibrary).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDynamicLibrary*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(GetProgramHandle,"wxDllType wxDynamicLibrary::GetProgramHandle() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#getprogramhandle).");
    ADD_CLASS_STATICMETHOD(GetDllExt,"wxChar const * wxDynamicLibrary::GetDllExt() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#getdllext).");
    ADD_CLASS_STATICMETHOD(RawLoad,"wxDllType wxDynamicLibrary::RawLoad(wxString const & libname, int flags = wxDL_NOW) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#rawload).");
    /* The following types are missing: void
    ADD_CLASS_STATICMETHOD(Unload,"void wxDynamicLibrary::Unload(wxDllType handle) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#unload).");
    */
    /* The following types are missing: void
    ADD_CLASS_STATICMETHOD(RawGetSymbol,"void * wxDynamicLibrary::RawGetSymbol(wxDllType handle, wxString const & name) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#rawgetsymbol).");
    */
    ADD_CLASS_STATICMETHOD(ListLoaded,"wxDynamicLibraryDetailsArray wxDynamicLibrary::ListLoaded() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#listloaded).");
    ADD_CLASS_STATICMETHOD(CanonicalizeName,"wxString wxDynamicLibrary::CanonicalizeName(wxString const & name, wxDynamicLibraryCategory cat = wxDL_LIBRARY) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#canonicalizename).");
    ADD_CLASS_STATICMETHOD(CanonicalizePluginName,"wxString wxDynamicLibrary::CanonicalizePluginName(wxString const & name, wxPluginCategory cat = wxDL_PLUGIN_GUI) (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#canonicalizepluginname).");
    ADD_CLASS_STATICMETHOD(GetPluginsDirectory,"wxString wxDynamicLibrary::GetPluginsDirectory() (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#getpluginsdirectory).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsLoaded,"bool wxDynamicLibrary::IsLoaded()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#isloaded)")
    ADD_CLASS_METHOD(Load,"bool wxDynamicLibrary::Load(wxString const & libname, int flags = wxDL_NOW)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#load)")
    ADD_CLASS_METHOD(Detach,"wxDllType wxDynamicLibrary::Detach()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#detach)")
    ADD_CLASS_METHOD(Unload,"void wxDynamicLibrary::Unload()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#unload)")
    ADD_CLASS_METHOD(GetLibHandle,"wxDllType wxDynamicLibrary::GetLibHandle()  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#getlibhandle)")
    ADD_CLASS_METHOD(HasSymbol,"bool wxDynamicLibrary::HasSymbol(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#hassymbol)")
    ADD_CLASS_METHOD(GetSymbol,"void * wxDynamicLibrary::GetSymbol(wxString const & name, bool * success = 0l)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#getsymbol)")
    ADD_CLASS_METHOD(RawGetSymbol,"void * wxDynamicLibrary::RawGetSymbol(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxdynamiclibrary.html#rawgetsymbol)")





    void AddMethods(WrapClass<wxDynamicLibrary>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDynamicLibrary_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxDynamicLibrary_h
