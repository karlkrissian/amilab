#pragma once
#ifndef _LocalStatsClass_h_
#define _LocalStatsClass_h_

#include "inrimage.hpp"

// deal with EXPORT...

class LocalStatsClass {

protected:
  // Private constructor to avoid wrapping
  LocalStatsClass() {}
  ~LocalStatsClass() {}
  
private:
  LocalStatsClass(const LocalStatsClass&);  // Not implemented.
  void operator=(const LocalStatsClass&);  // Not implemented.

public:

  /**
   * @brief Compute image local intensity averages (or means).
   * The mean intensity is computed on squared windows centered at each pixel/voxel.
   * The algorithm can be applied to 1D,2D and 3D images.
   *
   * @param input Input image.
   * @param size window size of (2*size+1)^n, where n is the image dimension.
   * @return Result image of local means.
   * Example(s):
   *  j = localmean(&i,1) // local means on 3x3 windows for 2D image
   * 
   * @sa filter localmean2 localSD localSD2
   **/
  static InrImage::ptr localmean(
                                  InrImage::ptr input,
                                  int size );

  /**
   * @brief Compute image local intensity averages (or means).
   * The mean intensity is computed on squared windows centered at each pixel/voxel.
   * This version is optimized to be independent, in complexity, of the window size.
   * The algorithm can be applied to 1D,2D and 3D images.
   *
   * @param input Input image.
   * @param size window size of (2*size+1)^n, where n is the image dimension.
   * @return Result image of local means.
   * Example(s):
   *  j = localmean2(&i,1) // local means on 3x3 windows for 2D image
   * 
   * @sa filter localmean localSD localSD2
   **/
  static InrImage::ptr localmean2(
                                  InrImage::ptr input,
                                  int size );

  /**
   * @brief Compute image local intensity standard deviation.
   * The standard deviation of intensity is computed on squared windows centered 
   * at each pixel/voxel.
   * The algorithm can be applied to 1D,2D and 3D images.
   *
   * @param input Input image.
   * @param Imean Image of local means (can be computed with localmean2).
   * @param size window size of (2*size+1)^n, where n is the image dimension.
   * @return Result image of local means.
   * Example(s):
   *  j = localSD(&i,1) // local means on 3x3 windows for 2D image
   * 
   * @sa filter localmean localmean2 localSD2
   **/
  static InrImage::ptr localSD(
                                  InrImage::ptr input,
                                  InrImage::ptr Imean,
                                  int size );

  /**
   * @brief Compute image local intensity standard deviation.
   * The standard deviation of intensity is computed on squared windows centered 
   * at each pixel/voxel.
   * This version is optimized to be independent, in complexity, of the window size.
   * The algorithm can be applied to 1D,2D and 3D images.
   *
   * @param input Input image.
   * @param Imean Image of local means (can be computed with localmean2).
   * @param size window size of (2*size+1)^n, where n is the image dimension.
   * @return Result image of local means.
   * Example(s):
   *  j = localSD2(&i,1) // local means on 3x3 windows for 2D image
   * 
   * @sa filter localmean localmean2 localSD2
   **/
  static InrImage::ptr localSD2(
                                  InrImage::ptr input,
                                  InrImage::ptr Imean,
                                  int size );
  
  
};


#endif 
//  _LocalStatsClass_h_
