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
 * $Revision: 1.2 $
 * $Log: inrimage_template.hpp,v $
 * Revision 1.2  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.2  2000/09/19 12:19:09  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:12:10  karl
 * Sources code
 *
 * Revision 1.2  1998/10/02 20:08:17  kkrissia
 * Creation d'une classe InrImage Template
 *
 ***************************************************************************/

//  Fichier inrimage_base.hpp
// 


#ifndef _INRIMAGE_TEMPLATE_HPP
#define _INRIMAGE_TEMPLATE_HPP

#include "style.hpp"
#include "chaine.hpp"

//@Include: /u/broca/0/kkrissia/Sources/Prog/Commun/include/chaine.doc  /user/jmontagn/src/Zinrimage/*.h

#include "inrimage_base.hpp"

//using -- namespace std;

//=========================================================================


/** 
  class de template contenant des variables et fonctions
  communes a tous les types d'images
*/
template <class T>
class InrImageTemplate : public InrImageBase
//     ================
{

protected:

  // buffer permettant la gestion d'images
  T*         _buffer;

/** @name Positions
  tableau de pointeurs permettant d'acc�der directement
   au debut de la ligne:
   _positions[z][y] pointe sur l'adresse de l'element (x=0,y,z)
   dans le buffer de l'image
*/
  T***       _positions;


  /// initialisation du tableau de positions _positions[z][y]
  unsigned char   InitPositions();

  /// initialisation du tableau de positions _positions[z][y]
  unsigned char   FreePositions();

public:

  /** @name 2-Diff�rents constructeurs  et le destructeur */
  //@{
    ///
     InrImageTemplate( )
    {    }

    ///
     InrImageTemplate( const char* nom)
      : InrImageBase(nom)
    { InitPositions();    }

    /// Pour des fichier d'un autre format
     InrImageTemplate( const char* nom, int type)
      : InrImageBase(nom, type)
    { InitPositions();    }

    ///
     InrImageTemplate( int dimx, 
				   int dimy, 
				   int dimz, const char* nom=NULL)
      : InrImageBase( dimx, dimy, dimz, nom)
    {    
      _format = GetFormat();
      _vdim   = VectorDim[_format];
      Si (long) sizeof(T)*VectorDim[_format] != (long) TailleFormat[_format]*_vdim Alors
       std::cout << "probleme entre le format et le type donne...\n";
      FinSi
      Alloue();
      InitPositions();    
    }

    ///
    ~InrImageTemplate( )
    { FreePositions();}
  //@}

  virtual WORDTYPE GetFormat();// { return _format;}

  /** @name 4-M�thode li�es � la gestion du buffer */
  //@{
    /** Op�ration de parcours de buffer inter-formats
     */
    virtual void InitBuffer( int pos = 0);
    //           ----------

    ///  
    virtual void BufferPos( int x, int y, int z);
    //           ---------

    /**
       Fonction en ligne
       Incr�mentation du buffer
    */
    virtual void IncBuffer( int inc=1);
    //           ---------

    /**
       Renvoie la valeur de l'image � la position courante du buffer
    */
    double ValeurBuffer( );
    //         ------------

    //
    double ValeurBuffer( int inc);
    //         ------------
    // Renvoie la valeur du buffer+inc

    /**
      Renvoie la valeur du buffer pour la coordonnee i (0:x, 1:y, 2:z)
    */
    virtual double VectValeurBuffer( int i );
    //                 ----------------


    /// Fixe la valeur de l'image au point courant du buffer
    void FixeValeur( double val);
    //   ----------

    /// Fixe la valeur de l'image au point courant du buffer
    virtual void VectFixeValeurs( double valx, 
    //           ---------------
			  double valy, 
			  double valz);

  //@}



  /** @name 6-Red�finitions d'op�rateurs */
  //@{

    //  {\bf Operator(x,y,z) }
    double operator()( int x, int y, int z);
    //         --------

    //  {\em Operator(x,y,z,coord) }
     virtual double operator()( int x, int y, int z, 
    //                  --------
				    int coord);

  //@}


  /** @name 7-M�thodes plus �volu�es */
  //@{

  ///
  InrImageBase* CreeSousImage( int min_x, int max_x, 
			       int min_y, int max_y,
			       int min_z, int max_z);

  ///
  void MinMax(float* min, float* max);

  // Interpolation Lin�aire de l'intensit� au point (x,y,z)
  double InterpLinIntensite2( float dx1, float dx2, int tx1, int tx2);
  //         -------------------

  /** Interpolation Lin�aire de l'intensit� au point (x,y,z)
   en coordonn�es r�elles
   Prendre en compte la taille des voxels ???
   Pour une image 3D ...
  */
  double InterpLinIntensite( float x, float y, float z);
  //         ------------------

  ///
  void VoisinageYZ( int x, int y, int z, float** vois);
  //   -----------

  //@}

}; // InrImageTemplate


