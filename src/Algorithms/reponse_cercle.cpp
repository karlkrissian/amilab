/***************************************************************************
 * $Author: karl $
 * $Revision: 1.1.1.1 $
 * $Log: reponse_cercle.cpp,v $
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:08:28  karl
 * Sources code
 *
 * Revision 1.7  1998/10/02 20:10:01  kkrissia
 * Creation d'une classe InrImage Template
 *
 */

#include "reponse_cercle.hpp"
#include <iostream>

#include <limits>
using namespace std;

bool sort_operator(const response_info& r1,const response_info& r2)
{ 
  return r1.radius_gradient > r2.radius_gradient; 
}

//======================================================================
// MEMBRES PRIVES
//======================================================================

/*============================================================*/


//--------------------------------------------------------------------------------
unsigned char  CalculRepCercle :: GradientCorrect( const Vect3D<double>& p)
//                                   ---------------
{

    return (
            (p.x > 1) Et ( p.x < _image->_tx-2) Et
            (p.y > 1) Et ( p.y < _image->_ty-2) Et
            (p.z > 1) Et ( p.z < _image->_tz-2) 
           );

} // GradientCorrect()


//======================================================================
// MEMBRES PUBLICS
//======================================================================


//----------------------------------------------------------------------
///
CalculRepCercle ::  CalculRepCercle( InrImage* image, CircleResponseType type_reponse)
//                           ------------
{

  _image        = image;

  _coord_image  = new CoordImage(image);

  _type_reponse = type_reponse;
  
  nb_points  = nb_points2    = 0;

  _filter = NULL;
  _grad   = NULL;

  _NoLinearInterp = false;
  _OptReponse     = false;

  ReducePairs(  true, PAIRS_MIN);
  useSD(        0.7);
  useEXC(       1);
  KeepHighest(  70);

  coeff_cos = coeff_sin = (double*) NULL;

}


//----------------------------------------------------------------------
///
CalculRepCercle :: ~CalculRepCercle()
//                           -----------
{
  delete [] coeff_cos;
  delete [] coeff_sin;

  delete _coord_image;
}


//----------------------------------------------------------------------
///
void CalculRepCercle :: FixeRayon( double rayon, float coeff_rayon)
//                                ---------
{
    double alpha;
    int    i;
    float  radius_x,radius_y,radius_z;
    float  radius_vox;


    _rayon = rayon;

    Si coeff_rayon > 0.0 AlorsFait _rayon *= coeff_rayon;


// Pour des gros rayons, il est tres lent de calculer la reponse
// sur un nombre de points eleve (par exemple 50 points),
// du fait des gros lissage, des points proches auront les gradients proches
// et le nombre de points utilises ne depend alors plus du rayon ...

    radius_x = _rayon/_image->_size_x;
    radius_y = _rayon/_image->_size_y;
    radius_z = _rayon/_image->_size_z;
    radius_vox = sqrt(radius_x*radius_x +
          radius_y*radius_y +
          radius_z*radius_z);

    // ancienne version:
    Si _OptReponse Alors

      Si coeff_rayon > 1.0 Alors
        nb_points2 = ((int) (PI*coeff_rayon + 1));
      Sinon
        nb_points2 = ((int) (PI + 1));
      FinSi

    Sinon
      nb_points2  = ((int) (PI*radius_vox + 1));
    FinSi

    Si nb_points2>10 AlorsFait nb_points2 = 10;

    nb_points   = 2*nb_points2;

   std::cout << "Rayon    = " << _rayon << std::endl;
   std::cout << "NbPoints = " << nb_points << std::endl;

    coeff_cos      = new double[ nb_points2];
    coeff_sin      = new double[ nb_points2];
    alpha       = 0;
    d_alpha     = (double) (2.0 * PI / nb_points);
    // Precompute coefficients
    for(i = 0; i < nb_points2; i++) {
      coeff_cos[i] = cos(alpha);
      coeff_sin[i] = sin(alpha);
      alpha   += d_alpha;
    }
} // FixeRayon

  
//----------------------------------------------------------------------------
void  CalculRepCercle :: ComputeResponse( const Vect3D<double>& pos, 
//                      ---------------
                                        const Vect3D<double>& vect,
                                        response_info& response)
{
      register Vect3D<double>     g;
      float                        gx,gy,gz;
      double rep;

    if (!(GradientCorrect(pos))) {
      response.radius_gradient  = 0;
      response.tangent_gradient = 0;
      return;
    }

    // Check for linear interpolation flag
    if (_NoLinearInterp) {
      int posx = (int) (pos.x+0.5);
      int posy = (int) (pos.y+0.5);
      int posz = (int) (pos.z+0.5);
      if (_filter!= NULL) 
          g = _filter->Gradient( posx,posy,posz);
      else {
        // buffer pos is not thread safe ...
        _grad->BufferPos(posx,posy,posz);
        g.Init( _grad->ValeurBuffer(0),
                _grad->ValeurBuffer(1),
                _grad->ValeurBuffer(2));
      }
    } else {
      if (_filter!= NULL) 
          g = _filter->Gradient( pos.x , pos.y, pos.z);
      else {
          gx = _grad->InterpLinIntensite(pos.x,pos.y,pos.z,0);
          gy = _grad->InterpLinIntensite(pos.x,pos.y,pos.z,1);
          gz = _grad->InterpLinIntensite(pos.x,pos.y,pos.z,2);
          g.Init(gx,gy,gz);
      }
    }

    // since for bright tubes, the gradient is oriented inwards
    // take a positive response by multiplying by -1
    rep = -1.0*( g * vect) ;

    // Save response
    response.radius_gradient = rep;
    //        Si rep > 0 AlorsFait rep = 0;
    if (_use_EXC)
        response.tangent_gradient = Norme(g + (rep*vect));

} // ComputeResponse()

