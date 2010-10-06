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
/* Math1.cpp
 * Analyse d'une expression math�matique sous forme de chaine de caract�res
 * reprise du programme en pascal
 * Karl KRISSIAN
 * Perpignan		22/09/94
 */


#include "style.hpp"

extern "C" {
#include <stdio.h>

#ifdef HAVE_MALLOC_H
  #include <malloc.h>
#else
  #include <stdlib.h>
#endif

#include <math.h>
}

#include "chaine.hpp"
#include "math1.hpp"

#if defined(_MSC_VER) 
  inline float roundf(const float& x)
  {
   return (x-floor(x))>0.5 ? ceil(x) : floor(x);
  }
#endif


#define If        if(
#define Then      ){
#define Else      }else{
#define EndIf     }
#define Otherwise }else

#define On        if(
#define DoReturn  ) return

#define While     while (
#define Do        ) {
#define EndWhile  }

// Logical Operators

#define Or    ||
#define And   &&
#define Not   !


// Switch expression In
//   Case ... :
//     ...
//   EndCase
//   ...
// EndSwitch

/*
enum Token {

  //
  Tok_addition,
  Tok_soustraction,

  //
  Tok_multiplication,
  Tok_division,

  // valeurs r�elles
  Tok_nombre,

  // fonctions � 1 parametre
  Tok_parametre,

  Tok_sinus,
  Tok_cosinus,
  Tok_valeur_absolue,
  Tok_tangente,
  Tok_arc_tangente,
  Tok_arc_sinus,
  Tok_arc_cosinus,
  Tok_exponentielle,
  Tok_logarithme_neperien,
  Tok_logarithme10,
  Tok_round,
  Tok_cosinus_hyperbolique,
  Tok_sinus_hyperbolique,
  Tok_valeur_entiere,

  //
  Tok_puissance,
  Tok_factorielle,
  Tok_degre,

  // int�grale : cas particulier
  Tok_integrale

};
*/

/* ---------------------------------------------------------------------------
 * combinaisons de p �l�ments parmis n
 */

int comb( int p, int n)
{
  int i,r;

#define InitLoop   for (
#define NextWhile  ;
#define Step       ;
#define Do         ) {
#define NextLoop   }

  r = 1;
  InitLoop i = p+1 NextWhile i<=n Step i++ Do
    r = r*i;
  NextLoop
  InitLoop i = 2 NextWhile i<=n-p Step i++ Do
    r = (int) (r/i);
  NextLoop
  return r;
};

/* ---------------------------------------------------------------------------
 * fonction valeur absolue
 */

#if !(defined(_MSC_VER))
// || defined(__MINGW32__))
float abs( float r)
{
  if (r < 0)  return -r;
  return r;
}
#endif

/* ---------------------------------------------------------------------------
 * fonction puissance
 */

float puis( float a, float b)
{
  float puis1;
  int   i;
  const int erreur = 12345;

  If b == (int) b Then
      puis1 = 1;

      If b != 0 Then
	InitLoop i = 1 NextWhile i <= abs(roundf(b)) Step i++ Do
	  puis1 *= a;
        NextLoop
      Else
	puis1 = 1;
      EndIf

      If b<0 Then
	If puis1 != 0 Then
	  puis1 = 1/puis1;
	Else
	  puis1 = erreur;
	EndIf
      EndIf

  Otherwise
  If a>0 Then
    puis1 = exp(b*log(a));

  Otherwise
  If (a == 0) And (b>0) Then
    puis1 = 0;

  Otherwise
  If (a<0) And (1/b == roundf(1.0/b))
  And ( roundf(1.0/b)/2 != roundf(roundf(1.0/b)/2) ) Then
    puis1 = -exp(b*log(-a));

  Else
    puis1 = erreur;
  EndIf

  return puis1;

}; // puis()

/* ---------------------------------------------------------------------------
 */

static int   round( float a)
{
 If fabs(a)<32767 Then
   If a >= 0 Then
     return (int) (a+0.5);
   Else
     return (int) (a-0.5);
   EndIf
 Else
     If a>0 Then
       return 32766;
     Else
       return -32767;
     EndIf
 EndIf
};

/* ---------------------------------------------------------------------------
 * valeur d'une chaine repr�sentant un nombre
 */

float nombre( st46 a)
{
  float res;

  sscanf( a,"%f",&(res));
  return res;
};


