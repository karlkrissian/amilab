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
 * $Revision: 1.5 $
 * $Log: Coordonnees.hpp,v $
 * Revision 1.5  2006/01/09 17:59:04  karl
 * current version
 *
 * Revision 1.4  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.3  2004/08/27 23:21:24  karl
 * all for automatic grab of results for Book Chapter
 *
 * Revision 1.2  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.1.1.1  2004/02/02 20:47:09  karl
 * source code in C++
 *
 * Revision 1.3  2001/03/02 11:49:35  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/19 12:19:11  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:08:34  karl
 * Sources code
 *
 * Revision 1.3.0.3  1998/10/02 20:59:27  kkrissia
 * creation: objets generiques  Point et Vecteur (2D et 3D)
 *
 */
//
// Definition des operations de base sur des
// Points et des Vecteurs dans un espace a 2 ou 3 dimensions
//

#ifndef COORDONNEES_HPP
#define COORDONNEES_HPP



#include <iostream>
using namespace std;

#include "math.h"
#include "style.hpp"


class NormeFaible {};

#ifdef EPSILON
#undef EPSILON
#endif
#define EPSILON 1E-5

//============================================================
//  DIMENSION 2
//============================================================

template <class T> class Vect2D;

template < class T > class Point2D;

template <class T>
 Vect2D<T> operator-( Point2D<T>& p1, Point2D<T>& p2);

template <class T>
ostream& operator<<( ostream&s, Point2D<T>& pt);

//==============================================================
/**
  Point dans un espace a 2 dimensions
 */
template < class T >
class Point2D 
//     -------
{

public:

  //
  T x;

  //
  T y;


  /**
    {\em Constructor} par d�faut
   */
   Point2D() {}
  //----------

  /**
    {\em Constructor}
   */
   Point2D( T x0, T y0) { x=x0; y=y0;}
  //----------

  /**
    {\em Destructor}
   */
  ~Point2D() {}
  //---------

  /**
   */
  void Init( T x0, T y0) { x=x0; y=y0;}

  /**
   */
  Point2D<T>& operator=( const Point2D<T>& p)
  //         ---------
  {
    x        = p.x;
    y        = p.y;
    return(*this);
  }


#if !(defined(_sgi_))

  /**
    Soustraction de 2 points -> 1 Vecteur
   */
  friend Vect2D<T> operator- <> ( Point2D<T>& p1, Point2D<T>& p2);
  //               ---------

  /**
   */
  friend ostream& operator<< <> ( ostream&s, Point2D<T>& pt);

#else

  /**
    Soustraction de 2 points -> 1 Vecteur
   */
  friend 
  Vect2D<T> operator-  ( Point2D<T>& p1, Point2D<T>& p2);
  //               ---------

  /**
   */
  friend 
  ostream& operator<<  ( ostream&s, Point2D<T>& pt);

#endif

}; // Point2D<T>

//==============================================================

template <class T> T Norme( Vect2D<T>&);
  

/**
 */
template <class T> ostream& operator<<( ostream&s, Vect2D<T>& pt);

/**
  soustraction de 2 Vecteurs
 */
template <class T> Vect2D<T> operator-( Vect2D<T>, Vect2D<T>);

/**
  addition de 2 Vecteurs
 */
template <class T> Vect2D<T> operator+( Vect2D<T>, Vect2D<T>);

/**
  produit scalaire de 2 Vecteurs
 */
template <class T> T operator*( Vect2D<T>, Vect2D<T>);

/**
  produit vectoriel de 2 Vecteurs
 */
template <class T> T operator^( Vect2D<T>, Vect2D<T>);

/**
  Egalite de vecteurs
*/
template <class T> unsigned char  operator==( Vect2D<T>, Vect2D<T>);

/**
    Egalite approximative de vecteurs: Norme(v2-v1)< epsilon
*/
template <class T> unsigned char  Proche( Vect2D<T> v1 , Vect2D<T> v2, float epsilon);

//==============================================================
/**
  Vecteur dans un espace a 2 dimensions
 */
