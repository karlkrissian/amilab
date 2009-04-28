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

#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "style.hpp"
#include "surface.hpp"
#include "Crest.hpp"


//----------------------------------------------------------------------
SurfacePoly* Func_ConnectLines(SurfacePoly* s, float maxdist, float maxangle)
//           -----------------
{
#ifndef _WITHOUT_VTK_

//    vtkPolyData* res_vtk;
    Crest*       res_crest;
    SurfacePoly* res;


  res_crest = new Crest();
  res_crest->ImportVTK((vtkPolyData*) (*s));

  res_crest->FixeCriteresConnexion( maxdist, maxangle);
  res_crest->ConnecteLignes();

  res = new SurfacePoly((vtkPolyData*)(*res_crest));

  delete res_crest;

  return res;
#else
  fprintf(stderr,"Func_ConnectLines()\t this function needs VTK and it is not available ...\n");
  return NULL;
#endif

} // Func_ConnectLines()
