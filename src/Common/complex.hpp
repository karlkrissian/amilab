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
// Je Recopie ce code en raison de problemes de compilation ...
//

#ifndef		__COMPLEX_HXX
#define		__COMPLEX_HXX

//
//
/*  COPYRIGHT (C) DIGITAL EQUIPMENT CORPORATION 1990, 1991, 1992*/
//
/*  THIS SOFTWARE IS FURNISHED UNDER A LICENSE AND MAY BE USED AND  COPIED*/
/*  ONLY  IN  ACCORDANCE  WITH  THE  TERMS  OF  SUCH  LICENSE AND WITH THE*/
/*  INCLUSION OF THE ABOVE COPYRIGHT NOTICE.  THIS SOFTWARE OR  ANY  OTHER*/
/*  COPIES  THEREOF MAY NOT BE PROVIDED OR OTHERWISE MADE AVAILABLE TO ANY*/
/*  OTHER PERSON.  NO TITLE TO AND OWNERSHIP OF  THE  SOFTWARE  IS  HEREBY*/
/*  TRANSFERRED.*/
//
/*  THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE  WITHOUT  NOTICE*/
/*  AND  SHOULD  NOT  BE  CONSTRUED  AS  A COMMITMENT BY DIGITAL EQUIPMENT*/
/*  CORPORATION.*/
//
/*  DIGITAL ASSUMES NO RESPONSIBILITY FOR THE USE OR  RELIABILITY  OF  ITS*/
/*  SOFTWARE ON EQUIPMENT WHICH IS NOT SUPPLIED BY DIGITAL.*/
//
//

