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
 * $Log: fonction2D.cpp,v $
 * Revision 1.2  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:09:46  karl
 * Sources code
 *
 *
 ***************************************************************************/

#ifdef _MSC_VER
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include "math1.hpp"
#include "fonction2D.hpp"

//----------------------------------------------------------------------
Fonction2D ::  Fonction2D( )
//
{

  _xmin = _ymin = 0.0;
  _xmax = _ymax = 0.0;
  _nom = "Fonction2D.dat";

} // Constructor

//----------------------------------------------------------------------
Fonction2D ::  Fonction2D( Chaine nom)
//
{

  _xmin = _ymin = 0.0;
  _xmax = _ymax = 0.0;
  Read(nom);

} // Constructor


//----------------------------------------------------------------------
Fonction2D ::  Fonction2D( const Fonction2D& f)
//
{

  _nom    = f._nom; 
  _xmin   = f._xmin;
  _xmax   = f._xmax;
  _ymin   = f._ymin;
  _ymax   = f._ymax;
  _points = f._points;

} // Constructor


//----------------------------------------------------------------------
Fonction2D :: ~Fonction2D( )
//
{


} // Destructor




//----------------------------------------------------------------------
///
void Fonction2D :: Read( Chaine nom) throw( ErreurLecture)
//                           ---
{

  
    FILE*  fic_donnees;    
    float   x,y;

  _nom = nom;

  // Premiere lecture pour connaitre le nombre de points
  fic_donnees = fopen( (char*) _nom, "r");

  Si fic_donnees == NULL Alors
     throw ErreurLecture( _nom);
  FinSi
  
  fscanf( fic_donnees, "%f\t%f\n", &x,&y);
//  _xmin = x;
//  _xmax = x;
  _points += Point2D<float>(x,y);

  TantQue Non(feof(fic_donnees)) Faire
    fscanf( fic_donnees, "%f\t%f\n", &x,&y);
    Si x<_xmin AlorsFait _xmin = x;
    Si x>_xmax AlorsFait _xmax = x;
    _points += Point2D<float>(x,y);
  FinTantQue

} // Read()


//----------------------------------------------------------------------
///
void Fonction2D :: Sauve( Chaine nom)
//                           -----
{

  
    FILE*  fic_donnees;    
    int i;

  Si nom != "" AlorsFait _nom = nom;

  Si (fic_donnees = fopen( (char*) _nom, "w")) != NULL Alors
    Pour( i, 0, _points.NbElts() -1)
      fprintf( fic_donnees, "%f\t%f\n", _points[i].x, _points[i].y);
    FinPour
    fclose( fic_donnees);
  Sinon
    std::cerr << " Fonction2D::Sauve() \t Erreur dans l'ouverture du fichier de donnees\n";
    return;
  FinSi

} // Sauve()


//----------------------------------------------------------------------
Fonction2D& Fonction2D :: operator+=( const Point2D<float>& pt)
//
{

  _points += pt;  

  return (*this);

} // operator+=( const Point2D<float>&)


//----------------------------------------------------------------------
Fonction2D& Fonction2D :: operator=(const Fonction2D& f)
//
{

  _xmin = f._xmin;
  _xmax = f._xmax;
  _ymin = f._ymin;
  _ymax = f._ymax;
  _points = f._points;

  return *this;

} // operator=(const Fonction2D&)

  
//----------------------------------------------------------------------
Fonction2D& Fonction2D :: operator=( float r)
//
{

  
    int i;

  Pour(i,0,_points.NbElts()-1)
    _points[i].y = r;
  FinPour

  return *this;

} // operator+=(float)


//----------------------------------------------------------------------
Fonction2D& Fonction2D :: operator+=( float r)
//
{

  
    int i;

  Pour(i,0,_points.NbElts()-1)
    _points[i].y += r;
  FinPour

  return *this;

} // operator+=(float)


//----------------------------------------------------------------------
Fonction2D& Fonction2D :: operator*=( float r)
//
{

  
    int i;

  Pour(i,0,_points.NbElts()-1)
    _points[i].y *= r;
  FinPour

  return *this;

} // operator*=(float)


//----------------------------------------------------------------------
Fonction2D& Fonction2D :: RacineCarree( ) 
//
{

  
    int i;

  Pour(i,0,_points.NbElts()-1)
    Si _points[i].y>=0 Alors
      _points[i].y = sqrt(_points[i].y);
    Sinon
      _points[i].y = 0.0;
    FinSi
  FinPour

  return *this;

} // RacineCarree( )


//----------------------------------------------------------------------
Point2D<float> Fonction2D :: Min( )
//
{

  
    Point2D<float> pt_min;
    int        i;

  pt_min = _points[0];
  Pour(i,1,_points.NbElts()-1)
    Si _points[i].y < pt_min.y Alors
      pt_min = _points[i];
    FinSi
  FinPour
 
  return pt_min;

} // Min()


//----------------------------------------------------------------------
void Fonction2D :: Rescale( float facteur)
//
{

  
    int i;

  Pour(i,0,_points.NbElts()-1)
    _points[i].x *= facteur;
  FinPour

} // Rescale()


//----------------------------------------------------------------------
float Fonction2D :: Moyenne(  float min, float max) 
//
{

  
    int i;
    int nb;
    float   moy;

  Si min == max Alors
    min = _xmin;
    max = _xmax;
  FinSi

  moy = 0.0;
  nb  = 0;
  Pour(i,0,_points.NbElts()-1)
    Si _points[i].x>min-1E-5 Et _points[i].x<max+1E-5 Alors
      nb++;
      moy += _points[i].y;
    FinSi
  FinPour

  return (moy/nb);

} // Moyenne( )


//----------------------------------------------------------------------
float Fonction2D :: EcartType(  float min, float max) 
//
{

  
    int i;
    int nb;
    float   moy,et;

  Si min == max Alors
    min = _xmin;
    max = _xmax;
  FinSi

  moy = Moyenne( min, max);
  et = 0.0;
  nb  = 0;
  Pour(i,0,_points.NbElts()-1)
    Si _points[i].x>min-1E-5 Et _points[i].x<max+1E-5 Alors
      nb++;
      et += (_points[i].y-moy)*(_points[i].y-moy);
    FinSi
  FinPour

  return sqrt(et/nb);

} // EcartType( )


//----------------------------------------------------------------------
float Fonction2D :: operator()( float x) 
//
{

  
    int i,max;
    float   c1,c2,c;

  max = _points.NbElts()-1;
  Si x<_xmin AlorsRetourne _points[0].y;
  Si x>_xmax AlorsRetourne _points[max].y;

  i = 0;
  TantQue (x>_points[i].x)Et(i<max) Faire
    i++;
  FinTantQue

  Si i==0   AlorsRetourne  _points[0].y;
  Si i==max AlorsRetourne  _points[max].y;

  c  = _points[i].x-_points[i-1].x;

  Si fabsf(c) < 1E-5 Alors
    std::cerr << " Points successifs de meme abscisse \n";
    return 0;
  FinSi

  c1 = (_points[i].x - x)/c;
  c2 = (float) (1.0 - c1);

  return _points[i-1].y  *c1 + 
           _points[i].y    *c2;

} // operator()(float)
