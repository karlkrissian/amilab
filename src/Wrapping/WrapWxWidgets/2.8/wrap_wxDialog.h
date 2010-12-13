/**
 * C++ Interface: wrap_wxDialog
 *
 * Description: wrapping wxDialog
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDialog_h_
#define _wrap_wxDialog_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxDialogBase.h"


#ifndef wxDialog_declared
  #define wxDialog_declared
  AMI_DECLARE_TYPE(wxDialog);
#endif

// TODO: check for inheritence ...
class WrapClass_wxDialog : public WrapClass<wxDialog>
    , public   WrapClass_wxDialogBase
{
  DEFINE_CLASS(WrapClass_wxDialog);

  protected:
    typedef WrapClass<wxDialog>::ptr _parentclass_ptr;
    typedef wxDialog ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDialog>& GetObj() const { return WrapClass<wxDialog>::GetObj(); }

    /// Constructor
    WrapClass_wxDialog(boost::shared_ptr<wxDialog > si): 
    WrapClass<wxDialog>(si)
    , WrapClass_wxDialogBase(si)
    {}

    /// Destructor
    ~WrapClass_wxDialog()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDialog_1,"Constructor wxDialog::wxDialog() (http://docs.wxwidgets.org/stable/wx_wxdialog.html#wxdialog).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDialog,"Constructor wxDialog::wxDialog() (http://docs.wxwidgets.org/stable/wx_wxdialog.html#wxdialog).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxDialog_2,"Constructor wxDialog::wxDialog(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 536877056, wxString const & name = wxDialogNameStr) (http://docs.wxwidgets.org/stable/wx_wxdialog.html#wxdialog).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDialog*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxDialog::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 536877056, wxString const & name = wxDialogNameStr)  (http://docs.wxwidgets.org/stable/wx_wxdialog.html#create)")
    ADD_CLASS_METHOD(Show,"bool wxDialog::Show(bool show = 1)  (http://docs.wxwidgets.org/stable/wx_wxdialog.html#show)")
    ADD_CLASS_METHOD(ShowModal,"int wxDialog::ShowModal()  (http://docs.wxwidgets.org/stable/wx_wxdialog.html#showmodal)")
    ADD_CLASS_METHOD(EndModal,"void wxDialog::EndModal(int retCode)  (http://docs.wxwidgets.org/stable/wx_wxdialog.html#endmodal)")
    ADD_CLASS_METHOD(IsModal,"bool wxDialog::IsModal()  (http://docs.wxwidgets.org/stable/wx_wxdialog.html#ismodal)")
    ADD_CLASS_METHOD(SetModal,"void wxDialog::SetModal(bool modal)  (http://docs.wxwidgets.org/stable/wx_wxdialog.html#setmodal)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxDialog::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxdialog.html#getclassinfo)")





    void AddMethods(WrapClass<wxDialog>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDialog_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxDialog_h
