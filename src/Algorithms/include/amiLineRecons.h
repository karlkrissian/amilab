//
// C++ Interface: ami::LineRecons
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _amiLineRecons_h_
#define _amiLineRecons_h_

#include "Coordonnees.hpp"

namespace amilab{
class SurfacePoly;
}
#include "inrimage.hpp"

class Excep_points_proches {};

namespace ami {

  class LineRecons 
  {

    public:
      
      /**
       * @brief Models of intensity profile of the reconstructed cross-sections
       **/
      enum IntensityProfile {
        EUCLIDEAN_DISTANCE,
        GAUSSIAN
      };
      
      LineRecons() :_profile(GAUSSIAN) {}
      
      void SetReferenceImage(InrImage::ptr r) { ref=r; }
      void SetRadiiImage(InrImage::ptr r)     { radii=r; }
      void SetIntensityProfile( IntensityProfile p) { _profile = p; }

      
      InrImage::ptr Run( amilab::SurfacePoly* surf);

    /**
      * @brief Tubular reconstruction based on a set of lines and an estimated 
      * radius size for each point
      *
      * @param surf input PolyData containing lines to reconstruct
      * @param ref reference image for reconstruction
      * @param rad image of the radii associated to each point of 
      * the input PolyData (1D image)
      * @return :ptr
      **/
      static InrImage::ptr LineReconstruction(amilab::SurfacePoly* surf,
                                      InrImage::ptr ref,
                                      InrImage::ptr rad);

    private:
      
      InrImage::ptr ref;
      InrImage::ptr radii;
      IntensityProfile _profile;
      
      /**
        Modele de Reconstruction:
        i.e. intensite en fonction de la distance au centre
      */
      double ModeleReconstruction(  const double& distance,  
                                    const double& rayon,
                                    const double& intensity );

    
      /**
       *  point1 sera nomme M1, point2 sera nomme M2, point0->M0, point3->M3
       *  dessin d'un cylindre a base d'une gaussienne circulaire dont
       *  le rayon varie linerairement de rayon1 au point M1 a rayon2 au point M2,
       *  Si un point M ne se projette sur aucun des 3 segments [M0,M1], [M1,M2] ou [M2,M3]
       *  alors on prend une sphere de centre l'extremite de [M1,M2] la plus proche
       */
      void DessineCylindre( 
                            const Point_3D<float>& point0,
                            const Point_3D<float>& point1,
                            const Point_3D<float>& point2,
                            const Point_3D<float>& point3,
                            float rayon1,
                            float rayon2,
                            InrImage::ptr ref,
                            InrImage::ptr recons
                          )  noexcept(false);
      
  };
}

#endif // _amiLineRecons_h_
