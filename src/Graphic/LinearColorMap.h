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

#include <vector>
#include <wx/colour.h>

/// position+color
class LinearColorMapPoint
{
  double pos;
  wxColour colour;

public:
  LinearColorMapPoint( const double& p=0, const wxColour& c = *wxBLACK ) {
    pos = p;
    colour = c;
  }

  void SetPosition(const double& position)
  {
    pos = position;
  }

  double GetPosition() const { return pos; }

  void SetColour(const wxColour& c)
  {
    colour = c;
  }

  wxColour GetColour() const { return colour; }
  
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

  int size() const
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
    if (n==1) return points[0].GetColour();
    
    if (pos<=points[0].  GetPosition()) return points[0].  GetColour();
    if (pos>=points[n-1].GetPosition()) return points[n-1].GetColour();
    
    int i=0;
    while ((i<n)&&(pos>points[i].GetPosition())) i++;
    // interpolate colour between point i-1 and i
    double pos1 = points[i-1].GetPosition();
    wxColour c1 = points[i-1].GetColour();
    double pos2 = points[i].GetPosition();
    wxColour c2 = points[i-1].GetColour();
    
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
};

#endif // _LinearColorMap_h_