template < class T >
class Vect2D 
//     ------
{

public:

  //
  T x;
  
  //
  T y;


  /**
    {\em Constructor} par d�faut
   */
 Vect2D() {}
  //----------

  /**
    {\em Constructor}
   */
   Vect2D( T x0, T y0) { x=x0; y=y0;}
  //----------

  /**
   */
  void Init( T x0, T y0) { x=x0; y=y0;}

  /**
    {\em Destructor}
   */
  ~Vect2D() {}
  //---------


  /**
   */
  Vect2D<T>& operator=( const Vect2D<T>& p)
  //         ---------
  {
    x        = p.x;
    y        = p.y;
    return(*this);
  }

  //---------------------------------
  // Fonctions Amies
  //---------------------------------

#if !(defined(_sgi_))

  /**
    Norme du vecteur
   */
  friend T Norme<>( Vect2D<T>&);
  

  /**
   */
  friend ostream& operator<< <>( ostream&s, Vect2D<T>& pt);

  /**
    soustraction de 2 Vecteurs
   */
  friend Vect2D<T> operator- <>( Vect2D<T>, Vect2D<T>);

  /**
    addition de 2 Vecteurs
   */
  friend Vect2D<T> operator+ <>( Vect2D<T>, Vect2D<T>);

  /**
    produit scalaire de 2 Vecteurs
   */
  friend T operator* <>( Vect2D<T>, Vect2D<T>);

  /**
    produit vectoriel de 2 Vecteurs
   */
  friend T operator^ <>( Vect2D<T>, Vect2D<T>);

  /**
    Egalite de vecteurs
  */
  friend unsigned char  operator== <>( Vect2D<T>, Vect2D<T>);

  /**
    Egalite approximative de vecteurs: Norme(v2-v1)< epsilon
  */
  friend unsigned char  Proche <>( Vect2D<T> v1 , Vect2D<T> v2, float epsilon);

#else

  /**
    Norme du vecteur
   */
  friend T Norme( Vect2D<T>&);
  

  /**
   */
  friend ostream& operator<< ( ostream&s, Vect2D<T>& pt);

  /**
    soustraction de 2 Vecteurs
   */
  friend Vect2D<T> operator- ( Vect2D<T>, Vect2D<T>);

  /**
    addition de 2 Vecteurs
   */
  friend Vect2D<T> operator+ ( Vect2D<T>, Vect2D<T>);

  /**
    produit scalaire de 2 Vecteurs
   */
  friend T operator* ( Vect2D<T>, Vect2D<T>);

  /**
    produit vectoriel de 2 Vecteurs
   */
  friend T operator^ ( Vect2D<T>, Vect2D<T>);

  /**
    Egalite de vecteurs
  */
  friend unsigned char  operator== ( Vect2D<T>, Vect2D<T>);

  /**
    Egalite approximative de vecteurs: Norme(v2-v1)< epsilon
  */
  friend unsigned char  Proche ( Vect2D<T> v1 , Vect2D<T> v2, float epsilon);

#endif

}; // Vect2D<T>

//============================================================
// Point2D

/**
 */
template < class T >
Vect2D<T> operator-( Point2D<T>& p1, Point2D<T>& p2)
//        ---------
{
  return Vect2D<T>( p1.x-p2.x, p1.y-p2.y);
}

/**
 */
template < class T >
ostream& operator<<( ostream&s, Point2D<T>& pt)
//       ----------
{
  return s << '(' << pt.x << ',' << pt.y << ')';
}


//============================================================
//  Vect2D 
//============================================================


//----------------------------------------------------------
/**
 */
template < class T >
T  Norme( Vect2D<T>& v)
// -----
{
  return sqrt(v.x*v.x+v.y*v.y);
}




//----------------------------------------------------------
/**
 */
template < class T >
ostream& operator<<( ostream&s, Vect2D<T>& v)
//       ----------
{
  return s << '(' << v.x << ',' << v.y << ')';
}


//----------------------------------------------------------
/**
 */
