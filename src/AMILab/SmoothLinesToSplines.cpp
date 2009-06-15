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

extern "C" {
#include    "coeff.h"
#include    "interpol.h"
}

//----------------------------------------------------------------------
SurfacePoly* Func_SmoothLinesToSplines(SurfacePoly* s, float samplingStep )
//           ----------------
{
    SurfacePoly* res;
    T_Line line;
    //register int    t;
    register int    l,n;
    int nb_lines,nb_points;

  if (samplingStep<1E-5) samplingStep = 1E-5;

  res = new SurfacePoly();

#define init(n)   (*s)[  line[n]].pt

  // Smooth the lines
  nb_lines = s->GetNumberOfLines();
  int idPoints = 0;

  Pour( l, 0, nb_lines-1)
    line = s->GetLine(l);
    nb_points = line.NbElts();
    cout << "nb_points = "<< nb_points << endl;
    if (nb_points>1) {
      //printf("line[0]=%d\n"          ,line[0]);
      //printf("line[nb_points-1]=%d\n",line[nb_points-1]);
      // Smooth the line
      res->NewLine();

      float* coefX = new float[nb_points];
      float* coefY = new float[nb_points];
      float* coefZ = new float[nb_points];

      Pour( n, 0, nb_points-1)
         coefX[n] =  init(n).x;
         coefY[n] =  init(n).y;
         coefZ[n] =  init(n).z;
      FinPour

      SamplesToCoefficients(coefX, nb_points, 1, 2);
      SamplesToCoefficients(coefY, nb_points, 1, 2);
      SamplesToCoefficients(coefZ, nb_points, 1, 2);

      double AccuracyStep = 0.01;
      int AccSamplingSize = 100;
      double estimatedLength = 0;

//      Pour( n, 1, nb_points-1)
//         estimatedLength +=  sqrtl(sqr(init(n).x - init(n-1).x) + sqr(init(n).y - init(n-1).y) + sqr(init(n).z - init(n-1).z));
//      FinPour
      // estimated the lenght of the spline for 100 points to sample it with regular intervals

      float preSampleXPrec;
      float preSampleYPrec;
      float preSampleZPrec;
      float preSampleX;
      float preSampleY;
      float preSampleZ;

      preSampleXPrec = InterpolatedValue(coefX, nb_points, 1, 0, 0, 2);
      preSampleYPrec = InterpolatedValue(coefY, nb_points, 1, 0, 0, 2);
      preSampleZPrec = InterpolatedValue(coefZ, nb_points, 1, 0, 0, 2);

      Pour( n, 1, AccSamplingSize)
        float pos =  1.0/AccSamplingSize*(nb_points-1);
         preSampleX = InterpolatedValue(coefX, nb_points, 1,n*pos, 0, 2);
         preSampleY = InterpolatedValue(coefY, nb_points, 1,n*pos, 0, 2);
         preSampleZ = InterpolatedValue(coefZ, nb_points, 1,n*pos, 0, 2);
        cout << " " << preSampleX << " " << preSampleY << " " << preSampleZ << endl;
         estimatedLength +=  sqrtf( (preSampleX - preSampleXPrec)*(preSampleX - preSampleXPrec) +
                                    (preSampleY - preSampleYPrec)*(preSampleY - preSampleYPrec) +
                                    (preSampleZ - preSampleZPrec)*(preSampleZ - preSampleZPrec));

         preSampleXPrec = preSampleX;
         preSampleYPrec = preSampleY;
         preSampleZPrec = preSampleZ;
      FinPour

      // define the number of sampled points based on the lenght of the spline and the samplingStep
      if (AccuracyStep>samplingStep/2.0) AccuracyStep = samplingStep/2.0;
      int nbSamplePoints;
      nbSamplePoints = round(estimatedLength/samplingStep);
      int nbEpsilonSamplePoints;
      nbEpsilonSamplePoints = round(estimatedLength/AccuracyStep);
      double currentLength = 0;
      double targetLength  = 0;

      Pour( n, 0, nbEpsilonSamplePoints)
        float pos =  1.0/nbEpsilonSamplePoints*(nb_points-1);
         preSampleX = InterpolatedValue(coefX, nb_points, 1, n*pos, 0, 2);
         preSampleY = InterpolatedValue(coefY, nb_points, 1, n*pos, 0, 2);
         preSampleZ = InterpolatedValue(coefZ, nb_points, 1, n*pos, 0, 2);
         if (n>0)
            currentLength +=  sqrtf(  (preSampleX - preSampleXPrec)*(preSampleX - preSampleXPrec) +
                                        (preSampleY - preSampleYPrec)*(preSampleY - preSampleYPrec) +
                                        (preSampleZ - preSampleZPrec)*(preSampleZ - preSampleZPrec));


        if (currentLength>=targetLength-1E-10) {
           targetLength += samplingStep;
            cout  << " position " << n*pos 
                  << " addpoint " << n << " id " << idPoints 
                  << " " << preSampleX 
                  << " " << preSampleY 
                  << " " << preSampleZ << endl;
           res->AddPoint(preSampleX, preSampleY, preSampleZ);
           res->LineAddPointNumber(idPoints);
           idPoints++;
        } else {
            if (n==nbEpsilonSamplePoints) {
               cout << " position " << n*pos
                    << "addpoint " << n << " id " << idPoints
                    << " " << preSampleX 
                    << " " << preSampleY
                    << " " << preSampleZ << endl;
               res->AddPoint(preSampleX, preSampleY, preSampleZ);
               res->LineAddPointNumber(idPoints);
               idPoints++;
            }
        }

         preSampleXPrec = preSampleX;
         preSampleYPrec = preSampleY;
         preSampleZPrec = preSampleZ;
      FinPour

      // Save the line
      res->EndLine();
      delete [] coefX;
      delete [] coefY;
      delete [] coefZ;

	}

  FinPour // l


  return res;

} // Func_SmoothLines()
