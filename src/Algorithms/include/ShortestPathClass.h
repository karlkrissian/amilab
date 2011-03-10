//
// C++ Interface: func_shortestpath
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _func_shortestpath_h_
#define _func_shortestpath_h_

#include "surface.hpp"
using namespace amilab;

#include "inrimage.hpp"

class ShortestPathClass {
  
public:

  //-------------------------------------------------------
  static SurfacePoly* Func_shortestpath( SurfacePoly* lines, 
                                  float pt1_x, float pt1_y, float pt1_z,
                                  float pt2_x, float pt2_y, float pt2_z);

  //-------------------------------------------------------
  static SurfacePoly* Func_shortestpath_image( InrImage* weights,
                                        double threshold,
                                        float pt1_x, float pt1_y, float pt1_z,
                                        float pt2_x, float pt2_y, float pt2_z);

  //-------------------------------------------------------
  static SurfacePoly* Func_path_from_displ( InrImage* displ,
                                    int startx, int starty, int startz);

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \brief Find path in 3D+T (4D) images, where the 4th dimension is encoded in the image vectorial components
  /// \param displ      4D speed 
  /// \param start      initial point for the path 
  /// \param step_size  step size for the evolution 
  /// \param max_length maximal length of the path
  /// \param delta      step for computing local derivatives
  /// \return resulting 3D path as a amilab::SurfacePoly object

  static SurfacePoly* Func_path_4D(   InrImage::ptr speed,
                                      double start[4],
                                      double step_size,
                                      double max_length,
                                      double delta = 0.05);


  //-------------------------------------------------------
  static SurfacePoly::ptr Func_path_from_vectfield(  InrImage::ptr displ,
                                          double start[3],
                                          double step_size,
                                          double max_length,
                                          double delta = 0.05);

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \brief Find path in 3D+T (4D) images, where the 4th dimension is encoded in the image vectorial components
  ///    Creates a path starting at a point in spatial coordinates
  ///    and following the displacements given by the input vector field
  ///    image
  ///    if the input is scalar the corresponding vector field is computed
  ///    from its gradient by local linear interpolation
  ///    the tracking stops in one of the following cases:
  ///      - the maximal distance is reached
  ///      - the closest voxel to the current location has a negative intensity
  ///      - the current gradient is very low
  /// \param displ      4D speed 
  /// \param start      initial point for the path 
  /// \param end        final   point for the path 
  /// \param step_size  step size for the evolution 
  /// \param max_length maximal length of the path
  /// \param delta      step for computing local derivatives
  /// \return resulting 3D path as a amilab::SurfacePoly object
  static SurfacePoly::ptr Func_path_from_vectfield( InrImage::ptr displ,
                                        double start[3],
                                        double end[3],
                                        double step_size,
                                        double max_length,
                                        double delta = 0.05);
};
/*

    |
    T_PathFromVectField T_OP_PAR     expr_image
                            T_COMMA expr T_COMMA expr
                            T_COMMA expr T_COMMA expr T_COMMA expr
                          T_CL_PAR
    {
    Parameters:
      (3)  input image as a vector field in spatial coordinates
            or as a scalar potential
      (5) time step for the evolution
      (7) maximal Euclidean distance of the path
      (9)  X coord of the starting point (in spatial coord.)
      (11)  Y coord ---
      (13)  Z coord ---

    Description:
      Creates a path starting at a point in spatial coordinates
      and following the displacements given by the input vector field
      image
      if the input is scalar the corresponding vector field is computed
      from its gradient by local linear interpolation
      the tracking stops in one of the following cases:
        - the maximal distance is reached
        - the closest voxel to the current location has a negative intensity
        - the current gradient is very low
      GET_VARSTACK_VALUE(InrImage,im);
      SurfacePoly* surf;

      double start[3] = {$9,$11,$13};
      surf = ShortestPathClass::Func_path_from_vectfield(  im,
                                        start,
                                        $5, $7);

      Si surf==NULL Alors
        driver.err_print("Func_path_from_vectfield() error ... \n");
        YYABORT;
      FinSi
      BasicVariable::ptr res(WrapClass_SurfacePoly::CreateVar(surf));
      driver.var_stack.AddVar(res);
    }
*/
#endif // _func_shortestpath_h_
