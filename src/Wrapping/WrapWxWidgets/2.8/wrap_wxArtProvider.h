/**
 * C++ Interface: wrap_wxArtProvider
 *
 * Description: wrapping wxArtProvider
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxArtProvider_h_
#define _wrap_wxArtProvider_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


#ifndef wxArtProvider_declared
  #define wxArtProvider_declared
  AMI_DECLARE_TYPE(wxArtProvider);
#endif

// TODO: check for inheritence ...
class WrapClass_wxArtProvider : public WrapClass<wxArtProvider>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxArtProvider);

  protected:
    typedef WrapClass<wxArtProvider>::ptr _parentclass_ptr;
    typedef wxArtProvider ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxArtProvider>& GetObj() const { return WrapClass<wxArtProvider>::GetObj(); }

    /// Constructor
    WrapClass_wxArtProvider(boost::shared_ptr<wxArtProvider > si): 
    WrapClass<wxArtProvider>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxArtProvider()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxArtProvider*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(Push,"void wxArtProvider::Push(wxArtProvider * provider) (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#push).");
    ADD_CLASS_STATICMETHOD(PushBack,"void wxArtProvider::PushBack(wxArtProvider * provider) (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#pushback).");
    ADD_CLASS_STATICMETHOD(Insert,"void wxArtProvider::Insert(wxArtProvider * provider) (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#insert).");
    ADD_CLASS_STATICMETHOD(Pop,"bool wxArtProvider::Pop() (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#pop).");
    ADD_CLASS_STATICMETHOD(Remove,"bool wxArtProvider::Remove(wxArtProvider * provider) (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#remove).");
    ADD_CLASS_STATICMETHOD(Delete,"bool wxArtProvider::Delete(wxArtProvider * provider) (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#delete).");
    ADD_CLASS_STATICMETHOD(GetBitmap,"wxBitmap wxArtProvider::GetBitmap(wxArtID const & id, wxArtClient const & client = 'wxART_OTHER_C', wxSize const & size = wxDefaultSize) (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#getbitmap).");
    ADD_CLASS_STATICMETHOD(GetIcon,"wxIcon wxArtProvider::GetIcon(wxArtID const & id, wxArtClient const & client = 'wxART_OTHER_C', wxSize const & size = wxDefaultSize) (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#geticon).");
    ADD_CLASS_STATICMETHOD(GetSizeHint,"wxSize wxArtProvider::GetSizeHint(wxArtClient const & client, bool platform_dependent = false) (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#getsizehint).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxArtProvider::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxArtProvider & wxArtProvider::operator =(wxArtProvider const & param0) (http://docs.wxwidgets.org/stable/wx_wxartprovider.html#__assign__)")




    void AddMethods(WrapClass<wxArtProvider>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxArtProvider_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxArtProvider_h