//----------------------------------------------------------------------
///
void  CalculRepCercle::CalculReponses(  const int& x, 
                                        const int& y, 
                                        const int& z, 
                                        const Vect3D<double>& vep0,
                                        const Vect3D<double>& vep1,
                                        const float& rap_ellipse  )
{
      /*---  Variables pour int�grer la r�ponse le long d'un cercle ---*/
      int    k;
      double coeff_v1;
      double coeff_v2;
      register Vect3D<double>     g;
      register Vect3D<double>     vecteur;
      Vect3D<double>              displacement;
      Vect3D<double>              p(x,y,z);
      register Vect3D<double>     pos;
      float                       radius_x,radius_y,radius_z;
      response_info               rep1,rep2;


    /*--- calcul de la reponse du filtre gradient par integrale le long 
     *    du cercle de centre (x,y,z) de rayon sigma dans le plan // a (v1,v2)
     */
    // empty vector of responses
    responses.clear();

    if ((x==20)&&(y==7)&&(z==35)) {
      std::cout << " at 20,7,35" << std::endl;
    }
                   
    k         = 0;

    radius_x = _rayon/_image->_size_x;
    radius_y = _rayon/_image->_size_y;
    radius_z = _rayon/_image->_size_z;

    for(k = 0;  k<nb_points2; k++) {
      coeff_v1 = coeff_cos[k];
      coeff_v2 = coeff_sin[k];
      Si rap_ellipse != 1 AlorsFait
        coeff_v2 /= rap_ellipse;

      /*--- calcul de la position ---*/
      vecteur      = (coeff_v1*vep0) + (coeff_v2*vep1);
      displacement = Vect3D<double>( vecteur.x*radius_x,
                                    vecteur.y*radius_y,
                                    vecteur.z*radius_z);

      //
      // First point
      //
      pos = p + displacement;
      this->ComputeResponse(pos,vecteur, rep1);

      if ((x==20)&&(y==7)&&(z==35)) {
        std::cout << " k = " << k << " rep1 = " << rep1.radius_gradient << std::endl;
      }

//
      // Second point: opposite point for the circle
      //
      pos = p + (-1.0)*displacement;
      vecteur = -1.0*vecteur;
      this->ComputeResponse(pos,vecteur, rep2);

      if ((x==20)&&(y==7)&&(z==35)) {
        std::cout << " k = " << k << " rep2 = " << rep2.radius_gradient << std::endl;
      }

      // if combining opposite point create only 1 response out of the 2 points
      if (_reduce_pairs) {
        switch(_pairs_type) {
          case PAIRS_MEAN:
            rep1.radius_gradient  += rep2.radius_gradient;
            rep1.tangent_gradient += rep2.tangent_gradient;
            rep1.radius_gradient  /= 2.0;
            rep1.tangent_gradient /= 2.0;
            responses.push_back(rep1); 
          break;
          case PAIRS_MIN:
            if (rep1<rep2) 
              responses.push_back(rep1); 
            else 
              responses.push_back(rep2);
          break;
          case PAIRS_MAX:
            if (rep2<rep1) 
              responses.push_back(rep1); 
            else 
              responses.push_back(rep2);
          break;
        }
      } else {
      // else adds both points to the vector
        responses.push_back(rep1); 
        responses.push_back(rep2); 
      } // if _reduce_pairs
    } // end for 

} // CalculReponses()
 

