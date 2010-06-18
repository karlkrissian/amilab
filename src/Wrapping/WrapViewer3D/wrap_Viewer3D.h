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
#include "wrap_wxWindow.h"
#include "wrap_SurfacePoly.h"
//#include "wrap_FenetreDessin.h"

TO_STRING(Viewer3D);

class WrapClass_Viewer3D: public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_Viewer3D);

  protected:
    // for nested classes
    typedef WrapClass_Viewer3D::ptr _parentclass_ptr;
    typedef Viewer3D _obj_type;

  public:
    /// Stores a pointer to an object of type Viewer3D.
    boost::shared_ptr<_obj_type> _obj;
    const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }

    /// Constructor
    WrapClass_Viewer3D(boost::shared_ptr<Viewer3D > si): WrapClass_wxWindow(si), _obj(si)
    {}

    ADD_CLASS_METHOD(reference,         "Called each time a new reference of the variable is created: increases the list of variable to delete from their contexts when closing the window.");

    ADD_CLASS_METHOD(rotate,            "Applies a rotation to the objects displayed by the surface visualization window.");
    ADD_CLASS_METHOD(AddObject,         "Add a wrapped SurfacePoly object.");
    ADD_CLASS_METHOD(add_assign,        "Operator +=, add a new SurfacePoly object.");
    ADD_CLASS_METHOD(subtraction_assign,"Operator -=, remove a existing SurfacePoly object.");
    ADD_CLASS_METHOD(Remove,            "Removes the surface without swapping the 3D buffer.");
    ADD_CLASS_METHOD(SwapBuffers,       "Swaps the 3D buffer");
    ADD_CLASS_METHOD(drawCCOnlyCC,      "Choose to draw only the specified connected component.");
    ADD_CLASS_METHOD(drawCC,            "Choose to draw or not a given connected component.");
    ADD_CLASS_METHOD(SetCurrentObj,     "The object indicated by the index becomes the current object.");
    ADD_CLASS_METHOD(compare,           "Put a comparison image for the imagedraw window specified by the parameters. The comparison image is displayed in a new window.");
    ADD_CLASS_METHOD(setvector,         "This command allows to set one of the vector fields, specified by the given number. The image parameter can display up to 3 vector fields.");
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
    ADD_CLASS_METHOD(GetTransform,      "TODO");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      AddVar_rotate(            this_ptr);
      AddVar_AddObject(         this_ptr);
      AddVar_Remove(            this_ptr);
      AddVar_SwapBuffers(       this_ptr);
      AddVar_drawCC(            this_ptr);
      AddVar_SetCurrentObj(     this_ptr);
      AddVar_compare(           this_ptr);
      AddVar_setvector(         this_ptr);
      AddVar_ShowSection(       this_ptr);
      AddVar_HideSection(       this_ptr);
      AddVar_PrintMatrices(     this_ptr);
      AddVar_SetTransform(      this_ptr,"_SetTransform");
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
      AddVar_GetTransform(      this_ptr,"_GetTransform");
    };
};

/**
 * Create a Wrapped object around Viewer3D
 * @param objectptr input smart pointer to a WrapClass_Viewer3D
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_Viewer3D(  WrapClass_Viewer3D::ptr& objectptr);

/**
 * Create a Wrapped object around Viewer3D
 * @param si_ptr input smart pointer to a Viewer3D
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_Viewer3D( Viewer3D* si);

/** Method that adds wrapping of Viewer3D
 */
ADD_CLASS_FUNCTION( Viewer3D, "Wrapping of Viewer3D." );

#endif // _wrap_Viewer3D_h