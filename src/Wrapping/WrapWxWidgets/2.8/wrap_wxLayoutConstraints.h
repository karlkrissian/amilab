/**
 * C++ Interface: wrap_wxLayoutConstraints
 *
 * Description: wrapping wxLayoutConstraints
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxLayoutConstraints_h_
#define _wrap_wxLayoutConstraints_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


AMI_DECLARE_TYPE(wxLayoutConstraints);

// TODO: check for inheritence ...
class WrapClass_wxLayoutConstraints : public WrapClass<wxLayoutConstraints>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxLayoutConstraints);

  protected:
    typedef WrapClass<wxLayoutConstraints>::ptr _parentclass_ptr;
    typedef wxLayoutConstraints ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxLayoutConstraints>& GetObj() const { return WrapClass<wxLayoutConstraints>::GetObj(); }

    /// Constructor
    WrapClass_wxLayoutConstraints(boost::shared_ptr<wxLayoutConstraints > si): 
    WrapClass<wxLayoutConstraints>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxLayoutConstraints()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxLayoutConstraints_1,"Constructor wxLayoutConstraints::wxLayoutConstraints(wxLayoutConstraints const & param0) (http://docs.wxwidgets.org/stable/wx_wxlayoutconstraints.html#wxlayoutconstraints).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxLayoutConstraints,"Constructor wxLayoutConstraints::wxLayoutConstraints() (http://docs.wxwidgets.org/stable/wx_wxlayoutconstraints.html#wxlayoutconstraints).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxLayoutConstraints_2,"Constructor wxLayoutConstraints::wxLayoutConstraints() (http://docs.wxwidgets.org/stable/wx_wxlayoutconstraints.html#wxlayoutconstraints).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxLayoutConstraints*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SatisfyConstraints,"bool wxLayoutConstraints::SatisfyConstraints(wxWindowBase * win, int * noChanges)  (http://docs.wxwidgets.org/stable/wx_wxlayoutconstraints.html#satisfyconstraints)")
    ADD_CLASS_METHOD(AreSatisfied,"bool wxLayoutConstraints::AreSatisfied()  (http://docs.wxwidgets.org/stable/wx_wxlayoutconstraints.html#aresatisfied)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxLayoutConstraints::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxlayoutconstraints.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxLayoutConstraints & wxLayoutConstraints::operator =(wxLayoutConstraints const & param0) (http://docs.wxwidgets.org/stable/wx_wxlayoutconstraints.html#__assign__)")




    void AddMethods(WrapClass<wxLayoutConstraints>::ptr this_ptr );

};


#endif // _wrap_wxLayoutConstraints_h
