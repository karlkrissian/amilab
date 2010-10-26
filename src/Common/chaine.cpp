/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@ctm.ulpgc.es

    OSRAD is a noise reducing filter program
    ==================================================
    Copyright (C) 2008  Karl Krissian

    OSRAD is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    OSRAD is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in LesserGPL_license.txt
*/

// Karl KRISSIAN
// Chaine.cpp
// Perpignan,	24/09/94

#include "AMILabConfig.h"
#include "style.hpp"

extern "C" {
#include <stdio.h>
#include <string.h>
//#include <malloc.h>
}

#include "chaine.hpp"

using namespace std; 

// METHODES PRIVEES :
// ==================

/* ------------------------------------------------------------------------
 */

void Chaine::IncSize( int n)
//           -------
{
  char* s;

  Si (int) strlen(st)+ n  > size Alors
    size = strlen(st) + n + 10;     
    s = new char[ size + 1];
    strcpy(s, st);
    delete[] st;
    st = s;
    // st = ( char *) realloc( st, size + 1);
  FinSi
}

/* ------------------------------------------------------------------------
 */

void Chaine::NewSize( int n)
//           -------
{
  char* s;

  Si n > size Alors
    size = n + 10;
    s = new char[ size + 1];
    strcpy( s, st);
    delete[] st;
    st = s;
    // st = ( char *) realloc( st, size + 1);
  FinSi
}

// METHODES PUBLIQUES :
//=====================

Chaine::Chaine(int sz)
//      ------
{
  size = sz;
  st = new char[ size+1];
  // st = (char *) malloc( size+1);
}


/* ------------------------------------------------------------------------
 */

Chaine::Chaine(const char * ch)
//      ------
{
  size = strlen(ch);
  st = new char[ size+1];
  // st = (char *) malloc( size+1);
  strcpy(st,ch);
}

/* ------------------------------------------------------------------------
 */

Chaine::Chaine(const Chaine& ch)
//      ------
{
  size =  ch.size;
  st = new char[ size+1];
  strcpy(st,ch.st);
}

/* ------------------------------------------------------------------------
 */

Chaine::~Chaine()
//      ---------
{
  delete[] st;
} /* segmentation fault */

/* ------------------------------------------------------------------------
 */

Chaine::operator  char *(void) const
//      -----------------
{
  return st;
}

/* ------------------------------------------------------------------------
 *  Reset the size when the string st has been modified
 */
        
void Chaine::reset_size()
//            --------
{

  Si (int)strlen(st) > size AlorsFait size = strlen(st);

}


/* ------------------------------------------------------------------------
 */

char&  Chaine::operator[] ( int n)
//             -------------------
{
  Si n < size Alors  
    return st[n];
  Sinon
    return st[size];
  FinSi
}

/* ------------------------------------------------------------------------
 */

short int Chaine::operator==(const Chaine& ch)
//                ----------------------
{
  return (!strcmp(st,(char *) ch));
}

/* ------------------------------------------------------------------------
 */

short int Chaine::operator==( const char* ch)
//                ---------------------------
{
  return (!strcmp(st, ch));
}

/* ------------------------------------------------------------------------
 */

short int Chaine::operator!=( const char* ch)
//                ---------------------------
{
  return (strcmp(st, ch));
}

/* ------------------------------------------------------------------------
 */

short int Chaine::operator==( const char ch)
//                --------------------------
{
  return ( strlen(st) == 1) && (st[0] == ch);
}

/* ------------------------------------------------------------------------
 */

Chaine& Chaine::operator=( const Chaine& ch)
//              --------------------
{
  NewSize( strlen( (char*) ch ));
  strcpy(st,(char *) ch);
  return *this;
}

/* ------------------------------------------------------------------------
 */

Chaine& Chaine::operator=( const char* ch)
//              --------------------
{
  if (st!=ch) {
    NewSize( strlen(  ch ));
    strcpy(st, ch);
  }
  return *this;
}

/* ------------------------------------------------------------------------
 */

Chaine& Chaine::operator=(char ch)
//              ------------------
{
  NewSize( 1);
  st[0] = ch;
  st[1] = '\0';
  return *this; 
}

/* ------------------------------------------------------------------------
 */

int Chaine::length() const
//          --------
{
  return strlen(st);
}

/* ------------------------------------------------------------------------
 */

void Chaine::affiche()
//           ---------
{
  printf("%s",st);
}

/* ------------------------------------------------------------------------
 */

Chaine& Chaine::operator+=(Chaine& ch)
//              ----------------------
{
  IncSize( strlen((char *) ch) );
  strcat(st,(char *) ch);
  return *this;
}

/* ------------------------------------------------------------------------
 */

Chaine& Chaine::operator+=(const char* ch)
//              ----------------------
{
  IncSize( strlen(ch) );
  strcat(st, ch);
  return *this;
}

/* ------------------------------------------------------------------------
 */

Chaine& Chaine::operator+=(char ch)
//              -------------------
{
  IncSize( 1);
  st[strlen( st)+1] = '\0';
  st[strlen( st)  ] = ch;
  return *this;
}


/* ------------------------------------------------------------------------
 */
Chaine operator+(const Chaine& ch1, const char* ch2)
//
{

  
    Chaine chaine;

  chaine  = ch1;
  chaine += ch2;

  return chaine;

} // operator+()


/* ------------------------------------------------------------------------
 */
ostream& operator<<(ostream& os, const Chaine& c)
//       ----------
{
  return os << (char*) c.st;

}
