//
// C++ Interface: wrap_wxStcFrame
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxStcFrame_h_
#define _wrap_wxStcFrame_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrap_wxWindow.h"

#include "wxStcFrame.h"

AMI_DECLARE_TYPE(wxStcFrame)

class WrapClass_wxStcFrame : public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxStcFrame);

  // for nested classes
  typedef WrapClass_wxStcFrame::ptr _parentclass_ptr;
  typedef wxStcFrame _obj_type;

  public:
    boost::shared_ptr<_obj_type> _obj;
    const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }

    /// Constructor
    WrapClass_wxStcFrame(boost::shared_ptr<wxStcFrame> si):  WrapClass_wxWindow(si), _obj(si)
    {}

    ADD_CLASS_METHOD(GetActiveEditor,   "Gets the active editor window as a wxEditor object.");
    ADD_CLASS_METHOD(FileOpen,          "Opens the given file.");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      AddVar_GetActiveEditor(  this_ptr);
      AddVar_FileOpen(         this_ptr);
    }

};

/**
 * Create a Wrapped object around _wxStcFrame
 * @param objectptr input smart pointer to a WrapClass_wxStcFrame
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_wxStcFrame(  WrapClass_wxStcFrame::ptr& objectptr);

/**
 * Create a Wrapped object around _wxStcFrame
 * @param si input smart pointer to a _wxStcFrame
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_wxStcFrame( wxStcFrame* si);

/** Method that adds wrapping of wxStcFrame 
 */
ADD_CLASS_FUNCTION( wxStcFrame, "Wrapping of wxStcFrame." );


#endif // _wrap_wxStcFrame_h_
