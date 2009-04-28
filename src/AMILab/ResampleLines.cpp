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
#include "surface.hpp"
#include "Crest.hpp"


//----------------------------------------------------------------------
SurfacePoly* Func_ResampleLines(SurfacePoly* s, float dist)
//           ------------------
{
#ifndef _WITHOUT_VTK_
  
//    vtkPolyData* res_vtk;
    Crest*       input_crest;
    Crest*       res_crest;

    SurfacePoly* res;
    int          l,n,i;
    float        length,a;
    Point3D      pt;
    LigneCrest   ligne_crest;


  input_crest = new Crest();
  input_crest->ImportVTK((vtkPolyData*) (*s));

  res_crest = new Crest();
  Pour(n,0,input_crest->NbPoints()-1)
    res_crest->AddPoint(input_crest->Point(n));
  FinPour

  // Copy the same points to start from
  // the junctions need to be kept...
  // unused points should be removed as a pruning final step  

  Pour(l,0,input_crest->NbLignes()-1)
    length = input_crest->LongueurLigne(l);
    n = (int) (length/dist);
    // l/dist = n +a
    // l/n     = l/(n+a)*(n+a)/n     = dist * (1+a/n)
    // l/(n+1) = l/(n+a)*(n+a)/(n+1) = dist * (1 - (1-a)/(n+1))
    a = length/dist - n;
    if ((1-a)/(n+1) < a/n) n++;
    // add the new line
    ligne_crest.EmptyLine();
    ligne_crest.liste_points.Resize(n+1);
    ligne_crest += input_crest->NumPoint(l,0);
    Pour(i,1,n-1)
      input_crest->Position(l,(length/n)*i,pt);
      ligne_crest += res_crest->AddPoint(pt);
    FinPour
    ligne_crest += input_crest->NumPoint(l,input_crest->NbPoints(l)-1);
    res_crest->AjouteLigne(ligne_crest);
  FinPour 


  res = new SurfacePoly((vtkPolyData*)(*res_crest));

  delete res_crest;
  delete input_crest;

  return res;
#else
  fprintf(stderr,"Func_ResampleLines()\t this function needs VTK and it is not available ...\n");
  return NULL;
#endif

} // Func_ResampleLines()