// =========================================================================
// class CompileExpr Methodes Priv�es

// -------------------------------------------------------------------------
// Ajoute une instruction dans le tableau des instructions
// R�alloue ce tableau s'il est trop petit.
//
void CompileExpr :: AjouteInstruction( Token tok)
//                           -----------------
{

  Si Instr_Pos == Taille_Instr Alors
    Taille_Instr *=2;
    // est-ce qu'il faut refaire new, tout recopier, et faire delete de
    // l'ancien ??
    Instruction = Convertis( Token*,
      realloc( Instruction, sizeof(Token)*Taille_Instr + 1));
  FinSi

  Instruction[ Instr_Pos] = tok;
  Instr_Pos++;

} // CompileExpr :: AjouteInstruction()


// -------------------------------------------------------------------------
// Ajoute un nombre dans le tableau des nombres
// R�alloue ce tableau s'il est trop petit.
//
void CompileExpr :: AjouteNombre( float r)
//                           ------------
{

  Si Nombre_Pos == Taille_Nombre Alors
    Taille_Nombre *=2;
    TabNombre   = Convertis( float*,
      realloc( TabNombre, sizeof(float)*Taille_Nombre + 1));
  FinSi

  TabNombre[ Nombre_Pos] = r;
  Nombre_Pos++;

} // CompileExpr :: AjouteNombre()


// =========================================================================
// CompileExpr Methodes Publiques

// -------------------------------------------------------------------------
//
CompileExpr ::  CompileExpr()
//                         ------------ -----------
{

  Taille_Instr  = 100; // Si �a d�passe, on r�alloue
  Taille_Nombre = 15;
  Taille_Pile   = 100;


  Instruction = Convertis( Token*, new Token[ Taille_Instr]);
  TabNombre   = Convertis( float*,  new float [ Taille_Nombre]);
  Pile        = Convertis( float*,  new float [ Taille_Pile]);
  Instruction = Convertis( Token*, malloc( sizeof(Token)*Taille_Instr + 1));
  TabNombre   = Convertis( float*,  malloc( sizeof(float)*Taille_Nombre + 1));
  Pile        = Convertis( float*,  malloc( sizeof(float)*Taille_Pile   + 1));

  Instr_Pos   = 0;
  Nombre_Pos  = 0;
  Pile_Pos    = 0;

} // CompileExpr Constructor CompileExpr()


// -------------------------------------------------------------------------------
//
CompileExpr :: ~CompileExpr()
//                         ------------ -----------
{

  delete[] Instruction;
  delete[] TabNombre;
  delete[] Pile;

} // CompileExpr ~CompileExpr()


#define InitPile()  Pile_Pos = 0
#define Empile( a ) Pile[Pile_Pos++] = a
#define Depile()    Pile[--Pile_Pos]

