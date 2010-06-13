//
// C++ Interface: wrap_wxEditor
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxEditor_h_
#define _wrap_wxEditor_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrap_wxWindow.h"

#include "wxEditor.h"

class WrapClass_wxEditor : public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxEditor);

  // for nested classes
  typedef WrapClass_wxEditor::ptr _parentclass_ptr;
  typedef wxEditor _obj_type;

  public:
    boost::shared_ptr<_obj_type> _obj;
    const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }

    /// Constructor
    WrapClass_wxEditor(boost::shared_ptr<wxEditor> si):  WrapClass_wxWindow(si), _obj(si)
    {}

    ADD_CLASS_METHOD(LoadFile,          "Loads a file in the editor.");
    ADD_CLASS_METHOD(ShowLineNumbers,   "Shows/Hides line numbers.");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      AddVar_LoadFile(         this_ptr);
      AddVar_ShowLineNumbers(  this_ptr);
    }

};

/**
 * Create a Wrapped object around _wxEditor
 * @param objectptr input smart pointer to a WrapClass_wxEditor
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_wxEditor(  WrapClass_wxEditor::ptr& objectptr);

/**
 * Create a Wrapped object around _wxEditor
 * @param si input smart pointer to a _wxEditor
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_wxEditor( wxEditor* si);

/** Method that adds wrapping of wxEditor 
 */
ADD_CLASS_FUNCTION( wxEditor, "Wrapping of wxEditor." );


#endif // _wrap_wxEditor_h_
