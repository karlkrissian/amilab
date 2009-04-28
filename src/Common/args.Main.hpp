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
#include "style.hpp"

DebutDeclareC
#include <stdlib.h>
FinDeclareC

//#ifdef UNKNOWN
//#undefine UNKOWN
//#endif 

#define UNKNOWN          -1

//---------------------------------------------------------------------------
// Quelques defines .........
//

#define parse_reel(st,nom)                              \
      Si strcmp ( argv[i], st ) == 0 Alors              \
        i += 1;                                         \
        sprintf(text," parsing %s...\n",st);            \
        if ( i >= argc)    E_ErrorParse(text, false );  \
        status = sscanf( argv[i],"%f",&(nom) );         \
        if ( status <= 0 ) E_ErrorParse(text, false );  \
      Autrement

#define parse_entier(st,nom)                            \
      Si strcmp ( argv[i], st ) == 0 Alors              \
        i += 1;                                         \
        sprintf(text," parsing %s...\n",st);            \
        if ( i >= argc)    E_ErrorParse(text, false );  \
        status = sscanf( argv[i],"%d",&(nom) );         \
        if ( status <= 0 ) E_ErrorParse(text, false );  \
      Autrement

#define parse_booleen(st,b)                             \
      Si strcmp ( argv[i], st ) == 0 Alors              \
        b = true;                                       \
      Autrement

#define parse_enum(st,nom,valeur)                      \
      Si strcmp ( argv[i], st ) == 0 Alors             \
  	 Si nom != UNKNOWN Alors                       \
           sprintf(text," %s another value already chosen\n",st);   \
           E_ErrorParse( text, false);                \
         FinSi                                         \
	 nom = valeur;                                 \
      Autrement

#define parse_chaine(st,nom)                              \
      Si strcmp ( argv[i], st ) == 0 Alors              \
        i += 1;                                         \
        sprintf(text," parsing %s...\n",st);            \
        if ( i >= argc)    E_ErrorParse(text, false );  \
        nom = argv[i];                                  \
      Autrement

#define parse_tableau_reel(st,tab, taille)              \
      Si strcmp ( argv[i], st ) == 0 Alors              \
        sprintf(text," parsing %s...\n",st);            \
        Si taille == 0 AlorsFait E_ErrorParse(text, false ); \
        Pour( n, 0, taille-1)                           \
          i++;                                           \
          if ( i >= argc)    E_ErrorParse(text, false ); \
          status = sscanf( argv[i],"%f",&(tab[n]) );        \
          if ( status <= 0 ) E_ErrorParse(text, false ); \
        FinPour                                          \
      Autrement

#define parse_tableau_entier(st,tab, taille)              \
      Si strcmp ( argv[i], st ) == 0 Alors              \
        sprintf(text," parsing %s...\n",st);            \
        Si taille == 0 AlorsFait E_ErrorParse(text, false ); \
        Pour( n, 0, taille-1)                           \
          i++;                                           \
          if ( i >= argc)    E_ErrorParse(text, false ); \
          status = sscanf( argv[i],"%d",&(tab[n]) );        \
          if ( status <= 0 ) E_ErrorParse(text, false ); \
        FinPour                                          \
      Autrement


//--------------------------------------------------------------------
void SauveLigneCommandes( int argc, char* argv[], Chaine nom)
//
{
  FILE*            fic_param;    // Sauvegarde de la ligne de commandes
  Chaine           nom_fic_param;
  Chaine ligne_commandes;
  Chaine cmd;
  int i;

  // chainage de la ligne de commandes :
  ligne_commandes = argv[0];
  DebutBoucle i = 1 ItererTantQue i < argc Pas i++ Faire
    ligne_commandes += ' ';
    ligne_commandes += argv[i];
  FinBoucle // i

  nom_fic_param = nom;
  nom_fic_param += ".param";
  Si (fic_param = fopen( (char*) nom_fic_param, "w")) != NULL Alors
    //    fprintf( fic_param, "#!/usr/bin/tcsh\n\n");
    fprintf( fic_param, "#\tLigne de commandes : \n");
    fprintf( fic_param, " echo \n");
    fprintf( fic_param, " echo %s \n" , (char*) ligne_commandes);
    fprintf( fic_param, " echo \n\n");
    fprintf( fic_param, " %s \n", (char*) ligne_commandes);
    fclose( fic_param);
  FinSi

  // On rend le fichier executable
  cmd = "chmod u+x ";
  cmd += nom_fic_param;
  system( (char*) cmd);

}