// -------------------------------------------------------------------------------
//
float CompileExpr :: Resultat()
//                              --------
{


    int   NombreCourant = 0;
    register float   term1, term2;
    register int   i;

  InitPile();

  for(  int pos = 0
  ;  pos < Instr_Pos
  ;  pos++ Faire

    switch ( Instruction[pos] ){

      case Tok_nombre :
      //     ------------
        Si Pile_Pos == Taille_Pile Alors
          Taille_Pile *=2;
	  Pile = Convertis( float*,
	    realloc( Pile, sizeof(Token)*Taille_Pile + 1));
        FinSi
	Empile( TabNombre[NombreCourant] );
        NombreCourant++;
      break;

      case Tok_parametre :
      //     ---------------
	Si Pile_Pos == Taille_Pile Alors
          Taille_Pile *=2;
	  Pile = Convertis( float*,
	    realloc( Pile, sizeof(Token)*Taille_Pile + 1));
        FinSi
	Empile( ParamValue[ Convertis( int, TabNombre[ NombreCourant])]);
	NombreCourant++;
      break;

      case Tok_addition :
      //     --------------
        term2 = Depile();
        term1 = Depile();
        Empile( term1 + term2 );
      break;

      case Tok_superieur :
      //     -------------
	term2 = Depile();
        term1 = Depile();
        Si term1 > term2 Alors
          Empile( 1.0);
        Sinon
	  Empile( 0.0);
        FinSi
      break;

      case Tok_inferieur :
      //     -------------
	term2 = Depile();
        term1 = Depile();
        Si term1 < term2 Alors
          Empile( 1.0);
        Sinon
	  Empile( 0.0);
        FinSi
      break;

      case Tok_egal :
      //     ----------
	term2 = Depile();
        term1 = Depile();
        Si term1 == term2 Alors
          Empile( 1.0);
        Sinon
	  Empile( 0.0);
        FinSi
      break;

      case Tok_et:
      //     ------
	term2 = Depile();
        term1 = Depile();
        Si (term1 > 0.5) Et ( term2 > 0.5) Alors
          Empile( 1.0);
        Sinon
	  Empile( 0.0);
        FinSi
      break;

      case Tok_ou:
      //     ------
	term2 = Depile();
        term1 = Depile();
        Si (term1 > 0.5) Ou ( term2 > 0.5) Alors
          Empile( 1.0);
        Sinon
	  Empile( 0.0);
        FinSi
      break;

      case Tok_soustraction :
      //     ------------------
	term2 = Depile();
        term1 = Depile();
        Empile( term1 - term2);
      break;

      case Tok_multiplication :
      //     --------------------
        term2 = Depile();
        term1 = Depile();
        Empile( term1 * term2 );
      break;

      case Tok_division :
      //     --------------
	term2 = Depile();
	term1 = Depile();
	Si term2 != 0 Alors
	  Empile( term1/term2);
	Sinon
	  Erreur |= CALCUL_ERROR;
	  return 0;
	FinSi
      break;

      case Tok_sinus :
      //     -----------
        term1 = Depile();
	Empile( sin( term1));
      break;

      case Tok_cosinus :
      //     -------------
        term1 = cos( Depile() );
        Empile( term1);
      break;

      case Tok_tangente :
      //     --------------
	term1 = Depile();
	Si cos(term1) != 0 Alors
	  Empile( sin( term1)/cos( term1) );
	Sinon
          Erreur |= CALCUL_ERROR;
	  return 0;
	FinSi
      break;

      case Tok_arc_tangente :
      //     ------------------
        term1 = Depile();
        Empile( atan( term1));
      break;

      case Tok_arc_sinus :
      //     ---------------
	term1 = Depile();
	Si term1 >= -1 Et term1 <=1 Alors
	  Empile( asin( term1));
	Sinon
	  Erreur |= CALCUL_ERROR;
	  return 0;
	FinSi
      break;

      case Tok_arc_cosinus :
      //     -----------------
	term1 = Depile();
	Si term1 >= -1 Et term1 <=1 Alors
	  Empile( acos( term1));
	Sinon
	  Erreur |= CALCUL_ERROR;
	  return 0;
	FinSi
      break;

      case Tok_exponentielle :
      //     -------------------
        term1 = Depile();
        Empile( exp( term1));
      break;

      case Tok_logarithme_neperien :
      //     -------------------------
	term1 = Depile();
	Si term1 > 0 Alors
	  Empile( log( term1));
	Sinon
	  Erreur |= CALCUL_ERROR;
	  return 0;
	FinSi
      break;

      case Tok_logarithme10 :
      //     ------------------
	term1 = Depile();
	Si term1 > 0 Alors
	  Empile( log10( term1));
	Sinon
	  Erreur |= CALCUL_ERROR;
	  return 0;
	FinSi
      break;

      case Tok_round :
      //     -----------
        term1 = Depile();
        Empile( round( term1));
      break;

      case Tok_cosinus_hyperbolique :
      //     --------------------------
	term1 = Depile();
        Empile( 0.5*(exp(term1)+exp(-1*term1)) );
      break;

      case Tok_sinus_hyperbolique :
      //     ------------------------
	term1 = Depile();
        Empile( 0.5*(exp(term1)-exp(-1*term1)) );
      break;

      case Tok_valeur_entiere :
      //     --------------------
        term1 = Depile();
        Empile( Convertis( int, term1));
      break;

      case Tok_puissance :
      //     ---------------
	term2 = Depile();
	term1 = Depile();
        Empile( puis( term1, term2));
      break;

      case Tok_factorielle :
      //     -----------------
        term1 = Depile();
	term2 = 1;
	for(   i = 1 ;  i <= round(term1) ;  i++ Faire
	  term2 *= i;
	} // end for
        Empile( term2);
      break;

      case Tok_degre :
      //     -----------
        term1 = Depile();
        Empile( term1/180* PI);
      break;

      case Tok_valeur_absolue :
      //     --------------------
        term1 = Depile();
//        Empile( fabsf(term1));
// pour solaris
        Empile( (float) fabs(term1));
      break;

      case Tok_integrale :
      //     ---------------
	// non trait� ...
      break;

    } // end switch

  } // end for

  return Depile();

} // CompileExpr :: Resultat()