template < class T >
Vect2D<T> operator-( Vect2D<T> v1, Vect2D<T> v2)
//        ---------
{
  Vect2D<T> v;

  v.x = v1.x-v2.x;
  v.y = v1.y-v2.y;

  return v;
}


//----------------------------------------------------------
/**
 */
template < class T >
Vect2D<T> operator+( Vect2D<T> v1, Vect2D<T> v2)
//        ---------
{
  Vect2D<T> v;

  v.x = v1.x+v2.x;
  v.y = v1.y+v2.y;

  return v;
}


//----------------------------------------------------------
/**
 */
template < class T >
T operator*( Vect2D<T> v1, Vect2D<T> v2)
//        ---------
{
  return (v1.x*v2.x+v1.y*v2.y);
}


//----------------------------------------------------------
/**
 */
template < class T >
T operator^( Vect2D<T> v1, Vect2D<T> v2)
// ---------
{

  return (v1.x*v2.y-v1.y*v2.x);
}


//----------------------------------------------------------
/**
 */
template < class T >
unsigned char operator==( Vect2D<T> v1, Vect2D<T> v2)
//      ----------
{
  return ((v1.x==v2.x)Et(v1.y==v2.y));
}


//----------------------------------------------------------
/**
 */
template < class T >
unsigned char Proche( Vect2D<T> v1, Vect2D<T> v2, float epsilon)
//      ------
{
  return ( Norme(v2-v1) < epsilon );
}


//============================================================
//  DIMENSION 3
//============================================================

template <class T> class Vect3D;

template < class T > class Point_3D;

/**
    Egalite approximative de Points: Norme(p2-p1)< epsilon
*/
template <class T>
  unsigned char  Proche( Point_3D<T>& p1 , Point_3D<T>& p2, float epsilon);


/**
    Moyenne de 2 points
*/
template <class T>
  Point_3D<T>  Moyenne( Point_3D<T>& p1 , Point_3D<T>& p2);


/**
    Soustraction de 2 points -> 1 Vecteur 
*/
template <class T>
   Vect3D<T> operator-(const  Point_3D<T>& p1,const Point_3D<T>& p2);
  //         ---------

/**
 */
template <class T>
  ostream& operator<<( ostream&s, Point_3D<T>& pt);


//==============================================================
/**
  Point dans un espace a 3 dimensions
 */
template < class T >
class Point_3D 
//     -------
{

public:

  //
  T x;

  //
  T y;


  //
  T z;


  /**
    {\em Constructor} par d�faut
   */
   Point_3D() {}
  //----------

  /**
    {\em Constructor}
   */
   Point_3D( T x0, T y0, T z0) { x=x0; y=y0; z=z0;}
  //----------

  /**
    {\em Destructor}
   */
  ~Point_3D() {}
  //---------

  /**
   */
  void Init( T x0, T y0, T z0) { x=x0; y=y0; z=z0;}


  T& X() { return x; }
  T& Y() { return y; }
  T& Z() { return z; }

  T X() const { return x; }
  T Y() const { return y; }
  T Z() const { return z; }

  /**
   */
  Point_3D<T>& operator=(const Point_3D<T>& p)
  //         ---------
  {
    x        = p.x;
    y        = p.y;
    z        = p.z;
    return(*this);
  }


  /**
   */
  unsigned char operator==(Point_3D<T>& p)
  //      ---------
  {
    return ((x == p.x) Et (y == p.y) Et (z == p.z));
  }


  /**
    dit si la distance du point a p2 est inferieure a epsilon
   */
  unsigned char ProcheDe( Point_3D<T> p2, float epsilon)
  //      --------
  {
    return ( sqrt((p2.x-x)*(p2.x-x) + 
            (p2.y-y)*(p2.y-y) +
            (p2.z-z)*(p2.z-z)) 
           < epsilon );
  }


#if !(defined(_sgi_))
  /**
    Egalite approximative de Points: Norme(p2-p1)< epsilon
  */
  friend unsigned char  Proche<>( Point_3D<T>& p1 , Point_3D<T>& p2, float epsilon);


  /**
    Moyenne de 2 points
  */
  friend Point_3D<T>  Moyenne<>( Point_3D<T>& p1 , Point_3D<T>& p2);


  /**
    Soustraction de 2 points -> 1 Vecteur
   */
  friend Vect3D<T> operator- <>(  const Point_3D<T>& p1, 
                                  const Point_3D<T>& p2);
  //               ---------

  /**
   */
  friend ostream& operator<< <>( ostream&s, Point_3D<T>& pt);

#else
  /**
    Egalite approximative de Points: Norme(p2-p1)< epsilon
  */
  friend unsigned char  Proche( Point_3D<T>& p1 , Point_3D<T>& p2, float epsilon);


  /**
    Moyenne de 2 points
  */
  friend Point_3D<T>  Moyenne( Point_3D<T>& p1 , Point_3D<T>& p2);


  /**
    Soustraction de 2 points -> 1 Vecteur
   */
  friend Vect3D<T> operator- (  const Point_3D<T>& p1, 
  //               ---------
                                const Point_3D<T>& p2);

  /**
   */
  friend ostream& operator<< ( ostream&s, Point_3D<T>& pt);

#endif

}; // Point_3D<T>


