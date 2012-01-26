
#pragma once
#ifndef _amivtkFastMarchingFunctions_h_
#define _amivtkFastMarchingFunctions_h_

#include "AlgorithmsConfigure.h"
#include <ostream>

#include "inrimage.hpp"
//#include "amiImageExtent.h"

class InrImage;


namespace ami {

  
  /**
  * Create Skeleton from a binary image, reducing the image
  * based on its topology (simple points)
  */
  class Algorithms_EXPORT vtkFastMarchingFunctions
  {

    public:
      /**
       * @brief Initialization type.
      **/
      enum InitializationType {
        InitIsoSurf = 0, /**< recomputes the distance close to the surface */
        InitWithImage    /**< much faster: all values lower than initmaxdist 
                            (set to 1E-3 here) will be accepted to start with.*/
      };

      /**
       * @brief Runs the fast marching algorithm.
       *
       * @param input input image
       * @param init initialization image
       * @param maxtime maximal evolution time
       * @param inittype initialization type. Defaults to 0.
       * @return :ptr
       **/
      static InrImage::ptr FastMarching( InrImage* input
                                      ,InrImage* init
                                      ,float maxtime
                                      ,InitializationType inittype=InitIsoSurf);

      /**
      * @brief Runs the fast marching algorithm with a target point.
      * Stops the evolution when the target is reached.
      * 
      * @param input input image
      * @param init initialization
      * @param maxtime  maximal evolution time
      * @param x  target point X coordinate
      * @param y  target Y coord.
      * @param z  target Z coord.
      * @return :ptr
      **/
      static InrImage::ptr FastMarchingTarget( InrImage* input 
                                              ,InrImage* init
                                              ,float maxtime 
                                              ,int x, int y, int z);

      /**
      * @brief Runs the fast marching algorithm based on intensity-based.
      *
      * @param input input image
      * @param init initialization
      * @param mean mean
      * @param sd standard deviation
      * @param maxtime maximal time
      * @param inittype  Defaults to InitIsoSurf.
      * @return :ptr
      **/
      static InrImage::ptr FastMarching(  InrImage* input
                                      , InrImage* init
                                      ,float mean
                                      , float sd
                                      , float maxtime 
                                      ,InitializationType inittype=InitIsoSurf
                                      ,int evol_scheme = 0);

      /**
      * @brief Runs the fast marching algorithm based on intensity-based and
      * using Dijkstra algorithm with trajectory tracking
      * 
      * @param input input image
      * @param init initialization
      * @param track image that keeps the trajectory, must be 'unsigned int'
      * @param mean mean
      * @param sd standard deviation
      * @param maxtime maximal time
      * @param inittype  Defaults to InitIsoSurf.
      * @return :ptr
      **/
      static InrImage::ptr FastMarchingTrack(  
                                      InrImage* input
                                      , InrImage* init
                                      , InrImage* track
                                      ,float mean
                                      , float sd
                                      , float maxtime
                                      ,InitializationType inittype=InitIsoSurf);


        /**
        * @brief Runs the fast marching algorithm using Dijkstra algorithm and 
        * tracking back the trajectories
        *
        * @param input  input image
        * @param init initialization
        * @param track track image, must be of format unsigned int
        * @param maxtime maximal time
        * @param inittype initialization type Defaults to InitIsoSurf.
        * @return :ptr
        **/
        static InrImage::ptr FastMarchingTrack(  
                                    InrImage* input, InrImage* init,
                                    InrImage* track,
                                    float maxtime, 
                                    InitializationType inittype=InitIsoSurf);


  };

} // end namespace ami

#endif // _amivtkFastMarchingFunctions_h_