/* ===========================================================================
 * Expression math�matique :
 * Class ExprMath
 */

// METHODES PRIVEES :
// ==================

/* ---------------------------------------------------------------------------
 * calcul d'une int�grale
 */
/*
float ExprMath::integrale( int from_pos, int to_pos, float first, float last,
//              ---------
			    int m2)
{
  float i,d,result;

  If (m2 > 2) And (m2/2 == (int) (m2/2)) Then
    result = Evaluate( from_pos, to_pos, first);
    d = (last-first)/m2;
    i = first+d;
    While abs(i-last-d) > 1E-7 Do
      result += 4 * Evaluate( from_pos, to_pos, i);
      i += d;
      result += 2*  Evaluate( from_pos, to_pos, i);
      i += d;
    EndWhile
    result = (result - Evaluate( from_pos, to_pos, last)) * d/3;
  Else
    Erreur |= CALCUL_ERROR;
    return 0;
  EndIf
  return result;

}; // ExprMath::integrale()
*/

/* ---------------------------------------------------------------------------
 */

int ExprMath::CanBeDigit( char ch)
{
	switch (ch) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.': return true;
    default : return false;
	} // EndSwitch

} // ExprMath::CanBeDigit();

/* ---------------------------------------------------------------------------
 * calcul de l'expression math�matique
 */

void ExprMath::recherche( char car1, char car2, int &from_pos, int &to_pos)
//             ---------
{
  int i,j;

  i = pos;
  j = 1;
  While (j != 0) And (i <= LastPos) Do
    If chaine[i] == car1 Then
      j++;
    EndIf
    If chaine[i] == car2 Then
      j--;
    EndIf
    i++;
  EndWhile

  from_pos = pos;
  to_pos   = i-2; // juste avant le dernier caract�re qui vaut car2
  pos      = i;

}; // ExprMath::recherche()

/* ---------------------------------------------------------------------------
 */

void ExprMath::SauteBlancs()
//             -----------
{

  // On saute les blancs :
  //======================
  TantQue (chaine[pos] == ' ') Et (pos <= LastPos) Faire
    pos++;
  FinTantQue

} // ExprMath::SauteBlancs()

/* ---------------------------------------------------------------------------
 */

#define CodeFct1( chaine, tok_inst)	\
  Si ch == chaine Alors          	\
    HigherLevel();                	\
    AjouteInstruction( tok_inst); 	\
    return;                     	\
  FinSi