//==============================================================


/**
    Norme du vecteur
 */
template <class T>
  T Norme(const Vect3D<T>&);
  
/**
    Square Norm of the vector
 */
template <class T>
  T Norme2(const Vect3D<T>&);

/**
 */
template <class T>
  ostream& operator<<( ostream& s, const Vect3D<T>& pt);

/**
    soustraction de 2 Vecteurs
 */
template <class T>
  Vect3D<T> operator-( Vect3D<T>, Vect3D<T>);

/**
    addition de 2 Vecteurs
 */
template <class T>
  Vect3D<T> operator+( Vect3D<T>, Vect3D<T>);

/**
    addition de Vecteur + scalaire
 */
template <class T>
  Vect3D<T> operator+( Vect3D<T>, T);

template <class T>
 Point_3D<T> operator+( Point_3D<T>, Vect3D<T>);

/**
  produit scalaire de 2 Vecteurs
 */
template <class T>
  T operator*( Vect3D<T>, Vect3D<T>);

/**
  produit d'un scalaire avec un 2 Vecteur
 */
template <class T>
  Vect3D<T> operator*( T, const Vect3D<T>&);

template <class T>
Vect3D<T> operator*(  const Vect3D<T>&, T);

/**
    produit vectoriel de 2 Vecteurs
 */
template <class T>
  Vect3D<T> operator^( const Vect3D<T>&,const  Vect3D<T>&);

/**
    Egalite de vecteurs
*/
template <class T>
  unsigned char  operator==( Vect3D<T>, Vect3D<T>);

/**
    Egalite approximative de vecteurs: Norme(v2-v1)< epsilon
*/
template <class T>
  unsigned char  Proche( Vect3D<T> v1 , Vect3D<T> v2, float epsilon);

//==============================================================

/**
  Vecteur dans un espace a 3 dimensions
 */
