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
/*
// Tableau dynamique d'�l�ments quelconques
//
 * $Author: karl $
 * $Revision: 1.3 $
 * $Log: TableauDyn.hpp,v $
 * Revision 1.3  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.2  2004/08/06 20:48:29  karl
 * removed warnings + fixed bugs in IsoLigne
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:12:40  karl
 * Sources code
 *
 * Revision 1.3.0.1  1998/10/02 20:50:52  kkrissia
 * *** empty log message ***
 *
 * Revision 1.3  1998/10/02 20:50:41  kkrissia
 * *** empty log message ***
 *
 * Revision 1.2  1998/10/02 20:23:49  kkrissia
 * operator <<
 *

*/

#ifndef _TABLEAUDYN_HPP
#define _TABLEAUDYN_HPP

#include "style.hpp"
#include "Erreurs.hpp"
#include <stdio.h>

#ifdef _MSC_VER
  #pragma warning( disable : 4290 )
#endif

class OutOfArray {};

template < class T > class TableauDyn;

/**
 */
template<class T>
ostream& operator<< (ostream&, const TableauDyn<T>& p);


//===========================================================================
/**
   class tableau de base
   Les elts sont num�rot�s en commencant par 0 ...
 */
template < class T >
class TableauDyn // : public GestionErreurs
//     ------------
{

private:

  /// nombre d'elements contenus dans le tableau
  int _nbelts_utilises;

  /// Taille maximale du tableau
  int _nbelts_alloues;

  /// Tableau d'�l�ments
  T* _tableau;

  /// Augmentation du nombre d'�l�ments allou�s (x2) et recopie du tableau
  unsigned char Resize( );
  //      ------

public:

  /**
   Changement du nombre d'�l�ments allou�s et recopie du tableau
   la valeur taille doit etre sup�rieure a _nbelts_utilises
  */
  unsigned char Resize( int taille);
  //      ------

  /**
    {\em Constructeur}
    @param n_max nombre d'�l�ments allou�s
   */
  Constructeur TableauDyn( int n_max = 2) //: GestionErreurs("TableauDyn<T>")
  //----------
  {
  //    printf("Constructeur TableauDyn( int n_max = 2)\n");

    _nbelts_utilises = 0;
    _nbelts_alloues = n_max;
    _tableau = new T[_nbelts_alloues];

  }


  /**
    {\em Constructeur de copie}
   */
  Constructeur TableauDyn( const TableauDyn<T>& elt) //: GestionErreurs("TableauDyn<T>")
  //----------
  {


      int i;


//   printf("constructeur TableauDyn( TableauDyn<T>& elt) \n");
   _nbelts_utilises = elt._nbelts_utilises;
    _nbelts_alloues  = elt._nbelts_alloues;

    _tableau = new T[_nbelts_alloues];

    Pour( i, 0, _nbelts_utilises-1)
      _tableau[i] = elt._tableau[i];
    FinPour

  } // Constructeur de copie



  /**
    {\em destructeur}
   */
  Destructeur TableauDyn()
  //---------
  {
    delete [] _tableau;
  } // Destructeur


  /**
    Acc�s � l'�l�ment n
   */
#ifdef _MSC_VER
  T& operator[](int n) const; //throw(OutOfArray);
#else
  T& operator[](int n) const throw(OutOfArray);
#endif
  // ----------


  /**
    Assignment operator
    */
  TableauDyn<T>&   operator=( const TableauDyn<T>&);
  //               ---------


  //-------------------------------------------------------
  /**
    Ajout d'un �l�ment � la fin du tableau
    */
  TableauDyn<T>&  operator+=(const T& elt);
  //              -----------


  //-------------------------------------------------------
  /** Insertion d'un �l�ment � la position n
    */
  void Insere( int pos, T elt);
  //   ------


  //-------------------------------------------------------
  /** Suppression d'un �l�ment � la position n
    */
  void Supprime( int pos);
  //   --------


  //-------------------------------------------------------
  /**
     Suppression des elements du tableau
    */
  void VideTableau( )
  //   -----------
  {
    _nbelts_utilises = 0;
    Resize(2);
  }


  //-------------------------------------------------------
  /** Nombre d'�l�ments du tableau
   */
  int NbElts() const { return _nbelts_utilises; }
  //     ------


  /**
    Recherche l'element dans le tableau et dit s'il est present
   */
  unsigned char Existe( const T& elt);
  //      ------

  /**
    Returns the position of the first elt equal to 'elt', -1 if no element is found
   */
  int Position( const T& elt);
  //  --------

#if !(defined(_sgi_))
// && !(defined(_linux_))
  /**
   */
  friend ostream& operator << <>(ostream&, const TableauDyn<T>& p);
#else

  friend ostream& operator << (ostream&, const TableauDyn<T>& p);
#endif

}; // TableauDyn<T>


//===========================================================================
//  Definition des Methodes
//===========================================================================


//===========================================================================
//  Definition des Methodes
//===========================================================================

//===========================================================================
//  Membres Prives
//===========================================================================

//#include "TableauDyn.hpp.template"

//
// D�finition des methode de la classe TableauDyn g�n�rique
// dans ce fichier pour eviter des conflit � la generation de la documentation


