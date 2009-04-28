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
//  Routines from numerical recipes in C
//


//======================================================================
// For any dimension

int jacobi(float** a, int n, float d[], float** v, int *nrot);
//
//
// Computes all eigenvalues and eigenvectors of a real symmetric matrix
// a[0..n-1][0..n-1]. On output, elements of a above the diagonal 
// are destroyed.
// d[0..n-1] returns the eigenvalues of a.
// v[0..n-1][0..n-1] is a matrix whose columns contain, on output, 
// the normalized
// eigenvectors of a.
// nrot returns the number of Jacobi rotations that were required.
//

void eigsrt(float d[], float** v, int n);
//
// Given the eigenvalues d[0..n-1] and the eigenvectors
// v[0..n-1][0..n-1] as output from jacobi or tqli,
// this routine sorts the eigenvalues into descending order,
// and rearranges the columns of v correspondingly.
//

void eigsrt_abs(float d[], float** v, int n);
// use absolute values for sorting

void eigsrt_inc(float d[], float** v, int n);
//
// Given the eigenvalues d[0..n-1] and the eigenvectors
// v[0..n-1][0..n-1] as output from jacobi or tqli,
// this routine sorts the eigenvalues into descending order,
// and rearranges the columns of v correspondingly.
//