/*++*/
/*  FACILITY:	DEC C++ Class Library*/
//
/*  SUBSYSTEM:	Complex arithmetic*/
//
/*  MODULE:	complex*/
//
/*  INFORMATION HIDDEN:*/
//
/*	Representation of a complex number.*/
//
/*  MODULE DESCRIPTION:*/
//
/*	This module implements the representation of complex numbers and defines*/
/*	the functions which operate on them.*/
//
/*	Differences from AT&T's product:*/
/*	    Add tan(const complex &).*/
/*	    Add tanh(const complex &).*/
/*	    Add arg1(const complex &).*/
/*	    Add sqr(const complex &).*/
/*	    Make the data members of c_exception be public instead of private.*/
//
/*  AUTHORS:*/
//
/*	Craig Hansen-Sturm*/
/*	Aron K. Insinga*/
//
/*  CREATION DATE:  13-Oct-1988*/
//
/*  VERSION:  1.1*/
//
/*  DESIGN ISSUES:*/
//
/*	The representation is kept in cartesian coordinates (as in FORTRAN)*/
/*	to prevent errors resulting from converting back and forth between*/
/*	coordinate systems (including altering the parameters to the operators,*/
/*	which are passed by reference).*/
//
/*  PORTABILITY ISSUES:*/
//
/*	The VMS RTL is not used (except through the C RTL).*/
//
/*  MODIFICATION HISTORY:*/
//
/*	1.0-*/
/*	   1  CHS  13-Oct-1988	Initial creation*/
/*	   2  AKI  17-Jan-1990	Add standard comments, c_exception*/
/*	   3  AKI  23-May-1990	Revise & complete standard comments*/
/*				Remove obselete "overload" declarations*/
/*				Eliminate is_polar (a redundant variable)*/
/*				Have 2nd arg default to 0 in*/
/*				    complex(double, double) (imaginary part = 0)*/
/*				    and polar(double, double) (angle = 0)*/
/*				    to eliminate single-arg forms*/
/*				Overlay cartesian & polar coordinates*/
/*				Make is_cartesian an int instead of a char*/
/*				    (it is really a boolean)*/
/*				Replace cxxl_platform.hxx with cxxl.h*/
/*				Use cxxl_boolean_t*/
/*	   4  AKI  15-Jun-1990	Add call by reference for complex args*/
/*				Use inline functions*/
/*				Rewrite using ONLY cartesian coordinates to*/
/*				    prevent altering the reference parameters*/
/*				    due to numerical errors in converting back*/
/*				    and forth*/
/*	   5  AKI  18-Jun-1990	Fix typos*/
/*				Make complex(double, double, cxxl_boolean_t) be*/
/*				    inline instead of polar(double, double)*/
/*	   6  AKI  28-Jun-1990	Make complex_zero and "complex &" args be const*/
/*				    (except for operator<<)*/
/*	   7  AKI  02-Aug-1990	Make complex_zero local to each using module*/
/*				    so that the compiler sees the value when*/
/*				    compiling each module (instead of making*/
/*				    the linker fix up references to it)*/
/*				Change literals' values for compatability*/
/*	   8  AKI  17-Aug-1990	Make last arg to c_exception::c_exception(char,*/
/*				    const complex &, const complex&) be of type*/
/*				    const complex & like the one before it.*/
/*	   9  AKI  05-Sep-1990	Add complex::cxxl__exp(cxxl_boolean_t &) to fix*/
/*				    a problem with user defined error handling*/
/*				    bypassing error detection in sinh & cosh.*/
/*	  10  AKI  12-Sep-1990	Make polar() be inline too*/
/*	  11  AKI  17-Sep-1990	Add complex::cxxl__real_overflow_return_value()*/
/*				    since exp, sinh, cosh compute the same value*/
/*	  12  AKI  19-Sep-1990	Make the data membrs of c_exception be public so*/
/*				    that user-defined error handlers may access*/
/*				    them even if the error handlers are not*/
/*				    named complex_error.*/
/*	  17  AKI  26-Sep-1990	Move polar() from .CXX file to .HXX file*/
/*	  18  AKI  27-Sep-1990	Use polar(double, double) instead of*/
/*				complex::complex(double, double, cxxl_boolean_t)*/
/*				Remove polar()*/
/*				Make c_exception constructor not be inline*/
/*	  19  AKI  28-Sep-1990	Remove extra initializers on function arguments*/
/*				Add inline keyword in class declaration*/
/*	  20  AKI  12-Oct-1990	Replace #include "..." with #include <...>*/
/*	  21  AKI  18-Jul-1991	Change preprocessor symbol which prevents*/
/*				duplicate inclusion*/
/*	  22  AKI  27-Aug-1991	Use Objection for error messages*/
/*	  23  AHM   8-Oct-1991	Reformat comments before release*/
/*	  24  AKI  21-Oct-1991	Use M_PI and HUGE_VAL from <math.h>*/
/*				Don't export PI, PI2, or HUGE*/
/*	  25  AKI   5-Feb-1992	Shorten comments*/
/*	  26   HH  19-Feb-1992	Undefine the definition of true from cxxl.hxx*/
/*				    to work around it being multiply defined. */
/*	  27   HH  28-Feb-1992	Add __extern_model pragmas for proper handling*/
/*				    of symbols by the DEC C++ compiler on VMS.*/
/*	  28  AKI  01-Apr-1992	Replace __ with _ and fix Messages for VMS*/
/*	  29   HH  12-Apr-1992	Make cxxl.hxx to be the first included header.*/
/*	  30  JSY  15-Apr-1992  Add support for sharable images.*/
/*	  31   HH   6-May-1992	Remove the work-around for C RTL unconditionally*/
/*				    defining true, which is now fixed.*/
/*	  32  AKI  11-May-1992	Replace cxxl_boolean_t with int*/
/*	  33  AKI  14-May-1992	Undefine macros for any ANSI C math functions*/
/*	  34  AKI  03-Jun-1992	Eradicate the symbols true & false*/
/*	  35  AKI  17-Jun-1992	Remove the unused reference to <objection.hxx>*/
/*				(the objections are now hidden in complex.cxx)*/
/*	  36  AKI  18-Jun-1992	Use member initializers in constructors*/
//
/*	1.1-*/
/*	  37  AKI  27-Oct-1992	Use a macro to circumvent extraneous definition*/
/*				of type complex in <math.h> on OSF/1*/
//
/*	1.2-*/
/*	  38  RKP   9-Mar-1994	Disable complex macro definition on Windows NT(tm)*/
/*--*/



//
//
/*  INCLUDE FILES*/
//
//

/*  MODIF PERSO
#include <cxxl.hxx>
*/
/*  MODIF PERSO
#include <iostream.h>
*/

