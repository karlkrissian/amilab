/**
 * C++ Interface: wrap_wxFrame
 *
 * Description: wrapping wxFrame
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFrame_h_
#define _wrap_wxFrame_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

//#include "wrap_wxFrameBase.h"


AMI_DECLARE_TYPE(wxFrame);

// TODO: check for inheritence ...
class WrapClass_wxFrame : public WrapClass<wxFrame>
    //, public virtual WrapClass_wxFrameBase
{
  DEFINE_CLASS(WrapClass_wxFrame);

  protected:
    typedef WrapClass<wxFrame>::ptr _parentclass_ptr;
    typedef wxFrame ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFrame>& GetObj() const { return WrapClass<wxFrame>::GetObj(); }

    /// Constructor
    WrapClass_wxFrame(boost::shared_ptr<wxFrame > si): 
    WrapClass<wxFrame>(si)
    //, WrapClass_wxFrameBase(si)
    {}

    /// Destructor
    ~WrapClass_wxFrame()
    {
      std::cout << "~WrapClass_wxFrame()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrame1,"Wrapping of wxFrame.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrame,"Wrapping of wxFrame.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrame2,"Wrapping of wxFrame.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFrame*);

    // here add each method
    
    ADD_CLASS_METHOD(Create,"")
/* The following types are missing: wxStatusBar
    ADD_CLASS_METHOD(CreateStatusBar,"")
*/
/* The following types are missing: wxStatusBar
    ADD_CLASS_METHOD(SetStatusBar,"")
*/
/* The following types are missing: wxToolBar
    ADD_CLASS_METHOD(CreateToolBar,"")
*/
/* The following types are missing: wxToolBar
    ADD_CLASS_METHOD(SetToolBar,"")
*/
    ADD_CLASS_METHOD(GetClientAreaOrigin,"")
    ADD_CLASS_METHOD(GtkOnSize,"")
    ADD_CLASS_METHOD(OnInternalIdle,"")
    ADD_CLASS_METHOD(UpdateMenuBarSize,"")
    ADD_CLASS_METHOD(GetClassInfo,"")
    ADD_CLASS_METHOD(wxCreateObject,"")





    void AddMethods(WrapClass<wxFrame>::ptr this_ptr )
    {
      // here inheritence
      /*
      // Add members from wxFrameBase
      WrapClass_wxFrameBase::ptr parent_wxFrameBase(        boost::dynamic_pointer_cast<WrapClass_wxFrameBase>(this_ptr));
      parent_wxFrameBase->AddMethods(parent_wxFrameBase);
      */


      // check that the method name is not a token
      
      AddVar_Create( this_ptr);
/* The following types are missing: wxStatusBar
      AddVar_CreateStatusBar( this_ptr);
*/
/* The following types are missing: wxStatusBar
      AddVar_SetStatusBar( this_ptr);
*/
/* The following types are missing: wxToolBar
      AddVar_CreateToolBar( this_ptr);
*/
/* The following types are missing: wxToolBar
      AddVar_SetToolBar( this_ptr);
*/
      AddVar_GetClientAreaOrigin( this_ptr);
      AddVar_GtkOnSize( this_ptr);
      AddVar_OnInternalIdle( this_ptr);
      AddVar_UpdateMenuBarSize( this_ptr);
      AddVar_GetClassInfo( this_ptr);
      AddVar_wxCreateObject( this_ptr);



    };
};


#endif // _wrap_wxFrame_h