template < class T >
class Vect3D 
//     ------
{

public:

  //
  T x;
  
  //
  T y;

  //
  T z;


  /**
    {\em Constructor} par d�faut
   */
 Vect3D() {}
  //----------

  /**
    {\em Constructor}
   */
   Vect3D( T x0, T y0, T z0) { x=x0; y=y0; z=z0;}
  //----------

  /**
   */
  void Init( T x0, T y0, T z0) { x=x0; y=y0; z=z0;}

  /**
    {\em Destructor}
   */
  ~Vect3D() {}
  //---------


  Vect3D<T>& operator=( const Vect3D<T>& p)
  //         ---------
  {
    x        = p.x;
    y        = p.y;
    z        = p.z;
    return(*this);
  }


  Vect3D<T>& Normalise( ) throw (NormeFaible)
  //         ---------
  {
    
      T norme;

    norme = sqrt(x*x+y*y+z*z);
   
    Si norme > EPSILON Alors
      x = x/norme;
      y = y/norme;
      z = z/norme;
    Sinon
      throw NormeFaible();
     std::cout << "Vect3D<T>::Normalise\t norme <= 1E-2..\n";
    FinSi
    return(*this);

  }


  //---------------------------------
  // Fonctions Amies
  //---------------------------------

#if !(defined(_sgi_))

  /**
    Norme du vecteur
   */
  friend T Norme<>(const Vect3D<T>&);
  

  /**
   */
  friend ostream& operator<< <>( ostream&s, const Vect3D<T>& pt);

  /**
    soustraction de 2 Vecteurs
   */
  friend Vect3D<T> operator- <>( Vect3D<T>, Vect3D<T>);

  /**
    addition de 2 Vecteurs
   */
  friend Vect3D<T> operator+ <>( Vect3D<T>, Vect3D<T>);

   /**
    addition de  Vecteur + scalaire
   */
  friend Vect3D<T> operator+ <>( Vect3D<T>, T);

 /**
    addition de d'un vecteur a un point
   */
  friend Point_3D<T> operator+ <>( Point_3D<T>, Vect3D<T>);

  /**
    produit scalaire de 2 Vecteurs
   */
  friend T operator* <>( Vect3D<T>, Vect3D<T>);

  /**
    produit scalaire * Vecteur
   */
  friend Vect3D<T> operator* <>( T, const Vect3D<T>&);
friend Vect3D<T> operator* <>( const Vect3D<T>&, T);

  /**
    produit vectoriel de 2 Vecteurs
   */
  friend Vect3D<T> operator^ <>( const Vect3D<T>&, const Vect3D<T>&);

  /**
    Egalite de vecteurs
  */
  friend unsigned char  operator== <>( Vect3D<T>, Vect3D<T>);

  /**
    Egalite approximative de vecteurs: Norme(v2-v1)< epsilon
  */
  friend unsigned char  Proche <>( Vect3D<T> v1 , Vect3D<T> v2, float epsilon);

#else

  /**
    Norme du vecteur
   */
  friend T Norme(const Vect3D<T>&);
  

  /**
   */
  friend ostream& operator<< ( ostream&s, const Vect3D<T>& pt);

  /**
    soustraction de 2 Vecteurs
   */
  friend Vect3D<T> operator- ( Vect3D<T>, Vect3D<T>);

  /**
    addition de 2 Vecteurs
   */
  friend Vect3D<T> operator+ ( Vect3D<T>, Vect3D<T>);

  /**
    addition de d'un vecteur a un point
   */
  friend Point_3D<T> operator+ ( Point_3D<T>, Vect3D<T>);

  /**
    produit scalaire de 2 Vecteurs
   */
  friend T operator* ( Vect3D<T>, Vect3D<T>);

  /**
    produit scalaire * Vecteur
   */
  friend Vect3D<T> operator* ( T, const Vect3D<T>&);
  friend Vect3D<T> operator* ( const Vect3D<T>&, T);

  /**
    produit vectoriel de 2 Vecteurs
   */
  friend Vect3D<T> operator^ ( const Vect3D<T>&, const Vect3D<T>&);

  /**
    Egalite de vecteurs
  */
  friend unsigned char  operator== ( Vect3D<T>, Vect3D<T>);

  /**
    Egalite approximative de vecteurs: Norme(v2-v1)< epsilon
  */
  friend unsigned char  Proche ( Vect3D<T> v1 , Vect3D<T> v2, float epsilon);

#endif

}; // Vect3D<T>

//============================================================
// Point_3D

/**
 */
template < class T >
unsigned char Proche( Point_3D<T>& p1, Point_3D<T>& p2, float epsilon)
//      ------
{
  return ( Norme(p2-p1) < epsilon );
}


/**
  Moyenne de 2 points
*/
template < class T >
Point_3D<T>  Moyenne( Point_3D<T>& p1 , Point_3D<T>& p2)
//           -------
{
  return ( Point_3D<T>( (p1.x+p2.x)/2.0, 
              (p1.y+p2.y)/2.0,
              (p1.z+p2.z)/2.0 ) );
}



/**
 */
