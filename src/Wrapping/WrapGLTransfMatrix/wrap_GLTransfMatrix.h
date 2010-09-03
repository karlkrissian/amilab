/**
 * C++ Interface: wrap_GLTransfMatrix
 *
 * Description: wrapping GLTransfMatrix
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_GLTransfMatrix_h_
#define _wrap_GLTransfMatrix_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "GLparam.hpp"
//#include "InterpolateTransform.h"
//#include "wrap_wxWindow.h"

AMI_DECLARE_TYPE(GLTransfMatrix);

class WrapClass_GLTransfMatrix: public WrapClass<GLTransfMatrix>
{
  DEFINE_CLASS(WrapClass_GLTransfMatrix);

  public:

    /// Constructor
    WrapClass_GLTransfMatrix(boost::shared_ptr<GLTransfMatrix > si):  WrapClass<GLTransfMatrix>(si)
    {}

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( GLTransfMatrix* sp);

   /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( GLTransfMatrix, "Wrapping of GLTransfMatrix." );

    ADD_CLASS_METHOD(print,       "Prints the contents of the rotation matrices, translation and scaling.");
    ADD_CLASS_METHOD(save,        "Save the image to the disk, using the specified image name. The output format depends on the image type and on the filename extension. For saving images with standard 2D image format (jpeg, gif, etc...) you need to have a RGB image.");
    ADD_CLASS_METHOD(read,        "Read the image from the disk, using the specified image name.");
    ADD_CLASS_METHOD(Interpolate, "Interpolates the transformation between current object and the parameter passed using the interpolation coefficient: 0 gives current object and 1 gives the parameter passed. The interpolation separates translation, rotation and scaling. The rotation is decomposed into 3 rotation around the main axes, and the angles are linearly interpolated.");

    ADD_CLASS_METHOD(copy,        "Copy of the GLTransfMatrix.");
    ADD_CLASS_METHOD(assign,      "Operator =, copy assignment.");

    void AddMethods(WrapClass<GLTransfMatrix>::ptr this_ptr )
    {
      AddVar_print(        this_ptr, "_print");
      AddVar_save(         this_ptr, "_save");
      AddVar_read(         this_ptr, "_read");
      AddVar_Interpolate(  this_ptr);

      // Operators
      AddVar_copy(                this_ptr);
      AddVar_assign(              this_ptr);
    };

};

#endif // _wrap_GLTransfMatrix_h