#pragma once

#ifndef _function1_h_
#define _function1_h_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
//#include <conio.h>
#include <vector>
#include <string>

namespace VesselQuantif {
  
  class Point3D
  {
  public:
    std::vector<double> x;
    
    Point3D(double vx=0, double vy=0, double vz=0) : x(3,0) {
      x[0]=vx;
      x[1]=vy;
      x[2]=vz;
    }
    
    const double& operator[] (int k) const
    {
      return x[k];
    }

    double& operator[] (int k)
    {
      return x[k];
    }
  };
    
  class Line
  {
  public:
    std::vector<Point3D> points;
    
    Line()
    {
    }

    Line(int size) : points(size)
    {
    }
    
    std::vector<Point3D>& GetPoints(){
      return points;
    }
    
    int size() const
    { 
      return points.size(); 
    }
    
    const Point3D& operator[] (int k) const
    {
      return points[k];
    }

    Point3D& operator[] (int k) 
    {
      return points[k];
    }
    
    void Print(std::string name) const
    {
    for (int i=0;i<size();i++)
        for(int j=0;j<3;j++)
          std::cout << name 
              << "[" << i << "]" 
              << "[" << j << "]  = " << points[i][j] << std::endl;
    }
  };
  
  class LineResample {

    double Funcion(double s, const Line& cubspline);

    // to avoid creating a matrix 4x3 class, we use the Line structure with 4 points
    Line Kochanek(const Line& V);

    Point3D DerivadaPunto(const Line& line,int i);
    
    Line construir(const Line& line,int i);

    double LongArco(double x, double b, const Line& CS, int subdiv=1000);
  public:

    Line CenterlineEquidistante(double long_fija, const Line& centerline, 
                                double paso);
    
    static Line Run(double long_fija, const Line& centerline, double paso)
    {
      LineResample lr;
      return lr.CenterlineEquidistante(long_fija,centerline,paso);
    }
  };

}

#endif 
// _function1_h_
