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

    /**
     * commande -> VAR_IMAGEDRAW '.' SETPOS '(' expr ',' expr ',' expr ')'
     *
     * parameters
     *   #1 expr:  X pos of the cursor
     *   #2 expr:  Y pos of the cursor
     *   #3 expr:  Z pos of the cursor
     *
     * description:
     *   Set the cursor position on a imagedraw window.
     *
     **/
    ADD_CLASS_METHOD(setpos,                  "Set the cursor position on a imagedraw window");

    /**
     * commande -> VAR_IMAGEDRAW '.' SHOWCURSOR '(' expr ')'
     *
     * parameters
     *   #1 expr:  integer 0 or 1.
     * description:
     *   Displays or hides the cursor of a imagedraw window.
     *
     **/
    ADD_CLASS_METHOD(showcursor,             "Displays or hides the cursor of a imagedraw window");

    /**
     * commande -> VAR_IMAGEDRAW '.' UPDATE
     *
     * parameters
     *   None.
     * description:
     *   Updates the image that is drawn in the specified window.
     *
     **/
    ADD_CLASS_METHOD(update,             "Updates the image that is drawn in the specified window");

    /**
     * commande -> VAR_IMAGEDRAW '.' COMPARE '(' VAR_IMAGE ')'
     *
     * parameters
     *   #1 var_image | $variable_imagedraw:  image to compare.
     * description:
     *    Put a comparison image for the imagedraw window. The comparison image
     * is displayed in a new window.
     *
     **/
    ADD_CLASS_METHOD(compare,             "Put a comparison image for the imagedraw window");

    /**
     * command <-- $variable_imagedraw.SetCompareDisplacement($variable_imagedraw,var_image ) 
     *
     * parameters
     *   #1 $variable_imagedraw:  comparison window.
     *   #2 var_image:  vectorial image.
     * description:
     *    Defines a displacement to apply to the cursor when comparing 2 image
     * drawing windows.
     *
     **/
    ADD_CLASS_METHOD(SetCompareDisplacement,             "Defines a displacement to apply to the cursor when comparing 2 image drawing windows");

    /**
     * command <-- $variable_imagedraw.SetCompTransf(expr,expr,expr,expr,expr,expr,expr,expr,expr,expr,expr,expr) 
     *
     * parameters
     *   #1 ... #12 expr:  expression.
     * description:
     *    TODO.
     *
     **/
    ADD_CLASS_METHOD(SetCompTransf,             "TODO");

    /**
     * commande -> VAR_IMAGEDRAW '.' SETVECTOR '(' number ',' VAR_IMAGE ')'
     *
     * parameters
     *  #1 number:     number of the vector field (1,2 or 3).
     *  #2 VAR_IMAGE:  vector field image.
     * description:
     *    The variable VAR_IMAGEDRAW can display up to 3 vector fields. This
     * command allows to set one of the vector fields, specified by the given
     * number.
     *
     **/
    ADD_CLASS_METHOD(setvector,             "This command allows to set one of the vector fields, specified by the given number");

    /**
     * commande -> $variable_imagedraw.DrawVector(expr,expr)
     *
     * parameters
     *  #1 and #2 expr:  expression.
     * description:
     *    TODO.
     *
     **/
    ADD_CLASS_METHOD(DrawVector,             "TODO");

    /**
     * commande -> $variable_imagedraw.DisplayVectors
     *
     * parameters
     *  None.
     * description:
     *    TODO.
     *
     **/
    ADD_CLASS_METHOD(DisplayVectors,             "TODO");

    /**
     * commande -> $variable_imagedraw.SetVectParam(expr,expr)
     *
     * parameters
     *   #1 expr:  vector size
     *   #2 expr:  vector spacing
     * description:
     *    Sets the size and spacing of the vector drawing interface in the given
     * image drawing window.
     *
     **/
    ADD_CLASS_METHOD(SetVectParam,             "Sets the size and spacing of the vector drawing interface in the given image drawing window");

    /**
     * commande -> $variable_imagedraw.SetVectColor(expr,expr,expr,expr)
     *
     * parameters
     *   #1 expr:  vector id
     *   #2 expr:  red component (0-255)
     *   #3 expr:  green component (0-255)
     *   #4 expr:  blue component (0-255)
     * description:
     *    Sets the color of the given vector field (given by vector id),the
     * color is set as (R,G,B) components, each component has a value between 0
     * and 255.
     *
     **/
    ADD_CLASS_METHOD(SetVectColor,             "Sets the color of the given vector field (given by vector id),the color is set as (R,G,B) components, each component has a value between 0 and 255.");

    /**
     * commande -> $variable_imagedraw.SetVectStyle(expr)
     *
     * parameters
     *   #1 expr:  expression
     * description:
     *    TODO.
     *
     **/
    ADD_CLASS_METHOD(SetVectStyle,             "TODO");

    /**
     * commande -> $variable_imagedraw.SetLineThickness(expr)
     *
     * parameters
     *   #1 expr:  expression
     * description:
     *    TODO.
     *
     **/
    ADD_CLASS_METHOD(SetLineThickness,             "TODO");

    /**
     * commande -> $variable_imagedraw.SetZoom(expr,expr,expr,expr,expr,expr) 
     *
     * parameters
     *   #1 ... #6 expr:  expression
     * description:
     *    TODO.
     *
     **/
    ADD_CLASS_METHOD(SetZoom,             "TODO");

    /**
     * commande <-- VAR_IMAGEDRAW '.' T_SetWindowSize '(' expr ',' expr ')'
     *
     * parameters
     *   #1 expr:  width
     *   #2 expr:  height
     * description:
     *   Set the dimension of the drawing window, for either images or surfaces.
     *
     **/
    ADD_CLASS_METHOD(SetWindowSize,             "Set the dimension of the drawing window, for either images or surfaces");

    /**
     * commande <-- drawcircle(expr,expr,expr,expr,expr,expr) 
     *
     * parameters
     *   #1 expr:  X-coordinate.
     *   #2 expr:  Y-coordinate.
     *   #3 expr:  Z-coordinate.
     *   #4 expr:  red component (0-255)
     *   #5 expr:  green component (0-255)
     *   #6 expr:  blue component (0-255)
     * description:
     *   Draw a circle at coordinates: X, Y and Z with a specific color.
     *
     **/
    ADD_CLASS_METHOD(drawcircle,             "Draw a circle at coordinates: X, Y and Z with a specific color.");

    /**
     * commande <-- $variable_imagedraw.SetColormap(expr_image,expr,expr) 
     *
     * parameters
     *   #1 expr_image: image's expression
     *   #2 ... #3 expr:  expression
     * description:
     *   TODO.
     *
     **/
    ADD_CLASS_METHOD(SetColormap,             "TODO");

    /**
     * commande <-- $variable_imagedraw.setGLwin($variable_surfdraw)
     *
     * parameters
     *   #1 $variable_surfdraw: variable of type surfdraw.
     * description:
     *   TODO.
     *
     **/
    ADD_CLASS_METHOD(setGLwin,             "TODO");

    /**
     * commande <-- $variable_imagedraw.SetIsoContour(expr,var_image,expr)
     * commande <-- $variable_imagedraw.SetIsoContour(var_image,expr)
     *
     * parameters
     *   #1 expr:  isocontour index (0,1 or 2) [Optional]
     *   #2 var_image:  image to use for the isocontour
     *   #3 expr:  intensity value of the isocontour
     * description:
     *   Sets the image and intensity value of an isocontour in an 'image_draw'
     * window.
     *
     **/
    ADD_CLASS_METHOD(SetIsoContour,             "Sets the image and intensity value of an isocontour in an 'image_draw' window");

    /**
     * commande <-- $variable_imagedraw.SetIsoContourParam(expr,expr,expr)
     * commande <-- $variable_imagedraw.SetIsoContourParam(expr,expr,expr,expr,expr)
     *
     * parameters
     *   #1 expr:  isocontour index (0,1 or 2)
     *   #2 expr:  isocontour thickness
     *   #3 expr:  isocontour style (0,1,2 for LineSolid, LineOnOffDash, or LineDoubleDash)
     *   #4 expr:  cap_style (0:CapNotLast, 1:CapButt, 2:CapRound, or 3:CapProjecting)
     *   #5 expr:  join_style (0:JoinMiter, 1:JoinRound, or 2:JoinBevel)
     * description:
     *   Sets the parameters (line style and thickeness) of an isocontour in an
     * 'image_draw' window.
     *
     **/
    ADD_CLASS_METHOD(SetIsoContourParam,             "Sets the parameters (line style and thickeness) of an isocontour in an 'image_draw' window");

    /**
     * command <-- $variable_imagedraw.DrawIsoContour(expr,expr)
     *
     * parameters
     *   #1 expr:  isocontour index (0,1 or 2)
     *   #2 expr:  visible or not (0 or 1)
     * description:
     *   Sets the visibility of an isocontour in an 'image_draw' window. 
     *
     **/
    ADD_CLASS_METHOD(DrawIsoContour,             "Sets the visibility of an isocontour in an 'image_draw' window");

    /**
     * command <-- $variable_imagedraw.SetIsoContourColor(expr,expr,expr,expr)
     *
     * parameters
     *   #1 expr:  isocontour index (0,1 or 2)
     *   #2 expr:  Red component in [0,255]
     *   #1 expr:  Green component in [0,255]
     *   #2 expr:  Blue component in [0,255]
     * description:
     *   Sets the color as RGB of an isocontour in an 'image_draw' window.
     *
     **/
    ADD_CLASS_METHOD(SetIsoContourColor,             "Sets the color as RGB of an isocontour in an 'image_draw' window");

    /**
     * command <-- $variable_imagedraw.DrawAllContours(expr)
     *
     * parameters
     *   #1 expr:  boolean parameter
     * description:
     *   Activates or desactivates the drawing of a series of isocontours.
     *
     **/
    ADD_CLASS_METHOD(DrawAllContours,             "Activates or desactivates the drawing of a series of isocontours");

    /**
     * command <-- $variable_imagedraw.AllContoursParam(expr,expr)
     *
     * parameters
     *   #1 expr:  intensity step between isocontours
     *   #2 expr:  alf size of the intensity range where to draw isocontours
     * description:
     *   Parameters for drawing a series of isocontours around the main
     * isocontour.
     *
     **/
    ADD_CLASS_METHOD(AllContoursParam,             "Parameters for drawing a series of isocontours around the main isocontour");

    /**
     * command <-- $variable_imagedraw.PaintCallback($variable_ami_function)
     *
     * parameters
     *   #1 $variable_ami_function:  variable of type function.
     * description:
     *   TODO.
     *
     **/
    ADD_CLASS_METHOD(PaintCallback,             "TODO");

    /**
     * command <-- $variable_imagedraw.SetOpacityImage(var_image)
     *
     * parameters
     *   #1 var_image:  variable of type image.
     * description:
     *   Setting the opacity image for the volume rendering.This image should
     * have unsigned char values.
     *
     **/
    ADD_CLASS_METHOD(SetOpacityImage,             "Setting the opacity image for the volume rendering.This image should have unsigned char values");

    /**
     * command <-- $variable_imagedraw.GetXmin
     *
     * parameters
     *   None
     * description:
     *   Gets the minimum dimension of the coordinate X.
     *
     **/
    ADD_CLASS_METHOD(GetXmin,             "Gets the minimum dimension of the coordinate X.");

    /**
     * command <-- $variable_imagedraw.GetXmax
     *
     * parameters
     *   None
     * description:
     *   Gets the maximum dimension of the coordinate X.
     *
     **/
    ADD_CLASS_METHOD(GetXmax,             "Gets the maximum dimension of the coordinate X.");

    /**
     * command <-- $variable_imagedraw.GetYmin
     *
     * parameters
     *   None
     * description:
     *   Gets the minimum dimension of the coordinate Y.
     *
     **/
    ADD_CLASS_METHOD(GetYmin,             "Gets the minimum dimension of the coordinate Y.");

    /**
     * command <-- $variable_imagedraw.GetYmax
     *
     * parameters
     *   None
     * description:
     *   Gets the maximum dimension of the coordinate Y.
     *
     **/
    ADD_CLASS_METHOD(GetYmax,             "Gets the maximum dimension of the coordinate Y.");

    /**
     * command <-- $variable_imagedraw.GetZmin
     *
     * parameters
     *   None
     * description:
     *   Gets the minimum dimension of the coordinate Z.
     *
     **/
    ADD_CLASS_METHOD(GetZmin,             "Gets the minimum dimension of the coordinate Z.");

    /**
     * command <-- $variable_imagedraw.GetZmax
     *
     * parameters
     *   None
     * description:
     *   Gets the maximum dimension of the coordinate Z.
     *
     **/
    ADD_CLASS_METHOD(GetZmax,             "Gets the maximum dimension of the coordinate Z.");

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