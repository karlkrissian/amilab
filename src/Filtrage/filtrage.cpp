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
//  fichier filtrage.hpp
//
//  Karl Krissian    Sophia Antipolis, le 13-12-97
//
//  Realisation de differents type de filtrage
//  basee sur une fenetre centree en chaque point
//
//  Idees
//     option 2D, 3D
//     definition de la fenetre 2nx+1,2ny+1,2nz+1
//
//     Type de filtre: appel a une fonction de R^m dans R
//     qui a partir des points de la fenetre renvoie la nouvelle valeur
//
//     moyen, median, Gaussien, derivees, etc...
//     ecart-type, analyse du bruit ??
//
//


#include "filtrage.hpp"

// ==========================================================================
// protected:
//

