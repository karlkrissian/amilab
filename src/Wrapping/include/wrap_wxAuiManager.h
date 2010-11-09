/**
 * C++ Interface: wrap_wxAuiManager
 *
 * Description: wrapping wxAuiManager
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiManager_h_
#define _wrap_wxAuiManager_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/aui/aui.h"

// include what is needed for inheritence and for types ...
//#include "wrap_BaseClass1.h"
//#include "wrap_BaseClass2.h"
// ...


AMI_DECLARE_TYPE(wxAuiManager);

// TODO: check for inheritence ...
class WrapClass_wxAuiManager : public WrapClass<wxAuiManager>
// inheritence, public virtual WrapClass_BaseClass1, ...
{
  DEFINE_CLASS(WrapClass_wxAuiManager);

  protected:
    typedef WrapClass<wxAuiManager>::ptr _parentclass_ptr;
    typedef wxAuiManager ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiManager>& GetObj() const { return WrapClass<wxAuiManager>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiManager(boost::shared_ptr<wxAuiManager > si): 
    // inheritence WrapClass_BaseClass1(si), ... 
    WrapClass<wxAuiManager>(si)
    {}

    /// Destructor
    ~WrapClass_wxAuiManager()
    {
      std::cout << "~WrapClass_wxAuiManager()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiManager,"Wrapping of $wxAuiManager.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiManager*);

    // here add each method
    
    ADD_CLASS_METHOD(UnInit,"")
    ADD_CLASS_METHOD(SetFlags,"")
    ADD_CLASS_METHOD(GetFlags,"")
    ADD_CLASS_METHOD(SetManagedWindow,"")
    ADD_CLASS_METHOD(GetManagedWindow,"")
    ADD_CLASS_METHOD(GetManager,"")
/* The following types are missing: wxAuiDockArt
    ADD_CLASS_METHOD(SetArtProvider,"")
*/
/* The following types are missing: wxAuiDockArt
    ADD_CLASS_METHOD(GetArtProvider,"")
*/
    ADD_CLASS_METHOD(GetPane,"")
    ADD_CLASS_METHOD(GetPane1,"")
/* The following types are missing: wxAuiPaneInfoArray
    ADD_CLASS_METHOD(GetAllPanes,"")
*/
    ADD_CLASS_METHOD(AddPane,"")
    ADD_CLASS_METHOD(AddPane1,"")
    ADD_CLASS_METHOD(AddPane2,"")
    ADD_CLASS_METHOD(InsertPane,"")
    ADD_CLASS_METHOD(DetachPane,"")
    ADD_CLASS_METHOD(Update,"")
    ADD_CLASS_METHOD(SavePaneInfo,"")
    ADD_CLASS_METHOD(LoadPaneInfo,"")
    ADD_CLASS_METHOD(SavePerspective,"")
    ADD_CLASS_METHOD(LoadPerspective,"")
    ADD_CLASS_METHOD(SetDockSizeConstraint,"")
    ADD_CLASS_METHOD(GetDockSizeConstraint,"")
    ADD_CLASS_METHOD(ClosePane,"")
    ADD_CLASS_METHOD(MaximizePane,"")
    ADD_CLASS_METHOD(RestorePane,"")
    ADD_CLASS_METHOD(RestoreMaximizedPane,"")
/* The following types are missing: wxAuiFloatingFrame
    ADD_CLASS_METHOD(CreateFloatingFrame,"")
*/
    ADD_CLASS_METHOD(StartPaneDrag,"")
    ADD_CLASS_METHOD(CalculateHintRect,"")
    ADD_CLASS_METHOD(DrawHintRect,"")
    ADD_CLASS_METHOD(ShowHint,"")
    ADD_CLASS_METHOD(HideHint,"")
    ADD_CLASS_METHOD(SetFrame,"")
    ADD_CLASS_METHOD(GetFrame,"")
/* The following types are missing: wxAuiManagerEvent
    ADD_CLASS_METHOD(OnRender,"")
*/
/* The following types are missing: wxAuiManagerEvent
    ADD_CLASS_METHOD(OnPaneButton,"")
*/
/* The following types are missing: wxClassInfo
    ADD_CLASS_METHOD(GetClassInfo,"")
*/
/* The following types are missing: wxObject
    ADD_CLASS_METHOD(wxCreateObject,"")
*/




    void AddMethods(WrapClass<wxAuiManager>::ptr this_ptr )
    {
      // here inheritence
      // Add members from wxWindow
      //WrapClass_BaseClass1::ptr parent_obj(
      //  boost::dynamic_pointer_cast<WrapClass_BaseClass1>(this_ptr));
      //parent_obj->AddMethods(parent_obj);

      // check that the method name is not a token
      
      AddVar_UnInit( this_ptr);
      AddVar_SetFlags( this_ptr);
      AddVar_GetFlags( this_ptr);
      AddVar_SetManagedWindow( this_ptr);
      AddVar_GetManagedWindow( this_ptr);
      AddVar_GetManager( this_ptr);
/* The following types are missing: wxAuiDockArt
      AddVar_SetArtProvider( this_ptr);
*/
/* The following types are missing: wxAuiDockArt
      AddVar_GetArtProvider( this_ptr);
*/
      AddVar_GetPane( this_ptr);
      AddVar_GetPane1( this_ptr);
/* The following types are missing: wxAuiPaneInfoArray
      AddVar_GetAllPanes( this_ptr);
*/
      AddVar_AddPane( this_ptr);
      AddVar_AddPane1( this_ptr);
      AddVar_AddPane2( this_ptr);
      AddVar_InsertPane( this_ptr);
      AddVar_DetachPane( this_ptr);
      AddVar_Update( this_ptr);
      AddVar_SavePaneInfo( this_ptr);
      AddVar_LoadPaneInfo( this_ptr);
      AddVar_SavePerspective( this_ptr);
      AddVar_LoadPerspective( this_ptr);
      AddVar_SetDockSizeConstraint( this_ptr);
      AddVar_GetDockSizeConstraint( this_ptr);
      AddVar_ClosePane( this_ptr);
      AddVar_MaximizePane( this_ptr);
      AddVar_RestorePane( this_ptr);
      AddVar_RestoreMaximizedPane( this_ptr);
/* The following types are missing: wxAuiFloatingFrame
      AddVar_CreateFloatingFrame( this_ptr);
*/
      AddVar_StartPaneDrag( this_ptr);
      AddVar_CalculateHintRect( this_ptr);
      AddVar_DrawHintRect( this_ptr);
      AddVar_ShowHint( this_ptr);
      AddVar_HideHint( this_ptr);
      AddVar_SetFrame( this_ptr);
      AddVar_GetFrame( this_ptr);
/* The following types are missing: wxAuiManagerEvent
      AddVar_OnRender( this_ptr);
*/
/* The following types are missing: wxAuiManagerEvent
      AddVar_OnPaneButton( this_ptr);
*/
/* The following types are missing: wxClassInfo
      AddVar_GetClassInfo( this_ptr);
*/
/* The following types are missing: wxObject
      AddVar_wxCreateObject( this_ptr);
*/


    };
};


#endif // _wrap_wxAuiManager_h
