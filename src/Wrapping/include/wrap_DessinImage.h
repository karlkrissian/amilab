/**
 * C++ Interface: wrap_DessinImage
 *
 * Description: wrapping DessinImage
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_DessinImage_h_
#define _wrap_DessinImage_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "DessinImage.hpp"
//#include "ImageDraw_MIPParam.h"

#include "wrap_FenetreDessin.h"
#include "wrap_ImageViewerBase.h"

#include "wrap_wxWindow.h"
#include "wrap_Viewer3D.h"

AMI_DECLARE_TYPE(DessinImage);

class WrapClass_DessinImage : public WrapClass<DessinImage>, public  WrapClass_FenetreDessin, public WrapClass_ImageViewerBase
{
  DEFINE_CLASS(WrapClass_DessinImage);

  protected:
    typedef WrapClass<DessinImage>::ptr _parentclass_ptr;
    typedef DessinImage ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<DessinImage>& GetObj() const { return WrapClass<DessinImage>::GetObj(); }

    /// Constructor
    WrapClass_DessinImage(boost::shared_ptr<DessinImage > si):  WrapClass<DessinImage>(si), WrapClass_FenetreDessin(si), WrapClass_ImageViewerBase(si)
    {}

    /// Destructor
    ~WrapClass_DessinImage()
    {
      std::cout << "~WrapClass_DessinImage()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(DessinImage, "Wrapping of DessinImage." );

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( DessinImage*);

    ADD_CLASS_METHOD(__reference__,       "Called each time a new reference of the variable is created: increases the list of variable to delete from their contexts when closing the window.");

    ADD_CLASS_METHOD(setpos,                 "Set the cursor position on a imagedraw window");
    ADD_CLASS_METHOD(showcursor,             "Displays or hides the cursor of a imagedraw window");
    ADD_CLASS_METHOD(update,                 "Redraw all the slices");
    ADD_CLASS_METHOD(Paint,                  "Calls the Paint method");
    ADD_CLASS_METHOD(compare,                "Put a comparison image for the imagedraw window");
    ADD_CLASS_METHOD(SetCompareDisplacement, "Defines a displacement to apply to the cursor of the window in parameter, when comparing 2 image drawing windows");
    ADD_CLASS_METHOD(SetCompTransf,          "SetCompTransf is not available at the moment.");
    ADD_CLASS_METHOD(setvector,              "This command allows to set one of the vector fields, specified by the given number");
    ADD_CLASS_METHOD(DrawVector,             "Enable/Disable the draw of a vector field.");

    ADD_CLASS_METHOD(DisplayVectors,         "Display the vectors once.");

    ADD_CLASS_METHOD(SetDisplayVectors,         "Enable/Disable the display of the vectors.");

    ADD_CLASS_METHOD(SetVectParam,           "Sets the size and spacing of the vector drawing interface in the given image drawing window");
    ADD_CLASS_METHOD(SetVectColor,           "Sets the color of the given vector field (given by vector id),the color is set as (R,G,B) components, each component has a value between 0 and 255.");
    ADD_CLASS_METHOD(SetVectStyle,           "Specifies the type of vector.");
    ADD_CLASS_METHOD(SetLineThickness,       "Specifies the line thickness");
    ADD_CLASS_METHOD(SetZoom,                "Zooms in on an area of the image.");
    ADD_CLASS_METHOD(SetWindowSize,          "Sets the dimension of the drawing window, for either images or surfaces");
    ADD_CLASS_METHOD(drawcircle,             "Draws a circle at coordinates: X, Y and Z with a specific color.");
    //Microntracker utility
    ADD_CLASS_METHOD(DrawCircleR,             "Draws a circle at coordinates: X, Y with radius R.");
    //end
    ADD_CLASS_METHOD(SetUserColormap,       "Sets color map of an image.");
    ADD_CLASS_METHOD(UpdateColormap,        "Updates the colormap value.");
    ADD_CLASS_METHOD(setGLwin,              "Associates a 3D surface viewer to this image viewer.");
    ADD_CLASS_METHOD(SetIsoContour,         "Sets the image and intensity value of an isocontour in an 'image_draw' window");
    ADD_CLASS_METHOD(SetIsoContourParam,    "Sets the parameters (line style and thickeness) of an isocontour in an 'image_draw' window");
    ADD_CLASS_METHOD(DrawIsoContour,        "Sets the visibility of an isocontour in an 'image_draw' window");
    ADD_CLASS_METHOD(SetIsoContourColor,    "Sets the color as RGB of an isocontour in an 'image_draw' window");
    ADD_CLASS_METHOD(DrawAllContours,       "Activates or desactivates the drawing of a series of isocontours");
    ADD_CLASS_METHOD(AllContoursParam,      "Parameters for drawing a series of isocontours around the main isocontour");
    ADD_CLASS_METHOD(PaintCallback,         "Specifies a callback routine after painting the image.");
    ADD_CLASS_METHOD(SetOpacityImage,       "Setting the opacity image for the volume rendering.This image should have unsigned char values");
    ADD_CLASS_METHOD(GetXmin,               "Gets the minimum value of the X coordinates.");
    ADD_CLASS_METHOD(GetXmax,               "Gets the maximum value of the X coordinates.");
    ADD_CLASS_METHOD(GetYmin,               "Gets the minimum dimension of the coordinate Y.");
    ADD_CLASS_METHOD(GetYmax,               "Gets the maximum dimension of the coordinate Y.");
    ADD_CLASS_METHOD(GetZmin,               "Gets the minimum dimension of the coordinate Z.");
    ADD_CLASS_METHOD(GetZmax,               "Gets the maximum dimension of the coordinate Z.");
    ADD_CLASS_METHOD(GetXPos,             "Gets the position of the coordinate X.");
    ADD_CLASS_METHOD(GetYPos,             "Gets the position of the coordinate Y.");
    ADD_CLASS_METHOD(GetZPos,             "Gets the position of the coordinate Z.");

    ADD_CLASS_METHOD(getimage,             "Save the snapshot as a 2D image of format RGB. In the case of an image, the snapshot is taken from X11 and it includes potential colorbar and axes, in the case of a surface, it is taken from OpenGL");

    ADD_CLASS_METHOD(DrawLineZ,  "Draws a line on XY plane.");
    ADD_CLASS_METHOD(DrawLines,  "Draws a set of line segments (optionally arrows) on the XY plane.");

    ADD_CLASS_METHOD(SetIntensityRange, "Sets the lower and upper limits of the intensity look-up table.");

    void AddMethods(WrapClass<DessinImage>::ptr this_ptr )
    {

      AddVar___reference__(             this_ptr);
      AddVar_setpos(                this_ptr, "_setpos");
      AddVar_showcursor(            this_ptr);
      AddVar_update(                this_ptr);
      AddVar_Paint(                 this_ptr);
      AddVar_compare(               this_ptr);
      AddVar_SetCompareDisplacement(this_ptr);
      AddVar_SetCompTransf(         this_ptr);
      AddVar_setvector(             this_ptr);
      AddVar_DrawVector(            this_ptr);
      AddVar_DisplayVectors(        this_ptr);
      AddVar_SetDisplayVectors(     this_ptr);
      AddVar_SetVectParam(          this_ptr);
      AddVar_SetVectColor(          this_ptr);
      AddVar_SetVectStyle(          this_ptr);
      AddVar_SetLineThickness(      this_ptr);
      AddVar_SetZoom(               this_ptr);
      AddVar_SetWindowSize(         this_ptr);
      AddVar_drawcircle(            this_ptr);
      AddVar_DrawCircleR(           this_ptr); //MicronTraker
      AddVar_SetUserColormap(       this_ptr);
      AddVar_UpdateColormap(        this_ptr);
      AddVar_setGLwin(              this_ptr);
      AddVar_SetIsoContour(         this_ptr);
      AddVar_SetIsoContourParam(    this_ptr);
      AddVar_DrawIsoContour(        this_ptr);
      AddVar_SetIsoContourColor(    this_ptr);
      AddVar_DrawAllContours(       this_ptr);
      AddVar_AllContoursParam(      this_ptr);
      AddVar_PaintCallback(         this_ptr);
      AddVar_SetOpacityImage(       this_ptr);
      AddVar_GetXmin(               this_ptr);
      AddVar_GetXmax(               this_ptr);
      AddVar_GetYmin(               this_ptr);
      AddVar_GetYmax(               this_ptr);
      AddVar_GetZmin(               this_ptr);
      AddVar_GetZmax(               this_ptr);
      AddVar_GetXPos(               this_ptr);
      AddVar_GetYPos(               this_ptr);
      AddVar_GetZPos(               this_ptr);
      AddVar_getimage(              this_ptr);
      AddVar_DrawLineZ(             this_ptr);
      AddVar_DrawLines(             this_ptr);
      AddVar_SetIntensityRange(     this_ptr);
      
      // Adding Bases
//       WrapClass_FenetreDessin::ptr parent_obj(
//         boost::dynamic_pointer_cast<WrapClass_FenetreDessin>(this_ptr));
//       parent_obj->AddMethods(parent_obj);

      // Add public fields 
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());

      // Add base parent FenetreDessin
      boost::shared_ptr<FenetreDessin > parent_FenetreDessin(  boost::dynamic_pointer_cast<FenetreDessin >(this_ptr->GetObj()));
      BasicVariable::ptr var_FenetreDessin = AMILabType<FenetreDessin>::CreateVarFromSmtPtr(parent_FenetreDessin);
      context->AddVar("FenetreDessin",var_FenetreDessin);
      // Set as a default context
      Variable<AMIObject>::ptr obj_FenetreDessin = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_FenetreDessin);
      context->AddDefault(obj_FenetreDessin->Pointer()->GetContext());
      
    };
};


#endif // _wrap_DessinImage_h
