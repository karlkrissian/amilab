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
//
// Fichier Erreurs.cpp
//
// Gestion des erreurs 
//
// Karl Krissian        Sophia Antipolis le 15-08-98
// 


#include "Erreurs.hpp"


//---------------------------------------------------------------------
/**
 */
std::ostream& operator<<(std::ostream& os, const NomMethode& m)
//       ----------
{

  
//    int      n;

  return os
           <<  m._nom_fichier << "\t"
           <<  m._nom_classe << "::"
           <<  m._nom_methode << "()";

} // operator<<


//---------------------------------------------------------------------
/**
 */
std::ostream& operator<<(std::ostream& os, const ExceptionErreur& e)
//       ----------
{

  
    int      n;
    NomMethode* methode;

  n = GB_pile_nom_methode.NbElts();
  Si n>0 Alors  
    methode = GB_pile_nom_methode[n-1];
    return os
           <<  GB_mess_erreur[(int)e._type] << "\t"
           <<  *methode << "\t"
           <<  (char*) e._message
           << std::endl;
  Sinon
    methode = new NomMethode("classe inconnue ","fichier inconnu","methode inconnue");
    return os
           <<  GB_mess_erreur[(int)e._type] << "\t"
           <<  *methode << "\t"
           <<  e._message << std::endl;
    delete methode;
  FinSi

} // operator<<


//---------------------------------------------------------------------
/**
 */
std::ostream& operator<<(std::ostream& os, const ExceptionWarning& w)
//       ----------
{
    int      n;
    NomMethode* methode;

  n = GB_pile_nom_methode.NbElts();
  Si n>0 Alors  
    methode = GB_pile_nom_methode[n-1];
    return os
           <<  GB_mess_warning[(int)w._type] << "\t"
           <<  *methode << "\t"
           <<  w._message << std::endl;
  Sinon
    methode = new NomMethode("classe inconnue ","fichier inconnu","methode inconnue");
    return os
           <<  GB_mess_warning[(int)w._type] << "\t"
           <<  *methode << "\t"
           <<  w._message << std::endl;
    delete methode;
  FinSi

} // operator<<

  /*
//------------------------------------------------------------------------
GestionErreurs ::   GestionErreurs( const Chaine& nomclasse)
//                           ------------
{

  _nom_classe = nomclasse;
  InitMessages();

  _debug = false;

} // Constructor
  */

//------------------------------------------------------------------------
GestionErreurs ::  ~ GestionErreurs()
//                           -----------
{

} // Destructor


//------------------------------------------------------------------------
void GestionErreurs :: MethodeCourante( const Chaine& nom, const Chaine& fic)
//                               --------------
{

  _nom_fichier = fic;

  _nom_methode_courante = nom;

  Si _debug AlorsFait
    std::cerr << "Debut " <<  _nom_methode_courante << std::endl;

  GB_pile_nom_methode += new NomMethode( _nom_classe,
           fic,
           _nom_methode_courante);

} // MethodeCourante()

//------------------------------------------------------------------------
void GestionErreurs :: FinMethode( )
//                               ----------
{

  NomMethode* last;
  int      n;

  Si _debug AlorsFait
    std::cerr << "Fin " <<  _nom_methode_courante << std::endl;

  last = GB_pile_nom_methode--;
  delete last;
 
  n = GB_pile_nom_methode.NbElts();

  Si n>0 Alors
    _nom_methode_courante = (GB_pile_nom_methode[n-1])->_nom_methode;
  Sinon
    _nom_methode_courante = "pile vide (pas de m�thode)";
  FinSi

} // FinMethode()


//------------------------------------------------------------------------
void GestionErreurs :: AfficheWarning( type_warning type, const Chaine& mess)
//                               --------------
{

  Si GB_AfficheWarning AlorsFait
  std::cerr
       <<  GB_mess_warning[(int)type] << "\t"
       <<  _nom_fichier << "\t"
       <<  _nom_classe << "::"
       <<  _nom_methode_courante << "\t"
       <<  mess << std::endl;

} // AfficheWarning()


//------------------------------------------------------------------------
void GestionErreurs :: AfficheErreur( type_erreur type, const Chaine& mess) 
//                               -------------
{

//   int n,i;

  Si GB_AfficheErreur AlorsFait
  std::cerr
       <<  GB_mess_erreur[(int)type] << "\t"
       <<  _nom_fichier << "\t"
       <<  _nom_classe << "::"
       <<  _nom_methode_courante << "\t"
       <<  mess << std::endl;

} // AfficheErreur()


//------------------------------------------------------------------------
void AffichePileNomMethode()
//   ---------------------
{

   int n,i;

  n = GB_pile_nom_methode.NbElts();

  Pour(i,0,n-1)
    std::cerr <<  *(GB_pile_nom_methode[i]);
    Si i!= n-1 Alors
      std::cerr << "-->";
    Sinon
      std::cerr << "." << std::endl;
    FinSi
  FinPour

} // AffichePileNomMethode()
