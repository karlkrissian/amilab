/**
 * C++ Interface: wrap_wxMessageDialog
 *
 * Description: wrapping wxMessageDialog
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMessageDialog_h_
#define _wrap_wxMessageDialog_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxDialog.h"
#include "wrap_wxMessageDialogBase.h"


#ifndef wxMessageDialog_declared
  #define wxMessageDialog_declared
  AMI_DECLARE_TYPE(wxMessageDialog);
#endif

// TODO: check for inheritence ...
class WrapClass_wxMessageDialog : public WrapClass<wxMessageDialog>
    , public   WrapClass_wxDialog, public   WrapClass_wxMessageDialogBase
{
  DEFINE_CLASS(WrapClass_wxMessageDialog);

  protected:
    typedef WrapClass<wxMessageDialog>::ptr _parentclass_ptr;
    typedef wxMessageDialog ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMessageDialog>& GetObj() const { return WrapClass<wxMessageDialog>::GetObj(); }

    /// Constructor
    WrapClass_wxMessageDialog(boost::shared_ptr<wxMessageDialog > si): 
    WrapClass<wxMessageDialog>(si)
    , WrapClass_wxDialog(si), WrapClass_wxMessageDialogBase(si)
    {}

    /// Destructor
    ~WrapClass_wxMessageDialog()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMessageDialog,"Constructor wxMessageDialog::wxMessageDialog(wxWindow * parent, wxString const & message, wxString const & caption = wxMessageBoxCaptionStr, long int style = 5, wxPoint const & pos = wxDefaultPosition) (http://docs.wxwidgets.org/stable/wx_wxmessagedialog.html#wxmessagedialog).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMessageDialog*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(ShowModal,"int wxMessageDialog::ShowModal()  (http://docs.wxwidgets.org/stable/wx_wxmessagedialog.html#showmodal)")
    ADD_CLASS_METHOD(Show,"bool wxMessageDialog::Show(bool param0 = true)  (http://docs.wxwidgets.org/stable/wx_wxmessagedialog.html#show)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxMessageDialog::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxmessagedialog.html#getclassinfo)")





    void AddMethods(WrapClass<wxMessageDialog>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxMessageDialog_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxMessageDialog_h
