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
// Chaine.hpp
// Perpignan,	24/09/94
#pragma once
#ifndef _CHAINE_H
#define _CHAINE_H

#include "CommonBaseConfigure.h"
#include <iosfwd>

#include "style.hpp"
//#include <malloc.h>


/** classe chaine de caract�res */
class CommonBase_EXPORT Chaine
//                      ======
{
        ///
	char* st;	
        ///
	int   size;

        ///
	void IncSize( int n);
        //   -------

        ///
	void NewSize( int n);
        //   -------

  public:
  //=======
    ///
	  Chaine(int sz);
	  //------


    ///
	  Chaine(const char * ch="");
    //------

    ///
	  Chaine(const Chaine& ch);
    //------

    ///
	  ~Chaine();
	  //-------

    ///
	  operator  char *(void) const;
	  //             --------

    /// Reset the size when the string st has been modified
    void reset_size();
    //   ----------

    ///
	  char&  operator[] ( int n);
	  //     -------------------

    ///
	  short int operator==(const Chaine& ch);
	  //        ----------------------

    ///
	  short int operator==( const char* ch);
	  //        ---------------------------

    ///
	  short int operator!=( const char* ch);
	  //        ---------------------------

    ///
	  short int operator==( const char ch);
	  //        --------------------------

    ///
	  Chaine& operator=( const Chaine&);
	  //      ----------------

    ///
	  Chaine& operator=( const char *);
	  //      ----------------

    ////
	  Chaine& operator=(char ch);
	  //      ------------------

    ///
	  int length() const;
    //  ------

    ///
	  void affiche();
    //   -------

    ///
	  Chaine& operator+=(Chaine& ch);
    //      ----------------------

    ///
	  Chaine& operator+=(const char* ch);
    //      --------------------

    ///
	  Chaine& operator+=(char ch);
	  //      -------------------

    ///
    friend CommonBase_EXPORT Chaine operator+(const Chaine&, const char*);
    //                              ---------

    ///
    friend CommonBase_EXPORT std::ostream& operator<<(std::ostream& os, const Chaine& );
    //                                     ----------
};

#endif
