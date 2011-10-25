#pragma once
#ifndef _DistanceTransformClass_h_
#define _DistanceTransformClass_h_

#include "inrimage.hpp"

// deal with EXPORT...

class DistanceTransformClass {

protected:
  // Private constructor to avoid wrapping
  DistanceTransformClass() {}
  ~DistanceTransformClass() {}
  
private:
  DistanceTransformClass(const DistanceTransformClass&);  // Not implemented.
  void operator=(const DistanceTransformClass&);  // Not implemented.

public:

/*
 *  TODO: check what to do with this code: is it better than another one?
      T_AndreDist T_OP_PAR var_image T_CL_PAR
      {
        GET_VARSTACK_VALUE(InrImage, im);
        driver.err_print("The function AndreDist() has been removed for licence issues! \n");
        InrImage::ptr  in = *(InrImage::ptr*) $3->Pointer();
        InrImage*  res;
        int ok;

        res = new InrImage(WT_FLOAT,"AndreDist.ami.gz", in.get());

        ok = dist_squared( in.get(),res);

        Si !ok Alors
          sprintf(tmp_string,"AndreDist() erreur ... \n");
          driver.err_print(tmp_string);
          delete res;
          res=NULL;
        Sinon
          ADD_VARSTACK_PTR(InrImage,res);
        FinSi
    }
*/


  /**
  * @brief Distance Transform based on Borgefors distance.
  * It call the Chamfer distance with coefficients 0.92644, 1.34065, 1.65849.
  *
  * @param input Input image for the Chamfer distance.
  * @param maxdist Maximal distance needed
  * @return Distance Transform image.
  **/
  static InrImage::ptr BorgeforsDT( InrImage::ptr input, float maxdist);
  
  /**
  * @brief Signed Distance Transform based on Borgefors distance.
  * It call the Chamfer distance with coefficients 0.92644, 1.34065, 1.65849.
  *
  * @param input Input image for the Chamfer distance.
  * @param maxdist Maximal distance needed
  * @return Signed Distance Transform image.
  **/
  static InrImage::ptr BorgeforsSDT( InrImage::ptr input, float maxdist);


  /**
  * @brief Computes a Chamfer distance transform in a 3D image.
  *
  * @param im input image
  * @param a coefficient for X coordinates
  * @param b coefficient for Y coordinates
  * @param c coefficient for Z coordinates
  * @return Resulting image.
  **/
  static InrImage::ptr ChamferDT( InrImage::ptr input, float a, float b, float c);

  /**
  * @brief Computes a Chamfer distance transform in a 3D image.
  * This version is faster than ChamferDT and can be used also for 2D images.
  *
  * @param im input image
  * @param a coefficient for X coordinates
  * @param b coefficient for Y coordinates
  * @param c coefficient for Z coordinates
  * @param dmax maximal distance needed. Default 10000.
  * @return Resulting image.
  **/
  static InrImage::ptr Chamfer2DT( InrImage::ptr input, 
                                   float a, 
                                   float b, 
                                   float c,
                                   float dmax=10000
                                 );

  /**
  * @brief Signed Distance Transform based on Borgefors distance.
  * It call the Chamfer distance with coefficients 0.92644, 1.34065, 1.65849.
  * Implementation using a vtk class.
  *
  * @param input Input image for the Chamfer distance.
  * @param maxdist Maximal distance needed
  * @return Signed Distance Transform image.
  **/
  // within wrapvtk ...
  //static InrImage::ptr vtkSignedBorgefors( InrImage::ptr input, float maxdist);


  /**
  * @brief Distance Transform by progapation.
  *
  * @param input Input image.
  * @param maxdist maximal distance needed
  * @return Resulting distance transform.
  **/
  static InrImage::ptr PropagationDist( InrImage::ptr input, float maxdist);

/*
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        |
        T_vtkSignedFMDist T_OP_PAR var_image  T_COMMA expr T_CL_PAR
        {
        float dmax = $5;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        ADD_VARSTACK_PTR(InrImage,res);

        }
        |
        T_PropagationDist2 T_OP_PAR var_image  T_COMMA expr T_CL_PAR
        {
        float dmax = $5;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
        |
        T_PropDanielsson T_OP_PAR var_image  T_COMMA expr T_CL_PAR
        {
        float dmax = $5;

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        }
        |
        T_vtkPropDanielsson T_OP_PAR var_image  T_COMMA expr T_CL_PAR
        {
        float dmax = $5;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
        |
        T_vtkPropDanielsson T_OP_PAR var_image  T_COMMA expr T_COMMA expr T_CL_PAR
        {
        float dmin = $5;
        float dmax = $7;

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        ADD_VARSTACK_PTR(InrImage,res);
        }
        |
        T_vtkPropDaniel2 T_OP_PAR var_image  T_COMMA expr T_COMMA expr T_COMMA expr T_CL_PAR
        {
        / **
        Parameters:
          (3) input image variable
          (5) threshold on the image intensity to define
              the object
          (7) minimal distance (<0)
          (9) maximal distance (>0)

        Description:
          Computes an Euclidean distance by propagation
          starting from the object, up to a given distance
          for positive and negative sides.
        ** /
      GET_VARSTACK_VALUE(InrImage, im);
        float threshold = $5;
        float dmin      = $7;
        float dmax      = $9;

        printf("threshold = %f \n",threshold);
        InrImage::ptr res ( Func_vtkPropDaniel2(im.get(),
                    threshold,dmin,dmax));

        ADD_VARSTACK_PTR(InrImage,res);
        }
*/
  
};


#endif 
//  _DistanceTransformClass_h_
