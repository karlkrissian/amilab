/**
 * C++ Interface: wrap_wxBoxSizer
 *
 * Description: wrapping wxBoxSizer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBoxSizer_h_
#define _wrap_wxBoxSizer_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxSizer.h"


AMI_DECLARE_TYPE(wxBoxSizer);

// TODO: check for inheritence ...
class WrapClass_wxBoxSizer : public WrapClass<wxBoxSizer>
    , public   WrapClass_wxSizer
{
  DEFINE_CLASS(WrapClass_wxBoxSizer);

  protected:
    typedef WrapClass<wxBoxSizer>::ptr _parentclass_ptr;
    typedef wxBoxSizer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBoxSizer>& GetObj() const { return WrapClass<wxBoxSizer>::GetObj(); }

    /// Constructor
    WrapClass_wxBoxSizer(boost::shared_ptr<wxBoxSizer > si): 
    WrapClass<wxBoxSizer>(si)
    , WrapClass_wxSizer(si)
    {}

    /// Destructor
    ~WrapClass_wxBoxSizer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBoxSizer_1,"Constructor wxBoxSizer::wxBoxSizer(wxBoxSizer const & param0) (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#wxboxsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBoxSizer,"Constructor wxBoxSizer::wxBoxSizer() (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#wxboxsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBoxSizer_2,"Constructor wxBoxSizer::wxBoxSizer(int orient) (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#wxboxsizer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBoxSizer*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(AddSpacer,"wxSizerItem * wxBoxSizer::AddSpacer(int size)  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#addspacer)")
    ADD_CLASS_METHOD(GetOrientation,"int wxBoxSizer::GetOrientation()  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#getorientation)")
    ADD_CLASS_METHOD(IsVertical,"bool wxBoxSizer::IsVertical()  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#isvertical)")
    ADD_CLASS_METHOD(SetOrientation,"void wxBoxSizer::SetOrientation(int orient)  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#setorientation)")
    ADD_CLASS_METHOD(CalcMin,"wxSize wxBoxSizer::CalcMin()  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#calcmin)")
    ADD_CLASS_METHOD(RecalcSizes,"void wxBoxSizer::RecalcSizes()  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#recalcsizes)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxBoxSizer::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxBoxSizer & wxBoxSizer::=(wxBoxSizer const & param0) (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#__assign__)")




    void AddMethods(WrapClass<wxBoxSizer>::ptr this_ptr );

};


#endif // _wrap_wxBoxSizer_h