//----------------------------------------------------------------------
///
double CalculRepCercle::Reponse ( )
//                      -------
{
  response_info rep;
  std::vector<response_info>::iterator Iter;
  double result = 0;
  int pos;

  if (responses.empty()) return 0;

  // if applying median, reduce the vector to the highest values
  if (_keep_highest) {
    // 1. sort the vector, decreasing order
    std::sort(responses.begin(),responses.end(),sort_operator);
    // dropping elements
    size_t new_size = (int) (_highest_percentage*responses.size()/100.0);
    responses.resize(new_size);
  }

  // here use vector iterators
  switch ( GetResponseType() )
  {
    case circle_min:
      // vector already sorted in decreasing order
      if (_keep_highest)
        return responses.back().radius_gradient;

#ifdef max
#undef max
	  rep.radius_gradient = 
		  numeric_limits<float>::max();
#endif
      for(Iter = responses.begin();
          Iter != responses.end();
          Iter++)
        if (*Iter<rep) rep = *Iter;
      result = rep.radius_gradient;
    break;

    case circle_mean:
      result = 0;
      for(Iter = responses.begin();
          Iter != responses.end();
          Iter++)
        result += Iter->radius_gradient;
      result /= (1.0*responses.size());
    break;

    case circle_median:
      if (!_keep_highest) {
        sort(responses.begin(),responses.end());
      }

      Iter = responses.begin();
      pos = 0;
      while ( pos < (int) (responses.size()/2.0) ) {
        Iter++;
        pos++;
      }
      result = Iter->radius_gradient;
    break;
  } // end switch type_rep


   if ((_use_EXC)&&(GetResponseType()==circle_mean)) {
    double res_tang = 0;
    for(Iter = responses.begin();
        Iter != responses.end();
        Iter++)
      res_tang += Iter->tangent_gradient;
    res_tang /= (1.0*responses.size());

    if (result>1E-3) {
      double coeff_exc = fabs ( res_tang/result ) /_SeuilEXC;
      coeff_exc =  exp ( -1.0 * coeff_exc*coeff_exc );

      result *=  coeff_exc;
    }
  }

  if (_use_SD) {
    double mean = 0;
    double mean_squared = 0;
    double sdv,coeff_sdv;

    mean         = 0;
    mean_squared = 0;
    for(Iter  = responses.begin(); 
        Iter != responses.end(); 
        Iter++)
    {
      mean         += Iter->radius_gradient;
      mean_squared += Iter->radius_gradient*Iter->radius_gradient;
    }

    mean         /= responses.size();
    mean_squared /= responses.size();

    //----- Coeff Ecart Type
    sdv = sqrt ( mean_squared-mean*mean );
    if ((mean<1E-5)||(_SeuilET<1E-5))
      return 0;
    coeff_sdv = fabs ( sdv/mean ) /_SeuilET;
    coeff_sdv = exp ( -1.0 * coeff_sdv*coeff_sdv );
    result *= coeff_sdv ;
  }

  return result;

} // Reponse( )


