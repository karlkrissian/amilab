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
//#include "wrap_wxWindow.h"

class WrapClass_DessinImage : public WrapClassBase
//: public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_DessinImage);

  // for nested classes
  typedef WrapClass_DessinImage::ptr _parentclass_ptr;

  public:
    /// Stores a pointer to an object of type DessinImage.
    boost::shared_ptr<DessinImage> _obj;

    /// Constructor
    WrapClass_DessinImage(boost::shared_ptr<DessinImage > si): _obj(si)
    {}

    ADD_CLASS_METHOD(setpos,                 "Set the cursor position on a imagedraw window");
    ADD_CLASS_METHOD(showcursor,             "Displays or hides the cursor of a imagedraw window");
    ADD_CLASS_METHOD(update,                 "Updates the image that is drawn in the specified window");
    ADD_CLASS_METHOD(compare,                "Put a comparison image for the imagedraw window");
    ADD_CLASS_METHOD(SetCompareDisplacement, "Defines a displacement to apply to the cursor of the window in parameter, when comparing 2 image drawing windows");
    ADD_CLASS_METHOD(SetCompTransf,          "SetCompTransf is not available at the moment.");
    ADD_CLASS_METHOD(setvector,              "This command allows to set one of the vector fields, specified by the given number");
    ADD_CLASS_METHOD(DrawVector,             "Enable/Disable the draw of a vector field.");
    ADD_CLASS_METHOD(DisplayVectors,         "Display the vectors.");
    ADD_CLASS_METHOD(SetVectParam,           "Sets the size and spacing of the vector drawing interface in the given image drawing window");
    ADD_CLASS_METHOD(SetVectColor,           "Sets the color of the given vector field (given by vector id),the color is set as (R,G,B) components, each component has a value between 0 and 255.");
    ADD_CLASS_METHOD(SetVectStyle,           "Specifies the type of vector.");
    ADD_CLASS_METHOD(SetLineThickness,       "Specifies the line thickness");
    ADD_CLASS_METHOD(SetZoom,                "Zooms in on an area of the image.");
    ADD_CLASS_METHOD(SetWindowSize,          "Sets the dimension of the drawing window, for either images or surfaces");
    ADD_CLASS_METHOD(drawcircle,             "Draws a circle at coordinates: X, Y and Z with a specific color.");
    ADD_CLASS_METHOD(SetColormap,           "Sets color map of an image.");
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

    /**
     * command <-- $variable_imagedraw.GetXPos
     *
     * parameters
     *   None
     * description:
     *   Gets the position of the coordinate X.
     *
     **/
    ADD_CLASS_METHOD(GetXPos,             "Gets the position of the coordinate X.");

    /**
     * command <-- $variable_imagedraw.GetYPos
     *
     * parameters
     *   None
     * description:
     *   Gets the position of the coordinate Y.
     *
     **/
    ADD_CLASS_METHOD(GetYPos,             "Gets the position of the coordinate Y.");

    /**
     * command <-- $variable_imagedraw.GetZPos
     *
     * parameters
     *   None
     * description:
     *   Gets the position of the coordinate Z.
     *
     **/
    ADD_CLASS_METHOD(GetZPos,             "Gets the position of the coordinate Z.");

    /**
     * image <-- VAR_IMAGEDRAW '.' T_getimage
     *
     * parameters
     *   None
     * description:
     *   Save the snapshot as a 2D image of format RGB. In the case of an image,
     * the snapshot is taken from X11 and it includes potential colorbar and
     * axes, in the case of a surface, it is taken from OpenGL.
     *
     **/
    ADD_CLASS_METHOD(getimage,             "Save the snapshot as a 2D image of format RGB. In the case of an image, the snapshot is taken from X11 and it includes potential colorbar and axes, in the case of a surface, it is taken from OpenGL");


    ADD_CLASS_METHOD(reference,       "Called each time a new reference of the variable is created: increases the list of variable to delete from their contexts when closing the window.");

    void AddMethods(_parentclass_ptr& this_ptr )
    {

      AddVar_setpos(                this_ptr, "_setpos");
      AddVar_showcursor(            this_ptr);
      AddVar_update(                this_ptr);
      AddVar_compare(               this_ptr, "_compare");
      AddVar_SetCompareDisplacement(this_ptr);
      AddVar_SetCompTransf(         this_ptr);
      AddVar_setvector(             this_ptr, "_setvector");
      AddVar_DrawVector(            this_ptr);
      AddVar_DisplayVectors(        this_ptr);
      AddVar_SetVectParam(          this_ptr);
      AddVar_SetVectColor(          this_ptr);
      AddVar_SetVectStyle(          this_ptr);
      AddVar_SetLineThickness(      this_ptr);
      AddVar_SetZoom(               this_ptr);
      AddVar_SetWindowSize(         this_ptr, "_SetWindowSize");
      AddVar_drawcircle(            this_ptr);
      AddVar_SetColormap(           this_ptr);
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
      AddVar_getimage(              this_ptr, "_getimage");
      AddVar_reference(             this_ptr);
    };
};

/**
 * Create a Wrapped object around DessinImage
 * @param objectptr input smart pointer to a WrapClass_DessinImage
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_DessinImage(  WrapClass_DessinImage::ptr& objectptr);

/**
 * Create a Wrapped object around DessinImage
 * @param si_ptr input smart pointer to a DessinImage
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_DessinImage( DessinImage* si);

/** Method that adds wrapping of DessinImage
 */
ADD_CLASS_FUNCTION( DessinImage, "Wrapping of DessinImage." );

#endif // _wrap_DessinImage_h