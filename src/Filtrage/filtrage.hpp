/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.4 $
 * $Log: filtrage.hpp,v $
 * Revision 1.4  2005/11/16 14:03:08  karl
 * added LGPL license
 *
 * Revision 1.3  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.2  2004/04/30 20:10:15  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.3  2000/10/02 16:57:15  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/19 12:19:03  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:10:21  karl
 * Sources code
 *
 * Revision 1.1  1998/12/03 16:18:05  kkrissia
 * *** empty log message ***
 *
 *
 ***************************************************************************/
//  
//  fichier filtrage.hpp
//
//  Karl Krissian    Sophia Antipolis, le 13-12-97
//
//  Realisation de differents type de filtrage
//  basee sur une fenetre centree en chaque point
//
//  Idees
//     option 2D, 3D
//     definition de la fenetre 2nx+1,2ny+1,2nz+1
//
//     Type de filtre: appel a une fonction de R^m dans R
//     qui a partir des points de la fenetre renvoie la nouvelle valeur
//
//     moyen, median, Gaussien, derivees, etc...
//     ecart-type, analyse du bruit ??
//
//  Probleme des bords ??


#ifndef _FILTRAGE_HPP
#define _FILTRAGE_HPP

#include "style.hpp"
#include "inrimage.hpp"
//#include "inrimage_compressee.hpp"
#include <math.h>
#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif

extern unsigned char debug;

typedef 
/** @name direction_filtre
 */
enum direction_filtre
{
  DIR_X,
  DIR_Y,
  DIR_Z
} direction_filtre;



