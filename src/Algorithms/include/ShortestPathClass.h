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

  //-------------------------------------------------------
  static SurfacePoly* Func_path_from_vectfield(  InrImage::ptr displ,
                                          double start[3],
                                          double step_size,
                                          double max_length,
                                          double delta = 0.05);

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
  static SurfacePoly* Func_path_from_vectfield( InrImage::ptr displ,
                                        double start[3],
                                        double end[3],
                                        double step_size,
                                        double max_length,
                                        double delta = 0.05);
};

#endif // _func_shortestpath_h_
