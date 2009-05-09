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
/* epi_err.h 2.1 5/13/96 */
/* epi_err.h 1.1 1/10/94 */
/************************************************************************/
/*
    epi_err.h

	Standart error code and messages for fatal errors

    (c) Jean-Philippe THIRION -- INRIA -- August 10 1992
*/
/************************************************************************/

#ifndef _epi_err_h_
#define _epi_err_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char program[80];
extern unsigned char verbose;

#ifndef true
  #define true		1
#endif

#ifndef true
  #define false		0
#endif

#ifndef B_FNAME_LENGTH
#define B_FNAME_LENGTH 80
#endif

#define E_ERRNO 0								/* error codes	*/
#define E_ERRUNKNOWN 1
#define E_ERRC 2
#define E_ERRO 3
#define E_ERRW 4
#define E_ERRR 5
#define E_ERRMEM 6
#define E_ERRDIV 7
#define E_ERRFATAL 8
#define E_ERRARRAY 9
#define E_ERRNULL 10
#define E_ERRMISMATCH 11
#define E_ERRNB 12

#define EM_ERRNO "no errors"					/* error messages	*/
#define EM_ERRUNKNOWN "unknown type"
#define EM_ERRC "creating file"
#define EM_ERRO "opening file"
#define EM_ERRW "writing in file"
#define EM_ERRR "reading in file"
#define EM_ERRMEM "no more memory"
#define EM_ERRDIV "divide by zero"
#define EM_ERRFATAL "fatal error"
#define EM_ERRARRAY "array size overflow"
#define EM_ERRNULL "null pointer"
#define EM_ERRMISMATCH "type mismatch"
#define EM_ERRNB "total number of error kinds"

/*......................................................................*/
/*
	Fatal error management system, to be used by all Epidaure.lib
	routines since no exit() should appears in the program. If verbose
	mode is on, then the name of the procedure "proc" is printed,
	and eventually a complementary message "mess".

	E_ERR:		if (test) set the fatal error flag to no, return value
	E_ERRN:		if (test) set the fatal error flag to no, return no value
	E_XERR:		the same without test, to be used in switch()
	E_XERRN:	... without returned values
	E_ISERR:	test if fatal error flag on, return value
	E_ISERRN:	test if fatal error flag on, return no value
	E_SETERR:	set the fatal error flag to no, no return at this stage
	E_REPERR:	if fatal error, make some reparations
	E_RESETERR:	clear the error flag

example, for the allocation of memory:

	char *myAlloc( long size )
	{
    	buf= malloc( (unsigned) size );
    	E_ERR( buf==NULL, E_ERRMEM, NULL, "myAlloc", "no more memory left");
		return( buf );
		}
	...
	table= myAlloc( long size )
	E_ISERR( false, "myAllocTables", "trying to allocate table" );
	...

etc. The verbose mode produces a trace back of the errors in routines.
In case of fatal error, all routines should make reparations, that is,
desallocates all allocated routines.

*/
/*......................................................................*/

#define E_ERR(test,no,ret,proc,mess) \
	{if (test) { if( E_Error(no,proc,mess) ) return(ret); }}

#define E_ERRN(test,no,proc,mess) \
	{if (test) {if(E_Error(no,proc,mess)) return;}}

#define E_XERR(no,ret,proc,mess) {if( E_Error(no,proc,mess) ) return(ret);}
#define E_XERRN(no,proc,mess) {if( E_Error(no,proc,mess)) return;}
#define E_ISERR(ret,proc,mess) {if(E_Error(E_ERRNO,proc,mess))  return(ret);}
#define E_ISERRN(proc,mess) {if(E_Error(E_ERRNO,proc,mess)) return;}
#define E_SETERR(no,proc,mess) {E_Error(no,proc,mess);}
#define E_REPERR(repare) {if(E_Error(E_ERRNO,(char*)NULL,(char*)NULL)) repare;}
#define E_RESETERR() {E_ErrorReset();}

/*......................................................................*/

int E_Error(
int no, 	/* Reference number of the error */
const char *proc, /* procedure where error occured */
const char *mess 	/* complementary message */
);

void E_ErrorReset( void );
void E_FatalInit( void );
void T_SetExtend( char *name1, char *name2, char *extend );
void T_Err( char *str1, char *str2 );
void T_Warn( char *str1, char *str2 );


#endif