//==========================================================================
///
class Filtrage
//     ========
{

protected:

/**
  Dimensions de l'image a traiter
 */
//@{
  ///
  int     _tx;
  ///
  int     _ty;
  ///
  int     _tz;
//@}

  /// nombre de points sur un ligne en x
  int     _pas_y; 
  /// nombre de points sur un plan en xy
  int     _pas_z; 

  /// fenetre (2*_nx+1) * (2*_ny+1) * (2*_nz+1)
  int     _nx,_ny,_nz;        

  /// tableau des points de la fenetre
  double* _tab_coeff;   

  /** la taille de _tab_coeff est _taille_div2+1
      la taille du support est 2*_taille_div2+1
  */
  int      _taille_div2; 
  double  _sigma;

  int      _facteur_support;

  int      _ordre;

  int      _x;
  int      _y;
  int      _z;

/**
  Valeur minimale et maximale lorsque l'on depasse les bords de l'image
 */
//@{
  double  _minval;
  double  _maxval;
//@}

  /// Coefficients du filtre: integrales de gaussienne
  unsigned char     _coeff_int_gauss;

public:

  //------------------------------------------------------------
  // Exceptions

  class OrdreNonTraite {};

  class BadImageType {};

  class ImagesDiffDim {};

  class GaussianNotInitialized {};

  //------------------------------------------------------------
  ///
  Constructeur Filtrage()
  //----------          
  {

    _tab_coeff = (double*) NULL;
    _ordre = -1;

    _facteur_support = 4;
    _taille_div2     = _facteur_support; 
    _coeff_int_gauss = false;

  }

  //------------------------------------------------------------
  ///
  virtual Destructeur  Filtrage()
  //        -----------
  {

    Si _tab_coeff != NULL Alors
      delete [] _tab_coeff;
    FinSi

  }

  //------------------------------------------------------------
  ///
  void FixeFacteurSupport( int facteur)
  //  
  {

    _facteur_support = facteur;

  }  


  //----------------------------------------------------------------------
  ///
  void IntegraleCoeffGaussienne()
  //
  {

    _coeff_int_gauss = true;

  } // IntegraleCoeffGaussienne()

  //------------------------------------------------------------
  ///
  double GaussienneInterp( double x) throw (OrdreNonTraite)
  //         ----------------
  {

    
      double gauss1,gauss2,sigma2,x1,x2;

    sigma2 = _sigma*_sigma;
    x1 = x-0.5;
    gauss1  = 1.0/sqrt(2.0*M_PI)/_sigma*exp( -0.5*(x1/_sigma)*(x1/_sigma));

    x2 = x+0.5;
    gauss2  = 1.0/sqrt(2.0*M_PI)/_sigma*exp( -0.5*(x2/_sigma)*(x2/_sigma));

    SelonQue _ordre Vaut
        Valeur 1: return ( gauss2 - gauss1);
        Valeur 2: return ( gauss2*(-1.0*x2/sigma2) - gauss1*(-1.0*x1/sigma2) );
        Defaut  : throw OrdreNonTraite(); 
    FinSelonQue

    //    return 0.0;

  } // GaussienneInterp()


  //------------------------------------------------------------
  ///
  double Gaussienne( double x) throw (OrdreNonTraite)
  //         ----------
  {

    
      double gauss,sigma2;

    Si (_coeff_int_gauss == false) Ou ( _ordre == 0) Alors
      gauss  = 1.0/sqrt(2.0*M_PI)/_sigma*exp( -0.5*(x/_sigma)*(x/_sigma));
      sigma2 = _sigma*_sigma;

      SelonQue _ordre Vaut
        Valeur 0: return gauss;
        Valeur 1: return gauss*(-1.0*x/sigma2);
        Valeur 2: return gauss*((x/sigma2)*(x/sigma2)-1/sigma2);
        Defaut  : throw OrdreNonTraite(); 
      FinSelonQue
    Sinon
      return GaussienneInterp(x);
    FinSi

    //    return 0.0;

  } // Gaussienne()


  //------------------------------------------------------------
  ///
  void InitGaussienne( float sigma, int facteur_support, int ordre)
  //   --------------
  {

    
      int i;
      int t;
      double somme_coeff = 0;

    _sigma       = sigma;

    t = (int) (sigma*facteur_support);
    Si t == 0 AlorsFait t = 1;

    Si (t!= _taille_div2)Ou(_tab_coeff == NULL) Alors
      _taille_div2 = t;
      Si _tab_coeff != NULL Alors
        delete [] _tab_coeff;
        _tab_coeff = NULL;
      FinSi
      _tab_coeff   = new double[ _taille_div2 + 1];

      _ordre       = ordre;

      Si ordre == 0 AlorsFait somme_coeff = 0.0;
      Pour( i, 0, _taille_div2)
        _tab_coeff[i] = Gaussienne( -i);
        Si ordre == 0 AlorsFait
	    Si i==0 Alors
              somme_coeff += _tab_coeff[i];
            Sinon
              somme_coeff += 2*_tab_coeff[i];
            FinSi
      FinPour

      Si ordre == 0 Alors
        Pour( i, 0, _taille_div2)
          _tab_coeff[i] /= somme_coeff;
        FinPour
      FinSi

    Sinon

      Si ordre != _ordre Alors

        _ordre       = ordre;
        Si ordre == 0 AlorsFait somme_coeff = 0.0;

        Pour( i, 0, _taille_div2)
          _tab_coeff[i] = Gaussienne( -i);
          Si ordre == 0 AlorsFait 
	    Si i==0 Alors
              somme_coeff += _tab_coeff[i];
            Sinon
              somme_coeff += 2*_tab_coeff[i];
            FinSi
        FinPour

        Si ordre == 0 Alors
          Pour( i, 0, _taille_div2)
            _tab_coeff[i] /= somme_coeff;
          FinPour
        FinSi

      FinSi
    FinSi

  } // InitGaussienne()


  //------------------------------------------------------------
  ///
  double FiltreDirXPair( float* entree)
  //
  {

    
      register float*       entree1;
      register float*       entree2;
      register int      i;
      register double  val,resultat;

    resultat = (*entree) * _tab_coeff[0];

    entree1 = entree + _taille_div2;
    entree2 = entree - _taille_div2;

    DebutBoucle i = _taille_div2 ItererTantQue i >= 1 Pas i-- Faire
      Si _x+i >= _tx Alors val  = _maxval; Sinon val  = *entree1; FinSi
      Si _x-i <  0   Alors val += _minval; Sinon val += *entree2; FinSi
      resultat += val*_tab_coeff[i];
      entree1--;
      entree2++;
    FinBoucle

    return resultat;

  } // FiltreDirXPair

  //------------------------------------------------------------
  ///
  double FiltreDirXImpair( float* entree)
  //
  {

    
      register float*       entree1;
      register float*       entree2;
      register int      i;
      register double  val,resultat;

    resultat = (*entree) * _tab_coeff[0];

    entree1 = entree + _taille_div2;
    entree2 = entree - _taille_div2;

    DebutBoucle i = _taille_div2 ItererTantQue i >= 1 Pas i-- Faire
      Si _x+i >= _tx Alors val  = _maxval; Sinon val  = *entree1; FinSi
      Si _x-i <  0   Alors val -= _minval; Sinon val -= *entree2; FinSi
      resultat += val*_tab_coeff[i];
      entree1--;
      entree2++;
    FinBoucle

    return resultat;

  } // FiltreDirXImpair

  //------------------------------------------------------------
  /// necessaire _pas_y, _tab_coeff, _minval, _maxval, ...
  double FiltreDirYPair( float* entree)
  //
  {

    
      register float*       entree1;
      register float*       entree2;
      register int      i;
      register double  val,resultat;

    resultat = (*entree) * _tab_coeff[0];

    entree1 = entree + _taille_div2*_pas_y;
    entree2 = entree - _taille_div2*_pas_y;

    DebutBoucle i = _taille_div2 ItererTantQue i >= 1 Pas i-- Faire
      Si _y+i >= _ty Alors val  = _maxval; Sinon val  = *entree1; FinSi
      Si _y-i <  0   Alors val += _minval; Sinon val += *entree2; FinSi
      resultat += val*_tab_coeff[i];
      entree1 -= _pas_y;
      entree2 += _pas_y;
    FinBoucle

    return resultat;

  } // FiltreDirYPair

  //------------------------------------------------------------
  ///
  double FiltreDirYImpair( float* entree)
  //
  {

    
      register float*       entree1;
      register float*       entree2;
      register int      i;
      register double  val,resultat;

    resultat = (*entree) * _tab_coeff[0];

    entree1 = entree + _taille_div2*_pas_y;
    entree2 = entree - _taille_div2*_pas_y;

    DebutBoucle i = _taille_div2 ItererTantQue i >= 1 Pas i-- Faire
      Si _y+i >= _ty Alors val  = _maxval; Sinon val  = *entree1; FinSi
      Si _y-i <  0   Alors val -= _minval; Sinon val -= *entree2; FinSi
      resultat += val*_tab_coeff[i];
      entree1 -= _pas_y;
      entree2 += _pas_y;
    FinBoucle

    return resultat;

  } // FiltreDirYImpair

  //------------------------------------------------------------
  /// necessaire _pas_y, _tab_coeff, _minval, _maxval, y
  double FiltreDirZPair( float* entree)
  //
  {

    
      register float*       entree1;
      register float*       entree2;
      register int      i;
      register double  val,resultat;

    resultat = (*entree) * _tab_coeff[0];

    entree1 = entree + _taille_div2*_pas_z;
    entree2 = entree - _taille_div2*_pas_z;

    DebutBoucle i = _taille_div2 ItererTantQue i >= 1 Pas i-- Faire
      Si _z+i >= _tz Alors val  = _maxval; Sinon val  = *entree1; FinSi
      Si _z-i <  0   Alors val += _minval; Sinon val += *entree2; FinSi
      resultat += val*_tab_coeff[i];
      entree1 -= _pas_z;
      entree2 += _pas_z;
    FinBoucle

    return resultat;

  } // FiltreDirZPair

  //------------------------------------------------------------
  ///
  double FiltreDirZImpair( float* entree)
  //
  {

    
      register float*       entree1;
      register float*       entree2;
      register int      i;
      register double  val,resultat;

    resultat = (*entree) * _tab_coeff[0];

    entree1 = entree + _taille_div2*_pas_z;
    entree2 = entree - _taille_div2*_pas_z;

    DebutBoucle i = _taille_div2 ItererTantQue i >= 1 Pas i-- Faire
      Si _z+i >= _tz Alors val  = _maxval; Sinon val  = *entree1; FinSi
      Si _z-i <  0   Alors val -= _minval; Sinon val -= *entree2; FinSi
      resultat += val*_tab_coeff[i];
      entree1 -= _pas_z;
      entree2 += _pas_z;
    FinBoucle

    return resultat;

  } // FiltreDirZImpair

  //------------------------------------------------------------
  ///
  void Filtre1D( InrImage* entree, InrImage* sortie, InrImage* masque,
  //   --------
		 direction_filtre dir, double sigma, int ordre)
    throw (BadImageType, ImagesDiffDim)

  {

    
  //      register int x,y,z;
      float*          entree_buf;
      float*          sortie_buf;
      unsigned char* masque_buf = NULL;


    Si (entree->_format!=WT_FLOAT) Ou (sortie->_format!=WT_FLOAT) 
    AlorsFait throw BadImageType();
 
    Si (masque != NULL)Et(masque->_format!=WT_UNSIGNED_CHAR)
    AlorsFait throw BadImageType();

    Si (entree->_tx) != (sortie->_tx) Ou
       (entree->_tx) != (sortie->_tx) Ou
       (entree->_tx) != (sortie->_tx) 
    AlorsFait throw ImagesDiffDim();

    _tx = entree->_tx;
    _ty = entree->_ty;
    _tz = entree->_tz;

    _pas_y = _tx;
    _pas_z = _tx * _ty;

    InitGaussienne( sigma, _facteur_support, ordre);

    entree_buf = (float*) entree->Buffer();
    sortie_buf = (float*) sortie->Buffer();
    Si masque != NULL AlorsFait
      masque_buf = (unsigned char*) masque->Buffer();

    Pour( _z, 0, _tz-1 )
    Pour( _y, 0, _ty-1 )
    Pour( _x, 0, _tx-1 )

      //      Si debug Et (_x==15)Et(_y==15)Et(_z==25)
      // AlorsFait
      //  printf( "Stop\n");

      Si (masque==NULL) Ou ((masque != NULL)Et(*masque_buf > 127)) 
      Alors

      SelonQue dir Vaut

        Valeur DIR_X:
          _minval = (*entree)(     0, _y, _z );
          _maxval = (*entree)( _tx-1, _y, _z );

          Si (ordre%2==0) Alors 
            *sortie_buf = FiltreDirXPair(   entree_buf);
          Sinon              
            *sortie_buf = FiltreDirXImpair( entree_buf);
          FinSi
        FinValeur

        Valeur DIR_Y:
          _minval = (*entree)( _x,     0, _z );
          _maxval = (*entree)( _x, _ty-1, _z );

          Si (ordre%2==0) Alors 
            *sortie_buf = FiltreDirYPair(   entree_buf);
          Sinon              
            *sortie_buf = FiltreDirYImpair( entree_buf);
          FinSi
        FinValeur

        Valeur DIR_Z:
          _minval = (*entree)( _x, _y,     0 );
          _maxval = (*entree)( _x, _y, _tz-1 );

          Si (ordre%2==0) Alors 
            *sortie_buf = FiltreDirZPair(   entree_buf);
          Sinon              
            *sortie_buf = FiltreDirZImpair( entree_buf);
          FinSi 
	  
        FinValeur

      FinSelonQue

      Sinon

        *sortie_buf = 0;

      FinSi // *masque_buf > 127

      entree_buf++;
      sortie_buf++;
      Si masque != NULL AlorsFait  masque_buf++;

    FinPour
    FinPour
    FinPour

  } // Filtre1D()


/*
  //------------------------------------------------------------
  ///
  void Filtre1DCompressee( InrImage* entree, 
  //   ------------------
			   InrImageCompressee* sortie, InrImage* masque,
			   direction_filtre dir, double sigma, int ordre)
    throw (BadImageType, ImagesDiffDim)

  {

    
  //      register int x,y,z;
      float*          entree_buf;
//      float*          sortie_buf;
      unsigned char* masque_buf = NULL;

    Si (entree->_format!=WT_FLOAT) Ou (sortie->_format!=WT_FLOAT) 
    AlorsFait throw BadImageType();
 
    Si (masque != NULL)Et(masque->_format!=WT_UNSIGNED_CHAR)
    AlorsFait throw BadImageType();

    Si (entree->_tx) != (sortie->_tx) Ou
       (entree->_tx) != (sortie->_tx) Ou
       (entree->_tx) != (sortie->_tx) 
    AlorsFait throw ImagesDiffDim();

    _tx = entree->_tx;
    _ty = entree->_ty;
    _tz = entree->_tz;

    _pas_y = _tx;
    _pas_z = _tx * _ty;

    InitGaussienne( sigma, _facteur_support, ordre);

    entree_buf = (float*) entree->Buffer();
//  sortie_buf = (float*) sortie->Buffer();
    Si masque != NULL AlorsFait
      masque_buf = (unsigned char*) masque->Buffer();

    sortie->InitBuffer();

    Pour( _z, 0, _tz-1 )
    Pour( _y, 0, _ty-1 )
    Pour( _x, 0, _tx-1 )

      //      Si debug Et (_x==15)Et(_y==15)Et(_z==25)
      // AlorsFait
      //  printf( "Stop\n");

      Si (masque==NULL) Ou ((masque != NULL)Et(*masque_buf > 127)) 
      Alors

      SelonQue dir Vaut

        Valeur DIR_X:
          _minval = (*entree)(     0, _y, _z );
          _maxval = (*entree)( _tx-1, _y, _z );

          Si (ordre%2==0) Alors 
             sortie->FixeValeur(FiltreDirXPair(   entree_buf));
          Sinon              
             sortie->FixeValeur(FiltreDirXImpair( entree_buf));
          FinSi
        FinValeur

        Valeur DIR_Y:
          _minval = (*entree)( _x,     0, _z );
          _maxval = (*entree)( _x, _ty-1, _z );

          Si (ordre%2==0) Alors 
            sortie->FixeValeur(FiltreDirYPair(   entree_buf));
          Sinon              
            sortie->FixeValeur(FiltreDirYImpair( entree_buf));
          FinSi
        FinValeur

        Valeur DIR_Z:
          _minval = (*entree)( _x, _y,     0 );
          _maxval = (*entree)( _x, _y, _tz-1 );

          Si (ordre%2==0) Alors 
            sortie->FixeValeur(FiltreDirZPair(   entree_buf));
          Sinon              
            sortie->FixeValeur(FiltreDirZImpair( entree_buf));
          FinSi
        FinValeur

      FinSelonQue

      Sinon

        sortie->FixeValeur(0);

      FinSi // *masque_buf > 127

      entree_buf++;
      sortie->IncBuffer();;
      Si masque != NULL AlorsFait  masque_buf++;

    FinPour
    FinPour
    FinPour


  } // Filtre1DCompressee()
*/

  //------------------------------------------------------------
  /** La Gaussienne doit deja etre initialisee
      avec InitGaussienne() ...
  */
  double Filtre1DPoint( InrImage* entree, 
  //         -------------
		 direction_filtre dir,
		 int x, int y, int z)
    throw (BadImageType, GaussianNotInitialized)
  {

    Si (entree->_format!=WT_FLOAT) AlorsFait throw BadImageType();
 
    _tx = entree->_tx;
    _ty = entree->_ty;
    _tz = entree->_tz;

    _pas_y = _tx;
    _pas_z = _tx*_ty;

    Si _tab_coeff == NULL AlorsFait throw GaussianNotInitialized();

    entree->BufferPos(x,y,z);

    _x = x;
    _y = y;
    _z = z;

    SelonQue dir Vaut

      Valeur DIR_X:
        _minval = (*entree)(     0, _y, _z );
        _maxval = (*entree)( _tx-1, _y, _z );

        Si (_ordre%2==0) Alors 
          return FiltreDirXPair(   (float*) entree->BufferPtr());
        Sinon              
          return FiltreDirXImpair( (float*) entree->BufferPtr());
        FinSi
	//      FinValeur

      Valeur DIR_Y:
        _minval = (*entree)( _x,     0, _z );
        _maxval = (*entree)( _x, _ty-1, _z );

        Si (_ordre%2==0) Alors 
          return FiltreDirYPair(   (float*) entree->BufferPtr());
        Sinon              
          return FiltreDirYImpair( (float*) entree->BufferPtr());
        FinSi
	//FinValeur

      Valeur DIR_Z:
        _minval = (*entree)( _x, _y,     0 );
        _maxval = (*entree)( _x, _y, _tz-1 );

        Si (_ordre%2==0) Alors 
          return FiltreDirZPair(   (float*) entree->BufferPtr());
        Sinon              
          return FiltreDirZImpair( (float*) entree->BufferPtr());
        FinSi
	//FinValeur

    FinSelonQue

    return 0.0;

  } // Filtre1DPoint()


}; // Filtrage


#endif // _FILTRAGE_HPP