//=======================================================================================
// Definition des methodes privees
//=======================================================================================


//-----------------------------------------------------------------------
template <class T>
unsigned char InrImageTemplate<T>::InitPositions()
{
   
    int z,y;
    int txy;

  txy = _tx*_ty;

  _positions = new T**[_tz];
  Pour( z, 0, _tz-1)
    _positions[z] = new T*[ _ty];
    Pour( y, 0, _ty-1)
      _positions[z][y] = (T*)_inrimage->data+VectorDim[_format]*(z*txy+y*_tx);
    FinPour
  FinPour

  return true;
}


//-----------------------------------------------------------------------
template <class T>
unsigned char InrImageTemplate<T>::FreePositions()
{
   
    int z;

  Pour(z,0,_tz-1) delete [] _positions;FinPour
  delete [] _positions;

  return true;
}



//=======================================================================================
// Definition des methodes publiques
//=======================================================================================


//-----------------------------------------------------------------------
// Fonction li�es au buffer
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
template <class T>
inline void InrImageTemplate<T>::InitBuffer( int pos)
{
  _buffer = (T*) _inrimage->data + pos;  
}

//-----------------------------------------------------------------------
template <class T>
inline void InrImageTemplate<T>::BufferPos( int x, int y, int z)
{
  _buffer = (_positions[z][y] + x); 
}

//-----------------------------------------------------------------------
template <class T>
inline void InrImageTemplate<T>::IncBuffer( int inc)
{
  _buffer += inc;
}

//-----------------------------------------------------------------------
template <class T>
inline double InrImageTemplate<T>::ValeurBuffer( )
{
  return (double) (*_buffer);
}

//-----------------------------------------------------------------------
template <class T>
inline double InrImageTemplate<T>::ValeurBuffer(  int inc)
{
  return (double) (*_buffer + inc);
}

//-----------------------------------------------------------------------
template <class T>
inline double InrImageTemplate<T>::VectValeurBuffer( int i )
{
  return (double) _buffer[i];
}

//-----------------------------------------------------------------------
template <class T>
inline void InrImageTemplate<T>::FixeValeur( double val)
{
  *_buffer = (T) val;
  // Il faut gerer a part les images de vecteurs ??
} 

//-----------------------------------------------------------------------
template <class T>
inline void InrImageTemplate<T>::VectFixeValeurs( double valx, 
					   double valy, 
					   double valz)
{
  _buffer[0]   = (T)  valx;
  _buffer[1]   = (T)  valy;
  _buffer[2]   = (T)  valz;
}

//-----------------------------------------------------------------------
// Red�finitions d'op�rateurs
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
template <class T>
inline double InrImageTemplate<T>::operator()( int x, int y, int z)
{
   return (double)(_positions[z][y][x]);
}
 
//-----------------------------------------------------------------------
template <class T>
inline double InrImageTemplate<T>::operator()( int x, int y, int z, 
					       int coord)
{
  return (double)(_positions[z][y][_vdim*x+coord]);
}
 

//-----------------------------------------------------------------------
// M�thodes plus �volu�es
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
template <class T>
InrImageBase* InrImageTemplate<T>:: CreeSousImage( 
			       int min_x, int max_x, 
			       int min_y, int max_y,
			       int min_z, int max_z)
{
  
    InrImageTemplate<T>*  res;
    int                x,y,z;

  Si (max_x < min_x) Ou (max_y < min_y) Ou (max_z < min_z) Ou
     (min_x < 0)     Ou (min_y < 0)     Ou (min_z < 0)     Ou
     (max_x > _tx)   Ou (max_y > _ty)   Ou (max_z > _tz)     
  Alors
    return NULL;
  FinSi

  res = new InrImageTemplate<T>( max_x - min_x + 1, max_y - min_y + 1, max_z - min_z +1);
  
  Pour( z, 0, res->_tz-1 )
  Pour( y, 0, res->_ty-1 )
  Pour( x, 0, res->_tx-1 )

     ((T*) res->_inrimage->data)[ (z*_ty + y)*_tx + x ] = 
     ((T*)      _inrimage->data)[ ((z+min_z)*_ty + (y+min_y))*_tx + x + min_x];

  FinPour
  FinPour
  FinPour
  
  return( res);
}

//-----------------------------------------------------------------------
template <class T>
void InrImageTemplate<T>::MinMax(float* min, float* max)
{

  
       T*  buf;
       long n;

  buf = (T*) _inrimage->data;
  *min = *max = *buf;
  for(  n=0 ;  n < _tx*_ty*_tz ;  n++ Faire
    Si *buf < *min AlorsFait *min = *buf;
    Si *buf > *max AlorsFait *max = *buf;
    buf++;
  } // end for // n

}

