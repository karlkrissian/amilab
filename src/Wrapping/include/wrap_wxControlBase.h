/**
 * C++ Interface: wrap_wxControlBase
 *
 * Description: wrapping wxControlBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxControlBase_h_
#define _wrap_wxControlBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWindow.h"


AMI_DECLARE_TYPE(wxControlBase);

// TODO: check for inheritence ...
class WrapClass_wxControlBase : public WrapClass<wxControlBase>
    , public  WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxControlBase);

  protected:
    typedef WrapClass<wxControlBase>::ptr _parentclass_ptr;
    typedef wxControlBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxControlBase>& GetObj() const { return WrapClass<wxControlBase>::GetObj(); }

    /// Constructor
    WrapClass_wxControlBase(boost::shared_ptr<wxControlBase > si): 
    WrapClass<wxControlBase>(si)
    , WrapClass_wxWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxControlBase()
    {
      std::cout << "~WrapClass_wxControlBase()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxControlBase,"Wrapping of wxControlBase, http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#wxcontrolbase.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxControlBase*);

    // here add each method
    
    // Adding standard methods
/* The following types are missing: wxValidator
    ADD_CLASS_METHOD(Create,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#create")
*/
    ADD_CLASS_METHOD(GetAlignment,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#getalignment")
    ADD_CLASS_METHOD(GetLabelText1,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#getlabeltext")
    ADD_CLASS_METHOD(GetLabelText,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#getlabeltext")
    ADD_CLASS_METHOD(GetLabelText2,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#getlabeltext")
    ADD_CLASS_METHOD(ShouldInheritColours,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#shouldinheritcolours")
/* The following types are missing: wxCommandEvent
    ADD_CLASS_METHOD(Command,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#command")
*/
    ADD_CLASS_METHOD(SetLabel,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#setlabel")
    ADD_CLASS_METHOD(SetFont,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#setfont")
/* The following types are missing: wxUpdateUIEvent
    ADD_CLASS_METHOD(DoUpdateWindowUI,"http://docs.wxwidgets.org/stable/wx_wxcontrolbase.html#doupdatewindowui")
*/





    void AddMethods(WrapClass<wxControlBase>::ptr this_ptr )
    {
      // here inheritence
      
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_wxWindow(        boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));
      parent_wxWindow->AddMethods(parent_wxWindow);


      // check that the method name is not a token
      
       // Adding standard methods 
/* The following types are missing: wxValidator
      AddVar_Create( this_ptr);
*/
      AddVar_GetAlignment( this_ptr);
      AddVar_GetLabelText1( this_ptr);
      AddVar_GetLabelText( this_ptr);
      AddVar_GetLabelText2( this_ptr);
      AddVar_ShouldInheritColours( this_ptr);
/* The following types are missing: wxCommandEvent
      AddVar_Command( this_ptr);
*/
      AddVar_SetLabel( this_ptr);
      AddVar_SetFont( this_ptr);
/* The following types are missing: wxUpdateUIEvent
      AddVar_DoUpdateWindowUI( this_ptr);
*/


    };
};


#endif // _wrap_wxControlBase_h