extern "C"
{
#include <stddef.h>

#if ! defined(complex) && ! defined(__NT)
    /* in case <math.h> defines its own struct complex, give it a different name*/
    /* <math.h> on Windows NT (tm) defines its own complex macro*/
#   define complex __cxxl_math_complex
#endif
#include <math.h>
#undef complex

}

/* ANSI C says that these may be macros in <math.h> but it prevents overloading*/
#undef sin
#undef sinh
#undef cos
#undef cosh
#undef exp
#undef pow
#undef sqrt



//
//
/*  LINKAGE*/
//
//

#if defined(__VMS) && defined(__DECCXX)
#   pragma __extern_model __save
#   pragma __extern_model __strict_refdef
#   pragma __extern_prefix __save
#   pragma __extern_prefix __CXXL_FLOAT_FUNC_LINKAGE
#   pragma __member_alignment __save
#   if defined __VAX
#       pragma __nomember_alignment
#   else
#       pragma __member_alignment
#   endif
#endif

class complex

/*++*/
/*  CLASS DESCRIPTION:*/
//
/*	Complex number (real part plus imaginary part)*/
//
/*  DESIGN:*/
//
/*	The complex number is only stored in cartesian coordinates to prevent*/
/*	errors resulting from converting back and forth.  ("Floating point*/
/*	numbers are like little piles of sand; every time you move one, you*/
/*	lose a little sand and pick up a little dirt.")*/
//
/*	The operators are defined as friends so that implicit conversions can*/
/*	be done, such as treating 1+complex(3,4) as complex(1)+complex(3,4).*/
/*	Otherwise, the operators should really be defined as member functions*/
/*	instead of friend functions.*/
//
/*	Parameters are passed by reference.*/
/*--*/

{
    inline friend complex polar(double, double = 0);
    friend double abs(const complex &);
    friend double norm(const complex &);
    friend double arg(const complex &);
    friend double arg1(const complex &);
    inline friend complex conj(const complex &);
    friend complex sin(const complex &);
    friend complex sinh(const complex &);
    friend complex cos(const complex &);
    friend complex cosh(const complex &);
    friend complex tan(const complex &);
    friend complex tanh(const complex &);
    inline friend double imag(const complex &);
    inline friend double real(const complex &);
    friend complex log(const complex &);
    friend complex exp(const complex &);
    friend complex pow(double, const complex &);
    friend complex pow(const complex &, int);
    friend complex pow(const complex &, double);
    friend complex pow(const complex &, const complex &);
    friend complex sqrt(const complex &);
    friend complex sqr(const complex &);
    inline friend complex operator-(const complex &);
    inline friend complex operator+(const complex &, const complex &);
    inline friend complex operator-(const complex &, const complex &);
    inline friend complex operator*(const complex &, const complex &);
    inline friend complex operator/(const complex &, const double &);
    friend complex operator/(const complex &, const complex &);
    inline friend int operator==(const complex &, const complex &);
    inline friend int operator!=(const complex &, const complex &);
    /*
MODIF PERSO
    friend ostream &operator<<(ostream &, const complex &);
    friend istream &operator>>(istream &, complex &);
	*/

private:
    double cxxl_re;			/* Real part.*/
    double cxxl_im;			/* Imaginary part.*/

    complex cxxl_exp(int &) const;
    complex cxxl_real_overflow_return_value() const;

public:

    inline complex(double, double = 0);
    inline complex();

    inline void operator-=(const complex &);
    inline void operator+=(const complex &);
    void operator*=(const complex &);
    void operator/=(const complex &);
};



//
//
/*  EXTERNAL DATA*/
//
//

static const complex complex_zero(0,0);

