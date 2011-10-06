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
// Fichier Erreurs.hpp
//
// Gestion des erreurs
//
// Karl Krissian        Sophia Antipolis le 15-08-98
//


#ifndef _ERREURS_HPP
#define _ERREURS_HPP


#include "style.hpp"

#include <iostream>
//using -- namespace std;

#include "chaine.hpp"
#include <string>
#include "Pile.hpp"

#include "CommonConfigure.h"

class ExceptionErreur;
class NomMethode;
 
/* Variables Globales */
/*
  liste des exceptions
 */

/*
  pile des methodes utilisees
 */


#include "CommonConfigure.h"

#include "common_global_import.h"
//COMMON_EXPORT Pile<NomMethode*> GB_pile_nom_methode;
//COMMON_EXPORT unsigned char GB_AfficheWarning;
//COMMON_EXPORT unsigned char GB_AfficheErreur;

///
void AffichePileNomMethode();

//NomMethode* Pile<NomMethode*>::_defaut = NULL;

///
static  std::string GB_mess_warning[1] = {
  "Warning              "
};


///
static  std::string GB_mess_erreur[4] = {
  "Erreur de Calcul     ",
  "Erreur d'allocation  ",
  "Erreur de parametres ",
  "Erreur divers        "
};


typedef 
/**
@name type_warning
 */
enum { 
  ///
   WARNING_DIVERS 
} type_warning;

typedef 
/**
@name type_erreur
 */
enum { 
  ///
  ERREUR_CALCUL     = 0,
  ///
  ERREUR_ALLOCATION = 1,
  ///
  ERREUR_PARAMETRES,
  ///
  ERREUR_DIVERS 
}   type_erreur;



/**
 */
class NomClasse
//     ---------
{

public:
  ///
  Chaine _nom_classe;

  ///
   NomClasse( const Chaine& nom):_nom_classe(nom) {}

};


/**
 */
class NomMethode : public NomClasse
//     ---------- 
{

public:

  ///
  Chaine _nom_fichier;
  ///
  Chaine _nom_methode;

  ///
   NomMethode( const Chaine& classe="?", 
			   const Chaine& fichier="?",
			   const Chaine& methode="?"):
    NomClasse(classe),
    _nom_fichier(fichier),
    _nom_methode(methode)
  {}

  /// Message
  friend COMMON_EXPORT std::ostream& operator<<(std::ostream&, const NomMethode&);

};



/**
class Exception
 */
class COMMON_EXPORT Exception 
//                  ---------
{

protected:

  ///
  NomMethode    _nom_methode;
  ///
  Chaine        _message;

public:

  /// constructeur
   Exception( const Chaine& mess): _message(mess) 
  {
    NomMethode* top;
    top = GB_pile_nom_methode.Top();
    Si top!=NULL Alors
      _nom_methode = *top;
    FinSi
  }


}; // ExceptionErreur


/**
class ExceptionErreur
 */
class COMMON_EXPORT ExceptionErreur : public Exception
//                  ---------------
{

protected:

  ///
  type_erreur  _type;

public:

  /// constructeur
   ExceptionErreur( const Chaine& mess) : Exception( mess) 
  {
  }

  /// Message
  friend COMMON_EXPORT std::ostream& operator<<(std::ostream&, const ExceptionErreur&);

}; // ExceptionErreur


/**
class ExceptionWarning
 */
class COMMON_EXPORT ExceptionWarning : public Exception
//     ---------------
{

protected:

  ///
  type_warning  _type;

public:

  /// constructeur
   ExceptionWarning( const Chaine& mess) : Exception( mess) 
  {
  }

  /// Message
  friend COMMON_EXPORT std::ostream& operator<<(std::ostream&, const ExceptionWarning&);

}; // ExceptionWarning


/**
 */
class COMMON_EXPORT WarningDivers: public ExceptionWarning
//     -------------
{

public:

  ///
   WarningDivers( const Chaine& mess) :   ExceptionWarning(mess)
  {
   _type = WARNING_DIVERS;
    Si GB_AfficheWarning AlorsFait std::cerr << *this;
  }

}; // WarningDivers


/**
 */
class COMMON_EXPORT ErreurDivers: public ExceptionErreur
//     ------------
{

public:

  ///
   ErreurDivers( const Chaine& mess) : 
    ExceptionErreur(mess)
  {
    _type = ERREUR_DIVERS; 
    Si GB_AfficheErreur AlorsFait std::cerr << *this;
  }

}; // ErreurDivers


/**
 */
class COMMON_EXPORT ErreurParametres: public ExceptionErreur
//     ----------------
{

public:

  ///
   ErreurParametres( const Chaine& mess) : 
    ExceptionErreur(mess)
  {
    _type = ERREUR_PARAMETRES;
    Si GB_AfficheErreur AlorsFait std::cerr << *this;
  }

}; // ErreurParametres


/**
 */
class COMMON_EXPORT ErreurAllocation: public ExceptionErreur
//     ----------------
{

public:

  ///
   ErreurAllocation( const Chaine& mess) : 
    ExceptionErreur(mess)
  {
    _type = ERREUR_ALLOCATION;
    Si GB_AfficheErreur AlorsFait std::cerr << *this;
  }

}; // ErreurParametres


/**
 */
class COMMON_EXPORT ErreurCalcul: public ExceptionErreur
//     ------------
{

public:

  ///
   ErreurCalcul( Chaine& mess) : 
    ExceptionErreur(mess)
  {
     _type = ERREUR_CALCUL;
    Si GB_AfficheErreur AlorsFait std::cerr << *this;
  }

}; // ErreurParametres




//---------------------------------------------------------------------
/** class de Gestion des Erreurs
 */
class COMMON_EXPORT GestionErreurs
//                  --------------
{

  ///
  Chaine _nom_fichier;
  ///
  Chaine _nom_classe;
  ///
  Chaine _nom_methode_courante;

  ///
  unsigned char _debug;

public:

  ///
   GestionErreurs( const Chaine nomclasse)
  //           --------------
{
  _nom_classe = nomclasse;
  InitMessages();

  _debug = false;
}


  ///
  ~ GestionErreurs();
  //

  ///
  void SetDebug( unsigned char debug) { _debug = debug; }
  //   --------

  ///
  void SetNomClasse( Chaine nomclasse) { _nom_classe = nomclasse; }
  //   ------------

  ///
  void InitMessages()
  //
  {

  /*
    GB_mess_warning[WARNING_DIVERS] = "Warning";

    GB_mess_erreur[ERREUR_CALCUL]     = "Erreur de Calcul";
    GB_mess_erreur[ERREUR_ALLOCATION] = "Erreur d'allocation";
    GB_mess_erreur[ERREUR_PARAMETRES] = "Erreur de parametres";
    GB_mess_erreur[ERREUR_DIVERS]     = "Erreur";
  */

  }

  ///
  void MethodeCourante(  const Chaine& nom, const Chaine& fichier="?");
  //   ---------------

  ///
  void FinMethode( );
  //   ----------

  ///
  void AfficheWarning( type_warning type, const Chaine& mess);
  //   --------------

  ///
  void AfficheErreur( type_erreur type, const Chaine& mess);
  //   -------------


}; // GestionErreurs






#endif // _ERREURS_HPP
