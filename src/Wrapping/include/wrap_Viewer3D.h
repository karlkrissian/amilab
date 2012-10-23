/**
 * C++ Interface: wrap_Viewer3D
 *
 * Description: wrapping Viewer3D
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_Viewer3D_h_
#define _wrap_Viewer3D_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "Viewer3D.hpp"
#include "wrap_wxFrame.h"
#include "wrap_SurfacePoly.h"
#include "wrap_GLTransfMatrix.h"

AMI_DECLARE_TYPE(Viewer3D);

class WrapClass_Viewer3D:  public WrapClass<Viewer3D>,  public  WrapClass_wxFrame
{
  DEFINE_CLASS(WrapClass_Viewer3D);

  protected:  
    // needed to resolve ambiguity from multiple inheritance
    typedef boost::shared_ptr<WrapClass<Viewer3D> > _parentclass_ptr;
    typedef Viewer3D ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<Viewer3D>& GetObj() const { return WrapClass<Viewer3D>::GetObj(); }

    /// Constructor
    WrapClass_Viewer3D(boost::shared_ptr<Viewer3D > si): WrapClass<Viewer3D>(si), WrapClass_wxFrame(si)
    { }

    /// Constructor const
    WrapClass_Viewer3D(boost::shared_ptr<Viewer3D const> si, bool): 
      WrapClass<Viewer3D>(si, true), 
      WrapClass_wxFrame(si, true)
    { }

    std::string ObjPointerAsString() { return "Viewer3D"; }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(Viewer3D, "Wrapping of Viewer3D." )

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( Viewer3D*);

    ADD_CLASS_METHOD(__reference__,         "Called each time a new reference of the variable is created: increases the list of variable to delete from their contexts when closing the window.");

    ADD_CLASS_METHOD(rotate,            "Applies a rotation to the objects displayed by the surface visualization window.");
    ADD_CLASS_METHOD(AddObject,         "Add a wrapped SurfacePoly object.");
    ADD_CLASS_METHOD(add_assign,        "Operator +=, add a new SurfacePoly object.");
    ADD_CLASS_METHOD(sub_assign,        "Operator -=, remove a existing SurfacePoly object.");
    ADD_CLASS_METHOD(Remove,            "Removes the surface without swapping the 3D buffer.");
    ADD_CLASS_METHOD(SwapBuffers,       "Swaps the 3D buffer");
    ADD_CLASS_METHOD(drawCCOnlyCC,      "Choose to draw only the specified connected component.");
    ADD_CLASS_METHOD(drawCC,            "Choose to draw or not a given connected component.");
    ADD_CLASS_METHOD(SetCurrentObj,     "The object indicated by the index becomes the current object.");
    ADD_CLASS_METHOD(compare,           "Put a comparison image for the imagedraw window specified by the parameters. The comparison image is displayed in a new window.");
    ADD_CLASS_METHOD(setvector,         "This command allows to set one of the vector fields, specified by the given number. The image parameter can display up to 2 vector fields.");
    ADD_CLASS_METHOD(ShowSection,       "Show free section (TODO)");
    ADD_CLASS_METHOD(HideSection,       "Hide free section (TODO)");
    ADD_CLASS_METHOD(PrintMatrices,     "TODO");
    ADD_CLASS_METHOD(SetTransform,      "Sets a given transform (defining a point of view) to the surface drawing window.");
    ADD_CLASS_METHOD(Paint,             "Calls the method 'Paint' of the surface drawing window, updating the scene information.");
    ADD_CLASS_METHOD(SetLightAmbient,   "Set the ambient RGB color for a given light. The initial light that is enable by default is light 0.");
    ADD_CLASS_METHOD(SetLightDiffuse,   "Set the diffuse RGB color for a given light. The initial light that is enable by default is light 0.");
    ADD_CLASS_METHOD(SetLightSpecular,  "Set the specular RGB color for a given light. The initial light that is enable by default is light 0.");
    ADD_CLASS_METHOD(SetBackground,     "Sets the background of the surface drawing window to the specified RGB color");
    ADD_CLASS_METHOD(Normalize,         "Normalizes the 3D view based on the limits in space of the current objects.");
    ADD_CLASS_METHOD(Center,            "Centers the 3D view based on the limits in space of the current objects.");
    ADD_CLASS_METHOD(SetWindowSize,     "Set the dimension of the drawing window, for either images or surfaces.");
    ADD_CLASS_METHOD(getimage,          "Save the snapshot as a 2D image of format RGB. In the case of an image, the snapshot is taken from X11 and it includes potential colorbar and axes, in the case of a surface, it is taken from OpenGL.");
    ADD_CLASS_METHOD(GetImageFromX,     "Save the snapshot as a 2D image of format RGB. In the case of an image, the snapshot is taken from X11 as opposed to getimage, which takes the image using OpenGL.");
    ADD_CLASS_METHOD(GetTransform,      "Gets the transform corresponding to the current 3D view.");

    void AddMethods(WrapClass<Viewer3D>::ptr this_ptr )
    {

      AddVar_rotate(            this_ptr);
      AddVar_AddObject(         this_ptr);
      AddVar_Remove(            this_ptr);
      AddVar_SwapBuffers(       this_ptr);
      AddVar_drawCC(            this_ptr);
      AddVar_drawCCOnlyCC(      this_ptr);
      AddVar_SetCurrentObj(     this_ptr);
      AddVar_compare(           this_ptr);
      AddVar_setvector(         this_ptr);
      AddVar_ShowSection(       this_ptr);
      AddVar_HideSection(       this_ptr);
      AddVar_PrintMatrices(     this_ptr);
      AddVar_SetTransform(      this_ptr);
      AddVar_Paint(             this_ptr);
      AddVar_SetLightAmbient(   this_ptr);
      AddVar_SetLightDiffuse(   this_ptr);
      AddVar_SetLightSpecular(  this_ptr);
      AddVar_SetBackground(     this_ptr);
      AddVar_Normalize(         this_ptr);
      AddVar_Center(            this_ptr);
      AddVar_SetWindowSize(     this_ptr);
      AddVar_getimage(          this_ptr);
      AddVar_GetImageFromX(     this_ptr);
      AddVar_GetTransform(      this_ptr);

      // Operators
      AddVar_add_assign(        this_ptr);
      AddVar_sub_assign(        this_ptr);
      AddVar___reference__(         this_ptr);

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
      
      
    };
};


#endif // _wrap_Viewer3D_h