void ExprMath::HigherLevel()
//             -----------
{

  Chaine ch;
  int from_pos;
  int to_pos;
  int i;


  SauteBlancs();

  // Mots � 1 caract�re :
  // ====================
  If pos > LastPos Then
    Erreur |= SYNTAX_ERROR;
    return;
  EndIf
  ch = chaine[pos++];

  // Test Pour les param�tres
  for(  i = 0
  ;  i < NumberOfParameters
  ;  i++ Faire
    Si ch == Parameter[i] Alors
      AjouteNombre( i);
      AjouteInstruction( Tok_parametre);
      return;
    FinSi
  } // end for

  switch (ch[0]) {

    // f(..) appel d'une fonction
    //    case 'f':
    //      pos++;
    //      i = round(n_suivant);
    //      return fonc[i].Value( variable);

    // (..) calcul de la parenth�se
    case '(':
      recherche( '(', ')', from_pos, to_pos);
      Compile( from_pos, to_pos);
      return;

    /* Non trait�
    // I(..) int�grale
    case 'I':
	// borne inf�rieure de l'intervalle
	recherche( '?', ',', from_pos, to_pos);
	a = Evaluate( from_pos, to_pos, ParamValue[1]);

        // borne sup�rieure
        recherche( '?', ',', from_pos, to_pos);
	b = Evaluate( from_pos, to_pos, ParamValue[1]);

        // nombre de points
        recherche( '?', ',', from_pos, to_pos);
	term  = Evaluate( from_pos, to_pos, ParamValue[1]);

        // calcul de l'int�grale
        recherche( '{', '}', from_pos, to_pos);
	return integrale( from_pos, to_pos ,a, b, round(term));
    */

	} // EndSwitch

  // Parcours des nombres :
  If CanBeDigit( ch[0]) Or ch == '-' Or ch == '+' Then
    While CanBeDigit( chaine[pos]) And ( pos <= LastPos) Do
      ch += chaine[pos++];
    EndWhile
    AjouteNombre( nombre( (char *) ch ));
    AjouteInstruction( Tok_nombre);
    return;
  EndIf

  // Mots � 2 Carat�res
  // ==================
  // valeur pi
  If pos > LastPos Then
    Erreur |= SYNTAX_ERROR;
    return;
  EndIf
  ch += chaine[pos++];

  If ch == "pi" Then
    pos += 2;
    AjouteNombre( PI);
    AjouteInstruction( Tok_nombre);
    return;
  EndIf


  // Mots � 3 caract�res
  // ===================
  If pos > LastPos Then
    Erreur |= SYNTAX_ERROR;
    return;
  EndIf
  ch += chaine[pos++];

  CodeFct1( "sin", Tok_sinus);
  CodeFct1( "cos", Tok_cosinus);
  CodeFct1( "abs", Tok_valeur_absolue);
  CodeFct1( "tan", Tok_tangente);
  CodeFct1( "atn", Tok_arc_tangente);
  CodeFct1( "asi", Tok_arc_sinus);
  CodeFct1( "aco", Tok_arc_cosinus);
  CodeFct1( "exp", Tok_exponentielle);
  CodeFct1( "lgn", Tok_logarithme_neperien);
  CodeFct1( "log", Tok_logarithme10);
  CodeFct1( "rnd", Tok_round);
  CodeFct1( "coh", Tok_cosinus_hyperbolique);
  CodeFct1( "sih", Tok_sinus_hyperbolique);
  CodeFct1( "int", Tok_valeur_entiere);

  Erreur |= SYNTAX_ERROR;
  return;

} // ExprMath::HigherLevel()


/* ---------------------------------------------------------------------------
 */
void ExprMath::PuisTerm()
//             --------
{

  HigherLevel();

  SauteBlancs();

  If pos <= LastPos Then
	  switch (chaine[pos]) {

      case '^' :
      //   ---
	pos ++;
	HigherLevel();
	AjouteInstruction( Tok_puissance);
        return;

      case '!' :
      //   ---
	pos ++;
	AjouteInstruction( Tok_factorielle);
        return;

      case '\'' :
//      case '�' :
      //   ---
	pos ++;
	AjouteInstruction( Tok_degre);
        return;

  } //EndSwitch
  EndIf

  return;

} // ExprMath::PuisTerm()


/* ---------------------------------------------------------------------------
 */
void ExprMath::MultTerm()
//             ---------
{

  PuisTerm();

  SauteBlancs();

  While ( pos <= LastPos) And Not( Erreur)

    And ( chaine[pos] != '+')
    And ( chaine[pos] != '-')

    And ( chaine[pos] != '<')
    And ( chaine[pos] != '>')
    And ( chaine[pos] != '=')
    And ( chaine[pos] != '&')
    And ( chaine[pos] != '|')
  Do

  switch (chaine[pos]) {

      case '*' :
      //   ---
	pos++;
        PuisTerm();
	AjouteInstruction( Tok_multiplication);
	break;

      case '/' :
      //   ---
        pos++;
        PuisTerm();
        AjouteInstruction( Tok_division);
		break;

        default :
      //-------
	Erreur |= SYNTAX_ERROR;
        return;
  } // EndSwitch

  EndWhile

  return;

}  // ExprMath::MultTerm()


/* ---------------------------------------------------------------------------
 */
void ExprMath::AddTerm()
//             -------
{

  MultTerm();

  SauteBlancs();

  While ( pos <= LastPos) And Not( Erreur)
    And ( chaine[pos] != '<')
    And ( chaine[pos] != '>')
    And ( chaine[pos] != '=')
    And ( chaine[pos] != '&')
    And ( chaine[pos] != '|')
  Do

  switch (chaine[pos]) {

      case '+' :
      //   ---
	pos++;
        MultTerm();
        AjouteInstruction( Tok_addition);
		break;

      case '-' :
      //   ----
	pos++;
        MultTerm();
        AjouteInstruction( Tok_soustraction);
      break;

        default :
      //-------
	Erreur |= SYNTAX_ERROR;
        return;
  } // EndSwitch

  EndWhile

  return;

}  // ExprMath::AddTerm()


