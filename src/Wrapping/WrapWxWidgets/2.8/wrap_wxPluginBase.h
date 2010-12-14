/**
 * C++ Interface: wrap_wxPluginBase
 *
 * Description: wrapping wxPluginBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPluginBase_h_
#define _wrap_wxPluginBase_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxPluginInterface.h"


#ifndef wxPluginBase_declared
  #define wxPluginBase_declared
  AMI_DECLARE_TYPE(wxPluginBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxPluginBase : public WrapClass<wxPluginBase>
    , public   WrapClass_wxPluginInterface
{
  DEFINE_CLASS(WrapClass_wxPluginBase);

  protected:
    typedef WrapClass<wxPluginBase>::ptr _parentclass_ptr;
    typedef wxPluginBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPluginBase>& GetObj() const { return WrapClass<wxPluginBase>::GetObj(); }

    /// Constructor
    WrapClass_wxPluginBase(boost::shared_ptr<wxPluginBase > si): 
    WrapClass<wxPluginBase>(si)
    , WrapClass_wxPluginInterface(si)
    {}

    /// Destructor
    ~WrapClass_wxPluginBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPluginBase_1,"Constructor wxPluginBase::wxPluginBase(wxPluginBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#wxpluginbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPluginBase,"Constructor wxPluginBase::wxPluginBase() (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#wxpluginbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPluginBase_2,"Constructor wxPluginBase::wxPluginBase() (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#wxpluginbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPluginBase*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetName,"wxString wxPluginBase::GetName()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#getname)")
    ADD_CLASS_METHOD(GetDescription,"wxString wxPluginBase::GetDescription()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#getdescription)")
    ADD_CLASS_METHOD(GetVersion,"wxString wxPluginBase::GetVersion()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#getversion)")
    ADD_CLASS_METHOD(GetAuthor,"wxString wxPluginBase::GetAuthor()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#getauthor)")
    ADD_CLASS_METHOD(SetName,"void wxPluginBase::SetName(wxString const & Name)  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#setname)")
    ADD_CLASS_METHOD(SetDescription,"void wxPluginBase::SetDescription(wxString const & Description)  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#setdescription)")
    ADD_CLASS_METHOD(SetVersion,"void wxPluginBase::SetVersion(wxString const & Version)  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#setversion)")
    ADD_CLASS_METHOD(SetAuthor,"void wxPluginBase::SetAuthor(wxString const & Author)  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#setauthor)")
    ADD_CLASS_METHOD(GetwxWindow,"wxWindow * wxPluginBase::GetwxWindow()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#getwxwindow)")
    ADD_CLASS_METHOD(SetwxWindow,"void wxPluginBase::SetwxWindow(wxWindow * Parent)  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#setwxwindow)")
    ADD_CLASS_METHOD(SetConsoleMode,"void wxPluginBase::SetConsoleMode()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#setconsolemode)")
    ADD_CLASS_METHOD(SetGraphicMode,"void wxPluginBase::SetGraphicMode()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#setgraphicmode)")
    ADD_CLASS_METHOD(IsConsoleMode,"bool wxPluginBase::IsConsoleMode()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#isconsolemode)")
    ADD_CLASS_METHOD(IsGraphicMode,"bool wxPluginBase::IsGraphicMode()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#isgraphicmode)")
    ADD_CLASS_METHOD(Execute,"bool wxPluginBase::Execute()  (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#execute)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxPluginBase & wxPluginBase::operator =(wxPluginBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxpluginbase.html#__assign__)")




    void AddMethods(WrapClass<wxPluginBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPluginBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxPluginBase_h
