/**
 * C++ Interface: wrap_wxIconLocationBase
 *
 * Description: wrapping wxIconLocationBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxIconLocationBase_h_
#define _wrap_wxIconLocationBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxIconLocationBase);

// TODO: check for inheritence ...
class WrapClass_wxIconLocationBase : public WrapClass<wxIconLocationBase>
    
{
  DEFINE_CLASS(WrapClass_wxIconLocationBase);

  protected:
    typedef WrapClass<wxIconLocationBase>::ptr _parentclass_ptr;
    typedef wxIconLocationBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxIconLocationBase>& GetObj() const { return WrapClass<wxIconLocationBase>::GetObj(); }

    /// Constructor
    WrapClass_wxIconLocationBase(boost::shared_ptr<wxIconLocationBase > si): 
    WrapClass<wxIconLocationBase>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxIconLocationBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconLocationBase_1,"Constructor wxIconLocationBase::wxIconLocationBase(wxIconLocationBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxiconlocationbase.html#wxiconlocationbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconLocationBase,"Constructor wxIconLocationBase::wxIconLocationBase() (http://docs.wxwidgets.org/stable/wx_wxiconlocationbase.html#wxiconlocationbase).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxIconLocationBase_2,"Constructor wxIconLocationBase::wxIconLocationBase(wxString const & filename = wxEmptyString) (http://docs.wxwidgets.org/stable/wx_wxiconlocationbase.html#wxiconlocationbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxIconLocationBase*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(IsOk,"bool wxIconLocationBase::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxiconlocationbase.html#isok)")
    ADD_CLASS_METHOD(SetFileName,"void wxIconLocationBase::SetFileName(wxString const & filename)  (http://docs.wxwidgets.org/stable/wx_wxiconlocationbase.html#setfilename)")
    ADD_CLASS_METHOD(GetFileName,"wxString const & wxIconLocationBase::GetFileName()  (http://docs.wxwidgets.org/stable/wx_wxiconlocationbase.html#getfilename)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxIconLocationBase & wxIconLocationBase::operator =(wxIconLocationBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxiconlocationbase.html#__assign__)")




    void AddMethods(WrapClass<wxIconLocationBase>::ptr this_ptr );

};


#endif // _wrap_wxIconLocationBase_h
