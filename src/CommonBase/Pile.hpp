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
// Pile dynamique d'�l�ments quelconques
//
 * $Author: karl $
 * $Revision: 1.2 $
 * $Log: Pile.hpp,v $
 * Revision 1.2  2005/11/16 14:03:07  karl
 * added LGPL license
 *
 * Revision 1.1.1.1  2004/02/02 20:47:07  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2000/04/07 16:12:39  karl
 * Sources code
 *
 * Revision 1.3.0.1  1998/10/02 20:50:51  kkrissia
 * *** empty log message ***
 *
 * Revision 1.3  1998/10/02 20:50:40  kkrissia
 * *** empty log message ***
 *
 * Revision 1.1  1998/10/02 20:23:49  kkrissia
 * operator <<
 *

*/

#ifndef _PILE_HPP
#define _PILE_HPP

#include "style.hpp"
//#include "Erreurs.hpp"
#include <iostream>

template < class T > class Pile;


/**
 */
template<class T>
std::ostream& operator<< (std::ostream&, const Pile<T>& p);



//===========================================================================
/**
   class tableau de base
   Les elts sont num�rot�s en commencant par 0
 */
template < class T >
class Pile // : public GestionErreurs
//     ------------
{

private:

  /// Element par defaut, retourne en cas de pile vide
  T _defaut;

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

  //---------------------------------------------------------
  /**
    {\em Constructor}
    @param n_max nombre d'�l�ments allou�s
   */
   Pile( T defaut, int n_max = 2) //: GestionErreurs("Pile<T>")
  //----------
  {
  //    printf("Constructor Pile( int n_max = 2)\n");

    _defaut = defaut;

    _nbelts_utilises = 0;
    _nbelts_alloues = n_max;
    _tableau = new T[_nbelts_alloues];

  }


  //---------------------------------------------------------
  /**
    {\em Constructor de copie}
   */
   Pile( Pile<T>& elt) //: GestionErreurs("Pile<T>")
  //----------
  {

    
      int i;

 
//   printf("constructeur Pile( Pile<T>& elt) \n");
   _nbelts_utilises = elt._nbelts_utilises;
    _nbelts_alloues  = elt._nbelts_alloues;

    _tableau = new T[_nbelts_alloues];

    Pour( i, 0, _nbelts_utilises-1)
      _tableau[i] = elt._tableau[i];
    FinPour

  } // Constructor de copie



  //---------------------------------------------------------
  /**
    {\em destructeur}
   */
  ~Pile()
  //---------
  {
    delete [] _tableau;
  } // Destructor


  //---------------------------------------------------------
  /**
    Acc�s � l'�l�ment n
   */
  T& operator[](int n);
  // ----------

  //---------------------------------------------------------
  /**
    Acc�s au dernier element
   */
  T& Top();
  // ---


  //-------------------------------------------------------
  /**
    Assignment operator
    */
  Pile<T>&   operator=(  Pile<T>);
  //               ---------


  //-------------------------------------------------------
  /**
    Ajout d'un �l�ment � la fin du tableau
    */
  Pile<T>&  operator+=( T elt);
  //              -----------

  //-------------------------------------------------------
  /**
    Suppression du dernier elt
    */
  T  operator--(int);
  // -----------

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
  int NbElts() { return _nbelts_utilises; }
  //     ------


  /**
    Recherche l'element dans le tableau et dit s'il est present
   */
  unsigned char Existe( T elt);
  //      ------

#if !(defined(_sgi_)) 
// && !(defined(_linux_)) 
  /**
   */
  friend std::ostream& operator << <>(std::ostream&, const Pile<T>& p);
#else

  friend std::ostream& operator << (std::ostream&, const Pile<T>& p);
#endif

}; // Pile<T>


//===========================================================================
//  Definition des Methodes
//===========================================================================


// #include "Pile.hpp.template"

//
// D�finition des methode de la classe Pile g�n�rique
// dans ce fichier pour eviter des conflit � la generation de la documentation



//===========================================================================
//  Definition des Methodes
//===========================================================================

//===========================================================================
//  Membres Prives
//===========================================================================

//--------------------------------------------------------------------------
/**
  Definition dans le fichier hpp de la fonction membre de la classe
  Pile<T>
 */
template<class T>
unsigned char Pile<T> :: Resize( )
//                                 ------
{

  return Resize( 2*_nbelts_alloues);

} // Resize()


