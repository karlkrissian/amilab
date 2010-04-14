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
using namespace amilab;


//----------------------------------------------------------------------
SurfacePoly* Func_SmoothLines(SurfacePoly* s, float alpha, float beta, int N )
//           ----------------
{
    SurfacePoly* res;
    T_Line line; 
    register int    t;
    register float  a,b;
    register int    l,n;
    int nb_lines,nb_points;

  res = new SurfacePoly();

  // Copy the points
  nb_points = s->GetNumberOfPoints();
  Pour(n,0,nb_points-1)
    res->AddPoint((*s)[n].pt.x,(*s)[n].pt.y,(*s)[n].pt.z);
    res->SetColor((*s)[n].red,(*s)[n].green,(*s)[n].blue);
  FinPour

#define smooth(n) (*res)[line[n]].pt
#define init(n)   (*s)[  line[n]].pt

  // Smooth the lines
  nb_lines = s->GetNumberOfLines();
  a = alpha;
  b = beta;

  Pour( l, 0, nb_lines-1)
    line = s->GetLine(l);
    nb_points = line.NbElts();
    if (nb_points>1) {
      //printf("line[0]=%d\n"          ,line[0]);
      //printf("line[nb_points-1]=%d\n",line[nb_points-1]);
      // Smooth the line
      Pour( t, 1, N)
        Pour( n, 1, nb_points-2)
          smooth(n).x +=  a * ( smooth(n-1).x - 2*smooth(n).x + smooth(n+1).x) +
                          b * ( init(n).x - smooth(n).x );
          smooth(n).y +=  a * ( smooth(n-1).y - 2*smooth(n).y + smooth(n+1).y) +
                          b * ( init(n).y - smooth(n).y );
          smooth(n).z +=  a * ( smooth(n-1).z - 2*smooth(n).z + smooth(n+1).z) +
                          b * ( init(n).z - smooth(n).z );
        FinPour
        // if the line is a loop, smooth the extremity??
        if (line[0]==line[nb_points-1]) {
          smooth(0).x +=  a * ( smooth(nb_points-2).x
                                - 2*smooth(0).x + smooth(1).x) +
            b * ( init(0).x - smooth(0).x );
          smooth(0).y +=  a * ( smooth(nb_points-2).y 
                                - 2*smooth(0).y + smooth(1).y) +
            b * ( init(0).y - smooth(0).y );
          smooth(0).z +=  a * ( smooth(nb_points-2).z 
                                - 2*smooth(0).z + smooth(1).z) +
            b * ( init(0).z - smooth(0).z );
        }
      FinPour // t

      // Save the line
      res->NewLine();
      Pour( n, 0, nb_points-1)
        res->LineAddPointNumber(line[n]);
      FinPour
      res->EndLine();
    } // if nb_points>1


  FinPour // l


  return res;

} // Func_SmoothLines()
