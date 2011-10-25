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
#include "wrap_wxFrame.h"

#include "wxStcFrame.h"

AMI_DECLARE_TYPE(wxStcFrame)

class WrapClass_wxStcFrame : public WrapClass<wxStcFrame>, public WrapClass_wxFrame
{
  DEFINE_CLASS(WrapClass_wxStcFrame);

  protected:
    // for nested classes
    typedef WrapClass<wxStcFrame>::ptr _parentclass_ptr;
    typedef wxStcFrame ObjectType;

  public:

    /// Constructor
    WrapClass_wxStcFrame(boost::shared_ptr<wxStcFrame> si):  WrapClass<wxStcFrame>(si), WrapClass_wxFrame(si)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStcFrame, "Wrapping of wxStcFrame." )

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStcFrame*);

    ADD_CLASS_METHOD(GetActiveEditor,   "Gets the active editor window as a wxEditor object.");
    ADD_CLASS_METHOD(FileOpen,          "Opens the given file.");

    void AddMethods(WrapClass<wxStcFrame>::ptr this_ptr )
    {

      AddVar_GetActiveEditor(  this_ptr);
      AddVar_FileOpen(         this_ptr);

      // Add public fields 
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());

      // Add base parent wxFrame
      boost::shared_ptr<wxFrame > parent_wxFrame(  boost::dynamic_pointer_cast<wxFrame >(this_ptr->GetObj()));
      BasicVariable::ptr var_wxFrame = AMILabType<wxFrame>::CreateVarFromSmtPtr(parent_wxFrame);
      context->AddVar("wxFrame",var_wxFrame);
      // Set as a default context
      Variable<AMIObject>::ptr obj_wxFrame = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxFrame);
      context->AddDefault(obj_wxFrame->Pointer()->GetContext());
    }

};


#endif // _wrap_wxStcFrame_h_