template < class T >
Vect3D<T> operator-( const Point_3D<T>& p1, const Point_3D<T>& p2)
//        ---------
{
  return Vect3D<T>( p1.x-p2.x, p1.y-p2.y, p1.z-p2.z);
}


/**
 */
template < class T >
ostream& operator<<( ostream&s, Point_3D<T>& pt)
//       ----------
{
  return s << '(' 
                        << pt.x 
                 << ',' << pt.y 
                 << ',' << pt.z 
           << ')';
}


//============================================================
//  Vect3D 
//============================================================


//----------------------------------------------------------
/**
 */
template < class T >
T  Norme( const Vect3D<T>& v)
// -----
{
  return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}


/**
 */
template < class T >
T  Norme2( const Vect3D<T>& v)
// -----
{
  return v.x*v.x+v.y*v.y+v.z*v.z;
}

//----------------------------------------------------------
/**
 */
template < class T >
ostream& operator<<( ostream&s, const Vect3D<T>& v)
//       ----------
{
  return s << '(' 
                        << v.x 
                 << ',' << v.y 
                 << ',' << v.z 
           << ')';
}


//----------------------------------------------------------
/**
 */
template < class T >
Vect3D<T> operator-( Vect3D<T> v1, Vect3D<T> v2)
//        ---------
{
  Vect3D<T> v;

  v.x = v1.x - v2.x;
  v.y = v1.y - v2.y;
  v.z = v1.z - v2.z;

  return v;
}


//----------------------------------------------------------
/**
 */
template < class T >
Vect3D<T> operator+( Vect3D<T> v1, Vect3D<T> v2)
//        ---------
{
  Vect3D<T> v;

  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  v.z = v1.z + v2.z;

  return v;
}


//----------------------------------------------------------
/**
 */
template < class T >
Vect3D<T> operator+( Vect3D<T> v1, T d)
//        ---------
{
  Vect3D<T> v;

  v.x = v1.x + d;
  v.y = v1.y + d;
  v.z = v1.z + d;

  return v;
}


//----------------------------------------------------------
/**
 */
template < class T >
Point_3D<T> operator+( Point_3D<T> p, Vect3D<T> v)
//          ---------
{
  Point_3D<T> p1;

  p1.x = p.x + v.x;
  p1.y = p.y + v.y;
  p1.z = p.z + v.z;

  return p1;
}

//----------------------------------------------------------
/**
 */
template < class T >
T  operator*( Vect3D<T> v1, Vect3D<T> v2)
// ---------
{
  return ( v1.x*v2.x + v1.y*v2.y + v1.z*v2.z );
}


//----------------------------------------------------------
/**
 */
template < class T >
Vect3D<T>  operator*( T sc, const Vect3D<T>& v)
//         ---------
{
  return Vect3D<T>( v.x*sc, v.y*sc, v.z*sc);
}

//----------------------------------------------------------
/**
 */
template < class T >
Vect3D<T>  operator*( const Vect3D<T>& v, T sc)
//         ---------
{
  return Vect3D<T>( v.x*sc, v.y*sc, v.z*sc);
}


//----------------------------------------------------------
/**
 */
template < class T >
Vect3D<T> operator^( const Vect3D<T>& v1, const Vect3D<T>& v2)
//        ---------
{
  Vect3D<T> v;

  v.x = v1.y*v2.z - v1.z*v2.y;
  v.y = v1.z*v2.x - v1.x*v2.z;
  v.z = v1.x*v2.y - v1.y*v2.x;

  return v;
}


//----------------------------------------------------------
/**
 */
template < class T >
unsigned char operator==( Vect3D<T> v1, Vect3D<T> v2)
//      ----------
{
  return ((v1.x==v2.x)Et(v1.y==v2.y)Et(v1.z==v2.z));
}


//----------------------------------------------------------
/**
 */
template < class T >
unsigned char Proche( Vect3D<T> v1, Vect3D<T> v2, float epsilon)
//      ------
{
  return ( Norme(v2-v1) < epsilon );
}


#endif // COORDONNEES_HPP