inline complex::complex(
    double x,			/* initial real part*/
    double y			/* initial imaginary part, defaults to 0*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	This is a constructor to create & initialize the complex number from*/
/*	cartesian coordinates.*/
//
/*  IMPLICIT OUTPUT PARAMETERS AND SIDE EFFECTS:*/
//
/*	Memory is allocated*/
//
/*  POSTCONDITIONS:*/
//
/*	cxxl_re == x*/
/*	cxxl_im == y*/
/*--*/

    :
    cxxl_re(x),
    cxxl_im(y)
{
}

inline complex::complex(
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	This is a constructor to create & initialize the complex number to 0.*/
//
/*  IMPLICIT OUTPUT PARAMETERS AND SIDE EFFECTS:*/
//
/*	Memory is allocated*/
//
/*  POSTCONDITIONS:*/
//
/*	*this == 0*/
/*--*/

    :
    cxxl_re(0),
    cxxl_im(0)
{
}

inline complex polar(
    double rho,				/* initial magnitude*/
    double theta			/* initial angle, defaults to 0*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Create a complex number and initialize it in polar coordinates.*/
//
/*  FRIEND OF:	complex*/
//
/*  RETURN VALUE:*/
//
/*	A new complex number.*/
//
/*  POSTCONDITIONS:*/
//
/*	abs() == rho*/
/*	sin(arg()) == sin(theta)*/
/*	cos(arg()) == cos(theta)*/
/*--*/

{
    return complex(rho * cos(theta), rho * sin(theta));
}

inline double real(
    const complex &z1			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Return the real part of a complex number.*/
//
/*  FRIEND OF:	complex*/
//
/*  RETURN VALUE:*/
//
/*	The real part of z1*/
/*--*/

{
    return z1.cxxl_re;
}

inline double imag(
    const complex &z1			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Return the imaginary part of a complex number.*/
//
/*  FRIEND OF:	complex*/
//
/*  RETURN VALUE:*/
//
/*	The imaginary part of z1*/
/*--*/

{
    return z1.cxxl_im;
}

inline complex conj(
    const complex &z1			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Take the conjugate of a complex number.*/
//
/*  FRIEND OF:	complex*/
//
/*  RETURN VALUE:*/
//
/*	The conjugate of z1*/
//
/*  DESIGN:*/
//
/*	conj((re,im)) = (re, -im)*/
/*--*/

{
    return complex(z1.cxxl_re, - z1.cxxl_im);
}

inline complex operator-(
    const complex &z1			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Unary negation of a complex number.*/
//
/*  FRIEND OF:	complex*/
//
/*  RETURN VALUE:*/
//
/*	-z1*/
//
/*  DESIGN:*/
//
/*	-(re,im) = (-re,-im)*/
/*--*/

{
    return complex(- z1.cxxl_re, - z1.cxxl_im);
}

inline complex operator+(
    const complex &z1,			/* A complex number*/
    const complex &z2			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Sum of complex numbers.*/
//
/*  FRIEND OF:	complex*/
//
/*  RETURN VALUE:*/
//
/*	z1+z2*/
//
/*  DESIGN:*/
//
/*	(re1,im1)+(re2,im2) = (re1+re2,im1+im2)*/
/*--*/

{
    return complex(z1.cxxl_re + z2.cxxl_re, z1.cxxl_im + z2.cxxl_im);
}

inline complex operator-(
    const complex &z1,			/* A complex number*/
    const complex &z2			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Difference of complex numbers.*/
//
/*  FRIEND OF:	complex*/
//
/*  RETURN VALUE:*/
//
/*	z1-z2*/
//
/*  DESIGN:*/
//
/*	(re1,im1)-(re2,im2) = (re1-re2,im1-im2)*/
/*--*/

{
    return complex(z1.cxxl_re - z2.cxxl_re, z1.cxxl_im - z2.cxxl_im);
}


//------------------------------------------------------------------------
inline complex operator*(
    const complex &z1,			/* A complex number*/
    const complex &z2			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
/*--*/
{
    return complex(z1.cxxl_re*z2.cxxl_re - z1.cxxl_im*z2.cxxl_im,
                   z1.cxxl_re*z2.cxxl_im + z1.cxxl_im*z2.cxxl_re);
}


//------------------------------------------------------------------------
inline complex operator/(
    const complex &z1,			/* A complex number*/
    const double &r			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
/*--*/
{
    return complex(z1.cxxl_re/r,
                   z1.cxxl_im/r);
}


//------------------------------------------------------------------------
inline void complex::operator+=(
    const complex &z1			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Add a complex number to a complex number.*/
//
/*  IMPLICIT OUTPUT PARAMETERS AND SIDE EFFECTS:*/
//
/*	*this is increased by z1*/
//
/*  DESIGN:*/
//
/*	(re1,im1)+(re2,im2) = (re1+re2,im1+im2)*/
/*--*/

{
    cxxl_re += z1.cxxl_re;
    cxxl_im += z1.cxxl_im;
}

inline void complex::operator-=(
    const complex &z1			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Subtract a complex number from a complex number.*/
//
/*  IMPLICIT OUTPUT PARAMETERS AND SIDE EFFECTS:*/
//
/*	*this is decreased by z1*/
//
/*  DESIGN:*/
//
/*	(re1,im1)-(re2,im2) = (re1-re2,im1-im2)*/
/*--*/

{
    cxxl_re -= z1.cxxl_re;
    cxxl_im -= z1.cxxl_im;
}

inline int operator==(
    const complex &z1,			/* A complex number*/
    const complex &z2			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Compare complex numbers for equality.*/
//
/*  FRIEND OF:	complex*/
//
/*  RETURN VALUE:*/
//
/*	If z1 == z1, a non-0 value*/
/*	If z1 != z1, 0*/
/*--*/

{
    return (z1.cxxl_re == z2.cxxl_re && z1.cxxl_im == z2.cxxl_im);
}

inline int operator!=(
    const complex &z1,			/* A complex number*/
    const complex &z2			/* A complex number*/
    )

/*++*/
/*  FUNCTIONAL DESCRIPTION:*/
//
/*	Compare complex numbers for inequality.*/
//
/*  FRIEND OF:	complex*/
//
/*  RETURN VALUE:*/
//
/*	If z1 != z1, a non-0 value*/
/*	If z1 == z1, 0*/
/*--*/

{
    return (z1.cxxl_re != z2.cxxl_re || z1.cxxl_im != z2.cxxl_im);
}

class c_exception

/*++*/
/*  CLASS DESCRIPTION:*/
//
/*	Complex arithmetic exception information (function, parameters, error*/
/*	type, and default return value)*/
//
/*  DESIGN:*/
//
/*	Note that the private data members of this class are really part of*/
/*	the public interface, because they may be used by the optionally-user-*/
/*	supplied friend function, complex_error(c_exception &).  (This is why*/
/*	they do not have the facility prefix like other private members of a*/
/*	class.)  Also note that they are public instead of private for access by*/
/*	complex_error(c_exception &)-like functions which are established with*/
/*	set_complex_error(cxxl_p_complex_error_t) instead of by order of*/
/*	linking getting the "correct" instance of complex_error(c_exception &).*/
//
/*	See also:*/
//
/*	    "ULTRIX-32 Programmer's Manual Sections 2, 3, 4, and 5*/
/*	    (AA-BG54E-TE)" page 3-166ff on subroutine "matherr ( 3m )"*/
/*	    for information on the analogous capability in the ULTRIX C library.*/
/*--*/

{
    friend complex exp(const complex &);
    friend complex sinh(const complex &);
    friend complex cosh(const complex &);
    friend complex log(const complex &);

#if defined(__VMS) && defined(__DECCXX)
#   pragma __extern_prefix __CXXL_PLAIN_FUNC_LINKAGE
#endif

    friend int complex_error(c_exception &);


public:

    int type;				/* Error type (SING, OVERFLOW,*/
					/* or UNDERFLOW).*/
    char *name;				/* The name of the function that*/
					/* incurred the error.*/
    complex arg1;			/* Left argument of the function.*/
    complex arg2;			/* Right argument of the function.*/
    complex retval;			/* Value to be returned by*/
					/* the function; may be changed by*/
					/* complex_error(c_exception &).*/

private:

    void invoke_complex_error_handling(int n_args = 1);

#if defined(__VMS) && defined(__DECCXX)
#   pragma __extern_prefix __CXXL_FLOAT_FUNC_LINKAGE
#endif

public:

    c_exception(char *function_name, const complex &function_arg1,
	const complex &function_arg2 = complex_zero);
};



//
//
/*  CONSTANTS*/
//
//

/* ULTRIX puts these error codes in <math.h> but VMS doesn't*/

#ifndef SING
#define SING 2
#endif

#ifndef OVERFLOW
#define OVERFLOW 3
#endif

#ifndef UNDERFLOW
#define UNDERFLOW 4
#endif

#if defined(__VMS) && defined(__DECCXX)
#   pragma __extern_model __restore
#   pragma __extern_prefix __restore
#   pragma __member_alignment __restore
#endif

#endif

/* End of complex.hxx*/
