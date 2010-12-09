/**
 * C++ Interface: wrap_wxStdDialogButtonSizer
 *
 * Description: wrapping wxStdDialogButtonSizer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxStdDialogButtonSizer_h_
#define _wrap_wxStdDialogButtonSizer_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxBoxSizer.h"



AMI_DECLARE_TYPE(wxStdDialogButtonSizer);

// TODO: check for inheritence ...
class WrapClass_wxStdDialogButtonSizer : public WrapClass<wxStdDialogButtonSizer>
    , public   WrapClass_wxBoxSizer
{
  DEFINE_CLASS(WrapClass_wxStdDialogButtonSizer);

  protected:
    typedef WrapClass<wxStdDialogButtonSizer>::ptr _parentclass_ptr;
    typedef wxStdDialogButtonSizer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxStdDialogButtonSizer>& GetObj() const { return WrapClass<wxStdDialogButtonSizer>::GetObj(); }

    /// Constructor
    WrapClass_wxStdDialogButtonSizer(boost::shared_ptr<wxStdDialogButtonSizer > si): 
    WrapClass<wxStdDialogButtonSizer>(si)
    , WrapClass_wxBoxSizer(si)
    {}

    /// Destructor
    ~WrapClass_wxStdDialogButtonSizer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStdDialogButtonSizer,"Constructor wxStdDialogButtonSizer::wxStdDialogButtonSizer() (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#wxstddialogbuttonsizer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStdDialogButtonSizer*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(AddButton,"void wxStdDialogButtonSizer::AddButton(wxButton * button)  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#addbutton)")
    ADD_CLASS_METHOD(SetAffirmativeButton,"void wxStdDialogButtonSizer::SetAffirmativeButton(wxButton * button)  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#setaffirmativebutton)")
    ADD_CLASS_METHOD(SetNegativeButton,"void wxStdDialogButtonSizer::SetNegativeButton(wxButton * button)  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#setnegativebutton)")
    ADD_CLASS_METHOD(SetCancelButton,"void wxStdDialogButtonSizer::SetCancelButton(wxButton * button)  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#setcancelbutton)")
    ADD_CLASS_METHOD(Realize,"void wxStdDialogButtonSizer::Realize()  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#realize)")
    ADD_CLASS_METHOD(GetAffirmativeButton,"wxButton * wxStdDialogButtonSizer::GetAffirmativeButton()  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#getaffirmativebutton)")
    ADD_CLASS_METHOD(GetApplyButton,"wxButton * wxStdDialogButtonSizer::GetApplyButton()  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#getapplybutton)")
    ADD_CLASS_METHOD(GetNegativeButton,"wxButton * wxStdDialogButtonSizer::GetNegativeButton()  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#getnegativebutton)")
    ADD_CLASS_METHOD(GetCancelButton,"wxButton * wxStdDialogButtonSizer::GetCancelButton()  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#getcancelbutton)")
    ADD_CLASS_METHOD(GetHelpButton,"wxButton * wxStdDialogButtonSizer::GetHelpButton()  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#gethelpbutton)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxStdDialogButtonSizer::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxstddialogbuttonsizer.html#getclassinfo)")





    void AddMethods(WrapClass<wxStdDialogButtonSizer>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxStdDialogButtonSizer_h
