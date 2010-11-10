/**
 * C++ Interface: wrap_wxAuiToolBarItem
 *
 * Description: wrapping wxAuiToolBarItem
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiToolBarItem_h_
#define _wrap_wxAuiToolBarItem_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/aui/aui.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxAuiToolBarItem);

// TODO: check for inheritence ...
class WrapClass_wxAuiToolBarItem : public WrapClass<wxAuiToolBarItem>
    
{
  DEFINE_CLASS(WrapClass_wxAuiToolBarItem);

  protected:
    typedef WrapClass<wxAuiToolBarItem>::ptr _parentclass_ptr;
    typedef wxAuiToolBarItem ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiToolBarItem>& GetObj() const { return WrapClass<wxAuiToolBarItem>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiToolBarItem(boost::shared_ptr<wxAuiToolBarItem > si): 
    WrapClass<wxAuiToolBarItem>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAuiToolBarItem()
    {
      std::cout << "~WrapClass_wxAuiToolBarItem()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItem,"Wrapping of wxAuiToolBarItem.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItem1,"Wrapping of wxAuiToolBarItem.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiToolBarItem*);

    // here add each method
    
    ADD_CLASS_METHOD(Assign,"")
    ADD_CLASS_METHOD(SetWindow,"")
    ADD_CLASS_METHOD(GetWindow,"")
    ADD_CLASS_METHOD(SetId,"")
    ADD_CLASS_METHOD(GetId,"")
    ADD_CLASS_METHOD(SetKind,"")
    ADD_CLASS_METHOD(GetKind,"")
    ADD_CLASS_METHOD(SetState,"")
    ADD_CLASS_METHOD(GetState,"")
/* The following types are missing: wxSizerItem
    ADD_CLASS_METHOD(SetSizerItem,"")
*/
/* The following types are missing: wxSizerItem
    ADD_CLASS_METHOD(GetSizerItem,"")
*/
    ADD_CLASS_METHOD(SetLabel,"")
    ADD_CLASS_METHOD(GetLabel,"")
    ADD_CLASS_METHOD(SetBitmap,"")
    ADD_CLASS_METHOD(GetBitmap,"")
    ADD_CLASS_METHOD(SetDisabledBitmap,"")
    ADD_CLASS_METHOD(GetDisabledBitmap,"")
    ADD_CLASS_METHOD(SetHoverBitmap,"")
    ADD_CLASS_METHOD(GetHoverBitmap,"")
    ADD_CLASS_METHOD(SetShortHelp,"")
    ADD_CLASS_METHOD(GetShortHelp,"")
    ADD_CLASS_METHOD(SetLongHelp,"")
    ADD_CLASS_METHOD(GetLongHelp,"")
    ADD_CLASS_METHOD(SetMinSize,"")
    ADD_CLASS_METHOD(GetMinSize,"")
    ADD_CLASS_METHOD(SetSpacerPixels,"")
    ADD_CLASS_METHOD(GetSpacerPixels,"")
    ADD_CLASS_METHOD(SetProportion,"")
    ADD_CLASS_METHOD(GetProportion,"")
    ADD_CLASS_METHOD(SetActive,"")
    ADD_CLASS_METHOD(IsActive,"")
    ADD_CLASS_METHOD(SetHasDropDown,"")
    ADD_CLASS_METHOD(HasDropDown,"")
    ADD_CLASS_METHOD(SetSticky,"")
    ADD_CLASS_METHOD(IsSticky,"")
    ADD_CLASS_METHOD(SetUserData,"")
    ADD_CLASS_METHOD(GetUserData,"")

    // Operators:
    ADD_CLASS_METHOD(assign,"")




    void AddMethods(WrapClass<wxAuiToolBarItem>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      
      AddVar_Assign( this_ptr);
      AddVar_SetWindow( this_ptr);
      AddVar_GetWindow( this_ptr);
      AddVar_SetId( this_ptr);
      AddVar_GetId( this_ptr);
      AddVar_SetKind( this_ptr);
      AddVar_GetKind( this_ptr);
      AddVar_SetState( this_ptr);
      AddVar_GetState( this_ptr);
/* The following types are missing: wxSizerItem
      AddVar_SetSizerItem( this_ptr);
*/
/* The following types are missing: wxSizerItem
      AddVar_GetSizerItem( this_ptr);
*/
      AddVar_SetLabel( this_ptr);
      AddVar_GetLabel( this_ptr);
      AddVar_SetBitmap( this_ptr);
      AddVar_GetBitmap( this_ptr);
      AddVar_SetDisabledBitmap( this_ptr);
      AddVar_GetDisabledBitmap( this_ptr);
      AddVar_SetHoverBitmap( this_ptr);
      AddVar_GetHoverBitmap( this_ptr);
      AddVar_SetShortHelp( this_ptr);
      AddVar_GetShortHelp( this_ptr);
      AddVar_SetLongHelp( this_ptr);
      AddVar_GetLongHelp( this_ptr);
      AddVar_SetMinSize( this_ptr);
      AddVar_GetMinSize( this_ptr);
      AddVar_SetSpacerPixels( this_ptr);
      AddVar_GetSpacerPixels( this_ptr);
      AddVar_SetProportion( this_ptr);
      AddVar_GetProportion( this_ptr);
      AddVar_SetActive( this_ptr);
      AddVar_IsActive( this_ptr);
      AddVar_SetHasDropDown( this_ptr);
      AddVar_HasDropDown( this_ptr);
      AddVar_SetSticky( this_ptr);
      AddVar_IsSticky( this_ptr);
      AddVar_SetUserData( this_ptr);
      AddVar_GetUserData( this_ptr);

      // Operators:
      AddVar_assign( this_ptr);


    };
};


#endif // _wrap_wxAuiToolBarItem_h