//--------------------------------------------------------------------------
//
//  Definition dans le fichier hpp de la fonction membre de la classe
//  TableauDyn<T>
//
template<class T> unsigned char TableauDyn<T> :: Resize( )
//                                 ------
{

  return Resize( 2*_nbelts_alloues);

} // Resize()


//===========================================================================
//  Membres Publics
//===========================================================================

//---------------------------------------------------------
//
//  {\em Constructeur de copie}
//

//--------------------------------------------------------------------------
//
//  Definition dans le fichier hpp de la fonction membre de la classe
//  TableauDyn<T>
//
template<class T> unsigned char TableauDyn<T> :: Resize( int taille)
//                                 ------
{



    T*     new_tab;
    int new_nbelts,i=0;

  Si taille < _nbelts_utilises Alors
    return false;
  FinSi


  //  fprintf(stderr,"Resize taille=%d nbelts utilises = %d\n ",taille,_nbelts_utilises);
  new_nbelts = taille;
  new_tab = new T [new_nbelts];

  Pour(i,0,_nbelts_utilises-1)
    new_tab[i] = _tableau[i];
  FinPour

  delete [] _tableau;

  _tableau = new_tab;
  _nbelts_alloues = new_nbelts;

  return true;

} // Resize()


//-------------------------------------------------------
/**
    operator d'affectation
  */
template<class T>
TableauDyn<T>& TableauDyn<T> :: operator=( const TableauDyn<T>& elt)
//                            ---------
{


    int i;

if (this!=&elt) {

//  printf("TableauDyn<T> operator = ( TableauDyn<T>& elt)\n");
  Resize( elt._nbelts_alloues);
  _nbelts_utilises = elt._nbelts_utilises;

  Pour( i, 0, _nbelts_utilises-1)
    _tableau[i] = elt._tableau[i];
  FinPour

    }
 else
   fprintf(stderr,"TableauDyn::operator =, this==&elt\n");

  return *this;

} // operateur =


//-------------------------------------------------------
//
//    Ajout d'un �l�ment � la fin du tableau
//
template<class T>
TableauDyn<T>& TableauDyn<T> :: operator+=( const T& elt)
//                              ----------
{

    Si _nbelts_utilises >= _nbelts_alloues AlorsFait Resize( 2*_nbelts_utilises );
    _tableau[_nbelts_utilises++] = elt;

    return *this;

} // operateur +=


//-------------------------------------------------------
/**
   Insertion d'un �l�ment � la position n
  */
template<class T>
void TableauDyn<T> :: Insere( int pos, T elt)
//                              ------
{


      int i;

    Si _nbelts_utilises >= _nbelts_alloues AlorsFait Resize( 2*_nbelts_utilises);

    DebutBoucle i=_nbelts_utilises ItererTantQue i > pos Pas i-- Faire
      _tableau[i] = _tableau[i-1];
    FinBoucle

    _tableau[pos] = elt;
    _nbelts_utilises++;

} // Insere()


//-------------------------------------------------------
/** Suppression d'un �l�ment � la position n
  */
template<class T> void TableauDyn<T> :: Supprime( int pos)
//                                                --------
{


      int i;

    Pour( i, pos, _nbelts_utilises-2)
      _tableau[i] = _tableau[i+1];
    FinPour

    _nbelts_utilises--;

} // Supprime()


//--------------------------------------------------------------------------
/**
  Definition dans le fichier hpp de la fonction membre de la classe
  TableauDyn<T>
 */
template<class T>
T& TableauDyn<T> :: operator[](int n) const throw (OutOfArray)
//                            ----------
{

    Si (n<0) Ou (n>=_nbelts_utilises) Alors

//      MethodeCourante("Operator[]");
//     AfficheErreur(ERREUR_DIVERS,
printf(" TableauDyn<T> operator[]\t Indice incorrect ... %d [0 %d]\n",
       n, _nbelts_utilises-1);
//      FinMethode();
      throw OutOfArray();
//      return *elt;
    Sinon
      return _tableau[n];
    FinSi

} // operator[]


//-------------------------------------------------------
template<class T>
unsigned char TableauDyn<T> :: Existe( const T& elt)
//                                 ------
{


    int i;

  Pour( i, 0, _nbelts_utilises-1)
    Si _tableau[i] == elt Alors
      return true;
    FinSi
  FinPour

  return false;

} // Existe()


//-------------------------------------------------------
template<class T>
int TableauDyn<T> :: Position( const T& elt)
{


    int i;

  Pour( i, 0, _nbelts_utilises-1)
    Si _tableau[i] == elt Alors
      return i;
    FinSi
  FinPour

  return -1;

} // Existe()

//-------------------------------------------------------
/**
 */
template<class T>
ostream& operator << (ostream& os, const TableauDyn<T>& p)
//       -----------
{

    int i;

  os << "Tableau =  { ";
  Pour( i, 0, p._nbelts_utilises-1)
    os << p._tableau[i];
    Si i < p._nbelts_utilises-1 Alors
      os  << " ; ";
    Sinon
      os  << " }" << endl;
    FinSi
  FinPour

  return os;

} // operator << ( , const TableauDyn<T>&)



#endif // _TABLEAUDYN_HPP
