//
// C++ Interface: LinearColorMap
//
// Description: Colormap with interpolation between points
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _LinearColorMap_h_
#define _LinearColorMap_h_

#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <vector>
#include <wx/colour.h>
#include "inrimage.hpp"

/// position+color
class LinearColorMapPoint
{
  double pos;
  double alpha;
  double sharpness; 
  double midpoint;
  wxColour left_colour;
  wxColour right_colour;

public:
  LinearColorMapPoint( const double& p=0, const double& a=0, const wxColour& c = *wxBLACK ) {
    pos = p;
    alpha =a;
    left_colour =  c;
    right_colour =  c;
    midpoint = 0.5;
    sharpness = 0; 
  }

  void SetPosition(const double& position)
  {
    pos = position;
  }

  double GetPosition() const { return pos; }
  
  void SetAlpha(const double& opacity)
  {
    alpha = opacity;
  }

  double GetAlpha() const { return alpha; }

  void SetColour(const wxColour& c)
  {
    left_colour = c;
    right_colour = c;
  }

  void SetLeftColour(const wxColour& c)
  {
    left_colour = c;
  }

  void SetRightColour(const wxColour& c)
  {
    right_colour = c;
  }

  void SetMidpoint(const double& mid)
  {
    midpoint = mid;
  }

  double GetMidpoint() const { return midpoint; }
  
  void SetSharpness(const double& shar)
  {
    sharpness = shar;
  }

  double GetSharpness() const { return sharpness; }

  wxColour GetLeftColour()  const { return left_colour;  }
  wxColour GetRightColour() const { return right_colour; }
  
  bool operator<(const LinearColorMapPoint& p) const {
   return pos<p.GetPosition();
  }
  
};


/// This class contains a list of position with RGB colors
class LinearColorMap
{
    std::vector<LinearColorMapPoint> points;
  
  public:
    LinearColorMap() {}
  
    void AddPoint( const LinearColorMapPoint& cmpt)
    {
      points.push_back(cmpt);
      this->sort();
    }
  
    LinearColorMapPoint& GetPoint( int index)
    {
      return points[index];
    }
  
    size_t size() const
    {
      return points.size();
    }
  
    void sort()
    {
      std::sort(points.begin(),points.end());
    }
  
    wxColour InterpolateColour( double pos) {
  
      int n = points.size();
      if (n==0) return *wxBLACK;
      if (n==1) {
        if (pos<=points[0].GetPosition())
          return points[0].GetLeftColour();
        else 
          return points[0].GetRightColour();
      }
      
      if (pos<=points[0].  GetPosition()) return points[0].  GetLeftColour();
      if (pos>=points[n-1].GetPosition()) return points[n-1].GetRightColour();
      
      int i=0;
      while ((i<n)&&(pos>points[i].GetPosition())) i++;
      // interpolate colour between point i-1 and i
      double pos1 = points[i-1].GetPosition();
      wxColour c1 = points[i-1].GetRightColour();
      double pos2 = points[i].GetPosition();
      wxColour c2 = points[i].GetLeftColour();
      
      if (fabsf(pos2-pos1)<=1E-5) return c1;
      
      double coeff1 = (pos-pos1)/(pos2-pos1);
      double coeff2 = 1.0-coeff1;
      wxColour res;
      res.Set(coeff2*c1.Red()  +coeff1*c2.Red(),
              coeff2*c1.Green()+coeff1*c2.Green(),
              coeff2*c1.Blue() +coeff1*c2.Blue()  );
      return res;
    }
  
    void clear()
    {
      points.clear();
    }

    InrImage::ptr CreateColormapImage();
};

#endif // _LinearColorMap_h_
