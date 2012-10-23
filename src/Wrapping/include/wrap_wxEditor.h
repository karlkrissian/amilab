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
#include "wrap_wxStyledTextCtrl.h"

#include "wxEditor.h"

AMI_DECLARE_TYPE(wxEditor)

class WrapClass_wxEditor : public WrapClass<wxEditor>, public WrapClass_wxStyledTextCtrl
{
  DEFINE_CLASS(WrapClass_wxEditor);

  protected: 
    // for nested classes
    typedef WrapClass<wxEditor>::ptr _parentclass_ptr;
    typedef wxEditor ObjectType;

  public:
    /// Constructor
    WrapClass_wxEditor(boost::shared_ptr<wxEditor> si):  WrapClass<wxEditor>(si), WrapClass_wxStyledTextCtrl(si)
    {}

    /// Constructor const
    WrapClass_wxEditor(boost::shared_ptr<wxEditor const> si,bool):  
      WrapClass<wxEditor>(si,true), 
      WrapClass_wxStyledTextCtrl(si,true)
    {}

    std::string ObjPointerAsString() { return "wxEditor"; }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxEditor, "Wrapping of wxEditor." )

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxEditor*);

    ADD_CLASS_METHOD(LoadFile,          "Loads a file in the editor.");
    ADD_CLASS_METHOD(ShowLineNumbers,   "Shows/Hides line numbers.");

    void AddMethods(WrapClass<wxEditor>::ptr this_ptr )
    {

      AddVar_LoadFile(         this_ptr);
      AddVar_ShowLineNumbers(  this_ptr);

      // Add public fields 
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());

      // Add base parent wxStyledTextCtrl
      boost::shared_ptr<wxStyledTextCtrl > parent_wxStyledTextCtrl(  boost::dynamic_pointer_cast<wxStyledTextCtrl >(this_ptr->GetObj()));
      BasicVariable::ptr var_wxStyledTextCtrl = AMILabType<wxStyledTextCtrl>::CreateVarFromSmtPtr(parent_wxStyledTextCtrl);
      context->AddVar("wxStyledTextCtrl",var_wxStyledTextCtrl);
      // Set as a default context
      Variable<AMIObject>::ptr obj_wxStyledTextCtrl = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxStyledTextCtrl);
      context->AddDefault(obj_wxStyledTextCtrl->Pointer()->GetContext());
      
      
    }

};



#endif // _wrap_wxEditor_h_