//===========================================================================
//  Membres Publics
//===========================================================================

//---------------------------------------------------------
/**
  {\em Constructor de copie}
 */

//--------------------------------------------------------------------------
/**
  Definition dans le fichier hpp de la fonction membre de la classe
  Pile<T>
 */
template<class T>
unsigned char Pile<T> :: Resize( int taille)
//                                 ------
{


  
    T*     new_tab;
    int new_nbelts,i;

  Si taille < _nbelts_utilises Alors
    return false;
  FinSi

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
Pile<T>& Pile<T> :: operator=(  Pile<T> elt)
//                            ---------
{

  
    int i;

//  printf("Pile<T> operator = ( Pile<T>& elt)\n");
  Resize( elt._nbelts_alloues);
  _nbelts_utilises = elt._nbelts_utilises;
  
  Pour( i, 0, _nbelts_utilises-1)
    _tableau[i] = elt._tableau[i];
  FinPour
  
  return *this;

} // operateur =


//-------------------------------------------------------
/**
    Ajout d'un �l�ment � la fin du tableau
  */
template<class T>
Pile<T>& Pile<T> :: operator+=( T elt)
//                              ----------
{

    Si _nbelts_utilises >= _nbelts_alloues AlorsFait Resize( 2*_nbelts_utilises );
    _tableau[_nbelts_utilises++] = elt;

    return *this;

} // operateur +=


//-------------------------------------------------------
/**
 */
template<class T>
T Pile<T> :: operator--(int )
//                     ----------
{

  Si _nbelts_utilises > 0 Alors
    _nbelts_utilises--;
    return _tableau[_nbelts_utilises];
  Sinon
    return( Pile<T>::_defaut);
  FinSi

} // operateur --


//-------------------------------------------------------
/**
   Insertion d'un �l�ment � la position n
  */
template<class T>
void Pile<T> :: Insere( int pos, T elt)
//                              ------
{

    
      int i;

    Si _nbelts_utilises >= _nbelts_alloues AlorsFait Resize( 2*_nbelts_utilises);
    
    for(  i=_nbelts_utilises ;  i > pos ;  i-- Faire
      _tableau[i] = _tableau[i-1];
    } // end for

    _tableau[pos] = elt;
    _nbelts_utilises++;

} // Insere()


//-------------------------------------------------------
/** Suppression d'un �l�ment � la position n
  */
template<class T>
void Pile<T> :: Supprime( int pos)
//                              --------
{

    
      int i;

    Pour( i, pos, _nbelts_utilises-1)
      _tableau[i] = _tableau[i+1];
    FinPour

    _nbelts_utilises--;

} // Supprime()


//--------------------------------------------------------------------------
/**
  Definition dans le fichier hpp de la fonction membre de la classe
  Pile<T>
 */
template<class T>
T& Pile<T> :: operator[](int n)
//                      ----------
{

    Si (n<0) Ou (n>=_nbelts_utilises) Alors

//      MethodeCourante("Operator[]");
//     AfficheErreur(ERREUR_DIVERS,
       std::cerr << " Pile<T> operator[]\t Indice incorrect ... "
            << n << "[0 " <<  _nbelts_utilises-1 << "]\n";
//      FinMethode();
      return Pile<T>::_defaut;
    Sinon
      return _tableau[n];
    FinSi

} // operator[]


//--------------------------------------------------------------------------
/**
  Definition dans le fichier hpp de la fonction membre de la classe
  Pile<T>
 */
template<class T>
T& Pile<T> :: Top()
//                      ---
{

    Si (_nbelts_utilises==0) Alors

      std::cerr << " Pile<T>::Top()\t Pile vide ... " << std::endl;
      return Pile<T>::_defaut;
    Sinon
      return _tableau[_nbelts_utilises-1];
    FinSi

} // Top()


//-------------------------------------------------------
template<class T>
unsigned char Pile<T> :: Existe( T elt)
//                           ------
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
/**
 */
template<class T>
std::ostream& operator << (std::ostream& os, const Pile<T>& p)
//       -----------
{
  
    int i;

  os << "Pile =  { ";
  Pour( i, 0, p._nbelts_utilises-1)
    os << p._tableau[i];
    Si i < p._nbelts_utilises-1 Alors
      os  << " ; ";
    Sinon
      os  << " }" << std::endl;
    FinSi
  FinPour

  return os;

} // operator << ( , const Pile<T>&)


#endif // _PILE_HPP
