/**
 * C++ Interface: wrap_wxPluginManager
 *
 * Description: wrapping wxPluginManager
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPluginManager_h_
#define _wrap_wxPluginManager_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxPluginManager_declared
  #define wxPluginManager_declared
  AMI_DECLARE_TYPE(wxPluginManager);
#endif

// TODO: check for inheritence ...
class WrapClass_wxPluginManager : public WrapClass<wxPluginManager>
    
{
  DEFINE_CLASS(WrapClass_wxPluginManager);

  protected:
    typedef WrapClass<wxPluginManager>::ptr _parentclass_ptr;
    typedef wxPluginManager ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPluginManager>& GetObj() const { return WrapClass<wxPluginManager>::GetObj(); }

    /// Constructor
    WrapClass_wxPluginManager(boost::shared_ptr<wxPluginManager > si): 
    WrapClass<wxPluginManager>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxPluginManager()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPluginManager,"Constructor wxPluginManager::wxPluginManager() (http://docs.wxwidgets.org/stable/wx_wxpluginmanager.html#wxpluginmanager).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPluginManager*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(get_name,"char const * wxPluginManager::get_name()  (http://docs.wxwidgets.org/stable/wx_wxpluginmanager.html#get_name)")
    ADD_CLASS_METHOD(Load,"bool wxPluginManager::Load(wxString const & LibName)  (http://docs.wxwidgets.org/stable/wx_wxpluginmanager.html#load)")
    ADD_CLASS_METHOD(Detach,"void wxPluginManager::Detach()  (http://docs.wxwidgets.org/stable/wx_wxpluginmanager.html#detach)")
    ADD_CLASS_METHOD(Unload,"void wxPluginManager::Unload()  (http://docs.wxwidgets.org/stable/wx_wxpluginmanager.html#unload)")
    ADD_CLASS_METHOD(Getplugin,"wxPluginBase * wxPluginManager::Getplugin()  (http://docs.wxwidgets.org/stable/wx_wxpluginmanager.html#getplugin)")
    ADD_CLASS_METHOD(Getdll,"wxDynamicLibrary & wxPluginManager::Getdll()  (http://docs.wxwidgets.org/stable/wx_wxpluginmanager.html#getdll)")





    void AddMethods(WrapClass<wxPluginManager>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPluginManager_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxPluginManager_h