/* ---------------------------------------------------------------------------
 * begin : position of the first character
 * end   : position of the last  character
 */

void ExprMath::Compile( int begin, int end )
//             -------
{

  int    prev_pos;
  int    prev_lastpos;

  // record previous values
  prev_pos         = pos;
  prev_lastpos     = LastPos;

  // init new ones
  pos             = begin;
  LastPos         = end;

  If pos > LastPos Then
    Erreur |= SYNTAX_ERROR;
    return;
  EndIf

  AddTerm();
  While (pos <= LastPos) And Not(Erreur) Do

	  switch (chaine[pos]) {

      case '>' :
      //   ---
	pos++;
        AddTerm();
        AjouteInstruction( Tok_superieur);
      break;

      case '<' :
      //   ---
	pos++;
        AddTerm();
        AjouteInstruction( Tok_inferieur);
      break;

      case '=' :
      //   ----
	pos++;
        AddTerm();
        AjouteInstruction( Tok_egal);
      break;

      case '&' :
      //   ----
	pos++;
        AddTerm();
        AjouteInstruction( Tok_et);
      break;

      case '|' :
      //   ----
	pos++;
        AddTerm();
        AjouteInstruction( Tok_ou);
      break;

        default :
      //-------
	Erreur |= SYNTAX_ERROR;
	return;

  } // EndSwitch

  EndWhile

  // recover previous values
  pos             = prev_pos;
  LastPos         = prev_lastpos;

  return;

} // ExprMath::Compile()


// METHODES PUBLIQUES :
// ====================

/* ---------------------------------------------------------------------------
 */

ExprMath::ExprMath(Chaine& ch, char param1, char param2) : CompileExpr()
//        --------
{
  chaine             = ch;
  Parameter[0]       = param1;
  Parameter[1]       = param2;
  NumberOfParameters = 2;
  Erreur             = 0; //NO_ERROR;
  pos                = 0;
  LastPos            = ch.length() - 1;
  a_compiler         = true;

} // ExprMath::ExprMath()

/* ---------------------------------------------------------------------------
 * Calcul du r�sultat de l'expression enti�re
 */

float ExprMath::Value( float val1, float val2)
//              -----
{
  Si a_compiler Alors
    Compile( 0, LastPos);
    a_compiler = false;
  FinSi
  Si Erreur == SYNTAX_ERROR AlorsFait return 0;

  ParamValue[0] = val1;
  ParamValue[1] = val2;
  Erreur        = 0; //NO_ERROR;
  pos           = 0;
  return Resultat();

}; // ExprMath::Value()


/* ---------------------------------------------------------------------------
 * Ajout d'un parametre
 * BUG : v�rifier que le param�tre n'existe pas d�j� ...
 */

int ExprMath :: AddParameter( char caract )
//                             ------------
{
  int n;

  Si NumberOfParameters < 10 Et caract >= 'A' Et caract <= 'Z' Alors
    // Teste si le param�tre existe d�j� :
    for(    n = 0
    ;  n < NumberOfParameters Et Parameter[n] != caract
    ;            n++ Faire
    } // end for

    Si n < NumberOfParameters Alors
      return false;
    Sinon
      n = NumberOfParameters;
      NumberOfParameters++;
      Parameter[n] = caract;
      ParamValue[n] = 1;
      return true;
    FinSi
  Autrement return false;

} // ExprMath :: AddParamter()


/* ---------------------------------------------------------------------------
 * fixe la valeur d'un param�tre
 */

int ExprMath :: SetParamValue( char caract, float valeur )
//                             -------------
{

   int n;

  for(  n = 0
  ;  n < NumberOfParameters Et Parameter[n] != caract
  ;  n++ Faire
  } // end for

  Si n < NumberOfParameters Alors
    ParamValue[n] = valeur;
    return true;
  Autrement return false;

} // ExprMath :: AddParamter()


/* ---------------------------------------------------------------------------
 * Retour des erreurs
 */

int ExprMath :: Erreurs( )
//                             -------
{
  return Erreur;
} // ExprMath::Value()

// END.

