/**
 * C++ Interface: wrap_wxIconBundle
 *
 * Description: wrapping wxIconBundle
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxIconBundle_h_
#define _wrap_wxIconBundle_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxIconBundle_declared
  #define wxIconBundle_declared
  AMI_DECLARE_TYPE(wxIconBundle);
#endif

// TODO: check for inheritence ...
class WrapClass_wxIconBundle : public WrapClass<wxIconBundle>
    
{
  DEFINE_CLASS(WrapClass_wxIconBundle);

  protected:
    typedef WrapClass<wxIconBundle>::ptr _parentclass_ptr;
    typedef wxIconBundle ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxIconBundle>& GetObj() const { return WrapClass<wxIconBundle>::GetObj(); }

    /// Constructor
    WrapClass_wxIconBundle(boost::shared_ptr<wxIconBundle > si): 
    WrapClass<wxIconBundle>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxIconBundle()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconBundle_1,"Constructor wxIconBundle::wxIconBundle() (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#wxiconbundle).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconBundle,"Constructor wxIconBundle::wxIconBundle() (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#wxiconbundle).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconBundle_2,"Constructor wxIconBundle::wxIconBundle(wxString const & file, long int type) (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#wxiconbundle).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconBundle_3,"Constructor wxIconBundle::wxIconBundle(wxIcon const & icon) (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#wxiconbundle).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconBundle_4,"Constructor wxIconBundle::wxIconBundle(wxIconBundle const & ic) (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#wxiconbundle).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxIconBundle*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(AddIcon_1,"void wxIconBundle::AddIcon(wxString const & file, long int type)  (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#addicon)")
    ADD_CLASS_METHOD(AddIcon,"wxIconBundle::AddIcon()  (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#addicon)")
    ADD_CLASS_METHOD(AddIcon_2,"void wxIconBundle::AddIcon(wxIcon const & icon)  (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#addicon)")
    ADD_CLASS_METHOD(GetIcon_1,"wxIcon const & wxIconBundle::GetIcon(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#geticon)")
    ADD_CLASS_METHOD(GetIcon,"wxIconBundle::GetIcon()  (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#geticon)")
    ADD_CLASS_METHOD(GetIcon_2,"wxIcon const & wxIconBundle::GetIcon(wxCoord size = wxDefaultCoord)  (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#geticon)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxIconBundle const & wxIconBundle::operator =(wxIconBundle const & ic) (http://docs.wxwidgets.org/stable/wx_wxiconbundle.html#__assign__)")




    void AddMethods(WrapClass<wxIconBundle>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxIconBundle_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxIconBundle_h
