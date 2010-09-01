//
// C++ Interface: wrap_MainFrame
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_MainFrame_h_
#define _wrap_MainFrame_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrap_wxWindow.h"

#include "MainFrame.h"

AMI_DECLARE_TYPE(MainFrame)

class WrapClass_MainFrame : public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_MainFrame);

  // for nested classes
  typedef WrapClass_MainFrame::ptr _parentclass_ptr;
  typedef MainFrame _obj_type;

  public:
    boost::shared_ptr<_obj_type> _obj;
    const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }

    /// Constructor
    WrapClass_MainFrame(boost::shared_ptr<MainFrame> si):  WrapClass_wxWindow(si), _obj(si)
    {}

    ADD_CLASS_METHOD(GetAmilabEditor,  "Opens or get the amilab editor frame.");
    ADD_CLASS_METHOD(AddMenuScript,    "Adds a new link to a script from the 'Scripts' menu.");
    ADD_CLASS_METHOD(AddToMenu,        "Adds a new link to a script from any menu.");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));

      parent_obj->AddMethods(parent_obj);

      AddVar_GetAmilabEditor(  this_ptr);
      AddVar_AddMenuScript(    this_ptr);
      AddVar_AddToMenu(        this_ptr);
    }

};

/**
 * Create a Wrapped object and adds all the members around MainFrame
 * @param objectptr input MainFrame pointer
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_MainFrame( MainFrame* si );

/**
 * Create a Wrapped object around _MainFrame
 * @param si input smart pointer to a _MainFrame
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_MainFrame( MainFrame* si);

/** Method that adds wrapping of MainFrame 
 */
ADD_CLASS_FUNCTION( MainFrame, "Wrapping of MainFrame, this object cannot be constructed from scratch ..." );


#endif // _wrap_MainFrame_h_
