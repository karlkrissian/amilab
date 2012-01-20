
#pragma once
#ifndef _amiThinning_h_
#define _amiThinning_h_

#include "AlgorithmsConfigure.h"
#include <ostream>

#include "inrimage.hpp"
//#include "amiImageExtent.h"

class InrImage;

//#include "vtkMinHeap.h"
//#include "style.hpp"
//#include "Coordonnees.hpp"

namespace ami {

  
/**
 * Create Skeleton from a binary image, reducing the image
 * based on its topology (simple points)
 */
class Algorithms_EXPORT Thinning
{

private:
  static int N26_star[27][27]; // 26 adjacent neighbors for each point in 
                              // the N26* neighborhood:
                              // N26_star[i][0] = number of neighbors

  static int N18[27][27]; // 6 adjacent neighbors for each point in 
                          // the N18 neighborhood:
                          // N18[i][0] = number of neighbors

  static int pos[3][3][3];
  static int neighbors_pos  [27];
  static int neighbors_place[27][3];

  //----------------------------------------------------------------------------
  static void ParseCC(  int* domain, 
                        int neighborhood[27][27], 
                        int* cc,
                        int point, 
                        int num_cc );

public:
  
  enum  EndPointType {
    ENDPOINT_LINE,
    ENDPOINT_SURFACE,
    ENDPOINT_LINE_OR_SURFACE,
    };
  
  
  //----------------------------------------------------------------------
  //
  class TrialPoint {

  public:
    int   x,y,z;
    float value;

    TrialPoint()
    {
      x = y = z = 0;
      value = 1000;
    }

    TrialPoint(int px, int py, int pz, float val)
    {
      x     = px;
      y     = py;
      z     = pz;
      value = val;
    }

    TrialPoint& operator=(const TrialPoint& p)
    {
      x     = p.x;
      y     = p.y;
      z     = p.z;
      value = p.value;
      return *this;
    }


    friend int operator < ( const TrialPoint& p1, const TrialPoint& p2)
    {
      return (p1.value < p2.value);
    }

    friend int operator > ( const TrialPoint& p1, const TrialPoint& p2)
    {
      return (p1.value > p2.value);
    }

    friend std::ostream& operator << (std::ostream&, const TrialPoint& p);

  }; // TrialPoint


  //----------------------------------------------------------------------------
  /**
   * @brief Initialize voxel neighborhood information to speed-up processing
   *
   * @param im Input image to get image dimensions and compute increments
   * @return void
   **/
  static void Thin_init_pos( InrImage::ptr im);
  

  /**
   * @brief Initialize neighborhood information N26* and N18
   * int N26_star[27][27] 26 adjacent neighbors for each point in 
   *                      the N26* neighborhood:
   *                      N26_star[i][0] = number of neighbors
   *
   * int N18[27][27]; 6 adjacent neighbors for each point in 
   *                  the N18 neighborhood:
   *                  N18[i][0] = number of neighbors
   *
   * @return void
   **/
  //----------------------------------------------------------------------------
  static void init_neighborhoods();

  //----------------------------------------------------------------------------
  /**
   * @brief Check if a voxel is a line endpoint (has exactly 2 neighboors 
   * of positive intensity)
   *
   * @param im image: positive intensities are inside the structure
   * @param x X coordinate of the voxel
   * @param y Y coord.
   * @param z Z coord.
   * @return bool: true/false
   **/
  static bool IsEndPointLine( InrImage::ptr im, int x, int y, int z);


  //----------------------------------------------------------------------------
  /**
   * @brief Check if a point is a surface border point: 26-connected case
   * Add an extra test to make sure it is not a line end point.
   * we want only surfaces here...
   *
   * @param im image: positive intensities are inside the structure
   * @param x X voxel coord
   * @param y Y voxel coord
   * @param z Z voxel coord
   * @return bool
   **/
  static bool IsEndPointSurface( InrImage::ptr im, int x, int y, int z);


  //----------------------------------------------------------------------------
  /**
   * @brief Check for endpoint
   *
   * @param im input image, positive inside the structure
   * @param x X voxel coord
   * @param y Y voxel coord
   * @param z Z voxel coord
   * @param endpoint_type type of endpoint
   * @return bool
   **/
  static bool IsEndPoint( InrImage::ptr im, int x, int y, int z, 
                          EndPointType endpoint_type);

  //----------------------------------------------------------------------------
  /**
   * @brief Returns an image with information about the local topology of each
   * point.
   *
   * Two numbers for connected components are computed at each voxel:
   * cc1 and cc2.
   * The returned image contains the values cc1+10*cc2.
   * If cc2==1 then the voxel is simple (it can be removed without topological
   * changes).
   * @param im input binary image
   * @return :ptr
   **/
  static InrImage::ptr SimplePoints( InrImage::ptr im);

  //----------------------------------------------------------------------------
  static unsigned char IsSimple(  InrImage::ptr im, int x, int y, int z, 
                                  int& cc1, int& cc2);


  //----------------------------------------------------------------------------
  static InrImage::ptr Skeleton( InrImage::ptr im, InrImage::ptr criterion, 
                                  float min_threshold, float max_threshold, 
                                  EndPointType endpoint_type = ENDPOINT_LINE);
  
}; // end class Thinning

} // end namespace ami

#endif // _amiThinning_h_