//-----------------------------------------------------------------------
template <class T>
double InrImageTemplate<T>::InterpLinIntensite2( float dx1, float dx2, 
						 int tx1, int tx2)
{

    
      register double coeff00,coeff01,coeff10,coeff11;
      register double res;

    coeff00 = 1.0 - dx1;
    coeff10 = dx1;

    coeff01 = coeff00 * dx2;
    coeff11 = coeff10 * dx2;

    coeff00 -= coeff01;
    coeff10 -= coeff11;

    res  = coeff00* *(_buffer)     + coeff10* *(_buffer+tx1)  +
           coeff01* *(_buffer+tx2) + coeff11* *(_buffer+tx1+tx2);

    return res;

}


//-----------------------------------------------------------------------
template <class T>
double InrImageTemplate<T>::InterpLinIntensite( float x, float y,  float z)
{

    
      register int     xi,yi,zi;
      register double dx,dy,dz;
      register double res;
      register double coeff000,coeff010,coeff100,coeff110;
      register double coeff001,coeff011,coeff101,coeff111;

    Si (x < 0) Ou ( x > _tx-1) Ou
       (y < 0) Ou ( y > _ty-1) Ou
       (z < 0) Ou ( z > _tz-1) AlorsRetourne 0;

    xi = (int) x;           
    yi = (int) y;           
    zi = (int) z;

    dx = x - (double)xi;   
    dy = y - (double)yi;   
    dz = z - (double)zi;

    Si xi == _tx-1 Alors      xi = _tx-2;      dx = 1.0;    FinSi
    Si yi == _ty-1 Alors      yi = _ty-2;      dy = 1.0;    FinSi
    Si zi == _tz-1 Alors      zi = _tz-2;      dz = 1.0;    FinSi

    Si dx < 1E-10 Alors
      BufferPos(xi,yi,zi);
      return InterpLinIntensite2(dy,dz,_tx,_txy);
    FinSi

    Si dy < 1E-10 Alors
      BufferPos(xi,yi,zi);
      return InterpLinIntensite2(dx,dz,1,_txy);
    FinSi

    Si dz < 1E-10 Alors
      BufferPos(xi,yi,zi);
      return InterpLinIntensite2(dx,dy,1,_tx);
    FinSi

    /*--- calcul des poids associ�s � chaque point ---*/
    // 16 multiplication, 12 additions, 8 affectations
    // coeff000 = (1.0 - dx) * (1.0 - dy) * (1.0 - dz);
    // coeff100 = dx         * (1.0 - dy) * (1.0 - dz);
    // coeff010 = (1.0 - dx) * dy         * (1.0 - dz);
    // coeff110 = dx         * dy         * (1.0 - dz);
    // coeff001= (1.0 - dx) * (1.0 - dy)  * dz;
    // coeff101 = dx         * (1.0 - dy) * dz;
    // coeff011 = (1.0 - dx) * dy         * dz;
    // coeff111 = dx         * dy         * dz;


    // 6 multiplication, 7 additions, 14 affectations
    coeff000 = 1.0 - dx;
    coeff100 = dx;

    coeff010 = coeff000 * dy;
    coeff110 = coeff100 * dy;

    coeff000 -= coeff010;
    coeff100 -= coeff110;

    coeff001 = coeff000*dz; 
    coeff101 = coeff100*dz; 
    coeff011 = coeff010*dz; 
    coeff111 = coeff110*dz; 

    coeff000 -= coeff001;
    coeff100 -= coeff101;
    coeff010 -= coeff011;
    coeff110 -= coeff111;

    _buffer = (_positions[zi][yi] + xi); 
    res  = coeff000* *(_buffer)          + coeff100* *(_buffer+1);
    res += coeff010* *(_buffer+_tx)      + coeff110* *(_buffer+_tx+1);
    res += coeff001* *(_buffer+_txy)     + coeff101* *(_buffer+_txy+1);
    res += coeff011* *(_buffer+_txy+_tx) + coeff111* *(_buffer+_txy+_tx+1);

    return res;

}


//-----------------------------------------------------------------------
template <class T>
void InrImageTemplate<T>::VoisinageYZ( int x, int y, int z, 
				       float** vois)
{
  vois[0][0] = (float) _positions[z]  [y]  [x];
  vois[0][1] = (float) _positions[z+1][y]  [x];
  vois[1][0] = (float) _positions[z]  [y+1][x];
  vois[1][1] = (float) _positions[z+1][y+1][x];
}


#endif // _INRIMAGE_TEMPLATE_HPP
