//
// C++ Interface: wrap_FenetreDessin
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_FenetreDessin_h_
#define _wrap_FenetreDessin_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrap_wxFrame.h"

#include "FenetreDessin.hpp"

AMI_DECLARE_TYPE(FenetreDessin);

class WrapClass_FenetreDessin : public WrapClass<FenetreDessin>, public WrapClass_wxFrame
{
  DEFINE_CLASS(WrapClass_FenetreDessin);

  protected:  
    // for nested classes
    typedef WrapClass<FenetreDessin>::ptr _parentclass_ptr;
    typedef FenetreDessin ObjectType;

  public:

    /// Constructor
    WrapClass_FenetreDessin(boost::shared_ptr<FenetreDessin> si):  WrapClass<FenetreDessin>(si), WrapClass_wxFrame(si)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(FenetreDessin, "Wrapping of FenetreDessin." );

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( FenetreDessin*);

    ADD_CLASS_METHOD(DrawingAreaDisplay, "Updates the display of the Drawing Area.");
    ADD_CLASS_METHOD(SetPenColor,        "Sets the color of the drawing pen.");
    ADD_CLASS_METHOD(SetLineParameters,  "Sets the parameters of the line.");

    // wrapping of other methods
    ADD_CLASS_METHOD(GetDrawingWindow,"Returns the drawing window as a wxWindow.");

    void AddMethods(WrapClass<FenetreDessin>::ptr this_ptr )
    {

      AddVar_DrawingAreaDisplay( this_ptr);
      AddVar_SetPenColor(        this_ptr);
      AddVar_SetLineParameters(  this_ptr);
      AddVar_GetDrawingWindow(   this_ptr);

/*      // Add members from wxWindow
      WrapClass_wxFrame::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxFrame>(this_ptr));
      parent_obj->AddMethods(parent_obj);*/
      
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



#endif // _wrap_FenetreDessin_h_
